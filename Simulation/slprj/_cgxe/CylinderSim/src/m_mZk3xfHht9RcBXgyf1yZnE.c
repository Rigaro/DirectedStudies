/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CylinderSim_cgxe.h"
#include "m_mZk3xfHht9RcBXgyf1yZnE.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 1, 1, "SystemCore",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"
};

/* Function Declarations */
static Cylinder *Cylinder_Cylinder(Cylinder *obj);
static void SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void b_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void c_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void d_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void e_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void f_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void g_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void h_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void i_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void j_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void k_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void l_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void m_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void n_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static void o_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj);
static boolean_T isequal(real_T varargin_1, real_T varargin_2);
static void cgxe_mdl_start(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance);
static const mxArray *mw__internal__name__resolution__fcn(void);
static void info_helper(const mxArray **info);
static const mxArray *emlrt_marshallOut(const char * u);
static const mxArray *b_emlrt_marshallOut(const uint32_T u);
static void b_info_helper(const mxArray **info);
static const mxArray *mw__internal__autoInference__fcn(void);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance);
static void emlrt_marshallIn(const mxArray *b_sysobj, const char_T *identifier,
  Cylinder *y);
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, Cylinder *y);
static boolean_T c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void e_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[2]);
static boolean_T f_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier);
static void mw__internal__setSimState__fcn(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance, const mxArray *st);
static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location);
static void error(const mxArray *b, emlrtMCInfo *location);
static boolean_T g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static real_T h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[2]);

/* Function Definitions */
static Cylinder *Cylinder_Cylinder(Cylinder *obj)
{
  Cylinder *b_obj;
  Cylinder *c_obj;
  boolean_T flag;
  real_T a;
  int32_T i0;
  b_obj = obj;
  c_obj = b_obj;
  c_obj->isInitialized = false;
  c_obj->isReleased = false;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->R = 0.02;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->M = 0.003;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->g = 9.81;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Us = 0.5;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Uk = 0.48;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  a = b_obj->R;
  a = b_obj->M * (a * a);
  b_obj->Iz = a / 2.0;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->F_s_x = b_obj->M * b_obj->g * b_obj->Us;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->F_s_y = b_obj->M * b_obj->g * b_obj->Us;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->F_k_x = b_obj->M * b_obj->g * b_obj->Uk;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->F_k_y = b_obj->M * b_obj->g * b_obj->Uk;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->T_s = 0.66666666666666663 * b_obj->Us * b_obj->R * b_obj->M * b_obj->g;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->T_k = 0.66666666666666663 * b_obj->Uk * b_obj->R * b_obj->M * b_obj->g;
  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  for (i0 = 0; i0 < 2; i0++) {
    b_obj->Position_o_G3[i0] = 0.0;
  }

  c_obj = b_obj;
  if (c_obj->isInitialized && !c_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    c_obj->TunablePropsChanged = true;
  }

  b_obj->Position_G3_P3_frame_cylinder[0] = 0.0;
  b_obj->Position_G3_P3_frame_cylinder[1] = b_obj->R;
  return b_obj;
}

static void SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void b_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void c_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void d_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void e_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void f_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void g_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void h_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void i_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void j_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void k_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void l_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void m_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void n_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void o_SystemProp_matlabCodegenNotifyAnyProp(Cylinder *obj)
{
  Cylinder *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
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

static void cgxe_mdl_start(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance)
{
  real_T varargin_13[2];
  real_T varargin_14[2];
  int32_T i1;
  boolean_T flag;
  Cylinder *obj;
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 51 };

  const mxArray *m0;
  char_T cv0[51];
  static char_T cv1[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 5 };

  char_T cv2[5];
  static char_T cv3[5] = { 's', 'e', 't', 'u', 'p' };

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
  Position_G3_P3_frame_cylinder = (real_T (*)[2])(ssGetRunTimeParamInfo
    (moduleInstance->S, 13U))->data;
  Position_o_G3 = (real_T (*)[2])(ssGetRunTimeParamInfo(moduleInstance->S, 12U)
    )->data;
  T_k = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  T_s = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  F_k_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  F_k_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  F_s_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  F_s_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  Iz = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  Uk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  Us = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  g = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  M = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  R = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  for (i1 = 0; i1 < 2; i1++) {
    varargin_13[i1] = (*Position_o_G3)[i1];
    varargin_14[i1] = (*Position_G3_P3_frame_cylinder)[i1];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Cylinder_Cylinder(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i1 = 0; i1 < 2; i1++) {
      moduleInstance->sysobj.Position_o_G3[i1] = varargin_13[i1];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i1 = 0; i1 < 2; i1++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i1] = varargin_14[i1];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    for (i1 = 0; i1 < 51; i1++) {
      cv0[i1] = cv1[i1];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m0, cv0);
    emlrtAssign(&y, m0);
    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    for (i1 = 0; i1 < 5; i1++) {
      cv2[i1] = cv3[i1];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m0, cv2);
    emlrtAssign(&b_y, m0);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  obj->isInitialized = true;
  obj->TunablePropsChanged = false;
}

static void cgxe_mdl_initialize(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance)
{
  real_T varargin_13[2];
  real_T varargin_14[2];
  int32_T i2;
  boolean_T flag;
  Cylinder *obj;
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 45 };

  const mxArray *m1;
  char_T cv4[45];
  static char_T cv5[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 8 };

  char_T cv6[8];
  static char_T cv7[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  const mxArray *c_y;
  static const int32_T iv4[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv5[2] = { 1, 5 };

  char_T cv8[5];
  static char_T cv9[5] = { 'r', 'e', 's', 'e', 't' };

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
  Position_G3_P3_frame_cylinder = (real_T (*)[2])(ssGetRunTimeParamInfo
    (moduleInstance->S, 13U))->data;
  Position_o_G3 = (real_T (*)[2])(ssGetRunTimeParamInfo(moduleInstance->S, 12U)
    )->data;
  T_k = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  T_s = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  F_k_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  F_k_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  F_s_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  F_s_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  Iz = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  Uk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  Us = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  g = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  M = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  R = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  for (i2 = 0; i2 < 2; i2++) {
    varargin_13[i2] = (*Position_o_G3)[i2];
    varargin_14[i2] = (*Position_G3_P3_frame_cylinder)[i2];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Cylinder_Cylinder(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i2 = 0; i2 < 2; i2++) {
      moduleInstance->sysobj.Position_o_G3[i2] = varargin_13[i2];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i2 = 0; i2 < 2; i2++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i2] = varargin_14[i2];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isReleased) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    for (i2 = 0; i2 < 45; i2++) {
      cv4[i2] = cv5[i2];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, cv4);
    emlrtAssign(&y, m1);
    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    for (i2 = 0; i2 < 8; i2++) {
      cv6[i2] = cv7[i2];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m1, cv6);
    emlrtAssign(&b_y, m1);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = obj->isInitialized;
  if (flag && moduleInstance->sysobj.isReleased) {
    c_y = NULL;
    m1 = emlrtCreateCharArray(2, iv4);
    for (i2 = 0; i2 < 45; i2++) {
      cv4[i2] = cv5[i2];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, cv4);
    emlrtAssign(&c_y, m1);
    d_y = NULL;
    m1 = emlrtCreateCharArray(2, iv5);
    for (i2 = 0; i2 < 5; i2++) {
      cv8[i2] = cv9[i2];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m1, cv8);
    emlrtAssign(&d_y, m1);
    error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
  }
}

static void cgxe_mdl_outputs(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance)
{
  real_T Acceleration_o_P3_frame_0[2];
  real_T varargin_14[2];
  int32_T k;
  real_T ForceEvaluation;
  boolean_T p;
  boolean_T b_p;
  real_T hoistedGlobal_Position_o_G3[2];
  boolean_T exitg2;
  boolean_T exitg1;
  Cylinder *obj;
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 45 };

  const mxArray *m2;
  char_T cv10[45];
  static char_T cv11[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv7[2] = { 1, 4 };

  char_T cv12[4];
  static char_T cv13[4] = { 's', 't', 'e', 'p' };

  const mxArray *c_y;
  static const int32_T iv8[2] = { 1, 51 };

  char_T cv14[51];
  static char_T cv15[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *d_y;
  static const int32_T iv9[2] = { 1, 5 };

  char_T cv16[5];
  static char_T cv17[5] = { 's', 'e', 't', 'u', 'p' };

  real_T GenCordExt[3];
  real_T SignOposite[3];
  int32_T i3;
  real_T B;
  real_T GeneralCoordinatesDoubleDot_idx_0;
  int32_T i4;
  real_T GeneralCoordinatesDoubleDot_idx_1;
  int32_T i5;
  real_T Accelerations[4];
  real_T varargin_22[2];
  int32_T i6;
  real_T Positions[4];
  real_T GeneralCoordinatesDoubleDot[2];
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
  real_T *u0;
  real_T *u1;
  real_T *u2;
  real_T *u4;
  real_T *u7;
  real_T *u8;
  real_T *u3;
  real_T (*b_y0)[6];
  real_T (*Position_o_G3)[2];
  real_T (*Position_G3_P3_frame_cylinder)[2];
  Position_G3_P3_frame_cylinder = (real_T (*)[2])(ssGetRunTimeParamInfo
    (moduleInstance->S, 13U))->data;
  Position_o_G3 = (real_T (*)[2])(ssGetRunTimeParamInfo(moduleInstance->S, 12U)
    )->data;
  T_k = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  T_s = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  F_k_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  F_k_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  F_s_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  F_s_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  Iz = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  Uk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  Us = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  g = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  M = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  R = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  b_y0 = (real_T (*)[6])ssGetOutputPortSignal(moduleInstance->S, 0U);
  u8 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 8U);
  u7 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 7U);
  u4 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 4U);
  u3 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 3U);
  u2 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 2U);
  u1 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 1U);
  u0 = (real_T *)ssGetInputPortSignal(moduleInstance->S, 0U);
  for (k = 0; k < 2; k++) {
    Acceleration_o_P3_frame_0[k] = (*Position_o_G3)[k];
    varargin_14[k] = (*Position_G3_P3_frame_cylinder)[k];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Cylinder_Cylinder(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    b_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.R = *R;
    c_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.M = *M;
    d_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.g = *g;
    e_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.Us = *Us;
    f_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.Uk = *Uk;
    g_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.Iz = *Iz;
    h_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.F_s_x = *F_s_x;
    i_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.F_s_y = *F_s_y;
    j_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.F_k_x = *F_k_x;
    k_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.F_k_y = *F_k_y;
    l_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.T_s = *T_s;
    m_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.T_k = *T_k;
    n_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_o_G3[k] = Acceleration_o_P3_frame_0[k];
    }

    o_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k] = varargin_14[k];
    }
  }

  if (!isequal(moduleInstance->sysobj.R, *R)) {
    b_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
  }

  for (k = 0; k < 2; k++) {
    hoistedGlobal_Position_o_G3[k] = moduleInstance->sysobj.Position_o_G3[k];
  }

  p = false;
  b_p = true;
  k = 0;
  exitg2 = false;
  while (exitg2 == false && k < 2) {
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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

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
  while (exitg1 == false && k < 2) {
    if (!(hoistedGlobal_Position_o_G3[k] == varargin_14[k])) {
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
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 2; k++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[k] = varargin_14[k];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isReleased) {
    y = NULL;
    m2 = emlrtCreateCharArray(2, iv6);
    for (k = 0; k < 45; k++) {
      cv10[k] = cv11[k];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m2, cv10);
    emlrtAssign(&y, m2);
    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv7);
    for (k = 0; k < 4; k++) {
      cv12[k] = cv13[k];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 4, m2, cv12);
    emlrtAssign(&b_y, m2);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  if (!obj->isInitialized) {
    if (obj->isInitialized) {
      c_y = NULL;
      m2 = emlrtCreateCharArray(2, iv8);
      for (k = 0; k < 51; k++) {
        cv14[k] = cv15[k];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m2, cv14);
      emlrtAssign(&c_y, m2);
      d_y = NULL;
      m2 = emlrtCreateCharArray(2, iv9);
      for (k = 0; k < 5; k++) {
        cv16[k] = cv17[k];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m2, cv16);
      emlrtAssign(&d_y, m2);
      error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
    }

    obj->isInitialized = true;
    obj->TunablePropsChanged = false;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
  }

  /* ............................................................................ */
  /* ............................................................................ */
  /* Function that is called in Simulink to calculate updated */
  /* positions,velocities and accelerations for the cylinder */
  GenCordExt[0] = *u0;
  GenCordExt[1] = *u1;
  GenCordExt[2] = *u2;
  for (k = 0; k < 3; k++) {
    SignOposite[k] = -muDoubleScalarSign(GenCordExt[k]);
  }

  ForceEvaluation = obj->F_s_x;
  if (muDoubleScalarAbs(*u0) <= ForceEvaluation) {
    i3 = 0;
  } else {
    i3 = 1;
  }

  if (i3 == 1) {
    ForceEvaluation = *u0 + SignOposite[0] * obj->F_k_x;
    B = obj->M;
    GeneralCoordinatesDoubleDot_idx_0 = ForceEvaluation / B;
  } else {
    GeneralCoordinatesDoubleDot_idx_0 = 0.0;
  }

  ForceEvaluation = obj->F_s_y;
  if (muDoubleScalarAbs(*u1) <= ForceEvaluation) {
    i4 = 0;
  } else {
    i4 = 1;
  }

  if (i4 == 1) {
    ForceEvaluation = *u1 + SignOposite[1] * obj->F_k_y;
    B = obj->M;
    GeneralCoordinatesDoubleDot_idx_1 = ForceEvaluation / B;
  } else {
    GeneralCoordinatesDoubleDot_idx_1 = 0.0;
  }

  ForceEvaluation = obj->T_s;
  if (muDoubleScalarAbs(*u2) <= ForceEvaluation) {
    i5 = 0;
  } else {
    i5 = 1;
  }

  if (i5 == 1) {
    ForceEvaluation = *u2 + SignOposite[2] * obj->T_k;
    B = obj->Iz;
    ForceEvaluation /= B;
  } else {
    ForceEvaluation = 0.0;
  }

  for (k = 0; k < 2; k++) {
    Acceleration_o_P3_frame_0[k] = obj->Position_G3_P3_frame_cylinder[k];
  }

  Accelerations[0] = muDoubleScalarCos(*u4);
  Accelerations[2] = -muDoubleScalarSin(*u4);
  Accelerations[1] = muDoubleScalarSin(*u4);
  Accelerations[3] = muDoubleScalarCos(*u4);
  varargin_22[0] = *u7;
  varargin_22[1] = *u8;
  for (k = 0; k < 2; k++) {
    hoistedGlobal_Position_o_G3[k] = 0.0;
    for (i6 = 0; i6 < 2; i6++) {
      hoistedGlobal_Position_o_G3[k] += Accelerations[k + (i6 << 1)] *
        Acceleration_o_P3_frame_0[i6];
    }
  }

  for (k = 0; k < 2; k++) {
    Positions[k] = obj->Position_o_G3[k];
  }

  for (k = 0; k < 2; k++) {
    Positions[2 + k] = varargin_22[k] + hoistedGlobal_Position_o_G3[k];
  }

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
  Acceleration_o_P3_frame_0[0] = GeneralCoordinatesDoubleDot_idx_0 + obj->R *
    muDoubleScalarSin(*u4) * (*u3 * *u3) - obj->R * muDoubleScalarCos(*u4) *
    ForceEvaluation;
  Acceleration_o_P3_frame_0[1] = GeneralCoordinatesDoubleDot_idx_1 - obj->R *
    muDoubleScalarCos(*u4) * (*u3 * *u3) - obj->R * muDoubleScalarSin(*u4) *
    ForceEvaluation;
  GeneralCoordinatesDoubleDot[0] = GeneralCoordinatesDoubleDot_idx_0;
  GeneralCoordinatesDoubleDot[1] = GeneralCoordinatesDoubleDot_idx_1;
  for (k = 0; k < 2; k++) {
    Accelerations[k] = GeneralCoordinatesDoubleDot[k];
    Accelerations[2 + k] = Acceleration_o_P3_frame_0[k];
  }

  (*b_y0)[0] = Accelerations[0];
  (*b_y0)[1] = Accelerations[1];
  (*b_y0)[2] = ForceEvaluation;
  (*b_y0)[3] = obj->R;
  (*b_y0)[4] = Positions[2];
  (*b_y0)[5] = Positions[3];
}

static void cgxe_mdl_update(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance)
{
  real_T varargin_13[2];
  real_T varargin_14[2];
  int32_T i7;
  boolean_T flag;
  Cylinder *obj;
  const mxArray *y;
  static const int32_T iv10[2] = { 1, 45 };

  const mxArray *m3;
  char_T cv18[45];
  static char_T cv19[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv11[2] = { 1, 8 };

  char_T cv20[8];
  static char_T cv21[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  const mxArray *c_y;
  static const int32_T iv12[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv13[2] = { 1, 7 };

  char_T cv22[7];
  static char_T cv23[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

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
  Position_G3_P3_frame_cylinder = (real_T (*)[2])(ssGetRunTimeParamInfo
    (moduleInstance->S, 13U))->data;
  Position_o_G3 = (real_T (*)[2])(ssGetRunTimeParamInfo(moduleInstance->S, 12U)
    )->data;
  T_k = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  T_s = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  F_k_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  F_k_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  F_s_y = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  F_s_x = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  Iz = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  Uk = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  Us = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  g = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  M = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  R = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  for (i7 = 0; i7 < 2; i7++) {
    varargin_13[i7] = (*Position_o_G3)[i7];
    varargin_14[i7] = (*Position_G3_P3_frame_cylinder)[i7];
  }

  if (!moduleInstance->sysobj_not_empty) {
    Cylinder_Cylinder(&moduleInstance->sysobj);
    moduleInstance->sysobj_not_empty = true;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.R = *R;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.M = *M;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.g = *g;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Us = *Us;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Uk = *Uk;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.Iz = *Iz;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_x = *F_s_x;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_s_y = *F_s_y;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_x = *F_k_x;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.F_k_y = *F_k_y;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_s = *T_s;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.T_k = *T_k;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i7 = 0; i7 < 2; i7++) {
      moduleInstance->sysobj.Position_o_G3[i7] = varargin_13[i7];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i7 = 0; i7 < 2; i7++) {
      moduleInstance->sysobj.Position_G3_P3_frame_cylinder[i7] = varargin_14[i7];
    }
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isReleased) {
    y = NULL;
    m3 = emlrtCreateCharArray(2, iv10);
    for (i7 = 0; i7 < 45; i7++) {
      cv18[i7] = cv19[i7];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m3, cv18);
    emlrtAssign(&y, m3);
    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv11);
    for (i7 = 0; i7 < 8; i7++) {
      cv20[i7] = cv21[i7];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m3, cv20);
    emlrtAssign(&b_y, m3);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = obj->isInitialized;
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isReleased) {
      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv12);
      for (i7 = 0; i7 < 45; i7++) {
        cv18[i7] = cv19[i7];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m3, cv18);
      emlrtAssign(&c_y, m3);
      d_y = NULL;
      m3 = emlrtCreateCharArray(2, iv13);
      for (i7 = 0; i7 < 7; i7++) {
        cv22[i7] = cv23[i7];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 7, m3, cv22);
      emlrtAssign(&d_y, m3);
      error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
    }

    if (obj->isInitialized) {
      obj->isReleased = true;
    }
  }
}

static const mxArray *mw__internal__name__resolution__fcn(void)
{
  const mxArray *nameCaptureInfo;
  nameCaptureInfo = NULL;
  emlrtAssign(&nameCaptureInfo, emlrtCreateStructMatrix(86, 1, 0, NULL));
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
  emlrtAddField(*info, b_emlrt_marshallOut(1372553614U), "fileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 1);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 1);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(1389681774U), "fileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 2);
  emlrtAddField(*info, emlrt_marshallOut("eml_assert_valid_size_arg"), "name", 2);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "resolved", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(1368154230U), "fileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 3);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 3);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                "context", 4);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 4);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(1363677856U), "fileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context", 5);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 5);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 6);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_integer_class"), "name", 6);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                "resolved", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(1286786382U), "fileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 7);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 7);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(1362225882U), "fileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context", 8);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 8);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(1393294858U), "fileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 9);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 9);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(1362225882U), "fileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context", 10);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 10);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(1393294858U), "fileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 11);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexIntRelop"), "name",
                11);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                "resolved", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(1326692322U), "fileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                "context", 12);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 12);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(1393294858U), "fileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                "context", 13);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 13);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(1326691996U), "fileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                "context", 14);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 14);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(1362225882U), "fileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 15);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 15);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(1323134578U), "fileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 16);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 16);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(1362225882U), "fileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 17);
  emlrtAddField(*info, emlrt_marshallOut("max"), "name", 17);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(1311226516U), "fileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context", 18);
  emlrtAddField(*info, emlrt_marshallOut("eml_min_or_max"), "name", 18);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                "resolved", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(1378267184U), "fileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 19);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 19);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                19);
  emlrtAddField(*info, b_emlrt_marshallOut(1375951888U), "fileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 21);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 21);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(1375951888U), "fileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 23);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 23);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(1323134578U), "fileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 24);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 24);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                24);
  emlrtAddField(*info, b_emlrt_marshallOut(1375951888U), "fileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 26);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 26);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(1397228622U), "fileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 27);
  emlrtAddField(*info, emlrt_marshallOut("isfi"), "name", 27);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(1346481558U), "fileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context", 28);
  emlrtAddField(*info, emlrt_marshallOut("isnumerictype"), "name", 28);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                28);
  emlrtAddField(*info, b_emlrt_marshallOut(1398846798U), "fileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 29);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 29);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(1362225882U), "fileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 30);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 30);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(1362225882U), "fileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 31);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 31);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 32);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 32);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 33);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 33);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778822U), "fileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 34);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 34);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 35);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 35);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 35);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778822U), "fileTimeLo", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 35);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 36);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.System"), "name",
                36);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 36);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "resolved", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778822U), "fileTimeLo", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 36);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 37);
  emlrtAddField(*info, emlrt_marshallOut("Cylinder"), "name", 37);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 37);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "resolved", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(1459812571U), "fileTimeLo", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 37);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 38);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 38);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 38);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778822U), "fileTimeLo", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 38);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 39);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 39);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 39);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778822U), "fileTimeLo", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 39);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 40);
  emlrtAddField(*info, emlrt_marshallOut("mpower"), "name", 40);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 40);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(1363677878U), "fileTimeLo", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 40);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 41);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 41);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 41);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 41);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 42);
  emlrtAddField(*info, emlrt_marshallOut("ismatrix"), "name", 42);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 42);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                42);
  emlrtAddField(*info, b_emlrt_marshallOut(1331268858U), "fileTimeLo", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 42);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 43);
  emlrtAddField(*info, emlrt_marshallOut("power"), "name", 43);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 43);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(1395292506U), "fileTimeLo", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 43);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context", 44);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 44);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 44);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 44);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                45);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 45);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 45);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                45);
  emlrtAddField(*info, b_emlrt_marshallOut(1375951888U), "fileTimeLo", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 45);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                46);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 46);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 46);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 46);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                47);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 47);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 47);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(1375951888U), "fileTimeLo", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 47);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 48);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                48);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 48);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 48);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                49);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 49);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 49);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(1363677854U), "fileTimeLo", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 49);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context", 50);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 50);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 50);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 50);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context", 51);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_floor"), "name", 51);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 51);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                "resolved", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(1286786326U), "fileTimeLo", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 51);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                "context", 52);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 52);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 52);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                52);
  emlrtAddField(*info, b_emlrt_marshallOut(1375951888U), "fileTimeLo", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 52);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 53);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 53);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 53);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778848U), "fileTimeLo", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(1369981086U), "mFileTimeLo", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 53);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context", 54);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 54);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 54);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(1389681774U), "fileTimeLo", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 54);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context", 55);
  emlrtAddField(*info, emlrt_marshallOut("rdivide"), "name", 55);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 55);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(1363677880U), "fileTimeLo", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 55);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 56);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 56);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 56);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 56);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 57);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_compatible"), "name", 57);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 57);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                "resolved", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(1286786396U), "fileTimeLo", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 57);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 58);
  emlrtAddField(*info, emlrt_marshallOut("eml_div"), "name", 58);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 58);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(1386387952U), "fileTimeLo", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 58);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context", 59);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.div"), "name", 59);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 59);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                59);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 59);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 60);
  emlrtAddField(*info, emlrt_marshallOut("isequal"), "name", 60);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 60);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(1286786358U), "fileTimeLo", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 60);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context", 61);
  emlrtAddField(*info, emlrt_marshallOut("eml_isequal_core"), "name", 61);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 61);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                "resolved", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(1286786386U), "fileTimeLo", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 61);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                "context", 62);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 62);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 62);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(1363677858U), "fileTimeLo", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 62);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context", 63);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 63);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 63);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 63);
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
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 64);
  emlrtAddField(*info, emlrt_marshallOut("sign"), "name", 64);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 64);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(1363677856U), "fileTimeLo", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 64);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context", 65);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 65);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 65);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 65);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context", 66);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sign"), "name", 66);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 66);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                "resolved", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(1356505494U), "fileTimeLo", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 66);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 67);
  emlrtAddField(*info, emlrt_marshallOut("eml_mtimes_helper"), "name", 67);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 67);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "resolved", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(1383841294U), "fileTimeLo", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 67);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                "context", 68);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 68);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 68);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 68);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 69);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 69);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 69);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(1363677852U), "fileTimeLo", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 69);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 70);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 70);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 70);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(1395895856U), "fileTimeLo", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 70);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 71);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_abs"), "name", 71);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 71);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                "resolved", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(1286786312U), "fileTimeLo", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 71);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 72);
  emlrtAddField(*info, emlrt_marshallOut("cos"), "name", 72);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 72);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(1395292496U), "fileTimeLo", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 72);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context", 73);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_cos"), "name", 73);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 73);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                "resolved", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(1286786322U), "fileTimeLo", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 73);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/jportella/Desktop/DirectedStudies-master/Simulation/Classes/Cylinder.m"),
                "context", 74);
  emlrtAddField(*info, emlrt_marshallOut("sin"), "name", 74);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 74);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(1395292504U), "fileTimeLo", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 74);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context", 75);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sin"), "name", 75);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 75);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                "resolved", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(1286786336U), "fileTimeLo", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 75);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "context", 76);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 76);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 76);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(1323134578U), "fileTimeLo", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 76);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "context", 77);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 77);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 77);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                77);
  emlrtAddField(*info, b_emlrt_marshallOut(1375951888U), "fileTimeLo", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 77);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "context", 78);
  emlrtAddField(*info, emlrt_marshallOut("eml_xgemm"), "name", 78);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 78);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                "resolved", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(1375951890U), "fileTimeLo", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 78);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                79);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.inline"), "name",
                79);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 79);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                "resolved", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778972U), "fileTimeLo", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 79);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                80);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.xgemm"), "name",
                80);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 80);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                "resolved", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 80);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                "context", 81);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.use_refblas"),
                "name", 81);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 81);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                "resolved", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 81);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                "context", 82);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.threshold"),
                "name", 82);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 82);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "resolved", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778972U), "fileTimeLo", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 82);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "context", 83);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 83);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 83);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(1393294858U), "fileTimeLo", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 83);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                "context", 84);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 84);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 84);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778970U), "fileTimeLo", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 84);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                "context", 85);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.refblas.xgemm"), "name",
                85);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 85);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                "resolved", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(1410778972U), "fileTimeLo", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 85);
}

static const mxArray *mw__internal__autoInference__fcn(void)
{
  const mxArray *infoCache;
  int8_T Ports_dims_data[4];
  int32_T i8;
  static int8_T iv14[4] = { 6, 2, 1, 6 };

  char_T t2_objTypeName[8];
  static char_T cv24[8] = { 'C', 'y', 'l', 'i', 'n', 'd', 'e', 'r' };

  char_T t2_sysObjChksum[22];
  static char_T cv25[22] = { 'U', '1', '6', 'D', '7', 'M', 'r', 'q', 'X', 'K',
    'x', 'g', 'e', 'C', 'u', 'D', 'y', 'T', 'I', 'Z', 't', 'B' };

  uint32_T t1_cgxeChksum[4];
  static uint32_T uv0[4] = { 1851714360U, 3545027892U, 3074268267U, 1486636326U
  };

  static int32_T t3_chksum[4] = { 2142174056, 846573741, 1209501514, 430395370 };

  s7UBIGHSehQY1gCsIQWwr5C checksums[4];
  static uint32_T t4_chksum[4] = { 425343916U, 2179284580U, 2146508138U,
    3819613487U };

  static uint32_T t5_chksum[4] = { 776759425U, 3454184808U, 3908237643U,
    4275338662U };

  static uint32_T t6_chksum[4] = { 146508757U, 1565374272U, 2733973528U,
    3623211604U };

  uint32_T b_t6_chksum[4];
  static uint32_T t7_codeGenChksum[4] = { 907274058U, 3220786148U, 779473529U,
    2769831971U };

  char_T u_slVer[3];
  static char_T cv26[3] = { '8', '.', '4' };

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
  int32_T iv15[2];
  const mxArray *k_y;
  static const int32_T iv16[2] = { 1, 8 };

  const mxArray *l_y;
  const mxArray *m_y;
  const mxArray *n_y;
  static const int32_T iv17[2] = { 1, 22 };

  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  int32_T b_u_sizes[2];
  const mxArray *t_y;
  const mxArray *u_y;
  static const int32_T iv18[2] = { 1, 4 };

  const mxArray *v_y;
  s7UBIGHSehQY1gCsIQWwr5C u[4];
  const mxArray *w_y;
  const s7UBIGHSehQY1gCsIQWwr5C *r0;
  real_T b_u[4];
  const mxArray *x_y;
  static const int32_T iv19[2] = { 1, 4 };

  const mxArray *y_y;
  const mxArray *ab_y;
  static const int32_T iv20[2] = { 1, 4 };

  const mxArray *bb_y;
  static const int32_T iv21[2] = { 1, 3 };

  infoCache = NULL;
  for (i8 = 0; i8 < 4; i8++) {
    Ports_dims_data[i8] = iv14[i8];
  }

  for (i8 = 0; i8 < 8; i8++) {
    t2_objTypeName[i8] = cv24[i8];
  }

  for (i8 = 0; i8 < 22; i8++) {
    t2_sysObjChksum[i8] = cv25[i8];
  }

  for (i8 = 0; i8 < 4; i8++) {
    t1_cgxeChksum[i8] = uv0[i8];
  }

  for (i8 = 0; i8 < 4; i8++) {
    checksums[0].chksum[i8] = (real_T)t3_chksum[i8];
  }

  for (i8 = 0; i8 < 4; i8++) {
    checksums[1].chksum[i8] = (real_T)t4_chksum[i8];
  }

  for (i8 = 0; i8 < 4; i8++) {
    checksums[2].chksum[i8] = (real_T)t5_chksum[i8];
  }

  for (i8 = 0; i8 < 4; i8++) {
    checksums[3].chksum[i8] = (real_T)t6_chksum[i8];
  }

  for (i8 = 0; i8 < 4; i8++) {
    b_t6_chksum[i8] = t7_codeGenChksum[i8];
  }

  for (i8 = 0; i8 < 3; i8++) {
    u_slVer[i8] = cv26[i8];
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
  for (i8 = 0; i8 < 4; i8++) {
    u_data[i8] = Ports_dims_data[i8];
  }

  f_y = NULL;
  m6 = emlrtCreateNumericArray(2, u_sizes, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  i8 = 0;
  for (i = 0; i < u_sizes[1]; i++) {
    pData[i8] = (real_T)u_data[u_sizes[0] * i];
    i8++;
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
  for (i8 = 0; i8 < 2; i8++) {
    iv15[i8] = 1 - i8;
  }

  emlrtAssign(&j_y, emlrtCreateStructArray(2, iv15, 0, NULL));
  emlrtAddField(j_y, NULL, "names", 0);
  emlrtAddField(j_y, NULL, "dims", 0);
  emlrtAddField(j_y, NULL, "dType", 0);
  emlrtAddField(j_y, NULL, "complexity", 0);
  emlrtAddField(c_y, j_y, "dWork", 0);
  k_y = NULL;
  m6 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m6, t2_objTypeName);
  emlrtAssign(&k_y, m6);
  emlrtAddField(c_y, k_y, "objTypeName", 0);
  l_y = NULL;
  m6 = emlrtCreateDoubleScalar(136.0);
  emlrtAssign(&l_y, m6);
  emlrtAddField(c_y, l_y, "objTypeSize", 0);
  m_y = NULL;
  for (i8 = 0; i8 < 2; i8++) {
    iv15[i8] = 1 - i8;
  }

  emlrtAssign(&m_y, emlrtCreateStructArray(2, iv15, 0, NULL));
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
  m6 = emlrtCreateCharArray(2, iv17);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 22, m6, t2_sysObjChksum);
  emlrtAssign(&n_y, m6);
  emlrtAddField(c_y, n_y, "sysObjChksum", 0);
  o_y = NULL;
  emlrtAssign(&o_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  p_y = NULL;
  for (i8 = 0; i8 < 2; i8++) {
    iv15[i8] = 1 - i8;
  }

  emlrtAssign(&p_y, emlrtCreateStructArray(2, iv15, 0, NULL));
  emlrtAddField(p_y, NULL, "Index", 0);
  emlrtAddField(p_y, NULL, "DataType", 0);
  emlrtAddField(p_y, NULL, "IsSigned", 0);
  emlrtAddField(p_y, NULL, "MantBits", 0);
  emlrtAddField(p_y, NULL, "FixExp", 0);
  emlrtAddField(p_y, NULL, "Slope", 0);
  emlrtAddField(p_y, NULL, "Bias", 0);
  emlrtAddField(o_y, p_y, "Out", 0);
  q_y = NULL;
  for (i8 = 0; i8 < 2; i8++) {
    iv15[i8] = 1 - i8;
  }

  emlrtAssign(&q_y, emlrtCreateStructArray(2, iv15, 0, NULL));
  emlrtAddField(q_y, NULL, "Index", 0);
  emlrtAddField(q_y, NULL, "DataType", 0);
  emlrtAddField(q_y, NULL, "IsSigned", 0);
  emlrtAddField(q_y, NULL, "MantBits", 0);
  emlrtAddField(q_y, NULL, "FixExp", 0);
  emlrtAddField(q_y, NULL, "Slope", 0);
  emlrtAddField(q_y, NULL, "Bias", 0);
  emlrtAddField(o_y, q_y, "DW", 0);
  r_y = NULL;
  for (i8 = 0; i8 < 2; i8++) {
    iv15[i8] = 1 - i8;
  }

  emlrtAssign(&r_y, emlrtCreateStructArray(2, iv15, 0, NULL));
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
  m6 = emlrtCreateDoubleScalar(2.0);
  emlrtAssign(&s_y, m6);
  emlrtAddField(c_y, s_y, "objDWorkTypeNameIndex", 0);
  b_u_sizes[0] = 1;
  b_u_sizes[1] = 9;
  t_y = NULL;
  m6 = emlrtCreateNumericArray(2, b_u_sizes, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  i8 = 0;
  for (i = 0; i < 9; i++) {
    pData[i8] = 0.0;
    i8++;
  }

  emlrtAssign(&t_y, m6);
  emlrtAddField(c_y, t_y, "inputDFFlagsIndexField", 0);
  emlrtAddField(b_y, c_y, "DispatcherInfo", 0);
  u_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv18, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)t1_cgxeChksum[i];
  }

  emlrtAssign(&u_y, m6);
  emlrtAddField(b_y, u_y, "cgxeChksum", 0);
  emlrtAddField(y, b_y, "RestoreInfo", 0);
  v_y = NULL;
  emlrtAssign(&v_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  for (i8 = 0; i8 < 4; i8++) {
    u[i8] = checksums[i8];
  }

  w_y = NULL;
  for (i8 = 0; i8 < 2; i8++) {
    iv15[i8] = 1 + 3 * i8;
  }

  emlrtAssign(&w_y, emlrtCreateStructArray(2, iv15, 0, NULL));
  for (i8 = 0; i8 < 4; i8++) {
    r0 = &u[i8];
    for (i = 0; i < 4; i++) {
      b_u[i] = r0->chksum[i];
    }

    x_y = NULL;
    m6 = emlrtCreateNumericArray(2, iv19, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T *)mxGetPr(m6);
    for (i = 0; i < 4; i++) {
      pData[i] = b_u[i];
    }

    emlrtAssign(&x_y, m6);
    emlrtAddField(w_y, x_y, "chksum", i8);
  }

  emlrtAddField(v_y, w_y, "checksums", 0);
  y_y = NULL;
  emlrtAssign(&y_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  ab_y = NULL;
  m6 = emlrtCreateNumericArray(2, iv20, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m6);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)b_t6_chksum[i];
  }

  emlrtAssign(&ab_y, m6);
  emlrtAddField(y_y, ab_y, "codeGenChksum", 0);
  emlrtAddField(v_y, y_y, "codeGenOnlyInfo", 0);
  emlrtAddField(y, v_y, "VerificationInfo", 0);
  bb_y = NULL;
  m6 = emlrtCreateCharArray(2, iv21);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 3, m6, u_slVer);
  emlrtAssign(&bb_y, m6);
  emlrtAddField(y, bb_y, "slVer", 0);
  emlrtAssign(&infoCache, y);
  return infoCache;
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance)
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
  static const int32_T iv22[1] = { 2 };

  real_T *pData;
  int32_T i;
  const mxArray *s_y;
  static const int32_T iv23[1] = { 2 };

  const mxArray *t_y;
  st = NULL;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isInitialized);
  emlrtAssign(&c_y, m7);
  emlrtAddField(b_y, c_y, "isInitialized", 0);
  d_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isReleased);
  emlrtAssign(&d_y, m7);
  emlrtAddField(b_y, d_y, "isReleased", 0);
  e_y = NULL;
  m7 = emlrtCreateLogicalScalar(moduleInstance->sysobj.TunablePropsChanged);
  emlrtAssign(&e_y, m7);
  emlrtAddField(b_y, e_y, "TunablePropsChanged", 0);
  f_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.R);
  emlrtAssign(&f_y, m7);
  emlrtAddField(b_y, f_y, "R", 0);
  g_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.M);
  emlrtAssign(&g_y, m7);
  emlrtAddField(b_y, g_y, "M", 0);
  h_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.g);
  emlrtAssign(&h_y, m7);
  emlrtAddField(b_y, h_y, "g", 0);
  i_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Us);
  emlrtAssign(&i_y, m7);
  emlrtAddField(b_y, i_y, "Us", 0);
  j_y = NULL;
  m7 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Uk);
  emlrtAssign(&j_y, m7);
  emlrtAddField(b_y, j_y, "Uk", 0);
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
  m7 = emlrtCreateNumericArray(1, iv22, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m7);
  for (i = 0; i < 2; i++) {
    pData[i] = moduleInstance->sysobj.Position_o_G3[i];
  }

  emlrtAssign(&r_y, m7);
  emlrtAddField(b_y, r_y, "Position_o_G3", 0);
  s_y = NULL;
  m7 = emlrtCreateNumericArray(1, iv23, mxDOUBLE_CLASS, mxREAL);
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
  static const char * fieldNames[17] = { "isInitialized", "isReleased",
    "TunablePropsChanged", "R", "M", "g", "Us", "Uk", "Iz", "F_s_x", "F_s_y",
    "F_k_x", "F_k_y", "T_s", "T_k", "Position_o_G3",
    "Position_G3_P3_frame_cylinder" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 17, fieldNames, 0U, 0);
  thisId.fIdentifier = "isInitialized";
  y->isInitialized = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isInitialized")), &thisId);
  thisId.fIdentifier = "isReleased";
  y->isReleased = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isReleased")), &thisId);
  thisId.fIdentifier = "TunablePropsChanged";
  y->TunablePropsChanged = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "TunablePropsChanged")), &thisId);
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

static boolean_T c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  boolean_T y;
  y = g_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = h_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[2])
{
  i_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T f_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = c_emlrt_marshallIn(emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_mZk3xfHht9RcBXgyf1yZnE
  *moduleInstance, const mxArray *st)
{
  const mxArray *u;
  u = emlrtAlias(st);
  emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, u, 0)), "sysobj",
                   &moduleInstance->sysobj);
  moduleInstance->sysobj_not_empty = f_emlrt_marshallIn(emlrtAlias(emlrtGetCell
    (emlrtRootTLSGlobal, u, 1)), "sysobj_not_empty");
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

static boolean_T g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  boolean_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "logical", false, 0U,
    0);
  ret = *mxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[2])
{
  int32_T iv24[1];
  int32_T i9;
  iv24[0] = 2;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
    iv24);
  for (i9 = 0; i9 < 2; i9++) {
    ret[i9] = (*(real_T (*)[2])mxGetData(src))[i9];
  }

  emlrtDestroyArray(&src);
}

/* CGXE Glue Code */
static void mdlOutputs_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S, int_T tid)
{
  InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance;
  moduleInstance = (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_outputs(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlInitialize_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S)
{
  InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance;
  moduleInstance = (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_initialize(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlUpdate_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S, int_T tid)
{
  InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance;
  moduleInstance = (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_update(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static mxArray* getSimState_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S)
{
  InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance;
  mxArray* mxSS;
  moduleInstance = (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
  return mxSS;
}

static void setSimState_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance;
  moduleInstance = (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
  CGXERT_LEAVE_CHECK();
}

static void mdlTerminate_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S)
{
  InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance;
  moduleInstance = (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_terminate(moduleInstance);
  CGXERT_LEAVE_CHECK();
  free((void *)moduleInstance);
  ssSetUserData(S, NULL);
}

static void mdlStart_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S)
{
  InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *moduleInstance;
  moduleInstance = (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE *)calloc(1, sizeof
    (InstanceStruct_mZk3xfHht9RcBXgyf1yZnE));
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

  ssSetmdlOutputs(S, mdlOutputs_mZk3xfHht9RcBXgyf1yZnE);
  ssSetmdlInitializeConditions(S, mdlInitialize_mZk3xfHht9RcBXgyf1yZnE);
  ssSetmdlUpdate(S, mdlUpdate_mZk3xfHht9RcBXgyf1yZnE);
  ssSetmdlTerminate(S, mdlTerminate_mZk3xfHht9RcBXgyf1yZnE);
}

static void mdlProcessParameters_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S)
{
}

void method_dispatcher_mZk3xfHht9RcBXgyf1yZnE(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_mZk3xfHht9RcBXgyf1yZnE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_mZk3xfHht9RcBXgyf1yZnE(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_mZk3xfHht9RcBXgyf1yZnE(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_mZk3xfHht9RcBXgyf1yZnE(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: mZk3xfHht9RcBXgyf1yZnE.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

int autoInfer_dispatcher_mZk3xfHht9RcBXgyf1yZnE(mxArray* plhs[], const char
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

mxArray *cgxe_mZk3xfHht9RcBXgyf1yZnE_BuildInfoUpdate(void)
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
