function regOfAttraction(theta,thetaDot)
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
    % Controller gains
    Kp = [0.55, 0;
          0, 0.55];
    Kd = [0.015, 0;
          0, 0.015];
    % Calculate the region of attraction bounds
    % Calculate parameter kc
    kc = 2*norm(C)/norm(thetaDot);
    % Compute eigen values of M
    lambdaM = eig(M);
    % Calculate parameter kq
    kq = Kd(1,1)*min(lambdaM)/(2*kc);
    % Create L
    zero = zeros(size(M));
    Ltop = horzcat(Kp,zero);
    Lbot = horzcat(zero,M);
    L = vertcat(Ltop,Lbot);
    % Compute eigen values of L
    lambdaL = eig(L);
    % Get circle radius
    r = sqrt(min(lambdaL)/max(lambdaL))*((min(lambdaM)*Kd(1,1)/kc)-kq)
    angle = linspace(0,2*pi);
    x = r*cos(angle)+theta(1);
    y = r*sin(angle)+thetaDot(1);
    figure(2)
    hold on
    plot(x,y);
    axis([pi/10 pi/3 -0.01 0.01]);
end

