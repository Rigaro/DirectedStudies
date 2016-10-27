/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c25_hybridSysSim.h"
#include <math.h>
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
static const char * c25_debug_family_names[49] = { "kP", "kD", "dP", "dD", "lP",
  "lD", "rP", "rD", "aP", "aD", "bP", "bD", "mP", "mD", "IP", "ID", "alpha",
  "beta", "delta", "M", "C", "D", "Hp", "Hd", "Ki", "Kp", "Kd", "kc", "lambdaM",
  "lambdaHp", "lambdaHd", "lambdaKi", "kq", "zero", "one", "L1", "L2", "L3",
  "L4", "L5", "L", "lambdaL", "lambdaD", "nargin", "nargout", "q", "qDot",
  "qTilde", "rGAC" };

/* Function Declarations */
static void initialize_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void c25_update_debugger_state_c25_hybridSysSim
  (SFc25_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c25_hybridSysSim
  (SFc25_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_st);
static void finalize_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void c25_chartstep_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber);
static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static creal_T c25_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_b_rGAC, const char_T *c25_identifier);
static creal_T c25_b_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static const mxArray *c25_c_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static const mxArray *c25_d_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_c_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_e_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static const mxArray *c25_f_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_d_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  creal_T c25_y[10]);
static void c25_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_g_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_e_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[100]);
static void c25_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_h_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_f_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[20]);
static void c25_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_i_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_g_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  creal_T c25_y[2]);
static void c25_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static void c25_h_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[4]);
static void c25_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static void c25_info_helper(const mxArray **c25_info);
static const mxArray *c25_emlrt_marshallOut(const char * c25_u);
static const mxArray *c25_b_emlrt_marshallOut(const uint32_T c25_u);
static void c25_b_info_helper(const mxArray **c25_info);
static void c25_c_info_helper(const mxArray **c25_info);
static void c25_d_info_helper(const mxArray **c25_info);
static void c25_e_info_helper(const mxArray **c25_info);
static void c25_eml_scalar_eg(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_assert(SFc25_hybridSysSimInstanceStruct *chartInstance);
static real_T c25_rdivide(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_x, real_T c25_y);
static real_T c25_norm(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x[4]);
static void c25_eml_switch_helper(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static boolean_T c25_isfinite(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_x);
static void c25_eml_error(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_eml_matlab_zsvdc(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_A[4], real_T c25_S[2]);
static void c25_b_eml_scalar_eg(SFc25_hybridSysSimInstanceStruct *chartInstance);
static real_T c25_eml_xnrm2(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_x[4]);
static void c25_threshold(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_realmin(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_eml_realmin(SFc25_hybridSysSimInstanceStruct *chartInstance);
static real_T c25_abs(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
                      c25_x);
static void c25_eps(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_b_eml_switch_helper(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static real_T c25_eml_xdotc(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_x[4], real_T c25_y[4]);
static void c25_eml_xaxpy(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_a, real_T c25_y[4], real_T c25_b_y[4]);
static void c25_b_eml_error(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_check_forloop_overflow_error(SFc25_hybridSysSimInstanceStruct
  *chartInstance, boolean_T c25_overflow);
static real_T c25_sqrt(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x);
static void c25_c_eml_error(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_eml_xrotg(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_a, real_T c25_b, real_T *c25_b_a, real_T *c25_b_b, real_T *c25_c,
  real_T *c25_s);
static real_T c25_b_norm(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x[2]);
static void c25_eig(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
                    c25_A[4], creal_T c25_V[2]);
static void c25_b_assert(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_c_assert(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_parseopts(SFc25_hybridSysSimInstanceStruct *chartInstance);
static real_T c25_eml_matlab_zlangeM(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_x[4]);
static real_T c25_b_abs(SFc25_hybridSysSimInstanceStruct *chartInstance, creal_T
  c25_x);
static void c25_eml_matlab_zlascl(SFc25_hybridSysSimInstanceStruct
  *chartInstance, real_T c25_cfrom, real_T c25_cto, creal_T c25_A[4], creal_T
  c25_b_A[4]);
static void c25_eml_matlab_zggbal(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[4], creal_T c25_b_A[4], int32_T *c25_ilo,
  int32_T *c25_ihi, int32_T c25_rscale[2]);
static void c25_eml_matlab_zlartg(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_f, creal_T c25_g, real_T *c25_cs, creal_T *c25_sn,
  creal_T *c25_r);
static void c25_eml_matlab_zhgeqz(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[4], int32_T c25_ilo, int32_T c25_ihi, int32_T
  *c25_info, creal_T c25_alpha1[2], creal_T c25_beta1[2]);
static real_T c25_eml_matlab_zlanhs(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[4], int32_T c25_ilo, int32_T c25_ihi);
static int32_T c25_mod(SFc25_hybridSysSimInstanceStruct *chartInstance, int32_T
  c25_x);
static creal_T c25_b_sqrt(SFc25_hybridSysSimInstanceStruct *chartInstance,
  creal_T c25_x);
static void c25_realmax(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_b_eml_matlab_zlartg(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_f, creal_T c25_g, real_T *c25_cs, creal_T *c25_sn);
static void c25_eml_warning(SFc25_hybridSysSimInstanceStruct *chartInstance);
static boolean_T c25_eml_relop(SFc25_hybridSysSimInstanceStruct *chartInstance,
  creal_T c25_a, creal_T c25_b);
static real_T c25_hypot(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x, real_T c25_y);
static real_T c25_angle(SFc25_hybridSysSimInstanceStruct *chartInstance, creal_T
  c25_x);
static void c25_inv(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
                    c25_x[4], real_T c25_y[4]);
static real_T c25_c_norm(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x[4]);
static void c25_b_eml_warning(SFc25_hybridSysSimInstanceStruct *chartInstance);
static void c25_c_eml_warning(SFc25_hybridSysSimInstanceStruct *chartInstance,
  char_T c25_varargin_2[14]);
static void c25_b_eig(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
                      c25_A[100], creal_T c25_V[10]);
static void c25_c_eml_scalar_eg(SFc25_hybridSysSimInstanceStruct *chartInstance);
static real_T c25_b_eml_matlab_zlangeM(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_x[100]);
static void c25_b_eml_matlab_zggbal(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[100], creal_T c25_b_A[100], int32_T *c25_ilo,
  int32_T *c25_ihi, int32_T c25_rscale[10]);
static void c25_eml_matlab_zgghrd(SFc25_hybridSysSimInstanceStruct
  *chartInstance, int32_T c25_ilo, int32_T c25_ihi, creal_T c25_A[100], creal_T
  c25_b_A[100]);
static void c25_b_eml_matlab_zhgeqz(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[100], int32_T c25_ilo, int32_T c25_ihi, int32_T *
  c25_info, creal_T c25_alpha1[10], creal_T c25_beta1[10]);
static real_T c25_b_eml_matlab_zlanhs(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[100], int32_T c25_ilo, int32_T c25_ihi);
static boolean_T c25_b_eml_relop(SFc25_hybridSysSimInstanceStruct *chartInstance,
  creal_T c25_a, creal_T c25_b);
static void c25_i_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_sprintf, const char_T *c25_identifier,
  char_T c25_y[14]);
static void c25_j_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  char_T c25_y[14]);
static const mxArray *c25_j_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static int32_T c25_k_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static uint8_T c25_l_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_hybridSysSim, const char_T *
  c25_identifier);
static uint8_T c25_m_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_b_eml_xaxpy(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_a, real_T c25_y[4]);
static void c25_c_sqrt(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  *c25_x);
static void c25_b_eml_xrotg(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T *c25_a, real_T *c25_b, real_T *c25_c, real_T *c25_s);
static void c25_b_eml_matlab_zlascl(SFc25_hybridSysSimInstanceStruct
  *chartInstance, real_T c25_cfrom, real_T c25_cto, creal_T c25_A[4]);
static void c25_c_eml_matlab_zggbal(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[4], int32_T *c25_ilo, int32_T *c25_ihi, int32_T
  c25_rscale[2]);
static void c25_d_sqrt(SFc25_hybridSysSimInstanceStruct *chartInstance, creal_T *
  c25_x);
static void c25_d_eml_matlab_zggbal(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[100], int32_T *c25_ilo, int32_T *c25_ihi,
  int32_T c25_rscale[10]);
static void c25_b_eml_matlab_zgghrd(SFc25_hybridSysSimInstanceStruct
  *chartInstance, int32_T c25_ilo, int32_T c25_ihi, creal_T c25_A[100]);
static int32_T c25_div_s32(SFc25_hybridSysSimInstanceStruct *chartInstance,
  int32_T c25_numerator, int32_T c25_denominator);
static void init_dsm_address_info(SFc25_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc25_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c25_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c25_is_active_c25_hybridSysSim = 0U;
}

static void initialize_params_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c25_update_debugger_state_c25_hybridSysSim
  (SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c25_hybridSysSim
  (SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c25_st;
  const mxArray *c25_y = NULL;
  creal_T c25_u;
  const mxArray *c25_b_y = NULL;
  uint8_T c25_hoistedGlobal;
  uint8_T c25_b_u;
  const mxArray *c25_c_y = NULL;
  c25_st = NULL;
  c25_st = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_createcellmatrix(2, 1), false);
  c25_u = *chartInstance->c25_rGAC;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_u, 0, 1U, 0U, 0U, 0), false);
  sf_mex_setcell(c25_y, 0, c25_b_y);
  c25_hoistedGlobal = chartInstance->c25_is_active_c25_hybridSysSim;
  c25_b_u = c25_hoistedGlobal;
  c25_c_y = NULL;
  sf_mex_assign(&c25_c_y, sf_mex_create("y", &c25_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c25_y, 1, c25_c_y);
  sf_mex_assign(&c25_st, c25_y, false);
  return c25_st;
}

static void set_sim_state_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_st)
{
  const mxArray *c25_u;
  chartInstance->c25_doneDoubleBufferReInit = true;
  c25_u = sf_mex_dup(c25_st);
  *chartInstance->c25_rGAC = c25_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c25_u, 0)), "rGAC");
  chartInstance->c25_is_active_c25_hybridSysSim = c25_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c25_u, 1)),
     "is_active_c25_hybridSysSim");
  sf_mex_destroy(&c25_u);
  c25_update_debugger_state_c25_hybridSysSim(chartInstance);
  sf_mex_destroy(&c25_st);
}

static void finalize_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c25_i0;
  int32_T c25_i1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, chartInstance->c25_sfEvent);
  for (c25_i0 = 0; c25_i0 < 2; c25_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_q)[c25_i0], 0U);
  }

  chartInstance->c25_sfEvent = CALL_EVENT;
  c25_chartstep_c25_hybridSysSim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c25_i1 = 0; c25_i1 < 2; c25_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_qDot)[c25_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c25_qTilde, 3U);
}

static void mdl_start_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_chartstep_c25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  real_T c25_hoistedGlobal;
  int32_T c25_i2;
  real_T c25_b_q[2];
  int32_T c25_i3;
  real_T c25_b_qDot[2];
  real_T c25_b_qTilde;
  uint32_T c25_debug_family_var_map[49];
  real_T c25_kP;
  real_T c25_kD;
  real_T c25_dP;
  real_T c25_dD;
  real_T c25_lP;
  real_T c25_lD;
  real_T c25_rP;
  real_T c25_rD;
  real_T c25_aP;
  real_T c25_aD;
  real_T c25_bP;
  real_T c25_bD;
  real_T c25_mP;
  real_T c25_mD;
  real_T c25_IP;
  real_T c25_ID;
  real_T c25_alpha;
  real_T c25_beta;
  real_T c25_delta;
  real_T c25_M[4];
  real_T c25_C[4];
  real_T c25_D[4];
  real_T c25_Hp[4];
  real_T c25_Hd[4];
  real_T c25_Ki[4];
  real_T c25_Kp[4];
  real_T c25_Kd;
  real_T c25_kc;
  creal_T c25_lambdaM[2];
  creal_T c25_lambdaHp[2];
  creal_T c25_lambdaHd[2];
  creal_T c25_lambdaKi[2];
  creal_T c25_kq;
  real_T c25_zero[4];
  real_T c25_one[4];
  real_T c25_L1[20];
  real_T c25_L2[20];
  real_T c25_L3[20];
  real_T c25_L4[20];
  real_T c25_L5[20];
  real_T c25_L[100];
  creal_T c25_lambdaL[10];
  creal_T c25_lambdaD[2];
  real_T c25_nargin = 3.0;
  real_T c25_nargout = 1.0;
  creal_T c25_b_rGAC;
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_e_x;
  real_T c25_f_x;
  real_T c25_g_x;
  real_T c25_h_x;
  real_T c25_i_x;
  real_T c25_j_x;
  real_T c25_k_x;
  real_T c25_l_x;
  int32_T c25_i4;
  static real_T c25_dv0[4] = { 0.01, 0.0, 0.0, 0.01 };

  int32_T c25_i5;
  static real_T c25_dv1[4] = { 5.8, 0.0, 0.0, 5.8 };

  int32_T c25_i6;
  static real_T c25_dv2[4] = { 0.03, 0.0, 0.0, 0.03 };

  int32_T c25_i7;
  static real_T c25_dv3[4] = { 1.0, 0.0, 0.0, 1.0 };

  int32_T c25_i8;
  int32_T c25_i9;
  real_T c25_b_C[4];
  real_T c25_A;
  int32_T c25_i10;
  real_T c25_c_qDot[2];
  real_T c25_B;
  int32_T c25_i11;
  real_T c25_b_M[4];
  creal_T c25_dcv0[2];
  int32_T c25_i12;
  int32_T c25_i13;
  int32_T c25_i14;
  int32_T c25_i15;
  int32_T c25_i16;
  creal_T c25_varargin_1[2];
  int32_T c25_ixstart;
  creal_T c25_mtmp;
  boolean_T c25_b0;
  boolean_T c25_b1;
  boolean_T c25_b;
  int32_T c25_ix;
  int32_T c25_b_ix;
  creal_T c25_m_x;
  boolean_T c25_b2;
  boolean_T c25_b3;
  boolean_T c25_b_b;
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_i17;
  int32_T c25_c_a;
  int32_T c25_d_a;
  boolean_T c25_overflow;
  int32_T c25_c_ix;
  creal_T c25_b_varargin_1;
  static creal_T c25_dc0 = { 0.03, 0.0 };

  real_T c25_b_B;
  real_T c25_y;
  real_T c25_b_y;
  real_T c25_c_y;
  real_T c25_ar;
  real_T c25_ai;
  real_T c25_br;
  real_T c25_bi;
  real_T c25_brm;
  real_T c25_bim;
  real_T c25_s;
  real_T c25_d;
  real_T c25_nr;
  real_T c25_ni;
  real_T c25_sgnbr;
  real_T c25_sgnbi;
  int32_T c25_i18;
  int32_T c25_i19;
  int32_T c25_i20;
  int32_T c25_i21;
  int32_T c25_i22;
  static real_T c25_dv4[4] = { 5.84, 0.0, 0.0, 5.84 };

  int32_T c25_i23;
  int32_T c25_i24;
  int32_T c25_i25;
  int32_T c25_i26;
  int32_T c25_i27;
  int32_T c25_i28;
  int32_T c25_i29;
  int32_T c25_i30;
  int32_T c25_i31;
  int32_T c25_i32;
  int32_T c25_i33;
  int32_T c25_i34;
  int32_T c25_i35;
  int32_T c25_i36;
  int32_T c25_i37;
  int32_T c25_i38;
  int32_T c25_i39;
  int32_T c25_i40;
  int32_T c25_i41;
  int32_T c25_i42;
  int32_T c25_i43;
  int32_T c25_i44;
  int32_T c25_i45;
  int32_T c25_i46;
  int32_T c25_i47;
  int32_T c25_i48;
  int32_T c25_i49;
  int32_T c25_i50;
  static real_T c25_dv5[20] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.8, 0.0,
    0.0, 5.8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c25_i51;
  int32_T c25_i52;
  int32_T c25_i53;
  int32_T c25_i54;
  int32_T c25_i55;
  int32_T c25_i56;
  int32_T c25_i57;
  int32_T c25_i58;
  int32_T c25_i59;
  int32_T c25_i60;
  int32_T c25_i61;
  int32_T c25_i62;
  int32_T c25_i63;
  int32_T c25_i64;
  int32_T c25_i65;
  int32_T c25_i66;
  real_T c25_dv6[4];
  real_T c25_dv7[4];
  int32_T c25_i67;
  int32_T c25_i68;
  int32_T c25_i69;
  int32_T c25_i70;
  int32_T c25_i71;
  int32_T c25_i72;
  int32_T c25_i73;
  int32_T c25_i74;
  int32_T c25_i75;
  int32_T c25_i76;
  int32_T c25_i77;
  int32_T c25_i78;
  int32_T c25_i79;
  int32_T c25_i80;
  int32_T c25_i81;
  int32_T c25_i82;
  int32_T c25_i83;
  int32_T c25_i84;
  int32_T c25_i85;
  int32_T c25_i86;
  int32_T c25_i87;
  int32_T c25_i88;
  int32_T c25_i89;
  int32_T c25_i90;
  int32_T c25_i91;
  int32_T c25_i92;
  int32_T c25_i93;
  int32_T c25_i94;
  int32_T c25_i95;
  int32_T c25_i96;
  int32_T c25_i97;
  int32_T c25_i98;
  int32_T c25_i99;
  int32_T c25_i100;
  int32_T c25_i101;
  int32_T c25_i102;
  real_T c25_b_L[100];
  creal_T c25_dcv1[10];
  int32_T c25_i103;
  int32_T c25_i104;
  real_T c25_c_B;
  real_T c25_d_y;
  int32_T c25_i105;
  creal_T c25_c_varargin_1[10];
  int32_T c25_b_ixstart;
  boolean_T c25_b4;
  boolean_T c25_b5;
  boolean_T c25_c_b;
  int32_T c25_d_ix;
  int32_T c25_e_ix;
  boolean_T c25_b6;
  boolean_T c25_b7;
  boolean_T c25_d_b;
  int32_T c25_e_a;
  int32_T c25_f_a;
  int32_T c25_i106;
  int32_T c25_g_a;
  int32_T c25_h_a;
  boolean_T c25_b_overflow;
  int32_T c25_f_ix;
  creal_T c25_d_varargin_1;
  int32_T c25_i107;
  int32_T c25_c_ixstart;
  creal_T c25_b_mtmp;
  boolean_T c25_b8;
  boolean_T c25_b9;
  boolean_T c25_e_b;
  int32_T c25_g_ix;
  int32_T c25_h_ix;
  boolean_T c25_b10;
  boolean_T c25_b11;
  boolean_T c25_f_b;
  int32_T c25_i_a;
  int32_T c25_j_a;
  int32_T c25_i108;
  int32_T c25_k_a;
  int32_T c25_l_a;
  boolean_T c25_c_overflow;
  int32_T c25_i_ix;
  creal_T c25_e_varargin_1;
  real_T c25_b_ar;
  real_T c25_b_ai;
  real_T c25_b_br;
  real_T c25_b_bi;
  creal_T c25_e_y;
  real_T c25_b_brm;
  real_T c25_b_bim;
  real_T c25_b_s;
  real_T c25_b_d;
  real_T c25_b_nr;
  real_T c25_b_ni;
  real_T c25_b_sgnbr;
  real_T c25_b_sgnbi;
  real_T c25_m_a;
  int32_T c25_i109;
  int32_T c25_d_ixstart;
  boolean_T c25_b12;
  boolean_T c25_b13;
  boolean_T c25_g_b;
  int32_T c25_j_ix;
  int32_T c25_k_ix;
  boolean_T c25_b14;
  boolean_T c25_b15;
  boolean_T c25_h_b;
  int32_T c25_n_a;
  int32_T c25_o_a;
  int32_T c25_i110;
  int32_T c25_p_a;
  int32_T c25_q_a;
  boolean_T c25_d_overflow;
  int32_T c25_l_ix;
  creal_T c25_f_varargin_1;
  creal_T c25_f_y;
  static creal_T c25_dc1 = { 0.01, 0.0 };

  int32_T c25_m_ix;
  int32_T c25_n_ix;
  int32_T c25_o_ix;
  creal_T c25_dc2;
  int32_T c25_p_ix;
  int32_T c25_q_ix;
  int32_T c25_r_ix;
  int32_T c25_s_ix;
  creal_T c25_dc3;
  int32_T c25_t_ix;
  creal_T c25_c_mtmp;
  int32_T c25_u_ix;
  int32_T c25_v_ix;
  int32_T c25_w_ix;
  creal_T c25_dc4;
  int32_T c25_x_ix;
  int32_T c25_i111;
  int32_T c25_e_ixstart;
  creal_T c25_d_mtmp;
  boolean_T c25_b16;
  boolean_T c25_b17;
  boolean_T c25_i_b;
  int32_T c25_y_ix;
  int32_T c25_ab_ix;
  boolean_T c25_b18;
  boolean_T c25_b19;
  boolean_T c25_j_b;
  int32_T c25_r_a;
  int32_T c25_s_a;
  int32_T c25_i112;
  int32_T c25_t_a;
  int32_T c25_u_a;
  boolean_T c25_e_overflow;
  int32_T c25_bb_ix;
  creal_T c25_g_varargin_1;
  creal_T c25_n_x;
  static creal_T c25_dc5 = { 1.0, 0.0 };

  real_T c25_c_ar;
  real_T c25_c_ai;
  real_T c25_c_br;
  real_T c25_c_bi;
  real_T c25_c_brm;
  real_T c25_c_bim;
  real_T c25_c_s;
  real_T c25_c_d;
  real_T c25_c_nr;
  real_T c25_c_ni;
  real_T c25_c_sgnbr;
  real_T c25_c_sgnbi;
  real_T c25_d_ar;
  real_T c25_d_ai;
  static creal_T c25_dc6 = { 4.8, 0.0 };

  real_T c25_d_br;
  real_T c25_d_bi;
  real_T c25_d_brm;
  real_T c25_d_bim;
  real_T c25_d_s;
  real_T c25_d_d;
  real_T c25_d_nr;
  real_T c25_d_ni;
  real_T c25_d_sgnbr;
  real_T c25_d_sgnbi;
  creal_T c25_o_x;
  static creal_T c25_dc7 = { 0.000225, 0.0 };

  creal_T c25_dc8;
  creal_T c25_g_y;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c25_sfEvent);
  c25_hoistedGlobal = *chartInstance->c25_qTilde;
  for (c25_i2 = 0; c25_i2 < 2; c25_i2++) {
    c25_b_q[c25_i2] = (*chartInstance->c25_q)[c25_i2];
  }

  for (c25_i3 = 0; c25_i3 < 2; c25_i3++) {
    c25_b_qDot[c25_i3] = (*chartInstance->c25_qDot)[c25_i3];
  }

  c25_b_qTilde = c25_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 49U, 49U, c25_debug_family_names,
    c25_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_kP, 0U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_kD, 1U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_dP, 2U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_dD, 3U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_lP, 4U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_lD, 5U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_rP, 6U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_rD, 7U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_aP, 8U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_aD, 9U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_bP, 10U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_bD, 11U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_mP, 12U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_mD, 13U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_IP, 14U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_ID, 15U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_alpha, 16U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_beta, 17U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_delta, 18U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_M, 19U, c25_i_sf_marshallOut,
    c25_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_C, 20U, c25_i_sf_marshallOut,
    c25_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_D, 21U, c25_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_Hp, 22U, c25_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_Hd, 23U, c25_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_Ki, 24U, c25_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_Kp, 25U, c25_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_Kd, 26U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_kc, 27U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_lambdaM, 28U, c25_e_sf_marshallOut,
    c25_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_lambdaHp, 29U, c25_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_lambdaHd, 30U, c25_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_lambdaKi, 31U, c25_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_kq, 32U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_zero, 33U, c25_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_one, 34U, c25_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_L1, 35U, c25_h_sf_marshallOut,
    c25_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_L2, 36U, c25_h_sf_marshallOut,
    c25_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_L3, 37U, c25_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_L4, 38U, c25_h_sf_marshallOut,
    c25_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_L5, 39U, c25_h_sf_marshallOut,
    c25_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_L, 40U, c25_g_sf_marshallOut,
    c25_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_lambdaL, 41U, c25_f_sf_marshallOut,
    c25_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_lambdaD, 42U, c25_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargin, 43U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargout, 44U, c25_b_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_q, 45U, c25_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_qDot, 46U, c25_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_b_qTilde, 47U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_b_rGAC, 48U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 3);
  c25_kP = 0.043;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 4);
  c25_kD = 0.185;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 5);
  c25_dP = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 6);
  c25_dD = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 7);
  c25_lP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 8);
  c25_lD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 9);
  c25_rP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 10);
  c25_rD = 0.012;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 11);
  c25_aP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 12);
  c25_aD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 13);
  c25_bP = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 14);
  c25_bD = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 15);
  c25_mP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 16);
  c25_mD = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 17);
  c25_IP = 6.6666666666666683E-5;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 18);
  c25_ID = 1.6666666666666671E-5;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 20);
  c25_alpha = 0.0003833333333333334;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 21);
  c25_beta = 0.0001;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 22);
  c25_delta = c25_ID + 5.0000000000000009E-5;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 24);
  c25_x = c25_b_q[1];
  c25_b_x = c25_x;
  c25_b_x = muDoubleScalarCos(c25_b_x);
  c25_c_x = c25_b_q[1];
  c25_d_x = c25_c_x;
  c25_d_x = muDoubleScalarCos(c25_d_x);
  c25_e_x = c25_b_q[1];
  c25_f_x = c25_e_x;
  c25_f_x = muDoubleScalarCos(c25_f_x);
  c25_M[0] = c25_alpha + 0.0002 * c25_b_x;
  c25_M[2] = c25_delta + 0.0001 * c25_d_x;
  c25_M[1] = c25_delta + 0.0001 * c25_f_x;
  c25_M[3] = c25_delta;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 27);
  c25_g_x = c25_b_q[1];
  c25_h_x = c25_g_x;
  c25_h_x = muDoubleScalarSin(c25_h_x);
  c25_i_x = c25_b_q[1];
  c25_j_x = c25_i_x;
  c25_j_x = muDoubleScalarSin(c25_j_x);
  c25_k_x = c25_b_q[1];
  c25_l_x = c25_k_x;
  c25_l_x = muDoubleScalarSin(c25_l_x);
  c25_C[0] = -0.0001 * c25_h_x * c25_b_qDot[1];
  c25_C[2] = -0.0001 * c25_j_x * (c25_b_qDot[0] + c25_b_qDot[1]);
  c25_C[1] = 0.0001 * c25_l_x * c25_b_qDot[0];
  c25_C[3] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 31);
  for (c25_i4 = 0; c25_i4 < 4; c25_i4++) {
    c25_D[c25_i4] = c25_dv0[c25_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 34);
  for (c25_i5 = 0; c25_i5 < 4; c25_i5++) {
    c25_Hp[c25_i5] = c25_dv1[c25_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 36);
  for (c25_i6 = 0; c25_i6 < 4; c25_i6++) {
    c25_Hd[c25_i6] = c25_dv2[c25_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 38);
  for (c25_i7 = 0; c25_i7 < 4; c25_i7++) {
    c25_Ki[c25_i7] = c25_dv3[c25_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 41);
  for (c25_i8 = 0; c25_i8 < 4; c25_i8++) {
    c25_Kp[c25_i8] = c25_dv1[c25_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 45);
  c25_Kd = 500.0;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 48);
  for (c25_i9 = 0; c25_i9 < 4; c25_i9++) {
    c25_b_C[c25_i9] = c25_C[c25_i9];
  }

  c25_A = 2.0 * c25_norm(chartInstance, c25_b_C);
  for (c25_i10 = 0; c25_i10 < 2; c25_i10++) {
    c25_c_qDot[c25_i10] = c25_b_qDot[c25_i10];
  }

  c25_B = c25_b_norm(chartInstance, c25_c_qDot);
  c25_kc = c25_rdivide(chartInstance, c25_A, c25_B);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 50);
  for (c25_i11 = 0; c25_i11 < 4; c25_i11++) {
    c25_b_M[c25_i11] = c25_M[c25_i11];
  }

  c25_eig(chartInstance, c25_b_M, c25_dcv0);
  for (c25_i12 = 0; c25_i12 < 2; c25_i12++) {
    c25_lambdaM[c25_i12] = c25_dcv0[c25_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 51);
  for (c25_i13 = 0; c25_i13 < 2; c25_i13++) {
    c25_lambdaHp[c25_i13].re = 5.8;
    c25_lambdaHp[c25_i13].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 52);
  for (c25_i14 = 0; c25_i14 < 2; c25_i14++) {
    c25_lambdaHd[c25_i14].re = 0.03;
    c25_lambdaHd[c25_i14].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 53);
  for (c25_i15 = 0; c25_i15 < 2; c25_i15++) {
    c25_lambdaKi[c25_i15].re = 1.0;
    c25_lambdaKi[c25_i15].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 55);
  for (c25_i16 = 0; c25_i16 < 2; c25_i16++) {
    c25_varargin_1[c25_i16] = c25_lambdaM[c25_i16];
  }

  c25_ixstart = 1;
  c25_mtmp = c25_varargin_1[0];
  c25_b0 = muDoubleScalarIsNaN(c25_mtmp.re);
  c25_b1 = muDoubleScalarIsNaN(c25_mtmp.im);
  c25_b = (c25_b0 || c25_b1);
  if (c25_b) {
    c25_eml_switch_helper(chartInstance);
    c25_eml_switch_helper(chartInstance);
    c25_ix = 2;
    exitg5 = false;
    while ((exitg5 == false) && (c25_ix < 3)) {
      c25_b_ix = c25_ix;
      c25_ixstart = c25_b_ix;
      c25_m_x.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 2, 1, 0) - 1].re;
      c25_m_x.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 2, 1, 0) - 1].im;
      c25_b2 = muDoubleScalarIsNaN(c25_m_x.re);
      c25_b3 = muDoubleScalarIsNaN(c25_m_x.im);
      c25_b_b = (c25_b2 || c25_b3);
      if (!c25_b_b) {
        c25_mtmp.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 2, 1, 0) - 1].re;
        c25_mtmp.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 2, 1, 0) - 1].im;
        exitg5 = true;
      } else {
        c25_ix++;
      }
    }
  }

  if (c25_ixstart < 2) {
    c25_a = c25_ixstart;
    c25_b_a = c25_a + 1;
    c25_i17 = c25_b_a;
    c25_c_a = c25_i17;
    c25_d_a = c25_c_a;
    if (c25_d_a > 2) {
      c25_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_overflow = false;
    }

    if (c25_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_overflow);
    }

    for (c25_c_ix = c25_i17; c25_c_ix < 3; c25_c_ix++) {
      c25_b_ix = c25_c_ix;
      c25_b_varargin_1.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 2, 1, 0) - 1].re;
      c25_b_varargin_1.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 2, 1, 0) - 1].im;
      if (c25_eml_relop(chartInstance, c25_b_varargin_1, c25_mtmp)) {
        c25_mtmp.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 2, 1, 0) - 1].re;
        c25_mtmp.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 2, 1, 0) - 1].im;
      }
    }
  }

  c25_m_x.re = c25_dc0.re * c25_mtmp.re - c25_dc0.im * c25_mtmp.im;
  c25_m_x.im = c25_dc0.re * c25_mtmp.im + c25_dc0.im * c25_mtmp.re;
  c25_b_B = 2.0 * c25_kc;
  c25_y = c25_b_B;
  c25_b_y = c25_y;
  c25_c_y = c25_b_y;
  c25_ar = c25_m_x.re;
  c25_ai = c25_m_x.im;
  c25_br = c25_c_y;
  c25_bi = 0.0;
  if (c25_bi == 0.0) {
    if (c25_ai == 0.0) {
      c25_kq.re = c25_ar / c25_br;
      c25_kq.im = 0.0;
    } else if (c25_ar == 0.0) {
      c25_kq.re = 0.0;
      c25_kq.im = c25_ai / c25_br;
    } else {
      c25_kq.re = c25_ar / c25_br;
      c25_kq.im = c25_ai / c25_br;
    }
  } else if (c25_br == 0.0) {
    if (c25_ar == 0.0) {
      c25_kq.re = c25_ai / c25_bi;
      c25_kq.im = 0.0;
    } else if (c25_ai == 0.0) {
      c25_kq.re = 0.0;
      c25_kq.im = -(c25_ar / c25_bi);
    } else {
      c25_kq.re = c25_ai / c25_bi;
      c25_kq.im = -(c25_ar / c25_bi);
    }
  } else {
    c25_brm = muDoubleScalarAbs(c25_br);
    c25_bim = muDoubleScalarAbs(c25_bi);
    if (c25_brm > c25_bim) {
      c25_s = c25_bi / c25_br;
      c25_d = c25_br + c25_s * c25_bi;
      c25_nr = c25_ar + c25_s * c25_ai;
      c25_ni = c25_ai - c25_s * c25_ar;
      c25_kq.re = c25_nr / c25_d;
      c25_kq.im = c25_ni / c25_d;
    } else if (c25_bim == c25_brm) {
      if (c25_br > 0.0) {
        c25_sgnbr = 0.5;
      } else {
        c25_sgnbr = -0.5;
      }

      if (c25_bi > 0.0) {
        c25_sgnbi = 0.5;
      } else {
        c25_sgnbi = -0.5;
      }

      c25_nr = c25_ar * c25_sgnbr + c25_ai * c25_sgnbi;
      c25_ni = c25_ai * c25_sgnbr - c25_ar * c25_sgnbi;
      c25_kq.re = c25_nr / c25_brm;
      c25_kq.im = c25_ni / c25_brm;
    } else {
      c25_s = c25_br / c25_bi;
      c25_d = c25_bi + c25_s * c25_br;
      c25_nr = c25_s * c25_ar + c25_ai;
      c25_ni = c25_s * c25_ai - c25_ar;
      c25_kq.re = c25_nr / c25_d;
      c25_kq.im = c25_ni / c25_d;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 57);
  for (c25_i18 = 0; c25_i18 < 4; c25_i18++) {
    c25_zero[c25_i18] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 58);
  for (c25_i19 = 0; c25_i19 < 4; c25_i19++) {
    c25_one[c25_i19] = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 59);
  c25_i20 = 0;
  for (c25_i21 = 0; c25_i21 < 2; c25_i21++) {
    for (c25_i22 = 0; c25_i22 < 2; c25_i22++) {
      c25_L1[c25_i22 + c25_i20] = c25_dv4[c25_i22 + c25_i20];
    }

    c25_i20 += 2;
  }

  c25_i23 = 0;
  for (c25_i24 = 0; c25_i24 < 2; c25_i24++) {
    for (c25_i25 = 0; c25_i25 < 2; c25_i25++) {
      c25_L1[(c25_i25 + c25_i23) + 4] = c25_M[c25_i25 + c25_i23];
    }

    c25_i23 += 2;
  }

  c25_i26 = 0;
  for (c25_i27 = 0; c25_i27 < 2; c25_i27++) {
    for (c25_i28 = 0; c25_i28 < 2; c25_i28++) {
      c25_L1[(c25_i28 + c25_i26) + 8] = 0.0;
    }

    c25_i26 += 2;
  }

  c25_i29 = 0;
  for (c25_i30 = 0; c25_i30 < 2; c25_i30++) {
    for (c25_i31 = 0; c25_i31 < 2; c25_i31++) {
      c25_L1[(c25_i31 + c25_i29) + 12] = 0.0;
    }

    c25_i29 += 2;
  }

  c25_i32 = 0;
  for (c25_i33 = 0; c25_i33 < 2; c25_i33++) {
    for (c25_i34 = 0; c25_i34 < 2; c25_i34++) {
      c25_L1[(c25_i34 + c25_i32) + 16] = -1.0;
    }

    c25_i32 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 60);
  c25_i35 = 0;
  for (c25_i36 = 0; c25_i36 < 2; c25_i36++) {
    for (c25_i37 = 0; c25_i37 < 2; c25_i37++) {
      c25_L2[c25_i37 + c25_i35] = c25_M[c25_i37 + c25_i35];
    }

    c25_i35 += 2;
  }

  c25_i38 = 0;
  for (c25_i39 = 0; c25_i39 < 2; c25_i39++) {
    for (c25_i40 = 0; c25_i40 < 2; c25_i40++) {
      c25_L2[(c25_i40 + c25_i38) + 4] = c25_M[c25_i40 + c25_i38];
    }

    c25_i38 += 2;
  }

  c25_i41 = 0;
  for (c25_i42 = 0; c25_i42 < 2; c25_i42++) {
    for (c25_i43 = 0; c25_i43 < 2; c25_i43++) {
      c25_L2[(c25_i43 + c25_i41) + 8] = 0.0;
    }

    c25_i41 += 2;
  }

  c25_i44 = 0;
  for (c25_i45 = 0; c25_i45 < 2; c25_i45++) {
    for (c25_i46 = 0; c25_i46 < 2; c25_i46++) {
      c25_L2[(c25_i46 + c25_i44) + 12] = 0.0;
    }

    c25_i44 += 2;
  }

  c25_i47 = 0;
  for (c25_i48 = 0; c25_i48 < 2; c25_i48++) {
    for (c25_i49 = 0; c25_i49 < 2; c25_i49++) {
      c25_L2[(c25_i49 + c25_i47) + 16] = 0.0;
    }

    c25_i47 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 61);
  for (c25_i50 = 0; c25_i50 < 20; c25_i50++) {
    c25_L3[c25_i50] = c25_dv5[c25_i50];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 62);
  c25_i51 = 0;
  for (c25_i52 = 0; c25_i52 < 2; c25_i52++) {
    for (c25_i53 = 0; c25_i53 < 2; c25_i53++) {
      c25_L4[c25_i53 + c25_i51] = 0.0;
    }

    c25_i51 += 2;
  }

  c25_i54 = 0;
  for (c25_i55 = 0; c25_i55 < 2; c25_i55++) {
    for (c25_i56 = 0; c25_i56 < 2; c25_i56++) {
      c25_L4[(c25_i56 + c25_i54) + 4] = 0.0;
    }

    c25_i54 += 2;
  }

  c25_i57 = 0;
  for (c25_i58 = 0; c25_i58 < 2; c25_i58++) {
    for (c25_i59 = 0; c25_i59 < 2; c25_i59++) {
      c25_L4[(c25_i59 + c25_i57) + 8] = 0.0;
    }

    c25_i57 += 2;
  }

  c25_i60 = 0;
  for (c25_i61 = 0; c25_i61 < 2; c25_i61++) {
    for (c25_i62 = 0; c25_i62 < 2; c25_i62++) {
      c25_L4[(c25_i62 + c25_i60) + 12] = c25_M[c25_i62 + c25_i60];
    }

    c25_i60 += 2;
  }

  c25_i63 = 0;
  for (c25_i64 = 0; c25_i64 < 2; c25_i64++) {
    for (c25_i65 = 0; c25_i65 < 2; c25_i65++) {
      c25_L4[(c25_i65 + c25_i63) + 16] = 0.0;
    }

    c25_i63 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 63);
  for (c25_i66 = 0; c25_i66 < 4; c25_i66++) {
    c25_dv6[c25_i66] = c25_dv3[c25_i66];
  }

  c25_inv(chartInstance, c25_dv6, c25_dv7);
  c25_i67 = 0;
  for (c25_i68 = 0; c25_i68 < 2; c25_i68++) {
    for (c25_i69 = 0; c25_i69 < 2; c25_i69++) {
      c25_L5[c25_i69 + c25_i67] = -1.0;
    }

    c25_i67 += 2;
  }

  c25_i70 = 0;
  for (c25_i71 = 0; c25_i71 < 2; c25_i71++) {
    for (c25_i72 = 0; c25_i72 < 2; c25_i72++) {
      c25_L5[(c25_i72 + c25_i70) + 4] = 0.0;
    }

    c25_i70 += 2;
  }

  c25_i73 = 0;
  for (c25_i74 = 0; c25_i74 < 2; c25_i74++) {
    for (c25_i75 = 0; c25_i75 < 2; c25_i75++) {
      c25_L5[(c25_i75 + c25_i73) + 8] = 0.0;
    }

    c25_i73 += 2;
  }

  c25_i76 = 0;
  for (c25_i77 = 0; c25_i77 < 2; c25_i77++) {
    for (c25_i78 = 0; c25_i78 < 2; c25_i78++) {
      c25_L5[(c25_i78 + c25_i76) + 12] = 0.0;
    }

    c25_i76 += 2;
  }

  c25_i79 = 0;
  for (c25_i80 = 0; c25_i80 < 2; c25_i80++) {
    for (c25_i81 = 0; c25_i81 < 2; c25_i81++) {
      c25_L5[(c25_i81 + c25_i79) + 16] = c25_dv7[c25_i81 + c25_i79];
    }

    c25_i79 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 64);
  c25_i82 = 0;
  c25_i83 = 0;
  for (c25_i84 = 0; c25_i84 < 10; c25_i84++) {
    for (c25_i85 = 0; c25_i85 < 2; c25_i85++) {
      c25_L[c25_i85 + c25_i82] = c25_L1[c25_i85 + c25_i83];
    }

    c25_i82 += 10;
    c25_i83 += 2;
  }

  c25_i86 = 0;
  c25_i87 = 0;
  for (c25_i88 = 0; c25_i88 < 10; c25_i88++) {
    for (c25_i89 = 0; c25_i89 < 2; c25_i89++) {
      c25_L[(c25_i89 + c25_i86) + 2] = c25_L2[c25_i89 + c25_i87];
    }

    c25_i86 += 10;
    c25_i87 += 2;
  }

  c25_i90 = 0;
  c25_i91 = 0;
  for (c25_i92 = 0; c25_i92 < 10; c25_i92++) {
    for (c25_i93 = 0; c25_i93 < 2; c25_i93++) {
      c25_L[(c25_i93 + c25_i90) + 4] = c25_dv5[c25_i93 + c25_i91];
    }

    c25_i90 += 10;
    c25_i91 += 2;
  }

  c25_i94 = 0;
  c25_i95 = 0;
  for (c25_i96 = 0; c25_i96 < 10; c25_i96++) {
    for (c25_i97 = 0; c25_i97 < 2; c25_i97++) {
      c25_L[(c25_i97 + c25_i94) + 6] = c25_L4[c25_i97 + c25_i95];
    }

    c25_i94 += 10;
    c25_i95 += 2;
  }

  c25_i98 = 0;
  c25_i99 = 0;
  for (c25_i100 = 0; c25_i100 < 10; c25_i100++) {
    for (c25_i101 = 0; c25_i101 < 2; c25_i101++) {
      c25_L[(c25_i101 + c25_i98) + 8] = c25_L5[c25_i101 + c25_i99];
    }

    c25_i98 += 10;
    c25_i99 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 66);
  for (c25_i102 = 0; c25_i102 < 100; c25_i102++) {
    c25_b_L[c25_i102] = c25_L[c25_i102];
  }

  c25_b_eig(chartInstance, c25_b_L, c25_dcv1);
  for (c25_i103 = 0; c25_i103 < 10; c25_i103++) {
    c25_lambdaL[c25_i103] = c25_dcv1[c25_i103];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 67);
  for (c25_i104 = 0; c25_i104 < 2; c25_i104++) {
    c25_lambdaD[c25_i104].re = 0.01;
    c25_lambdaD[c25_i104].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 69);
  c25_c_B = 2.0 * c25_kc;
  c25_d_y = c25_rdivide(chartInstance, 1.0, c25_c_B);
  for (c25_i105 = 0; c25_i105 < 10; c25_i105++) {
    c25_c_varargin_1[c25_i105] = c25_lambdaL[c25_i105];
  }

  c25_b_ixstart = 1;
  c25_mtmp = c25_c_varargin_1[0];
  c25_b4 = muDoubleScalarIsNaN(c25_mtmp.re);
  c25_b5 = muDoubleScalarIsNaN(c25_mtmp.im);
  c25_c_b = (c25_b4 || c25_b5);
  if (c25_c_b) {
    c25_eml_switch_helper(chartInstance);
    c25_eml_switch_helper(chartInstance);
    c25_d_ix = 2;
    exitg4 = false;
    while ((exitg4 == false) && (c25_d_ix < 11)) {
      c25_e_ix = c25_d_ix;
      c25_b_ixstart = c25_e_ix;
      c25_m_x.re = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_e_ix), 1, 10, 1, 0) - 1].re;
      c25_m_x.im = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_e_ix), 1, 10, 1, 0) - 1].im;
      c25_b6 = muDoubleScalarIsNaN(c25_m_x.re);
      c25_b7 = muDoubleScalarIsNaN(c25_m_x.im);
      c25_d_b = (c25_b6 || c25_b7);
      if (!c25_d_b) {
        c25_mtmp.re = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_e_ix), 1, 10, 1, 0) - 1].re;
        c25_mtmp.im = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_e_ix), 1, 10, 1, 0) - 1].im;
        exitg4 = true;
      } else {
        c25_d_ix++;
      }
    }
  }

  if (c25_b_ixstart < 10) {
    c25_e_a = c25_b_ixstart;
    c25_f_a = c25_e_a + 1;
    c25_i106 = c25_f_a;
    c25_g_a = c25_i106;
    c25_h_a = c25_g_a;
    if (c25_h_a > 10) {
      c25_b_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_b_overflow = false;
    }

    if (c25_b_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
    }

    for (c25_f_ix = c25_i106; c25_f_ix < 11; c25_f_ix++) {
      c25_e_ix = c25_f_ix;
      c25_d_varargin_1.re = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_ix), 1, 10, 1, 0) - 1].re;
      c25_d_varargin_1.im = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_ix), 1, 10, 1, 0) - 1].im;
      if (c25_eml_relop(chartInstance, c25_d_varargin_1, c25_mtmp)) {
        c25_mtmp.re = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_e_ix), 1, 10, 1, 0) - 1].re;
        c25_mtmp.im = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_e_ix), 1, 10, 1, 0) - 1].im;
      }
    }
  }

  for (c25_i107 = 0; c25_i107 < 10; c25_i107++) {
    c25_c_varargin_1[c25_i107] = c25_lambdaL[c25_i107];
  }

  c25_c_ixstart = 1;
  c25_b_mtmp = c25_c_varargin_1[0];
  c25_b8 = muDoubleScalarIsNaN(c25_b_mtmp.re);
  c25_b9 = muDoubleScalarIsNaN(c25_b_mtmp.im);
  c25_e_b = (c25_b8 || c25_b9);
  if (c25_e_b) {
    c25_eml_switch_helper(chartInstance);
    c25_eml_switch_helper(chartInstance);
    c25_g_ix = 2;
    exitg3 = false;
    while ((exitg3 == false) && (c25_g_ix < 11)) {
      c25_h_ix = c25_g_ix;
      c25_c_ixstart = c25_h_ix;
      c25_m_x.re = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_h_ix), 1, 10, 1, 0) - 1].re;
      c25_m_x.im = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_h_ix), 1, 10, 1, 0) - 1].im;
      c25_b10 = muDoubleScalarIsNaN(c25_m_x.re);
      c25_b11 = muDoubleScalarIsNaN(c25_m_x.im);
      c25_f_b = (c25_b10 || c25_b11);
      if (!c25_f_b) {
        c25_b_mtmp.re = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_h_ix), 1, 10, 1, 0) - 1].
          re;
        c25_b_mtmp.im = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_h_ix), 1, 10, 1, 0) - 1].
          im;
        exitg3 = true;
      } else {
        c25_g_ix++;
      }
    }
  }

  if (c25_c_ixstart < 10) {
    c25_i_a = c25_c_ixstart;
    c25_j_a = c25_i_a + 1;
    c25_i108 = c25_j_a;
    c25_k_a = c25_i108;
    c25_l_a = c25_k_a;
    if (c25_l_a > 10) {
      c25_c_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_c_overflow = false;
    }

    if (c25_c_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_c_overflow);
    }

    for (c25_i_ix = c25_i108; c25_i_ix < 11; c25_i_ix++) {
      c25_h_ix = c25_i_ix;
      c25_e_varargin_1.re = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_h_ix), 1, 10, 1, 0) - 1].re;
      c25_e_varargin_1.im = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_h_ix), 1, 10, 1, 0) - 1].im;
      if (c25_b_eml_relop(chartInstance, c25_e_varargin_1, c25_b_mtmp)) {
        c25_b_mtmp.re = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_h_ix), 1, 10, 1, 0) - 1].
          re;
        c25_b_mtmp.im = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_h_ix), 1, 10, 1, 0) - 1].
          im;
      }
    }
  }

  c25_b_ar = c25_mtmp.re;
  c25_b_ai = c25_mtmp.im;
  c25_b_br = c25_b_mtmp.re;
  c25_b_bi = c25_b_mtmp.im;
  if (c25_b_bi == 0.0) {
    if (c25_b_ai == 0.0) {
      c25_e_y.re = c25_b_ar / c25_b_br;
      c25_e_y.im = 0.0;
    } else if (c25_b_ar == 0.0) {
      c25_e_y.re = 0.0;
      c25_e_y.im = c25_b_ai / c25_b_br;
    } else {
      c25_e_y.re = c25_b_ar / c25_b_br;
      c25_e_y.im = c25_b_ai / c25_b_br;
    }
  } else if (c25_b_br == 0.0) {
    if (c25_b_ar == 0.0) {
      c25_e_y.re = c25_b_ai / c25_b_bi;
      c25_e_y.im = 0.0;
    } else if (c25_b_ai == 0.0) {
      c25_e_y.re = 0.0;
      c25_e_y.im = -(c25_b_ar / c25_b_bi);
    } else {
      c25_e_y.re = c25_b_ai / c25_b_bi;
      c25_e_y.im = -(c25_b_ar / c25_b_bi);
    }
  } else {
    c25_b_brm = muDoubleScalarAbs(c25_b_br);
    c25_b_bim = muDoubleScalarAbs(c25_b_bi);
    if (c25_b_brm > c25_b_bim) {
      c25_b_s = c25_b_bi / c25_b_br;
      c25_b_d = c25_b_br + c25_b_s * c25_b_bi;
      c25_b_nr = c25_b_ar + c25_b_s * c25_b_ai;
      c25_b_ni = c25_b_ai - c25_b_s * c25_b_ar;
      c25_e_y.re = c25_b_nr / c25_b_d;
      c25_e_y.im = c25_b_ni / c25_b_d;
    } else if (c25_b_bim == c25_b_brm) {
      if (c25_b_br > 0.0) {
        c25_b_sgnbr = 0.5;
      } else {
        c25_b_sgnbr = -0.5;
      }

      if (c25_b_bi > 0.0) {
        c25_b_sgnbi = 0.5;
      } else {
        c25_b_sgnbi = -0.5;
      }

      c25_b_nr = c25_b_ar * c25_b_sgnbr + c25_b_ai * c25_b_sgnbi;
      c25_b_ni = c25_b_ai * c25_b_sgnbr - c25_b_ar * c25_b_sgnbi;
      c25_e_y.re = c25_b_nr / c25_b_brm;
      c25_e_y.im = c25_b_ni / c25_b_brm;
    } else {
      c25_b_s = c25_b_br / c25_b_bi;
      c25_b_d = c25_b_bi + c25_b_s * c25_b_br;
      c25_b_nr = c25_b_s * c25_b_ar + c25_b_ai;
      c25_b_ni = c25_b_s * c25_b_ai - c25_b_ar;
      c25_e_y.re = c25_b_nr / c25_b_d;
      c25_e_y.im = c25_b_ni / c25_b_d;
    }
  }

  c25_m_a = c25_d_y;
  c25_d_sqrt(chartInstance, &c25_e_y);
  c25_e_y.re *= c25_m_a;
  c25_e_y.im *= c25_m_a;
  for (c25_i109 = 0; c25_i109 < 2; c25_i109++) {
    c25_varargin_1[c25_i109] = c25_lambdaM[c25_i109];
  }

  c25_d_ixstart = 1;
  c25_mtmp = c25_varargin_1[0];
  c25_b12 = muDoubleScalarIsNaN(c25_mtmp.re);
  c25_b13 = muDoubleScalarIsNaN(c25_mtmp.im);
  c25_g_b = (c25_b12 || c25_b13);
  if (c25_g_b) {
    c25_eml_switch_helper(chartInstance);
    c25_eml_switch_helper(chartInstance);
    c25_j_ix = 2;
    exitg2 = false;
    while ((exitg2 == false) && (c25_j_ix < 3)) {
      c25_k_ix = c25_j_ix;
      c25_d_ixstart = c25_k_ix;
      c25_m_x.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_k_ix), 1, 2, 1, 0) - 1].re;
      c25_m_x.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_k_ix), 1, 2, 1, 0) - 1].im;
      c25_b14 = muDoubleScalarIsNaN(c25_m_x.re);
      c25_b15 = muDoubleScalarIsNaN(c25_m_x.im);
      c25_h_b = (c25_b14 || c25_b15);
      if (!c25_h_b) {
        c25_mtmp.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_k_ix), 1, 2, 1, 0) - 1].re;
        c25_mtmp.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_k_ix), 1, 2, 1, 0) - 1].im;
        exitg2 = true;
      } else {
        c25_j_ix++;
      }
    }
  }

  if (c25_d_ixstart < 2) {
    c25_n_a = c25_d_ixstart;
    c25_o_a = c25_n_a + 1;
    c25_i110 = c25_o_a;
    c25_p_a = c25_i110;
    c25_q_a = c25_p_a;
    if (c25_q_a > 2) {
      c25_d_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_d_overflow = false;
    }

    if (c25_d_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_d_overflow);
    }

    for (c25_l_ix = c25_i110; c25_l_ix < 3; c25_l_ix++) {
      c25_k_ix = c25_l_ix;
      c25_f_varargin_1.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_k_ix), 1, 2, 1, 0) - 1].re;
      c25_f_varargin_1.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_k_ix), 1, 2, 1, 0) - 1].im;
      if (c25_eml_relop(chartInstance, c25_f_varargin_1, c25_mtmp)) {
        c25_mtmp.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_k_ix), 1, 2, 1, 0) - 1].re;
        c25_mtmp.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_k_ix), 1, 2, 1, 0) - 1].im;
      }
    }
  }

  c25_f_y.re = 500.0 * c25_mtmp.re;
  c25_f_y.im = 500.0 * c25_mtmp.im;
  c25_mtmp = c25_dc1;
  c25_eml_switch_helper(chartInstance);
  c25_eml_switch_helper(chartInstance);
  for (c25_m_ix = 2; c25_m_ix < 3; c25_m_ix++) {
    c25_n_ix = c25_m_ix;
    c25_o_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c25_n_ix), 1, 2, 1, 0) - 1;
    c25_dc2.re = 0.01;
    c25_dc2.im = 0.0;
    if (c25_eml_relop(chartInstance, c25_dc2, c25_mtmp)) {
      c25_p_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c25_n_ix), 1, 2, 1, 0) - 1;
      c25_mtmp.re = 0.01;
      c25_mtmp.im = 0.0;
    }
  }

  c25_b_mtmp = c25_dc1;
  c25_eml_switch_helper(chartInstance);
  c25_eml_switch_helper(chartInstance);
  for (c25_q_ix = 2; c25_q_ix < 3; c25_q_ix++) {
    c25_r_ix = c25_q_ix;
    c25_s_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c25_r_ix), 1, 2, 1, 0) - 1;
    c25_dc3.re = 0.01;
    c25_dc3.im = 0.0;
    if (c25_eml_relop(chartInstance, c25_dc3, c25_b_mtmp)) {
      c25_t_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c25_r_ix), 1, 2, 1, 0) - 1;
      c25_b_mtmp.re = 0.01;
      c25_b_mtmp.im = 0.0;
    }
  }

  c25_c_mtmp = c25_dc0;
  c25_eml_switch_helper(chartInstance);
  c25_eml_switch_helper(chartInstance);
  for (c25_u_ix = 2; c25_u_ix < 3; c25_u_ix++) {
    c25_v_ix = c25_u_ix;
    c25_w_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c25_v_ix), 1, 2, 1, 0) - 1;
    c25_dc4.re = 0.03;
    c25_dc4.im = 0.0;
    if (c25_eml_relop(chartInstance, c25_dc4, c25_c_mtmp)) {
      c25_x_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c25_v_ix), 1, 2, 1, 0) - 1;
      c25_c_mtmp.re = 0.03;
      c25_c_mtmp.im = 0.0;
    }
  }

  for (c25_i111 = 0; c25_i111 < 2; c25_i111++) {
    c25_varargin_1[c25_i111] = c25_lambdaM[c25_i111];
  }

  c25_e_ixstart = 1;
  c25_d_mtmp = c25_varargin_1[0];
  c25_b16 = muDoubleScalarIsNaN(c25_d_mtmp.re);
  c25_b17 = muDoubleScalarIsNaN(c25_d_mtmp.im);
  c25_i_b = (c25_b16 || c25_b17);
  if (c25_i_b) {
    c25_eml_switch_helper(chartInstance);
    c25_eml_switch_helper(chartInstance);
    c25_y_ix = 2;
    exitg1 = false;
    while ((exitg1 == false) && (c25_y_ix < 3)) {
      c25_ab_ix = c25_y_ix;
      c25_e_ixstart = c25_ab_ix;
      c25_m_x.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_ab_ix), 1, 2, 1, 0) - 1].re;
      c25_m_x.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_ab_ix), 1, 2, 1, 0) - 1].im;
      c25_b18 = muDoubleScalarIsNaN(c25_m_x.re);
      c25_b19 = muDoubleScalarIsNaN(c25_m_x.im);
      c25_j_b = (c25_b18 || c25_b19);
      if (!c25_j_b) {
        c25_d_mtmp.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_ab_ix), 1, 2, 1, 0) - 1].re;
        c25_d_mtmp.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_ab_ix), 1, 2, 1, 0) - 1].im;
        exitg1 = true;
      } else {
        c25_y_ix++;
      }
    }
  }

  if (c25_e_ixstart < 2) {
    c25_r_a = c25_e_ixstart;
    c25_s_a = c25_r_a + 1;
    c25_i112 = c25_s_a;
    c25_t_a = c25_i112;
    c25_u_a = c25_t_a;
    if (c25_u_a > 2) {
      c25_e_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_e_overflow = false;
    }

    if (c25_e_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_e_overflow);
    }

    for (c25_bb_ix = c25_i112; c25_bb_ix < 3; c25_bb_ix++) {
      c25_ab_ix = c25_bb_ix;
      c25_g_varargin_1.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ab_ix), 1, 2, 1, 0) - 1].re;
      c25_g_varargin_1.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ab_ix), 1, 2, 1, 0) - 1].im;
      if (c25_eml_relop(chartInstance, c25_g_varargin_1, c25_d_mtmp)) {
        c25_d_mtmp.re = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_ab_ix), 1, 2, 1, 0) - 1].re;
        c25_d_mtmp.im = c25_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_ab_ix), 1, 2, 1, 0) - 1].im;
      }
    }
  }

  c25_m_x.re = ((c25_b_mtmp.re + c25_c_mtmp.re) - c25_d_mtmp.re) - c25_kc *
    c25_b_qTilde;
  c25_m_x.im = (c25_b_mtmp.im + c25_c_mtmp.im) - c25_d_mtmp.im;
  c25_n_x = c25_m_x;
  c25_c_ar = c25_dc5.re;
  c25_c_ai = c25_dc5.im;
  c25_c_br = c25_n_x.re;
  c25_c_bi = c25_n_x.im;
  if (c25_c_bi == 0.0) {
    if (c25_c_ai == 0.0) {
      c25_m_x.re = c25_c_ar / c25_c_br;
      c25_m_x.im = 0.0;
    } else if (c25_c_ar == 0.0) {
      c25_m_x.re = 0.0;
      c25_m_x.im = c25_c_ai / c25_c_br;
    } else {
      c25_m_x.re = c25_c_ar / c25_c_br;
      c25_m_x.im = c25_c_ai / c25_c_br;
    }
  } else if (c25_c_br == 0.0) {
    if (c25_c_ar == 0.0) {
      c25_m_x.re = c25_c_ai / c25_c_bi;
      c25_m_x.im = 0.0;
    } else if (c25_c_ai == 0.0) {
      c25_m_x.re = 0.0;
      c25_m_x.im = -(c25_c_ar / c25_c_bi);
    } else {
      c25_m_x.re = c25_c_ai / c25_c_bi;
      c25_m_x.im = -(c25_c_ar / c25_c_bi);
    }
  } else {
    c25_c_brm = muDoubleScalarAbs(c25_c_br);
    c25_c_bim = muDoubleScalarAbs(c25_c_bi);
    if (c25_c_brm > c25_c_bim) {
      c25_c_s = c25_c_bi / c25_c_br;
      c25_c_d = c25_c_br + c25_c_s * c25_c_bi;
      c25_c_nr = c25_c_ar + c25_c_s * c25_c_ai;
      c25_c_ni = c25_c_ai - c25_c_s * c25_c_ar;
      c25_m_x.re = c25_c_nr / c25_c_d;
      c25_m_x.im = c25_c_ni / c25_c_d;
    } else if (c25_c_bim == c25_c_brm) {
      if (c25_c_br > 0.0) {
        c25_c_sgnbr = 0.5;
      } else {
        c25_c_sgnbr = -0.5;
      }

      if (c25_c_bi > 0.0) {
        c25_c_sgnbi = 0.5;
      } else {
        c25_c_sgnbi = -0.5;
      }

      c25_c_nr = c25_c_ar * c25_c_sgnbr + c25_c_ai * c25_c_sgnbi;
      c25_c_ni = c25_c_ai * c25_c_sgnbr - c25_c_ar * c25_c_sgnbi;
      c25_m_x.re = c25_c_nr / c25_c_brm;
      c25_m_x.im = c25_c_ni / c25_c_brm;
    } else {
      c25_c_s = c25_c_br / c25_c_bi;
      c25_c_d = c25_c_bi + c25_c_s * c25_c_br;
      c25_c_nr = c25_c_s * c25_c_ar + c25_c_ai;
      c25_c_ni = c25_c_s * c25_c_ai - c25_c_ar;
      c25_m_x.re = c25_c_nr / c25_c_d;
      c25_m_x.im = c25_c_ni / c25_c_d;
    }
  }

  c25_d_ar = c25_dc5.re;
  c25_d_ai = c25_dc5.im;
  c25_d_br = c25_dc6.re;
  c25_d_bi = c25_dc6.im;
  if (c25_d_bi == 0.0) {
    if (c25_d_ai == 0.0) {
      c25_b_mtmp.re = c25_d_ar / c25_d_br;
      c25_b_mtmp.im = 0.0;
    } else if (c25_d_ar == 0.0) {
      c25_b_mtmp.re = 0.0;
      c25_b_mtmp.im = c25_d_ai / c25_d_br;
    } else {
      c25_b_mtmp.re = c25_d_ar / c25_d_br;
      c25_b_mtmp.im = c25_d_ai / c25_d_br;
    }
  } else if (c25_d_br == 0.0) {
    if (c25_d_ar == 0.0) {
      c25_b_mtmp.re = c25_d_ai / c25_d_bi;
      c25_b_mtmp.im = 0.0;
    } else if (c25_d_ai == 0.0) {
      c25_b_mtmp.re = 0.0;
      c25_b_mtmp.im = -(c25_d_ar / c25_d_bi);
    } else {
      c25_b_mtmp.re = c25_d_ai / c25_d_bi;
      c25_b_mtmp.im = -(c25_d_ar / c25_d_bi);
    }
  } else {
    c25_d_brm = muDoubleScalarAbs(c25_d_br);
    c25_d_bim = muDoubleScalarAbs(c25_d_bi);
    if (c25_d_brm > c25_d_bim) {
      c25_d_s = c25_d_bi / c25_d_br;
      c25_d_d = c25_d_br + c25_d_s * c25_d_bi;
      c25_d_nr = c25_d_ar + c25_d_s * c25_d_ai;
      c25_d_ni = c25_d_ai - c25_d_s * c25_d_ar;
      c25_b_mtmp.re = c25_d_nr / c25_d_d;
      c25_b_mtmp.im = c25_d_ni / c25_d_d;
    } else if (c25_d_bim == c25_d_brm) {
      if (c25_d_br > 0.0) {
        c25_d_sgnbr = 0.5;
      } else {
        c25_d_sgnbr = -0.5;
      }

      if (c25_d_bi > 0.0) {
        c25_d_sgnbi = 0.5;
      } else {
        c25_d_sgnbi = -0.5;
      }

      c25_d_nr = c25_d_ar * c25_d_sgnbr + c25_d_ai * c25_d_sgnbi;
      c25_d_ni = c25_d_ai * c25_d_sgnbr - c25_d_ar * c25_d_sgnbi;
      c25_b_mtmp.re = c25_d_nr / c25_d_brm;
      c25_b_mtmp.im = c25_d_ni / c25_d_brm;
    } else {
      c25_d_s = c25_d_br / c25_d_bi;
      c25_d_d = c25_d_bi + c25_d_s * c25_d_br;
      c25_d_nr = c25_d_s * c25_d_ar + c25_d_ai;
      c25_d_ni = c25_d_s * c25_d_ai - c25_d_ar;
      c25_b_mtmp.re = c25_d_nr / c25_d_d;
      c25_b_mtmp.im = c25_d_ni / c25_d_d;
    }
  }

  c25_o_x.re = c25_m_x.re + c25_b_mtmp.re;
  c25_o_x.im = c25_m_x.im + c25_b_mtmp.im;
  c25_dc8.re = c25_dc7.re * c25_o_x.re - c25_dc7.im * c25_o_x.im;
  c25_dc8.im = c25_dc7.re * c25_o_x.im + c25_dc7.im * c25_o_x.re;
  c25_g_y.re = (c25_f_y.re + c25_mtmp.re) - c25_dc8.re;
  c25_g_y.im = (c25_f_y.im + c25_mtmp.im) - c25_dc8.im;
  c25_b_rGAC.re = c25_e_y.re * c25_g_y.re - c25_e_y.im * c25_g_y.im;
  c25_b_rGAC.im = c25_e_y.re * c25_g_y.im + c25_e_y.im * c25_g_y.re;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -69);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c25_rGAC = c25_b_rGAC;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c25_sfEvent);
}

static void initSimStructsc25_hybridSysSim(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber)
{
  (void)c25_machineNumber;
  (void)c25_chartNumber;
  (void)c25_instanceNumber;
}

static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  creal_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(creal_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static creal_T c25_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_b_rGAC, const char_T *c25_identifier)
{
  creal_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_rGAC),
    &c25_thisId);
  sf_mex_destroy(&c25_b_rGAC);
  return c25_y;
}

static creal_T c25_b_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  creal_T c25_y;
  creal_T c25_dc9;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_dc9, 1, 0, 1U, 0, 0U, 0);
  c25_y = c25_dc9;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_rGAC;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  creal_T c25_y;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_b_rGAC = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_rGAC),
    &c25_thisId);
  sf_mex_destroy(&c25_b_rGAC);
  *(creal_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_c_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i113;
  real_T c25_b_inData[2];
  int32_T c25_i114;
  real_T c25_u[2];
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i113 = 0; c25_i113 < 2; c25_i113++) {
    c25_b_inData[c25_i113] = (*(real_T (*)[2])c25_inData)[c25_i113];
  }

  for (c25_i114 = 0; c25_i114 < 2; c25_i114++) {
    c25_u[c25_i114] = c25_b_inData[c25_i114];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_d_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i115;
  real_T c25_b_inData[2];
  int32_T c25_i116;
  real_T c25_u[2];
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i115 = 0; c25_i115 < 2; c25_i115++) {
    c25_b_inData[c25_i115] = (*(real_T (*)[2])c25_inData)[c25_i115];
  }

  for (c25_i116 = 0; c25_i116 < 2; c25_i116++) {
    c25_u[c25_i116] = c25_b_inData[c25_i116];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_c_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d0, 1, 0, 0U, 0, 0U, 0);
  c25_y = c25_d0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_nargout;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_nargout = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_nargout),
    &c25_thisId);
  sf_mex_destroy(&c25_nargout);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_e_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i117;
  creal_T c25_b_inData[2];
  int32_T c25_i118;
  creal_T c25_u[2];
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i117 = 0; c25_i117 < 2; c25_i117++) {
    c25_b_inData[c25_i117] = (*(creal_T (*)[2])c25_inData)[c25_i117];
  }

  for (c25_i118 = 0; c25_i118 < 2; c25_i118++) {
    c25_u[c25_i118] = c25_b_inData[c25_i118];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 1U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_f_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i119;
  creal_T c25_b_inData[10];
  int32_T c25_i120;
  creal_T c25_u[10];
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i119 = 0; c25_i119 < 10; c25_i119++) {
    c25_b_inData[c25_i119] = (*(creal_T (*)[10])c25_inData)[c25_i119];
  }

  for (c25_i120 = 0; c25_i120 < 10; c25_i120++) {
    c25_u[c25_i120] = c25_b_inData[c25_i120];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 1U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_d_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  creal_T c25_y[10])
{
  creal_T c25_dcv2[10];
  int32_T c25_i121;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dcv2, 1, 0, 1U, 1, 0U, 1,
                10);
  for (c25_i121 = 0; c25_i121 < 10; c25_i121++) {
    c25_y[c25_i121] = c25_dcv2[c25_i121];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_lambdaL;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  creal_T c25_y[10];
  int32_T c25_i122;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_lambdaL = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_lambdaL), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_lambdaL);
  for (c25_i122 = 0; c25_i122 < 10; c25_i122++) {
    (*(creal_T (*)[10])c25_outData)[c25_i122] = c25_y[c25_i122];
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_g_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i123;
  int32_T c25_i124;
  int32_T c25_i125;
  real_T c25_b_inData[100];
  int32_T c25_i126;
  int32_T c25_i127;
  int32_T c25_i128;
  real_T c25_u[100];
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_i123 = 0;
  for (c25_i124 = 0; c25_i124 < 10; c25_i124++) {
    for (c25_i125 = 0; c25_i125 < 10; c25_i125++) {
      c25_b_inData[c25_i125 + c25_i123] = (*(real_T (*)[100])c25_inData)
        [c25_i125 + c25_i123];
    }

    c25_i123 += 10;
  }

  c25_i126 = 0;
  for (c25_i127 = 0; c25_i127 < 10; c25_i127++) {
    for (c25_i128 = 0; c25_i128 < 10; c25_i128++) {
      c25_u[c25_i128 + c25_i126] = c25_b_inData[c25_i128 + c25_i126];
    }

    c25_i126 += 10;
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 2, 10, 10),
                false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_e_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[100])
{
  real_T c25_dv8[100];
  int32_T c25_i129;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv8, 1, 0, 0U, 1, 0U, 2, 10,
                10);
  for (c25_i129 = 0; c25_i129 < 100; c25_i129++) {
    c25_y[c25_i129] = c25_dv8[c25_i129];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_L;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y[100];
  int32_T c25_i130;
  int32_T c25_i131;
  int32_T c25_i132;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_L = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_L), &c25_thisId, c25_y);
  sf_mex_destroy(&c25_L);
  c25_i130 = 0;
  for (c25_i131 = 0; c25_i131 < 10; c25_i131++) {
    for (c25_i132 = 0; c25_i132 < 10; c25_i132++) {
      (*(real_T (*)[100])c25_outData)[c25_i132 + c25_i130] = c25_y[c25_i132 +
        c25_i130];
    }

    c25_i130 += 10;
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_h_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i133;
  int32_T c25_i134;
  int32_T c25_i135;
  real_T c25_b_inData[20];
  int32_T c25_i136;
  int32_T c25_i137;
  int32_T c25_i138;
  real_T c25_u[20];
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_i133 = 0;
  for (c25_i134 = 0; c25_i134 < 10; c25_i134++) {
    for (c25_i135 = 0; c25_i135 < 2; c25_i135++) {
      c25_b_inData[c25_i135 + c25_i133] = (*(real_T (*)[20])c25_inData)[c25_i135
        + c25_i133];
    }

    c25_i133 += 2;
  }

  c25_i136 = 0;
  for (c25_i137 = 0; c25_i137 < 10; c25_i137++) {
    for (c25_i138 = 0; c25_i138 < 2; c25_i138++) {
      c25_u[c25_i138 + c25_i136] = c25_b_inData[c25_i138 + c25_i136];
    }

    c25_i136 += 2;
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 2, 2, 10),
                false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_f_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[20])
{
  real_T c25_dv9[20];
  int32_T c25_i139;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv9, 1, 0, 0U, 1, 0U, 2, 2,
                10);
  for (c25_i139 = 0; c25_i139 < 20; c25_i139++) {
    c25_y[c25_i139] = c25_dv9[c25_i139];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_L5;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y[20];
  int32_T c25_i140;
  int32_T c25_i141;
  int32_T c25_i142;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_L5 = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_L5), &c25_thisId, c25_y);
  sf_mex_destroy(&c25_L5);
  c25_i140 = 0;
  for (c25_i141 = 0; c25_i141 < 10; c25_i141++) {
    for (c25_i142 = 0; c25_i142 < 2; c25_i142++) {
      (*(real_T (*)[20])c25_outData)[c25_i142 + c25_i140] = c25_y[c25_i142 +
        c25_i140];
    }

    c25_i140 += 2;
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_i_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i143;
  int32_T c25_i144;
  int32_T c25_i145;
  real_T c25_b_inData[4];
  int32_T c25_i146;
  int32_T c25_i147;
  int32_T c25_i148;
  real_T c25_u[4];
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_i143 = 0;
  for (c25_i144 = 0; c25_i144 < 2; c25_i144++) {
    for (c25_i145 = 0; c25_i145 < 2; c25_i145++) {
      c25_b_inData[c25_i145 + c25_i143] = (*(real_T (*)[4])c25_inData)[c25_i145
        + c25_i143];
    }

    c25_i143 += 2;
  }

  c25_i146 = 0;
  for (c25_i147 = 0; c25_i147 < 2; c25_i147++) {
    for (c25_i148 = 0; c25_i148 < 2; c25_i148++) {
      c25_u[c25_i148 + c25_i146] = c25_b_inData[c25_i148 + c25_i146];
    }

    c25_i146 += 2;
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_g_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  creal_T c25_y[2])
{
  creal_T c25_dcv3[2];
  int32_T c25_i149;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dcv3, 1, 0, 1U, 1, 0U, 1, 2);
  for (c25_i149 = 0; c25_i149 < 2; c25_i149++) {
    c25_y[c25_i149] = c25_dcv3[c25_i149];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_lambdaM;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  creal_T c25_y[2];
  int32_T c25_i150;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_lambdaM = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_lambdaM), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_lambdaM);
  for (c25_i150 = 0; c25_i150 < 2; c25_i150++) {
    (*(creal_T (*)[2])c25_outData)[c25_i150] = c25_y[c25_i150];
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static void c25_h_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[4])
{
  real_T c25_dv10[4];
  int32_T c25_i151;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv10, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c25_i151 = 0; c25_i151 < 4; c25_i151++) {
    c25_y[c25_i151] = c25_dv10[c25_i151];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_C;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y[4];
  int32_T c25_i152;
  int32_T c25_i153;
  int32_T c25_i154;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_C = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_C), &c25_thisId, c25_y);
  sf_mex_destroy(&c25_C);
  c25_i152 = 0;
  for (c25_i153 = 0; c25_i153 < 2; c25_i153++) {
    for (c25_i154 = 0; c25_i154 < 2; c25_i154++) {
      (*(real_T (*)[4])c25_outData)[c25_i154 + c25_i152] = c25_y[c25_i154 +
        c25_i152];
    }

    c25_i152 += 2;
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

const mxArray *sf_c25_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c25_nameCaptureInfo = NULL;
  c25_nameCaptureInfo = NULL;
  sf_mex_assign(&c25_nameCaptureInfo, sf_mex_createstruct("structure", 2, 319, 1),
                false);
  c25_info_helper(&c25_nameCaptureInfo);
  c25_b_info_helper(&c25_nameCaptureInfo);
  c25_c_info_helper(&c25_nameCaptureInfo);
  c25_d_info_helper(&c25_nameCaptureInfo);
  c25_e_info_helper(&c25_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c25_nameCaptureInfo);
  return c25_nameCaptureInfo;
}

static void c25_info_helper(const mxArray **c25_info)
{
  const mxArray *c25_rhs0 = NULL;
  const mxArray *c25_lhs0 = NULL;
  const mxArray *c25_rhs1 = NULL;
  const mxArray *c25_lhs1 = NULL;
  const mxArray *c25_rhs2 = NULL;
  const mxArray *c25_lhs2 = NULL;
  const mxArray *c25_rhs3 = NULL;
  const mxArray *c25_lhs3 = NULL;
  const mxArray *c25_rhs4 = NULL;
  const mxArray *c25_lhs4 = NULL;
  const mxArray *c25_rhs5 = NULL;
  const mxArray *c25_lhs5 = NULL;
  const mxArray *c25_rhs6 = NULL;
  const mxArray *c25_lhs6 = NULL;
  const mxArray *c25_rhs7 = NULL;
  const mxArray *c25_lhs7 = NULL;
  const mxArray *c25_rhs8 = NULL;
  const mxArray *c25_lhs8 = NULL;
  const mxArray *c25_rhs9 = NULL;
  const mxArray *c25_lhs9 = NULL;
  const mxArray *c25_rhs10 = NULL;
  const mxArray *c25_lhs10 = NULL;
  const mxArray *c25_rhs11 = NULL;
  const mxArray *c25_lhs11 = NULL;
  const mxArray *c25_rhs12 = NULL;
  const mxArray *c25_lhs12 = NULL;
  const mxArray *c25_rhs13 = NULL;
  const mxArray *c25_lhs13 = NULL;
  const mxArray *c25_rhs14 = NULL;
  const mxArray *c25_lhs14 = NULL;
  const mxArray *c25_rhs15 = NULL;
  const mxArray *c25_lhs15 = NULL;
  const mxArray *c25_rhs16 = NULL;
  const mxArray *c25_lhs16 = NULL;
  const mxArray *c25_rhs17 = NULL;
  const mxArray *c25_lhs17 = NULL;
  const mxArray *c25_rhs18 = NULL;
  const mxArray *c25_lhs18 = NULL;
  const mxArray *c25_rhs19 = NULL;
  const mxArray *c25_lhs19 = NULL;
  const mxArray *c25_rhs20 = NULL;
  const mxArray *c25_lhs20 = NULL;
  const mxArray *c25_rhs21 = NULL;
  const mxArray *c25_lhs21 = NULL;
  const mxArray *c25_rhs22 = NULL;
  const mxArray *c25_lhs22 = NULL;
  const mxArray *c25_rhs23 = NULL;
  const mxArray *c25_lhs23 = NULL;
  const mxArray *c25_rhs24 = NULL;
  const mxArray *c25_lhs24 = NULL;
  const mxArray *c25_rhs25 = NULL;
  const mxArray *c25_lhs25 = NULL;
  const mxArray *c25_rhs26 = NULL;
  const mxArray *c25_lhs26 = NULL;
  const mxArray *c25_rhs27 = NULL;
  const mxArray *c25_lhs27 = NULL;
  const mxArray *c25_rhs28 = NULL;
  const mxArray *c25_lhs28 = NULL;
  const mxArray *c25_rhs29 = NULL;
  const mxArray *c25_lhs29 = NULL;
  const mxArray *c25_rhs30 = NULL;
  const mxArray *c25_lhs30 = NULL;
  const mxArray *c25_rhs31 = NULL;
  const mxArray *c25_lhs31 = NULL;
  const mxArray *c25_rhs32 = NULL;
  const mxArray *c25_lhs32 = NULL;
  const mxArray *c25_rhs33 = NULL;
  const mxArray *c25_lhs33 = NULL;
  const mxArray *c25_rhs34 = NULL;
  const mxArray *c25_lhs34 = NULL;
  const mxArray *c25_rhs35 = NULL;
  const mxArray *c25_lhs35 = NULL;
  const mxArray *c25_rhs36 = NULL;
  const mxArray *c25_lhs36 = NULL;
  const mxArray *c25_rhs37 = NULL;
  const mxArray *c25_lhs37 = NULL;
  const mxArray *c25_rhs38 = NULL;
  const mxArray *c25_lhs38 = NULL;
  const mxArray *c25_rhs39 = NULL;
  const mxArray *c25_lhs39 = NULL;
  const mxArray *c25_rhs40 = NULL;
  const mxArray *c25_lhs40 = NULL;
  const mxArray *c25_rhs41 = NULL;
  const mxArray *c25_lhs41 = NULL;
  const mxArray *c25_rhs42 = NULL;
  const mxArray *c25_lhs42 = NULL;
  const mxArray *c25_rhs43 = NULL;
  const mxArray *c25_lhs43 = NULL;
  const mxArray *c25_rhs44 = NULL;
  const mxArray *c25_lhs44 = NULL;
  const mxArray *c25_rhs45 = NULL;
  const mxArray *c25_lhs45 = NULL;
  const mxArray *c25_rhs46 = NULL;
  const mxArray *c25_lhs46 = NULL;
  const mxArray *c25_rhs47 = NULL;
  const mxArray *c25_lhs47 = NULL;
  const mxArray *c25_rhs48 = NULL;
  const mxArray *c25_lhs48 = NULL;
  const mxArray *c25_rhs49 = NULL;
  const mxArray *c25_lhs49 = NULL;
  const mxArray *c25_rhs50 = NULL;
  const mxArray *c25_lhs50 = NULL;
  const mxArray *c25_rhs51 = NULL;
  const mxArray *c25_lhs51 = NULL;
  const mxArray *c25_rhs52 = NULL;
  const mxArray *c25_lhs52 = NULL;
  const mxArray *c25_rhs53 = NULL;
  const mxArray *c25_lhs53 = NULL;
  const mxArray *c25_rhs54 = NULL;
  const mxArray *c25_lhs54 = NULL;
  const mxArray *c25_rhs55 = NULL;
  const mxArray *c25_lhs55 = NULL;
  const mxArray *c25_rhs56 = NULL;
  const mxArray *c25_lhs56 = NULL;
  const mxArray *c25_rhs57 = NULL;
  const mxArray *c25_lhs57 = NULL;
  const mxArray *c25_rhs58 = NULL;
  const mxArray *c25_lhs58 = NULL;
  const mxArray *c25_rhs59 = NULL;
  const mxArray *c25_lhs59 = NULL;
  const mxArray *c25_rhs60 = NULL;
  const mxArray *c25_lhs60 = NULL;
  const mxArray *c25_rhs61 = NULL;
  const mxArray *c25_lhs61 = NULL;
  const mxArray *c25_rhs62 = NULL;
  const mxArray *c25_lhs62 = NULL;
  const mxArray *c25_rhs63 = NULL;
  const mxArray *c25_lhs63 = NULL;
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c25_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c25_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("ismatrix"), "name", "name",
                  2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1331268858U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c25_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395292506U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c25_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c25_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c25_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c25_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c25_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c25_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677854U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c25_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c25_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c25_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c25_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c25_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 14);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 14);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c25_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 15);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("rdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c25_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c25_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 17);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c25_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_div"), "name", "name",
                  18);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c25_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 19);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c25_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("cos"), "name", "name", 20);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c25_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 21);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786322U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c25_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("sin"), "name", "name", 22);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395292504U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c25_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 23);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786336U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c25_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 24);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("norm"), "name", "name", 24);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677868U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c25_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("svd"), "name", "name", 25);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786432U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c25_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 26);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c25_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 27);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c25_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 28);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isfi"), "name", "name", 28);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 28);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1346481558U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c25_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 29);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1398846798U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c25_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 30);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("intmax"), "name", "name", 30);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c25_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 31);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c25_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 32);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("intmin"), "name", "name", 32);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c25_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 33);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c25_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isfinite"), "name", "name",
                  34);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c25_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 35);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c25_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isinf"), "name", "name", 36);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c25_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 37);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c25_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnan"), "name", "name", 38);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c25_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 39);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c25_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_error"), "name", "name",
                  40);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c25_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xgesvd"), "name", "name",
                  41);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786406U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c25_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_lapack_xgesvd"), "name",
                  "name", 42);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786410U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c25_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zsvdc"), "name",
                  "name", 43);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1398846806U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c25_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 44);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c25_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("min"), "name", "name", 45);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 45);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1311226518U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c25_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 46);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1378267184U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c25_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 47);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 47);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c25_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 48);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c25_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 49);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 49);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c25_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 50);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c25_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 51);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 51);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c25_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 52);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 52);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 52);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c25_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 53);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 53);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 53);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c25_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 54);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("max"), "name", "name", 54);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c25_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 55);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1378267184U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c25_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 56);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 56);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 56);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c25_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 57);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 57);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c25_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 58);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 58);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c25_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 59);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_relop"), "name", "name",
                  59);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 59);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 59);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1342422382U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c25_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 60);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326692322U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c25_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 61);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 61);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c25_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 62);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 62);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c25_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 63);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("intmin"), "name", "name", 63);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 63);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c25_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c25_rhs0);
  sf_mex_destroy(&c25_lhs0);
  sf_mex_destroy(&c25_rhs1);
  sf_mex_destroy(&c25_lhs1);
  sf_mex_destroy(&c25_rhs2);
  sf_mex_destroy(&c25_lhs2);
  sf_mex_destroy(&c25_rhs3);
  sf_mex_destroy(&c25_lhs3);
  sf_mex_destroy(&c25_rhs4);
  sf_mex_destroy(&c25_lhs4);
  sf_mex_destroy(&c25_rhs5);
  sf_mex_destroy(&c25_lhs5);
  sf_mex_destroy(&c25_rhs6);
  sf_mex_destroy(&c25_lhs6);
  sf_mex_destroy(&c25_rhs7);
  sf_mex_destroy(&c25_lhs7);
  sf_mex_destroy(&c25_rhs8);
  sf_mex_destroy(&c25_lhs8);
  sf_mex_destroy(&c25_rhs9);
  sf_mex_destroy(&c25_lhs9);
  sf_mex_destroy(&c25_rhs10);
  sf_mex_destroy(&c25_lhs10);
  sf_mex_destroy(&c25_rhs11);
  sf_mex_destroy(&c25_lhs11);
  sf_mex_destroy(&c25_rhs12);
  sf_mex_destroy(&c25_lhs12);
  sf_mex_destroy(&c25_rhs13);
  sf_mex_destroy(&c25_lhs13);
  sf_mex_destroy(&c25_rhs14);
  sf_mex_destroy(&c25_lhs14);
  sf_mex_destroy(&c25_rhs15);
  sf_mex_destroy(&c25_lhs15);
  sf_mex_destroy(&c25_rhs16);
  sf_mex_destroy(&c25_lhs16);
  sf_mex_destroy(&c25_rhs17);
  sf_mex_destroy(&c25_lhs17);
  sf_mex_destroy(&c25_rhs18);
  sf_mex_destroy(&c25_lhs18);
  sf_mex_destroy(&c25_rhs19);
  sf_mex_destroy(&c25_lhs19);
  sf_mex_destroy(&c25_rhs20);
  sf_mex_destroy(&c25_lhs20);
  sf_mex_destroy(&c25_rhs21);
  sf_mex_destroy(&c25_lhs21);
  sf_mex_destroy(&c25_rhs22);
  sf_mex_destroy(&c25_lhs22);
  sf_mex_destroy(&c25_rhs23);
  sf_mex_destroy(&c25_lhs23);
  sf_mex_destroy(&c25_rhs24);
  sf_mex_destroy(&c25_lhs24);
  sf_mex_destroy(&c25_rhs25);
  sf_mex_destroy(&c25_lhs25);
  sf_mex_destroy(&c25_rhs26);
  sf_mex_destroy(&c25_lhs26);
  sf_mex_destroy(&c25_rhs27);
  sf_mex_destroy(&c25_lhs27);
  sf_mex_destroy(&c25_rhs28);
  sf_mex_destroy(&c25_lhs28);
  sf_mex_destroy(&c25_rhs29);
  sf_mex_destroy(&c25_lhs29);
  sf_mex_destroy(&c25_rhs30);
  sf_mex_destroy(&c25_lhs30);
  sf_mex_destroy(&c25_rhs31);
  sf_mex_destroy(&c25_lhs31);
  sf_mex_destroy(&c25_rhs32);
  sf_mex_destroy(&c25_lhs32);
  sf_mex_destroy(&c25_rhs33);
  sf_mex_destroy(&c25_lhs33);
  sf_mex_destroy(&c25_rhs34);
  sf_mex_destroy(&c25_lhs34);
  sf_mex_destroy(&c25_rhs35);
  sf_mex_destroy(&c25_lhs35);
  sf_mex_destroy(&c25_rhs36);
  sf_mex_destroy(&c25_lhs36);
  sf_mex_destroy(&c25_rhs37);
  sf_mex_destroy(&c25_lhs37);
  sf_mex_destroy(&c25_rhs38);
  sf_mex_destroy(&c25_lhs38);
  sf_mex_destroy(&c25_rhs39);
  sf_mex_destroy(&c25_lhs39);
  sf_mex_destroy(&c25_rhs40);
  sf_mex_destroy(&c25_lhs40);
  sf_mex_destroy(&c25_rhs41);
  sf_mex_destroy(&c25_lhs41);
  sf_mex_destroy(&c25_rhs42);
  sf_mex_destroy(&c25_lhs42);
  sf_mex_destroy(&c25_rhs43);
  sf_mex_destroy(&c25_lhs43);
  sf_mex_destroy(&c25_rhs44);
  sf_mex_destroy(&c25_lhs44);
  sf_mex_destroy(&c25_rhs45);
  sf_mex_destroy(&c25_lhs45);
  sf_mex_destroy(&c25_rhs46);
  sf_mex_destroy(&c25_lhs46);
  sf_mex_destroy(&c25_rhs47);
  sf_mex_destroy(&c25_lhs47);
  sf_mex_destroy(&c25_rhs48);
  sf_mex_destroy(&c25_lhs48);
  sf_mex_destroy(&c25_rhs49);
  sf_mex_destroy(&c25_lhs49);
  sf_mex_destroy(&c25_rhs50);
  sf_mex_destroy(&c25_lhs50);
  sf_mex_destroy(&c25_rhs51);
  sf_mex_destroy(&c25_lhs51);
  sf_mex_destroy(&c25_rhs52);
  sf_mex_destroy(&c25_lhs52);
  sf_mex_destroy(&c25_rhs53);
  sf_mex_destroy(&c25_lhs53);
  sf_mex_destroy(&c25_rhs54);
  sf_mex_destroy(&c25_lhs54);
  sf_mex_destroy(&c25_rhs55);
  sf_mex_destroy(&c25_lhs55);
  sf_mex_destroy(&c25_rhs56);
  sf_mex_destroy(&c25_lhs56);
  sf_mex_destroy(&c25_rhs57);
  sf_mex_destroy(&c25_lhs57);
  sf_mex_destroy(&c25_rhs58);
  sf_mex_destroy(&c25_lhs58);
  sf_mex_destroy(&c25_rhs59);
  sf_mex_destroy(&c25_lhs59);
  sf_mex_destroy(&c25_rhs60);
  sf_mex_destroy(&c25_lhs60);
  sf_mex_destroy(&c25_rhs61);
  sf_mex_destroy(&c25_lhs61);
  sf_mex_destroy(&c25_rhs62);
  sf_mex_destroy(&c25_lhs62);
  sf_mex_destroy(&c25_rhs63);
  sf_mex_destroy(&c25_lhs63);
}

static const mxArray *c25_emlrt_marshallOut(const char * c25_u)
{
  const mxArray *c25_y = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c25_u)), false);
  return c25_y;
}

static const mxArray *c25_b_emlrt_marshallOut(const uint32_T c25_u)
{
  const mxArray *c25_y = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 7, 0U, 0U, 0U, 0), false);
  return c25_y;
}

static void c25_b_info_helper(const mxArray **c25_info)
{
  const mxArray *c25_rhs64 = NULL;
  const mxArray *c25_lhs64 = NULL;
  const mxArray *c25_rhs65 = NULL;
  const mxArray *c25_lhs65 = NULL;
  const mxArray *c25_rhs66 = NULL;
  const mxArray *c25_lhs66 = NULL;
  const mxArray *c25_rhs67 = NULL;
  const mxArray *c25_lhs67 = NULL;
  const mxArray *c25_rhs68 = NULL;
  const mxArray *c25_lhs68 = NULL;
  const mxArray *c25_rhs69 = NULL;
  const mxArray *c25_lhs69 = NULL;
  const mxArray *c25_rhs70 = NULL;
  const mxArray *c25_lhs70 = NULL;
  const mxArray *c25_rhs71 = NULL;
  const mxArray *c25_lhs71 = NULL;
  const mxArray *c25_rhs72 = NULL;
  const mxArray *c25_lhs72 = NULL;
  const mxArray *c25_rhs73 = NULL;
  const mxArray *c25_lhs73 = NULL;
  const mxArray *c25_rhs74 = NULL;
  const mxArray *c25_lhs74 = NULL;
  const mxArray *c25_rhs75 = NULL;
  const mxArray *c25_lhs75 = NULL;
  const mxArray *c25_rhs76 = NULL;
  const mxArray *c25_lhs76 = NULL;
  const mxArray *c25_rhs77 = NULL;
  const mxArray *c25_lhs77 = NULL;
  const mxArray *c25_rhs78 = NULL;
  const mxArray *c25_lhs78 = NULL;
  const mxArray *c25_rhs79 = NULL;
  const mxArray *c25_lhs79 = NULL;
  const mxArray *c25_rhs80 = NULL;
  const mxArray *c25_lhs80 = NULL;
  const mxArray *c25_rhs81 = NULL;
  const mxArray *c25_lhs81 = NULL;
  const mxArray *c25_rhs82 = NULL;
  const mxArray *c25_lhs82 = NULL;
  const mxArray *c25_rhs83 = NULL;
  const mxArray *c25_lhs83 = NULL;
  const mxArray *c25_rhs84 = NULL;
  const mxArray *c25_lhs84 = NULL;
  const mxArray *c25_rhs85 = NULL;
  const mxArray *c25_lhs85 = NULL;
  const mxArray *c25_rhs86 = NULL;
  const mxArray *c25_lhs86 = NULL;
  const mxArray *c25_rhs87 = NULL;
  const mxArray *c25_lhs87 = NULL;
  const mxArray *c25_rhs88 = NULL;
  const mxArray *c25_lhs88 = NULL;
  const mxArray *c25_rhs89 = NULL;
  const mxArray *c25_lhs89 = NULL;
  const mxArray *c25_rhs90 = NULL;
  const mxArray *c25_lhs90 = NULL;
  const mxArray *c25_rhs91 = NULL;
  const mxArray *c25_lhs91 = NULL;
  const mxArray *c25_rhs92 = NULL;
  const mxArray *c25_lhs92 = NULL;
  const mxArray *c25_rhs93 = NULL;
  const mxArray *c25_lhs93 = NULL;
  const mxArray *c25_rhs94 = NULL;
  const mxArray *c25_lhs94 = NULL;
  const mxArray *c25_rhs95 = NULL;
  const mxArray *c25_lhs95 = NULL;
  const mxArray *c25_rhs96 = NULL;
  const mxArray *c25_lhs96 = NULL;
  const mxArray *c25_rhs97 = NULL;
  const mxArray *c25_lhs97 = NULL;
  const mxArray *c25_rhs98 = NULL;
  const mxArray *c25_lhs98 = NULL;
  const mxArray *c25_rhs99 = NULL;
  const mxArray *c25_lhs99 = NULL;
  const mxArray *c25_rhs100 = NULL;
  const mxArray *c25_lhs100 = NULL;
  const mxArray *c25_rhs101 = NULL;
  const mxArray *c25_lhs101 = NULL;
  const mxArray *c25_rhs102 = NULL;
  const mxArray *c25_lhs102 = NULL;
  const mxArray *c25_rhs103 = NULL;
  const mxArray *c25_lhs103 = NULL;
  const mxArray *c25_rhs104 = NULL;
  const mxArray *c25_lhs104 = NULL;
  const mxArray *c25_rhs105 = NULL;
  const mxArray *c25_lhs105 = NULL;
  const mxArray *c25_rhs106 = NULL;
  const mxArray *c25_lhs106 = NULL;
  const mxArray *c25_rhs107 = NULL;
  const mxArray *c25_lhs107 = NULL;
  const mxArray *c25_rhs108 = NULL;
  const mxArray *c25_lhs108 = NULL;
  const mxArray *c25_rhs109 = NULL;
  const mxArray *c25_lhs109 = NULL;
  const mxArray *c25_rhs110 = NULL;
  const mxArray *c25_lhs110 = NULL;
  const mxArray *c25_rhs111 = NULL;
  const mxArray *c25_lhs111 = NULL;
  const mxArray *c25_rhs112 = NULL;
  const mxArray *c25_lhs112 = NULL;
  const mxArray *c25_rhs113 = NULL;
  const mxArray *c25_lhs113 = NULL;
  const mxArray *c25_rhs114 = NULL;
  const mxArray *c25_lhs114 = NULL;
  const mxArray *c25_rhs115 = NULL;
  const mxArray *c25_lhs115 = NULL;
  const mxArray *c25_rhs116 = NULL;
  const mxArray *c25_lhs116 = NULL;
  const mxArray *c25_rhs117 = NULL;
  const mxArray *c25_lhs117 = NULL;
  const mxArray *c25_rhs118 = NULL;
  const mxArray *c25_lhs118 = NULL;
  const mxArray *c25_rhs119 = NULL;
  const mxArray *c25_lhs119 = NULL;
  const mxArray *c25_rhs120 = NULL;
  const mxArray *c25_lhs120 = NULL;
  const mxArray *c25_rhs121 = NULL;
  const mxArray *c25_lhs121 = NULL;
  const mxArray *c25_rhs122 = NULL;
  const mxArray *c25_lhs122 = NULL;
  const mxArray *c25_rhs123 = NULL;
  const mxArray *c25_lhs123 = NULL;
  const mxArray *c25_rhs124 = NULL;
  const mxArray *c25_lhs124 = NULL;
  const mxArray *c25_rhs125 = NULL;
  const mxArray *c25_lhs125 = NULL;
  const mxArray *c25_rhs126 = NULL;
  const mxArray *c25_lhs126 = NULL;
  const mxArray *c25_rhs127 = NULL;
  const mxArray *c25_lhs127 = NULL;
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 64);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnan"), "name", "name", 64);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 64);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c25_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 65);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 65);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c25_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 66);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("max"), "name", "name", 66);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 66);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c25_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  67);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c25_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 68);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c25_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 69);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 69);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c25_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 70);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 70);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c25_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 71);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 71);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c25_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 72);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c25_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 73);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 73);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c25_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 74);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmin"), "name", "name",
                  74);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c25_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 75);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622444U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c25_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 76);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 76);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c25_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 77);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 77);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c25_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 78);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 78);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 78);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c25_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 79);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 79);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 79);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c25_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 80);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 80);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c25_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 81);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 81);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c25_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 82);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 82);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c25_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 83);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 83);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786312U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c25_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 84);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.scaleVectorByRecip"), "name", "name", 84);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c25_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 85);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmin"), "name", "name",
                  85);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c25_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 86);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 86);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 86);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c25_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 87);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 87);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c25_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 88);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_eps"), "name", "name",
                  88);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c25_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 89);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 89);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c25_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 90);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  90);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c25_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 91);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 91);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 91);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c25_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 92);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.xscal"),
                  "name", "name", 92);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c25_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 93);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 93);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c25_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p!below_threshold"),
                  "context", "context", 94);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 94);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c25_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 95);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 95);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c25_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 96);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.refblas.xscal"), "name", "name", 96);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c25_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 97);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 97);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c25_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 98);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 98);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 98);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c25_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 99);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 99);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 99);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c25_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 100);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 100);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c25_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 101);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 101);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c25_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 102);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 102);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 102);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c25_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 103);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 103);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 103);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c25_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 104);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 104);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c25_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 105);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  105);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c25_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 106);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c25_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.xdotc"),
                  "name", "name", 107);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c25_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "context", "context", 108);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 108);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c25_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 109);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 109);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c25_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 110);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 110);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c25_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 111);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 111);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c25_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 112);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 112);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c25_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 113);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 113);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c25_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 114);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 114);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c25_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 115);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 115);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 115);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c25_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 116);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  116);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 116);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c25_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 117);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xaxpy"), "name", "name",
                  117);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c25_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"), "context",
                  "context", 118);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 118);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c25_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"), "context",
                  "context", 119);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.xaxpy"),
                  "name", "name", 119);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "resolved", "resolved", 119);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c25_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 120);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 120);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c25_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p!below_threshold"),
                  "context", "context", 121);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 121);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c25_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 122);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 122);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c25_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 123);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.refblas.xaxpy"), "name", "name", 123);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c25_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 124);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 124);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 124);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c25_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 125);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 125);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c25_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 126);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 126);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c25_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 127);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 127);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c25_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c25_rhs64);
  sf_mex_destroy(&c25_lhs64);
  sf_mex_destroy(&c25_rhs65);
  sf_mex_destroy(&c25_lhs65);
  sf_mex_destroy(&c25_rhs66);
  sf_mex_destroy(&c25_lhs66);
  sf_mex_destroy(&c25_rhs67);
  sf_mex_destroy(&c25_lhs67);
  sf_mex_destroy(&c25_rhs68);
  sf_mex_destroy(&c25_lhs68);
  sf_mex_destroy(&c25_rhs69);
  sf_mex_destroy(&c25_lhs69);
  sf_mex_destroy(&c25_rhs70);
  sf_mex_destroy(&c25_lhs70);
  sf_mex_destroy(&c25_rhs71);
  sf_mex_destroy(&c25_lhs71);
  sf_mex_destroy(&c25_rhs72);
  sf_mex_destroy(&c25_lhs72);
  sf_mex_destroy(&c25_rhs73);
  sf_mex_destroy(&c25_lhs73);
  sf_mex_destroy(&c25_rhs74);
  sf_mex_destroy(&c25_lhs74);
  sf_mex_destroy(&c25_rhs75);
  sf_mex_destroy(&c25_lhs75);
  sf_mex_destroy(&c25_rhs76);
  sf_mex_destroy(&c25_lhs76);
  sf_mex_destroy(&c25_rhs77);
  sf_mex_destroy(&c25_lhs77);
  sf_mex_destroy(&c25_rhs78);
  sf_mex_destroy(&c25_lhs78);
  sf_mex_destroy(&c25_rhs79);
  sf_mex_destroy(&c25_lhs79);
  sf_mex_destroy(&c25_rhs80);
  sf_mex_destroy(&c25_lhs80);
  sf_mex_destroy(&c25_rhs81);
  sf_mex_destroy(&c25_lhs81);
  sf_mex_destroy(&c25_rhs82);
  sf_mex_destroy(&c25_lhs82);
  sf_mex_destroy(&c25_rhs83);
  sf_mex_destroy(&c25_lhs83);
  sf_mex_destroy(&c25_rhs84);
  sf_mex_destroy(&c25_lhs84);
  sf_mex_destroy(&c25_rhs85);
  sf_mex_destroy(&c25_lhs85);
  sf_mex_destroy(&c25_rhs86);
  sf_mex_destroy(&c25_lhs86);
  sf_mex_destroy(&c25_rhs87);
  sf_mex_destroy(&c25_lhs87);
  sf_mex_destroy(&c25_rhs88);
  sf_mex_destroy(&c25_lhs88);
  sf_mex_destroy(&c25_rhs89);
  sf_mex_destroy(&c25_lhs89);
  sf_mex_destroy(&c25_rhs90);
  sf_mex_destroy(&c25_lhs90);
  sf_mex_destroy(&c25_rhs91);
  sf_mex_destroy(&c25_lhs91);
  sf_mex_destroy(&c25_rhs92);
  sf_mex_destroy(&c25_lhs92);
  sf_mex_destroy(&c25_rhs93);
  sf_mex_destroy(&c25_lhs93);
  sf_mex_destroy(&c25_rhs94);
  sf_mex_destroy(&c25_lhs94);
  sf_mex_destroy(&c25_rhs95);
  sf_mex_destroy(&c25_lhs95);
  sf_mex_destroy(&c25_rhs96);
  sf_mex_destroy(&c25_lhs96);
  sf_mex_destroy(&c25_rhs97);
  sf_mex_destroy(&c25_lhs97);
  sf_mex_destroy(&c25_rhs98);
  sf_mex_destroy(&c25_lhs98);
  sf_mex_destroy(&c25_rhs99);
  sf_mex_destroy(&c25_lhs99);
  sf_mex_destroy(&c25_rhs100);
  sf_mex_destroy(&c25_lhs100);
  sf_mex_destroy(&c25_rhs101);
  sf_mex_destroy(&c25_lhs101);
  sf_mex_destroy(&c25_rhs102);
  sf_mex_destroy(&c25_lhs102);
  sf_mex_destroy(&c25_rhs103);
  sf_mex_destroy(&c25_lhs103);
  sf_mex_destroy(&c25_rhs104);
  sf_mex_destroy(&c25_lhs104);
  sf_mex_destroy(&c25_rhs105);
  sf_mex_destroy(&c25_lhs105);
  sf_mex_destroy(&c25_rhs106);
  sf_mex_destroy(&c25_lhs106);
  sf_mex_destroy(&c25_rhs107);
  sf_mex_destroy(&c25_lhs107);
  sf_mex_destroy(&c25_rhs108);
  sf_mex_destroy(&c25_lhs108);
  sf_mex_destroy(&c25_rhs109);
  sf_mex_destroy(&c25_lhs109);
  sf_mex_destroy(&c25_rhs110);
  sf_mex_destroy(&c25_lhs110);
  sf_mex_destroy(&c25_rhs111);
  sf_mex_destroy(&c25_lhs111);
  sf_mex_destroy(&c25_rhs112);
  sf_mex_destroy(&c25_lhs112);
  sf_mex_destroy(&c25_rhs113);
  sf_mex_destroy(&c25_lhs113);
  sf_mex_destroy(&c25_rhs114);
  sf_mex_destroy(&c25_lhs114);
  sf_mex_destroy(&c25_rhs115);
  sf_mex_destroy(&c25_lhs115);
  sf_mex_destroy(&c25_rhs116);
  sf_mex_destroy(&c25_lhs116);
  sf_mex_destroy(&c25_rhs117);
  sf_mex_destroy(&c25_lhs117);
  sf_mex_destroy(&c25_rhs118);
  sf_mex_destroy(&c25_lhs118);
  sf_mex_destroy(&c25_rhs119);
  sf_mex_destroy(&c25_lhs119);
  sf_mex_destroy(&c25_rhs120);
  sf_mex_destroy(&c25_lhs120);
  sf_mex_destroy(&c25_rhs121);
  sf_mex_destroy(&c25_lhs121);
  sf_mex_destroy(&c25_rhs122);
  sf_mex_destroy(&c25_lhs122);
  sf_mex_destroy(&c25_rhs123);
  sf_mex_destroy(&c25_lhs123);
  sf_mex_destroy(&c25_rhs124);
  sf_mex_destroy(&c25_lhs124);
  sf_mex_destroy(&c25_rhs125);
  sf_mex_destroy(&c25_lhs125);
  sf_mex_destroy(&c25_rhs126);
  sf_mex_destroy(&c25_lhs126);
  sf_mex_destroy(&c25_rhs127);
  sf_mex_destroy(&c25_lhs127);
}

static void c25_c_info_helper(const mxArray **c25_info)
{
  const mxArray *c25_rhs128 = NULL;
  const mxArray *c25_lhs128 = NULL;
  const mxArray *c25_rhs129 = NULL;
  const mxArray *c25_lhs129 = NULL;
  const mxArray *c25_rhs130 = NULL;
  const mxArray *c25_lhs130 = NULL;
  const mxArray *c25_rhs131 = NULL;
  const mxArray *c25_lhs131 = NULL;
  const mxArray *c25_rhs132 = NULL;
  const mxArray *c25_lhs132 = NULL;
  const mxArray *c25_rhs133 = NULL;
  const mxArray *c25_lhs133 = NULL;
  const mxArray *c25_rhs134 = NULL;
  const mxArray *c25_lhs134 = NULL;
  const mxArray *c25_rhs135 = NULL;
  const mxArray *c25_lhs135 = NULL;
  const mxArray *c25_rhs136 = NULL;
  const mxArray *c25_lhs136 = NULL;
  const mxArray *c25_rhs137 = NULL;
  const mxArray *c25_lhs137 = NULL;
  const mxArray *c25_rhs138 = NULL;
  const mxArray *c25_lhs138 = NULL;
  const mxArray *c25_rhs139 = NULL;
  const mxArray *c25_lhs139 = NULL;
  const mxArray *c25_rhs140 = NULL;
  const mxArray *c25_lhs140 = NULL;
  const mxArray *c25_rhs141 = NULL;
  const mxArray *c25_lhs141 = NULL;
  const mxArray *c25_rhs142 = NULL;
  const mxArray *c25_lhs142 = NULL;
  const mxArray *c25_rhs143 = NULL;
  const mxArray *c25_lhs143 = NULL;
  const mxArray *c25_rhs144 = NULL;
  const mxArray *c25_lhs144 = NULL;
  const mxArray *c25_rhs145 = NULL;
  const mxArray *c25_lhs145 = NULL;
  const mxArray *c25_rhs146 = NULL;
  const mxArray *c25_lhs146 = NULL;
  const mxArray *c25_rhs147 = NULL;
  const mxArray *c25_lhs147 = NULL;
  const mxArray *c25_rhs148 = NULL;
  const mxArray *c25_lhs148 = NULL;
  const mxArray *c25_rhs149 = NULL;
  const mxArray *c25_lhs149 = NULL;
  const mxArray *c25_rhs150 = NULL;
  const mxArray *c25_lhs150 = NULL;
  const mxArray *c25_rhs151 = NULL;
  const mxArray *c25_lhs151 = NULL;
  const mxArray *c25_rhs152 = NULL;
  const mxArray *c25_lhs152 = NULL;
  const mxArray *c25_rhs153 = NULL;
  const mxArray *c25_lhs153 = NULL;
  const mxArray *c25_rhs154 = NULL;
  const mxArray *c25_lhs154 = NULL;
  const mxArray *c25_rhs155 = NULL;
  const mxArray *c25_lhs155 = NULL;
  const mxArray *c25_rhs156 = NULL;
  const mxArray *c25_lhs156 = NULL;
  const mxArray *c25_rhs157 = NULL;
  const mxArray *c25_lhs157 = NULL;
  const mxArray *c25_rhs158 = NULL;
  const mxArray *c25_lhs158 = NULL;
  const mxArray *c25_rhs159 = NULL;
  const mxArray *c25_lhs159 = NULL;
  const mxArray *c25_rhs160 = NULL;
  const mxArray *c25_lhs160 = NULL;
  const mxArray *c25_rhs161 = NULL;
  const mxArray *c25_lhs161 = NULL;
  const mxArray *c25_rhs162 = NULL;
  const mxArray *c25_lhs162 = NULL;
  const mxArray *c25_rhs163 = NULL;
  const mxArray *c25_lhs163 = NULL;
  const mxArray *c25_rhs164 = NULL;
  const mxArray *c25_lhs164 = NULL;
  const mxArray *c25_rhs165 = NULL;
  const mxArray *c25_lhs165 = NULL;
  const mxArray *c25_rhs166 = NULL;
  const mxArray *c25_lhs166 = NULL;
  const mxArray *c25_rhs167 = NULL;
  const mxArray *c25_lhs167 = NULL;
  const mxArray *c25_rhs168 = NULL;
  const mxArray *c25_lhs168 = NULL;
  const mxArray *c25_rhs169 = NULL;
  const mxArray *c25_lhs169 = NULL;
  const mxArray *c25_rhs170 = NULL;
  const mxArray *c25_lhs170 = NULL;
  const mxArray *c25_rhs171 = NULL;
  const mxArray *c25_lhs171 = NULL;
  const mxArray *c25_rhs172 = NULL;
  const mxArray *c25_lhs172 = NULL;
  const mxArray *c25_rhs173 = NULL;
  const mxArray *c25_lhs173 = NULL;
  const mxArray *c25_rhs174 = NULL;
  const mxArray *c25_lhs174 = NULL;
  const mxArray *c25_rhs175 = NULL;
  const mxArray *c25_lhs175 = NULL;
  const mxArray *c25_rhs176 = NULL;
  const mxArray *c25_lhs176 = NULL;
  const mxArray *c25_rhs177 = NULL;
  const mxArray *c25_lhs177 = NULL;
  const mxArray *c25_rhs178 = NULL;
  const mxArray *c25_lhs178 = NULL;
  const mxArray *c25_rhs179 = NULL;
  const mxArray *c25_lhs179 = NULL;
  const mxArray *c25_rhs180 = NULL;
  const mxArray *c25_lhs180 = NULL;
  const mxArray *c25_rhs181 = NULL;
  const mxArray *c25_lhs181 = NULL;
  const mxArray *c25_rhs182 = NULL;
  const mxArray *c25_lhs182 = NULL;
  const mxArray *c25_rhs183 = NULL;
  const mxArray *c25_lhs183 = NULL;
  const mxArray *c25_rhs184 = NULL;
  const mxArray *c25_lhs184 = NULL;
  const mxArray *c25_rhs185 = NULL;
  const mxArray *c25_lhs185 = NULL;
  const mxArray *c25_rhs186 = NULL;
  const mxArray *c25_lhs186 = NULL;
  const mxArray *c25_rhs187 = NULL;
  const mxArray *c25_lhs187 = NULL;
  const mxArray *c25_rhs188 = NULL;
  const mxArray *c25_lhs188 = NULL;
  const mxArray *c25_rhs189 = NULL;
  const mxArray *c25_lhs189 = NULL;
  const mxArray *c25_rhs190 = NULL;
  const mxArray *c25_lhs190 = NULL;
  const mxArray *c25_rhs191 = NULL;
  const mxArray *c25_lhs191 = NULL;
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 128);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 128);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 128);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c25_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 129);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 129);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c25_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs129), "rhs",
                  "rhs", 129);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs129), "lhs",
                  "lhs", 129);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 130);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 130);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 130);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c25_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs130), "rhs",
                  "rhs", 130);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs130), "lhs",
                  "lhs", 130);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 131);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmin"), "name", "name",
                  131);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 131);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 131);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c25_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs131), "rhs",
                  "rhs", 131);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs131), "lhs",
                  "lhs", 131);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 132);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 132);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 132);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 132);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c25_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs132), "rhs",
                  "rhs", 132);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs132), "lhs",
                  "lhs", 132);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 133);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 133);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 133);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 133);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c25_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs133), "rhs",
                  "rhs", 133);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs133), "lhs",
                  "lhs", 133);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 134);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_error"), "name", "name",
                  134);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 134);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c25_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs134), "rhs",
                  "rhs", 134);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs134), "lhs",
                  "lhs", 134);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 135);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 135);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c25_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs135), "rhs",
                  "rhs", 135);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs135), "lhs",
                  "lhs", 135);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 136);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 136);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c25_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs136), "rhs",
                  "rhs", 136);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs136), "lhs",
                  "lhs", 136);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 137);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 137);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 137);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c25_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs137), "rhs",
                  "rhs", 137);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs137), "lhs",
                  "lhs", 137);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 138);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 138);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 138);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c25_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs138), "rhs",
                  "rhs", 138);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs138), "lhs",
                  "lhs", 138);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 139);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 139);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 139);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c25_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs139), "rhs",
                  "rhs", 139);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs139), "lhs",
                  "lhs", 139);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 140);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnan"), "name", "name", 140);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 140);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c25_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs140), "rhs",
                  "rhs", 140);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs140), "lhs",
                  "lhs", 140);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 141);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 141);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 141);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c25_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs141), "rhs",
                  "rhs", 141);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs141), "lhs",
                  "lhs", 141);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 142);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 142);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 142);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c25_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs142), "rhs",
                  "rhs", 142);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs142), "lhs",
                  "lhs", 142);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 143);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 143);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 143);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c25_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs143), "rhs",
                  "rhs", 143);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs143), "lhs",
                  "lhs", 143);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 144);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_relop"), "name", "name",
                  144);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 144);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 144);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1342422382U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c25_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs144), "rhs",
                  "rhs", 144);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs144), "lhs",
                  "lhs", 144);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 145);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("sqrt"), "name", "name", 145);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 145);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c25_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs145), "rhs",
                  "rhs", 145);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs145), "lhs",
                  "lhs", 145);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 146);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_error"), "name", "name",
                  146);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 146);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c25_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs146), "rhs",
                  "rhs", 146);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs146), "lhs",
                  "lhs", 146);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 147);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 147);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 147);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786338U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c25_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs147), "rhs",
                  "rhs", 147);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs147), "lhs",
                  "lhs", 147);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 148);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xrotg"), "name", "name",
                  148);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c25_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs148), "rhs",
                  "rhs", 148);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs148), "lhs",
                  "lhs", 148);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"), "context",
                  "context", 149);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 149);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c25_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs149), "rhs",
                  "rhs", 149);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs149), "lhs",
                  "lhs", 149);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"), "context",
                  "context", 150);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.xrotg"),
                  "name", "name", 150);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "resolved", "resolved", 150);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c25_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs150), "rhs",
                  "rhs", 150);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs150), "lhs",
                  "lhs", 150);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "context", "context", 151);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 151);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c25_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs151), "rhs",
                  "rhs", 151);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs151), "lhs",
                  "lhs", 151);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "context", "context", 152);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.refblas.xrotg"), "name", "name", 152);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c25_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs152), "rhs",
                  "rhs", 152);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs152), "lhs",
                  "lhs", 152);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 153);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 153);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 153);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c25_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs153), "rhs",
                  "rhs", 153);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs153), "lhs",
                  "lhs", 153);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 154);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  154);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 154);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 154);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c25_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs154), "rhs",
                  "rhs", 154);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs154), "lhs",
                  "lhs", 154);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 155);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("sqrt"), "name", "name", 155);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 155);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 155);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c25_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs155), "rhs",
                  "rhs", 155);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs155), "lhs",
                  "lhs", 155);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p!eml_ceval_xrotg"),
                  "context", "context", 156);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 156);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 156);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 156);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c25_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs156), "rhs",
                  "rhs", 156);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs156), "lhs",
                  "lhs", 156);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 157);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 157);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 157);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c25_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs157), "rhs",
                  "rhs", 157);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs157), "lhs",
                  "lhs", 157);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 158);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 158);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 158);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 158);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c25_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs158), "rhs",
                  "rhs", 158);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs158), "lhs",
                  "lhs", 158);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 159);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  159);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 159);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c25_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs159), "rhs",
                  "rhs", 159);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs159), "lhs",
                  "lhs", 159);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context",
                  160);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eig"), "name", "name", 160);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "resolved",
                  "resolved", 160);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1398846808U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c25_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs160), "rhs",
                  "rhs", 160);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs160), "lhs",
                  "lhs", 160);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "context",
                  "context", 161);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 161);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 161);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c25_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs161), "rhs",
                  "rhs", 161);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs161), "lhs",
                  "lhs", 161);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m!parseopts"),
                  "context", "context", 162);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("length"), "name", "name",
                  162);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("cell"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 162);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1303117406U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c25_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs162), "rhs",
                  "rhs", 162);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs162), "lhs",
                  "lhs", 162);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "context",
                  "context", 163);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 163);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 163);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c25_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs163), "rhs",
                  "rhs", 163);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs163), "lhs",
                  "lhs", 163);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "context",
                  "context", 164);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xgeev"), "name", "name",
                  164);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeev.m"),
                  "resolved", "resolved", 164);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786404U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c25_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs164), "rhs",
                  "rhs", 164);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs164), "lhs",
                  "lhs", 164);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeev.m"),
                  "context", "context", 165);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_lapack_xgeev"), "name",
                  "name", 165);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeev.m"),
                  "resolved", "resolved", 165);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1301296068U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c25_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs165), "rhs",
                  "rhs", 165);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs165), "lhs",
                  "lhs", 165);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeev.m"),
                  "context", "context", 166);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zggev"), "name",
                  "name", 166);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c25_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs166), "rhs",
                  "rhs", 166);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs166), "lhs",
                  "lhs", 166);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 167);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 167);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 167);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c25_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs167), "rhs",
                  "rhs", 167);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs167), "lhs",
                  "lhs", 167);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 168);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmin"), "name", "name",
                  168);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 168);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c25_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs168), "rhs",
                  "rhs", 168);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs168), "lhs",
                  "lhs", 168);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 169);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("sqrt"), "name", "name", 169);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 169);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c25_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs169), "rhs",
                  "rhs", 169);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs169), "lhs",
                  "lhs", 169);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 170);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 170);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 170);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c25_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs170), "rhs",
                  "rhs", 170);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs170), "lhs",
                  "lhs", 170);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 171);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zlangeM"), "name",
                  "name", 171);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 171);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlangeM.m"),
                  "resolved", "resolved", 171);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786420U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c25_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs171), "rhs",
                  "rhs", 171);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs171), "lhs",
                  "lhs", 171);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlangeM.m"),
                  "context", "context", 172);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 172);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 172);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c25_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs172), "rhs",
                  "rhs", 172);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs172), "lhs",
                  "lhs", 172);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "context", "context", 173);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_dlapy2"), "name", "name",
                  173);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                  "resolved", 173);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1350378254U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c25_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs173), "rhs",
                  "rhs", 173);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs173), "lhs",
                  "lhs", 173);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlangeM.m"),
                  "context", "context", 174);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnan"), "name", "name", 174);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 174);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c25_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs174), "rhs",
                  "rhs", 174);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs174), "lhs",
                  "lhs", 174);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlangeM.m"),
                  "context", "context", 175);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 175);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 175);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 175);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c25_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs175), "rhs",
                  "rhs", 175);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs175), "lhs",
                  "lhs", 175);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 176);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 176);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 176);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c25_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs176), "rhs",
                  "rhs", 176);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs176), "lhs",
                  "lhs", 176);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 177);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isfinite"), "name", "name",
                  177);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 177);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c25_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs177), "rhs",
                  "rhs", 177);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs177), "lhs",
                  "lhs", 177);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 178);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 178);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 178);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 178);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c25_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs178), "rhs",
                  "rhs", 178);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs178), "lhs",
                  "lhs", 178);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 179);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zlascl"), "name",
                  "name", 179);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 179);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "resolved", "resolved", 179);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786422U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c25_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs179), "rhs",
                  "rhs", 179);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs179), "lhs",
                  "lhs", 179);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "context", "context", 180);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmin"), "name", "name",
                  180);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 180);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 180);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c25_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs180), "rhs",
                  "rhs", 180);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs180), "lhs",
                  "lhs", 180);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "context", "context", 181);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 181);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 181);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 181);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c25_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs181), "rhs",
                  "rhs", 181);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs181), "lhs",
                  "lhs", 181);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "context", "context", 182);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 182);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 182);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 182);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c25_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs182), "rhs",
                  "rhs", 182);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs182), "lhs",
                  "lhs", 182);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "context", "context", 183);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 183);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 183);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 183);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c25_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs183), "rhs",
                  "rhs", 183);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs183), "lhs",
                  "lhs", 183);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 184);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 184);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 184);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 184);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 184);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 184);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 184);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 184);
  sf_mex_assign(&c25_rhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs184), "rhs",
                  "rhs", 184);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs184), "lhs",
                  "lhs", 184);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 185);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zggbal"), "name",
                  "name", 185);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 185);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"),
                  "resolved", "resolved", 185);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786418U), "fileTimeLo",
                  "fileTimeLo", 185);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 185);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 185);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 185);
  sf_mex_assign(&c25_rhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs185), "rhs",
                  "rhs", 185);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs185), "lhs",
                  "lhs", 185);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"),
                  "context", "context", 186);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 186);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 186);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 186);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 186);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 186);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 186);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 186);
  sf_mex_assign(&c25_rhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs186), "rhs",
                  "rhs", 186);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs186), "lhs",
                  "lhs", 186);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_rows"),
                  "context", "context", 187);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 187);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 187);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 187);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 187);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 187);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 187);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 187);
  sf_mex_assign(&c25_rhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs187), "rhs",
                  "rhs", 187);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs187), "lhs",
                  "lhs", 187);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_rows"),
                  "context", "context", 188);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 188);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 188);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 188);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 188);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 188);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 188);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 188);
  sf_mex_assign(&c25_rhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs188), "rhs",
                  "rhs", 188);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs188), "lhs",
                  "lhs", 188);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_rows"),
                  "context", "context", 189);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 189);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 189);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 189);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 189);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 189);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 189);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 189);
  sf_mex_assign(&c25_rhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs189), "rhs",
                  "rhs", 189);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs189), "lhs",
                  "lhs", 189);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 190);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 190);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 190);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 190);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 190);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 190);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 190);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 190);
  sf_mex_assign(&c25_rhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs190), "rhs",
                  "rhs", 190);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs190), "lhs",
                  "lhs", 190);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_simtran"),
                  "context", "context", 191);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 191);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 191);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 191);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 191);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 191);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 191);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 191);
  sf_mex_assign(&c25_rhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs191), "rhs",
                  "rhs", 191);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs191), "lhs",
                  "lhs", 191);
  sf_mex_destroy(&c25_rhs128);
  sf_mex_destroy(&c25_lhs128);
  sf_mex_destroy(&c25_rhs129);
  sf_mex_destroy(&c25_lhs129);
  sf_mex_destroy(&c25_rhs130);
  sf_mex_destroy(&c25_lhs130);
  sf_mex_destroy(&c25_rhs131);
  sf_mex_destroy(&c25_lhs131);
  sf_mex_destroy(&c25_rhs132);
  sf_mex_destroy(&c25_lhs132);
  sf_mex_destroy(&c25_rhs133);
  sf_mex_destroy(&c25_lhs133);
  sf_mex_destroy(&c25_rhs134);
  sf_mex_destroy(&c25_lhs134);
  sf_mex_destroy(&c25_rhs135);
  sf_mex_destroy(&c25_lhs135);
  sf_mex_destroy(&c25_rhs136);
  sf_mex_destroy(&c25_lhs136);
  sf_mex_destroy(&c25_rhs137);
  sf_mex_destroy(&c25_lhs137);
  sf_mex_destroy(&c25_rhs138);
  sf_mex_destroy(&c25_lhs138);
  sf_mex_destroy(&c25_rhs139);
  sf_mex_destroy(&c25_lhs139);
  sf_mex_destroy(&c25_rhs140);
  sf_mex_destroy(&c25_lhs140);
  sf_mex_destroy(&c25_rhs141);
  sf_mex_destroy(&c25_lhs141);
  sf_mex_destroy(&c25_rhs142);
  sf_mex_destroy(&c25_lhs142);
  sf_mex_destroy(&c25_rhs143);
  sf_mex_destroy(&c25_lhs143);
  sf_mex_destroy(&c25_rhs144);
  sf_mex_destroy(&c25_lhs144);
  sf_mex_destroy(&c25_rhs145);
  sf_mex_destroy(&c25_lhs145);
  sf_mex_destroy(&c25_rhs146);
  sf_mex_destroy(&c25_lhs146);
  sf_mex_destroy(&c25_rhs147);
  sf_mex_destroy(&c25_lhs147);
  sf_mex_destroy(&c25_rhs148);
  sf_mex_destroy(&c25_lhs148);
  sf_mex_destroy(&c25_rhs149);
  sf_mex_destroy(&c25_lhs149);
  sf_mex_destroy(&c25_rhs150);
  sf_mex_destroy(&c25_lhs150);
  sf_mex_destroy(&c25_rhs151);
  sf_mex_destroy(&c25_lhs151);
  sf_mex_destroy(&c25_rhs152);
  sf_mex_destroy(&c25_lhs152);
  sf_mex_destroy(&c25_rhs153);
  sf_mex_destroy(&c25_lhs153);
  sf_mex_destroy(&c25_rhs154);
  sf_mex_destroy(&c25_lhs154);
  sf_mex_destroy(&c25_rhs155);
  sf_mex_destroy(&c25_lhs155);
  sf_mex_destroy(&c25_rhs156);
  sf_mex_destroy(&c25_lhs156);
  sf_mex_destroy(&c25_rhs157);
  sf_mex_destroy(&c25_lhs157);
  sf_mex_destroy(&c25_rhs158);
  sf_mex_destroy(&c25_lhs158);
  sf_mex_destroy(&c25_rhs159);
  sf_mex_destroy(&c25_lhs159);
  sf_mex_destroy(&c25_rhs160);
  sf_mex_destroy(&c25_lhs160);
  sf_mex_destroy(&c25_rhs161);
  sf_mex_destroy(&c25_lhs161);
  sf_mex_destroy(&c25_rhs162);
  sf_mex_destroy(&c25_lhs162);
  sf_mex_destroy(&c25_rhs163);
  sf_mex_destroy(&c25_lhs163);
  sf_mex_destroy(&c25_rhs164);
  sf_mex_destroy(&c25_lhs164);
  sf_mex_destroy(&c25_rhs165);
  sf_mex_destroy(&c25_lhs165);
  sf_mex_destroy(&c25_rhs166);
  sf_mex_destroy(&c25_lhs166);
  sf_mex_destroy(&c25_rhs167);
  sf_mex_destroy(&c25_lhs167);
  sf_mex_destroy(&c25_rhs168);
  sf_mex_destroy(&c25_lhs168);
  sf_mex_destroy(&c25_rhs169);
  sf_mex_destroy(&c25_lhs169);
  sf_mex_destroy(&c25_rhs170);
  sf_mex_destroy(&c25_lhs170);
  sf_mex_destroy(&c25_rhs171);
  sf_mex_destroy(&c25_lhs171);
  sf_mex_destroy(&c25_rhs172);
  sf_mex_destroy(&c25_lhs172);
  sf_mex_destroy(&c25_rhs173);
  sf_mex_destroy(&c25_lhs173);
  sf_mex_destroy(&c25_rhs174);
  sf_mex_destroy(&c25_lhs174);
  sf_mex_destroy(&c25_rhs175);
  sf_mex_destroy(&c25_lhs175);
  sf_mex_destroy(&c25_rhs176);
  sf_mex_destroy(&c25_lhs176);
  sf_mex_destroy(&c25_rhs177);
  sf_mex_destroy(&c25_lhs177);
  sf_mex_destroy(&c25_rhs178);
  sf_mex_destroy(&c25_lhs178);
  sf_mex_destroy(&c25_rhs179);
  sf_mex_destroy(&c25_lhs179);
  sf_mex_destroy(&c25_rhs180);
  sf_mex_destroy(&c25_lhs180);
  sf_mex_destroy(&c25_rhs181);
  sf_mex_destroy(&c25_lhs181);
  sf_mex_destroy(&c25_rhs182);
  sf_mex_destroy(&c25_lhs182);
  sf_mex_destroy(&c25_rhs183);
  sf_mex_destroy(&c25_lhs183);
  sf_mex_destroy(&c25_rhs184);
  sf_mex_destroy(&c25_lhs184);
  sf_mex_destroy(&c25_rhs185);
  sf_mex_destroy(&c25_lhs185);
  sf_mex_destroy(&c25_rhs186);
  sf_mex_destroy(&c25_lhs186);
  sf_mex_destroy(&c25_rhs187);
  sf_mex_destroy(&c25_lhs187);
  sf_mex_destroy(&c25_rhs188);
  sf_mex_destroy(&c25_lhs188);
  sf_mex_destroy(&c25_rhs189);
  sf_mex_destroy(&c25_lhs189);
  sf_mex_destroy(&c25_rhs190);
  sf_mex_destroy(&c25_lhs190);
  sf_mex_destroy(&c25_rhs191);
  sf_mex_destroy(&c25_lhs191);
}

static void c25_d_info_helper(const mxArray **c25_info)
{
  const mxArray *c25_rhs192 = NULL;
  const mxArray *c25_lhs192 = NULL;
  const mxArray *c25_rhs193 = NULL;
  const mxArray *c25_lhs193 = NULL;
  const mxArray *c25_rhs194 = NULL;
  const mxArray *c25_lhs194 = NULL;
  const mxArray *c25_rhs195 = NULL;
  const mxArray *c25_lhs195 = NULL;
  const mxArray *c25_rhs196 = NULL;
  const mxArray *c25_lhs196 = NULL;
  const mxArray *c25_rhs197 = NULL;
  const mxArray *c25_lhs197 = NULL;
  const mxArray *c25_rhs198 = NULL;
  const mxArray *c25_lhs198 = NULL;
  const mxArray *c25_rhs199 = NULL;
  const mxArray *c25_lhs199 = NULL;
  const mxArray *c25_rhs200 = NULL;
  const mxArray *c25_lhs200 = NULL;
  const mxArray *c25_rhs201 = NULL;
  const mxArray *c25_lhs201 = NULL;
  const mxArray *c25_rhs202 = NULL;
  const mxArray *c25_lhs202 = NULL;
  const mxArray *c25_rhs203 = NULL;
  const mxArray *c25_lhs203 = NULL;
  const mxArray *c25_rhs204 = NULL;
  const mxArray *c25_lhs204 = NULL;
  const mxArray *c25_rhs205 = NULL;
  const mxArray *c25_lhs205 = NULL;
  const mxArray *c25_rhs206 = NULL;
  const mxArray *c25_lhs206 = NULL;
  const mxArray *c25_rhs207 = NULL;
  const mxArray *c25_lhs207 = NULL;
  const mxArray *c25_rhs208 = NULL;
  const mxArray *c25_lhs208 = NULL;
  const mxArray *c25_rhs209 = NULL;
  const mxArray *c25_lhs209 = NULL;
  const mxArray *c25_rhs210 = NULL;
  const mxArray *c25_lhs210 = NULL;
  const mxArray *c25_rhs211 = NULL;
  const mxArray *c25_lhs211 = NULL;
  const mxArray *c25_rhs212 = NULL;
  const mxArray *c25_lhs212 = NULL;
  const mxArray *c25_rhs213 = NULL;
  const mxArray *c25_lhs213 = NULL;
  const mxArray *c25_rhs214 = NULL;
  const mxArray *c25_lhs214 = NULL;
  const mxArray *c25_rhs215 = NULL;
  const mxArray *c25_lhs215 = NULL;
  const mxArray *c25_rhs216 = NULL;
  const mxArray *c25_lhs216 = NULL;
  const mxArray *c25_rhs217 = NULL;
  const mxArray *c25_lhs217 = NULL;
  const mxArray *c25_rhs218 = NULL;
  const mxArray *c25_lhs218 = NULL;
  const mxArray *c25_rhs219 = NULL;
  const mxArray *c25_lhs219 = NULL;
  const mxArray *c25_rhs220 = NULL;
  const mxArray *c25_lhs220 = NULL;
  const mxArray *c25_rhs221 = NULL;
  const mxArray *c25_lhs221 = NULL;
  const mxArray *c25_rhs222 = NULL;
  const mxArray *c25_lhs222 = NULL;
  const mxArray *c25_rhs223 = NULL;
  const mxArray *c25_lhs223 = NULL;
  const mxArray *c25_rhs224 = NULL;
  const mxArray *c25_lhs224 = NULL;
  const mxArray *c25_rhs225 = NULL;
  const mxArray *c25_lhs225 = NULL;
  const mxArray *c25_rhs226 = NULL;
  const mxArray *c25_lhs226 = NULL;
  const mxArray *c25_rhs227 = NULL;
  const mxArray *c25_lhs227 = NULL;
  const mxArray *c25_rhs228 = NULL;
  const mxArray *c25_lhs228 = NULL;
  const mxArray *c25_rhs229 = NULL;
  const mxArray *c25_lhs229 = NULL;
  const mxArray *c25_rhs230 = NULL;
  const mxArray *c25_lhs230 = NULL;
  const mxArray *c25_rhs231 = NULL;
  const mxArray *c25_lhs231 = NULL;
  const mxArray *c25_rhs232 = NULL;
  const mxArray *c25_lhs232 = NULL;
  const mxArray *c25_rhs233 = NULL;
  const mxArray *c25_lhs233 = NULL;
  const mxArray *c25_rhs234 = NULL;
  const mxArray *c25_lhs234 = NULL;
  const mxArray *c25_rhs235 = NULL;
  const mxArray *c25_lhs235 = NULL;
  const mxArray *c25_rhs236 = NULL;
  const mxArray *c25_lhs236 = NULL;
  const mxArray *c25_rhs237 = NULL;
  const mxArray *c25_lhs237 = NULL;
  const mxArray *c25_rhs238 = NULL;
  const mxArray *c25_lhs238 = NULL;
  const mxArray *c25_rhs239 = NULL;
  const mxArray *c25_lhs239 = NULL;
  const mxArray *c25_rhs240 = NULL;
  const mxArray *c25_lhs240 = NULL;
  const mxArray *c25_rhs241 = NULL;
  const mxArray *c25_lhs241 = NULL;
  const mxArray *c25_rhs242 = NULL;
  const mxArray *c25_lhs242 = NULL;
  const mxArray *c25_rhs243 = NULL;
  const mxArray *c25_lhs243 = NULL;
  const mxArray *c25_rhs244 = NULL;
  const mxArray *c25_lhs244 = NULL;
  const mxArray *c25_rhs245 = NULL;
  const mxArray *c25_lhs245 = NULL;
  const mxArray *c25_rhs246 = NULL;
  const mxArray *c25_lhs246 = NULL;
  const mxArray *c25_rhs247 = NULL;
  const mxArray *c25_lhs247 = NULL;
  const mxArray *c25_rhs248 = NULL;
  const mxArray *c25_lhs248 = NULL;
  const mxArray *c25_rhs249 = NULL;
  const mxArray *c25_lhs249 = NULL;
  const mxArray *c25_rhs250 = NULL;
  const mxArray *c25_lhs250 = NULL;
  const mxArray *c25_rhs251 = NULL;
  const mxArray *c25_lhs251 = NULL;
  const mxArray *c25_rhs252 = NULL;
  const mxArray *c25_lhs252 = NULL;
  const mxArray *c25_rhs253 = NULL;
  const mxArray *c25_lhs253 = NULL;
  const mxArray *c25_rhs254 = NULL;
  const mxArray *c25_lhs254 = NULL;
  const mxArray *c25_rhs255 = NULL;
  const mxArray *c25_lhs255 = NULL;
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_simtran"),
                  "context", "context", 192);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 192);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 192);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 192);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 192);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 192);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 192);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 192);
  sf_mex_assign(&c25_rhs192, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs192, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs192), "rhs",
                  "rhs", 192);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs192), "lhs",
                  "lhs", 192);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"),
                  "context", "context", 193);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 193);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 193);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 193);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 193);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 193);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 193);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 193);
  sf_mex_assign(&c25_rhs193, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs193, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs193), "rhs",
                  "rhs", 193);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs193), "lhs",
                  "lhs", 193);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_cols"),
                  "context", "context", 194);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 194);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 194);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 194);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 194);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 194);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 194);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 194);
  sf_mex_assign(&c25_rhs194, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs194, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs194), "rhs",
                  "rhs", 194);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs194), "lhs",
                  "lhs", 194);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_cols"),
                  "context", "context", 195);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 195);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 195);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 195);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 195);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 195);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 195);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 195);
  sf_mex_assign(&c25_rhs195, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs195, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs195), "rhs",
                  "rhs", 195);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs195), "lhs",
                  "lhs", 195);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"),
                  "context", "context", 196);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 196);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 196);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 196);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 196);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 196);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 196);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 196);
  sf_mex_assign(&c25_rhs196, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs196, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs196), "rhs",
                  "rhs", 196);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs196), "lhs",
                  "lhs", 196);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 197);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zgghrd"), "name",
                  "name", 197);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 197);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "resolved", "resolved", 197);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786420U), "fileTimeLo",
                  "fileTimeLo", 197);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 197);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 197);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 197);
  sf_mex_assign(&c25_rhs197, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs197, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs197), "rhs",
                  "rhs", 197);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs197), "lhs",
                  "lhs", 197);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 198);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 198);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 198);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 198);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 198);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 198);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 198);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 198);
  sf_mex_assign(&c25_rhs198, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs198, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs198), "rhs",
                  "rhs", 198);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs198), "lhs",
                  "lhs", 198);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 199);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 199);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 199);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 199);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 199);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 199);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 199);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 199);
  sf_mex_assign(&c25_rhs199, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs199, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs199), "rhs",
                  "rhs", 199);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs199), "lhs",
                  "lhs", 199);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 200);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 200);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 200);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 200);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 200);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 200);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 200);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 200);
  sf_mex_assign(&c25_rhs200, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs200, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs200), "rhs",
                  "rhs", 200);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs200), "lhs",
                  "lhs", 200);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 201);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 201);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 201);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 201);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 201);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 201);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 201);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 201);
  sf_mex_assign(&c25_rhs201, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs201, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs201), "rhs",
                  "rhs", 201);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs201), "lhs",
                  "lhs", 201);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 202);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 202);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 202);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 202);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 202);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 202);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 202);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 202);
  sf_mex_assign(&c25_rhs202, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs202, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs202), "rhs",
                  "rhs", 202);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs202), "lhs",
                  "lhs", 202);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 203);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zlartg"), "name",
                  "name", 203);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 203);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "resolved", "resolved", 203);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786422U), "fileTimeLo",
                  "fileTimeLo", 203);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 203);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 203);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 203);
  sf_mex_assign(&c25_rhs203, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs203, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs203), "rhs",
                  "rhs", 203);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs203), "lhs",
                  "lhs", 203);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 204);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmin"), "name", "name",
                  204);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 204);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 204);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 204);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 204);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 204);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 204);
  sf_mex_assign(&c25_rhs204, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs204, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs204), "rhs",
                  "rhs", 204);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs204), "lhs",
                  "lhs", 204);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 205);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 205);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 205);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 205);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 205);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 205);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 205);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 205);
  sf_mex_assign(&c25_rhs205, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs205, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs205), "rhs",
                  "rhs", 205);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs205), "lhs",
                  "lhs", 205);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 206);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("fix"), "name", "name", 206);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 206);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m"), "resolved",
                  "resolved", 206);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 206);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 206);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 206);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 206);
  sf_mex_assign(&c25_rhs206, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs206, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs206), "rhs",
                  "rhs", 206);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs206), "lhs",
                  "lhs", 206);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m"), "context",
                  "context", 207);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 207);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 207);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 207);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 207);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 207);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 207);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 207);
  sf_mex_assign(&c25_rhs207, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs207, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs207), "rhs",
                  "rhs", 207);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs207), "lhs",
                  "lhs", 207);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m"), "context",
                  "context", 208);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_fix"), "name",
                  "name", 208);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 208);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_fix.m"),
                  "resolved", "resolved", 208);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622438U), "fileTimeLo",
                  "fileTimeLo", 208);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 208);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 208);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 208);
  sf_mex_assign(&c25_rhs208, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs208, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs208), "rhs",
                  "rhs", 208);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs208), "lhs",
                  "lhs", 208);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 209);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mpower"), "name", "name",
                  209);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 209);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 209);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677878U), "fileTimeLo",
                  "fileTimeLo", 209);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 209);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 209);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 209);
  sf_mex_assign(&c25_rhs209, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs209, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs209), "rhs",
                  "rhs", 209);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs209), "lhs",
                  "lhs", 209);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 210);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 210);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 210);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 210);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 210);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 210);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 210);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 210);
  sf_mex_assign(&c25_rhs210, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs210, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs210), "rhs",
                  "rhs", 210);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs210), "lhs",
                  "lhs", 210);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m!absinf"),
                  "context", "context", 211);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 211);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 211);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 211);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 211);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 211);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 211);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 211);
  sf_mex_assign(&c25_rhs211, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs211, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs211), "rhs",
                  "rhs", 211);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs211), "lhs",
                  "lhs", 211);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 212);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 212);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 212);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 212);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 212);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 212);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 212);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 212);
  sf_mex_assign(&c25_rhs212, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs212, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs212), "rhs",
                  "rhs", 212);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs212), "lhs",
                  "lhs", 212);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 213);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 213);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 213);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 213);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 213);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 213);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 213);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 213);
  sf_mex_assign(&c25_rhs213, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs213, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs213), "rhs",
                  "rhs", 213);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs213), "lhs",
                  "lhs", 213);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 214);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_dlapy2"), "name", "name",
                  214);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 214);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                  "resolved", 214);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1350378254U), "fileTimeLo",
                  "fileTimeLo", 214);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 214);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 214);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 214);
  sf_mex_assign(&c25_rhs214, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs214, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs214), "rhs",
                  "rhs", 214);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs214), "lhs",
                  "lhs", 214);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 215);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("sqrt"), "name", "name", 215);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 215);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 215);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 215);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 215);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 215);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 215);
  sf_mex_assign(&c25_rhs215, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs215, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs215), "rhs",
                  "rhs", 215);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs215), "lhs",
                  "lhs", 215);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 216);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 216);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 216);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 216);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 216);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 216);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 216);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 216);
  sf_mex_assign(&c25_rhs216, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs216, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs216), "rhs",
                  "rhs", 216);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs216), "lhs",
                  "lhs", 216);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 217);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_zrot_rows"), "name",
                  "name", 217);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 217);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "resolved", "resolved", 217);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1360246352U), "fileTimeLo",
                  "fileTimeLo", 217);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 217);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 217);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 217);
  sf_mex_assign(&c25_rhs217, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs217, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs217), "rhs",
                  "rhs", 217);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs217), "lhs",
                  "lhs", 217);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "context", "context", 218);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 218);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 218);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 218);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 218);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 218);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 218);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 218);
  sf_mex_assign(&c25_rhs218, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs218, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs218), "rhs",
                  "rhs", 218);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs218), "lhs",
                  "lhs", 218);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "context", "context", 219);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 219);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 219);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 219);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 219);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 219);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 219);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 219);
  sf_mex_assign(&c25_rhs219, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs219, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs219), "rhs",
                  "rhs", 219);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs219), "lhs",
                  "lhs", 219);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "context", "context", 220);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.conjtimes"),
                  "name", "name", 220);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 220);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/conjtimes.m"),
                  "resolved", "resolved", 220);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1360246586U), "fileTimeLo",
                  "fileTimeLo", 220);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 220);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 220);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 220);
  sf_mex_assign(&c25_rhs220, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs220, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs220), "rhs",
                  "rhs", 220);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs220), "lhs",
                  "lhs", 220);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 221);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_zrot_cols"), "name",
                  "name", 221);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 221);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "resolved", "resolved", 221);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1360246350U), "fileTimeLo",
                  "fileTimeLo", 221);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 221);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 221);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 221);
  sf_mex_assign(&c25_rhs221, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs221, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs221), "rhs",
                  "rhs", 221);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs221), "lhs",
                  "lhs", 221);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "context", "context", 222);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 222);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 222);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 222);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 222);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 222);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 222);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 222);
  sf_mex_assign(&c25_rhs222, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs222, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs222), "rhs",
                  "rhs", 222);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs222), "lhs",
                  "lhs", 222);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "context", "context", 223);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 223);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 223);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 223);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 223);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 223);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 223);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 223);
  sf_mex_assign(&c25_rhs223, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs223, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs223), "rhs",
                  "rhs", 223);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs223), "lhs",
                  "lhs", 223);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "context", "context", 224);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.conjtimes"),
                  "name", "name", 224);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 224);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/conjtimes.m"),
                  "resolved", "resolved", 224);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1360246586U), "fileTimeLo",
                  "fileTimeLo", 224);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 224);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 224);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 224);
  sf_mex_assign(&c25_rhs224, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs224, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs224), "rhs",
                  "rhs", 224);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs224), "lhs",
                  "lhs", 224);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 225);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zhgeqz"), "name",
                  "name", 225);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 225);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "resolved", "resolved", 225);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 225);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 225);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 225);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 225);
  sf_mex_assign(&c25_rhs225, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs225, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs225), "rhs",
                  "rhs", 225);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs225), "lhs",
                  "lhs", 225);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 226);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 226);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 226);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 226);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 226);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 226);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 226);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 226);
  sf_mex_assign(&c25_rhs226, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs226, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs226), "rhs",
                  "rhs", 226);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs226), "lhs",
                  "lhs", 226);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 227);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 227);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 227);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 227);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 227);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 227);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 227);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 227);
  sf_mex_assign(&c25_rhs227, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs227, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs227), "rhs",
                  "rhs", 227);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs227), "lhs",
                  "lhs", 227);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 228);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmin"), "name", "name",
                  228);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 228);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 228);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 228);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 228);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 228);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 228);
  sf_mex_assign(&c25_rhs228, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs228, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs228), "rhs",
                  "rhs", 228);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs228), "lhs",
                  "lhs", 228);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 229);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zlanhs"), "name",
                  "name", 229);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 229);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "resolved", "resolved", 229);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786420U), "fileTimeLo",
                  "fileTimeLo", 229);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 229);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 229);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 229);
  sf_mex_assign(&c25_rhs229, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs229, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs229), "rhs",
                  "rhs", 229);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs229), "lhs",
                  "lhs", 229);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 230);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 230);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 230);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 230);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 230);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 230);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 230);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 230);
  sf_mex_assign(&c25_rhs230, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs230, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs230), "rhs",
                  "rhs", 230);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs230), "lhs",
                  "lhs", 230);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 231);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 231);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 231);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 231);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 231);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 231);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 231);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 231);
  sf_mex_assign(&c25_rhs231, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs231, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs231), "rhs",
                  "rhs", 231);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs231), "lhs",
                  "lhs", 231);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 232);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 232);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 232);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 232);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 232);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 232);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 232);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 232);
  sf_mex_assign(&c25_rhs232, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs232, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs232), "rhs",
                  "rhs", 232);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs232), "lhs",
                  "lhs", 232);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 233);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 233);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 233);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 233);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 233);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 233);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 233);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 233);
  sf_mex_assign(&c25_rhs233, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs233, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs233), "rhs",
                  "rhs", 233);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs233), "lhs",
                  "lhs", 233);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 234);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("sqrt"), "name", "name", 234);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 234);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 234);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 234);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 234);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 234);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 234);
  sf_mex_assign(&c25_rhs234, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs234, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs234), "rhs",
                  "rhs", 234);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs234), "lhs",
                  "lhs", 234);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 235);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 235);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 235);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 235);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 235);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 235);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 235);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 235);
  sf_mex_assign(&c25_rhs235, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs235, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs235), "rhs",
                  "rhs", 235);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs235), "lhs",
                  "lhs", 235);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 236);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 236);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 236);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 236);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 236);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 236);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 236);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 236);
  sf_mex_assign(&c25_rhs236, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs236, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs236), "rhs",
                  "rhs", 236);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs236), "lhs",
                  "lhs", 236);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 237);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 237);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 237);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 237);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 237);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 237);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 237);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 237);
  sf_mex_assign(&c25_rhs237, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs237, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs237), "rhs",
                  "rhs", 237);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs237), "lhs",
                  "lhs", 237);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 238);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 238);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 238);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 238);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 238);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 238);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 238);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 238);
  sf_mex_assign(&c25_rhs238, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs238, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs238), "rhs",
                  "rhs", 238);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs238), "lhs",
                  "lhs", 238);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 239);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 239);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 239);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 239);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 239);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 239);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 239);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 239);
  sf_mex_assign(&c25_rhs239, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs239, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs239), "rhs",
                  "rhs", 239);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs239), "lhs",
                  "lhs", 239);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m!abs1"),
                  "context", "context", 240);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 240);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 240);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 240);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 240);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 240);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 240);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 240);
  sf_mex_assign(&c25_rhs240, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs240, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs240), "rhs",
                  "rhs", 240);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs240), "lhs",
                  "lhs", 240);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 241);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 241);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 241);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 241);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 241);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 241);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 241);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 241);
  sf_mex_assign(&c25_rhs241, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs241, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs241), "rhs",
                  "rhs", 241);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs241), "lhs",
                  "lhs", 241);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 242);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_matlab_zlartg"), "name",
                  "name", 242);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 242);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "resolved", "resolved", 242);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786422U), "fileTimeLo",
                  "fileTimeLo", 242);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 242);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 242);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 242);
  sf_mex_assign(&c25_rhs242, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs242, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs242), "rhs",
                  "rhs", 242);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs242), "lhs",
                  "lhs", 242);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 243);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_zrot_cols"), "name",
                  "name", 243);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 243);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "resolved", "resolved", 243);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1360246350U), "fileTimeLo",
                  "fileTimeLo", 243);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 243);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 243);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 243);
  sf_mex_assign(&c25_rhs243, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs243, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs243), "rhs",
                  "rhs", 243);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs243), "lhs",
                  "lhs", 243);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 244);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mod"), "name", "name", 244);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 244);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "resolved",
                  "resolved", 244);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677854U), "fileTimeLo",
                  "fileTimeLo", 244);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 244);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 244);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 244);
  sf_mex_assign(&c25_rhs244, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs244, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs244), "rhs",
                  "rhs", 244);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs244), "lhs",
                  "lhs", 244);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 245);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 245);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 245);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 245);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 245);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 245);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 245);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 245);
  sf_mex_assign(&c25_rhs245, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs245, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs245), "rhs",
                  "rhs", 245);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs245), "lhs",
                  "lhs", 245);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 246);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 246);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 246);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 246);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 246);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 246);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 246);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 246);
  sf_mex_assign(&c25_rhs246, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs246, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs246), "rhs",
                  "rhs", 246);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs246), "lhs",
                  "lhs", 246);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 247);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 247);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 247);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 247);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 247);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 247);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 247);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 247);
  sf_mex_assign(&c25_rhs247, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs247, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs247), "rhs",
                  "rhs", 247);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs247), "lhs",
                  "lhs", 247);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 248);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 248);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 248);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 248);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 248);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 248);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 248);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 248);
  sf_mex_assign(&c25_rhs248, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs248, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs248), "rhs",
                  "rhs", 248);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs248), "lhs",
                  "lhs", 248);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 249);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 249);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 249);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 249);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 249);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 249);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 249);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 249);
  sf_mex_assign(&c25_rhs249, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs249, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs249), "rhs",
                  "rhs", 249);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs249), "lhs",
                  "lhs", 249);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!intmod"), "context",
                  "context", 250);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 250);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 250);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 250);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 250);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 250);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 250);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 250);
  sf_mex_assign(&c25_rhs250, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs250, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs250), "rhs",
                  "rhs", 250);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs250), "lhs",
                  "lhs", 250);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 251);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_div"), "name", "name",
                  251);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 251);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 251);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 251);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 251);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 251);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 251);
  sf_mex_assign(&c25_rhs251, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs251, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs251), "rhs",
                  "rhs", 251);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs251), "lhs",
                  "lhs", 251);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                  "context", "context", 252);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 252);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 252);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 252);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 252);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 252);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 252);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 252);
  sf_mex_assign(&c25_rhs252, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs252, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs252), "rhs",
                  "rhs", 252);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs252), "lhs",
                  "lhs", 252);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                  "context", "context", 253);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 253);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 253);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 253);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 253);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 253);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 253);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 253);
  sf_mex_assign(&c25_rhs253, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs253, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs253), "rhs",
                  "rhs", 253);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs253), "lhs",
                  "lhs", 253);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                  "context", "context", 254);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 254);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 254);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 254);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 254);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 254);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 254);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 254);
  sf_mex_assign(&c25_rhs254, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs254, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs254), "rhs",
                  "rhs", 254);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs254), "lhs",
                  "lhs", 254);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 255);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("sqrt"), "name", "name", 255);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 255);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 255);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 255);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 255);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 255);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 255);
  sf_mex_assign(&c25_rhs255, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs255, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs255), "rhs",
                  "rhs", 255);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs255), "lhs",
                  "lhs", 255);
  sf_mex_destroy(&c25_rhs192);
  sf_mex_destroy(&c25_lhs192);
  sf_mex_destroy(&c25_rhs193);
  sf_mex_destroy(&c25_lhs193);
  sf_mex_destroy(&c25_rhs194);
  sf_mex_destroy(&c25_lhs194);
  sf_mex_destroy(&c25_rhs195);
  sf_mex_destroy(&c25_lhs195);
  sf_mex_destroy(&c25_rhs196);
  sf_mex_destroy(&c25_lhs196);
  sf_mex_destroy(&c25_rhs197);
  sf_mex_destroy(&c25_lhs197);
  sf_mex_destroy(&c25_rhs198);
  sf_mex_destroy(&c25_lhs198);
  sf_mex_destroy(&c25_rhs199);
  sf_mex_destroy(&c25_lhs199);
  sf_mex_destroy(&c25_rhs200);
  sf_mex_destroy(&c25_lhs200);
  sf_mex_destroy(&c25_rhs201);
  sf_mex_destroy(&c25_lhs201);
  sf_mex_destroy(&c25_rhs202);
  sf_mex_destroy(&c25_lhs202);
  sf_mex_destroy(&c25_rhs203);
  sf_mex_destroy(&c25_lhs203);
  sf_mex_destroy(&c25_rhs204);
  sf_mex_destroy(&c25_lhs204);
  sf_mex_destroy(&c25_rhs205);
  sf_mex_destroy(&c25_lhs205);
  sf_mex_destroy(&c25_rhs206);
  sf_mex_destroy(&c25_lhs206);
  sf_mex_destroy(&c25_rhs207);
  sf_mex_destroy(&c25_lhs207);
  sf_mex_destroy(&c25_rhs208);
  sf_mex_destroy(&c25_lhs208);
  sf_mex_destroy(&c25_rhs209);
  sf_mex_destroy(&c25_lhs209);
  sf_mex_destroy(&c25_rhs210);
  sf_mex_destroy(&c25_lhs210);
  sf_mex_destroy(&c25_rhs211);
  sf_mex_destroy(&c25_lhs211);
  sf_mex_destroy(&c25_rhs212);
  sf_mex_destroy(&c25_lhs212);
  sf_mex_destroy(&c25_rhs213);
  sf_mex_destroy(&c25_lhs213);
  sf_mex_destroy(&c25_rhs214);
  sf_mex_destroy(&c25_lhs214);
  sf_mex_destroy(&c25_rhs215);
  sf_mex_destroy(&c25_lhs215);
  sf_mex_destroy(&c25_rhs216);
  sf_mex_destroy(&c25_lhs216);
  sf_mex_destroy(&c25_rhs217);
  sf_mex_destroy(&c25_lhs217);
  sf_mex_destroy(&c25_rhs218);
  sf_mex_destroy(&c25_lhs218);
  sf_mex_destroy(&c25_rhs219);
  sf_mex_destroy(&c25_lhs219);
  sf_mex_destroy(&c25_rhs220);
  sf_mex_destroy(&c25_lhs220);
  sf_mex_destroy(&c25_rhs221);
  sf_mex_destroy(&c25_lhs221);
  sf_mex_destroy(&c25_rhs222);
  sf_mex_destroy(&c25_lhs222);
  sf_mex_destroy(&c25_rhs223);
  sf_mex_destroy(&c25_lhs223);
  sf_mex_destroy(&c25_rhs224);
  sf_mex_destroy(&c25_lhs224);
  sf_mex_destroy(&c25_rhs225);
  sf_mex_destroy(&c25_lhs225);
  sf_mex_destroy(&c25_rhs226);
  sf_mex_destroy(&c25_lhs226);
  sf_mex_destroy(&c25_rhs227);
  sf_mex_destroy(&c25_lhs227);
  sf_mex_destroy(&c25_rhs228);
  sf_mex_destroy(&c25_lhs228);
  sf_mex_destroy(&c25_rhs229);
  sf_mex_destroy(&c25_lhs229);
  sf_mex_destroy(&c25_rhs230);
  sf_mex_destroy(&c25_lhs230);
  sf_mex_destroy(&c25_rhs231);
  sf_mex_destroy(&c25_lhs231);
  sf_mex_destroy(&c25_rhs232);
  sf_mex_destroy(&c25_lhs232);
  sf_mex_destroy(&c25_rhs233);
  sf_mex_destroy(&c25_lhs233);
  sf_mex_destroy(&c25_rhs234);
  sf_mex_destroy(&c25_lhs234);
  sf_mex_destroy(&c25_rhs235);
  sf_mex_destroy(&c25_lhs235);
  sf_mex_destroy(&c25_rhs236);
  sf_mex_destroy(&c25_lhs236);
  sf_mex_destroy(&c25_rhs237);
  sf_mex_destroy(&c25_lhs237);
  sf_mex_destroy(&c25_rhs238);
  sf_mex_destroy(&c25_lhs238);
  sf_mex_destroy(&c25_rhs239);
  sf_mex_destroy(&c25_lhs239);
  sf_mex_destroy(&c25_rhs240);
  sf_mex_destroy(&c25_lhs240);
  sf_mex_destroy(&c25_rhs241);
  sf_mex_destroy(&c25_lhs241);
  sf_mex_destroy(&c25_rhs242);
  sf_mex_destroy(&c25_lhs242);
  sf_mex_destroy(&c25_rhs243);
  sf_mex_destroy(&c25_lhs243);
  sf_mex_destroy(&c25_rhs244);
  sf_mex_destroy(&c25_lhs244);
  sf_mex_destroy(&c25_rhs245);
  sf_mex_destroy(&c25_lhs245);
  sf_mex_destroy(&c25_rhs246);
  sf_mex_destroy(&c25_lhs246);
  sf_mex_destroy(&c25_rhs247);
  sf_mex_destroy(&c25_lhs247);
  sf_mex_destroy(&c25_rhs248);
  sf_mex_destroy(&c25_lhs248);
  sf_mex_destroy(&c25_rhs249);
  sf_mex_destroy(&c25_lhs249);
  sf_mex_destroy(&c25_rhs250);
  sf_mex_destroy(&c25_lhs250);
  sf_mex_destroy(&c25_rhs251);
  sf_mex_destroy(&c25_lhs251);
  sf_mex_destroy(&c25_rhs252);
  sf_mex_destroy(&c25_lhs252);
  sf_mex_destroy(&c25_rhs253);
  sf_mex_destroy(&c25_lhs253);
  sf_mex_destroy(&c25_rhs254);
  sf_mex_destroy(&c25_lhs254);
  sf_mex_destroy(&c25_rhs255);
  sf_mex_destroy(&c25_lhs255);
}

static void c25_e_info_helper(const mxArray **c25_info)
{
  const mxArray *c25_rhs256 = NULL;
  const mxArray *c25_lhs256 = NULL;
  const mxArray *c25_rhs257 = NULL;
  const mxArray *c25_lhs257 = NULL;
  const mxArray *c25_rhs258 = NULL;
  const mxArray *c25_lhs258 = NULL;
  const mxArray *c25_rhs259 = NULL;
  const mxArray *c25_lhs259 = NULL;
  const mxArray *c25_rhs260 = NULL;
  const mxArray *c25_lhs260 = NULL;
  const mxArray *c25_rhs261 = NULL;
  const mxArray *c25_lhs261 = NULL;
  const mxArray *c25_rhs262 = NULL;
  const mxArray *c25_lhs262 = NULL;
  const mxArray *c25_rhs263 = NULL;
  const mxArray *c25_lhs263 = NULL;
  const mxArray *c25_rhs264 = NULL;
  const mxArray *c25_lhs264 = NULL;
  const mxArray *c25_rhs265 = NULL;
  const mxArray *c25_lhs265 = NULL;
  const mxArray *c25_rhs266 = NULL;
  const mxArray *c25_lhs266 = NULL;
  const mxArray *c25_rhs267 = NULL;
  const mxArray *c25_lhs267 = NULL;
  const mxArray *c25_rhs268 = NULL;
  const mxArray *c25_lhs268 = NULL;
  const mxArray *c25_rhs269 = NULL;
  const mxArray *c25_lhs269 = NULL;
  const mxArray *c25_rhs270 = NULL;
  const mxArray *c25_lhs270 = NULL;
  const mxArray *c25_rhs271 = NULL;
  const mxArray *c25_lhs271 = NULL;
  const mxArray *c25_rhs272 = NULL;
  const mxArray *c25_lhs272 = NULL;
  const mxArray *c25_rhs273 = NULL;
  const mxArray *c25_lhs273 = NULL;
  const mxArray *c25_rhs274 = NULL;
  const mxArray *c25_lhs274 = NULL;
  const mxArray *c25_rhs275 = NULL;
  const mxArray *c25_lhs275 = NULL;
  const mxArray *c25_rhs276 = NULL;
  const mxArray *c25_lhs276 = NULL;
  const mxArray *c25_rhs277 = NULL;
  const mxArray *c25_lhs277 = NULL;
  const mxArray *c25_rhs278 = NULL;
  const mxArray *c25_lhs278 = NULL;
  const mxArray *c25_rhs279 = NULL;
  const mxArray *c25_lhs279 = NULL;
  const mxArray *c25_rhs280 = NULL;
  const mxArray *c25_lhs280 = NULL;
  const mxArray *c25_rhs281 = NULL;
  const mxArray *c25_lhs281 = NULL;
  const mxArray *c25_rhs282 = NULL;
  const mxArray *c25_lhs282 = NULL;
  const mxArray *c25_rhs283 = NULL;
  const mxArray *c25_lhs283 = NULL;
  const mxArray *c25_rhs284 = NULL;
  const mxArray *c25_lhs284 = NULL;
  const mxArray *c25_rhs285 = NULL;
  const mxArray *c25_lhs285 = NULL;
  const mxArray *c25_rhs286 = NULL;
  const mxArray *c25_lhs286 = NULL;
  const mxArray *c25_rhs287 = NULL;
  const mxArray *c25_lhs287 = NULL;
  const mxArray *c25_rhs288 = NULL;
  const mxArray *c25_lhs288 = NULL;
  const mxArray *c25_rhs289 = NULL;
  const mxArray *c25_lhs289 = NULL;
  const mxArray *c25_rhs290 = NULL;
  const mxArray *c25_lhs290 = NULL;
  const mxArray *c25_rhs291 = NULL;
  const mxArray *c25_lhs291 = NULL;
  const mxArray *c25_rhs292 = NULL;
  const mxArray *c25_lhs292 = NULL;
  const mxArray *c25_rhs293 = NULL;
  const mxArray *c25_lhs293 = NULL;
  const mxArray *c25_rhs294 = NULL;
  const mxArray *c25_lhs294 = NULL;
  const mxArray *c25_rhs295 = NULL;
  const mxArray *c25_lhs295 = NULL;
  const mxArray *c25_rhs296 = NULL;
  const mxArray *c25_lhs296 = NULL;
  const mxArray *c25_rhs297 = NULL;
  const mxArray *c25_lhs297 = NULL;
  const mxArray *c25_rhs298 = NULL;
  const mxArray *c25_lhs298 = NULL;
  const mxArray *c25_rhs299 = NULL;
  const mxArray *c25_lhs299 = NULL;
  const mxArray *c25_rhs300 = NULL;
  const mxArray *c25_lhs300 = NULL;
  const mxArray *c25_rhs301 = NULL;
  const mxArray *c25_lhs301 = NULL;
  const mxArray *c25_rhs302 = NULL;
  const mxArray *c25_lhs302 = NULL;
  const mxArray *c25_rhs303 = NULL;
  const mxArray *c25_lhs303 = NULL;
  const mxArray *c25_rhs304 = NULL;
  const mxArray *c25_lhs304 = NULL;
  const mxArray *c25_rhs305 = NULL;
  const mxArray *c25_lhs305 = NULL;
  const mxArray *c25_rhs306 = NULL;
  const mxArray *c25_lhs306 = NULL;
  const mxArray *c25_rhs307 = NULL;
  const mxArray *c25_lhs307 = NULL;
  const mxArray *c25_rhs308 = NULL;
  const mxArray *c25_lhs308 = NULL;
  const mxArray *c25_rhs309 = NULL;
  const mxArray *c25_lhs309 = NULL;
  const mxArray *c25_rhs310 = NULL;
  const mxArray *c25_lhs310 = NULL;
  const mxArray *c25_rhs311 = NULL;
  const mxArray *c25_lhs311 = NULL;
  const mxArray *c25_rhs312 = NULL;
  const mxArray *c25_lhs312 = NULL;
  const mxArray *c25_rhs313 = NULL;
  const mxArray *c25_lhs313 = NULL;
  const mxArray *c25_rhs314 = NULL;
  const mxArray *c25_lhs314 = NULL;
  const mxArray *c25_rhs315 = NULL;
  const mxArray *c25_lhs315 = NULL;
  const mxArray *c25_rhs316 = NULL;
  const mxArray *c25_lhs316 = NULL;
  const mxArray *c25_rhs317 = NULL;
  const mxArray *c25_lhs317 = NULL;
  const mxArray *c25_rhs318 = NULL;
  const mxArray *c25_lhs318 = NULL;
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 256);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("rdivide"), "name", "name",
                  256);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 256);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 256);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 256);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 256);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 256);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 256);
  sf_mex_assign(&c25_rhs256, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs256, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs256), "rhs",
                  "rhs", 256);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs256), "lhs",
                  "lhs", 256);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 257);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnan"), "name", "name", 257);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 257);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 257);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 257);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 257);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 257);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 257);
  sf_mex_assign(&c25_rhs257, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs257, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs257), "rhs",
                  "rhs", 257);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs257), "lhs",
                  "lhs", 257);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 258);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 258);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 258);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 258);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 258);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 258);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 258);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 258);
  sf_mex_assign(&c25_rhs258, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs258, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs258), "rhs",
                  "rhs", 258);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs258), "lhs",
                  "lhs", 258);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 259);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isinf"), "name", "name", 259);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 259);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 259);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 259);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 259);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 259);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 259);
  sf_mex_assign(&c25_rhs259, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs259, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs259), "rhs",
                  "rhs", 259);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs259), "lhs",
                  "lhs", 259);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 260);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_guarded_inf"), "name",
                  "name", 260);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 260);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m"),
                  "resolved", "resolved", 260);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 260);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 260);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 260);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 260);
  sf_mex_assign(&c25_rhs260, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs260, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs260), "rhs",
                  "rhs", 260);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs260), "lhs",
                  "lhs", 260);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m"),
                  "context", "context", 261);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 261);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 261);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 261);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 261);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 261);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 261);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 261);
  sf_mex_assign(&c25_rhs261, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs261, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs261), "rhs",
                  "rhs", 261);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs261), "lhs",
                  "lhs", 261);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 262);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmax"), "name", "name",
                  262);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 262);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 262);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 262);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 262);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 262);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 262);
  sf_mex_assign(&c25_rhs262, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs262, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs262), "rhs",
                  "rhs", 262);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs262), "lhs",
                  "lhs", 262);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 263);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 263);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 263);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 263);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 263);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 263);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 263);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 263);
  sf_mex_assign(&c25_rhs263, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs263, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs263), "rhs",
                  "rhs", 263);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs263), "lhs",
                  "lhs", 263);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 264);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 264);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 264);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 264);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 264);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 264);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 264);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 264);
  sf_mex_assign(&c25_rhs264, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs264, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs264), "rhs",
                  "rhs", 264);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs264), "lhs",
                  "lhs", 264);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 265);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  265);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 265);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 265);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 265);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 265);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 265);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 265);
  sf_mex_assign(&c25_rhs265, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs265, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs265), "rhs",
                  "rhs", 265);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs265), "lhs",
                  "lhs", 265);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 266);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_hypot"), "name",
                  "name", 266);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 266);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "resolved", "resolved", 266);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 266);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 266);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 266);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 266);
  sf_mex_assign(&c25_rhs266, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs266, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs266), "rhs",
                  "rhs", 266);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs266), "lhs",
                  "lhs", 266);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "context", "context", 267);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 267);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 267);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 267);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 267);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 267);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 267);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 267);
  sf_mex_assign(&c25_rhs267, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs267, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs267), "rhs",
                  "rhs", 267);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs267), "lhs",
                  "lhs", 267);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "context", "context", 268);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_dlapy2"), "name", "name",
                  268);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 268);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                  "resolved", 268);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1350378254U), "fileTimeLo",
                  "fileTimeLo", 268);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 268);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 268);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 268);
  sf_mex_assign(&c25_rhs268, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs268, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs268), "rhs",
                  "rhs", 268);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs268), "lhs",
                  "lhs", 268);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 269);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 269);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 269);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 269);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 269);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 269);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 269);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 269);
  sf_mex_assign(&c25_rhs269, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs269, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs269), "rhs",
                  "rhs", 269);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs269), "lhs",
                  "lhs", 269);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 270);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_zrot_rows"), "name",
                  "name", 270);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 270);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "resolved", "resolved", 270);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1360246352U), "fileTimeLo",
                  "fileTimeLo", 270);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 270);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 270);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 270);
  sf_mex_assign(&c25_rhs270, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs270, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs270), "rhs",
                  "rhs", 270);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs270), "lhs",
                  "lhs", 270);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m!makeD"), "context",
                  "context", 271);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("rdivide"), "name", "name",
                  271);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 271);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 271);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 271);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 271);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 271);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 271);
  sf_mex_assign(&c25_rhs271, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs271, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs271), "rhs",
                  "rhs", 271);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs271), "lhs",
                  "lhs", 271);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "context", "context", 272);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isequal"), "name", "name",
                  272);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 272);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 272);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786358U), "fileTimeLo",
                  "fileTimeLo", 272);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 272);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 272);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 272);
  sf_mex_assign(&c25_rhs272, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs272, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs272), "rhs",
                  "rhs", 272);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs272), "lhs",
                  "lhs", 272);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 273);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 273);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 273);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 273);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786386U), "fileTimeLo",
                  "fileTimeLo", 273);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 273);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 273);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 273);
  sf_mex_assign(&c25_rhs273, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs273, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs273), "rhs",
                  "rhs", 273);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs273), "lhs",
                  "lhs", 273);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 274);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnan"), "name", "name", 274);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 274);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 274);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 274);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 274);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 274);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 274);
  sf_mex_assign(&c25_rhs274, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs274, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs274), "rhs",
                  "rhs", 274);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs274), "lhs",
                  "lhs", 274);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p!equalsize"),
                  "context", "context", 275);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("max"), "name", "name", 275);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 275);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 275);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 275);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 275);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 275);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 275);
  sf_mex_assign(&c25_rhs275, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs275, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs275), "rhs",
                  "rhs", 275);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs275), "lhs",
                  "lhs", 275);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "context",
                  "context", 276);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_warning"), "name",
                  "name", 276);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 276);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 276);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786402U), "fileTimeLo",
                  "fileTimeLo", 276);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 276);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 276);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 276);
  sf_mex_assign(&c25_rhs276, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs276, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs276), "rhs",
                  "rhs", 276);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs276), "lhs",
                  "lhs", 276);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context",
                  277);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("min"), "name", "name", 277);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 277);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 277);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1311226518U), "fileTimeLo",
                  "fileTimeLo", 277);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 277);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 277);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 277);
  sf_mex_assign(&c25_rhs277, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs277, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs277), "rhs",
                  "rhs", 277);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs277), "lhs",
                  "lhs", 277);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 278);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmax"), "name", "name",
                  278);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 278);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 278);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 278);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 278);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 278);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 278);
  sf_mex_assign(&c25_rhs278, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs278, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs278), "rhs",
                  "rhs", 278);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs278), "lhs",
                  "lhs", 278);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 279);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  279);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 279);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 279);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 279);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 279);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 279);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 279);
  sf_mex_assign(&c25_rhs279, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs279, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs279), "rhs",
                  "rhs", 279);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs279), "lhs",
                  "lhs", 279);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 280);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 280);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 280);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 280);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 280);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 280);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 280);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 280);
  sf_mex_assign(&c25_rhs280, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs280, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs280), "rhs",
                  "rhs", 280);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs280), "lhs",
                  "lhs", 280);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 281);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("hypot"), "name", "name", 281);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 281);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "resolved",
                  "resolved", 281);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395292500U), "fileTimeLo",
                  "fileTimeLo", 281);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 281);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 281);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 281);
  sf_mex_assign(&c25_rhs281, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs281, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs281), "rhs",
                  "rhs", 281);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs281), "lhs",
                  "lhs", 281);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 282);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 282);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 282);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 282);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 282);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 282);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 282);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 282);
  sf_mex_assign(&c25_rhs282, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs282, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs282), "rhs",
                  "rhs", 282);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs282), "lhs",
                  "lhs", 282);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 283);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 283);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 283);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 283);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 283);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 283);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 283);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 283);
  sf_mex_assign(&c25_rhs283, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs283, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs283), "rhs",
                  "rhs", 283);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs283), "lhs",
                  "lhs", 283);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 284);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_hypot"), "name",
                  "name", 284);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 284);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "resolved", "resolved", 284);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 284);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 284);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 284);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 284);
  sf_mex_assign(&c25_rhs284, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs284, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs284), "rhs",
                  "rhs", 284);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs284), "lhs",
                  "lhs", 284);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 285);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_safe_eq"), "name",
                  "name", 285);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 285);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "resolved",
                  "resolved", 285);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1383841286U), "fileTimeLo",
                  "fileTimeLo", 285);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 285);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 285);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 285);
  sf_mex_assign(&c25_rhs285, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs285, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs285), "rhs",
                  "rhs", 285);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs285), "lhs",
                  "lhs", 285);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 286);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 286);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 286);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 286);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 286);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 286);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 286);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 286);
  sf_mex_assign(&c25_rhs286, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs286, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs286), "rhs",
                  "rhs", 286);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs286), "lhs",
                  "lhs", 286);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 287);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  287);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 287);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 287);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 287);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 287);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 287);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 287);
  sf_mex_assign(&c25_rhs287, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs287, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs287), "rhs",
                  "rhs", 287);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs287), "lhs",
                  "lhs", 287);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 288);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 288);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 288);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 288);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 288);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 288);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 288);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 288);
  sf_mex_assign(&c25_rhs288, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs288, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs288), "rhs",
                  "rhs", 288);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs288), "lhs",
                  "lhs", 288);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 289);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_mantissa_nbits"), "name",
                  "name", 289);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 289);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m"),
                  "resolved", "resolved", 289);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 289);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 289);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 289);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 289);
  sf_mex_assign(&c25_rhs289, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs289, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs289), "rhs",
                  "rhs", 289);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs289), "lhs",
                  "lhs", 289);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m"),
                  "context", "context", 290);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 290);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 290);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 290);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 290);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 290);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 290);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 290);
  sf_mex_assign(&c25_rhs290, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs290, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs290), "rhs",
                  "rhs", 290);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs290), "lhs",
                  "lhs", 290);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 291);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 291);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 291);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 291);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307622444U), "fileTimeLo",
                  "fileTimeLo", 291);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 291);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 291);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 291);
  sf_mex_assign(&c25_rhs291, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs291, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs291), "rhs",
                  "rhs", 291);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs291), "lhs",
                  "lhs", 291);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 292);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_realmin_denormal"),
                  "name", "name", 292);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 292);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m"),
                  "resolved", "resolved", 292);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691998U), "fileTimeLo",
                  "fileTimeLo", 292);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 292);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 292);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 292);
  sf_mex_assign(&c25_rhs292, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs292, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs292), "rhs",
                  "rhs", 292);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs292), "lhs",
                  "lhs", 292);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m"),
                  "context", "context", 293);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 293);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 293);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 293);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 293);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 293);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 293);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 293);
  sf_mex_assign(&c25_rhs293, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs293, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs293), "rhs",
                  "rhs", 293);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs293), "lhs",
                  "lhs", 293);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 294);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 294);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 294);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 294);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 294);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 294);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 294);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 294);
  sf_mex_assign(&c25_rhs294, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs294, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs294), "rhs",
                  "rhs", 294);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs294), "lhs",
                  "lhs", 294);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 295);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isfinite"), "name", "name",
                  295);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 295);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 295);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 295);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 295);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 295);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 295);
  sf_mex_assign(&c25_rhs295, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs295, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs295), "rhs",
                  "rhs", 295);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs295), "lhs",
                  "lhs", 295);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 296);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 296);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 296);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 296);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 296);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 296);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 296);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 296);
  sf_mex_assign(&c25_rhs296, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs296, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs296), "rhs",
                  "rhs", 296);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs296), "lhs",
                  "lhs", 296);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 297);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isinf"), "name", "name", 297);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 297);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 297);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 297);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 297);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 297);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 297);
  sf_mex_assign(&c25_rhs297, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs297, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs297), "rhs",
                  "rhs", 297);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs297), "lhs",
                  "lhs", 297);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 298);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("angle"), "name", "name", 298);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 298);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/angle.m"), "resolved",
                  "resolved", 298);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801570U), "fileTimeLo",
                  "fileTimeLo", 298);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 298);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 298);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 298);
  sf_mex_assign(&c25_rhs298, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs298, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs298), "rhs",
                  "rhs", 298);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs298), "lhs",
                  "lhs", 298);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/angle.m"), "context",
                  "context", 299);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_angle"), "name",
                  "name", 299);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 299);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_angle.m"),
                  "resolved", "resolved", 299);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786316U), "fileTimeLo",
                  "fileTimeLo", 299);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 299);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 299);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 299);
  sf_mex_assign(&c25_rhs299, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs299, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs299), "rhs",
                  "rhs", 299);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs299), "lhs",
                  "lhs", 299);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_angle.m"),
                  "context", "context", 300);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 300);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 300);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 300);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786320U), "fileTimeLo",
                  "fileTimeLo", 300);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 300);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 300);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 300);
  sf_mex_assign(&c25_rhs300, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs300, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs300), "rhs",
                  "rhs", 300);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs300), "lhs",
                  "lhs", 300);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context",
                  301);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("inv"), "name", "name", 301);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 301);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m"), "resolved",
                  "resolved", 301);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1305289200U), "fileTimeLo",
                  "fileTimeLo", 301);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 301);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 301);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 301);
  sf_mex_assign(&c25_rhs301, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs301, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs301), "rhs",
                  "rhs", 301);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs301), "lhs",
                  "lhs", 301);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2"), "context",
                  "context", 302);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  302);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 302);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 302);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 302);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 302);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 302);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 302);
  sf_mex_assign(&c25_rhs302, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs302, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs302), "rhs",
                  "rhs", 302);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs302), "lhs",
                  "lhs", 302);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 303);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 303);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 303);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 303);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 303);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 303);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 303);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 303);
  sf_mex_assign(&c25_rhs303, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs303, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs303), "rhs",
                  "rhs", 303);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs303), "lhs",
                  "lhs", 303);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 304);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 304);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 304);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 304);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 304);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 304);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 304);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 304);
  sf_mex_assign(&c25_rhs304, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs304, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs304), "rhs",
                  "rhs", 304);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs304), "lhs",
                  "lhs", 304);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2"), "context",
                  "context", 305);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  305);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 305);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 305);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 305);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 305);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 305);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 305);
  sf_mex_assign(&c25_rhs305, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs305, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs305), "rhs",
                  "rhs", 305);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs305), "lhs",
                  "lhs", 305);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 306);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("norm"), "name", "name", 306);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 306);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 306);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677868U), "fileTimeLo",
                  "fileTimeLo", 306);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 306);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 306);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 306);
  sf_mex_assign(&c25_rhs306, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs306, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs306), "rhs",
                  "rhs", 306);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs306), "lhs",
                  "lhs", 306);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 307);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 307);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 307);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 307);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 307);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 307);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 307);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 307);
  sf_mex_assign(&c25_rhs307, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs307, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs307), "rhs",
                  "rhs", 307);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs307), "lhs",
                  "lhs", 307);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 308);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 308);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 308);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 308);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 308);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 308);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 308);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 308);
  sf_mex_assign(&c25_rhs308, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs308, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs308), "rhs",
                  "rhs", 308);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs308), "lhs",
                  "lhs", 308);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 309);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnan"), "name", "name", 309);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 309);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 309);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 309);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 309);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 309);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 309);
  sf_mex_assign(&c25_rhs309, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs309, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs309), "rhs",
                  "rhs", 309);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs309), "lhs",
                  "lhs", 309);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 310);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 310);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 310);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 310);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 310);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 310);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 310);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 310);
  sf_mex_assign(&c25_rhs310, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs310, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs310), "rhs",
                  "rhs", 310);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs310), "lhs",
                  "lhs", 310);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 311);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_warning"), "name",
                  "name", 311);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 311);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 311);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286786402U), "fileTimeLo",
                  "fileTimeLo", 311);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 311);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 311);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 311);
  sf_mex_assign(&c25_rhs311, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs311, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs311), "rhs",
                  "rhs", 311);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs311), "lhs",
                  "lhs", 311);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 312);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("isnan"), "name", "name", 312);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 312);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 312);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 312);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 312);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 312);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 312);
  sf_mex_assign(&c25_rhs312, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs312, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs312), "rhs",
                  "rhs", 312);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs312), "lhs",
                  "lhs", 312);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 313);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 313);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 313);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 313);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 313);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 313);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 313);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 313);
  sf_mex_assign(&c25_rhs313, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs313, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs313), "rhs",
                  "rhs", 313);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs313), "lhs",
                  "lhs", 313);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 314);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_flt2str"), "name",
                  "name", 314);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 314);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "resolved",
                  "resolved", 314);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1360246350U), "fileTimeLo",
                  "fileTimeLo", 314);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 314);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 314);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 314);
  sf_mex_assign(&c25_rhs314, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs314, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs314), "rhs",
                  "rhs", 314);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs314), "lhs",
                  "lhs", 314);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "context",
                  "context", 315);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "name", "name", 315);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 315);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 315);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1319697568U), "fileTimeLo",
                  "fileTimeLo", 315);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 315);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 315);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 315);
  sf_mex_assign(&c25_rhs315, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs315, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs315), "rhs",
                  "rhs", 315);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs315), "lhs",
                  "lhs", 315);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context",
                  316);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("max"), "name", "name", 316);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 316);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 316);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 316);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 316);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 316);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 316);
  sf_mex_assign(&c25_rhs316, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs316, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs316), "rhs",
                  "rhs", 316);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs316), "lhs",
                  "lhs", 316);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context",
                  317);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("sqrt"), "name", "name", 317);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 317);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 317);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 317);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 317);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 317);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 317);
  sf_mex_assign(&c25_rhs317, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs317, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs317), "rhs",
                  "rhs", 317);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs317), "lhs",
                  "lhs", 317);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context",
                  318);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 318);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 318);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 318);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 318);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 318);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 318);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 318);
  sf_mex_assign(&c25_rhs318, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs318, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs318), "rhs",
                  "rhs", 318);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs318), "lhs",
                  "lhs", 318);
  sf_mex_destroy(&c25_rhs256);
  sf_mex_destroy(&c25_lhs256);
  sf_mex_destroy(&c25_rhs257);
  sf_mex_destroy(&c25_lhs257);
  sf_mex_destroy(&c25_rhs258);
  sf_mex_destroy(&c25_lhs258);
  sf_mex_destroy(&c25_rhs259);
  sf_mex_destroy(&c25_lhs259);
  sf_mex_destroy(&c25_rhs260);
  sf_mex_destroy(&c25_lhs260);
  sf_mex_destroy(&c25_rhs261);
  sf_mex_destroy(&c25_lhs261);
  sf_mex_destroy(&c25_rhs262);
  sf_mex_destroy(&c25_lhs262);
  sf_mex_destroy(&c25_rhs263);
  sf_mex_destroy(&c25_lhs263);
  sf_mex_destroy(&c25_rhs264);
  sf_mex_destroy(&c25_lhs264);
  sf_mex_destroy(&c25_rhs265);
  sf_mex_destroy(&c25_lhs265);
  sf_mex_destroy(&c25_rhs266);
  sf_mex_destroy(&c25_lhs266);
  sf_mex_destroy(&c25_rhs267);
  sf_mex_destroy(&c25_lhs267);
  sf_mex_destroy(&c25_rhs268);
  sf_mex_destroy(&c25_lhs268);
  sf_mex_destroy(&c25_rhs269);
  sf_mex_destroy(&c25_lhs269);
  sf_mex_destroy(&c25_rhs270);
  sf_mex_destroy(&c25_lhs270);
  sf_mex_destroy(&c25_rhs271);
  sf_mex_destroy(&c25_lhs271);
  sf_mex_destroy(&c25_rhs272);
  sf_mex_destroy(&c25_lhs272);
  sf_mex_destroy(&c25_rhs273);
  sf_mex_destroy(&c25_lhs273);
  sf_mex_destroy(&c25_rhs274);
  sf_mex_destroy(&c25_lhs274);
  sf_mex_destroy(&c25_rhs275);
  sf_mex_destroy(&c25_lhs275);
  sf_mex_destroy(&c25_rhs276);
  sf_mex_destroy(&c25_lhs276);
  sf_mex_destroy(&c25_rhs277);
  sf_mex_destroy(&c25_lhs277);
  sf_mex_destroy(&c25_rhs278);
  sf_mex_destroy(&c25_lhs278);
  sf_mex_destroy(&c25_rhs279);
  sf_mex_destroy(&c25_lhs279);
  sf_mex_destroy(&c25_rhs280);
  sf_mex_destroy(&c25_lhs280);
  sf_mex_destroy(&c25_rhs281);
  sf_mex_destroy(&c25_lhs281);
  sf_mex_destroy(&c25_rhs282);
  sf_mex_destroy(&c25_lhs282);
  sf_mex_destroy(&c25_rhs283);
  sf_mex_destroy(&c25_lhs283);
  sf_mex_destroy(&c25_rhs284);
  sf_mex_destroy(&c25_lhs284);
  sf_mex_destroy(&c25_rhs285);
  sf_mex_destroy(&c25_lhs285);
  sf_mex_destroy(&c25_rhs286);
  sf_mex_destroy(&c25_lhs286);
  sf_mex_destroy(&c25_rhs287);
  sf_mex_destroy(&c25_lhs287);
  sf_mex_destroy(&c25_rhs288);
  sf_mex_destroy(&c25_lhs288);
  sf_mex_destroy(&c25_rhs289);
  sf_mex_destroy(&c25_lhs289);
  sf_mex_destroy(&c25_rhs290);
  sf_mex_destroy(&c25_lhs290);
  sf_mex_destroy(&c25_rhs291);
  sf_mex_destroy(&c25_lhs291);
  sf_mex_destroy(&c25_rhs292);
  sf_mex_destroy(&c25_lhs292);
  sf_mex_destroy(&c25_rhs293);
  sf_mex_destroy(&c25_lhs293);
  sf_mex_destroy(&c25_rhs294);
  sf_mex_destroy(&c25_lhs294);
  sf_mex_destroy(&c25_rhs295);
  sf_mex_destroy(&c25_lhs295);
  sf_mex_destroy(&c25_rhs296);
  sf_mex_destroy(&c25_lhs296);
  sf_mex_destroy(&c25_rhs297);
  sf_mex_destroy(&c25_lhs297);
  sf_mex_destroy(&c25_rhs298);
  sf_mex_destroy(&c25_lhs298);
  sf_mex_destroy(&c25_rhs299);
  sf_mex_destroy(&c25_lhs299);
  sf_mex_destroy(&c25_rhs300);
  sf_mex_destroy(&c25_lhs300);
  sf_mex_destroy(&c25_rhs301);
  sf_mex_destroy(&c25_lhs301);
  sf_mex_destroy(&c25_rhs302);
  sf_mex_destroy(&c25_lhs302);
  sf_mex_destroy(&c25_rhs303);
  sf_mex_destroy(&c25_lhs303);
  sf_mex_destroy(&c25_rhs304);
  sf_mex_destroy(&c25_lhs304);
  sf_mex_destroy(&c25_rhs305);
  sf_mex_destroy(&c25_lhs305);
  sf_mex_destroy(&c25_rhs306);
  sf_mex_destroy(&c25_lhs306);
  sf_mex_destroy(&c25_rhs307);
  sf_mex_destroy(&c25_lhs307);
  sf_mex_destroy(&c25_rhs308);
  sf_mex_destroy(&c25_lhs308);
  sf_mex_destroy(&c25_rhs309);
  sf_mex_destroy(&c25_lhs309);
  sf_mex_destroy(&c25_rhs310);
  sf_mex_destroy(&c25_lhs310);
  sf_mex_destroy(&c25_rhs311);
  sf_mex_destroy(&c25_lhs311);
  sf_mex_destroy(&c25_rhs312);
  sf_mex_destroy(&c25_lhs312);
  sf_mex_destroy(&c25_rhs313);
  sf_mex_destroy(&c25_lhs313);
  sf_mex_destroy(&c25_rhs314);
  sf_mex_destroy(&c25_lhs314);
  sf_mex_destroy(&c25_rhs315);
  sf_mex_destroy(&c25_lhs315);
  sf_mex_destroy(&c25_rhs316);
  sf_mex_destroy(&c25_lhs316);
  sf_mex_destroy(&c25_rhs317);
  sf_mex_destroy(&c25_lhs317);
  sf_mex_destroy(&c25_rhs318);
  sf_mex_destroy(&c25_lhs318);
}

static void c25_eml_scalar_eg(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c25_assert(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c25_rdivide(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_x, real_T c25_y)
{
  real_T c25_b_x;
  real_T c25_b_y;
  real_T c25_c_x;
  real_T c25_c_y;
  (void)chartInstance;
  c25_b_x = c25_x;
  c25_b_y = c25_y;
  c25_c_x = c25_b_x;
  c25_c_y = c25_b_y;
  return c25_c_x / c25_c_y;
}

static real_T c25_norm(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x[4])
{
  int32_T c25_k;
  int32_T c25_b_k;
  int32_T c25_i155;
  real_T c25_b_x[4];
  real_T c25_s[2];
  c25_eml_switch_helper(chartInstance);
  for (c25_k = 1; c25_k < 5; c25_k++) {
    c25_b_k = c25_k;
    if (!c25_isfinite(chartInstance, c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 4, 1, 0) - 1])) {
      c25_eml_error(chartInstance);
    }
  }

  for (c25_i155 = 0; c25_i155 < 4; c25_i155++) {
    c25_b_x[c25_i155] = c25_x[c25_i155];
  }

  c25_eml_matlab_zsvdc(chartInstance, c25_b_x, c25_s);
  return c25_s[0];
}

static void c25_eml_switch_helper(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c25_isfinite(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_x)
{
  real_T c25_b_x;
  boolean_T c25_b_b;
  boolean_T c25_b20;
  real_T c25_c_x;
  boolean_T c25_c_b;
  boolean_T c25_b21;
  (void)chartInstance;
  c25_b_x = c25_x;
  c25_b_b = muDoubleScalarIsInf(c25_b_x);
  c25_b20 = !c25_b_b;
  c25_c_x = c25_x;
  c25_c_b = muDoubleScalarIsNaN(c25_c_x);
  c25_b21 = !c25_c_b;
  return c25_b20 && c25_b21;
}

static void c25_eml_error(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c25_i156;
  static char_T c25_cv0[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c25_u[33];
  const mxArray *c25_y = NULL;
  (void)chartInstance;
  for (c25_i156 = 0; c25_i156 < 33; c25_i156++) {
    c25_u[c25_i156] = c25_cv0[c25_i156];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c25_y));
}

static void c25_eml_matlab_zsvdc(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_A[4], real_T c25_S[2])
{
  boolean_T c25_apply_transform;
  int32_T c25_i157;
  real_T c25_b_A[4];
  real_T c25_nrm;
  real_T c25_absx;
  real_T c25_d;
  real_T c25_y;
  real_T c25_s[2];
  real_T c25_a;
  real_T c25_SAFMIN;
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_b_y;
  real_T c25_B;
  real_T c25_c_y;
  real_T c25_b_a;
  real_T c25_c_a;
  int32_T c25_k;
  int32_T c25_b_k;
  int32_T c25_c_k;
  int32_T c25_d_k;
  real_T c25_c_A;
  real_T c25_b_B;
  real_T c25_d_y;
  int32_T c25_i158;
  real_T c25_d_A[4];
  int32_T c25_i159;
  real_T c25_e_A[4];
  real_T c25_t;
  real_T c25_f_A;
  real_T c25_c_B;
  real_T c25_e_y;
  int32_T c25_m;
  real_T c25_e[2];
  int32_T c25_b_q;
  int32_T c25_c_q;
  real_T c25_rt;
  real_T c25_g_A;
  real_T c25_d_B;
  real_T c25_r;
  real_T c25_h_A;
  real_T c25_e_B;
  real_T c25_f_y;
  real_T c25_i_A;
  real_T c25_f_B;
  real_T c25_iter;
  real_T c25_tiny;
  real_T c25_snorm;
  int32_T c25_ii;
  int32_T c25_b_ii;
  real_T c25_varargin_1;
  real_T c25_varargin_2;
  real_T c25_b_varargin_2;
  real_T c25_varargin_3;
  real_T c25_c_x;
  real_T c25_g_y;
  real_T c25_d_x;
  real_T c25_h_y;
  real_T c25_xk;
  real_T c25_yk;
  real_T c25_e_x;
  real_T c25_i_y;
  real_T c25_maxval;
  real_T c25_b_varargin_1;
  real_T c25_c_varargin_2;
  real_T c25_d_varargin_2;
  real_T c25_b_varargin_3;
  real_T c25_f_x;
  real_T c25_j_y;
  real_T c25_g_x;
  real_T c25_k_y;
  real_T c25_b_xk;
  real_T c25_b_yk;
  real_T c25_h_x;
  real_T c25_l_y;
  int32_T c25_i160;
  int32_T c25_d_a;
  int32_T c25_e_a;
  boolean_T c25_overflow;
  int32_T c25_c_ii;
  real_T c25_test0;
  real_T c25_ztest0;
  real_T c25_kase;
  int32_T c25_qs;
  int32_T c25_b_m;
  int32_T c25_d_q;
  int32_T c25_f_a;
  int32_T c25_b;
  int32_T c25_g_a;
  int32_T c25_b_b;
  boolean_T c25_b_overflow;
  int32_T c25_d_ii;
  real_T c25_test;
  real_T c25_ztest;
  real_T c25_f;
  int32_T c25_i161;
  int32_T c25_e_q;
  int32_T c25_h_a;
  int32_T c25_c_b;
  int32_T c25_i_a;
  int32_T c25_d_b;
  boolean_T c25_c_overflow;
  int32_T c25_e_k;
  int32_T c25_f_k;
  real_T c25_t1;
  real_T c25_b_t1;
  real_T c25_b_f;
  real_T c25_sn;
  real_T c25_cs;
  real_T c25_b_cs;
  real_T c25_b_sn;
  int32_T c25_km1;
  int32_T c25_qm1;
  int32_T c25_f_q;
  int32_T c25_c_m;
  int32_T c25_j_a;
  int32_T c25_e_b;
  int32_T c25_k_a;
  int32_T c25_f_b;
  boolean_T c25_d_overflow;
  int32_T c25_g_k;
  real_T c25_c_t1;
  real_T c25_unusedU0;
  real_T c25_c_sn;
  real_T c25_c_cs;
  int32_T c25_mm1;
  real_T c25_d1;
  real_T c25_d2;
  real_T c25_d3;
  real_T c25_d4;
  real_T c25_d5;
  real_T c25_c_varargin_1[5];
  int32_T c25_ixstart;
  real_T c25_mtmp;
  real_T c25_i_x;
  boolean_T c25_g_b;
  int32_T c25_ix;
  int32_T c25_b_ix;
  real_T c25_j_x;
  boolean_T c25_h_b;
  int32_T c25_l_a;
  int32_T c25_m_a;
  int32_T c25_i162;
  int32_T c25_n_a;
  int32_T c25_o_a;
  boolean_T c25_e_overflow;
  int32_T c25_c_ix;
  real_T c25_p_a;
  real_T c25_i_b;
  boolean_T c25_p;
  real_T c25_b_mtmp;
  real_T c25_scale;
  real_T c25_j_A;
  real_T c25_g_B;
  real_T c25_sm;
  real_T c25_k_A;
  real_T c25_h_B;
  real_T c25_smm1;
  real_T c25_l_A;
  real_T c25_i_B;
  real_T c25_emm1;
  real_T c25_m_A;
  real_T c25_j_B;
  real_T c25_sqds;
  real_T c25_n_A;
  real_T c25_k_B;
  real_T c25_eqds;
  real_T c25_o_A;
  real_T c25_j_b;
  real_T c25_c;
  real_T c25_shift;
  real_T c25_p_A;
  real_T c25_l_B;
  real_T c25_g;
  int32_T c25_g_q;
  int32_T c25_b_mm1;
  int32_T c25_q_a;
  int32_T c25_k_b;
  int32_T c25_r_a;
  int32_T c25_l_b;
  boolean_T c25_f_overflow;
  int32_T c25_h_k;
  int32_T c25_kp1;
  real_T c25_c_f;
  real_T c25_unusedU1;
  real_T c25_d_sn;
  real_T c25_d_cs;
  real_T c25_d_f;
  real_T c25_unusedU2;
  real_T c25_e_sn;
  real_T c25_e_cs;
  int32_T c25_i_k;
  int32_T c25_qp1;
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
  c25_b_eml_scalar_eg(chartInstance);
  c25_apply_transform = false;
  for (c25_i157 = 0; c25_i157 < 4; c25_i157++) {
    c25_b_A[c25_i157] = c25_A[c25_i157];
  }

  c25_nrm = c25_eml_xnrm2(chartInstance, c25_b_A);
  if (c25_nrm > 0.0) {
    c25_apply_transform = true;
    c25_absx = c25_nrm;
    c25_d = c25_A[0];
    if (c25_d < 0.0) {
      c25_y = -c25_absx;
    } else {
      c25_y = c25_absx;
    }

    c25_s[0] = c25_y;
    c25_a = c25_s[0];
    c25_eml_realmin(chartInstance);
    c25_eps(chartInstance);
    c25_SAFMIN = c25_rdivide(chartInstance, 2.2250738585072014E-308,
      2.2204460492503131E-16);
    c25_x = c25_a;
    c25_b_x = c25_x;
    c25_b_y = muDoubleScalarAbs(c25_b_x);
    if (c25_b_y >= c25_SAFMIN) {
      c25_B = c25_a;
      c25_c_y = c25_rdivide(chartInstance, 1.0, c25_B);
      c25_b_a = c25_c_y;
      c25_b_eml_switch_helper(chartInstance);
      c25_c_a = c25_b_a;
      c25_eml_switch_helper(chartInstance);
      for (c25_k = 1; c25_k < 3; c25_k++) {
        c25_b_k = c25_k;
        c25_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_k), 1, 4, 1, 0) - 1] = c25_c_a *
          c25_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_k), 1, 4, 1, 0) - 1];
      }
    } else {
      c25_eml_switch_helper(chartInstance);
      for (c25_c_k = 1; c25_c_k < 3; c25_c_k++) {
        c25_d_k = c25_c_k;
        c25_c_A = c25_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_d_k), 1, 4, 1, 0) - 1];
        c25_b_B = c25_a;
        c25_d_y = c25_rdivide(chartInstance, c25_c_A, c25_b_B);
        c25_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_d_k), 1, 4, 1, 0) - 1] = c25_d_y;
      }
    }

    c25_A[0]++;
    c25_s[0] = -c25_s[0];
  } else {
    c25_s[0] = 0.0;
  }

  if (c25_apply_transform) {
    for (c25_i158 = 0; c25_i158 < 4; c25_i158++) {
      c25_d_A[c25_i158] = c25_A[c25_i158];
    }

    for (c25_i159 = 0; c25_i159 < 4; c25_i159++) {
      c25_e_A[c25_i159] = c25_A[c25_i159];
    }

    c25_t = c25_eml_xdotc(chartInstance, c25_d_A, c25_e_A);
    c25_f_A = c25_t;
    c25_c_B = c25_A[0];
    c25_e_y = c25_rdivide(chartInstance, c25_f_A, c25_c_B);
    c25_t = -c25_e_y;
    c25_b_eml_xaxpy(chartInstance, c25_t, c25_A);
  }

  c25_m = 1;
  c25_s[1] = c25_A[3];
  c25_e[0] = c25_A[2];
  c25_e[1] = 0.0;
  c25_eml_switch_helper(chartInstance);
  for (c25_b_q = 1; c25_b_q < 3; c25_b_q++) {
    c25_c_q = c25_b_q;
    if (c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_c_q), 1, 2, 1, 0) - 1] != 0.0) {
      c25_rt = c25_abs(chartInstance, c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1]);
      c25_g_A = c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1];
      c25_d_B = c25_rt;
      c25_r = c25_rdivide(chartInstance, c25_g_A, c25_d_B);
      c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c25_c_q), 1, 2, 1, 0) - 1] = c25_rt;
      if (c25_c_q < 2) {
        c25_h_A = c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1];
        c25_e_B = c25_r;
        c25_f_y = c25_rdivide(chartInstance, c25_h_A, c25_e_B);
        c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_c_q), 1, 2, 1, 0) - 1] = c25_f_y;
      }
    }

    if (c25_c_q < 2) {
      if (c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_c_q), 1, 2, 1, 0) - 1] != 0.0) {
        c25_rt = c25_abs(chartInstance, c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1]);
        c25_i_A = c25_rt;
        c25_f_B = c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1];
        c25_r = c25_rdivide(chartInstance, c25_i_A, c25_f_B);
        c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_c_q), 1, 2, 1, 0) - 1] = c25_rt;
        c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c25_c_q + 1)), 1, 2, 1, 0) - 1] =
          c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c25_c_q + 1)), 1, 2, 1, 0) - 1] * c25_r;
      }
    }
  }

  c25_iter = 0.0;
  c25_realmin(chartInstance);
  c25_eps(chartInstance);
  c25_tiny = c25_rdivide(chartInstance, 2.2250738585072014E-308,
    2.2204460492503131E-16);
  c25_snorm = 0.0;
  c25_eml_switch_helper(chartInstance);
  for (c25_ii = 1; c25_ii < 3; c25_ii++) {
    c25_b_ii = c25_ii;
    c25_varargin_1 = c25_abs(chartInstance, c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ii),
      1, 2, 1, 0) - 1]);
    c25_varargin_2 = c25_abs(chartInstance, c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ii),
      1, 2, 1, 0) - 1]);
    c25_b_varargin_2 = c25_varargin_1;
    c25_varargin_3 = c25_varargin_2;
    c25_c_x = c25_b_varargin_2;
    c25_g_y = c25_varargin_3;
    c25_d_x = c25_c_x;
    c25_h_y = c25_g_y;
    c25_eml_scalar_eg(chartInstance);
    c25_xk = c25_d_x;
    c25_yk = c25_h_y;
    c25_e_x = c25_xk;
    c25_i_y = c25_yk;
    c25_eml_scalar_eg(chartInstance);
    c25_maxval = muDoubleScalarMax(c25_e_x, c25_i_y);
    c25_b_varargin_1 = c25_snorm;
    c25_c_varargin_2 = c25_maxval;
    c25_d_varargin_2 = c25_b_varargin_1;
    c25_b_varargin_3 = c25_c_varargin_2;
    c25_f_x = c25_d_varargin_2;
    c25_j_y = c25_b_varargin_3;
    c25_g_x = c25_f_x;
    c25_k_y = c25_j_y;
    c25_eml_scalar_eg(chartInstance);
    c25_b_xk = c25_g_x;
    c25_b_yk = c25_k_y;
    c25_h_x = c25_b_xk;
    c25_l_y = c25_b_yk;
    c25_eml_scalar_eg(chartInstance);
    c25_snorm = muDoubleScalarMax(c25_h_x, c25_l_y);
  }

  exitg1 = false;
  while ((exitg1 == false) && (c25_m + 1 > 0)) {
    if (c25_iter >= 75.0) {
      c25_b_eml_error(chartInstance);
      exitg1 = true;
    } else {
      c25_c_q = c25_m;
      c25_i160 = c25_m;
      c25_d_a = c25_i160;
      c25_e_a = c25_d_a;
      if (c25_e_a < 0) {
        c25_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_overflow = false;
      }

      if (c25_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_overflow);
      }

      c25_c_ii = c25_i160;
      guard3 = false;
      guard4 = false;
      exitg5 = false;
      while ((exitg5 == false) && (c25_c_ii > -1)) {
        c25_b_ii = c25_c_ii;
        c25_c_q = c25_b_ii;
        if (c25_b_ii == 0) {
          exitg5 = true;
        } else {
          c25_test0 = c25_abs(chartInstance, c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ii), 1, 2, 1, 0) -
                              1]) + c25_abs(chartInstance,
            c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c25_b_ii + 1)), 1, 2, 1, 0) - 1]);
          c25_ztest0 = c25_abs(chartInstance, c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ii), 1, 2, 1, 0) -
                               1]);
          c25_eps(chartInstance);
          if (c25_ztest0 <= 2.2204460492503131E-16 * c25_test0) {
            guard4 = true;
            exitg5 = true;
          } else if (c25_ztest0 <= c25_tiny) {
            guard4 = true;
            exitg5 = true;
          } else {
            guard11 = false;
            if (c25_iter > 20.0) {
              c25_eps(chartInstance);
              if (c25_ztest0 <= 2.2204460492503131E-16 * c25_snorm) {
                guard3 = true;
                exitg5 = true;
              } else {
                guard11 = true;
              }
            } else {
              guard11 = true;
            }

            if (guard11 == true) {
              c25_c_ii--;
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
        c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_ii), 1, 2, 1, 0) - 1] = 0.0;
      }

      if (c25_c_q == c25_m) {
        c25_kase = 4.0;
      } else {
        c25_qs = c25_m + 1;
        c25_b_m = c25_m + 1;
        c25_d_q = c25_c_q;
        c25_f_a = c25_b_m;
        c25_b = c25_d_q;
        c25_g_a = c25_f_a;
        c25_b_b = c25_b;
        if (c25_g_a < c25_b_b) {
          c25_b_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_b_overflow = (c25_b_b < -2147483647);
        }

        if (c25_b_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
        }

        c25_d_ii = c25_b_m;
        guard2 = false;
        exitg4 = false;
        while ((exitg4 == false) && (c25_d_ii >= c25_d_q)) {
          c25_b_ii = c25_d_ii;
          c25_qs = c25_b_ii;
          if (c25_b_ii == c25_c_q) {
            exitg4 = true;
          } else {
            c25_test = 0.0;
            if (c25_b_ii < c25_m + 1) {
              c25_test = c25_abs(chartInstance,
                                 c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_ii), 1, 2, 1, 0) - 1]);
            }

            if (c25_b_ii > c25_c_q + 1) {
              c25_test += c25_abs(chartInstance,
                                  c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)(c25_b_ii - 1)), 1, 2, 1, 0) - 1]);
            }

            c25_ztest = c25_abs(chartInstance, c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK
                                ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
              c25_b_ii), 1, 2, 1, 0) - 1]);
            c25_eps(chartInstance);
            if (c25_ztest <= 2.2204460492503131E-16 * c25_test) {
              guard2 = true;
              exitg4 = true;
            } else if (c25_ztest <= c25_tiny) {
              guard2 = true;
              exitg4 = true;
            } else {
              c25_d_ii--;
              guard2 = false;
            }
          }
        }

        if (guard2 == true) {
          c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_b_ii), 1, 2, 1, 0) - 1] = 0.0;
        }

        if (c25_qs == c25_c_q) {
          c25_kase = 3.0;
        } else if (c25_qs == c25_m + 1) {
          c25_kase = 1.0;
        } else {
          c25_kase = 2.0;
          c25_c_q = c25_qs;
        }
      }

      c25_c_q++;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c25_kase)) {
       case 1:
        c25_f = c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_m), 1, 2, 1, 0) - 1];
        c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_m), 1, 2, 1, 0) - 1] = 0.0;
        c25_i161 = c25_m;
        c25_e_q = c25_c_q;
        c25_h_a = c25_i161;
        c25_c_b = c25_e_q;
        c25_i_a = c25_h_a;
        c25_d_b = c25_c_b;
        if (c25_i_a < c25_d_b) {
          c25_c_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_c_overflow = (c25_d_b < -2147483647);
        }

        if (c25_c_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_c_overflow);
        }

        for (c25_e_k = c25_i161; c25_e_k >= c25_e_q; c25_e_k--) {
          c25_f_k = c25_e_k;
          c25_t1 = c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_f_k), 1, 2, 1, 0) - 1];
          c25_b_t1 = c25_t1;
          c25_b_f = c25_f;
          c25_b_eml_xrotg(chartInstance, &c25_b_t1, &c25_b_f, &c25_cs, &c25_sn);
          c25_t1 = c25_b_t1;
          c25_f = c25_b_f;
          c25_b_cs = c25_cs;
          c25_b_sn = c25_sn;
          c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1] = c25_t1;
          if (c25_f_k > c25_c_q) {
            c25_km1 = c25_f_k - 1;
            c25_f = -c25_b_sn * c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_km1), 1, 2, 1, 0) - 1];
            c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c25_km1), 1, 2, 1, 0) - 1] =
              c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c25_km1), 1, 2, 1, 0) - 1] * c25_b_cs;
          }
        }
        break;

       case 2:
        c25_qm1 = c25_c_q - 1;
        c25_f = c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_qm1), 1, 2, 1, 0) - 1];
        c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_qm1), 1, 2, 1, 0) - 1] = 0.0;
        c25_f_q = c25_c_q;
        c25_c_m = c25_m + 1;
        c25_j_a = c25_f_q;
        c25_e_b = c25_c_m;
        c25_k_a = c25_j_a;
        c25_f_b = c25_e_b;
        if (c25_k_a > c25_f_b) {
          c25_d_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_d_overflow = (c25_f_b > 2147483646);
        }

        if (c25_d_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_d_overflow);
        }

        for (c25_g_k = c25_f_q; c25_g_k <= c25_c_m; c25_g_k++) {
          c25_f_k = c25_g_k;
          c25_t1 = c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_f_k), 1, 2, 1, 0) - 1];
          c25_c_t1 = c25_t1;
          c25_unusedU0 = c25_f;
          c25_b_eml_xrotg(chartInstance, &c25_c_t1, &c25_unusedU0, &c25_c_cs,
                          &c25_c_sn);
          c25_t1 = c25_c_t1;
          c25_b_cs = c25_c_cs;
          c25_b_sn = c25_c_sn;
          c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1] = c25_t1;
          c25_f = -c25_b_sn * c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_f_k), 1, 2, 1, 0) - 1];
          c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1] =
            c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1] * c25_b_cs;
        }
        break;

       case 3:
        c25_mm1 = c25_m;
        c25_d1 = c25_abs(chartInstance, c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c25_m + 1)), 1, 2, 1, 0) - 1]);
        c25_d2 = c25_abs(chartInstance, c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_mm1), 1, 2, 1, 0) - 1]);
        c25_d3 = c25_abs(chartInstance, c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_mm1), 1, 2, 1, 0) - 1]);
        c25_d4 = c25_abs(chartInstance, c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1]);
        c25_d5 = c25_abs(chartInstance, c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1]);
        c25_c_varargin_1[0] = c25_d1;
        c25_c_varargin_1[1] = c25_d2;
        c25_c_varargin_1[2] = c25_d3;
        c25_c_varargin_1[3] = c25_d4;
        c25_c_varargin_1[4] = c25_d5;
        c25_ixstart = 1;
        c25_mtmp = c25_c_varargin_1[0];
        c25_i_x = c25_mtmp;
        c25_g_b = muDoubleScalarIsNaN(c25_i_x);
        if (c25_g_b) {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_ix = 2;
          exitg2 = false;
          while ((exitg2 == false) && (c25_ix < 6)) {
            c25_b_ix = c25_ix;
            c25_ixstart = c25_b_ix;
            c25_j_x = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 5, 1, 0) - 1];
            c25_h_b = muDoubleScalarIsNaN(c25_j_x);
            if (!c25_h_b) {
              c25_mtmp = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 5, 1, 0) -
                1];
              exitg2 = true;
            } else {
              c25_ix++;
            }
          }
        }

        if (c25_ixstart < 5) {
          c25_l_a = c25_ixstart;
          c25_m_a = c25_l_a + 1;
          c25_i162 = c25_m_a;
          c25_n_a = c25_i162;
          c25_o_a = c25_n_a;
          if (c25_o_a > 5) {
            c25_e_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_e_overflow = false;
          }

          if (c25_e_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_e_overflow);
          }

          for (c25_c_ix = c25_i162; c25_c_ix < 6; c25_c_ix++) {
            c25_b_ix = c25_c_ix;
            c25_p_a = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 5, 1, 0) - 1];
            c25_i_b = c25_mtmp;
            c25_p = (c25_p_a > c25_i_b);
            if (c25_p) {
              c25_mtmp = c25_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ix), 1, 5, 1, 0) -
                1];
            }
          }
        }

        c25_b_mtmp = c25_mtmp;
        c25_scale = c25_b_mtmp;
        c25_j_A = c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c25_m + 1)), 1, 2, 1, 0) - 1];
        c25_g_B = c25_scale;
        c25_sm = c25_rdivide(chartInstance, c25_j_A, c25_g_B);
        c25_k_A = c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_mm1), 1, 2, 1, 0) - 1];
        c25_h_B = c25_scale;
        c25_smm1 = c25_rdivide(chartInstance, c25_k_A, c25_h_B);
        c25_l_A = c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_mm1), 1, 2, 1, 0) - 1];
        c25_i_B = c25_scale;
        c25_emm1 = c25_rdivide(chartInstance, c25_l_A, c25_i_B);
        c25_m_A = c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1];
        c25_j_B = c25_scale;
        c25_sqds = c25_rdivide(chartInstance, c25_m_A, c25_j_B);
        c25_n_A = c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1];
        c25_k_B = c25_scale;
        c25_eqds = c25_rdivide(chartInstance, c25_n_A, c25_k_B);
        c25_o_A = (c25_smm1 + c25_sm) * (c25_smm1 - c25_sm) + c25_emm1 *
          c25_emm1;
        c25_j_b = c25_rdivide(chartInstance, c25_o_A, 2.0);
        c25_c = c25_sm * c25_emm1;
        c25_c *= c25_c;
        guard1 = false;
        if (c25_j_b != 0.0) {
          guard1 = true;
        } else if (c25_c != 0.0) {
          guard1 = true;
        } else {
          c25_shift = 0.0;
        }

        if (guard1 == true) {
          c25_shift = c25_j_b * c25_j_b + c25_c;
          c25_c_sqrt(chartInstance, &c25_shift);
          if (c25_j_b < 0.0) {
            c25_shift = -c25_shift;
          }

          c25_p_A = c25_c;
          c25_l_B = c25_j_b + c25_shift;
          c25_shift = c25_rdivide(chartInstance, c25_p_A, c25_l_B);
        }

        c25_f = (c25_sqds + c25_sm) * (c25_sqds - c25_sm) + c25_shift;
        c25_g = c25_sqds * c25_eqds;
        c25_g_q = c25_c_q;
        c25_b_mm1 = c25_mm1;
        c25_q_a = c25_g_q;
        c25_k_b = c25_b_mm1;
        c25_r_a = c25_q_a;
        c25_l_b = c25_k_b;
        if (c25_r_a > c25_l_b) {
          c25_f_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_f_overflow = (c25_l_b > 2147483646);
        }

        if (c25_f_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_f_overflow);
        }

        for (c25_h_k = c25_g_q; c25_h_k <= c25_b_mm1; c25_h_k++) {
          c25_f_k = c25_h_k;
          c25_km1 = c25_f_k;
          c25_kp1 = c25_f_k + 1;
          c25_c_f = c25_f;
          c25_unusedU1 = c25_g;
          c25_b_eml_xrotg(chartInstance, &c25_c_f, &c25_unusedU1, &c25_d_cs,
                          &c25_d_sn);
          c25_f = c25_c_f;
          c25_b_cs = c25_d_cs;
          c25_b_sn = c25_d_sn;
          if (c25_f_k > c25_c_q) {
            c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c25_km1 - 1)), 1, 2, 1, 0) - 1] = c25_f;
          }

          c25_f = c25_b_cs * c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_f_k), 1, 2, 1, 0) - 1] + c25_b_sn
            * c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c25_f_k), 1, 2, 1, 0) - 1];
          c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1] = c25_b_cs *
            c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1] - c25_b_sn *
            c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1];
          c25_g = c25_b_sn * c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_kp1), 1, 2, 1, 0) - 1];
          c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_kp1), 1, 2, 1, 0) - 1] =
            c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_kp1), 1, 2, 1, 0) - 1] * c25_b_cs;
          c25_d_f = c25_f;
          c25_unusedU2 = c25_g;
          c25_b_eml_xrotg(chartInstance, &c25_d_f, &c25_unusedU2, &c25_e_cs,
                          &c25_e_sn);
          c25_f = c25_d_f;
          c25_b_cs = c25_e_cs;
          c25_b_sn = c25_e_sn;
          c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1] = c25_f;
          c25_f = c25_b_cs * c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_f_k), 1, 2, 1, 0) - 1] + c25_b_sn
            * c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c25_kp1), 1, 2, 1, 0) - 1];
          c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_kp1), 1, 2, 1, 0) - 1] = -c25_b_sn *
            c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_f_k), 1, 2, 1, 0) - 1] + c25_b_cs *
            c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_kp1), 1, 2, 1, 0) - 1];
          c25_g = c25_b_sn * c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_kp1), 1, 2, 1, 0) - 1];
          c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_kp1), 1, 2, 1, 0) - 1] =
            c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_kp1), 1, 2, 1, 0) - 1] * c25_b_cs;
        }

        c25_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_m), 1, 2, 1, 0) - 1] = c25_f;
        c25_iter++;
        break;

       default:
        if (c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c25_c_q), 1, 2, 1, 0) - 1] < 0.0) {
          c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_c_q), 1, 2, 1, 0) - 1] =
            -c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c25_c_q), 1, 2, 1, 0) - 1];
        }

        c25_qp1 = c25_c_q + 1;
        exitg3 = false;
        while ((exitg3 == false) && (c25_c_q < 2)) {
          if (c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c25_c_q), 1, 2, 1, 0) - 1] <
              c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c25_qp1), 1, 2, 1, 0) - 1]) {
            c25_rt = c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_c_q), 1, 2, 1, 0) - 1];
            c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c25_c_q), 1, 2, 1, 0) - 1] =
              c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c25_qp1), 1, 2, 1, 0) - 1];
            c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c25_qp1), 1, 2, 1, 0) - 1] = c25_rt;
            c25_c_q = c25_qp1;
            c25_qp1 = c25_c_q + 1;
          } else {
            exitg3 = true;
          }
        }

        c25_iter = 0.0;
        c25_m--;
        break;
      }
    }
  }

  c25_eml_switch_helper(chartInstance);
  for (c25_i_k = 1; c25_i_k < 3; c25_i_k++) {
    c25_f_k = c25_i_k;
    c25_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c25_f_k), 1, 2, 1, 0) - 1] = c25_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_f_k), 1, 2, 1, 0) - 1];
  }
}

static void c25_b_eml_scalar_eg(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c25_eml_xnrm2(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_x[4])
{
  real_T c25_y;
  real_T c25_scale;
  int32_T c25_k;
  int32_T c25_b_k;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_absxk;
  real_T c25_t;
  c25_threshold(chartInstance);
  c25_y = 0.0;
  c25_eml_realmin(chartInstance);
  c25_scale = 2.2250738585072014E-308;
  c25_eml_switch_helper(chartInstance);
  for (c25_k = 1; c25_k < 3; c25_k++) {
    c25_b_k = c25_k;
    c25_b_x = c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c25_b_k), 1, 4, 1, 0) - 1];
    c25_c_x = c25_b_x;
    c25_absxk = muDoubleScalarAbs(c25_c_x);
    if (c25_absxk > c25_scale) {
      c25_t = c25_scale / c25_absxk;
      c25_y = 1.0 + c25_y * c25_t * c25_t;
      c25_scale = c25_absxk;
    } else {
      c25_t = c25_absxk / c25_scale;
      c25_y += c25_t * c25_t;
    }
  }

  return c25_scale * muDoubleScalarSqrt(c25_y);
}

static void c25_threshold(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c25_realmin(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  c25_eml_realmin(chartInstance);
}

static void c25_eml_realmin(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c25_abs(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
                      c25_x)
{
  real_T c25_b_x;
  (void)chartInstance;
  c25_b_x = c25_x;
  return muDoubleScalarAbs(c25_b_x);
}

static void c25_eps(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c25_b_eml_switch_helper(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c25_eml_xdotc(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_x[4], real_T c25_y[4])
{
  real_T c25_d;
  int32_T c25_ix;
  int32_T c25_iy;
  int32_T c25_k;
  int32_T c25_a;
  int32_T c25_b_a;
  c25_d = 0.0;
  c25_ix = 1;
  c25_iy = 3;
  c25_eml_switch_helper(chartInstance);
  for (c25_k = 1; c25_k < 3; c25_k++) {
    c25_d += c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c25_ix), 1, 4, 1, 0) - 1] * c25_y[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_iy), 1, 4, 1, 0) - 1];
    c25_a = c25_ix + 1;
    c25_ix = c25_a;
    c25_b_a = c25_iy + 1;
    c25_iy = c25_b_a;
  }

  return c25_d;
}

static void c25_eml_xaxpy(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_a, real_T c25_y[4], real_T c25_b_y[4])
{
  int32_T c25_i163;
  for (c25_i163 = 0; c25_i163 < 4; c25_i163++) {
    c25_b_y[c25_i163] = c25_y[c25_i163];
  }

  c25_b_eml_xaxpy(chartInstance, c25_a, c25_b_y);
}

static void c25_b_eml_error(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c25_i164;
  static char_T c25_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c25_u[30];
  const mxArray *c25_y = NULL;
  (void)chartInstance;
  for (c25_i164 = 0; c25_i164 < 30; c25_i164++) {
    c25_u[c25_i164] = c25_cv1[c25_i164];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c25_y));
}

static void c25_check_forloop_overflow_error(SFc25_hybridSysSimInstanceStruct
  *chartInstance, boolean_T c25_overflow)
{
  int32_T c25_i165;
  static char_T c25_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c25_u[34];
  const mxArray *c25_y = NULL;
  int32_T c25_i166;
  static char_T c25_cv3[5] = { 'i', 'n', 't', '3', '2' };

  char_T c25_b_u[5];
  const mxArray *c25_b_y = NULL;
  (void)chartInstance;
  if (!c25_overflow) {
  } else {
    for (c25_i165 = 0; c25_i165 < 34; c25_i165++) {
      c25_u[c25_i165] = c25_cv2[c25_i165];
    }

    c25_y = NULL;
    sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c25_i166 = 0; c25_i166 < 5; c25_i166++) {
      c25_b_u[c25_i166] = c25_cv3[c25_i166];
    }

    c25_b_y = NULL;
    sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c25_y, 14, c25_b_y));
  }
}

static real_T c25_sqrt(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x)
{
  real_T c25_b_x;
  c25_b_x = c25_x;
  c25_c_sqrt(chartInstance, &c25_b_x);
  return c25_b_x;
}

static void c25_c_eml_error(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c25_i167;
  static char_T c25_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c25_u[30];
  const mxArray *c25_y = NULL;
  int32_T c25_i168;
  static char_T c25_cv5[4] = { 's', 'q', 'r', 't' };

  char_T c25_b_u[4];
  const mxArray *c25_b_y = NULL;
  (void)chartInstance;
  for (c25_i167 = 0; c25_i167 < 30; c25_i167++) {
    c25_u[c25_i167] = c25_cv4[c25_i167];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c25_i168 = 0; c25_i168 < 4; c25_i168++) {
    c25_b_u[c25_i168] = c25_cv5[c25_i168];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c25_y, 14, c25_b_y));
}

static void c25_eml_xrotg(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_a, real_T c25_b, real_T *c25_b_a, real_T *c25_b_b, real_T *c25_c,
  real_T *c25_s)
{
  *c25_b_a = c25_a;
  *c25_b_b = c25_b;
  c25_b_eml_xrotg(chartInstance, c25_b_a, c25_b_b, c25_c, c25_s);
}

static real_T c25_b_norm(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x[2])
{
  real_T c25_y;
  real_T c25_scale;
  int32_T c25_k;
  int32_T c25_b_k;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_absxk;
  real_T c25_t;
  c25_threshold(chartInstance);
  c25_y = 0.0;
  c25_eml_realmin(chartInstance);
  c25_scale = 2.2250738585072014E-308;
  c25_eml_switch_helper(chartInstance);
  for (c25_k = 1; c25_k < 3; c25_k++) {
    c25_b_k = c25_k;
    c25_b_x = c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c25_b_k), 1, 2, 1, 0) - 1];
    c25_c_x = c25_b_x;
    c25_absxk = muDoubleScalarAbs(c25_c_x);
    if (c25_absxk > c25_scale) {
      c25_t = c25_scale / c25_absxk;
      c25_y = 1.0 + c25_y * c25_t * c25_t;
      c25_scale = c25_absxk;
    } else {
      c25_t = c25_absxk / c25_scale;
      c25_y += c25_t * c25_t;
    }
  }

  return c25_scale * muDoubleScalarSqrt(c25_y);
}

static void c25_eig(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
                    c25_A[4], creal_T c25_V[2])
{
  int32_T c25_i169;
  static creal_T c25_dc10 = { 0.0, 0.0 };

  creal_T c25_b_A[4];
  int32_T c25_info;
  int32_T c25_i170;
  creal_T c25_c_A[4];
  real_T c25_anrm;
  int32_T c25_i171;
  int32_T c25_i172;
  creal_T c25_beta1[2];
  boolean_T c25_ilascl;
  real_T c25_anrmto;
  int32_T c25_rscale[2];
  int32_T c25_ihi;
  int32_T c25_ilo;
  int32_T c25_b_ilo;
  int32_T c25_b_ihi;
  int32_T c25_c_ilo;
  int32_T c25_c_ihi;
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_c;
  int32_T c25_c_a;
  int32_T c25_d_a;
  int32_T c25_ihim1;
  int32_T c25_jcol;
  int32_T c25_e_a;
  int32_T c25_f_a;
  int32_T c25_jcolp1;
  int32_T c25_jrow;
  int32_T c25_g_a;
  int32_T c25_h_a;
  int32_T c25_jrowm1;
  creal_T c25_d_A;
  creal_T c25_e_A;
  creal_T c25_b;
  creal_T c25_s;
  real_T c25_b_c;
  real_T c25_c_c;
  real_T c25_d_c;
  int32_T c25_xrow;
  int32_T c25_yrow;
  int32_T c25_jlo;
  int32_T c25_jhi;
  int32_T c25_b_jlo;
  int32_T c25_b_jhi;
  int32_T c25_i_a;
  int32_T c25_b_b;
  int32_T c25_j_a;
  int32_T c25_c_b;
  boolean_T c25_overflow;
  int32_T c25_j;
  int32_T c25_b_j;
  real_T c25_k_a;
  creal_T c25_y;
  creal_T c25_b_s;
  creal_T c25_stemp;
  real_T c25_l_a;
  creal_T c25_d_b;
  creal_T c25_e_b;
  creal_T c25_f_b;
  creal_T c25_g_b;
  real_T c25_e_c;
  int32_T c25_xcol;
  int32_T c25_ycol;
  int32_T c25_d_ilo;
  int32_T c25_d_ihi;
  int32_T c25_e_ilo;
  int32_T c25_e_ihi;
  int32_T c25_m_a;
  int32_T c25_h_b;
  int32_T c25_n_a;
  int32_T c25_i_b;
  boolean_T c25_b_overflow;
  int32_T c25_i;
  int32_T c25_b_i;
  real_T c25_o_a;
  creal_T c25_c_s;
  real_T c25_p_a;
  creal_T c25_j_b;
  creal_T c25_k_b;
  creal_T c25_l_b;
  creal_T c25_m_b;
  int32_T c25_i173;
  creal_T c25_f_A[4];
  int32_T c25_b_info;
  real_T c25_cfrom;
  real_T c25_cto;
  real_T c25_cfromc;
  real_T c25_ctoc;
  boolean_T c25_notdone;
  real_T c25_cfrom1;
  real_T c25_cto1;
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_b_y;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_c_y;
  real_T c25_mul;
  real_T c25_e_x;
  real_T c25_f_x;
  real_T c25_d_y;
  real_T c25_g_x;
  real_T c25_h_x;
  real_T c25_e_y;
  real_T c25_q_a;
  int32_T c25_i174;
  int32_T c25_c_info;
  int32_T c25_d_info;
  int32_T c25_e_info;
  int32_T c25_i175;
  creal_T c25_b_V;
  real_T c25_ar;
  real_T c25_ai;
  real_T c25_br;
  real_T c25_bi;
  real_T c25_brm;
  real_T c25_bim;
  real_T c25_d_s;
  real_T c25_d;
  real_T c25_nr;
  real_T c25_ni;
  real_T c25_sgnbr;
  real_T c25_sgnbi;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c25_assert(chartInstance);
  c25_b_assert(chartInstance);
  c25_c_assert(chartInstance);
  c25_parseopts(chartInstance);
  c25_b_eml_scalar_eg(chartInstance);
  for (c25_i169 = 0; c25_i169 < 4; c25_i169++) {
    c25_b_A[c25_i169].re = c25_A[c25_i169] + c25_dc10.re;
    c25_b_A[c25_i169].im = c25_dc10.im;
  }

  c25_info = 0;
  c25_eml_realmin(chartInstance);
  c25_eps(chartInstance);
  for (c25_i170 = 0; c25_i170 < 4; c25_i170++) {
    c25_c_A[c25_i170] = c25_b_A[c25_i170];
  }

  c25_anrm = c25_eml_matlab_zlangeM(chartInstance, c25_c_A);
  if (!c25_isfinite(chartInstance, c25_anrm)) {
    for (c25_i171 = 0; c25_i171 < 2; c25_i171++) {
      c25_V[c25_i171].re = rtNaN;
      c25_V[c25_i171].im = 0.0;
    }

    for (c25_i172 = 0; c25_i172 < 2; c25_i172++) {
      c25_beta1[c25_i172].re = rtNaN;
      c25_beta1[c25_i172].im = 0.0;
    }
  } else {
    c25_ilascl = false;
    c25_anrmto = c25_anrm;
    guard2 = false;
    if (c25_anrm > 0.0) {
      if (c25_anrm < 6.7178761075670888E-139) {
        c25_anrmto = 6.7178761075670888E-139;
        c25_ilascl = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      if (c25_anrm > 1.4885657073574029E+138) {
        c25_anrmto = 1.4885657073574029E+138;
        c25_ilascl = true;
      }
    }

    if (c25_ilascl) {
      c25_b_eml_matlab_zlascl(chartInstance, c25_anrm, c25_anrmto, c25_b_A);
    }

    c25_c_eml_matlab_zggbal(chartInstance, c25_b_A, &c25_ilo, &c25_ihi,
      c25_rscale);
    c25_b_ilo = c25_ilo;
    c25_b_ihi = c25_ihi;
    c25_c_ilo = c25_b_ilo;
    c25_c_ihi = c25_b_ihi;
    c25_a = c25_c_ilo;
    c25_b_a = c25_a + 2;
    c25_c = c25_b_a;
    if (c25_c_ihi < c25_c) {
    } else {
      c25_c_a = c25_c_ihi;
      c25_d_a = c25_c_a - 1;
      c25_ihim1 = c25_d_a;
      c25_jcol = c25_c_ilo;
      while (c25_jcol < c25_ihim1) {
        c25_e_a = c25_jcol;
        c25_f_a = c25_e_a + 1;
        c25_jcolp1 = c25_f_a;
        c25_jrow = c25_c_ihi;
        while (c25_jrow > c25_jcolp1) {
          c25_g_a = c25_jrow;
          c25_h_a = c25_g_a - 1;
          c25_jrowm1 = c25_h_a;
          c25_d_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_jrowm1), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_jcol), 1, 2, 2, 0) - 1) << 1)) -
            1].re;
          c25_d_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_jrowm1), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_jcol), 1, 2, 2, 0) - 1) << 1)) -
            1].im;
          c25_e_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_jrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_jcol), 1, 2, 2, 0) - 1) << 1)) -
            1].re;
          c25_e_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_jrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_jcol), 1, 2, 2, 0) - 1) << 1)) -
            1].im;
          c25_eml_matlab_zlartg(chartInstance, c25_d_A, c25_e_A, &c25_b_c,
                                &c25_s, &c25_b);
          c25_c_c = c25_b_c;
          c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_jrowm1), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_jcol), 1, 2, 2, 0) - 1) << 1)) - 1].re =
            c25_b.re;
          c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_jrowm1), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_jcol), 1, 2, 2, 0) - 1) << 1)) - 1].im =
            c25_b.im;
          c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_jrow), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_jcol), 1, 2, 2, 0) - 1) << 1)) - 1].re =
            c25_dc10.re;
          c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_jrow), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_jcol), 1, 2, 2, 0) - 1) << 1)) - 1].im =
            c25_dc10.im;
          c25_d_c = c25_c_c;
          c25_xrow = c25_jrowm1;
          c25_yrow = c25_jrow;
          c25_jlo = c25_jcolp1;
          c25_jhi = c25_c_ihi;
          c25_b_jlo = c25_jlo;
          c25_b_jhi = c25_jhi;
          c25_i_a = c25_b_jlo;
          c25_b_b = c25_b_jhi;
          c25_j_a = c25_i_a;
          c25_c_b = c25_b_b;
          if (c25_j_a > c25_c_b) {
            c25_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_overflow = (c25_c_b > 2147483646);
          }

          if (c25_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_overflow);
          }

          for (c25_j = c25_b_jlo; c25_j <= c25_b_jhi; c25_j++) {
            c25_b_j = c25_j;
            c25_k_a = c25_d_c;
            c25_b.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c25_b.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c25_y.re = c25_k_a * c25_b.re;
            c25_y.im = c25_k_a * c25_b.im;
            c25_b_s.re = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
              ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].re - c25_s.im *
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c25_b_s.im = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
              ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].im + c25_s.im *
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c25_stemp.re = c25_y.re + c25_b_s.re;
            c25_stemp.im = c25_y.im + c25_b_s.im;
            c25_l_a = c25_d_c;
            c25_b.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c25_b.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c25_y.re = c25_l_a * c25_b.re;
            c25_y.im = c25_l_a * c25_b.im;
            c25_b.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c25_b.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c25_d_b = c25_b;
            c25_e_b = c25_b;
            c25_f_b = c25_b;
            c25_g_b = c25_b;
            c25_b.re = c25_s.re * c25_d_b.re + c25_s.im * c25_e_b.im;
            c25_b.im = c25_s.re * c25_f_b.im - c25_s.im * c25_g_b.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_yrow), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1)
                      << 1)) - 1].re = c25_y.re - c25_b.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_yrow), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1)
                      << 1)) - 1].im = c25_y.im - c25_b.im;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_xrow), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1)
                      << 1)) - 1].re = c25_stemp.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_xrow), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1)
                      << 1)) - 1].im = c25_stemp.im;
          }

          c25_s.re = -c25_s.re;
          c25_s.im = -c25_s.im;
          c25_e_c = c25_c_c;
          c25_xcol = c25_jrow;
          c25_ycol = c25_jrowm1;
          c25_d_ilo = c25_c_ilo;
          c25_d_ihi = c25_c_ihi;
          c25_e_ilo = c25_d_ilo;
          c25_e_ihi = c25_d_ihi;
          c25_m_a = c25_e_ilo;
          c25_h_b = c25_e_ihi;
          c25_n_a = c25_m_a;
          c25_i_b = c25_h_b;
          if (c25_n_a > c25_i_b) {
            c25_b_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_b_overflow = (c25_i_b > 2147483646);
          }

          if (c25_b_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
          }

          for (c25_i = c25_e_ilo; c25_i <= c25_e_ihi; c25_i++) {
            c25_b_i = c25_i;
            c25_o_a = c25_e_c;
            c25_b.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c25_b.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c25_y.re = c25_o_a * c25_b.re;
            c25_y.im = c25_o_a * c25_b.im;
            c25_c_s.re = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
              ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1)) - 1].re - c25_s.im *
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c25_c_s.im = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
              ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1)) - 1].im + c25_s.im *
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c25_stemp.re = c25_y.re + c25_c_s.re;
            c25_stemp.im = c25_y.im + c25_c_s.im;
            c25_p_a = c25_e_c;
            c25_b.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c25_b.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c25_y.re = c25_p_a * c25_b.re;
            c25_y.im = c25_p_a * c25_b.im;
            c25_b.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c25_b.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c25_j_b = c25_b;
            c25_k_b = c25_b;
            c25_l_b = c25_b;
            c25_m_b = c25_b;
            c25_b.re = c25_s.re * c25_j_b.re + c25_s.im * c25_k_b.im;
            c25_b.im = c25_s.re * c25_l_b.im - c25_s.im * c25_m_b.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_i), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) -
                       1) << 1)) - 1].re = c25_y.re - c25_b.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_i), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) -
                       1) << 1)) - 1].im = c25_y.im - c25_b.im;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_i), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) -
                       1) << 1)) - 1].re = c25_stemp.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_i), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) -
                       1) << 1)) - 1].im = c25_stemp.im;
          }

          c25_jrow = c25_jrowm1;
        }

        c25_jcol = c25_jcolp1;
      }
    }

    for (c25_i173 = 0; c25_i173 < 4; c25_i173++) {
      c25_f_A[c25_i173] = c25_b_A[c25_i173];
    }

    c25_eml_matlab_zhgeqz(chartInstance, c25_f_A, c25_b_ilo, c25_b_ihi,
                          &c25_b_info, c25_V, c25_beta1);
    c25_info = c25_b_info;
    if (c25_info != 0) {
    } else {
      if (c25_ilascl) {
        c25_cfrom = c25_anrmto;
        c25_cto = c25_anrm;
        c25_eml_realmin(chartInstance);
        c25_eps(chartInstance);
        c25_cfromc = c25_cfrom;
        c25_ctoc = c25_cto;
        c25_notdone = true;
        while (c25_notdone) {
          c25_cfrom1 = c25_cfromc * 2.0041683600089728E-292;
          c25_cto1 = c25_ctoc / 4.9896007738368E+291;
          c25_x = c25_cfrom1;
          c25_b_x = c25_x;
          c25_b_y = muDoubleScalarAbs(c25_b_x);
          c25_c_x = c25_ctoc;
          c25_d_x = c25_c_x;
          c25_c_y = muDoubleScalarAbs(c25_d_x);
          guard1 = false;
          if (c25_b_y > c25_c_y) {
            if (c25_ctoc != 0.0) {
              c25_mul = 2.0041683600089728E-292;
              c25_notdone = true;
              c25_cfromc = c25_cfrom1;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1 == true) {
            c25_e_x = c25_cto1;
            c25_f_x = c25_e_x;
            c25_d_y = muDoubleScalarAbs(c25_f_x);
            c25_g_x = c25_cfromc;
            c25_h_x = c25_g_x;
            c25_e_y = muDoubleScalarAbs(c25_h_x);
            if (c25_d_y > c25_e_y) {
              c25_mul = 4.9896007738368E+291;
              c25_notdone = true;
              c25_ctoc = c25_cto1;
            } else {
              c25_mul = c25_ctoc / c25_cfromc;
              c25_notdone = false;
            }
          }

          c25_q_a = c25_mul;
          for (c25_i174 = 0; c25_i174 < 2; c25_i174++) {
            c25_V[c25_i174].re *= c25_q_a;
            c25_V[c25_i174].im *= c25_q_a;
          }
        }
      }
    }
  }

  c25_c_info = c25_info;
  c25_d_info = c25_c_info;
  c25_e_info = c25_d_info;
  for (c25_i175 = 0; c25_i175 < 2; c25_i175++) {
    c25_b_V = c25_V[c25_i175];
    c25_ar = c25_b_V.re;
    c25_ai = c25_b_V.im;
    c25_br = c25_beta1[c25_i175].re;
    c25_bi = c25_beta1[c25_i175].im;
    if (c25_bi == 0.0) {
      if (c25_ai == 0.0) {
        c25_V[c25_i175].re = c25_ar / c25_br;
        c25_V[c25_i175].im = 0.0;
      } else if (c25_ar == 0.0) {
        c25_V[c25_i175].re = 0.0;
        c25_V[c25_i175].im = c25_ai / c25_br;
      } else {
        c25_V[c25_i175].re = c25_ar / c25_br;
        c25_V[c25_i175].im = c25_ai / c25_br;
      }
    } else if (c25_br == 0.0) {
      if (c25_ar == 0.0) {
        c25_V[c25_i175].re = c25_ai / c25_bi;
        c25_V[c25_i175].im = 0.0;
      } else if (c25_ai == 0.0) {
        c25_V[c25_i175].re = 0.0;
        c25_V[c25_i175].im = -(c25_ar / c25_bi);
      } else {
        c25_V[c25_i175].re = c25_ai / c25_bi;
        c25_V[c25_i175].im = -(c25_ar / c25_bi);
      }
    } else {
      c25_brm = muDoubleScalarAbs(c25_br);
      c25_bim = muDoubleScalarAbs(c25_bi);
      if (c25_brm > c25_bim) {
        c25_d_s = c25_bi / c25_br;
        c25_d = c25_br + c25_d_s * c25_bi;
        c25_nr = c25_ar + c25_d_s * c25_ai;
        c25_ni = c25_ai - c25_d_s * c25_ar;
        c25_V[c25_i175].re = c25_nr / c25_d;
        c25_V[c25_i175].im = c25_ni / c25_d;
      } else if (c25_bim == c25_brm) {
        if (c25_br > 0.0) {
          c25_sgnbr = 0.5;
        } else {
          c25_sgnbr = -0.5;
        }

        if (c25_bi > 0.0) {
          c25_sgnbi = 0.5;
        } else {
          c25_sgnbi = -0.5;
        }

        c25_nr = c25_ar * c25_sgnbr + c25_ai * c25_sgnbi;
        c25_ni = c25_ai * c25_sgnbr - c25_ar * c25_sgnbi;
        c25_V[c25_i175].re = c25_nr / c25_brm;
        c25_V[c25_i175].im = c25_ni / c25_brm;
      } else {
        c25_d_s = c25_br / c25_bi;
        c25_d = c25_bi + c25_d_s * c25_br;
        c25_nr = c25_d_s * c25_ar + c25_ai;
        c25_ni = c25_d_s * c25_ai - c25_ar;
        c25_V[c25_i175].re = c25_nr / c25_d;
        c25_V[c25_i175].im = c25_ni / c25_d;
      }
    }
  }

  if (c25_e_info != 0) {
    c25_eml_warning(chartInstance);
  }
}

static void c25_b_assert(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c25_c_assert(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c25_parseopts(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c25_eml_matlab_zlangeM(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_x[4])
{
  real_T c25_y;
  int32_T c25_k;
  real_T c25_b_k;
  creal_T c25_b_x;
  real_T c25_x1;
  real_T c25_x2;
  real_T c25_a;
  real_T c25_b;
  real_T c25_absxk;
  real_T c25_c_x;
  boolean_T c25_b_b;
  boolean_T exitg1;
  (void)chartInstance;
  c25_y = 0.0;
  c25_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c25_k < 4)) {
    c25_b_k = 1.0 + (real_T)c25_k;
    c25_b_x.re = c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c25_b_k), 1, 4, 1, 0) - 1].re;
    c25_b_x.im = c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c25_b_k), 1, 4, 1, 0) - 1].im;
    c25_x1 = c25_b_x.re;
    c25_x2 = c25_b_x.im;
    c25_a = c25_x1;
    c25_b = c25_x2;
    c25_absxk = muDoubleScalarHypot(c25_a, c25_b);
    c25_c_x = c25_absxk;
    c25_b_b = muDoubleScalarIsNaN(c25_c_x);
    if (c25_b_b) {
      c25_y = rtNaN;
      exitg1 = true;
    } else {
      if (c25_absxk > c25_y) {
        c25_y = c25_absxk;
      }

      c25_k++;
    }
  }

  return c25_y;
}

static real_T c25_b_abs(SFc25_hybridSysSimInstanceStruct *chartInstance, creal_T
  c25_x)
{
  real_T c25_x1;
  real_T c25_x2;
  real_T c25_a;
  real_T c25_b;
  (void)chartInstance;
  c25_x1 = c25_x.re;
  c25_x2 = c25_x.im;
  c25_a = c25_x1;
  c25_b = c25_x2;
  return muDoubleScalarHypot(c25_a, c25_b);
}

static void c25_eml_matlab_zlascl(SFc25_hybridSysSimInstanceStruct
  *chartInstance, real_T c25_cfrom, real_T c25_cto, creal_T c25_A[4], creal_T
  c25_b_A[4])
{
  int32_T c25_i176;
  for (c25_i176 = 0; c25_i176 < 4; c25_i176++) {
    c25_b_A[c25_i176] = c25_A[c25_i176];
  }

  c25_b_eml_matlab_zlascl(chartInstance, c25_cfrom, c25_cto, c25_b_A);
}

static void c25_eml_matlab_zggbal(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[4], creal_T c25_b_A[4], int32_T *c25_ilo,
  int32_T *c25_ihi, int32_T c25_rscale[2])
{
  int32_T c25_i177;
  for (c25_i177 = 0; c25_i177 < 4; c25_i177++) {
    c25_b_A[c25_i177] = c25_A[c25_i177];
  }

  c25_c_eml_matlab_zggbal(chartInstance, c25_b_A, c25_ilo, c25_ihi, c25_rscale);
}

static void c25_eml_matlab_zlartg(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_f, creal_T c25_g, real_T *c25_cs, creal_T *c25_sn,
  creal_T *c25_r)
{
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_y;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_b_y;
  real_T c25_e_x;
  real_T c25_c_y;
  real_T c25_d_y;
  real_T c25_f_x;
  real_T c25_g_x;
  real_T c25_e_y;
  real_T c25_h_x;
  real_T c25_i_x;
  real_T c25_f_y;
  real_T c25_j_x;
  real_T c25_g_y;
  real_T c25_h_y;
  real_T c25_k_x;
  real_T c25_i_y;
  real_T c25_scale;
  creal_T c25_fs;
  creal_T c25_gs;
  int32_T c25_count;
  real_T c25_rescaledir;
  int32_T c25_a;
  int32_T c25_b_a;
  static creal_T c25_dc11 = { 0.0, 0.0 };

  boolean_T c25_b_g;
  int32_T c25_c_a;
  int32_T c25_d_a;
  real_T c25_f2;
  real_T c25_g2;
  real_T c25_l_x;
  real_T c25_m_x;
  boolean_T c25_b_f;
  real_T c25_x1;
  real_T c25_x2;
  real_T c25_e_a;
  real_T c25_b;
  real_T c25_j_y;
  real_T c25_b_x1;
  real_T c25_b_x2;
  real_T c25_f_a;
  real_T c25_b_b;
  real_T c25_d;
  real_T c25_c_x1;
  real_T c25_c_x2;
  real_T c25_g_a;
  real_T c25_c_b;
  real_T c25_f2s;
  real_T c25_n_x;
  real_T c25_g2s;
  real_T c25_o_x;
  real_T c25_p_x;
  real_T c25_k_y;
  real_T c25_q_x;
  real_T c25_r_x;
  real_T c25_l_y;
  real_T c25_s_x;
  real_T c25_m_y;
  real_T c25_n_y;
  real_T c25_d_x1;
  real_T c25_d_x2;
  real_T c25_h_a;
  real_T c25_d_b;
  real_T c25_dr;
  real_T c25_di;
  real_T c25_e_x1;
  real_T c25_e_x2;
  real_T c25_i_a;
  real_T c25_e_b;
  creal_T c25_b_gs;
  real_T c25_j_a;
  creal_T c25_b_sn;
  real_T c25_t_x;
  creal_T c25_c_gs;
  creal_T c25_c_sn;
  int32_T c25_b_count;
  int32_T c25_f_b;
  int32_T c25_g_b;
  boolean_T c25_overflow;
  int32_T c25_i;
  int32_T c25_c_count;
  int32_T c25_h_b;
  int32_T c25_i_b;
  boolean_T c25_b_overflow;
  int32_T c25_b_i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c25_eml_realmin(chartInstance);
  c25_eps(chartInstance);
  c25_eps(chartInstance);
  c25_x = c25_f.re;
  c25_b_x = c25_x;
  c25_y = muDoubleScalarAbs(c25_b_x);
  c25_c_x = c25_f.im;
  c25_d_x = c25_c_x;
  c25_b_y = muDoubleScalarAbs(c25_d_x);
  c25_e_x = c25_y;
  c25_c_y = c25_b_y;
  c25_d_y = c25_e_x;
  if (c25_c_y > c25_d_y) {
    c25_d_y = c25_c_y;
  }

  c25_f_x = c25_g.re;
  c25_g_x = c25_f_x;
  c25_e_y = muDoubleScalarAbs(c25_g_x);
  c25_h_x = c25_g.im;
  c25_i_x = c25_h_x;
  c25_f_y = muDoubleScalarAbs(c25_i_x);
  c25_j_x = c25_e_y;
  c25_g_y = c25_f_y;
  c25_h_y = c25_j_x;
  if (c25_g_y > c25_h_y) {
    c25_h_y = c25_g_y;
  }

  c25_k_x = c25_d_y;
  c25_i_y = c25_h_y;
  c25_scale = c25_k_x;
  if (c25_i_y > c25_scale) {
    c25_scale = c25_i_y;
  }

  c25_fs = c25_f;
  c25_gs = c25_g;
  c25_count = 0;
  c25_rescaledir = 0.0;
  guard1 = false;
  guard2 = false;
  if (c25_scale >= 7.4428285367870146E+137) {
    do {
      c25_a = c25_count;
      c25_b_a = c25_a + 1;
      c25_count = c25_b_a;
      c25_fs.re *= 1.3435752215134178E-138;
      c25_fs.im *= 1.3435752215134178E-138;
      c25_gs.re *= 1.3435752215134178E-138;
      c25_gs.im *= 1.3435752215134178E-138;
      c25_scale *= 1.3435752215134178E-138;
    } while (!(c25_scale < 7.4428285367870146E+137));

    c25_rescaledir = 1.0;
    guard1 = true;
  } else if (c25_scale <= 1.3435752215134178E-138) {
    c25_b_g = ((c25_g.re == c25_dc11.re) && (c25_g.im == c25_dc11.im));
    if (c25_b_g) {
      *c25_cs = 1.0;
      *c25_sn = c25_dc11;
      *c25_r = c25_f;
    } else {
      do {
        c25_c_a = c25_count;
        c25_d_a = c25_c_a + 1;
        c25_count = c25_d_a;
        c25_fs.re *= 7.4428285367870146E+137;
        c25_fs.im *= 7.4428285367870146E+137;
        c25_gs.re *= 7.4428285367870146E+137;
        c25_gs.im *= 7.4428285367870146E+137;
        c25_scale *= 7.4428285367870146E+137;
      } while (!(c25_scale > 1.3435752215134178E-138));

      c25_rescaledir = -1.0;
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c25_f2 = c25_fs.re * c25_fs.re + c25_fs.im * c25_fs.im;
    c25_g2 = c25_gs.re * c25_gs.re + c25_gs.im * c25_gs.im;
    c25_l_x = c25_g2;
    c25_m_x = c25_l_x;
    if (1.0 > c25_m_x) {
      c25_m_x = 1.0;
    }

    if (c25_f2 <= c25_m_x * 2.0041683600089728E-292) {
      c25_b_f = ((c25_f.re == c25_dc11.re) && (c25_f.im == c25_dc11.im));
      if (c25_b_f) {
        *c25_cs = 0.0;
        c25_x1 = c25_g.re;
        c25_x2 = c25_g.im;
        c25_e_a = c25_x1;
        c25_b = c25_x2;
        c25_j_y = muDoubleScalarHypot(c25_e_a, c25_b);
        c25_r->re = c25_j_y;
        c25_r->im = 0.0;
        c25_b_x1 = c25_gs.re;
        c25_b_x2 = c25_gs.im;
        c25_f_a = c25_b_x1;
        c25_b_b = c25_b_x2;
        c25_d = muDoubleScalarHypot(c25_f_a, c25_b_b);
        c25_sn->re = c25_gs.re / c25_d;
        c25_sn->im = -c25_gs.im / c25_d;
      } else {
        c25_c_x1 = c25_fs.re;
        c25_c_x2 = c25_fs.im;
        c25_g_a = c25_c_x1;
        c25_c_b = c25_c_x2;
        c25_f2s = muDoubleScalarHypot(c25_g_a, c25_c_b);
        c25_n_x = c25_g2;
        c25_g2s = c25_n_x;
        if (c25_g2s < 0.0) {
          c25_c_eml_error(chartInstance);
        }

        c25_g2s = muDoubleScalarSqrt(c25_g2s);
        *c25_cs = c25_f2s / c25_g2s;
        c25_o_x = c25_f.re;
        c25_p_x = c25_o_x;
        c25_k_y = muDoubleScalarAbs(c25_p_x);
        c25_q_x = c25_f.im;
        c25_r_x = c25_q_x;
        c25_l_y = muDoubleScalarAbs(c25_r_x);
        c25_s_x = c25_k_y;
        c25_m_y = c25_l_y;
        c25_n_y = c25_s_x;
        if (c25_m_y > c25_n_y) {
          c25_n_y = c25_m_y;
        }

        if (c25_n_y > 1.0) {
          c25_d_x1 = c25_f.re;
          c25_d_x2 = c25_f.im;
          c25_h_a = c25_d_x1;
          c25_d_b = c25_d_x2;
          c25_d = muDoubleScalarHypot(c25_h_a, c25_d_b);
          c25_fs.re = c25_f.re / c25_d;
          c25_fs.im = c25_f.im / c25_d;
        } else {
          c25_dr = 7.4428285367870146E+137 * c25_f.re;
          c25_di = 7.4428285367870146E+137 * c25_f.im;
          c25_e_x1 = c25_dr;
          c25_e_x2 = c25_di;
          c25_i_a = c25_e_x1;
          c25_e_b = c25_e_x2;
          c25_d = muDoubleScalarHypot(c25_i_a, c25_e_b);
          c25_fs.re = c25_dr / c25_d;
          c25_fs.im = c25_di / c25_d;
        }

        c25_b_gs.re = c25_gs.re / c25_g2s;
        c25_b_gs.im = -c25_gs.im / c25_g2s;
        c25_sn->re = c25_fs.re * c25_b_gs.re - c25_fs.im * c25_b_gs.im;
        c25_sn->im = c25_fs.re * c25_b_gs.im + c25_fs.im * c25_b_gs.re;
        c25_j_a = *c25_cs;
        c25_fs.re = c25_j_a * c25_f.re;
        c25_fs.im = c25_j_a * c25_f.im;
        c25_b_sn.re = c25_sn->re * c25_g.re - c25_sn->im * c25_g.im;
        c25_b_sn.im = c25_sn->re * c25_g.im + c25_sn->im * c25_g.re;
        c25_r->re = c25_fs.re + c25_b_sn.re;
        c25_r->im = c25_fs.im + c25_b_sn.im;
      }
    } else {
      c25_t_x = 1.0 + c25_g2 / c25_f2;
      c25_f2s = c25_t_x;
      if (c25_f2s < 0.0) {
        c25_c_eml_error(chartInstance);
      }

      c25_f2s = muDoubleScalarSqrt(c25_f2s);
      c25_r->re = c25_f2s * c25_fs.re;
      c25_r->im = c25_f2s * c25_fs.im;
      *c25_cs = 1.0 / c25_f2s;
      c25_d = c25_f2 + c25_g2;
      c25_sn->re = c25_r->re / c25_d;
      c25_sn->im = c25_r->im / c25_d;
      c25_c_gs.re = c25_gs.re;
      c25_c_gs.im = -c25_gs.im;
      c25_c_sn = *c25_sn;
      c25_sn->re = c25_c_sn.re * c25_c_gs.re - c25_c_sn.im * c25_c_gs.im;
      c25_sn->im = c25_c_sn.re * c25_c_gs.im + c25_c_sn.im * c25_c_gs.re;
      if (c25_rescaledir > 0.0) {
        c25_b_count = c25_count;
        c25_f_b = c25_b_count;
        c25_g_b = c25_f_b;
        if (1 > c25_g_b) {
          c25_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_overflow = (c25_g_b > 2147483646);
        }

        if (c25_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_overflow);
        }

        for (c25_i = 1; c25_i <= c25_b_count; c25_i++) {
          c25_r->re *= 7.4428285367870146E+137;
          c25_r->im *= 7.4428285367870146E+137;
        }
      } else {
        if (c25_rescaledir < 0.0) {
          c25_c_count = c25_count;
          c25_h_b = c25_c_count;
          c25_i_b = c25_h_b;
          if (1 > c25_i_b) {
            c25_b_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_b_overflow = (c25_i_b > 2147483646);
          }

          if (c25_b_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
          }

          for (c25_b_i = 1; c25_b_i <= c25_c_count; c25_b_i++) {
            c25_r->re *= 1.3435752215134178E-138;
            c25_r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

static void c25_eml_matlab_zhgeqz(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[4], int32_T c25_ilo, int32_T c25_ihi, int32_T
  *c25_info, creal_T c25_alpha1[2], creal_T c25_beta1[2])
{
  static creal_T c25_dc12 = { 0.0, 0.0 };

  int32_T c25_i178;
  creal_T c25_b_A[4];
  int32_T c25_i179;
  int32_T c25_i180;
  static creal_T c25_dc13 = { 0.0, 0.0 };

  creal_T c25_eshift;
  creal_T c25_ctemp;
  creal_T c25_rho;
  int32_T c25_i181;
  creal_T c25_c_A[4];
  real_T c25_anorm;
  real_T c25_y;
  real_T c25_atol;
  real_T c25_b_y;
  real_T c25_x;
  real_T c25_ascale;
  boolean_T c25_failed;
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_i182;
  int32_T c25_c_a;
  int32_T c25_d_a;
  boolean_T c25_overflow;
  int32_T c25_j;
  int32_T c25_b_j;
  int32_T c25_ifirst;
  int32_T c25_istart;
  int32_T c25_ilast;
  int32_T c25_e_a;
  int32_T c25_f_a;
  int32_T c25_ilastm1;
  int32_T c25_ifrstm;
  int32_T c25_ilastm;
  int32_T c25_iiter;
  int32_T c25_g_a;
  int32_T c25_b;
  int32_T c25_h_a;
  int32_T c25_b_b;
  int32_T c25_c;
  int32_T c25_i_a;
  int32_T c25_j_a;
  int32_T c25_b_c;
  int32_T c25_c_b;
  int32_T c25_d_b;
  int32_T c25_maxit;
  boolean_T c25_goto50;
  boolean_T c25_goto60;
  boolean_T c25_goto70;
  boolean_T c25_goto90;
  int32_T c25_b_maxit;
  int32_T c25_e_b;
  int32_T c25_f_b;
  boolean_T c25_b_overflow;
  int32_T c25_jiter;
  creal_T c25_a22;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_c_y;
  real_T c25_d_x;
  real_T c25_e_x;
  real_T c25_d_y;
  real_T c25_e_y;
  int32_T c25_k_a;
  int32_T c25_l_a;
  int32_T c25_jm1;
  boolean_T c25_ilazro;
  real_T c25_f_x;
  real_T c25_g_x;
  real_T c25_f_y;
  real_T c25_h_x;
  real_T c25_i_x;
  real_T c25_g_y;
  real_T c25_h_y;
  boolean_T c25_b22;
  int32_T c25_i183;
  int32_T c25_i184;
  creal_T c25_d_A;
  creal_T c25_e_A;
  creal_T c25_s;
  real_T c25_c_c;
  real_T c25_d_c;
  real_T c25_e_c;
  int32_T c25_xcol;
  int32_T c25_ycol;
  int32_T c25_b_ilo;
  int32_T c25_b_ihi;
  int32_T c25_c_ilo;
  int32_T c25_c_ihi;
  int32_T c25_m_a;
  int32_T c25_g_b;
  int32_T c25_n_a;
  int32_T c25_h_b;
  boolean_T c25_c_overflow;
  int32_T c25_i;
  int32_T c25_b_i;
  real_T c25_o_a;
  creal_T c25_a12;
  creal_T c25_b_s;
  creal_T c25_a21;
  real_T c25_p_a;
  creal_T c25_b_a22;
  creal_T c25_c_a22;
  creal_T c25_d_a22;
  creal_T c25_e_a22;
  int32_T c25_q_a;
  int32_T c25_r_a;
  int32_T c25_s_a;
  int32_T c25_t_a;
  creal_T c25_r2;
  real_T c25_ar;
  real_T c25_ai;
  static creal_T c25_dc14 = { 2.0, 0.0 };

  real_T c25_br;
  real_T c25_bi;
  real_T c25_brm;
  real_T c25_bim;
  real_T c25_c_s;
  real_T c25_d;
  real_T c25_nr;
  real_T c25_ni;
  real_T c25_sgnbr;
  real_T c25_sgnbi;
  creal_T c25_d_s;
  creal_T c25_b_a12;
  creal_T c25_c_a12;
  creal_T c25_b_a21;
  real_T c25_d6;
  real_T c25_d7;
  int32_T c25_u_a;
  int32_T c25_v_a;
  int32_T c25_jp1;
  int32_T c25_w_a;
  int32_T c25_x_a;
  real_T c25_j_x;
  real_T c25_k_x;
  real_T c25_i_y;
  real_T c25_l_x;
  real_T c25_m_x;
  real_T c25_j_y;
  real_T c25_k_y;
  real_T c25_temp;
  real_T c25_n_x;
  real_T c25_o_x;
  real_T c25_l_y;
  real_T c25_p_x;
  real_T c25_q_x;
  real_T c25_m_y;
  real_T c25_n_y;
  real_T c25_temp2;
  real_T c25_r_x;
  real_T c25_o_y;
  real_T c25_tempr;
  real_T c25_s_x;
  real_T c25_t_x;
  real_T c25_p_y;
  real_T c25_u_x;
  real_T c25_v_x;
  real_T c25_q_y;
  real_T c25_r_y;
  int32_T c25_y_a;
  int32_T c25_ab_a;
  int32_T c25_f_c;
  real_T c25_g_c;
  int32_T c25_bb_a;
  int32_T c25_cb_a;
  int32_T c25_db_a;
  int32_T c25_eb_a;
  creal_T c25_f_A;
  creal_T c25_g_A;
  real_T c25_h_c;
  real_T c25_i_c;
  int32_T c25_xrow;
  int32_T c25_yrow;
  int32_T c25_jlo;
  int32_T c25_jhi;
  int32_T c25_b_jlo;
  int32_T c25_b_jhi;
  int32_T c25_fb_a;
  int32_T c25_i_b;
  int32_T c25_gb_a;
  int32_T c25_j_b;
  boolean_T c25_d_overflow;
  int32_T c25_c_j;
  int32_T c25_d_j;
  real_T c25_hb_a;
  creal_T c25_e_s;
  real_T c25_ib_a;
  creal_T c25_f_a22;
  creal_T c25_g_a22;
  creal_T c25_h_a22;
  creal_T c25_i_a22;
  int32_T c25_jb_a;
  int32_T c25_kb_a;
  int32_T c25_j_c;
  int32_T c25_w_x;
  int32_T c25_s_y;
  int32_T c25_x_x;
  real_T c25_k_c;
  int32_T c25_b_xcol;
  int32_T c25_b_ycol;
  int32_T c25_d_ilo;
  int32_T c25_d_ihi;
  int32_T c25_e_ilo;
  int32_T c25_e_ihi;
  int32_T c25_lb_a;
  int32_T c25_k_b;
  int32_T c25_mb_a;
  int32_T c25_l_b;
  boolean_T c25_e_overflow;
  int32_T c25_c_i;
  int32_T c25_d_i;
  real_T c25_nb_a;
  creal_T c25_f_s;
  real_T c25_ob_a;
  creal_T c25_j_a22;
  creal_T c25_k_a22;
  creal_T c25_l_a22;
  creal_T c25_m_a22;
  int32_T c25_b_ilast;
  int32_T c25_m_b;
  int32_T c25_n_b;
  boolean_T c25_f_overflow;
  int32_T c25_k;
  int32_T c25_b_k;
  int32_T c25_pb_a;
  int32_T c25_qb_a;
  int32_T c25_i185;
  int32_T c25_o_b;
  int32_T c25_p_b;
  boolean_T c25_g_overflow;
  int32_T c25_e_j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T guard11 = false;
  c25_dc12.re = rtNaN;
  for (c25_i178 = 0; c25_i178 < 4; c25_i178++) {
    c25_b_A[c25_i178] = c25_A[c25_i178];
  }

  *c25_info = 0;
  for (c25_i179 = 0; c25_i179 < 2; c25_i179++) {
    c25_alpha1[c25_i179].re = 0.0;
    c25_alpha1[c25_i179].im = 0.0;
  }

  for (c25_i180 = 0; c25_i180 < 2; c25_i180++) {
    c25_beta1[c25_i180].re = 1.0;
    c25_beta1[c25_i180].im = 0.0;
  }

  c25_eps(chartInstance);
  c25_realmin(chartInstance);
  c25_eshift = c25_dc13;
  c25_ctemp = c25_dc13;
  c25_rho = c25_dc13;
  for (c25_i181 = 0; c25_i181 < 4; c25_i181++) {
    c25_c_A[c25_i181] = c25_b_A[c25_i181];
  }

  c25_anorm = c25_eml_matlab_zlanhs(chartInstance, c25_c_A, c25_ilo, c25_ihi);
  c25_y = 2.2204460492503131E-16 * c25_anorm;
  c25_atol = 2.2250738585072014E-308;
  if (c25_y > 2.2250738585072014E-308) {
    c25_atol = c25_y;
  }

  c25_b_y = c25_anorm;
  c25_x = 2.2250738585072014E-308;
  if (c25_b_y > 2.2250738585072014E-308) {
    c25_x = c25_b_y;
  }

  c25_ascale = 1.0 / c25_x;
  c25_failed = true;
  c25_a = c25_ihi;
  c25_b_a = c25_a + 1;
  c25_i182 = c25_b_a;
  c25_c_a = c25_i182;
  c25_d_a = c25_c_a;
  if (c25_d_a > 2) {
    c25_overflow = false;
  } else {
    c25_eml_switch_helper(chartInstance);
    c25_eml_switch_helper(chartInstance);
    c25_overflow = false;
  }

  if (c25_overflow) {
    c25_check_forloop_overflow_error(chartInstance, c25_overflow);
  }

  for (c25_j = c25_i182; c25_j < 3; c25_j++) {
    c25_b_j = c25_j;
    c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c25_b_j), 1, 2, 1, 0) - 1].re = c25_b_A
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c25_b_j), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1]
      .re;
    c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c25_b_j), 1, 2, 1, 0) - 1].im = c25_b_A
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c25_b_j), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1]
      .im;
  }

  guard1 = false;
  guard2 = false;
  if (c25_ihi >= c25_ilo) {
    c25_ifirst = c25_ilo;
    c25_istart = c25_ilo;
    c25_ilast = c25_ihi;
    c25_e_a = c25_ilast;
    c25_f_a = c25_e_a - 1;
    c25_ilastm1 = c25_f_a;
    c25_ifrstm = c25_ilo;
    c25_ilastm = c25_ihi;
    c25_iiter = 0;
    c25_g_a = c25_ihi;
    c25_b = c25_ilo;
    c25_h_a = c25_g_a;
    c25_b_b = c25_b;
    c25_c = c25_h_a - c25_b_b;
    c25_i_a = c25_c;
    c25_j_a = c25_i_a + 1;
    c25_b_c = c25_j_a;
    c25_c_b = c25_b_c;
    c25_d_b = c25_c_b;
    c25_maxit = 30 * c25_d_b;
    c25_goto50 = false;
    c25_goto60 = false;
    c25_goto70 = false;
    c25_goto90 = false;
    c25_b_maxit = c25_maxit;
    c25_e_b = c25_b_maxit;
    c25_f_b = c25_e_b;
    if (1 > c25_f_b) {
      c25_b_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_b_overflow = (c25_f_b > 2147483646);
    }

    if (c25_b_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
    }

    c25_jiter = 1;
    do {
      exitg1 = 0;
      if (c25_jiter <= c25_b_maxit) {
        if (c25_ilast == c25_ilo) {
          c25_goto60 = true;
        } else {
          c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) << 1))
            - 1].re;
          c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) << 1))
            - 1].im;
          c25_b_x = c25_a22.re;
          c25_c_x = c25_b_x;
          c25_c_y = muDoubleScalarAbs(c25_c_x);
          c25_d_x = c25_a22.im;
          c25_e_x = c25_d_x;
          c25_d_y = muDoubleScalarAbs(c25_e_x);
          c25_e_y = c25_c_y + c25_d_y;
          if (c25_e_y <= c25_atol) {
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0)
                       - 1) << 1)) - 1].re = c25_dc13.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0)
                       - 1) << 1)) - 1].im = c25_dc13.im;
            c25_goto60 = true;
          } else {
            c25_b_j = c25_ilastm1;
            exitg3 = false;
            while ((exitg3 == false) && (c25_b_j >= c25_ilo)) {
              c25_k_a = c25_b_j;
              c25_l_a = c25_k_a - 1;
              c25_jm1 = c25_l_a;
              if (c25_b_j == c25_ilo) {
                c25_ilazro = true;
              } else {
                c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2, 0) - 1) << 1))
                  - 1].re;
                c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2, 0) - 1) << 1))
                  - 1].im;
                c25_f_x = c25_a22.re;
                c25_g_x = c25_f_x;
                c25_f_y = muDoubleScalarAbs(c25_g_x);
                c25_h_x = c25_a22.im;
                c25_i_x = c25_h_x;
                c25_g_y = muDoubleScalarAbs(c25_i_x);
                c25_h_y = c25_f_y + c25_g_y;
                if (c25_h_y <= c25_atol) {
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c25_dc13.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c25_dc13.im;
                  c25_ilazro = true;
                } else {
                  c25_ilazro = false;
                }
              }

              if (c25_ilazro) {
                c25_ifirst = c25_b_j;
                c25_goto70 = true;
                exitg3 = true;
              } else {
                c25_b_j = c25_jm1;
              }
            }
          }
        }

        guard3 = false;
        guard4 = false;
        if (c25_goto50) {
          guard4 = true;
        } else if (c25_goto60) {
          guard4 = true;
        } else if (c25_goto70) {
          guard3 = true;
        } else {
          c25_b22 = false;
        }

        if (guard4 == true) {
          guard3 = true;
        }

        if (guard3 == true) {
          c25_b22 = true;
        }

        if (!c25_b22) {
          for (c25_i183 = 0; c25_i183 < 2; c25_i183++) {
            c25_alpha1[c25_i183] = c25_dc12;
          }

          for (c25_i184 = 0; c25_i184 < 2; c25_i184++) {
            c25_beta1[c25_i184] = c25_dc12;
          }

          *c25_info = 1;
          exitg1 = 1;
        } else {
          if (c25_goto50) {
            c25_goto50 = false;
            c25_d_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c25_d_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c25_e_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c25_e_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c25_eml_matlab_zlartg(chartInstance, c25_d_A, c25_e_A, &c25_c_c,
                                  &c25_s, &c25_a22);
            c25_d_c = c25_c_c;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) -
                       1) << 1)) - 1].re = c25_a22.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) -
                       1) << 1)) - 1].im = c25_a22.im;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0)
                       - 1) << 1)) - 1].re = c25_dc13.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0)
                       - 1) << 1)) - 1].im = c25_dc13.im;
            c25_e_c = c25_d_c;
            c25_xcol = c25_ilast;
            c25_ycol = c25_ilastm1;
            c25_b_ilo = c25_ifrstm;
            c25_b_ihi = c25_ilastm1;
            c25_c_ilo = c25_b_ilo;
            c25_c_ihi = c25_b_ihi;
            c25_m_a = c25_c_ilo;
            c25_g_b = c25_c_ihi;
            c25_n_a = c25_m_a;
            c25_h_b = c25_g_b;
            if (c25_n_a > c25_h_b) {
              c25_c_overflow = false;
            } else {
              c25_eml_switch_helper(chartInstance);
              c25_eml_switch_helper(chartInstance);
              c25_c_overflow = (c25_h_b > 2147483646);
            }

            if (c25_c_overflow) {
              c25_check_forloop_overflow_error(chartInstance, c25_c_overflow);
            }

            for (c25_i = c25_c_ilo; c25_i <= c25_c_ihi; c25_i++) {
              c25_b_i = c25_i;
              c25_o_a = c25_e_c;
              c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) - 1) << 1))
                - 1].re;
              c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) - 1) << 1))
                - 1].im;
              c25_a12.re = c25_o_a * c25_a22.re;
              c25_a12.im = c25_o_a * c25_a22.im;
              c25_b_s.re = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1)) - 1].re - c25_s.im *
                c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                         ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1))
                - 1].im;
              c25_b_s.im = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1)) - 1].im + c25_s.im *
                c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                         ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1))
                - 1].re;
              c25_a21.re = c25_a12.re + c25_b_s.re;
              c25_a21.im = c25_a12.im + c25_b_s.im;
              c25_p_a = c25_e_c;
              c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1))
                - 1].re;
              c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0) - 1) << 1))
                - 1].im;
              c25_a12.re = c25_p_a * c25_a22.re;
              c25_a12.im = c25_p_a * c25_a22.im;
              c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) - 1) << 1))
                - 1].re;
              c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0) - 1) << 1))
                - 1].im;
              c25_b_a22 = c25_a22;
              c25_c_a22 = c25_a22;
              c25_d_a22 = c25_a22;
              c25_e_a22 = c25_a22;
              c25_a22.re = c25_s.re * c25_b_a22.re + c25_s.im * c25_c_a22.im;
              c25_a22.im = c25_s.re * c25_d_a22.im - c25_s.im * c25_e_a22.re;
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0)
                         - 1) << 1)) - 1].re = c25_a12.re - c25_a22.re;
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 2, 2, 0)
                         - 1) << 1)) - 1].im = c25_a12.im - c25_a22.im;
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0)
                         - 1) << 1)) - 1].re = c25_a21.re;
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 2, 2, 0)
                         - 1) << 1)) - 1].im = c25_a21.im;
            }

            c25_goto60 = true;
          }

          guard11 = false;
          if (c25_goto60) {
            c25_goto60 = false;
            c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) - 1].re =
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) - 1].im =
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c25_ilast = c25_ilastm1;
            c25_q_a = c25_ilast;
            c25_r_a = c25_q_a - 1;
            c25_ilastm1 = c25_r_a;
            if (c25_ilast < c25_ilo) {
              c25_failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              c25_iiter = 0;
              c25_eshift = c25_dc13;
              c25_ilastm = c25_ilast;
              if (c25_ifrstm > c25_ilast) {
                c25_ifrstm = c25_ilo;
              }

              guard11 = true;
            }
          } else {
            if (c25_goto70) {
              c25_goto70 = false;
              c25_s_a = c25_iiter;
              c25_t_a = c25_s_a + 1;
              c25_iiter = c25_t_a;
              c25_ifrstm = c25_ifirst;
              if (c25_mod(chartInstance, c25_iiter) != 0) {
                c25_rho.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) <<
                  1)) - 1].re;
                c25_rho.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) <<
                  1)) - 1].im;
                c25_r2.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) - 1) <<
                                      1)) - 1].re;
                c25_r2.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) - 1) <<
                                      1)) - 1].im;
                c25_a12.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) - 1) <<
                  1)) - 1].re;
                c25_a12.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 2, 0) - 1) <<
                  1)) - 1].im;
                c25_a21.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) <<
                  1)) - 1].re;
                c25_a21.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) <<
                  1)) - 1].im;
                c25_a22.re = c25_r2.re - c25_rho.re;
                c25_a22.im = c25_r2.im - c25_rho.im;
                c25_a22.re = -c25_a22.re;
                c25_a22.im = -c25_a22.im;
                c25_ar = c25_a22.re;
                c25_ai = c25_a22.im;
                c25_br = c25_dc14.re;
                c25_bi = c25_dc14.im;
                if (c25_bi == 0.0) {
                  if (c25_ai == 0.0) {
                    c25_s.re = c25_ar / c25_br;
                    c25_s.im = 0.0;
                  } else if (c25_ar == 0.0) {
                    c25_s.re = 0.0;
                    c25_s.im = c25_ai / c25_br;
                  } else {
                    c25_s.re = c25_ar / c25_br;
                    c25_s.im = c25_ai / c25_br;
                  }
                } else if (c25_br == 0.0) {
                  if (c25_ar == 0.0) {
                    c25_s.re = c25_ai / c25_bi;
                    c25_s.im = 0.0;
                  } else if (c25_ai == 0.0) {
                    c25_s.re = 0.0;
                    c25_s.im = -(c25_ar / c25_bi);
                  } else {
                    c25_s.re = c25_ai / c25_bi;
                    c25_s.im = -(c25_ar / c25_bi);
                  }
                } else {
                  c25_brm = muDoubleScalarAbs(c25_br);
                  c25_bim = muDoubleScalarAbs(c25_bi);
                  if (c25_brm > c25_bim) {
                    c25_c_s = c25_bi / c25_br;
                    c25_d = c25_br + c25_c_s * c25_bi;
                    c25_nr = c25_ar + c25_c_s * c25_ai;
                    c25_ni = c25_ai - c25_c_s * c25_ar;
                    c25_s.re = c25_nr / c25_d;
                    c25_s.im = c25_ni / c25_d;
                  } else if (c25_bim == c25_brm) {
                    if (c25_br > 0.0) {
                      c25_sgnbr = 0.5;
                    } else {
                      c25_sgnbr = -0.5;
                    }

                    if (c25_bi > 0.0) {
                      c25_sgnbi = 0.5;
                    } else {
                      c25_sgnbi = -0.5;
                    }

                    c25_nr = c25_ar * c25_sgnbr + c25_ai * c25_sgnbi;
                    c25_ni = c25_ai * c25_sgnbr - c25_ar * c25_sgnbi;
                    c25_s.re = c25_nr / c25_brm;
                    c25_s.im = c25_ni / c25_brm;
                  } else {
                    c25_c_s = c25_br / c25_bi;
                    c25_d = c25_bi + c25_c_s * c25_br;
                    c25_nr = c25_c_s * c25_ar + c25_ai;
                    c25_ni = c25_c_s * c25_ai - c25_ar;
                    c25_s.re = c25_nr / c25_d;
                    c25_s.im = c25_ni / c25_d;
                  }
                }

                c25_d_s.re = c25_s.re * c25_s.re - c25_s.im * c25_s.im;
                c25_d_s.im = c25_s.re * c25_s.im + c25_s.im * c25_s.re;
                c25_b_a12.re = c25_a12.re * c25_a21.re - c25_a12.im * c25_a21.im;
                c25_b_a12.im = c25_a12.re * c25_a21.im + c25_a12.im * c25_a21.re;
                c25_a22.re = c25_d_s.re + c25_b_a12.re;
                c25_a22.im = c25_d_s.im + c25_b_a12.im;
                c25_d_sqrt(chartInstance, &c25_a22);
                c25_a12.re = c25_rho.re - (c25_s.re - c25_a22.re);
                c25_a12.im = c25_rho.im - (c25_s.im - c25_a22.im);
                c25_a21.re = c25_rho.re - (c25_s.re + c25_a22.re);
                c25_a21.im = c25_rho.im - (c25_s.im + c25_a22.im);
                c25_c_a12.re = c25_a12.re - c25_r2.re;
                c25_c_a12.im = c25_a12.im - c25_r2.im;
                c25_b_a21.re = c25_a21.re - c25_r2.re;
                c25_b_a21.im = c25_a21.im - c25_r2.im;
                c25_d6 = c25_b_abs(chartInstance, c25_c_a12);
                c25_d7 = c25_b_abs(chartInstance, c25_b_a21);
                if (c25_d6 <= c25_d7) {
                  c25_a21 = c25_a12;
                  c25_rho.re = c25_s.re - c25_a22.re;
                  c25_rho.im = c25_s.im - c25_a22.im;
                } else {
                  c25_rho.re = c25_s.re + c25_a22.re;
                  c25_rho.im = c25_s.im + c25_a22.im;
                }
              } else {
                c25_eshift.re += c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0)
                  + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) <<
                     1)) - 1].re;
                c25_eshift.im += c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 2, 1, 0)
                  + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 2, 2, 0) - 1) <<
                     1)) - 1].im;
                c25_a21 = c25_eshift;
              }

              c25_b_j = c25_ilastm1;
              c25_u_a = c25_b_j;
              c25_v_a = c25_u_a + 1;
              c25_jp1 = c25_v_a;
              exitg2 = false;
              while ((exitg2 == false) && (c25_b_j > c25_ifirst)) {
                c25_w_a = c25_b_j;
                c25_x_a = c25_w_a - 1;
                c25_jm1 = c25_x_a;
                c25_istart = c25_b_j;
                c25_ctemp.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0) +
                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                  "", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].re -
                  c25_a21.re;
                c25_ctemp.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0) +
                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                  "", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].im -
                  c25_a21.im;
                c25_j_x = c25_ctemp.re;
                c25_k_x = c25_j_x;
                c25_i_y = muDoubleScalarAbs(c25_k_x);
                c25_l_x = c25_ctemp.im;
                c25_m_x = c25_l_x;
                c25_j_y = muDoubleScalarAbs(c25_m_x);
                c25_k_y = c25_i_y + c25_j_y;
                c25_temp = c25_ascale * c25_k_y;
                c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1))
                  - 1].re;
                c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1))
                  - 1].im;
                c25_n_x = c25_a22.re;
                c25_o_x = c25_n_x;
                c25_l_y = muDoubleScalarAbs(c25_o_x);
                c25_p_x = c25_a22.im;
                c25_q_x = c25_p_x;
                c25_m_y = muDoubleScalarAbs(c25_q_x);
                c25_n_y = c25_l_y + c25_m_y;
                c25_temp2 = c25_ascale * c25_n_y;
                c25_r_x = c25_temp;
                c25_o_y = c25_temp2;
                c25_tempr = c25_r_x;
                if (c25_o_y > c25_tempr) {
                  c25_tempr = c25_o_y;
                }

                if (c25_tempr < 1.0) {
                  if (c25_tempr != 0.0) {
                    c25_temp /= c25_tempr;
                    c25_temp2 /= c25_tempr;
                  }
                }

                c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2, 0) - 1) << 1))
                  - 1].re;
                c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2, 0) - 1) << 1))
                  - 1].im;
                c25_s_x = c25_a22.re;
                c25_t_x = c25_s_x;
                c25_p_y = muDoubleScalarAbs(c25_t_x);
                c25_u_x = c25_a22.im;
                c25_v_x = c25_u_x;
                c25_q_y = muDoubleScalarAbs(c25_v_x);
                c25_r_y = c25_p_y + c25_q_y;
                if (c25_r_y * c25_temp2 <= c25_temp * c25_atol) {
                  c25_goto90 = true;
                  exitg2 = true;
                } else {
                  c25_jp1 = c25_b_j;
                  c25_b_j = c25_jm1;
                }
              }

              if (!c25_goto90) {
                c25_istart = c25_ifirst;
                if (c25_istart == c25_ilastm1) {
                  c25_ctemp = c25_rho;
                } else {
                  c25_ctemp.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 2, 1,
                    0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 2, 2, 0) - 1)
                          << 1)) - 1].re - c25_a21.re;
                  c25_ctemp.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 2, 1,
                    0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 2, 2, 0) - 1)
                          << 1)) - 1].im - c25_a21.im;
                }

                c25_goto90 = true;
              }
            }

            if (c25_goto90) {
              c25_goto90 = false;
              c25_y_a = c25_istart;
              c25_ab_a = c25_y_a + 1;
              c25_f_c = c25_ab_a;
              c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_f_c), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 2, 2, 0) - 1) <<
                1)) - 1].re;
              c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_f_c), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 2, 2, 0) - 1) <<
                1)) - 1].im;
              c25_b_eml_matlab_zlartg(chartInstance, c25_ctemp, c25_a22,
                &c25_g_c, &c25_s);
              c25_d_c = c25_g_c;
              c25_b_j = c25_istart;
              c25_bb_a = c25_b_j;
              c25_cb_a = c25_bb_a - 1;
              c25_jm1 = c25_cb_a;
              while (c25_b_j < c25_ilast) {
                c25_db_a = c25_b_j;
                c25_eb_a = c25_db_a + 1;
                c25_jp1 = c25_eb_a;
                if (c25_b_j > c25_istart) {
                  c25_f_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c25_f_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c25_g_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c25_g_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c25_eml_matlab_zlartg(chartInstance, c25_f_A, c25_g_A,
                                        &c25_h_c, &c25_s, &c25_a22);
                  c25_d_c = c25_h_c;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c25_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c25_a22.im;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c25_dc13.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c25_dc13.im;
                }

                c25_i_c = c25_d_c;
                c25_xrow = c25_b_j;
                c25_yrow = c25_jp1;
                c25_jlo = c25_b_j;
                c25_jhi = c25_ilastm;
                c25_b_jlo = c25_jlo;
                c25_b_jhi = c25_jhi;
                c25_fb_a = c25_b_jlo;
                c25_i_b = c25_b_jhi;
                c25_gb_a = c25_fb_a;
                c25_j_b = c25_i_b;
                if (c25_gb_a > c25_j_b) {
                  c25_d_overflow = false;
                } else {
                  c25_eml_switch_helper(chartInstance);
                  c25_eml_switch_helper(chartInstance);
                  c25_d_overflow = (c25_j_b > 2147483646);
                }

                if (c25_d_overflow) {
                  c25_check_forloop_overflow_error(chartInstance, c25_d_overflow);
                }

                for (c25_c_j = c25_b_jlo; c25_c_j <= c25_b_jhi; c25_c_j++) {
                  c25_d_j = c25_c_j;
                  c25_hb_a = c25_i_c;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c25_a12.re = c25_hb_a * c25_a22.re;
                  c25_a12.im = c25_hb_a * c25_a22.im;
                  c25_e_s.re = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2,
                    1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0) - 1) <<
                             1)) - 1].re - c25_s.im * c25_b_A
                    [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0) -
                        1) << 1)) - 1].im;
                  c25_e_s.im = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2,
                    1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0) - 1) <<
                             1)) - 1].im + c25_s.im * c25_b_A
                    [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0) -
                        1) << 1)) - 1].re;
                  c25_a21.re = c25_a12.re + c25_e_s.re;
                  c25_a21.im = c25_a12.im + c25_e_s.im;
                  c25_ib_a = c25_i_c;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c25_a12.re = c25_ib_a * c25_a22.re;
                  c25_a12.im = c25_ib_a * c25_a22.im;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c25_f_a22 = c25_a22;
                  c25_g_a22 = c25_a22;
                  c25_h_a22 = c25_a22;
                  c25_i_a22 = c25_a22;
                  c25_a22.re = c25_s.re * c25_f_a22.re + c25_s.im * c25_g_a22.im;
                  c25_a22.im = c25_s.re * c25_h_a22.im - c25_s.im * c25_i_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c25_a12.re - c25_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c25_a12.im - c25_a22.im;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c25_a21.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c25_a21.im;
                }

                c25_s.re = -c25_s.re;
                c25_s.im = -c25_s.im;
                c25_jb_a = c25_jp1;
                c25_kb_a = c25_jb_a + 1;
                c25_j_c = c25_kb_a;
                c25_w_x = c25_j_c;
                c25_s_y = c25_ilast;
                c25_x_x = c25_w_x;
                if (c25_s_y < c25_x_x) {
                  c25_x_x = c25_s_y;
                }

                c25_k_c = c25_d_c;
                c25_b_xcol = c25_jp1;
                c25_b_ycol = c25_b_j;
                c25_d_ilo = c25_ifrstm;
                c25_d_ihi = c25_x_x;
                c25_e_ilo = c25_d_ilo;
                c25_e_ihi = c25_d_ihi;
                c25_lb_a = c25_e_ilo;
                c25_k_b = c25_e_ihi;
                c25_mb_a = c25_lb_a;
                c25_l_b = c25_k_b;
                if (c25_mb_a > c25_l_b) {
                  c25_e_overflow = false;
                } else {
                  c25_eml_switch_helper(chartInstance);
                  c25_eml_switch_helper(chartInstance);
                  c25_e_overflow = (c25_l_b > 2147483646);
                }

                if (c25_e_overflow) {
                  c25_check_forloop_overflow_error(chartInstance, c25_e_overflow);
                }

                for (c25_c_i = c25_e_ilo; c25_c_i <= c25_e_ihi; c25_c_i++) {
                  c25_d_i = c25_c_i;
                  c25_nb_a = c25_k_c;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 2, 2,
                    0) - 1) << 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 2, 2,
                    0) - 1) << 1)) - 1].im;
                  c25_a12.re = c25_nb_a * c25_a22.re;
                  c25_a12.im = c25_nb_a * c25_a22.im;
                  c25_f_s.re = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2,
                    1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 2, 2, 0) - 1)
                             << 1)) - 1].re - c25_s.im * c25_b_A
                    [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 2, 2, 0)
                        - 1) << 1)) - 1].im;
                  c25_f_s.im = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2,
                    1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 2, 2, 0) - 1)
                             << 1)) - 1].im + c25_s.im * c25_b_A
                    [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 2, 2, 0)
                        - 1) << 1)) - 1].re;
                  c25_a21.re = c25_a12.re + c25_f_s.re;
                  c25_a21.im = c25_a12.im + c25_f_s.im;
                  c25_ob_a = c25_k_c;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 2, 2,
                    0) - 1) << 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 2, 2,
                    0) - 1) << 1)) - 1].im;
                  c25_a12.re = c25_ob_a * c25_a22.re;
                  c25_a12.im = c25_ob_a * c25_a22.im;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 2, 2,
                    0) - 1) << 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 2, 2,
                    0) - 1) << 1)) - 1].im;
                  c25_j_a22 = c25_a22;
                  c25_k_a22 = c25_a22;
                  c25_l_a22 = c25_a22;
                  c25_m_a22 = c25_a22;
                  c25_a22.re = c25_s.re * c25_j_a22.re + c25_s.im * c25_k_a22.im;
                  c25_a22.im = c25_s.re * c25_l_a22.im - c25_s.im * c25_m_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 2,
                              2, 0) - 1) << 1)) - 1].re = c25_a12.re -
                    c25_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 2,
                              2, 0) - 1) << 1)) - 1].im = c25_a12.im -
                    c25_a22.im;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 2,
                              2, 0) - 1) << 1)) - 1].re = c25_a21.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 2,
                              2, 0) - 1) << 1)) - 1].im = c25_a21.im;
                }

                c25_jm1 = c25_b_j;
                c25_b_j = c25_jp1;
              }
            }

            guard11 = true;
          }

          if (guard11 == true) {
            c25_jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2 == true) {
    if (c25_failed) {
      *c25_info = c25_ilast;
      c25_b_ilast = c25_ilast;
      c25_m_b = c25_b_ilast;
      c25_n_b = c25_m_b;
      if (1 > c25_n_b) {
        c25_f_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_f_overflow = (c25_n_b > 2147483646);
      }

      if (c25_f_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_f_overflow);
      }

      for (c25_k = 1; c25_k <= c25_b_ilast; c25_k++) {
        c25_b_k = c25_k;
        c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c25_b_k), 1, 2, 1, 0) - 1].re = c25_dc12.re;
        c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c25_b_k), 1, 2, 1, 0) - 1].im = c25_dc12.im;
        c25_beta1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_k), 1, 2, 1, 0) - 1].re = c25_dc12.re;
        c25_beta1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_k), 1, 2, 1, 0) - 1].im = c25_dc12.im;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    c25_pb_a = c25_ilo;
    c25_qb_a = c25_pb_a - 1;
    c25_i185 = c25_qb_a;
    c25_o_b = c25_i185;
    c25_p_b = c25_o_b;
    if (1 > c25_p_b) {
      c25_g_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_g_overflow = (c25_p_b > 2147483646);
    }

    if (c25_g_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_g_overflow);
    }

    for (c25_e_j = 1; c25_e_j <= c25_i185; c25_e_j++) {
      c25_b_j = c25_e_j;
      c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c25_b_j), 1, 2, 1, 0) - 1].re = c25_b_A
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_b_j), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) <<
           1)) - 1].re;
      c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c25_b_j), 1, 2, 1, 0) - 1].im = c25_b_A
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_b_j), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) <<
           1)) - 1].im;
    }
  }
}

static real_T c25_eml_matlab_zlanhs(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[4], int32_T c25_ilo, int32_T c25_ihi)
{
  real_T c25_f;
  real_T c25_scale;
  real_T c25_sumsq;
  boolean_T c25_firstNonZero;
  int32_T c25_b_ilo;
  int32_T c25_b_ihi;
  int32_T c25_a;
  int32_T c25_b;
  int32_T c25_b_a;
  int32_T c25_b_b;
  boolean_T c25_overflow;
  int32_T c25_j;
  int32_T c25_b_j;
  int32_T c25_c_ilo;
  int32_T c25_c_a;
  int32_T c25_d_a;
  int32_T c25_c;
  int32_T c25_x;
  int32_T c25_y;
  int32_T c25_i186;
  int32_T c25_e_a;
  int32_T c25_c_b;
  int32_T c25_f_a;
  int32_T c25_d_b;
  boolean_T c25_b_overflow;
  int32_T c25_i;
  int32_T c25_b_i;
  creal_T c25_Aij;
  real_T c25_reAij;
  real_T c25_imAij;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_temp1;
  real_T c25_temp2;
  real_T c25_d_x;
  real_T c25_e_x;
  real_T c25_f_x;
  real_T c25_g_x;
  c25_f = 0.0;
  if (c25_ilo > c25_ihi) {
  } else {
    c25_scale = 0.0;
    c25_sumsq = 0.0;
    c25_firstNonZero = true;
    c25_b_ilo = c25_ilo;
    c25_b_ihi = c25_ihi;
    c25_a = c25_b_ilo;
    c25_b = c25_b_ihi;
    c25_b_a = c25_a;
    c25_b_b = c25_b;
    if (c25_b_a > c25_b_b) {
      c25_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_overflow = (c25_b_b > 2147483646);
    }

    if (c25_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_overflow);
    }

    for (c25_j = c25_b_ilo; c25_j <= c25_b_ihi; c25_j++) {
      c25_b_j = c25_j;
      c25_c_ilo = c25_ilo;
      c25_c_a = c25_b_j;
      c25_d_a = c25_c_a;
      c25_c = c25_d_a;
      c25_x = c25_c + 1;
      c25_y = c25_ihi;
      c25_i186 = c25_x;
      if (c25_y < c25_i186) {
        c25_i186 = c25_y;
      }

      c25_e_a = c25_c_ilo;
      c25_c_b = c25_i186;
      c25_f_a = c25_e_a;
      c25_d_b = c25_c_b;
      if (c25_f_a > c25_d_b) {
        c25_b_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_b_overflow = (c25_d_b > 2147483646);
      }

      if (c25_b_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
      }

      for (c25_i = c25_c_ilo; c25_i <= c25_i186; c25_i++) {
        c25_b_i = c25_i;
        c25_Aij.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].
          re;
        c25_Aij.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 2, 1, 0) +
                            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].
          im;
        c25_reAij = c25_Aij.re;
        c25_imAij = c25_Aij.im;
        if (c25_reAij != 0.0) {
          c25_b_x = c25_reAij;
          c25_c_x = c25_b_x;
          c25_temp1 = muDoubleScalarAbs(c25_c_x);
          if (c25_firstNonZero) {
            c25_sumsq = 1.0;
            c25_scale = c25_temp1;
            c25_firstNonZero = false;
          } else if (c25_scale < c25_temp1) {
            c25_temp2 = c25_scale / c25_temp1;
            c25_sumsq = 1.0 + c25_sumsq * c25_temp2 * c25_temp2;
            c25_scale = c25_temp1;
          } else {
            c25_temp2 = c25_temp1 / c25_scale;
            c25_sumsq += c25_temp2 * c25_temp2;
          }
        }

        if (c25_imAij != 0.0) {
          c25_d_x = c25_imAij;
          c25_e_x = c25_d_x;
          c25_temp1 = muDoubleScalarAbs(c25_e_x);
          if (c25_firstNonZero) {
            c25_sumsq = 1.0;
            c25_scale = c25_temp1;
            c25_firstNonZero = false;
          } else if (c25_scale < c25_temp1) {
            c25_temp2 = c25_scale / c25_temp1;
            c25_sumsq = 1.0 + c25_sumsq * c25_temp2 * c25_temp2;
            c25_scale = c25_temp1;
          } else {
            c25_temp2 = c25_temp1 / c25_scale;
            c25_sumsq += c25_temp2 * c25_temp2;
          }
        }
      }
    }

    c25_f_x = c25_sumsq;
    c25_g_x = c25_f_x;
    if (c25_g_x < 0.0) {
      c25_c_eml_error(chartInstance);
    }

    c25_g_x = muDoubleScalarSqrt(c25_g_x);
    c25_f = c25_scale * c25_g_x;
  }

  return c25_f;
}

static int32_T c25_mod(SFc25_hybridSysSimInstanceStruct *chartInstance, int32_T
  c25_x)
{
  int32_T c25_b_x;
  int32_T c25_t;
  c25_b_x = c25_x;
  c25_t = c25_div_s32(chartInstance, c25_b_x, 10);
  c25_t *= 10;
  return c25_b_x - c25_t;
}

static creal_T c25_b_sqrt(SFc25_hybridSysSimInstanceStruct *chartInstance,
  creal_T c25_x)
{
  creal_T c25_b_x;
  c25_b_x = c25_x;
  c25_d_sqrt(chartInstance, &c25_b_x);
  return c25_b_x;
}

static void c25_realmax(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c25_b_eml_matlab_zlartg(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_f, creal_T c25_g, real_T *c25_cs, creal_T *c25_sn)
{
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_y;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_b_y;
  real_T c25_e_x;
  real_T c25_c_y;
  real_T c25_d_y;
  real_T c25_f_x;
  real_T c25_g_x;
  real_T c25_e_y;
  real_T c25_h_x;
  real_T c25_i_x;
  real_T c25_f_y;
  real_T c25_j_x;
  real_T c25_g_y;
  real_T c25_h_y;
  real_T c25_k_x;
  real_T c25_i_y;
  real_T c25_scale;
  creal_T c25_fs;
  creal_T c25_gs;
  int32_T c25_count;
  real_T c25_rescaledir;
  int32_T c25_a;
  int32_T c25_b_a;
  static creal_T c25_dc15 = { 0.0, 0.0 };

  boolean_T c25_b_g;
  int32_T c25_c_a;
  int32_T c25_d_a;
  real_T c25_f2;
  real_T c25_g2;
  real_T c25_l_x;
  real_T c25_m_x;
  boolean_T c25_b_f;
  real_T c25_x1;
  real_T c25_x2;
  real_T c25_e_a;
  real_T c25_b;
  real_T c25_d;
  real_T c25_b_x1;
  real_T c25_b_x2;
  real_T c25_f_a;
  real_T c25_b_b;
  real_T c25_f2s;
  real_T c25_n_x;
  real_T c25_g2s;
  real_T c25_o_x;
  real_T c25_p_x;
  real_T c25_j_y;
  real_T c25_q_x;
  real_T c25_r_x;
  real_T c25_k_y;
  real_T c25_s_x;
  real_T c25_l_y;
  real_T c25_m_y;
  real_T c25_c_x1;
  real_T c25_c_x2;
  real_T c25_g_a;
  real_T c25_c_b;
  real_T c25_dr;
  real_T c25_di;
  real_T c25_d_x1;
  real_T c25_d_x2;
  real_T c25_h_a;
  real_T c25_d_b;
  creal_T c25_b_gs;
  real_T c25_t_x;
  creal_T c25_b_fs;
  creal_T c25_c_fs;
  creal_T c25_c_gs;
  creal_T c25_b_sn;
  int32_T c25_b_count;
  int32_T c25_e_b;
  int32_T c25_f_b;
  boolean_T c25_overflow;
  int32_T c25_c_count;
  int32_T c25_g_b;
  int32_T c25_h_b;
  boolean_T c25_b_overflow;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c25_eml_realmin(chartInstance);
  c25_eps(chartInstance);
  c25_eps(chartInstance);
  c25_x = c25_f.re;
  c25_b_x = c25_x;
  c25_y = muDoubleScalarAbs(c25_b_x);
  c25_c_x = c25_f.im;
  c25_d_x = c25_c_x;
  c25_b_y = muDoubleScalarAbs(c25_d_x);
  c25_e_x = c25_y;
  c25_c_y = c25_b_y;
  c25_d_y = c25_e_x;
  if (c25_c_y > c25_d_y) {
    c25_d_y = c25_c_y;
  }

  c25_f_x = c25_g.re;
  c25_g_x = c25_f_x;
  c25_e_y = muDoubleScalarAbs(c25_g_x);
  c25_h_x = c25_g.im;
  c25_i_x = c25_h_x;
  c25_f_y = muDoubleScalarAbs(c25_i_x);
  c25_j_x = c25_e_y;
  c25_g_y = c25_f_y;
  c25_h_y = c25_j_x;
  if (c25_g_y > c25_h_y) {
    c25_h_y = c25_g_y;
  }

  c25_k_x = c25_d_y;
  c25_i_y = c25_h_y;
  c25_scale = c25_k_x;
  if (c25_i_y > c25_scale) {
    c25_scale = c25_i_y;
  }

  c25_fs = c25_f;
  c25_gs = c25_g;
  c25_count = 0;
  c25_rescaledir = 0.0;
  guard1 = false;
  guard2 = false;
  if (c25_scale >= 7.4428285367870146E+137) {
    do {
      c25_a = c25_count;
      c25_b_a = c25_a + 1;
      c25_count = c25_b_a;
      c25_fs.re *= 1.3435752215134178E-138;
      c25_fs.im *= 1.3435752215134178E-138;
      c25_gs.re *= 1.3435752215134178E-138;
      c25_gs.im *= 1.3435752215134178E-138;
      c25_scale *= 1.3435752215134178E-138;
    } while (!(c25_scale < 7.4428285367870146E+137));

    c25_rescaledir = 1.0;
    guard1 = true;
  } else if (c25_scale <= 1.3435752215134178E-138) {
    c25_b_g = ((c25_g.re == c25_dc15.re) && (c25_g.im == c25_dc15.im));
    if (c25_b_g) {
      *c25_cs = 1.0;
      *c25_sn = c25_dc15;
    } else {
      do {
        c25_c_a = c25_count;
        c25_d_a = c25_c_a + 1;
        c25_count = c25_d_a;
        c25_fs.re *= 7.4428285367870146E+137;
        c25_fs.im *= 7.4428285367870146E+137;
        c25_gs.re *= 7.4428285367870146E+137;
        c25_gs.im *= 7.4428285367870146E+137;
        c25_scale *= 7.4428285367870146E+137;
      } while (!(c25_scale > 1.3435752215134178E-138));

      c25_rescaledir = -1.0;
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c25_f2 = c25_fs.re * c25_fs.re + c25_fs.im * c25_fs.im;
    c25_g2 = c25_gs.re * c25_gs.re + c25_gs.im * c25_gs.im;
    c25_l_x = c25_g2;
    c25_m_x = c25_l_x;
    if (1.0 > c25_m_x) {
      c25_m_x = 1.0;
    }

    if (c25_f2 <= c25_m_x * 2.0041683600089728E-292) {
      c25_b_f = ((c25_f.re == c25_dc15.re) && (c25_f.im == c25_dc15.im));
      if (c25_b_f) {
        *c25_cs = 0.0;
        c25_x1 = c25_gs.re;
        c25_x2 = c25_gs.im;
        c25_e_a = c25_x1;
        c25_b = c25_x2;
        c25_d = muDoubleScalarHypot(c25_e_a, c25_b);
        c25_sn->re = c25_gs.re / c25_d;
        c25_sn->im = -c25_gs.im / c25_d;
      } else {
        c25_b_x1 = c25_fs.re;
        c25_b_x2 = c25_fs.im;
        c25_f_a = c25_b_x1;
        c25_b_b = c25_b_x2;
        c25_f2s = muDoubleScalarHypot(c25_f_a, c25_b_b);
        c25_n_x = c25_g2;
        c25_g2s = c25_n_x;
        if (c25_g2s < 0.0) {
          c25_c_eml_error(chartInstance);
        }

        c25_g2s = muDoubleScalarSqrt(c25_g2s);
        *c25_cs = c25_f2s / c25_g2s;
        c25_o_x = c25_f.re;
        c25_p_x = c25_o_x;
        c25_j_y = muDoubleScalarAbs(c25_p_x);
        c25_q_x = c25_f.im;
        c25_r_x = c25_q_x;
        c25_k_y = muDoubleScalarAbs(c25_r_x);
        c25_s_x = c25_j_y;
        c25_l_y = c25_k_y;
        c25_m_y = c25_s_x;
        if (c25_l_y > c25_m_y) {
          c25_m_y = c25_l_y;
        }

        if (c25_m_y > 1.0) {
          c25_c_x1 = c25_f.re;
          c25_c_x2 = c25_f.im;
          c25_g_a = c25_c_x1;
          c25_c_b = c25_c_x2;
          c25_d = muDoubleScalarHypot(c25_g_a, c25_c_b);
          c25_fs.re = c25_f.re / c25_d;
          c25_fs.im = c25_f.im / c25_d;
        } else {
          c25_dr = 7.4428285367870146E+137 * c25_f.re;
          c25_di = 7.4428285367870146E+137 * c25_f.im;
          c25_d_x1 = c25_dr;
          c25_d_x2 = c25_di;
          c25_h_a = c25_d_x1;
          c25_d_b = c25_d_x2;
          c25_d = muDoubleScalarHypot(c25_h_a, c25_d_b);
          c25_fs.re = c25_dr / c25_d;
          c25_fs.im = c25_di / c25_d;
        }

        c25_b_gs.re = c25_gs.re / c25_g2s;
        c25_b_gs.im = -c25_gs.im / c25_g2s;
        c25_sn->re = c25_fs.re * c25_b_gs.re - c25_fs.im * c25_b_gs.im;
        c25_sn->im = c25_fs.re * c25_b_gs.im + c25_fs.im * c25_b_gs.re;
      }
    } else {
      c25_t_x = 1.0 + c25_g2 / c25_f2;
      c25_f2s = c25_t_x;
      if (c25_f2s < 0.0) {
        c25_c_eml_error(chartInstance);
      }

      c25_f2s = muDoubleScalarSqrt(c25_f2s);
      c25_b_fs = c25_fs;
      c25_c_fs = c25_fs;
      c25_fs.re = c25_f2s * c25_b_fs.re;
      c25_fs.im = c25_f2s * c25_c_fs.im;
      *c25_cs = 1.0 / c25_f2s;
      c25_d = c25_f2 + c25_g2;
      c25_sn->re = c25_fs.re / c25_d;
      c25_sn->im = c25_fs.im / c25_d;
      c25_c_gs.re = c25_gs.re;
      c25_c_gs.im = -c25_gs.im;
      c25_b_sn = *c25_sn;
      c25_sn->re = c25_b_sn.re * c25_c_gs.re - c25_b_sn.im * c25_c_gs.im;
      c25_sn->im = c25_b_sn.re * c25_c_gs.im + c25_b_sn.im * c25_c_gs.re;
      if (c25_rescaledir > 0.0) {
        c25_b_count = c25_count;
        c25_e_b = c25_b_count;
        c25_f_b = c25_e_b;
        if (1 > c25_f_b) {
          c25_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_overflow = (c25_f_b > 2147483646);
        }

        if (c25_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_overflow);
        }
      } else {
        if (c25_rescaledir < 0.0) {
          c25_c_count = c25_count;
          c25_g_b = c25_c_count;
          c25_h_b = c25_g_b;
          if (1 > c25_h_b) {
            c25_b_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_b_overflow = (c25_h_b > 2147483646);
          }

          if (c25_b_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
          }
        }
      }
    }
  }
}

static void c25_eml_warning(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c25_i187;
  static char_T c25_varargin_1[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e',
    'i', 'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c',
    'e' };

  char_T c25_u[24];
  const mxArray *c25_y = NULL;
  (void)chartInstance;
  for (c25_i187 = 0; c25_i187 < 24; c25_i187++) {
    c25_u[c25_i187] = c25_varargin_1[c25_i187];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c25_y));
}

static boolean_T c25_eml_relop(SFc25_hybridSysSimInstanceStruct *chartInstance,
  creal_T c25_a, creal_T c25_b)
{
  real_T c25_RMAXA;
  real_T c25_RMAXB;
  real_T c25_d8;
  real_T c25_d9;
  real_T c25_d10;
  real_T c25_d11;
  real_T c25_A;
  real_T c25_y;
  real_T c25_b_A;
  real_T c25_b_y;
  real_T c25_x;
  real_T c25_c_A;
  real_T c25_c_y;
  real_T c25_d_A;
  real_T c25_d_y;
  real_T c25_e_y;
  real_T c25_b_a;
  real_T c25_b_b;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_f_y;
  real_T c25_e_A;
  real_T c25_g_y;
  real_T c25_d_x;
  real_T c25_e_x;
  real_T c25_f_x;
  real_T c25_absxk;
  real_T c25_r;
  int32_T c25_exponent;
  int32_T c25_b_exponent;
  int32_T c25_c_exponent;
  real_T c25_g_x;
  boolean_T c25_c_b;
  real_T c25_h_x;
  boolean_T c25_d_b;
  boolean_T c25_b23;
  boolean_T c25_b_p;
  real_T c25_ar;
  real_T c25_absar;
  real_T c25_ai;
  real_T c25_absai;
  real_T c25_br;
  real_T c25_absbr;
  real_T c25_bi;
  real_T c25_absbi;
  real_T c25_Ma;
  real_T c25_ma;
  real_T c25_Mb;
  real_T c25_mb;
  real_T c25_f_A;
  real_T c25_h_y;
  real_T c25_g_A;
  real_T c25_i_y;
  real_T c25_Mbar;
  real_T c25_h_A;
  real_T c25_j_y;
  real_T c25_i_A;
  real_T c25_k_y;
  real_T c25_mbar;
  real_T c25_j_A;
  real_T c25_B;
  real_T c25_l_y;
  real_T c25_k_A;
  real_T c25_m_y;
  real_T c25_l_A;
  real_T c25_n_y;
  real_T c25_m_A;
  real_T c25_o_y;
  real_T c25_n_A;
  real_T c25_p_y;
  real_T c25_o_A;
  real_T c25_b_B;
  real_T c25_q_y;
  real_T c25_c_a;
  real_T c25_e_b;
  real_T c25_i_x;
  real_T c25_j_x;
  real_T c25_r_y;
  real_T c25_p_A;
  real_T c25_s_y;
  real_T c25_k_x;
  real_T c25_l_x;
  real_T c25_m_x;
  real_T c25_b_absxk;
  real_T c25_b_r;
  int32_T c25_d_exponent;
  int32_T c25_e_exponent;
  int32_T c25_f_exponent;
  real_T c25_n_x;
  boolean_T c25_f_b;
  real_T c25_o_x;
  boolean_T c25_g_b;
  boolean_T c25_b24;
  boolean_T c25_c_p;
  real_T c25_d_a;
  real_T c25_h_b;
  real_T c25_p_x;
  real_T c25_q_x;
  real_T c25_t_y;
  real_T c25_q_A;
  real_T c25_u_y;
  real_T c25_r_x;
  real_T c25_s_x;
  real_T c25_t_x;
  real_T c25_c_absxk;
  real_T c25_c_r;
  int32_T c25_g_exponent;
  int32_T c25_h_exponent;
  int32_T c25_i_exponent;
  real_T c25_u_x;
  boolean_T c25_i_b;
  real_T c25_v_x;
  boolean_T c25_j_b;
  boolean_T c25_b25;
  boolean_T c25_d_p;
  real_T c25_v_y;
  real_T c25_w_y;
  real_T c25_x_y;
  real_T c25_y_y;
  real_T c25_e_a;
  real_T c25_k_b;
  real_T c25_w_x;
  real_T c25_x_x;
  real_T c25_ab_y;
  real_T c25_r_A;
  real_T c25_bb_y;
  real_T c25_y_x;
  real_T c25_ab_x;
  real_T c25_bb_x;
  real_T c25_d_absxk;
  real_T c25_d_r;
  int32_T c25_j_exponent;
  int32_T c25_k_exponent;
  int32_T c25_l_exponent;
  real_T c25_cb_x;
  boolean_T c25_l_b;
  real_T c25_db_x;
  boolean_T c25_m_b;
  boolean_T c25_b26;
  boolean_T c25_e_p;
  real_T c25_eb_x;
  real_T c25_cb_y;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  boolean_T guard13 = false;
  boolean_T guard14 = false;
  boolean_T guard15 = false;
  c25_realmax(chartInstance);
  c25_RMAXA = c25_rdivide(chartInstance, 1.7976931348623157E+308, 2.0);
  c25_realmax(chartInstance);
  c25_RMAXB = c25_rdivide(chartInstance, 1.7976931348623157E+308, 2.0);
  c25_d8 = c25_abs(chartInstance, c25_a.re);
  guard13 = false;
  guard14 = false;
  guard15 = false;
  if (c25_d8 > c25_RMAXA) {
    guard15 = true;
  } else {
    c25_d9 = c25_abs(chartInstance, c25_a.im);
    if (c25_d9 > c25_RMAXA) {
      guard15 = true;
    } else {
      c25_d10 = c25_abs(chartInstance, c25_b.re);
      if (c25_d10 > c25_RMAXB) {
        guard14 = true;
      } else {
        c25_d11 = c25_abs(chartInstance, c25_b.im);
        if (c25_d11 > c25_RMAXB) {
          guard13 = true;
        } else {
          c25_x = c25_b_abs(chartInstance, c25_a);
          c25_e_y = c25_b_abs(chartInstance, c25_b);
        }
      }
    }
  }

  if (guard15 == true) {
    guard14 = true;
  }

  if (guard14 == true) {
    guard13 = true;
  }

  if (guard13 == true) {
    c25_A = c25_a.re;
    c25_y = c25_rdivide(chartInstance, c25_A, 2.0);
    c25_b_A = c25_a.im;
    c25_b_y = c25_rdivide(chartInstance, c25_b_A, 2.0);
    c25_x = c25_hypot(chartInstance, c25_y, c25_b_y);
    c25_c_A = c25_b.re;
    c25_c_y = c25_rdivide(chartInstance, c25_c_A, 2.0);
    c25_d_A = c25_b.im;
    c25_d_y = c25_rdivide(chartInstance, c25_d_A, 2.0);
    c25_e_y = c25_hypot(chartInstance, c25_c_y, c25_d_y);
  }

  c25_b_a = c25_x;
  c25_b_b = c25_e_y;
  c25_b_x = c25_b_b - c25_b_a;
  c25_c_x = c25_b_x;
  c25_f_y = muDoubleScalarAbs(c25_c_x);
  c25_e_A = c25_b_b;
  c25_g_y = c25_rdivide(chartInstance, c25_e_A, 2.0);
  c25_d_x = c25_g_y;
  c25_eml_realmin(chartInstance);
  c25_e_x = c25_d_x;
  c25_f_x = c25_e_x;
  c25_absxk = muDoubleScalarAbs(c25_f_x);
  if (c25_isfinite(chartInstance, c25_absxk)) {
    if (c25_absxk <= 2.2250738585072014E-308) {
      c25_r = 4.94065645841247E-324;
    } else {
      frexp(c25_absxk, &c25_exponent);
      c25_b_exponent = c25_exponent;
      c25_c_exponent = c25_b_exponent;
      c25_c_exponent;
      c25_r = ldexp(1.0, c25_c_exponent - 53);
    }
  } else {
    c25_r = rtNaN;
  }

  guard10 = false;
  guard11 = false;
  guard12 = false;
  if (c25_f_y < c25_r) {
    guard11 = true;
  } else {
    c25_g_x = c25_b_a;
    c25_c_b = muDoubleScalarIsInf(c25_g_x);
    if (c25_c_b) {
      c25_h_x = c25_b_b;
      c25_d_b = muDoubleScalarIsInf(c25_h_x);
      if (c25_d_b) {
        if (c25_b_a > 0.0 == c25_b_b > 0.0) {
          guard11 = true;
        } else {
          guard10 = true;
        }
      } else {
        guard12 = true;
      }
    } else {
      guard12 = true;
    }
  }

  if (guard12 == true) {
    guard10 = true;
  }

  if (guard11 == true) {
    c25_b23 = true;
  }

  if (guard10 == true) {
    c25_b23 = false;
  }

  c25_b_p = c25_b23;
  if (c25_b_p) {
    c25_ar = c25_a.re;
    c25_absar = c25_abs(chartInstance, c25_ar);
    c25_ai = c25_a.im;
    c25_absai = c25_abs(chartInstance, c25_ai);
    c25_br = c25_b.re;
    c25_absbr = c25_abs(chartInstance, c25_br);
    c25_bi = c25_b.im;
    c25_absbi = c25_abs(chartInstance, c25_bi);
    if (c25_absar > c25_absai) {
      c25_Ma = c25_absar;
      c25_ma = c25_absai;
    } else {
      c25_Ma = c25_absai;
      c25_ma = c25_absar;
    }

    if (c25_absbr > c25_absbi) {
      c25_Mb = c25_absbr;
      c25_mb = c25_absbi;
    } else {
      c25_Mb = c25_absbi;
      c25_mb = c25_absbr;
    }

    if (c25_Ma > c25_Mb) {
      if (c25_ma < c25_mb) {
        c25_x = c25_Ma - c25_Mb;
        c25_f_A = c25_Ma;
        c25_h_y = c25_rdivide(chartInstance, c25_f_A, 2.0);
        c25_g_A = c25_Mb;
        c25_i_y = c25_rdivide(chartInstance, c25_g_A, 2.0);
        c25_Mbar = c25_h_y + c25_i_y;
        c25_h_A = c25_ma;
        c25_j_y = c25_rdivide(chartInstance, c25_h_A, 2.0);
        c25_i_A = c25_mb;
        c25_k_y = c25_rdivide(chartInstance, c25_i_A, 2.0);
        c25_mbar = c25_j_y + c25_k_y;
        c25_j_A = c25_mbar;
        c25_B = c25_Mbar;
        c25_l_y = c25_rdivide(chartInstance, c25_j_A, c25_B);
        c25_e_y = c25_l_y * (c25_mb - c25_ma);
      } else {
        c25_x = c25_Ma;
        c25_e_y = c25_Mb;
      }
    } else if (c25_Ma < c25_Mb) {
      if (c25_ma > c25_mb) {
        c25_e_y = c25_Mb - c25_Ma;
        c25_k_A = c25_Ma;
        c25_m_y = c25_rdivide(chartInstance, c25_k_A, 2.0);
        c25_l_A = c25_Mb;
        c25_n_y = c25_rdivide(chartInstance, c25_l_A, 2.0);
        c25_Mbar = c25_m_y + c25_n_y;
        c25_m_A = c25_ma;
        c25_o_y = c25_rdivide(chartInstance, c25_m_A, 2.0);
        c25_n_A = c25_mb;
        c25_p_y = c25_rdivide(chartInstance, c25_n_A, 2.0);
        c25_mbar = c25_o_y + c25_p_y;
        c25_o_A = c25_mbar;
        c25_b_B = c25_Mbar;
        c25_q_y = c25_rdivide(chartInstance, c25_o_A, c25_b_B);
        c25_x = c25_q_y * (c25_ma - c25_mb);
      } else {
        c25_x = c25_Ma;
        c25_e_y = c25_Mb;
      }
    } else {
      c25_x = c25_ma;
      c25_e_y = c25_mb;
    }

    c25_c_a = c25_x;
    c25_e_b = c25_e_y;
    c25_i_x = c25_e_b - c25_c_a;
    c25_j_x = c25_i_x;
    c25_r_y = muDoubleScalarAbs(c25_j_x);
    c25_p_A = c25_e_b;
    c25_s_y = c25_rdivide(chartInstance, c25_p_A, 2.0);
    c25_k_x = c25_s_y;
    c25_eml_realmin(chartInstance);
    c25_l_x = c25_k_x;
    c25_m_x = c25_l_x;
    c25_b_absxk = muDoubleScalarAbs(c25_m_x);
    if (c25_isfinite(chartInstance, c25_b_absxk)) {
      if (c25_b_absxk <= 2.2250738585072014E-308) {
        c25_b_r = 4.94065645841247E-324;
      } else {
        frexp(c25_b_absxk, &c25_d_exponent);
        c25_e_exponent = c25_d_exponent;
        c25_f_exponent = c25_e_exponent;
        c25_f_exponent;
        c25_b_r = ldexp(1.0, c25_f_exponent - 53);
      }
    } else {
      c25_b_r = rtNaN;
    }

    guard7 = false;
    guard8 = false;
    guard9 = false;
    if (c25_r_y < c25_b_r) {
      guard8 = true;
    } else {
      c25_n_x = c25_c_a;
      c25_f_b = muDoubleScalarIsInf(c25_n_x);
      if (c25_f_b) {
        c25_o_x = c25_e_b;
        c25_g_b = muDoubleScalarIsInf(c25_o_x);
        if (c25_g_b) {
          if (c25_c_a > 0.0 == c25_e_b > 0.0) {
            guard8 = true;
          } else {
            guard7 = true;
          }
        } else {
          guard9 = true;
        }
      } else {
        guard9 = true;
      }
    }

    if (guard9 == true) {
      guard7 = true;
    }

    if (guard8 == true) {
      c25_b24 = true;
    }

    if (guard7 == true) {
      c25_b24 = false;
    }

    c25_c_p = c25_b24;
    if (c25_c_p) {
      c25_x = c25_angle(chartInstance, c25_a);
      c25_e_y = c25_angle(chartInstance, c25_b);
      c25_d_a = c25_x;
      c25_h_b = c25_e_y;
      c25_p_x = c25_h_b - c25_d_a;
      c25_q_x = c25_p_x;
      c25_t_y = muDoubleScalarAbs(c25_q_x);
      c25_q_A = c25_h_b;
      c25_u_y = c25_rdivide(chartInstance, c25_q_A, 2.0);
      c25_r_x = c25_u_y;
      c25_eml_realmin(chartInstance);
      c25_s_x = c25_r_x;
      c25_t_x = c25_s_x;
      c25_c_absxk = muDoubleScalarAbs(c25_t_x);
      if (c25_isfinite(chartInstance, c25_c_absxk)) {
        if (c25_c_absxk <= 2.2250738585072014E-308) {
          c25_c_r = 4.94065645841247E-324;
        } else {
          frexp(c25_c_absxk, &c25_g_exponent);
          c25_h_exponent = c25_g_exponent;
          c25_i_exponent = c25_h_exponent;
          c25_i_exponent;
          c25_c_r = ldexp(1.0, c25_i_exponent - 53);
        }
      } else {
        c25_c_r = rtNaN;
      }

      guard4 = false;
      guard5 = false;
      guard6 = false;
      if (c25_t_y < c25_c_r) {
        guard5 = true;
      } else {
        c25_u_x = c25_d_a;
        c25_i_b = muDoubleScalarIsInf(c25_u_x);
        if (c25_i_b) {
          c25_v_x = c25_h_b;
          c25_j_b = muDoubleScalarIsInf(c25_v_x);
          if (c25_j_b) {
            if (c25_d_a > 0.0 == c25_h_b > 0.0) {
              guard5 = true;
            } else {
              guard4 = true;
            }
          } else {
            guard6 = true;
          }
        } else {
          guard6 = true;
        }
      }

      if (guard6 == true) {
        guard4 = true;
      }

      if (guard5 == true) {
        c25_b25 = true;
      }

      if (guard4 == true) {
        c25_b25 = false;
      }

      c25_d_p = c25_b25;
      if (c25_d_p) {
        c25_v_y = c25_rdivide(chartInstance, 3.1415926535897931, 4.0);
        if (c25_x > c25_v_y) {
          c25_w_y = c25_rdivide(chartInstance, 9.42477796076938, 4.0);
          if (c25_x > c25_w_y) {
            c25_x = -c25_ai;
            c25_e_y = -c25_bi;
          } else {
            c25_x = -c25_ar;
            c25_e_y = -c25_br;
          }
        } else {
          c25_x_y = c25_rdivide(chartInstance, -3.1415926535897931, 4.0);
          if (c25_x > c25_x_y) {
            c25_x = c25_ai;
            c25_e_y = c25_bi;
          } else {
            c25_y_y = c25_rdivide(chartInstance, -9.42477796076938, 4.0);
            if (c25_x > c25_y_y) {
              c25_x = c25_ar;
              c25_e_y = c25_br;
            } else {
              c25_x = -c25_ai;
              c25_e_y = -c25_bi;
            }
          }
        }

        c25_e_a = c25_x;
        c25_k_b = c25_e_y;
        c25_w_x = c25_k_b - c25_e_a;
        c25_x_x = c25_w_x;
        c25_ab_y = muDoubleScalarAbs(c25_x_x);
        c25_r_A = c25_k_b;
        c25_bb_y = c25_rdivide(chartInstance, c25_r_A, 2.0);
        c25_y_x = c25_bb_y;
        c25_eml_realmin(chartInstance);
        c25_ab_x = c25_y_x;
        c25_bb_x = c25_ab_x;
        c25_d_absxk = muDoubleScalarAbs(c25_bb_x);
        if (c25_isfinite(chartInstance, c25_d_absxk)) {
          if (c25_d_absxk <= 2.2250738585072014E-308) {
            c25_d_r = 4.94065645841247E-324;
          } else {
            frexp(c25_d_absxk, &c25_j_exponent);
            c25_k_exponent = c25_j_exponent;
            c25_l_exponent = c25_k_exponent;
            c25_l_exponent;
            c25_d_r = ldexp(1.0, c25_l_exponent - 53);
          }
        } else {
          c25_d_r = rtNaN;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (c25_ab_y < c25_d_r) {
          guard2 = true;
        } else {
          c25_cb_x = c25_e_a;
          c25_l_b = muDoubleScalarIsInf(c25_cb_x);
          if (c25_l_b) {
            c25_db_x = c25_k_b;
            c25_m_b = muDoubleScalarIsInf(c25_db_x);
            if (c25_m_b) {
              if (c25_e_a > 0.0 == c25_k_b > 0.0) {
                guard2 = true;
              } else {
                guard1 = true;
              }
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
        }

        if (guard3 == true) {
          guard1 = true;
        }

        if (guard2 == true) {
          c25_b26 = true;
        }

        if (guard1 == true) {
          c25_b26 = false;
        }

        c25_e_p = c25_b26;
        if (c25_e_p) {
          c25_x = 0.0;
          c25_e_y = 0.0;
        }
      }
    }
  }

  c25_eb_x = c25_x;
  c25_cb_y = c25_e_y;
  return c25_eb_x < c25_cb_y;
}

static real_T c25_hypot(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x, real_T c25_y)
{
  real_T c25_b_x;
  real_T c25_b_y;
  real_T c25_x1;
  real_T c25_x2;
  real_T c25_a;
  real_T c25_b;
  c25_eml_scalar_eg(chartInstance);
  c25_b_x = c25_x;
  c25_b_y = c25_y;
  c25_eml_scalar_eg(chartInstance);
  c25_x1 = c25_b_x;
  c25_x2 = c25_b_y;
  c25_a = c25_x1;
  c25_b = c25_x2;
  return muDoubleScalarHypot(c25_a, c25_b);
}

static real_T c25_angle(SFc25_hybridSysSimInstanceStruct *chartInstance, creal_T
  c25_x)
{
  real_T c25_b_y;
  real_T c25_b_x;
  (void)chartInstance;
  c25_b_y = c25_x.im;
  c25_b_x = c25_x.re;
  return muDoubleScalarAtan2(c25_b_y, c25_b_x);
}

static void c25_inv(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
                    c25_x[4], real_T c25_y[4])
{
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_e_x;
  real_T c25_b_y;
  real_T c25_f_x;
  real_T c25_g_x;
  real_T c25_c_y;
  real_T c25_d;
  real_T c25_h_x;
  real_T c25_i_x;
  real_T c25_j_x;
  real_T c25_k_x;
  real_T c25_d_y;
  real_T c25_l_x;
  real_T c25_m_x;
  real_T c25_e_y;
  real_T c25_b_d;
  real_T c25_A;
  real_T c25_B;
  real_T c25_r;
  real_T c25_b_B;
  real_T c25_t;
  real_T c25_b_A;
  real_T c25_c_B;
  real_T c25_f_y;
  real_T c25_c_A;
  real_T c25_d_B;
  real_T c25_g_y;
  real_T c25_d_A;
  real_T c25_e_B;
  real_T c25_f_B;
  real_T c25_e_A;
  real_T c25_g_B;
  real_T c25_h_y;
  real_T c25_f_A;
  real_T c25_h_B;
  real_T c25_i_y;
  int32_T c25_i188;
  real_T c25_n_x[4];
  real_T c25_n1x;
  int32_T c25_i189;
  real_T c25_j_y[4];
  real_T c25_n1xinv;
  real_T c25_rc;
  real_T c25_o_x;
  boolean_T c25_b;
  real_T c25_p_x;
  int32_T c25_i190;
  static char_T c25_cv6[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c25_u[8];
  const mxArray *c25_k_y = NULL;
  real_T c25_b_u;
  const mxArray *c25_l_y = NULL;
  real_T c25_c_u;
  const mxArray *c25_m_y = NULL;
  real_T c25_d_u;
  const mxArray *c25_n_y = NULL;
  char_T c25_str[14];
  int32_T c25_i191;
  char_T c25_b_str[14];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c25_b_x = c25_x[1];
  c25_c_x = c25_b_x;
  c25_d_x = c25_c_x;
  c25_e_x = c25_d_x;
  c25_b_y = muDoubleScalarAbs(c25_e_x);
  c25_f_x = 0.0;
  c25_g_x = c25_f_x;
  c25_c_y = muDoubleScalarAbs(c25_g_x);
  c25_d = c25_b_y + c25_c_y;
  c25_h_x = c25_x[0];
  c25_i_x = c25_h_x;
  c25_j_x = c25_i_x;
  c25_k_x = c25_j_x;
  c25_d_y = muDoubleScalarAbs(c25_k_x);
  c25_l_x = 0.0;
  c25_m_x = c25_l_x;
  c25_e_y = muDoubleScalarAbs(c25_m_x);
  c25_b_d = c25_d_y + c25_e_y;
  if (c25_d > c25_b_d) {
    c25_A = c25_x[0];
    c25_B = c25_x[1];
    c25_r = c25_rdivide(chartInstance, c25_A, c25_B);
    c25_b_B = c25_r * c25_x[3] - c25_x[2];
    c25_t = c25_rdivide(chartInstance, 1.0, c25_b_B);
    c25_b_A = c25_x[3];
    c25_c_B = c25_x[1];
    c25_f_y = c25_rdivide(chartInstance, c25_b_A, c25_c_B);
    c25_y[0] = c25_f_y * c25_t;
    c25_y[1] = -c25_t;
    c25_c_A = -c25_x[2];
    c25_d_B = c25_x[1];
    c25_g_y = c25_rdivide(chartInstance, c25_c_A, c25_d_B);
    c25_y[2] = c25_g_y * c25_t;
    c25_y[3] = c25_r * c25_t;
  } else {
    c25_d_A = c25_x[1];
    c25_e_B = c25_x[0];
    c25_r = c25_rdivide(chartInstance, c25_d_A, c25_e_B);
    c25_f_B = c25_x[3] - c25_r * c25_x[2];
    c25_t = c25_rdivide(chartInstance, 1.0, c25_f_B);
    c25_e_A = c25_x[3];
    c25_g_B = c25_x[0];
    c25_h_y = c25_rdivide(chartInstance, c25_e_A, c25_g_B);
    c25_y[0] = c25_h_y * c25_t;
    c25_y[1] = -c25_r * c25_t;
    c25_f_A = -c25_x[2];
    c25_h_B = c25_x[0];
    c25_i_y = c25_rdivide(chartInstance, c25_f_A, c25_h_B);
    c25_y[2] = c25_i_y * c25_t;
    c25_y[3] = c25_t;
  }

  for (c25_i188 = 0; c25_i188 < 4; c25_i188++) {
    c25_n_x[c25_i188] = c25_x[c25_i188];
  }

  c25_n1x = c25_c_norm(chartInstance, c25_n_x);
  for (c25_i189 = 0; c25_i189 < 4; c25_i189++) {
    c25_j_y[c25_i189] = c25_y[c25_i189];
  }

  c25_n1xinv = c25_c_norm(chartInstance, c25_j_y);
  c25_rc = 1.0 / (c25_n1x * c25_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c25_n1x == 0.0) {
    guard2 = true;
  } else if (c25_n1xinv == 0.0) {
    guard2 = true;
  } else if (c25_rc == 0.0) {
    guard1 = true;
  } else {
    c25_o_x = c25_rc;
    c25_b = muDoubleScalarIsNaN(c25_o_x);
    guard3 = false;
    if (c25_b) {
      guard3 = true;
    } else {
      c25_eps(chartInstance);
      if (c25_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c25_p_x = c25_rc;
      for (c25_i190 = 0; c25_i190 < 8; c25_i190++) {
        c25_u[c25_i190] = c25_cv6[c25_i190];
      }

      c25_k_y = NULL;
      sf_mex_assign(&c25_k_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    false);
      c25_b_u = 14.0;
      c25_l_y = NULL;
      sf_mex_assign(&c25_l_y, sf_mex_create("y", &c25_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c25_c_u = 6.0;
      c25_m_y = NULL;
      sf_mex_assign(&c25_m_y, sf_mex_create("y", &c25_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c25_d_u = c25_p_x;
      c25_n_y = NULL;
      sf_mex_assign(&c25_n_y, sf_mex_create("y", &c25_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      c25_i_emlrt_marshallIn(chartInstance, sf_mex_call_debug
        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14, sf_mex_call_debug
         (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14, c25_k_y, 14,
          c25_l_y, 14, c25_m_y), 14, c25_n_y), "sprintf", c25_str);
      for (c25_i191 = 0; c25_i191 < 14; c25_i191++) {
        c25_b_str[c25_i191] = c25_str[c25_i191];
      }

      c25_c_eml_warning(chartInstance, c25_b_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c25_b_eml_warning(chartInstance);
  }
}

static real_T c25_c_norm(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  c25_x[4])
{
  real_T c25_y;
  int32_T c25_j;
  real_T c25_b_j;
  real_T c25_s;
  int32_T c25_i;
  real_T c25_b_i;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_b_y;
  real_T c25_d_x;
  boolean_T c25_b;
  boolean_T exitg1;
  (void)chartInstance;
  c25_y = 0.0;
  c25_j = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c25_j < 2)) {
    c25_b_j = 1.0 + (real_T)c25_j;
    c25_s = 0.0;
    for (c25_i = 0; c25_i < 2; c25_i++) {
      c25_b_i = 1.0 + (real_T)c25_i;
      c25_b_x = c25_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c25_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c25_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c25_c_x = c25_b_x;
      c25_b_y = muDoubleScalarAbs(c25_c_x);
      c25_s += c25_b_y;
    }

    c25_d_x = c25_s;
    c25_b = muDoubleScalarIsNaN(c25_d_x);
    if (c25_b) {
      c25_y = rtNaN;
      exitg1 = true;
    } else {
      if (c25_s > c25_y) {
        c25_y = c25_s;
      }

      c25_j++;
    }
  }

  return c25_y;
}

static void c25_b_eml_warning(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c25_i192;
  static char_T c25_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c25_u[27];
  const mxArray *c25_y = NULL;
  (void)chartInstance;
  for (c25_i192 = 0; c25_i192 < 27; c25_i192++) {
    c25_u[c25_i192] = c25_varargin_1[c25_i192];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c25_y));
}

static void c25_c_eml_warning(SFc25_hybridSysSimInstanceStruct *chartInstance,
  char_T c25_varargin_2[14])
{
  int32_T c25_i193;
  static char_T c25_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c25_u[33];
  const mxArray *c25_y = NULL;
  int32_T c25_i194;
  char_T c25_b_u[14];
  const mxArray *c25_b_y = NULL;
  (void)chartInstance;
  for (c25_i193 = 0; c25_i193 < 33; c25_i193++) {
    c25_u[c25_i193] = c25_varargin_1[c25_i193];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  for (c25_i194 = 0; c25_i194 < 14; c25_i194++) {
    c25_b_u[c25_i194] = c25_varargin_2[c25_i194];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c25_y, 14, c25_b_y));
}

static void c25_b_eig(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
                      c25_A[100], creal_T c25_V[10])
{
  int32_T c25_i195;
  static creal_T c25_dc16 = { 0.0, 0.0 };

  creal_T c25_b_A[100];
  int32_T c25_info;
  int32_T c25_i196;
  creal_T c25_c_A[100];
  real_T c25_anrm;
  int32_T c25_i197;
  int32_T c25_i198;
  creal_T c25_beta1[10];
  boolean_T c25_ilascl;
  real_T c25_anrmto;
  real_T c25_cfrom;
  real_T c25_cto;
  real_T c25_cfromc;
  real_T c25_ctoc;
  boolean_T c25_notdone;
  real_T c25_cfrom1;
  real_T c25_cto1;
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_y;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_b_y;
  real_T c25_mul;
  real_T c25_e_x;
  real_T c25_f_x;
  real_T c25_c_y;
  real_T c25_g_x;
  real_T c25_h_x;
  real_T c25_d_y;
  real_T c25_a;
  int32_T c25_i199;
  int32_T c25_rscale[10];
  int32_T c25_ihi;
  int32_T c25_ilo;
  int32_T c25_b_ilo;
  int32_T c25_b_ihi;
  int32_T c25_i200;
  creal_T c25_d_A[100];
  int32_T c25_b_info;
  real_T c25_b_cfrom;
  real_T c25_b_cto;
  real_T c25_b_cfromc;
  real_T c25_b_ctoc;
  boolean_T c25_b_notdone;
  real_T c25_b_cfrom1;
  real_T c25_b_cto1;
  real_T c25_i_x;
  real_T c25_j_x;
  real_T c25_e_y;
  real_T c25_k_x;
  real_T c25_l_x;
  real_T c25_f_y;
  real_T c25_b_mul;
  real_T c25_m_x;
  real_T c25_n_x;
  real_T c25_g_y;
  real_T c25_o_x;
  real_T c25_p_x;
  real_T c25_h_y;
  real_T c25_b_a;
  int32_T c25_i201;
  int32_T c25_c_info;
  int32_T c25_d_info;
  int32_T c25_e_info;
  int32_T c25_i202;
  creal_T c25_b_V;
  real_T c25_ar;
  real_T c25_ai;
  real_T c25_br;
  real_T c25_bi;
  real_T c25_brm;
  real_T c25_bim;
  real_T c25_s;
  real_T c25_d;
  real_T c25_nr;
  real_T c25_ni;
  real_T c25_sgnbr;
  real_T c25_sgnbi;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c25_assert(chartInstance);
  c25_b_assert(chartInstance);
  c25_c_assert(chartInstance);
  c25_parseopts(chartInstance);
  c25_c_eml_scalar_eg(chartInstance);
  for (c25_i195 = 0; c25_i195 < 100; c25_i195++) {
    c25_b_A[c25_i195].re = c25_A[c25_i195] + c25_dc16.re;
    c25_b_A[c25_i195].im = c25_dc16.im;
  }

  c25_info = 0;
  c25_eml_realmin(chartInstance);
  c25_eps(chartInstance);
  for (c25_i196 = 0; c25_i196 < 100; c25_i196++) {
    c25_c_A[c25_i196] = c25_b_A[c25_i196];
  }

  c25_anrm = c25_b_eml_matlab_zlangeM(chartInstance, c25_c_A);
  if (!c25_isfinite(chartInstance, c25_anrm)) {
    for (c25_i197 = 0; c25_i197 < 10; c25_i197++) {
      c25_V[c25_i197].re = rtNaN;
      c25_V[c25_i197].im = 0.0;
    }

    for (c25_i198 = 0; c25_i198 < 10; c25_i198++) {
      c25_beta1[c25_i198].re = rtNaN;
      c25_beta1[c25_i198].im = 0.0;
    }
  } else {
    c25_ilascl = false;
    c25_anrmto = c25_anrm;
    guard3 = false;
    if (c25_anrm > 0.0) {
      if (c25_anrm < 6.7178761075670888E-139) {
        c25_anrmto = 6.7178761075670888E-139;
        c25_ilascl = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      if (c25_anrm > 1.4885657073574029E+138) {
        c25_anrmto = 1.4885657073574029E+138;
        c25_ilascl = true;
      }
    }

    if (c25_ilascl) {
      c25_cfrom = c25_anrm;
      c25_cto = c25_anrmto;
      c25_eml_realmin(chartInstance);
      c25_eps(chartInstance);
      c25_cfromc = c25_cfrom;
      c25_ctoc = c25_cto;
      c25_notdone = true;
      while (c25_notdone) {
        c25_cfrom1 = c25_cfromc * 2.0041683600089728E-292;
        c25_cto1 = c25_ctoc / 4.9896007738368E+291;
        c25_x = c25_cfrom1;
        c25_b_x = c25_x;
        c25_y = muDoubleScalarAbs(c25_b_x);
        c25_c_x = c25_ctoc;
        c25_d_x = c25_c_x;
        c25_b_y = muDoubleScalarAbs(c25_d_x);
        guard2 = false;
        if (c25_y > c25_b_y) {
          if (c25_ctoc != 0.0) {
            c25_mul = 2.0041683600089728E-292;
            c25_notdone = true;
            c25_cfromc = c25_cfrom1;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2 == true) {
          c25_e_x = c25_cto1;
          c25_f_x = c25_e_x;
          c25_c_y = muDoubleScalarAbs(c25_f_x);
          c25_g_x = c25_cfromc;
          c25_h_x = c25_g_x;
          c25_d_y = muDoubleScalarAbs(c25_h_x);
          if (c25_c_y > c25_d_y) {
            c25_mul = 4.9896007738368E+291;
            c25_notdone = true;
            c25_ctoc = c25_cto1;
          } else {
            c25_mul = c25_ctoc / c25_cfromc;
            c25_notdone = false;
          }
        }

        c25_a = c25_mul;
        for (c25_i199 = 0; c25_i199 < 100; c25_i199++) {
          c25_b_A[c25_i199].re *= c25_a;
          c25_b_A[c25_i199].im *= c25_a;
        }
      }
    }

    c25_d_eml_matlab_zggbal(chartInstance, c25_b_A, &c25_ilo, &c25_ihi,
      c25_rscale);
    c25_b_ilo = c25_ilo;
    c25_b_ihi = c25_ihi;
    c25_b_eml_matlab_zgghrd(chartInstance, c25_b_ilo, c25_b_ihi, c25_b_A);
    for (c25_i200 = 0; c25_i200 < 100; c25_i200++) {
      c25_d_A[c25_i200] = c25_b_A[c25_i200];
    }

    c25_b_eml_matlab_zhgeqz(chartInstance, c25_d_A, c25_b_ilo, c25_b_ihi,
      &c25_b_info, c25_V, c25_beta1);
    c25_info = c25_b_info;
    if (c25_info != 0) {
    } else {
      if (c25_ilascl) {
        c25_b_cfrom = c25_anrmto;
        c25_b_cto = c25_anrm;
        c25_eml_realmin(chartInstance);
        c25_eps(chartInstance);
        c25_b_cfromc = c25_b_cfrom;
        c25_b_ctoc = c25_b_cto;
        c25_b_notdone = true;
        while (c25_b_notdone) {
          c25_b_cfrom1 = c25_b_cfromc * 2.0041683600089728E-292;
          c25_b_cto1 = c25_b_ctoc / 4.9896007738368E+291;
          c25_i_x = c25_b_cfrom1;
          c25_j_x = c25_i_x;
          c25_e_y = muDoubleScalarAbs(c25_j_x);
          c25_k_x = c25_b_ctoc;
          c25_l_x = c25_k_x;
          c25_f_y = muDoubleScalarAbs(c25_l_x);
          guard1 = false;
          if (c25_e_y > c25_f_y) {
            if (c25_b_ctoc != 0.0) {
              c25_b_mul = 2.0041683600089728E-292;
              c25_b_notdone = true;
              c25_b_cfromc = c25_b_cfrom1;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1 == true) {
            c25_m_x = c25_b_cto1;
            c25_n_x = c25_m_x;
            c25_g_y = muDoubleScalarAbs(c25_n_x);
            c25_o_x = c25_b_cfromc;
            c25_p_x = c25_o_x;
            c25_h_y = muDoubleScalarAbs(c25_p_x);
            if (c25_g_y > c25_h_y) {
              c25_b_mul = 4.9896007738368E+291;
              c25_b_notdone = true;
              c25_b_ctoc = c25_b_cto1;
            } else {
              c25_b_mul = c25_b_ctoc / c25_b_cfromc;
              c25_b_notdone = false;
            }
          }

          c25_b_a = c25_b_mul;
          for (c25_i201 = 0; c25_i201 < 10; c25_i201++) {
            c25_V[c25_i201].re *= c25_b_a;
            c25_V[c25_i201].im *= c25_b_a;
          }
        }
      }
    }
  }

  c25_c_info = c25_info;
  c25_d_info = c25_c_info;
  c25_e_info = c25_d_info;
  for (c25_i202 = 0; c25_i202 < 10; c25_i202++) {
    c25_b_V = c25_V[c25_i202];
    c25_ar = c25_b_V.re;
    c25_ai = c25_b_V.im;
    c25_br = c25_beta1[c25_i202].re;
    c25_bi = c25_beta1[c25_i202].im;
    if (c25_bi == 0.0) {
      if (c25_ai == 0.0) {
        c25_V[c25_i202].re = c25_ar / c25_br;
        c25_V[c25_i202].im = 0.0;
      } else if (c25_ar == 0.0) {
        c25_V[c25_i202].re = 0.0;
        c25_V[c25_i202].im = c25_ai / c25_br;
      } else {
        c25_V[c25_i202].re = c25_ar / c25_br;
        c25_V[c25_i202].im = c25_ai / c25_br;
      }
    } else if (c25_br == 0.0) {
      if (c25_ar == 0.0) {
        c25_V[c25_i202].re = c25_ai / c25_bi;
        c25_V[c25_i202].im = 0.0;
      } else if (c25_ai == 0.0) {
        c25_V[c25_i202].re = 0.0;
        c25_V[c25_i202].im = -(c25_ar / c25_bi);
      } else {
        c25_V[c25_i202].re = c25_ai / c25_bi;
        c25_V[c25_i202].im = -(c25_ar / c25_bi);
      }
    } else {
      c25_brm = muDoubleScalarAbs(c25_br);
      c25_bim = muDoubleScalarAbs(c25_bi);
      if (c25_brm > c25_bim) {
        c25_s = c25_bi / c25_br;
        c25_d = c25_br + c25_s * c25_bi;
        c25_nr = c25_ar + c25_s * c25_ai;
        c25_ni = c25_ai - c25_s * c25_ar;
        c25_V[c25_i202].re = c25_nr / c25_d;
        c25_V[c25_i202].im = c25_ni / c25_d;
      } else if (c25_bim == c25_brm) {
        if (c25_br > 0.0) {
          c25_sgnbr = 0.5;
        } else {
          c25_sgnbr = -0.5;
        }

        if (c25_bi > 0.0) {
          c25_sgnbi = 0.5;
        } else {
          c25_sgnbi = -0.5;
        }

        c25_nr = c25_ar * c25_sgnbr + c25_ai * c25_sgnbi;
        c25_ni = c25_ai * c25_sgnbr - c25_ar * c25_sgnbi;
        c25_V[c25_i202].re = c25_nr / c25_brm;
        c25_V[c25_i202].im = c25_ni / c25_brm;
      } else {
        c25_s = c25_br / c25_bi;
        c25_d = c25_bi + c25_s * c25_br;
        c25_nr = c25_s * c25_ar + c25_ai;
        c25_ni = c25_s * c25_ai - c25_ar;
        c25_V[c25_i202].re = c25_nr / c25_d;
        c25_V[c25_i202].im = c25_ni / c25_d;
      }
    }
  }

  if (c25_e_info != 0) {
    c25_eml_warning(chartInstance);
  }
}

static void c25_c_eml_scalar_eg(SFc25_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c25_b_eml_matlab_zlangeM(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_x[100])
{
  real_T c25_y;
  int32_T c25_k;
  real_T c25_b_k;
  creal_T c25_b_x;
  real_T c25_x1;
  real_T c25_x2;
  real_T c25_a;
  real_T c25_b;
  real_T c25_absxk;
  real_T c25_c_x;
  boolean_T c25_b_b;
  boolean_T exitg1;
  (void)chartInstance;
  c25_y = 0.0;
  c25_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c25_k < 100)) {
    c25_b_k = 1.0 + (real_T)c25_k;
    c25_b_x.re = c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c25_b_k), 1, 100, 1, 0) - 1].re;
    c25_b_x.im = c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c25_b_k), 1, 100, 1, 0) - 1].im;
    c25_x1 = c25_b_x.re;
    c25_x2 = c25_b_x.im;
    c25_a = c25_x1;
    c25_b = c25_x2;
    c25_absxk = muDoubleScalarHypot(c25_a, c25_b);
    c25_c_x = c25_absxk;
    c25_b_b = muDoubleScalarIsNaN(c25_c_x);
    if (c25_b_b) {
      c25_y = rtNaN;
      exitg1 = true;
    } else {
      if (c25_absxk > c25_y) {
        c25_y = c25_absxk;
      }

      c25_k++;
    }
  }

  return c25_y;
}

static void c25_b_eml_matlab_zggbal(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[100], creal_T c25_b_A[100], int32_T *c25_ilo,
  int32_T *c25_ihi, int32_T c25_rscale[10])
{
  int32_T c25_i203;
  for (c25_i203 = 0; c25_i203 < 100; c25_i203++) {
    c25_b_A[c25_i203] = c25_A[c25_i203];
  }

  c25_d_eml_matlab_zggbal(chartInstance, c25_b_A, c25_ilo, c25_ihi, c25_rscale);
}

static void c25_eml_matlab_zgghrd(SFc25_hybridSysSimInstanceStruct
  *chartInstance, int32_T c25_ilo, int32_T c25_ihi, creal_T c25_A[100], creal_T
  c25_b_A[100])
{
  int32_T c25_i204;
  for (c25_i204 = 0; c25_i204 < 100; c25_i204++) {
    c25_b_A[c25_i204] = c25_A[c25_i204];
  }

  c25_b_eml_matlab_zgghrd(chartInstance, c25_ilo, c25_ihi, c25_b_A);
}

static void c25_b_eml_matlab_zhgeqz(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[100], int32_T c25_ilo, int32_T c25_ihi, int32_T *
  c25_info, creal_T c25_alpha1[10], creal_T c25_beta1[10])
{
  static creal_T c25_dc17 = { 0.0, 0.0 };

  int32_T c25_i205;
  creal_T c25_b_A[100];
  int32_T c25_i206;
  int32_T c25_i207;
  static creal_T c25_dc18 = { 0.0, 0.0 };

  creal_T c25_eshift;
  creal_T c25_ctemp;
  creal_T c25_rho;
  int32_T c25_i208;
  creal_T c25_c_A[100];
  real_T c25_anorm;
  real_T c25_y;
  real_T c25_atol;
  real_T c25_b_y;
  real_T c25_x;
  real_T c25_ascale;
  boolean_T c25_failed;
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_i209;
  int32_T c25_c_a;
  int32_T c25_d_a;
  boolean_T c25_overflow;
  int32_T c25_j;
  int32_T c25_b_j;
  int32_T c25_ifirst;
  int32_T c25_istart;
  int32_T c25_ilast;
  int32_T c25_e_a;
  int32_T c25_f_a;
  int32_T c25_ilastm1;
  int32_T c25_ifrstm;
  int32_T c25_ilastm;
  int32_T c25_iiter;
  int32_T c25_g_a;
  int32_T c25_b;
  int32_T c25_h_a;
  int32_T c25_b_b;
  int32_T c25_c;
  int32_T c25_i_a;
  int32_T c25_j_a;
  int32_T c25_b_c;
  int32_T c25_c_b;
  int32_T c25_d_b;
  int32_T c25_maxit;
  boolean_T c25_goto50;
  boolean_T c25_goto60;
  boolean_T c25_goto70;
  boolean_T c25_goto90;
  int32_T c25_b_maxit;
  int32_T c25_e_b;
  int32_T c25_f_b;
  boolean_T c25_b_overflow;
  int32_T c25_jiter;
  creal_T c25_a22;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_c_y;
  real_T c25_d_x;
  real_T c25_e_x;
  real_T c25_d_y;
  real_T c25_e_y;
  int32_T c25_k_a;
  int32_T c25_l_a;
  int32_T c25_jm1;
  boolean_T c25_ilazro;
  real_T c25_f_x;
  real_T c25_g_x;
  real_T c25_f_y;
  real_T c25_h_x;
  real_T c25_i_x;
  real_T c25_g_y;
  real_T c25_h_y;
  boolean_T c25_b27;
  int32_T c25_i210;
  int32_T c25_i211;
  creal_T c25_d_A;
  creal_T c25_e_A;
  creal_T c25_s;
  real_T c25_c_c;
  real_T c25_d_c;
  real_T c25_e_c;
  int32_T c25_xcol;
  int32_T c25_ycol;
  int32_T c25_b_ilo;
  int32_T c25_b_ihi;
  int32_T c25_c_ilo;
  int32_T c25_c_ihi;
  int32_T c25_m_a;
  int32_T c25_g_b;
  int32_T c25_n_a;
  int32_T c25_h_b;
  boolean_T c25_c_overflow;
  int32_T c25_i;
  int32_T c25_b_i;
  real_T c25_o_a;
  creal_T c25_a12;
  creal_T c25_b_s;
  creal_T c25_a21;
  real_T c25_p_a;
  creal_T c25_b_a22;
  creal_T c25_c_a22;
  creal_T c25_d_a22;
  creal_T c25_e_a22;
  int32_T c25_q_a;
  int32_T c25_r_a;
  int32_T c25_s_a;
  int32_T c25_t_a;
  creal_T c25_r2;
  real_T c25_ar;
  real_T c25_ai;
  static creal_T c25_dc19 = { 2.0, 0.0 };

  real_T c25_br;
  real_T c25_bi;
  real_T c25_brm;
  real_T c25_bim;
  real_T c25_c_s;
  real_T c25_d;
  real_T c25_nr;
  real_T c25_ni;
  real_T c25_sgnbr;
  real_T c25_sgnbi;
  creal_T c25_d_s;
  creal_T c25_b_a12;
  creal_T c25_c_a12;
  creal_T c25_b_a21;
  real_T c25_d12;
  real_T c25_d13;
  int32_T c25_u_a;
  int32_T c25_v_a;
  int32_T c25_jp1;
  int32_T c25_w_a;
  int32_T c25_x_a;
  real_T c25_j_x;
  real_T c25_k_x;
  real_T c25_i_y;
  real_T c25_l_x;
  real_T c25_m_x;
  real_T c25_j_y;
  real_T c25_k_y;
  real_T c25_temp;
  real_T c25_n_x;
  real_T c25_o_x;
  real_T c25_l_y;
  real_T c25_p_x;
  real_T c25_q_x;
  real_T c25_m_y;
  real_T c25_n_y;
  real_T c25_temp2;
  real_T c25_r_x;
  real_T c25_o_y;
  real_T c25_tempr;
  real_T c25_s_x;
  real_T c25_t_x;
  real_T c25_p_y;
  real_T c25_u_x;
  real_T c25_v_x;
  real_T c25_q_y;
  real_T c25_r_y;
  int32_T c25_y_a;
  int32_T c25_ab_a;
  int32_T c25_f_c;
  real_T c25_g_c;
  int32_T c25_bb_a;
  int32_T c25_cb_a;
  int32_T c25_db_a;
  int32_T c25_eb_a;
  creal_T c25_f_A;
  creal_T c25_g_A;
  real_T c25_h_c;
  real_T c25_i_c;
  int32_T c25_xrow;
  int32_T c25_yrow;
  int32_T c25_jlo;
  int32_T c25_jhi;
  int32_T c25_b_jlo;
  int32_T c25_b_jhi;
  int32_T c25_fb_a;
  int32_T c25_i_b;
  int32_T c25_gb_a;
  int32_T c25_j_b;
  boolean_T c25_d_overflow;
  int32_T c25_c_j;
  int32_T c25_d_j;
  real_T c25_hb_a;
  creal_T c25_e_s;
  real_T c25_ib_a;
  creal_T c25_f_a22;
  creal_T c25_g_a22;
  creal_T c25_h_a22;
  creal_T c25_i_a22;
  int32_T c25_jb_a;
  int32_T c25_kb_a;
  int32_T c25_j_c;
  int32_T c25_w_x;
  int32_T c25_s_y;
  int32_T c25_x_x;
  real_T c25_k_c;
  int32_T c25_b_xcol;
  int32_T c25_b_ycol;
  int32_T c25_d_ilo;
  int32_T c25_d_ihi;
  int32_T c25_e_ilo;
  int32_T c25_e_ihi;
  int32_T c25_lb_a;
  int32_T c25_k_b;
  int32_T c25_mb_a;
  int32_T c25_l_b;
  boolean_T c25_e_overflow;
  int32_T c25_c_i;
  int32_T c25_d_i;
  real_T c25_nb_a;
  creal_T c25_f_s;
  real_T c25_ob_a;
  creal_T c25_j_a22;
  creal_T c25_k_a22;
  creal_T c25_l_a22;
  creal_T c25_m_a22;
  int32_T c25_b_ilast;
  int32_T c25_m_b;
  int32_T c25_n_b;
  boolean_T c25_f_overflow;
  int32_T c25_k;
  int32_T c25_b_k;
  int32_T c25_pb_a;
  int32_T c25_qb_a;
  int32_T c25_i212;
  int32_T c25_o_b;
  int32_T c25_p_b;
  boolean_T c25_g_overflow;
  int32_T c25_e_j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T guard11 = false;
  c25_dc17.re = rtNaN;
  for (c25_i205 = 0; c25_i205 < 100; c25_i205++) {
    c25_b_A[c25_i205] = c25_A[c25_i205];
  }

  *c25_info = 0;
  for (c25_i206 = 0; c25_i206 < 10; c25_i206++) {
    c25_alpha1[c25_i206].re = 0.0;
    c25_alpha1[c25_i206].im = 0.0;
  }

  for (c25_i207 = 0; c25_i207 < 10; c25_i207++) {
    c25_beta1[c25_i207].re = 1.0;
    c25_beta1[c25_i207].im = 0.0;
  }

  c25_eps(chartInstance);
  c25_realmin(chartInstance);
  c25_eshift = c25_dc18;
  c25_ctemp = c25_dc18;
  c25_rho = c25_dc18;
  for (c25_i208 = 0; c25_i208 < 100; c25_i208++) {
    c25_c_A[c25_i208] = c25_b_A[c25_i208];
  }

  c25_anorm = c25_b_eml_matlab_zlanhs(chartInstance, c25_c_A, c25_ilo, c25_ihi);
  c25_y = 2.2204460492503131E-16 * c25_anorm;
  c25_atol = 2.2250738585072014E-308;
  if (c25_y > 2.2250738585072014E-308) {
    c25_atol = c25_y;
  }

  c25_b_y = c25_anorm;
  c25_x = 2.2250738585072014E-308;
  if (c25_b_y > 2.2250738585072014E-308) {
    c25_x = c25_b_y;
  }

  c25_ascale = 1.0 / c25_x;
  c25_failed = true;
  c25_a = c25_ihi;
  c25_b_a = c25_a + 1;
  c25_i209 = c25_b_a;
  c25_c_a = c25_i209;
  c25_d_a = c25_c_a;
  if (c25_d_a > 10) {
    c25_overflow = false;
  } else {
    c25_eml_switch_helper(chartInstance);
    c25_eml_switch_helper(chartInstance);
    c25_overflow = false;
  }

  if (c25_overflow) {
    c25_check_forloop_overflow_error(chartInstance, c25_overflow);
  }

  for (c25_j = c25_i209; c25_j < 11; c25_j++) {
    c25_b_j = c25_j;
    c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c25_b_j), 1, 10, 1, 0) - 1].re = c25_b_A
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c25_b_j), 1, 10, 1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) -
      1].re;
    c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c25_b_j), 1, 10, 1, 0) - 1].im = c25_b_A
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c25_b_j), 1, 10, 1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) -
      1].im;
  }

  guard1 = false;
  guard2 = false;
  if (c25_ihi >= c25_ilo) {
    c25_ifirst = c25_ilo;
    c25_istart = c25_ilo;
    c25_ilast = c25_ihi;
    c25_e_a = c25_ilast;
    c25_f_a = c25_e_a - 1;
    c25_ilastm1 = c25_f_a;
    c25_ifrstm = c25_ilo;
    c25_ilastm = c25_ihi;
    c25_iiter = 0;
    c25_g_a = c25_ihi;
    c25_b = c25_ilo;
    c25_h_a = c25_g_a;
    c25_b_b = c25_b;
    c25_c = c25_h_a - c25_b_b;
    c25_i_a = c25_c;
    c25_j_a = c25_i_a + 1;
    c25_b_c = c25_j_a;
    c25_c_b = c25_b_c;
    c25_d_b = c25_c_b;
    c25_maxit = 30 * c25_d_b;
    c25_goto50 = false;
    c25_goto60 = false;
    c25_goto70 = false;
    c25_goto90 = false;
    c25_b_maxit = c25_maxit;
    c25_e_b = c25_b_maxit;
    c25_f_b = c25_e_b;
    if (1 > c25_f_b) {
      c25_b_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_b_overflow = (c25_f_b > 2147483646);
    }

    if (c25_b_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
    }

    c25_jiter = 1;
    do {
      exitg1 = 0;
      if (c25_jiter <= c25_b_maxit) {
        if (c25_ilast == c25_ilo) {
          c25_goto60 = true;
        } else {
          c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0) - 1)) - 1]
            .re;
          c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0) - 1)) - 1]
            .im;
          c25_b_x = c25_a22.re;
          c25_c_x = c25_b_x;
          c25_c_y = muDoubleScalarAbs(c25_c_x);
          c25_d_x = c25_a22.im;
          c25_e_x = c25_d_x;
          c25_d_y = muDoubleScalarAbs(c25_e_x);
          c25_e_y = c25_c_y + c25_d_y;
          if (c25_e_y <= c25_atol) {
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0)
                      - 1)) - 1].re = c25_dc18.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0)
                      - 1)) - 1].im = c25_dc18.im;
            c25_goto60 = true;
          } else {
            c25_b_j = c25_ilastm1;
            exitg3 = false;
            while ((exitg3 == false) && (c25_b_j >= c25_ilo)) {
              c25_k_a = c25_b_j;
              c25_l_a = c25_k_a - 1;
              c25_jm1 = c25_l_a;
              if (c25_b_j == c25_ilo) {
                c25_ilazro = true;
              } else {
                c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2, 0) - 1)) -
                  1].re;
                c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2, 0) - 1)) -
                  1].im;
                c25_f_x = c25_a22.re;
                c25_g_x = c25_f_x;
                c25_f_y = muDoubleScalarAbs(c25_g_x);
                c25_h_x = c25_a22.im;
                c25_i_x = c25_h_x;
                c25_g_y = muDoubleScalarAbs(c25_i_x);
                c25_h_y = c25_f_y + c25_g_y;
                if (c25_h_y <= c25_atol) {
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                             0) - 1)) - 1].re = c25_dc18.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                             0) - 1)) - 1].im = c25_dc18.im;
                  c25_ilazro = true;
                } else {
                  c25_ilazro = false;
                }
              }

              if (c25_ilazro) {
                c25_ifirst = c25_b_j;
                c25_goto70 = true;
                exitg3 = true;
              } else {
                c25_b_j = c25_jm1;
              }
            }
          }
        }

        guard3 = false;
        guard4 = false;
        if (c25_goto50) {
          guard4 = true;
        } else if (c25_goto60) {
          guard4 = true;
        } else if (c25_goto70) {
          guard3 = true;
        } else {
          c25_b27 = false;
        }

        if (guard4 == true) {
          guard3 = true;
        }

        if (guard3 == true) {
          c25_b27 = true;
        }

        if (!c25_b27) {
          for (c25_i210 = 0; c25_i210 < 10; c25_i210++) {
            c25_alpha1[c25_i210] = c25_dc17;
          }

          for (c25_i211 = 0; c25_i211 < 10; c25_i211++) {
            c25_beta1[c25_i211] = c25_dc17;
          }

          *c25_info = 1;
          exitg1 = 1;
        } else {
          if (c25_goto50) {
            c25_goto50 = false;
            c25_d_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2, 0) - 1)) - 1]
              .re;
            c25_d_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2, 0) - 1)) - 1]
              .im;
            c25_e_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0) - 1)) -
              1].re;
            c25_e_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0) - 1)) -
              1].im;
            c25_eml_matlab_zlartg(chartInstance, c25_d_A, c25_e_A, &c25_c_c,
                                  &c25_s, &c25_a22);
            c25_d_c = c25_c_c;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2, 0) -
                      1)) - 1].re = c25_a22.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2, 0) -
                      1)) - 1].im = c25_a22.im;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0)
                      - 1)) - 1].re = c25_dc18.re;
            c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0)
                      - 1)) - 1].im = c25_dc18.im;
            c25_e_c = c25_d_c;
            c25_xcol = c25_ilast;
            c25_ycol = c25_ilastm1;
            c25_b_ilo = c25_ifrstm;
            c25_b_ihi = c25_ilastm1;
            c25_c_ilo = c25_b_ilo;
            c25_c_ihi = c25_b_ihi;
            c25_m_a = c25_c_ilo;
            c25_g_b = c25_c_ihi;
            c25_n_a = c25_m_a;
            c25_h_b = c25_g_b;
            if (c25_n_a > c25_h_b) {
              c25_c_overflow = false;
            } else {
              c25_eml_switch_helper(chartInstance);
              c25_eml_switch_helper(chartInstance);
              c25_c_overflow = (c25_h_b > 2147483646);
            }

            if (c25_c_overflow) {
              c25_check_forloop_overflow_error(chartInstance, c25_c_overflow);
            }

            for (c25_i = c25_c_ilo; c25_i <= c25_c_ihi; c25_i++) {
              c25_b_i = c25_i;
              c25_o_a = c25_e_c;
              c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1]
                .re;
              c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1]
                .im;
              c25_a12.re = c25_o_a * c25_a22.re;
              c25_a12.im = c25_o_a * c25_a22.im;
              c25_b_s.re = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) +
                10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1]
                .re - c25_s.im * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) +
                10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1]
                .im;
              c25_b_s.im = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) +
                10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1]
                .im + c25_s.im * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) +
                10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1]
                .re;
              c25_a21.re = c25_a12.re + c25_b_s.re;
              c25_a21.im = c25_a12.im + c25_b_s.im;
              c25_p_a = c25_e_c;
              c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1]
                .re;
              c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1]
                .im;
              c25_a12.re = c25_p_a * c25_a22.re;
              c25_a12.im = c25_p_a * c25_a22.im;
              c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1]
                .re;
              c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1]
                .im;
              c25_b_a22 = c25_a22;
              c25_c_a22 = c25_a22;
              c25_d_a22 = c25_a22;
              c25_e_a22 = c25_a22;
              c25_a22.re = c25_s.re * c25_b_a22.re + c25_s.im * c25_c_a22.im;
              c25_a22.im = c25_s.re * c25_d_a22.im - c25_s.im * c25_e_a22.re;
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) +
                       10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0)
                             - 1)) - 1].re = c25_a12.re - c25_a22.re;
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) +
                       10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0)
                             - 1)) - 1].im = c25_a12.im - c25_a22.im;
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) +
                       10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0)
                             - 1)) - 1].re = c25_a21.re;
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) +
                       10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0)
                             - 1)) - 1].im = c25_a21.im;
            }

            c25_goto60 = true;
          }

          guard11 = false;
          if (c25_goto60) {
            c25_goto60 = false;
            c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) - 1].re =
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0)
                       + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2, 0) - 1)) - 1]
              .re;
            c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) - 1].im =
              c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0)
                       + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2, 0) - 1)) - 1]
              .im;
            c25_ilast = c25_ilastm1;
            c25_q_a = c25_ilast;
            c25_r_a = c25_q_a - 1;
            c25_ilastm1 = c25_r_a;
            if (c25_ilast < c25_ilo) {
              c25_failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              c25_iiter = 0;
              c25_eshift = c25_dc18;
              c25_ilastm = c25_ilast;
              if (c25_ifrstm > c25_ilast) {
                c25_ifrstm = c25_ilo;
              }

              guard11 = true;
            }
          } else {
            if (c25_goto70) {
              c25_goto70 = false;
              c25_s_a = c25_iiter;
              c25_t_a = c25_s_a + 1;
              c25_iiter = c25_t_a;
              c25_ifrstm = c25_ifirst;
              if (c25_mod(chartInstance, c25_iiter) != 0) {
                c25_rho.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 1, 0) + 10
                                      * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2,
                  0) - 1)) - 1].re;
                c25_rho.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 1, 0) + 10
                                      * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2,
                  0) - 1)) - 1].im;
                c25_r2.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2, 0) - 1))
                  - 1].re;
                c25_r2.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2, 0) - 1))
                  - 1].im;
                c25_a12.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 1, 0) + 10
                                      * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2,
                  0) - 1)) - 1].re;
                c25_a12.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 1, 0) + 10
                                      * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 2,
                  0) - 1)) - 1].im;
                c25_a21.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0) - 1))
                  - 1].re;
                c25_a21.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0) - 1))
                  - 1].im;
                c25_a22.re = c25_r2.re - c25_rho.re;
                c25_a22.im = c25_r2.im - c25_rho.im;
                c25_a22.re = -c25_a22.re;
                c25_a22.im = -c25_a22.im;
                c25_ar = c25_a22.re;
                c25_ai = c25_a22.im;
                c25_br = c25_dc19.re;
                c25_bi = c25_dc19.im;
                if (c25_bi == 0.0) {
                  if (c25_ai == 0.0) {
                    c25_s.re = c25_ar / c25_br;
                    c25_s.im = 0.0;
                  } else if (c25_ar == 0.0) {
                    c25_s.re = 0.0;
                    c25_s.im = c25_ai / c25_br;
                  } else {
                    c25_s.re = c25_ar / c25_br;
                    c25_s.im = c25_ai / c25_br;
                  }
                } else if (c25_br == 0.0) {
                  if (c25_ar == 0.0) {
                    c25_s.re = c25_ai / c25_bi;
                    c25_s.im = 0.0;
                  } else if (c25_ai == 0.0) {
                    c25_s.re = 0.0;
                    c25_s.im = -(c25_ar / c25_bi);
                  } else {
                    c25_s.re = c25_ai / c25_bi;
                    c25_s.im = -(c25_ar / c25_bi);
                  }
                } else {
                  c25_brm = muDoubleScalarAbs(c25_br);
                  c25_bim = muDoubleScalarAbs(c25_bi);
                  if (c25_brm > c25_bim) {
                    c25_c_s = c25_bi / c25_br;
                    c25_d = c25_br + c25_c_s * c25_bi;
                    c25_nr = c25_ar + c25_c_s * c25_ai;
                    c25_ni = c25_ai - c25_c_s * c25_ar;
                    c25_s.re = c25_nr / c25_d;
                    c25_s.im = c25_ni / c25_d;
                  } else if (c25_bim == c25_brm) {
                    if (c25_br > 0.0) {
                      c25_sgnbr = 0.5;
                    } else {
                      c25_sgnbr = -0.5;
                    }

                    if (c25_bi > 0.0) {
                      c25_sgnbi = 0.5;
                    } else {
                      c25_sgnbi = -0.5;
                    }

                    c25_nr = c25_ar * c25_sgnbr + c25_ai * c25_sgnbi;
                    c25_ni = c25_ai * c25_sgnbr - c25_ar * c25_sgnbi;
                    c25_s.re = c25_nr / c25_brm;
                    c25_s.im = c25_ni / c25_brm;
                  } else {
                    c25_c_s = c25_br / c25_bi;
                    c25_d = c25_bi + c25_c_s * c25_br;
                    c25_nr = c25_c_s * c25_ar + c25_ai;
                    c25_ni = c25_c_s * c25_ai - c25_ar;
                    c25_s.re = c25_nr / c25_d;
                    c25_s.im = c25_ni / c25_d;
                  }
                }

                c25_d_s.re = c25_s.re * c25_s.re - c25_s.im * c25_s.im;
                c25_d_s.im = c25_s.re * c25_s.im + c25_s.im * c25_s.re;
                c25_b_a12.re = c25_a12.re * c25_a21.re - c25_a12.im * c25_a21.im;
                c25_b_a12.im = c25_a12.re * c25_a21.im + c25_a12.im * c25_a21.re;
                c25_a22.re = c25_d_s.re + c25_b_a12.re;
                c25_a22.im = c25_d_s.im + c25_b_a12.im;
                c25_d_sqrt(chartInstance, &c25_a22);
                c25_a12.re = c25_rho.re - (c25_s.re - c25_a22.re);
                c25_a12.im = c25_rho.im - (c25_s.im - c25_a22.im);
                c25_a21.re = c25_rho.re - (c25_s.re + c25_a22.re);
                c25_a21.im = c25_rho.im - (c25_s.im + c25_a22.im);
                c25_c_a12.re = c25_a12.re - c25_r2.re;
                c25_c_a12.im = c25_a12.im - c25_r2.im;
                c25_b_a21.re = c25_a21.re - c25_r2.re;
                c25_b_a21.im = c25_a21.im - c25_r2.im;
                c25_d12 = c25_b_abs(chartInstance, c25_c_a12);
                c25_d13 = c25_b_abs(chartInstance, c25_b_a21);
                if (c25_d12 <= c25_d13) {
                  c25_a21 = c25_a12;
                  c25_rho.re = c25_s.re - c25_a22.re;
                  c25_rho.im = c25_s.im - c25_a22.im;
                } else {
                  c25_rho.re = c25_s.re + c25_a22.re;
                  c25_rho.im = c25_s.im + c25_a22.im;
                }
              } else {
                c25_eshift.re += c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1,
                  0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0) - 1))
                  - 1].re;
                c25_eshift.im += c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ilast), 1, 10, 1,
                  0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_ilastm1), 1, 10, 2, 0) - 1))
                  - 1].im;
                c25_a21 = c25_eshift;
              }

              c25_b_j = c25_ilastm1;
              c25_u_a = c25_b_j;
              c25_v_a = c25_u_a + 1;
              c25_jp1 = c25_v_a;
              exitg2 = false;
              while ((exitg2 == false) && (c25_b_j > c25_ifirst)) {
                c25_w_a = c25_b_j;
                c25_x_a = c25_w_a - 1;
                c25_jm1 = c25_x_a;
                c25_istart = c25_b_j;
                c25_ctemp.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0) + 10 *
                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                  "", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re - c25_a21.re;
                c25_ctemp.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0) + 10 *
                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                  "", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im - c25_a21.im;
                c25_j_x = c25_ctemp.re;
                c25_k_x = c25_j_x;
                c25_i_y = muDoubleScalarAbs(c25_k_x);
                c25_l_x = c25_ctemp.im;
                c25_m_x = c25_l_x;
                c25_j_y = muDoubleScalarAbs(c25_m_x);
                c25_k_y = c25_i_y + c25_j_y;
                c25_temp = c25_ascale * c25_k_y;
                c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) -
                  1].re;
                c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) -
                  1].im;
                c25_n_x = c25_a22.re;
                c25_o_x = c25_n_x;
                c25_l_y = muDoubleScalarAbs(c25_o_x);
                c25_p_x = c25_a22.im;
                c25_q_x = c25_p_x;
                c25_m_y = muDoubleScalarAbs(c25_q_x);
                c25_n_y = c25_l_y + c25_m_y;
                c25_temp2 = c25_ascale * c25_n_y;
                c25_r_x = c25_temp;
                c25_o_y = c25_temp2;
                c25_tempr = c25_r_x;
                if (c25_o_y > c25_tempr) {
                  c25_tempr = c25_o_y;
                }

                if (c25_tempr < 1.0) {
                  if (c25_tempr != 0.0) {
                    c25_temp /= c25_tempr;
                    c25_temp2 /= c25_tempr;
                  }
                }

                c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2, 0) - 1)) -
                  1].re;
                c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2, 0) - 1)) -
                  1].im;
                c25_s_x = c25_a22.re;
                c25_t_x = c25_s_x;
                c25_p_y = muDoubleScalarAbs(c25_t_x);
                c25_u_x = c25_a22.im;
                c25_v_x = c25_u_x;
                c25_q_y = muDoubleScalarAbs(c25_v_x);
                c25_r_y = c25_p_y + c25_q_y;
                if (c25_r_y * c25_temp2 <= c25_temp * c25_atol) {
                  c25_goto90 = true;
                  exitg2 = true;
                } else {
                  c25_jp1 = c25_b_j;
                  c25_b_j = c25_jm1;
                }
              }

              if (!c25_goto90) {
                c25_istart = c25_ifirst;
                if (c25_istart == c25_ilastm1) {
                  c25_ctemp = c25_rho;
                } else {
                  c25_ctemp.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 10, 2, 0) - 1))
                    - 1].re - c25_a21.re;
                  c25_ctemp.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 10, 2, 0) - 1))
                    - 1].im - c25_a21.im;
                }

                c25_goto90 = true;
              }
            }

            if (c25_goto90) {
              c25_goto90 = false;
              c25_y_a = c25_istart;
              c25_ab_a = c25_y_a + 1;
              c25_f_c = c25_ab_a;
              c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_f_c), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 10, 2, 0) - 1)) -
                1].re;
              c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_f_c), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c25_istart), 1, 10, 2, 0) - 1)) -
                1].im;
              c25_b_eml_matlab_zlartg(chartInstance, c25_ctemp, c25_a22,
                &c25_g_c, &c25_s);
              c25_d_c = c25_g_c;
              c25_b_j = c25_istart;
              c25_bb_a = c25_b_j;
              c25_cb_a = c25_bb_a - 1;
              c25_jm1 = c25_cb_a;
              while (c25_b_j < c25_ilast) {
                c25_db_a = c25_b_j;
                c25_eb_a = c25_db_a + 1;
                c25_jp1 = c25_eb_a;
                if (c25_b_j > c25_istart) {
                  c25_f_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c25_f_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c25_g_A.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c25_g_A.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c25_eml_matlab_zlartg(chartInstance, c25_f_A, c25_g_A,
                                        &c25_h_c, &c25_s, &c25_a22);
                  c25_d_c = c25_h_c;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                             0) - 1)) - 1].re = c25_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                             0) - 1)) - 1].im = c25_a22.im;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                             0) - 1)) - 1].re = c25_dc18.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_jp1), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_jm1), 1, 10, 2,
                             0) - 1)) - 1].im = c25_dc18.im;
                }

                c25_i_c = c25_d_c;
                c25_xrow = c25_b_j;
                c25_yrow = c25_jp1;
                c25_jlo = c25_b_j;
                c25_jhi = c25_ilastm;
                c25_b_jlo = c25_jlo;
                c25_b_jhi = c25_jhi;
                c25_fb_a = c25_b_jlo;
                c25_i_b = c25_b_jhi;
                c25_gb_a = c25_fb_a;
                c25_j_b = c25_i_b;
                if (c25_gb_a > c25_j_b) {
                  c25_d_overflow = false;
                } else {
                  c25_eml_switch_helper(chartInstance);
                  c25_eml_switch_helper(chartInstance);
                  c25_d_overflow = (c25_j_b > 2147483646);
                }

                if (c25_d_overflow) {
                  c25_check_forloop_overflow_error(chartInstance, c25_d_overflow);
                }

                for (c25_c_j = c25_b_jlo; c25_c_j <= c25_b_jhi; c25_c_j++) {
                  c25_d_j = c25_c_j;
                  c25_hb_a = c25_i_c;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c25_a12.re = c25_hb_a * c25_a22.re;
                  c25_a12.im = c25_hb_a * c25_a22.im;
                  c25_e_s.re = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2, 0) - 1))
                    - 1].re - c25_s.im * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1,
                    0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2, 0) - 1))
                    - 1].im;
                  c25_e_s.im = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2, 0) - 1))
                    - 1].im + c25_s.im * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1,
                    0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2, 0) - 1))
                    - 1].re;
                  c25_a21.re = c25_a12.re + c25_e_s.re;
                  c25_a21.im = c25_a12.im + c25_e_s.im;
                  c25_ib_a = c25_i_c;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c25_a12.re = c25_ib_a * c25_a22.re;
                  c25_a12.im = c25_ib_a * c25_a22.im;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c25_f_a22 = c25_a22;
                  c25_g_a22 = c25_a22;
                  c25_h_a22 = c25_a22;
                  c25_i_a22 = c25_a22;
                  c25_a22.re = c25_s.re * c25_f_a22.re + c25_s.im * c25_g_a22.im;
                  c25_a22.im = c25_s.re * c25_h_a22.im - c25_s.im * c25_i_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1,
                            0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                             0) - 1)) - 1].re = c25_a12.re - c25_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1,
                            0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                             0) - 1)) - 1].im = c25_a12.im - c25_a22.im;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1,
                            0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                             0) - 1)) - 1].re = c25_a21.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1,
                            0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2,
                             0) - 1)) - 1].im = c25_a21.im;
                }

                c25_s.re = -c25_s.re;
                c25_s.im = -c25_s.im;
                c25_jb_a = c25_jp1;
                c25_kb_a = c25_jb_a + 1;
                c25_j_c = c25_kb_a;
                c25_w_x = c25_j_c;
                c25_s_y = c25_ilast;
                c25_x_x = c25_w_x;
                if (c25_s_y < c25_x_x) {
                  c25_x_x = c25_s_y;
                }

                c25_k_c = c25_d_c;
                c25_b_xcol = c25_jp1;
                c25_b_ycol = c25_b_j;
                c25_d_ilo = c25_ifrstm;
                c25_d_ihi = c25_x_x;
                c25_e_ilo = c25_d_ilo;
                c25_e_ihi = c25_d_ihi;
                c25_lb_a = c25_e_ilo;
                c25_k_b = c25_e_ihi;
                c25_mb_a = c25_lb_a;
                c25_l_b = c25_k_b;
                if (c25_mb_a > c25_l_b) {
                  c25_e_overflow = false;
                } else {
                  c25_eml_switch_helper(chartInstance);
                  c25_eml_switch_helper(chartInstance);
                  c25_e_overflow = (c25_l_b > 2147483646);
                }

                if (c25_e_overflow) {
                  c25_check_forloop_overflow_error(chartInstance, c25_e_overflow);
                }

                for (c25_c_i = c25_e_ilo; c25_c_i <= c25_e_ihi; c25_c_i++) {
                  c25_d_i = c25_c_i;
                  c25_nb_a = c25_k_c;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 10,
                    2, 0) - 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 10,
                    2, 0) - 1)) - 1].im;
                  c25_a12.re = c25_nb_a * c25_a22.re;
                  c25_a12.im = c25_nb_a * c25_a22.im;
                  c25_f_s.re = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 10, 2, 0) - 1))
                    - 1].re - c25_s.im * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1,
                    0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 10, 2, 0) - 1))
                    - 1].im;
                  c25_f_s.im = c25_s.re * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 10, 2, 0) - 1))
                    - 1].im + c25_s.im * c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1,
                    0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 10, 2, 0) - 1))
                    - 1].re;
                  c25_a21.re = c25_a12.re + c25_f_s.re;
                  c25_a21.im = c25_a12.im + c25_f_s.im;
                  c25_ob_a = c25_k_c;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 10,
                    2, 0) - 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 10,
                    2, 0) - 1)) - 1].im;
                  c25_a12.re = c25_ob_a * c25_a22.re;
                  c25_a12.im = c25_ob_a * c25_a22.im;
                  c25_a22.re = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 10,
                    2, 0) - 1)) - 1].re;
                  c25_a22.im = c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 10,
                    2, 0) - 1)) - 1].im;
                  c25_j_a22 = c25_a22;
                  c25_k_a22 = c25_a22;
                  c25_l_a22 = c25_a22;
                  c25_m_a22 = c25_a22;
                  c25_a22.re = c25_s.re * c25_j_a22.re + c25_s.im * c25_k_a22.im;
                  c25_a22.im = c25_s.re * c25_l_a22.im - c25_s.im * c25_m_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 10,
                             2, 0) - 1)) - 1].re = c25_a12.re - c25_a22.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_b_ycol), 1, 10,
                             2, 0) - 1)) - 1].im = c25_a12.im - c25_a22.im;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 10,
                             2, 0) - 1)) - 1].re = c25_a21.re;
                  c25_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c25_b_xcol), 1, 10,
                             2, 0) - 1)) - 1].im = c25_a21.im;
                }

                c25_jm1 = c25_b_j;
                c25_b_j = c25_jp1;
              }
            }

            guard11 = true;
          }

          if (guard11 == true) {
            c25_jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2 == true) {
    if (c25_failed) {
      *c25_info = c25_ilast;
      c25_b_ilast = c25_ilast;
      c25_m_b = c25_b_ilast;
      c25_n_b = c25_m_b;
      if (1 > c25_n_b) {
        c25_f_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_f_overflow = (c25_n_b > 2147483646);
      }

      if (c25_f_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_f_overflow);
      }

      for (c25_k = 1; c25_k <= c25_b_ilast; c25_k++) {
        c25_b_k = c25_k;
        c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c25_b_k), 1, 10, 1, 0) - 1].re = c25_dc17.re;
        c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c25_b_k), 1, 10, 1, 0) - 1].im = c25_dc17.im;
        c25_beta1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_k), 1, 10, 1, 0) - 1].re = c25_dc17.re;
        c25_beta1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_k), 1, 10, 1, 0) - 1].im = c25_dc17.im;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    c25_pb_a = c25_ilo;
    c25_qb_a = c25_pb_a - 1;
    c25_i212 = c25_qb_a;
    c25_o_b = c25_i212;
    c25_p_b = c25_o_b;
    if (1 > c25_p_b) {
      c25_g_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_g_overflow = (c25_p_b > 2147483646);
    }

    if (c25_g_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_g_overflow);
    }

    for (c25_e_j = 1; c25_e_j <= c25_i212; c25_e_j++) {
      c25_b_j = c25_e_j;
      c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c25_b_j), 1, 10, 1, 0) - 1].re = c25_b_A
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_b_j), 1, 10, 1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) -
           1)) - 1].re;
      c25_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c25_b_j), 1, 10, 1, 0) - 1].im = c25_b_A
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_b_j), 1, 10, 1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) -
           1)) - 1].im;
    }
  }
}

static real_T c25_b_eml_matlab_zlanhs(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[100], int32_T c25_ilo, int32_T c25_ihi)
{
  real_T c25_f;
  real_T c25_scale;
  real_T c25_sumsq;
  boolean_T c25_firstNonZero;
  int32_T c25_b_ilo;
  int32_T c25_b_ihi;
  int32_T c25_a;
  int32_T c25_b;
  int32_T c25_b_a;
  int32_T c25_b_b;
  boolean_T c25_overflow;
  int32_T c25_j;
  int32_T c25_b_j;
  int32_T c25_c_ilo;
  int32_T c25_c_a;
  int32_T c25_d_a;
  int32_T c25_c;
  int32_T c25_x;
  int32_T c25_y;
  int32_T c25_i213;
  int32_T c25_e_a;
  int32_T c25_c_b;
  int32_T c25_f_a;
  int32_T c25_d_b;
  boolean_T c25_b_overflow;
  int32_T c25_i;
  int32_T c25_b_i;
  creal_T c25_Aij;
  real_T c25_reAij;
  real_T c25_imAij;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_temp1;
  real_T c25_temp2;
  real_T c25_d_x;
  real_T c25_e_x;
  real_T c25_f_x;
  real_T c25_g_x;
  c25_f = 0.0;
  if (c25_ilo > c25_ihi) {
  } else {
    c25_scale = 0.0;
    c25_sumsq = 0.0;
    c25_firstNonZero = true;
    c25_b_ilo = c25_ilo;
    c25_b_ihi = c25_ihi;
    c25_a = c25_b_ilo;
    c25_b = c25_b_ihi;
    c25_b_a = c25_a;
    c25_b_b = c25_b;
    if (c25_b_a > c25_b_b) {
      c25_overflow = false;
    } else {
      c25_eml_switch_helper(chartInstance);
      c25_eml_switch_helper(chartInstance);
      c25_overflow = (c25_b_b > 2147483646);
    }

    if (c25_overflow) {
      c25_check_forloop_overflow_error(chartInstance, c25_overflow);
    }

    for (c25_j = c25_b_ilo; c25_j <= c25_b_ihi; c25_j++) {
      c25_b_j = c25_j;
      c25_c_ilo = c25_ilo;
      c25_c_a = c25_b_j;
      c25_d_a = c25_c_a;
      c25_c = c25_d_a;
      c25_x = c25_c + 1;
      c25_y = c25_ihi;
      c25_i213 = c25_x;
      if (c25_y < c25_i213) {
        c25_i213 = c25_y;
      }

      c25_e_a = c25_c_ilo;
      c25_c_b = c25_i213;
      c25_f_a = c25_e_a;
      c25_d_b = c25_c_b;
      if (c25_f_a > c25_d_b) {
        c25_b_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_b_overflow = (c25_d_b > 2147483646);
      }

      if (c25_b_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
      }

      for (c25_i = c25_c_ilo; c25_i <= c25_i213; c25_i++) {
        c25_b_i = c25_i;
        c25_Aij.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re;
        c25_Aij.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im;
        c25_reAij = c25_Aij.re;
        c25_imAij = c25_Aij.im;
        if (c25_reAij != 0.0) {
          c25_b_x = c25_reAij;
          c25_c_x = c25_b_x;
          c25_temp1 = muDoubleScalarAbs(c25_c_x);
          if (c25_firstNonZero) {
            c25_sumsq = 1.0;
            c25_scale = c25_temp1;
            c25_firstNonZero = false;
          } else if (c25_scale < c25_temp1) {
            c25_temp2 = c25_scale / c25_temp1;
            c25_sumsq = 1.0 + c25_sumsq * c25_temp2 * c25_temp2;
            c25_scale = c25_temp1;
          } else {
            c25_temp2 = c25_temp1 / c25_scale;
            c25_sumsq += c25_temp2 * c25_temp2;
          }
        }

        if (c25_imAij != 0.0) {
          c25_d_x = c25_imAij;
          c25_e_x = c25_d_x;
          c25_temp1 = muDoubleScalarAbs(c25_e_x);
          if (c25_firstNonZero) {
            c25_sumsq = 1.0;
            c25_scale = c25_temp1;
            c25_firstNonZero = false;
          } else if (c25_scale < c25_temp1) {
            c25_temp2 = c25_scale / c25_temp1;
            c25_sumsq = 1.0 + c25_sumsq * c25_temp2 * c25_temp2;
            c25_scale = c25_temp1;
          } else {
            c25_temp2 = c25_temp1 / c25_scale;
            c25_sumsq += c25_temp2 * c25_temp2;
          }
        }
      }
    }

    c25_f_x = c25_sumsq;
    c25_g_x = c25_f_x;
    if (c25_g_x < 0.0) {
      c25_c_eml_error(chartInstance);
    }

    c25_g_x = muDoubleScalarSqrt(c25_g_x);
    c25_f = c25_scale * c25_g_x;
  }

  return c25_f;
}

static boolean_T c25_b_eml_relop(SFc25_hybridSysSimInstanceStruct *chartInstance,
  creal_T c25_a, creal_T c25_b)
{
  real_T c25_RMAXA;
  real_T c25_RMAXB;
  real_T c25_d14;
  real_T c25_d15;
  real_T c25_d16;
  real_T c25_d17;
  real_T c25_A;
  real_T c25_y;
  real_T c25_b_A;
  real_T c25_b_y;
  real_T c25_x;
  real_T c25_c_A;
  real_T c25_c_y;
  real_T c25_d_A;
  real_T c25_d_y;
  real_T c25_e_y;
  real_T c25_b_a;
  real_T c25_b_b;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_f_y;
  real_T c25_e_A;
  real_T c25_g_y;
  real_T c25_d_x;
  real_T c25_e_x;
  real_T c25_f_x;
  real_T c25_absxk;
  real_T c25_r;
  int32_T c25_exponent;
  int32_T c25_b_exponent;
  int32_T c25_c_exponent;
  real_T c25_g_x;
  boolean_T c25_c_b;
  real_T c25_h_x;
  boolean_T c25_d_b;
  boolean_T c25_b28;
  boolean_T c25_b_p;
  real_T c25_ar;
  real_T c25_absar;
  real_T c25_ai;
  real_T c25_absai;
  real_T c25_br;
  real_T c25_absbr;
  real_T c25_bi;
  real_T c25_absbi;
  real_T c25_Ma;
  real_T c25_ma;
  real_T c25_Mb;
  real_T c25_mb;
  real_T c25_f_A;
  real_T c25_h_y;
  real_T c25_g_A;
  real_T c25_i_y;
  real_T c25_Mbar;
  real_T c25_h_A;
  real_T c25_j_y;
  real_T c25_i_A;
  real_T c25_k_y;
  real_T c25_mbar;
  real_T c25_j_A;
  real_T c25_B;
  real_T c25_l_y;
  real_T c25_k_A;
  real_T c25_m_y;
  real_T c25_l_A;
  real_T c25_n_y;
  real_T c25_m_A;
  real_T c25_o_y;
  real_T c25_n_A;
  real_T c25_p_y;
  real_T c25_o_A;
  real_T c25_b_B;
  real_T c25_q_y;
  real_T c25_c_a;
  real_T c25_e_b;
  real_T c25_i_x;
  real_T c25_j_x;
  real_T c25_r_y;
  real_T c25_p_A;
  real_T c25_s_y;
  real_T c25_k_x;
  real_T c25_l_x;
  real_T c25_m_x;
  real_T c25_b_absxk;
  real_T c25_b_r;
  int32_T c25_d_exponent;
  int32_T c25_e_exponent;
  int32_T c25_f_exponent;
  real_T c25_n_x;
  boolean_T c25_f_b;
  real_T c25_o_x;
  boolean_T c25_g_b;
  boolean_T c25_b29;
  boolean_T c25_c_p;
  real_T c25_d_a;
  real_T c25_h_b;
  real_T c25_p_x;
  real_T c25_q_x;
  real_T c25_t_y;
  real_T c25_q_A;
  real_T c25_u_y;
  real_T c25_r_x;
  real_T c25_s_x;
  real_T c25_t_x;
  real_T c25_c_absxk;
  real_T c25_c_r;
  int32_T c25_g_exponent;
  int32_T c25_h_exponent;
  int32_T c25_i_exponent;
  real_T c25_u_x;
  boolean_T c25_i_b;
  real_T c25_v_x;
  boolean_T c25_j_b;
  boolean_T c25_b30;
  boolean_T c25_d_p;
  real_T c25_v_y;
  real_T c25_w_y;
  real_T c25_x_y;
  real_T c25_y_y;
  real_T c25_e_a;
  real_T c25_k_b;
  real_T c25_w_x;
  real_T c25_x_x;
  real_T c25_ab_y;
  real_T c25_r_A;
  real_T c25_bb_y;
  real_T c25_y_x;
  real_T c25_ab_x;
  real_T c25_bb_x;
  real_T c25_d_absxk;
  real_T c25_d_r;
  int32_T c25_j_exponent;
  int32_T c25_k_exponent;
  int32_T c25_l_exponent;
  real_T c25_cb_x;
  boolean_T c25_l_b;
  real_T c25_db_x;
  boolean_T c25_m_b;
  boolean_T c25_b31;
  boolean_T c25_e_p;
  real_T c25_eb_x;
  real_T c25_cb_y;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  boolean_T guard13 = false;
  boolean_T guard14 = false;
  boolean_T guard15 = false;
  c25_realmax(chartInstance);
  c25_RMAXA = c25_rdivide(chartInstance, 1.7976931348623157E+308, 2.0);
  c25_realmax(chartInstance);
  c25_RMAXB = c25_rdivide(chartInstance, 1.7976931348623157E+308, 2.0);
  c25_d14 = c25_abs(chartInstance, c25_a.re);
  guard13 = false;
  guard14 = false;
  guard15 = false;
  if (c25_d14 > c25_RMAXA) {
    guard15 = true;
  } else {
    c25_d15 = c25_abs(chartInstance, c25_a.im);
    if (c25_d15 > c25_RMAXA) {
      guard15 = true;
    } else {
      c25_d16 = c25_abs(chartInstance, c25_b.re);
      if (c25_d16 > c25_RMAXB) {
        guard14 = true;
      } else {
        c25_d17 = c25_abs(chartInstance, c25_b.im);
        if (c25_d17 > c25_RMAXB) {
          guard13 = true;
        } else {
          c25_x = c25_b_abs(chartInstance, c25_a);
          c25_e_y = c25_b_abs(chartInstance, c25_b);
        }
      }
    }
  }

  if (guard15 == true) {
    guard14 = true;
  }

  if (guard14 == true) {
    guard13 = true;
  }

  if (guard13 == true) {
    c25_A = c25_a.re;
    c25_y = c25_rdivide(chartInstance, c25_A, 2.0);
    c25_b_A = c25_a.im;
    c25_b_y = c25_rdivide(chartInstance, c25_b_A, 2.0);
    c25_x = c25_hypot(chartInstance, c25_y, c25_b_y);
    c25_c_A = c25_b.re;
    c25_c_y = c25_rdivide(chartInstance, c25_c_A, 2.0);
    c25_d_A = c25_b.im;
    c25_d_y = c25_rdivide(chartInstance, c25_d_A, 2.0);
    c25_e_y = c25_hypot(chartInstance, c25_c_y, c25_d_y);
  }

  c25_b_a = c25_x;
  c25_b_b = c25_e_y;
  c25_b_x = c25_b_b - c25_b_a;
  c25_c_x = c25_b_x;
  c25_f_y = muDoubleScalarAbs(c25_c_x);
  c25_e_A = c25_b_b;
  c25_g_y = c25_rdivide(chartInstance, c25_e_A, 2.0);
  c25_d_x = c25_g_y;
  c25_eml_realmin(chartInstance);
  c25_e_x = c25_d_x;
  c25_f_x = c25_e_x;
  c25_absxk = muDoubleScalarAbs(c25_f_x);
  if (c25_isfinite(chartInstance, c25_absxk)) {
    if (c25_absxk <= 2.2250738585072014E-308) {
      c25_r = 4.94065645841247E-324;
    } else {
      frexp(c25_absxk, &c25_exponent);
      c25_b_exponent = c25_exponent;
      c25_c_exponent = c25_b_exponent;
      c25_c_exponent;
      c25_r = ldexp(1.0, c25_c_exponent - 53);
    }
  } else {
    c25_r = rtNaN;
  }

  guard10 = false;
  guard11 = false;
  guard12 = false;
  if (c25_f_y < c25_r) {
    guard11 = true;
  } else {
    c25_g_x = c25_b_a;
    c25_c_b = muDoubleScalarIsInf(c25_g_x);
    if (c25_c_b) {
      c25_h_x = c25_b_b;
      c25_d_b = muDoubleScalarIsInf(c25_h_x);
      if (c25_d_b) {
        if (c25_b_a > 0.0 == c25_b_b > 0.0) {
          guard11 = true;
        } else {
          guard10 = true;
        }
      } else {
        guard12 = true;
      }
    } else {
      guard12 = true;
    }
  }

  if (guard12 == true) {
    guard10 = true;
  }

  if (guard11 == true) {
    c25_b28 = true;
  }

  if (guard10 == true) {
    c25_b28 = false;
  }

  c25_b_p = c25_b28;
  if (c25_b_p) {
    c25_ar = c25_a.re;
    c25_absar = c25_abs(chartInstance, c25_ar);
    c25_ai = c25_a.im;
    c25_absai = c25_abs(chartInstance, c25_ai);
    c25_br = c25_b.re;
    c25_absbr = c25_abs(chartInstance, c25_br);
    c25_bi = c25_b.im;
    c25_absbi = c25_abs(chartInstance, c25_bi);
    if (c25_absar > c25_absai) {
      c25_Ma = c25_absar;
      c25_ma = c25_absai;
    } else {
      c25_Ma = c25_absai;
      c25_ma = c25_absar;
    }

    if (c25_absbr > c25_absbi) {
      c25_Mb = c25_absbr;
      c25_mb = c25_absbi;
    } else {
      c25_Mb = c25_absbi;
      c25_mb = c25_absbr;
    }

    if (c25_Ma > c25_Mb) {
      if (c25_ma < c25_mb) {
        c25_x = c25_Ma - c25_Mb;
        c25_f_A = c25_Ma;
        c25_h_y = c25_rdivide(chartInstance, c25_f_A, 2.0);
        c25_g_A = c25_Mb;
        c25_i_y = c25_rdivide(chartInstance, c25_g_A, 2.0);
        c25_Mbar = c25_h_y + c25_i_y;
        c25_h_A = c25_ma;
        c25_j_y = c25_rdivide(chartInstance, c25_h_A, 2.0);
        c25_i_A = c25_mb;
        c25_k_y = c25_rdivide(chartInstance, c25_i_A, 2.0);
        c25_mbar = c25_j_y + c25_k_y;
        c25_j_A = c25_mbar;
        c25_B = c25_Mbar;
        c25_l_y = c25_rdivide(chartInstance, c25_j_A, c25_B);
        c25_e_y = c25_l_y * (c25_mb - c25_ma);
      } else {
        c25_x = c25_Ma;
        c25_e_y = c25_Mb;
      }
    } else if (c25_Ma < c25_Mb) {
      if (c25_ma > c25_mb) {
        c25_e_y = c25_Mb - c25_Ma;
        c25_k_A = c25_Ma;
        c25_m_y = c25_rdivide(chartInstance, c25_k_A, 2.0);
        c25_l_A = c25_Mb;
        c25_n_y = c25_rdivide(chartInstance, c25_l_A, 2.0);
        c25_Mbar = c25_m_y + c25_n_y;
        c25_m_A = c25_ma;
        c25_o_y = c25_rdivide(chartInstance, c25_m_A, 2.0);
        c25_n_A = c25_mb;
        c25_p_y = c25_rdivide(chartInstance, c25_n_A, 2.0);
        c25_mbar = c25_o_y + c25_p_y;
        c25_o_A = c25_mbar;
        c25_b_B = c25_Mbar;
        c25_q_y = c25_rdivide(chartInstance, c25_o_A, c25_b_B);
        c25_x = c25_q_y * (c25_ma - c25_mb);
      } else {
        c25_x = c25_Ma;
        c25_e_y = c25_Mb;
      }
    } else {
      c25_x = c25_ma;
      c25_e_y = c25_mb;
    }

    c25_c_a = c25_x;
    c25_e_b = c25_e_y;
    c25_i_x = c25_e_b - c25_c_a;
    c25_j_x = c25_i_x;
    c25_r_y = muDoubleScalarAbs(c25_j_x);
    c25_p_A = c25_e_b;
    c25_s_y = c25_rdivide(chartInstance, c25_p_A, 2.0);
    c25_k_x = c25_s_y;
    c25_eml_realmin(chartInstance);
    c25_l_x = c25_k_x;
    c25_m_x = c25_l_x;
    c25_b_absxk = muDoubleScalarAbs(c25_m_x);
    if (c25_isfinite(chartInstance, c25_b_absxk)) {
      if (c25_b_absxk <= 2.2250738585072014E-308) {
        c25_b_r = 4.94065645841247E-324;
      } else {
        frexp(c25_b_absxk, &c25_d_exponent);
        c25_e_exponent = c25_d_exponent;
        c25_f_exponent = c25_e_exponent;
        c25_f_exponent;
        c25_b_r = ldexp(1.0, c25_f_exponent - 53);
      }
    } else {
      c25_b_r = rtNaN;
    }

    guard7 = false;
    guard8 = false;
    guard9 = false;
    if (c25_r_y < c25_b_r) {
      guard8 = true;
    } else {
      c25_n_x = c25_c_a;
      c25_f_b = muDoubleScalarIsInf(c25_n_x);
      if (c25_f_b) {
        c25_o_x = c25_e_b;
        c25_g_b = muDoubleScalarIsInf(c25_o_x);
        if (c25_g_b) {
          if (c25_c_a > 0.0 == c25_e_b > 0.0) {
            guard8 = true;
          } else {
            guard7 = true;
          }
        } else {
          guard9 = true;
        }
      } else {
        guard9 = true;
      }
    }

    if (guard9 == true) {
      guard7 = true;
    }

    if (guard8 == true) {
      c25_b29 = true;
    }

    if (guard7 == true) {
      c25_b29 = false;
    }

    c25_c_p = c25_b29;
    if (c25_c_p) {
      c25_x = c25_angle(chartInstance, c25_a);
      c25_e_y = c25_angle(chartInstance, c25_b);
      c25_d_a = c25_x;
      c25_h_b = c25_e_y;
      c25_p_x = c25_h_b - c25_d_a;
      c25_q_x = c25_p_x;
      c25_t_y = muDoubleScalarAbs(c25_q_x);
      c25_q_A = c25_h_b;
      c25_u_y = c25_rdivide(chartInstance, c25_q_A, 2.0);
      c25_r_x = c25_u_y;
      c25_eml_realmin(chartInstance);
      c25_s_x = c25_r_x;
      c25_t_x = c25_s_x;
      c25_c_absxk = muDoubleScalarAbs(c25_t_x);
      if (c25_isfinite(chartInstance, c25_c_absxk)) {
        if (c25_c_absxk <= 2.2250738585072014E-308) {
          c25_c_r = 4.94065645841247E-324;
        } else {
          frexp(c25_c_absxk, &c25_g_exponent);
          c25_h_exponent = c25_g_exponent;
          c25_i_exponent = c25_h_exponent;
          c25_i_exponent;
          c25_c_r = ldexp(1.0, c25_i_exponent - 53);
        }
      } else {
        c25_c_r = rtNaN;
      }

      guard4 = false;
      guard5 = false;
      guard6 = false;
      if (c25_t_y < c25_c_r) {
        guard5 = true;
      } else {
        c25_u_x = c25_d_a;
        c25_i_b = muDoubleScalarIsInf(c25_u_x);
        if (c25_i_b) {
          c25_v_x = c25_h_b;
          c25_j_b = muDoubleScalarIsInf(c25_v_x);
          if (c25_j_b) {
            if (c25_d_a > 0.0 == c25_h_b > 0.0) {
              guard5 = true;
            } else {
              guard4 = true;
            }
          } else {
            guard6 = true;
          }
        } else {
          guard6 = true;
        }
      }

      if (guard6 == true) {
        guard4 = true;
      }

      if (guard5 == true) {
        c25_b30 = true;
      }

      if (guard4 == true) {
        c25_b30 = false;
      }

      c25_d_p = c25_b30;
      if (c25_d_p) {
        c25_v_y = c25_rdivide(chartInstance, 3.1415926535897931, 4.0);
        if (c25_x > c25_v_y) {
          c25_w_y = c25_rdivide(chartInstance, 9.42477796076938, 4.0);
          if (c25_x > c25_w_y) {
            c25_x = -c25_ai;
            c25_e_y = -c25_bi;
          } else {
            c25_x = -c25_ar;
            c25_e_y = -c25_br;
          }
        } else {
          c25_x_y = c25_rdivide(chartInstance, -3.1415926535897931, 4.0);
          if (c25_x > c25_x_y) {
            c25_x = c25_ai;
            c25_e_y = c25_bi;
          } else {
            c25_y_y = c25_rdivide(chartInstance, -9.42477796076938, 4.0);
            if (c25_x > c25_y_y) {
              c25_x = c25_ar;
              c25_e_y = c25_br;
            } else {
              c25_x = -c25_ai;
              c25_e_y = -c25_bi;
            }
          }
        }

        c25_e_a = c25_x;
        c25_k_b = c25_e_y;
        c25_w_x = c25_k_b - c25_e_a;
        c25_x_x = c25_w_x;
        c25_ab_y = muDoubleScalarAbs(c25_x_x);
        c25_r_A = c25_k_b;
        c25_bb_y = c25_rdivide(chartInstance, c25_r_A, 2.0);
        c25_y_x = c25_bb_y;
        c25_eml_realmin(chartInstance);
        c25_ab_x = c25_y_x;
        c25_bb_x = c25_ab_x;
        c25_d_absxk = muDoubleScalarAbs(c25_bb_x);
        if (c25_isfinite(chartInstance, c25_d_absxk)) {
          if (c25_d_absxk <= 2.2250738585072014E-308) {
            c25_d_r = 4.94065645841247E-324;
          } else {
            frexp(c25_d_absxk, &c25_j_exponent);
            c25_k_exponent = c25_j_exponent;
            c25_l_exponent = c25_k_exponent;
            c25_l_exponent;
            c25_d_r = ldexp(1.0, c25_l_exponent - 53);
          }
        } else {
          c25_d_r = rtNaN;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (c25_ab_y < c25_d_r) {
          guard2 = true;
        } else {
          c25_cb_x = c25_e_a;
          c25_l_b = muDoubleScalarIsInf(c25_cb_x);
          if (c25_l_b) {
            c25_db_x = c25_k_b;
            c25_m_b = muDoubleScalarIsInf(c25_db_x);
            if (c25_m_b) {
              if (c25_e_a > 0.0 == c25_k_b > 0.0) {
                guard2 = true;
              } else {
                guard1 = true;
              }
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
        }

        if (guard3 == true) {
          guard1 = true;
        }

        if (guard2 == true) {
          c25_b31 = true;
        }

        if (guard1 == true) {
          c25_b31 = false;
        }

        c25_e_p = c25_b31;
        if (c25_e_p) {
          c25_x = 0.0;
          c25_e_y = 0.0;
        }
      }
    }
  }

  c25_eb_x = c25_x;
  c25_cb_y = c25_e_y;
  return c25_eb_x > c25_cb_y;
}

static void c25_i_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_sprintf, const char_T *c25_identifier,
  char_T c25_y[14])
{
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_sprintf), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_sprintf);
}

static void c25_j_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  char_T c25_y[14])
{
  char_T c25_cv7[14];
  int32_T c25_i214;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_cv7, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c25_i214 = 0; c25_i214 < 14; c25_i214++) {
    c25_y[c25_i214] = c25_cv7[c25_i214];
  }

  sf_mex_destroy(&c25_u);
}

static const mxArray *c25_j_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(int32_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static int32_T c25_k_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  int32_T c25_y;
  int32_T c25_i215;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_i215, 1, 6, 0U, 0, 0U, 0);
  c25_y = c25_i215;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_sfEvent;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  int32_T c25_y;
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c25_b_sfEvent = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_sfEvent),
    &c25_thisId);
  sf_mex_destroy(&c25_b_sfEvent);
  *(int32_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static uint8_T c25_l_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_hybridSysSim, const char_T *
  c25_identifier)
{
  uint8_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c25_b_is_active_c25_hybridSysSim), &c25_thisId);
  sf_mex_destroy(&c25_b_is_active_c25_hybridSysSim);
  return c25_y;
}

static uint8_T c25_m_emlrt_marshallIn(SFc25_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  uint8_T c25_y;
  uint8_T c25_u0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_u0, 1, 3, 0U, 0, 0U, 0);
  c25_y = c25_u0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_b_eml_xaxpy(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T c25_a, real_T c25_y[4])
{
  real_T c25_b_a;
  real_T c25_c_a;
  int32_T c25_ix;
  int32_T c25_iy;
  int32_T c25_k;
  int32_T c25_d_a;
  int32_T c25_c;
  int32_T c25_e_a;
  int32_T c25_b_c;
  int32_T c25_f_a;
  int32_T c25_c_c;
  int32_T c25_g_a;
  int32_T c25_h_a;
  c25_b_a = c25_a;
  c25_c_a = c25_b_a;
  if (c25_c_a == 0.0) {
  } else {
    c25_ix = 0;
    c25_iy = 2;
    c25_eml_switch_helper(chartInstance);
    for (c25_k = 0; c25_k < 2; c25_k++) {
      c25_d_a = c25_iy;
      c25_c = c25_d_a;
      c25_e_a = c25_iy;
      c25_b_c = c25_e_a;
      c25_f_a = c25_ix;
      c25_c_c = c25_f_a;
      c25_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c25_c + 1)), 1, 4, 1, 0) - 1] =
        c25_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c25_b_c + 1)), 1, 4, 1, 0) - 1] + c25_c_a *
        c25_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c25_c_c + 1)), 1, 4, 1, 0) - 1];
      c25_g_a = c25_ix + 1;
      c25_ix = c25_g_a;
      c25_h_a = c25_iy + 1;
      c25_iy = c25_h_a;
    }
  }
}

static void c25_c_sqrt(SFc25_hybridSysSimInstanceStruct *chartInstance, real_T
  *c25_x)
{
  if (*c25_x < 0.0) {
    c25_c_eml_error(chartInstance);
  }

  *c25_x = muDoubleScalarSqrt(*c25_x);
}

static void c25_b_eml_xrotg(SFc25_hybridSysSimInstanceStruct *chartInstance,
  real_T *c25_a, real_T *c25_b, real_T *c25_c, real_T *c25_s)
{
  real_T c25_b_a;
  real_T c25_b_b;
  real_T c25_c_b;
  real_T c25_c_a;
  real_T c25_d_a;
  real_T c25_d_b;
  real_T c25_e_b;
  real_T c25_e_a;
  real_T c25_b_c;
  real_T c25_b_s;
  double * c25_a_t;
  double * c25_b_t;
  double * c25_c_t;
  double * c25_s_t;
  real_T c25_c_c;
  real_T c25_c_s;
  (void)chartInstance;
  c25_b_a = *c25_a;
  c25_b_b = *c25_b;
  c25_c_b = c25_b_b;
  c25_c_a = c25_b_a;
  c25_d_a = c25_c_a;
  c25_d_b = c25_c_b;
  c25_e_b = c25_d_b;
  c25_e_a = c25_d_a;
  c25_b_c = 0.0;
  c25_b_s = 0.0;
  c25_a_t = (double *)(&c25_e_a);
  c25_b_t = (double *)(&c25_e_b);
  c25_c_t = (double *)(&c25_b_c);
  c25_s_t = (double *)(&c25_b_s);
  drotg(c25_a_t, c25_b_t, c25_c_t, c25_s_t);
  c25_c_a = c25_e_a;
  c25_c_b = c25_e_b;
  c25_c_c = c25_b_c;
  c25_c_s = c25_b_s;
  *c25_a = c25_c_a;
  *c25_b = c25_c_b;
  *c25_c = c25_c_c;
  *c25_s = c25_c_s;
}

static void c25_b_eml_matlab_zlascl(SFc25_hybridSysSimInstanceStruct
  *chartInstance, real_T c25_cfrom, real_T c25_cto, creal_T c25_A[4])
{
  real_T c25_cfromc;
  real_T c25_ctoc;
  boolean_T c25_notdone;
  real_T c25_cfrom1;
  real_T c25_cto1;
  real_T c25_x;
  real_T c25_b_x;
  real_T c25_y;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_b_y;
  real_T c25_mul;
  real_T c25_e_x;
  real_T c25_f_x;
  real_T c25_c_y;
  real_T c25_g_x;
  real_T c25_h_x;
  real_T c25_d_y;
  real_T c25_a;
  int32_T c25_i216;
  boolean_T guard1 = false;
  c25_eml_realmin(chartInstance);
  c25_eps(chartInstance);
  c25_cfromc = c25_cfrom;
  c25_ctoc = c25_cto;
  c25_notdone = true;
  while (c25_notdone) {
    c25_cfrom1 = c25_cfromc * 2.0041683600089728E-292;
    c25_cto1 = c25_ctoc / 4.9896007738368E+291;
    c25_x = c25_cfrom1;
    c25_b_x = c25_x;
    c25_y = muDoubleScalarAbs(c25_b_x);
    c25_c_x = c25_ctoc;
    c25_d_x = c25_c_x;
    c25_b_y = muDoubleScalarAbs(c25_d_x);
    guard1 = false;
    if (c25_y > c25_b_y) {
      if (c25_ctoc != 0.0) {
        c25_mul = 2.0041683600089728E-292;
        c25_notdone = true;
        c25_cfromc = c25_cfrom1;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      c25_e_x = c25_cto1;
      c25_f_x = c25_e_x;
      c25_c_y = muDoubleScalarAbs(c25_f_x);
      c25_g_x = c25_cfromc;
      c25_h_x = c25_g_x;
      c25_d_y = muDoubleScalarAbs(c25_h_x);
      if (c25_c_y > c25_d_y) {
        c25_mul = 4.9896007738368E+291;
        c25_notdone = true;
        c25_ctoc = c25_cto1;
      } else {
        c25_mul = c25_ctoc / c25_cfromc;
        c25_notdone = false;
      }
    }

    c25_a = c25_mul;
    for (c25_i216 = 0; c25_i216 < 4; c25_i216++) {
      c25_A[c25_i216].re *= c25_a;
      c25_A[c25_i216].im *= c25_a;
    }
  }
}

static void c25_c_eml_matlab_zggbal(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[4], int32_T *c25_ilo, int32_T *c25_ihi, int32_T
  c25_rscale[2])
{
  int32_T c25_i217;
  int32_T c25_b_ihi;
  int32_T c25_i;
  int32_T c25_j;
  boolean_T c25_found;
  int32_T c25_ii;
  real_T c25_nzcount;
  int32_T c25_c_ihi;
  int32_T c25_b;
  int32_T c25_b_b;
  boolean_T c25_overflow;
  int32_T c25_jj;
  int32_T c25_b_jj;
  static creal_T c25_dc20 = { 0.0, 0.0 };

  boolean_T c25_b_A;
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_b_i;
  int32_T c25_b_j;
  boolean_T c25_b_found;
  int32_T c25_b_ilo;
  int32_T c25_d_ihi;
  int32_T c25_c_i;
  int32_T c25_c_j;
  boolean_T c25_c_found;
  int32_T c25_c_ilo;
  int32_T c25_e_ihi;
  int32_T c25_c_a;
  int32_T c25_c_b;
  int32_T c25_d_a;
  int32_T c25_d_b;
  boolean_T c25_b_overflow;
  int32_T c25_c_jj;
  int32_T c25_d_jj;
  real_T c25_b_nzcount;
  int32_T c25_d_ilo;
  int32_T c25_f_ihi;
  int32_T c25_e_a;
  int32_T c25_e_b;
  int32_T c25_f_a;
  int32_T c25_f_b;
  boolean_T c25_c_overflow;
  int32_T c25_b_ii;
  int32_T c25_c_ii;
  boolean_T c25_c_A;
  int32_T c25_m;
  int32_T c25_d_i;
  int32_T c25_d_j;
  int32_T c25_e_ilo;
  int32_T c25_g_ihi;
  int32_T c25_f_ilo;
  int32_T c25_g_a;
  int32_T c25_h_a;
  boolean_T c25_d_overflow;
  int32_T c25_k;
  int32_T c25_b_k;
  creal_T c25_atmp;
  int32_T c25_h_ihi;
  int32_T c25_g_b;
  int32_T c25_h_b;
  boolean_T c25_e_overflow;
  int32_T c25_c_k;
  int32_T c25_i_a;
  int32_T c25_j_a;
  int32_T c25_b_m;
  int32_T c25_e_i;
  int32_T c25_e_j;
  int32_T c25_i_ihi;
  int32_T c25_d_k;
  int32_T c25_e_k;
  int32_T c25_j_ihi;
  int32_T c25_i_b;
  int32_T c25_j_b;
  boolean_T c25_f_overflow;
  int32_T c25_f_k;
  int32_T c25_k_a;
  int32_T c25_l_a;
  int32_T exitg1;
  int32_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T exitg6;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  for (c25_i217 = 0; c25_i217 < 2; c25_i217++) {
    c25_rscale[c25_i217] = 0;
  }

  *c25_ilo = 1;
  *c25_ihi = 2;
  do {
    exitg2 = 0;
    c25_b_ihi = *c25_ihi;
    c25_i = 0;
    c25_j = 0;
    c25_found = false;
    c25_ii = c25_b_ihi;
    exitg5 = false;
    while ((exitg5 == false) && (c25_ii > 0)) {
      c25_nzcount = 0.0;
      c25_i = c25_ii;
      c25_j = c25_b_ihi;
      c25_c_ihi = c25_b_ihi;
      c25_b = c25_c_ihi;
      c25_b_b = c25_b;
      if (1 > c25_b_b) {
        c25_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_overflow = (c25_b_b > 2147483646);
      }

      if (c25_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_overflow);
      }

      c25_jj = 1;
      exitg6 = false;
      while ((exitg6 == false) && (c25_jj <= c25_c_ihi)) {
        c25_b_jj = c25_jj;
        c25_b_A = ((c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_ii), 1, 2, 1, 0) +
                           ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_jj), 1, 2, 2, 0) - 1) << 1)) - 1]
                    .re != c25_dc20.re) || (c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ii), 1, 2, 1, 0) +
          ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_jj), 1, 2, 2, 0) - 1) << 1)) - 1].im != c25_dc20.im));
        guard3 = false;
        guard4 = false;
        if (c25_b_A) {
          guard4 = true;
        } else if (c25_ii == c25_b_jj) {
          guard4 = true;
        } else {
          guard3 = true;
        }

        if (guard4 == true) {
          if (c25_nzcount == 0.0) {
            c25_j = c25_b_jj;
            c25_nzcount = 1.0;
            guard3 = true;
          } else {
            c25_nzcount = 2.0;
            exitg6 = true;
          }
        }

        if (guard3 == true) {
          c25_jj++;
        }
      }

      if (c25_nzcount < 2.0) {
        c25_found = true;
        exitg5 = true;
      } else {
        c25_a = c25_ii;
        c25_b_a = c25_a - 1;
        c25_ii = c25_b_a;
      }
    }

    c25_b_i = c25_i;
    c25_b_j = c25_j;
    c25_b_found = c25_found;
    if (!c25_b_found) {
      exitg2 = 2;
    } else {
      c25_b_m = *c25_ihi;
      c25_e_i = c25_b_i;
      c25_e_j = c25_b_j;
      c25_i_ihi = *c25_ihi;
      if (c25_e_i != c25_b_m) {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        for (c25_d_k = 1; c25_d_k < 3; c25_d_k++) {
          c25_e_k = c25_d_k;
          c25_atmp.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_i), 1, 2, 1, 0) +
                               ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2, 2, 0) - 1) << 1)) - 1]
            .re;
          c25_atmp.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_i), 1, 2, 1, 0) +
                               ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2, 2, 0) - 1) << 1)) - 1]
            .im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2,
                    2, 0) - 1) << 1)) - 1].re = c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_b_m), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2, 2, 0) -
                1) << 1)) - 1].re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2,
                    2, 0) - 1) << 1)) - 1].im = c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_b_m), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2, 2, 0) -
                1) << 1)) - 1].im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_m), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2,
                    2, 0) - 1) << 1)) - 1].re = c25_atmp.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_m), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2,
                    2, 0) - 1) << 1)) - 1].im = c25_atmp.im;
        }
      }

      if (c25_e_j != c25_b_m) {
        c25_j_ihi = c25_i_ihi;
        c25_i_b = c25_j_ihi;
        c25_j_b = c25_i_b;
        if (1 > c25_j_b) {
          c25_f_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_f_overflow = (c25_j_b > 2147483646);
        }

        if (c25_f_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_f_overflow);
        }

        for (c25_f_k = 1; c25_f_k <= c25_j_ihi; c25_f_k++) {
          c25_e_k = c25_f_k;
          c25_atmp.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2, 1, 0) +
                               ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_j), 1, 2, 2, 0) - 1) << 1)) - 1]
            .re;
          c25_atmp.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 2, 1, 0) +
                               ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_j), 1, 2, 2, 0) - 1) << 1)) - 1]
            .im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_j), 1, 2,
                    2, 0) - 1) << 1)) - 1].re = c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_m), 1, 2, 2, 0) -
                1) << 1)) - 1].re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_e_j), 1, 2,
                    2, 0) - 1) << 1)) - 1].im = c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_m), 1, 2, 2, 0) -
                1) << 1)) - 1].im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_m), 1, 2,
                    2, 0) - 1) << 1)) - 1].re = c25_atmp.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_m), 1, 2,
                    2, 0) - 1) << 1)) - 1].im = c25_atmp.im;
        }
      }

      c25_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)*c25_ihi), 1, 2, 1, 0) - 1] = c25_b_j;
      c25_k_a = *c25_ihi;
      c25_l_a = c25_k_a - 1;
      *c25_ihi = c25_l_a;
      if (*c25_ihi == 1) {
        c25_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)*c25_ihi), 1, 2, 1, 0) - 1] = *c25_ihi;
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
  } else {
    do {
      exitg1 = 0;
      c25_b_ilo = *c25_ilo;
      c25_d_ihi = *c25_ihi;
      c25_c_i = 0;
      c25_c_j = 0;
      c25_c_found = false;
      c25_c_ilo = c25_b_ilo;
      c25_e_ihi = c25_d_ihi;
      c25_c_a = c25_c_ilo;
      c25_c_b = c25_e_ihi;
      c25_d_a = c25_c_a;
      c25_d_b = c25_c_b;
      if (c25_d_a > c25_d_b) {
        c25_b_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_b_overflow = (c25_d_b > 2147483646);
      }

      if (c25_b_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
      }

      c25_c_jj = c25_c_ilo;
      exitg3 = false;
      while ((exitg3 == false) && (c25_c_jj <= c25_e_ihi)) {
        c25_d_jj = c25_c_jj;
        c25_b_nzcount = 0.0;
        c25_c_i = c25_d_ihi;
        c25_c_j = c25_d_jj;
        c25_d_ilo = c25_b_ilo;
        c25_f_ihi = c25_d_ihi;
        c25_e_a = c25_d_ilo;
        c25_e_b = c25_f_ihi;
        c25_f_a = c25_e_a;
        c25_f_b = c25_e_b;
        if (c25_f_a > c25_f_b) {
          c25_c_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_c_overflow = (c25_f_b > 2147483646);
        }

        if (c25_c_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_c_overflow);
        }

        c25_b_ii = c25_d_ilo;
        exitg4 = false;
        while ((exitg4 == false) && (c25_b_ii <= c25_f_ihi)) {
          c25_c_ii = c25_b_ii;
          c25_c_A = ((c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_c_ii), 1, 2, 1, 0) +
                             ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_d_jj), 1, 2, 2, 0) - 1) << 1)) -
                      1].re != c25_dc20.re) || (c25_A
                      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_c_ii), 1, 2, 1, 0) +
                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_d_jj), 1, 2, 2, 0) - 1) << 1)) -
                      1].im != c25_dc20.im));
          guard1 = false;
          guard2 = false;
          if (c25_c_A) {
            guard2 = true;
          } else if (c25_c_ii == c25_d_jj) {
            guard2 = true;
          } else {
            guard1 = true;
          }

          if (guard2 == true) {
            if (c25_b_nzcount == 0.0) {
              c25_c_i = c25_c_ii;
              c25_b_nzcount = 1.0;
              guard1 = true;
            } else {
              c25_b_nzcount = 2.0;
              exitg4 = true;
            }
          }

          if (guard1 == true) {
            c25_b_ii++;
          }
        }

        if (c25_b_nzcount < 2.0) {
          c25_c_found = true;
          exitg3 = true;
        } else {
          c25_c_jj++;
        }
      }

      c25_b_i = c25_c_i;
      c25_b_j = c25_c_j;
      c25_b_found = c25_c_found;
      if (!c25_b_found) {
        exitg1 = 1;
      } else {
        c25_m = *c25_ilo;
        c25_d_i = c25_b_i;
        c25_d_j = c25_b_j;
        c25_e_ilo = *c25_ilo;
        c25_g_ihi = *c25_ihi;
        if (c25_d_i != c25_m) {
          c25_f_ilo = c25_e_ilo;
          c25_g_a = c25_f_ilo;
          c25_h_a = c25_g_a;
          if (c25_h_a > 2) {
            c25_d_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_d_overflow = false;
          }

          if (c25_d_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_d_overflow);
          }

          for (c25_k = c25_f_ilo; c25_k < 3; c25_k++) {
            c25_b_k = c25_k;
            c25_atmp.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                                 ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c25_atmp.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 2, 1, 0) +
                                 ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_d_i), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_k), 1, 2, 2, 0) - 1) << 1)) - 1].re =
              c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_m), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 2, 2, 0) - 1)
                      << 1)) - 1].re;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_d_i), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_k), 1, 2, 2, 0) - 1) << 1)) - 1].im =
              c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_m), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 2, 2, 0) - 1)
                      << 1)) - 1].im;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_m), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_k), 1, 2, 2, 0) - 1) << 1)) - 1].re =
              c25_atmp.re;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_m), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_k), 1, 2, 2, 0) - 1) << 1)) - 1].im =
              c25_atmp.im;
          }
        }

        if (c25_d_j != c25_m) {
          c25_h_ihi = c25_g_ihi;
          c25_g_b = c25_h_ihi;
          c25_h_b = c25_g_b;
          if (1 > c25_h_b) {
            c25_e_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_e_overflow = (c25_h_b > 2147483646);
          }

          if (c25_e_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_e_overflow);
          }

          for (c25_c_k = 1; c25_c_k <= c25_h_ihi; c25_c_k++) {
            c25_b_k = c25_c_k;
            c25_atmp.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 2, 1, 0) +
                                 ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c25_atmp.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 2, 1, 0) +
                                 ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_b_k), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_d_j), 1, 2, 2, 0) - 1) << 1)) - 1].re =
              c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_k), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_m), 1, 2, 2, 0) - 1) <<
                      1)) - 1].re;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_b_k), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_d_j), 1, 2, 2, 0) - 1) << 1)) - 1].im =
              c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_b_k), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c25_m), 1, 2, 2, 0) - 1) <<
                      1)) - 1].im;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_b_k), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_m), 1, 2, 2, 0) - 1) << 1)) - 1].re =
              c25_atmp.re;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_b_k), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c25_m), 1, 2, 2, 0) - 1) << 1)) - 1].im =
              c25_atmp.im;
          }
        }

        c25_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)*c25_ilo), 1, 2, 1, 0) - 1] = c25_b_j;
        c25_i_a = *c25_ilo;
        c25_j_a = c25_i_a + 1;
        *c25_ilo = c25_j_a;
        if (*c25_ilo == *c25_ihi) {
          c25_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", (real_T)*c25_ilo), 1, 2, 1, 0) - 1] = *c25_ilo;
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void c25_d_sqrt(SFc25_hybridSysSimInstanceStruct *chartInstance, creal_T *
  c25_x)
{
  real_T c25_yr;
  real_T c25_yi;
  boolean_T c25_b32;
  boolean_T c25_b33;
  boolean_T c25_b;
  real_T c25_b_x;
  boolean_T c25_b_b;
  real_T c25_c_x;
  boolean_T c25_c_b;
  real_T c25_absxr;
  real_T c25_absxi;
  real_T c25_y;
  real_T c25_b_y;
  real_T c25_d_x;
  real_T c25_c_y;
  real_T c25_x1;
  real_T c25_x2;
  real_T c25_a;
  real_T c25_d_b;
  real_T c25_absxd2;
  real_T c25_e_x;
  real_T c25_d_y;
  real_T c25_b_x1;
  real_T c25_b_x2;
  real_T c25_b_a;
  real_T c25_e_b;
  real_T c25_z;
  real_T c25_d18;
  real_T c25_d19;
  boolean_T guard1 = false;
  if (c25_x->im == 0.0) {
    if (c25_x->re < 0.0) {
      c25_yr = 0.0;
      c25_yi = muDoubleScalarSqrt(muDoubleScalarAbs(c25_x->re));
    } else {
      c25_yr = muDoubleScalarSqrt(c25_x->re);
      c25_yi = 0.0;
    }
  } else if (c25_x->re == 0.0) {
    if (c25_x->im < 0.0) {
      c25_yr = muDoubleScalarSqrt(c25_rdivide(chartInstance, -c25_x->im, 2.0));
      c25_yi = -c25_yr;
    } else {
      c25_yr = muDoubleScalarSqrt(c25_rdivide(chartInstance, c25_x->im, 2.0));
      c25_yi = c25_yr;
    }
  } else {
    c25_b32 = muDoubleScalarIsNaN(c25_x->re);
    c25_b33 = muDoubleScalarIsNaN(c25_x->im);
    c25_b = (c25_b32 || c25_b33);
    if (c25_b) {
      c25_yr = rtNaN;
      c25_yi = rtNaN;
    } else {
      c25_b_x = c25_x->im;
      c25_b_b = muDoubleScalarIsInf(c25_b_x);
      if (c25_b_b) {
        c25_yr = rtInf;
        c25_yi = c25_x->im;
      } else {
        c25_c_x = c25_x->re;
        c25_c_b = muDoubleScalarIsInf(c25_c_x);
        if (c25_c_b) {
          if (c25_x->re < 0.0) {
            c25_yr = 0.0;
            c25_yi = rtInf;
          } else {
            c25_yr = rtInf;
            c25_yi = 0.0;
          }
        } else {
          c25_absxr = muDoubleScalarAbs(c25_x->re);
          c25_absxi = muDoubleScalarAbs(c25_x->im);
          c25_realmax(chartInstance);
          c25_y = c25_rdivide(chartInstance, 1.7976931348623157E+308, 4.0);
          guard1 = false;
          if (c25_absxr > c25_y) {
            guard1 = true;
          } else {
            c25_realmax(chartInstance);
            c25_b_y = c25_rdivide(chartInstance, 1.7976931348623157E+308, 4.0);
            if (c25_absxi > c25_b_y) {
              guard1 = true;
            } else {
              c25_e_x = c25_absxr;
              c25_d_y = c25_absxi;
              c25_eml_scalar_eg(chartInstance);
              c25_b_x1 = c25_e_x;
              c25_b_x2 = c25_d_y;
              c25_b_a = c25_b_x1;
              c25_e_b = c25_b_x2;
              c25_z = muDoubleScalarHypot(c25_b_a, c25_e_b);
              c25_yr = muDoubleScalarSqrt((c25_z + c25_absxr) * 0.5);
            }
          }

          if (guard1 == true) {
            c25_absxr *= 0.5;
            c25_absxi *= 0.5;
            c25_d_x = c25_absxr;
            c25_c_y = c25_absxi;
            c25_eml_scalar_eg(chartInstance);
            c25_x1 = c25_d_x;
            c25_x2 = c25_c_y;
            c25_a = c25_x1;
            c25_d_b = c25_x2;
            c25_absxd2 = muDoubleScalarHypot(c25_a, c25_d_b);
            if (c25_absxd2 > c25_absxr) {
              c25_yr = muDoubleScalarSqrt(c25_absxd2) * muDoubleScalarSqrt(1.0 +
                c25_rdivide(chartInstance, c25_absxr, c25_absxd2));
            } else {
              c25_yr = muDoubleScalarSqrt(c25_absxd2) * 1.4142135623730951;
            }
          }

          if (c25_x->re > 0.0) {
            c25_d18 = c25_rdivide(chartInstance, c25_x->im, c25_yr);
            c25_yi = 0.5 * c25_d18;
          } else {
            if (c25_x->im < 0.0) {
              c25_yi = -c25_yr;
            } else {
              c25_yi = c25_yr;
            }

            c25_d19 = c25_rdivide(chartInstance, c25_x->im, c25_yi);
            c25_yr = 0.5 * c25_d19;
          }
        }
      }
    }
  }

  c25_x->re = c25_yr;
  c25_x->im = c25_yi;
}

static void c25_d_eml_matlab_zggbal(SFc25_hybridSysSimInstanceStruct
  *chartInstance, creal_T c25_A[100], int32_T *c25_ilo, int32_T *c25_ihi,
  int32_T c25_rscale[10])
{
  int32_T c25_i218;
  int32_T c25_b_ihi;
  int32_T c25_i;
  int32_T c25_j;
  boolean_T c25_found;
  int32_T c25_ii;
  real_T c25_nzcount;
  int32_T c25_c_ihi;
  int32_T c25_b;
  int32_T c25_b_b;
  boolean_T c25_overflow;
  int32_T c25_jj;
  int32_T c25_b_jj;
  static creal_T c25_dc21 = { 0.0, 0.0 };

  boolean_T c25_b_A;
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_b_i;
  int32_T c25_b_j;
  boolean_T c25_b_found;
  int32_T c25_b_ilo;
  int32_T c25_d_ihi;
  int32_T c25_c_i;
  int32_T c25_c_j;
  boolean_T c25_c_found;
  int32_T c25_c_ilo;
  int32_T c25_e_ihi;
  int32_T c25_c_a;
  int32_T c25_c_b;
  int32_T c25_d_a;
  int32_T c25_d_b;
  boolean_T c25_b_overflow;
  int32_T c25_c_jj;
  int32_T c25_d_jj;
  real_T c25_b_nzcount;
  int32_T c25_d_ilo;
  int32_T c25_f_ihi;
  int32_T c25_e_a;
  int32_T c25_e_b;
  int32_T c25_f_a;
  int32_T c25_f_b;
  boolean_T c25_c_overflow;
  int32_T c25_b_ii;
  int32_T c25_c_ii;
  boolean_T c25_c_A;
  int32_T c25_m;
  int32_T c25_d_i;
  int32_T c25_d_j;
  int32_T c25_e_ilo;
  int32_T c25_g_ihi;
  int32_T c25_f_ilo;
  int32_T c25_g_a;
  int32_T c25_h_a;
  boolean_T c25_d_overflow;
  int32_T c25_k;
  int32_T c25_b_k;
  creal_T c25_atmp;
  int32_T c25_h_ihi;
  int32_T c25_g_b;
  int32_T c25_h_b;
  boolean_T c25_e_overflow;
  int32_T c25_c_k;
  int32_T c25_i_a;
  int32_T c25_j_a;
  int32_T c25_b_m;
  int32_T c25_e_i;
  int32_T c25_e_j;
  int32_T c25_i_ihi;
  int32_T c25_d_k;
  int32_T c25_e_k;
  int32_T c25_j_ihi;
  int32_T c25_i_b;
  int32_T c25_j_b;
  boolean_T c25_f_overflow;
  int32_T c25_f_k;
  int32_T c25_k_a;
  int32_T c25_l_a;
  int32_T exitg1;
  int32_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T exitg6;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  for (c25_i218 = 0; c25_i218 < 10; c25_i218++) {
    c25_rscale[c25_i218] = 0;
  }

  *c25_ilo = 1;
  *c25_ihi = 10;
  do {
    exitg2 = 0;
    c25_b_ihi = *c25_ihi;
    c25_i = 0;
    c25_j = 0;
    c25_found = false;
    c25_ii = c25_b_ihi;
    exitg5 = false;
    while ((exitg5 == false) && (c25_ii > 0)) {
      c25_nzcount = 0.0;
      c25_i = c25_ii;
      c25_j = c25_b_ihi;
      c25_c_ihi = c25_b_ihi;
      c25_b = c25_c_ihi;
      c25_b_b = c25_b;
      if (1 > c25_b_b) {
        c25_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_overflow = (c25_b_b > 2147483646);
      }

      if (c25_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_overflow);
      }

      c25_jj = 1;
      exitg6 = false;
      while ((exitg6 == false) && (c25_jj <= c25_c_ihi)) {
        c25_b_jj = c25_jj;
        c25_b_A = ((c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_ii), 1, 10, 1, 0) + 10 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_b_jj), 1, 10, 2, 0) - 1)) - 1].re
                    != c25_dc21.re) || (c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_ii), 1, 10, 1, 0) + 10 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c25_b_jj), 1, 10, 2, 0) - 1)) - 1].im != c25_dc21.im));
        guard3 = false;
        guard4 = false;
        if (c25_b_A) {
          guard4 = true;
        } else if (c25_ii == c25_b_jj) {
          guard4 = true;
        } else {
          guard3 = true;
        }

        if (guard4 == true) {
          if (c25_nzcount == 0.0) {
            c25_j = c25_b_jj;
            c25_nzcount = 1.0;
            guard3 = true;
          } else {
            c25_nzcount = 2.0;
            exitg6 = true;
          }
        }

        if (guard3 == true) {
          c25_jj++;
        }
      }

      if (c25_nzcount < 2.0) {
        c25_found = true;
        exitg5 = true;
      } else {
        c25_a = c25_ii;
        c25_b_a = c25_a - 1;
        c25_ii = c25_b_a;
      }
    }

    c25_b_i = c25_i;
    c25_b_j = c25_j;
    c25_b_found = c25_found;
    if (!c25_b_found) {
      exitg2 = 2;
    } else {
      c25_b_m = *c25_ihi;
      c25_e_i = c25_b_i;
      c25_e_j = c25_b_j;
      c25_i_ihi = *c25_ihi;
      if (c25_e_i != c25_b_m) {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        for (c25_d_k = 1; c25_d_k < 11; c25_d_k++) {
          c25_e_k = c25_d_k;
          c25_atmp.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_i), 1, 10, 1, 0) + 10 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 10, 2, 0) - 1)) - 1].re;
          c25_atmp.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_i), 1, 10, 1, 0) + 10 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 10, 2, 0) - 1)) - 1].im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_e_k), 1, 10, 2, 0) - 1)) - 1].re = c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_b_m), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_e_k), 1, 10, 2, 0) - 1)) - 1].re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_e_k), 1, 10, 2, 0) - 1)) - 1].im = c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_b_m), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_e_k), 1, 10, 2, 0) - 1)) - 1].im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_m), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_e_k), 1, 10, 2, 0) - 1)) - 1].re = c25_atmp.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_m), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_e_k), 1, 10, 2, 0) - 1)) - 1].im = c25_atmp.im;
        }
      }

      if (c25_e_j != c25_b_m) {
        c25_j_ihi = c25_i_ihi;
        c25_i_b = c25_j_ihi;
        c25_j_b = c25_i_b;
        if (1 > c25_j_b) {
          c25_f_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_f_overflow = (c25_j_b > 2147483646);
        }

        if (c25_f_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_f_overflow);
        }

        for (c25_f_k = 1; c25_f_k <= c25_j_ihi; c25_f_k++) {
          c25_e_k = c25_f_k;
          c25_atmp.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 10, 1, 0) + 10 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_j), 1, 10, 2, 0) - 1)) - 1].re;
          c25_atmp.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_k), 1, 10, 1, 0) + 10 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_e_j), 1, 10, 2, 0) - 1)) - 1].im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_k), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_e_j), 1, 10, 2, 0) - 1)) - 1].re = c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_e_k), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_b_m), 1, 10, 2, 0) - 1)) - 1].re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_k), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_e_j), 1, 10, 2, 0) - 1)) - 1].im = c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_e_k), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_b_m), 1, 10, 2, 0) - 1)) - 1].im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_k), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_b_m), 1, 10, 2, 0) - 1)) - 1].re = c25_atmp.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_e_k), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_b_m), 1, 10, 2, 0) - 1)) - 1].im = c25_atmp.im;
        }
      }

      c25_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)*c25_ihi), 1, 10, 1, 0) - 1] = c25_b_j;
      c25_k_a = *c25_ihi;
      c25_l_a = c25_k_a - 1;
      *c25_ihi = c25_l_a;
      if (*c25_ihi == 1) {
        c25_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)*c25_ihi), 1, 10, 1, 0) - 1] = *c25_ihi;
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
  } else {
    do {
      exitg1 = 0;
      c25_b_ilo = *c25_ilo;
      c25_d_ihi = *c25_ihi;
      c25_c_i = 0;
      c25_c_j = 0;
      c25_c_found = false;
      c25_c_ilo = c25_b_ilo;
      c25_e_ihi = c25_d_ihi;
      c25_c_a = c25_c_ilo;
      c25_c_b = c25_e_ihi;
      c25_d_a = c25_c_a;
      c25_d_b = c25_c_b;
      if (c25_d_a > c25_d_b) {
        c25_b_overflow = false;
      } else {
        c25_eml_switch_helper(chartInstance);
        c25_eml_switch_helper(chartInstance);
        c25_b_overflow = (c25_d_b > 2147483646);
      }

      if (c25_b_overflow) {
        c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
      }

      c25_c_jj = c25_c_ilo;
      exitg3 = false;
      while ((exitg3 == false) && (c25_c_jj <= c25_e_ihi)) {
        c25_d_jj = c25_c_jj;
        c25_b_nzcount = 0.0;
        c25_c_i = c25_d_ihi;
        c25_c_j = c25_d_jj;
        c25_d_ilo = c25_b_ilo;
        c25_f_ihi = c25_d_ihi;
        c25_e_a = c25_d_ilo;
        c25_e_b = c25_f_ihi;
        c25_f_a = c25_e_a;
        c25_f_b = c25_e_b;
        if (c25_f_a > c25_f_b) {
          c25_c_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_c_overflow = (c25_f_b > 2147483646);
        }

        if (c25_c_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_c_overflow);
        }

        c25_b_ii = c25_d_ilo;
        exitg4 = false;
        while ((exitg4 == false) && (c25_b_ii <= c25_f_ihi)) {
          c25_c_ii = c25_b_ii;
          c25_c_A = ((c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_c_ii), 1, 10, 1, 0) + 10 *
                             (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_d_jj), 1, 10, 2, 0) - 1)) - 1].re
                      != c25_dc21.re) || (c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_c_ii), 1, 10,
            1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_d_jj), 1, 10, 2, 0) - 1)) - 1].im
                      != c25_dc21.im));
          guard1 = false;
          guard2 = false;
          if (c25_c_A) {
            guard2 = true;
          } else if (c25_c_ii == c25_d_jj) {
            guard2 = true;
          } else {
            guard1 = true;
          }

          if (guard2 == true) {
            if (c25_b_nzcount == 0.0) {
              c25_c_i = c25_c_ii;
              c25_b_nzcount = 1.0;
              guard1 = true;
            } else {
              c25_b_nzcount = 2.0;
              exitg4 = true;
            }
          }

          if (guard1 == true) {
            c25_b_ii++;
          }
        }

        if (c25_b_nzcount < 2.0) {
          c25_c_found = true;
          exitg3 = true;
        } else {
          c25_c_jj++;
        }
      }

      c25_b_i = c25_c_i;
      c25_b_j = c25_c_j;
      c25_b_found = c25_c_found;
      if (!c25_b_found) {
        exitg1 = 1;
      } else {
        c25_m = *c25_ilo;
        c25_d_i = c25_b_i;
        c25_d_j = c25_b_j;
        c25_e_ilo = *c25_ilo;
        c25_g_ihi = *c25_ihi;
        if (c25_d_i != c25_m) {
          c25_f_ilo = c25_e_ilo;
          c25_g_a = c25_f_ilo;
          c25_h_a = c25_g_a;
          if (c25_h_a > 10) {
            c25_d_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_d_overflow = false;
          }

          if (c25_d_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_d_overflow);
          }

          for (c25_k = c25_f_ilo; c25_k < 11; c25_k++) {
            c25_b_k = c25_k;
            c25_atmp.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 10, 2, 0) - 1)) - 1].
              re;
            c25_atmp.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 10, 2, 0) - 1)) - 1].
              im;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c25_b_k), 1, 10, 2, 0) - 1)) - 1].re = c25_A
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c25_m), 1, 10, 1, 0) + 10 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_k), 1, 10, 2, 0) - 1)) - 1].re;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_d_i), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c25_b_k), 1, 10, 2, 0) - 1)) - 1].im = c25_A
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c25_m), 1, 10, 1, 0) + 10 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_k), 1, 10, 2, 0) - 1)) - 1].im;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_m), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c25_b_k), 1, 10, 2, 0) - 1)) - 1].re =
              c25_atmp.re;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_m), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c25_b_k), 1, 10, 2, 0) - 1)) - 1].im =
              c25_atmp.im;
          }
        }

        if (c25_d_j != c25_m) {
          c25_h_ihi = c25_g_ihi;
          c25_g_b = c25_h_ihi;
          c25_h_b = c25_g_b;
          if (1 > c25_h_b) {
            c25_e_overflow = false;
          } else {
            c25_eml_switch_helper(chartInstance);
            c25_eml_switch_helper(chartInstance);
            c25_e_overflow = (c25_h_b > 2147483646);
          }

          if (c25_e_overflow) {
            c25_check_forloop_overflow_error(chartInstance, c25_e_overflow);
          }

          for (c25_c_k = 1; c25_c_k <= c25_h_ihi; c25_c_k++) {
            c25_b_k = c25_c_k;
            c25_atmp.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 10, 1, 0) + 10 *
                                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2, 0) - 1)) - 1].
              re;
            c25_atmp.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_b_k), 1, 10, 1, 0) + 10 *
                                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c25_d_j), 1, 10, 2, 0) - 1)) - 1].
              im;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_b_k), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c25_d_j), 1, 10, 2, 0) - 1)) - 1].re = c25_A
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c25_b_k), 1, 10, 1, 0) + 10 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_m), 1, 10, 2, 0) - 1)) - 1].re;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_b_k), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c25_d_j), 1, 10, 2, 0) - 1)) - 1].im = c25_A
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c25_b_k), 1, 10, 1, 0) + 10 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_m), 1, 10, 2, 0) - 1)) - 1].im;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_b_k), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c25_m), 1, 10, 2, 0) - 1)) - 1].re =
              c25_atmp.re;
            c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c25_b_k), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c25_m), 1, 10, 2, 0) - 1)) - 1].im =
              c25_atmp.im;
          }
        }

        c25_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)*c25_ilo), 1, 10, 1, 0) - 1] = c25_b_j;
        c25_i_a = *c25_ilo;
        c25_j_a = c25_i_a + 1;
        *c25_ilo = c25_j_a;
        if (*c25_ilo == *c25_ihi) {
          c25_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", (real_T)*c25_ilo), 1, 10, 1, 0) - 1] = *c25_ilo;
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void c25_b_eml_matlab_zgghrd(SFc25_hybridSysSimInstanceStruct
  *chartInstance, int32_T c25_ilo, int32_T c25_ihi, creal_T c25_A[100])
{
  int32_T c25_a;
  int32_T c25_b_a;
  int32_T c25_c;
  int32_T c25_c_a;
  int32_T c25_d_a;
  int32_T c25_ihim1;
  int32_T c25_jcol;
  int32_T c25_e_a;
  int32_T c25_f_a;
  int32_T c25_jcolp1;
  int32_T c25_jrow;
  int32_T c25_g_a;
  int32_T c25_h_a;
  int32_T c25_jrowm1;
  creal_T c25_b_A;
  creal_T c25_c_A;
  creal_T c25_b;
  creal_T c25_s;
  real_T c25_b_c;
  real_T c25_c_c;
  static creal_T c25_dc22 = { 0.0, 0.0 };

  real_T c25_d_c;
  int32_T c25_xrow;
  int32_T c25_yrow;
  int32_T c25_jlo;
  int32_T c25_jhi;
  int32_T c25_b_jlo;
  int32_T c25_b_jhi;
  int32_T c25_i_a;
  int32_T c25_b_b;
  int32_T c25_j_a;
  int32_T c25_c_b;
  boolean_T c25_overflow;
  int32_T c25_j;
  int32_T c25_b_j;
  real_T c25_k_a;
  creal_T c25_y;
  creal_T c25_b_s;
  creal_T c25_stemp;
  real_T c25_l_a;
  creal_T c25_d_b;
  creal_T c25_e_b;
  creal_T c25_f_b;
  creal_T c25_g_b;
  real_T c25_e_c;
  int32_T c25_xcol;
  int32_T c25_ycol;
  int32_T c25_b_ilo;
  int32_T c25_b_ihi;
  int32_T c25_c_ilo;
  int32_T c25_c_ihi;
  int32_T c25_m_a;
  int32_T c25_h_b;
  int32_T c25_n_a;
  int32_T c25_i_b;
  boolean_T c25_b_overflow;
  int32_T c25_i;
  int32_T c25_b_i;
  real_T c25_o_a;
  creal_T c25_c_s;
  real_T c25_p_a;
  creal_T c25_j_b;
  creal_T c25_k_b;
  creal_T c25_l_b;
  creal_T c25_m_b;
  c25_a = c25_ilo;
  c25_b_a = c25_a;
  c25_c = c25_b_a;
  if (c25_ihi < c25_c + 2) {
  } else {
    c25_c_a = c25_ihi;
    c25_d_a = c25_c_a;
    c25_ihim1 = c25_d_a;
    c25_jcol = c25_ilo;
    while (c25_jcol < c25_ihim1 - 1) {
      c25_e_a = c25_jcol;
      c25_f_a = c25_e_a + 1;
      c25_jcolp1 = c25_f_a;
      c25_jrow = c25_ihi;
      while (c25_jrow > c25_jcolp1) {
        c25_g_a = c25_jrow;
        c25_h_a = c25_g_a - 1;
        c25_jrowm1 = c25_h_a;
        c25_b_A.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_jrowm1), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_jcol), 1, 10, 2, 0) - 1)) - 1].re;
        c25_b_A.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_jrowm1), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_jcol), 1, 10, 2, 0) - 1)) - 1].im;
        c25_c_A.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_jrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_jcol), 1, 10, 2, 0) - 1)) - 1].re;
        c25_c_A.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_jrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c25_jcol), 1, 10, 2, 0) - 1)) - 1].im;
        c25_eml_matlab_zlartg(chartInstance, c25_b_A, c25_c_A, &c25_b_c, &c25_s,
                              &c25_b);
        c25_c_c = c25_b_c;
        c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_jrowm1), 1, 10, 1, 0) + 10 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c25_jcol), 1, 10, 2, 0) - 1)) - 1].re = c25_b.re;
        c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_jrowm1), 1, 10, 1, 0) + 10 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c25_jcol), 1, 10, 2, 0) - 1)) - 1].im = c25_b.im;
        c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_jrow), 1, 10, 1, 0) + 10 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c25_jcol), 1, 10, 2, 0) - 1)) - 1].re = c25_dc22.re;
        c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_jrow), 1, 10, 1, 0) + 10 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c25_jcol), 1, 10, 2, 0) - 1)) - 1].im = c25_dc22.im;
        c25_d_c = c25_c_c;
        c25_xrow = c25_jrowm1;
        c25_yrow = c25_jrow;
        c25_jlo = c25_jcolp1;
        c25_jhi = c25_ihi;
        c25_b_jlo = c25_jlo;
        c25_b_jhi = c25_jhi;
        c25_i_a = c25_b_jlo;
        c25_b_b = c25_b_jhi;
        c25_j_a = c25_i_a;
        c25_c_b = c25_b_b;
        if (c25_j_a > c25_c_b) {
          c25_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_overflow = (c25_c_b > 2147483646);
        }

        if (c25_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_overflow);
        }

        for (c25_j = c25_b_jlo; c25_j <= c25_b_jhi; c25_j++) {
          c25_b_j = c25_j;
          c25_k_a = c25_d_c;
          c25_b.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re;
          c25_b.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im;
          c25_y.re = c25_k_a * c25_b.re;
          c25_y.im = c25_k_a * c25_b.im;
          c25_b_s.re = c25_s.re * c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1, 0) + 10
            * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re - c25_s.im * c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_yrow), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im;
          c25_b_s.im = c25_s.re * c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1, 0) + 10
            * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im + c25_s.im * c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_yrow), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re;
          c25_stemp.re = c25_y.re + c25_b_s.re;
          c25_stemp.im = c25_y.im + c25_b_s.im;
          c25_l_a = c25_d_c;
          c25_b.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re;
          c25_b.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_yrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im;
          c25_y.re = c25_l_a * c25_b.re;
          c25_y.im = c25_l_a * c25_b.im;
          c25_b.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re;
          c25_b.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im;
          c25_d_b = c25_b;
          c25_e_b = c25_b;
          c25_f_b = c25_b;
          c25_g_b = c25_b;
          c25_b.re = c25_s.re * c25_d_b.re + c25_s.im * c25_e_b.im;
          c25_b.im = c25_s.re * c25_f_b.im - c25_s.im * c25_g_b.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_yrow), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re = c25_y.re -
            c25_b.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_yrow), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im = c25_y.im -
            c25_b.im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].re = c25_stemp.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_xrow), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_b_j), 1, 10, 2, 0) - 1)) - 1].im = c25_stemp.im;
        }

        c25_s.re = -c25_s.re;
        c25_s.im = -c25_s.im;
        c25_e_c = c25_c_c;
        c25_xcol = c25_jrow;
        c25_ycol = c25_jrowm1;
        c25_b_ilo = c25_ilo;
        c25_b_ihi = c25_ihi;
        c25_c_ilo = c25_b_ilo;
        c25_c_ihi = c25_b_ihi;
        c25_m_a = c25_c_ilo;
        c25_h_b = c25_c_ihi;
        c25_n_a = c25_m_a;
        c25_i_b = c25_h_b;
        if (c25_n_a > c25_i_b) {
          c25_b_overflow = false;
        } else {
          c25_eml_switch_helper(chartInstance);
          c25_eml_switch_helper(chartInstance);
          c25_b_overflow = (c25_i_b > 2147483646);
        }

        if (c25_b_overflow) {
          c25_check_forloop_overflow_error(chartInstance, c25_b_overflow);
        }

        for (c25_i = c25_c_ilo; c25_i <= c25_c_ihi; c25_i++) {
          c25_b_i = c25_i;
          c25_o_a = c25_e_c;
          c25_b.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1].re;
          c25_b.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1].im;
          c25_y.re = c25_o_a * c25_b.re;
          c25_y.im = c25_o_a * c25_b.im;
          c25_c_s.re = c25_s.re * c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1].re - c25_s.im * c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1].im;
          c25_c_s.im = c25_s.re * c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1].im + c25_s.im * c25_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1].re;
          c25_stemp.re = c25_y.re + c25_c_s.re;
          c25_stemp.im = c25_y.im + c25_c_s.im;
          c25_p_a = c25_e_c;
          c25_b.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1].re;
          c25_b.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1].im;
          c25_y.re = c25_p_a * c25_b.re;
          c25_y.im = c25_p_a * c25_b.im;
          c25_b.re = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1].re;
          c25_b.im = c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1].im;
          c25_j_b = c25_b;
          c25_k_b = c25_b;
          c25_l_b = c25_b;
          c25_m_b = c25_b;
          c25_b.re = c25_s.re * c25_j_b.re + c25_s.im * c25_k_b.im;
          c25_b.im = c25_s.re * c25_l_b.im - c25_s.im * c25_m_b.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1].re = c25_y.re -
            c25_b.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_ycol), 1, 10, 2, 0) - 1)) - 1].im = c25_y.im -
            c25_b.im;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1].re = c25_stemp.re;
          c25_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c25_b_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c25_xcol), 1, 10, 2, 0) - 1)) - 1].im = c25_stemp.im;
        }

        c25_jrow = c25_jrowm1;
      }

      c25_jcol = c25_jcolp1;
    }
  }
}

static int32_T c25_div_s32(SFc25_hybridSysSimInstanceStruct *chartInstance,
  int32_T c25_numerator, int32_T c25_denominator)
{
  int32_T c25_quotient;
  uint32_T c25_absNumerator;
  uint32_T c25_absDenominator;
  boolean_T c25_quotientNeedsNegation;
  uint32_T c25_tempAbsQuotient;
  (void)chartInstance;
  if (c25_denominator == 0) {
    if (c25_numerator >= 0) {
      c25_quotient = MAX_int32_T;
    } else {
      c25_quotient = MIN_int32_T;
    }

    _SFD_OVERFLOW_DETECTION(SFDB_DIVIDE_BY_ZERO);
  } else {
    if (c25_numerator >= 0) {
      c25_absNumerator = (uint32_T)c25_numerator;
    } else {
      c25_absNumerator = (uint32_T)-c25_numerator;
    }

    if (c25_denominator >= 0) {
      c25_absDenominator = (uint32_T)c25_denominator;
    } else {
      c25_absDenominator = (uint32_T)-c25_denominator;
    }

    c25_quotientNeedsNegation = (c25_numerator < 0 != c25_denominator < 0);
    c25_tempAbsQuotient = c25_absNumerator / c25_absDenominator;
    if (c25_quotientNeedsNegation) {
      c25_quotient = -(int32_T)c25_tempAbsQuotient;
    } else {
      c25_quotient = (int32_T)c25_tempAbsQuotient;
    }
  }

  return c25_quotient;
}

static void init_dsm_address_info(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc25_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c25_q = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c25_rGAC = (creal_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c25_qDot = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c25_qTilde = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c25_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2342498959U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3423671954U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4151009445U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3128862947U);
}

mxArray* sf_c25_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c25_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5SU3ZBswaNmXlCJoV5BLuE");
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

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(1));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c25_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c25_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c25_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c25_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c25_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c25_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"rGAC\",},{M[8],M[0],T\"is_active_c25_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c25_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc25_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc25_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           25,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,2,0,1,"rGAC");
          _SFD_SET_DATA_PROPS(2,1,1,0,"qDot");
          _SFD_SET_DATA_PROPS(3,1,1,0,"qTilde");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1999);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,1,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)c25_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c25_q);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c25_rGAC);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c25_qDot);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c25_qTilde);
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
  return "A0A33CuYlV9gUJevsOtaBF";
}

static void sf_opaque_initialize_c25_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc25_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c25_hybridSysSim(void *chartInstanceVar)
{
  enable_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c25_hybridSysSim(void *chartInstanceVar)
{
  disable_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c25_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c25_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c25_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c25_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc25_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*)
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
  initSimStructsc25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c25_hybridSysSim(SimStruct *S)
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
    initialize_params_c25_hybridSysSim((SFc25_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c25_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      25);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,25,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,25,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,25);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,25,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,25,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,25);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(674442751U));
  ssSetChecksum1(S,(33252911U));
  ssSetChecksum2(S,(3422805413U));
  ssSetChecksum3(S,(1841598073U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c25_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c25_hybridSysSim(SimStruct *S)
{
  SFc25_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc25_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc25_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc25_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c25_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c25_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c25_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c25_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c25_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c25_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c25_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c25_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c25_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c25_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c25_hybridSysSim;
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

void c25_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c25_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c25_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c25_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c25_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
