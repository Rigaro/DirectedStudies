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
            if(NonLinearFriction(obj,GenCordExt(1),'F_k_x')== 1)
                GeneralCoordinatesDoubleDot(1)= (GenCordExt(1)- obj.F_k_x)/obj.M;
            else
                GeneralCoordinatesDoubleDot(1)= 0;
            end
        %Ecuation of motion for y coordinates
            if(NonLinearFriction(obj,GenCordExt(2),'F_k_y')== 1)
                GeneralCoordinatesDoubleDot(2)= (GenCordExt(2)- obj.F_k_y)/obj.M;
            else
                GeneralCoordinatesDoubleDot(2)= 0;
            end
        %Ecuation of motion for Tetha coordinates
            if(NonLinearFriction(obj,GenCordExt(3),'T_k')== 1)
                GeneralCoordinatesDoubleDot(3)= (GenCordExt(3)- obj.T_k)/obj.Iz;
            else
                GeneralCoordinatesDoubleDot(3)= 0;
            end
        end
    end
end