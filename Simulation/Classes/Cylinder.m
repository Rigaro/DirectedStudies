classdef Cylinder < handle & matlab.System
    properties 
       R;%Radius of the cylindrical object in meters
       M;%Mass of the object in Kg
       g;%Acceleration of gravity in m/s^2
       Uk;%Static coefficient of friction
       Us;%Kinetic coefficient of friction
       Iz;%Inertia of the cylindrical object in Z
       F_k_x;%Static friction force in X
       F_k_y;%Static friction force in Y
       F_s_x;%Static friction force in X
       F_s_y;%Static friction force in Y
       T_k;%Static friction torque see derivation notes to verify the expression
       T_s;%Kinetic friction torque see derivation notes to verify the expression
       Position_o_G3;%Position from frame 0 to the centre of gravity of the cylinder
       Position_G3_P3_frame_cylinder=[0;0];%Position to second point of the cylinder
    end
    methods  
    %............................................................................
    %............................................................................
    %Constructor
        function obj=Cylinder(varargin)
            obj.R=0.02;
            obj.M=0.03;
            obj.g=9.81;
            obj.Uk=0.5;
            obj.Us=0.3;
            obj.Iz=(obj.M*obj.R^2)/2;
            obj.F_k_x=obj.M*obj.g*obj.Uk;
            obj.F_k_y=obj.M*obj.g*obj.Uk;
            obj.F_s_x=obj.M*obj.g*obj.Us;
            obj.F_s_y=obj.M*obj.g*obj.Us;
            obj.T_k=(2/3)*obj.Uk*obj.R*obj.M*obj.g;
            obj.T_s=(2/3)*obj.Us*obj.R*obj.M*obj.g;
            obj.Position_o_G3=[0;0];
            obj.Position_G3_P3_frame_cylinder=[0;obj.R];
        end
    %............................................................................
    %............................................................................
    %Evaluates if the external force is greater than the static
    %friction forces or torques
        function FrictionCondition=NonLinearFriction(obj,GenCordExt,Election)
            %Evaluates wich static friction have to be compared
            if (strcmp(Election,'F_k_x')==1)
                ForceEvaluation=obj.F_k_x;
            elseif(strcmp(Election,'F_k_y')==1)
                ForceEvaluation=obj.F_k_y;
            else
                ForceEvaluation=obj.T_k;
            end
            %Condition checker
            if(GenCordExt<=ForceEvaluation)
                FrictionCondition=0;%if the Friction condition is 0 there is no movement
            else
                FrictionCondition=1;%if the Friction condition is 1 there is movement
            end
        end
    %............................................................................
    %............................................................................
    %Calculates the acceleration components in X and Y for the centre of
    %gravity of the object and the angular acceleration
        function GeneralCoordinatesDoubleDot = Equation_Of_Motion(obj,GenCordExt)
        %Ecuation of motion for X coordinates
            SignOposite=-1*sign(GenCordExt);
            if(NonLinearFriction(obj,abs(GenCordExt(1)),'F_k_x')== 1)
                GeneralCoordinatesDoubleDot(1)= (GenCordExt(1)- SignOposite(1)*obj.F_k_x)/obj.M;
            else
                GeneralCoordinatesDoubleDot(1)= 0;
            end
        %Ecuation of motion for y coordinates
            if(NonLinearFriction(obj,abs(GenCordExt(2)),'F_k_y')== 1)
                GeneralCoordinatesDoubleDot(2)= (GenCordExt(2)- SignOposite(2)*obj.F_k_y)/obj.M;
            else
                GeneralCoordinatesDoubleDot(2)= 0;
            end
        %Ecuation of motion for Tetha coordinates
            if(NonLinearFriction(obj,abs(GenCordExt(3)),'T_k')== 1)
                GeneralCoordinatesDoubleDot(3)= (GenCordExt(3)- SignOposite(3)*obj.T_k)/obj.Iz;
            else
                GeneralCoordinatesDoubleDot(3)= 0;
            end
        end
    %............................................................................
    %............................................................................
    %Absolute positions for G3 and P3 updated from frame 0
        function Positions = PosCalculation(obj,angle,xPositionG3,yPositionG3)
            Rotation_o_3=[cos(angle),-sin(angle);sin(angle),cos(angle)];
            Position_G3_P3_frame_0=Rotation_o_3*obj.Position_G3_P3_frame_cylinder;
            Position_o_P3=obj.Position_o_G3 + Position_G3_P3_frame_0;
            Positions=[obj.Position_o_G3,Position_o_P3];
        end
    %............................................................................
    %............................................................................
    %Absolute velocities for G3 and P3 updated from frame 0
        function Velocities = VelCalculation (obj,angle,angleDot,xDotG3,yDotG3)
            Velocity_o_G3_frame_0=[xDotG3;yDotG3];
            Velocity_o_P3_frame_0=[xDotG3-obj.R*cos(angle)*angleDot;yDotG3-obj.R*sin(angle)*angleDot];
            Velocities=[Velocity_o_G3_frame_0,Velocity_o_P3_frame_0];
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function Accelerations = AccCalculation (obj,angle,angleDot,angleDoubleDot,xDoubleDot,yDoubleDot)
            Acceleration_o_G3_frame_0=[xDoubleDot;yDoubleDot];
            Acceleration_o_P3_frame_0=[xDoubleDot+obj.R*sin(angle)*(angleDot^2)-obj.R*cos(angle)*angleDoubleDot;...
                                       yDoubleDot-obj.R*cos(angle)*(angleDot^2)-obj.R*sin(angle)*angleDoubleDot];
            Accelerations=[Acceleration_o_G3_frame_0,Acceleration_o_P3_frame_0];
        end
    end
    methods (Access = protected)
    %............................................................................
    %............................................................................
    %Function that is called in Simulink to calculate updated
    %positions,velocities and accelerations for the cylinder
        function CylinderResults=SimulinkImplementation(obj,FextX,FextY,TorqueExt,angleDot,angle,...
                                                        xDotG3,yDotG3,xPositionG3,yPositionG3)
            GenCordExt=[FextX,FextY,TorqueExt];
            GeneralCoordinatesDoubleDot = Equation_Of_Motion(obj,GenCordExt);
            xDoubleDot = GeneralCoordinatesDoubleDot(1);
            yDoubleDot = GeneralCoordinatesDoubleDot(2);
            angleDoubleDot = GeneralCoordinatesDoubleDot(3);
            Positions = PosCalculation(obj,angle,xPositionG3,yPositionG3);
            Velocities = VelCalculation (obj,angle,angleDot,xDotG3,yDotG3);
            Accelerations = AccCalculation (obj,angle,angleDot,angleDoubleDot,xDoubleDot,yDoubleDot);
            CylinderResults = [Positions,Velocities,Accelerations];
        end
    end
end