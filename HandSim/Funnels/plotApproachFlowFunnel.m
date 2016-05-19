%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Start offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% clear all
% t=0:0.01:3;
[paramP, paramD] = cubicTrajectory();
tSize = size(t);
for i=1:tSize(1)
    theta1(i,:) = posTrajectory(paramP,paramD,t(i));
    thetaDot1(i,:) = velTrajectory(paramP,paramD,t(i));
    r_temp1(i) = regOfAttractionGACObs(theta1(i,:)',thetaDot1(i,:)');
end
r1 = r_temp1';
thetaR1 = theta1(:,1);
thetaDotR1 = thetaDot1(:,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% End of offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
angle = linspace(0,2*pi);
rSize = size(r1);
 % Compute surface
[x,y,z] = cylinder(real(r1),rSize(1));
clear X Y Z
zSize = size(z);
for i=1:size(r1)
    X(i,:) = x(i,:)+thetaR1(i);
    Y(i,:) = y(i,:)+thetaDotR1(i);
    zTemp = repmat(t(i),zSize(2));
    Z(i,:) = zTemp(1,:);
end
% Z = z*max(t);
figure(2)
hold on
% Plot mesh
s = surf(X,Y,Z);
set(s,'FaceColor','c');
set(s,'FaceAlpha',0.4);
set(s,'FaceLighting','none');
set(s,'LineStyle',':');
set(s,'LineWidth',0.1);
% Plot Desired Trajectory
traj1 = plot3(thetaR1(:,1),thetaDotR1(:,1),t,'-b','LineWidth',2);
% Plot real trajectory
trajr = plot3(theta(:,1),thetaDot(:,1),t,'-k','LineWidth',2);
% Set Axis
axis equal
xlabel('$q$ (rad)', 'interpreter', 'latex')
ylabel('$\dot q$ (rad/s)', 'interpreter', 'latex')
zlabel('$t$ (sec)', 'interpreter', 'latex')
title('Approach Flow Funnel')
legend([s,traj1,trajr],'Approach Flow Funnel','Desired Position Trajectory',...
    'Finger Trajectory','Location','eastoutside');