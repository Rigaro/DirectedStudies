classdef ForceFinger < Force
    % ForceFinger class
    % Represents a Force vector [fn,ft] acting on a Finger at a distance
    % d from a joint. fn represents the Force normal to the finger and
    % ft the tangential Force due to friction miu.
    properties (SetAccess = private)
        d % Distance from joint to Force (m)
    end
    methods
        function obj = ForceFinger(fn,d,miu)
            % Create a new ForceFinger object
            obj.fv = [fn;miu*fn];
            obj.d = d;
        end
        function setD(obj,d)
            % Set the distance from the joint to the Force
            obj.d = d;
        end
    end
end