/* Include files */

#include "modelInterface.h"
#include "m_CynCoNzEkJ1QVd5zEkhIm.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 17, 9, "error",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\error.m"
};

static emlrtMCInfo b_emlrtMCI = { 1, 1, "SystemCore",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"
};

/* Function Declarations */
static Cylinder *Cylinder_Cylinder(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, Cylinder *obj);
static void Cylinder_stepImpl(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, Cylinder *obj, real_T b_Urk, real_T IndexFext[2], real_T
  ThumbFext[2], boolean_T CollisionCondition[2], real_T CollisionPosition[4],
  real_T xDotG3, real_T yDotG3, real_T angleDot, real_T xPositionG3, real_T
  yPositionG3, real_T angle, real_T CylinderResults[12]);
static void Cylinder_ColissionConditionCalc(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, Cylinder *obj, boolean_T ColissionCondition[2], real_T
  IndexForce[2], real_T ThumbForce[2], real_T BunchOfTotalForces[4]);
static void Cylinder_RotationToContactFrame(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, Cylinder *obj, real_T CollisionPosition[2], real_T
  xPositionG3, real_T yPositionG3, real_T RotMatrix_0_4[4]);
static void cgxe_mdl_start(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *b_sysobj, const char_T *identifier, Cylinder
  *y);
static void b_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Cylinder *y);
static int32_T c_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static boolean_T d_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static real_T e_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static void f_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2]);
static boolean_T g_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier);
static void mw__internal__setSimState__fcn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *
  moduleInstance, const mxArray *st);
static const mxArray *message(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *b, emlrtMCInfo *location);
static void error(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location);
static const mxArray *b_message(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static int32_T h_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static boolean_T i_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static real_T j_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static void k_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2]);
static void init_simulink_io_address(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance);

/* Function Definitions */
static Cylinder *Cylinder_Cylinder(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, Cylinder *obj)
{
  Cylinder *b_obj;
  Cylinder *c_obj;
  boolean_T flag;
  real_T a;
  int32_T i0;
  covrtLogFcn(moduleInstance->covInst, 0, 0);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 0);
  b_obj = obj;
  c_obj = b_obj;
  c_obj->isInitialized = 0;
  c_obj->TunablePropsChanged = false;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->R = 0.02;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->M = 0.003;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->g = 9.81;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Us = 0.5;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Uk = 0.48;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Urs = 0.5;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Urk = 0.48;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Ucs = 0.5;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Uck = 0.4;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  a = b_obj->R;
  a = b_obj->M * (a * a);
  b_obj->Iz = a / 2.0;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->F_s_x = b_obj->M * b_obj->g * b_obj->Us;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->F_s_y = b_obj->M * b_obj->g * b_obj->Us;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->F_k_x = b_obj->M * b_obj->g * b_obj->Uk;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->F_k_y = b_obj->M * b_obj->g * b_obj->Uk;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->T_s = 0.66666666666666663 * b_obj->Urs * b_obj->R * b_obj->M * b_obj->g;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->T_k = 0.66666666666666663 * b_obj->Urk * b_obj->R * b_obj->M * b_obj->g;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  for (i0 = 0; i0 < 2; i0++) {
    b_obj->Position_o_G3[i0] = 0.0;
  }

  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Position_G3_P3_frame_cylinder[0] = 0.0;
  b_obj->Position_G3_P3_frame_cylinder[1] = b_obj->R;
  return b_obj;
}

static void Cylinder_stepImpl(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, Cylinder *obj, real_T b_Urk, real_T IndexFext[2], real_T
  ThumbFext[2], boolean_T CollisionCondition[2], real_T CollisionPosition[4],
  real_T xDotG3, real_T yDotG3, real_T angleDot, real_T xPositionG3, real_T
  yPositionG3, real_T angle, real_T CylinderResults[12])
{
  Cylinder *b_obj;
  boolean_T flag;
  real_T BunchOfTotalForces[4];
  real_T ResultantTorqueIndex;
  real_T ResultantTorqueThumb;
  real_T RotatedForceToFrame0Index[2];
  real_T RotatedForceToFrame0Thumb[2];
  int32_T k;
  real_T RotMatrix_0_4_Thumb[4];
  real_T RotatedForceThumb[2];
  int32_T i1;
  real_T FrictionForceInContactFrameThumb[2];
  real_T unusedExpr[4];
  real_T GenCordExt[3];
  int32_T FrictionCondition;
  real_T SignOposite[3];
  real_T GeneralCoordinatesDoubleDot_idx_0;
  real_T GeneralCoordinatesDoubleDot_idx_1;
  real_T ForceReactionIndex[2];
  real_T ForceReactionThumb[2];
  real_T dv0[4];
  real_T b_xPositionG3[2];
  real_T GeneralCoordinatesDoubleDot[2];
  real_T b_GeneralCoordinatesDoubleDot[2];
  real_T c_GeneralCoordinatesDoubleDot[6];
  static int8_T iv0[3] = { 0, 1, 4 };

  (void)xDotG3;
  (void)yDotG3;
  covrtLogFcn(moduleInstance->covInst, 0, 16);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 44);

  /* ............................................................................ */
  /* ............................................................................ */
  /* Function that is called in Simulink to calculate updated */
  /* positions,velocities and accelerations for the cylinder */
  b_obj = obj;
  flag = (b_obj->isInitialized == 1);
  if (flag) {
    b_obj->TunablePropsChanged = true;
  }

  obj->Urk = b_Urk;
  b_obj = obj;
  flag = (b_obj->isInitialized == 1);
  if (flag) {
    b_obj->TunablePropsChanged = true;
  }

  obj->T_k = 0.66666666666666663 * obj->Urk * obj->R * obj->M * obj->g;
  b_obj = obj;
  covrtLogFcn(moduleInstance->covInst, 0, 14);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 37);
  Cylinder_ColissionConditionCalc(moduleInstance, b_obj, CollisionCondition,
    IndexFext, ThumbFext, BunchOfTotalForces);
  ResultantTorqueIndex = 0.0;
  ResultantTorqueThumb = 0.0;
  for (k = 0; k < 2; k++) {
    RotatedForceToFrame0Index[k] = 0.0;
    RotatedForceToFrame0Thumb[k] = 0.0;
  }

  if (covrtLogIf(moduleInstance->covInst, 0, 0, 17, CollisionCondition[0])) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 38);
    Cylinder_RotationToContactFrame(moduleInstance, b_obj, *(real_T (*)[2])&
      CollisionPosition[0], xPositionG3, yPositionG3, RotMatrix_0_4_Thumb);
    covrtLogFcn(moduleInstance->covInst, 0, 7);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 26);
    for (k = 0; k < 2; k++) {
      RotatedForceThumb[k] = 0.0;
      for (i1 = 0; i1 < 2; i1++) {
        RotatedForceThumb[k] += RotMatrix_0_4_Thumb[i1 + (k << 1)] *
          BunchOfTotalForces[i1];
      }
    }

    covrtLogFcn(moduleInstance->covInst, 0, 8);
    if (covrtLogIf(moduleInstance->covInst, 0, 0, 13, RotatedForceThumb[1] <=
                   b_obj->Ucs * RotatedForceThumb[0])) {
      covrtLogBasicBlock(moduleInstance->covInst, 0, 27);
      FrictionForceInContactFrameThumb[1] = RotatedForceThumb[1] +
        -muDoubleScalarSign(RotatedForceThumb[1]);
    } else {
      covrtLogBasicBlock(moduleInstance->covInst, 0, 28);
      for (k = 0; k < 2; k++) {
        FrictionForceInContactFrameThumb[k] = RotatedForceThumb[k];
      }
    }

    RotatedForceThumb[1] = FrictionForceInContactFrameThumb[1];
    covrtLogFcn(moduleInstance->covInst, 0, 10);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 30);
    ResultantTorqueIndex = b_obj->R * FrictionForceInContactFrameThumb[1] +
      b_obj->R * 0.0;
    covrtLogFcn(moduleInstance->covInst, 0, 9);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 29);
    for (k = 0; k < 2; k++) {
      RotatedForceToFrame0Index[k] = 0.0;
      for (i1 = 0; i1 < 2; i1++) {
        RotatedForceToFrame0Index[k] += RotMatrix_0_4_Thumb[k + (i1 << 1)] *
          RotatedForceThumb[i1];
      }
    }
  } else if (covrtLogIf(moduleInstance->covInst, 0, 0, 18, CollisionCondition[1]))
  {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 39);
    Cylinder_RotationToContactFrame(moduleInstance, b_obj, *(real_T (*)[2])&
      CollisionPosition[2], xPositionG3, yPositionG3, RotMatrix_0_4_Thumb);
    covrtLogFcn(moduleInstance->covInst, 0, 7);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 26);
    for (k = 0; k < 2; k++) {
      RotatedForceThumb[k] = 0.0;
      for (i1 = 0; i1 < 2; i1++) {
        RotatedForceThumb[k] += RotMatrix_0_4_Thumb[i1 + (k << 1)] *
          BunchOfTotalForces[2 + i1];
      }
    }

    covrtLogFcn(moduleInstance->covInst, 0, 8);
    if (covrtLogIf(moduleInstance->covInst, 0, 0, 13, RotatedForceThumb[1] <=
                   b_obj->Ucs * RotatedForceThumb[0])) {
      covrtLogBasicBlock(moduleInstance->covInst, 0, 27);
      FrictionForceInContactFrameThumb[1] = RotatedForceThumb[1] +
        -muDoubleScalarSign(RotatedForceThumb[1]);
    } else {
      covrtLogBasicBlock(moduleInstance->covInst, 0, 28);
      for (k = 0; k < 2; k++) {
        FrictionForceInContactFrameThumb[k] = RotatedForceThumb[k];
      }
    }

    RotatedForceThumb[1] = FrictionForceInContactFrameThumb[1];
    covrtLogFcn(moduleInstance->covInst, 0, 10);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 30);
    ResultantTorqueThumb = b_obj->R * 0.0 + b_obj->R *
      FrictionForceInContactFrameThumb[1];
    covrtLogFcn(moduleInstance->covInst, 0, 9);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 29);
    for (k = 0; k < 2; k++) {
      RotatedForceToFrame0Thumb[k] = 0.0;
      for (i1 = 0; i1 < 2; i1++) {
        RotatedForceToFrame0Thumb[k] += RotMatrix_0_4_Thumb[k + (i1 << 1)] *
          RotatedForceThumb[i1];
      }
    }
  } else {
    covrtLogCond(moduleInstance->covInst, 0, 0, 0, CollisionCondition[1]);
    covrtLogMcdc(moduleInstance->covInst, 0, 0, 7, false);
    covrtLogIf(moduleInstance->covInst, 0, 0, 19, false);
    covrtLogCond(moduleInstance->covInst, 0, 0, 2, !CollisionCondition[1]);
    covrtLogCond(moduleInstance->covInst, 0, 0, 3, !CollisionCondition[0]);
    covrtLogMcdc(moduleInstance->covInst, 0, 0, 8, true);
    covrtLogIf(moduleInstance->covInst, 0, 0, 20, true);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 41);
  }

  covrtLogBasicBlock(moduleInstance->covInst, 0, 42);
  Cylinder_ColissionConditionCalc(moduleInstance, b_obj, CollisionCondition,
    RotatedForceToFrame0Index, RotatedForceToFrame0Thumb, unusedExpr);
  covrtLogFcn(moduleInstance->covInst, 0, 11);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 31);
  covrtLogFcn(moduleInstance->covInst, 0, 12);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 32);
  GenCordExt[0] = RotatedForceToFrame0Index[0] + RotatedForceToFrame0Thumb[0];
  GenCordExt[1] = RotatedForceToFrame0Index[0] + RotatedForceToFrame0Thumb[0];
  GenCordExt[2] = ResultantTorqueIndex + ResultantTorqueThumb;
  b_obj = obj;
  covrtLogFcn(moduleInstance->covInst, 0, 1);
  covrtLogIf(moduleInstance->covInst, 0, 0, 0, false);
  covrtLogIf(moduleInstance->covInst, 0, 0, 1, false);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 3);
  ResultantTorqueIndex = b_obj->T_s;
  if (covrtLogIf(moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs(GenCordExt
        [2]) <= ResultantTorqueIndex)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
    FrictionCondition = 0;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 5);
    FrictionCondition = 1;
  }

  b_obj = obj;
  covrtLogFcn(moduleInstance->covInst, 0, 2);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 6);
  for (k = 0; k < 3; k++) {
    SignOposite[k] = -muDoubleScalarSign(GenCordExt[k]);
  }

  covrtLogFcn(moduleInstance->covInst, 0, 1);
  covrtLogIf(moduleInstance->covInst, 0, 0, 0, true);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 1);
  ResultantTorqueIndex = b_obj->F_s_x;
  if (covrtLogIf(moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs(GenCordExt
        [0]) <= ResultantTorqueIndex)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(moduleInstance->covInst, 0, 0, 3, k == 1)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 7);
    ResultantTorqueIndex = GenCordExt[0] + SignOposite[0] * b_obj->F_k_x;
    ResultantTorqueThumb = b_obj->M;
    GeneralCoordinatesDoubleDot_idx_0 = ResultantTorqueIndex /
      ResultantTorqueThumb;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 8);
    GeneralCoordinatesDoubleDot_idx_0 = 0.0;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 1);
  covrtLogIf(moduleInstance->covInst, 0, 0, 0, false);
  covrtLogIf(moduleInstance->covInst, 0, 0, 1, true);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 2);
  ResultantTorqueIndex = b_obj->F_s_y;
  if (covrtLogIf(moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs(GenCordExt
        [1]) <= ResultantTorqueIndex)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(moduleInstance->covInst, 0, 0, 4, k == 1)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 9);
    ResultantTorqueIndex = GenCordExt[1] + SignOposite[1] * b_obj->F_k_y;
    ResultantTorqueThumb = b_obj->M;
    GeneralCoordinatesDoubleDot_idx_1 = ResultantTorqueIndex /
      ResultantTorqueThumb;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 10);
    GeneralCoordinatesDoubleDot_idx_1 = 0.0;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 1);
  covrtLogIf(moduleInstance->covInst, 0, 0, 0, false);
  covrtLogIf(moduleInstance->covInst, 0, 0, 1, false);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 3);
  ResultantTorqueIndex = b_obj->T_s;
  if (covrtLogIf(moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs(GenCordExt
        [2]) <= ResultantTorqueIndex)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(moduleInstance->covInst, 0, 0, 5, k == 1)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 11);
    ResultantTorqueIndex = GenCordExt[2] + SignOposite[2] * b_obj->T_k;
    ResultantTorqueThumb = b_obj->Iz;
    ResultantTorqueIndex /= ResultantTorqueThumb;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 12);
    ResultantTorqueIndex = 0.0;
  }

  b_obj = obj;
  covrtLogFcn(moduleInstance->covInst, 0, 15);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 43);

  /* Radius of the cylindrical object in meters */
  /* Mass of the object in Kg */
  /* Acceleration of gravity in m/s^2 */
  /* Static coefficient of friction */
  /* Kinetic coefficient of friction */
  /* Static rotational coefficient of friction */
  /* Kinetic rotational coefficient of friction */
  /* Static contact coefficient of friction */
  /* Kinetic contact coefficient of friction */
  /* Inertia of the cylindrical object in Z */
  /* Static friction force in X */
  /* Static friction force in Y */
  /* Kinetic friction force in X */
  /* Kinetic friction force in Y */
  /* Static friction torque see derivation notes to verify the expression */
  /* Kinetic friction torque see derivation notes to verify the expression */
  /* Position from frame 0 to the centre of gravity of the cylinder */
  /* Position to second point of the cylinder */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Constructor */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Evaluates if the external force is greater than the static */
  /* friction forces or torques */
  /* Evaluates wich static friction have to be compared */
  /* Condition checker */
  /* if the Friction condition is 0 there is no movement */
  /* if the Friction condition is 1 there is movement */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Calculates the acceleration components in X and Y for the centre of */
  /* gravity of the object and the angular acceleration */
  /* Ecuation of motion for X coordinates */
  /* Ecuation of motion for y coordinates */
  /* Ecuation of motion for Tetha coordinates */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute positions for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute velocities for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  ForceReactionIndex[0] = IndexFext[0] - GeneralCoordinatesDoubleDot_idx_0 *
    b_obj->M;
  ForceReactionIndex[1] = IndexFext[1] - GeneralCoordinatesDoubleDot_idx_0 *
    b_obj->M;
  b_obj = obj;
  covrtLogFcn(moduleInstance->covInst, 0, 15);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 43);

  /* Radius of the cylindrical object in meters */
  /* Mass of the object in Kg */
  /* Acceleration of gravity in m/s^2 */
  /* Static coefficient of friction */
  /* Kinetic coefficient of friction */
  /* Static rotational coefficient of friction */
  /* Kinetic rotational coefficient of friction */
  /* Static contact coefficient of friction */
  /* Kinetic contact coefficient of friction */
  /* Inertia of the cylindrical object in Z */
  /* Static friction force in X */
  /* Static friction force in Y */
  /* Kinetic friction force in X */
  /* Kinetic friction force in Y */
  /* Static friction torque see derivation notes to verify the expression */
  /* Kinetic friction torque see derivation notes to verify the expression */
  /* Position from frame 0 to the centre of gravity of the cylinder */
  /* Position to second point of the cylinder */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Constructor */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Evaluates if the external force is greater than the static */
  /* friction forces or torques */
  /* Evaluates wich static friction have to be compared */
  /* Condition checker */
  /* if the Friction condition is 0 there is no movement */
  /* if the Friction condition is 1 there is movement */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Calculates the acceleration components in X and Y for the centre of */
  /* gravity of the object and the angular acceleration */
  /* Ecuation of motion for X coordinates */
  /* Ecuation of motion for y coordinates */
  /* Ecuation of motion for Tetha coordinates */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute positions for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute velocities for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  /* ............................................................................ */
  /* ............................................................................ */
  /* Absolute Accelerations for G3 and P3 updated from frame 0 */
  ForceReactionThumb[0] = ThumbFext[0] - GeneralCoordinatesDoubleDot_idx_0 *
    b_obj->M;
  ForceReactionThumb[1] = ThumbFext[1] - GeneralCoordinatesDoubleDot_idx_0 *
    b_obj->M;
  b_obj = obj;
  covrtLogFcn(moduleInstance->covInst, 0, 3);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 13);
  for (k = 0; k < 2; k++) {
    FrictionForceInContactFrameThumb[k] = b_obj->Position_G3_P3_frame_cylinder[k];
  }

  dv0[0] = muDoubleScalarCos(angle);
  dv0[2] = -muDoubleScalarSin(angle);
  dv0[1] = muDoubleScalarSin(angle);
  dv0[3] = muDoubleScalarCos(angle);
  b_xPositionG3[0] = xPositionG3;
  b_xPositionG3[1] = yPositionG3;
  for (k = 0; k < 2; k++) {
    RotatedForceToFrame0Index[k] = 0.0;
    for (i1 = 0; i1 < 2; i1++) {
      RotatedForceToFrame0Index[k] += dv0[k + (i1 << 1)] *
        FrictionForceInContactFrameThumb[i1];
    }

    RotMatrix_0_4_Thumb[k] = b_obj->Position_o_G3[k];
    RotMatrix_0_4_Thumb[2 + k] = b_xPositionG3[k] + RotatedForceToFrame0Index[k];
  }

  covrtLogFcn(moduleInstance->covInst, 0, 4);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 14);
  b_obj = obj;
  covrtLogFcn(moduleInstance->covInst, 0, 5);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 15);
  FrictionForceInContactFrameThumb[0] = (GeneralCoordinatesDoubleDot_idx_0 +
    b_obj->R * muDoubleScalarSin(angle) * (angleDot * angleDot)) - b_obj->R *
    muDoubleScalarCos(angle) * ResultantTorqueIndex;
  FrictionForceInContactFrameThumb[1] = (GeneralCoordinatesDoubleDot_idx_1 -
    b_obj->R * muDoubleScalarCos(angle) * (angleDot * angleDot)) - b_obj->R *
    muDoubleScalarSin(angle) * ResultantTorqueIndex;
  GeneralCoordinatesDoubleDot[0] = GeneralCoordinatesDoubleDot_idx_0;
  GeneralCoordinatesDoubleDot[1] = GeneralCoordinatesDoubleDot_idx_1;
  b_GeneralCoordinatesDoubleDot[0] = ResultantTorqueIndex;
  b_GeneralCoordinatesDoubleDot[1] = 0.0;
  for (k = 0; k < 2; k++) {
    c_GeneralCoordinatesDoubleDot[k] = GeneralCoordinatesDoubleDot[k];
    c_GeneralCoordinatesDoubleDot[2 + k] = FrictionForceInContactFrameThumb[k];
    c_GeneralCoordinatesDoubleDot[4 + k] = b_GeneralCoordinatesDoubleDot[k];
  }

  for (k = 0; k < 3; k++) {
    CylinderResults[k] = c_GeneralCoordinatesDoubleDot[iv0[k]];
  }

  for (k = 0; k < 2; k++) {
    CylinderResults[k + 3] = RotMatrix_0_4_Thumb[2 + k];
  }

  CylinderResults[5] = obj->R;
  for (k = 0; k < 2; k++) {
    CylinderResults[k + 6] = ForceReactionIndex[k];
    CylinderResults[k + 8] = ForceReactionThumb[k];
  }

  CylinderResults[10] = obj->Urk;
  CylinderResults[11] = (real_T)FrictionCondition;
}

static void Cylinder_ColissionConditionCalc(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, Cylinder *obj, boolean_T ColissionCondition[2], real_T
  IndexForce[2], real_T ThumbForce[2], real_T BunchOfTotalForces[4])
{
  int32_T i2;
  (void)obj;
  covrtLogFcn(moduleInstance->covInst, 0, 13);
  if (covrtLogCond(moduleInstance->covInst, 0, 0, 4, ColissionCondition[0]) &&
      covrtLogCond(moduleInstance->covInst, 0, 0, 5, ColissionCondition[1])) {
    covrtLogMcdc(moduleInstance->covInst, 0, 0, 4, true);
    covrtLogIf(moduleInstance->covInst, 0, 0, 14, true);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 33);
    for (i2 = 0; i2 < 2; i2++) {
      BunchOfTotalForces[i2] = IndexForce[i2];
      BunchOfTotalForces[2 + i2] = ThumbForce[i2];
    }
  } else {
    covrtLogMcdc(moduleInstance->covInst, 0, 0, 4, false);
    covrtLogIf(moduleInstance->covInst, 0, 0, 14, false);
    if (covrtLogCond(moduleInstance->covInst, 0, 0, 6, !ColissionCondition[0]) &&
        covrtLogCond(moduleInstance->covInst, 0, 0, 7, ColissionCondition[1])) {
      covrtLogMcdc(moduleInstance->covInst, 0, 0, 5, true);
      covrtLogIf(moduleInstance->covInst, 0, 0, 15, true);
      covrtLogBasicBlock(moduleInstance->covInst, 0, 34);
      for (i2 = 0; i2 < 2; i2++) {
        BunchOfTotalForces[i2] = 0.0;
        BunchOfTotalForces[2 + i2] = ThumbForce[i2];
      }
    } else {
      covrtLogMcdc(moduleInstance->covInst, 0, 0, 5, false);
      covrtLogIf(moduleInstance->covInst, 0, 0, 15, false);
      if (covrtLogCond(moduleInstance->covInst, 0, 0, 8, ColissionCondition[0]) &&
          covrtLogCond(moduleInstance->covInst, 0, 0, 9, !ColissionCondition[1]))
      {
        covrtLogMcdc(moduleInstance->covInst, 0, 0, 6, true);
        covrtLogIf(moduleInstance->covInst, 0, 0, 16, true);
        covrtLogBasicBlock(moduleInstance->covInst, 0, 35);
        for (i2 = 0; i2 < 2; i2++) {
          BunchOfTotalForces[i2] = IndexForce[i2];
          BunchOfTotalForces[2 + i2] = 0.0;
        }
      } else {
        covrtLogMcdc(moduleInstance->covInst, 0, 0, 6, false);
        covrtLogIf(moduleInstance->covInst, 0, 0, 16, false);
        covrtLogBasicBlock(moduleInstance->covInst, 0, 36);
        for (i2 = 0; i2 < 4; i2++) {
          BunchOfTotalForces[i2] = 0.0;
        }
      }
    }
  }
}

static void Cylinder_RotationToContactFrame(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, Cylinder *obj, real_T CollisionPosition[2], real_T
  xPositionG3, real_T yPositionG3, real_T RotMatrix_0_4[4])
{
  real_T Theta;
  real_T tan_angle;
  (void)obj;
  covrtLogFcn(moduleInstance->covInst, 0, 6);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 16);
  Theta = 0.0;
  if (covrtLogIf(moduleInstance->covInst, 0, 0, 6, CollisionPosition[0] -
                 xPositionG3 == 0.0)) {
    if (covrtLogIf(moduleInstance->covInst, 0, 0, 7, CollisionPosition[1] -
                   yPositionG3 > 0.0)) {
      covrtLogBasicBlock(moduleInstance->covInst, 0, 17);
      Theta = 1.5707963267948966;
    } else {
      covrtLogBasicBlock(moduleInstance->covInst, 0, 18);
      Theta = 4.71238898038469;
    }
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 19);
    tan_angle = (CollisionPosition[1] - yPositionG3) / (CollisionPosition[0] -
      xPositionG3);
    if (covrtLogCond(moduleInstance->covInst, 0, 0, 10, tan_angle > 0.0) &&
        covrtLogCond(moduleInstance->covInst, 0, 0, 11, CollisionPosition[0] -
                     xPositionG3 > 0.0) && covrtLogCond(moduleInstance->covInst,
         0, 0, 12, CollisionPosition[1] - yPositionG3 > 0.0)) {
      covrtLogMcdc(moduleInstance->covInst, 0, 0, 0, true);
      covrtLogIf(moduleInstance->covInst, 0, 0, 8, true);
      covrtLogBasicBlock(moduleInstance->covInst, 0, 20);
      Theta = muDoubleScalarAtan(tan_angle);
    } else {
      covrtLogMcdc(moduleInstance->covInst, 0, 0, 0, false);
      covrtLogIf(moduleInstance->covInst, 0, 0, 8, false);
      if (covrtLogCond(moduleInstance->covInst, 0, 0, 13, tan_angle > 0.0) &&
          covrtLogCond(moduleInstance->covInst, 0, 0, 14, CollisionPosition[0] -
                       xPositionG3 < 0.0) && covrtLogCond
          (moduleInstance->covInst, 0, 0, 15, CollisionPosition[1] - yPositionG3
           < 0.0)) {
        covrtLogMcdc(moduleInstance->covInst, 0, 0, 1, true);
        covrtLogIf(moduleInstance->covInst, 0, 0, 9, true);
        covrtLogBasicBlock(moduleInstance->covInst, 0, 21);
        Theta = muDoubleScalarAtan(tan_angle) + 3.1415926535897931;
      } else {
        covrtLogMcdc(moduleInstance->covInst, 0, 0, 1, false);
        covrtLogIf(moduleInstance->covInst, 0, 0, 9, false);
        if (covrtLogCond(moduleInstance->covInst, 0, 0, 16, tan_angle < 0.0) &&
            covrtLogCond(moduleInstance->covInst, 0, 0, 17, CollisionPosition[0]
                         - xPositionG3 < 0.0) && covrtLogCond
            (moduleInstance->covInst, 0, 0, 18, CollisionPosition[1] -
             yPositionG3 > 0.0)) {
          covrtLogMcdc(moduleInstance->covInst, 0, 0, 2, true);
          covrtLogIf(moduleInstance->covInst, 0, 0, 10, true);
          covrtLogBasicBlock(moduleInstance->covInst, 0, 22);
          Theta = muDoubleScalarAtan(tan_angle);
        } else {
          covrtLogMcdc(moduleInstance->covInst, 0, 0, 2, false);
          covrtLogIf(moduleInstance->covInst, 0, 0, 10, false);
          if (covrtLogCond(moduleInstance->covInst, 0, 0, 19, tan_angle < 0.0) &&
              covrtLogCond(moduleInstance->covInst, 0, 0, 20, CollisionPosition
                           [0] - xPositionG3 > 0.0) && covrtLogCond
              (moduleInstance->covInst, 0, 0, 21, CollisionPosition[1] -
               yPositionG3 < 0.0)) {
            covrtLogMcdc(moduleInstance->covInst, 0, 0, 3, true);
            covrtLogIf(moduleInstance->covInst, 0, 0, 11, true);
            covrtLogBasicBlock(moduleInstance->covInst, 0, 23);
            Theta = muDoubleScalarAtan(tan_angle) + 3.1415926535897931;
          } else {
            covrtLogMcdc(moduleInstance->covInst, 0, 0, 3, false);
            covrtLogIf(moduleInstance->covInst, 0, 0, 11, false);
            if (covrtLogIf(moduleInstance->covInst, 0, 0, 12, tan_angle == 0.0))
            {
              covrtLogBasicBlock(moduleInstance->covInst, 0, 24);
            }
          }
        }
      }
    }
  }

  covrtLogBasicBlock(moduleInstance->covInst, 0, 25);
  RotMatrix_0_4[0] = muDoubleScalarCos(Theta);
  RotMatrix_0_4[2] = -muDoubleScalarSin(Theta);
  RotMatrix_0_4[1] = muDoubleScalarSin(Theta);
  RotMatrix_0_4[3] = muDoubleScalarCos(Theta);
}

static void cgxe_mdl_start(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance)
{
  int32_T postfix_exprs_0_0[3] = { 0, 1, -3 };

  int32_T cond_ends_0_0[2] = { 13072, 13102 };

  int32_T cond_starts_0_0[2] = { 13046, 13076 };

  int32_T postfix_exprs_0_1[3] = { 0, 1, -3 };

  int32_T cond_ends_0_1[2] = { 14398, 14428 };

  int32_T cond_starts_0_1[2] = { 14372, 14402 };

  int32_T postfix_exprs_0_2[3] = { 0, 1, -3 };

  int32_T cond_ends_0_2[2] = { 10553, 10581 };

  int32_T cond_starts_0_2[2] = { 10529, 10557 };

  int32_T postfix_exprs_0_3[3] = { 0, 1, -3 };

  int32_T cond_ends_0_3[2] = { 10686, 10714 };

  int32_T cond_starts_0_3[2] = { 10662, 10690 };

  int32_T postfix_exprs_0_4[3] = { 0, 1, -3 };

  int32_T cond_ends_0_4[2] = { 10814, 10842 };

  int32_T cond_starts_0_4[2] = { 10790, 10818 };

  int32_T postfix_exprs_0_5[5] = { 0, 1, -3, 2, -3 };

  int32_T cond_ends_0_5[3] = { 6844, 6884, 6924 };

  int32_T cond_starts_0_5[3] = { 6833, 6848, 6888 };

  int32_T postfix_exprs_0_6[5] = { 0, 1, -3, 2, -3 };

  int32_T cond_ends_0_6[3] = { 7003, 7043, 7083 };

  int32_T cond_starts_0_6[3] = { 6992, 7007, 7047 };

  int32_T postfix_exprs_0_7[5] = { 0, 1, -3, 2, -3 };

  int32_T cond_ends_0_7[3] = { 7165, 7205, 7245 };

  int32_T cond_starts_0_7[3] = { 7154, 7169, 7209 };

  int32_T postfix_exprs_0_8[5] = { 0, 1, -3, 2, -3 };

  int32_T cond_ends_0_8[3] = { 7324, 7364, 7404 };

  int32_T cond_starts_0_8[3] = { 7313, 7328, 7368 };

  real_T varargin_17[2];
  real_T varargin_18[2];
  int32_T i3;
  boolean_T flag;
  Cylinder *obj;
  static char_T cv0[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T u[51];
  const mxArray *y;
  static const int32_T iv1[2] = { 1, 51 };

  const mxArray *m0;
  static char_T cv1[5] = { 's', 'e', 't', 'u', 'p' };

  char_T b_u[5];
  const mxArray *b_y;
  static const int32_T iv2[2] = { 1, 5 };

  static char_T cv2[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T c_u[44];
  const mxArray *c_y;
  static const int32_T iv3[2] = { 1, 44 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
  real_T *Urs;
  real_T *Urk;
  real_T *Ucs;
  real_T *Uck;
  real_T *Iz;
  real_T *F_s_x;
  real_T *F_s_y;
  real_T *F_k_x;
  real_T *F_k_y;
  real_T *T_s;
  real_T *T_k;
  real_T (*Position_o_G3)[2];
  real_T (*Position_G3_P3_frame_cylinder)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])cgxertGetRunTimeParamInfoData
    (moduleInstance->S, 17);
  Position_o_G3 = (real_T (*)[2])cgxertGetRunTimeParamInfoData(moduleInstance->S,
    16);
  T_k = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 15);
  T_s = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 14);
  F_k_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 13);
  F_k_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 12);
  F_s_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  F_s_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  Iz = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  Uck = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  Ucs = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  Urk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  Urs = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  Uk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  Us = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  g = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  M = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  R = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  init_simulink_io_address(moduleInstance);

  /* Allocate instance data */
  covrtAllocateInstanceData(moduleInstance->covInst);

  /* Initialize Coverage Information */
  covrtScriptInit(moduleInstance->covInst,
                  "C:\\Users\\Ricardo\\Documents\\Workspace\\Directed Studies\\Simulation\\Classes\\Cylinder.m",
                  0, 17, 45, 21, 0, 0, 0, 0, 0, 22, 9);

  /* Initialize Function Information */
  covrtFcnInit(moduleInstance->covInst, 0, 15, "Cylinder_ForceReactionFinger",
               15481, -1, 15836);
  covrtFcnInit(moduleInstance->covInst, 0, 14, "Cylinder_ReactionForceCalc",
               11229, -1, 15245);
  covrtFcnInit(moduleInstance->covInst, 0, 13, "Cylinder_ColissionConditionCalc",
               10417, -1, 10993);
  covrtFcnInit(moduleInstance->covInst, 0, 12,
               "Cylinder_ResultantXForceWithoutFloorFrictionY", 10026, -1, 10181);
  covrtFcnInit(moduleInstance->covInst, 0, 11,
               "Cylinder_ResultantXForceWithoutFloorFrictionX", 9635, -1, 9790);
  covrtFcnInit(moduleInstance->covInst, 0, 10, "Cylinder_ResultantTorqueCalc",
               9223, -1, 9399);
  covrtFcnInit(moduleInstance->covInst, 0, 9,
               "Cylinder_ConvesrsionContactPointFrame0", 8835, -1, 8987);
  covrtFcnInit(moduleInstance->covInst, 0, 8,
               "Cylinder_EvaluateFrictionInContactPoint", 8248, -1, 8599);
  covrtFcnInit(moduleInstance->covInst, 0, 7,
               "Cylinder_ConvesrsionForceContactPoint", 7876, -1, 8012);
  covrtFcnInit(moduleInstance->covInst, 0, 6, "Cylinder_RotationToContactFrame",
               6367, -1, 7640);
  covrtFcnInit(moduleInstance->covInst, 0, 5, "Cylinder_AccCalculation", 5629,
               -1, 6131);
  covrtFcnInit(moduleInstance->covInst, 0, 4, "Cylinder_VelCalculation", 5086,
               -1, 5393);
  covrtFcnInit(moduleInstance->covInst, 0, 3, "Cylinder_PosCalculation", 4480,
               -1, 4853);
  covrtFcnInit(moduleInstance->covInst, 0, 2, "Cylinder_Equation_Of_Motion",
               3172, -1, 4248);
  covrtFcnInit(moduleInstance->covInst, 0, 1, "Cylinder_NonLinearFriction", 2189,
               -1, 2870);
  covrtFcnInit(moduleInstance->covInst, 0, 0, "Cylinder_Cylinder", 1248, -1,
               1920);
  covrtFcnInit(moduleInstance->covInst, 0, 16, "Cylinder_stepImpl", 16173, -1,
               17579);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(moduleInstance->covInst, 0, 43, 15580, -1, 15823);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 42, 14630, -1, 15232);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 41, 14445, -1, 14602);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 40, 13119, -1, 14352);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 39, 12418, -1, 13026);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 38, 11747, -1, 12355);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 37, 11440, -1, 11687);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 36, 10932, -1, 10964);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 35, 10860, -1, 10897);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 34, 10732, -1, 10769);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 33, 10599, -1, 10641);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 32, 10129, -1, 10168);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 31, 9738, -1, 9777);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 30, 9323, -1, 9386);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 29, 8934, -1, 8974);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 28, 8530, -1, 8570);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 27, 8407, -1, 8495);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 26, 7966, -1, 7999);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 25, 7567, -1, 7627);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 24, 7509, -1, 7516);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 23, 7426, -1, 7450);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 22, 7267, -1, 7288);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 21, 7105, -1, 7129);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 20, 6946, -1, 6967);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 19, 6733, -1, 6812);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 18, 6666, -1, 6678);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 17, 6613, -1, 6623);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 16, 6472, -1, 6479);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 15, 5739, -1, 6118);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 14, 5170, -1, 5380);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 13, 4563, -1, 4840);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 12, 4186, -1, 4219);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 11, 4073, -1, 4151);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 10, 3888, -1, 3921);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 9, 3774, -1, 3853);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 8, 3591, -1, 3624);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 7, 3477, -1, 3556);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 6, 3258, -1, 3389);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 5, 2773, -1, 2792);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 4, 2667, -1, 2686);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 3, 2535, -1, 2558);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 2, 2475, -1, 2500);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 1, 2384, -1, 2409);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 0, 1292, -1, 1907);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 44, 16386, -1, 17566);

  /* Initialize If Information */
  covrtIfInit(moduleInstance->covInst, 0, 17, 11700, 11731, 12368, 12402);
  covrtIfInit(moduleInstance->covInst, 0, 18, 12368, 12402, 13039, 14618);
  covrtIfInit(moduleInstance->covInst, 0, 19, 13039, 13103, 14365, 14618);
  covrtIfInit(moduleInstance->covInst, 0, 20, 14365, 14429, -1, 14429);
  covrtIfInit(moduleInstance->covInst, 0, 14, 10526, 10582, 10655, 10981);
  covrtIfInit(moduleInstance->covInst, 0, 15, 10655, 10715, 10783, 10981);
  covrtIfInit(moduleInstance->covInst, 0, 16, 10783, 10843, 10911, 10981);
  covrtIfInit(moduleInstance->covInst, 0, 13, 8346, 8390, 8509, 8587);
  covrtIfInit(moduleInstance->covInst, 0, 6, 6493, 6535, 6712, 7553);
  covrtIfInit(moduleInstance->covInst, 0, 7, 6552, 6592, 6641, 6699);
  covrtIfInit(moduleInstance->covInst, 0, 8, 6830, 6925, 6985, 7084);
  covrtIfInit(moduleInstance->covInst, 0, 9, 6985, 7084, 7147, 7537);
  covrtIfInit(moduleInstance->covInst, 0, 10, 7147, 7246, 7306, 7537);
  covrtIfInit(moduleInstance->covInst, 0, 11, 7306, 7405, 7468, 7537);
  covrtIfInit(moduleInstance->covInst, 0, 12, 7468, 7488, -1, 7488);
  covrtIfInit(moduleInstance->covInst, 0, 3, 3403, 3460, 3570, 3641);
  covrtIfInit(moduleInstance->covInst, 0, 4, 3700, 3757, 3867, 3938);
  covrtIfInit(moduleInstance->covInst, 0, 5, 4001, 4056, 4165, 4236);
  covrtIfInit(moduleInstance->covInst, 0, 0, 2335, 2367, 2423, 2575);
  covrtIfInit(moduleInstance->covInst, 0, 1, 2423, 2458, 2514, 2575);
  covrtIfInit(moduleInstance->covInst, 0, 2, 2619, 2650, 2752, 2858);

  /* Initialize MCDC Information */
  covrtMcdcInit(moduleInstance->covInst, 0, 7, 13046, 13102, 2, 0,
                cond_starts_0_0, cond_ends_0_0, 3, postfix_exprs_0_0);
  covrtMcdcInit(moduleInstance->covInst, 0, 8, 14372, 14428, 2, 2,
                cond_starts_0_1, cond_ends_0_1, 3, postfix_exprs_0_1);
  covrtMcdcInit(moduleInstance->covInst, 0, 4, 10529, 10581, 2, 4,
                cond_starts_0_2, cond_ends_0_2, 3, postfix_exprs_0_2);
  covrtMcdcInit(moduleInstance->covInst, 0, 5, 10662, 10714, 2, 6,
                cond_starts_0_3, cond_ends_0_3, 3, postfix_exprs_0_3);
  covrtMcdcInit(moduleInstance->covInst, 0, 6, 10790, 10842, 2, 8,
                cond_starts_0_4, cond_ends_0_4, 3, postfix_exprs_0_4);
  covrtMcdcInit(moduleInstance->covInst, 0, 0, 6833, 6924, 3, 10,
                cond_starts_0_5, cond_ends_0_5, 5, postfix_exprs_0_5);
  covrtMcdcInit(moduleInstance->covInst, 0, 1, 6992, 7083, 3, 13,
                cond_starts_0_6, cond_ends_0_6, 5, postfix_exprs_0_6);
  covrtMcdcInit(moduleInstance->covInst, 0, 2, 7154, 7245, 3, 16,
                cond_starts_0_7, cond_ends_0_7, 5, postfix_exprs_0_7);
  covrtMcdcInit(moduleInstance->covInst, 0, 3, 7313, 7404, 3, 19,
                cond_starts_0_8, cond_ends_0_8, 5, postfix_exprs_0_8);

  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(moduleInstance->covInst, 0U);
  for (i3 = 0; i3 < 2; i3++) {
    varargin_17[i3] = (*Position_o_G3)[i3];
    varargin_18[i3] = (*Position_G3_P3_frame_cylinder)[i3];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Cylinder_Cylinder(moduleInstance, &moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urs = *Urs;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urk = *Urk;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Ucs = *Ucs;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uck = *Uck;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i3 = 0; i3 < 2; i3++) {
      moduleInstance->sysobj.Position_o_G3[i3] = varargin_17[i3];
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i3 = 0; i3 < 2; i3++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i3] = varargin_18[i3];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized != 0) {
    for (i3 = 0; i3 < 51; i3++) {
      u[i3] = cv0[i3];
    }

    y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m0, &u[0]);
    emlrtAssign(&y, m0);
    for (i3 = 0; i3 < 5; i3++) {
      b_u[i3] = cv1[i3];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m0, &b_u[0]);
    emlrtAssign(&b_y, m0);
    error(moduleInstance, b_message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  obj->isInitialized = 1;
  if (obj->TunablePropsChanged) {
    for (i3 = 0; i3 < 44; i3++) {
      c_u[i3] = cv2[i3];
    }

    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m0, &c_u[0]);
    emlrtAssign(&c_y, m0);
    error(moduleInstance, message(moduleInstance, c_y, &b_emlrtMCI), &b_emlrtMCI);
  }

  obj->TunablePropsChanged = false;
}

static void cgxe_mdl_initialize(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance)
{
  real_T varargin_17[2];
  real_T varargin_18[2];
  int32_T i4;
  boolean_T tunablePropChangedBeforeResetImpl;
  Cylinder *obj;
  static char_T cv3[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv4[2] = { 1, 45 };

  const mxArray *m1;
  static char_T cv4[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv5[2] = { 1, 8 };

  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv6[2] = { 1, 45 };

  static char_T cv5[5] = { 'r', 'e', 's', 'e', 't' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv7[2] = { 1, 5 };

  static char_T cv6[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T e_u[44];
  const mxArray *e_y;
  static const int32_T iv8[2] = { 1, 44 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
  real_T *Urs;
  real_T *Urk;
  real_T *Ucs;
  real_T *Uck;
  real_T *Iz;
  real_T *F_s_x;
  real_T *F_s_y;
  real_T *F_k_x;
  real_T *F_k_y;
  real_T *T_s;
  real_T *T_k;
  real_T (*Position_o_G3)[2];
  real_T (*Position_G3_P3_frame_cylinder)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])cgxertGetRunTimeParamInfoData
    (moduleInstance->S, 17);
  Position_o_G3 = (real_T (*)[2])cgxertGetRunTimeParamInfoData(moduleInstance->S,
    16);
  T_k = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 15);
  T_s = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 14);
  F_k_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 13);
  F_k_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 12);
  F_s_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  F_s_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  Iz = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  Uck = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  Ucs = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  Urk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  Urs = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  Uk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  Us = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  g = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  M = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  R = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  for (i4 = 0; i4 < 2; i4++) {
    varargin_17[i4] = (*Position_o_G3)[i4];
    varargin_18[i4] = (*Position_G3_P3_frame_cylinder)[i4];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Cylinder_Cylinder(moduleInstance, &moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urs = *Urs;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urk = *Urk;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Ucs = *Ucs;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uck = *Uck;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i4 = 0; i4 < 2; i4++) {
      moduleInstance->sysobj.Position_o_G3[i4] = varargin_17[i4];
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i4 = 0; i4 < 2; i4++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i4] = varargin_18[i4];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i4 = 0; i4 < 45; i4++) {
      u[i4] = cv3[i4];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv4);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m1, &u[0]);
    emlrtAssign(&y, m1);
    for (i4 = 0; i4 < 8; i4++) {
      b_u[i4] = cv4[i4];
    }

    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv5);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m1, &b_u[0]);
    emlrtAssign(&b_y, m1);
    error(moduleInstance, b_message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  tunablePropChangedBeforeResetImpl = (obj->isInitialized == 1);
  if (tunablePropChangedBeforeResetImpl) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i4 = 0; i4 < 45; i4++) {
        c_u[i4] = cv3[i4];
      }

      c_y = NULL;
      m1 = emlrtCreateCharArray(2, iv6);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m1, &c_u
        [0]);
      emlrtAssign(&c_y, m1);
      for (i4 = 0; i4 < 5; i4++) {
        d_u[i4] = cv5[i4];
      }

      d_y = NULL;
      m1 = emlrtCreateCharArray(2, iv7);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m1, &d_u[0]);
      emlrtAssign(&d_y, m1);
      error(moduleInstance, b_message(moduleInstance, c_y, d_y, &b_emlrtMCI),
            &b_emlrtMCI);
    }

    tunablePropChangedBeforeResetImpl = obj->TunablePropsChanged;
    if ((int32_T)tunablePropChangedBeforeResetImpl != (int32_T)
        obj->TunablePropsChanged) {
      for (i4 = 0; i4 < 44; i4++) {
        e_u[i4] = cv6[i4];
      }

      e_y = NULL;
      m1 = emlrtCreateCharArray(2, iv8);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m1, &e_u
        [0]);
      emlrtAssign(&e_y, m1);
      error(moduleInstance, message(moduleInstance, e_y, &b_emlrtMCI),
            &b_emlrtMCI);
    }
  }
}

static void cgxe_mdl_outputs(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance)
{
  real_T varargin_17[2];
  real_T varargin_18[2];
  real_T varargin_20[2];
  real_T varargin_21[2];
  boolean_T varargin_22[2];
  int32_T k;
  boolean_T flag;
  real_T hoistedGlobal_R;
  boolean_T p;
  real_T hoistedGlobal_Position_o_G3[2];
  boolean_T exitg2;
  boolean_T exitg1;
  Cylinder *obj;
  static char_T cv7[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv9[2] = { 1, 45 };

  const mxArray *m2;
  static char_T cv8[4] = { 's', 't', 'e', 'p' };

  char_T b_u[4];
  const mxArray *b_y;
  static const int32_T iv10[2] = { 1, 4 };

  static char_T cv9[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T c_u[51];
  const mxArray *c_y;
  static const int32_T iv11[2] = { 1, 51 };

  static char_T cv10[5] = { 's', 'e', 't', 'u', 'p' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv12[2] = { 1, 5 };

  static char_T cv11[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T e_u[44];
  const mxArray *e_y;
  static const int32_T iv13[2] = { 1, 44 };

  char_T f_u[44];
  const mxArray *f_y;
  static const int32_T iv14[2] = { 1, 44 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
  real_T *Urs;
  real_T *Urk;
  real_T *Ucs;
  real_T *Uck;
  real_T *Iz;
  real_T *F_s_x;
  real_T *F_s_y;
  real_T *F_k_x;
  real_T *F_k_y;
  real_T *T_s;
  real_T *T_k;
  real_T (*Position_o_G3)[2];
  real_T (*Position_G3_P3_frame_cylinder)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])cgxertGetRunTimeParamInfoData
    (moduleInstance->S, 17);
  Position_o_G3 = (real_T (*)[2])cgxertGetRunTimeParamInfoData(moduleInstance->S,
    16);
  T_k = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 15);
  T_s = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 14);
  F_k_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 13);
  F_k_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 12);
  F_s_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  F_s_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  Iz = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  Uck = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  Ucs = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  Urk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  Urs = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  Uk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  Us = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  g = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  M = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  R = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  for (k = 0; k < 2; k++) {
    varargin_17[k] = (*Position_o_G3)[k];
    varargin_18[k] = (*Position_G3_P3_frame_cylinder)[k];
    varargin_20[k] = (*moduleInstance->u1)[k];
    varargin_21[k] = (*moduleInstance->u2)[k];
    varargin_22[k] = (*moduleInstance->u3)[k];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Cylinder_Cylinder(moduleInstance, &moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urs = *Urs;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urk = *Urk;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Ucs = *Ucs;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uck = *Uck;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_o_G3[k] = varargin_17[k];
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k] = varargin_18[k];
    }
  }

  hoistedGlobal_R = moduleInstance->sysobj.R;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *R)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
  }

  hoistedGlobal_R = moduleInstance->sysobj.M;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *M)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
  }

  hoistedGlobal_R = moduleInstance->sysobj.g;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *g)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
  }

  hoistedGlobal_R = moduleInstance->sysobj.Us;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *Us)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
  }

  hoistedGlobal_R = moduleInstance->sysobj.Uk;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *Uk)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
  }

  hoistedGlobal_R = moduleInstance->sysobj.Urs;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *Urs)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urs = *Urs;
  }

  hoistedGlobal_R = moduleInstance->sysobj.Urk;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *Urk)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urk = *Urk;
  }

  hoistedGlobal_R = moduleInstance->sysobj.Ucs;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *Ucs)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Ucs = *Ucs;
  }

  hoistedGlobal_R = moduleInstance->sysobj.Uck;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *Uck)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uck = *Uck;
  }

  hoistedGlobal_R = moduleInstance->sysobj.Iz;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *Iz)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
  }

  hoistedGlobal_R = moduleInstance->sysobj.F_s_x;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *F_s_x)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
  }

  hoistedGlobal_R = moduleInstance->sysobj.F_s_y;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *F_s_y)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
  }

  hoistedGlobal_R = moduleInstance->sysobj.F_k_x;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *F_k_x)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
  }

  hoistedGlobal_R = moduleInstance->sysobj.F_k_y;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *F_k_y)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
  }

  hoistedGlobal_R = moduleInstance->sysobj.T_s;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *T_s)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
  }

  hoistedGlobal_R = moduleInstance->sysobj.T_k;
  flag = false;
  p = true;
  if (!(hoistedGlobal_R == *T_k)) {
    p = false;
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
  }

  for (k = 0; k < 2; k++) {
    hoistedGlobal_Position_o_G3[k] = moduleInstance->sysobj.Position_o_G3[k];
  }

  flag = false;
  p = true;
  k = 0;
  exitg2 = false;
  while ((exitg2 == false) && (k < 2)) {
    if (!(hoistedGlobal_Position_o_G3[k] == varargin_17[k])) {
      p = false;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_o_G3[k] = varargin_17[k];
    }
  }

  for (k = 0; k < 2; k++) {
    varargin_17[k] = moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k];
  }

  flag = false;
  p = true;
  k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (k < 2)) {
    if (!(varargin_17[k] == varargin_18[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (p) {
    flag = true;
  }

  if (!flag) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k] = varargin_18[k];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (k = 0; k < 45; k++) {
      u[k] = cv7[k];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv9);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m2, &u[0]);
    emlrtAssign(&y, m2);
    for (k = 0; k < 4; k++) {
      b_u[k] = cv8[k];
    }

    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv10);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 4, m2, &b_u[0]);
    emlrtAssign(&b_y, m2);
    error(moduleInstance, b_message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  if (obj->isInitialized != 1) {
    if (obj->isInitialized != 0) {
      for (k = 0; k < 51; k++) {
        c_u[k] = cv9[k];
      }

      c_y = NULL;
      m2 = emlrtCreateCharArray(2, iv11);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m2, &c_u
        [0]);
      emlrtAssign(&c_y, m2);
      for (k = 0; k < 5; k++) {
        d_u[k] = cv10[k];
      }

      d_y = NULL;
      m2 = emlrtCreateCharArray(2, iv12);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m2, &d_u[0]);
      emlrtAssign(&d_y, m2);
      error(moduleInstance, b_message(moduleInstance, c_y, d_y, &b_emlrtMCI),
            &b_emlrtMCI);
    }

    obj->isInitialized = 1;
    if (obj->TunablePropsChanged) {
      for (k = 0; k < 44; k++) {
        e_u[k] = cv11[k];
      }

      e_y = NULL;
      m2 = emlrtCreateCharArray(2, iv13);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m2, &e_u
        [0]);
      emlrtAssign(&e_y, m2);
      error(moduleInstance, message(moduleInstance, e_y, &b_emlrtMCI),
            &b_emlrtMCI);
    }

    obj->TunablePropsChanged = false;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
  }

  Cylinder_stepImpl(moduleInstance, obj, *moduleInstance->u0, varargin_20,
                    varargin_21, varargin_22, *moduleInstance->u4,
                    *moduleInstance->u5, *moduleInstance->u6,
                    *moduleInstance->u7, *moduleInstance->u8,
                    *moduleInstance->u9, *moduleInstance->u10,
                    *moduleInstance->b_y0);
  if (obj->TunablePropsChanged) {
    for (k = 0; k < 44; k++) {
      f_u[k] = cv11[k];
    }

    f_y = NULL;
    m2 = emlrtCreateCharArray(2, iv14);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m2, &f_u[0]);
    emlrtAssign(&f_y, m2);
    error(moduleInstance, message(moduleInstance, f_y, &b_emlrtMCI), &b_emlrtMCI);
  }
}

static void cgxe_mdl_update(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance)
{
  real_T varargin_17[2];
  real_T varargin_18[2];
  int32_T i5;
  boolean_T flag;
  Cylinder *obj;
  static char_T cv12[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv15[2] = { 1, 45 };

  const mxArray *m3;
  static char_T cv13[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv16[2] = { 1, 8 };

  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv17[2] = { 1, 45 };

  static char_T cv14[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  char_T d_u[7];
  const mxArray *d_y;
  static const int32_T iv18[2] = { 1, 7 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
  real_T *Urs;
  real_T *Urk;
  real_T *Ucs;
  real_T *Uck;
  real_T *Iz;
  real_T *F_s_x;
  real_T *F_s_y;
  real_T *F_k_x;
  real_T *F_k_y;
  real_T *T_s;
  real_T *T_k;
  real_T (*Position_o_G3)[2];
  real_T (*Position_G3_P3_frame_cylinder)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])cgxertGetRunTimeParamInfoData
    (moduleInstance->S, 17);
  Position_o_G3 = (real_T (*)[2])cgxertGetRunTimeParamInfoData(moduleInstance->S,
    16);
  T_k = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 15);
  T_s = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 14);
  F_k_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 13);
  F_k_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 12);
  F_s_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  F_s_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  Iz = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  Uck = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  Ucs = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  Urk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  Urs = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  Uk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  Us = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  g = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  M = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  R = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  for (i5 = 0; i5 < 2; i5++) {
    varargin_17[i5] = (*Position_o_G3)[i5];
    varargin_18[i5] = (*Position_G3_P3_frame_cylinder)[i5];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Cylinder_Cylinder(moduleInstance, &moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urs = *Urs;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Urk = *Urk;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Ucs = *Ucs;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uck = *Uck;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i5 = 0; i5 < 2; i5++) {
      moduleInstance->sysobj.Position_o_G3[i5] = varargin_17[i5];
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i5 = 0; i5 < 2; i5++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i5] = varargin_18[i5];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i5 = 0; i5 < 45; i5++) {
      u[i5] = cv12[i5];
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv15);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &u[0]);
    emlrtAssign(&y, m3);
    for (i5 = 0; i5 < 8; i5++) {
      b_u[i5] = cv13[i5];
    }

    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv16);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m3, &b_u[0]);
    emlrtAssign(&b_y, m3);
    error(moduleInstance, b_message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i5 = 0; i5 < 45; i5++) {
        c_u[i5] = cv12[i5];
      }

      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv17);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &c_u
        [0]);
      emlrtAssign(&c_y, m3);
      for (i5 = 0; i5 < 7; i5++) {
        d_u[i5] = cv14[i5];
      }

      d_y = NULL;
      m3 = emlrtCreateCharArray(2, iv18);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 7, m3, &d_u[0]);
      emlrtAssign(&d_y, m3);
      error(moduleInstance, b_message(moduleInstance, c_y, d_y, &b_emlrtMCI),
            &b_emlrtMCI);
    }

    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* Free instance data */
  covrtFreeInstanceData(moduleInstance->covInst);
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance)
{
  const mxArray *st;
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m4;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  static const int32_T iv19[1] = { 2 };

  real_T *pData;
  int32_T i;
  const mxArray *v_y;
  static const int32_T iv20[1] = { 2 };

  const mxArray *w_y;
  st = NULL;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  m4 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m4) = moduleInstance->sysobj.isInitialized;
  emlrtAssign(&c_y, m4);
  emlrtAddField(b_y, c_y, "isInitialized", 0);
  d_y = NULL;
  m4 = emlrtCreateLogicalScalar(moduleInstance->sysobj.TunablePropsChanged);
  emlrtAssign(&d_y, m4);
  emlrtAddField(b_y, d_y, "TunablePropsChanged", 0);
  e_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.R);
  emlrtAssign(&e_y, m4);
  emlrtAddField(b_y, e_y, "R", 0);
  f_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.M);
  emlrtAssign(&f_y, m4);
  emlrtAddField(b_y, f_y, "M", 0);
  g_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.g);
  emlrtAssign(&g_y, m4);
  emlrtAddField(b_y, g_y, "g", 0);
  h_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Us);
  emlrtAssign(&h_y, m4);
  emlrtAddField(b_y, h_y, "Us", 0);
  i_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Uk);
  emlrtAssign(&i_y, m4);
  emlrtAddField(b_y, i_y, "Uk", 0);
  j_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Urs);
  emlrtAssign(&j_y, m4);
  emlrtAddField(b_y, j_y, "Urs", 0);
  k_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Urk);
  emlrtAssign(&k_y, m4);
  emlrtAddField(b_y, k_y, "Urk", 0);
  l_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Ucs);
  emlrtAssign(&l_y, m4);
  emlrtAddField(b_y, l_y, "Ucs", 0);
  m_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Uck);
  emlrtAssign(&m_y, m4);
  emlrtAddField(b_y, m_y, "Uck", 0);
  n_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Iz);
  emlrtAssign(&n_y, m4);
  emlrtAddField(b_y, n_y, "Iz", 0);
  o_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_s_x);
  emlrtAssign(&o_y, m4);
  emlrtAddField(b_y, o_y, "F_s_x", 0);
  p_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_s_y);
  emlrtAssign(&p_y, m4);
  emlrtAddField(b_y, p_y, "F_s_y", 0);
  q_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_k_x);
  emlrtAssign(&q_y, m4);
  emlrtAddField(b_y, q_y, "F_k_x", 0);
  r_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_k_y);
  emlrtAssign(&r_y, m4);
  emlrtAddField(b_y, r_y, "F_k_y", 0);
  s_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.T_s);
  emlrtAssign(&s_y, m4);
  emlrtAddField(b_y, s_y, "T_s", 0);
  t_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.T_k);
  emlrtAssign(&t_y, m4);
  emlrtAddField(b_y, t_y, "T_k", 0);
  u_y = NULL;
  m4 = emlrtCreateNumericArray(1, iv19, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m4);
  for (i = 0; i < 2; i++) {
    pData[i] = moduleInstance->sysobj.Position_o_G3[i];
  }

  emlrtAssign(&u_y, m4);
  emlrtAddField(b_y, u_y, "Position_o_G3", 0);
  v_y = NULL;
  m4 = emlrtCreateNumericArray(1, iv20, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m4);
  for (i = 0; i < 2; i++) {
    pData[i] = moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i];
  }

  emlrtAssign(&v_y, m4);
  emlrtAddField(b_y, v_y, "Position_G3_P3_frame_cylinder", 0);
  emlrtSetCell(y, 0, b_y);
  w_y = NULL;
  m4 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&w_y, m4);
  emlrtSetCell(y, 1, w_y);
  emlrtAssign(&st, y);
  return st;
}

static void emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *b_sysobj, const char_T *identifier, Cylinder
  *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(moduleInstance, emlrtAlias(b_sysobj), &thisId, y);
  emlrtDestroyArray(&b_sysobj);
}

static void b_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Cylinder *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[20] = { "isInitialized", "TunablePropsChanged",
    "R", "M", "g", "Us", "Uk", "Urs", "Urk", "Ucs", "Uck", "Iz", "F_s_x",
    "F_s_y", "F_k_x", "F_k_y", "T_s", "T_k", "Position_o_G3",
    "Position_G3_P3_frame_cylinder" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(moduleInstance->emlrtRootTLSGlobal, parentId, u, 20,
    fieldNames, 0U, &dims);
  thisId.fIdentifier = "isInitialized";
  y->isInitialized = c_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetFieldR2013a(moduleInstance->emlrtRootTLSGlobal, u, 0,
    "isInitialized")), &thisId);
  thisId.fIdentifier = "TunablePropsChanged";
  y->TunablePropsChanged = d_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetFieldR2013a(moduleInstance->emlrtRootTLSGlobal, u, 0,
    "TunablePropsChanged")), &thisId);
  thisId.fIdentifier = "R";
  y->R = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "R")), &thisId);
  thisId.fIdentifier = "M";
  y->M = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "M")), &thisId);
  thisId.fIdentifier = "g";
  y->g = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "g")), &thisId);
  thisId.fIdentifier = "Us";
  y->Us = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Us")), &thisId);
  thisId.fIdentifier = "Uk";
  y->Uk = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Uk")), &thisId);
  thisId.fIdentifier = "Urs";
  y->Urs = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Urs")), &thisId);
  thisId.fIdentifier = "Urk";
  y->Urk = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Urk")), &thisId);
  thisId.fIdentifier = "Ucs";
  y->Ucs = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Ucs")), &thisId);
  thisId.fIdentifier = "Uck";
  y->Uck = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Uck")), &thisId);
  thisId.fIdentifier = "Iz";
  y->Iz = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Iz")), &thisId);
  thisId.fIdentifier = "F_s_x";
  y->F_s_x = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "F_s_x")), &thisId);
  thisId.fIdentifier = "F_s_y";
  y->F_s_y = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "F_s_y")), &thisId);
  thisId.fIdentifier = "F_k_x";
  y->F_k_x = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "F_k_x")), &thisId);
  thisId.fIdentifier = "F_k_y";
  y->F_k_y = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "F_k_y")), &thisId);
  thisId.fIdentifier = "T_s";
  y->T_s = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "T_s")), &thisId);
  thisId.fIdentifier = "T_k";
  y->T_k = e_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "T_k")), &thisId);
  thisId.fIdentifier = "Position_o_G3";
  f_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Position_o_G3")), &thisId,
                     y->Position_o_G3);
  thisId.fIdentifier = "Position_G3_P3_frame_cylinder";
  f_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Position_G3_P3_frame_cylinder")),
                     &thisId, y->Position_G3_P3_frame_cylinder);
  emlrtDestroyArray(&u);
}

static int32_T c_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = h_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T d_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = i_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void f_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2])
{
  k_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T g_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(moduleInstance, emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *
  moduleInstance, const mxArray *st)
{
  const mxArray *u;
  u = emlrtAlias(st);
  emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetCell
    (moduleInstance->emlrtRootTLSGlobal, "sysobj", u, 0)), "sysobj",
                   &moduleInstance->sysobj);
  moduleInstance->sysobj_not_empty = g_emlrt_marshallIn(moduleInstance,
    emlrtAlias(emlrtGetCell(moduleInstance->emlrtRootTLSGlobal,
    "sysobj_not_empty", u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static const mxArray *message(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m5;
  pArray = b;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m5, 1,
    &pArray, "message", true, location);
}

static void error(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 0, NULL, 1, &pArray,
                        "error", true, location);
}

static const mxArray *b_message(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m6, 2,
    pArrays, "message", true, location);
}

static int32_T h_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId)
{
  int32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "int32", false, 0U, &dims);
  ret = *(int32_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T i_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "logical", false, 0U, &dims);
  ret = *mxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T j_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void k_emlrt_marshallIn(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2])
{
  static const int32_T dims[1] = { 2 };

  int32_T i6;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "double", false, 1U, dims);
  for (i6 = 0; i6 < 2; i6++) {
    ret[i6] = (*(real_T (*)[2])mxGetData(src))[i6];
  }

  emlrtDestroyArray(&src);
}

static void init_simulink_io_address(InstanceStruct_CynCoNzEkJ1QVd5zEkhIm
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = cgxertGetEMLRTCtx(moduleInstance->S, 0);
  moduleInstance->covInst = (covrtInstance *)cgxertGetCovrtInstance
    (moduleInstance->S, 0);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T (*)[2])cgxertGetInputPortSignal(moduleInstance->S,
    1);
  moduleInstance->u2 = (real_T (*)[2])cgxertGetInputPortSignal(moduleInstance->S,
    2);
  moduleInstance->u3 = (boolean_T (*)[2])cgxertGetInputPortSignal
    (moduleInstance->S, 3);
  moduleInstance->u4 = (real_T (*)[4])cgxertGetInputPortSignal(moduleInstance->S,
    4);
  moduleInstance->u5 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 5);
  moduleInstance->u6 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 6);
  moduleInstance->u7 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 7);
  moduleInstance->u8 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 8);
  moduleInstance->u9 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 9);
  moduleInstance->u10 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 10);
  moduleInstance->b_y0 = (real_T (*)[12])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S, int_T tid)
{
  InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance =
    (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S)
{
  InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance =
    (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S, int_T tid)
{
  InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance =
    (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static mxArray* getSimState_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance =
    (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  return mxSS;
}

static void setSimState_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance =
    (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *)cgxertGetRuntimeInstance(S);
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S)
{
  InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance =
    (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlStart_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S)
{
  InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *moduleInstance =
    (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm *)calloc(1, sizeof
    (InstanceStruct_CynCoNzEkJ1QVd5zEkhIm));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_CynCoNzEkJ1QVd5zEkhIm);
  ssSetmdlInitializeConditions(S, mdlInitialize_CynCoNzEkJ1QVd5zEkhIm);
  ssSetmdlUpdate(S, mdlUpdate_CynCoNzEkJ1QVd5zEkhIm);
  ssSetmdlTerminate(S, mdlTerminate_CynCoNzEkJ1QVd5zEkhIm);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S)
{
}

void method_dispatcher_CynCoNzEkJ1QVd5zEkhIm(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_CynCoNzEkJ1QVd5zEkhIm(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_CynCoNzEkJ1QVd5zEkhIm(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_CynCoNzEkJ1QVd5zEkhIm(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_CynCoNzEkJ1QVd5zEkhIm(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: CynCoNzEkJ1QVd5zEkhIm.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_CynCoNzEkJ1QVd5zEkhIm_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_9 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_9);
  return mxBIArgs;
}
