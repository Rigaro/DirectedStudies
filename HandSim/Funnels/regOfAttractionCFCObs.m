function r = regOfAttractionCFCObs(q,qDot,FcTilde)
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
    M = [alpha+2*beta*cos(q(2,1)) delta+beta*cos(q(2,1));
         delta+beta*cos(q(2,1)) delta];
    % Coriolis and Centrifugal matrix (C)
    C = [-beta*sin(q(2,1))*qDot(2,1) ...
         -beta*sin(q(2,1))*(qDot(1,1)+qDot(2,1));
         beta*sin(q(2,1))*qDot(1,1) 0];
    % Rayleigh damping
    D = [dP 0;
         0 dD];
    % Controller gains
%     Hp = [0.05, 0;
%           0, 0.05];
%     Hd = [0.16, 0;
%           0, 0.16];
%     Ki = [0.01, 0;
%           0, 0.01];
    Hp = [110, 0;
          0, 110];
    Hd = [1.5, 0;
          0, 1.5];
    Ki = [12, 0;
          0, 12];
    % Observer gains
    Kp = [50, 0;
          0, 50]; 
%     Kd = [0.1, 0;
%           0, 0.1]; 
%     Kd = 500;
    Kd = 500;
    % Calculate the region of attraction bounds
    % Calculate parameter kc
    if(norm(qDot)==0)
        kc = 0.0001;
    else
        kc = 2*norm(C)/norm(qDot);
    end
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
    r = (1/(2*kc))*sqrt(min(lambdaL)/max(lambdaL))*(Kd*min(lambdaM)+min(lambdaD)-(((max(lambdaHd)^2)/4)*((1/(min(lambdaD)+min(lambdaHd)-min(lambdaM)-(kc*FcTilde)))+(1/(min(lambdaHp)-min(lambdaKi))))));
end

