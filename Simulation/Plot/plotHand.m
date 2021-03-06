% Plots the entire hand to the default figure. Handled in Simulink.
% Author: Ricardo Garcia Rosas
% Change log:
%%%%%%%%%%%%|%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|
% Date      |   Author  | Notes                                     |
% 16/03/23  |   RGR     | Added more comments.                      |
function plotHand(indexO,indexrOtoL,thumbO,thumbrOtoL)
    % Plots the entire hand to the default figure. Handled in Simulink.
    % @param indexO Index finger origin position [x,y] (m).
    % @param indexrOtoL Index finger vector from its origin to its link
    % ends.
    % @param thumbO Thumb origin position [x,y] (m).
    % @param thumbrOtoL Thumb vector from its origin to its link ends.

    % Call figure
    figure(1);
    clf;
    hold on;
    % Draw pam
    plot([indexO(1) thumbO(1)],[indexO(2) thumbO(2)],'LineWidth',8,'Color', 'k');
    % Draw Proximal components of Index
    plot([indexO(1) indexrOtoL(1,1)],[indexO(2) indexrOtoL(2,1)],'LineWidth',8,'Color', 'k');
    plot(indexO(1),indexO(2),'ko','MarkerSize',18);
    % Draw Distal components of Index
    plot([indexrOtoL(1,1) indexrOtoL(1,2)],[indexrOtoL(2,1) indexrOtoL(2,2)],'LineWidth',8,'Color', 'k');
    plot(indexrOtoL(1,1),indexrOtoL(2,1),'ko','MarkerSize',18);
    % Draw Index fingertip
    plot(indexrOtoL(1,2),indexrOtoL(2,2),'ko','MarkerSize',8);
    % Draw Proximal components of Thumb
    plot([thumbO(1) thumbrOtoL(1,1)],[thumbO(2) thumbrOtoL(2,1)],'LineWidth',8,'Color', 'k');
    plot(thumbO(1),thumbO(2),'ko','MarkerSize',18);
    % Draw Distal components of Thumn
    plot([thumbrOtoL(1,1) thumbrOtoL(1,2)],[thumbrOtoL(2,1) thumbrOtoL(2,2)],'LineWidth',8,'Color', 'k');
    plot(thumbrOtoL(1,1),thumbrOtoL(2,1),'ko','MarkerSize',18);
    % Draw Thumb fingertip
    plot(thumbrOtoL(1,2),thumbrOtoL(2,2),'ko','MarkerSize',8);
    hold off;
    axis([-0.2 0.2 -0.05 0.2]);
end