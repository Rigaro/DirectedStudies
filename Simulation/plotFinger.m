function [  ] = plotFinger(finger, fig)
%PLOTFINGER Summary of this function goes here
%   Detailed explanation goes here
    
    % Call figure
    fig;
    hold on;
    % Draw Proximal components of finger
    viscircles(finger.origin,0.005,'Color', 'b','LineWidth',8);
    plot([finger.origin(1) finger.r_op(1)],[finger.origin(2) finger.r_op(2)],'LineWidth',8,'Color', 'b');
    % Draw Distal components of finger
    viscircles(finger.r_op',0.005,'Color', 'b','LineWidth',8);
    plot([finger.r_op(1) finger.r_od(1)],[finger.r_op(2) finger.r_od(2)],'LineWidth',8,'Color', 'b');
    % Draw fingertip
    viscircles(finger.r_od',0.003,'Color', 'b','LineWidth',8);
    hold off;

end

