/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c22_hybridSysSim.h"
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
static const char * c22_debug_family_names[10] = { "lP", "lD", "mD", "beta", "C",
  "nargin", "nargout", "theta", "x1DotEstimated", "coriolis" };

/* Function Declarations */
static void initialize_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance);
static void c22_update_debugger_state_c22_hybridSysSim
  (SFc22_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c22_hybridSysSim
  (SFc22_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_st);
static void finalize_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c22_b_coriolis, const char_T *c22_identifier, real_T c22_y[4]);
static void c22_b_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[4]);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real_T c22_c_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static void c22_info_helper(const mxArray **c22_info);
static const mxArray *c22_emlrt_marshallOut(const char * c22_u);
static const mxArray *c22_b_emlrt_marshallOut(const uint32_T c22_u);
static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_d_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static uint8_T c22_e_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_hybridSysSim, const char_T *
  c22_identifier);
static uint8_T c22_f_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void init_dsm_address_info(SFc22_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc22_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_is_active_c22_hybridSysSim = 0U;
}

static void initialize_params_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c22_update_debugger_state_c22_hybridSysSim
  (SFc22_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c22_hybridSysSim
  (SFc22_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  int32_T c22_i0;
  real_T c22_u[4];
  const mxArray *c22_b_y = NULL;
  uint8_T c22_hoistedGlobal;
  uint8_T c22_b_u;
  const mxArray *c22_c_y = NULL;
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellmatrix(2, 1), false);
  for (c22_i0 = 0; c22_i0 < 4; c22_i0++) {
    c22_u[c22_i0] = (*chartInstance->c22_coriolis)[c22_i0];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 2, 2, 2),
                false);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_hoistedGlobal = chartInstance->c22_is_active_c22_hybridSysSim;
  c22_b_u = c22_hoistedGlobal;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 1, c22_c_y);
  sf_mex_assign(&c22_st, c22_y, false);
  return c22_st;
}

static void set_sim_state_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_st)
{
  const mxArray *c22_u;
  real_T c22_dv0[4];
  int32_T c22_i1;
  chartInstance->c22_doneDoubleBufferReInit = true;
  c22_u = sf_mex_dup(c22_st);
  c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 0)),
                       "coriolis", c22_dv0);
  for (c22_i1 = 0; c22_i1 < 4; c22_i1++) {
    (*chartInstance->c22_coriolis)[c22_i1] = c22_dv0[c22_i1];
  }

  chartInstance->c22_is_active_c22_hybridSysSim = c22_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 1)),
     "is_active_c22_hybridSysSim");
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_hybridSysSim(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c22_i2;
  int32_T c22_i3;
  real_T c22_b_theta[2];
  int32_T c22_i4;
  real_T c22_b_x1DotEstimated[2];
  uint32_T c22_debug_family_var_map[10];
  real_T c22_lP;
  real_T c22_lD;
  real_T c22_mD;
  real_T c22_beta;
  real_T c22_C[4];
  real_T c22_nargin = 2.0;
  real_T c22_nargout = 1.0;
  real_T c22_b_coriolis[4];
  real_T c22_x;
  real_T c22_b_x;
  real_T c22_c_x;
  real_T c22_d_x;
  real_T c22_e_x;
  real_T c22_f_x;
  int32_T c22_i5;
  int32_T c22_i6;
  int32_T c22_i7;
  int32_T c22_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  for (c22_i2 = 0; c22_i2 < 2; c22_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c22_theta)[c22_i2], 0U);
  }

  chartInstance->c22_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  for (c22_i3 = 0; c22_i3 < 2; c22_i3++) {
    c22_b_theta[c22_i3] = (*chartInstance->c22_theta)[c22_i3];
  }

  for (c22_i4 = 0; c22_i4 < 2; c22_i4++) {
    c22_b_x1DotEstimated[c22_i4] = (*chartInstance->c22_x1DotEstimated)[c22_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c22_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_lP, 0U, c22_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_lD, 1U, c22_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_mD, 2U, c22_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_beta, 3U, c22_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_C, 4U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 5U, c22_c_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 6U, c22_c_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c22_b_theta, 7U, c22_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c22_b_x1DotEstimated, 8U, c22_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_b_coriolis, 9U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 2);
  c22_lP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 3);
  c22_lD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 4);
  c22_mD = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 6);
  c22_beta = 0.0001;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 8);
  c22_x = c22_b_theta[1];
  c22_b_x = c22_x;
  c22_b_x = muDoubleScalarSin(c22_b_x);
  c22_c_x = c22_b_theta[1];
  c22_d_x = c22_c_x;
  c22_d_x = muDoubleScalarSin(c22_d_x);
  c22_e_x = c22_b_theta[1];
  c22_f_x = c22_e_x;
  c22_f_x = muDoubleScalarSin(c22_f_x);
  c22_C[0] = -0.0001 * c22_b_x * c22_b_x1DotEstimated[1];
  c22_C[2] = -0.0001 * c22_d_x * (c22_b_x1DotEstimated[0] +
    c22_b_x1DotEstimated[1]);
  c22_C[1] = 0.0001 * c22_f_x * c22_b_x1DotEstimated[0];
  c22_C[3] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 11);
  for (c22_i5 = 0; c22_i5 < 4; c22_i5++) {
    c22_b_coriolis[c22_i5] = c22_C[c22_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c22_i6 = 0; c22_i6 < 4; c22_i6++) {
    (*chartInstance->c22_coriolis)[c22_i6] = c22_b_coriolis[c22_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c22_i7 = 0; c22_i7 < 4; c22_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c22_coriolis)[c22_i7], 1U);
  }

  for (c22_i8 = 0; c22_i8 < 2; c22_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c22_x1DotEstimated)[c22_i8], 2U);
  }
}

static void mdl_start_c22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc22_hybridSysSim(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber)
{
  (void)c22_machineNumber;
  (void)c22_chartNumber;
  (void)c22_instanceNumber;
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i9;
  int32_T c22_i10;
  int32_T c22_i11;
  real_T c22_b_inData[4];
  int32_T c22_i12;
  int32_T c22_i13;
  int32_T c22_i14;
  real_T c22_u[4];
  const mxArray *c22_y = NULL;
  SFc22_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc22_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_i9 = 0;
  for (c22_i10 = 0; c22_i10 < 2; c22_i10++) {
    for (c22_i11 = 0; c22_i11 < 2; c22_i11++) {
      c22_b_inData[c22_i11 + c22_i9] = (*(real_T (*)[4])c22_inData)[c22_i11 +
        c22_i9];
    }

    c22_i9 += 2;
  }

  c22_i12 = 0;
  for (c22_i13 = 0; c22_i13 < 2; c22_i13++) {
    for (c22_i14 = 0; c22_i14 < 2; c22_i14++) {
      c22_u[c22_i14 + c22_i12] = c22_b_inData[c22_i14 + c22_i12];
    }

    c22_i12 += 2;
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static void c22_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c22_b_coriolis, const char_T *c22_identifier, real_T c22_y[4])
{
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_coriolis), &c22_thisId,
    c22_y);
  sf_mex_destroy(&c22_b_coriolis);
}

static void c22_b_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[4])
{
  real_T c22_dv1[4];
  int32_T c22_i15;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv1, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c22_i15 = 0; c22_i15 < 4; c22_i15++) {
    c22_y[c22_i15] = c22_dv1[c22_i15];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_coriolis;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[4];
  int32_T c22_i16;
  int32_T c22_i17;
  int32_T c22_i18;
  SFc22_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc22_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c22_b_coriolis = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_coriolis), &c22_thisId,
    c22_y);
  sf_mex_destroy(&c22_b_coriolis);
  c22_i16 = 0;
  for (c22_i17 = 0; c22_i17 < 2; c22_i17++) {
    for (c22_i18 = 0; c22_i18 < 2; c22_i18++) {
      (*(real_T (*)[4])c22_outData)[c22_i18 + c22_i16] = c22_y[c22_i18 + c22_i16];
    }

    c22_i16 += 2;
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i19;
  real_T c22_b_inData[2];
  int32_T c22_i20;
  real_T c22_u[2];
  const mxArray *c22_y = NULL;
  SFc22_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc22_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i19 = 0; c22_i19 < 2; c22_i19++) {
    c22_b_inData[c22_i19] = (*(real_T (*)[2])c22_inData)[c22_i19];
  }

  for (c22_i20 = 0; c22_i20 < 2; c22_i20++) {
    c22_u[c22_i20] = c22_b_inData[c22_i20];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc22_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static real_T c22_c_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_nargout;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y;
  SFc22_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc22_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c22_nargout = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_nargout),
    &c22_thisId);
  sf_mex_destroy(&c22_nargout);
  *(real_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_createstruct("structure", 2, 9, 1),
                false);
  c22_info_helper(&c22_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c22_nameCaptureInfo);
  return c22_nameCaptureInfo;
}

static void c22_info_helper(const mxArray **c22_info)
{
  const mxArray *c22_rhs0 = NULL;
  const mxArray *c22_lhs0 = NULL;
  const mxArray *c22_rhs1 = NULL;
  const mxArray *c22_lhs1 = NULL;
  const mxArray *c22_rhs2 = NULL;
  const mxArray *c22_lhs2 = NULL;
  const mxArray *c22_rhs3 = NULL;
  const mxArray *c22_lhs3 = NULL;
  const mxArray *c22_rhs4 = NULL;
  const mxArray *c22_lhs4 = NULL;
  const mxArray *c22_rhs5 = NULL;
  const mxArray *c22_lhs5 = NULL;
  const mxArray *c22_rhs6 = NULL;
  const mxArray *c22_lhs6 = NULL;
  const mxArray *c22_rhs7 = NULL;
  const mxArray *c22_lhs7 = NULL;
  const mxArray *c22_rhs8 = NULL;
  const mxArray *c22_lhs8 = NULL;
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c22_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c22_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c22_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c22_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286786396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c22_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c22_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c22_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("sin"), "name", "name", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1395292504U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c22_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c22_info, c22_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(1286786336U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c22_info, c22_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c22_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c22_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c22_info, sf_mex_duplicatearraysafe(&c22_lhs8), "lhs", "lhs",
                  8);
  sf_mex_destroy(&c22_rhs0);
  sf_mex_destroy(&c22_lhs0);
  sf_mex_destroy(&c22_rhs1);
  sf_mex_destroy(&c22_lhs1);
  sf_mex_destroy(&c22_rhs2);
  sf_mex_destroy(&c22_lhs2);
  sf_mex_destroy(&c22_rhs3);
  sf_mex_destroy(&c22_lhs3);
  sf_mex_destroy(&c22_rhs4);
  sf_mex_destroy(&c22_lhs4);
  sf_mex_destroy(&c22_rhs5);
  sf_mex_destroy(&c22_lhs5);
  sf_mex_destroy(&c22_rhs6);
  sf_mex_destroy(&c22_lhs6);
  sf_mex_destroy(&c22_rhs7);
  sf_mex_destroy(&c22_lhs7);
  sf_mex_destroy(&c22_rhs8);
  sf_mex_destroy(&c22_lhs8);
}

static const mxArray *c22_emlrt_marshallOut(const char * c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c22_u)), false);
  return c22_y;
}

static const mxArray *c22_b_emlrt_marshallOut(const uint32_T c22_u)
{
  const mxArray *c22_y = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 7, 0U, 0U, 0U, 0), false);
  return c22_y;
}

static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc22_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static int32_T c22_d_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i21;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i21, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i21;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc22_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static uint8_T c22_e_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_hybridSysSim, const char_T *
  c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_active_c22_hybridSysSim), &c22_thisId);
  sf_mex_destroy(&c22_b_is_active_c22_hybridSysSim);
  return c22_y;
}

static uint8_T c22_f_emlrt_marshallIn(SFc22_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void init_dsm_address_info(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc22_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c22_theta = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c22_coriolis = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c22_x1DotEstimated = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
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

void sf_c22_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3582803434U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(500030592U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4248331904U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3719602742U);
}

mxArray* sf_c22_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c22_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("s4n9yvMf7tawY88m93IZaE");
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
    mxArray* mxPostCodegenInfo = sf_c22_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c22_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c22_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c22_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c22_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c22_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"coriolis\",},{M[8],M[0],T\"is_active_c22_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc22_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           22,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"coriolis");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x1DotEstimated");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,402);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)
            c22_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c22_theta);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c22_coriolis);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c22_x1DotEstimated);
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
  return "fW5WKNIAfuC3dkdNLyW34G";
}

static void sf_opaque_initialize_c22_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c22_hybridSysSim(void *chartInstanceVar)
{
  enable_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c22_hybridSysSim(void *chartInstanceVar)
{
  disable_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c22_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c22_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c22_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c22_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*)
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
  initSimStructsc22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_hybridSysSim(SimStruct *S)
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
    initialize_params_c22_hybridSysSim((SFc22_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c22_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,22,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,22);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2521072438U));
  ssSetChecksum1(S,(4135672968U));
  ssSetChecksum2(S,(792387694U));
  ssSetChecksum3(S,(2145643093U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_hybridSysSim(SimStruct *S)
{
  SFc22_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc22_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc22_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c22_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c22_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c22_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c22_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c22_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c22_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c22_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c22_hybridSysSim;
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

void c22_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
