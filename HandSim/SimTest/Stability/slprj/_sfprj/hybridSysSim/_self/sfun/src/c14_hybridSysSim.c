/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c14_hybridSysSim.h"
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
static const char * c14_debug_family_names[5] = { "nargin", "nargout", "o",
  "rOtoL", "figNum" };

/* Function Declarations */
static void initialize_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance);
static void c14_update_debugger_state_c14_hybridSysSim
  (SFc14_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_hybridSysSim
  (SFc14_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_st);
static void finalize_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_emlrt_marshallIn(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_info_helper(const mxArray **c14_info);
static const mxArray *c14_emlrt_marshallOut(const char * c14_u);
static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_b_emlrt_marshallIn(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_c_emlrt_marshallIn(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_hybridSysSim, const char_T *
  c14_identifier);
static uint8_T c14_d_emlrt_marshallIn(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info(SFc14_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc14_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_is_active_c14_hybridSysSim = 0U;
}

static void initialize_params_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c14_update_debugger_state_c14_hybridSysSim
  (SFc14_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c14_hybridSysSim
  (SFc14_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  uint8_T c14_hoistedGlobal;
  uint8_T c14_u;
  const mxArray *c14_b_y = NULL;
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellmatrix(1, 1), false);
  c14_hoistedGlobal = chartInstance->c14_is_active_c14_hybridSysSim;
  c14_u = c14_hoistedGlobal;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  sf_mex_assign(&c14_st, c14_y, false);
  return c14_st;
}

static void set_sim_state_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  chartInstance->c14_doneDoubleBufferReInit = true;
  c14_u = sf_mex_dup(c14_st);
  chartInstance->c14_is_active_c14_hybridSysSim = c14_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 0)),
     "is_active_c14_hybridSysSim");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_hybridSysSim(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c14_i0;
  int32_T c14_i1;
  real_T c14_hoistedGlobal;
  int32_T c14_i2;
  real_T c14_b_o[2];
  int32_T c14_i3;
  real_T c14_b_rOtoL[4];
  real_T c14_b_figNum;
  uint32_T c14_debug_family_var_map[5];
  real_T c14_nargin = 3.0;
  real_T c14_nargout = 0.0;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  int32_T c14_i4;
  static char_T c14_cv0[2] = { 'o', 'n' };

  char_T c14_b_u[2];
  const mxArray *c14_b_y = NULL;
  real_T c14_c_u[2];
  const mxArray *c14_c_y = NULL;
  real_T c14_d_u[2];
  const mxArray *c14_d_y = NULL;
  int32_T c14_i5;
  static char_T c14_cv1[9] = { 'L', 'i', 'n', 'e', 'W', 'i', 'd', 't', 'h' };

  char_T c14_e_u[9];
  const mxArray *c14_e_y = NULL;
  real_T c14_f_u;
  const mxArray *c14_f_y = NULL;
  int32_T c14_i6;
  static char_T c14_cv2[5] = { 'C', 'o', 'l', 'o', 'r' };

  char_T c14_g_u[5];
  const mxArray *c14_g_y = NULL;
  char_T c14_h_u;
  const mxArray *c14_h_y = NULL;
  real_T c14_i_u;
  const mxArray *c14_i_y = NULL;
  real_T c14_j_u;
  const mxArray *c14_j_y = NULL;
  int32_T c14_i7;
  static char_T c14_cv3[2] = { 'k', 'o' };

  char_T c14_k_u[2];
  const mxArray *c14_k_y = NULL;
  int32_T c14_i8;
  static char_T c14_cv4[10] = { 'M', 'a', 'r', 'k', 'e', 'r', 'S', 'i', 'z', 'e'
  };

  char_T c14_l_u[10];
  const mxArray *c14_l_y = NULL;
  real_T c14_m_u;
  const mxArray *c14_m_y = NULL;
  real_T c14_n_u[2];
  const mxArray *c14_n_y = NULL;
  real_T c14_o_u[2];
  const mxArray *c14_o_y = NULL;
  int32_T c14_i9;
  char_T c14_p_u[9];
  const mxArray *c14_p_y = NULL;
  real_T c14_q_u;
  const mxArray *c14_q_y = NULL;
  int32_T c14_i10;
  char_T c14_r_u[5];
  const mxArray *c14_r_y = NULL;
  char_T c14_s_u;
  const mxArray *c14_s_y = NULL;
  real_T c14_t_u;
  const mxArray *c14_t_y = NULL;
  real_T c14_u_u;
  const mxArray *c14_u_y = NULL;
  int32_T c14_i11;
  char_T c14_v_u[2];
  const mxArray *c14_v_y = NULL;
  int32_T c14_i12;
  char_T c14_w_u[10];
  const mxArray *c14_w_y = NULL;
  real_T c14_x_u;
  const mxArray *c14_x_y = NULL;
  real_T c14_y_u;
  const mxArray *c14_y_y = NULL;
  real_T c14_ab_u;
  const mxArray *c14_ab_y = NULL;
  int32_T c14_i13;
  char_T c14_bb_u[2];
  const mxArray *c14_bb_y = NULL;
  int32_T c14_i14;
  char_T c14_cb_u[10];
  const mxArray *c14_cb_y = NULL;
  real_T c14_db_u;
  const mxArray *c14_db_y = NULL;
  int32_T c14_i15;
  static char_T c14_cv5[3] = { 'o', 'f', 'f' };

  char_T c14_eb_u[3];
  const mxArray *c14_eb_y = NULL;
  int32_T c14_i16;
  static real_T c14_dv0[4] = { -0.2, 0.2, -0.05, 0.2 };

  real_T c14_fb_u[4];
  const mxArray *c14_fb_y = NULL;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  for (c14_i0 = 0; c14_i0 < 2; c14_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c14_o)[c14_i0], 0U);
  }

  for (c14_i1 = 0; c14_i1 < 4; c14_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c14_rOtoL)[c14_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c14_figNum, 2U);
  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  c14_hoistedGlobal = *chartInstance->c14_figNum;
  for (c14_i2 = 0; c14_i2 < 2; c14_i2++) {
    c14_b_o[c14_i2] = (*chartInstance->c14_o)[c14_i2];
  }

  for (c14_i3 = 0; c14_i3 < 4; c14_i3++) {
    c14_b_rOtoL[c14_i3] = (*chartInstance->c14_rOtoL)[c14_i3];
  }

  c14_b_figNum = c14_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 0U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 1U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_b_o, 2U, c14_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_b_rOtoL, 3U, c14_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_b_figNum, 4U, c14_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 15);
  c14_u = c14_b_figNum;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "figure", 0U, 1U, 14, c14_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 16);
  for (c14_i4 = 0; c14_i4 < 2; c14_i4++) {
    c14_b_u[c14_i4] = c14_cv0[c14_i4];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_b_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14, c14_b_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 18);
  c14_c_u[0] = c14_b_o[0];
  c14_c_u[1] = c14_b_rOtoL[0];
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", c14_c_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  c14_d_u[0] = c14_b_o[1];
  c14_d_u[1] = c14_b_rOtoL[1];
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", c14_d_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c14_i5 = 0; c14_i5 < 9; c14_i5++) {
    c14_e_u[c14_i5] = c14_cv1[c14_i5];
  }

  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", c14_e_u, 10, 0U, 1U, 0U, 2, 1, 9),
                false);
  c14_f_u = 8.0;
  c14_f_y = NULL;
  sf_mex_assign(&c14_f_y, sf_mex_create("y", &c14_f_u, 0, 0U, 0U, 0U, 0), false);
  for (c14_i6 = 0; c14_i6 < 5; c14_i6++) {
    c14_g_u[c14_i6] = c14_cv2[c14_i6];
  }

  c14_g_y = NULL;
  sf_mex_assign(&c14_g_y, sf_mex_create("y", c14_g_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  c14_h_u = 'k';
  c14_h_y = NULL;
  sf_mex_assign(&c14_h_y, sf_mex_create("y", &c14_h_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 6U, 14, c14_c_y, 14,
                    c14_d_y, 14, c14_e_y, 14, c14_f_y, 14, c14_g_y, 14, c14_h_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 19);
  c14_i_u = c14_b_o[0];
  c14_i_y = NULL;
  sf_mex_assign(&c14_i_y, sf_mex_create("y", &c14_i_u, 0, 0U, 0U, 0U, 0), false);
  c14_j_u = c14_b_o[1];
  c14_j_y = NULL;
  sf_mex_assign(&c14_j_y, sf_mex_create("y", &c14_j_u, 0, 0U, 0U, 0U, 0), false);
  for (c14_i7 = 0; c14_i7 < 2; c14_i7++) {
    c14_k_u[c14_i7] = c14_cv3[c14_i7];
  }

  c14_k_y = NULL;
  sf_mex_assign(&c14_k_y, sf_mex_create("y", c14_k_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c14_i8 = 0; c14_i8 < 10; c14_i8++) {
    c14_l_u[c14_i8] = c14_cv4[c14_i8];
  }

  c14_l_y = NULL;
  sf_mex_assign(&c14_l_y, sf_mex_create("y", c14_l_u, 10, 0U, 1U, 0U, 2, 1, 10),
                false);
  c14_m_u = 18.0;
  c14_m_y = NULL;
  sf_mex_assign(&c14_m_y, sf_mex_create("y", &c14_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 5U, 14, c14_i_y, 14,
                    c14_j_y, 14, c14_k_y, 14, c14_l_y, 14, c14_m_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 21);
  c14_n_u[0] = c14_b_rOtoL[0];
  c14_n_u[1] = c14_b_rOtoL[2];
  c14_n_y = NULL;
  sf_mex_assign(&c14_n_y, sf_mex_create("y", c14_n_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  c14_o_u[0] = c14_b_rOtoL[1];
  c14_o_u[1] = c14_b_rOtoL[3];
  c14_o_y = NULL;
  sf_mex_assign(&c14_o_y, sf_mex_create("y", c14_o_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c14_i9 = 0; c14_i9 < 9; c14_i9++) {
    c14_p_u[c14_i9] = c14_cv1[c14_i9];
  }

  c14_p_y = NULL;
  sf_mex_assign(&c14_p_y, sf_mex_create("y", c14_p_u, 10, 0U, 1U, 0U, 2, 1, 9),
                false);
  c14_q_u = 8.0;
  c14_q_y = NULL;
  sf_mex_assign(&c14_q_y, sf_mex_create("y", &c14_q_u, 0, 0U, 0U, 0U, 0), false);
  for (c14_i10 = 0; c14_i10 < 5; c14_i10++) {
    c14_r_u[c14_i10] = c14_cv2[c14_i10];
  }

  c14_r_y = NULL;
  sf_mex_assign(&c14_r_y, sf_mex_create("y", c14_r_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  c14_s_u = 'k';
  c14_s_y = NULL;
  sf_mex_assign(&c14_s_y, sf_mex_create("y", &c14_s_u, 10, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 6U, 14, c14_n_y, 14,
                    c14_o_y, 14, c14_p_y, 14, c14_q_y, 14, c14_r_y, 14, c14_s_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 22);
  c14_t_u = c14_b_rOtoL[0];
  c14_t_y = NULL;
  sf_mex_assign(&c14_t_y, sf_mex_create("y", &c14_t_u, 0, 0U, 0U, 0U, 0), false);
  c14_u_u = c14_b_rOtoL[1];
  c14_u_y = NULL;
  sf_mex_assign(&c14_u_y, sf_mex_create("y", &c14_u_u, 0, 0U, 0U, 0U, 0), false);
  for (c14_i11 = 0; c14_i11 < 2; c14_i11++) {
    c14_v_u[c14_i11] = c14_cv3[c14_i11];
  }

  c14_v_y = NULL;
  sf_mex_assign(&c14_v_y, sf_mex_create("y", c14_v_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c14_i12 = 0; c14_i12 < 10; c14_i12++) {
    c14_w_u[c14_i12] = c14_cv4[c14_i12];
  }

  c14_w_y = NULL;
  sf_mex_assign(&c14_w_y, sf_mex_create("y", c14_w_u, 10, 0U, 1U, 0U, 2, 1, 10),
                false);
  c14_x_u = 18.0;
  c14_x_y = NULL;
  sf_mex_assign(&c14_x_y, sf_mex_create("y", &c14_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 5U, 14, c14_t_y, 14,
                    c14_u_y, 14, c14_v_y, 14, c14_w_y, 14, c14_x_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 24);
  c14_y_u = c14_b_rOtoL[2];
  c14_y_y = NULL;
  sf_mex_assign(&c14_y_y, sf_mex_create("y", &c14_y_u, 0, 0U, 0U, 0U, 0), false);
  c14_ab_u = c14_b_rOtoL[3];
  c14_ab_y = NULL;
  sf_mex_assign(&c14_ab_y, sf_mex_create("y", &c14_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  for (c14_i13 = 0; c14_i13 < 2; c14_i13++) {
    c14_bb_u[c14_i13] = c14_cv3[c14_i13];
  }

  c14_bb_y = NULL;
  sf_mex_assign(&c14_bb_y, sf_mex_create("y", c14_bb_u, 10, 0U, 1U, 0U, 2, 1, 2),
                false);
  for (c14_i14 = 0; c14_i14 < 10; c14_i14++) {
    c14_cb_u[c14_i14] = c14_cv4[c14_i14];
  }

  c14_cb_y = NULL;
  sf_mex_assign(&c14_cb_y, sf_mex_create("y", c14_cb_u, 10, 0U, 1U, 0U, 2, 1, 10),
                false);
  c14_db_u = 8.0;
  c14_db_y = NULL;
  sf_mex_assign(&c14_db_y, sf_mex_create("y", &c14_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "plot", 0U, 5U, 14, c14_y_y, 14,
                    c14_ab_y, 14, c14_bb_y, 14, c14_cb_y, 14, c14_db_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 25);
  for (c14_i15 = 0; c14_i15 < 3; c14_i15++) {
    c14_eb_u[c14_i15] = c14_cv5[c14_i15];
  }

  c14_eb_y = NULL;
  sf_mex_assign(&c14_eb_y, sf_mex_create("y", c14_eb_u, 10, 0U, 1U, 0U, 2, 1, 3),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "hold", 0U, 1U, 14, c14_eb_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 26);
  for (c14_i16 = 0; c14_i16 < 4; c14_i16++) {
    c14_fb_u[c14_i16] = c14_dv0[c14_i16];
  }

  c14_fb_y = NULL;
  sf_mex_assign(&c14_fb_y, sf_mex_create("y", c14_fb_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "axis", 0U, 1U, 14, c14_fb_y);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc14_hybridSysSim(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber)
{
  (void)c14_machineNumber;
  (void)c14_chartNumber;
  (void)c14_instanceNumber;
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc14_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i17;
  int32_T c14_i18;
  int32_T c14_i19;
  real_T c14_b_inData[4];
  int32_T c14_i20;
  int32_T c14_i21;
  int32_T c14_i22;
  real_T c14_u[4];
  const mxArray *c14_y = NULL;
  SFc14_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc14_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i17 = 0;
  for (c14_i18 = 0; c14_i18 < 2; c14_i18++) {
    for (c14_i19 = 0; c14_i19 < 2; c14_i19++) {
      c14_b_inData[c14_i19 + c14_i17] = (*(real_T (*)[4])c14_inData)[c14_i19 +
        c14_i17];
    }

    c14_i17 += 2;
  }

  c14_i20 = 0;
  for (c14_i21 = 0; c14_i21 < 2; c14_i21++) {
    for (c14_i22 = 0; c14_i22 < 2; c14_i22++) {
      c14_u[c14_i22 + c14_i20] = c14_b_inData[c14_i22 + c14_i20];
    }

    c14_i20 += 2;
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i23;
  real_T c14_b_inData[2];
  int32_T c14_i24;
  real_T c14_u[2];
  const mxArray *c14_y = NULL;
  SFc14_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc14_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i23 = 0; c14_i23 < 2; c14_i23++) {
    c14_b_inData[c14_i23] = (*(real_T (*)[2])c14_inData)[c14_i23];
  }

  for (c14_i24 = 0; c14_i24 < 2; c14_i24++) {
    c14_u[c14_i24] = c14_b_inData[c14_i24];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static real_T c14_emlrt_marshallIn(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_nargout;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc14_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c14_nargout = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_nargout),
    &c14_thisId);
  sf_mex_destroy(&c14_nargout);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
                false);
  c14_info_helper(&c14_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(const mxArray **c14_info)
{
  const mxArray *c14_rhs0 = NULL;
  const mxArray *c14_lhs0 = NULL;
  const mxArray *c14_rhs1 = NULL;
  const mxArray *c14_lhs1 = NULL;
  const mxArray *c14_rhs2 = NULL;
  const mxArray *c14_lhs2 = NULL;
  const mxArray *c14_rhs3 = NULL;
  const mxArray *c14_lhs3 = NULL;
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("figure"), "name", "name", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/graphics/figure"), "resolved", "resolved",
                  0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 0);
  sf_mex_assign(&c14_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("hold"), "name", "name", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/matlab/graphics/hold.m"), "resolved", "resolved",
                  1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1396563870U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c14_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("plot"), "name", "name", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/graph2d/plot"), "resolved", "resolved", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 2);
  sf_mex_assign(&c14_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("axis"), "name", "name", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/matlab/graph2d/axis.m"), "resolved", "resolved",
                  3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1405992834U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c14_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs3), "lhs", "lhs",
                  3);
  sf_mex_destroy(&c14_rhs0);
  sf_mex_destroy(&c14_lhs0);
  sf_mex_destroy(&c14_rhs1);
  sf_mex_destroy(&c14_lhs1);
  sf_mex_destroy(&c14_rhs2);
  sf_mex_destroy(&c14_lhs2);
  sf_mex_destroy(&c14_rhs3);
  sf_mex_destroy(&c14_lhs3);
}

static const mxArray *c14_emlrt_marshallOut(const char * c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c14_u)), false);
  return c14_y;
}

static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 7, 0U, 0U, 0U, 0), false);
  return c14_y;
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc14_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static int32_T c14_b_emlrt_marshallIn(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i25;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i25, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i25;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc14_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_c_emlrt_marshallIn(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_hybridSysSim, const char_T *
  c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_hybridSysSim), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_hybridSysSim);
  return c14_y;
}

static uint8_T c14_d_emlrt_marshallIn(SFc14_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc14_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c14_o = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c14_rOtoL = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c14_figNum = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c14_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1638998822U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3840079075U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2290400665U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3813701264U);
}

mxArray* sf_c14_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c14_hybridSysSim_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c14_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c14_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c14_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c14_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c14_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c14_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc14_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           14,
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
            1.0,0,0,(MexFcnForType)c14_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c14_o);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c14_rOtoL);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c14_figNum);
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

static void sf_opaque_initialize_c14_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_hybridSysSim(void *chartInstanceVar)
{
  enable_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_hybridSysSim(void *chartInstanceVar)
{
  disable_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c14_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c14_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c14_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*)
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
  initSimStructsc14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_hybridSysSim(SimStruct *S)
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
    initialize_params_c14_hybridSysSim((SFc14_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,14,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
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

static void mdlRTW_c14_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_hybridSysSim(SimStruct *S)
{
  SFc14_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc14_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc14_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c14_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c14_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c14_hybridSysSim;
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

void c14_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
