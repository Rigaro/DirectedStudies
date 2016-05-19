function [paramP, paramD] = cubicTrajectory()
    startVel = 0; % rad/s
    endVel = 0; % rad/s
    startPos = pi/10; % rad
    endPos = pi/2; % rad
    startTime = 0; % seconds
    endTime = 3; % seconds
    eqnMat = [[startTime^3 startTime^2 startTime 1];
             [3*startTime^2 2*startTime 1 0];
             [endTime^3 endTime^2 endTime 1];
             [3*endTime^2 2*endTime 1 0]];
    solMat = [startPos; startVel; endPos; endVel];
    paramP = inv(eqnMat)*solMat;
    startVel = 0; % rad/s
    endVel = 0; % rad/s
    startPos = pi/3; % rad
    endPos = 1.2226; % rad
    eqnMat = [[startTime^3 startTime^2 startTime 1];
             [3*startTime^2 2*startTime 1 0];
             [endTime^3 endTime^2 endTime 1];
             [3*endTime^2 2*endTime 1 0]];
    solMat = [startPos; startVel; endPos; endVel];
    paramD = inv(eqnMat)*solMat;
end