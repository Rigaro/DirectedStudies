clear all
t=0:0.01:3;
[paramP, paramD] = cubicTrajectory();
tSize = size(t);
for i=1:tSize(2)
    q(i,:) = posTrajectory(paramP,paramD,t(i));
    qDot(i,:) = velTrajectory(paramP,paramD,t(i));
end
% Compute region of atttraction
r = regOfAttractionGACObs_Kd(q(100,:)',qDot(100,:)',0,700);
%
% Compute circle
% Funnel 1
angle = linspace(0,2*pi);
x = real(r)*cos(angle);
y = real(r)*sin(angle);
hold on
circ = plot(x,y,'-g');
hold off