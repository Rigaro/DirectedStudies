classdef Object < handle
    properties (SetAccess = private)
        m % mass of the object
        cf % friction coefficient between the object and the finger
        cfl % friction coefficient between the object and the floor
        l % length of the object
        h % height of the object
    end
    methods
        function obj2 = Object(m,cf,cfl,l,h)
            if(nargin == 0)
                m=0.2;
                cf=0.45;
                cfl=0.35;
                l=0.02;
                h=0.02;
            else
                m=m;
                cf=cf;
                cfl=cfl;
                l=l;
                h=h;
            end
        end     
end