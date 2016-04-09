% Finger Simulink function.
% Represents an underactuated cable driven finger.
% The finger is composed of two phalanges driven by a tendon-pulley
% mechanism. This has methods for calculating the kinematics and
% dynamics of the system.
% Author: Ricardo Garcia Rosas
% Change log:
%%%%%%%%%%%%|%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|
% Date      |   Author  | Notes                                     |
% 16/03/23  |   RGR     | Added more comments.                      |
% 16/03/24  |   RGR     | Compute fc and transform to [x,y].        |
% 16/04/06  |   RGR     | Removed force class, using only magnitude.|
% 16/04/09  |   RGR     | Removed classes and opted for functions.  |

function [ xDot, rOtoL, iFcComp ] = Finger( iInitVal,iFa,iFcSense,iFeDist,iO )

    % Set initial condition:
    theta = [iInitVal(1); iInitVal(2)];
    thetaDot = [iInitVal(3); iInitVal(4)];
    % Transform forces:
    % Contact force
    fcTN = rotMat(theta(1,1)+theta(2,1))'*iFcSense;
    fcD = fcTN(2,1);
    % Disturbance force
    feTN = rotMat(theta(1,1)+theta(2,1))'*iFeDist;
    feD = feTN(2,1);
    % Set model variables:
    kP = -0.043;
    kD = -0.185;
    dP = -0.01;
    dD = -0.01;
    lP = 0.1;
    lD = 0.1;
    rP = 0.02;
    rD = 0.012;
    aP = 0.1;
    aD = 0.1;
    bP = 0.05;
    bD = 0.05;
    mP = 0.02;
    mD = 0.02;
    theta0 = [pi/10;pi/3];
    IP = mP*(lP^2)/3;
    ID = mD*(lD^2)/12;
    % Set matrices
    K = [kP 0;
         0 kD];
    D = [dP 0;
         0 dD];
    Ja = [rP rD];
    Jc = [aP, 0;
          aD+lP*cos(theta(2,1)),aD];
    Je = [bP, 0;
          bD+lP*cos(theta(2,1)),bD]; 

    % Forward kinematics to link ends and centre of gravity.
    % rOtoL vector from finger origin to link end, one 2D
    % vector for each link.
    % rOtoG vector from finger origin to link center of
    % gravity, one 2D vector for each link.
    rOtoL = zeros(2,2);
    rOtoG = zeros(2,2);
    rOtoL(:,1) = iO + rotMat(theta(1,1))*[lP;0];
    rOtoG(:,1) = iO + rotMat(theta(1,1))*[lP/2;0];
    rOtoL(:,2) = rOtoL(:,2-1) + rotMat(theta(1,1)+theta(2,1))*[lD;0];
    rOtoG(:,2) = rOtoG(:,2-1) + rotMat(theta(1,1)+theta(2,1))*[lD/2;0];
    
    % Dyniamics
    % Compute matrix parameters.
    alpha = IP + ID + (mP*(lP/2)^2) + mD*(lP^2+(lD/2)^2);
    beta = mD*lP*(lD/2);
    delta = ID+mD*(lD/2)^2;
    % Intertia matrix (M)
    M = [alpha+2*beta*cos(theta(2,1)) delta+beta*cos(theta(2,1));
         delta+beta*cos(theta(2,1)) delta];
    % Coriolis and Centrifugal matrix (C)
    C = [-beta*sin(theta(2,1))*thetaDot(2,1) ...
         -beta*sin(theta(2,1))*(thetaDot(1,1)+thetaDot(2,1));
         beta*sin(theta(2,1))*thetaDot(1,1) 0];
    % Torques
    springTau = K*(theta-theta0);
    damperTau = D*thetaDot;
    contactTau = Jc'*[0; fcD];
    distTau = Je'*[0; feD];
    actTau = Ja'*iFa;
    % Compute angular acceleration
    thetaDotDot = inv(M)*(-C*thetaDot + springTau + damperTau + contactTau + distTau + actTau);
    xDot = [thetaDot; thetaDotDot];
    % Compute applied contact force give a static condition. (Kinetostatic)
    % Compute forces normal to proximal and distal links.
    fcComp = (inv(Jc')*-(springTau+damperTau+distTau+actTau));
    % Distal normal and tangential (0, no tangential force due to
    % actuation) forces and transform to [x,y] coordinate.
    iFcComp = -rotMat(theta(1,1)+theta(2,1))*[0;fcComp(2)];
end
        function rot = rotMat(theta)
            % 2D Z-Rotation matrix on theta.
            % @param theta the angle
            % @return rot the rotation matrix as a 2x2 matrix.
            rot = [cos(theta) -sin(theta);
                   sin(theta) cos(theta)];
        end
