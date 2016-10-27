/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c27_hybridSysSim.h"
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
static const char * c27_debug_family_names[17] = { "kP", "kD", "rP", "rD", "K",
  "Ja", "theta0", "Kp", "Kd", "tauA", "nargin", "nargout", "FcRef", "FcSense",
  "theta", "thetaDot", "fa" };

/* Function Declarations */
static void initialize_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void c27_update_debugger_state_c27_hybridSysSim
  (SFc27_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c27_hybridSysSim
  (SFc27_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_st);
static void finalize_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void c27_chartstep_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static real_T c27_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_b_fa, const char_T *c27_identifier);
static real_T c27_b_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_c_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[2]);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_info_helper(const mxArray **c27_info);
static const mxArray *c27_emlrt_marshallOut(const char * c27_u);
static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u);
static void c27_b_info_helper(const mxArray **c27_info);
static void c27_c_info_helper(const mxArray **c27_info);
static void c27_eml_scalar_eg(SFc27_hybridSysSimInstanceStruct *chartInstance);
static boolean_T c27_use_refblas(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_threshold(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_b_eml_scalar_eg(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_eml_switch_helper(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void c27_eml_error(SFc27_hybridSysSimInstanceStruct *chartInstance);
static real_T c27_eml_xnrm2(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2]);
static void c27_below_threshold(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_realmin(SFc27_hybridSysSimInstanceStruct *chartInstance);
static real_T c27_abs(SFc27_hybridSysSimInstanceStruct *chartInstance, real_T
                      c27_x);
static void c27_eps(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_b_eml_switch_helper(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void c27_eml_xscal(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T c27_x[2], real_T c27_b_x[2]);
static void c27_c_eml_scalar_eg(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_b_eml_error(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_eml_pinv(SFc27_hybridSysSimInstanceStruct *chartInstance, real_T
  c27_X[2]);
static void c27_eml_matlab_zsvdc(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_U[2], real_T *c27_S, real_T *c27_V);
static void c27_check_forloop_overflow_error(SFc27_hybridSysSimInstanceStruct
  *chartInstance, boolean_T c27_overflow);
static real_T c27_sqrt(SFc27_hybridSysSimInstanceStruct *chartInstance, real_T
  c27_x);
static void c27_c_eml_error(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_eml_xrotg(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T c27_b, real_T *c27_b_a, real_T *c27_b_b, real_T *c27_c,
  real_T *c27_s);
static real_T c27_eml_xrot(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x, int32_T c27_ix0, int32_T c27_iy0, real_T c27_c, real_T c27_s);
static void c27_b_threshold(SFc27_hybridSysSimInstanceStruct *chartInstance);
static void c27_b_eml_xrot(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], int32_T c27_ix0, int32_T c27_iy0, real_T c27_c, real_T c27_s,
  real_T c27_b_x[2]);
static void c27_d_eml_scalar_eg(SFc27_hybridSysSimInstanceStruct *chartInstance);
static real_T c27_b_eml_xscal(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T c27_x, int32_T c27_ix0);
static real_T c27_eml_xswap(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x, int32_T c27_ix0, int32_T c27_iy0);
static void c27_c_eml_switch_helper(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void c27_b_eml_xswap(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], int32_T c27_ix0, int32_T c27_iy0, real_T c27_b_x[2]);
static void c27_eml_xgemm(SFc27_hybridSysSimInstanceStruct *chartInstance,
  int32_T c27_k, real_T c27_A, real_T c27_B[2], real_T c27_C[2], real_T c27_b_C
  [2]);
static real_T c27_eml_xdotu(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], real_T c27_y[2]);
static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_d_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static uint8_T c27_e_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_hybridSysSim, const char_T *
  c27_identifier);
static uint8_T c27_f_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_c_eml_xscal(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T c27_x[2]);
static void c27_b_sqrt(SFc27_hybridSysSimInstanceStruct *chartInstance, real_T
  *c27_x);
static void c27_b_eml_xrotg(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T *c27_a, real_T *c27_b, real_T *c27_c, real_T *c27_s);
static void c27_c_eml_xrot(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T *c27_x, int32_T c27_ix0, int32_T c27_iy0, real_T c27_c, real_T c27_s);
static void c27_d_eml_xrot(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], int32_T c27_ix0, int32_T c27_iy0, real_T c27_c, real_T c27_s);
static void c27_d_eml_xscal(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T *c27_x, int32_T c27_ix0);
static void c27_c_eml_xswap(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T *c27_x, int32_T c27_ix0, int32_T c27_iy0);
static void c27_d_eml_xswap(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], int32_T c27_ix0, int32_T c27_iy0);
static void c27_b_eml_xgemm(SFc27_hybridSysSimInstanceStruct *chartInstance,
  int32_T c27_k, real_T c27_A, real_T c27_B[2], real_T c27_C[2]);
static void init_dsm_address_info(SFc27_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc27_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c27_is_active_c27_hybridSysSim = 0U;
}

static void initialize_params_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c27_update_debugger_state_c27_hybridSysSim
  (SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c27_hybridSysSim
  (SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  real_T c27_hoistedGlobal;
  real_T c27_u;
  const mxArray *c27_b_y = NULL;
  uint8_T c27_b_hoistedGlobal;
  uint8_T c27_b_u;
  const mxArray *c27_c_y = NULL;
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellmatrix(2, 1), false);
  c27_hoistedGlobal = *chartInstance->c27_fa;
  c27_u = c27_hoistedGlobal;
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  c27_b_hoistedGlobal = chartInstance->c27_is_active_c27_hybridSysSim;
  c27_b_u = c27_b_hoistedGlobal;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 1, c27_c_y);
  sf_mex_assign(&c27_st, c27_y, false);
  return c27_st;
}

static void set_sim_state_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_st)
{
  const mxArray *c27_u;
  chartInstance->c27_doneDoubleBufferReInit = true;
  c27_u = sf_mex_dup(c27_st);
  *chartInstance->c27_fa = c27_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c27_u, 0)), "fa");
  chartInstance->c27_is_active_c27_hybridSysSim = c27_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 1)),
     "is_active_c27_hybridSysSim");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_hybridSysSim(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c27_i0;
  int32_T c27_i1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, chartInstance->c27_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c27_FcRef, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c27_FcSense, 1U);
  for (c27_i0 = 0; c27_i0 < 2; c27_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_theta)[c27_i0], 2U);
  }

  chartInstance->c27_sfEvent = CALL_EVENT;
  c27_chartstep_c27_hybridSysSim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c27_fa, 3U);
  for (c27_i1 = 0; c27_i1 < 2; c27_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c27_thetaDot)[c27_i1], 4U);
  }
}

static void mdl_start_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c27_chartstep_c27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  real_T c27_hoistedGlobal;
  real_T c27_b_hoistedGlobal;
  real_T c27_b_FcRef;
  real_T c27_b_FcSense;
  int32_T c27_i2;
  real_T c27_b_theta[2];
  int32_T c27_i3;
  real_T c27_b_thetaDot[2];
  uint32_T c27_debug_family_var_map[17];
  real_T c27_kP;
  real_T c27_kD;
  real_T c27_rP;
  real_T c27_rD;
  real_T c27_K[4];
  real_T c27_Ja[2];
  real_T c27_theta0[2];
  real_T c27_Kp[4];
  real_T c27_Kd[4];
  real_T c27_tauA[2];
  real_T c27_nargin = 4.0;
  real_T c27_nargout = 1.0;
  real_T c27_b_fa;
  int32_T c27_i4;
  static real_T c27_a[4] = { 0.043, 0.0, 0.0, 0.185 };

  int32_T c27_i5;
  int32_T c27_i6;
  int32_T c27_i7;
  static real_T c27_b_a[4] = { 110.0, 0.0, 0.0, 110.0 };

  int32_T c27_i8;
  static real_T c27_c_a[4] = { 1.5, 0.0, 0.0, 1.5 };

  int32_T c27_i9;
  real_T c27_b[2];
  int32_T c27_i10;
  real_T c27_y[2];
  int32_T c27_i11;
  int32_T c27_i12;
  real_T c27_dv0[2];
  real_T c27_dv1[2];
  int32_T c27_i13;
  int32_T c27_i14;
  real_T c27_b_y[2];
  int32_T c27_i15;
  int32_T c27_i16;
  int32_T c27_i17;
  int32_T c27_i18;
  real_T c27_c_y[2];
  int32_T c27_i19;
  int32_T c27_i20;
  int32_T c27_i21;
  real_T c27_X[2];
  int32_T c27_i22;
  int32_T c27_i23;
  real_T c27_b_X[2];
  int32_T c27_i24;
  real_T c27_b_b[2];
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c27_sfEvent);
  c27_hoistedGlobal = *chartInstance->c27_FcRef;
  c27_b_hoistedGlobal = *chartInstance->c27_FcSense;
  c27_b_FcRef = c27_hoistedGlobal;
  c27_b_FcSense = c27_b_hoistedGlobal;
  for (c27_i2 = 0; c27_i2 < 2; c27_i2++) {
    c27_b_theta[c27_i2] = (*chartInstance->c27_theta)[c27_i2];
  }

  for (c27_i3 = 0; c27_i3 < 2; c27_i3++) {
    c27_b_thetaDot[c27_i3] = (*chartInstance->c27_thetaDot)[c27_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c27_debug_family_names,
    c27_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_kP, 0U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_kD, 1U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_rP, 2U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_rD, 3U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_K, 4U, c27_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_Ja, 5U, c27_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_theta0, 6U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_Kp, 7U, c27_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_Kd, 8U, c27_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_tauA, 9U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargin, 10U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargout, 11U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_b_FcRef, 12U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_b_FcSense, 13U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_b_theta, 14U, c27_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_b_thetaDot, 15U, c27_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_b_fa, 16U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 4);
  c27_kP = 0.043;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 5);
  c27_kD = 0.185;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 6);
  c27_rP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 7);
  c27_rD = 0.012;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 8);
  for (c27_i4 = 0; c27_i4 < 4; c27_i4++) {
    c27_K[c27_i4] = c27_a[c27_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 10);
  for (c27_i5 = 0; c27_i5 < 2; c27_i5++) {
    c27_Ja[c27_i5] = 50.0 + 33.333333333333329 * (real_T)c27_i5;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 11);
  for (c27_i6 = 0; c27_i6 < 2; c27_i6++) {
    c27_theta0[c27_i6] = 0.31415926535897931 + 0.73303828583761832 * (real_T)
      c27_i6;
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 13);
  for (c27_i7 = 0; c27_i7 < 4; c27_i7++) {
    c27_Kp[c27_i7] = c27_b_a[c27_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 15);
  for (c27_i8 = 0; c27_i8 < 4; c27_i8++) {
    c27_Kd[c27_i8] = c27_c_a[c27_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 17);
  for (c27_i9 = 0; c27_i9 < 2; c27_i9++) {
    c27_b[c27_i9] = c27_b_theta[c27_i9] - c27_theta0[c27_i9];
  }

  c27_eml_scalar_eg(chartInstance);
  c27_eml_scalar_eg(chartInstance);
  c27_threshold(chartInstance);
  for (c27_i10 = 0; c27_i10 < 2; c27_i10++) {
    c27_y[c27_i10] = 0.0;
    c27_i11 = 0;
    for (c27_i12 = 0; c27_i12 < 2; c27_i12++) {
      c27_y[c27_i10] += c27_a[c27_i11 + c27_i10] * c27_b[c27_i12];
      c27_i11 += 2;
    }
  }

  c27_dv0[0] = 0.0;
  c27_dv0[1] = c27_b_FcSense;
  c27_dv1[0] = 0.0;
  c27_dv1[1] = c27_b_FcRef;
  for (c27_i13 = 0; c27_i13 < 2; c27_i13++) {
    c27_b[c27_i13] = c27_dv0[c27_i13] - c27_dv1[c27_i13];
  }

  c27_eml_scalar_eg(chartInstance);
  c27_eml_scalar_eg(chartInstance);
  c27_threshold(chartInstance);
  for (c27_i14 = 0; c27_i14 < 2; c27_i14++) {
    c27_b_y[c27_i14] = 0.0;
    c27_i15 = 0;
    for (c27_i16 = 0; c27_i16 < 2; c27_i16++) {
      c27_b_y[c27_i14] += c27_b_a[c27_i15 + c27_i14] * c27_b[c27_i16];
      c27_i15 += 2;
    }
  }

  for (c27_i17 = 0; c27_i17 < 2; c27_i17++) {
    c27_b[c27_i17] = c27_b_thetaDot[c27_i17];
  }

  c27_eml_scalar_eg(chartInstance);
  c27_eml_scalar_eg(chartInstance);
  c27_threshold(chartInstance);
  for (c27_i18 = 0; c27_i18 < 2; c27_i18++) {
    c27_c_y[c27_i18] = 0.0;
    c27_i19 = 0;
    for (c27_i20 = 0; c27_i20 < 2; c27_i20++) {
      c27_c_y[c27_i18] += c27_c_a[c27_i19 + c27_i18] * c27_b[c27_i20];
      c27_i19 += 2;
    }
  }

  for (c27_i21 = 0; c27_i21 < 2; c27_i21++) {
    c27_tauA[c27_i21] = (c27_y[c27_i21] - c27_b_y[c27_i21]) - c27_c_y[c27_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 30);
  c27_eml_pinv(chartInstance, c27_X);
  for (c27_i22 = 0; c27_i22 < 2; c27_i22++) {
    c27_b[c27_i22] = c27_tauA[c27_i22];
  }

  for (c27_i23 = 0; c27_i23 < 2; c27_i23++) {
    c27_b_X[c27_i23] = c27_X[c27_i23];
  }

  for (c27_i24 = 0; c27_i24 < 2; c27_i24++) {
    c27_b_b[c27_i24] = c27_b[c27_i24];
  }

  c27_b_fa = c27_eml_xdotu(chartInstance, c27_b_X, c27_b_b);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c27_fa = c27_b_fa;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c27_sfEvent);
}

static void initSimStructsc27_hybridSysSim(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber)
{
  (void)c27_machineNumber;
  (void)c27_chartNumber;
  (void)c27_instanceNumber;
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static real_T c27_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_b_fa, const char_T *c27_identifier)
{
  real_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_fa),
    &c27_thisId);
  sf_mex_destroy(&c27_b_fa);
  return c27_y;
}

static real_T c27_b_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d0, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_fa;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y;
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c27_b_fa = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_fa),
    &c27_thisId);
  sf_mex_destroy(&c27_b_fa);
  *(real_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i25;
  real_T c27_b_inData[2];
  int32_T c27_i26;
  real_T c27_u[2];
  const mxArray *c27_y = NULL;
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i25 = 0; c27_i25 < 2; c27_i25++) {
    c27_b_inData[c27_i25] = (*(real_T (*)[2])c27_inData)[c27_i25];
  }

  for (c27_i26 = 0; c27_i26 < 2; c27_i26++) {
    c27_u[c27_i26] = c27_b_inData[c27_i26];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_c_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[2])
{
  real_T c27_dv2[2];
  int32_T c27_i27;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c27_i27 = 0; c27_i27 < 2; c27_i27++) {
    c27_y[c27_i27] = c27_dv2[c27_i27];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_tauA;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[2];
  int32_T c27_i28;
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c27_tauA = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_tauA), &c27_thisId, c27_y);
  sf_mex_destroy(&c27_tauA);
  for (c27_i28 = 0; c27_i28 < 2; c27_i28++) {
    (*(real_T (*)[2])c27_outData)[c27_i28] = c27_y[c27_i28];
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i29;
  int32_T c27_i30;
  int32_T c27_i31;
  real_T c27_b_inData[4];
  int32_T c27_i32;
  int32_T c27_i33;
  int32_T c27_i34;
  real_T c27_u[4];
  const mxArray *c27_y = NULL;
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i29 = 0;
  for (c27_i30 = 0; c27_i30 < 2; c27_i30++) {
    for (c27_i31 = 0; c27_i31 < 2; c27_i31++) {
      c27_b_inData[c27_i31 + c27_i29] = (*(real_T (*)[4])c27_inData)[c27_i31 +
        c27_i29];
    }

    c27_i29 += 2;
  }

  c27_i32 = 0;
  for (c27_i33 = 0; c27_i33 < 2; c27_i33++) {
    for (c27_i34 = 0; c27_i34 < 2; c27_i34++) {
      c27_u[c27_i34 + c27_i32] = c27_b_inData[c27_i34 + c27_i32];
    }

    c27_i32 += 2;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i35;
  real_T c27_b_inData[2];
  int32_T c27_i36;
  real_T c27_u[2];
  const mxArray *c27_y = NULL;
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i35 = 0; c27_i35 < 2; c27_i35++) {
    c27_b_inData[c27_i35] = (*(real_T (*)[2])c27_inData)[c27_i35];
  }

  for (c27_i36 = 0; c27_i36 < 2; c27_i36++) {
    c27_u[c27_i36] = c27_b_inData[c27_i36];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

const mxArray *sf_c27_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  sf_mex_assign(&c27_nameCaptureInfo, sf_mex_createstruct("structure", 2, 184, 1),
                false);
  c27_info_helper(&c27_nameCaptureInfo);
  c27_b_info_helper(&c27_nameCaptureInfo);
  c27_c_info_helper(&c27_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c27_nameCaptureInfo);
  return c27_nameCaptureInfo;
}

static void c27_info_helper(const mxArray **c27_info)
{
  const mxArray *c27_rhs0 = NULL;
  const mxArray *c27_lhs0 = NULL;
  const mxArray *c27_rhs1 = NULL;
  const mxArray *c27_lhs1 = NULL;
  const mxArray *c27_rhs2 = NULL;
  const mxArray *c27_lhs2 = NULL;
  const mxArray *c27_rhs3 = NULL;
  const mxArray *c27_lhs3 = NULL;
  const mxArray *c27_rhs4 = NULL;
  const mxArray *c27_lhs4 = NULL;
  const mxArray *c27_rhs5 = NULL;
  const mxArray *c27_lhs5 = NULL;
  const mxArray *c27_rhs6 = NULL;
  const mxArray *c27_lhs6 = NULL;
  const mxArray *c27_rhs7 = NULL;
  const mxArray *c27_lhs7 = NULL;
  const mxArray *c27_rhs8 = NULL;
  const mxArray *c27_lhs8 = NULL;
  const mxArray *c27_rhs9 = NULL;
  const mxArray *c27_lhs9 = NULL;
  const mxArray *c27_rhs10 = NULL;
  const mxArray *c27_lhs10 = NULL;
  const mxArray *c27_rhs11 = NULL;
  const mxArray *c27_lhs11 = NULL;
  const mxArray *c27_rhs12 = NULL;
  const mxArray *c27_lhs12 = NULL;
  const mxArray *c27_rhs13 = NULL;
  const mxArray *c27_lhs13 = NULL;
  const mxArray *c27_rhs14 = NULL;
  const mxArray *c27_lhs14 = NULL;
  const mxArray *c27_rhs15 = NULL;
  const mxArray *c27_lhs15 = NULL;
  const mxArray *c27_rhs16 = NULL;
  const mxArray *c27_lhs16 = NULL;
  const mxArray *c27_rhs17 = NULL;
  const mxArray *c27_lhs17 = NULL;
  const mxArray *c27_rhs18 = NULL;
  const mxArray *c27_lhs18 = NULL;
  const mxArray *c27_rhs19 = NULL;
  const mxArray *c27_lhs19 = NULL;
  const mxArray *c27_rhs20 = NULL;
  const mxArray *c27_lhs20 = NULL;
  const mxArray *c27_rhs21 = NULL;
  const mxArray *c27_lhs21 = NULL;
  const mxArray *c27_rhs22 = NULL;
  const mxArray *c27_lhs22 = NULL;
  const mxArray *c27_rhs23 = NULL;
  const mxArray *c27_lhs23 = NULL;
  const mxArray *c27_rhs24 = NULL;
  const mxArray *c27_lhs24 = NULL;
  const mxArray *c27_rhs25 = NULL;
  const mxArray *c27_lhs25 = NULL;
  const mxArray *c27_rhs26 = NULL;
  const mxArray *c27_lhs26 = NULL;
  const mxArray *c27_rhs27 = NULL;
  const mxArray *c27_lhs27 = NULL;
  const mxArray *c27_rhs28 = NULL;
  const mxArray *c27_lhs28 = NULL;
  const mxArray *c27_rhs29 = NULL;
  const mxArray *c27_lhs29 = NULL;
  const mxArray *c27_rhs30 = NULL;
  const mxArray *c27_lhs30 = NULL;
  const mxArray *c27_rhs31 = NULL;
  const mxArray *c27_lhs31 = NULL;
  const mxArray *c27_rhs32 = NULL;
  const mxArray *c27_lhs32 = NULL;
  const mxArray *c27_rhs33 = NULL;
  const mxArray *c27_lhs33 = NULL;
  const mxArray *c27_rhs34 = NULL;
  const mxArray *c27_lhs34 = NULL;
  const mxArray *c27_rhs35 = NULL;
  const mxArray *c27_lhs35 = NULL;
  const mxArray *c27_rhs36 = NULL;
  const mxArray *c27_lhs36 = NULL;
  const mxArray *c27_rhs37 = NULL;
  const mxArray *c27_lhs37 = NULL;
  const mxArray *c27_rhs38 = NULL;
  const mxArray *c27_lhs38 = NULL;
  const mxArray *c27_rhs39 = NULL;
  const mxArray *c27_lhs39 = NULL;
  const mxArray *c27_rhs40 = NULL;
  const mxArray *c27_lhs40 = NULL;
  const mxArray *c27_rhs41 = NULL;
  const mxArray *c27_lhs41 = NULL;
  const mxArray *c27_rhs42 = NULL;
  const mxArray *c27_lhs42 = NULL;
  const mxArray *c27_rhs43 = NULL;
  const mxArray *c27_lhs43 = NULL;
  const mxArray *c27_rhs44 = NULL;
  const mxArray *c27_lhs44 = NULL;
  const mxArray *c27_rhs45 = NULL;
  const mxArray *c27_lhs45 = NULL;
  const mxArray *c27_rhs46 = NULL;
  const mxArray *c27_lhs46 = NULL;
  const mxArray *c27_rhs47 = NULL;
  const mxArray *c27_lhs47 = NULL;
  const mxArray *c27_rhs48 = NULL;
  const mxArray *c27_lhs48 = NULL;
  const mxArray *c27_rhs49 = NULL;
  const mxArray *c27_lhs49 = NULL;
  const mxArray *c27_rhs50 = NULL;
  const mxArray *c27_lhs50 = NULL;
  const mxArray *c27_rhs51 = NULL;
  const mxArray *c27_lhs51 = NULL;
  const mxArray *c27_rhs52 = NULL;
  const mxArray *c27_lhs52 = NULL;
  const mxArray *c27_rhs53 = NULL;
  const mxArray *c27_lhs53 = NULL;
  const mxArray *c27_rhs54 = NULL;
  const mxArray *c27_lhs54 = NULL;
  const mxArray *c27_rhs55 = NULL;
  const mxArray *c27_lhs55 = NULL;
  const mxArray *c27_rhs56 = NULL;
  const mxArray *c27_lhs56 = NULL;
  const mxArray *c27_rhs57 = NULL;
  const mxArray *c27_lhs57 = NULL;
  const mxArray *c27_rhs58 = NULL;
  const mxArray *c27_lhs58 = NULL;
  const mxArray *c27_rhs59 = NULL;
  const mxArray *c27_lhs59 = NULL;
  const mxArray *c27_rhs60 = NULL;
  const mxArray *c27_lhs60 = NULL;
  const mxArray *c27_rhs61 = NULL;
  const mxArray *c27_lhs61 = NULL;
  const mxArray *c27_rhs62 = NULL;
  const mxArray *c27_lhs62 = NULL;
  const mxArray *c27_rhs63 = NULL;
  const mxArray *c27_lhs63 = NULL;
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c27_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c27_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c27_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c27_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c27_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c27_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c27_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c27_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c27_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c27_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c27_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c27_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c27_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c27_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c27_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c27_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c27_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c27_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c27_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 19);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c27_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("pinv"), "name", "name", 20);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786428U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c27_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 21);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 21);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c27_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 22);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 22);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c27_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 23);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("svd"), "name", "name", 23);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786432U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c27_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 24);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c27_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 25);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c27_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 26);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isfi"), "name", "name", 26);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 26);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1346481558U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c27_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 27);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1398846798U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c27_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 28);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("intmax"), "name", "name", 28);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c27_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 29);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c27_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 30);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("intmin"), "name", "name", 30);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c27_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 31);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c27_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isfinite"), "name", "name",
                  32);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c27_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 33);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c27_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isinf"), "name", "name", 34);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c27_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 35);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c27_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isnan"), "name", "name", 36);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c27_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 37);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c27_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_error"), "name", "name",
                  38);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c27_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xgesvd"), "name", "name",
                  39);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786406U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c27_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_lapack_xgesvd"), "name",
                  "name", 40);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786410U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c27_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_matlab_zsvdc"), "name",
                  "name", 41);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1398846806U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c27_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 42);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c27_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("min"), "name", "name", 43);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 43);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1311226518U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c27_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 44);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1378267184U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c27_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 45);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 45);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 45);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c27_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 46);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 46);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c27_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 47);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 47);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c27_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 48);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c27_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 49);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 49);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c27_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 50);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 50);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c27_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 51);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 51);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 51);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c27_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("max"), "name", "name", 52);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c27_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 53);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1378267184U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c27_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 54);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 54);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c27_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 55);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 55);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c27_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 56);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c27_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 57);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 57);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c27_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 58);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_relop"), "name", "name",
                  58);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 58);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1342422382U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c27_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 59);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326692322U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c27_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 60);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 60);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c27_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 61);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 61);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c27_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 62);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("intmin"), "name", "name", 62);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c27_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 63);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isnan"), "name", "name", 63);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 63);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 63);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c27_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c27_rhs0);
  sf_mex_destroy(&c27_lhs0);
  sf_mex_destroy(&c27_rhs1);
  sf_mex_destroy(&c27_lhs1);
  sf_mex_destroy(&c27_rhs2);
  sf_mex_destroy(&c27_lhs2);
  sf_mex_destroy(&c27_rhs3);
  sf_mex_destroy(&c27_lhs3);
  sf_mex_destroy(&c27_rhs4);
  sf_mex_destroy(&c27_lhs4);
  sf_mex_destroy(&c27_rhs5);
  sf_mex_destroy(&c27_lhs5);
  sf_mex_destroy(&c27_rhs6);
  sf_mex_destroy(&c27_lhs6);
  sf_mex_destroy(&c27_rhs7);
  sf_mex_destroy(&c27_lhs7);
  sf_mex_destroy(&c27_rhs8);
  sf_mex_destroy(&c27_lhs8);
  sf_mex_destroy(&c27_rhs9);
  sf_mex_destroy(&c27_lhs9);
  sf_mex_destroy(&c27_rhs10);
  sf_mex_destroy(&c27_lhs10);
  sf_mex_destroy(&c27_rhs11);
  sf_mex_destroy(&c27_lhs11);
  sf_mex_destroy(&c27_rhs12);
  sf_mex_destroy(&c27_lhs12);
  sf_mex_destroy(&c27_rhs13);
  sf_mex_destroy(&c27_lhs13);
  sf_mex_destroy(&c27_rhs14);
  sf_mex_destroy(&c27_lhs14);
  sf_mex_destroy(&c27_rhs15);
  sf_mex_destroy(&c27_lhs15);
  sf_mex_destroy(&c27_rhs16);
  sf_mex_destroy(&c27_lhs16);
  sf_mex_destroy(&c27_rhs17);
  sf_mex_destroy(&c27_lhs17);
  sf_mex_destroy(&c27_rhs18);
  sf_mex_destroy(&c27_lhs18);
  sf_mex_destroy(&c27_rhs19);
  sf_mex_destroy(&c27_lhs19);
  sf_mex_destroy(&c27_rhs20);
  sf_mex_destroy(&c27_lhs20);
  sf_mex_destroy(&c27_rhs21);
  sf_mex_destroy(&c27_lhs21);
  sf_mex_destroy(&c27_rhs22);
  sf_mex_destroy(&c27_lhs22);
  sf_mex_destroy(&c27_rhs23);
  sf_mex_destroy(&c27_lhs23);
  sf_mex_destroy(&c27_rhs24);
  sf_mex_destroy(&c27_lhs24);
  sf_mex_destroy(&c27_rhs25);
  sf_mex_destroy(&c27_lhs25);
  sf_mex_destroy(&c27_rhs26);
  sf_mex_destroy(&c27_lhs26);
  sf_mex_destroy(&c27_rhs27);
  sf_mex_destroy(&c27_lhs27);
  sf_mex_destroy(&c27_rhs28);
  sf_mex_destroy(&c27_lhs28);
  sf_mex_destroy(&c27_rhs29);
  sf_mex_destroy(&c27_lhs29);
  sf_mex_destroy(&c27_rhs30);
  sf_mex_destroy(&c27_lhs30);
  sf_mex_destroy(&c27_rhs31);
  sf_mex_destroy(&c27_lhs31);
  sf_mex_destroy(&c27_rhs32);
  sf_mex_destroy(&c27_lhs32);
  sf_mex_destroy(&c27_rhs33);
  sf_mex_destroy(&c27_lhs33);
  sf_mex_destroy(&c27_rhs34);
  sf_mex_destroy(&c27_lhs34);
  sf_mex_destroy(&c27_rhs35);
  sf_mex_destroy(&c27_lhs35);
  sf_mex_destroy(&c27_rhs36);
  sf_mex_destroy(&c27_lhs36);
  sf_mex_destroy(&c27_rhs37);
  sf_mex_destroy(&c27_lhs37);
  sf_mex_destroy(&c27_rhs38);
  sf_mex_destroy(&c27_lhs38);
  sf_mex_destroy(&c27_rhs39);
  sf_mex_destroy(&c27_lhs39);
  sf_mex_destroy(&c27_rhs40);
  sf_mex_destroy(&c27_lhs40);
  sf_mex_destroy(&c27_rhs41);
  sf_mex_destroy(&c27_lhs41);
  sf_mex_destroy(&c27_rhs42);
  sf_mex_destroy(&c27_lhs42);
  sf_mex_destroy(&c27_rhs43);
  sf_mex_destroy(&c27_lhs43);
  sf_mex_destroy(&c27_rhs44);
  sf_mex_destroy(&c27_lhs44);
  sf_mex_destroy(&c27_rhs45);
  sf_mex_destroy(&c27_lhs45);
  sf_mex_destroy(&c27_rhs46);
  sf_mex_destroy(&c27_lhs46);
  sf_mex_destroy(&c27_rhs47);
  sf_mex_destroy(&c27_lhs47);
  sf_mex_destroy(&c27_rhs48);
  sf_mex_destroy(&c27_lhs48);
  sf_mex_destroy(&c27_rhs49);
  sf_mex_destroy(&c27_lhs49);
  sf_mex_destroy(&c27_rhs50);
  sf_mex_destroy(&c27_lhs50);
  sf_mex_destroy(&c27_rhs51);
  sf_mex_destroy(&c27_lhs51);
  sf_mex_destroy(&c27_rhs52);
  sf_mex_destroy(&c27_lhs52);
  sf_mex_destroy(&c27_rhs53);
  sf_mex_destroy(&c27_lhs53);
  sf_mex_destroy(&c27_rhs54);
  sf_mex_destroy(&c27_lhs54);
  sf_mex_destroy(&c27_rhs55);
  sf_mex_destroy(&c27_lhs55);
  sf_mex_destroy(&c27_rhs56);
  sf_mex_destroy(&c27_lhs56);
  sf_mex_destroy(&c27_rhs57);
  sf_mex_destroy(&c27_lhs57);
  sf_mex_destroy(&c27_rhs58);
  sf_mex_destroy(&c27_lhs58);
  sf_mex_destroy(&c27_rhs59);
  sf_mex_destroy(&c27_lhs59);
  sf_mex_destroy(&c27_rhs60);
  sf_mex_destroy(&c27_lhs60);
  sf_mex_destroy(&c27_rhs61);
  sf_mex_destroy(&c27_lhs61);
  sf_mex_destroy(&c27_rhs62);
  sf_mex_destroy(&c27_lhs62);
  sf_mex_destroy(&c27_rhs63);
  sf_mex_destroy(&c27_lhs63);
}

static const mxArray *c27_emlrt_marshallOut(const char * c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c27_u)), false);
  return c27_y;
}

static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 7, 0U, 0U, 0U, 0), false);
  return c27_y;
}

static void c27_b_info_helper(const mxArray **c27_info)
{
  const mxArray *c27_rhs64 = NULL;
  const mxArray *c27_lhs64 = NULL;
  const mxArray *c27_rhs65 = NULL;
  const mxArray *c27_lhs65 = NULL;
  const mxArray *c27_rhs66 = NULL;
  const mxArray *c27_lhs66 = NULL;
  const mxArray *c27_rhs67 = NULL;
  const mxArray *c27_lhs67 = NULL;
  const mxArray *c27_rhs68 = NULL;
  const mxArray *c27_lhs68 = NULL;
  const mxArray *c27_rhs69 = NULL;
  const mxArray *c27_lhs69 = NULL;
  const mxArray *c27_rhs70 = NULL;
  const mxArray *c27_lhs70 = NULL;
  const mxArray *c27_rhs71 = NULL;
  const mxArray *c27_lhs71 = NULL;
  const mxArray *c27_rhs72 = NULL;
  const mxArray *c27_lhs72 = NULL;
  const mxArray *c27_rhs73 = NULL;
  const mxArray *c27_lhs73 = NULL;
  const mxArray *c27_rhs74 = NULL;
  const mxArray *c27_lhs74 = NULL;
  const mxArray *c27_rhs75 = NULL;
  const mxArray *c27_lhs75 = NULL;
  const mxArray *c27_rhs76 = NULL;
  const mxArray *c27_lhs76 = NULL;
  const mxArray *c27_rhs77 = NULL;
  const mxArray *c27_lhs77 = NULL;
  const mxArray *c27_rhs78 = NULL;
  const mxArray *c27_lhs78 = NULL;
  const mxArray *c27_rhs79 = NULL;
  const mxArray *c27_lhs79 = NULL;
  const mxArray *c27_rhs80 = NULL;
  const mxArray *c27_lhs80 = NULL;
  const mxArray *c27_rhs81 = NULL;
  const mxArray *c27_lhs81 = NULL;
  const mxArray *c27_rhs82 = NULL;
  const mxArray *c27_lhs82 = NULL;
  const mxArray *c27_rhs83 = NULL;
  const mxArray *c27_lhs83 = NULL;
  const mxArray *c27_rhs84 = NULL;
  const mxArray *c27_lhs84 = NULL;
  const mxArray *c27_rhs85 = NULL;
  const mxArray *c27_lhs85 = NULL;
  const mxArray *c27_rhs86 = NULL;
  const mxArray *c27_lhs86 = NULL;
  const mxArray *c27_rhs87 = NULL;
  const mxArray *c27_lhs87 = NULL;
  const mxArray *c27_rhs88 = NULL;
  const mxArray *c27_lhs88 = NULL;
  const mxArray *c27_rhs89 = NULL;
  const mxArray *c27_lhs89 = NULL;
  const mxArray *c27_rhs90 = NULL;
  const mxArray *c27_lhs90 = NULL;
  const mxArray *c27_rhs91 = NULL;
  const mxArray *c27_lhs91 = NULL;
  const mxArray *c27_rhs92 = NULL;
  const mxArray *c27_lhs92 = NULL;
  const mxArray *c27_rhs93 = NULL;
  const mxArray *c27_lhs93 = NULL;
  const mxArray *c27_rhs94 = NULL;
  const mxArray *c27_lhs94 = NULL;
  const mxArray *c27_rhs95 = NULL;
  const mxArray *c27_lhs95 = NULL;
  const mxArray *c27_rhs96 = NULL;
  const mxArray *c27_lhs96 = NULL;
  const mxArray *c27_rhs97 = NULL;
  const mxArray *c27_lhs97 = NULL;
  const mxArray *c27_rhs98 = NULL;
  const mxArray *c27_lhs98 = NULL;
  const mxArray *c27_rhs99 = NULL;
  const mxArray *c27_lhs99 = NULL;
  const mxArray *c27_rhs100 = NULL;
  const mxArray *c27_lhs100 = NULL;
  const mxArray *c27_rhs101 = NULL;
  const mxArray *c27_lhs101 = NULL;
  const mxArray *c27_rhs102 = NULL;
  const mxArray *c27_lhs102 = NULL;
  const mxArray *c27_rhs103 = NULL;
  const mxArray *c27_lhs103 = NULL;
  const mxArray *c27_rhs104 = NULL;
  const mxArray *c27_lhs104 = NULL;
  const mxArray *c27_rhs105 = NULL;
  const mxArray *c27_lhs105 = NULL;
  const mxArray *c27_rhs106 = NULL;
  const mxArray *c27_lhs106 = NULL;
  const mxArray *c27_rhs107 = NULL;
  const mxArray *c27_lhs107 = NULL;
  const mxArray *c27_rhs108 = NULL;
  const mxArray *c27_lhs108 = NULL;
  const mxArray *c27_rhs109 = NULL;
  const mxArray *c27_lhs109 = NULL;
  const mxArray *c27_rhs110 = NULL;
  const mxArray *c27_lhs110 = NULL;
  const mxArray *c27_rhs111 = NULL;
  const mxArray *c27_lhs111 = NULL;
  const mxArray *c27_rhs112 = NULL;
  const mxArray *c27_lhs112 = NULL;
  const mxArray *c27_rhs113 = NULL;
  const mxArray *c27_lhs113 = NULL;
  const mxArray *c27_rhs114 = NULL;
  const mxArray *c27_lhs114 = NULL;
  const mxArray *c27_rhs115 = NULL;
  const mxArray *c27_lhs115 = NULL;
  const mxArray *c27_rhs116 = NULL;
  const mxArray *c27_lhs116 = NULL;
  const mxArray *c27_rhs117 = NULL;
  const mxArray *c27_lhs117 = NULL;
  const mxArray *c27_rhs118 = NULL;
  const mxArray *c27_lhs118 = NULL;
  const mxArray *c27_rhs119 = NULL;
  const mxArray *c27_lhs119 = NULL;
  const mxArray *c27_rhs120 = NULL;
  const mxArray *c27_lhs120 = NULL;
  const mxArray *c27_rhs121 = NULL;
  const mxArray *c27_lhs121 = NULL;
  const mxArray *c27_rhs122 = NULL;
  const mxArray *c27_lhs122 = NULL;
  const mxArray *c27_rhs123 = NULL;
  const mxArray *c27_lhs123 = NULL;
  const mxArray *c27_rhs124 = NULL;
  const mxArray *c27_lhs124 = NULL;
  const mxArray *c27_rhs125 = NULL;
  const mxArray *c27_lhs125 = NULL;
  const mxArray *c27_rhs126 = NULL;
  const mxArray *c27_lhs126 = NULL;
  const mxArray *c27_rhs127 = NULL;
  const mxArray *c27_lhs127 = NULL;
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 64);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 64);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 64);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c27_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 65);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("max"), "name", "name", 65);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 65);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c27_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 66);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  66);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c27_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 67);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c27_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 68);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c27_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 69);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 69);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c27_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 70);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 70);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c27_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 71);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 71);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c27_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("realmin"), "name", "name",
                  72);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 72);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c27_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 73);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1307622444U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c27_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 74);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c27_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 75);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 75);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c27_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 76);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 76);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c27_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 77);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 77);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 77);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c27_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 78);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 78);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c27_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 79);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("abs"), "name", "name", 79);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 79);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c27_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 80);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 80);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c27_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 81);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 81);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786312U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c27_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 82);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.scaleVectorByRecip"), "name", "name", 82);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c27_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 83);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("realmin"), "name", "name",
                  83);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c27_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 84);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eps"), "name", "name", 84);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 84);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c27_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 85);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 85);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c27_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 86);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_eps"), "name", "name",
                  86);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 86);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c27_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 87);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 87);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c27_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 88);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("mrdivide"), "name", "name",
                  88);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c27_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 89);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("abs"), "name", "name", 89);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 89);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c27_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 90);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xscal"),
                  "name", "name", 90);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c27_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 91);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 91);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c27_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p!below_threshold"),
                  "context", "context", 92);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 92);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c27_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 93);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 93);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c27_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 94);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.refblas.xscal"), "name", "name", 94);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c27_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 95);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 95);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c27_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 96);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 96);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 96);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c27_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 97);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 97);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 97);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c27_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 98);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 98);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c27_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 99);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 99);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c27_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 100);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 100);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 100);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c27_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 101);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 101);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 101);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c27_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 102);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 102);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c27_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 103);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 103);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c27_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 104);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("abs"), "name", "name", 104);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 104);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c27_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 105);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("mrdivide"), "name", "name",
                  105);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 105);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c27_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 106);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xscal"), "name", "name",
                  106);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c27_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 107);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c27_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"), "context",
                  "context", 108);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xscal"),
                  "name", "name", 108);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c27_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 109);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("realmin"), "name", "name",
                  109);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 109);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c27_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 110);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eps"), "name", "name", 110);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 110);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c27_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 111);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 111);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c27_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 112);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_error"), "name", "name",
                  112);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 112);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c27_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 113);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 113);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c27_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 114);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 114);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c27_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 115);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 115);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 115);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c27_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 116);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 116);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c27_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 117);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 117);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c27_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 118);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("isnan"), "name", "name", 118);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 118);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c27_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 119);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 119);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 119);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 119);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c27_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 120);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 120);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 120);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c27_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 121);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 121);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c27_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 122);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_relop"), "name", "name",
                  122);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 122);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 122);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1342422382U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c27_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 123);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("sqrt"), "name", "name", 123);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 123);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c27_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 124);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_error"), "name", "name",
                  124);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 124);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c27_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 125);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 125);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786338U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c27_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 126);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xrotg"), "name", "name",
                  126);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c27_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"), "context",
                  "context", 127);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 127);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c27_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c27_rhs64);
  sf_mex_destroy(&c27_lhs64);
  sf_mex_destroy(&c27_rhs65);
  sf_mex_destroy(&c27_lhs65);
  sf_mex_destroy(&c27_rhs66);
  sf_mex_destroy(&c27_lhs66);
  sf_mex_destroy(&c27_rhs67);
  sf_mex_destroy(&c27_lhs67);
  sf_mex_destroy(&c27_rhs68);
  sf_mex_destroy(&c27_lhs68);
  sf_mex_destroy(&c27_rhs69);
  sf_mex_destroy(&c27_lhs69);
  sf_mex_destroy(&c27_rhs70);
  sf_mex_destroy(&c27_lhs70);
  sf_mex_destroy(&c27_rhs71);
  sf_mex_destroy(&c27_lhs71);
  sf_mex_destroy(&c27_rhs72);
  sf_mex_destroy(&c27_lhs72);
  sf_mex_destroy(&c27_rhs73);
  sf_mex_destroy(&c27_lhs73);
  sf_mex_destroy(&c27_rhs74);
  sf_mex_destroy(&c27_lhs74);
  sf_mex_destroy(&c27_rhs75);
  sf_mex_destroy(&c27_lhs75);
  sf_mex_destroy(&c27_rhs76);
  sf_mex_destroy(&c27_lhs76);
  sf_mex_destroy(&c27_rhs77);
  sf_mex_destroy(&c27_lhs77);
  sf_mex_destroy(&c27_rhs78);
  sf_mex_destroy(&c27_lhs78);
  sf_mex_destroy(&c27_rhs79);
  sf_mex_destroy(&c27_lhs79);
  sf_mex_destroy(&c27_rhs80);
  sf_mex_destroy(&c27_lhs80);
  sf_mex_destroy(&c27_rhs81);
  sf_mex_destroy(&c27_lhs81);
  sf_mex_destroy(&c27_rhs82);
  sf_mex_destroy(&c27_lhs82);
  sf_mex_destroy(&c27_rhs83);
  sf_mex_destroy(&c27_lhs83);
  sf_mex_destroy(&c27_rhs84);
  sf_mex_destroy(&c27_lhs84);
  sf_mex_destroy(&c27_rhs85);
  sf_mex_destroy(&c27_lhs85);
  sf_mex_destroy(&c27_rhs86);
  sf_mex_destroy(&c27_lhs86);
  sf_mex_destroy(&c27_rhs87);
  sf_mex_destroy(&c27_lhs87);
  sf_mex_destroy(&c27_rhs88);
  sf_mex_destroy(&c27_lhs88);
  sf_mex_destroy(&c27_rhs89);
  sf_mex_destroy(&c27_lhs89);
  sf_mex_destroy(&c27_rhs90);
  sf_mex_destroy(&c27_lhs90);
  sf_mex_destroy(&c27_rhs91);
  sf_mex_destroy(&c27_lhs91);
  sf_mex_destroy(&c27_rhs92);
  sf_mex_destroy(&c27_lhs92);
  sf_mex_destroy(&c27_rhs93);
  sf_mex_destroy(&c27_lhs93);
  sf_mex_destroy(&c27_rhs94);
  sf_mex_destroy(&c27_lhs94);
  sf_mex_destroy(&c27_rhs95);
  sf_mex_destroy(&c27_lhs95);
  sf_mex_destroy(&c27_rhs96);
  sf_mex_destroy(&c27_lhs96);
  sf_mex_destroy(&c27_rhs97);
  sf_mex_destroy(&c27_lhs97);
  sf_mex_destroy(&c27_rhs98);
  sf_mex_destroy(&c27_lhs98);
  sf_mex_destroy(&c27_rhs99);
  sf_mex_destroy(&c27_lhs99);
  sf_mex_destroy(&c27_rhs100);
  sf_mex_destroy(&c27_lhs100);
  sf_mex_destroy(&c27_rhs101);
  sf_mex_destroy(&c27_lhs101);
  sf_mex_destroy(&c27_rhs102);
  sf_mex_destroy(&c27_lhs102);
  sf_mex_destroy(&c27_rhs103);
  sf_mex_destroy(&c27_lhs103);
  sf_mex_destroy(&c27_rhs104);
  sf_mex_destroy(&c27_lhs104);
  sf_mex_destroy(&c27_rhs105);
  sf_mex_destroy(&c27_lhs105);
  sf_mex_destroy(&c27_rhs106);
  sf_mex_destroy(&c27_lhs106);
  sf_mex_destroy(&c27_rhs107);
  sf_mex_destroy(&c27_lhs107);
  sf_mex_destroy(&c27_rhs108);
  sf_mex_destroy(&c27_lhs108);
  sf_mex_destroy(&c27_rhs109);
  sf_mex_destroy(&c27_lhs109);
  sf_mex_destroy(&c27_rhs110);
  sf_mex_destroy(&c27_lhs110);
  sf_mex_destroy(&c27_rhs111);
  sf_mex_destroy(&c27_lhs111);
  sf_mex_destroy(&c27_rhs112);
  sf_mex_destroy(&c27_lhs112);
  sf_mex_destroy(&c27_rhs113);
  sf_mex_destroy(&c27_lhs113);
  sf_mex_destroy(&c27_rhs114);
  sf_mex_destroy(&c27_lhs114);
  sf_mex_destroy(&c27_rhs115);
  sf_mex_destroy(&c27_lhs115);
  sf_mex_destroy(&c27_rhs116);
  sf_mex_destroy(&c27_lhs116);
  sf_mex_destroy(&c27_rhs117);
  sf_mex_destroy(&c27_lhs117);
  sf_mex_destroy(&c27_rhs118);
  sf_mex_destroy(&c27_lhs118);
  sf_mex_destroy(&c27_rhs119);
  sf_mex_destroy(&c27_lhs119);
  sf_mex_destroy(&c27_rhs120);
  sf_mex_destroy(&c27_lhs120);
  sf_mex_destroy(&c27_rhs121);
  sf_mex_destroy(&c27_lhs121);
  sf_mex_destroy(&c27_rhs122);
  sf_mex_destroy(&c27_lhs122);
  sf_mex_destroy(&c27_rhs123);
  sf_mex_destroy(&c27_lhs123);
  sf_mex_destroy(&c27_rhs124);
  sf_mex_destroy(&c27_lhs124);
  sf_mex_destroy(&c27_rhs125);
  sf_mex_destroy(&c27_lhs125);
  sf_mex_destroy(&c27_rhs126);
  sf_mex_destroy(&c27_lhs126);
  sf_mex_destroy(&c27_rhs127);
  sf_mex_destroy(&c27_lhs127);
}

static void c27_c_info_helper(const mxArray **c27_info)
{
  const mxArray *c27_rhs128 = NULL;
  const mxArray *c27_lhs128 = NULL;
  const mxArray *c27_rhs129 = NULL;
  const mxArray *c27_lhs129 = NULL;
  const mxArray *c27_rhs130 = NULL;
  const mxArray *c27_lhs130 = NULL;
  const mxArray *c27_rhs131 = NULL;
  const mxArray *c27_lhs131 = NULL;
  const mxArray *c27_rhs132 = NULL;
  const mxArray *c27_lhs132 = NULL;
  const mxArray *c27_rhs133 = NULL;
  const mxArray *c27_lhs133 = NULL;
  const mxArray *c27_rhs134 = NULL;
  const mxArray *c27_lhs134 = NULL;
  const mxArray *c27_rhs135 = NULL;
  const mxArray *c27_lhs135 = NULL;
  const mxArray *c27_rhs136 = NULL;
  const mxArray *c27_lhs136 = NULL;
  const mxArray *c27_rhs137 = NULL;
  const mxArray *c27_lhs137 = NULL;
  const mxArray *c27_rhs138 = NULL;
  const mxArray *c27_lhs138 = NULL;
  const mxArray *c27_rhs139 = NULL;
  const mxArray *c27_lhs139 = NULL;
  const mxArray *c27_rhs140 = NULL;
  const mxArray *c27_lhs140 = NULL;
  const mxArray *c27_rhs141 = NULL;
  const mxArray *c27_lhs141 = NULL;
  const mxArray *c27_rhs142 = NULL;
  const mxArray *c27_lhs142 = NULL;
  const mxArray *c27_rhs143 = NULL;
  const mxArray *c27_lhs143 = NULL;
  const mxArray *c27_rhs144 = NULL;
  const mxArray *c27_lhs144 = NULL;
  const mxArray *c27_rhs145 = NULL;
  const mxArray *c27_lhs145 = NULL;
  const mxArray *c27_rhs146 = NULL;
  const mxArray *c27_lhs146 = NULL;
  const mxArray *c27_rhs147 = NULL;
  const mxArray *c27_lhs147 = NULL;
  const mxArray *c27_rhs148 = NULL;
  const mxArray *c27_lhs148 = NULL;
  const mxArray *c27_rhs149 = NULL;
  const mxArray *c27_lhs149 = NULL;
  const mxArray *c27_rhs150 = NULL;
  const mxArray *c27_lhs150 = NULL;
  const mxArray *c27_rhs151 = NULL;
  const mxArray *c27_lhs151 = NULL;
  const mxArray *c27_rhs152 = NULL;
  const mxArray *c27_lhs152 = NULL;
  const mxArray *c27_rhs153 = NULL;
  const mxArray *c27_lhs153 = NULL;
  const mxArray *c27_rhs154 = NULL;
  const mxArray *c27_lhs154 = NULL;
  const mxArray *c27_rhs155 = NULL;
  const mxArray *c27_lhs155 = NULL;
  const mxArray *c27_rhs156 = NULL;
  const mxArray *c27_lhs156 = NULL;
  const mxArray *c27_rhs157 = NULL;
  const mxArray *c27_lhs157 = NULL;
  const mxArray *c27_rhs158 = NULL;
  const mxArray *c27_lhs158 = NULL;
  const mxArray *c27_rhs159 = NULL;
  const mxArray *c27_lhs159 = NULL;
  const mxArray *c27_rhs160 = NULL;
  const mxArray *c27_lhs160 = NULL;
  const mxArray *c27_rhs161 = NULL;
  const mxArray *c27_lhs161 = NULL;
  const mxArray *c27_rhs162 = NULL;
  const mxArray *c27_lhs162 = NULL;
  const mxArray *c27_rhs163 = NULL;
  const mxArray *c27_lhs163 = NULL;
  const mxArray *c27_rhs164 = NULL;
  const mxArray *c27_lhs164 = NULL;
  const mxArray *c27_rhs165 = NULL;
  const mxArray *c27_lhs165 = NULL;
  const mxArray *c27_rhs166 = NULL;
  const mxArray *c27_lhs166 = NULL;
  const mxArray *c27_rhs167 = NULL;
  const mxArray *c27_lhs167 = NULL;
  const mxArray *c27_rhs168 = NULL;
  const mxArray *c27_lhs168 = NULL;
  const mxArray *c27_rhs169 = NULL;
  const mxArray *c27_lhs169 = NULL;
  const mxArray *c27_rhs170 = NULL;
  const mxArray *c27_lhs170 = NULL;
  const mxArray *c27_rhs171 = NULL;
  const mxArray *c27_lhs171 = NULL;
  const mxArray *c27_rhs172 = NULL;
  const mxArray *c27_lhs172 = NULL;
  const mxArray *c27_rhs173 = NULL;
  const mxArray *c27_lhs173 = NULL;
  const mxArray *c27_rhs174 = NULL;
  const mxArray *c27_lhs174 = NULL;
  const mxArray *c27_rhs175 = NULL;
  const mxArray *c27_lhs175 = NULL;
  const mxArray *c27_rhs176 = NULL;
  const mxArray *c27_lhs176 = NULL;
  const mxArray *c27_rhs177 = NULL;
  const mxArray *c27_lhs177 = NULL;
  const mxArray *c27_rhs178 = NULL;
  const mxArray *c27_lhs178 = NULL;
  const mxArray *c27_rhs179 = NULL;
  const mxArray *c27_lhs179 = NULL;
  const mxArray *c27_rhs180 = NULL;
  const mxArray *c27_lhs180 = NULL;
  const mxArray *c27_rhs181 = NULL;
  const mxArray *c27_lhs181 = NULL;
  const mxArray *c27_rhs182 = NULL;
  const mxArray *c27_lhs182 = NULL;
  const mxArray *c27_rhs183 = NULL;
  const mxArray *c27_lhs183 = NULL;
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"), "context",
                  "context", 128);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xrotg"),
                  "name", "name", 128);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c27_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "context", "context", 129);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 129);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c27_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs129), "rhs",
                  "rhs", 129);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs129), "lhs",
                  "lhs", 129);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "context", "context", 130);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.refblas.xrotg"), "name", "name", 130);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c27_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs130), "rhs",
                  "rhs", 130);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs130), "lhs",
                  "lhs", 130);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 131);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("abs"), "name", "name", 131);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 131);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 131);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c27_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs131), "rhs",
                  "rhs", 131);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs131), "lhs",
                  "lhs", 131);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 132);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("mrdivide"), "name", "name",
                  132);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 132);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 132);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c27_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs132), "rhs",
                  "rhs", 132);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs132), "lhs",
                  "lhs", 132);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 133);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("sqrt"), "name", "name", 133);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 133);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 133);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c27_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs133), "rhs",
                  "rhs", 133);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs133), "lhs",
                  "lhs", 133);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p!eml_ceval_xrotg"),
                  "context", "context", 134);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 134);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c27_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs134), "rhs",
                  "rhs", 134);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs134), "lhs",
                  "lhs", 134);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 135);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xrot"), "name", "name",
                  135);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m"), "resolved",
                  "resolved", 135);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c27_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs135), "rhs",
                  "rhs", 135);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs135), "lhs",
                  "lhs", 135);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m"), "context",
                  "context", 136);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 136);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c27_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs136), "rhs",
                  "rhs", 136);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs136), "lhs",
                  "lhs", 136);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m"), "context",
                  "context", 137);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xrot"),
                  "name", "name", 137);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p"),
                  "resolved", "resolved", 137);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c27_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs137), "rhs",
                  "rhs", 137);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs137), "lhs",
                  "lhs", 137);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p"),
                  "context", "context", 138);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 138);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 138);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c27_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs138), "rhs",
                  "rhs", 138);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs138), "lhs",
                  "lhs", 138);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p!below_threshold"),
                  "context", "context", 139);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 139);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 139);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c27_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs139), "rhs",
                  "rhs", 139);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs139), "lhs",
                  "lhs", 139);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p"),
                  "context", "context", 140);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 140);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 140);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c27_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs140), "rhs",
                  "rhs", 140);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs140), "lhs",
                  "lhs", 140);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrot.p"),
                  "context", "context", 141);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.refblas.xrot"),
                  "name", "name", 141);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrot.p"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c27_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs141), "rhs",
                  "rhs", 141);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs141), "lhs",
                  "lhs", 141);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrot.p"),
                  "context", "context", 142);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 142);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 142);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c27_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs142), "rhs",
                  "rhs", 142);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs142), "lhs",
                  "lhs", 142);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrot.p"),
                  "context", "context", 143);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 143);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 143);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c27_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs143), "rhs",
                  "rhs", 143);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs143), "lhs",
                  "lhs", 143);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 144);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xswap"), "name", "name",
                  144);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c27_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs144), "rhs",
                  "rhs", 144);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs144), "lhs",
                  "lhs", 144);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 145);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 145);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c27_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs145), "rhs",
                  "rhs", 145);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs145), "lhs",
                  "lhs", 145);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 146);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xswap"),
                  "name", "name", 146);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "resolved", "resolved", 146);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c27_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs146), "rhs",
                  "rhs", 146);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs146), "lhs",
                  "lhs", 146);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 147);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 147);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 147);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c27_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs147), "rhs",
                  "rhs", 147);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs147), "lhs",
                  "lhs", 147);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                  "context", "context", 148);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 148);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c27_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs148), "rhs",
                  "rhs", 148);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs148), "lhs",
                  "lhs", 148);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 149);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.refblas.xswap"), "name", "name", 149);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c27_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs149), "rhs",
                  "rhs", 149);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs149), "lhs",
                  "lhs", 149);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 150);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("abs"), "name", "name", 150);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 150);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 150);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c27_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs150), "rhs",
                  "rhs", 150);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs150), "lhs",
                  "lhs", 150);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 151);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 151);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 151);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c27_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs151), "rhs",
                  "rhs", 151);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs151), "lhs",
                  "lhs", 151);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 152);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 152);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 152);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286786312U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c27_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs152), "rhs",
                  "rhs", 152);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs152), "lhs",
                  "lhs", 152);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 153);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 153);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 153);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 153);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c27_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs153), "rhs",
                  "rhs", 153);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs153), "lhs",
                  "lhs", 153);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 154);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 154);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 154);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 154);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c27_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs154), "rhs",
                  "rhs", 154);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs154), "lhs",
                  "lhs", 154);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 155);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eps"), "name", "name", 155);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 155);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 155);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c27_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs155), "rhs",
                  "rhs", 155);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs155), "lhs",
                  "lhs", 155);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 156);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 156);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 156);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 156);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c27_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs156), "rhs",
                  "rhs", 156);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs156), "lhs",
                  "lhs", 156);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 157);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 157);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 157);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c27_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs157), "rhs",
                  "rhs", 157);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs157), "lhs",
                  "lhs", 157);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 158);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 158);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 158);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 158);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c27_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs158), "rhs",
                  "rhs", 158);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs158), "lhs",
                  "lhs", 158);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 159);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_div"), "name", "name",
                  159);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 159);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c27_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs159), "rhs",
                  "rhs", 159);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs159), "lhs",
                  "lhs", 159);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 160);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xscal"), "name", "name",
                  160);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m"),
                  "resolved", "resolved", 160);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c27_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs160), "rhs",
                  "rhs", 160);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs160), "lhs",
                  "lhs", 160);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 161);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 161);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 161);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 161);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c27_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs161), "rhs",
                  "rhs", 161);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs161), "lhs",
                  "lhs", 161);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv"),
                  "context", "context", 162);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  162);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 162);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c27_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs162), "rhs",
                  "rhs", 162);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs162), "lhs",
                  "lhs", 162);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 163);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("min"), "name", "name", 163);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 163);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1311226518U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c27_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs163), "rhs",
                  "rhs", 163);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs163), "lhs",
                  "lhs", 163);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 164);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 164);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 164);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c27_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs164), "rhs",
                  "rhs", 164);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs164), "lhs",
                  "lhs", 164);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 165);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 165);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 165);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c27_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs165), "rhs",
                  "rhs", 165);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs165), "lhs",
                  "lhs", 165);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 166);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 166);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 166);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c27_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs166), "rhs",
                  "rhs", 166);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs166), "lhs",
                  "lhs", 166);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 167);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 167);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 167);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 167);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c27_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs167), "rhs",
                  "rhs", 167);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs167), "lhs",
                  "lhs", 167);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 168);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 168);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 168);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c27_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs168), "rhs",
                  "rhs", 168);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs168), "lhs",
                  "lhs", 168);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "context", "context", 169);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 169);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 169);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c27_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs169), "rhs",
                  "rhs", 169);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs169), "lhs",
                  "lhs", 169);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 170);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 170);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 170);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c27_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs170), "rhs",
                  "rhs", 170);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs170), "lhs",
                  "lhs", 170);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 171);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  171);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 171);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 171);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c27_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs171), "rhs",
                  "rhs", 171);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs171), "lhs",
                  "lhs", 171);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 172);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 172);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 172);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c27_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs172), "rhs",
                  "rhs", 172);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs172), "lhs",
                  "lhs", 172);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 173);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 173);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 173);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c27_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs173), "rhs",
                  "rhs", 173);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs173), "lhs",
                  "lhs", 173);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 174);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 174);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 174);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c27_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs174), "rhs",
                  "rhs", 174);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs174), "lhs",
                  "lhs", 174);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 175);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 175);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 175);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 175);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c27_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs175), "rhs",
                  "rhs", 175);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs175), "lhs",
                  "lhs", 175);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 176);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 176);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 176);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c27_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs176), "rhs",
                  "rhs", 176);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs176), "lhs",
                  "lhs", 176);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 177);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 177);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 177);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c27_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs177), "rhs",
                  "rhs", 177);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs177), "lhs",
                  "lhs", 177);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 178);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 178);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 178);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 178);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c27_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs178), "rhs",
                  "rhs", 178);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs178), "lhs",
                  "lhs", 178);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 179);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 179);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 179);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 179);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c27_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs179), "rhs",
                  "rhs", 179);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs179), "lhs",
                  "lhs", 179);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 180);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 180);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 180);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 180);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c27_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs180), "rhs",
                  "rhs", 180);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs180), "lhs",
                  "lhs", 180);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 181);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 181);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 181);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 181);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c27_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs181), "rhs",
                  "rhs", 181);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs181), "lhs",
                  "lhs", 181);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 182);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 182);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 182);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 182);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c27_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs182), "rhs",
                  "rhs", 182);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs182), "lhs",
                  "lhs", 182);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 183);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 183);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 183);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 183);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c27_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs183), "rhs",
                  "rhs", 183);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs183), "lhs",
                  "lhs", 183);
  sf_mex_destroy(&c27_rhs128);
  sf_mex_destroy(&c27_lhs128);
  sf_mex_destroy(&c27_rhs129);
  sf_mex_destroy(&c27_lhs129);
  sf_mex_destroy(&c27_rhs130);
  sf_mex_destroy(&c27_lhs130);
  sf_mex_destroy(&c27_rhs131);
  sf_mex_destroy(&c27_lhs131);
  sf_mex_destroy(&c27_rhs132);
  sf_mex_destroy(&c27_lhs132);
  sf_mex_destroy(&c27_rhs133);
  sf_mex_destroy(&c27_lhs133);
  sf_mex_destroy(&c27_rhs134);
  sf_mex_destroy(&c27_lhs134);
  sf_mex_destroy(&c27_rhs135);
  sf_mex_destroy(&c27_lhs135);
  sf_mex_destroy(&c27_rhs136);
  sf_mex_destroy(&c27_lhs136);
  sf_mex_destroy(&c27_rhs137);
  sf_mex_destroy(&c27_lhs137);
  sf_mex_destroy(&c27_rhs138);
  sf_mex_destroy(&c27_lhs138);
  sf_mex_destroy(&c27_rhs139);
  sf_mex_destroy(&c27_lhs139);
  sf_mex_destroy(&c27_rhs140);
  sf_mex_destroy(&c27_lhs140);
  sf_mex_destroy(&c27_rhs141);
  sf_mex_destroy(&c27_lhs141);
  sf_mex_destroy(&c27_rhs142);
  sf_mex_destroy(&c27_lhs142);
  sf_mex_destroy(&c27_rhs143);
  sf_mex_destroy(&c27_lhs143);
  sf_mex_destroy(&c27_rhs144);
  sf_mex_destroy(&c27_lhs144);
  sf_mex_destroy(&c27_rhs145);
  sf_mex_destroy(&c27_lhs145);
  sf_mex_destroy(&c27_rhs146);
  sf_mex_destroy(&c27_lhs146);
  sf_mex_destroy(&c27_rhs147);
  sf_mex_destroy(&c27_lhs147);
  sf_mex_destroy(&c27_rhs148);
  sf_mex_destroy(&c27_lhs148);
  sf_mex_destroy(&c27_rhs149);
  sf_mex_destroy(&c27_lhs149);
  sf_mex_destroy(&c27_rhs150);
  sf_mex_destroy(&c27_lhs150);
  sf_mex_destroy(&c27_rhs151);
  sf_mex_destroy(&c27_lhs151);
  sf_mex_destroy(&c27_rhs152);
  sf_mex_destroy(&c27_lhs152);
  sf_mex_destroy(&c27_rhs153);
  sf_mex_destroy(&c27_lhs153);
  sf_mex_destroy(&c27_rhs154);
  sf_mex_destroy(&c27_lhs154);
  sf_mex_destroy(&c27_rhs155);
  sf_mex_destroy(&c27_lhs155);
  sf_mex_destroy(&c27_rhs156);
  sf_mex_destroy(&c27_lhs156);
  sf_mex_destroy(&c27_rhs157);
  sf_mex_destroy(&c27_lhs157);
  sf_mex_destroy(&c27_rhs158);
  sf_mex_destroy(&c27_lhs158);
  sf_mex_destroy(&c27_rhs159);
  sf_mex_destroy(&c27_lhs159);
  sf_mex_destroy(&c27_rhs160);
  sf_mex_destroy(&c27_lhs160);
  sf_mex_destroy(&c27_rhs161);
  sf_mex_destroy(&c27_lhs161);
  sf_mex_destroy(&c27_rhs162);
  sf_mex_destroy(&c27_lhs162);
  sf_mex_destroy(&c27_rhs163);
  sf_mex_destroy(&c27_lhs163);
  sf_mex_destroy(&c27_rhs164);
  sf_mex_destroy(&c27_lhs164);
  sf_mex_destroy(&c27_rhs165);
  sf_mex_destroy(&c27_lhs165);
  sf_mex_destroy(&c27_rhs166);
  sf_mex_destroy(&c27_lhs166);
  sf_mex_destroy(&c27_rhs167);
  sf_mex_destroy(&c27_lhs167);
  sf_mex_destroy(&c27_rhs168);
  sf_mex_destroy(&c27_lhs168);
  sf_mex_destroy(&c27_rhs169);
  sf_mex_destroy(&c27_lhs169);
  sf_mex_destroy(&c27_rhs170);
  sf_mex_destroy(&c27_lhs170);
  sf_mex_destroy(&c27_rhs171);
  sf_mex_destroy(&c27_lhs171);
  sf_mex_destroy(&c27_rhs172);
  sf_mex_destroy(&c27_lhs172);
  sf_mex_destroy(&c27_rhs173);
  sf_mex_destroy(&c27_lhs173);
  sf_mex_destroy(&c27_rhs174);
  sf_mex_destroy(&c27_lhs174);
  sf_mex_destroy(&c27_rhs175);
  sf_mex_destroy(&c27_lhs175);
  sf_mex_destroy(&c27_rhs176);
  sf_mex_destroy(&c27_lhs176);
  sf_mex_destroy(&c27_rhs177);
  sf_mex_destroy(&c27_lhs177);
  sf_mex_destroy(&c27_rhs178);
  sf_mex_destroy(&c27_lhs178);
  sf_mex_destroy(&c27_rhs179);
  sf_mex_destroy(&c27_lhs179);
  sf_mex_destroy(&c27_rhs180);
  sf_mex_destroy(&c27_lhs180);
  sf_mex_destroy(&c27_rhs181);
  sf_mex_destroy(&c27_lhs181);
  sf_mex_destroy(&c27_rhs182);
  sf_mex_destroy(&c27_lhs182);
  sf_mex_destroy(&c27_rhs183);
  sf_mex_destroy(&c27_lhs183);
}

static void c27_eml_scalar_eg(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c27_use_refblas(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return false;
}

static void c27_threshold(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c27_b_eml_scalar_eg(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c27_eml_switch_helper(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c27_eml_error(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c27_i37;
  static char_T c27_cv0[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c27_u[33];
  const mxArray *c27_y = NULL;
  (void)chartInstance;
  for (c27_i37 = 0; c27_i37 < 33; c27_i37++) {
    c27_u[c27_i37] = c27_cv0[c27_i37];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c27_y));
}

static real_T c27_eml_xnrm2(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2])
{
  real_T c27_y;
  real_T c27_scale;
  int32_T c27_k;
  int32_T c27_b_k;
  real_T c27_b_x;
  real_T c27_c_x;
  real_T c27_absxk;
  real_T c27_t;
  c27_below_threshold(chartInstance);
  c27_y = 0.0;
  c27_realmin(chartInstance);
  c27_scale = 2.2250738585072014E-308;
  c27_eml_switch_helper(chartInstance);
  for (c27_k = 1; c27_k < 3; c27_k++) {
    c27_b_k = c27_k;
    c27_b_x = c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c27_b_k), 1, 2, 1, 0) - 1];
    c27_c_x = c27_b_x;
    c27_absxk = muDoubleScalarAbs(c27_c_x);
    if (c27_absxk > c27_scale) {
      c27_t = c27_scale / c27_absxk;
      c27_y = 1.0 + c27_y * c27_t * c27_t;
      c27_scale = c27_absxk;
    } else {
      c27_t = c27_absxk / c27_scale;
      c27_y += c27_t * c27_t;
    }
  }

  return c27_scale * muDoubleScalarSqrt(c27_y);
}

static void c27_below_threshold(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c27_realmin(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c27_abs(SFc27_hybridSysSimInstanceStruct *chartInstance, real_T
                      c27_x)
{
  real_T c27_b_x;
  (void)chartInstance;
  c27_b_x = c27_x;
  return muDoubleScalarAbs(c27_b_x);
}

static void c27_eps(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c27_b_eml_switch_helper(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c27_eml_xscal(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T c27_x[2], real_T c27_b_x[2])
{
  int32_T c27_i38;
  for (c27_i38 = 0; c27_i38 < 2; c27_i38++) {
    c27_b_x[c27_i38] = c27_x[c27_i38];
  }

  c27_c_eml_xscal(chartInstance, c27_a, c27_b_x);
}

static void c27_c_eml_scalar_eg(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c27_b_eml_error(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c27_i39;
  static char_T c27_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c27_u[30];
  const mxArray *c27_y = NULL;
  (void)chartInstance;
  for (c27_i39 = 0; c27_i39 < 30; c27_i39++) {
    c27_u[c27_i39] = c27_cv1[c27_i39];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c27_y));
}

static void c27_eml_pinv(SFc27_hybridSysSimInstanceStruct *chartInstance, real_T
  c27_X[2])
{
  int32_T c27_i40;
  int32_T c27_k;
  int32_T c27_b_k;
  real_T c27_x;
  real_T c27_b_x;
  boolean_T c27_b;
  boolean_T c27_b0;
  real_T c27_c_x;
  boolean_T c27_b_b;
  boolean_T c27_b1;
  boolean_T c27_c_b;
  real_T c27_V;
  real_T c27_S;
  real_T c27_U[2];
  real_T c27_b_S;
  real_T c27_b_V;
  real_T c27_s;
  real_T c27_c_V;
  real_T c27_b_s;
  real_T c27_d_V;
  real_T c27_c_S;
  real_T c27_d_S;
  real_T c27_e_V;
  real_T c27_tol;
  int32_T c27_r;
  int32_T c27_vcol;
  int32_T c27_b_r;
  int32_T c27_d_b;
  int32_T c27_e_b;
  boolean_T c27_overflow;
  int32_T c27_j;
  int32_T c27_b_j;
  real_T c27_y;
  real_T c27_b_y;
  real_T c27_z;
  int32_T c27_a;
  int32_T c27_b_a;
  int32_T c27_i41;
  real_T c27_b_U[2];
  for (c27_i40 = 0; c27_i40 < 2; c27_i40++) {
    c27_X[c27_i40] = 0.0;
  }

  c27_eml_switch_helper(chartInstance);
  for (c27_k = 1; c27_k < 3; c27_k++) {
    c27_b_k = c27_k;
    c27_x = 50.0 + 33.333333333333329 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_k), 1, 2, 1, 0) - 1);
    c27_b_x = c27_x;
    c27_b = muDoubleScalarIsInf(c27_b_x);
    c27_b0 = !c27_b;
    c27_c_x = c27_x;
    c27_b_b = muDoubleScalarIsNaN(c27_c_x);
    c27_b1 = !c27_b_b;
    c27_c_b = (c27_b0 && c27_b1);
    if (!c27_c_b) {
      c27_eml_error(chartInstance);
    }
  }

  c27_eml_matlab_zsvdc(chartInstance, c27_U, &c27_S, &c27_V);
  c27_b_S = c27_S;
  c27_b_V = c27_V;
  c27_s = c27_b_S;
  c27_c_V = c27_b_V;
  c27_b_s = c27_s;
  c27_d_V = c27_c_V;
  c27_c_S = c27_b_s;
  c27_d_S = c27_c_S;
  c27_e_V = c27_d_V;
  c27_eps(chartInstance);
  c27_tol = 2.0 * c27_d_S * 2.2204460492503131E-16;
  c27_r = 0;
  if (!(c27_d_S > c27_tol)) {
  } else {
    c27_r = 1;
  }

  if (c27_r > 0) {
    c27_vcol = 1;
    c27_b_r = c27_r;
    c27_d_b = c27_b_r;
    c27_e_b = c27_d_b;
    if (1 > c27_e_b) {
      c27_overflow = false;
    } else {
      c27_eml_switch_helper(chartInstance);
      c27_eml_switch_helper(chartInstance);
      c27_overflow = (c27_e_b > 2147483646);
    }

    if (c27_overflow) {
      c27_check_forloop_overflow_error(chartInstance, c27_overflow);
    }

    for (c27_j = 1; c27_j <= c27_b_r; c27_j++) {
      c27_b_j = c27_j;
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c27_b_j), 1, 1, 1, 0);
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c27_b_j), 1, 1, 2, 0);
      c27_y = c27_d_S;
      c27_b_y = c27_y;
      c27_z = 1.0 / c27_b_y;
      c27_d_eml_xscal(chartInstance, c27_z, &c27_e_V, c27_vcol);
      c27_a = c27_vcol;
      c27_b_a = c27_a + 1;
      c27_vcol = c27_b_a;
    }

    for (c27_i41 = 0; c27_i41 < 2; c27_i41++) {
      c27_b_U[c27_i41] = c27_U[c27_i41];
    }

    c27_b_eml_xgemm(chartInstance, c27_r, c27_e_V, c27_b_U, c27_X);
  }
}

static void c27_eml_matlab_zsvdc(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_U[2], real_T *c27_S, real_T *c27_V)
{
  int32_T c27_i42;
  real_T c27_A[2];
  int32_T c27_i43;
  int32_T c27_i44;
  real_T c27_dv3[2];
  real_T c27_nrm;
  real_T c27_absx;
  real_T c27_s;
  real_T c27_a;
  real_T c27_x;
  real_T c27_b_x;
  real_T c27_y;
  real_T c27_B;
  real_T c27_b_y;
  real_T c27_c_y;
  real_T c27_d_y;
  real_T c27_e_y;
  real_T c27_b_a;
  real_T c27_c_a;
  int32_T c27_k;
  int32_T c27_b_k;
  int32_T c27_c_k;
  int32_T c27_d_k;
  real_T c27_b_A;
  real_T c27_b_B;
  real_T c27_c_x;
  real_T c27_f_y;
  real_T c27_d_x;
  real_T c27_g_y;
  real_T c27_e_x;
  real_T c27_h_y;
  real_T c27_i_y;
  int32_T c27_ii;
  int32_T c27_b_ii;
  int32_T c27_m;
  real_T c27_e;
  int32_T c27_c_ii;
  int32_T c27_d_ii;
  real_T c27_Vf;
  real_T c27_rt;
  real_T c27_c_A;
  real_T c27_c_B;
  real_T c27_f_x;
  real_T c27_j_y;
  real_T c27_g_x;
  real_T c27_k_y;
  real_T c27_h_x;
  real_T c27_l_y;
  real_T c27_r;
  real_T c27_iter;
  real_T c27_varargin_1;
  real_T c27_varargin_2;
  real_T c27_i_x;
  real_T c27_j_x;
  real_T c27_xk;
  real_T c27_k_x;
  real_T c27_maxval;
  real_T c27_b_varargin_2;
  real_T c27_varargin_3;
  real_T c27_m_y;
  real_T c27_n_y;
  real_T c27_yk;
  real_T c27_o_y;
  real_T c27_snorm;
  int32_T c27_q;
  int32_T c27_i45;
  int32_T c27_d_a;
  int32_T c27_e_a;
  boolean_T c27_overflow;
  int32_T c27_e_ii;
  real_T c27_test0;
  real_T c27_ztest0;
  real_T c27_kase;
  int32_T c27_qs;
  int32_T c27_b_m;
  int32_T c27_b_q;
  int32_T c27_f_a;
  int32_T c27_b;
  int32_T c27_g_a;
  int32_T c27_b_b;
  boolean_T c27_b_overflow;
  int32_T c27_f_ii;
  real_T c27_test;
  real_T c27_ztest;
  real_T c27_f;
  int32_T c27_i46;
  int32_T c27_c_q;
  int32_T c27_h_a;
  int32_T c27_c_b;
  int32_T c27_i_a;
  int32_T c27_d_b;
  boolean_T c27_c_overflow;
  int32_T c27_e_k;
  int32_T c27_f_k;
  real_T c27_t1;
  real_T c27_b_t1;
  real_T c27_b_f;
  real_T c27_sn;
  real_T c27_cs;
  real_T c27_b_cs;
  real_T c27_b_sn;
  int32_T c27_km1;
  int32_T c27_colk;
  int32_T c27_colm;
  int32_T c27_qm1;
  int32_T c27_d_q;
  int32_T c27_c_m;
  int32_T c27_j_a;
  int32_T c27_e_b;
  int32_T c27_k_a;
  int32_T c27_f_b;
  boolean_T c27_d_overflow;
  int32_T c27_g_k;
  real_T c27_c_t1;
  real_T c27_unusedU0;
  real_T c27_c_sn;
  real_T c27_c_cs;
  int32_T c27_colqm1;
  int32_T c27_mm1;
  real_T c27_d1;
  real_T c27_d2;
  real_T c27_d3;
  real_T c27_d4;
  real_T c27_d5;
  real_T c27_b_varargin_1[5];
  int32_T c27_ixstart;
  real_T c27_mtmp;
  real_T c27_l_x;
  boolean_T c27_g_b;
  int32_T c27_ix;
  int32_T c27_b_ix;
  real_T c27_m_x;
  boolean_T c27_h_b;
  int32_T c27_l_a;
  int32_T c27_m_a;
  int32_T c27_i47;
  int32_T c27_n_a;
  int32_T c27_o_a;
  boolean_T c27_e_overflow;
  int32_T c27_c_ix;
  real_T c27_p_a;
  real_T c27_i_b;
  boolean_T c27_p;
  real_T c27_b_mtmp;
  real_T c27_scale;
  real_T c27_d_A;
  real_T c27_d_B;
  real_T c27_n_x;
  real_T c27_p_y;
  real_T c27_o_x;
  real_T c27_q_y;
  real_T c27_p_x;
  real_T c27_r_y;
  real_T c27_sm;
  real_T c27_e_A;
  real_T c27_e_B;
  real_T c27_q_x;
  real_T c27_s_y;
  real_T c27_r_x;
  real_T c27_t_y;
  real_T c27_s_x;
  real_T c27_u_y;
  real_T c27_smm1;
  real_T c27_f_A;
  real_T c27_f_B;
  real_T c27_t_x;
  real_T c27_v_y;
  real_T c27_u_x;
  real_T c27_w_y;
  real_T c27_v_x;
  real_T c27_x_y;
  real_T c27_emm1;
  real_T c27_g_A;
  real_T c27_g_B;
  real_T c27_w_x;
  real_T c27_y_y;
  real_T c27_x_x;
  real_T c27_ab_y;
  real_T c27_y_x;
  real_T c27_bb_y;
  real_T c27_sqds;
  real_T c27_h_A;
  real_T c27_h_B;
  real_T c27_ab_x;
  real_T c27_cb_y;
  real_T c27_bb_x;
  real_T c27_db_y;
  real_T c27_cb_x;
  real_T c27_eb_y;
  real_T c27_eqds;
  real_T c27_i_A;
  real_T c27_db_x;
  real_T c27_eb_x;
  real_T c27_fb_x;
  real_T c27_j_b;
  real_T c27_c;
  real_T c27_shift;
  real_T c27_j_A;
  real_T c27_i_B;
  real_T c27_gb_x;
  real_T c27_fb_y;
  real_T c27_hb_x;
  real_T c27_gb_y;
  real_T c27_ib_x;
  real_T c27_hb_y;
  real_T c27_g;
  int32_T c27_e_q;
  int32_T c27_b_mm1;
  int32_T c27_q_a;
  int32_T c27_k_b;
  int32_T c27_r_a;
  int32_T c27_l_b;
  boolean_T c27_f_overflow;
  int32_T c27_h_k;
  int32_T c27_kp1;
  real_T c27_c_f;
  real_T c27_unusedU1;
  real_T c27_d_sn;
  real_T c27_d_cs;
  int32_T c27_colkp1;
  real_T c27_d_f;
  real_T c27_unusedU2;
  real_T c27_e_sn;
  real_T c27_e_cs;
  int32_T c27_qp1;
  int32_T c27_colq;
  int32_T c27_colqp1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = false;
  for (c27_i42 = 0; c27_i42 < 2; c27_i42++) {
    c27_A[c27_i42] = 50.0 + 33.333333333333329 * (real_T)c27_i42;
  }

  c27_b_eml_scalar_eg(chartInstance);
  for (c27_i43 = 0; c27_i43 < 2; c27_i43++) {
    c27_U[c27_i43] = 0.0;
  }

  for (c27_i44 = 0; c27_i44 < 2; c27_i44++) {
    c27_dv3[c27_i44] = 50.0 + 33.333333333333329 * (real_T)c27_i44;
  }

  c27_nrm = c27_eml_xnrm2(chartInstance, c27_dv3);
  if (c27_nrm > 0.0) {
    c27_absx = c27_nrm;
    c27_s = c27_absx;
    c27_a = c27_s;
    c27_realmin(chartInstance);
    c27_eps(chartInstance);
    c27_x = c27_a;
    c27_b_x = c27_x;
    c27_y = muDoubleScalarAbs(c27_b_x);
    if (c27_y >= 1.0020841800044864E-292) {
      c27_B = c27_a;
      c27_b_y = c27_B;
      c27_c_y = c27_b_y;
      c27_d_y = c27_c_y;
      c27_e_y = 1.0 / c27_d_y;
      c27_b_a = c27_e_y;
      c27_b_eml_switch_helper(chartInstance);
      c27_c_a = c27_b_a;
      c27_eml_switch_helper(chartInstance);
      for (c27_k = 1; c27_k < 3; c27_k++) {
        c27_b_k = c27_k;
        c27_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c27_b_k), 1, 2, 1, 0) - 1] = c27_c_a *
          c27_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c27_b_k), 1, 2, 1, 0) - 1];
      }
    } else {
      c27_eml_switch_helper(chartInstance);
      for (c27_c_k = 1; c27_c_k < 3; c27_c_k++) {
        c27_d_k = c27_c_k;
        c27_b_A = c27_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c27_d_k), 1, 2, 1, 0) - 1];
        c27_b_B = c27_a;
        c27_c_x = c27_b_A;
        c27_f_y = c27_b_B;
        c27_d_x = c27_c_x;
        c27_g_y = c27_f_y;
        c27_e_x = c27_d_x;
        c27_h_y = c27_g_y;
        c27_i_y = c27_e_x / c27_h_y;
        c27_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c27_d_k), 1, 2, 1, 0) - 1] = c27_i_y;
      }
    }

    c27_A[0]++;
    c27_s = -c27_s;
  } else {
    c27_s = 0.0;
  }

  c27_eml_switch_helper(chartInstance);
  for (c27_ii = 1; c27_ii < 3; c27_ii++) {
    c27_b_ii = c27_ii;
    c27_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_b_ii), 1, 2, 1, 0) - 1] = c27_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_ii), 1, 2, 1, 0) - 1];
  }

  c27_m = 1;
  c27_e = 0.0;
  if (c27_s != 0.0) {
    c27_eml_switch_helper(chartInstance);
    for (c27_c_ii = 1; c27_c_ii < 3; c27_c_ii++) {
      c27_b_ii = c27_c_ii;
      c27_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c27_b_ii), 1, 2, 1, 0) - 1] = -c27_U[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_ii), 1, 2, 1, 0) - 1];
    }

    c27_U[0]++;
  } else {
    c27_eml_switch_helper(chartInstance);
    for (c27_d_ii = 1; c27_d_ii < 3; c27_d_ii++) {
      c27_b_ii = c27_d_ii;
      c27_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c27_b_ii), 1, 2, 1, 0) - 1] = 0.0;
    }

    c27_U[0] = 1.0;
  }

  c27_Vf = 1.0;
  if (c27_s != 0.0) {
    c27_rt = c27_abs(chartInstance, c27_s);
    c27_c_A = c27_s;
    c27_c_B = c27_rt;
    c27_f_x = c27_c_A;
    c27_j_y = c27_c_B;
    c27_g_x = c27_f_x;
    c27_k_y = c27_j_y;
    c27_h_x = c27_g_x;
    c27_l_y = c27_k_y;
    c27_r = c27_h_x / c27_l_y;
    c27_s = c27_rt;
    c27_c_eml_xscal(chartInstance, c27_r, c27_U);
  }

  c27_iter = 0.0;
  c27_realmin(chartInstance);
  c27_eps(chartInstance);
  c27_varargin_1 = c27_abs(chartInstance, c27_s);
  c27_varargin_2 = c27_varargin_1;
  c27_i_x = c27_varargin_2;
  c27_j_x = c27_i_x;
  c27_c_eml_scalar_eg(chartInstance);
  c27_xk = c27_j_x;
  c27_k_x = c27_xk;
  c27_c_eml_scalar_eg(chartInstance);
  c27_maxval = muDoubleScalarMax(c27_k_x, 0.0);
  c27_b_varargin_2 = c27_maxval;
  c27_varargin_3 = c27_b_varargin_2;
  c27_m_y = c27_varargin_3;
  c27_n_y = c27_m_y;
  c27_c_eml_scalar_eg(chartInstance);
  c27_yk = c27_n_y;
  c27_o_y = c27_yk;
  c27_c_eml_scalar_eg(chartInstance);
  c27_snorm = muDoubleScalarMax(0.0, c27_o_y);
  exitg1 = false;
  while ((exitg1 == false) && (c27_m > 0)) {
    if (c27_iter >= 75.0) {
      c27_b_eml_error(chartInstance);
      exitg1 = true;
    } else {
      c27_q = c27_m - 1;
      c27_i45 = c27_m - 1;
      c27_d_a = c27_i45;
      c27_e_a = c27_d_a;
      if (c27_e_a < 0) {
        c27_overflow = false;
      } else {
        c27_eml_switch_helper(chartInstance);
        c27_eml_switch_helper(chartInstance);
        c27_overflow = false;
      }

      if (c27_overflow) {
        c27_check_forloop_overflow_error(chartInstance, c27_overflow);
      }

      c27_e_ii = c27_i45;
      guard3 = false;
      guard4 = false;
      exitg5 = false;
      while ((exitg5 == false) && (c27_e_ii > -1)) {
        c27_b_ii = c27_e_ii;
        c27_q = c27_b_ii;
        if (c27_b_ii == 0) {
          exitg5 = true;
        } else {
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_b_ii), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c27_b_ii + 1)), 1, 1, 1, 0);
          c27_test0 = c27_abs(chartInstance, c27_s) + c27_abs(chartInstance,
            c27_s);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_b_ii), 1, 1, 1, 0);
          c27_ztest0 = c27_abs(chartInstance, c27_e);
          c27_eps(chartInstance);
          if (c27_ztest0 <= 2.2204460492503131E-16 * c27_test0) {
            guard4 = true;
            exitg5 = true;
          } else if (c27_ztest0 <= 1.0020841800044864E-292) {
            guard4 = true;
            exitg5 = true;
          } else {
            guard11 = false;
            if (c27_iter > 20.0) {
              c27_eps(chartInstance);
              if (c27_ztest0 <= 2.2204460492503131E-16 * c27_snorm) {
                guard3 = true;
                exitg5 = true;
              } else {
                guard11 = true;
              }
            } else {
              guard11 = true;
            }

            if (guard11 == true) {
              c27_e_ii--;
              guard3 = false;
              guard4 = false;
            }
          }
        }
      }

      if (guard4 == true) {
        guard3 = true;
      }

      if (guard3 == true) {
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_b_ii), 1, 1, 1, 0);
        c27_e = 0.0;
      }

      if (c27_q == c27_m - 1) {
        c27_kase = 4.0;
      } else {
        c27_qs = c27_m;
        c27_b_m = c27_m;
        c27_b_q = c27_q;
        c27_f_a = c27_b_m;
        c27_b = c27_b_q;
        c27_g_a = c27_f_a;
        c27_b_b = c27_b;
        if (c27_g_a < c27_b_b) {
          c27_b_overflow = false;
        } else {
          c27_eml_switch_helper(chartInstance);
          c27_eml_switch_helper(chartInstance);
          c27_b_overflow = (c27_b_b < -2147483647);
        }

        if (c27_b_overflow) {
          c27_check_forloop_overflow_error(chartInstance, c27_b_overflow);
        }

        c27_f_ii = c27_b_m;
        guard2 = false;
        exitg4 = false;
        while ((exitg4 == false) && (c27_f_ii >= c27_b_q)) {
          c27_b_ii = c27_f_ii;
          c27_qs = c27_b_ii;
          if (c27_b_ii == c27_q) {
            exitg4 = true;
          } else {
            c27_test = 0.0;
            if (c27_b_ii < c27_m) {
              _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c27_b_ii), 1, 1, 1, 0);
              c27_test = c27_abs(chartInstance, c27_e);
            }

            if (c27_b_ii > c27_q + 1) {
              _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)(c27_b_ii - 1)), 1, 1, 1, 0);
              c27_test += c27_abs(chartInstance, c27_e);
            }

            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c27_b_ii), 1, 1, 1, 0);
            c27_ztest = c27_abs(chartInstance, c27_s);
            c27_eps(chartInstance);
            if (c27_ztest <= 2.2204460492503131E-16 * c27_test) {
              guard2 = true;
              exitg4 = true;
            } else if (c27_ztest <= 1.0020841800044864E-292) {
              guard2 = true;
              exitg4 = true;
            } else {
              c27_f_ii--;
              guard2 = false;
            }
          }
        }

        if (guard2 == true) {
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_b_ii), 1, 1, 1, 0);
          c27_s = 0.0;
        }

        if (c27_qs == c27_q) {
          c27_kase = 3.0;
        } else if (c27_qs == c27_m) {
          c27_kase = 1.0;
        } else {
          c27_kase = 2.0;
          c27_q = c27_qs;
        }
      }

      c27_q++;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c27_kase)) {
       case 1:
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                                     (c27_m - 1)), 1, 1, 1, 0);
        c27_f = c27_e;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                                     (c27_m - 1)), 1, 1, 1, 0);
        c27_e = 0.0;
        c27_i46 = c27_m - 1;
        c27_c_q = c27_q;
        c27_h_a = c27_i46;
        c27_c_b = c27_c_q;
        c27_i_a = c27_h_a;
        c27_d_b = c27_c_b;
        if (c27_i_a < c27_d_b) {
          c27_c_overflow = false;
        } else {
          c27_eml_switch_helper(chartInstance);
          c27_eml_switch_helper(chartInstance);
          c27_c_overflow = (c27_d_b < -2147483647);
        }

        if (c27_c_overflow) {
          c27_check_forloop_overflow_error(chartInstance, c27_c_overflow);
        }

        for (c27_e_k = c27_i46; c27_e_k >= c27_c_q; c27_e_k--) {
          c27_f_k = c27_e_k;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_t1 = c27_s;
          c27_b_t1 = c27_t1;
          c27_b_f = c27_f;
          c27_b_eml_xrotg(chartInstance, &c27_b_t1, &c27_b_f, &c27_cs, &c27_sn);
          c27_t1 = c27_b_t1;
          c27_f = c27_b_f;
          c27_b_cs = c27_cs;
          c27_b_sn = c27_sn;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_s = c27_t1;
          if (c27_f_k > c27_q) {
            c27_km1 = c27_f_k - 1;
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c27_km1), 1, 1, 1, 0);
            c27_f = -c27_b_sn * c27_e;
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c27_km1), 1, 1, 1, 0);
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c27_km1), 1, 1, 1, 0);
            c27_e *= c27_b_cs;
          }

          c27_colk = c27_f_k;
          c27_colm = c27_m;
          c27_c_eml_xrot(chartInstance, &c27_Vf, c27_colk, c27_colm, c27_b_cs,
                         c27_b_sn);
        }
        break;

       case 2:
        c27_qm1 = c27_q - 1;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_qm1), 1, 1, 1, 0);
        c27_f = c27_e;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_qm1), 1, 1, 1, 0);
        c27_e = 0.0;
        c27_d_q = c27_q;
        c27_c_m = c27_m;
        c27_j_a = c27_d_q;
        c27_e_b = c27_c_m;
        c27_k_a = c27_j_a;
        c27_f_b = c27_e_b;
        if (c27_k_a > c27_f_b) {
          c27_d_overflow = false;
        } else {
          c27_eml_switch_helper(chartInstance);
          c27_eml_switch_helper(chartInstance);
          c27_d_overflow = (c27_f_b > 2147483646);
        }

        if (c27_d_overflow) {
          c27_check_forloop_overflow_error(chartInstance, c27_d_overflow);
        }

        for (c27_g_k = c27_d_q; c27_g_k <= c27_c_m; c27_g_k++) {
          c27_f_k = c27_g_k;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_t1 = c27_s;
          c27_c_t1 = c27_t1;
          c27_unusedU0 = c27_f;
          c27_b_eml_xrotg(chartInstance, &c27_c_t1, &c27_unusedU0, &c27_c_cs,
                          &c27_c_sn);
          c27_t1 = c27_c_t1;
          c27_b_cs = c27_c_cs;
          c27_b_sn = c27_c_sn;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_s = c27_t1;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_f = -c27_b_sn * c27_e;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_e *= c27_b_cs;
          c27_colk = (c27_f_k - 1) << 1;
          c27_colqm1 = (c27_qm1 - 1) << 1;
          c27_d_eml_xrot(chartInstance, c27_U, c27_colk + 1, c27_colqm1 + 1,
                         c27_b_cs, c27_b_sn);
        }
        break;

       case 3:
        c27_mm1 = c27_m - 1;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_m), 1, 1, 1, 0);
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_mm1), 1, 1, 1, 0);
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_mm1), 1, 1, 1, 0);
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_q), 1, 1, 1, 0);
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_q), 1, 1, 1, 0);
        c27_d1 = c27_abs(chartInstance, c27_s);
        c27_d2 = c27_abs(chartInstance, c27_s);
        c27_d3 = c27_abs(chartInstance, c27_e);
        c27_d4 = c27_abs(chartInstance, c27_s);
        c27_d5 = c27_abs(chartInstance, c27_e);
        c27_b_varargin_1[0] = c27_d1;
        c27_b_varargin_1[1] = c27_d2;
        c27_b_varargin_1[2] = c27_d3;
        c27_b_varargin_1[3] = c27_d4;
        c27_b_varargin_1[4] = c27_d5;
        c27_ixstart = 1;
        c27_mtmp = c27_b_varargin_1[0];
        c27_l_x = c27_mtmp;
        c27_g_b = muDoubleScalarIsNaN(c27_l_x);
        if (c27_g_b) {
          c27_eml_switch_helper(chartInstance);
          c27_eml_switch_helper(chartInstance);
          c27_ix = 2;
          exitg2 = false;
          while ((exitg2 == false) && (c27_ix < 6)) {
            c27_b_ix = c27_ix;
            c27_ixstart = c27_b_ix;
            c27_m_x = c27_b_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c27_b_ix), 1, 5, 1, 0) - 1];
            c27_h_b = muDoubleScalarIsNaN(c27_m_x);
            if (!c27_h_b) {
              c27_mtmp = c27_b_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_ix), 1, 5, 1, 0) -
                1];
              exitg2 = true;
            } else {
              c27_ix++;
            }
          }
        }

        if (c27_ixstart < 5) {
          c27_l_a = c27_ixstart;
          c27_m_a = c27_l_a + 1;
          c27_i47 = c27_m_a;
          c27_n_a = c27_i47;
          c27_o_a = c27_n_a;
          if (c27_o_a > 5) {
            c27_e_overflow = false;
          } else {
            c27_eml_switch_helper(chartInstance);
            c27_eml_switch_helper(chartInstance);
            c27_e_overflow = false;
          }

          if (c27_e_overflow) {
            c27_check_forloop_overflow_error(chartInstance, c27_e_overflow);
          }

          for (c27_c_ix = c27_i47; c27_c_ix < 6; c27_c_ix++) {
            c27_b_ix = c27_c_ix;
            c27_p_a = c27_b_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c27_b_ix), 1, 5, 1, 0) - 1];
            c27_i_b = c27_mtmp;
            c27_p = (c27_p_a > c27_i_b);
            if (c27_p) {
              c27_mtmp = c27_b_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_ix), 1, 5, 1, 0) -
                1];
            }
          }
        }

        c27_b_mtmp = c27_mtmp;
        c27_scale = c27_b_mtmp;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_m), 1, 1, 1, 0);
        c27_d_A = c27_s;
        c27_d_B = c27_scale;
        c27_n_x = c27_d_A;
        c27_p_y = c27_d_B;
        c27_o_x = c27_n_x;
        c27_q_y = c27_p_y;
        c27_p_x = c27_o_x;
        c27_r_y = c27_q_y;
        c27_sm = c27_p_x / c27_r_y;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_mm1), 1, 1, 1, 0);
        c27_e_A = c27_s;
        c27_e_B = c27_scale;
        c27_q_x = c27_e_A;
        c27_s_y = c27_e_B;
        c27_r_x = c27_q_x;
        c27_t_y = c27_s_y;
        c27_s_x = c27_r_x;
        c27_u_y = c27_t_y;
        c27_smm1 = c27_s_x / c27_u_y;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_mm1), 1, 1, 1, 0);
        c27_f_A = c27_e;
        c27_f_B = c27_scale;
        c27_t_x = c27_f_A;
        c27_v_y = c27_f_B;
        c27_u_x = c27_t_x;
        c27_w_y = c27_v_y;
        c27_v_x = c27_u_x;
        c27_x_y = c27_w_y;
        c27_emm1 = c27_v_x / c27_x_y;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_q), 1, 1, 1, 0);
        c27_g_A = c27_s;
        c27_g_B = c27_scale;
        c27_w_x = c27_g_A;
        c27_y_y = c27_g_B;
        c27_x_x = c27_w_x;
        c27_ab_y = c27_y_y;
        c27_y_x = c27_x_x;
        c27_bb_y = c27_ab_y;
        c27_sqds = c27_y_x / c27_bb_y;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_q), 1, 1, 1, 0);
        c27_h_A = c27_e;
        c27_h_B = c27_scale;
        c27_ab_x = c27_h_A;
        c27_cb_y = c27_h_B;
        c27_bb_x = c27_ab_x;
        c27_db_y = c27_cb_y;
        c27_cb_x = c27_bb_x;
        c27_eb_y = c27_db_y;
        c27_eqds = c27_cb_x / c27_eb_y;
        c27_i_A = (c27_smm1 + c27_sm) * (c27_smm1 - c27_sm) + c27_emm1 *
          c27_emm1;
        c27_db_x = c27_i_A;
        c27_eb_x = c27_db_x;
        c27_fb_x = c27_eb_x;
        c27_j_b = c27_fb_x / 2.0;
        c27_c = c27_sm * c27_emm1;
        c27_c *= c27_c;
        guard1 = false;
        if (c27_j_b != 0.0) {
          guard1 = true;
        } else if (c27_c != 0.0) {
          guard1 = true;
        } else {
          c27_shift = 0.0;
        }

        if (guard1 == true) {
          c27_shift = c27_j_b * c27_j_b + c27_c;
          c27_b_sqrt(chartInstance, &c27_shift);
          if (c27_j_b < 0.0) {
            c27_shift = -c27_shift;
          }

          c27_j_A = c27_c;
          c27_i_B = c27_j_b + c27_shift;
          c27_gb_x = c27_j_A;
          c27_fb_y = c27_i_B;
          c27_hb_x = c27_gb_x;
          c27_gb_y = c27_fb_y;
          c27_ib_x = c27_hb_x;
          c27_hb_y = c27_gb_y;
          c27_shift = c27_ib_x / c27_hb_y;
        }

        c27_f = (c27_sqds + c27_sm) * (c27_sqds - c27_sm) + c27_shift;
        c27_g = c27_sqds * c27_eqds;
        c27_e_q = c27_q;
        c27_b_mm1 = c27_mm1;
        c27_q_a = c27_e_q;
        c27_k_b = c27_b_mm1;
        c27_r_a = c27_q_a;
        c27_l_b = c27_k_b;
        if (c27_r_a > c27_l_b) {
          c27_f_overflow = false;
        } else {
          c27_eml_switch_helper(chartInstance);
          c27_eml_switch_helper(chartInstance);
          c27_f_overflow = (c27_l_b > 2147483646);
        }

        if (c27_f_overflow) {
          c27_check_forloop_overflow_error(chartInstance, c27_f_overflow);
        }

        for (c27_h_k = c27_e_q; c27_h_k <= c27_b_mm1; c27_h_k++) {
          c27_f_k = c27_h_k;
          c27_km1 = c27_f_k;
          c27_kp1 = c27_f_k + 1;
          c27_c_f = c27_f;
          c27_unusedU1 = c27_g;
          c27_b_eml_xrotg(chartInstance, &c27_c_f, &c27_unusedU1, &c27_d_cs,
                          &c27_d_sn);
          c27_f = c27_c_f;
          c27_b_cs = c27_d_cs;
          c27_b_sn = c27_d_sn;
          if (c27_f_k > c27_q) {
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c27_km1 - 1)), 1, 1, 1, 0);
            c27_e = c27_f;
          }

          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_f = c27_b_cs * c27_s + c27_b_sn * c27_e;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_e = c27_b_cs * c27_e - c27_b_sn * c27_s;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          c27_g = c27_b_sn * c27_s;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          c27_colk = c27_f_k;
          c27_colkp1 = c27_f_k;
          c27_c_eml_xrot(chartInstance, &c27_Vf, c27_colk, c27_colkp1 + 1,
                         c27_b_cs, c27_b_sn);
          c27_d_f = c27_f;
          c27_unusedU2 = c27_g;
          c27_b_eml_xrotg(chartInstance, &c27_d_f, &c27_unusedU2, &c27_e_cs,
                          &c27_e_sn);
          c27_f = c27_d_f;
          c27_b_cs = c27_e_cs;
          c27_b_sn = c27_e_sn;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          c27_s = c27_f;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          c27_f = c27_b_cs * c27_e + c27_b_sn * c27_s;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_f_k), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          c27_s = -c27_b_sn * c27_e + c27_b_cs * c27_s;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          c27_g = c27_b_sn * c27_e;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_kp1), 1, 1, 1, 0);
          c27_e *= c27_b_cs;
          if (c27_f_k < 2) {
            c27_colk = (c27_f_k - 1) << 1;
            c27_colkp1 = c27_f_k << 1;
            c27_d_eml_xrot(chartInstance, c27_U, c27_colk + 1, c27_colkp1 + 1,
                           c27_b_cs, c27_b_sn);
          }
        }

        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                                     (c27_m - 1)), 1, 1, 1, 0);
        c27_e = c27_f;
        c27_iter++;
        break;

       default:
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c27_q), 1, 1, 1, 0);
        if (c27_s < 0.0) {
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_q), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_q), 1, 1, 1, 0);
          c27_s = -c27_s;
          c27_colq = c27_q;
          c27_d_eml_scalar_eg(chartInstance);
          c27_d_eml_xscal(chartInstance, -1.0, &c27_Vf, c27_colq);
        }

        c27_qp1 = c27_q + 1;
        exitg3 = false;
        while ((exitg3 == false) && (c27_q < 1)) {
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_q), 1, 1, 1, 0);
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_qp1), 1, 1, 1, 0);
          if (c27_s < c27_s) {
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c27_q), 1, 1, 1, 0);
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c27_qp1), 1, 1, 1, 0);
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c27_q), 1, 1, 1, 0);
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c27_qp1), 1, 1, 1, 0);
            if (c27_q < 1) {
              c27_colq = c27_q;
              c27_colqp1 = c27_q;
              c27_c_eml_xswap(chartInstance, &c27_Vf, c27_colq, c27_colqp1 + 1);
            }

            if (c27_q < 2) {
              c27_colq = (c27_q - 1) << 1;
              c27_colqp1 = c27_q << 1;
              c27_d_eml_xswap(chartInstance, c27_U, c27_colq + 1, c27_colqp1 + 1);
            }

            c27_q = c27_qp1;
            c27_qp1 = c27_q + 1;
          } else {
            exitg3 = true;
          }
        }

        c27_iter = 0.0;
        c27_m--;
        break;
      }
    }
  }

  *c27_S = c27_s;
  *c27_V = c27_Vf;
}

static void c27_check_forloop_overflow_error(SFc27_hybridSysSimInstanceStruct
  *chartInstance, boolean_T c27_overflow)
{
  int32_T c27_i48;
  static char_T c27_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c27_u[34];
  const mxArray *c27_y = NULL;
  int32_T c27_i49;
  static char_T c27_cv3[5] = { 'i', 'n', 't', '3', '2' };

  char_T c27_b_u[5];
  const mxArray *c27_b_y = NULL;
  (void)chartInstance;
  if (!c27_overflow) {
  } else {
    for (c27_i48 = 0; c27_i48 < 34; c27_i48++) {
      c27_u[c27_i48] = c27_cv2[c27_i48];
    }

    c27_y = NULL;
    sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c27_i49 = 0; c27_i49 < 5; c27_i49++) {
      c27_b_u[c27_i49] = c27_cv3[c27_i49];
    }

    c27_b_y = NULL;
    sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c27_y, 14, c27_b_y));
  }
}

static real_T c27_sqrt(SFc27_hybridSysSimInstanceStruct *chartInstance, real_T
  c27_x)
{
  real_T c27_b_x;
  c27_b_x = c27_x;
  c27_b_sqrt(chartInstance, &c27_b_x);
  return c27_b_x;
}

static void c27_c_eml_error(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c27_i50;
  static char_T c27_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c27_u[30];
  const mxArray *c27_y = NULL;
  int32_T c27_i51;
  static char_T c27_cv5[4] = { 's', 'q', 'r', 't' };

  char_T c27_b_u[4];
  const mxArray *c27_b_y = NULL;
  (void)chartInstance;
  for (c27_i50 = 0; c27_i50 < 30; c27_i50++) {
    c27_u[c27_i50] = c27_cv4[c27_i50];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c27_i51 = 0; c27_i51 < 4; c27_i51++) {
    c27_b_u[c27_i51] = c27_cv5[c27_i51];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c27_y, 14, c27_b_y));
}

static void c27_eml_xrotg(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T c27_b, real_T *c27_b_a, real_T *c27_b_b, real_T *c27_c,
  real_T *c27_s)
{
  *c27_b_a = c27_a;
  *c27_b_b = c27_b;
  c27_b_eml_xrotg(chartInstance, c27_b_a, c27_b_b, c27_c, c27_s);
}

static real_T c27_eml_xrot(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x, int32_T c27_ix0, int32_T c27_iy0, real_T c27_c, real_T c27_s)
{
  real_T c27_b_x;
  c27_b_x = c27_x;
  c27_c_eml_xrot(chartInstance, &c27_b_x, c27_ix0, c27_iy0, c27_c, c27_s);
  return c27_b_x;
}

static void c27_b_threshold(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c27_b_eml_xrot(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], int32_T c27_ix0, int32_T c27_iy0, real_T c27_c, real_T c27_s,
  real_T c27_b_x[2])
{
  int32_T c27_i52;
  for (c27_i52 = 0; c27_i52 < 2; c27_i52++) {
    c27_b_x[c27_i52] = c27_x[c27_i52];
  }

  c27_d_eml_xrot(chartInstance, c27_b_x, c27_ix0, c27_iy0, c27_c, c27_s);
}

static void c27_d_eml_scalar_eg(SFc27_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c27_b_eml_xscal(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T c27_x, int32_T c27_ix0)
{
  real_T c27_b_x;
  c27_b_x = c27_x;
  c27_d_eml_xscal(chartInstance, c27_a, &c27_b_x, c27_ix0);
  return c27_b_x;
}

static real_T c27_eml_xswap(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x, int32_T c27_ix0, int32_T c27_iy0)
{
  real_T c27_b_x;
  c27_b_x = c27_x;
  c27_c_eml_xswap(chartInstance, &c27_b_x, c27_ix0, c27_iy0);
  return c27_b_x;
}

static void c27_c_eml_switch_helper(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c27_b_eml_xswap(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], int32_T c27_ix0, int32_T c27_iy0, real_T c27_b_x[2])
{
  int32_T c27_i53;
  for (c27_i53 = 0; c27_i53 < 2; c27_i53++) {
    c27_b_x[c27_i53] = c27_x[c27_i53];
  }

  c27_d_eml_xswap(chartInstance, c27_b_x, c27_ix0, c27_iy0);
}

static void c27_eml_xgemm(SFc27_hybridSysSimInstanceStruct *chartInstance,
  int32_T c27_k, real_T c27_A, real_T c27_B[2], real_T c27_C[2], real_T c27_b_C
  [2])
{
  int32_T c27_i54;
  int32_T c27_i55;
  real_T c27_b_B[2];
  for (c27_i54 = 0; c27_i54 < 2; c27_i54++) {
    c27_b_C[c27_i54] = c27_C[c27_i54];
  }

  for (c27_i55 = 0; c27_i55 < 2; c27_i55++) {
    c27_b_B[c27_i55] = c27_B[c27_i55];
  }

  c27_b_eml_xgemm(chartInstance, c27_k, c27_A, c27_b_B, c27_b_C);
}

static real_T c27_eml_xdotu(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], real_T c27_y[2])
{
  real_T c27_d;
  int32_T c27_k;
  int32_T c27_b_k;
  c27_d = 0.0;
  c27_eml_switch_helper(chartInstance);
  for (c27_k = 1; c27_k < 3; c27_k++) {
    c27_b_k = c27_k;
    c27_d += c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c27_b_k), 1, 2, 1, 0) - 1] * c27_y[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_k), 1, 2, 1, 0) - 1];
  }

  return c27_d;
}

static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static int32_T c27_d_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i56;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i56, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i56;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static uint8_T c27_e_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_hybridSysSim, const char_T *
  c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_hybridSysSim), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_hybridSysSim);
  return c27_y;
}

static uint8_T c27_f_emlrt_marshallIn(SFc27_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_c_eml_xscal(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T c27_x[2])
{
  real_T c27_b_a;
  real_T c27_c_a;
  int32_T c27_k;
  int32_T c27_b_k;
  c27_b_a = c27_a;
  c27_b_eml_switch_helper(chartInstance);
  c27_c_a = c27_b_a;
  c27_eml_switch_helper(chartInstance);
  for (c27_k = 1; c27_k < 3; c27_k++) {
    c27_b_k = c27_k;
    c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_b_k), 1, 2, 1, 0) - 1] = c27_c_a *
      c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_b_k), 1, 2, 1, 0) - 1];
  }
}

static void c27_b_sqrt(SFc27_hybridSysSimInstanceStruct *chartInstance, real_T
  *c27_x)
{
  if (*c27_x < 0.0) {
    c27_c_eml_error(chartInstance);
  }

  *c27_x = muDoubleScalarSqrt(*c27_x);
}

static void c27_b_eml_xrotg(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T *c27_a, real_T *c27_b, real_T *c27_c, real_T *c27_s)
{
  real_T c27_b_a;
  real_T c27_b_b;
  real_T c27_c_b;
  real_T c27_c_a;
  real_T c27_d_a;
  real_T c27_d_b;
  real_T c27_e_b;
  real_T c27_e_a;
  real_T c27_b_c;
  real_T c27_b_s;
  double * c27_a_t;
  double * c27_b_t;
  double * c27_c_t;
  double * c27_s_t;
  real_T c27_c_c;
  real_T c27_c_s;
  (void)chartInstance;
  c27_b_a = *c27_a;
  c27_b_b = *c27_b;
  c27_c_b = c27_b_b;
  c27_c_a = c27_b_a;
  c27_d_a = c27_c_a;
  c27_d_b = c27_c_b;
  c27_e_b = c27_d_b;
  c27_e_a = c27_d_a;
  c27_b_c = 0.0;
  c27_b_s = 0.0;
  c27_a_t = (double *)(&c27_e_a);
  c27_b_t = (double *)(&c27_e_b);
  c27_c_t = (double *)(&c27_b_c);
  c27_s_t = (double *)(&c27_b_s);
  drotg(c27_a_t, c27_b_t, c27_c_t, c27_s_t);
  c27_c_a = c27_e_a;
  c27_c_b = c27_e_b;
  c27_c_c = c27_b_c;
  c27_c_s = c27_b_s;
  *c27_a = c27_c_a;
  *c27_b = c27_c_b;
  *c27_c = c27_c_c;
  *c27_s = c27_c_s;
}

static void c27_c_eml_xrot(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T *c27_x, int32_T c27_ix0, int32_T c27_iy0, real_T c27_c, real_T c27_s)
{
  real_T c27_b_x;
  int32_T c27_b_ix0;
  int32_T c27_b_iy0;
  real_T c27_b_c;
  real_T c27_b_s;
  real_T c27_c_x;
  real_T c27_d_x;
  int32_T c27_c_ix0;
  int32_T c27_c_iy0;
  real_T c27_c_c;
  real_T c27_c_s;
  real_T c27_e_x;
  int32_T c27_ix;
  int32_T c27_iy;
  real_T c27_temp;
  c27_b_x = *c27_x;
  c27_b_ix0 = c27_ix0;
  c27_b_iy0 = c27_iy0;
  c27_b_c = c27_c;
  c27_b_s = c27_s;
  c27_c_x = c27_b_x;
  c27_b_threshold(chartInstance);
  c27_d_x = c27_c_x;
  c27_c_ix0 = c27_b_ix0;
  c27_c_iy0 = c27_b_iy0;
  c27_c_c = c27_b_c;
  c27_c_s = c27_b_s;
  c27_e_x = c27_d_x;
  c27_ix = c27_c_ix0;
  c27_iy = c27_c_iy0;
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_ix),
    1, 1, 1, 0);
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_iy),
    1, 1, 1, 0);
  c27_temp = c27_c_c * c27_e_x + c27_c_s * c27_e_x;
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_iy),
    1, 1, 1, 0);
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_ix),
    1, 1, 1, 0);
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_iy),
    1, 1, 1, 0);
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_ix),
    1, 1, 1, 0);
  c27_e_x = c27_temp;
  c27_c_x = c27_e_x;
  *c27_x = c27_c_x;
}

static void c27_d_eml_xrot(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], int32_T c27_ix0, int32_T c27_iy0, real_T c27_c, real_T c27_s)
{
  int32_T c27_b_ix0;
  int32_T c27_b_iy0;
  real_T c27_b_c;
  real_T c27_b_s;
  int32_T c27_c_ix0;
  int32_T c27_c_iy0;
  real_T c27_c_c;
  real_T c27_c_s;
  int32_T c27_ix;
  int32_T c27_iy;
  int32_T c27_k;
  real_T c27_temp;
  int32_T c27_a;
  int32_T c27_b_a;
  c27_b_ix0 = c27_ix0;
  c27_b_iy0 = c27_iy0;
  c27_b_c = c27_c;
  c27_b_s = c27_s;
  c27_b_threshold(chartInstance);
  c27_c_ix0 = c27_b_ix0;
  c27_c_iy0 = c27_b_iy0;
  c27_c_c = c27_b_c;
  c27_c_s = c27_b_s;
  c27_ix = c27_c_ix0;
  c27_iy = c27_c_iy0;
  c27_eml_switch_helper(chartInstance);
  for (c27_k = 1; c27_k < 3; c27_k++) {
    c27_temp = c27_c_c * c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c27_ix), 1, 2, 1, 0) - 1] + c27_c_s *
      c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_iy), 1, 2, 1, 0) - 1];
    c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_iy), 1, 2, 1, 0) - 1] = c27_c_c *
      c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_iy), 1, 2, 1, 0) - 1] - c27_c_s *
      c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_ix), 1, 2, 1, 0) - 1];
    c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_ix), 1, 2, 1, 0) - 1] = c27_temp;
    c27_a = c27_iy + 1;
    c27_iy = c27_a;
    c27_b_a = c27_ix + 1;
    c27_ix = c27_b_a;
  }
}

static void c27_d_eml_xscal(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_a, real_T *c27_x, int32_T c27_ix0)
{
  real_T c27_b_a;
  int32_T c27_b_ix0;
  real_T c27_c_a;
  int32_T c27_c_ix0;
  int32_T c27_d_ix0;
  int32_T c27_d_a;
  int32_T c27_i57;
  int32_T c27_e_a;
  int32_T c27_b;
  int32_T c27_f_a;
  int32_T c27_b_b;
  boolean_T c27_overflow;
  int32_T c27_k;
  int32_T c27_b_k;
  c27_b_a = c27_a;
  c27_b_ix0 = c27_ix0;
  c27_b_eml_switch_helper(chartInstance);
  c27_c_a = c27_b_a;
  c27_c_ix0 = c27_b_ix0;
  c27_d_ix0 = c27_c_ix0;
  c27_d_a = c27_c_ix0;
  c27_i57 = c27_d_a;
  c27_e_a = c27_d_ix0;
  c27_b = c27_i57;
  c27_f_a = c27_e_a;
  c27_b_b = c27_b;
  if (c27_f_a > c27_b_b) {
    c27_overflow = false;
  } else {
    c27_eml_switch_helper(chartInstance);
    c27_eml_switch_helper(chartInstance);
    c27_overflow = (c27_b_b > 2147483646);
  }

  if (c27_overflow) {
    c27_check_forloop_overflow_error(chartInstance, c27_overflow);
  }

  for (c27_k = c27_d_ix0; c27_k <= c27_i57; c27_k++) {
    c27_b_k = c27_k;
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c27_b_k), 1, 1, 1, 0);
    _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c27_b_k), 1, 1, 1, 0);
    *c27_x *= c27_c_a;
  }
}

static void c27_c_eml_xswap(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T *c27_x, int32_T c27_ix0, int32_T c27_iy0)
{
  int32_T c27_b_ix0;
  int32_T c27_b_iy0;
  int32_T c27_c_ix0;
  int32_T c27_c_iy0;
  int32_T c27_ix;
  int32_T c27_iy;
  (void)c27_x;
  c27_b_ix0 = c27_ix0;
  c27_b_iy0 = c27_iy0;
  c27_c_eml_switch_helper(chartInstance);
  c27_c_ix0 = c27_b_ix0;
  c27_c_iy0 = c27_b_iy0;
  c27_ix = c27_c_ix0;
  c27_iy = c27_c_iy0;
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_ix),
    1, 1, 1, 0);
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_iy),
    1, 1, 1, 0);
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_ix),
    1, 1, 1, 0);
  _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_iy),
    1, 1, 1, 0);
}

static void c27_d_eml_xswap(SFc27_hybridSysSimInstanceStruct *chartInstance,
  real_T c27_x[2], int32_T c27_ix0, int32_T c27_iy0)
{
  int32_T c27_b_ix0;
  int32_T c27_b_iy0;
  int32_T c27_c_ix0;
  int32_T c27_c_iy0;
  int32_T c27_ix;
  int32_T c27_iy;
  int32_T c27_k;
  real_T c27_temp;
  int32_T c27_a;
  int32_T c27_b_a;
  c27_b_ix0 = c27_ix0;
  c27_b_iy0 = c27_iy0;
  c27_c_eml_switch_helper(chartInstance);
  c27_c_ix0 = c27_b_ix0;
  c27_c_iy0 = c27_b_iy0;
  c27_ix = c27_c_ix0;
  c27_iy = c27_c_iy0;
  c27_eml_switch_helper(chartInstance);
  for (c27_k = 1; c27_k < 3; c27_k++) {
    c27_temp = c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c27_ix), 1, 2, 1, 0) - 1];
    c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_ix), 1, 2, 1, 0) - 1] = c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_iy), 1, 2, 1, 0) - 1];
    c27_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c27_iy), 1, 2, 1, 0) - 1] = c27_temp;
    c27_a = c27_ix + 1;
    c27_ix = c27_a;
    c27_b_a = c27_iy + 1;
    c27_iy = c27_b_a;
  }
}

static void c27_b_eml_xgemm(SFc27_hybridSysSimInstanceStruct *chartInstance,
  int32_T c27_k, real_T c27_A, real_T c27_B[2], real_T c27_C[2])
{
  int32_T c27_b_k;
  real_T c27_b_A;
  int32_T c27_c_k;
  real_T c27_c_A;
  int32_T c27_a;
  int32_T c27_km1;
  int32_T c27_cr;
  int32_T c27_b_cr;
  int32_T c27_b_a;
  int32_T c27_i58;
  int32_T c27_c_a;
  int32_T c27_i59;
  int32_T c27_d_a;
  int32_T c27_b;
  int32_T c27_e_a;
  int32_T c27_b_b;
  boolean_T c27_overflow;
  int32_T c27_ic;
  int32_T c27_b_ic;
  int32_T c27_br;
  int32_T c27_c_cr;
  int32_T c27_ar;
  int32_T c27_f_a;
  int32_T c27_b_br;
  int32_T c27_c_b;
  int32_T c27_c;
  int32_T c27_g_a;
  int32_T c27_d_b;
  int32_T c27_i60;
  int32_T c27_h_a;
  int32_T c27_e_b;
  int32_T c27_i_a;
  int32_T c27_f_b;
  boolean_T c27_b_overflow;
  int32_T c27_ib;
  int32_T c27_b_ib;
  real_T c27_temp;
  int32_T c27_ia;
  int32_T c27_j_a;
  int32_T c27_i61;
  int32_T c27_k_a;
  int32_T c27_i62;
  int32_T c27_l_a;
  int32_T c27_g_b;
  int32_T c27_m_a;
  int32_T c27_h_b;
  boolean_T c27_c_overflow;
  int32_T c27_c_ic;
  int32_T c27_n_a;
  int32_T c27_o_a;
  c27_b_k = c27_k;
  c27_b_A = c27_A;
  if (c27_use_refblas(chartInstance)) {
  } else {
    c27_threshold(chartInstance);
  }

  c27_c_k = c27_b_k;
  c27_c_A = c27_b_A;
  c27_a = c27_c_k;
  c27_km1 = c27_a;
  c27_eml_switch_helper(chartInstance);
  for (c27_cr = 0; c27_cr < 2; c27_cr++) {
    c27_b_cr = c27_cr;
    c27_b_a = c27_b_cr + 1;
    c27_i58 = c27_b_a;
    c27_c_a = c27_b_cr + 1;
    c27_i59 = c27_c_a;
    c27_d_a = c27_i58;
    c27_b = c27_i59;
    c27_e_a = c27_d_a;
    c27_b_b = c27_b;
    if (c27_e_a > c27_b_b) {
      c27_overflow = false;
    } else {
      c27_eml_switch_helper(chartInstance);
      c27_eml_switch_helper(chartInstance);
      c27_overflow = (c27_b_b > 2147483646);
    }

    if (c27_overflow) {
      c27_check_forloop_overflow_error(chartInstance, c27_overflow);
    }

    for (c27_ic = c27_i58; c27_ic <= c27_i59; c27_ic++) {
      c27_b_ic = c27_ic;
      c27_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c27_b_ic), 1, 2, 1, 0) - 1] = 0.0;
    }
  }

  c27_br = 0;
  c27_eml_switch_helper(chartInstance);
  for (c27_c_cr = 0; c27_c_cr < 2; c27_c_cr++) {
    c27_b_cr = c27_c_cr;
    c27_ar = 0;
    c27_f_a = c27_br + 1;
    c27_br = c27_f_a;
    c27_b_br = c27_br;
    c27_c_b = c27_km1 - 1;
    c27_c = c27_c_b << 1;
    c27_g_a = c27_br;
    c27_d_b = c27_c;
    c27_i60 = c27_g_a + c27_d_b;
    c27_h_a = c27_b_br;
    c27_e_b = c27_i60;
    c27_i_a = c27_h_a;
    c27_f_b = c27_e_b;
    if (c27_i_a > c27_f_b) {
      c27_b_overflow = false;
    } else {
      c27_eml_switch_helper(chartInstance);
      c27_eml_switch_helper(chartInstance);
      c27_b_overflow = (c27_f_b > 2147483645);
    }

    if (c27_b_overflow) {
      c27_check_forloop_overflow_error(chartInstance, c27_b_overflow);
    }

    for (c27_ib = c27_b_br; c27_ib <= c27_i60; c27_ib += 2) {
      c27_b_ib = c27_ib;
      if (c27_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_b_ib), 1, 2, 1, 0) - 1] != 0.0) {
        c27_temp = c27_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c27_b_ib), 1, 2, 1, 0) - 1];
        c27_ia = c27_ar;
        c27_j_a = c27_b_cr + 1;
        c27_i61 = c27_j_a;
        c27_k_a = c27_b_cr + 1;
        c27_i62 = c27_k_a;
        c27_l_a = c27_i61;
        c27_g_b = c27_i62;
        c27_m_a = c27_l_a;
        c27_h_b = c27_g_b;
        if (c27_m_a > c27_h_b) {
          c27_c_overflow = false;
        } else {
          c27_eml_switch_helper(chartInstance);
          c27_eml_switch_helper(chartInstance);
          c27_c_overflow = (c27_h_b > 2147483646);
        }

        if (c27_c_overflow) {
          c27_check_forloop_overflow_error(chartInstance, c27_c_overflow);
        }

        for (c27_c_ic = c27_i61; c27_c_ic <= c27_i62; c27_c_ic++) {
          c27_b_ic = c27_c_ic;
          c27_n_a = c27_ia + 1;
          c27_ia = c27_n_a;
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_ia), 1, 1, 1, 0);
          c27_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_b_ic), 1, 2, 1, 0) - 1] =
            c27_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c27_b_ic), 1, 2, 1, 0) - 1] + c27_temp * c27_c_A;
        }
      }

      c27_o_a = c27_ar + 1;
      c27_ar = c27_o_a;
    }
  }
}

static void init_dsm_address_info(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc27_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c27_FcRef = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c27_FcSense = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c27_theta = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c27_fa = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c27_thetaDot = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c27_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(208159789U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2298503072U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3002704806U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3350784845U);
}

mxArray* sf_c27_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c27_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Vwp0RGwjr2uCoRKtNQtmmC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxArray* mxPostCodegenInfo = sf_c27_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c27_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c27_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c27_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c27_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c27_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"fa\",},{M[8],M[0],T\"is_active_c27_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc27_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           27,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"FcRef");
          _SFD_SET_DATA_PROPS(1,1,1,0,"FcSense");
          _SFD_SET_DATA_PROPS(2,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(3,2,0,1,"fa");
          _SFD_SET_DATA_PROPS(4,1,1,0,"thetaDot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,779);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)c27_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c27_FcRef);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c27_FcSense);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c27_theta);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c27_fa);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c27_thetaDot);
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
  return "FYuyQAQvwWuVcIXDL6C7bC";
}

static void sf_opaque_initialize_c27_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc27_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c27_hybridSysSim(void *chartInstanceVar)
{
  enable_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c27_hybridSysSim(void *chartInstanceVar)
{
  disable_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c27_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c27_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c27_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c27_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*)
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
  initSimStructsc27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_hybridSysSim(SimStruct *S)
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
    initialize_params_c27_hybridSysSim((SFc27_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,27,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,27);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,27,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,27,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(589724166U));
  ssSetChecksum1(S,(4287934694U));
  ssSetChecksum2(S,(295318068U));
  ssSetChecksum3(S,(3732880786U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c27_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_hybridSysSim(SimStruct *S)
{
  SFc27_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc27_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc27_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc27_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c27_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c27_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c27_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c27_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c27_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c27_hybridSysSim;
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

void c27_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
