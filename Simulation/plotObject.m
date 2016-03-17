function [ ] = plotObject(l,h,centerx,centery)
    %Calculations for the polyarea
    minx = centerx - l/2
    maxx = centerx + l/2
    miny = centery - h/2
    maxy = centery + h/2
    %polyarea
    x = [minx minx maxx maxx minx];
    y = [miny maxy maxy miny miny];
    plot(x,y,'-m.','LineWidth',8,'Color', 'b', 'MarkerSize', 30)
end
