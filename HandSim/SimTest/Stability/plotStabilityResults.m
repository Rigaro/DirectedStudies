%%
% References:
% theta: -0.0931*u^3+0.4189*u^2+0.3142
% thetaDot: -3*0.0931*u^2+2*0.4189*u
% Plot velocities.
figure(1);
plot(t,thetaDot(:,1),'-k');
hold on
plot(t,thetaDotHat(:,1),'-r');
% plot(t,thetaDotDer(:,1),'-b');
hold off
axis tight
%%
% Plot proximal joint position with reference.
figure(2);
hold on
plot(t,theta(:,1),'-k');
plot(t,thetaR(:,1),'-r');
hold off
axis tight
%%
% Plot distal joint position with reference.
figure(3);
hold on
plot(t,theta(:,2),'-k');
plot(t,repmat(1.0824,size(t)),'-r');
hold off
axis tight
%%
figure(4);
hold on
qPestError = thetaDot(:,1)-thetaDotHat(:,1);
qDestError = thetaDot(:,2)-thetaDotHat(:,2);
plot(t,qPestError,'-k');
plot(t,qDestError,'-.k');
hold off
axis tight
%%
figure(5);
hold on
plot(t,Fc,'--k');
% plot(t,repmat(0.1,size(t)),'-k');
hold off
axis tight