%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Start offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% clear all
% t=0:0.01:3;
tSize = size(t);
qC = [pi/3;1.15];
j = 0;
for i=1:tSize(1)
    if(t(i)>1.84)
        j = j + 1;
        t_cut(j) = t(i);
        Fc_cut(j) = Fc(i);
        qDot_cut(j,1) = qDot(i,1);
        FcR2(j) = 0.2;
        qDot2(j,:) = [0,0];
%         r_temp2(j) = regOfAttractionCFCObs(qC,qDot2(j,:)');
    end
    FcR2_full(i) = 0.2;
    qDotR2_full(i,:) = [0,0];
end
% rCFC = r_temp2';
qDotR2 = qDot2(:,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% End of offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
angle = linspace(0,2*pi);
rSize = size(rCFC);
 % Compute surface
% [x,y,z] = cylinder(real(r2),rSize(1));
[x,y,z] = cylinder(real(rCFC));
clear X Y Z
for i=1:size(rCFC) 
    X(i,:) = x(i,:)+FcR2_full(i);
    Y(i,:) = y(i,:)+qDotR2_full(i);
end
% Only positive forces allowed
X(X<0) = 0;
Z = z*max(t);
figure(2)
hold on
% Plot mesh
s = surf(Z,X,Y);
set(s,'FaceColor','g');
set(s,'FaceAlpha',0.4);
set(s,'FaceLighting','none');
set(s,'LineStyle',':');
set(s,'LineWidth',0.1);
% Plot Desired Trajectory
traj2 = plot3(t_cut,FcR2,qDotR2(:,1),'-r','LineWidth',2);
% Plot real Trajectory
trajr = plot3(t_cut,Fc_cut,qDot_cut(:,1),'-k','LineWidth',2);
% Set Axis
axis equal
zlim([-1.05 1.05])
xlim([0 5])
ylabel('$Fc$ (N)', 'interpreter', 'latex')
zlabel('$\dot q$ (rad/s)', 'interpreter', 'latex')
xlabel('$t$ (sec)', 'interpreter', 'latex')
title('Contact Catch Funnel')
% legend([s,traj2,trajr],'Contact Catch Funnel','Desired Force Trajectory',...
%     'Finger Trajectory','Location','eastoutside');
legend([s,traj2],'Contact Catch Funnel','Desired Force Trajectory',...
    'Location','eastoutside');