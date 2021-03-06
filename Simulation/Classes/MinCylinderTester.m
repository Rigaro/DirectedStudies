classdef MinCylinderTester < handle & matlab.System 
    properties 
       R;%Radius of the cylindrical object in meters
       M;%Mass of the object in Kg
       g;%Acceleration of gravity in m/s^2
       Us;%Static coefficient of friction
       Uk;%Kinetic coefficient of friction
       Urs;%Static rotational coefficient of friction
       Urk;%Kinetic rotational coefficient of friction
       Ucs;%Static contact coefficient of friction
       Uck;%Kinetic contact coefficient of friction
       Iz;%Inertia of the cylindrical object in Z
       F_s_x;%Static friction force in X
       F_s_y;%Static friction force in Y
       F_k_x;%Kinetic friction force in X
       F_k_y;%Kinetic friction force in Y
       T_s;%Static friction torque see derivation notes to verify the expression
       T_k;%Kinetic friction torque see derivation notes to verify the expression
       Position_o_G3;%Position from frame 0 to the centre of gravity of the cylinder
       Position_G3_P3_frame_cylinder=[0;0];%Position to second point of the cylinder
    end
    methods  
    %............................................................................
    %............................................................................
    %Constructor
        function obj=Cylinder(varargin)
            obj.R=0.02;
            obj.M=0.003;
            obj.g=9.81;
            obj.Us=0.5;
            obj.Uk=0.48;
            obj.Urs=0.5;
            obj.Urk=0.48;
            obj.Ucs=0.5;
            obj.Uck=0.4;
            obj.Iz=(obj.M*obj.R^2)/2;
            obj.F_s_x=obj.M*obj.g*obj.Us;
            obj.F_s_y=obj.M*obj.g*obj.Us;
            obj.F_k_x=obj.M*obj.g*obj.Uk;
            obj.F_k_y=obj.M*obj.g*obj.Uk;
            obj.T_s=(2/3)*obj.Urs*obj.R*obj.M*obj.g;
            obj.T_k=(2/3)*obj.Urk*obj.R*obj.M*obj.g;
            obj.Position_o_G3=[0;0];
            obj.Position_G3_P3_frame_cylinder=[0;obj.R];
        end
        function ForceReaction=ForceReactionCalc(~,CollisionCondition,IndexFext)
                if(CollisionCondition==1)
                    ForceReaction=IndexFext;
                else
                    ForceReaction=[0;0];
                end
        end
    end
    methods (Access = protected)
    %............................................................................
    %............................................................................
    %Function that is called in Simulink to calculate updated
    %positions,velocities and accelerations for the cylinder
<<<<<<< HEAD
        function MinCylinderResults=stepImpl(obj,IndexFext,ThumbFext,CollisionCondition,CollisionPosition)
                ForceReaction=ForceReactionCalc(obj,CollisionCondition,IndexFext,ThumbFext);
                MinCylinderResults=ForceReaction(obj.Position_o_G3,obj.Position_G3_P3_frame_cylinder,obj.R,ForceReaction([1 2]),ForceReaction([3 4]));
=======
        function [PositionO_G3,PositionO_P3,Radius,ForceReactionIndex]=stepImpl(obj,IndexFext,CollisionCondition,CollisionPosition)
                ForceReaction=ForceReactionCalc(obj,CollisionCondition,IndexFext);
                ForceReactionIndex=ForceReaction;
                PositionO_G3=obj.Position_o_G3;
                PositionO_P3=obj.Position_G3_P3_frame_cylinder;
                Radius=obj.R;
>>>>>>> bd59782f3a500d33eda999d2707cc296491da087
                
        end
    end
end