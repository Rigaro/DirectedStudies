/* Include files */

#include "modelInterface.h"
#include "m_ueo0WoZtTTZrQq4OwFcAGD.h"
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
static Finger_2 *Finger_Finger(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, Finger_2 *obj);
static real_T mpower(real_T a);
static Phalanx_3 *Phalanx_Phalanx(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, Phalanx_3 *obj, real_T k, real_T l, real_T r, real_T m,
  real_T theta, real_T linkNum);
static real_T norm(real_T x[4]);
static void warning(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance);
static void b_warning(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance,
                      char_T varargin_1[14]);
static void emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *c_sprintf, const char_T *identifier, char_T y
  [14]);
static void b_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, char_T
  y[14]);
static void cgxe_mdl_start(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance);
static const mxArray *emlrt_marshallOut(const Phalanx_3 *u);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance);
static void c_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b_sysobj, const char_T *identifier, Finger_2
  *y);
static void d_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Finger_2 *y);
static int32_T e_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static void f_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Phalanx_3 *y);
static real_T g_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static ForceNormal h_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2]);
static void j_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[4]);
static void k_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2]);
static boolean_T l_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier);
static boolean_T m_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static void mw__internal__setSimState__fcn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *st);
static void error(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location);
static const mxArray *message(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static const mxArray *feval(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static void b_feval(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance, const
                    mxArray *b, const mxArray *c, emlrtMCInfo *location);
static const mxArray *b_sprintf(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static const mxArray *c_feval(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b, const mxArray *c, const mxArray *d,
  emlrtMCInfo *location);
static void n_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, char_T
  ret[14]);
static int32_T o_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static real_T p_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static void q_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2]);
static void r_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[4]);
static void s_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2]);
static boolean_T t_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static void init_simulink_io_address(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance);

/* Function Definitions */
static Finger_2 *Finger_Finger(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, Finger_2 *obj)
{
  Finger_2 *b_obj;
  Finger_2 *c_obj;
  Phalanx_3 *d_obj;
  real_T A;
  real_T x;
  covrtLogFcn(moduleInstance->covInst, 0, 0);
  b_obj = obj;
  c_obj = b_obj;
  c_obj->isInitialized = 0;
  covrtLogIf(moduleInstance->covInst, 0, 0, 0, false);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 1);
  d_obj = &b_obj->prox;
  covrtLogFcn(moduleInstance->covInst, 1, 0);
  d_obj->k = 1.0;
  d_obj->l = 0.1;
  d_obj->r = 0.02;
  d_obj->m = 0.02;
  d_obj->miuC = 0.8;
  d_obj->miuE = 0.8;
  d_obj->theta = 0.31415926535897931;
  d_obj->a = 0.0;
  d_obj->b = 0.0;

  /*  Phalanx Class */
  /*  Represents the Phalanx of an underactuated Finger. */
  /*  Physical Phalanx properties */
  /*  Joint stiffness (Nm/rad) */
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
  covrtLogIf(moduleInstance->covInst, 1, 0, 0, false);
  covrtLogBasicBlock(moduleInstance->covInst, 1, 3);
  A = d_obj->m * mpower(d_obj->l);
  d_obj->I = A / 3.0;
  covrtLogBasicBlock(moduleInstance->covInst, 1, 4);
  d_obj->theta0 = d_obj->theta;
  A = d_obj->miuC;
  covrtLogFcn(moduleInstance->covInst, 2, 0);
  covrtLogBasicBlock(moduleInstance->covInst, 2, 0);
  d_obj->fc.fv[0] = 0.0;
  d_obj->fc.fv[1] = A * 0.0;
  A = d_obj->miuE;
  covrtLogFcn(moduleInstance->covInst, 2, 0);
  covrtLogBasicBlock(moduleInstance->covInst, 2, 0);
  d_obj->fe.fv[0] = 0.0;
  d_obj->fe.fv[1] = A * 0.0;
  Phalanx_Phalanx(moduleInstance, &b_obj->dist, 5.0, 0.1, 0.012, 0.02,
                  1.0471975511965976, 2.0);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 2);
  b_obj->K[0] = b_obj->prox.k;
  b_obj->K[2] = 0.0;
  b_obj->K[1] = 0.0;
  b_obj->K[3] = b_obj->dist.k;
  b_obj->Ja[0] = b_obj->prox.r;
  b_obj->Ja[1] = b_obj->dist.r;
  b_obj->fa = 0.0;
  c_obj = b_obj;
  covrtLogFcn(moduleInstance->covInst, 0, 5);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 7);
  A = c_obj->dist.theta;
  x = c_obj->dist.theta;
  c_obj->Jc[0] = c_obj->prox.a;
  c_obj->Jc[2] = 0.0;
  c_obj->Jc[1] = c_obj->dist.a + c_obj->prox.l * (muDoubleScalarCos(A) -
    c_obj->dist.miuC * muDoubleScalarSin(x));
  c_obj->Jc[3] = c_obj->dist.a;
  c_obj = b_obj;
  covrtLogFcn(moduleInstance->covInst, 0, 6);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 8);
  A = c_obj->dist.theta;
  x = c_obj->dist.theta;
  c_obj->Je[0] = c_obj->prox.b;
  c_obj->Je[2] = 0.0;
  c_obj->Je[1] = c_obj->dist.b + c_obj->prox.l * (muDoubleScalarCos(A) -
    c_obj->dist.miuE * muDoubleScalarSin(x));
  c_obj->Je[3] = c_obj->dist.b;
  return b_obj;
}

static real_T mpower(real_T a)
{
  return a * a;
}

static Phalanx_3 *Phalanx_Phalanx(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, Phalanx_3 *obj, real_T k, real_T l, real_T r, real_T m,
  real_T theta, real_T linkNum)
{
  Phalanx_3 *b_obj;
  real_T A;
  ForceNormal *c_obj;
  covrtLogFcn(moduleInstance->covInst, 1, 0);
  b_obj = obj;
  b_obj->k = 1.0;
  b_obj->l = 0.1;
  b_obj->r = 0.02;
  b_obj->m = 0.02;
  b_obj->miuC = 0.8;
  b_obj->miuE = 0.8;
  b_obj->theta = 0.31415926535897931;
  b_obj->a = 0.0;
  b_obj->b = 0.0;

  /*  Phalanx Class */
  /*  Represents the Phalanx of an underactuated Finger. */
  /*  Physical Phalanx properties */
  /*  Joint stiffness (Nm/rad) */
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

static void warning(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance)
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

static void b_warning(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance,
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

static void emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
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

static void b_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, char_T
  y[14])
{
  n_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void cgxe_mdl_start(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance)
{
  Finger_2 *obj;
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

  real_T x;
  real_T b_x;
  init_simulink_io_address(moduleInstance);

  /* Allocate instance data */
  covrtAllocateInstanceData(moduleInstance->covInst);

  /* Initialize Coverage Information */
  covrtScriptInit(moduleInstance->covInst,
                  "C:\\Users\\Ricardo\\Documents\\Workspace\\Directed Studies\\Simulation\\Finger.m",
                  0, 12, 14, 1, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(moduleInstance->covInst, 0, 10, "Finger_eom", 4456, -1, 5895);
  covrtFcnInit(moduleInstance->covInst, 0, 9, "Finger_getPoly", 4251, -1, 4447);
  covrtFcnInit(moduleInstance->covInst, 0, 8, "Finger_fKine", 3791, -1, 4242);
  covrtFcnInit(moduleInstance->covInst, 0, 7, "Finger_rotMat", 3624, -1, 3782);
  covrtFcnInit(moduleInstance->covInst, 0, 6, "Finger_updateJe", 3336, -1, 3615);
  covrtFcnInit(moduleInstance->covInst, 0, 5, "Finger_updateJc", 3030, -1, 3327);
  covrtFcnInit(moduleInstance->covInst, 0, 4, "Finger_setFa", 2928, -1, 3021);
  covrtFcnInit(moduleInstance->covInst, 0, 3, "Finger_setThetaADot", 2788, -1,
               2919);
  covrtFcnInit(moduleInstance->covInst, 0, 2, "Finger_setThetaA", 2673, -1, 2779);
  covrtFcnInit(moduleInstance->covInst, 0, 1, "Finger_setOrigin", 2556, -1, 2664);
  covrtFcnInit(moduleInstance->covInst, 0, 0, "Finger_Finger", 1547, -1, 2547);
  covrtFcnInit(moduleInstance->covInst, 0, 11, "Finger_stepImpl", 6705, -1, 8284);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(moduleInstance->covInst, 0, 12, 4501, -1, 5882);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 11, 4292, -1, 4434);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 10, 3873, -1, 4229);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 9, 3697, -1, 3769);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 8, 3413, -1, 3601);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 7, 3105, -1, 3293);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 6, 2997, -1, 3008);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 5, 2881, -1, 2906);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 4, 2747, -1, 2766);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 3, 2632, -1, 2651);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 2, 2178, -1, 2489);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 1, 2018, -1, 2099);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 0, 1811, -1, 1983);
  covrtBasicBlockInit(moduleInstance->covInst, 0, 13, 6865, -1, 8271);

  /* Initialize If Information */
  covrtIfInit(moduleInstance->covInst, 0, 0, 1779, 1794, 1997, 2116);

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
  covrtFcnInit(moduleInstance->covInst, 1, 0, "Phalanx_Phalanx", 1171, -1, 1892);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(moduleInstance->covInst, 1, 4, 1753, -1, 1879);
  covrtBasicBlockInit(moduleInstance->covInst, 1, 3, 1698, -1, 1723);
  covrtBasicBlockInit(moduleInstance->covInst, 1, 2, 1618, -1, 1643);
  covrtBasicBlockInit(moduleInstance->covInst, 1, 1, 1549, -1, 1575);
  covrtBasicBlockInit(moduleInstance->covInst, 1, 0, 1371, -1, 1496);

  /* Initialize If Information */
  covrtIfInit(moduleInstance->covInst, 1, 0, 1339, 1354, 1677, 1740);
  covrtIfInit(moduleInstance->covInst, 1, 1, 1514, 1528, 1593, 1664);

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
    Finger_Finger(moduleInstance, &moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
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
    error(moduleInstance, message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  obj->isInitialized = 1;
  Phalanx_Phalanx(moduleInstance, &obj->prox, 10.0, 0.1, 0.02, 0.02,
                  0.31415926535897931, 1.0);
  Phalanx_Phalanx(moduleInstance, &obj->dist, 50.0, 0.1, 0.012, 0.02,
                  1.0471975511965976, 2.0);
  obj->K[0] = obj->prox.k;
  obj->K[2] = 0.0;
  obj->K[1] = 0.0;
  obj->K[3] = obj->dist.k;
  obj->Ja[0] = obj->prox.r;
  obj->Ja[1] = obj->dist.r;
  obj->fa = 0.0;
  covrtLogFcn(moduleInstance->covInst, 0, 5);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 7);
  x = obj->dist.theta;
  b_x = obj->dist.theta;
  obj->Jc[0] = obj->prox.a;
  obj->Jc[2] = 0.0;
  obj->Jc[1] = obj->dist.a + obj->prox.l * (muDoubleScalarCos(x) -
    obj->dist.miuC * muDoubleScalarSin(b_x));
  obj->Jc[3] = obj->dist.a;
  covrtLogFcn(moduleInstance->covInst, 0, 6);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 8);
  x = obj->dist.theta;
  b_x = obj->dist.theta;
  obj->Je[0] = obj->prox.b;
  obj->Je[2] = 0.0;
  obj->Je[1] = obj->dist.b + obj->prox.l * (muDoubleScalarCos(x) -
    obj->dist.miuE * muDoubleScalarSin(b_x));
  obj->Je[3] = obj->dist.b;
}

static void cgxe_mdl_initialize(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance)
{
  Finger_2 *obj;
  int32_T i3;
  static char_T cv6[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv9[2] = { 1, 45 };

  const mxArray *m3;
  static char_T cv7[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv10[2] = { 1, 8 };

  boolean_T flag;
  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv11[2] = { 1, 45 };

  static char_T cv8[5] = { 'r', 'e', 's', 'e', 't' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv12[2] = { 1, 5 };

  if (!moduleInstance->sysobj_not_empty) {
    Finger_Finger(moduleInstance, &moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i3 = 0; i3 < 45; i3++) {
      u[i3] = cv6[i3];
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv9);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &u[0]);
    emlrtAssign(&y, m3);
    for (i3 = 0; i3 < 8; i3++) {
      b_u[i3] = cv7[i3];
    }

    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv10);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m3, &b_u[0]);
    emlrtAssign(&b_y, m3);
    error(moduleInstance, message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag && (moduleInstance->sysobj.isInitialized == 2)) {
    for (i3 = 0; i3 < 45; i3++) {
      c_u[i3] = cv6[i3];
    }

    c_y = NULL;
    m3 = emlrtCreateCharArray(2, iv11);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &c_u[0]);
    emlrtAssign(&c_y, m3);
    for (i3 = 0; i3 < 5; i3++) {
      d_u[i3] = cv8[i3];
    }

    d_y = NULL;
    m3 = emlrtCreateCharArray(2, iv12);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m3, &d_u[0]);
    emlrtAssign(&d_y, m3);
    error(moduleInstance, message(moduleInstance, c_y, d_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }
}

static void cgxe_mdl_outputs(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance)
{
  real_T varargin_1[4];
  int32_T i4;
  Finger_2 *obj;
  static char_T cv9[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv13[2] = { 1, 45 };

  const mxArray *m4;
  static char_T cv10[4] = { 's', 't', 'e', 'p' };

  char_T b_u[4];
  const mxArray *b_y;
  static const int32_T iv14[2] = { 1, 4 };

  static char_T cv11[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T c_u[51];
  const mxArray *c_y;
  static const int32_T iv15[2] = { 1, 51 };

  static char_T cv12[5] = { 's', 'e', 't', 'u', 'p' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv16[2] = { 1, 5 };

  real_T r;
  real_T t;
  real_T alpha;
  real_T beta;
  real_T delta;
  real_T rc;
  real_T M[4];
  real_T C[4];
  real_T a[4];
  real_T b_obj[2];
  real_T c_obj[2];
  real_T b[2];
  real_T b_b[2];
  real_T b_a[4];
  real_T c_a[4];
  real_T c_b[2];
  int32_T i5;
  real_T d_a[2];
  real_T thetaDot[2];
  real_T e_y[4];
  static char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  char_T e_u[6];
  const mxArray *f_y;
  static const int32_T iv17[2] = { 1, 6 };

  const mxArray *g_y;
  char_T str[14];
  real_T b_C[2];
  real_T e_a[2];
  real_T c_C[2];
  for (i4 = 0; i4 < 4; i4++) {
    varargin_1[i4] = (*moduleInstance->u0)[i4];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Finger_Finger(moduleInstance, &moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i4 = 0; i4 < 45; i4++) {
      u[i4] = cv9[i4];
    }

    y = NULL;
    m4 = emlrtCreateCharArray(2, iv13);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m4, &u[0]);
    emlrtAssign(&y, m4);
    for (i4 = 0; i4 < 4; i4++) {
      b_u[i4] = cv10[i4];
    }

    b_y = NULL;
    m4 = emlrtCreateCharArray(2, iv14);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 4, m4, &b_u[0]);
    emlrtAssign(&b_y, m4);
    error(moduleInstance, message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  if (obj->isInitialized != 1) {
    if (obj->isInitialized != 0) {
      for (i4 = 0; i4 < 51; i4++) {
        c_u[i4] = cv11[i4];
      }

      c_y = NULL;
      m4 = emlrtCreateCharArray(2, iv15);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m4, &c_u
        [0]);
      emlrtAssign(&c_y, m4);
      for (i4 = 0; i4 < 5; i4++) {
        d_u[i4] = cv12[i4];
      }

      d_y = NULL;
      m4 = emlrtCreateCharArray(2, iv16);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m4, &d_u[0]);
      emlrtAssign(&d_y, m4);
      error(moduleInstance, message(moduleInstance, c_y, d_y, &b_emlrtMCI),
            &b_emlrtMCI);
    }

    obj->isInitialized = 1;
    Phalanx_Phalanx(moduleInstance, &obj->prox, 10.0, 0.1, 0.02, 0.02,
                    0.31415926535897931, 1.0);
    Phalanx_Phalanx(moduleInstance, &obj->dist, 50.0, 0.1, 0.012, 0.02,
                    1.0471975511965976, 2.0);
    obj->K[0] = obj->prox.k;
    obj->K[2] = 0.0;
    obj->K[1] = 0.0;
    obj->K[3] = obj->dist.k;
    obj->Ja[0] = obj->prox.r;
    obj->Ja[1] = obj->dist.r;
    obj->fa = 0.0;
    covrtLogFcn(moduleInstance->covInst, 0, 5);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 7);
    r = obj->dist.theta;
    t = obj->dist.theta;
    obj->Jc[0] = obj->prox.a;
    obj->Jc[2] = 0.0;
    obj->Jc[1] = obj->dist.a + obj->prox.l * (muDoubleScalarCos(r) -
      obj->dist.miuC * muDoubleScalarSin(t));
    obj->Jc[3] = obj->dist.a;
    covrtLogFcn(moduleInstance->covInst, 0, 6);
    covrtLogBasicBlock(moduleInstance->covInst, 0, 8);
    r = obj->dist.theta;
    t = obj->dist.theta;
    obj->Je[0] = obj->prox.b;
    obj->Je[2] = 0.0;
    obj->Je[1] = obj->dist.b + obj->prox.l * (muDoubleScalarCos(r) -
      obj->dist.miuE * muDoubleScalarSin(t));
    obj->Je[3] = obj->dist.b;
  }

  covrtLogFcn(moduleInstance->covInst, 0, 11);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 13);

  /*  Implement tasks that need to be performed only once,  */
  /*  such as pre-computed constants. */
  /*  Physical properties initialization */
  /*  Kinematic values initialization */
  /*  Contact Kinematics */
  /*  Contact jacobian */
  /*  External forces */
  /*  Disturbance jacobian (only Distal contact) */
  /*  Implement algorithm. Calculate y as a function of */
  /*  input u and discrete states. */
  obj->fa = *moduleInstance->u1;
  obj->prox.theta = varargin_1[0];
  obj->dist.theta = varargin_1[1];
  obj->prox.thetaDot = varargin_1[2];
  obj->dist.thetaDot = varargin_1[3];
  covrtLogFcn(moduleInstance->covInst, 0, 5);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 7);
  r = obj->dist.theta;
  t = obj->dist.theta;
  obj->Jc[0] = obj->prox.a;
  obj->Jc[2] = 0.0;
  obj->Jc[1] = obj->dist.a + obj->prox.l * (muDoubleScalarCos(r) -
    obj->dist.miuC * muDoubleScalarSin(t));
  obj->Jc[3] = obj->dist.a;
  covrtLogFcn(moduleInstance->covInst, 0, 6);
  covrtLogBasicBlock(moduleInstance->covInst, 0, 8);
  r = obj->dist.theta;
  t = obj->dist.theta;
  obj->Je[0] = obj->prox.b;
  obj->Je[2] = 0.0;
  obj->Je[1] = obj->dist.b + obj->prox.l * (muDoubleScalarCos(r) -
    obj->dist.miuE * muDoubleScalarSin(t));
  obj->Je[3] = obj->dist.b;
  t = obj->prox.l;
  r = obj->dist.l;
  alpha = ((obj->prox.I + obj->dist.I) + obj->prox.m * mpower(t / 2.0)) +
    obj->dist.m * (mpower(obj->prox.l) + mpower(r / 2.0));
  t = obj->dist.m * obj->prox.l * obj->dist.l;
  beta = t / 2.0;
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
  for (i4 = 0; i4 < 4; i4++) {
    a[i4] = obj->K[i4];
  }

  b_obj[0] = obj->prox.theta;
  b_obj[1] = obj->dist.theta;
  c_obj[0] = obj->prox.theta0;
  c_obj[1] = obj->dist.theta0;
  b[0] = obj->prox.fc.fv[0];
  b[1] = obj->dist.fc.fv[0];
  b_b[0] = obj->prox.fe.fv[0];
  b_b[1] = obj->dist.fe.fv[0];
  for (i4 = 0; i4 < 2; i4++) {
    c_b[i4] = b_obj[i4] - c_obj[i4];
    for (i5 = 0; i5 < 2; i5++) {
      b_a[i5 + (i4 << 1)] = obj->Jc[i4 + (i5 << 1)];
      c_a[i5 + (i4 << 1)] = obj->Je[i4 + (i5 << 1)];
    }

    d_a[i4] = obj->Ja[i4];
  }

  alpha = obj->fa;
  thetaDot[0] = obj->prox.thetaDot;
  thetaDot[1] = obj->dist.thetaDot;
  if (muDoubleScalarAbs(M[1]) > muDoubleScalarAbs(M[0])) {
    r = M[0] / M[1];
    t = 1.0 / (r * delta - M[2]);
    e_y[0] = delta / M[1] * t;
    e_y[1] = -t;
    e_y[2] = -M[2] / M[1] * t;
    e_y[3] = r * t;
  } else {
    r = M[1] / M[0];
    t = 1.0 / (delta - r * M[2]);
    e_y[0] = delta / M[0] * t;
    e_y[1] = -r * t;
    e_y[2] = -M[2] / M[0] * t;
    e_y[3] = t;
  }

  r = norm(M);
  t = norm(e_y);
  rc = 1.0 / (r * t);
  if ((r == 0.0) || (t == 0.0) || (rc == 0.0)) {
    warning(moduleInstance);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      for (i4 = 0; i4 < 6; i4++) {
        e_u[i4] = rfmt[i4];
      }

      f_y = NULL;
      m4 = emlrtCreateCharArray(2, iv17);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 6, m4, &e_u[0]);
      emlrtAssign(&f_y, m4);
      g_y = NULL;
      m4 = emlrtCreateDoubleScalar(rc);
      emlrtAssign(&g_y, m4);
      emlrt_marshallIn(moduleInstance, b_sprintf(moduleInstance, f_y, g_y,
        &e_emlrtMCI), "sprintf", str);
      b_warning(moduleInstance, str);
    }
  }

  for (i4 = 0; i4 < 2; i4++) {
    for (i5 = 0; i5 < 2; i5++) {
      varargin_1[i5 + (i4 << 1)] = -C[i5 + (i4 << 1)];
    }
  }

  for (i4 = 0; i4 < 2; i4++) {
    b_obj[i4] = 0.0;
    c_obj[i4] = 0.0;
    r = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      r += b_a[i4 + (i5 << 1)] * b[i5];
      b_obj[i4] += varargin_1[i4 + (i5 << 1)] * thetaDot[i5];
      c_obj[i4] += a[i4 + (i5 << 1)] * c_b[i5];
    }

    b_C[i4] = (b_obj[i4] + c_obj[i4]) + r;
    e_a[i4] = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      e_a[i4] += c_a[i4 + (i5 << 1)] * b_b[i5];
    }

    c_C[i4] = (b_C[i4] + e_a[i4]) + d_a[i4] * alpha;
  }

  for (i4 = 0; i4 < 2; i4++) {
    b_obj[i4] = 0.0;
    for (i5 = 0; i5 < 2; i5++) {
      b_obj[i4] += e_y[i4 + (i5 << 1)] * c_C[i5];
    }

    varargin_1[i4] = thetaDot[i4];
    varargin_1[i4 + 2] = b_obj[i4];
  }

  for (i4 = 0; i4 < 4; i4++) {
    (*moduleInstance->b_y0)[i4] = varargin_1[i4];
  }
}

static void cgxe_mdl_update(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance)
{
  Finger_2 *obj;
  int32_T i6;
  static char_T cv13[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv18[2] = { 1, 45 };

  const mxArray *m5;
  static char_T cv14[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv19[2] = { 1, 8 };

  boolean_T flag;
  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv20[2] = { 1, 45 };

  static char_T cv15[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  char_T d_u[7];
  const mxArray *d_y;
  static const int32_T iv21[2] = { 1, 7 };

  if (!moduleInstance->sysobj_not_empty) {
    Finger_Finger(moduleInstance, &moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i6 = 0; i6 < 45; i6++) {
      u[i6] = cv13[i6];
    }

    y = NULL;
    m5 = emlrtCreateCharArray(2, iv18);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m5, &u[0]);
    emlrtAssign(&y, m5);
    for (i6 = 0; i6 < 8; i6++) {
      b_u[i6] = cv14[i6];
    }

    b_y = NULL;
    m5 = emlrtCreateCharArray(2, iv19);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m5, &b_u[0]);
    emlrtAssign(&b_y, m5);
    error(moduleInstance, message(moduleInstance, y, b_y, &b_emlrtMCI),
          &b_emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i6 = 0; i6 < 45; i6++) {
        c_u[i6] = cv13[i6];
      }

      c_y = NULL;
      m5 = emlrtCreateCharArray(2, iv20);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m5, &c_u
        [0]);
      emlrtAssign(&c_y, m5);
      for (i6 = 0; i6 < 7; i6++) {
        d_u[i6] = cv15[i6];
      }

      d_y = NULL;
      m5 = emlrtCreateCharArray(2, iv21);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 7, m5, &d_u[0]);
      emlrtAssign(&d_y, m5);
      error(moduleInstance, message(moduleInstance, c_y, d_y, &b_emlrtMCI),
            &b_emlrtMCI);
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
  static const int32_T iv22[1] = { 2 };

  real_T *pData;
  int32_T i;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  static const int32_T iv23[1] = { 2 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->k);
  emlrtAssign(&b_y, m6);
  emlrtAddField(y, b_y, "k", 0);
  c_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->l);
  emlrtAssign(&c_y, m6);
  emlrtAddField(y, c_y, "l", 0);
  d_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->r);
  emlrtAssign(&d_y, m6);
  emlrtAddField(y, d_y, "r", 0);
  e_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->m);
  emlrtAssign(&e_y, m6);
  emlrtAddField(y, e_y, "m", 0);
  f_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->I);
  emlrtAssign(&f_y, m6);
  emlrtAddField(y, f_y, "I", 0);
  g_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->miuC);
  emlrtAssign(&g_y, m6);
  emlrtAddField(y, g_y, "miuC", 0);
  h_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->miuE);
  emlrtAssign(&h_y, m6);
  emlrtAddField(y, h_y, "miuE", 0);
  i_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->theta0);
  emlrtAssign(&i_y, m6);
  emlrtAddField(y, i_y, "theta0", 0);
  j_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->theta);
  emlrtAssign(&j_y, m6);
  emlrtAddField(y, j_y, "theta", 0);
  k_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->thetaDot);
  emlrtAssign(&k_y, m6);
  emlrtAddField(y, k_y, "thetaDot", 0);
  l_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->a);
  emlrtAssign(&l_y, m6);
  emlrtAddField(y, l_y, "a", 0);
  m_y = NULL;
  emlrtAssign(&m_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  n_y = NULL;
  m6 = emlrtCreateNumericArray(1, iv22, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 2; i++) {
    pData[i] = u->fc.fv[i];
  }

  emlrtAssign(&n_y, m6);
  emlrtAddField(m_y, n_y, "fv", 0);
  emlrtAddField(y, m_y, "fc", 0);
  o_y = NULL;
  m6 = emlrtCreateDoubleScalar(u->b);
  emlrtAssign(&o_y, m6);
  emlrtAddField(y, o_y, "b", 0);
  p_y = NULL;
  emlrtAssign(&p_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  q_y = NULL;
  m6 = emlrtCreateNumericArray(1, iv23, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 2; i++) {
    pData[i] = u->fe.fv[i];
  }

  emlrtAssign(&q_y, m6);
  emlrtAddField(p_y, q_y, "fv", 0);
  emlrtAddField(y, p_y, "fe", 0);
  return y;
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance)
{
  const mxArray *st;
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m7;
  const mxArray *d_y;
  static const int32_T iv24[2] = { 2, 2 };

  real_T *pData;
  int32_T i;
  const mxArray *e_y;
  static const int32_T iv25[2] = { 1, 2 };

  const mxArray *f_y;
  const mxArray *g_y;
  static const int32_T iv26[2] = { 2, 2 };

  const mxArray *h_y;
  static const int32_T iv27[2] = { 2, 2 };

  const mxArray *i_y;
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
  emlrtAddField(b_y, emlrt_marshallOut(&moduleInstance->sysobj.prox), "prox", 0);
  emlrtAddField(b_y, emlrt_marshallOut(&moduleInstance->sysobj.dist), "dist", 0);
  d_y = NULL;
  m7 = emlrtCreateNumericArray(2, iv24, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m7);
  for (i = 0; i < 4; i++) {
    pData[i] = moduleInstance->sysobj.K[i];
  }

  emlrtAssign(&d_y, m7);
  emlrtAddField(b_y, d_y, "K", 0);
  e_y = NULL;
  m7 = emlrtCreateNumericArray(2, iv25, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m7);
  for (i = 0; i < 2; i++) {
    pData[i] = moduleInstance->sysobj.Ja[i];
  }

  emlrtAssign(&e_y, m7);
  emlrtAddField(b_y, e_y, "Ja", 0);
  f_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.fa);
  emlrtAssign(&f_y, m7);
  emlrtAddField(b_y, f_y, "fa", 0);
  g_y = NULL;
  m7 = emlrtCreateNumericArray(2, iv26, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m7);
  for (i = 0; i < 4; i++) {
    pData[i] = moduleInstance->sysobj.Jc[i];
  }

  emlrtAssign(&g_y, m7);
  emlrtAddField(b_y, g_y, "Jc", 0);
  h_y = NULL;
  m7 = emlrtCreateNumericArray(2, iv27, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m7);
  for (i = 0; i < 4; i++) {
    pData[i] = moduleInstance->sysobj.Je[i];
  }

  emlrtAssign(&h_y, m7);
  emlrtAddField(b_y, h_y, "Je", 0);
  emlrtSetCell(y, 0, b_y);
  i_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&i_y, m7);
  emlrtSetCell(y, 1, i_y);
  emlrtAssign(&st, y);
  return st;
}

static void c_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b_sysobj, const char_T *identifier, Finger_2
  *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(moduleInstance, emlrtAlias(b_sysobj), &thisId, y);
  emlrtDestroyArray(&b_sysobj);
}

static void d_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Finger_2 *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[8] = { "isInitialized", "prox", "dist", "K",
    "Ja", "fa", "Jc", "Je" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(moduleInstance->emlrtRootTLSGlobal, parentId, u, 8,
    fieldNames, 0U, &dims);
  thisId.fIdentifier = "isInitialized";
  y->isInitialized = e_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetFieldR2013a(moduleInstance->emlrtRootTLSGlobal, u, 0,
    "isInitialized")), &thisId);
  thisId.fIdentifier = "prox";
  f_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "prox")), &thisId, &y->prox);
  thisId.fIdentifier = "dist";
  f_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "dist")), &thisId, &y->dist);
  thisId.fIdentifier = "K";
  j_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "K")), &thisId, y->K);
  thisId.fIdentifier = "Ja";
  k_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Ja")), &thisId, y->Ja);
  thisId.fIdentifier = "fa";
  y->fa = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "fa")), &thisId);
  thisId.fIdentifier = "Jc";
  j_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Jc")), &thisId, y->Jc);
  thisId.fIdentifier = "Je";
  j_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "Je")), &thisId, y->Je);
  emlrtDestroyArray(&u);
}

static int32_T e_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = o_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void f_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  Phalanx_3 *y)
{
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[14] = { "k", "l", "r", "m", "I", "miuC", "miuE",
    "theta0", "theta", "thetaDot", "a", "fc", "b", "fe" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(moduleInstance->emlrtRootTLSGlobal, parentId, u, 14,
    fieldNames, 0U, &dims);
  thisId.fIdentifier = "k";
  y->k = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "k")), &thisId);
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
  y->fc = h_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "fc")), &thisId);
  thisId.fIdentifier = "b";
  y->b = g_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "b")), &thisId);
  thisId.fIdentifier = "fe";
  y->fe = h_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "fe")), &thisId);
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = p_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static ForceNormal h_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
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
  i_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetFieldR2013a
    (moduleInstance->emlrtRootTLSGlobal, u, 0, "fv")), &thisId, y.fv);
  emlrtDestroyArray(&u);
  return y;
}

static void i_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2])
{
  q_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[4])
{
  r_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId, real_T
  y[2])
{
  s_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T l_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = m_emlrt_marshallIn(moduleInstance, emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static boolean_T m_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = t_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *st)
{
  const mxArray *u;
  u = emlrtAlias(st);
  c_emlrt_marshallIn(moduleInstance, emlrtAlias(emlrtGetCell
    (moduleInstance->emlrtRootTLSGlobal, "sysobj", u, 0)), "sysobj",
                     &moduleInstance->sysobj);
  moduleInstance->sysobj_not_empty = l_emlrt_marshallIn(moduleInstance,
    emlrtAlias(emlrtGetCell(moduleInstance->emlrtRootTLSGlobal,
    "sysobj_not_empty", u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static void error(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 0, NULL, 1, &pArray,
                        "error", true, location);
}

static const mxArray *message(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m8, 2,
    pArrays, "message", true, location);
}

static const mxArray *feval(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m9, 2,
    pArrays, "feval", true, location);
}

static void b_feval(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance, const
                    mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 0, NULL, 2, pArrays,
                        "feval", true, location);
}

static const mxArray *b_sprintf(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m10;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m10, 2,
    pArrays, "sprintf", true, location);
}

static const mxArray *c_feval(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *b, const mxArray *c, const mxArray *d,
  emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m11;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m11, 3,
    pArrays, "feval", true, location);
}

static void n_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, char_T
  ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src, "char",
    false, 2U, dims);
  emlrtImportCharArrayR2015b(moduleInstance->emlrtRootTLSGlobal, src, ret, 14);
  emlrtDestroyArray(&src);
}

static int32_T o_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
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

static real_T p_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
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

static void q_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
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

static void r_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[4])
{
  static const int32_T dims[2] = { 2, 2 };

  int32_T i8;
  int32_T i9;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "double", false, 2U, dims);
  for (i8 = 0; i8 < 2; i8++) {
    for (i9 = 0; i9 < 2; i9++) {
      ret[i9 + (i8 << 1)] = (*(real_T (*)[4])mxGetData(src))[i9 + (i8 << 1)];
    }
  }

  emlrtDestroyArray(&src);
}

static void s_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId, real_T
  ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  int32_T i10;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "double", false, 2U, dims);
  for (i10 = 0; i10 < 2; i10++) {
    ret[i10] = (*(real_T (*)[2])mxGetData(src))[i10];
  }

  emlrtDestroyArray(&src);
}

static boolean_T t_emlrt_marshallIn(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
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

static void init_simulink_io_address(InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = cgxertGetEMLRTCtx(moduleInstance->S, 0);
  moduleInstance->covInst = (covrtInstance *)cgxertGetCovrtInstance
    (moduleInstance->S, 0);
  moduleInstance->u0 = (real_T (*)[4])cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->b_y0 = (real_T (*)[4])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S, int_T tid)
{
  InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance =
    (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S)
{
  InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance =
    (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S, int_T tid)
{
  InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance =
    (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static mxArray* getSimState_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance =
    (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  return mxSS;
}

static void setSimState_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance =
    (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *)cgxertGetRuntimeInstance(S);
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S)
{
  InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance =
    (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlStart_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S)
{
  InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *moduleInstance =
    (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD *)calloc(1, sizeof
    (InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_ueo0WoZtTTZrQq4OwFcAGD);
  ssSetmdlInitializeConditions(S, mdlInitialize_ueo0WoZtTTZrQq4OwFcAGD);
  ssSetmdlUpdate(S, mdlUpdate_ueo0WoZtTTZrQq4OwFcAGD);
  ssSetmdlTerminate(S, mdlTerminate_ueo0WoZtTTZrQq4OwFcAGD);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S)
{
}

void method_dispatcher_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_ueo0WoZtTTZrQq4OwFcAGD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_ueo0WoZtTTZrQq4OwFcAGD(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_ueo0WoZtTTZrQq4OwFcAGD(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_ueo0WoZtTTZrQq4OwFcAGD(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: ueo0WoZtTTZrQq4OwFcAGD.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_ueo0WoZtTTZrQq4OwFcAGD_BuildInfoUpdate(void)
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
