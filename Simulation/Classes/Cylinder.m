classdef Cylinder < handle & matlab.System 
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
    %............................................................................
    %............................................................................
    %Evaluates if the external force is greater than the static
    %friction forces or torques
        function FrictionCondition=NonLinearFriction(obj,GenCordExt,Election)
            %Evaluates wich static friction have to be compared
            if (strcmp(Election,'F_s_x')==1)
                ForceEvaluation=obj.F_s_x;
            elseif(strcmp(Election,'F_s_y')==1)
                ForceEvaluation=obj.F_s_y;
            else
                ForceEvaluation=obj.T_s;
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
            GeneralCoordinatesDoubleDot=zeros(3);
            %Ecuation of motion for X coordinates
            SignOposite=-1*sign(GenCordExt);
            if(NonLinearFriction(obj,abs(GenCordExt(1)),'F_s_x')== 1)
                GeneralCoordinatesDoubleDot(1)= (GenCordExt(1)+ SignOposite(1)*obj.F_k_x)/obj.M;
            else
                GeneralCoordinatesDoubleDot(1)= 0;
            end
        %Ecuation of motion for y coordinates
            if(NonLinearFriction(obj,abs(GenCordExt(2)),'F_s_y')== 1)
                GeneralCoordinatesDoubleDot(2)= (GenCordExt(2)+ SignOposite(2)*obj.F_k_y)/obj.M;
            else
                GeneralCoordinatesDoubleDot(2)= 0;
            end
        %Ecuation of motion for Tetha coordinates
            if(NonLinearFriction(obj,abs(GenCordExt(3)),'T_s')== 1)
                GeneralCoordinatesDoubleDot(3)= (GenCordExt(3)+ SignOposite(3)*obj.T_k)/obj.Iz;
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
            Position_o_P3=[xPositionG3;yPositionG3] + Position_G3_P3_frame_0;
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
            Accelerations=[Acceleration_o_G3_frame_0,Acceleration_o_P3_frame_0,[angleDoubleDot;0]];
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function RotMatrix_0_4=RotationToContactFrame(obj,CollisionPosition,xPositionG3,yPositionG3)
            Theta=0;
            if ((CollisionPosition(1)-xPositionG3)==0)
                if((CollisionPosition(2)-yPositionG3)>0)
                    Theta=pi/2;
                else
                    Theta=3*pi/2;
                end
            else
                tan_angle=(CollisionPosition(2)-yPositionG3)/(CollisionPosition(1)-xPositionG3);
                if(tan_angle>0 && (CollisionPosition(1)-xPositionG3)>0 && (CollisionPosition(2)-yPositionG3)>0)
                    Theta=atan(tan_angle);
                elseif(tan_angle>0 && (CollisionPosition(1)-xPositionG3)<0 && (CollisionPosition(2)-yPositionG3)<0)
                    Theta=atan(tan_angle)+pi;
                elseif(tan_angle<0 && (CollisionPosition(1)-xPositionG3)<0 && (CollisionPosition(2)-yPositionG3)>0)
                    Theta=atan(tan_angle);
                elseif(tan_angle<0 && (CollisionPosition(1)-xPositionG3)>0 && (CollisionPosition(2)-yPositionG3)<0)
                    Theta=atan(tan_angle)+pi;
                elseif(tan_angle==0)
                    Theta=0;
                end
            end 
            RotMatrix_0_4=[cos(Theta) -sin(Theta);sin(Theta) cos(Theta)];
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function RotatedForce = ConvesrsionForceContactPoint(obj,RotMatrix_0_4,Force)
            RotatedForce=RotMatrix_0_4'*Force;
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function FrictionForceInContactFrame=EvaluateFrictionInContactPoint(obj,RotatedForce)
            if(RotatedForce(2)<=obj.Ucs*RotatedForce(1))
                FrictionForceInContactFrame=[RotatedForce(1);RotatedForce(2)+(-1*sign(RotatedForce(2)))];
            else
                FrictionForceInContactFrame=RotatedForce;
            end
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function RotatedForceToFrame0 = ConvesrsionContactPointFrame0(obj,RotMatrix_0_4,Force)
            RotatedForceToFrame0=RotMatrix_0_4*Force;
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function ResultantTorque = ResultantTorqueCalc(obj,RotatedForceIndex,RotatedForceThumb)
            ResultantTorque=obj.R*RotatedForceIndex+obj.R*RotatedForceThumb;
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function ResultantForceX=ResultantXForceWithoutFloorFrictionX(obj,IndexForceX,ThumbForceX)
            ResultantForceX=IndexForceX+ThumbForceX;
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function ResultantForceY=ResultantXForceWithoutFloorFrictionY(obj,IndexForceY,ThumbForceY)
            ResultantForceY=IndexForceY+ThumbForceY;
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function BunchOfTotalForces=ColissionConditionCalc(obj,ColissionCondition,IndexForce,ThumbForce)
            if(ColissionCondition(1)==1 && ColissionCondition(2)==1)
                BunchOfTotalForces=[IndexForce,ThumbForce];
            elseif(ColissionCondition(1)==0 && ColissionCondition(2)==1)
                BunchOfTotalForces=[[0;0],ThumbForce];
            elseif(ColissionCondition(1)==1 && ColissionCondition(2)==0)
                BunchOfTotalForces=[IndexForce,[0;0]];
            else
                BunchOfTotalForces=[[0;0],[0;0]];
            end
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function ReactionForcePerFinger=ReactionForceCalc(obj,CollisionCondition,CollisionPosition,IndexFext,ThumbFext,...
                                                           xPositionG3,yPositionG3)
            BunchOfTotalForces=ColissionConditionCalc(obj,CollisionCondition,IndexFext,ThumbFext);
            ResultantTorqueIndex=0;
            ResultantTorqueThumb=0;
            RotatedForceToFrame0Index=[0;0];
            RotatedForceToFrame0Thumb=[0;0];
           if (CollisionCondition(1) == 1)
               RotMatrix_0_4_Index=RotationToContactFrame(obj,CollisionPosition([1;2]),xPositionG3,yPositionG3);
               RotatedForceIndex = ConvesrsionForceContactPoint(obj,RotMatrix_0_4_Index,BunchOfTotalForces([1;2]));
               FrictionForceInContactFrameIndex=EvaluateFrictionInContactPoint(obj,RotatedForceIndex);
               RotatedForceIndex(2)=FrictionForceInContactFrameIndex(2);
               ResultantTorqueIndex = ResultantTorqueCalc(obj,FrictionForceInContactFrameIndex(2),0);
               RotatedForceToFrame0Index = ConvesrsionContactPointFrame0(obj,RotMatrix_0_4_Index,RotatedForceIndex );
           elseif(CollisionCondition(2) == 1)
               RotMatrix_0_4_Thumb=RotationToContactFrame(obj,CollisionPosition([3;4]),xPositionG3,yPositionG3);
               RotatedForceThumb = ConvesrsionForceContactPoint(obj,RotMatrix_0_4_Thumb,BunchOfTotalForces([3;4]));
               FrictionForceInContactFrameThumb=EvaluateFrictionInContactPoint(obj,RotatedForceThumb);
               RotatedForceThumb(2)=FrictionForceInContactFrameThumb(2);
               ResultantTorqueThumb = ResultantTorqueCalc(obj,0,FrictionForceInContactFrameThumb(2));
               RotatedForceToFrame0Thumb = ConvesrsionContactPointFrame0(obj,RotMatrix_0_4_Thumb,RotatedForceThumb );
           elseif(CollisionCondition(2) == 1 && CollisionCondition(1) == 1)
               RotMatrix_0_4_Index=RotationToContactFrame(obj,CollisionPosition([1;2]),xPositionG3,yPositionG3);
               RotMatrix_0_4_Thumb=RotationToContactFrame(obj,CollisionPosition([3;4]),xPositionG3,yPositionG3);
               RotatedForceIndex = ConvesrsionForceContactPoint(obj,RotMatrix_0_4_Index,BunchOfTotalForces([1;2]));
               RotatedForceThumb = ConvesrsionForceContactPoint(obj,RotMatrix_0_4_Thumb,BunchOfTotalForces([3;4]));
               FrictionForceInContactFrameIndex=EvaluateFrictionInContactPoint(obj,RotatedForceIndex);
               FrictionForceInContactFrameThumb=EvaluateFrictionInContactPoint(obj,RotatedForceThumb);
               RotatedForceIndex(2)=FrictionForceInContactFrameIndex(2);
               RotatedForceThumb(2)=FrictionForceInContactFrameThumb(2);
               ResultantTorqueIndex = ResultantTorqueCalc(obj,FrictionForceInContactFrameIndex(2),0);
               ResultantTorqueThumb = ResultantTorqueCalc(obj,0,FrictionForceInContactFrameThumb(2));
               RotatedForceToFrame0Index = ConvesrsionContactPointFrame0(obj,RotMatrix_0_4_Index,RotatedForceIndex );
               RotatedForceToFrame0Thumb = ConvesrsionContactPointFrame0(obj,RotMatrix_0_4_Thumb,RotatedForceThumb );
           elseif(CollisionCondition(2) == 0 && CollisionCondition(1) == 0)
               ResultantTorqueIndex=0;
               ResultantTorqueThumb=0;
               RotatedForceToFrame0Index=[0;0];
               RotatedForceToFrame0Thumb=[0;0];
           end
           BunchOfTotalForcesOutput=ColissionConditionCalc(obj,CollisionCondition,RotatedForceToFrame0Index...
                                                                ,RotatedForceToFrame0Thumb);
           ResultantForceX=ResultantXForceWithoutFloorFrictionX(obj,RotatedForceToFrame0Index(1),RotatedForceToFrame0Thumb(1));
           ResultantForceY=ResultantXForceWithoutFloorFrictionY(obj,RotatedForceToFrame0Index(1),RotatedForceToFrame0Thumb(1));
           ResultantTorque=ResultantTorqueIndex+ResultantTorqueThumb;
           ReactionForcePerFinger=[ResultantForceX,ResultantForceY,ResultantTorque];
        end
    %............................................................................
    %............................................................................
    %Absolute Accelerations for G3 and P3 updated from frame 0
        function ForceReaction=ForceReactionFinger(obj,GeneralCoordinatesDoubleDot,ForceFinger)
           ForceReaction=[0;0];
           ForceReaction(1)=ForceFinger(1)-GeneralCoordinatesDoubleDot(1)*obj.M;
           ForceReaction(2)=ForceFinger(2)-GeneralCoordinatesDoubleDot(1)*obj.M;
           ForceReaction=[ForceReaction(1);ForceReaction(2)];
        end
    end
    methods (Access = protected)
    %............................................................................
    %............................................................................
    %Function that is called in Simulink to calculate updated
    %positions,velocities and accelerations for the cylinder
        function CylinderResults=stepImpl(obj,Urk,IndexFext,ThumbFext,CollisionCondition,CollisionPosition,...
                                            xDotG3,yDotG3,angleDot,xPositionG3,yPositionG3,angle)
            %obj.Urk=Urk;
            %obj.T_k=(2/3)*obj.Urk*obj.R*obj.M*obj.g;
            GenCordExt=ReactionForceCalc(obj,CollisionCondition,CollisionPosition,IndexFext,ThumbFext,xPositionG3,yPositionG3);
            FrictionCondition=NonLinearFriction(obj,abs(GenCordExt(3)),'T_s');
            GeneralCoordinatesDoubleDot = Equation_Of_Motion(obj,GenCordExt);
            ForceReactionIndex=ForceReactionFinger(obj,GeneralCoordinatesDoubleDot,IndexFext);
            ForceReactionThumb=ForceReactionFinger(obj,GeneralCoordinatesDoubleDot,ThumbFext);
            ForceReactions=[ForceReactionIndex,ForceReactionThumb];
            xDoubleDot = GeneralCoordinatesDoubleDot(1);
            yDoubleDot = GeneralCoordinatesDoubleDot(2);
            angleDoubleDot = GeneralCoordinatesDoubleDot(3);
            Positions = PosCalculation(obj,angle,xPositionG3,yPositionG3);
            Velocities = VelCalculation (obj,angle,angleDot,xDotG3,yDotG3);
            Accelerations = AccCalculation (obj,angle,angleDot,angleDoubleDot,xDoubleDot,yDoubleDot);
            CylinderResults = [Accelerations([1 2 5]),Positions([3 4]),obj.R,ForceReactionIndex',ForceReactionThumb',obj.Urk,FrictionCondition];
        end
    end
end