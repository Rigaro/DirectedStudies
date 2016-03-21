classdef ForceNormal < handle
    % ForceNormal class
    % Represents a Force vector [fn,ft] acting on a Finger at a distance
    % d from a joint. fn represents the Force normal to the finger and
    % ft the tangential Force due to friction miu.
    properties (SetAccess = private)
        fv % Force vector [fn;ft]
        d % Distance from joint to Force (m)
    end
    methods
        function obj = ForceNormal(fn,d,miu)
            % Create a new ForceFinger object
            obj.fv = [fn;miu*fn];
            obj.d = d;
        end
        function setD(obj,d)
            % Set the distance from the joint to the Force
            obj.d = d;
        end
        function setForceV(obj,fn,miu)
            % Set the Force vector [fx;fy]
            obj.fv = [fn;miu*fn];
        end
    end
end