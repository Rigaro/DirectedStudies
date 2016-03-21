% Finger Class
% Represents an underactuated cable driven finger.
% Author: Ricardo Garcia Rosas

classdef Finger < handle & matlab.System
    % Finger Class
    % Represents an underactuated cable driven finger.
    properties
        kP; % Proximal link stiffness coefficient
        kD;
        lP;
        lD;
        rP;
        rD;
        mP;
        mD;
        thetaP;
        thetaD;
        origin; % Finger origin location (m)
    end
    properties (SetAccess = private)
        prox; % Finger proximal phalanx
        dist; % Finger distal phalanx
    end
    methods
%         function obj = Finger(origin, kP, kD, lP, lD, rP, rD, mP, mD, thetaP, thetaD, thetaA)
        function obj = Finger(varargin)
            setProperties(obj, nargin, varargin{:});
            obj.kP = 1;
            obj.kD = 5;
            obj.lP = 0.1;
            obj.lD = 0.1;
            obj.rP = 0.02;
            obj.rD = 0.012;
            obj.mP = 0.02;
            obj.mD = 0.02;
            obj.thetaP = pi/10;
            obj.thetaD = pi/3;
            obj.origin = [0 0]; % Finger origin location (m)
            obj.prox = Phalanx(obj.kP,obj.lP,obj.rP,obj.mP,obj.thetaP,1);
            obj.dist = Phalanx(obj.kD,obj.lD,obj.rD,obj.mD,obj.thetaD,2);
        end
        function Jc = computeJc(obj)  
            % Update contact jacobian
            Jc = [obj.prox.a, 0;
                      obj.dist.a+obj.prox.l*...
                      (cos(obj.dist.theta)-obj.dist.miuC*...
                      sin(obj.dist.theta)),obj.dist.a];                     
        end
        function Je = computeJe(obj)
            % Update disturbance jacobian
            Je = [obj.prox.b, 0;
                      obj.dist.b+obj.prox.l*...
                      (cos(obj.dist.theta)-obj.dist.miuE*...
                      sin(obj.dist.theta)),obj.dist.b]; 
        end
        function rot = rotMat(~,theta)
            % Rotation matrix
            rot = [cos(theta) -sin(theta);
                   sin(theta) cos(theta)];
        end
        function [rOtoL, rOtoG] = fKine(obj)
            % Forward kinematics
            rOtoL = zeros(2,2);
            rOtoG = zeros(2,2);
            rOtoL(:,1) = obj.rotMat(obj.prox.theta)*[obj.prox.l;0];
            rOtoG(:,1) = obj.rotMat(obj.prox.theta)*[obj.prox.l/2;0];
            rOtoL(:,2) = rOtoL(:,2-1) + obj.rotMat(obj.dist.theta)*[obj.dist.l;0];
            rOtoG(:,2) = rOtoG(:,2-1) + obj.rotMat(obj.dist.theta)*[obj.dist.l/2;0];
        end
        function poly = getPoly(obj)
            obj.fKine();
            poly = [obj.origin(1),obj.rOtoL(1,1),obj.rOtoL(1,2);
                    obj.origin(2),obj.rOtoL(2,1),obj.rOtoL(2,2)];
        end
        function xDot = eom(obj,initVal,fa)
            obj.prox.theta = initVal(1);
            obj.dist.theta = initVal(2);
            obj.prox.thetaDot = initVal(3);
            obj.dist.thetaDot = initVal(4);
            K = [obj.prox.k 0;
                 0 obj.dist.k];
            Ja = [obj.prox.r obj.dist.r];
            Jc = obj.computeJc();
            Je = obj.computeJe();
            alpha = obj.prox.I + obj.dist.I + (obj.prox.m*(obj.prox.l/2)^2)+...
                    obj.dist.m*(obj.prox.l^2+(obj.dist.l/2)^2);
            beta = obj.dist.m*obj.prox.l*obj.dist.l/2;
            delta = obj.dist.I+obj.dist.m*(obj.dist.l/2)^2;
            % Intertia matrix (M)
            M = [alpha+2*beta*cos(obj.dist.theta) delta+beta*cos(obj.dist.theta);
                delta+beta*cos(obj.dist.theta) delta];
            % Coriolis and Centrifugal matrix (C)
            C = [-beta*sin(obj.dist.theta)*obj.dist.thetaDot ...
                -beta*sin(obj.dist.theta)*(obj.prox.thetaDot+obj.dist.thetaDot);
                beta*sin(obj.dist.theta)*obj.prox.thetaDot 0];
            springTau = K*([obj.prox.theta; obj.dist.theta]-[obj.prox.theta0; obj.dist.theta0]);
            contactTau = Jc'*[obj.prox.fc.fv(1); obj.dist.fc.fv(1)];
            distTau = Je'*[obj.prox.fe.fv(1); obj.dist.fe.fv(1)];
            actTau = Ja'*fa;
            thetaDot = [obj.prox.thetaDot; obj.dist.thetaDot];
            thetaDotDot = inv(M)*(-C*thetaDot + springTau + contactTau + distTau + actTau);
            xDot = [thetaDot; thetaDotDot];
        end
    end
    methods (Access = protected)
        function xDot = stepImpl(obj,initVal,fa)
            % Implement algorithm. Calculate y as a function of
            % input u and discrete states.
            xDot = obj.eom(initVal,fa);
        end
    end
end