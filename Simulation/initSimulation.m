fig = figure(1);
clf(fig);
% Create fingers
% global index;
% global thumb;
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