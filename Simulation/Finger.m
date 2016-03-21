% Finger Class
% Represents an underactuated cable driven finger.
% Author: Ricardo Garcia Rosas

classdef Finger < handle
    % Finger Class
    % Represents an underactuated cable driven finger.
    properties (SetAccess = immutable)
        % Finger phalanges
        phalanx;
%         prox = Phalanx(); % Proximal phalanx
%         dist = Phalanx(5,0.1,0.12,0.02,pi/3,2); % Distal phalanx
        K % Joint stiffness matrix
    end
    properties (SetAccess = private)
        % Physical finger properties
        origin = [0 0]; % Finger origin location (m)
        % Kinematic properties
        thetaA = 0; % Actuator pulley angle (rad)
        thetaADot = 0; % First derivative of Actuator pulley angle (rad/s)
        rOtoL % Vector from origin to end of phalanx link [x;y] (m)
        rOtoA % Vector from origin to phalanx contact location [x;y] (m)
        rOtoB % Vector from origin to phalanx disturbance location [x;y] (m)
        rOtoG % Vector from origin to phalanx centre of gravity [x;y] (m)
%         rOtoP % Vector from origin to end of proximal link [x;y] (m)
%         rOtoD % Vector from origin to end of distal link (fingertip) [x;y] (m)
%         rOtoAP % Vector from origin to proximal contact location [x;y] (m)
%         rOtoAD % Vector from origin to distal contact location [x;y] (m)
%         rOtoBP % Vector from origin to proximal disturbance location [x;y] (m)
%         rOtoBD % Vector from origin to distal disturbance location [x;y] (m)
        % Actuator properties
        Ja % Actuator Jacobian
        fa % actuator force
        % Contact Kinematics properties
        Jc % Contact jacobian
        % Disturbance Kinematics properties
        Je % Disturbance Jacobian
        % Special properties
        poly % Polyline parameters for collision detetion [x[];y[]]
    end
    methods
        function obj = Finger(origin, kP, kD, lP, lD, rP, rD, mP, mD, thetaP, thetaD, thetaA)
        % Constructor with parameter initialization
        % Creates a default 2 phalages finger
            % Custom initialization
            if(nargin ~= 0)
                obj.origin = origin;
                obj.thetaA = thetaA;
                obj.phalanx = [Phalanx(kP,lP,rP,mP,thetaP,1) Phalanx(kD,lD,rD,mD,thetaD,2)];
            else
                obj.phalanx = [Phalanx() Phalanx(5,0.1,0.012,0.02,pi/3,2)];
            end
            % Physical properties initialization
            obj.K = [obj.phalanx(1).k 0;
                     0 obj.phalanx(2).k];
            % Kinematic values initialization
            obj.Ja = [obj.phalanx(1).r obj.phalanx(2).r];
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
        % Set actuator theta
        function setThetaA(obj, thetaa)
            obj.thetaa = thetaa;
        end
        % Set actuator change in theta
        function setThetaADot(obj, thetaADot)
            obj.thetaADot = thetaADot;
        end
        % Set actuator force
        function setFa(obj, fa)
            obj.fa = fa;
        end
        % Update contact jacobian
        function updateJc(obj)  
            obj.Jc = [obj.phalanx(1).a, 0;
                      obj.phalanx(2).a+obj.phalanx(1).l*...
                      (cos(obj.phalanx(2).theta)-obj.phalanx(2).miuC*...
                      sin(obj.phalanx(2).theta)),obj.phalanx(2).a];                     
        end
        % Update disturbance jacobian
        function updateJe(obj)
            obj.Je = [obj.phalanx(1).b, 0;
                      obj.phalanx(2).b+obj.phalanx(1).l*...
                      (cos(obj.phalanx(2).theta)-obj.phalanx(2).miuE*...
                      sin(obj.phalanx(2).theta)),obj.phalanx(2).b]; 
        end
        function rot = rotMat(obj,theta)
            rot = [cos(theta) -sin(theta);
                   sin(theta) cos(theta)];
        end
        function fKine(obj)
            % Forward kinematics
            [phalanxRow, phalanxCol] = size(obj.phalanx);
            obj.rOtoL = zeros(2,phalanxCol);
            obj.rOtoG = zeros(2,phalanxCol);
            obj.rOtoL(:,1) = obj.rotMat(obj.phalanx(1).theta)*[obj.phalanx(1).l;0];
            obj.rOtoG(:,1) = obj.rotMat(obj.phalanx(1).theta)*[obj.phalanx(1).l/2;0];
            for i=2:phalanxCol
                obj.rOtoL(:,i) = obj.rOtoL(:,i-1) + obj.rotMat(obj.phalanx(i).theta)*[obj.phalanx(i).l;0];
                obj.rOtoG(:,i) = obj.rOtoG(:,i-1) + obj.rotMat(obj.phalanx(i).theta)*[obj.phalanx(i).l/2;0];
            end
        end
        function poly = getPoly(obj)
            obj.fKine();
            poly = [obj.origin(1),obj.rOtoL(1,1),obj.rOtoL(1,2);
                    obj.origin(2),obj.rOtoL(2,1),obj.rOtoL(2,2)];
        end
        function xDot = eom(obj,t,initVal)
            obj.phalanx(1).theta = initVal(1);
            obj.phalanx(2).theta = initVal(2);
            obj.phalanx(1).thetaDot = initVal(3);
            obj.phalanx(2).thetaDot = initVal(4);
            obj.updateJc();
            obj.updateJe();
            alpha = obj.phalanx(1).I + obj.phalanx(2).I + (obj.phalanx(1).m*(obj.phalanx(1).l/2)^2)+...
                    obj.phalanx(2).m*(obj.phalanx(1).l^2+(obj.phalanx(2).l/2)^2);
            beta = obj.phalanx(2).m*obj.phalanx(1).l*obj.phalanx(2).l/2;
            delta = obj.phalanx(2).I+obj.phalanx(2).m*(obj.phalanx(2).l/2)^2;
            % Intertia matrix (M)
            M = [alpha+2*beta*cos(obj.phalanx(2).theta) delta+beta*cos(obj.phalanx(2).theta);
                delta+beta*cos(obj.phalanx(2).theta) delta];
            % Coriolis and Centrifugal matrix (C)
            C = [-beta*sin(obj.phalanx(2).theta)*obj.phalanx(2).thetaDot ...
                -beta*sin(obj.phalanx(2).theta)*(obj.phalanx(1).thetaDot+obj.phalanx(2).thetaDot);
                beta*sin(obj.phalanx(2).theta)*obj.phalanx(1).thetaDot 0];
            springTau = obj.K*([obj.phalanx(1).theta; obj.phalanx(2).theta]-[obj.phalanx(1).theta0; obj.phalanx(2).theta0]);
            contactTau = obj.Jc'*[obj.phalanx(1).fc.fv(1); obj.phalanx(2).fc.fv(1)];
            distTau = obj.Je'*[obj.phalanx(1).fe.fv(1); obj.phalanx(2).fe.fv(1)];
            actTau = obj.Ja'*obj.fa;
            thetaDot = [obj.phalanx(1).thetaDot; obj.phalanx(2).thetaDot];
            thetaDotDot = inv(M)*(-C*thetaDot + springTau + contactTau + distTau + actTau);
            xDot = [thetaDot; thetaDotDot];
        end
    end
end