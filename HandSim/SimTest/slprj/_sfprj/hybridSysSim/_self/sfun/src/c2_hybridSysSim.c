/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c2_hybridSysSim.h"
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
static const char * c2_debug_family_names[52] = { "theta", "thetaDot", "fcTN",
  "fcD", "feTN", "feD", "kP", "kD", "dP", "dD", "lP", "lD", "rP", "rD", "aP",
  "aD", "bP", "bD", "mP", "mD", "theta0", "IP", "ID", "K", "D", "Ja", "Jc", "Je",
  "rOtoG", "alpha", "beta", "delta", "M", "C", "springTau", "damperTau",
  "contactTau", "distTau", "actTau", "thetaDotDot", "fcComp", "nargin",
  "nargout", "iInitVal", "iFa", "iFcSense", "iFeDist", "iO", "xDot", "rOtoL",
  "iFcComp", "rOtoLDot" };

static const char * c2_b_debug_family_names[4] = { "nargin", "nargout", "theta",
  "rot" };

/* Function Declarations */
static void initialize_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void enable_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_hybridSysSim
  (SFc2_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_hybridSysSim
  (SFc2_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_b_rOtoLDot, const char_T *c2_identifier, real_T c2_y[2]);
static void c2_b_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_b_rOtoL, const char_T *c2_identifier, real_T c2_y[4]);
static void c2_d_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_b_xDot, const char_T *c2_identifier, real_T c2_y[4]);
static void c2_f_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_g_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static void c2_rotMat(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T
                      c2_theta, real_T c2_rot[4]);
static void c2_eml_scalar_eg(SFc2_hybridSysSimInstanceStruct *chartInstance);
static void c2_eml_xgemm(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T
  c2_A[4], real_T c2_B[2], real_T c2_C[2], real_T c2_b_C[2]);
static void c2_inv(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T c2_x[4],
                   real_T c2_y[4]);
static void c2_inv2x2(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T
                      c2_x[4], real_T c2_y[4]);
static real_T c2_norm(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T
                      c2_x[4]);
static void c2_eml_warning(SFc2_hybridSysSimInstanceStruct *chartInstance);
static void c2_b_eml_warning(SFc2_hybridSysSimInstanceStruct *chartInstance,
  char_T c2_varargin_2[14]);
static void c2_h_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_sprintf, const char_T *c2_identifier, char_T c2_y[14]);
static void c2_i_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, char_T c2_y[14]);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_j_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_k_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_hybridSysSim, const char_T
  *c2_identifier);
static uint8_T c2_l_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_eml_xgemm(SFc2_hybridSysSimInstanceStruct *chartInstance,
  real_T c2_A[4], real_T c2_B[2], real_T c2_C[2]);
static void init_dsm_address_info(SFc2_hybridSysSimInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc2_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_hybridSysSim = 0U;
}

static void initialize_params_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_hybridSysSim
  (SFc2_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_hybridSysSim
  (SFc2_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[2];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[4];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i2;
  real_T c2_c_u[2];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i3;
  real_T c2_d_u[4];
  const mxArray *c2_e_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(5, 1), false);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    c2_u[c2_i0] = (*chartInstance->c2_iFcComp)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    c2_b_u[c2_i1] = (*chartInstance->c2_rOtoL)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 2, 2),
                false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_c_u[c2_i2] = (*chartInstance->c2_rOtoLDot)[c2_i2];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  for (c2_i3 = 0; c2_i3 < 4; c2_i3++) {
    c2_d_u[c2_i3] = (*chartInstance->c2_xDot)[c2_i3];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_hybridSysSim;
  c2_e_u = c2_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[2];
  int32_T c2_i4;
  real_T c2_dv1[4];
  int32_T c2_i5;
  real_T c2_dv2[2];
  int32_T c2_i6;
  real_T c2_dv3[4];
  int32_T c2_i7;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "iFcComp", c2_dv0);
  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    (*chartInstance->c2_iFcComp)[c2_i4] = c2_dv0[c2_i4];
  }

  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                        "rOtoL", c2_dv1);
  for (c2_i5 = 0; c2_i5 < 4; c2_i5++) {
    (*chartInstance->c2_rOtoL)[c2_i5] = c2_dv1[c2_i5];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
                      "rOtoLDot", c2_dv2);
  for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
    (*chartInstance->c2_rOtoLDot)[c2_i6] = c2_dv2[c2_i6];
  }

  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
                        "xDot", c2_dv3);
  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    (*chartInstance->c2_xDot)[c2_i7] = c2_dv3[c2_i7];
  }

  chartInstance->c2_is_active_c2_hybridSysSim = c2_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
     "is_active_c2_hybridSysSim");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_hybridSysSim(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i8 = 0; c2_i8 < 4; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_iInitVal)[c2_i8], 0U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_hybridSysSim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_xDot)[c2_i9], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_iFa, 2U);
  for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_iFcSense)[c2_i10], 3U);
  }

  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_iFeDist)[c2_i11], 4U);
  }

  for (c2_i12 = 0; c2_i12 < 2; c2_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_iO)[c2_i12], 5U);
  }

  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_rOtoL)[c2_i13], 6U);
  }

  for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_iFcComp)[c2_i14], 7U);
  }

  for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_rOtoLDot)[c2_i15], 8U);
  }
}

static void mdl_start_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  int32_T c2_i16;
  real_T c2_b_iInitVal[4];
  real_T c2_b_iFa;
  int32_T c2_i17;
  real_T c2_b_iFcSense[2];
  int32_T c2_i18;
  real_T c2_b_iFeDist[2];
  int32_T c2_i19;
  real_T c2_b_iO[2];
  uint32_T c2_debug_family_var_map[52];
  real_T c2_theta[2];
  real_T c2_thetaDot[2];
  real_T c2_fcTN[2];
  real_T c2_fcD;
  real_T c2_feTN[2];
  real_T c2_feD;
  real_T c2_kP;
  real_T c2_kD;
  real_T c2_dP;
  real_T c2_dD;
  real_T c2_lP;
  real_T c2_lD;
  real_T c2_rP;
  real_T c2_rD;
  real_T c2_aP;
  real_T c2_aD;
  real_T c2_bP;
  real_T c2_bD;
  real_T c2_mP;
  real_T c2_mD;
  real_T c2_theta0[2];
  real_T c2_IP;
  real_T c2_ID;
  real_T c2_K[4];
  real_T c2_D[4];
  real_T c2_Ja[2];
  real_T c2_Jc[4];
  real_T c2_Je[4];
  real_T c2_rOtoG[4];
  real_T c2_alpha;
  real_T c2_beta;
  real_T c2_delta;
  real_T c2_M[4];
  real_T c2_C[4];
  real_T c2_springTau[2];
  real_T c2_damperTau[2];
  real_T c2_contactTau[2];
  real_T c2_distTau[2];
  real_T c2_actTau[2];
  real_T c2_thetaDotDot[2];
  real_T c2_fcComp[2];
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 4.0;
  real_T c2_b_xDot[4];
  real_T c2_b_rOtoL[4];
  real_T c2_b_iFcComp[2];
  real_T c2_b_rOtoLDot[2];
  real_T c2_dv4[4];
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  real_T c2_a[4];
  int32_T c2_i24;
  real_T c2_b[2];
  int32_T c2_i25;
  int32_T c2_i26;
  real_T c2_dv5[2];
  int32_T c2_i27;
  real_T c2_b_a[4];
  int32_T c2_i28;
  real_T c2_b_b[2];
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T c2_c_a[4];
  int32_T c2_i38;
  real_T c2_c_b[2];
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  static real_T c2_d_a[4] = { -0.043, 0.0, 0.0, -0.185 };

  int32_T c2_i42;
  static real_T c2_e_a[4] = { -0.01, 0.0, 0.0, -0.01 };

  int32_T c2_i43;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  real_T c2_y[2];
  int32_T c2_i47;
  real_T c2_f_a[4];
  int32_T c2_i48;
  real_T c2_dv6[2];
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  real_T c2_g_a[4];
  int32_T c2_i52;
  real_T c2_dv7[2];
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  real_T c2_h_a[4];
  int32_T c2_i56;
  real_T c2_dv8[2];
  int32_T c2_i57;
  real_T c2_c_rOtoL[2];
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  real_T c2_i_a[4];
  int32_T c2_i61;
  real_T c2_dv9[2];
  int32_T c2_i62;
  real_T c2_b_rOtoG[2];
  int32_T c2_i63;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  real_T c2_j_a[4];
  int32_T c2_i68;
  real_T c2_d_b[2];
  int32_T c2_i69;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  real_T c2_k_a[4];
  int32_T c2_i74;
  real_T c2_e_b[2];
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  real_T c2_l_a[4];
  int32_T c2_i83;
  real_T c2_f_b[2];
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  real_T c2_m_a[4];
  int32_T c2_i92;
  real_T c2_g_b[2];
  int32_T c2_i93;
  real_T c2_h_b;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  int32_T c2_i98;
  real_T c2_n_a[4];
  int32_T c2_i99;
  real_T c2_i_b[2];
  int32_T c2_i100;
  real_T c2_b_M[4];
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  int32_T c2_i104;
  real_T c2_o_a[4];
  int32_T c2_i105;
  real_T c2_b_y[2];
  int32_T c2_i106;
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i110;
  int32_T c2_i111;
  int32_T c2_i112;
  real_T c2_b_Jc[4];
  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  int32_T c2_i116;
  real_T c2_p_a[4];
  int32_T c2_i117;
  real_T c2_j_b[2];
  int32_T c2_i118;
  real_T c2_b_theta;
  uint32_T c2_b_debug_family_var_map[4];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_rot[4];
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_gb_x;
  int32_T c2_i119;
  int32_T c2_i120;
  int32_T c2_i121;
  int32_T c2_i122;
  real_T c2_q_a[4];
  int32_T c2_i123;
  real_T c2_k_b[2];
  int32_T c2_i124;
  int32_T c2_i125;
  int32_T c2_i126;
  int32_T c2_i127;
  int32_T c2_i128;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_iFa;
  for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
    c2_b_iInitVal[c2_i16] = (*chartInstance->c2_iInitVal)[c2_i16];
  }

  c2_b_iFa = c2_hoistedGlobal;
  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    c2_b_iFcSense[c2_i17] = (*chartInstance->c2_iFcSense)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    c2_b_iFeDist[c2_i18] = (*chartInstance->c2_iFeDist)[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
    c2_b_iO[c2_i19] = (*chartInstance->c2_iO)[c2_i19];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 52U, 52U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_theta, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_thetaDot, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_fcTN, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_fcD, 3U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_feTN, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_feD, 5U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_kP, 6U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_kD, 7U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_dP, 8U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_dD, 9U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_lP, 10U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_lD, 11U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_rP, 12U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_rD, 13U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aP, 14U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_aD, 15U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_bP, 16U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_bD, 17U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_mP, 18U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_mD, 19U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_theta0, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_IP, 21U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_ID, 22U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_K, 23U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_D, 24U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Ja, 25U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Jc, 26U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Je, 27U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_rOtoG, 28U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_alpha, 29U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_beta, 30U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_delta, 31U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_M, 32U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_C, 33U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_springTau, 34U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_damperTau, 35U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_contactTau, 36U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_distTau, 37U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_actTau, 38U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_thetaDotDot, 39U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_fcComp, 40U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 41U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 42U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_iInitVal, 43U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_iFa, 44U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_iFcSense, 45U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_iFeDist, 46U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_iO, 47U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_xDot, 48U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_rOtoL, 49U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_iFcComp, 50U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_rOtoLDot, 51U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_theta[0] = c2_b_iInitVal[0];
  c2_theta[1] = c2_b_iInitVal[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_thetaDot[0] = c2_b_iInitVal[2];
  c2_thetaDot[1] = c2_b_iInitVal[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_rotMat(chartInstance, c2_theta[0] + c2_theta[1], c2_dv4);
  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
    c2_i22 = 0;
    for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
      c2_a[c2_i23 + c2_i20] = c2_dv4[c2_i22 + c2_i21];
      c2_i22 += 2;
    }

    c2_i20 += 2;
  }

  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    c2_b[c2_i24] = c2_b_iFcSense[c2_i24];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
    c2_fcTN[c2_i25] = 0.0;
  }

  for (c2_i26 = 0; c2_i26 < 2; c2_i26++) {
    c2_dv5[c2_i26] = 0.0;
  }

  for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
    c2_b_a[c2_i27] = c2_a[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 2; c2_i28++) {
    c2_b_b[c2_i28] = c2_b[c2_i28];
  }

  c2_b_eml_xgemm(chartInstance, c2_b_a, c2_b_b, c2_dv5);
  for (c2_i29 = 0; c2_i29 < 2; c2_i29++) {
    c2_fcTN[c2_i29] = c2_dv5[c2_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_fcD = c2_fcTN[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_rotMat(chartInstance, c2_theta[0] + c2_theta[1], c2_dv4);
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 2; c2_i31++) {
    c2_i32 = 0;
    for (c2_i33 = 0; c2_i33 < 2; c2_i33++) {
      c2_a[c2_i33 + c2_i30] = c2_dv4[c2_i32 + c2_i31];
      c2_i32 += 2;
    }

    c2_i30 += 2;
  }

  for (c2_i34 = 0; c2_i34 < 2; c2_i34++) {
    c2_b[c2_i34] = c2_b_iFeDist[c2_i34];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i35 = 0; c2_i35 < 2; c2_i35++) {
    c2_feTN[c2_i35] = 0.0;
  }

  for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
    c2_dv5[c2_i36] = 0.0;
  }

  for (c2_i37 = 0; c2_i37 < 4; c2_i37++) {
    c2_c_a[c2_i37] = c2_a[c2_i37];
  }

  for (c2_i38 = 0; c2_i38 < 2; c2_i38++) {
    c2_c_b[c2_i38] = c2_b[c2_i38];
  }

  c2_b_eml_xgemm(chartInstance, c2_c_a, c2_c_b, c2_dv5);
  for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
    c2_feTN[c2_i39] = c2_dv5[c2_i39];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_feD = c2_feTN[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_kP = -0.043;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_kD = -0.185;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_dP = -0.01;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_dD = -0.01;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_lP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
  c2_lD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_rP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_rD = 0.012;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
  c2_aP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  c2_aD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
  c2_bP = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  c2_bD = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  c2_mP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
  c2_mD = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
  for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
    c2_theta0[c2_i40] = 0.31415926535897931 + 0.73303828583761832 * (real_T)
      c2_i40;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
  c2_IP = 6.6666666666666683E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
  c2_ID = 1.6666666666666671E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
  for (c2_i41 = 0; c2_i41 < 4; c2_i41++) {
    c2_K[c2_i41] = c2_d_a[c2_i41];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
  for (c2_i42 = 0; c2_i42 < 4; c2_i42++) {
    c2_D[c2_i42] = c2_e_a[c2_i42];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
  for (c2_i43 = 0; c2_i43 < 2; c2_i43++) {
    c2_Ja[c2_i43] = 0.02 + -0.008 * (real_T)c2_i43;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
  c2_x = c2_theta[1];
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_Jc[0] = c2_aP;
  c2_Jc[2] = 0.0;
  c2_Jc[1] = c2_aD + 0.1 * c2_b_x;
  c2_Jc[3] = c2_aD;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
  c2_c_x = c2_theta[1];
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarCos(c2_d_x);
  c2_Je[0] = c2_bP;
  c2_Je[2] = 0.0;
  c2_Je[1] = c2_bD + 0.1 * c2_d_x;
  c2_Je[3] = c2_bD;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
  for (c2_i44 = 0; c2_i44 < 4; c2_i44++) {
    c2_b_rOtoL[c2_i44] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
  for (c2_i45 = 0; c2_i45 < 4; c2_i45++) {
    c2_rOtoG[c2_i45] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
  c2_rotMat(chartInstance, c2_theta[0], c2_a);
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i46 = 0; c2_i46 < 2; c2_i46++) {
    c2_y[c2_i46] = 0.0;
  }

  for (c2_i47 = 0; c2_i47 < 4; c2_i47++) {
    c2_f_a[c2_i47] = c2_a[c2_i47];
  }

  for (c2_i48 = 0; c2_i48 < 2; c2_i48++) {
    c2_dv6[c2_i48] = 0.1 + -0.1 * (real_T)c2_i48;
  }

  c2_b_eml_xgemm(chartInstance, c2_f_a, c2_dv6, c2_y);
  for (c2_i49 = 0; c2_i49 < 2; c2_i49++) {
    c2_b_rOtoL[c2_i49] = c2_b_iO[c2_i49] + c2_y[c2_i49];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
  c2_rotMat(chartInstance, c2_theta[0], c2_a);
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i50 = 0; c2_i50 < 2; c2_i50++) {
    c2_y[c2_i50] = 0.0;
  }

  for (c2_i51 = 0; c2_i51 < 4; c2_i51++) {
    c2_g_a[c2_i51] = c2_a[c2_i51];
  }

  for (c2_i52 = 0; c2_i52 < 2; c2_i52++) {
    c2_dv7[c2_i52] = 0.05 + -0.05 * (real_T)c2_i52;
  }

  c2_b_eml_xgemm(chartInstance, c2_g_a, c2_dv7, c2_y);
  for (c2_i53 = 0; c2_i53 < 2; c2_i53++) {
    c2_rOtoG[c2_i53] = c2_b_iO[c2_i53] + c2_y[c2_i53];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
  c2_rotMat(chartInstance, c2_theta[0] + c2_theta[1], c2_a);
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i54 = 0; c2_i54 < 2; c2_i54++) {
    c2_y[c2_i54] = 0.0;
  }

  for (c2_i55 = 0; c2_i55 < 4; c2_i55++) {
    c2_h_a[c2_i55] = c2_a[c2_i55];
  }

  for (c2_i56 = 0; c2_i56 < 2; c2_i56++) {
    c2_dv8[c2_i56] = 0.1 + -0.1 * (real_T)c2_i56;
  }

  c2_b_eml_xgemm(chartInstance, c2_h_a, c2_dv8, c2_y);
  for (c2_i57 = 0; c2_i57 < 2; c2_i57++) {
    c2_c_rOtoL[c2_i57] = c2_b_rOtoL[c2_i57] + c2_y[c2_i57];
  }

  for (c2_i58 = 0; c2_i58 < 2; c2_i58++) {
    c2_b_rOtoL[c2_i58 + 2] = c2_c_rOtoL[c2_i58];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
  c2_rotMat(chartInstance, c2_theta[0] + c2_theta[1], c2_a);
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i59 = 0; c2_i59 < 2; c2_i59++) {
    c2_y[c2_i59] = 0.0;
  }

  for (c2_i60 = 0; c2_i60 < 4; c2_i60++) {
    c2_i_a[c2_i60] = c2_a[c2_i60];
  }

  for (c2_i61 = 0; c2_i61 < 2; c2_i61++) {
    c2_dv9[c2_i61] = 0.05 + -0.05 * (real_T)c2_i61;
  }

  c2_b_eml_xgemm(chartInstance, c2_i_a, c2_dv9, c2_y);
  for (c2_i62 = 0; c2_i62 < 2; c2_i62++) {
    c2_b_rOtoG[c2_i62] = c2_rOtoG[c2_i62] + c2_y[c2_i62];
  }

  for (c2_i63 = 0; c2_i63 < 2; c2_i63++) {
    c2_rOtoG[c2_i63 + 2] = c2_b_rOtoG[c2_i63];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 74);
  c2_e_x = c2_theta[0];
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_theta[0] + c2_theta[1];
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSin(c2_h_x);
  c2_i_x = c2_theta[0];
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarCos(c2_j_x);
  c2_k_x = c2_theta[0] + c2_theta[1];
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarCos(c2_l_x);
  c2_b_rOtoLDot[0] = -0.1 * c2_f_x * c2_thetaDot[0] - 0.1 * c2_h_x *
    (c2_thetaDot[0] + c2_thetaDot[1]);
  c2_b_rOtoLDot[1] = -0.1 * c2_j_x * c2_thetaDot[0] - 0.1 * c2_l_x *
    (c2_thetaDot[0] + c2_thetaDot[1]);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 77);
  c2_alpha = 0.0003833333333333334;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
  c2_beta = 0.0001;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
  c2_delta = c2_ID + 5.0000000000000009E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 81);
  c2_m_x = c2_theta[1];
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarCos(c2_n_x);
  c2_o_x = c2_theta[1];
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarCos(c2_p_x);
  c2_q_x = c2_theta[1];
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarCos(c2_r_x);
  c2_M[0] = c2_alpha + 0.0002 * c2_n_x;
  c2_M[2] = c2_delta + 0.0001 * c2_p_x;
  c2_M[1] = c2_delta + 0.0001 * c2_r_x;
  c2_M[3] = c2_delta;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 84);
  c2_s_x = c2_theta[1];
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarSin(c2_t_x);
  c2_u_x = c2_theta[1];
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarSin(c2_v_x);
  c2_w_x = c2_theta[1];
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarSin(c2_x_x);
  c2_C[0] = -0.0001 * c2_t_x * c2_thetaDot[1];
  c2_C[2] = -0.0001 * c2_v_x * (c2_thetaDot[0] + c2_thetaDot[1]);
  c2_C[1] = 0.0001 * c2_x_x * c2_thetaDot[0];
  c2_C[3] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
  for (c2_i64 = 0; c2_i64 < 2; c2_i64++) {
    c2_b[c2_i64] = c2_theta[c2_i64] - c2_theta0[c2_i64];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i65 = 0; c2_i65 < 2; c2_i65++) {
    c2_springTau[c2_i65] = 0.0;
  }

  for (c2_i66 = 0; c2_i66 < 2; c2_i66++) {
    c2_dv5[c2_i66] = 0.0;
  }

  for (c2_i67 = 0; c2_i67 < 4; c2_i67++) {
    c2_j_a[c2_i67] = c2_d_a[c2_i67];
  }

  for (c2_i68 = 0; c2_i68 < 2; c2_i68++) {
    c2_d_b[c2_i68] = c2_b[c2_i68];
  }

  c2_b_eml_xgemm(chartInstance, c2_j_a, c2_d_b, c2_dv5);
  for (c2_i69 = 0; c2_i69 < 2; c2_i69++) {
    c2_springTau[c2_i69] = c2_dv5[c2_i69];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 89);
  for (c2_i70 = 0; c2_i70 < 2; c2_i70++) {
    c2_b[c2_i70] = c2_thetaDot[c2_i70];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i71 = 0; c2_i71 < 2; c2_i71++) {
    c2_damperTau[c2_i71] = 0.0;
  }

  for (c2_i72 = 0; c2_i72 < 2; c2_i72++) {
    c2_dv5[c2_i72] = 0.0;
  }

  for (c2_i73 = 0; c2_i73 < 4; c2_i73++) {
    c2_k_a[c2_i73] = c2_e_a[c2_i73];
  }

  for (c2_i74 = 0; c2_i74 < 2; c2_i74++) {
    c2_e_b[c2_i74] = c2_b[c2_i74];
  }

  c2_b_eml_xgemm(chartInstance, c2_k_a, c2_e_b, c2_dv5);
  for (c2_i75 = 0; c2_i75 < 2; c2_i75++) {
    c2_damperTau[c2_i75] = c2_dv5[c2_i75];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 90);
  c2_i76 = 0;
  for (c2_i77 = 0; c2_i77 < 2; c2_i77++) {
    c2_i78 = 0;
    for (c2_i79 = 0; c2_i79 < 2; c2_i79++) {
      c2_a[c2_i79 + c2_i76] = c2_Jc[c2_i78 + c2_i77];
      c2_i78 += 2;
    }

    c2_i76 += 2;
  }

  c2_b[0] = 0.0;
  c2_b[1] = c2_fcD;
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i80 = 0; c2_i80 < 2; c2_i80++) {
    c2_contactTau[c2_i80] = 0.0;
  }

  for (c2_i81 = 0; c2_i81 < 2; c2_i81++) {
    c2_dv5[c2_i81] = 0.0;
  }

  for (c2_i82 = 0; c2_i82 < 4; c2_i82++) {
    c2_l_a[c2_i82] = c2_a[c2_i82];
  }

  for (c2_i83 = 0; c2_i83 < 2; c2_i83++) {
    c2_f_b[c2_i83] = c2_b[c2_i83];
  }

  c2_b_eml_xgemm(chartInstance, c2_l_a, c2_f_b, c2_dv5);
  for (c2_i84 = 0; c2_i84 < 2; c2_i84++) {
    c2_contactTau[c2_i84] = c2_dv5[c2_i84];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 91);
  c2_i85 = 0;
  for (c2_i86 = 0; c2_i86 < 2; c2_i86++) {
    c2_i87 = 0;
    for (c2_i88 = 0; c2_i88 < 2; c2_i88++) {
      c2_a[c2_i88 + c2_i85] = c2_Je[c2_i87 + c2_i86];
      c2_i87 += 2;
    }

    c2_i85 += 2;
  }

  c2_b[0] = 0.0;
  c2_b[1] = c2_feD;
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i89 = 0; c2_i89 < 2; c2_i89++) {
    c2_distTau[c2_i89] = 0.0;
  }

  for (c2_i90 = 0; c2_i90 < 2; c2_i90++) {
    c2_dv5[c2_i90] = 0.0;
  }

  for (c2_i91 = 0; c2_i91 < 4; c2_i91++) {
    c2_m_a[c2_i91] = c2_a[c2_i91];
  }

  for (c2_i92 = 0; c2_i92 < 2; c2_i92++) {
    c2_g_b[c2_i92] = c2_b[c2_i92];
  }

  c2_b_eml_xgemm(chartInstance, c2_m_a, c2_g_b, c2_dv5);
  for (c2_i93 = 0; c2_i93 < 2; c2_i93++) {
    c2_distTau[c2_i93] = c2_dv5[c2_i93];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 92);
  c2_h_b = c2_b_iFa;
  for (c2_i94 = 0; c2_i94 < 2; c2_i94++) {
    c2_actTau[c2_i94] = (0.02 + -0.008 * (real_T)c2_i94) * c2_h_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
  for (c2_i95 = 0; c2_i95 < 4; c2_i95++) {
    c2_a[c2_i95] = -c2_C[c2_i95];
  }

  for (c2_i96 = 0; c2_i96 < 2; c2_i96++) {
    c2_b[c2_i96] = c2_thetaDot[c2_i96];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i97 = 0; c2_i97 < 2; c2_i97++) {
    c2_y[c2_i97] = 0.0;
  }

  for (c2_i98 = 0; c2_i98 < 4; c2_i98++) {
    c2_n_a[c2_i98] = c2_a[c2_i98];
  }

  for (c2_i99 = 0; c2_i99 < 2; c2_i99++) {
    c2_i_b[c2_i99] = c2_b[c2_i99];
  }

  c2_b_eml_xgemm(chartInstance, c2_n_a, c2_i_b, c2_y);
  for (c2_i100 = 0; c2_i100 < 4; c2_i100++) {
    c2_b_M[c2_i100] = c2_M[c2_i100];
  }

  c2_inv(chartInstance, c2_b_M, c2_a);
  for (c2_i101 = 0; c2_i101 < 2; c2_i101++) {
    c2_y[c2_i101] = ((((c2_y[c2_i101] + c2_springTau[c2_i101]) +
                       c2_damperTau[c2_i101]) + c2_contactTau[c2_i101]) +
                     c2_distTau[c2_i101]) + c2_actTau[c2_i101];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i102 = 0; c2_i102 < 2; c2_i102++) {
    c2_thetaDotDot[c2_i102] = 0.0;
  }

  for (c2_i103 = 0; c2_i103 < 2; c2_i103++) {
    c2_dv5[c2_i103] = 0.0;
  }

  for (c2_i104 = 0; c2_i104 < 4; c2_i104++) {
    c2_o_a[c2_i104] = c2_a[c2_i104];
  }

  for (c2_i105 = 0; c2_i105 < 2; c2_i105++) {
    c2_b_y[c2_i105] = c2_y[c2_i105];
  }

  c2_b_eml_xgemm(chartInstance, c2_o_a, c2_b_y, c2_dv5);
  for (c2_i106 = 0; c2_i106 < 2; c2_i106++) {
    c2_thetaDotDot[c2_i106] = c2_dv5[c2_i106];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 95);
  for (c2_i107 = 0; c2_i107 < 2; c2_i107++) {
    c2_b_xDot[c2_i107] = c2_thetaDot[c2_i107];
  }

  for (c2_i108 = 0; c2_i108 < 2; c2_i108++) {
    c2_b_xDot[c2_i108 + 2] = c2_thetaDotDot[c2_i108];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 98);
  c2_i109 = 0;
  for (c2_i110 = 0; c2_i110 < 2; c2_i110++) {
    c2_i111 = 0;
    for (c2_i112 = 0; c2_i112 < 2; c2_i112++) {
      c2_b_Jc[c2_i112 + c2_i109] = c2_Jc[c2_i111 + c2_i110];
      c2_i111 += 2;
    }

    c2_i109 += 2;
  }

  c2_inv(chartInstance, c2_b_Jc, c2_a);
  for (c2_i113 = 0; c2_i113 < 2; c2_i113++) {
    c2_b[c2_i113] = -(((c2_springTau[c2_i113] + c2_damperTau[c2_i113]) +
                       c2_distTau[c2_i113]) + c2_actTau[c2_i113]);
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i114 = 0; c2_i114 < 2; c2_i114++) {
    c2_fcComp[c2_i114] = 0.0;
  }

  for (c2_i115 = 0; c2_i115 < 2; c2_i115++) {
    c2_dv5[c2_i115] = 0.0;
  }

  for (c2_i116 = 0; c2_i116 < 4; c2_i116++) {
    c2_p_a[c2_i116] = c2_a[c2_i116];
  }

  for (c2_i117 = 0; c2_i117 < 2; c2_i117++) {
    c2_j_b[c2_i117] = c2_b[c2_i117];
  }

  c2_b_eml_xgemm(chartInstance, c2_p_a, c2_j_b, c2_dv5);
  for (c2_i118 = 0; c2_i118 < 2; c2_i118++) {
    c2_fcComp[c2_i118] = c2_dv5[c2_i118];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
  c2_b_theta = c2_theta[0] + c2_theta[1];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c2_b_debug_family_names,
    c2_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 0U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 1U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_theta, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_rot, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 107);
  c2_y_x = c2_b_theta;
  c2_ab_x = c2_y_x;
  c2_ab_x = muDoubleScalarCos(c2_ab_x);
  c2_bb_x = c2_b_theta;
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarSin(c2_cb_x);
  c2_db_x = c2_b_theta;
  c2_eb_x = c2_db_x;
  c2_eb_x = muDoubleScalarSin(c2_eb_x);
  c2_fb_x = c2_b_theta;
  c2_gb_x = c2_fb_x;
  c2_gb_x = muDoubleScalarCos(c2_gb_x);
  c2_rot[0] = c2_ab_x;
  c2_rot[2] = -c2_cb_x;
  c2_rot[1] = c2_eb_x;
  c2_rot[3] = c2_gb_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -107);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i119 = 0; c2_i119 < 4; c2_i119++) {
    c2_a[c2_i119] = -c2_rot[c2_i119];
  }

  c2_b[0] = 0.0;
  c2_b[1] = c2_fcComp[1];
  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i120 = 0; c2_i120 < 2; c2_i120++) {
    c2_b_iFcComp[c2_i120] = 0.0;
  }

  for (c2_i121 = 0; c2_i121 < 2; c2_i121++) {
    c2_dv5[c2_i121] = 0.0;
  }

  for (c2_i122 = 0; c2_i122 < 4; c2_i122++) {
    c2_q_a[c2_i122] = c2_a[c2_i122];
  }

  for (c2_i123 = 0; c2_i123 < 2; c2_i123++) {
    c2_k_b[c2_i123] = c2_b[c2_i123];
  }

  c2_b_eml_xgemm(chartInstance, c2_q_a, c2_k_b, c2_dv5);
  for (c2_i124 = 0; c2_i124 < 2; c2_i124++) {
    c2_b_iFcComp[c2_i124] = c2_dv5[c2_i124];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -101);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i125 = 0; c2_i125 < 4; c2_i125++) {
    (*chartInstance->c2_xDot)[c2_i125] = c2_b_xDot[c2_i125];
  }

  for (c2_i126 = 0; c2_i126 < 4; c2_i126++) {
    (*chartInstance->c2_rOtoL)[c2_i126] = c2_b_rOtoL[c2_i126];
  }

  for (c2_i127 = 0; c2_i127 < 2; c2_i127++) {
    (*chartInstance->c2_iFcComp)[c2_i127] = c2_b_iFcComp[c2_i127];
  }

  for (c2_i128 = 0; c2_i128 < 2; c2_i128++) {
    (*chartInstance->c2_rOtoLDot)[c2_i128] = c2_b_rOtoLDot[c2_i128];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_hybridSysSim(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i129;
  real_T c2_b_inData[2];
  int32_T c2_i130;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i129 = 0; c2_i129 < 2; c2_i129++) {
    c2_b_inData[c2_i129] = (*(real_T (*)[2])c2_inData)[c2_i129];
  }

  for (c2_i130 = 0; c2_i130 < 2; c2_i130++) {
    c2_u[c2_i130] = c2_b_inData[c2_i130];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_b_rOtoLDot, const char_T *c2_identifier, real_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_rOtoLDot), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_rOtoLDot);
}

static void c2_b_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2])
{
  real_T c2_dv10[2];
  int32_T c2_i131;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv10, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i131 = 0; c2_i131 < 2; c2_i131++) {
    c2_y[c2_i131] = c2_dv10[c2_i131];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_rOtoLDot;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i132;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_b_rOtoLDot = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_rOtoLDot), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_rOtoLDot);
  for (c2_i132 = 0; c2_i132 < 2; c2_i132++) {
    (*(real_T (*)[2])c2_outData)[c2_i132] = c2_y[c2_i132];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i133;
  int32_T c2_i134;
  int32_T c2_i135;
  real_T c2_b_inData[4];
  int32_T c2_i136;
  int32_T c2_i137;
  int32_T c2_i138;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i133 = 0;
  for (c2_i134 = 0; c2_i134 < 2; c2_i134++) {
    for (c2_i135 = 0; c2_i135 < 2; c2_i135++) {
      c2_b_inData[c2_i135 + c2_i133] = (*(real_T (*)[4])c2_inData)[c2_i135 +
        c2_i133];
    }

    c2_i133 += 2;
  }

  c2_i136 = 0;
  for (c2_i137 = 0; c2_i137 < 2; c2_i137++) {
    for (c2_i138 = 0; c2_i138 < 2; c2_i138++) {
      c2_u[c2_i138 + c2_i136] = c2_b_inData[c2_i138 + c2_i136];
    }

    c2_i136 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_b_rOtoL, const char_T *c2_identifier, real_T c2_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_rOtoL), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_rOtoL);
}

static void c2_d_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv11[4];
  int32_T c2_i139;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv11, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c2_i139 = 0; c2_i139 < 4; c2_i139++) {
    c2_y[c2_i139] = c2_dv11[c2_i139];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_rOtoL;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i140;
  int32_T c2_i141;
  int32_T c2_i142;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_b_rOtoL = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_rOtoL), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_rOtoL);
  c2_i140 = 0;
  for (c2_i141 = 0; c2_i141 < 2; c2_i141++) {
    for (c2_i142 = 0; c2_i142 < 2; c2_i142++) {
      (*(real_T (*)[4])c2_outData)[c2_i142 + c2_i140] = c2_y[c2_i142 + c2_i140];
    }

    c2_i140 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i143;
  real_T c2_b_inData[4];
  int32_T c2_i144;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i143 = 0; c2_i143 < 4; c2_i143++) {
    c2_b_inData[c2_i143] = (*(real_T (*)[4])c2_inData)[c2_i143];
  }

  for (c2_i144 = 0; c2_i144 < 4; c2_i144++) {
    c2_u[c2_i144] = c2_b_inData[c2_i144];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_b_xDot, const char_T *c2_identifier, real_T c2_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_xDot), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_xDot);
}

static void c2_f_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv12[4];
  int32_T c2_i145;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv12, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i145 = 0; c2_i145 < 4; c2_i145++) {
    c2_y[c2_i145] = c2_dv12[c2_i145];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_xDot;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i146;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_b_xDot = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_xDot), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_xDot);
  for (c2_i146 = 0; c2_i146 < 4; c2_i146++) {
    (*(real_T (*)[4])c2_outData)[c2_i146] = c2_y[c2_i146];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i147;
  real_T c2_b_inData[2];
  int32_T c2_i148;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i147 = 0; c2_i147 < 2; c2_i147++) {
    c2_b_inData[c2_i147] = (*(real_T (*)[2])c2_inData)[c2_i147];
  }

  for (c2_i148 = 0; c2_i148 < 2; c2_i148++) {
    c2_u[c2_i148] = c2_b_inData[c2_i148];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_g_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i149;
  real_T c2_b_inData[2];
  int32_T c2_i150;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i149 = 0; c2_i149 < 2; c2_i149++) {
    c2_b_inData[c2_i149] = (*(real_T (*)[2])c2_inData)[c2_i149];
  }

  for (c2_i150 = 0; c2_i150 < 2; c2_i150++) {
    c2_u[c2_i150] = c2_b_inData[c2_i150];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 58, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  const mxArray *c2_rhs11 = NULL;
  const mxArray *c2_lhs11 = NULL;
  const mxArray *c2_rhs12 = NULL;
  const mxArray *c2_lhs12 = NULL;
  const mxArray *c2_rhs13 = NULL;
  const mxArray *c2_lhs13 = NULL;
  const mxArray *c2_rhs14 = NULL;
  const mxArray *c2_lhs14 = NULL;
  const mxArray *c2_rhs15 = NULL;
  const mxArray *c2_lhs15 = NULL;
  const mxArray *c2_rhs16 = NULL;
  const mxArray *c2_lhs16 = NULL;
  const mxArray *c2_rhs17 = NULL;
  const mxArray *c2_lhs17 = NULL;
  const mxArray *c2_rhs18 = NULL;
  const mxArray *c2_lhs18 = NULL;
  const mxArray *c2_rhs19 = NULL;
  const mxArray *c2_lhs19 = NULL;
  const mxArray *c2_rhs20 = NULL;
  const mxArray *c2_lhs20 = NULL;
  const mxArray *c2_rhs21 = NULL;
  const mxArray *c2_lhs21 = NULL;
  const mxArray *c2_rhs22 = NULL;
  const mxArray *c2_lhs22 = NULL;
  const mxArray *c2_rhs23 = NULL;
  const mxArray *c2_lhs23 = NULL;
  const mxArray *c2_rhs24 = NULL;
  const mxArray *c2_lhs24 = NULL;
  const mxArray *c2_rhs25 = NULL;
  const mxArray *c2_lhs25 = NULL;
  const mxArray *c2_rhs26 = NULL;
  const mxArray *c2_lhs26 = NULL;
  const mxArray *c2_rhs27 = NULL;
  const mxArray *c2_lhs27 = NULL;
  const mxArray *c2_rhs28 = NULL;
  const mxArray *c2_lhs28 = NULL;
  const mxArray *c2_rhs29 = NULL;
  const mxArray *c2_lhs29 = NULL;
  const mxArray *c2_rhs30 = NULL;
  const mxArray *c2_lhs30 = NULL;
  const mxArray *c2_rhs31 = NULL;
  const mxArray *c2_lhs31 = NULL;
  const mxArray *c2_rhs32 = NULL;
  const mxArray *c2_lhs32 = NULL;
  const mxArray *c2_rhs33 = NULL;
  const mxArray *c2_lhs33 = NULL;
  const mxArray *c2_rhs34 = NULL;
  const mxArray *c2_lhs34 = NULL;
  const mxArray *c2_rhs35 = NULL;
  const mxArray *c2_lhs35 = NULL;
  const mxArray *c2_rhs36 = NULL;
  const mxArray *c2_lhs36 = NULL;
  const mxArray *c2_rhs37 = NULL;
  const mxArray *c2_lhs37 = NULL;
  const mxArray *c2_rhs38 = NULL;
  const mxArray *c2_lhs38 = NULL;
  const mxArray *c2_rhs39 = NULL;
  const mxArray *c2_lhs39 = NULL;
  const mxArray *c2_rhs40 = NULL;
  const mxArray *c2_lhs40 = NULL;
  const mxArray *c2_rhs41 = NULL;
  const mxArray *c2_lhs41 = NULL;
  const mxArray *c2_rhs42 = NULL;
  const mxArray *c2_lhs42 = NULL;
  const mxArray *c2_rhs43 = NULL;
  const mxArray *c2_lhs43 = NULL;
  const mxArray *c2_rhs44 = NULL;
  const mxArray *c2_lhs44 = NULL;
  const mxArray *c2_rhs45 = NULL;
  const mxArray *c2_lhs45 = NULL;
  const mxArray *c2_rhs46 = NULL;
  const mxArray *c2_lhs46 = NULL;
  const mxArray *c2_rhs47 = NULL;
  const mxArray *c2_lhs47 = NULL;
  const mxArray *c2_rhs48 = NULL;
  const mxArray *c2_lhs48 = NULL;
  const mxArray *c2_rhs49 = NULL;
  const mxArray *c2_lhs49 = NULL;
  const mxArray *c2_rhs50 = NULL;
  const mxArray *c2_lhs50 = NULL;
  const mxArray *c2_rhs51 = NULL;
  const mxArray *c2_lhs51 = NULL;
  const mxArray *c2_rhs52 = NULL;
  const mxArray *c2_lhs52 = NULL;
  const mxArray *c2_rhs53 = NULL;
  const mxArray *c2_lhs53 = NULL;
  const mxArray *c2_rhs54 = NULL;
  const mxArray *c2_lhs54 = NULL;
  const mxArray *c2_rhs55 = NULL;
  const mxArray *c2_lhs55 = NULL;
  const mxArray *c2_rhs56 = NULL;
  const mxArray *c2_lhs56 = NULL;
  const mxArray *c2_rhs57 = NULL;
  const mxArray *c2_lhs57 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786322U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395292504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786336U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xgemm"), "name", "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c2_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c2_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c2_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c2_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c2_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c2_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c2_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c2_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c2_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c2_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786396U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c2_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c2_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c2_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mpower"), "name", "name", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363677878U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c2_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c2_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331268858U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c2_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("power"), "name", "name", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395292506U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c2_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c2_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c2_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c2_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c2_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363677854U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c2_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c2_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c2_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c2_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("inv"), "name", "name", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1305289200U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c2_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2"), "context",
                  "context", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c2_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xcabs1"),
                  "name", "name", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c2_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("abs"), "name", "name", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c2_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c2_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786312U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c2_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2"), "context",
                  "context", 42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c2_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("norm"), "name", "name", 43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363677868U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c2_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c2_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("abs"), "name", "name", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c2_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isnan"), "name", "name", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c2_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c2_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c2_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c2_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_warning"), "name", "name",
                  50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786402U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c2_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isnan"), "name", "name", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c2_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eps"), "name", "name", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c2_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c2_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_eps"), "name", "name", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c2_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c2_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_flt2str"), "name", "name",
                  56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "resolved",
                  "resolved", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1360246350U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c2_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "name", "name", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1319697568U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c2_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs57), "lhs", "lhs",
                  57);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
  sf_mex_destroy(&c2_rhs11);
  sf_mex_destroy(&c2_lhs11);
  sf_mex_destroy(&c2_rhs12);
  sf_mex_destroy(&c2_lhs12);
  sf_mex_destroy(&c2_rhs13);
  sf_mex_destroy(&c2_lhs13);
  sf_mex_destroy(&c2_rhs14);
  sf_mex_destroy(&c2_lhs14);
  sf_mex_destroy(&c2_rhs15);
  sf_mex_destroy(&c2_lhs15);
  sf_mex_destroy(&c2_rhs16);
  sf_mex_destroy(&c2_lhs16);
  sf_mex_destroy(&c2_rhs17);
  sf_mex_destroy(&c2_lhs17);
  sf_mex_destroy(&c2_rhs18);
  sf_mex_destroy(&c2_lhs18);
  sf_mex_destroy(&c2_rhs19);
  sf_mex_destroy(&c2_lhs19);
  sf_mex_destroy(&c2_rhs20);
  sf_mex_destroy(&c2_lhs20);
  sf_mex_destroy(&c2_rhs21);
  sf_mex_destroy(&c2_lhs21);
  sf_mex_destroy(&c2_rhs22);
  sf_mex_destroy(&c2_lhs22);
  sf_mex_destroy(&c2_rhs23);
  sf_mex_destroy(&c2_lhs23);
  sf_mex_destroy(&c2_rhs24);
  sf_mex_destroy(&c2_lhs24);
  sf_mex_destroy(&c2_rhs25);
  sf_mex_destroy(&c2_lhs25);
  sf_mex_destroy(&c2_rhs26);
  sf_mex_destroy(&c2_lhs26);
  sf_mex_destroy(&c2_rhs27);
  sf_mex_destroy(&c2_lhs27);
  sf_mex_destroy(&c2_rhs28);
  sf_mex_destroy(&c2_lhs28);
  sf_mex_destroy(&c2_rhs29);
  sf_mex_destroy(&c2_lhs29);
  sf_mex_destroy(&c2_rhs30);
  sf_mex_destroy(&c2_lhs30);
  sf_mex_destroy(&c2_rhs31);
  sf_mex_destroy(&c2_lhs31);
  sf_mex_destroy(&c2_rhs32);
  sf_mex_destroy(&c2_lhs32);
  sf_mex_destroy(&c2_rhs33);
  sf_mex_destroy(&c2_lhs33);
  sf_mex_destroy(&c2_rhs34);
  sf_mex_destroy(&c2_lhs34);
  sf_mex_destroy(&c2_rhs35);
  sf_mex_destroy(&c2_lhs35);
  sf_mex_destroy(&c2_rhs36);
  sf_mex_destroy(&c2_lhs36);
  sf_mex_destroy(&c2_rhs37);
  sf_mex_destroy(&c2_lhs37);
  sf_mex_destroy(&c2_rhs38);
  sf_mex_destroy(&c2_lhs38);
  sf_mex_destroy(&c2_rhs39);
  sf_mex_destroy(&c2_lhs39);
  sf_mex_destroy(&c2_rhs40);
  sf_mex_destroy(&c2_lhs40);
  sf_mex_destroy(&c2_rhs41);
  sf_mex_destroy(&c2_lhs41);
  sf_mex_destroy(&c2_rhs42);
  sf_mex_destroy(&c2_lhs42);
  sf_mex_destroy(&c2_rhs43);
  sf_mex_destroy(&c2_lhs43);
  sf_mex_destroy(&c2_rhs44);
  sf_mex_destroy(&c2_lhs44);
  sf_mex_destroy(&c2_rhs45);
  sf_mex_destroy(&c2_lhs45);
  sf_mex_destroy(&c2_rhs46);
  sf_mex_destroy(&c2_lhs46);
  sf_mex_destroy(&c2_rhs47);
  sf_mex_destroy(&c2_lhs47);
  sf_mex_destroy(&c2_rhs48);
  sf_mex_destroy(&c2_lhs48);
  sf_mex_destroy(&c2_rhs49);
  sf_mex_destroy(&c2_lhs49);
  sf_mex_destroy(&c2_rhs50);
  sf_mex_destroy(&c2_lhs50);
  sf_mex_destroy(&c2_rhs51);
  sf_mex_destroy(&c2_lhs51);
  sf_mex_destroy(&c2_rhs52);
  sf_mex_destroy(&c2_lhs52);
  sf_mex_destroy(&c2_rhs53);
  sf_mex_destroy(&c2_lhs53);
  sf_mex_destroy(&c2_rhs54);
  sf_mex_destroy(&c2_lhs54);
  sf_mex_destroy(&c2_rhs55);
  sf_mex_destroy(&c2_lhs55);
  sf_mex_destroy(&c2_rhs56);
  sf_mex_destroy(&c2_lhs56);
  sf_mex_destroy(&c2_rhs57);
  sf_mex_destroy(&c2_lhs57);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static void c2_rotMat(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T
                      c2_theta, real_T c2_rot[4])
{
  uint32_T c2_debug_family_var_map[4];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_rot, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 107);
  c2_x = c2_theta;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_theta;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_e_x = c2_theta;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_theta;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_rot[0] = c2_b_x;
  c2_rot[2] = -c2_d_x;
  c2_rot[1] = c2_f_x;
  c2_rot[3] = c2_h_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -107);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_eml_scalar_eg(SFc2_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_xgemm(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T
  c2_A[4], real_T c2_B[2], real_T c2_C[2], real_T c2_b_C[2])
{
  int32_T c2_i151;
  int32_T c2_i152;
  real_T c2_b_A[4];
  int32_T c2_i153;
  real_T c2_b_B[2];
  for (c2_i151 = 0; c2_i151 < 2; c2_i151++) {
    c2_b_C[c2_i151] = c2_C[c2_i151];
  }

  for (c2_i152 = 0; c2_i152 < 4; c2_i152++) {
    c2_b_A[c2_i152] = c2_A[c2_i152];
  }

  for (c2_i153 = 0; c2_i153 < 2; c2_i153++) {
    c2_b_B[c2_i153] = c2_B[c2_i153];
  }

  c2_b_eml_xgemm(chartInstance, c2_b_A, c2_b_B, c2_b_C);
}

static void c2_inv(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T c2_x[4],
                   real_T c2_y[4])
{
  int32_T c2_i154;
  real_T c2_b_x[4];
  int32_T c2_i155;
  real_T c2_c_x[4];
  real_T c2_n1x;
  int32_T c2_i156;
  real_T c2_b_y[4];
  real_T c2_n1xinv;
  real_T c2_rc;
  real_T c2_d_x;
  boolean_T c2_b;
  real_T c2_e_x;
  int32_T c2_i157;
  static char_T c2_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c2_u[8];
  const mxArray *c2_c_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_f_y = NULL;
  char_T c2_str[14];
  int32_T c2_i158;
  char_T c2_b_str[14];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  for (c2_i154 = 0; c2_i154 < 4; c2_i154++) {
    c2_b_x[c2_i154] = c2_x[c2_i154];
  }

  c2_inv2x2(chartInstance, c2_b_x, c2_y);
  for (c2_i155 = 0; c2_i155 < 4; c2_i155++) {
    c2_c_x[c2_i155] = c2_x[c2_i155];
  }

  c2_n1x = c2_norm(chartInstance, c2_c_x);
  for (c2_i156 = 0; c2_i156 < 4; c2_i156++) {
    c2_b_y[c2_i156] = c2_y[c2_i156];
  }

  c2_n1xinv = c2_norm(chartInstance, c2_b_y);
  c2_rc = 1.0 / (c2_n1x * c2_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c2_n1x == 0.0) {
    guard2 = true;
  } else if (c2_n1xinv == 0.0) {
    guard2 = true;
  } else if (c2_rc == 0.0) {
    guard1 = true;
  } else {
    c2_d_x = c2_rc;
    c2_b = muDoubleScalarIsNaN(c2_d_x);
    guard3 = false;
    if (c2_b) {
      guard3 = true;
    } else {
      if (c2_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c2_e_x = c2_rc;
      for (c2_i157 = 0; c2_i157 < 8; c2_i157++) {
        c2_u[c2_i157] = c2_cv0[c2_i157];
      }

      c2_c_y = NULL;
      sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    false);
      c2_b_u = 14.0;
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c2_c_u = 6.0;
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c2_d_u = c2_e_x;
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      c2_h_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14,
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14,
                          c2_c_y, 14, c2_d_y, 14, c2_e_y), 14, c2_f_y),
                            "sprintf", c2_str);
      for (c2_i158 = 0; c2_i158 < 14; c2_i158++) {
        c2_b_str[c2_i158] = c2_str[c2_i158];
      }

      c2_b_eml_warning(chartInstance, c2_b_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c2_eml_warning(chartInstance);
  }
}

static void c2_inv2x2(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T
                      c2_x[4], real_T c2_y[4])
{
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_b_y;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_c_y;
  real_T c2_d;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_d_y;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_e_y;
  real_T c2_b_d;
  real_T c2_A;
  real_T c2_B;
  real_T c2_n_x;
  real_T c2_f_y;
  real_T c2_o_x;
  real_T c2_g_y;
  real_T c2_p_x;
  real_T c2_h_y;
  real_T c2_r;
  real_T c2_b_B;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_k_y;
  real_T c2_t;
  real_T c2_b_A;
  real_T c2_c_B;
  real_T c2_q_x;
  real_T c2_l_y;
  real_T c2_r_x;
  real_T c2_m_y;
  real_T c2_s_x;
  real_T c2_n_y;
  real_T c2_o_y;
  real_T c2_c_A;
  real_T c2_d_B;
  real_T c2_t_x;
  real_T c2_p_y;
  real_T c2_u_x;
  real_T c2_q_y;
  real_T c2_v_x;
  real_T c2_r_y;
  real_T c2_s_y;
  real_T c2_d_A;
  real_T c2_e_B;
  real_T c2_w_x;
  real_T c2_t_y;
  real_T c2_x_x;
  real_T c2_u_y;
  real_T c2_y_x;
  real_T c2_v_y;
  real_T c2_f_B;
  real_T c2_w_y;
  real_T c2_x_y;
  real_T c2_y_y;
  real_T c2_e_A;
  real_T c2_g_B;
  real_T c2_ab_x;
  real_T c2_ab_y;
  real_T c2_bb_x;
  real_T c2_bb_y;
  real_T c2_cb_x;
  real_T c2_cb_y;
  real_T c2_db_y;
  real_T c2_f_A;
  real_T c2_h_B;
  real_T c2_db_x;
  real_T c2_eb_y;
  real_T c2_eb_x;
  real_T c2_fb_y;
  real_T c2_fb_x;
  real_T c2_gb_y;
  real_T c2_hb_y;
  (void)chartInstance;
  c2_b_x = c2_x[1];
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  c2_e_x = c2_d_x;
  c2_b_y = muDoubleScalarAbs(c2_e_x);
  c2_f_x = 0.0;
  c2_g_x = c2_f_x;
  c2_c_y = muDoubleScalarAbs(c2_g_x);
  c2_d = c2_b_y + c2_c_y;
  c2_h_x = c2_x[0];
  c2_i_x = c2_h_x;
  c2_j_x = c2_i_x;
  c2_k_x = c2_j_x;
  c2_d_y = muDoubleScalarAbs(c2_k_x);
  c2_l_x = 0.0;
  c2_m_x = c2_l_x;
  c2_e_y = muDoubleScalarAbs(c2_m_x);
  c2_b_d = c2_d_y + c2_e_y;
  if (c2_d > c2_b_d) {
    c2_A = c2_x[0];
    c2_B = c2_x[1];
    c2_n_x = c2_A;
    c2_f_y = c2_B;
    c2_o_x = c2_n_x;
    c2_g_y = c2_f_y;
    c2_p_x = c2_o_x;
    c2_h_y = c2_g_y;
    c2_r = c2_p_x / c2_h_y;
    c2_b_B = c2_r * c2_x[3] - c2_x[2];
    c2_i_y = c2_b_B;
    c2_j_y = c2_i_y;
    c2_k_y = c2_j_y;
    c2_t = 1.0 / c2_k_y;
    c2_b_A = c2_x[3];
    c2_c_B = c2_x[1];
    c2_q_x = c2_b_A;
    c2_l_y = c2_c_B;
    c2_r_x = c2_q_x;
    c2_m_y = c2_l_y;
    c2_s_x = c2_r_x;
    c2_n_y = c2_m_y;
    c2_o_y = c2_s_x / c2_n_y;
    c2_y[0] = c2_o_y * c2_t;
    c2_y[1] = -c2_t;
    c2_c_A = -c2_x[2];
    c2_d_B = c2_x[1];
    c2_t_x = c2_c_A;
    c2_p_y = c2_d_B;
    c2_u_x = c2_t_x;
    c2_q_y = c2_p_y;
    c2_v_x = c2_u_x;
    c2_r_y = c2_q_y;
    c2_s_y = c2_v_x / c2_r_y;
    c2_y[2] = c2_s_y * c2_t;
    c2_y[3] = c2_r * c2_t;
  } else {
    c2_d_A = c2_x[1];
    c2_e_B = c2_x[0];
    c2_w_x = c2_d_A;
    c2_t_y = c2_e_B;
    c2_x_x = c2_w_x;
    c2_u_y = c2_t_y;
    c2_y_x = c2_x_x;
    c2_v_y = c2_u_y;
    c2_r = c2_y_x / c2_v_y;
    c2_f_B = c2_x[3] - c2_r * c2_x[2];
    c2_w_y = c2_f_B;
    c2_x_y = c2_w_y;
    c2_y_y = c2_x_y;
    c2_t = 1.0 / c2_y_y;
    c2_e_A = c2_x[3];
    c2_g_B = c2_x[0];
    c2_ab_x = c2_e_A;
    c2_ab_y = c2_g_B;
    c2_bb_x = c2_ab_x;
    c2_bb_y = c2_ab_y;
    c2_cb_x = c2_bb_x;
    c2_cb_y = c2_bb_y;
    c2_db_y = c2_cb_x / c2_cb_y;
    c2_y[0] = c2_db_y * c2_t;
    c2_y[1] = -c2_r * c2_t;
    c2_f_A = -c2_x[2];
    c2_h_B = c2_x[0];
    c2_db_x = c2_f_A;
    c2_eb_y = c2_h_B;
    c2_eb_x = c2_db_x;
    c2_fb_y = c2_eb_y;
    c2_fb_x = c2_eb_x;
    c2_gb_y = c2_fb_y;
    c2_hb_y = c2_fb_x / c2_gb_y;
    c2_y[2] = c2_hb_y * c2_t;
    c2_y[3] = c2_t;
  }
}

static real_T c2_norm(SFc2_hybridSysSimInstanceStruct *chartInstance, real_T
                      c2_x[4])
{
  real_T c2_y;
  int32_T c2_j;
  real_T c2_b_j;
  real_T c2_s;
  int32_T c2_i;
  real_T c2_b_i;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  boolean_T c2_b;
  boolean_T exitg1;
  (void)chartInstance;
  c2_y = 0.0;
  c2_j = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c2_j < 2)) {
    c2_b_j = 1.0 + (real_T)c2_j;
    c2_s = 0.0;
    for (c2_i = 0; c2_i < 2; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_b_x = c2_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c2_b_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", c2_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c2_c_x = c2_b_x;
      c2_b_y = muDoubleScalarAbs(c2_c_x);
      c2_s += c2_b_y;
    }

    c2_d_x = c2_s;
    c2_b = muDoubleScalarIsNaN(c2_d_x);
    if (c2_b) {
      c2_y = rtNaN;
      exitg1 = true;
    } else {
      if (c2_s > c2_y) {
        c2_y = c2_s;
      }

      c2_j++;
    }
  }

  return c2_y;
}

static void c2_eml_warning(SFc2_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c2_i159;
  static char_T c2_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c2_u[27];
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  for (c2_i159 = 0; c2_i159 < 27; c2_i159++) {
    c2_u[c2_i159] = c2_varargin_1[c2_i159];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 27), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_y));
}

static void c2_b_eml_warning(SFc2_hybridSysSimInstanceStruct *chartInstance,
  char_T c2_varargin_2[14])
{
  int32_T c2_i160;
  static char_T c2_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c2_u[33];
  const mxArray *c2_y = NULL;
  int32_T c2_i161;
  char_T c2_b_u[14];
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  for (c2_i160 = 0; c2_i160 < 33; c2_i160++) {
    c2_u[c2_i160] = c2_varargin_1[c2_i160];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 33), false);
  for (c2_i161 = 0; c2_i161 < 14; c2_i161++) {
    c2_b_u[c2_i161] = c2_varargin_2[c2_i161];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_y, 14, c2_b_y));
}

static void c2_h_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_sprintf, const char_T *c2_identifier, char_T c2_y[14])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_sprintf);
}

static void c2_i_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, char_T c2_y[14])
{
  char_T c2_cv1[14];
  int32_T c2_i162;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c2_i162 = 0; c2_i162 < 14; c2_i162++) {
    c2_y[c2_i162] = c2_cv1[c2_i162];
  }

  sf_mex_destroy(&c2_u);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_j_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i163;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i163, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i163;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_hybridSysSim, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_hybridSysSim), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_hybridSysSim);
  return c2_y;
}

static uint8_T c2_l_emlrt_marshallIn(SFc2_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_eml_xgemm(SFc2_hybridSysSimInstanceStruct *chartInstance,
  real_T c2_A[4], real_T c2_B[2], real_T c2_C[2])
{
  int32_T c2_i164;
  int32_T c2_i165;
  int32_T c2_i166;
  (void)chartInstance;
  for (c2_i164 = 0; c2_i164 < 2; c2_i164++) {
    c2_C[c2_i164] = 0.0;
    c2_i165 = 0;
    for (c2_i166 = 0; c2_i166 < 2; c2_i166++) {
      c2_C[c2_i164] += c2_A[c2_i165 + c2_i164] * c2_B[c2_i166];
      c2_i165 += 2;
    }
  }
}

static void init_dsm_address_info(SFc2_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c2_iInitVal = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_xDot = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_iFa = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_iFcSense = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_iFeDist = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_iO = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_rOtoL = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_iFcComp = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_rOtoLDot = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
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

void sf_c2_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(382132536U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3669273393U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1239684278U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1258857515U);
}

mxArray* sf_c2_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c2_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("o7RPMzabfleIu2CGK4JuHE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c2_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[11],T\"iFcComp\",},{M[1],M[10],T\"rOtoL\",},{M[1],M[13],T\"rOtoLDot\",},{M[1],M[5],T\"xDot\",},{M[8],M[0],T\"is_active_c2_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_hybridSysSimInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"iInitVal");
          _SFD_SET_DATA_PROPS(1,2,0,1,"xDot");
          _SFD_SET_DATA_PROPS(2,1,1,0,"iFa");
          _SFD_SET_DATA_PROPS(3,1,1,0,"iFcSense");
          _SFD_SET_DATA_PROPS(4,1,1,0,"iFeDist");
          _SFD_SET_DATA_PROPS(5,1,1,0,"iO");
          _SFD_SET_DATA_PROPS(6,2,0,1,"rOtoL");
          _SFD_SET_DATA_PROPS(7,2,0,1,"iFcComp");
          _SFD_SET_DATA_PROPS(8,2,0,1,"rOtoLDot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",704,-1,3694);
        _SFD_CV_INIT_EML_FCN(0,1,"rotMat",3703,-1,3974);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c2_iInitVal);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c2_xDot);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_iFa);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c2_iFcSense);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c2_iFeDist);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c2_iO);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c2_rOtoL);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c2_iFcComp);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c2_rOtoLDot);
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
  return "DBg0JN7X6l9c0MD6n6pjb";
}

static void sf_opaque_initialize_c2_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_hybridSysSim(void *chartInstanceVar)
{
  enable_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_hybridSysSim(void *chartInstanceVar)
{
  disable_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_hybridSysSim(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c2_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_hybridSysSim(SimStruct *S)
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
    initialize_params_c2_hybridSysSim((SFc2_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1779124548U));
  ssSetChecksum1(S,(1842402209U));
  ssSetChecksum2(S,(2739820592U));
  ssSetChecksum3(S,(3781860540U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_hybridSysSim(SimStruct *S)
{
  SFc2_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc2_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_hybridSysSim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_hybridSysSim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_hybridSysSim;
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

void c2_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
