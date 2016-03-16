% Finger class
% Author: Ricardo Garcia Rosas

classdef Finger < handle
    properties (SetAccess = private)
        origin % Finger origin location (m)
        Kp % Proximal joint stiffness (Nm/rad)
        Kd % Distal joint stiffness (Nm/rad)
        K % Joint stiffness matrix
        lp % Proximal link length (m)
        ld % Distal link length (m)
        rp % Proximal pulley radius (m)
        rd % Distal pulley radius (m)
        % Finger Kinematics
        theta0 % Proximal (1) and Distal (2) joint rest angles (rad)
        theta % Proximal (1) and Distal (2) joint angles (rad)
        thetaa % Actuator pulley angle (rad)
        dtheta % Change in Proximal (1) and Distal (2) joint angles (rad/s)
        dthetaa % Change in Actuator pulley angle (rad/s)
        Ja % Actuator Jacobian
        fa % actuator force
        r_op % Distance from origin to end of proximal [x;y] (m)
        r_od % Distance from origin to end of distal (fingertip) [x;y] (m)
        % Contact Kinematics
        ad % Distance from Distal joint to Distal contact force (m)
        ap % Distance from Proximal joint to Proximal contact force (m)
        dad % Change in Distal contact force (m/s)
        dap % change in Proximal contact force (m/s)
        Jc % Contact jacobian
        fc % Contact force
        % External forces
        bd % Distance from Distal joint to Distal disturbance force (m)
        bp % Distance from Proximal joint to Proximal disturbance force (m)
        Je % Disturbance Jacobian
        fe % External force vector [x;y]
        % Special properties
        poly % Polyline parameters for collision detetion [x[];y[]]
    end
    methods
        % Constructor with parameter initialization
        function obj = Finger(origin, Kp, Kd, lp, ld, rp, rd, thetap, thetad)
            % Default initialization
            if(nargin == 0)
                obj.origin = [0 0];
                obj.Kp = 1;
                obj.Kd = 5;
                obj.lp = 0.1;   
                obj.ld = 0.1;
                obj.rp = 0.02;  
                obj.rd = 0.012;  
                obj.theta = [pi/10 ; pi/3];
            % Custom initialization
            else
                obj.origin = origin;
                obj.Kp = Kp;
                obj.Kd = Kd;
                obj.lp = lp;   
                obj.ld = ld;
                obj.rp = rp;  
                obj.rd = rd;  
                obj.theta = [thetap;thetad];     
            end
            % Kinematic values initialization
            obj.K = [obj.Kp 0;
                     0 obj.Kd];
            obj.theta0 = obj.theta;
            obj.thetaa = 0;
            obj.dthetaa = 0;
            obj.dtheta = [0; 0];
            obj.Ja = [obj.rp obj.rd];
            obj.fa = 0;
            % Contact Kinematics
            obj.ad = 0; % Distance from Distal joint to Distal contact force (m)
            obj.ap = 0; % Distance from Proximal joint to Proximal contact force (m)
            obj.dad = 0;% Change in Distal contact force (m/s)
            obj.dap = 0;% change in Proximal contact force (m/s)
            obj.updateJc(); % Contact jacobian (only Distal contact)
            % External forces
            obj.bd = 0;% Distance from Distal joint to Distal disturbance force (m)
            obj.bp = 0;% Distance from Proximal joint to Proximal disturbance force (m)
            obj.updateJe(); % Disturbance jacobian (only Distal contact)
            obj.fe = Force(0,0,0,0);
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
        % Set Distal contact force location
        function setad(obj, ad)
            obj.ad = ad;
        end
        % Set Distal contact force location change
        function setDad(obj, dad)
            obj.dad = dad;
        end
        % Set Distal disturbance force location
        function setbd(obj, bd)
            obj.bd = bd;
        end
        % Set disturbance force
        function setfe(obj, fe)
            obj.fe = fe;
        end
        % Update contact jacobian
        function updateJc(obj)
            obj.Jc = [-obj.lp*sin(obj.theta(1))-obj.ad*sin(obj.theta(1)+obj.theta(2)), ...
                      -obj.ad*sin(obj.theta(1)+obj.theta(2)), cos(obj.theta(1)+obj.theta(2));
                      [obj.lp*cos(obj.theta(1))+obj.ad*cos(obj.theta(1)+obj.theta(2)), ...
                      obj.ad*cos(obj.theta(1)+obj.theta(2)), sin(obj.theta(1)+obj.theta(2))]];                     
        end
        % Update disturbance jacobian
        function updateJe(obj)
            obj.Je = [-obj.lp*sin(obj.theta(1))-obj.bd*sin(obj.theta(1)+obj.theta(2)), ...
                      -obj.bd*sin(obj.theta(1)+obj.theta(2));
                      obj.lp*cos(obj.theta(1))+obj.bd*cos(obj.theta(1)+obj.theta(2)), ...
                      obj.bd*cos(obj.theta(1)+obj.theta(2))];
        end
        % Forward kinematics
        function [r_op, r_od] = fKine(obj)
            % Update Jacobians
            obj.updateJc();
            obj.updateJe();
            % Distance from origin to end of Proximal link
            obj.r_op = obj.origin'+[obj.lp*cos(obj.theta(1)) ; obj.lp*sin(obj.theta(1))]; 
            % Distance from origin to end of Distal link (fingertip)
            obj.r_od = obj.origin'+[obj.lp*cos(obj.theta(1))+obj.ld*cos(obj.theta(1)+obj.theta(2));
                        obj.lp*sin(obj.theta(1))+obj.ld*sin(obj.theta(1)+obj.theta(2))];
            r_op = obj.r_op;
            r_od = obj.r_od;
        end
        % Update change in theta under force control condition (FC)
        function updateDynamicsFC(obj)
            obj.updateJe();
            obj.dtheta = inv(obj.K)*(-obj.Je'*obj.fe-obj.Ja'*obj.fa);
        end
        % Update kinematics from actuator angle change
        function updateKinematics(obj)
            % Compute change in theta from change in actuator angle
            %obj.dtheta = obj.Ja'*obj.dthetaa;
            obj.updateDynamicsFC();
            obj.theta = obj.theta + obj.dtheta;
            obj.fKine();
        end
        function poly = getPoly(obj)
            obj.fKine();
            poly = [obj.origin(1),obj.r_op(1),obj.r_od(1);
                    obj.origin(2),obj.r_op(2),obj.r_od(2)];
        end
    end
end