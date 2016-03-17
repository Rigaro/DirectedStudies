classdef Force < handle
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties (SetAccess = private)
        fv % Force vector [x;y]
        o % Force vector origin [x,y] location
    end
    
    methods
        function obj = Force(fx, fy, x, y)
            obj.fv = [fx;fy];
            obj.o = [x,y];
        end
        function setForceV(obj,fv)
            obj.fv = fv;
        end
        function setForceX(obj,fx)
            fvec = obj.fv;
            obj.fv = [fx;fvec(2,1)];
        end
        function setForceY(obj,fy)
            fvec = obj.fv;
            obj.fv = [fvec(1,1),fy];
        end
        function setPos(obj,pos)
        end
    end
    
end

