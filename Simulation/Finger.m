% Finger Class
% Represents an underactuated cable driven finger.
% Author: Ricardo Garcia Rosas

classdef Finger < handle
    % Finger Class
    % Represents an underactuated cable driven finger.
    properties (SetAccess = immutable)
        % Finger phalanges
        prox = Phalanx(); % Proximal phalanx
        dist = Phalanx(5,0.1,0.12,0.02,pi/3,2); % Distal phalanx
        K % Joint stiffness matrix
    end
    properties (SetAccess = private)
        % Physical finger properties
        origin = [0 0]; % Finger origin location (m)
        % Kinematic properties
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
        Jc % Contact jacobian
        % Disturbance Kinematics properties
        Je % Disturbance Jacobian
        % Special properties
        T_xtond % Transformation matrix between x,y vector to finger normal,tangential (proximal)
        poly % Polyline parameters for collision detetion [x[];y[]]
    end
    methods
        function obj = Finger(origin, kP, kD, lP, lD, rP, rD, mP, mD, thetaP, thetaD, thetaA)
        % Constructor with parameter initialization
            % Custom initialization
            if(nargin ~= 0)
                obj.origin = origin;
                obj.prox.k = kP;
                obj.dist.k = kD;
                obj.prox.l = lP;   
                obj.dist.l = lD;
                obj.prox.r = rP;  
                obj.dist.r = rD;  
                obj.prox.m = mP;
                obj.dist.m = mD;
                obj.prox.theta = thetaP;
                obj.dist.theta = thetaD;   
                obj.thetaA = thetaA;
            end
            % Physical properties initialization
            obj.K = [obj.prox.k 0;
                     0 obj.dist.k];
            % Kinematic values initialization
            obj.Ja = [obj.prox.r obj.dist.r];
            obj.fa = 0;
            % Contact Kinematics
            obj.updateJc(); % Contact jacobian
            % External forces
            obj.updateJe(); % Disturbance jacobian (only Distal contact)
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