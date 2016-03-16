function [col, xCol, yCol] = checkCollision(finger1, finger2)
    % Create finger polylines
    fin1X = [finger1.origin(1) finger1.r_op(1) finger1.r_od(1)];
    fin1Y = [finger1.origin(2) finger1.r_op(2) finger1.r_od(2)];
    fin2X = [finger2.origin(1) finger2.r_op(1) finger2.r_od(1)];
    fin2Y = [finger2.origin(2) finger2.r_op(2) finger2.r_od(2)];
    [xCol, yCol] = polyxpoly(fin1X,fin1Y,fin2X,fin2Y);
    col = ~(isempty(xCol) & isempty(yCol));
end