%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Start offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Funnel 1
% clear all
[paramP, paramD] = cubicTrajectory();
%t_ol=0:0.02:3;
t_ol = t;
tSize = size(t_ol);
j = 0;
for i=1:tSize(1)
    q1(i,:) = posTrajectory(paramP,paramD,t_ol(i));
    if(t(i)<1.84)
        FcR1(i) = 0;
        q1_cut(i,:) = posTrajectory(paramP,paramD,t_ol(i));
        qDot1(i,:) = velTrajectory(paramP,paramD,t_ol(i));
    elseif(t(i)>1.84&&j==0)
        tIndex = i;
        j = 1;
    end
%     r_tempGAC(i) = regOfAttractionGACObs(q1(i,:)',qDot1(i,:)');
end
% rGAC = r_tempGAC';
qR1 = q1_cut(:,1);
qDotR1 = qDot1(:,1);
% Funnel 2
q1Size = size(q1_cut);
qC = q1_cut(q1Size(1),:)';
for i=1:tSize(1)
    FcR2(i) = 0.2;
    q2(i,:) = qC;
    qDot2(i,:) = [0,0];
%     r_tempCFC(i) = regOfAttractionCFCObs(qC,qDot2(i,:)');
end
% rCFC = r_tempCFC';
% qR2 = q2(:,1);
qR2 = q;
qDotR2 = qDot2(:,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% End of offline computation %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
% Compute circles
% Funnel 1
angle = linspace(0,2*pi);
rGACSize = size(FcR1);
for i=1:rGACSize(2)
    x1(i,:) = real(rGAC(i))*cos(angle)+q1_cut(i);
    y1(i,:) = real(rGAC(i))*sin(angle)+qDotR1(i);
end
% Funnel 2
rCFCSize = size(rCFC);
for i=1:rCFCSize(1)
    x2(i,:) = real(rCFC(i))*cos(angle)+FcR2(i);
    y2(i,:) = real(rCFC(i))*sin(angle)+qDotR2(i);
end
% Only positive forces allowed
x2(x2<0) = 0;
%
figure(1)
hold on
% Plot circles 1
FcR1_resize = repmat(0,size(x1(1,:)));
for i=1:rGACSize(2)
    circ1 = plot3(x1(i,:),y1(i,:),FcR1_resize,'-c');
end
% Plot circles 2
for i=tIndex:rCFCSize(1)
%     qR1_resize = repmat(q1(i,1),size(x2(i,:)));
    qR2_resize = repmat(qR2(i,1),size(x2(i,:)));
    circ2 = plot3(qR2_resize,y2(i,:),x2(i,:),'-g');
end
% Plot Trajectory 1
traj1 = plot3(qR1(:,1),qDotR1(:,1),FcR1,'-b','LineWidth',2);
% Plot Trajectory 2
traj2 = plot3(qR2(:,1),qDotR2(:,1),FcR2,'-r','LineWidth',2);
% plot real Trajectory
trajr = plot3(q(:,1),qDot(:,1),Fc,'-k','LineWidth',2);
% Set Axis
axis equal tight
xlabel('$q$ (rad)', 'interpreter', 'latex')
ylabel('$\dot q$ (rad/s)', 'interpreter', 'latex')
zlabel('$Fc$ (N)', 'interpreter', 'latex')
title('Hybrid System Funnels')
legend([circ1,circ2,traj1,traj2,trajr],'Approach Flow Funnel',...
    'Contact Catch Funnel','Desired Position Trajectory','Desired Force',...
    'Finger Trajectory','Location','eastoutside');