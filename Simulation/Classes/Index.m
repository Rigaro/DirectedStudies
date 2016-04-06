% Finger Class
% Represents an underactuated cable driven finger.
% The finger is composed of two phalanges driven by a tendon-pulley
% mechanism. This class has methods for calculating the kinematics and
% dynamics of the system.
% Extends matlab.System class to allow Simulink implementation.
% Author: Ricardo Garcia Rosas
% Change log:
%%%%%%%%%%%%|%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|
% Date      |   Author  | Notes                                     |
% 16/03/23  |   RGR     | Added more comments.                      |
% 16/03/24  |   RGR     | Compute fc and transform to [x,y].        |
% 16/04/06  |   RGR     | Removed force class, using only magnitude.|

classdef Index < handle & matlab.System
    % Finger Class
    % Represents an underactuated cable driven finger.
    % The finger is composed of two phalanges driven by a tendon-pulley
    % mechanism. This class has methods for calculating the kinematics and
    % dynamics of the system.
    properties
        kP; % Proximal joiny stiffness coefficient (Nm/rad)
        kD; % Distal joint stiffness coefficient (Nm/rad)
        dP; % Proximal joint damping coefficient (Nm/(rad/s))
        dD; % Distal joint damping coefficient (Nm/(rad/s))
        lP; % Proximal link length (m)
        lD; % Distal link length (m)
        rP; % Proximal pulley radius (m)
        rD; % Distal pulley radius (m)
        mP; % Proximal link mass (kg)
        mD; % Distal link mass (kg)
        thetaP; % Proximal joint rest angle (rad)
        thetaD; % Distal joint rest angle (rad)
    end
    properties (SetAccess = private)
        prox; % Finger proximal phalanx
        dist; % Finger distal phalanx
    end
    methods
        function obj = Index(varargin)
            % System object constructor with default values.
            % @param varargin System object argument string.
            % @return Index object.
            setProperties(obj, nargin, varargin{:});
            obj.kP = -1;
            obj.kD = -5;
            obj.dP = -0.01;
            obj.dD = -0.01;
            obj.lP = 0.1;
            obj.lD = 0.1;
            obj.rP = 0.02;
            obj.rD = 0.012;
            obj.mP = 0.02;
            obj.mD = 0.02;
            obj.thetaP = pi/10;
            obj.thetaD = pi/3;
            obj.prox = Phalanx(obj.kP,obj.dP,obj.lP,obj.rP,obj.mP,obj.thetaP,1);
            obj.dist = Phalanx(obj.kD,obj.dD,obj.lD,obj.rD,obj.mD,obj.thetaD,2);
        end
        function Jc = computeJc(obj)  
            % Compute contact jacobian. Maps contact forces to joint
            % torques.
            % @return Jc the contact jacobian as a 2x2 matrix.
            Jc = [obj.prox.a, 0;
                  obj.dist.a+obj.prox.l*cos(obj.dist.theta),obj.dist.a];                    
        end
        function Je = computeJe(obj)
            % Compute disturbance jacobian. Maps disturbance forces to
            % joint torques.
            % @return Je the disturbance jacobian as a 2x2 matrix.
            Je = [obj.prox.b, 0;
                  obj.dist.b+obj.prox.l*cos(obj.dist.theta),obj.dist.b]; 
        end
        function rot = rotMat(~,theta)
            % 2D Z-Rotation matrix on theta.
            % @param theta the angle
            % @return rot the rotation matrix as a 2x2 matrix.
            rot = [cos(theta) -sin(theta);
                   sin(theta) cos(theta)];
        end
        function [rOtoL, rOtoG] = fKine(obj,origin)
            % Forward kinematics to link ends and centre of gravity.
            % @param origin the finger's origin [x,y] (m).
            % @return rOtoL vector from finger origin to link end, one 2D
            % vector for each link.
            % @return rOtoG vector from finger origin to link center of
            % gravity, one 2D vector for each link.
            rOtoL = zeros(2,2);
            rOtoG = zeros(2,2);
            rOtoL(:,1) = origin + obj.rotMat(obj.prox.theta)*[obj.prox.l;0];
            rOtoG(:,1) = origin + obj.rotMat(obj.prox.theta)*[obj.prox.l/2;0];
            rOtoL(:,2) = rOtoL(:,2-1) + obj.rotMat(obj.prox.theta+obj.dist.theta)*[obj.dist.l;0];
            rOtoG(:,2) = rOtoG(:,2-1) + obj.rotMat(obj.prox.theta+obj.dist.theta)*[obj.dist.l/2;0];
        end
        function fc = getContactForces(obj,fa)
            % Computes the contact force at contact location due to the
            % kinetostatic analysis expressed in [x,y] coordinates.
            % @param fa Actuator force (N).
            % @param rOtoL Finger position vector.
            % @return fc Force exerted at contact location (N) in [x,y].
            thetaDot = [obj.prox.thetaDot; obj.dist.thetaDot];
            K = [obj.prox.k 0;
                 0 obj.dist.k];
            D = [obj.prox.d 0;
                 0 obj.dist.d];
            Ja = [obj.prox.r obj.dist.r];
            Jc = obj.computeJc();
            Je = obj.computeJe();
            springTau = K*([obj.prox.theta; obj.dist.theta]-[obj.prox.theta0; obj.dist.theta0]);
            damperTau = D*thetaDot;
            distTau = Je'*[obj.prox.fe; obj.dist.fe];
            actTau = Ja'*fa;
            % Compute forces normal to proximal and distal links.
            fcN = (inv(Jc')*-(springTau+damperTau+distTau+actTau));
            % Distal normal and tangential (0, no tangential force due to
            % actuation) forces and transform to [x,y] coordinate.
            fc = -obj.rotMat(obj.prox.theta+obj.dist.theta)*[0;fcN(2)];
        end
        function [xDot, fc] = eom(obj,initVal,fa)
            % Solves the equations of motion given the initial condition
            % initVal. The states x are: x1 = prox.theta, x2 = dist.theta, 
            % x3 = prox.thetaDot, x4 = dist.thetaDot. For more information
            % on the model consult: Murray, et.al. "A Mathematical
            % Introduction to Robotic Manipulation", for the dynamic model. 
            % Birglen, et.al. "Underactuated Robotic Hands". for the
            % kinetostatic model.
            % @param initVal intial value of the states.
            % @param fa the actuator force (cable tension).
            % @return xDot the first derivative of the states that solves
            % the intial value problem.
            obj.prox.theta = initVal(1);
            obj.dist.theta = initVal(2);
            obj.prox.thetaDot = initVal(3);
            obj.dist.thetaDot = initVal(4);
            thetaDot = [obj.prox.thetaDot; obj.dist.thetaDot];
            % Compute kinetostatic matrices.
            K = [obj.prox.k 0;
                 0 obj.dist.k];
            D = [obj.prox.d 0;
                 0 obj.dist.d];
            Ja = [obj.prox.r obj.dist.r];
            Jc = obj.computeJc();
            Je = obj.computeJe();
            % Compute matrix parameters.
            alpha = obj.prox.I + obj.dist.I + (obj.prox.m*(obj.prox.l/2)^2)+...
                    obj.dist.m*(obj.prox.l^2+(obj.dist.l/2)^2);
            beta = obj.dist.m*obj.prox.l*(obj.dist.l/2);
            delta = obj.dist.I+obj.dist.m*(obj.dist.l/2)^2;
            % Intertia matrix (M)
            M = [alpha+2*beta*cos(obj.dist.theta) delta+beta*cos(obj.dist.theta);
                delta+beta*cos(obj.dist.theta) delta];
            % Coriolis and Centrifugal matrix (C)
            C = [-beta*sin(obj.dist.theta)*obj.dist.thetaDot ...
                -beta*sin(obj.dist.theta)*(obj.prox.thetaDot+obj.dist.thetaDot);
                beta*sin(obj.dist.theta)*obj.prox.thetaDot 0];
            springTau = K*([obj.prox.theta; obj.dist.theta]-[obj.prox.theta0; obj.dist.theta0]);
            damperTau = D*thetaDot;
            contactTau = Jc'*[obj.prox.fc; obj.dist.fc];
            distTau = Je'*[obj.prox.fe; obj.dist.fe];
            actTau = Ja'*fa;
            % Compute angular acceleration
            thetaDotDot = inv(M)*(-C*thetaDot + springTau + damperTau + contactTau + distTau + actTau);
            xDot = [thetaDot; thetaDotDot];
        end
    end
    methods (Access = protected)
        function setupImpl(obj)
            % Set up routine. Performed once when setting up Simulink
            % model. Initializes the finger phalanges.
            obj.prox = Phalanx(obj.kP,obj.dP,obj.lP,obj.rP,obj.mP,obj.thetaP,1);
            obj.dist = Phalanx(obj.kD,obj.dD,obj.lD,obj.rD,obj.mD,obj.thetaD,2);
        end
        function [xDot, rOtoL, fc] = stepImpl(obj,initVal,fa,fc,fe,origin)
            % Step routine. Performed for every simulation step in
            % Simulink.
            % @param initVal intial value of the states used for the 
            % equation of motion.
            % @param fa the actuator force (cable tension).
            % @param fc Force at contact location (N).
            % @param fe Force at disturbance location (N).
            % @param origin the finger's origin [x,y] (m).
            % @return xDot the first derivative of the states that solves
            % the intial value problem in the equation of motion.
            % @return rOtoL vector from finger origin to link end, one 2D
            % vector for each link.
            % @return fc Force exerted at contact location (N).
            
            % External forces to internal ([x,y] to Normal)
            % Contact
            fcN = obj.rotMat(obj.prox.theta+obj.dist.theta)*fc;
            obj.dist.fc = fcN(1);
            % Disturbance
            feN = obj.rotMat(obj.prox.theta+obj.dist.theta)*fe;
            obj.dist.fe = feN(1);
            
            % Equation of motion
            xDot = obj.eom(initVal,fa);
            % Forward kinematics
            [rOtoL, ~] = obj.fKine(origin);
            % Exerted contact force.
            fc = obj.getContactForces(fa);
        end
    end
end