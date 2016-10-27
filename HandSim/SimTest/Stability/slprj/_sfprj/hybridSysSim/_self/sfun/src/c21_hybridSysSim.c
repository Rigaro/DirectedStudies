/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c21_hybridSysSim.h"
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
static const char * c21_debug_family_names[31] = { "fcTN", "fcD", "kP", "kD",
  "dP", "dD", "lP", "rP", "rD", "aP", "aD", "theta0", "K", "D", "Ja", "Jc",
  "springTau", "damperTau", "contactTau", "actTau", "nargin", "nargout", "theta",
  "Inertia", "iFa", "iFcSense", "Coriolis", "estimatedVelocity",
  "estimatedTheta", "Kp", "estimatedAcceleration" };

static const char * c21_b_debug_family_names[4] = { "nargin", "nargout", "theta",
  "rot" };

/* Function Declarations */
static void initialize_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void c21_update_debugger_state_c21_hybridSysSim
  (SFc21_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_hybridSysSim
  (SFc21_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_st);
static void finalize_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void c21_chartstep_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c21_b_estimatedAcceleration, const char_T *c21_identifier,
  real_T c21_y[2]);
static void c21_b_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[2]);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_c_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static void c21_d_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[4]);
static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_e_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_info_helper(const mxArray **c21_info);
static const mxArray *c21_emlrt_marshallOut(const char * c21_u);
static const mxArray *c21_b_emlrt_marshallOut(const uint32_T c21_u);
static void c21_rotMat(SFc21_hybridSysSimInstanceStruct *chartInstance, real_T
  c21_b_theta, real_T c21_rot[4]);
static void c21_eml_scalar_eg(SFc21_hybridSysSimInstanceStruct *chartInstance);
static void c21_eml_xgemm(SFc21_hybridSysSimInstanceStruct *chartInstance,
  real_T c21_A[4], real_T c21_B[2], real_T c21_C[2], real_T c21_b_C[2]);
static void c21_inv2x2(SFc21_hybridSysSimInstanceStruct *chartInstance, real_T
  c21_x[4], real_T c21_y[4]);
static real_T c21_norm(SFc21_hybridSysSimInstanceStruct *chartInstance, real_T
  c21_x[4]);
static void c21_eml_warning(SFc21_hybridSysSimInstanceStruct *chartInstance);
static void c21_b_eml_warning(SFc21_hybridSysSimInstanceStruct *chartInstance,
  char_T c21_varargin_2[14]);
static void c21_e_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_sprintf, const char_T *c21_identifier,
  char_T c21_y[14]);
static void c21_f_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  char_T c21_y[14]);
static const mxArray *c21_f_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_g_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint8_T c21_h_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_hybridSysSim, const char_T *
  c21_identifier);
static uint8_T c21_i_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_eml_xgemm(SFc21_hybridSysSimInstanceStruct *chartInstance,
  real_T c21_A[4], real_T c21_B[2], real_T c21_C[2]);
static void init_dsm_address_info(SFc21_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc21_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_is_active_c21_hybridSysSim = 0U;
}

static void initialize_params_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c21_update_debugger_state_c21_hybridSysSim
  (SFc21_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c21_hybridSysSim
  (SFc21_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  int32_T c21_i0;
  real_T c21_u[2];
  const mxArray *c21_b_y = NULL;
  uint8_T c21_hoistedGlobal;
  uint8_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellmatrix(2, 1), false);
  for (c21_i0 = 0; c21_i0 < 2; c21_i0++) {
    c21_u[c21_i0] = (*chartInstance->c21_estimatedAcceleration)[c21_i0];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_hoistedGlobal = chartInstance->c21_is_active_c21_hybridSysSim;
  c21_b_u = c21_hoistedGlobal;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  sf_mex_assign(&c21_st, c21_y, false);
  return c21_st;
}

static void set_sim_state_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  real_T c21_dv0[2];
  int32_T c21_i1;
  chartInstance->c21_doneDoubleBufferReInit = true;
  c21_u = sf_mex_dup(c21_st);
  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 0)),
                       "estimatedAcceleration", c21_dv0);
  for (c21_i1 = 0; c21_i1 < 2; c21_i1++) {
    (*chartInstance->c21_estimatedAcceleration)[c21_i1] = c21_dv0[c21_i1];
  }

  chartInstance->c21_is_active_c21_hybridSysSim = c21_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 1)),
     "is_active_c21_hybridSysSim");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_hybridSysSim(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c21_i2;
  int32_T c21_i3;
  int32_T c21_i4;
  int32_T c21_i5;
  int32_T c21_i6;
  int32_T c21_i7;
  int32_T c21_i8;
  int32_T c21_i9;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
  for (c21_i2 = 0; c21_i2 < 2; c21_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_theta)[c21_i2], 0U);
  }

  for (c21_i3 = 0; c21_i3 < 4; c21_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_Inertia)[c21_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c21_iFa, 2U);
  for (c21_i4 = 0; c21_i4 < 2; c21_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_iFcSense)[c21_i4], 3U);
  }

  chartInstance->c21_sfEvent = CALL_EVENT;
  c21_chartstep_c21_hybridSysSim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c21_i5 = 0; c21_i5 < 2; c21_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_estimatedAcceleration)[c21_i5],
                          4U);
  }

  for (c21_i6 = 0; c21_i6 < 4; c21_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_Coriolis)[c21_i6], 5U);
  }

  for (c21_i7 = 0; c21_i7 < 2; c21_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_estimatedVelocity)[c21_i7], 6U);
  }

  for (c21_i8 = 0; c21_i8 < 2; c21_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_estimatedTheta)[c21_i8], 7U);
  }

  for (c21_i9 = 0; c21_i9 < 4; c21_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_Kp)[c21_i9], 8U);
  }
}

static void mdl_start_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c21_chartstep_c21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  real_T c21_hoistedGlobal;
  int32_T c21_i10;
  real_T c21_b_theta[2];
  int32_T c21_i11;
  real_T c21_b_Inertia[4];
  real_T c21_b_iFa;
  int32_T c21_i12;
  real_T c21_b_iFcSense[2];
  int32_T c21_i13;
  real_T c21_b_Coriolis[4];
  int32_T c21_i14;
  real_T c21_b_estimatedVelocity[2];
  int32_T c21_i15;
  real_T c21_b_estimatedTheta[2];
  int32_T c21_i16;
  real_T c21_b_Kp[4];
  uint32_T c21_debug_family_var_map[31];
  real_T c21_fcTN[2];
  real_T c21_fcD;
  real_T c21_kP;
  real_T c21_kD;
  real_T c21_dP;
  real_T c21_dD;
  real_T c21_lP;
  real_T c21_rP;
  real_T c21_rD;
  real_T c21_aP;
  real_T c21_aD;
  real_T c21_theta0[2];
  real_T c21_K[4];
  real_T c21_D[4];
  real_T c21_Ja[2];
  real_T c21_Jc[4];
  real_T c21_springTau[2];
  real_T c21_damperTau[2];
  real_T c21_contactTau[2];
  real_T c21_actTau[2];
  real_T c21_nargin = 8.0;
  real_T c21_nargout = 1.0;
  real_T c21_b_estimatedAcceleration[2];
  real_T c21_x[4];
  int32_T c21_i17;
  int32_T c21_i18;
  int32_T c21_i19;
  int32_T c21_i20;
  real_T c21_a[4];
  int32_T c21_i21;
  real_T c21_b[2];
  int32_T c21_i22;
  int32_T c21_i23;
  real_T c21_y[2];
  int32_T c21_i24;
  real_T c21_b_a[4];
  int32_T c21_i25;
  real_T c21_b_b[2];
  int32_T c21_i26;
  int32_T c21_i27;
  int32_T c21_i28;
  static real_T c21_c_a[4] = { -0.043, 0.0, 0.0, -0.185 };

  int32_T c21_i29;
  static real_T c21_d_a[4] = { -0.01, 0.0, 0.0, -0.01 };

  int32_T c21_i30;
  real_T c21_b_x;
  real_T c21_c_x;
  int32_T c21_i31;
  int32_T c21_i32;
  int32_T c21_i33;
  int32_T c21_i34;
  real_T c21_e_a[4];
  int32_T c21_i35;
  real_T c21_c_b[2];
  int32_T c21_i36;
  int32_T c21_i37;
  int32_T c21_i38;
  int32_T c21_i39;
  int32_T c21_i40;
  real_T c21_f_a[4];
  int32_T c21_i41;
  real_T c21_d_b[2];
  int32_T c21_i42;
  int32_T c21_i43;
  int32_T c21_i44;
  int32_T c21_i45;
  int32_T c21_i46;
  int32_T c21_i47;
  int32_T c21_i48;
  int32_T c21_i49;
  real_T c21_g_a[4];
  int32_T c21_i50;
  real_T c21_e_b[2];
  int32_T c21_i51;
  real_T c21_f_b;
  int32_T c21_i52;
  int32_T c21_i53;
  int32_T c21_i54;
  real_T c21_d_x[4];
  real_T c21_b_y[4];
  int32_T c21_i55;
  real_T c21_e_x[4];
  real_T c21_n1x;
  int32_T c21_i56;
  real_T c21_c_y[4];
  real_T c21_n1xinv;
  real_T c21_rc;
  real_T c21_f_x;
  boolean_T c21_g_b;
  real_T c21_g_x;
  int32_T c21_i57;
  static char_T c21_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c21_u[8];
  const mxArray *c21_d_y = NULL;
  real_T c21_b_u;
  const mxArray *c21_e_y = NULL;
  real_T c21_c_u;
  const mxArray *c21_f_y = NULL;
  real_T c21_d_u;
  const mxArray *c21_g_y = NULL;
  char_T c21_str[14];
  int32_T c21_i58;
  char_T c21_b_str[14];
  int32_T c21_i59;
  int32_T c21_i60;
  int32_T c21_i61;
  real_T c21_h_y[2];
  int32_T c21_i62;
  real_T c21_h_a[4];
  int32_T c21_i63;
  real_T c21_h_b[2];
  int32_T c21_i64;
  int32_T c21_i65;
  int32_T c21_i66;
  int32_T c21_i67;
  real_T c21_i_a[4];
  int32_T c21_i68;
  real_T c21_i_b[2];
  int32_T c21_i69;
  int32_T c21_i70;
  int32_T c21_i71;
  int32_T c21_i72;
  real_T c21_i_y[4];
  int32_T c21_i73;
  real_T c21_j_y[2];
  int32_T c21_i74;
  int32_T c21_i75;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
  c21_hoistedGlobal = *chartInstance->c21_iFa;
  for (c21_i10 = 0; c21_i10 < 2; c21_i10++) {
    c21_b_theta[c21_i10] = (*chartInstance->c21_theta)[c21_i10];
  }

  for (c21_i11 = 0; c21_i11 < 4; c21_i11++) {
    c21_b_Inertia[c21_i11] = (*chartInstance->c21_Inertia)[c21_i11];
  }

  c21_b_iFa = c21_hoistedGlobal;
  for (c21_i12 = 0; c21_i12 < 2; c21_i12++) {
    c21_b_iFcSense[c21_i12] = (*chartInstance->c21_iFcSense)[c21_i12];
  }

  for (c21_i13 = 0; c21_i13 < 4; c21_i13++) {
    c21_b_Coriolis[c21_i13] = (*chartInstance->c21_Coriolis)[c21_i13];
  }

  for (c21_i14 = 0; c21_i14 < 2; c21_i14++) {
    c21_b_estimatedVelocity[c21_i14] = (*chartInstance->c21_estimatedVelocity)
      [c21_i14];
  }

  for (c21_i15 = 0; c21_i15 < 2; c21_i15++) {
    c21_b_estimatedTheta[c21_i15] = (*chartInstance->c21_estimatedTheta)[c21_i15];
  }

  for (c21_i16 = 0; c21_i16 < 4; c21_i16++) {
    c21_b_Kp[c21_i16] = (*chartInstance->c21_Kp)[c21_i16];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 31U, 31U, c21_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_fcTN, 0U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_fcD, 1U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_kP, 2U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_kD, 3U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_dP, 4U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_dD, 5U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_lP, 6U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_rP, 7U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_rD, 8U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_aP, 9U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_aD, 10U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_theta0, 11U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_K, 12U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_D, 13U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_Ja, 14U, c21_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_Jc, 15U, c21_b_sf_marshallOut,
    c21_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_springTau, 16U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_damperTau, 17U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_contactTau, 18U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_actTau, 19U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 20U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 21U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_theta, 22U, c21_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_Inertia, 23U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_b_iFa, 24U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_iFcSense, 25U, c21_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_Coriolis, 26U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_estimatedVelocity, 27U, c21_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_estimatedTheta, 28U, c21_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_Kp, 29U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_b_estimatedAcceleration, 30U,
    c21_sf_marshallOut, c21_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 3);
  c21_rotMat(chartInstance, c21_b_theta[0] + c21_b_theta[1], c21_x);
  c21_i17 = 0;
  for (c21_i18 = 0; c21_i18 < 2; c21_i18++) {
    c21_i19 = 0;
    for (c21_i20 = 0; c21_i20 < 2; c21_i20++) {
      c21_a[c21_i20 + c21_i17] = c21_x[c21_i19 + c21_i18];
      c21_i19 += 2;
    }

    c21_i17 += 2;
  }

  for (c21_i21 = 0; c21_i21 < 2; c21_i21++) {
    c21_b[c21_i21] = c21_b_iFcSense[c21_i21];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i22 = 0; c21_i22 < 2; c21_i22++) {
    c21_fcTN[c21_i22] = 0.0;
  }

  for (c21_i23 = 0; c21_i23 < 2; c21_i23++) {
    c21_y[c21_i23] = 0.0;
  }

  for (c21_i24 = 0; c21_i24 < 4; c21_i24++) {
    c21_b_a[c21_i24] = c21_a[c21_i24];
  }

  for (c21_i25 = 0; c21_i25 < 2; c21_i25++) {
    c21_b_b[c21_i25] = c21_b[c21_i25];
  }

  c21_b_eml_xgemm(chartInstance, c21_b_a, c21_b_b, c21_y);
  for (c21_i26 = 0; c21_i26 < 2; c21_i26++) {
    c21_fcTN[c21_i26] = c21_y[c21_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 4);
  c21_fcD = c21_fcTN[1];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 6);
  c21_kP = -0.043;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 7);
  c21_kD = -0.185;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 8);
  c21_dP = -0.01;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 9);
  c21_dD = -0.01;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 10);
  c21_lP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 11);
  c21_rP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 12);
  c21_rD = 0.012;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 13);
  c21_aP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 14);
  c21_aD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 15);
  for (c21_i27 = 0; c21_i27 < 2; c21_i27++) {
    c21_theta0[c21_i27] = 0.31415926535897931 + 0.73303828583761832 * (real_T)
      c21_i27;
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 17);
  for (c21_i28 = 0; c21_i28 < 4; c21_i28++) {
    c21_K[c21_i28] = c21_c_a[c21_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 19);
  for (c21_i29 = 0; c21_i29 < 4; c21_i29++) {
    c21_D[c21_i29] = c21_d_a[c21_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 21);
  for (c21_i30 = 0; c21_i30 < 2; c21_i30++) {
    c21_Ja[c21_i30] = 0.02 + -0.008 * (real_T)c21_i30;
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 22);
  c21_b_x = c21_b_theta[1];
  c21_c_x = c21_b_x;
  c21_c_x = muDoubleScalarCos(c21_c_x);
  c21_Jc[0] = c21_aP;
  c21_Jc[2] = 0.0;
  c21_Jc[1] = c21_aD + 0.1 * c21_c_x;
  c21_Jc[3] = c21_aD;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 25);
  for (c21_i31 = 0; c21_i31 < 2; c21_i31++) {
    c21_b[c21_i31] = c21_b_theta[c21_i31] - c21_theta0[c21_i31];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i32 = 0; c21_i32 < 2; c21_i32++) {
    c21_springTau[c21_i32] = 0.0;
  }

  for (c21_i33 = 0; c21_i33 < 2; c21_i33++) {
    c21_y[c21_i33] = 0.0;
  }

  for (c21_i34 = 0; c21_i34 < 4; c21_i34++) {
    c21_e_a[c21_i34] = c21_c_a[c21_i34];
  }

  for (c21_i35 = 0; c21_i35 < 2; c21_i35++) {
    c21_c_b[c21_i35] = c21_b[c21_i35];
  }

  c21_b_eml_xgemm(chartInstance, c21_e_a, c21_c_b, c21_y);
  for (c21_i36 = 0; c21_i36 < 2; c21_i36++) {
    c21_springTau[c21_i36] = c21_y[c21_i36];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 26);
  for (c21_i37 = 0; c21_i37 < 2; c21_i37++) {
    c21_b[c21_i37] = c21_b_estimatedVelocity[c21_i37];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i38 = 0; c21_i38 < 2; c21_i38++) {
    c21_damperTau[c21_i38] = 0.0;
  }

  for (c21_i39 = 0; c21_i39 < 2; c21_i39++) {
    c21_y[c21_i39] = 0.0;
  }

  for (c21_i40 = 0; c21_i40 < 4; c21_i40++) {
    c21_f_a[c21_i40] = c21_d_a[c21_i40];
  }

  for (c21_i41 = 0; c21_i41 < 2; c21_i41++) {
    c21_d_b[c21_i41] = c21_b[c21_i41];
  }

  c21_b_eml_xgemm(chartInstance, c21_f_a, c21_d_b, c21_y);
  for (c21_i42 = 0; c21_i42 < 2; c21_i42++) {
    c21_damperTau[c21_i42] = c21_y[c21_i42];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 27);
  c21_i43 = 0;
  for (c21_i44 = 0; c21_i44 < 2; c21_i44++) {
    c21_i45 = 0;
    for (c21_i46 = 0; c21_i46 < 2; c21_i46++) {
      c21_a[c21_i46 + c21_i43] = c21_Jc[c21_i45 + c21_i44];
      c21_i45 += 2;
    }

    c21_i43 += 2;
  }

  c21_b[0] = 0.0;
  c21_b[1] = c21_fcD;
  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i47 = 0; c21_i47 < 2; c21_i47++) {
    c21_contactTau[c21_i47] = 0.0;
  }

  for (c21_i48 = 0; c21_i48 < 2; c21_i48++) {
    c21_y[c21_i48] = 0.0;
  }

  for (c21_i49 = 0; c21_i49 < 4; c21_i49++) {
    c21_g_a[c21_i49] = c21_a[c21_i49];
  }

  for (c21_i50 = 0; c21_i50 < 2; c21_i50++) {
    c21_e_b[c21_i50] = c21_b[c21_i50];
  }

  c21_b_eml_xgemm(chartInstance, c21_g_a, c21_e_b, c21_y);
  for (c21_i51 = 0; c21_i51 < 2; c21_i51++) {
    c21_contactTau[c21_i51] = c21_y[c21_i51];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 28);
  c21_f_b = c21_b_iFa;
  for (c21_i52 = 0; c21_i52 < 2; c21_i52++) {
    c21_actTau[c21_i52] = (0.02 + -0.008 * (real_T)c21_i52) * c21_f_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 29);
  for (c21_i53 = 0; c21_i53 < 4; c21_i53++) {
    c21_x[c21_i53] = c21_b_Inertia[c21_i53];
  }

  for (c21_i54 = 0; c21_i54 < 4; c21_i54++) {
    c21_d_x[c21_i54] = c21_x[c21_i54];
  }

  c21_inv2x2(chartInstance, c21_d_x, c21_b_y);
  for (c21_i55 = 0; c21_i55 < 4; c21_i55++) {
    c21_e_x[c21_i55] = c21_x[c21_i55];
  }

  c21_n1x = c21_norm(chartInstance, c21_e_x);
  for (c21_i56 = 0; c21_i56 < 4; c21_i56++) {
    c21_c_y[c21_i56] = c21_b_y[c21_i56];
  }

  c21_n1xinv = c21_norm(chartInstance, c21_c_y);
  c21_rc = 1.0 / (c21_n1x * c21_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c21_n1x == 0.0) {
    guard2 = true;
  } else if (c21_n1xinv == 0.0) {
    guard2 = true;
  } else if (c21_rc == 0.0) {
    guard1 = true;
  } else {
    c21_f_x = c21_rc;
    c21_g_b = muDoubleScalarIsNaN(c21_f_x);
    guard3 = false;
    if (c21_g_b) {
      guard3 = true;
    } else {
      if (c21_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c21_g_x = c21_rc;
      for (c21_i57 = 0; c21_i57 < 8; c21_i57++) {
        c21_u[c21_i57] = c21_cv0[c21_i57];
      }

      c21_d_y = NULL;
      sf_mex_assign(&c21_d_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    false);
      c21_b_u = 14.0;
      c21_e_y = NULL;
      sf_mex_assign(&c21_e_y, sf_mex_create("y", &c21_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c21_c_u = 6.0;
      c21_f_y = NULL;
      sf_mex_assign(&c21_f_y, sf_mex_create("y", &c21_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c21_d_u = c21_g_x;
      c21_g_y = NULL;
      sf_mex_assign(&c21_g_y, sf_mex_create("y", &c21_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      c21_e_emlrt_marshallIn(chartInstance, sf_mex_call_debug
        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14, sf_mex_call_debug
         (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14, c21_d_y, 14,
          c21_e_y, 14, c21_f_y), 14, c21_g_y), "sprintf", c21_str);
      for (c21_i58 = 0; c21_i58 < 14; c21_i58++) {
        c21_b_str[c21_i58] = c21_str[c21_i58];
      }

      c21_b_eml_warning(chartInstance, c21_b_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c21_eml_warning(chartInstance);
  }

  for (c21_i59 = 0; c21_i59 < 4; c21_i59++) {
    c21_a[c21_i59] = -c21_b_Coriolis[c21_i59];
  }

  for (c21_i60 = 0; c21_i60 < 2; c21_i60++) {
    c21_b[c21_i60] = c21_b_estimatedVelocity[c21_i60];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i61 = 0; c21_i61 < 2; c21_i61++) {
    c21_h_y[c21_i61] = 0.0;
  }

  for (c21_i62 = 0; c21_i62 < 4; c21_i62++) {
    c21_h_a[c21_i62] = c21_a[c21_i62];
  }

  for (c21_i63 = 0; c21_i63 < 2; c21_i63++) {
    c21_h_b[c21_i63] = c21_b[c21_i63];
  }

  c21_b_eml_xgemm(chartInstance, c21_h_a, c21_h_b, c21_h_y);
  for (c21_i64 = 0; c21_i64 < 4; c21_i64++) {
    c21_a[c21_i64] = c21_b_Kp[c21_i64];
  }

  for (c21_i65 = 0; c21_i65 < 2; c21_i65++) {
    c21_b[c21_i65] = c21_b_theta[c21_i65] - c21_b_estimatedTheta[c21_i65];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i66 = 0; c21_i66 < 2; c21_i66++) {
    c21_y[c21_i66] = 0.0;
  }

  for (c21_i67 = 0; c21_i67 < 4; c21_i67++) {
    c21_i_a[c21_i67] = c21_a[c21_i67];
  }

  for (c21_i68 = 0; c21_i68 < 2; c21_i68++) {
    c21_i_b[c21_i68] = c21_b[c21_i68];
  }

  c21_b_eml_xgemm(chartInstance, c21_i_a, c21_i_b, c21_y);
  for (c21_i69 = 0; c21_i69 < 2; c21_i69++) {
    c21_h_y[c21_i69] = ((((c21_h_y[c21_i69] + c21_y[c21_i69]) +
                          c21_springTau[c21_i69]) + c21_damperTau[c21_i69]) +
                        c21_contactTau[c21_i69]) + c21_actTau[c21_i69];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i70 = 0; c21_i70 < 2; c21_i70++) {
    c21_b_estimatedAcceleration[c21_i70] = 0.0;
  }

  for (c21_i71 = 0; c21_i71 < 2; c21_i71++) {
    c21_y[c21_i71] = 0.0;
  }

  for (c21_i72 = 0; c21_i72 < 4; c21_i72++) {
    c21_i_y[c21_i72] = c21_b_y[c21_i72];
  }

  for (c21_i73 = 0; c21_i73 < 2; c21_i73++) {
    c21_j_y[c21_i73] = c21_h_y[c21_i73];
  }

  c21_b_eml_xgemm(chartInstance, c21_i_y, c21_j_y, c21_y);
  for (c21_i74 = 0; c21_i74 < 2; c21_i74++) {
    c21_b_estimatedAcceleration[c21_i74] = c21_y[c21_i74];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -29);
  _SFD_SYMBOL_SCOPE_POP();
  for (c21_i75 = 0; c21_i75 < 2; c21_i75++) {
    (*chartInstance->c21_estimatedAcceleration)[c21_i75] =
      c21_b_estimatedAcceleration[c21_i75];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
}

static void initSimStructsc21_hybridSysSim(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber)
{
  (void)c21_machineNumber;
  (void)c21_chartNumber;
  (void)c21_instanceNumber;
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i76;
  real_T c21_b_inData[2];
  int32_T c21_i77;
  real_T c21_u[2];
  const mxArray *c21_y = NULL;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i76 = 0; c21_i76 < 2; c21_i76++) {
    c21_b_inData[c21_i76] = (*(real_T (*)[2])c21_inData)[c21_i76];
  }

  for (c21_i77 = 0; c21_i77 < 2; c21_i77++) {
    c21_u[c21_i77] = c21_b_inData[c21_i77];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static void c21_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c21_b_estimatedAcceleration, const char_T *c21_identifier,
  real_T c21_y[2])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_estimatedAcceleration),
    &c21_thisId, c21_y);
  sf_mex_destroy(&c21_b_estimatedAcceleration);
}

static void c21_b_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[2])
{
  real_T c21_dv1[2];
  int32_T c21_i78;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c21_i78 = 0; c21_i78 < 2; c21_i78++) {
    c21_y[c21_i78] = c21_dv1[c21_i78];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_estimatedAcceleration;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[2];
  int32_T c21_i79;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_b_estimatedAcceleration = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_estimatedAcceleration),
    &c21_thisId, c21_y);
  sf_mex_destroy(&c21_b_estimatedAcceleration);
  for (c21_i79 = 0; c21_i79 < 2; c21_i79++) {
    (*(real_T (*)[2])c21_outData)[c21_i79] = c21_y[c21_i79];
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i80;
  int32_T c21_i81;
  int32_T c21_i82;
  real_T c21_b_inData[4];
  int32_T c21_i83;
  int32_T c21_i84;
  int32_T c21_i85;
  real_T c21_u[4];
  const mxArray *c21_y = NULL;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_i80 = 0;
  for (c21_i81 = 0; c21_i81 < 2; c21_i81++) {
    for (c21_i82 = 0; c21_i82 < 2; c21_i82++) {
      c21_b_inData[c21_i82 + c21_i80] = (*(real_T (*)[4])c21_inData)[c21_i82 +
        c21_i80];
    }

    c21_i80 += 2;
  }

  c21_i83 = 0;
  for (c21_i84 = 0; c21_i84 < 2; c21_i84++) {
    for (c21_i85 = 0; c21_i85 < 2; c21_i85++) {
      c21_u[c21_i85 + c21_i83] = c21_b_inData[c21_i85 + c21_i83];
    }

    c21_i83 += 2;
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i86;
  real_T c21_b_inData[2];
  int32_T c21_i87;
  real_T c21_u[2];
  const mxArray *c21_y = NULL;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i86 = 0; c21_i86 < 2; c21_i86++) {
    c21_b_inData[c21_i86] = (*(real_T (*)[2])c21_inData)[c21_i86];
  }

  for (c21_i87 = 0; c21_i87 < 2; c21_i87++) {
    c21_u[c21_i87] = c21_b_inData[c21_i87];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  real_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static real_T c21_c_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_y;
  real_T c21_d0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d0, 1, 0, 0U, 0, 0U, 0);
  c21_y = c21_d0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_nargout;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_nargout = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_nargout),
    &c21_thisId);
  sf_mex_destroy(&c21_nargout);
  *(real_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static void c21_d_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[4])
{
  real_T c21_dv2[4];
  int32_T c21_i88;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv2, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c21_i88 = 0; c21_i88 < 4; c21_i88++) {
    c21_y[c21_i88] = c21_dv2[c21_i88];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_Jc;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[4];
  int32_T c21_i89;
  int32_T c21_i90;
  int32_T c21_i91;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_Jc = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_Jc), &c21_thisId, c21_y);
  sf_mex_destroy(&c21_Jc);
  c21_i89 = 0;
  for (c21_i90 = 0; c21_i90 < 2; c21_i90++) {
    for (c21_i91 = 0; c21_i91 < 2; c21_i91++) {
      (*(real_T (*)[4])c21_outData)[c21_i91 + c21_i89] = c21_y[c21_i91 + c21_i89];
    }

    c21_i89 += 2;
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_e_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i92;
  real_T c21_b_inData[2];
  int32_T c21_i93;
  real_T c21_u[2];
  const mxArray *c21_y = NULL;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i92 = 0; c21_i92 < 2; c21_i92++) {
    c21_b_inData[c21_i92] = (*(real_T (*)[2])c21_inData)[c21_i92];
  }

  for (c21_i93 = 0; c21_i93 < 2; c21_i93++) {
    c21_u[c21_i93] = c21_b_inData[c21_i93];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

const mxArray *sf_c21_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  sf_mex_assign(&c21_nameCaptureInfo, sf_mex_createstruct("structure", 2, 46, 1),
                false);
  c21_info_helper(&c21_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c21_nameCaptureInfo);
  return c21_nameCaptureInfo;
}

static void c21_info_helper(const mxArray **c21_info)
{
  const mxArray *c21_rhs0 = NULL;
  const mxArray *c21_lhs0 = NULL;
  const mxArray *c21_rhs1 = NULL;
  const mxArray *c21_lhs1 = NULL;
  const mxArray *c21_rhs2 = NULL;
  const mxArray *c21_lhs2 = NULL;
  const mxArray *c21_rhs3 = NULL;
  const mxArray *c21_lhs3 = NULL;
  const mxArray *c21_rhs4 = NULL;
  const mxArray *c21_lhs4 = NULL;
  const mxArray *c21_rhs5 = NULL;
  const mxArray *c21_lhs5 = NULL;
  const mxArray *c21_rhs6 = NULL;
  const mxArray *c21_lhs6 = NULL;
  const mxArray *c21_rhs7 = NULL;
  const mxArray *c21_lhs7 = NULL;
  const mxArray *c21_rhs8 = NULL;
  const mxArray *c21_lhs8 = NULL;
  const mxArray *c21_rhs9 = NULL;
  const mxArray *c21_lhs9 = NULL;
  const mxArray *c21_rhs10 = NULL;
  const mxArray *c21_lhs10 = NULL;
  const mxArray *c21_rhs11 = NULL;
  const mxArray *c21_lhs11 = NULL;
  const mxArray *c21_rhs12 = NULL;
  const mxArray *c21_lhs12 = NULL;
  const mxArray *c21_rhs13 = NULL;
  const mxArray *c21_lhs13 = NULL;
  const mxArray *c21_rhs14 = NULL;
  const mxArray *c21_lhs14 = NULL;
  const mxArray *c21_rhs15 = NULL;
  const mxArray *c21_lhs15 = NULL;
  const mxArray *c21_rhs16 = NULL;
  const mxArray *c21_lhs16 = NULL;
  const mxArray *c21_rhs17 = NULL;
  const mxArray *c21_lhs17 = NULL;
  const mxArray *c21_rhs18 = NULL;
  const mxArray *c21_lhs18 = NULL;
  const mxArray *c21_rhs19 = NULL;
  const mxArray *c21_lhs19 = NULL;
  const mxArray *c21_rhs20 = NULL;
  const mxArray *c21_lhs20 = NULL;
  const mxArray *c21_rhs21 = NULL;
  const mxArray *c21_lhs21 = NULL;
  const mxArray *c21_rhs22 = NULL;
  const mxArray *c21_lhs22 = NULL;
  const mxArray *c21_rhs23 = NULL;
  const mxArray *c21_lhs23 = NULL;
  const mxArray *c21_rhs24 = NULL;
  const mxArray *c21_lhs24 = NULL;
  const mxArray *c21_rhs25 = NULL;
  const mxArray *c21_lhs25 = NULL;
  const mxArray *c21_rhs26 = NULL;
  const mxArray *c21_lhs26 = NULL;
  const mxArray *c21_rhs27 = NULL;
  const mxArray *c21_lhs27 = NULL;
  const mxArray *c21_rhs28 = NULL;
  const mxArray *c21_lhs28 = NULL;
  const mxArray *c21_rhs29 = NULL;
  const mxArray *c21_lhs29 = NULL;
  const mxArray *c21_rhs30 = NULL;
  const mxArray *c21_lhs30 = NULL;
  const mxArray *c21_rhs31 = NULL;
  const mxArray *c21_lhs31 = NULL;
  const mxArray *c21_rhs32 = NULL;
  const mxArray *c21_lhs32 = NULL;
  const mxArray *c21_rhs33 = NULL;
  const mxArray *c21_lhs33 = NULL;
  const mxArray *c21_rhs34 = NULL;
  const mxArray *c21_lhs34 = NULL;
  const mxArray *c21_rhs35 = NULL;
  const mxArray *c21_lhs35 = NULL;
  const mxArray *c21_rhs36 = NULL;
  const mxArray *c21_lhs36 = NULL;
  const mxArray *c21_rhs37 = NULL;
  const mxArray *c21_lhs37 = NULL;
  const mxArray *c21_rhs38 = NULL;
  const mxArray *c21_lhs38 = NULL;
  const mxArray *c21_rhs39 = NULL;
  const mxArray *c21_lhs39 = NULL;
  const mxArray *c21_rhs40 = NULL;
  const mxArray *c21_lhs40 = NULL;
  const mxArray *c21_rhs41 = NULL;
  const mxArray *c21_lhs41 = NULL;
  const mxArray *c21_rhs42 = NULL;
  const mxArray *c21_lhs42 = NULL;
  const mxArray *c21_rhs43 = NULL;
  const mxArray *c21_lhs43 = NULL;
  const mxArray *c21_rhs44 = NULL;
  const mxArray *c21_lhs44 = NULL;
  const mxArray *c21_rhs45 = NULL;
  const mxArray *c21_lhs45 = NULL;
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c21_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286786322U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c21_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395292504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c21_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286786336U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c21_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c21_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c21_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c21_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c21_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c21_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c21_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c21_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c21_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c21_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c21_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c21_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c21_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c21_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("mrdivide"), "name", "name",
                  17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c21_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c21_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("rdivide"), "name", "name",
                  19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c21_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c21_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286786396U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c21_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_div"), "name", "name",
                  22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c21_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 23);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c21_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 24);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("inv"), "name", "name", 24);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1305289200U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c21_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2"), "context",
                  "context", 25);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  25);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c21_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 26);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c21_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 27);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("abs"), "name", "name", 27);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c21_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c21_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 29);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286786312U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c21_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2"), "context",
                  "context", 30);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("mrdivide"), "name", "name",
                  30);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c21_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 31);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("norm"), "name", "name", 31);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363677868U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c21_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c21_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 33);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("abs"), "name", "name", 33);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c21_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 34);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("isnan"), "name", "name", 34);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c21_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 35);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c21_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 36);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 36);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c21_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 37);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c21_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 38);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_warning"), "name",
                  "name", 38);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286786402U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c21_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 39);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("isnan"), "name", "name", 39);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c21_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 40);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eps"), "name", "name", 40);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c21_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 41);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c21_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_eps"), "name", "name",
                  42);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c21_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 43);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c21_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 44);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_flt2str"), "name",
                  "name", 44);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1360246350U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c21_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "name", "name", 45);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1319697568U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c21_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs45), "lhs", "lhs",
                  45);
  sf_mex_destroy(&c21_rhs0);
  sf_mex_destroy(&c21_lhs0);
  sf_mex_destroy(&c21_rhs1);
  sf_mex_destroy(&c21_lhs1);
  sf_mex_destroy(&c21_rhs2);
  sf_mex_destroy(&c21_lhs2);
  sf_mex_destroy(&c21_rhs3);
  sf_mex_destroy(&c21_lhs3);
  sf_mex_destroy(&c21_rhs4);
  sf_mex_destroy(&c21_lhs4);
  sf_mex_destroy(&c21_rhs5);
  sf_mex_destroy(&c21_lhs5);
  sf_mex_destroy(&c21_rhs6);
  sf_mex_destroy(&c21_lhs6);
  sf_mex_destroy(&c21_rhs7);
  sf_mex_destroy(&c21_lhs7);
  sf_mex_destroy(&c21_rhs8);
  sf_mex_destroy(&c21_lhs8);
  sf_mex_destroy(&c21_rhs9);
  sf_mex_destroy(&c21_lhs9);
  sf_mex_destroy(&c21_rhs10);
  sf_mex_destroy(&c21_lhs10);
  sf_mex_destroy(&c21_rhs11);
  sf_mex_destroy(&c21_lhs11);
  sf_mex_destroy(&c21_rhs12);
  sf_mex_destroy(&c21_lhs12);
  sf_mex_destroy(&c21_rhs13);
  sf_mex_destroy(&c21_lhs13);
  sf_mex_destroy(&c21_rhs14);
  sf_mex_destroy(&c21_lhs14);
  sf_mex_destroy(&c21_rhs15);
  sf_mex_destroy(&c21_lhs15);
  sf_mex_destroy(&c21_rhs16);
  sf_mex_destroy(&c21_lhs16);
  sf_mex_destroy(&c21_rhs17);
  sf_mex_destroy(&c21_lhs17);
  sf_mex_destroy(&c21_rhs18);
  sf_mex_destroy(&c21_lhs18);
  sf_mex_destroy(&c21_rhs19);
  sf_mex_destroy(&c21_lhs19);
  sf_mex_destroy(&c21_rhs20);
  sf_mex_destroy(&c21_lhs20);
  sf_mex_destroy(&c21_rhs21);
  sf_mex_destroy(&c21_lhs21);
  sf_mex_destroy(&c21_rhs22);
  sf_mex_destroy(&c21_lhs22);
  sf_mex_destroy(&c21_rhs23);
  sf_mex_destroy(&c21_lhs23);
  sf_mex_destroy(&c21_rhs24);
  sf_mex_destroy(&c21_lhs24);
  sf_mex_destroy(&c21_rhs25);
  sf_mex_destroy(&c21_lhs25);
  sf_mex_destroy(&c21_rhs26);
  sf_mex_destroy(&c21_lhs26);
  sf_mex_destroy(&c21_rhs27);
  sf_mex_destroy(&c21_lhs27);
  sf_mex_destroy(&c21_rhs28);
  sf_mex_destroy(&c21_lhs28);
  sf_mex_destroy(&c21_rhs29);
  sf_mex_destroy(&c21_lhs29);
  sf_mex_destroy(&c21_rhs30);
  sf_mex_destroy(&c21_lhs30);
  sf_mex_destroy(&c21_rhs31);
  sf_mex_destroy(&c21_lhs31);
  sf_mex_destroy(&c21_rhs32);
  sf_mex_destroy(&c21_lhs32);
  sf_mex_destroy(&c21_rhs33);
  sf_mex_destroy(&c21_lhs33);
  sf_mex_destroy(&c21_rhs34);
  sf_mex_destroy(&c21_lhs34);
  sf_mex_destroy(&c21_rhs35);
  sf_mex_destroy(&c21_lhs35);
  sf_mex_destroy(&c21_rhs36);
  sf_mex_destroy(&c21_lhs36);
  sf_mex_destroy(&c21_rhs37);
  sf_mex_destroy(&c21_lhs37);
  sf_mex_destroy(&c21_rhs38);
  sf_mex_destroy(&c21_lhs38);
  sf_mex_destroy(&c21_rhs39);
  sf_mex_destroy(&c21_lhs39);
  sf_mex_destroy(&c21_rhs40);
  sf_mex_destroy(&c21_lhs40);
  sf_mex_destroy(&c21_rhs41);
  sf_mex_destroy(&c21_lhs41);
  sf_mex_destroy(&c21_rhs42);
  sf_mex_destroy(&c21_lhs42);
  sf_mex_destroy(&c21_rhs43);
  sf_mex_destroy(&c21_lhs43);
  sf_mex_destroy(&c21_rhs44);
  sf_mex_destroy(&c21_lhs44);
  sf_mex_destroy(&c21_rhs45);
  sf_mex_destroy(&c21_lhs45);
}

static const mxArray *c21_emlrt_marshallOut(const char * c21_u)
{
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c21_u)), false);
  return c21_y;
}

static const mxArray *c21_b_emlrt_marshallOut(const uint32_T c21_u)
{
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 7, 0U, 0U, 0U, 0), false);
  return c21_y;
}

static void c21_rotMat(SFc21_hybridSysSimInstanceStruct *chartInstance, real_T
  c21_b_theta, real_T c21_rot[4])
{
  uint32_T c21_debug_family_var_map[4];
  real_T c21_nargin = 1.0;
  real_T c21_nargout = 1.0;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_h_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c21_b_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 0U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 1U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_b_theta, 2U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_rot, 3U, c21_b_sf_marshallOut,
    c21_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 35);
  c21_x = c21_b_theta;
  c21_b_x = c21_x;
  c21_b_x = muDoubleScalarCos(c21_b_x);
  c21_c_x = c21_b_theta;
  c21_d_x = c21_c_x;
  c21_d_x = muDoubleScalarSin(c21_d_x);
  c21_e_x = c21_b_theta;
  c21_f_x = c21_e_x;
  c21_f_x = muDoubleScalarSin(c21_f_x);
  c21_g_x = c21_b_theta;
  c21_h_x = c21_g_x;
  c21_h_x = muDoubleScalarCos(c21_h_x);
  c21_rot[0] = c21_b_x;
  c21_rot[2] = -c21_d_x;
  c21_rot[1] = c21_f_x;
  c21_rot[3] = c21_h_x;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c21_eml_scalar_eg(SFc21_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c21_eml_xgemm(SFc21_hybridSysSimInstanceStruct *chartInstance,
  real_T c21_A[4], real_T c21_B[2], real_T c21_C[2], real_T c21_b_C[2])
{
  int32_T c21_i94;
  int32_T c21_i95;
  real_T c21_b_A[4];
  int32_T c21_i96;
  real_T c21_b_B[2];
  for (c21_i94 = 0; c21_i94 < 2; c21_i94++) {
    c21_b_C[c21_i94] = c21_C[c21_i94];
  }

  for (c21_i95 = 0; c21_i95 < 4; c21_i95++) {
    c21_b_A[c21_i95] = c21_A[c21_i95];
  }

  for (c21_i96 = 0; c21_i96 < 2; c21_i96++) {
    c21_b_B[c21_i96] = c21_B[c21_i96];
  }

  c21_b_eml_xgemm(chartInstance, c21_b_A, c21_b_B, c21_b_C);
}

static void c21_inv2x2(SFc21_hybridSysSimInstanceStruct *chartInstance, real_T
  c21_x[4], real_T c21_y[4])
{
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_b_y;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_c_y;
  real_T c21_d;
  real_T c21_h_x;
  real_T c21_i_x;
  real_T c21_j_x;
  real_T c21_k_x;
  real_T c21_d_y;
  real_T c21_l_x;
  real_T c21_m_x;
  real_T c21_e_y;
  real_T c21_b_d;
  real_T c21_A;
  real_T c21_B;
  real_T c21_n_x;
  real_T c21_f_y;
  real_T c21_o_x;
  real_T c21_g_y;
  real_T c21_p_x;
  real_T c21_h_y;
  real_T c21_r;
  real_T c21_b_B;
  real_T c21_i_y;
  real_T c21_j_y;
  real_T c21_k_y;
  real_T c21_t;
  real_T c21_b_A;
  real_T c21_c_B;
  real_T c21_q_x;
  real_T c21_l_y;
  real_T c21_r_x;
  real_T c21_m_y;
  real_T c21_s_x;
  real_T c21_n_y;
  real_T c21_o_y;
  real_T c21_c_A;
  real_T c21_d_B;
  real_T c21_t_x;
  real_T c21_p_y;
  real_T c21_u_x;
  real_T c21_q_y;
  real_T c21_v_x;
  real_T c21_r_y;
  real_T c21_s_y;
  real_T c21_d_A;
  real_T c21_e_B;
  real_T c21_w_x;
  real_T c21_t_y;
  real_T c21_x_x;
  real_T c21_u_y;
  real_T c21_y_x;
  real_T c21_v_y;
  real_T c21_f_B;
  real_T c21_w_y;
  real_T c21_x_y;
  real_T c21_y_y;
  real_T c21_e_A;
  real_T c21_g_B;
  real_T c21_ab_x;
  real_T c21_ab_y;
  real_T c21_bb_x;
  real_T c21_bb_y;
  real_T c21_cb_x;
  real_T c21_cb_y;
  real_T c21_db_y;
  real_T c21_f_A;
  real_T c21_h_B;
  real_T c21_db_x;
  real_T c21_eb_y;
  real_T c21_eb_x;
  real_T c21_fb_y;
  real_T c21_fb_x;
  real_T c21_gb_y;
  real_T c21_hb_y;
  (void)chartInstance;
  c21_b_x = c21_x[1];
  c21_c_x = c21_b_x;
  c21_d_x = c21_c_x;
  c21_e_x = c21_d_x;
  c21_b_y = muDoubleScalarAbs(c21_e_x);
  c21_f_x = 0.0;
  c21_g_x = c21_f_x;
  c21_c_y = muDoubleScalarAbs(c21_g_x);
  c21_d = c21_b_y + c21_c_y;
  c21_h_x = c21_x[0];
  c21_i_x = c21_h_x;
  c21_j_x = c21_i_x;
  c21_k_x = c21_j_x;
  c21_d_y = muDoubleScalarAbs(c21_k_x);
  c21_l_x = 0.0;
  c21_m_x = c21_l_x;
  c21_e_y = muDoubleScalarAbs(c21_m_x);
  c21_b_d = c21_d_y + c21_e_y;
  if (c21_d > c21_b_d) {
    c21_A = c21_x[0];
    c21_B = c21_x[1];
    c21_n_x = c21_A;
    c21_f_y = c21_B;
    c21_o_x = c21_n_x;
    c21_g_y = c21_f_y;
    c21_p_x = c21_o_x;
    c21_h_y = c21_g_y;
    c21_r = c21_p_x / c21_h_y;
    c21_b_B = c21_r * c21_x[3] - c21_x[2];
    c21_i_y = c21_b_B;
    c21_j_y = c21_i_y;
    c21_k_y = c21_j_y;
    c21_t = 1.0 / c21_k_y;
    c21_b_A = c21_x[3];
    c21_c_B = c21_x[1];
    c21_q_x = c21_b_A;
    c21_l_y = c21_c_B;
    c21_r_x = c21_q_x;
    c21_m_y = c21_l_y;
    c21_s_x = c21_r_x;
    c21_n_y = c21_m_y;
    c21_o_y = c21_s_x / c21_n_y;
    c21_y[0] = c21_o_y * c21_t;
    c21_y[1] = -c21_t;
    c21_c_A = -c21_x[2];
    c21_d_B = c21_x[1];
    c21_t_x = c21_c_A;
    c21_p_y = c21_d_B;
    c21_u_x = c21_t_x;
    c21_q_y = c21_p_y;
    c21_v_x = c21_u_x;
    c21_r_y = c21_q_y;
    c21_s_y = c21_v_x / c21_r_y;
    c21_y[2] = c21_s_y * c21_t;
    c21_y[3] = c21_r * c21_t;
  } else {
    c21_d_A = c21_x[1];
    c21_e_B = c21_x[0];
    c21_w_x = c21_d_A;
    c21_t_y = c21_e_B;
    c21_x_x = c21_w_x;
    c21_u_y = c21_t_y;
    c21_y_x = c21_x_x;
    c21_v_y = c21_u_y;
    c21_r = c21_y_x / c21_v_y;
    c21_f_B = c21_x[3] - c21_r * c21_x[2];
    c21_w_y = c21_f_B;
    c21_x_y = c21_w_y;
    c21_y_y = c21_x_y;
    c21_t = 1.0 / c21_y_y;
    c21_e_A = c21_x[3];
    c21_g_B = c21_x[0];
    c21_ab_x = c21_e_A;
    c21_ab_y = c21_g_B;
    c21_bb_x = c21_ab_x;
    c21_bb_y = c21_ab_y;
    c21_cb_x = c21_bb_x;
    c21_cb_y = c21_bb_y;
    c21_db_y = c21_cb_x / c21_cb_y;
    c21_y[0] = c21_db_y * c21_t;
    c21_y[1] = -c21_r * c21_t;
    c21_f_A = -c21_x[2];
    c21_h_B = c21_x[0];
    c21_db_x = c21_f_A;
    c21_eb_y = c21_h_B;
    c21_eb_x = c21_db_x;
    c21_fb_y = c21_eb_y;
    c21_fb_x = c21_eb_x;
    c21_gb_y = c21_fb_y;
    c21_hb_y = c21_fb_x / c21_gb_y;
    c21_y[2] = c21_hb_y * c21_t;
    c21_y[3] = c21_t;
  }
}

static real_T c21_norm(SFc21_hybridSysSimInstanceStruct *chartInstance, real_T
  c21_x[4])
{
  real_T c21_y;
  int32_T c21_j;
  real_T c21_b_j;
  real_T c21_s;
  int32_T c21_i;
  real_T c21_b_i;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_b_y;
  real_T c21_d_x;
  boolean_T c21_b;
  boolean_T exitg1;
  (void)chartInstance;
  c21_y = 0.0;
  c21_j = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c21_j < 2)) {
    c21_b_j = 1.0 + (real_T)c21_j;
    c21_s = 0.0;
    for (c21_i = 0; c21_i < 2; c21_i++) {
      c21_b_i = 1.0 + (real_T)c21_i;
      c21_b_x = c21_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c21_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c21_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c21_c_x = c21_b_x;
      c21_b_y = muDoubleScalarAbs(c21_c_x);
      c21_s += c21_b_y;
    }

    c21_d_x = c21_s;
    c21_b = muDoubleScalarIsNaN(c21_d_x);
    if (c21_b) {
      c21_y = rtNaN;
      exitg1 = true;
    } else {
      if (c21_s > c21_y) {
        c21_y = c21_s;
      }

      c21_j++;
    }
  }

  return c21_y;
}

static void c21_eml_warning(SFc21_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c21_i97;
  static char_T c21_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c21_u[27];
  const mxArray *c21_y = NULL;
  (void)chartInstance;
  for (c21_i97 = 0; c21_i97 < 27; c21_i97++) {
    c21_u[c21_i97] = c21_varargin_1[c21_i97];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c21_y));
}

static void c21_b_eml_warning(SFc21_hybridSysSimInstanceStruct *chartInstance,
  char_T c21_varargin_2[14])
{
  int32_T c21_i98;
  static char_T c21_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c21_u[33];
  const mxArray *c21_y = NULL;
  int32_T c21_i99;
  char_T c21_b_u[14];
  const mxArray *c21_b_y = NULL;
  (void)chartInstance;
  for (c21_i98 = 0; c21_i98 < 33; c21_i98++) {
    c21_u[c21_i98] = c21_varargin_1[c21_i98];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  for (c21_i99 = 0; c21_i99 < 14; c21_i99++) {
    c21_b_u[c21_i99] = c21_varargin_2[c21_i99];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c21_y, 14, c21_b_y));
}

static void c21_e_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_sprintf, const char_T *c21_identifier,
  char_T c21_y[14])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_sprintf), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_sprintf);
}

static void c21_f_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  char_T c21_y[14])
{
  char_T c21_cv1[14];
  int32_T c21_i100;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c21_i100 = 0; c21_i100 < 14; c21_i100++) {
    c21_y[c21_i100] = c21_cv1[c21_i100];
  }

  sf_mex_destroy(&c21_u);
}

static const mxArray *c21_f_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static int32_T c21_g_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_y;
  int32_T c21_i101;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i101, 1, 6, 0U, 0, 0U, 0);
  c21_y = c21_i101;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y;
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c21_b_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_b_sfEvent);
  *(int32_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint8_T c21_h_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_hybridSysSim, const char_T *
  c21_identifier)
{
  uint8_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_is_active_c21_hybridSysSim), &c21_thisId);
  sf_mex_destroy(&c21_b_is_active_c21_hybridSysSim);
  return c21_y;
}

static uint8_T c21_i_emlrt_marshallIn(SFc21_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_b_eml_xgemm(SFc21_hybridSysSimInstanceStruct *chartInstance,
  real_T c21_A[4], real_T c21_B[2], real_T c21_C[2])
{
  int32_T c21_i102;
  int32_T c21_i103;
  int32_T c21_i104;
  (void)chartInstance;
  for (c21_i102 = 0; c21_i102 < 2; c21_i102++) {
    c21_C[c21_i102] = 0.0;
    c21_i103 = 0;
    for (c21_i104 = 0; c21_i104 < 2; c21_i104++) {
      c21_C[c21_i102] += c21_A[c21_i103 + c21_i102] * c21_B[c21_i104];
      c21_i103 += 2;
    }
  }
}

static void init_dsm_address_info(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc21_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c21_theta = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c21_Inertia = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c21_iFa = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c21_iFcSense = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c21_estimatedAcceleration = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c21_Coriolis = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c21_estimatedVelocity = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c21_estimatedTheta = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 6);
  chartInstance->c21_Kp = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
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

void sf_c21_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3002589177U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(647477299U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2346276022U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(672264178U);
}

mxArray* sf_c21_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c21_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("b1D6od9Mp8FwheU31CnRg");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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
      pr[1] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
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
    mxArray* mxPostCodegenInfo = sf_c21_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c21_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c21_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c21_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c21_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c21_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"estimatedAcceleration\",},{M[8],M[0],T\"is_active_c21_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc21_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           21,
           1,
           1,
           0,
           9,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"Inertia");
          _SFD_SET_DATA_PROPS(2,1,1,0,"iFa");
          _SFD_SET_DATA_PROPS(3,1,1,0,"iFcSense");
          _SFD_SET_DATA_PROPS(4,2,0,1,"estimatedAcceleration");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Coriolis");
          _SFD_SET_DATA_PROPS(6,1,1,0,"estimatedVelocity");
          _SFD_SET_DATA_PROPS(7,1,1,0,"estimatedTheta");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Kp");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,844);
        _SFD_CV_INIT_EML_FCN(0,1,"rotMat",853,-1,1124);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)
            c21_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c21_theta);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c21_Inertia);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c21_iFa);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c21_iFcSense);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c21_estimatedAcceleration);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c21_Coriolis);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c21_estimatedVelocity);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c21_estimatedTheta);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c21_Kp);
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
  return "cgAVEatbJpTuHUXea2WbjF";
}

static void sf_opaque_initialize_c21_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc21_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c21_hybridSysSim(void *chartInstanceVar)
{
  enable_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c21_hybridSysSim(void *chartInstanceVar)
{
  disable_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c21_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c21_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c21_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c21_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*)
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
  initSimStructsc21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_hybridSysSim(SimStruct *S)
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
    initialize_params_c21_hybridSysSim((SFc21_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,21,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,21);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(269029214U));
  ssSetChecksum1(S,(1003813929U));
  ssSetChecksum2(S,(707278642U));
  ssSetChecksum3(S,(556308661U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c21_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_hybridSysSim(SimStruct *S)
{
  SFc21_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc21_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc21_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c21_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c21_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c21_hybridSysSim;
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

void c21_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
