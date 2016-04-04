fig = figure(1);
clf(fig);
% Create fingers
index = Finger();
thumb = Finger([-0.01 0.01], 1, 5, 0.1, 0.1, 0.02, 0.012, 0.02, 0.02, pi-pi/10, pi-pi/3, 0);

% Change finger data
index.setOrigin([0.01 0.01]);
% Finger forward kinematics
index.fKine();
thumb.fKine();
% Plot finger
plotFinger(index,fig);
plotFinger(thumb,fig);
% Set figure axes
axis([-0.2 0.2 -0.05 0.2]);

% Set change in thetaa
index.setFa(-10);
thumb.setFa(1);
index.phalanx(2).b = 0.05;
thumb.phalanx(2).b = 0.05;
% index.fe.setForceV([-0.1;0]);
options = odeset('RelTol',1e-4);
% Initial conditions
xInit = [index.phalanx(1).theta,index.phalanx(2).theta,index.phalanx(1).thetaDot,index.phalanx(2).thetaDot];
% Simulation time
tSpan = [0,2];
% Solve ODE
solIndex = ode45(@index.eom,tSpan,xInit,options);
dt = 0.34;
t = 0:dt:solIndex.x(end);
xIndex = deval(solIndex,t);
for i=1:length(t)
    clf(fig);
    % Plot finger
    plotFinger(index,fig);
    plotFinger(thumb,fig);
    % Set figure axes
    axis([-0.2 0.2 -0.05 0.2]);
    % Check for collisions
%     [col, xCol, yCol] = checkCollision(index,thumb);
%     hold on
%     viscircles([xCol, yCol],0.005,'Color', 'r','LineWidth',2);
%     hold off
    pause(0.1);
end