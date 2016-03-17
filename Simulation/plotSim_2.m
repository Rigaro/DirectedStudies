fig = figure(1);
clf(fig);
% Create fingers
index = Finger();
thumb = Finger();
% Change finger data
index.setOrigin([0.01 0.01]);
thumb.setOrigin([-0.01 0.01]);
thumb.setTheta([pi-pi/10 ; -pi/3]);
thumb.setThetaRest([pi-pi/10 ; -pi/3]);
% Finger forward kinematics
index.fKine();
thumb.fKine();
% Plot finger
plotFinger(index,fig);
plotFinger(thumb,fig);
% Set figure axes
axis([-0.2 0.2 -0.05 0.2]);

% Set change in thetaa
index.setfa(-5);
thumb.setfa(1);
index.setbd(0.05);
index.setfe([-0.1;0]);
for i=1:20
    pause(0.1);
    clf(fig);
    index.updateKinematics();
    thumb.updateKinematics();
    % Plot finger
    plotFinger(index,fig);
    plotFinger(thumb,fig);
    % Set figure axes
    axis([-0.2 0.2 -0.05 0.2]);
    % Check for collisions
    hold on
    plotObject(0.04,0.04,0,0.1);
    [col, xCol, yCol] = checkCollision(index,thumb);
    hold on
    %viscircles([xCol, yCol],0.005,'Color', 'r','LineWidth',2);
    hold off
end