function [  ] = plotFinger(finger, fig)
%PLOTFINGER Summary of this function goes here
%   Detailed explanation goes here
    
    % Call figure
    fig;
    hold on;
    % Draw Proximal components of finger
    viscircles(finger.origin,0.005,'Color', 'k','LineWidth',8);
    plot([finger.origin(1) finger.rOtoL(1,1)],[finger.origin(2) finger.rOtoL(2,1)],'LineWidth',8,'Color', 'k');
    % Draw Distal components of finger
    viscircles(finger.rOtoL(:,1)',0.005,'Color', 'k','LineWidth',8);
    plot([finger.rOtoL(1,1) finger.rOtoL(1,2)],[finger.rOtoL(2,1) finger.rOtoL(2,2)],'LineWidth',8,'Color', 'k');
    % Draw fingertip
    viscircles(finger.rOtoL(:,2)',0.003,'Color', 'k','LineWidth',8);
    hold off;

end

