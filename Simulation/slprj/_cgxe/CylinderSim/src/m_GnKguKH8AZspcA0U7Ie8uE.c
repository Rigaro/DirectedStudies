/* Include files */

#include "modelInterface.h"
#include "m_GnKguKH8AZspcA0U7Ie8uE.h"
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
static Cylinder *Cylinder_Cylinder(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, Cylinder *obj);
static real_T mpower(real_T a);
static boolean_T isequal(real_T varargin_1, real_T varargin_2);
static boolean_T b_isequal(real_T varargin_1[2], real_T varargin_2[2]);
static void cgxe_mdl_start(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *b_sysobj, const char_T *identifier, Cylinder
  *y);
static void b_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Cylinder *y);
static int32_T c_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static boolean_T d_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static real_T e_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static void f_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2]);
static boolean_T g_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier);
static void mw__internal__setSimState__fcn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *st);
static const mxArray *message(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *b, emlrtMCInfo *location);
static void error(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location);
static const mxArray *b_message(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static int32_T h_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static boolean_T i_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static real_T j_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static void k_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2]);
static void init_simulink_io_address(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance);

/* Function Definitions */
static Cylinder *Cylinder_Cylinder(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, Cylinder *obj)
{
  Cylinder *b_obj;
  Cylinder *c_obj;
  boolean_T flag;
  real_T A;
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

  A = b_obj->M * mpower(b_obj->R);
  b_obj->Iz = A / 2.0;
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

  b_obj->T_s = 0.66666666666666663 * b_obj->Us * b_obj->R * b_obj->M * b_obj->g;
  c_obj = b_obj;
  flag = (c_obj->isInitialized == 1);
  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->T_k = 0.66666666666666663 * b_obj->Uk * b_obj->R * b_obj->M * b_obj->g;
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

static real_T mpower(real_T a)
{
  return a * a;
}

static boolean_T isequal(real_T varargin_1, real_T varargin_2)
{
  boolean_T p;
  boolean_T b_p;
  p = false;
  b_p = true;
  if (!(varargin_1 == varargin_2)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T b_isequal(real_T varargin_1[2], real_T varargin_2[2])
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static void cgxe_mdl_start(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance)
{
  real_T varargin_13[2];
  real_T varargin_14[2];
  int32_T i1;
  boolean_T flag;
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

  static char_T cv2[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T c_u[44];
  const mxArray *c_y;
  static const int32_T iv2[2] = { 1, 44 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
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
    (moduleInstance->S, 13);
  Position_o_G3 = (real_T (*)[2])cgxertGetRunTimeParamInfoData(moduleInstance->S,
    12);
  T_k = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  T_s = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  F_k_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  F_k_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  F_s_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  F_s_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  Iz = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
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
                  0, 7, 17, 6, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(moduleInstance->covInst, 0, 5, "Cylinder_AccCalculation", 5314,
               -1, 5797);
  covrtFcnInit(moduleInstance->covInst, 0, 4, "Cylinder_VelCalculation", 4771,
               -1, 5078);
  covrtFcnInit(moduleInstance->covInst, 0, 3, "Cylinder_PosCalculation", 4165,
               -1, 4538);
  covrtFcnInit(moduleInstance->covInst, 0, 2, "Cylinder_Equation_Of_Motion",
               2857, -1, 3933);
  covrtFcnInit(moduleInstance->covInst, 0, 1, "Cylinder_NonLinearFriction", 1874,
               -1, 2555);
  covrtFcnInit(moduleInstance->covInst, 0, 0, "Cylinder_Cylinder", 1036, -1,
               1605);
  covrtFcnInit(moduleInstance->covInst, 0, 6, "Cylinder_stepImpl", 6134, -1,
               6987);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(moduleInstance->covInst, 0, 15, 5424, -1, 5784);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 14, 4855, -1, 5065);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 13, 4248, -1, 4525);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 12, 3871, -1, 3904);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 11, 3758, -1, 3836);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 10, 3573, -1, 3606);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 9, 3459, -1, 3538);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 8, 3276, -1, 3309);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 7, 3162, -1, 3241);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 6, 2943, -1, 3074);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 5, 2458, -1, 2477);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 4, 2352, -1, 2371);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 3, 2220, -1, 2243);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 2, 2160, -1, 2185);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 1, 2069, -1, 2094);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 0, 1080, -1, 1592);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 16, 6320, -1, 6974);

  /* Initialize If Information */
  covrtIfInit(moduleInstance->covInst, 0, 3, 3088, 3145, 3255, 3326);
  covrtIfInit(moduleInstance->covInst, 0, 4, 3385, 3442, 3552, 3623);
  covrtIfInit(moduleInstance->covInst, 0, 5, 3686, 3741, 3850, 3921);
  covrtIfInit(moduleInstance->covInst, 0, 0, 2020, 2052, 2108, 2260);
  covrtIfInit(moduleInstance->covInst, 0, 1, 2108, 2143, 2199, 2260);
  covrtIfInit(moduleInstance->covInst, 0, 2, 2304, 2335, 2437, 2543);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(moduleInstance->covInst, 0U);
  for (i1 = 0; i1 < 2; i1++) {
    varargin_13[i1] = (*Position_o_G3)[i1];
    varargin_14[i1] = (*Position_G3_P3_frame_cylinder)[i1];
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

    for (i1 = 0; i1 < 2; i1++) {
      moduleInstance->sysobj.Position_o_G3[i1] = varargin_13[i1];
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i1 = 0; i1 < 2; i1++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i1] = varargin_14[i1];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized != 0) {
    for (i1 = 0; i1 < 51; i1++) {
      u[i1] = cv0[i1];
    }

    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m0, &u[0]);
    emlrtAssign(&y, m0);
    for (i1 = 0; i1 < 5; i1++) {
      b_u[i1] = cv1[i1];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m0, &b_u[0]);
    emlrtAssign(&b_y, m0);
    error(moduleInstance, b_message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  obj->isInitialized = 1;
  if (obj->TunablePropsChanged) {
    for (i1 = 0; i1 < 44; i1++) {
      c_u[i1] = cv2[i1];
    }

    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m0, &c_u[0]);
    emlrtAssign(&c_y, m0);
    error(moduleInstance, message(moduleInstance, c_y, &b_emlrtMCI), &b_emlrtMCI);
  }

  obj->TunablePropsChanged = false;
}

static void cgxe_mdl_initialize(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance)
{
  real_T varargin_13[2];
  real_T varargin_14[2];
  int32_T i2;
  boolean_T tunablePropChangedBeforeResetImpl;
  Cylinder *obj;
  static char_T cv3[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv3[2] = { 1, 45 };

  const mxArray *m1;
  static char_T cv4[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv4[2] = { 1, 8 };

  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv5[2] = { 1, 45 };

  static char_T cv5[5] = { 'r', 'e', 's', 'e', 't' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv6[2] = { 1, 5 };

  static char_T cv6[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T e_u[44];
  const mxArray *e_y;
  static const int32_T iv7[2] = { 1, 44 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
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
    (moduleInstance->S, 13);
  Position_o_G3 = (real_T (*)[2])cgxertGetRunTimeParamInfoData(moduleInstance->S,
    12);
  T_k = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  T_s = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  F_k_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  F_k_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  F_s_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  F_s_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  Iz = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  Uk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  Us = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  g = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  M = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  R = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  for (i2 = 0; i2 < 2; i2++) {
    varargin_13[i2] = (*Position_o_G3)[i2];
    varargin_14[i2] = (*Position_G3_P3_frame_cylinder)[i2];
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

    for (i2 = 0; i2 < 2; i2++) {
      moduleInstance->sysobj.Position_o_G3[i2] = varargin_13[i2];
    }

    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i2 = 0; i2 < 2; i2++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i2] = varargin_14[i2];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i2 = 0; i2 < 45; i2++) {
      u[i2] = cv3[i2];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m1, &u[0]);
    emlrtAssign(&y, m1);
    for (i2 = 0; i2 < 8; i2++) {
      b_u[i2] = cv4[i2];
    }

    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv4);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m1, &b_u[0]);
    emlrtAssign(&b_y, m1);
    error(moduleInstance, b_message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  tunablePropChangedBeforeResetImpl = (obj->isInitialized == 1);
  if (tunablePropChangedBeforeResetImpl) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i2 = 0; i2 < 45; i2++) {
        c_u[i2] = cv3[i2];
      }

      c_y = NULL;
      m1 = emlrtCreateCharArray(2, iv5);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m1, &c_u
        [0]);
      emlrtAssign(&c_y, m1);
      for (i2 = 0; i2 < 5; i2++) {
        d_u[i2] = cv5[i2];
      }

      d_y = NULL;
      m1 = emlrtCreateCharArray(2, iv6);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m1, &d_u[0]);
      emlrtAssign(&d_y, m1);
      error(moduleInstance, b_message(moduleInstance, c_y, d_y, &b_emlrtMCI),
            &b_emlrtMCI);
    }

    tunablePropChangedBeforeResetImpl = obj->TunablePropsChanged;
    if ((int32_T)tunablePropChangedBeforeResetImpl != (int32_T)
        obj->TunablePropsChanged) {
      for (i2 = 0; i2 < 44; i2++) {
        e_u[i2] = cv6[i2];
      }

      e_y = NULL;
      m1 = emlrtCreateCharArray(2, iv7);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m1, &e_u
        [0]);
      emlrtAssign(&e_y, m1);
      error(moduleInstance, message(moduleInstance, e_y, &b_emlrtMCI),
            &b_emlrtMCI);
    }
  }
}

static void cgxe_mdl_outputs(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance)
{
  real_T Acceleration_o_P3_frame_0[2];
  real_T varargin_14[2];
  int32_T k;
  boolean_T flag;
  real_T dv0[2];
  Cylinder *obj;
  static char_T cv7[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 45 };

  const mxArray *m2;
  static char_T cv8[4] = { 's', 't', 'e', 'p' };

  char_T b_u[4];
  const mxArray *b_y;
  static const int32_T iv9[2] = { 1, 4 };

  static char_T cv9[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T c_u[51];
  const mxArray *c_y;
  static const int32_T iv10[2] = { 1, 51 };

  static char_T cv10[5] = { 's', 'e', 't', 'u', 'p' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv11[2] = { 1, 5 };

  static char_T cv11[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T e_u[44];
  const mxArray *e_y;
  static const int32_T iv12[2] = { 1, 44 };

  real_T GenCordExt[3];
  real_T SignOposite[3];
  real_T ForceEvaluation;
  real_T B;
  real_T GeneralCoordinatesDoubleDot_idx_0;
  real_T GeneralCoordinatesDoubleDot_idx_1;
  real_T Accelerations[4];
  real_T varargin_22[2];
  real_T Positions[4];
  int32_T i3;
  real_T d0;
  real_T GeneralCoordinatesDoubleDot[2];
  char_T f_u[44];
  const mxArray *f_y;
  static const int32_T iv13[2] = { 1, 44 };

  real_T *T_k;
  real_T *T_s;
  real_T *F_k_y;
  real_T *F_k_x;
  real_T *F_s_y;
  real_T *F_s_x;
  real_T *Iz;
  real_T *Uk;
  real_T *Us;
  real_T *g;
  real_T *M;
  real_T *R;
  real_T (*Position_o_G3)[2];
  real_T (*Position_G3_P3_frame_cylinder)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])cgxertGetRunTimeParamInfoData
    (moduleInstance->S, 13);
  Position_o_G3 = (real_T (*)[2])cgxertGetRunTimeParamInfoData(moduleInstance->S,
    12);
  R = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  M = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  g = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  Us = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  Uk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  Iz = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  F_s_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  F_s_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  F_k_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  F_k_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  T_s = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  T_k = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  for (k = 0; k < 2; k++) {
    Acceleration_o_P3_frame_0[k] = (*Position_o_G3)[k];
    varargin_14[k] = (*Position_G3_P3_frame_cylinder)[k];
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
      moduleInstance->sysobj.Position_o_G3[k] = Acceleration_o_P3_frame_0[k];
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k] = varargin_14[k];
    }
  }

  if (!isequal(moduleInstance->sysobj.R, *R)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
  }

  if (!isequal(moduleInstance->sysobj.M, *M)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
  }

  if (!isequal(moduleInstance->sysobj.g, *g)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
  }

  if (!isequal(moduleInstance->sysobj.Us, *Us)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
  }

  if (!isequal(moduleInstance->sysobj.Uk, *Uk)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
  }

  if (!isequal(moduleInstance->sysobj.Iz, *Iz)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
  }

  if (!isequal(moduleInstance->sysobj.F_s_x, *F_s_x)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
  }

  if (!isequal(moduleInstance->sysobj.F_s_y, *F_s_y)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
  }

  if (!isequal(moduleInstance->sysobj.F_k_x, *F_k_x)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
  }

  if (!isequal(moduleInstance->sysobj.F_k_y, *F_k_y)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
  }

  if (!isequal(moduleInstance->sysobj.T_s, *T_s)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
  }

  if (!isequal(moduleInstance->sysobj.T_k, *T_k)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
  }

  for (k = 0; k < 2; k++) {
    dv0[k] = moduleInstance->sysobj.Position_o_G3[k];
  }

  if (!b_isequal(dv0, Acceleration_o_P3_frame_0)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_o_G3[k] = Acceleration_o_P3_frame_0[k];
    }
  }

  for (k = 0; k < 2; k++) {
    dv0[k] = moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k];
  }

  if (!b_isequal(dv0, varargin_14)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k] = varargin_14[k];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (k = 0; k < 45; k++) {
      u[k] = cv7[k];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv8);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m2, &u[0]);
    emlrtAssign(&y, m2);
    for (k = 0; k < 4; k++) {
      b_u[k] = cv8[k];
    }

    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv9);
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
      m2 = emlrtCreateCharArray(2, iv10);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m2, &c_u
        [0]);
      emlrtAssign(&c_y, m2);
      for (k = 0; k < 5; k++) {
        d_u[k] = cv10[k];
      }

      d_y = NULL;
      m2 = emlrtCreateCharArray(2, iv11);
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
      m2 = emlrtCreateCharArray(2, iv12);
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

  covrtLogFcn(moduleInstance->covInst, 0, 6);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 16);

  /* ............................................................................ */
  /* ............................................................................ */
  /* Function that is called in Simulink to calculate updated */
  /* positions,velocities and accelerations for the cylinder */
  GenCordExt[0] = *moduleInstance->u0;
  GenCordExt[1] = *moduleInstance->u1;
  GenCordExt[2] = *moduleInstance->u2;
  covrtLogFcn(moduleInstance->covInst, 0, 2);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 6);
  for (k = 0; k < 3; k++) {
    SignOposite[k] = -muDoubleScalarSign(GenCordExt[k]);
  }

  covrtLogFcn(moduleInstance->covInst, 0, 1);
  covrtLogIf(moduleInstance->covInst, 0, 0, 0, true);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 1);
  ForceEvaluation = obj->F_s_x;
  if (covrtLogIf(moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs
                 (*moduleInstance->u0) <= ForceEvaluation)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(moduleInstance->covInst, 0, 0, 3, k == 1)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 7);
    ForceEvaluation = *moduleInstance->u0 + SignOposite[0] * obj->F_k_x;
    B = obj->M;
    GeneralCoordinatesDoubleDot_idx_0 = ForceEvaluation / B;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 8);
    GeneralCoordinatesDoubleDot_idx_0 = 0.0;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 1);
  covrtLogIf(moduleInstance->covInst, 0, 0, 0, false);
  covrtLogIf(moduleInstance->covInst, 0, 0, 1, true);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 2);
  ForceEvaluation = obj->F_s_y;
  if (covrtLogIf(moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs
                 (*moduleInstance->u1) <= ForceEvaluation)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(moduleInstance->covInst, 0, 0, 4, k == 1)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 9);
    ForceEvaluation = *moduleInstance->u1 + SignOposite[1] * obj->F_k_y;
    B = obj->M;
    GeneralCoordinatesDoubleDot_idx_1 = ForceEvaluation / B;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 10);
    GeneralCoordinatesDoubleDot_idx_1 = 0.0;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 1);
  covrtLogIf(moduleInstance->covInst, 0, 0, 0, false);
  covrtLogIf(moduleInstance->covInst, 0, 0, 1, false);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 3);
  ForceEvaluation = obj->T_s;
  if (covrtLogIf(moduleInstance->covInst, 0, 0, 2, muDoubleScalarAbs
                 (*moduleInstance->u2) <= ForceEvaluation)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
    k = 0;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 5);
    k = 1;
  }

  if (covrtLogIf(moduleInstance->covInst, 0, 0, 5, k == 1)) {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 11);
    ForceEvaluation = *moduleInstance->u2 + SignOposite[2] * obj->T_k;
    B = obj->Iz;
    ForceEvaluation /= B;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 0, 12);
    ForceEvaluation = 0.0;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 3);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 13);
  for (k = 0; k < 2; k++) {
    Acceleration_o_P3_frame_0[k] = obj->Position_G3_P3_frame_cylinder[k];
  }

  Accelerations[0] = muDoubleScalarCos(*moduleInstance->u4);
  Accelerations[2] = -muDoubleScalarSin(*moduleInstance->u4);
  Accelerations[1] = muDoubleScalarSin(*moduleInstance->u4);
  Accelerations[3] = muDoubleScalarCos(*moduleInstance->u4);
  varargin_22[0] = *moduleInstance->u7;
  varargin_22[1] = *moduleInstance->u8;
  for (k = 0; k < 2; k++) {
    dv0[k] = 0.0;
    for (i3 = 0; i3 < 2; i3++) {
      dv0[k] += Accelerations[k + (i3 << 1)] * Acceleration_o_P3_frame_0[i3];
    }

    Positions[k] = obj->Position_o_G3[k];
    Positions[2 + k] = varargin_22[k] + dv0[k];
  }

  covrtLogFcn(moduleInstance->covInst, 0, 4);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 14);
  covrtLogFcn(moduleInstance->covInst, 0, 5);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 15);

  /* Radius of the cylindrical object in meters */
  /* Mass of the object in Kg */
  /* Acceleration of gravity in m/s^2 */
  /* Static coefficient of friction */
  /* Kinetic coefficient of friction */
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
  B = mpower(*moduleInstance->u3);
  d0 = mpower(*moduleInstance->u3);
  Acceleration_o_P3_frame_0[0] = (GeneralCoordinatesDoubleDot_idx_0 + obj->R *
    muDoubleScalarSin(*moduleInstance->u4) * B) - obj->R * muDoubleScalarCos
    (*moduleInstance->u4) * ForceEvaluation;
  Acceleration_o_P3_frame_0[1] = (GeneralCoordinatesDoubleDot_idx_1 - obj->R *
    muDoubleScalarCos(*moduleInstance->u4) * d0) - obj->R * muDoubleScalarSin
    (*moduleInstance->u4) * ForceEvaluation;
  GeneralCoordinatesDoubleDot[0] = GeneralCoordinatesDoubleDot_idx_0;
  GeneralCoordinatesDoubleDot[1] = GeneralCoordinatesDoubleDot_idx_1;
  for (k = 0; k < 2; k++) {
    Accelerations[k] = GeneralCoordinatesDoubleDot[k];
    Accelerations[2 + k] = Acceleration_o_P3_frame_0[k];
  }

  (*moduleInstance->b_y0)[0] = Accelerations[0];
  (*moduleInstance->b_y0)[1] = Accelerations[1];
  (*moduleInstance->b_y0)[2] = ForceEvaluation;
  (*moduleInstance->b_y0)[3] = obj->R;
  (*moduleInstance->b_y0)[4] = Positions[2];
  (*moduleInstance->b_y0)[5] = Positions[3];
  if (obj->TunablePropsChanged) {
    for (k = 0; k < 44; k++) {
      f_u[k] = cv11[k];
    }

    f_y = NULL;
    m2 = emlrtCreateCharArray(2, iv13);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m2, &f_u[0]);
    emlrtAssign(&f_y, m2);
    error(moduleInstance, message(moduleInstance, f_y, &b_emlrtMCI), &b_emlrtMCI);
  }
}

static void cgxe_mdl_update(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance)
{
  real_T varargin_13[2];
  real_T varargin_14[2];
  int32_T i4;
  boolean_T flag;
  Cylinder *obj;
  static char_T cv12[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv14[2] = { 1, 45 };

  const mxArray *m3;
  static char_T cv13[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv15[2] = { 1, 8 };

  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv16[2] = { 1, 45 };

  static char_T cv14[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  char_T d_u[7];
  const mxArray *d_y;
  static const int32_T iv17[2] = { 1, 7 };

  real_T *R;
  real_T *M;
  real_T *g;
  real_T *Us;
  real_T *Uk;
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
    (moduleInstance->S, 13);
  Position_o_G3 = (real_T (*)[2])cgxertGetRunTimeParamInfoData(moduleInstance->S,
    12);
  T_k = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  T_s = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  F_k_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  F_k_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  F_s_y = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  F_s_x = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  Iz = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  Uk = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  Us = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  g = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  M = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  R = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  for (i4 = 0; i4 < 2; i4++) {
    varargin_13[i4] = (*Position_o_G3)[i4];
    varargin_14[i4] = (*Position_G3_P3_frame_cylinder)[i4];
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

    for (i4 = 0; i4 < 2; i4++) {
      moduleInstance->sysobj.Position_o_G3[i4] = varargin_13[i4];
    }

    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i4 = 0; i4 < 2; i4++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i4] = varargin_14[i4];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i4 = 0; i4 < 45; i4++) {
      u[i4] = cv12[i4];
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv14);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &u[0]);
    emlrtAssign(&y, m3);
    for (i4 = 0; i4 < 8; i4++) {
      b_u[i4] = cv13[i4];
    }

    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv15);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m3, &b_u[0]);
    emlrtAssign(&b_y, m3);
    error(moduleInstance, b_message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i4 = 0; i4 < 45; i4++) {
        c_u[i4] = cv12[i4];
      }

      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv16);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &c_u
        [0]);
      emlrtAssign(&c_y, m3);
      for (i4 = 0; i4 < 7; i4++) {
        d_u[i4] = cv14[i4];
      }

      d_y = NULL;
      m3 = emlrtCreateCharArray(2, iv17);
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
  (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance)
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
  static const int32_T iv18[1] = { 2 };

  real_T *pData;
  int32_T i;
  const mxArray *r_y;
  static const int32_T iv19[1] = { 2 };

  const mxArray *s_y;
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
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Iz);
  emlrtAssign(&j_y, m4);
  emlrtAddField(b_y, j_y, "Iz", 0);
  k_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_s_x);
  emlrtAssign(&k_y, m4);
  emlrtAddField(b_y, k_y, "F_s_x", 0);
  l_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_s_y);
  emlrtAssign(&l_y, m4);
  emlrtAddField(b_y, l_y, "F_s_y", 0);
  m_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_k_x);
  emlrtAssign(&m_y, m4);
  emlrtAddField(b_y, m_y, "F_k_x", 0);
  n_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.F_k_y);
  emlrtAssign(&n_y, m4);
  emlrtAddField(b_y, n_y, "F_k_y", 0);
  o_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.T_s);
  emlrtAssign(&o_y, m4);
  emlrtAddField(b_y, o_y, "T_s", 0);
  p_y = NULL;
  m4 = emlrtCreateDoubleScalar(moduleInstance->sysobj.T_k);
  emlrtAssign(&p_y, m4);
  emlrtAddField(b_y, p_y, "T_k", 0);
  q_y = NULL;
  m4 = emlrtCreateNumericArray(1, iv18, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m4);
  for (i = 0; i < 2; i++) {
    pData[i] = moduleInstance->sysobj.Position_o_G3[i];
  }

  emlrtAssign(&q_y, m4);
  emlrtAddField(b_y, q_y, "Position_o_G3", 0);
  r_y = NULL;
  m4 = emlrtCreateNumericArray(1, iv19, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m4);
  for (i = 0; i < 2; i++) {
    pData[i] = moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i];
  }

  emlrtAssign(&r_y, m4);
  emlrtAddField(b_y, r_y, "Position_G3_P3_frame_cylinder", 0);
  emlrtSetCell(y, 0, b_y);
  s_y = NULL;
  m4 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&s_y, m4);
  emlrtSetCell(y, 1, s_y);
  emlrtAssign(&st, y);
  return st;
}

static void emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
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

static void b_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Cylinder *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[16] = { "isInitialized", "TunablePropsChanged",
    "R", "M", "g", "Us", "Uk", "Iz", "F_s_x", "F_s_y", "F_k_x", "F_k_y", "T_s",
    "T_k", "Position_o_G3", "Position_G3_P3_frame_cylinder" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(moduleInstance->emlrtRootTLSGlobal, parentId, u, 16,
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

static int32_T c_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = h_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T d_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = i_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void f_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2])
{
  k_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T g_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
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

static void mw__internal__setSimState__fcn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *st)
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

static const mxArray *message(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m5;
  pArray = b;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m5, 1,
    &pArray, "message", true, location);
}

static void error(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 0, NULL, 1, &pArray,
                        "error", true, location);
}

static const mxArray *b_message(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m6, 2,
    pArrays, "message", true, location);
}

static int32_T h_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
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

static boolean_T i_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
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

static real_T j_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
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

static void k_emlrt_marshallIn(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2])
{
  static const int32_T dims[1] = { 2 };

  int32_T i5;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "double", false, 1U, dims);
  for (i5 = 0; i5 < 2; i5++) {
    ret[i5] = (*(real_T (*)[2])mxGetData(src))[i5];
  }

  emlrtDestroyArray(&src);
}

static void init_simulink_io_address(InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = cgxertGetEMLRTCtx(moduleInstance->S, 0);
  moduleInstance->covInst = (covrtInstance *)cgxertGetCovrtInstance
    (moduleInstance->S, 0);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 2);
  moduleInstance->u3 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 3);
  moduleInstance->u4 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 4);
  moduleInstance->u5 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 5);
  moduleInstance->u6 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 6);
  moduleInstance->u7 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 7);
  moduleInstance->u8 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 8);
  moduleInstance->b_y0 = (real_T (*)[6])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S, int_T tid)
{
  InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance =
    (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S)
{
  InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance =
    (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S, int_T tid)
{
  InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance =
    (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static mxArray* getSimState_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance =
    (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  return mxSS;
}

static void setSimState_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance =
    (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *)cgxertGetRuntimeInstance(S);
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S)
{
  InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance =
    (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlStart_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S)
{
  InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *moduleInstance =
    (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE *)calloc(1, sizeof
    (InstanceStruct_GnKguKH8AZspcA0U7Ie8uE));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_GnKguKH8AZspcA0U7Ie8uE);
  ssSetmdlInitializeConditions(S, mdlInitialize_GnKguKH8AZspcA0U7Ie8uE);
  ssSetmdlUpdate(S, mdlUpdate_GnKguKH8AZspcA0U7Ie8uE);
  ssSetmdlTerminate(S, mdlTerminate_GnKguKH8AZspcA0U7Ie8uE);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S)
{
}

void method_dispatcher_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_GnKguKH8AZspcA0U7Ie8uE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_GnKguKH8AZspcA0U7Ie8uE(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_GnKguKH8AZspcA0U7Ie8uE(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_GnKguKH8AZspcA0U7Ie8uE(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: GnKguKH8AZspcA0U7Ie8uE.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_GnKguKH8AZspcA0U7Ie8uE_BuildInfoUpdate(void)
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
