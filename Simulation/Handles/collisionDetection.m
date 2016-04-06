% Handles collision detection between fingertips and Cylinder. 
% Handled in Simulink.
% Author: Ricardo Garcia Rosas
% Change log:
%%%%%%%%%%%%|%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|
% Date      |   Author  | Notes                                     |
% 16/04/06  |   RGR     | Created.                                  |
function [iCol,iColPos,tCol,tColPos] = collisionDetection(irOtoL,trOtoL,xPosG3,yPosG3,R)
    % Handles collision detection between fingertips and Cylinder.
    % Performed by comparing object radius.
    
    % Get circle radius given object center and fingertip position.
    ri = sqrt((irOtoL(1,1)-xPosG3)^2+(irOtoL(2,1)-yPosG3)^2);
    ti = sqrt((trOtoL(1,1)-xPosG3)^2+(trOtoL(2,1)-yPosG3)^2);
    % Verify calculated radius with object radius to define collision.
    if(ri<=R)
        iCol = true;
        iColPos = irOtoL;
    else
        iCol = false;
        iColPos = [0;0];
    end
    if(ti<=R)
        tCol = true;
        tColPos = trOtoL;
    else
        tCol = false;
        tColPos = [0;0];
    end
    
end