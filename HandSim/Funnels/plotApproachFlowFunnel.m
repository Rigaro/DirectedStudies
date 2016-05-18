%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Start offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% clear all
% t=0:0.01:3;
% tSize = size(t);
% for i=1:tSize(2)
%     theta(i,:) = posTrajectory(t(i));
%     thetaDot(i,:) = velTrajectory(t(i));
%     r_temp(i) = regOfAttractionGAC(theta(i,:)',thetaDot(i,:)');
% end
% r = r_temp';
% thetaR = theta(:,1);
% thetaDotR = thetaDot(:,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% End of offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
angle = linspace(0,2*pi);
rSize = size(r);
 % Compute surface
[x,y,z] = cylinder(real(r),rSize(1));
clear X Y Z
for i=1:size(r)
    X(i,:) = x(i,:)+thetaR(i);
    Y(i,:) = y(i,:)+thetaDotR(i);
end
Z = z*max(t);
figure(2)
hold on
% Plot mesh
s = surf(X,Y,Z);
set(s,'FaceColor','c');
set(s,'FaceAlpha',0.4);
set(s,'FaceLighting','none');
set(s,'LineStyle',':');
set(s,'LineWidth',0.1);
% Plot Trajectory
plot3(theta(:,1),thetaDot(:,1),t,'-k','LineWidth',2);
% Set Axis
axis equal
xlabel('$q$ (rad)', 'interpreter', 'latex')
ylabel('$\dot q$ (rad/s)', 'interpreter', 'latex')
zlabel('$t$ (sec)', 'interpreter', 'latex')
title('Approach Flow Funnel')