function traj = velTrajectory(paramP,paramD,t)
traj = [3*paramP(1)*t^2+2*paramP(2)*t+paramP(3),3*paramD(1)*t^2+2*paramD(2)*t+paramD(3)];
end

