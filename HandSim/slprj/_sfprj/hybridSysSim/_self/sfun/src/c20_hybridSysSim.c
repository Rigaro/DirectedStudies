/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c20_hybridSysSim.h"
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
static const char * c20_debug_family_names[9] = { "fcTN", "fcD", "nargin",
  "nargout", "FcSense", "CFC", "GAC", "q", "Fa" };

static const char * c20_b_debug_family_names[4] = { "nargin", "nargout", "theta",
  "rot" };

/* Function Declarations */
static void initialize_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance);
static void c20_update_debugger_state_c20_hybridSysSim
  (SFc20_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_hybridSysSim
  (SFc20_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_st);
static void finalize_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_b_Fa, const char_T *c20_identifier);
static real_T c20_b_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_c_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[2]);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_d_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[4]);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static void c20_info_helper(const mxArray **c20_info);
static const mxArray *c20_emlrt_marshallOut(const char * c20_u);
static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u);
static void c20_eml_scalar_eg(SFc20_hybridSysSimInstanceStruct *chartInstance);
static void c20_eml_xgemm(SFc20_hybridSysSimInstanceStruct *chartInstance,
  real_T c20_A[4], real_T c20_B[2], real_T c20_C[2], real_T c20_b_C[2]);
static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_e_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_f_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_hybridSysSim, const char_T *
  c20_identifier);
static uint8_T c20_g_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_eml_xgemm(SFc20_hybridSysSimInstanceStruct *chartInstance,
  real_T c20_A[4], real_T c20_B[2], real_T c20_C[2]);
static void init_dsm_address_info(SFc20_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc20_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_is_active_c20_hybridSysSim = 0U;
}

static void initialize_params_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c20_update_debugger_state_c20_hybridSysSim
  (SFc20_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c20_hybridSysSim
  (SFc20_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  real_T c20_hoistedGlobal;
  real_T c20_u;
  const mxArray *c20_b_y = NULL;
  uint8_T c20_b_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(2, 1), false);
  c20_hoistedGlobal = *chartInstance->c20_Fa;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = chartInstance->c20_is_active_c20_hybridSysSim;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  chartInstance->c20_doneDoubleBufferReInit = true;
  c20_u = sf_mex_dup(c20_st);
  *chartInstance->c20_Fa = c20_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 0)), "Fa");
  chartInstance->c20_is_active_c20_hybridSysSim = c20_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
     "is_active_c20_hybridSysSim");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_hybridSysSim(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c20_i0;
  int32_T c20_i1;
  real_T c20_hoistedGlobal;
  real_T c20_b_hoistedGlobal;
  int32_T c20_i2;
  real_T c20_b_FcSense[2];
  real_T c20_b_CFC;
  real_T c20_b_GAC;
  int32_T c20_i3;
  real_T c20_b_q[2];
  uint32_T c20_debug_family_var_map[9];
  real_T c20_fcTN[2];
  real_T c20_fcD;
  real_T c20_nargin = 4.0;
  real_T c20_nargout = 1.0;
  real_T c20_b_Fa;
  real_T c20_theta;
  uint32_T c20_b_debug_family_var_map[4];
  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  real_T c20_rot[4];
  real_T c20_x;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_f_x;
  real_T c20_g_x;
  real_T c20_h_x;
  int32_T c20_i4;
  int32_T c20_i5;
  int32_T c20_i6;
  int32_T c20_i7;
  real_T c20_a[4];
  int32_T c20_i8;
  real_T c20_b[2];
  int32_T c20_i9;
  int32_T c20_i10;
  real_T c20_dv0[2];
  int32_T c20_i11;
  real_T c20_b_a[4];
  int32_T c20_i12;
  real_T c20_b_b[2];
  int32_T c20_i13;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  for (c20_i0 = 0; c20_i0 < 2; c20_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c20_FcSense)[c20_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_CFC, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_GAC, 2U);
  for (c20_i1 = 0; c20_i1 < 2; c20_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c20_q)[c20_i1], 3U);
  }

  chartInstance->c20_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  c20_hoistedGlobal = *chartInstance->c20_CFC;
  c20_b_hoistedGlobal = *chartInstance->c20_GAC;
  for (c20_i2 = 0; c20_i2 < 2; c20_i2++) {
    c20_b_FcSense[c20_i2] = (*chartInstance->c20_FcSense)[c20_i2];
  }

  c20_b_CFC = c20_hoistedGlobal;
  c20_b_GAC = c20_b_hoistedGlobal;
  for (c20_i3 = 0; c20_i3 < 2; c20_i3++) {
    c20_b_q[c20_i3] = (*chartInstance->c20_q)[c20_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_fcTN, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_fcD, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 2U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 3U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_b_FcSense, 4U, c20_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_b_CFC, 5U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_b_GAC, 6U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_b_q, 7U, c20_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_Fa, 8U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_theta = c20_b_q[0] + c20_b_q[1];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c20_b_debug_family_names,
    c20_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_theta, 2U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_rot, 3U, c20_d_sf_marshallOut,
    c20_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 17);
  c20_x = c20_theta;
  c20_b_x = c20_x;
  c20_b_x = muDoubleScalarCos(c20_b_x);
  c20_c_x = c20_theta;
  c20_d_x = c20_c_x;
  c20_d_x = muDoubleScalarSin(c20_d_x);
  c20_e_x = c20_theta;
  c20_f_x = c20_e_x;
  c20_f_x = muDoubleScalarSin(c20_f_x);
  c20_g_x = c20_theta;
  c20_h_x = c20_g_x;
  c20_h_x = muDoubleScalarCos(c20_h_x);
  c20_rot[0] = c20_b_x;
  c20_rot[2] = -c20_d_x;
  c20_rot[1] = c20_f_x;
  c20_rot[3] = c20_h_x;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  c20_i4 = 0;
  for (c20_i5 = 0; c20_i5 < 2; c20_i5++) {
    c20_i6 = 0;
    for (c20_i7 = 0; c20_i7 < 2; c20_i7++) {
      c20_a[c20_i7 + c20_i4] = c20_rot[c20_i6 + c20_i5];
      c20_i6 += 2;
    }

    c20_i4 += 2;
  }

  for (c20_i8 = 0; c20_i8 < 2; c20_i8++) {
    c20_b[c20_i8] = -c20_b_FcSense[c20_i8];
  }

  c20_eml_scalar_eg(chartInstance);
  c20_eml_scalar_eg(chartInstance);
  for (c20_i9 = 0; c20_i9 < 2; c20_i9++) {
    c20_fcTN[c20_i9] = 0.0;
  }

  for (c20_i10 = 0; c20_i10 < 2; c20_i10++) {
    c20_dv0[c20_i10] = 0.0;
  }

  for (c20_i11 = 0; c20_i11 < 4; c20_i11++) {
    c20_b_a[c20_i11] = c20_a[c20_i11];
  }

  for (c20_i12 = 0; c20_i12 < 2; c20_i12++) {
    c20_b_b[c20_i12] = c20_b[c20_i12];
  }

  c20_b_eml_xgemm(chartInstance, c20_b_a, c20_b_b, c20_dv0);
  for (c20_i13 = 0; c20_i13 < 2; c20_i13++) {
    c20_fcTN[c20_i13] = c20_dv0[c20_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 5);
  c20_fcD = c20_fcTN[1];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c20_fcD, 0.0, -1, 4U,
        c20_fcD > 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 7);
    c20_b_Fa = c20_b_CFC;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 9);
    c20_b_Fa = c20_b_GAC;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c20_Fa = c20_b_Fa;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_Fa, 4U);
}

static void mdl_start_c20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc20_hybridSysSim(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  (void)c20_chartNumber;
  (void)c20_instanceNumber;
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static real_T c20_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_b_Fa, const char_T *c20_identifier)
{
  real_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_Fa),
    &c20_thisId);
  sf_mex_destroy(&c20_b_Fa);
  return c20_y;
}

static real_T c20_b_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_Fa;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_b_Fa = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_Fa),
    &c20_thisId);
  sf_mex_destroy(&c20_b_Fa);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i14;
  real_T c20_b_inData[2];
  int32_T c20_i15;
  real_T c20_u[2];
  const mxArray *c20_y = NULL;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i14 = 0; c20_i14 < 2; c20_i14++) {
    c20_b_inData[c20_i14] = (*(real_T (*)[2])c20_inData)[c20_i14];
  }

  for (c20_i15 = 0; c20_i15 < 2; c20_i15++) {
    c20_u[c20_i15] = c20_b_inData[c20_i15];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i16;
  real_T c20_b_inData[2];
  int32_T c20_i17;
  real_T c20_u[2];
  const mxArray *c20_y = NULL;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i16 = 0; c20_i16 < 2; c20_i16++) {
    c20_b_inData[c20_i16] = (*(real_T (*)[2])c20_inData)[c20_i16];
  }

  for (c20_i17 = 0; c20_i17 < 2; c20_i17++) {
    c20_u[c20_i17] = c20_b_inData[c20_i17];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_c_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[2])
{
  real_T c20_dv1[2];
  int32_T c20_i18;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c20_i18 = 0; c20_i18 < 2; c20_i18++) {
    c20_y[c20_i18] = c20_dv1[c20_i18];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_fcTN;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[2];
  int32_T c20_i19;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_fcTN = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_fcTN), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_fcTN);
  for (c20_i19 = 0; c20_i19 < 2; c20_i19++) {
    (*(real_T (*)[2])c20_outData)[c20_i19] = c20_y[c20_i19];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i20;
  int32_T c20_i21;
  int32_T c20_i22;
  real_T c20_b_inData[4];
  int32_T c20_i23;
  int32_T c20_i24;
  int32_T c20_i25;
  real_T c20_u[4];
  const mxArray *c20_y = NULL;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i20 = 0;
  for (c20_i21 = 0; c20_i21 < 2; c20_i21++) {
    for (c20_i22 = 0; c20_i22 < 2; c20_i22++) {
      c20_b_inData[c20_i22 + c20_i20] = (*(real_T (*)[4])c20_inData)[c20_i22 +
        c20_i20];
    }

    c20_i20 += 2;
  }

  c20_i23 = 0;
  for (c20_i24 = 0; c20_i24 < 2; c20_i24++) {
    for (c20_i25 = 0; c20_i25 < 2; c20_i25++) {
      c20_u[c20_i25 + c20_i23] = c20_b_inData[c20_i25 + c20_i23];
    }

    c20_i23 += 2;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_d_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[4])
{
  real_T c20_dv2[4];
  int32_T c20_i26;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv2, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c20_i26 = 0; c20_i26 < 4; c20_i26++) {
    c20_y[c20_i26] = c20_dv2[c20_i26];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_rot;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[4];
  int32_T c20_i27;
  int32_T c20_i28;
  int32_T c20_i29;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_rot = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_rot), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_rot);
  c20_i27 = 0;
  for (c20_i28 = 0; c20_i28 < 2; c20_i28++) {
    for (c20_i29 = 0; c20_i29 < 2; c20_i29++) {
      (*(real_T (*)[4])c20_outData)[c20_i29 + c20_i27] = c20_y[c20_i29 + c20_i27];
    }

    c20_i27 += 2;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_createstruct("structure", 2, 17, 1),
                false);
  c20_info_helper(&c20_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(const mxArray **c20_info)
{
  const mxArray *c20_rhs0 = NULL;
  const mxArray *c20_lhs0 = NULL;
  const mxArray *c20_rhs1 = NULL;
  const mxArray *c20_lhs1 = NULL;
  const mxArray *c20_rhs2 = NULL;
  const mxArray *c20_lhs2 = NULL;
  const mxArray *c20_rhs3 = NULL;
  const mxArray *c20_lhs3 = NULL;
  const mxArray *c20_rhs4 = NULL;
  const mxArray *c20_lhs4 = NULL;
  const mxArray *c20_rhs5 = NULL;
  const mxArray *c20_lhs5 = NULL;
  const mxArray *c20_rhs6 = NULL;
  const mxArray *c20_lhs6 = NULL;
  const mxArray *c20_rhs7 = NULL;
  const mxArray *c20_lhs7 = NULL;
  const mxArray *c20_rhs8 = NULL;
  const mxArray *c20_lhs8 = NULL;
  const mxArray *c20_rhs9 = NULL;
  const mxArray *c20_lhs9 = NULL;
  const mxArray *c20_rhs10 = NULL;
  const mxArray *c20_lhs10 = NULL;
  const mxArray *c20_rhs11 = NULL;
  const mxArray *c20_lhs11 = NULL;
  const mxArray *c20_rhs12 = NULL;
  const mxArray *c20_lhs12 = NULL;
  const mxArray *c20_rhs13 = NULL;
  const mxArray *c20_lhs13 = NULL;
  const mxArray *c20_rhs14 = NULL;
  const mxArray *c20_lhs14 = NULL;
  const mxArray *c20_rhs15 = NULL;
  const mxArray *c20_lhs15 = NULL;
  const mxArray *c20_rhs16 = NULL;
  const mxArray *c20_lhs16 = NULL;
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c20_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286786322U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c20_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1395292504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c20_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286786336U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c20_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c20_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c20_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c20_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c20_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c20_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c20_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c20_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c20_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c20_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c20_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c20_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c20_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 16);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c20_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c20_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs16), "lhs", "lhs",
                  16);
  sf_mex_destroy(&c20_rhs0);
  sf_mex_destroy(&c20_lhs0);
  sf_mex_destroy(&c20_rhs1);
  sf_mex_destroy(&c20_lhs1);
  sf_mex_destroy(&c20_rhs2);
  sf_mex_destroy(&c20_lhs2);
  sf_mex_destroy(&c20_rhs3);
  sf_mex_destroy(&c20_lhs3);
  sf_mex_destroy(&c20_rhs4);
  sf_mex_destroy(&c20_lhs4);
  sf_mex_destroy(&c20_rhs5);
  sf_mex_destroy(&c20_lhs5);
  sf_mex_destroy(&c20_rhs6);
  sf_mex_destroy(&c20_lhs6);
  sf_mex_destroy(&c20_rhs7);
  sf_mex_destroy(&c20_lhs7);
  sf_mex_destroy(&c20_rhs8);
  sf_mex_destroy(&c20_lhs8);
  sf_mex_destroy(&c20_rhs9);
  sf_mex_destroy(&c20_lhs9);
  sf_mex_destroy(&c20_rhs10);
  sf_mex_destroy(&c20_lhs10);
  sf_mex_destroy(&c20_rhs11);
  sf_mex_destroy(&c20_lhs11);
  sf_mex_destroy(&c20_rhs12);
  sf_mex_destroy(&c20_lhs12);
  sf_mex_destroy(&c20_rhs13);
  sf_mex_destroy(&c20_lhs13);
  sf_mex_destroy(&c20_rhs14);
  sf_mex_destroy(&c20_lhs14);
  sf_mex_destroy(&c20_rhs15);
  sf_mex_destroy(&c20_lhs15);
  sf_mex_destroy(&c20_rhs16);
  sf_mex_destroy(&c20_lhs16);
}

static const mxArray *c20_emlrt_marshallOut(const char * c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c20_u)), false);
  return c20_y;
}

static const mxArray *c20_b_emlrt_marshallOut(const uint32_T c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 7, 0U, 0U, 0U, 0), false);
  return c20_y;
}

static void c20_eml_scalar_eg(SFc20_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c20_eml_xgemm(SFc20_hybridSysSimInstanceStruct *chartInstance,
  real_T c20_A[4], real_T c20_B[2], real_T c20_C[2], real_T c20_b_C[2])
{
  int32_T c20_i30;
  int32_T c20_i31;
  real_T c20_b_A[4];
  int32_T c20_i32;
  real_T c20_b_B[2];
  for (c20_i30 = 0; c20_i30 < 2; c20_i30++) {
    c20_b_C[c20_i30] = c20_C[c20_i30];
  }

  for (c20_i31 = 0; c20_i31 < 4; c20_i31++) {
    c20_b_A[c20_i31] = c20_A[c20_i31];
  }

  for (c20_i32 = 0; c20_i32 < 2; c20_i32++) {
    c20_b_B[c20_i32] = c20_B[c20_i32];
  }

  c20_b_eml_xgemm(chartInstance, c20_b_A, c20_b_B, c20_b_C);
}

static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_e_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i33;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i33, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i33;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_f_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_hybridSysSim, const char_T *
  c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_hybridSysSim), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_hybridSysSim);
  return c20_y;
}

static uint8_T c20_g_emlrt_marshallIn(SFc20_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_eml_xgemm(SFc20_hybridSysSimInstanceStruct *chartInstance,
  real_T c20_A[4], real_T c20_B[2], real_T c20_C[2])
{
  int32_T c20_i34;
  int32_T c20_i35;
  int32_T c20_i36;
  (void)chartInstance;
  for (c20_i34 = 0; c20_i34 < 2; c20_i34++) {
    c20_C[c20_i34] = 0.0;
    c20_i35 = 0;
    for (c20_i36 = 0; c20_i36 < 2; c20_i36++) {
      c20_C[c20_i34] += c20_A[c20_i35 + c20_i34] * c20_B[c20_i36];
      c20_i35 += 2;
    }
  }
}

static void init_dsm_address_info(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc20_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c20_FcSense = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c20_CFC = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c20_GAC = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c20_q = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c20_Fa = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c20_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3868441616U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3340335550U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2757349670U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3332283687U);
}

mxArray* sf_c20_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c20_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("38TcD5KSPOHlcpW6H8Ck7C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
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
    mxArray* mxPostCodegenInfo = sf_c20_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c20_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c20_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c20_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Fa\",},{M[8],M[0],T\"is_active_c20_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           20,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"CFC");
          _SFD_SET_DATA_PROPS(2,1,1,0,"GAC");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Fa");
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
        _SFD_CV_INIT_EML(0,1,2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,229);
        _SFD_CV_INIT_EML_FCN(0,1,"rotMat",235,-1,502);
        _SFD_CV_INIT_EML_IF(0,1,0,163,172,195,225);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,166,171,-1,4);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c20_FcSense);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c20_CFC);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c20_GAC);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c20_q);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c20_Fa);
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
  return "8SU1t3D5E4uGNHkYVG7Y5E";
}

static void sf_opaque_initialize_c20_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_hybridSysSim(void *chartInstanceVar)
{
  enable_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_hybridSysSim(void *chartInstanceVar)
{
  disable_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c20_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c20_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c20_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*)
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
  initSimStructsc20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_hybridSysSim(SimStruct *S)
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
    initialize_params_c20_hybridSysSim((SFc20_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3359918140U));
  ssSetChecksum1(S,(1191770296U));
  ssSetChecksum2(S,(3660611556U));
  ssSetChecksum3(S,(1475480586U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_hybridSysSim(SimStruct *S)
{
  SFc20_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc20_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c20_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c20_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c20_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c20_hybridSysSim;
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

void c20_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
