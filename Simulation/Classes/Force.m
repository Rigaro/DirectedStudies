classdef Force < handle
    % Force Class
    % Represents a force vector [fx; fy] in a [x, y] location.
    
    properties (SetAccess = private)
        fv % Force vector [fx;fy]
        o % Force vector origin [x,y] location
    end
    
    methods
        function obj = Force(fx, fy, x, y)
            % Creates a new Force object
            obj.fv = [fx;fy];
            obj.o = [x,y];
        end
        function setForceV(obj,fv)
            % Set the Force vector [fx;fy]
            obj.fv = fv;
        end
        function setForceX(obj,fx)
            % Set the Force in the x direction
            fvec = obj.fv;
            obj.fv = [fx;fvec(2,1)];
        end
        function setForceY(obj,fy)
            % Set the Force in the y direction
            fvec = obj.fv;
            obj.fv = [fvec(1,1),fy];
        end
        function setPos(obj,pos)
            % Set the location where the Force is acting
            obj.o = pos;
        end
    end
    
end

