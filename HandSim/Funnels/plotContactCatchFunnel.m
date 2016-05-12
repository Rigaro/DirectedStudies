%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Start offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all
t=0:0.01:3;
tSize = size(t);
thetaC = [pi/3;1.15];
for i=1:tSize(2)
    FcR(i) = 0.1;
    thetaDot(i,:) = [0,0];
    r_temp(i) = regOfAttractionCFC(thetaC,thetaDot(i,:)');
end
r = r_temp';
thetaDotR = thetaDot(:,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% End of offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
angle = linspace(0,2*pi);
rSize = size(r);
 % Compute surface
[x,y,z] = cylinder(real(r),rSize(1));
clear X Y Z
for i=1:size(r) 
    X(i,:) = x(i,:)+FcR(i);
    Y(i,:) = y(i,:)+thetaDotR(i);
end
% Only positive forces allowed
X(X<0) = 0;
Z = z*max(t);
figure(2)
hold on
% Plot mesh
s = surf(X,Y,Z);
set(s,'FaceColor','m');
set(s,'FaceAlpha',0.4);
set(s,'FaceLighting','none');
set(s,'LineStyle',':');
set(s,'LineWidth',0.1);
% Plot Trajectory
plot3(FcR,thetaDotR(:,1),t,'-r','LineWidth',2);
% Set Axis
axis equal
xlabel('$Fc$ (N)', 'interpreter', 'latex')
ylabel('$\dot q$ (rad/s)', 'interpreter', 'latex')
zlabel('$t$ (sec)', 'interpreter', 'latex')
title('Contact Catch Funnel')