classdef Phalanx < handle
    % Phalanx Class
    % Represents the Phalanx of an underactuated Finger.
    properties (SetAccess = immutable)
        % Physical Phalanx properties
        k = 1;      % Joint stiffness (Nm/rad)
        l = 0.1;    % Link length (m)
        r = 0.02;   % Pulley radius (m)
        m = 0.02;   % Link mass (kg)
        I           % Link z-inertia
    end
    properties
        % Physical finger properties
        miuC = 0.8; % Coefficient of friction between phalanx and contact object.
        miuE = 0.8; % Coefficient of friction between phalanx and disturbance object.% Kinematic properties
        theta0 = pi/10; % Joint rest angle (rad)
        theta = pi/10; % Joint angle (rad)
        thetaDot = 0; % First derivative (velocity) of joint angle (rad/s)
        thetaDotDot = 0; % Second derivative (acceleration) of joint angle (rad/s^2)
        % Contact Kinematics properties
        a = 0; % Distance from joint to contact force (m)
        fc % Contact Force
        % Disturbance Kinematics properties
        b = 0; % Distance from joint to disturbance force (m)
        fe % Disturbance Force
    end
    methods
        function obj = Phalanx(k, l, r, m, theta, linkNum)
            % Constructor with parameter initialization
            
            % Custom initialization
            if(nargin ~= 0)
                obj.k = k;
                obj.l = l;
                obj.r = r;
                obj.m = m;
                obj.theta = theta;
                if (linkNum>1)
                    obj.I = obj.m*(obj.l^2)/12;
                else
                    obj.I = obj.m*(obj.l^2)/3;
                end
            else
                obj.I = obj.m*(obj.l^2)/3;
            end
            obj.theta0 = obj.theta;
            obj.fc = ForceNormal(0,obj.a,obj.miuC);
            obj.fe = ForceNormal(0,obj.b,obj.miuE);
        end
    end
end