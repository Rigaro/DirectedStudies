%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Start offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% clear all
% t=0:0.01:3;
tSize = size(t);
thetaC = [pi/3;1.15];
j = 0;
for i=1:tSize(1)
    if(t(i)>1.84)
        j = j + 1;
        t_cut(j) = t(i);
        Fc_cut(j) = Fc(i);
        thetaDot_cut(j,1) = thetaDot(i,1);
        FcR2(j) = 0.2;
        thetaDot2(j,:) = [0,0];
        r_temp2(j) = regOfAttractionCFCObs(thetaC,thetaDot2(j,:)');
    end
end
r2 = r_temp2';
thetaDotR2 = thetaDot2(:,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% End of offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
angle = linspace(0,2*pi);
rSize = size(r2);
 % Compute surface
[x,y,z] = cylinder(real(r2),rSize(1));
clear X Y Z
for i=1:size(r2) 
    X(i,:) = x(i,:)+FcR2(i);
    Y(i,:) = y(i,:)+thetaDotR2(i);
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
% Plot Desired Trajectory
traj2 = plot3(FcR2,thetaDotR2(:,1),t_cut,'-r','LineWidth',2);
% Plot real Trajectory
trajr = plot3(Fc_cut,thetaDot_cut(:,1),t_cut,'-k','LineWidth',2);
% Set Axis
axis equal
ylim([-1.05 1.05])
zlim([1.84 5])
xlabel('$Fc$ (N)', 'interpreter', 'latex')
ylabel('$\dot q$ (rad/s)', 'interpreter', 'latex')
zlabel('$t$ (sec)', 'interpreter', 'latex')
title('Contact Catch Funnel')
legend([s,traj2,trajr],'Contact Catch Funnel','Desired Force Trajectory',...
    'Finger Trajectory','Location','eastoutside');