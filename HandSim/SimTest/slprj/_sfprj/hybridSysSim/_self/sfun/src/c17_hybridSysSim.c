/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c17_hybridSysSim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "hybridSysSim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c17_debug_family_names[6] = { "fcTN", "nargin", "nargout",
  "FcSense", "theta", "fcD" };

static const char * c17_b_debug_family_names[4] = { "nargin", "nargout", "theta",
  "rot" };

/* Function Declarations */
static void initialize_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance);
static void c17_update_debugger_state_c17_hybridSysSim
  (SFc17_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_hybridSysSim
  (SFc17_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_st);
static void finalize_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_b_fcD, const char_T *c17_identifier);
static real_T c17_b_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_c_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[2]);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_d_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[4]);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static void c17_info_helper(const mxArray **c17_info);
static const mxArray *c17_emlrt_marshallOut(const char * c17_u);
static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u);
static void c17_eml_scalar_eg(SFc17_hybridSysSimInstanceStruct *chartInstance);
static void c17_eml_xgemm(SFc17_hybridSysSimInstanceStruct *chartInstance,
  real_T c17_A[4], real_T c17_B[2], real_T c17_C[2], real_T c17_b_C[2]);
static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_e_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_f_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_hybridSysSim, const char_T *
  c17_identifier);
static uint8_T c17_g_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_eml_xgemm(SFc17_hybridSysSimInstanceStruct *chartInstance,
  real_T c17_A[4], real_T c17_B[2], real_T c17_C[2]);
static void init_dsm_address_info(SFc17_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc17_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c17_is_active_c17_hybridSysSim = 0U;
}

static void initialize_params_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c17_update_debugger_state_c17_hybridSysSim
  (SFc17_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c17_hybridSysSim
  (SFc17_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  real_T c17_hoistedGlobal;
  real_T c17_u;
  const mxArray *c17_b_y = NULL;
  uint8_T c17_b_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellmatrix(2, 1), false);
  c17_hoistedGlobal = *chartInstance->c17_fcD;
  c17_u = c17_hoistedGlobal;
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_b_hoistedGlobal = chartInstance->c17_is_active_c17_hybridSysSim;
  c17_b_u = c17_b_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y, false);
  return c17_st;
}

static void set_sim_state_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_st)
{
  const mxArray *c17_u;
  chartInstance->c17_doneDoubleBufferReInit = true;
  c17_u = sf_mex_dup(c17_st);
  *chartInstance->c17_fcD = c17_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c17_u, 0)), "fcD");
  chartInstance->c17_is_active_c17_hybridSysSim = c17_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
     "is_active_c17_hybridSysSim");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_hybridSysSim(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c17_i0;
  int32_T c17_i1;
  real_T c17_b_FcSense[2];
  int32_T c17_i2;
  real_T c17_b_theta[2];
  uint32_T c17_debug_family_var_map[6];
  real_T c17_fcTN[2];
  real_T c17_nargin = 2.0;
  real_T c17_nargout = 1.0;
  real_T c17_b_fcD;
  real_T c17_c_theta;
  uint32_T c17_b_debug_family_var_map[4];
  real_T c17_b_nargin = 1.0;
  real_T c17_b_nargout = 1.0;
  real_T c17_rot[4];
  real_T c17_x;
  real_T c17_b_x;
  real_T c17_c_x;
  real_T c17_d_x;
  real_T c17_e_x;
  real_T c17_f_x;
  real_T c17_g_x;
  real_T c17_h_x;
  int32_T c17_i3;
  int32_T c17_i4;
  int32_T c17_i5;
  int32_T c17_i6;
  real_T c17_a[4];
  int32_T c17_i7;
  real_T c17_b[2];
  int32_T c17_i8;
  int32_T c17_i9;
  real_T c17_dv0[2];
  int32_T c17_i10;
  real_T c17_b_a[4];
  int32_T c17_i11;
  real_T c17_b_b[2];
  int32_T c17_i12;
  int32_T c17_i13;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  for (c17_i0 = 0; c17_i0 < 2; c17_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c17_FcSense)[c17_i0], 0U);
  }

  chartInstance->c17_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  for (c17_i1 = 0; c17_i1 < 2; c17_i1++) {
    c17_b_FcSense[c17_i1] = (*chartInstance->c17_FcSense)[c17_i1];
  }

  for (c17_i2 = 0; c17_i2 < 2; c17_i2++) {
    c17_b_theta[c17_i2] = (*chartInstance->c17_theta)[c17_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_fcTN, 0U, c17_b_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 1U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 2U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c17_b_FcSense, 3U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c17_b_theta, 4U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_fcD, 5U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 4);
  c17_c_theta = c17_b_theta[0] + c17_b_theta[1];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c17_b_debug_family_names,
    c17_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_nargin, 0U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_b_nargout, 1U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_c_theta, 2U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_rot, 3U, c17_d_sf_marshallOut,
    c17_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 11);
  c17_x = c17_c_theta;
  c17_b_x = c17_x;
  c17_b_x = muDoubleScalarCos(c17_b_x);
  c17_c_x = c17_c_theta;
  c17_d_x = c17_c_x;
  c17_d_x = muDoubleScalarSin(c17_d_x);
  c17_e_x = c17_c_theta;
  c17_f_x = c17_e_x;
  c17_f_x = muDoubleScalarSin(c17_f_x);
  c17_g_x = c17_c_theta;
  c17_h_x = c17_g_x;
  c17_h_x = muDoubleScalarCos(c17_h_x);
  c17_rot[0] = c17_b_x;
  c17_rot[2] = -c17_d_x;
  c17_rot[1] = c17_f_x;
  c17_rot[3] = c17_h_x;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  c17_i3 = 0;
  for (c17_i4 = 0; c17_i4 < 2; c17_i4++) {
    c17_i5 = 0;
    for (c17_i6 = 0; c17_i6 < 2; c17_i6++) {
      c17_a[c17_i6 + c17_i3] = c17_rot[c17_i5 + c17_i4];
      c17_i5 += 2;
    }

    c17_i3 += 2;
  }

  for (c17_i7 = 0; c17_i7 < 2; c17_i7++) {
    c17_b[c17_i7] = -c17_b_FcSense[c17_i7];
  }

  c17_eml_scalar_eg(chartInstance);
  c17_eml_scalar_eg(chartInstance);
  for (c17_i8 = 0; c17_i8 < 2; c17_i8++) {
    c17_fcTN[c17_i8] = 0.0;
  }

  for (c17_i9 = 0; c17_i9 < 2; c17_i9++) {
    c17_dv0[c17_i9] = 0.0;
  }

  for (c17_i10 = 0; c17_i10 < 4; c17_i10++) {
    c17_b_a[c17_i10] = c17_a[c17_i10];
  }

  for (c17_i11 = 0; c17_i11 < 2; c17_i11++) {
    c17_b_b[c17_i11] = c17_b[c17_i11];
  }

  c17_b_eml_xgemm(chartInstance, c17_b_a, c17_b_b, c17_dv0);
  for (c17_i12 = 0; c17_i12 < 2; c17_i12++) {
    c17_fcTN[c17_i12] = c17_dv0[c17_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 5);
  c17_b_fcD = c17_fcTN[1];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c17_fcD = c17_b_fcD;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c17_fcD, 1U);
  for (c17_i13 = 0; c17_i13 < 2; c17_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c17_theta)[c17_i13], 2U);
  }
}

static void mdl_start_c17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc17_hybridSysSim(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber)
{
  (void)c17_machineNumber;
  (void)c17_chartNumber;
  (void)c17_instanceNumber;
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static real_T c17_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_b_fcD, const char_T *c17_identifier)
{
  real_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_fcD),
    &c17_thisId);
  sf_mex_destroy(&c17_b_fcD);
  return c17_y;
}

static real_T c17_b_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_fcD;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_b_fcD = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_fcD),
    &c17_thisId);
  sf_mex_destroy(&c17_b_fcD);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i14;
  real_T c17_b_inData[2];
  int32_T c17_i15;
  real_T c17_u[2];
  const mxArray *c17_y = NULL;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i14 = 0; c17_i14 < 2; c17_i14++) {
    c17_b_inData[c17_i14] = (*(real_T (*)[2])c17_inData)[c17_i14];
  }

  for (c17_i15 = 0; c17_i15 < 2; c17_i15++) {
    c17_u[c17_i15] = c17_b_inData[c17_i15];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i16;
  real_T c17_b_inData[2];
  int32_T c17_i17;
  real_T c17_u[2];
  const mxArray *c17_y = NULL;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i16 = 0; c17_i16 < 2; c17_i16++) {
    c17_b_inData[c17_i16] = (*(real_T (*)[2])c17_inData)[c17_i16];
  }

  for (c17_i17 = 0; c17_i17 < 2; c17_i17++) {
    c17_u[c17_i17] = c17_b_inData[c17_i17];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_c_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[2])
{
  real_T c17_dv1[2];
  int32_T c17_i18;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c17_i18 = 0; c17_i18 < 2; c17_i18++) {
    c17_y[c17_i18] = c17_dv1[c17_i18];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_fcTN;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[2];
  int32_T c17_i19;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_fcTN = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_fcTN), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_fcTN);
  for (c17_i19 = 0; c17_i19 < 2; c17_i19++) {
    (*(real_T (*)[2])c17_outData)[c17_i19] = c17_y[c17_i19];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i20;
  int32_T c17_i21;
  int32_T c17_i22;
  real_T c17_b_inData[4];
  int32_T c17_i23;
  int32_T c17_i24;
  int32_T c17_i25;
  real_T c17_u[4];
  const mxArray *c17_y = NULL;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_i20 = 0;
  for (c17_i21 = 0; c17_i21 < 2; c17_i21++) {
    for (c17_i22 = 0; c17_i22 < 2; c17_i22++) {
      c17_b_inData[c17_i22 + c17_i20] = (*(real_T (*)[4])c17_inData)[c17_i22 +
        c17_i20];
    }

    c17_i20 += 2;
  }

  c17_i23 = 0;
  for (c17_i24 = 0; c17_i24 < 2; c17_i24++) {
    for (c17_i25 = 0; c17_i25 < 2; c17_i25++) {
      c17_u[c17_i25 + c17_i23] = c17_b_inData[c17_i25 + c17_i23];
    }

    c17_i23 += 2;
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_d_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[4])
{
  real_T c17_dv2[4];
  int32_T c17_i26;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv2, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c17_i26 = 0; c17_i26 < 4; c17_i26++) {
    c17_y[c17_i26] = c17_dv2[c17_i26];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_rot;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[4];
  int32_T c17_i27;
  int32_T c17_i28;
  int32_T c17_i29;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_rot = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_rot), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_rot);
  c17_i27 = 0;
  for (c17_i28 = 0; c17_i28 < 2; c17_i28++) {
    for (c17_i29 = 0; c17_i29 < 2; c17_i29++) {
      (*(real_T (*)[4])c17_outData)[c17_i29 + c17_i27] = c17_y[c17_i29 + c17_i27];
    }

    c17_i27 += 2;
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray *sf_c17_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_createstruct("structure", 2, 17, 1),
                false);
  c17_info_helper(&c17_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c17_nameCaptureInfo);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(const mxArray **c17_info)
{
  const mxArray *c17_rhs0 = NULL;
  const mxArray *c17_lhs0 = NULL;
  const mxArray *c17_rhs1 = NULL;
  const mxArray *c17_lhs1 = NULL;
  const mxArray *c17_rhs2 = NULL;
  const mxArray *c17_lhs2 = NULL;
  const mxArray *c17_rhs3 = NULL;
  const mxArray *c17_lhs3 = NULL;
  const mxArray *c17_rhs4 = NULL;
  const mxArray *c17_lhs4 = NULL;
  const mxArray *c17_rhs5 = NULL;
  const mxArray *c17_lhs5 = NULL;
  const mxArray *c17_rhs6 = NULL;
  const mxArray *c17_lhs6 = NULL;
  const mxArray *c17_rhs7 = NULL;
  const mxArray *c17_lhs7 = NULL;
  const mxArray *c17_rhs8 = NULL;
  const mxArray *c17_lhs8 = NULL;
  const mxArray *c17_rhs9 = NULL;
  const mxArray *c17_lhs9 = NULL;
  const mxArray *c17_rhs10 = NULL;
  const mxArray *c17_lhs10 = NULL;
  const mxArray *c17_rhs11 = NULL;
  const mxArray *c17_lhs11 = NULL;
  const mxArray *c17_rhs12 = NULL;
  const mxArray *c17_lhs12 = NULL;
  const mxArray *c17_rhs13 = NULL;
  const mxArray *c17_lhs13 = NULL;
  const mxArray *c17_rhs14 = NULL;
  const mxArray *c17_lhs14 = NULL;
  const mxArray *c17_rhs15 = NULL;
  const mxArray *c17_lhs15 = NULL;
  const mxArray *c17_rhs16 = NULL;
  const mxArray *c17_lhs16 = NULL;
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c17_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286786322U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c17_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1395292504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c17_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286786336U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c17_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c17_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c17_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c17_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c17_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c17_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c17_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c17_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c17_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c17_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c17_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c17_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c17_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c17_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs16), "lhs", "lhs",
                  16);
  sf_mex_destroy(&c17_rhs0);
  sf_mex_destroy(&c17_lhs0);
  sf_mex_destroy(&c17_rhs1);
  sf_mex_destroy(&c17_lhs1);
  sf_mex_destroy(&c17_rhs2);
  sf_mex_destroy(&c17_lhs2);
  sf_mex_destroy(&c17_rhs3);
  sf_mex_destroy(&c17_lhs3);
  sf_mex_destroy(&c17_rhs4);
  sf_mex_destroy(&c17_lhs4);
  sf_mex_destroy(&c17_rhs5);
  sf_mex_destroy(&c17_lhs5);
  sf_mex_destroy(&c17_rhs6);
  sf_mex_destroy(&c17_lhs6);
  sf_mex_destroy(&c17_rhs7);
  sf_mex_destroy(&c17_lhs7);
  sf_mex_destroy(&c17_rhs8);
  sf_mex_destroy(&c17_lhs8);
  sf_mex_destroy(&c17_rhs9);
  sf_mex_destroy(&c17_lhs9);
  sf_mex_destroy(&c17_rhs10);
  sf_mex_destroy(&c17_lhs10);
  sf_mex_destroy(&c17_rhs11);
  sf_mex_destroy(&c17_lhs11);
  sf_mex_destroy(&c17_rhs12);
  sf_mex_destroy(&c17_lhs12);
  sf_mex_destroy(&c17_rhs13);
  sf_mex_destroy(&c17_lhs13);
  sf_mex_destroy(&c17_rhs14);
  sf_mex_destroy(&c17_lhs14);
  sf_mex_destroy(&c17_rhs15);
  sf_mex_destroy(&c17_lhs15);
  sf_mex_destroy(&c17_rhs16);
  sf_mex_destroy(&c17_lhs16);
}

static const mxArray *c17_emlrt_marshallOut(const char * c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c17_u)), false);
  return c17_y;
}

static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 7, 0U, 0U, 0U, 0), false);
  return c17_y;
}

static void c17_eml_scalar_eg(SFc17_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c17_eml_xgemm(SFc17_hybridSysSimInstanceStruct *chartInstance,
  real_T c17_A[4], real_T c17_B[2], real_T c17_C[2], real_T c17_b_C[2])
{
  int32_T c17_i30;
  int32_T c17_i31;
  real_T c17_b_A[4];
  int32_T c17_i32;
  real_T c17_b_B[2];
  for (c17_i30 = 0; c17_i30 < 2; c17_i30++) {
    c17_b_C[c17_i30] = c17_C[c17_i30];
  }

  for (c17_i31 = 0; c17_i31 < 4; c17_i31++) {
    c17_b_A[c17_i31] = c17_A[c17_i31];
  }

  for (c17_i32 = 0; c17_i32 < 2; c17_i32++) {
    c17_b_B[c17_i32] = c17_B[c17_i32];
  }

  c17_b_eml_xgemm(chartInstance, c17_b_A, c17_b_B, c17_b_C);
}

static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static int32_T c17_e_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i33;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i33, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i33;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_f_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_hybridSysSim, const char_T *
  c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_hybridSysSim), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_hybridSysSim);
  return c17_y;
}

static uint8_T c17_g_emlrt_marshallIn(SFc17_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_eml_xgemm(SFc17_hybridSysSimInstanceStruct *chartInstance,
  real_T c17_A[4], real_T c17_B[2], real_T c17_C[2])
{
  int32_T c17_i34;
  int32_T c17_i35;
  int32_T c17_i36;
  (void)chartInstance;
  for (c17_i34 = 0; c17_i34 < 2; c17_i34++) {
    c17_C[c17_i34] = 0.0;
    c17_i35 = 0;
    for (c17_i36 = 0; c17_i36 < 2; c17_i36++) {
      c17_C[c17_i34] += c17_A[c17_i35 + c17_i34] * c17_B[c17_i36];
      c17_i35 += 2;
    }
  }
}

static void init_dsm_address_info(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc17_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c17_FcSense = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c17_fcD = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c17_theta = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c17_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2752569957U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4105302676U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2264475033U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(575337705U);
}

mxArray* sf_c17_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c17_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Gqta9sNzlfMfHuuB2xu1GB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c17_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c17_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_hybridSysSim_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c17_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c17_hybridSysSim_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c17_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"fcD\",},{M[8],M[0],T\"is_active_c17_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc17_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           17,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_hybridSysSimMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_hybridSysSimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _hybridSysSimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"FcSense");
          _SFD_SET_DATA_PROPS(1,2,0,1,"fcD");
          _SFD_SET_DATA_PROPS(2,1,1,0,"theta");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,166);
        _SFD_CV_INIT_EML_FCN(0,1,"rotMat",175,-1,446);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c17_FcSense);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c17_fcD);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c17_theta);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _hybridSysSimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "1la7Og7kRIVOPTIKclEqp";
}

static void sf_opaque_initialize_c17_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c17_hybridSysSim(void *chartInstanceVar)
{
  enable_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_hybridSysSim(void *chartInstanceVar)
{
  disable_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c17_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c17_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c17_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c17_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_hybridSysSim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c17_hybridSysSim((SFc17_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,17,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2946354695U));
  ssSetChecksum1(S,(1734299074U));
  ssSetChecksum2(S,(459416276U));
  ssSetChecksum3(S,(319759466U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c17_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_hybridSysSim(SimStruct *S)
{
  SFc17_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc17_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc17_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c17_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c17_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c17_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c17_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c17_hybridSysSim;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c17_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
