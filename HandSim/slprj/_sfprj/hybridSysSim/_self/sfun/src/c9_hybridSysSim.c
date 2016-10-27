/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c9_hybridSysSim.h"
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
static const char * c9_debug_family_names[5] = { "nargin", "nargout", "o",
  "rOtoL", "figNum" };

/* Function Declarations */
static void initialize_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance);
static void enable_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_hybridSysSim
  (SFc9_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_hybridSysSim
  (SFc9_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c9_st);
static void finalize_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_b_emlrt_marshallIn(SFc9_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_c_emlrt_marshallIn(SFc9_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_hybridSysSim, const char_T
  *c9_identifier);
static uint8_T c9_d_emlrt_marshallIn(SFc9_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_hybridSysSimInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc9_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_hybridSysSim = 0U;
}

static void initialize_params_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_hybridSysSim
  (SFc9_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_hybridSysSim
  (SFc9_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_u;
  const mxArray *c9_b_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(1, 1), false);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_hybridSysSim;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  chartInstance->c9_is_active_c9_hybridSysSim = c9_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
     "is_active_c9_hybridSysSim");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_hybridSysSim(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c9_i0;
  int32_T c9_i1;
  real_T c9_hoistedGlobal;
  int32_T c9_i2;
  real_T c9_b_o[2];
  int32_T c9_i3;
  real_T c9_b_rOtoL[4];
  real_T c9_b_figNum;
  uint32_T c9_debug_family_var_map[5];
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 0.0;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  int32_T c9_i4;
  static char_T c9_cv0[2] = { 'o', 'n' };

  char_T c9_b_u[2];
  const mxArray *c9_b_y = NULL;
  real_T c9_c_u[2];
  const mxArray *c9_c_y = NULL;
  real_T c9_d_u[2];
  const mxArray *c9_d_y = NULL;
  int32_T c9_i5;
  static char_T c9_cv1[9] = { 'L', 'i', 'n', 'e', 'W', 'i', 'd', 't', 'h' };

  char_T c9_e_u[9];
  const mxArray *c9_e_y = NULL;
  real_T c9_f_u;
  const mxArray *c9_f_y = NULL;
  int32_T c9_i6;
  static char_T c9_cv2[5] = { 'C', 'o', 'l', 'o', 'r' };

  char_T c9_g_u[5];
  const mxArray *c9_g_y = NULL;
  char_T c9_h_u;
  const mxArray *c9_h_y = NULL;
  real_T c9_i_u;
  const mxArray *c9_i_y = NULL;
  real_T c9_j_u;
  const mxArray *c9_j_y = NULL;
  int32_T c9_i7;
  static char_T c9_cv3[2] = { 'k', 'o' };

  char_T c9_k_u[2];
  const mxArray *c9_k_y = NULL;
  int32_T c9_i8;
  static char_T c9_cv4[10] = { 'M', 'a', 'r', 'k', 'e', 'r', 'S', 'i', 'z', 'e'
  };

  char_T c9_l_u[10];
  const mxArray *c9_l_y = NULL;
  real_T c9_m_u;
  const mxArray *c9_m_y = NULL;
  real_T c9_n_u[2];
  const mxArray *c9_n_y = NULL;
  real_T c9_o_u[2];
  const mxArray *c9_o_y = NULL;
  int32_T c9_i9;
  char_T c9_p_u[9];
  const mxArray *c9_p_y = NULL;
  real_T c9_q_u;
  const mxArray *c9_q_y = NULL;
  int32_T c9_i10;
  char_T c9_r_u[5];
  const mxArray *c9_r_y = NULL;
  char_T c9_s_u;
  const mxArray *c9_s_y = NULL;
  real_T c9_t_u;
  const mxArray *c9_t_y = NULL;
  real_T c9_u_u;
  const mxArray *c9_u_y = NULL;
  int32_T c9_i11;
  char_T c9_v_u[2];
  const mxArray *c9_v_y = NULL;
  int32_T c9_i12;
  char_T c9_w_u[10];
  const mxArray *c9_w_y = NULL;
  real_T c9_x_u;
  const mxArray *c9_x_y = NULL;
  real_T c9_y_u;
  const mxArray *c9_y_y = NULL;
  real_T c9_ab_u;
  const mxArray *c9_ab_y = NULL;
  int32_T c9_i13;
  char_T c9_bb_u[2];
  const mxArray *c9_bb_y = NULL;
  int32_T c9_i14;
  char_T c9_cb_u[10];
  const mxArray *c9_cb_y = NULL;
  real_T c9_db_u;
  const mxArray *c9_db_y = NULL;
  int32_T c9_i15;
  static char_T c9_cv5[3] = { 'o', 'f', 'f' };

  char_T c9_eb_u[3];
  const mxArray *c9_eb_y = NULL;
  int32_T c9_i16;
  static real_T c9_dv0[4] = { -0.2, 0.2, -0.05, 0.2 };

  real_T c9_fb_u[4];
  const mxArray *c9_fb_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i0 = 0; c9_i0 < 2; c9_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_o)[c9_i0], 0U);
  }

  for (c9_i1 = 0; c9_i1 < 4; c9_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_rOtoL)[c9_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_figNum, 2U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *chartInstance->c9_figNum;
  for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
    c9_b_o[c9_i2] = (*chartInstance->c9_o)[c9_i2];
  }

  for (c9_i3 = 0; c9_i3 < 4; c9_i3++) {
    c9_b_rOtoL[c9_i3] = (*chartInstance->c9_rOtoL)[c9_i3];
  }

  c9_b_figNum = c9_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_o, 2U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_rOtoL, 3U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_figNum, 4U, c9_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
  c9_u = c9_b_figNum;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "figure", 0U, 1U, 14, c9_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 16);
  for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
    c9_b_u[c9_i4] = c9_cv0[c9_i4];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14, c9_b_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 18);
  c9_c_u[0] = c9_b_o[0];
  c9_c_u[1] = c9_b_rOtoL[0];
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_c_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  c9_d_u[0] = c9_b_o[1];
  c9_d_u[1] = c9_b_rOtoL[1];
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_d_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c9_i5 = 0; c9_i5 < 9; c9_i5++) {
    c9_e_u[c9_i5] = c9_cv1[c9_i5];
  }

  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_e_u, 10, 0U, 1U, 0U, 2, 1, 9),
                false);
  c9_f_u = 8.0;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_f_u, 0, 0U, 0U, 0U, 0), false);
  for (c9_i6 = 0; c9_i6 < 5; c9_i6++) {
    c9_g_u[c9_i6] = c9_cv2[c9_i6];
  }

  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_g_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  c9_h_u = 'k';
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_h_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 6U, 14, c9_c_y, 14,
                    c9_d_y, 14, c9_e_y, 14, c9_f_y, 14, c9_g_y, 14, c9_h_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 19);
  c9_i_u = c9_b_o[0];
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_i_u, 0, 0U, 0U, 0U, 0), false);
  c9_j_u = c9_b_o[1];
  c9_j_y = NULL;
  sf_mex_assign(&c9_j_y, sf_mex_create("y", &c9_j_u, 0, 0U, 0U, 0U, 0), false);
  for (c9_i7 = 0; c9_i7 < 2; c9_i7++) {
    c9_k_u[c9_i7] = c9_cv3[c9_i7];
  }

  c9_k_y = NULL;
  sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_k_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c9_i8 = 0; c9_i8 < 10; c9_i8++) {
    c9_l_u[c9_i8] = c9_cv4[c9_i8];
  }

  c9_l_y = NULL;
  sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_l_u, 10, 0U, 1U, 0U, 2, 1, 10),
                false);
  c9_m_u = 18.0;
  c9_m_y = NULL;
  sf_mex_assign(&c9_m_y, sf_mex_create("y", &c9_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 5U, 14, c9_i_y, 14,
                    c9_j_y, 14, c9_k_y, 14, c9_l_y, 14, c9_m_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 21);
  c9_n_u[0] = c9_b_rOtoL[0];
  c9_n_u[1] = c9_b_rOtoL[2];
  c9_n_y = NULL;
  sf_mex_assign(&c9_n_y, sf_mex_create("y", c9_n_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  c9_o_u[0] = c9_b_rOtoL[1];
  c9_o_u[1] = c9_b_rOtoL[3];
  c9_o_y = NULL;
  sf_mex_assign(&c9_o_y, sf_mex_create("y", c9_o_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c9_i9 = 0; c9_i9 < 9; c9_i9++) {
    c9_p_u[c9_i9] = c9_cv1[c9_i9];
  }

  c9_p_y = NULL;
  sf_mex_assign(&c9_p_y, sf_mex_create("y", c9_p_u, 10, 0U, 1U, 0U, 2, 1, 9),
                false);
  c9_q_u = 8.0;
  c9_q_y = NULL;
  sf_mex_assign(&c9_q_y, sf_mex_create("y", &c9_q_u, 0, 0U, 0U, 0U, 0), false);
  for (c9_i10 = 0; c9_i10 < 5; c9_i10++) {
    c9_r_u[c9_i10] = c9_cv2[c9_i10];
  }

  c9_r_y = NULL;
  sf_mex_assign(&c9_r_y, sf_mex_create("y", c9_r_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  c9_s_u = 'k';
  c9_s_y = NULL;
  sf_mex_assign(&c9_s_y, sf_mex_create("y", &c9_s_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 6U, 14, c9_n_y, 14,
                    c9_o_y, 14, c9_p_y, 14, c9_q_y, 14, c9_r_y, 14, c9_s_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 22);
  c9_t_u = c9_b_rOtoL[0];
  c9_t_y = NULL;
  sf_mex_assign(&c9_t_y, sf_mex_create("y", &c9_t_u, 0, 0U, 0U, 0U, 0), false);
  c9_u_u = c9_b_rOtoL[1];
  c9_u_y = NULL;
  sf_mex_assign(&c9_u_y, sf_mex_create("y", &c9_u_u, 0, 0U, 0U, 0U, 0), false);
  for (c9_i11 = 0; c9_i11 < 2; c9_i11++) {
    c9_v_u[c9_i11] = c9_cv3[c9_i11];
  }

  c9_v_y = NULL;
  sf_mex_assign(&c9_v_y, sf_mex_create("y", c9_v_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c9_i12 = 0; c9_i12 < 10; c9_i12++) {
    c9_w_u[c9_i12] = c9_cv4[c9_i12];
  }

  c9_w_y = NULL;
  sf_mex_assign(&c9_w_y, sf_mex_create("y", c9_w_u, 10, 0U, 1U, 0U, 2, 1, 10),
                false);
  c9_x_u = 18.0;
  c9_x_y = NULL;
  sf_mex_assign(&c9_x_y, sf_mex_create("y", &c9_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 5U, 14, c9_t_y, 14,
                    c9_u_y, 14, c9_v_y, 14, c9_w_y, 14, c9_x_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 24);
  c9_y_u = c9_b_rOtoL[2];
  c9_y_y = NULL;
  sf_mex_assign(&c9_y_y, sf_mex_create("y", &c9_y_u, 0, 0U, 0U, 0U, 0), false);
  c9_ab_u = c9_b_rOtoL[3];
  c9_ab_y = NULL;
  sf_mex_assign(&c9_ab_y, sf_mex_create("y", &c9_ab_u, 0, 0U, 0U, 0U, 0), false);
  for (c9_i13 = 0; c9_i13 < 2; c9_i13++) {
    c9_bb_u[c9_i13] = c9_cv3[c9_i13];
  }

  c9_bb_y = NULL;
  sf_mex_assign(&c9_bb_y, sf_mex_create("y", c9_bb_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c9_i14 = 0; c9_i14 < 10; c9_i14++) {
    c9_cb_u[c9_i14] = c9_cv4[c9_i14];
  }

  c9_cb_y = NULL;
  sf_mex_assign(&c9_cb_y, sf_mex_create("y", c9_cb_u, 10, 0U, 1U, 0U, 2, 1, 10),
                false);
  c9_db_u = 8.0;
  c9_db_y = NULL;
  sf_mex_assign(&c9_db_y, sf_mex_create("y", &c9_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 5U, 14, c9_y_y, 14,
                    c9_ab_y, 14, c9_bb_y, 14, c9_cb_y, 14, c9_db_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 25);
  for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
    c9_eb_u[c9_i15] = c9_cv5[c9_i15];
  }

  c9_eb_y = NULL;
  sf_mex_assign(&c9_eb_y, sf_mex_create("y", c9_eb_u, 10, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14, c9_eb_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 26);
  for (c9_i16 = 0; c9_i16 < 4; c9_i16++) {
    c9_fb_u[c9_i16] = c9_dv0[c9_i16];
  }

  c9_fb_y = NULL;
  sf_mex_assign(&c9_fb_y, sf_mex_create("y", c9_fb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "axis", 0U, 1U, 14, c9_fb_y);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc9_hybridSysSim(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc9_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  real_T c9_b_inData[4];
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  real_T c9_u[4];
  const mxArray *c9_y = NULL;
  SFc9_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc9_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i17 = 0;
  for (c9_i18 = 0; c9_i18 < 2; c9_i18++) {
    for (c9_i19 = 0; c9_i19 < 2; c9_i19++) {
      c9_b_inData[c9_i19 + c9_i17] = (*(real_T (*)[4])c9_inData)[c9_i19 + c9_i17];
    }

    c9_i17 += 2;
  }

  c9_i20 = 0;
  for (c9_i21 = 0; c9_i21 < 2; c9_i21++) {
    for (c9_i22 = 0; c9_i22 < 2; c9_i22++) {
      c9_u[c9_i22 + c9_i20] = c9_b_inData[c9_i22 + c9_i20];
    }

    c9_i20 += 2;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i23;
  real_T c9_b_inData[2];
  int32_T c9_i24;
  real_T c9_u[2];
  const mxArray *c9_y = NULL;
  SFc9_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc9_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i23 = 0; c9_i23 < 2; c9_i23++) {
    c9_b_inData[c9_i23] = (*(real_T (*)[2])c9_inData)[c9_i23];
  }

  for (c9_i24 = 0; c9_i24 < 2; c9_i24++) {
    c9_u[c9_i24] = c9_b_inData[c9_i24];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc9_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
                false);
  c9_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  const mxArray *c9_rhs2 = NULL;
  const mxArray *c9_lhs2 = NULL;
  const mxArray *c9_rhs3 = NULL;
  const mxArray *c9_lhs3 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("figure"), "name", "name", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/graphics/figure"), "resolved", "resolved",
                  0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("hold"), "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/matlab/graphics/hold.m"), "resolved", "resolved",
                  1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1396563870U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("plot"), "name", "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/graph2d/plot"), "resolved", "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(MAX_uint32_T), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c9_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("axis"), "name", "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/matlab/graph2d/axis.m"), "resolved", "resolved",
                  3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1405992834U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c9_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs3), "lhs", "lhs", 3);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
  sf_mex_destroy(&c9_rhs3);
  sf_mex_destroy(&c9_lhs3);
}

static const mxArray *c9_emlrt_marshallOut(const char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), false);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), false);
  return c9_y;
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc9_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_b_emlrt_marshallIn(SFc9_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i25;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i25, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i25;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc9_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_c_emlrt_marshallIn(SFc9_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_hybridSysSim, const char_T
  *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_hybridSysSim), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_hybridSysSim);
  return c9_y;
}

static uint8_T c9_d_emlrt_marshallIn(SFc9_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c9_o = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_rOtoL = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_figNum = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c9_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1638998822U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3840079075U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2290400665U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3813701264U);
}

mxArray* sf_c9_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c9_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("2tJTO7Ng12BRODHFkubQ7G");
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c9_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c9_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c9_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c9_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_hybridSysSimInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"o");
          _SFD_SET_DATA_PROPS(1,1,1,0,"rOtoL");
          _SFD_SET_DATA_PROPS(2,1,1,0,"figNum");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",314,-1,1082);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c9_o);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c9_rOtoL);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c9_figNum);
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
  return "ZBb94EYUnKcIit3vgicPBB";
}

static void sf_opaque_initialize_c9_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_hybridSysSim(void *chartInstanceVar)
{
  enable_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_hybridSysSim(void *chartInstanceVar)
{
  disable_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_hybridSysSim(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c9_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_hybridSysSim(SimStruct *S)
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
    initialize_params_c9_hybridSysSim((SFc9_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2366809497U));
  ssSetChecksum1(S,(2703350341U));
  ssSetChecksum2(S,(3494974969U));
  ssSetChecksum3(S,(3841124276U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_hybridSysSim(SimStruct *S)
{
  SFc9_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc9_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_hybridSysSim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c9_hybridSysSim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c9_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_hybridSysSim;
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

void c9_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
