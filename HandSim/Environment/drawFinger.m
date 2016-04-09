% Plots finger to the default figure. Handled in Simulink.
% Author: Ricardo Garcia Rosas
% Change log:
%%%%%%%%%%%%|%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|
% Date      |   Author  | Notes                                     |
% 16/03/23  |   RGR     | Added more comments.                      |
function drawFinger(o,rOtoL,figNum)
    % Plots the finger to the default figure. Handled in Simulink.
    % @param o finger origin position [x,y] (m).
    % @param rOtoL finger vector from its origin to its link
    % ends.
    % @param figNum the figure number for the plot.

    % Call figure
    figure(figNum);
    hold on;
    % Draw Proximal components
    plot([o(1) rOtoL(1,1)],[o(2) rOtoL(2,1)],'LineWidth',8,'Color', 'k');
    plot(o(1),o(2),'ko','MarkerSize',18);
    % Draw Distal components
    plot([rOtoL(1,1) rOtoL(1,2)],[rOtoL(2,1) rOtoL(2,2)],'LineWidth',8,'Color', 'k');
    plot(rOtoL(1,1),rOtoL(2,1),'ko','MarkerSize',18);
    % Draw fingertip
    plot(rOtoL(1,2),rOtoL(2,2),'ko','MarkerSize',8);
    hold off;
    axis([-0.2 0.2 -0.05 0.2]);
end