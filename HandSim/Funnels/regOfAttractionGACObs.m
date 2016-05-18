function r = regOfAttractionGAC(theta,thetaDot)
    % Set model variables:
    kP = 0.043;
    kD = 0.185;
    dP = 0.01;
    dD = 0.01;
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
    IP = mP*(lP^2)/3;
    ID = mD*(lD^2)/12;
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
    % Rayleigh damping
    D = [dP 0;
         0 dD];
    % Controller gains
    Hp = [5.8, 0;
          0, 5.8];
    Hd = [0.03, 0;
          0, 0.03];
    Ki = [1, 0;
          0, 1];
    % Observer gain
    Kp = [5.8, 0;
          0, 5.8]; 
%     Kd = [0.1, 0;
%           0, 0.1]; 
    Kd = 500;
    % Calculate the region of attraction bounds
    % Calculate parameter kc
    kc = 2*norm(C)/norm(thetaDot);
    % Compute eigen values of M and Kd
    lambdaM = eig(M);
    lambdaHp = eig(Hp);
    lambdaHd = eig(Hd);
    lambdaKi = eig(Ki);
    % Calculate parameter kq
    kq = min(lambdaHd)*min(lambdaM)/(2*kc);
    % Create L
    zero = zeros(size(M));
    one = ones(size(M));
    L1 = horzcat(Hp+D+Hd,M,zero,zero,-one);
    L2 = horzcat(M,M,zero,zero,zero);
    L3 = horzcat(zero,zero,Kp,zero,zero);
    L4 = horzcat(zero,zero,zero,M,zero);
    L5 = horzcat(-one,zero,zero,zero,inv(Ki));
    L = vertcat(L1,L2,L3,L4,L5);
    % Compute eigen values of L and D
    lambdaL = eig(L);
    lambdaD = eig(D);
    % Get circle radius
    r = (1/(2*kc))*sqrt(min(lambdaL)/max(lambdaL))*(Kd*min(lambdaM)+min(lambdaD)-(((max(lambdaHd)^2)/4)*((1/(min(lambdaD)+min(lambdaHd)-min(lambdaM)))+(1/(min(lambdaHp)-min(lambdaKi))))));
    %r = 0.01;
% 	angle = linspace(0,2*pi);
%     x = r*cos(angle)+thetaR;
%     y = r*sin(angle)+(pi/30);
%     [th,r,t] = meshgrid(angle,repmat(rho,size(angle)),time);
%     x = r.*cos(th)+thetaR;
%     y = r.*sin(th)+(pi/30);
%     figure(2)
%     hold on
%     surf(real(x),real(y),t)
%     plot3(x,y,repmat(time,size(angle)),'-m');
%     plot3(theta(1),thetaDot(1),time,'.k');
%     axis([0.3 0.44 -0.005 0.13 0 1]);
end

