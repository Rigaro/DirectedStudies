% Finger Class
% Represents an underactuated cable driven finger.
% Author: Ricardo Garcia Rosas

classdef Finger < handle
    % Finger Class
    % Represents an underactuated cable driven finger.
    properties (SetAccess = immutable)
        % Physical finger properties
        kP = 1; % Proximal joint stiffness (Nm/rad)
        kD = 5; % Distal joint stiffness (Nm/rad)
        lP = 0.1; % Proximal link length (m)
        lD = 0.1; % Distal link length (m)
        rP = 0.02;  % Proximal pulley radius (m)
        rD = 0.012;  % Distal pulley radius (m)
        mP = 0.02; % Proximal link mass (kg)
        mD = 0.02; % Distal link mass (kg)
        K % Joint stiffness matrix
        Ip % Proximal link z-inertia
        Id % Distal link z-inertia
    end
    properties (SetAccess = private)
        % Physical finger properties
        origin = [0 0]; % Finger origin location (m)
        miuC = 0.8; % Coefficient of friction between finger and contact object.
        miuE = 0.8; % Coefficient of friction between finger and disturbance object.
        % Kinematic properties
        theta0 = [pi/10; pi/3]; % Proximal (1) and Distal (2) joint rest angles (rad)
        theta = [pi/10; pi/3]; % Proximal (1) and Distal (2) joint angles (rad)
        thetaDot = [0; 0]; % First derivative (velocity) of Proximal (1) and Distal (2) joint angles (rad/s)
        thetaDotDot = [0; 0]; % Second derivative (acceleration) of Proximal (1) and Distal (2) joint angles (rad/s^2)
        thetaA = 0; % Actuator pulley angle (rad)
        thetaADot = 0; % First derivative of Actuator pulley angle (rad/s)
        rOtoP % Vector from origin to end of proximal link [x;y] (m)
        rOtoD % Vector from origin to end of distal link (fingertip) [x;y] (m)
        rOtoAP % Vector from origin to proximal contact location [x;y] (m)
        rOtoAD % Vector from origin to distal contact location [x;y] (m)
        rOtoBP % Vector from origin to proximal disturbance location [x;y] (m)
        rOtoBD % Vector from origin to distal disturbance location [x;y] (m)
        % Actuator properties
        Ja % Actuator Jacobian
        fa % actuator force
        % Contact Kinematics properties
        aP % Distance from Proximal joint to Proximal contact force (m)
        aD % Distance from Distal joint to Distal contact force (m)
        Jc % Contact jacobian
        fc % Contact Force
        % Disturbance Kinematics properties
        bP % Distance from Proximal joint to Proximal disturbance force (m)
        bD % Distance from Distal joint to Distal disturbance force (m)
        Je % Disturbance Jacobian
        fe % Disturbance Force
        % Special properties
        T_xtond % Transformation matrix between x,y vector to finger normal,tangential (proximal)
        poly % Polyline parameters for collision detetion [x[];y[]]
    end
    methods
        % Constructor with parameter initialization
        function obj = Finger(origin, kP, kD, lP, lD, rP, rD, mP, mD, thetaP, thetaD, thetaA)
            % Custom initialization
            if(nargin ~= 0)
                obj.origin = origin;
                obj.kP = kP;
                obj.kD = kD;
                obj.lP = lP;   
                obj.lD = lD;
                obj.rP = rP;  
                obj.rD = rD;  
                obj.mP = mP;
                obj.mD = mD;
                obj.theta = [thetaP; thetaD];   
                obj.thetaA = thetaA;
            end
            % Physical properties initialization
            obj.K = [obj.kP 0;
                     0 obj.kD];
            % Kinematic values initialization
            obj.theta0 = obj.theta;
            obj.Ja = [obj.rP obj.rD];
            obj.fa = 0;
            % Contact Kinematics
            obj.aD = 0; % Distance from Distal joint to Distal contact force (m)
            obj.aP = 0; % Distance from Proximal joint to Proximal contact force (m)
            obj.updateJc(); % Contact jacobian
            obj.fc = [ForceFinger(0,aP,miuC);ForceFinger(0,aD,miuC)];
            % External forces
            obj.bD = 0;% Distance from Distal joint to Distal disturbance force (m)
            obj.bP = 0;% Distance from Proximal joint to Proximal disturbance force (m)
            obj.updateJe(); % Disturbance jacobian (only Distal contact)
            obj.fe = [ForceFinger(0,bP,miuE);ForceFinger(0,bD,miuE)];
        end
        % Set finger origin
        function setOrigin(obj, origin)
            obj.origin = origin;
        end
        % Set finger rest theta
        function setThetaRest(obj, theta0)
            obj.theta0 = theta0;
        end
        % Set finger theta
        function setTheta(obj, theta)
            obj.theta = theta;
        end
        % Set actuator theta
        function setThetaA(obj, thetaa)
            obj.thetaa = thetaa;
        end
        % Set actuator force
        function setfa(obj, fa)
            obj.fa = fa;
        end
        % Set actuator change in theta
        function setDThetaA(obj, dthetaa)
            obj.dthetaa = dthetaa;
        end
        % Set finger Proximal joint angle
        function setThetaP(obj, thetap)
            obj.theta(1) = thetap;
        end
        % Set finger Distal joint angle
        function setThetaD(obj, thetad)
            obj.theta(2) = thetad;
        end
        % Set disturbance force
        function setfe(obj, fe)
            obj.fe = fe;
        end
        % Set contact force
        function setfc(obj, fc)
            obj.fc = fc;
        end
        % Update contact jacobian
        function updateJc(obj)  
            obj.Je = [obj.aP, 0;
                      obj.aD+obj.lP*(cos(obj.theta(2))-obj.miuC*sin(obj.theta(2))),obj.aD];                     
        end
        % Update disturbance jacobian
        function updateJe(obj)
            obj.Je = [obj.bP, 0;
                      obj.bD+obj.lP*(cos(obj.theta(2))-obj.miuE*sin(obj.theta(2))),obj.bD]; 
        end
        function updateT_xtond(obj)
            obj.T_xtond = [cos(obj.theta(1)+obj.theta(2)) -sin(obj.theta(1)+obj.theta(2));
                           sin(obj.theta(1)+obj.theta(2)) cos(obj.theta(1)+obj.theta(2))];
        end
        function rot = rotMat(angle)
            rot = [cos(angle) -sin(angle);
                   sin(angle) cos(angle)];
        end
        function fKine(obj)
            % Forward kinematics
            obj.rOtoP = rotMat(obj.theta(1))*[obj.lP;0];
            obj.rOtoD = obj.rOtoP + rotMat(obj.theta(2))*[obj.lD;0];
        end
        function poly = getPoly(obj)
            obj.fKine();
            poly = [obj.origin(1),obj.r_op(1),obj.r_od(1);
                    obj.origin(2),obj.r_op(2),obj.r_od(2)];
        end
    end
end