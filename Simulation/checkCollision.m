function [col, xCol, yCol] = checkCollision(object1, object2)
    % Create object polylines
    poly1 = object1.getPoly();
    poly2 = object2.getPoly();
    % Compute collision locations between the two objects
    [xCol, yCol] = polyxpoly(poly1(1,:),poly1(2,:),poly2(1,:),poly2(2,:));
    col = ~(isempty(xCol) & isempty(yCol));
end