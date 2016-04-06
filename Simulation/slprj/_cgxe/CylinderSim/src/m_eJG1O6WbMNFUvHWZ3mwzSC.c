/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CylinderSim_cgxe.h"
#include "m_eJG1O6WbMNFUvHWZ3mwzSC.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 1, 1, "SystemCore",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a64\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"
};

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance);
static const mxArray *mw__internal__name__resolution__fcn(void);
static void info_helper(const mxArray **info);
static const mxArray *emlrt_marshallOut(const char * u);
static const mxArray *b_emlrt_marshallOut(const uint32_T u);
static void b_info_helper(const mxArray **info);
static const mxArray *mw__internal__autoInference__fcn(void);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance);
static void emlrt_marshallIn(const mxArray *b_sysobj, const char_T *identifier,
  Cylinder *y);
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, Cylinder *y);
static int32_T c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void e_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[2]);
static boolean_T f_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier);
static boolean_T g_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void mw__internal__setSimState__fcn(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance, const mxArray *st);
static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location);
static void error(const mxArray *b, emlrtMCInfo *location);
static int32_T h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static real_T i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void j_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[2]);
static boolean_T k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance)
{
  real_T a;
  int32_T i0;
  Cylinder *obj;
  static char_T cv0[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T u[51];
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 51 };

  const mxArray *m0;
  static char_T cv1[5] = { 's', 'e', 't', 'u', 'p' };

  char_T b_u[5];
  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 5 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
  real_T *Urs;
  real_T *Urk;
  real_T *Iz;
  real_T *F_s_x;
  real_T *F_s_y;
  real_T *F_k_x;
  real_T *F_k_y;
  real_T *T_s;
  real_T *T_k;
  real_T (*Position_G3_P3_frame_cylinder)[2];
  real_T (*Position_o_G3)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])(ssGetRunTimeParamInfo
    (moduleInstance->S, 15U))->data;
  Position_o_G3 = (real_T (*)[2])(ssGetRunTimeParamInfo(moduleInstance->S, 14U)
    )->data;
  T_k = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 13U))->data;
  T_s = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 12U))->data;
  F_k_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  F_k_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  F_s_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  F_s_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  Iz = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  Urk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  Urs = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  Uk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  Us = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  g = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  M = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  R = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;

  /* Allocate instance data */
  covrtAllocateInstanceData(&moduleInstance->covInst);

  /* Initialize Coverage Information */
  covrtScriptInit(&moduleInstance->covInst,
                  "C:\\Jhon\\UNIMELB\\cursos\\Directed studies\\GithubDirected\\Simulation\\Classes\\Cylinder.m",
                  0, 7, 17, 6, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&moduleInstance->covInst, 0, 5, "Cylinder_AccCalculation", 5476,
               -1, 5978);
  covrtFcnInit(&moduleInstance->covInst, 0, 4, "Cylinder_VelCalculation", 4933,
               -1, 5240);
  covrtFcnInit(&moduleInstance->covInst, 0, 3, "Cylinder_PosCalculation", 4327,
               -1, 4700);
  covrtFcnInit(&moduleInstance->covInst, 0, 2, "Cylinder_Equation_Of_Motion",
               3019, -1, 4095);
  covrtFcnInit(&moduleInstance->covInst, 0, 1, "Cylinder_NonLinearFriction",
               2036, -1, 2717);
  covrtFcnInit(&moduleInstance->covInst, 0, 0, "Cylinder_Cylinder", 1145, -1,
               1767);
  covrtFcnInit(&moduleInstance->covInst, 0, 6, "Cylinder_stepImpl", 6315, -1,
               7231);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 15, 5586, -1, 5965);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 14, 5017, -1, 5227);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 13, 4410, -1, 4687);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 12, 4033, -1, 4066);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 11, 3920, -1, 3998);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 10, 3735, -1, 3768);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 9, 3621, -1, 3700);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 8, 3438, -1, 3471);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 7, 3324, -1, 3403);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 6, 3105, -1, 3236);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 5, 2620, -1, 2639);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 4, 2514, -1, 2533);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 3, 2382, -1, 2405);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 2, 2322, -1, 2347);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 1, 2231, -1, 2256);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 0, 1189, -1, 1754);
  covrtBasicBlockInit(&moduleInstance->covInst, 0, 16, 6505, -1, 7218);

  /* Initialize If Information */
  covrtIfInit(&moduleInstance->covInst, 0, 3, 3250, 3307, 3417, 3488);
  covrtIfInit(&moduleInstance->covInst, 0, 4, 3547, 3604, 3714, 3785);
  covrtIfInit(&moduleInstance->covInst, 0, 5, 3848, 3903, 4012, 4083);
  covrtIfInit(&moduleInstance->covInst, 0, 0, 2182, 2214, 2270, 2422);
  covrtIfInit(&moduleInstance->covInst, 0, 1, 2270, 2305, 2361, 2422);
  covrtIfInit(&moduleInstance->covInst, 0, 2, 2466, 2497, 2599, 2705);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&moduleInstance->covInst, 0U);
  if (!moduleInstance->sysobj_not_empty) {
    covrtLogFcn(&moduleInstance->covInst, 0, 0);
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 0);
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj.R = 0.02;
    moduleInstance->sysobj.M = 0.003;
    moduleInstance->sysobj.g = 9.81;
    moduleInstance->sysobj.Us = 0.5;
    moduleInstance->sysobj.Uk = 0.48;
    moduleInstance->sysobj.Urs = 0.5;
    moduleInstance->sysobj.Urk = 0.48;
    a = moduleInstance->sysobj.R;
    a = moduleInstance->sysobj.M * (a * a);
    moduleInstance->sysobj.Iz = a / 2.0;
    moduleInstance->sysobj.F_s_x = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Us;
    moduleInstance->sysobj.F_s_y = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Us;
    moduleInstance->sysobj.F_k_x = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Uk;
    moduleInstance->sysobj.F_k_y = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Uk;
    moduleInstance->sysobj.T_s = 0.66666666666666663 *
      moduleInstance->sysobj.Urs * moduleInstance->sysobj.R *
      moduleInstance->sysobj.M * moduleInstance->sysobj.g;
    moduleInstance->sysobj.T_k = 0.66666666666666663 *
      moduleInstance->sysobj.Urk * moduleInstance->sysobj.R *
      moduleInstance->sysobj.M * moduleInstance->sysobj.g;
    for (i0 = 0; i0 < 2; i0++) {
      moduleInstance->sysobj.Position_o_G3[i0] = 0.0;
    }

    moduleInstance->sysobj.Position_G3_P3_frame_cylinder[0] = 0.0;
    moduleInstance->sysobj.Position_G3_P3_frame_cylinder[1] =
      moduleInstance->sysobj.R;
    moduleInstance->sysobj_not_empty = true;
    moduleInstance->sysobj.R = *R;
    moduleInstance->sysobj.M = *M;
    moduleInstance->sysobj.g = *g;
    moduleInstance->sysobj.Us = *Us;
    moduleInstance->sysobj.Uk = *Uk;
    moduleInstance->sysobj.Urs = *Urs;
    moduleInstance->sysobj.Urk = *Urk;
    moduleInstance->sysobj.Iz = *Iz;
    moduleInstance->sysobj.F_s_x = *F_s_x;
    moduleInstance->sysobj.F_s_y = *F_s_y;
    moduleInstance->sysobj.F_k_x = *F_k_x;
    moduleInstance->sysobj.F_k_y = *F_k_y;
    moduleInstance->sysobj.T_s = *T_s;
    moduleInstance->sysobj.T_k = *T_k;
    for (i0 = 0; i0 < 2; i0++) {
      moduleInstance->sysobj.Position_o_G3[i0] = (*Position_o_G3)[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i0] =
        (*Position_G3_P3_frame_cylinder)[i0];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized != 0) {
    for (i0 = 0; i0 < 51; i0++) {
      u[i0] = cv0[i0];
    }

    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m0, &u[0]);
    emlrtAssign(&y, m0);
    for (i0 = 0; i0 < 5; i0++) {
      b_u[i0] = cv1[i0];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m0, &b_u[0]);
    emlrtAssign(&b_y, m0);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  obj->isInitialized = 1;
}

static void cgxe_mdl_initialize(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance)
{
  real_T a;
  int32_T i1;
  Cylinder *obj;
  static char_T cv2[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 45 };

  const mxArray *m1;
  static char_T cv3[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 8 };

  boolean_T flag;
  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv4[2] = { 1, 45 };

  static char_T cv4[5] = { 'r', 'e', 's', 'e', 't' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv5[2] = { 1, 5 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
  real_T *Urs;
  real_T *Urk;
  real_T *Iz;
  real_T *F_s_x;
  real_T *F_s_y;
  real_T *F_k_x;
  real_T *F_k_y;
  real_T *T_s;
  real_T *T_k;
  real_T (*Position_G3_P3_frame_cylinder)[2];
  real_T (*Position_o_G3)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])(ssGetRunTimeParamInfo
    (moduleInstance->S, 15U))->data;
  Position_o_G3 = (real_T (*)[2])(ssGetRunTimeParamInfo(moduleInstance->S, 14U)
    )->data;
  T_k = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 13U))->data;
  T_s = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 12U))->data;
  F_k_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  F_k_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  F_s_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  F_s_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  Iz = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  Urk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  Urs = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  Uk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  Us = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  g = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  M = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  R = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  if (!moduleInstance->sysobj_not_empty) {
    covrtLogFcn(&moduleInstance->covInst, 0, 0);
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 0);
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj.R = 0.02;
    moduleInstance->sysobj.M = 0.003;
    moduleInstance->sysobj.g = 9.81;
    moduleInstance->sysobj.Us = 0.5;
    moduleInstance->sysobj.Uk = 0.48;
    moduleInstance->sysobj.Urs = 0.5;
    moduleInstance->sysobj.Urk = 0.48;
    a = moduleInstance->sysobj.R;
    a = moduleInstance->sysobj.M * (a * a);
    moduleInstance->sysobj.Iz = a / 2.0;
    moduleInstance->sysobj.F_s_x = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Us;
    moduleInstance->sysobj.F_s_y = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Us;
    moduleInstance->sysobj.F_k_x = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Uk;
    moduleInstance->sysobj.F_k_y = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Uk;
    moduleInstance->sysobj.T_s = 0.66666666666666663 *
      moduleInstance->sysobj.Urs * moduleInstance->sysobj.R *
      moduleInstance->sysobj.M * moduleInstance->sysobj.g;
    moduleInstance->sysobj.T_k = 0.66666666666666663 *
      moduleInstance->sysobj.Urk * moduleInstance->sysobj.R *
      moduleInstance->sysobj.M * moduleInstance->sysobj.g;
    for (i1 = 0; i1 < 2; i1++) {
      moduleInstance->sysobj.Position_o_G3[i1] = 0.0;
    }

    moduleInstance->sysobj.Position_G3_P3_frame_cylinder[0] = 0.0;
    moduleInstance->sysobj.Position_G3_P3_frame_cylinder[1] =
      moduleInstance->sysobj.R;
    moduleInstance->sysobj_not_empty = true;
    moduleInstance->sysobj.R = *R;
    moduleInstance->sysobj.M = *M;
    moduleInstance->sysobj.g = *g;
    moduleInstance->sysobj.Us = *Us;
    moduleInstance->sysobj.Uk = *Uk;
    moduleInstance->sysobj.Urs = *Urs;
    moduleInstance->sysobj.Urk = *Urk;
    moduleInstance->sysobj.Iz = *Iz;
    moduleInstance->sysobj.F_s_x = *F_s_x;
    moduleInstance->sysobj.F_s_y = *F_s_y;
    moduleInstance->sysobj.F_k_x = *F_k_x;
    moduleInstance->sysobj.F_k_y = *F_k_y;
    moduleInstance->sysobj.T_s = *T_s;
    moduleInstance->sysobj.T_k = *T_k;
    for (i1 = 0; i1 < 2; i1++) {
      moduleInstance->sysobj.Position_o_G3[i1] = (*Position_o_G3)[i1];
    }

    for (i1 = 0; i1 < 2; i1++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i1] =
        (*Position_G3_P3_frame_cylinder)[i1];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i1 = 0; i1 < 45; i1++) {
      u[i1] = cv2[i1];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, &u[0]);
    emlrtAssign(&y, m1);
    for (i1 = 0; i1 < 8; i1++) {
      b_u[i1] = cv3[i1];
    }

    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m1, &b_u[0]);
    emlrtAssign(&b_y, m1);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag && (moduleInstance->sysobj.isInitialized == 2)) {
    for (i1 = 0; i1 < 45; i1++) {
      c_u[i1] = cv2[i1];
    }

    c_y = NULL;
    m1 = emlrtCreateCharArray(2, iv4);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, &c_u[0]);
    emlrtAssign(&c_y, m1);
    for (i1 = 0; i1 < 5; i1++) {
      d_u[i1] = cv4[i1];
    }

    d_y = NULL;
    m1 = emlrtCreateCharArray(2, iv5);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m1, &d_u[0]);
    emlrtAssign(&d_y, m1);
    error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
  }
}

static void cgxe_mdl_outputs(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance)
{
  real_T Acceleration_o_P3_frame_0[2];
  real_T varargin_16[2];
  int32_T k;
  real_T ForceEvaluation;
  boolean_T p;
  boolean_T b_p;
  real_T hoistedGlobal_Position_o_G3[2];
  boolean_T exitg2;
  boolean_T exitg1;
  Cylinder *obj;
  static char_T cv5[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 45 };

  const mxArray *m2;
  static char_T cv6[4] = { 's', 't', 'e', 'p' };

  char_T b_u[4];
  const mxArray *b_y;
  static const int32_T iv7[2] = { 1, 4 };

  static char_T cv7[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T c_u[51];
  const mxArray *c_y;
  static const int32_T iv8[2] = { 1, 51 };

  static char_T cv8[5] = { 's', 'e', 't', 'u', 'p' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv9[2] = { 1, 5 };

  real_T GenCordExt[3];
  real_T SignOposite[3];
  real_T B;
  real_T GeneralCoordinatesDoubleDot_idx_0;
  real_T GeneralCoordinatesDoubleDot_idx_1;
  real_T dv0[4];
  real_T varargin_8[2];
  int32_T i2;
  real_T Positions[4];
  real_T GeneralCoordinatesDoubleDot[2];
  real_T b_GeneralCoordinatesDoubleDot[2];
  real_T c_GeneralCoordinatesDoubleDot[6];
  static int8_T iv10[3] = { 0, 1, 4 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
  real_T *Urs;
  real_T *Urk;
  real_T *Iz;
  real_T *F_s_x;
  real_T *F_s_y;
  real_T *F_k_x;
  real_T *F_k_y;
  real_T *T_s;
  real_T *T_k;
  real_T *u0;
  real_T *u1;
  real_T *u2;
  real_T *u3;
  real_T *u9;
  real_T *u7;
  real_T *u8;
  real_T *u6;
  real_T (*b_y0)[8];
  real_T (*Position_o_G3)[2];
  real_T (*Position_G3_P3_frame_cylinder)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])(ssGetRunTimeParamInfo
    (moduleInstance->S, 15U))->data;
  Position_o_G3 = (real_T (*)[2])(ssGetRunTimeParamInfo(moduleInstance->S, 14U)
    )->data;
  T_k = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 13U))->data;
  T_s = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 12U))->data;
  F_k_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  F_k_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  F_s_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  F_s_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  Iz = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  Urk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  Urs = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  Uk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  Us = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  g = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  M = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  R = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  b_y0 = (real_T (*)[8])ssGetOutputPortSignal(moduleInstance->S, 0U);
  u9 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 9U);
  u8 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 8U);
  u7 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 7U);
  u6 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 6U);
  u3 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 3U);
  u2 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 2U);
  u1 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 1U);
  u0 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 0U);
  for (k = 0; k < 2; k++) {
    Acceleration_o_P3_frame_0[k] = (*Position_o_G3)[k];
    varargin_16[k] = (*Position_G3_P3_frame_cylinder)[k];
  }

  if (!moduleInstance->sysobj_not_empty) {
    covrtLogFcn(&moduleInstance->covInst, 0, 0);
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 0);
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj.R = 0.02;
    moduleInstance->sysobj.M = 0.003;
    moduleInstance->sysobj.g = 9.81;
    moduleInstance->sysobj.Us = 0.5;
    moduleInstance->sysobj.Uk = 0.48;
    moduleInstance->sysobj.Urs = 0.5;
    moduleInstance->sysobj.Urk = 0.48;
    ForceEvaluation = moduleInstance->sysobj.R;
    ForceEvaluation = moduleInstance->sysobj.M * (ForceEvaluation *
      ForceEvaluation);
    moduleInstance->sysobj.Iz = ForceEvaluation / 2.0;
    moduleInstance->sysobj.F_s_x = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Us;
    moduleInstance->sysobj.F_s_y = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Us;
    moduleInstance->sysobj.F_k_x = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Uk;
    moduleInstance->sysobj.F_k_y = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Uk;
    moduleInstance->sysobj.T_s = 0.66666666666666663 *
      moduleInstance->sysobj.Urs * moduleInstance->sysobj.R *
      moduleInstance->sysobj.M * moduleInstance->sysobj.g;
    moduleInstance->sysobj.T_k = 0.66666666666666663 *
      moduleInstance->sysobj.Urk * moduleInstance->sysobj.R *
      moduleInstance->sysobj.M * moduleInstance->sysobj.g;
    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_o_G3[k] = 0.0;
    }

    moduleInstance->sysobj.Position_G3_P3_frame_cylinder[0] = 0.0;
    moduleInstance->sysobj.Position_G3_P3_frame_cylinder[1] =
      moduleInstance->sysobj.R;
    moduleInstance->sysobj_not_empty = true;
    moduleInstance->sysobj.R = *R;
    moduleInstance->sysobj.M = *M;
    moduleInstance->sysobj.g = *g;
    moduleInstance->sysobj.Us = *Us;
    moduleInstance->sysobj.Uk = *Uk;
    moduleInstance->sysobj.Urs = *Urs;
    moduleInstance->sysobj.Urk = *Urk;
    moduleInstance->sysobj.Iz = *Iz;
    moduleInstance->sysobj.F_s_x = *F_s_x;
    moduleInstance->sysobj.F_s_y = *F_s_y;
    moduleInstance->sysobj.F_k_x = *F_k_x;
    moduleInstance->sysobj.F_k_y = *F_k_y;
    moduleInstance->sysobj.T_s = *T_s;
    moduleInstance->sysobj.T_k = *T_k;
    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_o_G3[k] = Acceleration_o_P3_frame_0[k];
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k] = varargin_16[k];
    }
  }

  ForceEvaluation = moduleInstance->sysobj.R;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *R)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.R = *R;
  }

  ForceEvaluation = moduleInstance->sysobj.M;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *M)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.M = *M;
  }

  ForceEvaluation = moduleInstance->sysobj.g;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *g)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.g = *g;
  }

  ForceEvaluation = moduleInstance->sysobj.Us;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *Us)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.Us = *Us;
  }

  ForceEvaluation = moduleInstance->sysobj.Uk;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *Uk)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.Uk = *Uk;
  }

  ForceEvaluation = moduleInstance->sysobj.Urs;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *Urs)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.Urs = *Urs;
  }

  ForceEvaluation = moduleInstance->sysobj.Urk;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *Urk)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.Urk = *Urk;
  }

  ForceEvaluation = moduleInstance->sysobj.Iz;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *Iz)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.Iz = *Iz;
  }

  ForceEvaluation = moduleInstance->sysobj.F_s_x;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *F_s_x)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.F_s_x = *F_s_x;
  }

  ForceEvaluation = moduleInstance->sysobj.F_s_y;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *F_s_y)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.F_s_y = *F_s_y;
  }

  ForceEvaluation = moduleInstance->sysobj.F_k_x;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *F_k_x)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.F_k_x = *F_k_x;
  }

  ForceEvaluation = moduleInstance->sysobj.F_k_y;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *F_k_y)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.F_k_y = *F_k_y;
  }

  ForceEvaluation = moduleInstance->sysobj.T_s;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *T_s)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.T_s = *T_s;
  }

  ForceEvaluation = moduleInstance->sysobj.T_k;
  p = false;
  b_p = true;
  if (!(ForceEvaluation == *T_k)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    moduleInstance->sysobj.T_k = *T_k;
  }

  for (k = 0; k < 2; k++) {
    hoistedGlobal_Position_o_G3[k] = moduleInstance->sysobj.Position_o_G3[k];
  }

  p = false;
  b_p = true;
  k = 0;
  exitg2 = false;
  while ((exitg2 == false) && (k < 2)) {
    if (!(hoistedGlobal_Position_o_G3[k] == Acceleration_o_P3_frame_0[k])) {
      b_p = false;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_o_G3[k] = Acceleration_o_P3_frame_0[k];
    }
  }

  for (k = 0; k < 2; k++) {
    hoistedGlobal_Position_o_G3[k] =
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k];
  }

  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (k < 2)) {
    if (!(hoistedGlobal_Position_o_G3[k] == varargin_16[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k] = varargin_16[k];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (k = 0; k < 45; k++) {
      u[k] = cv5[k];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m2, &u[0]);
    emlrtAssign(&y, m2);
    for (k = 0; k < 4; k++) {
      b_u[k] = cv6[k];
    }

    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv7);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 4, m2, &b_u[0]);
    emlrtAssign(&b_y, m2);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  if (obj->isInitialized != 1) {
    if (obj->isInitialized != 0) {
      for (k = 0; k < 51; k++) {
        c_u[k] = cv7[k];
      }

      c_y = NULL;
      m2 = emlrtCreateCharArray(2, iv8);
      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m2, &c_u[0]);
      emlrtAssign(&c_y, m2);
      for (k = 0; k < 5; k++) {
        d_u[k] = cv8[k];
      }

      d_y = NULL;
      m2 = emlrtCreateCharArray(2, iv9);
      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m2, &d_u[0]);
      emlrtAssign(&d_y, m2);
      error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
    }

    obj->isInitialized = 1;
  }

  covrtLogFcn(&moduleInstance->covInst, 0, 6);
  covrtLogBasicBlock(&moduleInstance->covInst, 0, 16);

  /* ............................................................................ */
  /* ............................................................................ */
  /* Function that is called in Simulink to calculate updated */
  /* positions,velocities and accelerations for the cylinder */
  obj->Urk = *u0;
  obj->T_k = 0.66666666666666663 * obj->Urk * obj->R * obj->M * obj->g;
  GenCordExt[0] = *u1;
  GenCordExt[1] = *u2;
  GenCordExt[2] = *u3;
  covrtLogFcn(&moduleInstance->covInst, 0, 2);
  covrtLogBasicBlock(&moduleInstance->covInst, 0, 6);
  for (k = 0; k < 3; k++) {
    SignOposite[k] = -muDoubleScalarSign(GenCordExt[k]);
  }

  covrtLogFcn(&moduleInstance->covInst, 0, 1);
  covrtLogIf(&moduleInstance->covInst, 0, 0, 0, true);
  covrtLogBasicBlock(&moduleInstance->covInst, 0, 1);
  ForceEvaluation = obj->F_s_x;
  if (covrtLogIf(&moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs(*u1) <=
                 ForceEvaluation)) {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(&moduleInstance->covInst, 0, 0, 3, k == 1)) {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 7);
    ForceEvaluation = *u1 + SignOposite[0] * obj->F_k_x;
    B = obj->M;
    GeneralCoordinatesDoubleDot_idx_0 = ForceEvaluation / B;
  } else {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 8);
    GeneralCoordinatesDoubleDot_idx_0 = 0.0;
  }

  covrtLogFcn(&moduleInstance->covInst, 0, 1);
  covrtLogIf(&moduleInstance->covInst, 0, 0, 0, false);
  covrtLogIf(&moduleInstance->covInst, 0, 0, 1, true);
  covrtLogBasicBlock(&moduleInstance->covInst, 0, 2);
  ForceEvaluation = obj->F_s_y;
  if (covrtLogIf(&moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs(*u2) <=
                 ForceEvaluation)) {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(&moduleInstance->covInst, 0, 0, 4, k == 1)) {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 9);
    ForceEvaluation = *u2 + SignOposite[1] * obj->F_k_y;
    B = obj->M;
    GeneralCoordinatesDoubleDot_idx_1 = ForceEvaluation / B;
  } else {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 10);
    GeneralCoordinatesDoubleDot_idx_1 = 0.0;
  }

  covrtLogFcn(&moduleInstance->covInst, 0, 1);
  covrtLogIf(&moduleInstance->covInst, 0, 0, 0, false);
  covrtLogIf(&moduleInstance->covInst, 0, 0, 1, false);
  covrtLogBasicBlock(&moduleInstance->covInst, 0, 3);
  ForceEvaluation = obj->T_s;
  if (covrtLogIf(&moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs(*u3) <=
                 ForceEvaluation)) {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(&moduleInstance->covInst, 0, 0, 5, k == 1)) {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 11);
    ForceEvaluation = *u3 + SignOposite[2] * obj->T_k;
    B = obj->Iz;
    ForceEvaluation /= B;
  } else {
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 12);
    ForceEvaluation = 0.0;
  }

  covrtLogFcn(&moduleInstance->covInst, 0, 3);
  covrtLogBasicBlock(&moduleInstance->covInst, 0, 13);
  for (k = 0; k < 2; k++) {
    Acceleration_o_P3_frame_0[k] = obj->Position_G3_P3_frame_cylinder[k];
  }

  dv0[0] = muDoubleScalarCos(*u9);
  dv0[2] = -muDoubleScalarSin(*u9);
  dv0[1] = muDoubleScalarSin(*u9);
  dv0[3] = muDoubleScalarCos(*u9);
  varargin_8[0] = *u7;
  varargin_8[1] = *u8;
  for (k = 0; k < 2; k++) {
    hoistedGlobal_Position_o_G3[k] = 0.0;
    for (i2 = 0; i2 < 2; i2++) {
      hoistedGlobal_Position_o_G3[k] += dv0[k + (i2 << 1)] *
        Acceleration_o_P3_frame_0[i2];
    }
  }

  for (k = 0; k < 2; k++) {
    Positions[k] = obj->Position_o_G3[k];
  }

  for (k = 0; k < 2; k++) {
    Positions[2 + k] = varargin_8[k] + hoistedGlobal_Position_o_G3[k];
  }

  covrtLogFcn(&moduleInstance->covInst, 0, 4);
  covrtLogBasicBlock(&moduleInstance->covInst, 0, 14);
  covrtLogFcn(&moduleInstance->covInst, 0, 5);
  covrtLogBasicBlock(&moduleInstance->covInst, 0, 15);

  /* Radius of the cylindrical object in meters */
  /* Mass of the object in Kg */
  /* Acceleration of gravity in m/s^2 */
  /* Static coefficient of friction */
  /* Kinetic coefficient of friction */
  /* Static rotational coefficient of friction */
  /* Kinetic rotational coefficient of friction */
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
  Acceleration_o_P3_frame_0[0] = (GeneralCoordinatesDoubleDot_idx_0 + obj->R *
    muDoubleScalarSin(*u9) * (*u6 * *u6)) - obj->R * muDoubleScalarCos(*u9) *
    ForceEvaluation;
  Acceleration_o_P3_frame_0[1] = (GeneralCoordinatesDoubleDot_idx_1 - obj->R *
    muDoubleScalarCos(*u9) * (*u6 * *u6)) - obj->R * muDoubleScalarSin(*u9) *
    ForceEvaluation;
  GeneralCoordinatesDoubleDot[0] = GeneralCoordinatesDoubleDot_idx_0;
  GeneralCoordinatesDoubleDot[1] = GeneralCoordinatesDoubleDot_idx_1;
  b_GeneralCoordinatesDoubleDot[0] = ForceEvaluation;
  b_GeneralCoordinatesDoubleDot[1] = 0.0;
  for (k = 0; k < 2; k++) {
    c_GeneralCoordinatesDoubleDot[k] = GeneralCoordinatesDoubleDot[k];
    c_GeneralCoordinatesDoubleDot[2 + k] = Acceleration_o_P3_frame_0[k];
    c_GeneralCoordinatesDoubleDot[4 + k] = b_GeneralCoordinatesDoubleDot[k];
  }

  for (k = 0; k < 3; k++) {
    (*b_y0)[k] = c_GeneralCoordinatesDoubleDot[iv10[k]];
  }

  for (k = 0; k < 2; k++) {
    (*b_y0)[k + 3] = Positions[2 + k];
  }

  (*b_y0)[5] = obj->R;
  (*b_y0)[6] = obj->Urk;
  (*b_y0)[7] = obj->T_k;
}

static void cgxe_mdl_update(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance)
{
  real_T a;
  int32_T i3;
  Cylinder *obj;
  static char_T cv9[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv11[2] = { 1, 45 };

  const mxArray *m3;
  static char_T cv10[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv12[2] = { 1, 8 };

  boolean_T flag;
  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv13[2] = { 1, 45 };

  static char_T cv11[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  char_T d_u[7];
  const mxArray *d_y;
  static const int32_T iv14[2] = { 1, 7 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
  real_T *Urs;
  real_T *Urk;
  real_T *Iz;
  real_T *F_s_x;
  real_T *F_s_y;
  real_T *F_k_x;
  real_T *F_k_y;
  real_T *T_s;
  real_T *T_k;
  real_T (*Position_G3_P3_frame_cylinder)[2];
  real_T (*Position_o_G3)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])(ssGetRunTimeParamInfo
    (moduleInstance->S, 15U))->data;
  Position_o_G3 = (real_T (*)[2])(ssGetRunTimeParamInfo(moduleInstance->S, 14U)
    )->data;
  T_k = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 13U))->data;
  T_s = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 12U))->data;
  F_k_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  F_k_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  F_s_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  F_s_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  Iz = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  Urk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  Urs = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  Uk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  Us = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  g = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  M = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  R = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  if (!moduleInstance->sysobj_not_empty) {
    covrtLogFcn(&moduleInstance->covInst, 0, 0);
    covrtLogBasicBlock(&moduleInstance->covInst, 0, 0);
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj.R = 0.02;
    moduleInstance->sysobj.M = 0.003;
    moduleInstance->sysobj.g = 9.81;
    moduleInstance->sysobj.Us = 0.5;
    moduleInstance->sysobj.Uk = 0.48;
    moduleInstance->sysobj.Urs = 0.5;
    moduleInstance->sysobj.Urk = 0.48;
    a = moduleInstance->sysobj.R;
    a = moduleInstance->sysobj.M * (a * a);
    moduleInstance->sysobj.Iz = a / 2.0;
    moduleInstance->sysobj.F_s_x = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Us;
    moduleInstance->sysobj.F_s_y = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Us;
    moduleInstance->sysobj.F_k_x = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Uk;
    moduleInstance->sysobj.F_k_y = moduleInstance->sysobj.M *
      moduleInstance->sysobj.g * moduleInstance->sysobj.Uk;
    moduleInstance->sysobj.T_s = 0.66666666666666663 *
      moduleInstance->sysobj.Urs * moduleInstance->sysobj.R *
      moduleInstance->sysobj.M * moduleInstance->sysobj.g;
    moduleInstance->sysobj.T_k = 0.66666666666666663 *
      moduleInstance->sysobj.Urk * moduleInstance->sysobj.R *
      moduleInstance->sysobj.M * moduleInstance->sysobj.g;
    for (i3 = 0; i3 < 2; i3++) {
      moduleInstance->sysobj.Position_o_G3[i3] = 0.0;
    }

    moduleInstance->sysobj.Position_G3_P3_frame_cylinder[0] = 0.0;
    moduleInstance->sysobj.Position_G3_P3_frame_cylinder[1] =
      moduleInstance->sysobj.R;
    moduleInstance->sysobj_not_empty = true;
    moduleInstance->sysobj.R = *R;
    moduleInstance->sysobj.M = *M;
    moduleInstance->sysobj.g = *g;
    moduleInstance->sysobj.Us = *Us;
    moduleInstance->sysobj.Uk = *Uk;
    moduleInstance->sysobj.Urs = *Urs;
    moduleInstance->sysobj.Urk = *Urk;
    moduleInstance->sysobj.Iz = *Iz;
    moduleInstance->sysobj.F_s_x = *F_s_x;
    moduleInstance->sysobj.F_s_y = *F_s_y;
    moduleInstance->sysobj.F_k_x = *F_k_x;
    moduleInstance->sysobj.F_k_y = *F_k_y;
    moduleInstance->sysobj.T_s = *T_s;
    moduleInstance->sysobj.T_k = *T_k;
    for (i3 = 0; i3 < 2; i3++) {
      moduleInstance->sysobj.Position_o_G3[i3] = (*Position_o_G3)[i3];
    }

    for (i3 = 0; i3 < 2; i3++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i3] =
        (*Position_G3_P3_frame_cylinder)[i3];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i3 = 0; i3 < 45; i3++) {
      u[i3] = cv9[i3];
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv11);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m3, &u[0]);
    emlrtAssign(&y, m3);
    for (i3 = 0; i3 < 8; i3++) {
      b_u[i3] = cv10[i3];
    }

    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv12);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m3, &b_u[0]);
    emlrtAssign(&b_y, m3);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i3 = 0; i3 < 45; i3++) {
        c_u[i3] = cv9[i3];
      }

      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv13);
      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m3, &c_u[0]);
      emlrtAssign(&c_y, m3);
      for (i3 = 0; i3 < 7; i3++) {
        d_u[i3] = cv11[i3];
      }

      d_y = NULL;
      m3 = emlrtCreateCharArray(2, iv14);
      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 7, m3, &d_u[0]);
      emlrtAssign(&d_y, m3);
      error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
    }

    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* Free instance data */
  covrtFreeInstanceData(&moduleInstance->covInst);
}

static const mxArray *mw__internal__name__resolution__fcn(void)
{
  const mxArray *nameCaptureInfo;
  nameCaptureInfo = NULL;
  emlrtAssign(&nameCaptureInfo, emlrtCreateStructMatrix(89, 1, 0, NULL));
  info_helper(&nameCaptureInfo);
  b_info_helper(&nameCaptureInfo);
  emlrtNameCapturePostProcessR2013b(&nameCaptureInfo);
  return nameCaptureInfo;
}

static void info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 0);
  emlrtAddField(*info, emlrt_marshallOut("repmat"), "name", 0);
  emlrtAddField(*info, emlrt_marshallOut("struct"), "dominantType", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "resolved", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(1408795310U), "fileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 1);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.narginchk"), "name", 1);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                "resolved", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(1363736158U), "fileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                "context", 2);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 2);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(1363735454U), "fileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context", 3);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 3);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context", 4);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_floor"), "name", 4);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                "resolved", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(1286843926U), "fileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 5);
  emlrtAddField(*info, emlrt_marshallOut("eml_assert_valid_size_arg"), "name", 5);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "resolved", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(1368208230U), "fileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 6);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 6);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                "context", 7);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 7);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(1363735456U), "fileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context", 8);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 8);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 9);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_integer_class"), "name", 9);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                "resolved", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(1286843982U), "fileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 10);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 10);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context", 11);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 11);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 12);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 12);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context", 13);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 13);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 14);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexIntRelop"), "name",
                14);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                "resolved", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749922U), "fileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                "context", 15);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 15);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                "context", 16);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 16);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                "context", 17);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 17);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 18);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 18);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 19);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 19);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 20);
  emlrtAddField(*info, emlrt_marshallOut("max"), "name", 20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(1311280516U), "fileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context", 21);
  emlrtAddField(*info, emlrt_marshallOut("eml_min_or_max"), "name", 21);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                "resolved", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(1378321184U), "fileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 22);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                22);
  emlrtAddField(*info, b_emlrt_marshallOut(1376005888U), "fileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                23);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 23);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973028U), "fileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 24);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 24);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(1376005888U), "fileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973028U), "fileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "context", 26);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAllocNoCheck"),
                "name", 26);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAllocNoCheck.p"),
                "resolved", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973028U), "fileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 27);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 27);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 28);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 28);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                28);
  emlrtAddField(*info, b_emlrt_marshallOut(1376005888U), "fileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 29);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 29);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 30);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 30);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(1400545980U), "fileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 31);
  emlrtAddField(*info, emlrt_marshallOut("isfi"), "name", 31);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(1346535558U), "fileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context", 32);
  emlrtAddField(*info, emlrt_marshallOut("isnumerictype"), "name", 32);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                32);
  emlrtAddField(*info, b_emlrt_marshallOut(1398900798U), "fileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 33);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 33);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 34);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 34);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 35);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 35);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 35);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973030U), "fileTimeLo", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 35);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 36);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 36);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 36);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973030U), "fileTimeLo", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 36);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 37);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 37);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 37);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(1419971910U), "fileTimeLo", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 37);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 38);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 38);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 38);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973030U), "fileTimeLo", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 38);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 39);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 39);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 39);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(1419971910U), "fileTimeLo", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 39);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 40);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.System"), "name",
                40);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 40);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "resolved", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(1419971910U), "fileTimeLo", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 40);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 41);
  emlrtAddField(*info, emlrt_marshallOut("Cylinder"), "name", 41);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 41);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "resolved", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(1459930192U), "fileTimeLo", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 41);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 42);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 42);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 42);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(1419971910U), "fileTimeLo", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 42);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 43);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 43);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 43);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(1419971910U), "fileTimeLo", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 43);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 44);
  emlrtAddField(*info, emlrt_marshallOut("mpower"), "name", 44);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 44);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(1409883134U), "fileTimeLo", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 44);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 45);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 45);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 45);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 45);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 46);
  emlrtAddField(*info, emlrt_marshallOut("ismatrix"), "name", 46);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 46);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                46);
  emlrtAddField(*info, b_emlrt_marshallOut(1331326458U), "fileTimeLo", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 46);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 47);
  emlrtAddField(*info, emlrt_marshallOut("power"), "name", 47);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 47);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(1395350106U), "fileTimeLo", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 47);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context", 48);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 48);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 48);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 48);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                49);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 49);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 49);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                49);
  emlrtAddField(*info, b_emlrt_marshallOut(1376005888U), "fileTimeLo", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 49);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                50);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 50);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 50);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973028U), "fileTimeLo", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 50);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                51);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 51);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 51);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(1376005888U), "fileTimeLo", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 51);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 52);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                52);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 52);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973028U), "fileTimeLo", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 52);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "context", 53);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAllocNoCheck"),
                "name", 53);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 53);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAllocNoCheck.p"),
                "resolved", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973028U), "fileTimeLo", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 53);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                54);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 54);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 54);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(1363735454U), "fileTimeLo", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 54);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                "context", 55);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 55);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 55);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                55);
  emlrtAddField(*info, b_emlrt_marshallOut(1376005888U), "fileTimeLo", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 55);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 56);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 56);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 56);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973000U), "fileTimeLo", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(1370035086U), "mFileTimeLo", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 56);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context", 57);
  emlrtAddField(*info, emlrt_marshallOut("rdivide"), "name", 57);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 57);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(1363735480U), "fileTimeLo", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 57);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 58);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 58);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 58);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 58);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 59);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_compatible"), "name", 59);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 59);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                "resolved", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(1286843996U), "fileTimeLo", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 59);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 60);
  emlrtAddField(*info, emlrt_marshallOut("eml_div"), "name", 60);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 60);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(1386445552U), "fileTimeLo", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 60);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context", 61);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.div"), "name", 61);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 61);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                61);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973028U), "fileTimeLo", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 61);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 62);
  emlrtAddField(*info, emlrt_marshallOut("isequal"), "name", 62);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 62);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(1286843958U), "fileTimeLo", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 62);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context", 63);
  emlrtAddField(*info, emlrt_marshallOut("eml_isequal_core"), "name", 63);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 63);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                "resolved", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(1408625922U), "fileTimeLo", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 63);
}

static const mxArray *emlrt_marshallOut(const char * u)
{
  const mxArray *y;
  const mxArray *m4;
  y = NULL;
  m4 = emlrtCreateString(u);
  emlrtAssign(&y, m4);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const uint32_T u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)mxGetData(m5) = u;
  emlrtAssign(&y, m5);
  return y;
}

static void b_info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                "context", 64);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.narginchk"), "name", 64);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 64);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                "resolved", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(1363736158U), "fileTimeLo", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 64);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                "context", 65);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 65);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 65);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(1363735458U), "fileTimeLo", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 65);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context", 66);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 66);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 66);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 66);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 67);
  emlrtAddField(*info, emlrt_marshallOut("sign"), "name", 67);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 67);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(1363735456U), "fileTimeLo", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 67);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context", 68);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 68);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 68);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 68);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context", 69);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sign"), "name", 69);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 69);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                "resolved", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(1356563094U), "fileTimeLo", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 69);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 70);
  emlrtAddField(*info, emlrt_marshallOut("eml_mtimes_helper"), "name", 70);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 70);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "resolved", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(1383898894U), "fileTimeLo", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 70);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                "context", 71);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 71);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 71);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 71);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 72);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 72);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 72);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(1363735452U), "fileTimeLo", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 72);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 73);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 73);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 73);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(1395953456U), "fileTimeLo", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 73);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 74);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_abs"), "name", 74);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 74);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                "resolved", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(1286843912U), "fileTimeLo", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 74);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 75);
  emlrtAddField(*info, emlrt_marshallOut("cos"), "name", 75);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 75);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(1395350096U), "fileTimeLo", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 75);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context", 76);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_cos"), "name", 76);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 76);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                "resolved", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(1286843922U), "fileTimeLo", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 76);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Jhon/UNIMELB/cursos/Directed studies/GithubDirected/Simulation/Classes/Cylinder.m"),
                "context", 77);
  emlrtAddField(*info, emlrt_marshallOut("sin"), "name", 77);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 77);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(1395350104U), "fileTimeLo", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 77);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context", 78);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sin"), "name", 78);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 78);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                "resolved", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(1286843936U), "fileTimeLo", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 78);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "context", 79);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 79);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 79);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 79);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "context", 80);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 80);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 80);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                80);
  emlrtAddField(*info, b_emlrt_marshallOut(1376005888U), "fileTimeLo", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 80);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "context", 81);
  emlrtAddField(*info, emlrt_marshallOut("eml_xgemm"), "name", 81);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 81);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                "resolved", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(1376005890U), "fileTimeLo", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 81);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                82);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.inline"), "name",
                82);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 82);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                "resolved", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973030U), "fileTimeLo", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 82);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                83);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.xgemm"), "name",
                83);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 83);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                "resolved", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973030U), "fileTimeLo", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 83);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                "context", 84);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.use_refblas"),
                "name", 84);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 84);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                "resolved", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973030U), "fileTimeLo", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 84);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                "context", 85);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.threshold"),
                "name", 85);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 85);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "resolved", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973030U), "fileTimeLo", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 85);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "context", 86);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 86);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 86);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 86);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                "context", 87);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 87);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 87);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973028U), "fileTimeLo", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 87);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                "context", 88);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.refblas.xgemm"), "name",
                88);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 88);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                "resolved", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(1419973030U), "fileTimeLo", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 88);
}

static const mxArray *mw__internal__autoInference__fcn(void)
{
  const mxArray *infoCache;
  int8_T Ports_dims_data[4];
  int32_T i4;
  static int8_T iv15[4] = { 8, 2, 1, 8 };

  uint32_T RestoreInfo_cgxeChksum[4];
  uint32_T info_VerificationInfo_dlgPrmChksum_chksum[4];
  static uint32_T uv0[4] = { 106978902U, 377345797U, 3171370533U, 4112056921U };

  static uint32_T t0_dlgPrmChksum_chksum[4] = { 4119393617U, 1661565817U,
    4163944417U, 1726356677U };

  s7UBIGHSehQY1gCsIQWwr5C info_VerificationInfo_propChksum[3];
  static s7UBIGHSehQY1gCsIQWwr5C b_t0_propChksum[3] = { { { 5.80329916E+8,
        3.311835659E+9, 1.200678795E+9, 2.69024578E+8 } }, { { 1.30480059E+8,
        3.265749625E+9, 3.520795777E+9, 3.444041995E+9 } }, { { 3.912780797E+9,
        4.8271938E+7, 2.633218385E+9, 2.74198087E+8 } } };

  uint32_T b_t0_dlgPrmChksum_chksum[4];
  uint32_T info_VerificationInfo_postPropOnlyChksum_chksum[4];
  static uint32_T t0_CGOnlyParamChksum_chksum[4] = { 907274058U, 3220786148U,
    779473529U, 2769831971U };

  static uint32_T t0_postPropOnlyChksum_chksum[4] = { 2911221907U, 2308967934U,
    2419390157U, 1906300239U };

  char_T info_slVer[3];
  static char_T cv12[3] = { '8', '.', '5' };

  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m6;
  int32_T u_sizes[2];
  int8_T u_data[4];
  const mxArray *f_y;
  real_T *pData;
  int32_T i;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  int32_T iv16[2];
  const mxArray *k_y;
  static const int32_T iv17[2] = { 1, 0 };

  const mxArray *l_y;
  const mxArray *m_y;
  const mxArray *n_y;
  static const int32_T iv18[2] = { 1, 0 };

  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  int32_T b_u_sizes[2];
  const mxArray *t_y;
  const mxArray *u_y;
  const mxArray *v_y;
  static const int32_T iv19[2] = { 1, 4 };

  const mxArray *w_y;
  const mxArray *x_y;
  const mxArray *y_y;
  static const int32_T iv20[2] = { 1, 4 };

  s7UBIGHSehQY1gCsIQWwr5C u[3];
  const mxArray *ab_y;
  const s7UBIGHSehQY1gCsIQWwr5C *r0;
  real_T b_u[4];
  const mxArray *bb_y;
  static const int32_T iv21[2] = { 1, 4 };

  const mxArray *cb_y;
  const mxArray *db_y;
  static const int32_T iv22[2] = { 1, 4 };

  const mxArray *eb_y;
  const mxArray *fb_y;
  static const int32_T iv23[2] = { 1, 4 };

  char_T c_u[3];
  const mxArray *gb_y;
  static const int32_T iv24[2] = { 1, 3 };

  infoCache = NULL;
  for (i4 = 0; i4 < 4; i4++) {
    Ports_dims_data[i4] = iv15[i4];
  }

  for (i4 = 0; i4 < 4; i4++) {
    RestoreInfo_cgxeChksum[i4] = uv0[i4];
    info_VerificationInfo_dlgPrmChksum_chksum[i4] = t0_dlgPrmChksum_chksum[i4];
  }

  for (i4 = 0; i4 < 3; i4++) {
    info_VerificationInfo_propChksum[i4] = b_t0_propChksum[i4];
  }

  for (i4 = 0; i4 < 4; i4++) {
    b_t0_dlgPrmChksum_chksum[i4] = t0_CGOnlyParamChksum_chksum[i4];
    info_VerificationInfo_postPropOnlyChksum_chksum[i4] =
      t0_postPropOnlyChksum_chksum[i4];
  }

  for (i4 = 0; i4 < 3; i4++) {
    info_slVer[i4] = cv12[i4];
  }

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  d_y = NULL;
  emlrtAssign(&d_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  e_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&e_y, m6);
  emlrtAddField(d_y, e_y, "dimModes", 0);
  u_sizes[0] = 1;
  u_sizes[1] = 4;
  for (i4 = 0; i4 < 4; i4++) {
    u_data[i4] = Ports_dims_data[i4];
  }

  f_y = NULL;
  m6 = emlrtCreateNumericArray(2, u_sizes, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  i4 = 0;
  for (i = 0; i < u_sizes[1]; i++) {
    pData[i4] = (real_T)u_data[u_sizes[0] * i];
    i4++;
  }

  emlrtAssign(&f_y, m6);
  emlrtAddField(d_y, f_y, "dims", 0);
  g_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&g_y, m6);
  emlrtAddField(d_y, g_y, "dType", 0);
  h_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&h_y, m6);
  emlrtAddField(d_y, h_y, "complexity", 0);
  i_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&i_y, m6);
  emlrtAddField(d_y, i_y, "outputBuiltInDTEqUsed", 0);
  emlrtAddField(c_y, d_y, "Ports", 0);
  j_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv16[i4] = 1 - i4;
  }

  emlrtAssign(&j_y, emlrtCreateStructArray(2, iv16, 0, NULL));
  emlrtAddField(j_y, NULL, "names", 0);
  emlrtAddField(j_y, NULL, "dims", 0);
  emlrtAddField(j_y, NULL, "dType", 0);
  emlrtAddField(j_y, NULL, "complexity", 0);
  emlrtAddField(c_y, j_y, "dWork", 0);
  k_y = NULL;
  m6 = emlrtCreateCharArray(2, iv17);
  emlrtAssign(&k_y, m6);
  emlrtAddField(c_y, k_y, "objTypeName", 0);
  l_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&l_y, m6);
  emlrtAddField(c_y, l_y, "objTypeSize", 0);
  m_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv16[i4] = 1 - i4;
  }

  emlrtAssign(&m_y, emlrtCreateStructArray(2, iv16, 0, NULL));
  emlrtAddField(m_y, NULL, "names", 0);
  emlrtAddField(m_y, NULL, "dims", 0);
  emlrtAddField(m_y, NULL, "dType", 0);
  emlrtAddField(m_y, NULL, "dTypeSize", 0);
  emlrtAddField(m_y, NULL, "dTypeName", 0);
  emlrtAddField(m_y, NULL, "dTypeIndex", 0);
  emlrtAddField(m_y, NULL, "dTypeChksum", 0);
  emlrtAddField(m_y, NULL, "complexity", 0);
  emlrtAddField(c_y, m_y, "persisVarDWork", 0);
  n_y = NULL;
  m6 = emlrtCreateCharArray(2, iv18);
  emlrtAssign(&n_y, m6);
  emlrtAddField(c_y, n_y, "sysObjChksum", 0);
  o_y = NULL;
  emlrtAssign(&o_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  p_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv16[i4] = 1 - i4;
  }

  emlrtAssign(&p_y, emlrtCreateStructArray(2, iv16, 0, NULL));
  emlrtAddField(p_y, NULL, "Index", 0);
  emlrtAddField(p_y, NULL, "DataType", 0);
  emlrtAddField(p_y, NULL, "IsSigned", 0);
  emlrtAddField(p_y, NULL, "MantBits", 0);
  emlrtAddField(p_y, NULL, "FixExp", 0);
  emlrtAddField(p_y, NULL, "Slope", 0);
  emlrtAddField(p_y, NULL, "Bias", 0);
  emlrtAddField(o_y, p_y, "Out", 0);
  q_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv16[i4] = 1 - i4;
  }

  emlrtAssign(&q_y, emlrtCreateStructArray(2, iv16, 0, NULL));
  emlrtAddField(q_y, NULL, "Index", 0);
  emlrtAddField(q_y, NULL, "DataType", 0);
  emlrtAddField(q_y, NULL, "IsSigned", 0);
  emlrtAddField(q_y, NULL, "MantBits", 0);
  emlrtAddField(q_y, NULL, "FixExp", 0);
  emlrtAddField(q_y, NULL, "Slope", 0);
  emlrtAddField(q_y, NULL, "Bias", 0);
  emlrtAddField(o_y, q_y, "DW", 0);
  r_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv16[i4] = 1 - i4;
  }

  emlrtAssign(&r_y, emlrtCreateStructArray(2, iv16, 0, NULL));
  emlrtAddField(r_y, NULL, "Index", 0);
  emlrtAddField(r_y, NULL, "DataType", 0);
  emlrtAddField(r_y, NULL, "IsSigned", 0);
  emlrtAddField(r_y, NULL, "MantBits", 0);
  emlrtAddField(r_y, NULL, "FixExp", 0);
  emlrtAddField(r_y, NULL, "Slope", 0);
  emlrtAddField(r_y, NULL, "Bias", 0);
  emlrtAddField(o_y, r_y, "PersisDW", 0);
  emlrtAddField(c_y, o_y, "mapsInfo", 0);
  s_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&s_y, m6);
  emlrtAddField(c_y, s_y, "objDWorkTypeNameIndex", 0);
  b_u_sizes[0] = 1;
  b_u_sizes[1] = 10;
  t_y = NULL;
  m6 = emlrtCreateNumericArray(2, b_u_sizes, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  i4 = 0;
  for (i = 0; i < 10; i++) {
    pData[i4] = 0.0;
    i4++;
  }

  emlrtAssign(&t_y, m6);
  emlrtAddField(c_y, t_y, "inputDFFlagsIndexField", 0);
  u_y = NULL;
  m6 = emlrtCreateDoubleScalar(0.0);
  emlrtAssign(&u_y, m6);
  emlrtAddField(c_y, u_y, "postPropRun", 0);
  emlrtAddField(b_y, c_y, "DispatcherInfo", 0);
  v_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv19, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)RestoreInfo_cgxeChksum[i];
  }

  emlrtAssign(&v_y, m6);
  emlrtAddField(b_y, v_y, "cgxeChksum", 0);
  emlrtAddField(y, b_y, "RestoreInfo", 0);
  w_y = NULL;
  emlrtAssign(&w_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  x_y = NULL;
  emlrtAssign(&x_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  y_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv20, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)info_VerificationInfo_dlgPrmChksum_chksum[i];
  }

  emlrtAssign(&y_y, m6);
  emlrtAddField(x_y, y_y, "chksum", 0);
  emlrtAddField(w_y, x_y, "dlgPrmChksum", 0);
  for (i4 = 0; i4 < 3; i4++) {
    u[i4] = info_VerificationInfo_propChksum[i4];
  }

  ab_y = NULL;
  for (i4 = 0; i4 < 2; i4++) {
    iv16[i4] = 1 + (i4 << 1);
  }

  emlrtAssign(&ab_y, emlrtCreateStructArray(2, iv16, 0, NULL));
  for (i4 = 0; i4 < 3; i4++) {
    r0 = &u[i4];
    for (i = 0; i < 4; i++) {
      b_u[i] = r0->chksum[i];
    }

    bb_y = NULL;
    m6 = emlrtCreateNumericArray(2, iv21, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T *)mxGetPr(m6);
    for (i = 0; i < 4; i++) {
      pData[i] = b_u[i];
    }

    emlrtAssign(&bb_y, m6);
    emlrtAddField(ab_y, bb_y, "chksum", i4);
  }

  emlrtAddField(w_y, ab_y, "propChksum", 0);
  cb_y = NULL;
  emlrtAssign(&cb_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  db_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv22, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)b_t0_dlgPrmChksum_chksum[i];
  }

  emlrtAssign(&db_y, m6);
  emlrtAddField(cb_y, db_y, "chksum", 0);
  emlrtAddField(w_y, cb_y, "CGOnlyParamChksum", 0);
  eb_y = NULL;
  emlrtAssign(&eb_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  fb_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv23, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)info_VerificationInfo_postPropOnlyChksum_chksum[i];
  }

  emlrtAssign(&fb_y, m6);
  emlrtAddField(eb_y, fb_y, "chksum", 0);
  emlrtAddField(w_y, eb_y, "postPropOnlyChksum", 0);
  emlrtAddField(y, w_y, "VerificationInfo", 0);
  for (i4 = 0; i4 < 3; i4++) {
    c_u[i4] = info_slVer[i4];
  }

  gb_y = NULL;
  m6 = emlrtCreateCharArray(2, iv24);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 3, m6, &c_u[0]);
  emlrtAssign(&gb_y, m6);
  emlrtAddField(y, gb_y, "slVer", 0);
  emlrtAssign(&infoCache, y);
  return infoCache;
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance)
{
  const mxArray *st;
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m7;
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
  static const int32_T iv25[1] = { 2 };

  real_T *pData;
  int32_T i;
  const mxArray *s_y;
  static const int32_T iv26[1] = { 2 };

  const mxArray *t_y;
  st = NULL;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  m7 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m7) = moduleInstance->sysobj.isInitialized;
  emlrtAssign(&c_y, m7);
  emlrtAddField(b_y, c_y, "isInitialized", 0);
  d_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.R);
  emlrtAssign(&d_y, m7);
  emlrtAddField(b_y, d_y, "R", 0);
  e_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.M);
  emlrtAssign(&e_y, m7);
  emlrtAddField(b_y, e_y, "M", 0);
  f_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.g);
  emlrtAssign(&f_y, m7);
  emlrtAddField(b_y, f_y, "g", 0);
  g_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Us);
  emlrtAssign(&g_y, m7);
  emlrtAddField(b_y, g_y, "Us", 0);
  h_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Uk);
  emlrtAssign(&h_y, m7);
  emlrtAddField(b_y, h_y, "Uk", 0);
  i_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Urs);
  emlrtAssign(&i_y, m7);
  emlrtAddField(b_y, i_y, "Urs", 0);
  j_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Urk);
  emlrtAssign(&j_y, m7);
  emlrtAddField(b_y, j_y, "Urk", 0);
  k_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Iz);
  emlrtAssign(&k_y, m7);
  emlrtAddField(b_y, k_y, "Iz", 0);
  l_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_s_x);
  emlrtAssign(&l_y, m7);
  emlrtAddField(b_y, l_y, "F_s_x", 0);
  m_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_s_y);
  emlrtAssign(&m_y, m7);
  emlrtAddField(b_y, m_y, "F_s_y", 0);
  n_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_k_x);
  emlrtAssign(&n_y, m7);
  emlrtAddField(b_y, n_y, "F_k_x", 0);
  o_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_k_y);
  emlrtAssign(&o_y, m7);
  emlrtAddField(b_y, o_y, "F_k_y", 0);
  p_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.T_s);
  emlrtAssign(&p_y, m7);
  emlrtAddField(b_y, p_y, "T_s", 0);
  q_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.T_k);
  emlrtAssign(&q_y, m7);
  emlrtAddField(b_y, q_y, "T_k", 0);
  r_y = NULL;
  m7 = emlrtCreateNumericArray(1, iv25, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m7);
  for (i = 0; i < 2; i++) {
    pData[i] = moduleInstance->sysobj.Position_o_G3[i];
  }

  emlrtAssign(&r_y, m7);
  emlrtAddField(b_y, r_y, "Position_o_G3", 0);
  s_y = NULL;
  m7 = emlrtCreateNumericArray(1, iv26, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m7);
  for (i = 0; i < 2; i++) {
    pData[i] = moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i];
  }

  emlrtAssign(&s_y, m7);
  emlrtAddField(b_y, s_y, "Position_G3_P3_frame_cylinder", 0);
  emlrtSetCell(y, 0, b_y);
  t_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&t_y, m7);
  emlrtSetCell(y, 1, t_y);
  emlrtAssign(&st, y);
  return st;
}

static void emlrt_marshallIn(const mxArray *b_sysobj, const char_T *identifier,
  Cylinder *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(emlrtAlias(b_sysobj), &thisId, y);
  emlrtDestroyArray(&b_sysobj);
}

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, Cylinder *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[17] = { "isInitialized", "R", "M", "g", "Us",
    "Uk", "Urs", "Urk", "Iz", "F_s_x", "F_s_y", "F_k_x", "F_k_y", "T_s", "T_k",
    "Position_o_G3", "Position_G3_P3_frame_cylinder" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 17, fieldNames, 0U, 0);
  thisId.fIdentifier = "isInitialized";
  y->isInitialized = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isInitialized")), &thisId);
  thisId.fIdentifier = "R";
  y->R = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u,
    0, "R")), &thisId);
  thisId.fIdentifier = "M";
  y->M = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u,
    0, "M")), &thisId);
  thisId.fIdentifier = "g";
  y->g = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u,
    0, "g")), &thisId);
  thisId.fIdentifier = "Us";
  y->Us = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "Us")), &thisId);
  thisId.fIdentifier = "Uk";
  y->Uk = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "Uk")), &thisId);
  thisId.fIdentifier = "Urs";
  y->Urs = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "Urs")), &thisId);
  thisId.fIdentifier = "Urk";
  y->Urk = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "Urk")), &thisId);
  thisId.fIdentifier = "Iz";
  y->Iz = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "Iz")), &thisId);
  thisId.fIdentifier = "F_s_x";
  y->F_s_x = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "F_s_x")), &thisId);
  thisId.fIdentifier = "F_s_y";
  y->F_s_y = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "F_s_y")), &thisId);
  thisId.fIdentifier = "F_k_x";
  y->F_k_x = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "F_k_x")), &thisId);
  thisId.fIdentifier = "F_k_y";
  y->F_k_y = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "F_k_y")), &thisId);
  thisId.fIdentifier = "T_s";
  y->T_s = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "T_s")), &thisId);
  thisId.fIdentifier = "T_k";
  y->T_k = d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "T_k")), &thisId);
  thisId.fIdentifier = "Position_o_G3";
  e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "Position_o_G3")), &thisId, y->Position_o_G3);
  thisId.fIdentifier = "Position_G3_P3_frame_cylinder";
  e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "Position_G3_P3_frame_cylinder")), &thisId, y->Position_G3_P3_frame_cylinder);
  emlrtDestroyArray(&u);
}

static int32_T c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  int32_T y;
  y = h_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[2])
{
  j_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T f_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = g_emlrt_marshallIn(emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static boolean_T g_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  boolean_T y;
  y = k_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC
  *moduleInstance, const mxArray *st)
{
  const mxArray *u;
  u = emlrtAlias(st);
  emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, "sysobj", u, 0)),
                   "sysobj", &moduleInstance->sysobj);
  moduleInstance->sysobj_not_empty = f_emlrt_marshallIn(emlrtAlias(emlrtGetCell
    (emlrtRootTLSGlobal, "sysobj_not_empty", u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location)
{
  const mxArray *pArrays[2];
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m8, 2, pArrays, "message",
    true, location);
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", true,
                        location);
}

static int32_T h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  int32_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "int32", false, 0U, 0);
  ret = *(int32_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void j_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[2])
{
  int32_T iv27[1];
  int32_T i5;
  iv27[0] = 2;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
    iv27);
  for (i5 = 0; i5 < 2; i5++) {
    ret[i5] = (*(real_T (*)[2])mxGetData(src))[i5];
  }

  emlrtDestroyArray(&src);
}

static boolean_T k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  boolean_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "logical", false, 0U,
    0);
  ret = *mxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

/* CGXE Glue Code */
static void mdlOutputs_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S, int_T tid)
{
  InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance;
  moduleInstance = (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_outputs(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlInitialize_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S)
{
  InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance;
  moduleInstance = (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_initialize(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlUpdate_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S, int_T tid)
{
  InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance;
  moduleInstance = (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_update(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static mxArray* getSimState_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S)
{
  InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance;
  mxArray* mxSS;
  moduleInstance = (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
  return mxSS;
}

static void setSimState_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance;
  moduleInstance = (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
  CGXERT_LEAVE_CHECK();
}

static void mdlTerminate_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S)
{
  InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance;
  moduleInstance = (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_terminate(moduleInstance);
  CGXERT_LEAVE_CHECK();
  free((void *)moduleInstance);
  ssSetUserData(S, NULL);
}

static void mdlStart_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S)
{
  InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *moduleInstance;
  moduleInstance = (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC *)calloc(1, sizeof
    (InstanceStruct_eJG1O6WbMNFUvHWZ3mwzSC));
  moduleInstance->S = S;
  ssSetUserData(S, (void *)moduleInstance);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_start(moduleInstance);
  CGXERT_LEAVE_CHECK();

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }

  ssSetmdlOutputs(S, mdlOutputs_eJG1O6WbMNFUvHWZ3mwzSC);
  ssSetmdlInitializeConditions(S, mdlInitialize_eJG1O6WbMNFUvHWZ3mwzSC);
  ssSetmdlUpdate(S, mdlUpdate_eJG1O6WbMNFUvHWZ3mwzSC);
  ssSetmdlTerminate(S, mdlTerminate_eJG1O6WbMNFUvHWZ3mwzSC);
}

static void mdlProcessParameters_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S)
{
}

void method_dispatcher_eJG1O6WbMNFUvHWZ3mwzSC(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_eJG1O6WbMNFUvHWZ3mwzSC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_eJG1O6WbMNFUvHWZ3mwzSC(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_eJG1O6WbMNFUvHWZ3mwzSC(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_eJG1O6WbMNFUvHWZ3mwzSC(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: eJG1O6WbMNFUvHWZ3mwzSC.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

int autoInfer_dispatcher_eJG1O6WbMNFUvHWZ3mwzSC(mxArray* plhs[], const char
  * commandName)
{
  if (strcmp(commandName, "NameResolution") == 0) {
    plhs[0] = (mxArray*) mw__internal__name__resolution__fcn();
    return 1;
  }

  if (strcmp(commandName, "AutoInfer") == 0) {
    plhs[0] = (mxArray*) mw__internal__autoInference__fcn();
    return 1;
  }

  return 0;
}

mxArray *cgxe_eJG1O6WbMNFUvHWZ3mwzSC_BuildInfoUpdate(void)
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
