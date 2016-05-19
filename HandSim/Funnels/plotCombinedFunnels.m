%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Start offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Funnel 1
% clear all
[paramP, paramD] = cubicTrajectory();
t_ol=0:0.02:3;
tSize = size(t_ol);
for i=1:tSize(2)
    FcR1(i) = 0;
    theta1(i,:) = posTrajectory(paramP,paramD,t_ol(i));
    thetaDot1(i,:) = velTrajectory(paramP,paramD,t_ol(i));
    r_temp1(i) = regOfAttractionGACObs(theta1(i,:)',thetaDot1(i,:)');
end
r1 = r_temp1';
thetaR1 = theta1(:,1);
thetaDotR1 = thetaDot1(:,1);
% Funnel 2
th1Size = size(theta1);
thetaC = theta1(th1Size(1),:)';
for i=1:tSize(2)
    FcR2(i) = 0.2;
    theta2(i,:) = thetaC;
    thetaDot2(i,:) = [0,0];
    r_temp2(i) = regOfAttractionCFCObs(thetaC,thetaDot2(i,:)');
end
r2 = r_temp2';
thetaR2 = theta2(:,1);
thetaDotR2 = thetaDot2(:,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% End of offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute circles
% Funnel 1
angle = linspace(0,2*pi);
for i=1:size(r1)
    x1(i,:) = r1(i)*cos(angle)+thetaR1(i);
    y1(i,:) = r1(i)*sin(angle)+thetaDotR1(i);
end
% Funnel 2
for i=1:size(r2)
    x2(i,:) = r2(i)*cos(angle)+FcR2(i);
    y2(i,:) = r2(i)*sin(angle)+thetaDotR2(i);
end
% Only positive forces allowed
x2(x2<0) = 0;
%
figure(1)
hold on
% Plot circles 1
FcR1_resize = repmat(0,size(x1(1,:)));
for i=1:size(r1)
    circ1 = plot3(x1(i,:),y1(i,:),FcR1_resize,'-c');
end
% Plot circles 2
for i=1:size(r2)
    thetaR1_resize = repmat(thetaR1(i,1),size(x2(i,:)));
    circ2 = plot3(thetaR1_resize,y2(i,:),x2(i,:),'-m');
end
% Plot Trajectory 1
traj1 = plot3(thetaR1(:,1),thetaDotR1(:,1),FcR1,'-b','LineWidth',2);
% Plot Trajectory 2
traj2 = plot3(thetaR1(:,1),thetaDotR2(:,1),FcR2,'-r','LineWidth',2);
% plot real Trajectory
trajr = plot3(theta(:,1),thetaDot(:,1),Fc,'-k','LineWidth',2);
% Set Axis
axis equal tight
xlabel('$q$ (rad)', 'interpreter', 'latex')
ylabel('$\dot q$ (rad/s)', 'interpreter', 'latex')
zlabel('$Fc$ (N)', 'interpreter', 'latex')
title('Hybrid System Funnels')
legend([circ1,circ2,traj1,traj2,trajr],'Approach Flow Funnel',...
    'Contact Catch Funnel','Desired Position Trajectory','Desired Force',...
    'Finger Trajectory','Location','eastoutside');