/* Include files */

#include "modelInterface.h"
#include "m_ofpynhcn5LFnvtv82bGDI.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 1, 1, "SystemCore",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"
};

static emlrtMCInfo b_emlrtMCI = { 17, 9, "error",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\error.m"
};

static emlrtMCInfo c_emlrtMCI = { 14, 25, "warning",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo d_emlrtMCI = { 14, 9, "warning",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo e_emlrtMCI = { 52, 19, "flt2str",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"
};

/* Function Declarations */
static Phalanx_3 *Phalanx_Phalanx(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, Phalanx_3 *obj, real_T k, real_T d, real_T l, real_T r,
  real_T m, real_T theta, real_T linkNum);
static real_T mpower(real_T a);
static boolean_T isequal(real_T varargin_1, real_T varargin_2);
static real_T norm(real_T x[4]);
static void warning(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance);
static void b_warning(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance,
                      char_T varargin_1[14]);
static void emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *c_sprintf, const char_T *identifier, char_T y
  [14]);
static void b_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, char_T
  y[14]);
static void cgxe_mdl_start(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance);
static const mxArray *emlrt_marshallOut(const Phalanx_3 *u);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance);
static void c_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b_sysobj, const char_T *identifier, Thumb_2 *y);
static void d_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, Thumb_2
  *y);
static int32_T e_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static boolean_T f_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static real_T g_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static void h_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Phalanx_3 *y);
static ForceNormal i_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static void j_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2]);
static boolean_T k_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier);
static void mw__internal__setSimState__fcn(InstanceStruct_ofpynhcn5LFnvtv82bGDI *
  moduleInstance, const mxArray *st);
static const mxArray *message(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static void error(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location);
static const mxArray *b_message(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b, emlrtMCInfo *location);
static const mxArray *feval(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance,
  const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static void b_feval(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance, const
                    mxArray *b, const mxArray *c, emlrtMCInfo *location);
static const mxArray *b_sprintf(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static const mxArray *c_feval(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b, const mxArray *c, const mxArray *d,
  emlrtMCInfo *location);
static void l_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, char_T
  ret[14]);
static int32_T m_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static boolean_T n_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static real_T o_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static void p_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2]);
static void init_simulink_io_address(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance);

/* Function Definitions */
static Phalanx_3 *Phalanx_Phalanx(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, Phalanx_3 *obj, real_T k, real_T d, real_T l, real_T r,
  real_T m, real_T theta, real_T linkNum)
{
  Phalanx_3 *b_obj;
  real_T A;
  ForceNormal *c_obj;
  covrtLogFcn(moduleInstance->covInst, 1, 0);
  b_obj = obj;
  b_obj->miuC = 0.8;
  b_obj->miuE = 0.8;
  b_obj->a = 0.0;
  b_obj->b = 0.0;

  /*  Phalanx Class */
  /*  Represents the Phalanx of an underactuated Finger. */
  /*  Physical Phalanx properties */
  /*  Joint stiffness (Nm/rad) */
  /*  Joint damping coefficient (Nm/(rad/s)) */
  /*  Link length (m) */
  /*  Pulley radius (m) */
  /*  Link mass (kg) */
  /*  Link z-inertia */
  /*  Physical finger properties */
  /*  Coefficient of friction between phalanx and contact object. */
  /*  Coefficient of friction between phalanx and disturbance object.% Kinematic properties */
  /*  Joint rest angle (rad) */
  /*  Joint angle (rad) */
  /*  First derivative (velocity) of joint angle (rad/s) */
  /*  Second derivative (acceleration) of joint angle (rad/s^2) */
  /*  Contact Kinematics properties */
  /*  Distance from joint to contact force (m) */
  /*  Contact Force */
  /*  Disturbance Kinematics properties */
  /*  Distance from joint to disturbance force (m) */
  /*  Disturbance Force */
  /*  Constructor with parameter initialization */
  /*  Custom initialization */
  covrtLogIf(moduleInstance->covInst, 1, 0, 0, true);
  covrtLogBasicBlock(moduleInstance->covInst, 1, 0);
  b_obj->k = k;
  b_obj->d = d;
  b_obj->l = l;
  b_obj->r = r;
  b_obj->m = m;
  b_obj->theta = theta;
  if (covrtLogIf(moduleInstance->covInst, 1, 0, 1, linkNum > 1.0)) {
    covrtLogBasicBlock(moduleInstance->covInst, 1, 1);
    A = b_obj->m * mpower(b_obj->l);
    b_obj->I = A / 12.0;
  } else {
    covrtLogBasicBlock(moduleInstance->covInst, 1, 2);
    A = b_obj->m * mpower(b_obj->l);
    b_obj->I = A / 3.0;
  }

  covrtLogBasicBlock(moduleInstance->covInst, 1, 4);
  b_obj->theta0 = b_obj->theta;
  b_obj->thetaDot = 0.0;
  c_obj = &b_obj->fc;
  A = b_obj->miuC;
  covrtLogFcn(moduleInstance->covInst, 2, 0);
  covrtLogBasicBlock(moduleInstance->covInst, 2, 0);
  c_obj->fv[0] = 0.0;
  c_obj->fv[1] = A * 0.0;
  c_obj = &b_obj->fe;
  A = b_obj->miuE;
  covrtLogFcn(moduleInstance->covInst, 2, 0);
  covrtLogBasicBlock(moduleInstance->covInst, 2, 0);
  c_obj->fv[0] = 0.0;
  c_obj->fv[1] = A * 0.0;
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

static real_T norm(real_T x[4])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  real_T s;
  int32_T i;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((exitg1 == false) && (j < 2)) {
    s = 0.0;
    for (i = 0; i < 2; i++) {
      s += muDoubleScalarAbs(x[i + (j << 1)]);
    }

    if (muDoubleScalarIsNaN(s)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

static void warning(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance)
{
  int32_T i0;
  static char_T cv0[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 7 };

  const mxArray *m0;
  static char_T cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  char_T b_u[7];
  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 7 };

  static char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r',
    'i', 'x' };

  char_T c_u[27];
  const mxArray *c_y;
  static const int32_T iv2[2] = { 1, 27 };

  for (i0 = 0; i0 < 7; i0++) {
    u[i0] = cv0[i0];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  for (i0 = 0; i0 < 7; i0++) {
    b_u[i0] = cv1[i0];
  }

  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 7, m0, &b_u[0]);
  emlrtAssign(&b_y, m0);
  for (i0 = 0; i0 < 27; i0++) {
    c_u[i0] = msgID[i0];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 27, m0, &c_u[0]);
  emlrtAssign(&c_y, m0);
  b_feval(moduleInstance, y, feval(moduleInstance, b_y, c_y, &c_emlrtMCI),
          &d_emlrtMCI);
}

static void b_warning(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance,
                      char_T varargin_1[14])
{
  int32_T i1;
  static char_T cv2[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv3[2] = { 1, 7 };

  const mxArray *m1;
  static char_T cv3[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  char_T b_u[7];
  const mxArray *b_y;
  static const int32_T iv4[2] = { 1, 7 };

  static char_T msgID[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n',
    'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c_u[33];
  const mxArray *c_y;
  static const int32_T iv5[2] = { 1, 33 };

  char_T d_u[14];
  const mxArray *d_y;
  static const int32_T iv6[2] = { 1, 14 };

  for (i1 = 0; i1 < 7; i1++) {
    u[i1] = cv2[i1];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 7, m1, &u[0]);
  emlrtAssign(&y, m1);
  for (i1 = 0; i1 < 7; i1++) {
    b_u[i1] = cv3[i1];
  }

  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 7, m1, &b_u[0]);
  emlrtAssign(&b_y, m1);
  for (i1 = 0; i1 < 33; i1++) {
    c_u[i1] = msgID[i1];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 33, m1, &c_u[0]);
  emlrtAssign(&c_y, m1);
  for (i1 = 0; i1 < 14; i1++) {
    d_u[i1] = varargin_1[i1];
  }

  d_y = NULL;
  m1 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 14, m1, &d_u[0]);
  emlrtAssign(&d_y, m1);
  b_feval(moduleInstance, y, c_feval(moduleInstance, b_y, c_y, d_y, &c_emlrtMCI),
          &d_emlrtMCI);
}

static void emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *c_sprintf, const char_T *identifier, char_T y
  [14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(moduleInstance, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void b_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, char_T
  y[14])
{
  l_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void cgxe_mdl_start(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance)
{
  boolean_T flag;
  Thumb_2 *obj;
  int32_T i2;
  static char_T cv4[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T u[51];
  const mxArray *y;
  static const int32_T iv7[2] = { 1, 51 };

  const mxArray *m2;
  static char_T cv5[5] = { 's', 'e', 't', 'u', 'p' };

  char_T b_u[5];
  const mxArray *b_y;
  static const int32_T iv8[2] = { 1, 5 };

  static char_T cv6[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T c_u[44];
  const mxArray *c_y;
  static const int32_T iv9[2] = { 1, 44 };

  real_T *kP;
  real_T *kD;
  real_T *dP;
  real_T *dD;
  real_T *lP;
  real_T *lD;
  real_T *rP;
  real_T *rD;
  real_T *mP;
  real_T *mD;
  real_T *thetaP;
  real_T *thetaD;
  thetaD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  thetaP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  mD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  mP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  rD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  rP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  lD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  lP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  dD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  dP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  kD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  kP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  init_simulink_io_address(moduleInstance);

  /* Allocate instance data */
  covrtAllocateInstanceData(moduleInstance->covInst);

  /* Initialize Coverage Information */
  covrtScriptInit(moduleInstance->covInst,
                  "C:\\Users\\Ricardo\\Documents\\Workspace\\Directed Studies\\Simulation\\Thumb.m",
                  0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(moduleInstance->covInst, 0, 7, "Thumb_eom", 2946, -1, 4722);
  covrtFcnInit(moduleInstance->covInst, 0, 6, "Thumb_getPoly", 2741, -1, 2937);
  covrtFcnInit(moduleInstance->covInst, 0, 5, "Thumb_fKine", 2224, -1, 2732);
  covrtFcnInit(moduleInstance->covInst, 0, 4, "Thumb_rotMat", 2057, -1, 2215);
  covrtFcnInit(moduleInstance->covInst, 0, 3, "Thumb_computeJe", 1859, -1, 2048);
  covrtFcnInit(moduleInstance->covInst, 0, 2, "Thumb_computeJc", 1643, -1, 1850);
  covrtFcnInit(moduleInstance->covInst, 0, 1, "Thumb_Finger", 1042, -1, 1634);
  covrtFcnInit(moduleInstance->covInst, 0, 8, "Thumb_stepImpl", 4978, -1, 5130);
  covrtFcnInit(moduleInstance->covInst, 0, 0, "Thumb_Thumb", 107, -1, 112);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(moduleInstance->covInst, 0, 7, 2994, -1, 4709);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 6, 2782, -1, 2924);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 5, 2313, -1, 2719);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 4, 2130, -1, 2202);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 3, 1942, -1, 2034);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 2, 1724, -1, 1816);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 1, 1086, -1, 1621);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 8, 5046, -1, 5095);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 0, 107, -1, 112);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(moduleInstance->covInst, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(moduleInstance->covInst);

  /* Initialize Coverage Information */
  covrtScriptInit(moduleInstance->covInst,
                  "C:\\Users\\Ricardo\\Documents\\Workspace\\Directed Studies\\Simulation\\Phalanx.m",
                  1, 1, 5, 2, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(moduleInstance->covInst, 1, 0, "Phalanx_Phalanx", 1232, -1, 2046);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(moduleInstance->covInst, 1, 4, 1844, -1, 2033);
  covrtBasicBlockInit(moduleInstance->covInst, 1, 3, 1789, -1, 1814);
  covrtBasicBlockInit(moduleInstance->covInst, 1, 2, 1709, -1, 1734);
  covrtBasicBlockInit(moduleInstance->covInst, 1, 1, 1640, -1, 1666);
  covrtBasicBlockInit(moduleInstance->covInst, 1, 0, 1435, -1, 1587);

  /* Initialize If Information */
  covrtIfInit(moduleInstance->covInst, 1, 0, 1403, 1418, 1768, 1831);
  covrtIfInit(moduleInstance->covInst, 1, 1, 1605, 1619, 1684, 1755);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(moduleInstance->covInst, 1U);

  /* Allocate instance data */
  covrtAllocateInstanceData(moduleInstance->covInst);

  /* Initialize Coverage Information */
  covrtScriptInit(moduleInstance->covInst,
                  "C:\\Users\\Ricardo\\Documents\\Workspace\\Directed Studies\\Simulation\\ForceNormal.m",
                  2, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(moduleInstance->covInst, 2, 2, "ForceNormal_setForceV", 676, -1,
               795);
  covrtFcnInit(moduleInstance->covInst, 2, 1, "ForceNormal_setD", 553, -1, 667);
  covrtFcnInit(moduleInstance->covInst, 2, 0, "ForceNormal_ForceNormal", 393, -1,
               544);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(moduleInstance->covInst, 2, 2, 762, -1, 782);
  covrtBasicBlockInit(moduleInstance->covInst, 2, 1, 645, -1, 654);
  covrtBasicBlockInit(moduleInstance->covInst, 2, 0, 488, -1, 531);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(moduleInstance->covInst, 2U);
  if (!moduleInstance->sysobj_not_empty) {
    covrtLogFcn(moduleInstance->covInst, 0, 0);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 0);
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj.TunablePropsChanged = false;
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

    moduleInstance->sysobj.kP = *kP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kD = *kD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dP = *dP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dD = *dD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lP = *lP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lD = *lD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rP = *rP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rD = *rD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mP = *mP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mD = *mD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaP = *thetaP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaD = *thetaD;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized != 0) {
    for (i2 = 0; i2 < 51; i2++) {
      u[i2] = cv4[i2];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv7);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m2, &u[0]);
    emlrtAssign(&y, m2);
    for (i2 = 0; i2 < 5; i2++) {
      b_u[i2] = cv5[i2];
    }

    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv8);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m2, &b_u[0]);
    emlrtAssign(&b_y, m2);
    error(moduleInstance, message(moduleInstance, y, b_y, &emlrtMCI), &emlrtMCI);
  }

  obj->isInitialized = 1;
  Phalanx_Phalanx(moduleInstance, &obj->prox, obj->kP, obj->dP, obj->lP, obj->rP,
                  obj->mP, obj->thetaP, 1.0);
  Phalanx_Phalanx(moduleInstance, &obj->dist, obj->kD, obj->dD, obj->lD, obj->rD,
                  obj->mD, obj->thetaD, 2.0);
  if (obj->TunablePropsChanged) {
    for (i2 = 0; i2 < 44; i2++) {
      c_u[i2] = cv6[i2];
    }

    c_y = NULL;
    m2 = emlrtCreateCharArray(2, iv9);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m2, &c_u[0]);
    emlrtAssign(&c_y, m2);
    error(moduleInstance, b_message(moduleInstance, c_y, &emlrtMCI), &emlrtMCI);
  }

  obj->TunablePropsChanged = false;
}

static void cgxe_mdl_initialize(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance)
{
  boolean_T tunablePropChangedBeforeResetImpl;
  Thumb_2 *obj;
  int32_T i3;
  static char_T cv7[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv10[2] = { 1, 45 };

  const mxArray *m3;
  static char_T cv8[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv11[2] = { 1, 8 };

  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv12[2] = { 1, 45 };

  static char_T cv9[5] = { 'r', 'e', 's', 'e', 't' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv13[2] = { 1, 5 };

  static char_T cv10[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T e_u[44];
  const mxArray *e_y;
  static const int32_T iv14[2] = { 1, 44 };

  real_T *kP;
  real_T *kD;
  real_T *dP;
  real_T *dD;
  real_T *lP;
  real_T *lD;
  real_T *rP;
  real_T *rD;
  real_T *mP;
  real_T *mD;
  real_T *thetaP;
  real_T *thetaD;
  thetaD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  thetaP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  mD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  mP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  rD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  rP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  lD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  lP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  dD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  dP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  kD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  kP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  if (!moduleInstance->sysobj_not_empty) {
    covrtLogFcn(moduleInstance->covInst, 0, 0);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 0);
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj.TunablePropsChanged = false;
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

    moduleInstance->sysobj.kP = *kP;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kD = *kD;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dP = *dP;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dD = *dD;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lP = *lP;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lD = *lD;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rP = *rP;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rD = *rD;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mP = *mP;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mD = *mD;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaP = *thetaP;
    tunablePropChangedBeforeResetImpl = (moduleInstance->sysobj.isInitialized ==
      1);
    if (tunablePropChangedBeforeResetImpl) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaD = *thetaD;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i3 = 0; i3 < 45; i3++) {
      u[i3] = cv7[i3];
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv10);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &u[0]);
    emlrtAssign(&y, m3);
    for (i3 = 0; i3 < 8; i3++) {
      b_u[i3] = cv8[i3];
    }

    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv11);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m3, &b_u[0]);
    emlrtAssign(&b_y, m3);
    error(moduleInstance, message(moduleInstance, y, b_y, &emlrtMCI), &emlrtMCI);
  }

  tunablePropChangedBeforeResetImpl = (obj->isInitialized == 1);
  if (tunablePropChangedBeforeResetImpl) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i3 = 0; i3 < 45; i3++) {
        c_u[i3] = cv7[i3];
      }

      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv12);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &c_u
        [0]);
      emlrtAssign(&c_y, m3);
      for (i3 = 0; i3 < 5; i3++) {
        d_u[i3] = cv9[i3];
      }

      d_y = NULL;
      m3 = emlrtCreateCharArray(2, iv13);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m3, &d_u[0]);
      emlrtAssign(&d_y, m3);
      error(moduleInstance, message(moduleInstance, c_y, d_y, &emlrtMCI),
            &emlrtMCI);
    }

    tunablePropChangedBeforeResetImpl = obj->TunablePropsChanged;
    if ((int32_T)tunablePropChangedBeforeResetImpl != (int32_T)
        obj->TunablePropsChanged) {
      for (i3 = 0; i3 < 44; i3++) {
        e_u[i3] = cv10[i3];
      }

      e_y = NULL;
      m3 = emlrtCreateCharArray(2, iv14);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m3, &e_u
        [0]);
      emlrtAssign(&e_y, m3);
      error(moduleInstance, b_message(moduleInstance, e_y, &emlrtMCI), &emlrtMCI);
    }
  }
}

static void cgxe_mdl_outputs(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance)
{
  real_T varargin_13[4];
  int32_T i4;
  boolean_T flag;
  Thumb_2 *obj;
  static char_T cv11[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv15[2] = { 1, 45 };

  const mxArray *m4;
  static char_T cv12[4] = { 's', 't', 'e', 'p' };

  char_T b_u[4];
  const mxArray *b_y;
  static const int32_T iv16[2] = { 1, 4 };

  static char_T cv13[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T c_u[51];
  const mxArray *c_y;
  static const int32_T iv17[2] = { 1, 51 };

  static char_T cv14[5] = { 's', 'e', 't', 'u', 'p' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv18[2] = { 1, 5 };

  static char_T cv15[44] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd', 'T', 'u', 'n', 'a',
    'b', 'l', 'e', 'M', 'o', 'd', 'A', 'c', 'c', 'e', 's', 's', 'C', 'o', 'd',
    'e', 'g', 'e', 'n' };

  char_T e_u[44];
  const mxArray *e_y;
  static const int32_T iv19[2] = { 1, 44 };

  real_T thetaDot[2];
  real_T K[4];
  real_T D[4];
  real_T Ja[2];
  real_T r;
  real_T Jc[4];
  real_T Je[4];
  real_T t;
  real_T alpha;
  real_T beta;
  real_T delta;
  real_T rc;
  real_T M[4];
  real_T C[4];
  real_T b_obj[2];
  real_T c_obj[2];
  real_T b[2];
  real_T b_b[2];
  real_T c_b[2];
  real_T f_y[4];
  static char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  char_T f_u[6];
  const mxArray *g_y;
  static const int32_T iv20[2] = { 1, 6 };

  const mxArray *h_y;
  char_T str[14];
  real_T d_b[2];
  real_T varargin_3[2];
  real_T dv0[4];
  int32_T i5;
  real_T dv1[4];
  char_T g_u[44];
  const mxArray *i_y;
  static const int32_T iv21[2] = { 1, 44 };

  real_T b_C[2];
  real_T *thetaD;
  real_T *thetaP;
  real_T *mD;
  real_T *mP;
  real_T *rD;
  real_T *rP;
  real_T *lD;
  real_T *lP;
  real_T *dD;
  real_T *dP;
  real_T *kD;
  real_T *kP;
  kP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  kD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  dP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  dD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  lP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  lD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  rP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  rD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  mP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  mD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  thetaP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  thetaD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  for (i4 = 0; i4 < 4; i4++) {
    varargin_13[i4] = (*moduleInstance->u0)[i4];
  }

  if (!moduleInstance->sysobj_not_empty) {
    covrtLogFcn(moduleInstance->covInst, 0, 0);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 0);
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj.TunablePropsChanged = false;
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

    moduleInstance->sysobj.kP = *kP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kD = *kD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dP = *dP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dD = *dD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lP = *lP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lD = *lD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rP = *rP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rD = *rD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mP = *mP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mD = *mD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaP = *thetaP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaD = *thetaD;
  }

  if (!isequal(moduleInstance->sysobj.kP, *kP)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kP = *kP;
  }

  if (!isequal(moduleInstance->sysobj.kD, *kD)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kD = *kD;
  }

  if (!isequal(moduleInstance->sysobj.dP, *dP)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dP = *dP;
  }

  if (!isequal(moduleInstance->sysobj.dD, *dD)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dD = *dD;
  }

  if (!isequal(moduleInstance->sysobj.lP, *lP)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lP = *lP;
  }

  if (!isequal(moduleInstance->sysobj.lD, *lD)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lD = *lD;
  }

  if (!isequal(moduleInstance->sysobj.rP, *rP)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rP = *rP;
  }

  if (!isequal(moduleInstance->sysobj.rD, *rD)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rD = *rD;
  }

  if (!isequal(moduleInstance->sysobj.mP, *mP)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mP = *mP;
  }

  if (!isequal(moduleInstance->sysobj.mD, *mD)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mD = *mD;
  }

  if (!isequal(moduleInstance->sysobj.thetaP, *thetaP)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaP = *thetaP;
  }

  if (!isequal(moduleInstance->sysobj.thetaD, *thetaD)) {
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaD = *thetaD;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i4 = 0; i4 < 45; i4++) {
      u[i4] = cv11[i4];
    }

    y = NULL;
    m4 = emlrtCreateCharArray(2, iv15);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m4, &u[0]);
    emlrtAssign(&y, m4);
    for (i4 = 0; i4 < 4; i4++) {
      b_u[i4] = cv12[i4];
    }

    b_y = NULL;
    m4 = emlrtCreateCharArray(2, iv16);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 4, m4, &b_u[0]);
    emlrtAssign(&b_y, m4);
    error(moduleInstance, message(moduleInstance, y, b_y, &emlrtMCI), &emlrtMCI);
  }

  if (obj->isInitialized != 1) {
    if (obj->isInitialized != 0) {
      for (i4 = 0; i4 < 51; i4++) {
        c_u[i4] = cv13[i4];
      }

      c_y = NULL;
      m4 = emlrtCreateCharArray(2, iv17);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m4, &c_u
        [0]);
      emlrtAssign(&c_y, m4);
      for (i4 = 0; i4 < 5; i4++) {
        d_u[i4] = cv14[i4];
      }

      d_y = NULL;
      m4 = emlrtCreateCharArray(2, iv18);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m4, &d_u[0]);
      emlrtAssign(&d_y, m4);
      error(moduleInstance, message(moduleInstance, c_y, d_y, &emlrtMCI),
            &emlrtMCI);
    }

    obj->isInitialized = 1;
    Phalanx_Phalanx(moduleInstance, &obj->prox, obj->kP, obj->dP, obj->lP,
                    obj->rP, obj->mP, obj->thetaP, 1.0);
    Phalanx_Phalanx(moduleInstance, &obj->dist, obj->kD, obj->dD, obj->lD,
                    obj->rD, obj->mD, obj->thetaD, 2.0);
    if (obj->TunablePropsChanged) {
      for (i4 = 0; i4 < 44; i4++) {
        e_u[i4] = cv15[i4];
      }

      e_y = NULL;
      m4 = emlrtCreateCharArray(2, iv19);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m4, &e_u
        [0]);
      emlrtAssign(&e_y, m4);
      error(moduleInstance, b_message(moduleInstance, e_y, &emlrtMCI), &emlrtMCI);
    }

    obj->TunablePropsChanged = false;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 8);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 8);
  covrtLogFcn(moduleInstance->covInst, 0, 7);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 7);

  /*  Represents an underactuated cable driven finger. */
  /*  Author: Ricardo Garcia Rosas */
  /*  Finger Class */
  /*  Represents an underactuated cable driven finger. */
  /*  proximal joiny stiffness coefficient (Nm/rad) */
  /*  distal joint stiffness coefficient (Nm/rad) */
  /*  proximal joint damping coefficient (Nm/(rad/s)) */
  /*  distal joint damping coefficient (Nm/(rad/s)) */
  /*  proximal link length (m) */
  /*  distal link length (m) */
  /*  proximal pulley radius (m) */
  /*  distal pulley radius (m) */
  /*  proximal link mass (kg) */
  /*  distal link mass (kg) */
  /*  proximal joint rest angle (rad) */
  /*  distal joint rest angle (rad) */
  /*  Finger proximal phalanx */
  /*  Finger distal phalanx */
  /*          function obj = Finger(origin, kP, kD, lP, lD, rP, rD, mP, mD, thetaP, thetaD, thetaA) */
  /*  Update contact jacobian */
  /*  Update disturbance jacobian */
  /*  Rotation matrix */
  /*  Forward kinematics */
  obj->prox.theta = varargin_13[0];
  obj->dist.theta = varargin_13[1];
  obj->prox.thetaDot = varargin_13[2];
  obj->dist.thetaDot = varargin_13[3];
  thetaDot[0] = obj->prox.thetaDot;
  thetaDot[1] = obj->dist.thetaDot;
  K[0] = obj->prox.k;
  K[2] = 0.0;
  K[1] = 0.0;
  K[3] = obj->dist.k;
  D[0] = obj->prox.d;
  D[2] = 0.0;
  D[1] = 0.0;
  D[3] = obj->dist.d;
  Ja[0] = obj->prox.r;
  Ja[1] = obj->dist.r;
  covrtLogFcn(moduleInstance->covInst, 0, 2);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 2);
  r = obj->dist.theta;
  Jc[0] = obj->prox.a;
  Jc[2] = 0.0;
  Jc[1] = obj->dist.a + obj->prox.l * muDoubleScalarCos(r);
  Jc[3] = obj->dist.a;
  covrtLogFcn(moduleInstance->covInst, 0, 3);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 3);
  r = obj->dist.theta;
  Je[0] = obj->prox.b;
  Je[2] = 0.0;
  Je[1] = obj->dist.b + obj->prox.l * muDoubleScalarCos(r);
  Je[3] = obj->dist.b;
  t = obj->prox.l;
  r = obj->dist.l;
  alpha = ((obj->prox.I + obj->dist.I) + obj->prox.m * mpower(t / 2.0)) +
    obj->dist.m * (mpower(obj->prox.l) + mpower(r / 2.0));
  t = obj->dist.l;
  beta = obj->dist.m * obj->prox.l * (t / 2.0);
  t = obj->dist.l;
  delta = obj->dist.I + obj->dist.m * mpower(t / 2.0);

  /*  Intertia matrix (M) */
  r = obj->dist.theta;
  t = obj->dist.theta;
  rc = obj->dist.theta;
  M[0] = alpha + 2.0 * beta * muDoubleScalarCos(r);
  M[2] = delta + beta * muDoubleScalarCos(t);
  M[1] = delta + beta * muDoubleScalarCos(rc);
  M[3] = delta;

  /*  Coriolis and Centrifugal matrix (C) */
  r = obj->dist.theta;
  t = obj->dist.theta;
  rc = obj->dist.theta;
  C[0] = -beta * muDoubleScalarSin(r) * obj->dist.thetaDot;
  C[2] = -beta * muDoubleScalarSin(t) * (obj->prox.thetaDot + obj->dist.thetaDot);
  C[1] = beta * muDoubleScalarSin(rc) * obj->prox.thetaDot;
  C[3] = 0.0;
  b_obj[0] = obj->prox.theta;
  b_obj[1] = obj->dist.theta;
  c_obj[0] = obj->prox.theta0;
  c_obj[1] = obj->dist.theta0;
  for (i4 = 0; i4 < 2; i4++) {
    b[i4] = b_obj[i4] - c_obj[i4];
  }

  b_b[0] = obj->prox.fc.fv[0];
  b_b[1] = obj->dist.fc.fv[0];
  c_b[0] = obj->prox.fe.fv[0];
  c_b[1] = obj->dist.fe.fv[0];

  /*              thetaDotDot = inv(M)*(-C*thetaDot + springTau + [-0.01 0; 0 -0.01]*thetaDot + contactTau + distTau + actTau); */
  if (muDoubleScalarAbs(M[1]) > muDoubleScalarAbs(M[0])) {
    r = M[0] / M[1];
    t = 1.0 / (r * delta - M[2]);
    f_y[0] = delta / M[1] * t;
    f_y[1] = -t;
    f_y[2] = -M[2] / M[1] * t;
    f_y[3] = r * t;
  } else {
    r = M[1] / M[0];
    t = 1.0 / (delta - r * M[2]);
    f_y[0] = delta / M[0] * t;
    f_y[1] = -r * t;
    f_y[2] = -M[2] / M[0] * t;
    f_y[3] = t;
  }

  r = norm(M);
  t = norm(f_y);
  rc = 1.0 / (r * t);
  if ((r == 0.0) || (t == 0.0) || (rc == 0.0)) {
    warning(moduleInstance);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      for (i4 = 0; i4 < 6; i4++) {
        f_u[i4] = rfmt[i4];
      }

      g_y = NULL;
      m4 = emlrtCreateCharArray(2, iv20);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 6, m4, &f_u[0]);
      emlrtAssign(&g_y, m4);
      h_y = NULL;
      m4 = emlrtCreateDoubleScalar(rc);
      emlrtAssign(&h_y, m4);
      emlrt_marshallIn(moduleInstance, b_sprintf(moduleInstance, g_y, h_y,
        &e_emlrtMCI), "sprintf", str);
      b_warning(moduleInstance, str);
    }
  }

  covrtLogFcn(moduleInstance->covInst, 0, 5);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 5);
  for (i4 = 0; i4 < 4; i4++) {
    (*moduleInstance->b_y1)[i4] = 0.0;
  }

  r = obj->prox.theta;
  covrtLogFcn(moduleInstance->covInst, 0, 4);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
  d_b[0] = obj->prox.l;
  d_b[1] = 0.0;
  varargin_3[0] = *moduleInstance->u2;
  varargin_3[1] = *moduleInstance->u3;
  dv0[0] = muDoubleScalarCos(r);
  dv0[2] = -muDoubleScalarSin(r);
  dv0[1] = muDoubleScalarSin(r);
  dv0[3] = muDoubleScalarCos(r);
  for (i4 = 0; i4 < 2; i4++) {
    r = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      r += dv0[i4 + (i5 << 1)] * d_b[i5];
    }

    (*moduleInstance->b_y1)[i4] = varargin_3[i4] + r;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 4);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
  r = obj->prox.theta + obj->dist.theta;
  covrtLogFcn(moduleInstance->covInst, 0, 4);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
  d_b[0] = obj->dist.l;
  d_b[1] = 0.0;
  dv1[0] = muDoubleScalarCos(r);
  dv1[2] = -muDoubleScalarSin(r);
  dv1[1] = muDoubleScalarSin(r);
  dv1[3] = muDoubleScalarCos(r);
  for (i4 = 0; i4 < 2; i4++) {
    r = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      r += dv1[i4 + (i5 << 1)] * d_b[i5];
    }

    (*moduleInstance->b_y1)[2 + i4] = (*moduleInstance->b_y1)[i4] + r;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 4);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 4);
  if (obj->TunablePropsChanged) {
    for (i4 = 0; i4 < 44; i4++) {
      g_u[i4] = cv15[i4];
    }

    i_y = NULL;
    m4 = emlrtCreateCharArray(2, iv21);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 44, m4, &g_u[0]);
    emlrtAssign(&i_y, m4);
    error(moduleInstance, b_message(moduleInstance, i_y, &emlrtMCI), &emlrtMCI);
  }

  for (i4 = 0; i4 < 2; i4++) {
    for (i5 = 0; i5 < 2; i5++) {
      varargin_13[i5 + (i4 << 1)] = -C[i5 + (i4 << 1)];
    }
  }

  for (i4 = 0; i4 < 2; i4++) {
    b_obj[i4] = 0.0;
    c_obj[i4] = 0.0;
    r = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      r += D[i4 + (i5 << 1)] * thetaDot[i5];
      b_obj[i4] += varargin_13[i4 + (i5 << 1)] * thetaDot[i5];
      c_obj[i4] += K[i4 + (i5 << 1)] * b[i5];
    }

    d_b[i4] = (b_obj[i4] + c_obj[i4]) + r;
    varargin_3[i4] = 0.0;
    r = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      r += Je[i5 + (i4 << 1)] * c_b[i5];
      varargin_3[i4] += Jc[i5 + (i4 << 1)] * b_b[i5];
    }

    b_C[i4] = ((d_b[i4] + varargin_3[i4]) + r) + Ja[i4] * *moduleInstance->u1;
  }

  for (i4 = 0; i4 < 2; i4++) {
    b_obj[i4] = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      b_obj[i4] += f_y[i4 + (i5 << 1)] * b_C[i5];
    }

    varargin_13[i4] = thetaDot[i4];
    varargin_13[i4 + 2] = b_obj[i4];
  }

  for (i4 = 0; i4 < 4; i4++) {
    (*moduleInstance->b_y0)[i4] = varargin_13[i4];
  }
}

static void cgxe_mdl_update(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance)
{
  boolean_T flag;
  Thumb_2 *obj;
  int32_T i6;
  static char_T cv16[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv22[2] = { 1, 45 };

  const mxArray *m5;
  static char_T cv17[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv23[2] = { 1, 8 };

  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv24[2] = { 1, 45 };

  static char_T cv18[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  char_T d_u[7];
  const mxArray *d_y;
  static const int32_T iv25[2] = { 1, 7 };

  real_T *kP;
  real_T *kD;
  real_T *dP;
  real_T *dD;
  real_T *lP;
  real_T *lD;
  real_T *rP;
  real_T *rD;
  real_T *mP;
  real_T *mD;
  real_T *thetaP;
  real_T *thetaD;
  thetaD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 11);
  thetaP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 10);
  mD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 9);
  mP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 8);
  rD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 7);
  rP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 6);
  lD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 5);
  lP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 4);
  dD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  dP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);
  kD = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 1);
  kP = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  if (!moduleInstance->sysobj_not_empty) {
    covrtLogFcn(moduleInstance->covInst, 0, 0);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 0);
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj.TunablePropsChanged = false;
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

    moduleInstance->sysobj.kP = *kP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kD = *kD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dP = *dP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dD = *dD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lP = *lP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.lD = *lD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rP = *rP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.rD = *rD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mP = *mP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.mD = *mD;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaP = *thetaP;
    flag = (moduleInstance->sysobj.isInitialized == 1);
    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.thetaD = *thetaD;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i6 = 0; i6 < 45; i6++) {
      u[i6] = cv16[i6];
    }

    y = NULL;
    m5 = emlrtCreateCharArray(2, iv22);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m5, &u[0]);
    emlrtAssign(&y, m5);
    for (i6 = 0; i6 < 8; i6++) {
      b_u[i6] = cv17[i6];
    }

    b_y = NULL;
    m5 = emlrtCreateCharArray(2, iv23);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m5, &b_u[0]);
    emlrtAssign(&b_y, m5);
    error(moduleInstance, message(moduleInstance, y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i6 = 0; i6 < 45; i6++) {
        c_u[i6] = cv16[i6];
      }

      c_y = NULL;
      m5 = emlrtCreateCharArray(2, iv24);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m5, &c_u
        [0]);
      emlrtAssign(&c_y, m5);
      for (i6 = 0; i6 < 7; i6++) {
        d_u[i6] = cv18[i6];
      }

      d_y = NULL;
      m5 = emlrtCreateCharArray(2, iv25);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 7, m5, &d_u[0]);
      emlrtAssign(&d_y, m5);
      error(moduleInstance, message(moduleInstance, c_y, d_y, &emlrtMCI),
            &emlrtMCI);
    }

    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* Free instance data */
  covrtFreeInstanceData(moduleInstance->covInst);

  /* Free instance data */
  covrtFreeInstanceData(moduleInstance->covInst);

  /* Free instance data */
  covrtFreeInstanceData(moduleInstance->covInst);
}

static const mxArray *emlrt_marshallOut(const Phalanx_3 *u)
{
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *m6;
  const mxArray *c_y;
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
  static const int32_T iv26[1] = { 2 };

  real_T *pData;
  int32_T i;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  static const int32_T iv27[1] = { 2 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->k);
  emlrtAssign(&b_y, m6);
  emlrtAddField(y, b_y, "k", 0);
  c_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->d);
  emlrtAssign(&c_y, m6);
  emlrtAddField(y, c_y, "d", 0);
  d_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->l);
  emlrtAssign(&d_y, m6);
  emlrtAddField(y, d_y, "l", 0);
  e_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->r);
  emlrtAssign(&e_y, m6);
  emlrtAddField(y, e_y, "r", 0);
  f_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->m);
  emlrtAssign(&f_y, m6);
  emlrtAddField(y, f_y, "m", 0);
  g_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->I);
  emlrtAssign(&g_y, m6);
  emlrtAddField(y, g_y, "I", 0);
  h_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->miuC);
  emlrtAssign(&h_y, m6);
  emlrtAddField(y, h_y, "miuC", 0);
  i_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->miuE);
  emlrtAssign(&i_y, m6);
  emlrtAddField(y, i_y, "miuE", 0);
  j_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->theta0);
  emlrtAssign(&j_y, m6);
  emlrtAddField(y, j_y, "theta0", 0);
  k_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->theta);
  emlrtAssign(&k_y, m6);
  emlrtAddField(y, k_y, "theta", 0);
  l_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->thetaDot);
  emlrtAssign(&l_y, m6);
  emlrtAddField(y, l_y, "thetaDot", 0);
  m_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->a);
  emlrtAssign(&m_y, m6);
  emlrtAddField(y, m_y, "a", 0);
  n_y = NULL;
  emlrtAssign(&n_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  o_y = NULL;
  m6 = emlrtCreateNumericArray(1, iv26, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 2; i++) {
    pData[i] = u->fc.fv[i];
  }

  emlrtAssign(&o_y, m6);
  emlrtAddField(n_y, o_y, "fv", 0);
  emlrtAddField(y, n_y, "fc", 0);
  p_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->b);
  emlrtAssign(&p_y, m6);
  emlrtAddField(y, p_y, "b", 0);
  q_y = NULL;
  emlrtAssign(&q_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  r_y = NULL;
  m6 = emlrtCreateNumericArray(1, iv27, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 2; i++) {
    pData[i] = u->fe.fv[i];
  }

  emlrtAssign(&r_y, m6);
  emlrtAddField(q_y, r_y, "fv", 0);
  emlrtAddField(y, q_y, "fe", 0);
  return y;
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance)
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
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj.TunablePropsChanged);
  emlrtAssign(&d_y, m7);
  emlrtAddField(b_y, d_y, "TunablePropsChanged", 0);
  e_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kP);
  emlrtAssign(&e_y, m7);
  emlrtAddField(b_y, e_y, "kP", 0);
  f_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kD);
  emlrtAssign(&f_y, m7);
  emlrtAddField(b_y, f_y, "kD", 0);
  g_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dP);
  emlrtAssign(&g_y, m7);
  emlrtAddField(b_y, g_y, "dP", 0);
  h_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dD);
  emlrtAssign(&h_y, m7);
  emlrtAddField(b_y, h_y, "dD", 0);
  i_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.lP);
  emlrtAssign(&i_y, m7);
  emlrtAddField(b_y, i_y, "lP", 0);
  j_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.lD);
  emlrtAssign(&j_y, m7);
  emlrtAddField(b_y, j_y, "lD", 0);
  k_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.rP);
  emlrtAssign(&k_y, m7);
  emlrtAddField(b_y, k_y, "rP", 0);
  l_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.rD);
  emlrtAssign(&l_y, m7);
  emlrtAddField(b_y, l_y, "rD", 0);
  m_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.mP);
  emlrtAssign(&m_y, m7);
  emlrtAddField(b_y, m_y, "mP", 0);
  n_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.mD);
  emlrtAssign(&n_y, m7);
  emlrtAddField(b_y, n_y, "mD", 0);
  o_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.thetaP);
  emlrtAssign(&o_y, m7);
  emlrtAddField(b_y, o_y, "thetaP", 0);
  p_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.thetaD);
  emlrtAssign(&p_y, m7);
  emlrtAddField(b_y, p_y, "thetaD", 0);
  emlrtAddField(b_y, emlrt_marshallOut(&moduleInstance->sysobj.prox), "prox", 0);
  emlrtAddField(b_y, emlrt_marshallOut(&moduleInstance->sysobj.dist), "dist", 0);
  emlrtSetCell(y, 0, b_y);
  q_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&q_y, m7);
  emlrtSetCell(y, 1, q_y);
  emlrtAssign(&st, y);
  return st;
}

static void c_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b_sysobj, const char_T *identifier, Thumb_2 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(moduleInstance, emlrtAlias(b_sysobj), &thisId, y);
  emlrtDestroyArray(&b_sysobj);
}

static void d_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, Thumb_2
  *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[16] = { "isInitialized", "TunablePropsChanged",
    "kP", "kD", "dP", "dD", "lP", "lD", "rP", "rD", "mP", "mD", "thetaP",
    "thetaD", "prox", "dist" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(moduleInstance->emlrtRootTLSGlobal, parentId, u, 16,
    fieldNames, 0U, &dims);
  thisId.fIdentifier = "isInitialized";
  y->isInitialized = e_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetFieldR2013a(moduleInstance->emlrtRootTLSGlobal, u, 0,
    "isInitialized")), &thisId);
  thisId.fIdentifier = "TunablePropsChanged";
  y->TunablePropsChanged = f_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetFieldR2013a(moduleInstance->emlrtRootTLSGlobal, u, 0,
    "TunablePropsChanged")), &thisId);
  thisId.fIdentifier = "kP";
  y->kP = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "kP")), &thisId);
  thisId.fIdentifier = "kD";
  y->kD = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "kD")), &thisId);
  thisId.fIdentifier = "dP";
  y->dP = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "dP")), &thisId);
  thisId.fIdentifier = "dD";
  y->dD = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "dD")), &thisId);
  thisId.fIdentifier = "lP";
  y->lP = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "lP")), &thisId);
  thisId.fIdentifier = "lD";
  y->lD = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "lD")), &thisId);
  thisId.fIdentifier = "rP";
  y->rP = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "rP")), &thisId);
  thisId.fIdentifier = "rD";
  y->rD = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "rD")), &thisId);
  thisId.fIdentifier = "mP";
  y->mP = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "mP")), &thisId);
  thisId.fIdentifier = "mD";
  y->mD = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "mD")), &thisId);
  thisId.fIdentifier = "thetaP";
  y->thetaP = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "thetaP")), &thisId);
  thisId.fIdentifier = "thetaD";
  y->thetaD = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "thetaD")), &thisId);
  thisId.fIdentifier = "prox";
  h_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "prox")), &thisId, &y->prox);
  thisId.fIdentifier = "dist";
  h_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "dist")), &thisId, &y->dist);
  emlrtDestroyArray(&u);
}

static int32_T e_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = m_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T f_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = n_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T g_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = o_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Phalanx_3 *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[15] = { "k", "d", "l", "r", "m", "I", "miuC",
    "miuE", "theta0", "theta", "thetaDot", "a", "fc", "b", "fe" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(moduleInstance->emlrtRootTLSGlobal, parentId, u, 15,
    fieldNames, 0U, &dims);
  thisId.fIdentifier = "k";
  y->k = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "k")), &thisId);
  thisId.fIdentifier = "d";
  y->d = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "d")), &thisId);
  thisId.fIdentifier = "l";
  y->l = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "l")), &thisId);
  thisId.fIdentifier = "r";
  y->r = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "r")), &thisId);
  thisId.fIdentifier = "m";
  y->m = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "m")), &thisId);
  thisId.fIdentifier = "I";
  y->I = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "I")), &thisId);
  thisId.fIdentifier = "miuC";
  y->miuC = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "miuC")), &thisId);
  thisId.fIdentifier = "miuE";
  y->miuE = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "miuE")), &thisId);
  thisId.fIdentifier = "theta0";
  y->theta0 = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "theta0")), &thisId);
  thisId.fIdentifier = "theta";
  y->theta = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "theta")), &thisId);
  thisId.fIdentifier = "thetaDot";
  y->thetaDot = g_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetFieldR2013a(moduleInstance->emlrtRootTLSGlobal, u, 0, "thetaDot")),
    &thisId);
  thisId.fIdentifier = "a";
  y->a = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "a")), &thisId);
  thisId.fIdentifier = "fc";
  y->fc = i_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "fc")), &thisId);
  thisId.fIdentifier = "b";
  y->b = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "b")), &thisId);
  thisId.fIdentifier = "fe";
  y->fe = i_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "fe")), &thisId);
  emlrtDestroyArray(&u);
}

static ForceNormal i_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  ForceNormal y;
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[1] = { "fv" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(moduleInstance->emlrtRootTLSGlobal, parentId, u, 1,
    fieldNames, 0U, &dims);
  thisId.fIdentifier = "fv";
  j_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "fv")), &thisId, y.fv);
  emlrtDestroyArray(&u);
  return y;
}

static void j_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2])
{
  p_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T k_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(moduleInstance, emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_ofpynhcn5LFnvtv82bGDI *
  moduleInstance, const mxArray *st)
{
  const mxArray *u;
  u = emlrtAlias(st);
  c_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetCell
    (moduleInstance->emlrtRootTLSGlobal, "sysobj", u, 0)), "sysobj",
                     &moduleInstance->sysobj);
  moduleInstance->sysobj_not_empty = k_emlrt_marshallIn(moduleInstance,
    emlrtAlias(emlrtGetCell(moduleInstance->emlrtRootTLSGlobal,
    "sysobj_not_empty", u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static const mxArray *message(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m8, 2,
    pArrays, "message", true, location);
}

static void error(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 0, NULL, 1, &pArray,
                        "error", true, location);
}

static const mxArray *b_message(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m9;
  pArray = b;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m9, 1,
    &pArray, "message", true, location);
}

static const mxArray *feval(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance,
  const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m10;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m10, 2,
    pArrays, "feval", true, location);
}

static void b_feval(InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance, const
                    mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 0, NULL, 2, pArrays,
                        "feval", true, location);
}

static const mxArray *b_sprintf(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m11;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m11, 2,
    pArrays, "sprintf", true, location);
}

static const mxArray *c_feval(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *b, const mxArray *c, const mxArray *d,
  emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m12;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m12, 3,
    pArrays, "feval", true, location);
}

static void l_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, char_T
  ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src, "char",
    false, 2U, dims);
  emlrtImportCharArrayR2015b(moduleInstance->emlrtRootTLSGlobal, src, ret, 14);
  emlrtDestroyArray(&src);
}

static int32_T m_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
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

static boolean_T n_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
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

static real_T o_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
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

static void p_emlrt_marshallIn(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2])
{
  static const int32_T dims[1] = { 2 };

  int32_T i7;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "double", false, 1U, dims);
  for (i7 = 0; i7 < 2; i7++) {
    ret[i7] = (*(real_T (*)[2])mxGetData(src))[i7];
  }

  emlrtDestroyArray(&src);
}

static void init_simulink_io_address(InstanceStruct_ofpynhcn5LFnvtv82bGDI
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = cgxertGetEMLRTCtx(moduleInstance->S, 0);
  moduleInstance->covInst = (covrtInstance *)cgxertGetCovrtInstance
    (moduleInstance->S, 0);
  moduleInstance->u0 = (real_T (*)[4])cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 2);
  moduleInstance->u3 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 3);
  moduleInstance->b_y0 = (real_T (*)[4])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T (*)[4])cgxertGetOutputPortSignal
    (moduleInstance->S, 1);
}

/* CGXE Glue Code */
static void mdlOutputs_ofpynhcn5LFnvtv82bGDI(SimStruct *S, int_T tid)
{
  InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance =
    (InstanceStruct_ofpynhcn5LFnvtv82bGDI *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_ofpynhcn5LFnvtv82bGDI(SimStruct *S)
{
  InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance =
    (InstanceStruct_ofpynhcn5LFnvtv82bGDI *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_ofpynhcn5LFnvtv82bGDI(SimStruct *S, int_T tid)
{
  InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance =
    (InstanceStruct_ofpynhcn5LFnvtv82bGDI *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static mxArray* getSimState_ofpynhcn5LFnvtv82bGDI(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance =
    (InstanceStruct_ofpynhcn5LFnvtv82bGDI *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  return mxSS;
}

static void setSimState_ofpynhcn5LFnvtv82bGDI(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance =
    (InstanceStruct_ofpynhcn5LFnvtv82bGDI *)cgxertGetRuntimeInstance(S);
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_ofpynhcn5LFnvtv82bGDI(SimStruct *S)
{
  InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance =
    (InstanceStruct_ofpynhcn5LFnvtv82bGDI *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlStart_ofpynhcn5LFnvtv82bGDI(SimStruct *S)
{
  InstanceStruct_ofpynhcn5LFnvtv82bGDI *moduleInstance =
    (InstanceStruct_ofpynhcn5LFnvtv82bGDI *)calloc(1, sizeof
    (InstanceStruct_ofpynhcn5LFnvtv82bGDI));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_ofpynhcn5LFnvtv82bGDI);
  ssSetmdlInitializeConditions(S, mdlInitialize_ofpynhcn5LFnvtv82bGDI);
  ssSetmdlUpdate(S, mdlUpdate_ofpynhcn5LFnvtv82bGDI);
  ssSetmdlTerminate(S, mdlTerminate_ofpynhcn5LFnvtv82bGDI);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_ofpynhcn5LFnvtv82bGDI(SimStruct *S)
{
}

void method_dispatcher_ofpynhcn5LFnvtv82bGDI(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_ofpynhcn5LFnvtv82bGDI(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_ofpynhcn5LFnvtv82bGDI(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_ofpynhcn5LFnvtv82bGDI(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_ofpynhcn5LFnvtv82bGDI(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: ofpynhcn5LFnvtv82bGDI.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_ofpynhcn5LFnvtv82bGDI_BuildInfoUpdate(void)
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
