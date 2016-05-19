function traj = posTrajectory(paramP,paramD,t)
traj = [paramP(1)*t^3+paramP(2)*t^2+paramP(3)*t+paramP(4),paramD(1)*t^3+paramD(2)*t^2+paramD(3)*t+paramD(4)];
end