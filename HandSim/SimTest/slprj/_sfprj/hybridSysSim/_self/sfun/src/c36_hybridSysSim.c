/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c36_hybridSysSim.h"
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
static const char * c36_debug_family_names[6] = { "nargin", "nargout",
  "thetaDotHat", "thetaDotDer", "thetaDotMod", "thetaDot" };

/* Function Declarations */
static void initialize_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance);
static void c36_update_debugger_state_c36_hybridSysSim
  (SFc36_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c36_hybridSysSim
  (SFc36_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_st);
static void finalize_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber, uint32_T c36_instanceNumber);
static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c36_b_thetaDot, const char_T *c36_identifier, real_T c36_y[2]);
static void c36_b_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId,
  real_T c36_y[2]);
static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static real_T c36_c_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static int32_T c36_d_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static uint8_T c36_e_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_b_is_active_c36_hybridSysSim, const char_T *
  c36_identifier);
static uint8_T c36_f_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void init_dsm_address_info(SFc36_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc36_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c36_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c36_is_active_c36_hybridSysSim = 0U;
}

static void initialize_params_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c36_update_debugger_state_c36_hybridSysSim
  (SFc36_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c36_hybridSysSim
  (SFc36_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c36_st;
  const mxArray *c36_y = NULL;
  int32_T c36_i0;
  real_T c36_u[2];
  const mxArray *c36_b_y = NULL;
  uint8_T c36_hoistedGlobal;
  uint8_T c36_b_u;
  const mxArray *c36_c_y = NULL;
  c36_st = NULL;
  c36_st = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_createcellmatrix(2, 1), false);
  for (c36_i0 = 0; c36_i0 < 2; c36_i0++) {
    c36_u[c36_i0] = (*chartInstance->c36_thetaDot)[c36_i0];
  }

  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c36_y, 0, c36_b_y);
  c36_hoistedGlobal = chartInstance->c36_is_active_c36_hybridSysSim;
  c36_b_u = c36_hoistedGlobal;
  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", &c36_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c36_y, 1, c36_c_y);
  sf_mex_assign(&c36_st, c36_y, false);
  return c36_st;
}

static void set_sim_state_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_st)
{
  const mxArray *c36_u;
  real_T c36_dv0[2];
  int32_T c36_i1;
  chartInstance->c36_doneDoubleBufferReInit = true;
  c36_u = sf_mex_dup(c36_st);
  c36_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 0)),
                       "thetaDot", c36_dv0);
  for (c36_i1 = 0; c36_i1 < 2; c36_i1++) {
    (*chartInstance->c36_thetaDot)[c36_i1] = c36_dv0[c36_i1];
  }

  chartInstance->c36_is_active_c36_hybridSysSim = c36_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 1)),
     "is_active_c36_hybridSysSim");
  sf_mex_destroy(&c36_u);
  c36_update_debugger_state_c36_hybridSysSim(chartInstance);
  sf_mex_destroy(&c36_st);
}

static void finalize_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c36_i2;
  int32_T c36_i3;
  int32_T c36_i4;
  int32_T c36_i5;
  real_T c36_b_thetaDotHat[2];
  int32_T c36_i6;
  real_T c36_b_thetaDotDer[2];
  int32_T c36_i7;
  real_T c36_b_thetaDotMod[2];
  uint32_T c36_debug_family_var_map[6];
  real_T c36_nargin = 3.0;
  real_T c36_nargout = 1.0;
  real_T c36_b_thetaDot[2];
  int32_T c36_i8;
  int32_T c36_i9;
  int32_T c36_i10;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 33U, chartInstance->c36_sfEvent);
  for (c36_i2 = 0; c36_i2 < 2; c36_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c36_thetaDotHat)[c36_i2], 0U);
  }

  for (c36_i3 = 0; c36_i3 < 2; c36_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c36_thetaDotDer)[c36_i3], 1U);
  }

  for (c36_i4 = 0; c36_i4 < 2; c36_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c36_thetaDotMod)[c36_i4], 2U);
  }

  chartInstance->c36_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 33U, chartInstance->c36_sfEvent);
  for (c36_i5 = 0; c36_i5 < 2; c36_i5++) {
    c36_b_thetaDotHat[c36_i5] = (*chartInstance->c36_thetaDotHat)[c36_i5];
  }

  for (c36_i6 = 0; c36_i6 < 2; c36_i6++) {
    c36_b_thetaDotDer[c36_i6] = (*chartInstance->c36_thetaDotDer)[c36_i6];
  }

  for (c36_i7 = 0; c36_i7 < 2; c36_i7++) {
    c36_b_thetaDotMod[c36_i7] = (*chartInstance->c36_thetaDotMod)[c36_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c36_debug_family_names,
    c36_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargin, 0U, c36_c_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargout, 1U, c36_c_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c36_b_thetaDotHat, 2U, c36_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c36_b_thetaDotDer, 3U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c36_b_thetaDotMod, 4U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_b_thetaDot, 5U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 4);
  for (c36_i8 = 0; c36_i8 < 2; c36_i8++) {
    c36_b_thetaDot[c36_i8] = c36_b_thetaDotMod[c36_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c36_i9 = 0; c36_i9 < 2; c36_i9++) {
    (*chartInstance->c36_thetaDot)[c36_i9] = c36_b_thetaDot[c36_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c36_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c36_i10 = 0; c36_i10 < 2; c36_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c36_thetaDot)[c36_i10], 3U);
  }
}

static void mdl_start_c36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc36_hybridSysSim(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber, uint32_T c36_instanceNumber)
{
  (void)c36_machineNumber;
  (void)c36_chartNumber;
  (void)c36_instanceNumber;
}

static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i11;
  real_T c36_b_inData[2];
  int32_T c36_i12;
  real_T c36_u[2];
  const mxArray *c36_y = NULL;
  SFc36_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc36_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i11 = 0; c36_i11 < 2; c36_i11++) {
    c36_b_inData[c36_i11] = (*(real_T (*)[2])c36_inData)[c36_i11];
  }

  for (c36_i12 = 0; c36_i12 < 2; c36_i12++) {
    c36_u[c36_i12] = c36_b_inData[c36_i12];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static void c36_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c36_b_thetaDot, const char_T *c36_identifier, real_T c36_y[2])
{
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_thetaDot), &c36_thisId,
    c36_y);
  sf_mex_destroy(&c36_b_thetaDot);
}

static void c36_b_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId,
  real_T c36_y[2])
{
  real_T c36_dv1[2];
  int32_T c36_i13;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c36_i13 = 0; c36_i13 < 2; c36_i13++) {
    c36_y[c36_i13] = c36_dv1[c36_i13];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_thetaDot;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[2];
  int32_T c36_i14;
  SFc36_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc36_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c36_b_thetaDot = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_thetaDot), &c36_thisId,
    c36_y);
  sf_mex_destroy(&c36_b_thetaDot);
  for (c36_i14 = 0; c36_i14 < 2; c36_i14++) {
    (*(real_T (*)[2])c36_outData)[c36_i14] = c36_y[c36_i14];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i15;
  real_T c36_b_inData[2];
  int32_T c36_i16;
  real_T c36_u[2];
  const mxArray *c36_y = NULL;
  SFc36_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc36_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i15 = 0; c36_i15 < 2; c36_i15++) {
    c36_b_inData[c36_i15] = (*(real_T (*)[2])c36_inData)[c36_i15];
  }

  for (c36_i16 = 0; c36_i16 < 2; c36_i16++) {
    c36_u[c36_i16] = c36_b_inData[c36_i16];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  real_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc36_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(real_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static real_T c36_c_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  real_T c36_y;
  real_T c36_d0;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_d0, 1, 0, 0U, 0, 0U, 0);
  c36_y = c36_d0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_nargout;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y;
  SFc36_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc36_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c36_nargout = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_nargout),
    &c36_thisId);
  sf_mex_destroy(&c36_nargout);
  *(real_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

const mxArray *sf_c36_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c36_nameCaptureInfo = NULL;
  c36_nameCaptureInfo = NULL;
  sf_mex_assign(&c36_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c36_nameCaptureInfo;
}

static const mxArray *c36_d_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc36_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(int32_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static int32_T c36_d_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  int32_T c36_y;
  int32_T c36_i17;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_i17, 1, 6, 0U, 0, 0U, 0);
  c36_y = c36_i17;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_sfEvent;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  int32_T c36_y;
  SFc36_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc36_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c36_b_sfEvent = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_sfEvent),
    &c36_thisId);
  sf_mex_destroy(&c36_b_sfEvent);
  *(int32_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

static uint8_T c36_e_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_b_is_active_c36_hybridSysSim, const char_T *
  c36_identifier)
{
  uint8_T c36_y;
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c36_b_is_active_c36_hybridSysSim), &c36_thisId);
  sf_mex_destroy(&c36_b_is_active_c36_hybridSysSim);
  return c36_y;
}

static uint8_T c36_f_emlrt_marshallIn(SFc36_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  uint8_T c36_y;
  uint8_T c36_u0;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_u0, 1, 3, 0U, 0, 0U, 0);
  c36_y = c36_u0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void init_dsm_address_info(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc36_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c36_thetaDotHat = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c36_thetaDotDer = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c36_thetaDotMod = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c36_thetaDot = (real_T (*)[2])ssGetOutputPortSignal_wrapper
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

void sf_c36_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2217111362U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1144838715U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1402618818U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(923041464U);
}

mxArray* sf_c36_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c36_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ph0QHFP6jHv3PWG4cPhVeE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxArray* mxPostCodegenInfo = sf_c36_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c36_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c36_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c36_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c36_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c36_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"thetaDot\",},{M[8],M[0],T\"is_active_c36_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c36_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc36_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc36_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           36,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"thetaDotHat");
          _SFD_SET_DATA_PROPS(1,1,1,0,"thetaDotDer");
          _SFD_SET_DATA_PROPS(2,1,1,0,"thetaDotMod");
          _SFD_SET_DATA_PROPS(3,2,0,1,"thetaDot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,106);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)
            c36_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c36_thetaDotHat);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c36_thetaDotDer);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c36_thetaDotMod);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c36_thetaDot);
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
  return "yliQf786KFCvbaiMNgDmwC";
}

static void sf_opaque_initialize_c36_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc36_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c36_hybridSysSim(void *chartInstanceVar)
{
  enable_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c36_hybridSysSim(void *chartInstanceVar)
{
  disable_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c36_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c36_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c36_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c36_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc36_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*)
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
  initSimStructsc36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c36_hybridSysSim(SimStruct *S)
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
    initialize_params_c36_hybridSysSim((SFc36_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c36_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      36);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,36,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,36,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,36);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,36,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,36,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,36);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2584687363U));
  ssSetChecksum1(S,(3749141977U));
  ssSetChecksum2(S,(3406516330U));
  ssSetChecksum3(S,(3424523081U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c36_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c36_hybridSysSim(SimStruct *S)
{
  SFc36_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc36_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc36_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc36_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c36_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c36_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c36_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c36_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c36_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c36_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c36_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c36_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c36_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c36_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c36_hybridSysSim;
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

void c36_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c36_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c36_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c36_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c36_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
