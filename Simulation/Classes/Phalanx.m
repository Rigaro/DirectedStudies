% Phalanx Class
% Represents the phalanx of a robotic hand finger.
% Contains the properties that represent the physical properties of a
% robotic hand phalanx, as well as the external forces acting on it.
% Change log:
%%%%%%%%%%%%|%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|
% Date      |   Author  | Notes                                     |
% 16/03/23  |   RGR     | Added more comments.                      |

classdef Phalanx < handle
% Phalanx Class
% Represents the phalanx of a robotic hand finger.
% Contains the properties that represent the physical properties of a
% robotic hand phalanx, as well as the external forces acting on it.
    properties (SetAccess = immutable)
        % Physical Phalanx properties
        k = 1;      % Joint stiffness (Nm/rad)
        d = 0.01    % Joint damping coefficient (Nm/(rad/s))
        l = 0.1;    % Link length (m)
        r = 0.02;   % Pulley radius (m)
        m = 0.02;   % Link mass (kg)
        I           % Link z-inertia
    end
    properties
        % Physical phalanx properties
        miuC = 0.8; % Coefficient of friction between phalanx and contact object.
        miuE = 0.8; % Coefficient of friction between phalanx and disturbance object.% Kinematic properties
        theta0 = pi/10; % Joint rest angle (rad)
        theta = pi/10; % Joint angle (rad)
        thetaDot = 0; % First derivative (velocity) of joint angle (rad/s)
        thetaDotDot = 0; % Second derivative (acceleration) of joint angle (rad/s^2)
        % Contact Kinematics properties
        a = 0.1; % Distance from joint to contact force (m)
        fc = 0% Contact Force, Normal to finger.
        % Disturbance Kinematics properties
        b = 0.05; % Distance from joint to disturbance force (m)
        fe = 0% Disturbance Force, Normal to finger.
    end
    methods
        function obj = Phalanx(k, d, l, r, m, theta, linkNum)
            % Constructor with parameter initialization
            % @param linkNum the link number in the chain.
            
            % Custom initialization
            if(nargin ~= 0)
                obj.k = k;
                obj.d = d;
                obj.l = l;
                obj.r = r;
                obj.m = m;
                obj.theta = theta;
                % Compute intertia matrix depending on which part of the
                % chain the link is.
                if (linkNum>1)
                    obj.I = obj.m*(obj.l^2)/12;
                else
                    obj.I = obj.m*(obj.l^2)/3;
                end
            else
                obj.I = obj.m*(obj.l^2)/3;
            end
            obj.theta0 = obj.theta;
            obj.thetaDot = 0;
            obj.thetaDotDot = 0;
            obj.fc = 0;
            obj.fe = 0;
        end
    end
end