%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Start offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% clear all
% t=0:0.01:3;
[paramP, paramD] = cubicTrajectory();
tSize = size(t);
for i=1:tSize(1)
    q1(i,:) = posTrajectory(paramP,paramD,t(i));
    qDot1(i,:) = velTrajectory(paramP,paramD,t(i));
%     r_temp1(i) = regOfAttractionGACObs(q1(i,:)',qDot1(i,:)');
end
% rGAC = r_temp1';
qR1 = q1(:,1);
qDotR1 = qDot1(:,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% End of offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
angle = linspace(0,2*pi);
rSize = size(rGAC);
 % Compute surface
% [x,y,z] = cylinder(real(rGAC),rSize(1));
[x,y,z] = cylinder(real(rGAC));
clear X Y Z
zSize = size(z);
for i=1:size(rGAC)
    X(i,:) = x(i,:)+qR1(i);
    Y(i,:) = y(i,:)+qDotR1(i);
    zTemp = repmat(t(i),zSize(2));
    Z(i,:) = zTemp(1,:);
end
% Z = z*max(t);
figure(2)
hold on
% Plot mesh
s = surf(Z,X,Y);
set(s,'FaceColor','c');
set(s,'FaceAlpha',0.4);
set(s,'FaceLighting','none');
set(s,'LineStyle',':');
set(s,'LineWidth',0.1);
% Plot Desired Trajectory
traj1 = plot3(t,qR1(:,1),qDotR1(:,1),'-b','LineWidth',2);
% Plot real trajectory
% trajr = plot3(q(:,1),qDot(:,1),t,'-k','LineWidth',2);
% Set Axis
axis equal
ylabel('$q$ (rad)', 'interpreter', 'latex')
zlabel('$\dot q$ (rad/s)', 'interpreter', 'latex')
xlabel('$t$ (sec)', 'interpreter', 'latex')
title('Approach Flow Funnel')
% legend([s,traj1,trajr],'Approach Flow Funnel','Desired Position Trajectory',...
%     'Finger Trajectory','Location','eastoutside');
legend([s,traj1],'Approach Flow Funnel','Desired Position Trajectory',...
    'Location','eastoutside');