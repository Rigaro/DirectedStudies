/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c26_hybridSysSim.h"
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
static const char * c26_debug_family_names[49] = { "kP", "kD", "dP", "dD", "lP",
  "lD", "rP", "rD", "aP", "aD", "bP", "bD", "mP", "mD", "IP", "ID", "alpha",
  "beta", "delta", "M", "C", "D", "Hp", "Hd", "Ki", "Kp", "Kd", "kc", "lambdaM",
  "lambdaHp", "lambdaHd", "lambdaKi", "kq", "zero", "one", "L1", "L2", "L3",
  "L4", "L5", "L", "lambdaL", "lambdaD", "nargin", "nargout", "q", "qDot",
  "FcTilde", "rCFC" };

/* Function Declarations */
static void initialize_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void c26_update_debugger_state_c26_hybridSysSim
  (SFc26_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c26_hybridSysSim
  (SFc26_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_st);
static void finalize_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void c26_chartstep_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber, uint32_T c26_instanceNumber);
static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static creal_T c26_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_b_rCFC, const char_T *c26_identifier);
static creal_T c26_b_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static real_T c26_c_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_e_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static const mxArray *c26_f_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_d_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  creal_T c26_y[10]);
static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_g_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_e_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[100]);
static void c26_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_h_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_f_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[20]);
static void c26_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_i_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_g_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  creal_T c26_y[2]);
static void c26_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static void c26_h_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[4]);
static void c26_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static void c26_info_helper(const mxArray **c26_info);
static const mxArray *c26_emlrt_marshallOut(const char * c26_u);
static const mxArray *c26_b_emlrt_marshallOut(const uint32_T c26_u);
static void c26_b_info_helper(const mxArray **c26_info);
static void c26_c_info_helper(const mxArray **c26_info);
static void c26_d_info_helper(const mxArray **c26_info);
static void c26_e_info_helper(const mxArray **c26_info);
static void c26_eml_scalar_eg(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_assert(SFc26_hybridSysSimInstanceStruct *chartInstance);
static real_T c26_rdivide(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_x, real_T c26_y);
static real_T c26_norm(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x[2]);
static void c26_threshold(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_realmin(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_eml_realmin(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_eml_switch_helper(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static real_T c26_abs(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
                      c26_x);
static real_T c26_b_norm(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x[4]);
static boolean_T c26_isfinite(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_x);
static void c26_eml_error(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_eml_matlab_zsvdc(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_A[4], real_T c26_S[2]);
static void c26_b_eml_scalar_eg(SFc26_hybridSysSimInstanceStruct *chartInstance);
static real_T c26_eml_xnrm2(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_x[4]);
static void c26_eps(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_b_eml_switch_helper(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static real_T c26_eml_xdotc(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_x[4], real_T c26_y[4]);
static void c26_eml_xaxpy(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_a, real_T c26_y[4], real_T c26_b_y[4]);
static void c26_b_eml_error(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_check_forloop_overflow_error(SFc26_hybridSysSimInstanceStruct
  *chartInstance, boolean_T c26_overflow);
static real_T c26_sqrt(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x);
static void c26_c_eml_error(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_eml_xrotg(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_a, real_T c26_b, real_T *c26_b_a, real_T *c26_b_b, real_T *c26_c,
  real_T *c26_s);
static void c26_eig(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
                    c26_A[4], creal_T c26_V[2]);
static void c26_b_assert(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_c_assert(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_parseopts(SFc26_hybridSysSimInstanceStruct *chartInstance);
static real_T c26_eml_matlab_zlangeM(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_x[4]);
static real_T c26_b_abs(SFc26_hybridSysSimInstanceStruct *chartInstance, creal_T
  c26_x);
static void c26_eml_matlab_zlascl(SFc26_hybridSysSimInstanceStruct
  *chartInstance, real_T c26_cfrom, real_T c26_cto, creal_T c26_A[4], creal_T
  c26_b_A[4]);
static void c26_eml_matlab_zggbal(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[4], creal_T c26_b_A[4], int32_T *c26_ilo,
  int32_T *c26_ihi, int32_T c26_rscale[2]);
static void c26_eml_matlab_zlartg(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_f, creal_T c26_g, real_T *c26_cs, creal_T *c26_sn,
  creal_T *c26_r);
static void c26_eml_matlab_zhgeqz(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[4], int32_T c26_ilo, int32_T c26_ihi, int32_T
  *c26_info, creal_T c26_alpha1[2], creal_T c26_beta1[2]);
static real_T c26_eml_matlab_zlanhs(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[4], int32_T c26_ilo, int32_T c26_ihi);
static int32_T c26_mod(SFc26_hybridSysSimInstanceStruct *chartInstance, int32_T
  c26_x);
static creal_T c26_b_sqrt(SFc26_hybridSysSimInstanceStruct *chartInstance,
  creal_T c26_x);
static void c26_realmax(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_b_eml_matlab_zlartg(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_f, creal_T c26_g, real_T *c26_cs, creal_T *c26_sn);
static void c26_eml_warning(SFc26_hybridSysSimInstanceStruct *chartInstance);
static boolean_T c26_eml_relop(SFc26_hybridSysSimInstanceStruct *chartInstance,
  creal_T c26_a, creal_T c26_b);
static real_T c26_hypot(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x, real_T c26_y);
static real_T c26_angle(SFc26_hybridSysSimInstanceStruct *chartInstance, creal_T
  c26_x);
static void c26_inv(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
                    c26_x[4], real_T c26_y[4]);
static real_T c26_c_norm(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x[4]);
static void c26_b_eml_warning(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_c_eml_warning(SFc26_hybridSysSimInstanceStruct *chartInstance,
  char_T c26_varargin_2[14]);
static void c26_b_eig(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
                      c26_A[100], creal_T c26_V[10]);
static void c26_c_eml_scalar_eg(SFc26_hybridSysSimInstanceStruct *chartInstance);
static real_T c26_b_eml_matlab_zlangeM(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_x[100]);
static void c26_b_eml_matlab_zggbal(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[100], creal_T c26_b_A[100], int32_T *c26_ilo,
  int32_T *c26_ihi, int32_T c26_rscale[10]);
static void c26_eml_matlab_zgghrd(SFc26_hybridSysSimInstanceStruct
  *chartInstance, int32_T c26_ilo, int32_T c26_ihi, creal_T c26_A[100], creal_T
  c26_b_A[100]);
static void c26_b_eml_matlab_zhgeqz(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[100], int32_T c26_ilo, int32_T c26_ihi, int32_T *
  c26_info, creal_T c26_alpha1[10], creal_T c26_beta1[10]);
static real_T c26_b_eml_matlab_zlanhs(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[100], int32_T c26_ilo, int32_T c26_ihi);
static boolean_T c26_b_eml_relop(SFc26_hybridSysSimInstanceStruct *chartInstance,
  creal_T c26_a, creal_T c26_b);
static void c26_i_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_sprintf, const char_T *c26_identifier,
  char_T c26_y[14]);
static void c26_j_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  char_T c26_y[14]);
static const mxArray *c26_j_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static int32_T c26_k_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static uint8_T c26_l_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_hybridSysSim, const char_T *
  c26_identifier);
static uint8_T c26_m_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_b_eml_xaxpy(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_a, real_T c26_y[4]);
static void c26_c_sqrt(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  *c26_x);
static void c26_b_eml_xrotg(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T *c26_a, real_T *c26_b, real_T *c26_c, real_T *c26_s);
static void c26_b_eml_matlab_zlascl(SFc26_hybridSysSimInstanceStruct
  *chartInstance, real_T c26_cfrom, real_T c26_cto, creal_T c26_A[4]);
static void c26_c_eml_matlab_zggbal(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[4], int32_T *c26_ilo, int32_T *c26_ihi, int32_T
  c26_rscale[2]);
static void c26_d_sqrt(SFc26_hybridSysSimInstanceStruct *chartInstance, creal_T *
  c26_x);
static void c26_d_eml_matlab_zggbal(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[100], int32_T *c26_ilo, int32_T *c26_ihi,
  int32_T c26_rscale[10]);
static void c26_b_eml_matlab_zgghrd(SFc26_hybridSysSimInstanceStruct
  *chartInstance, int32_T c26_ilo, int32_T c26_ihi, creal_T c26_A[100]);
static int32_T c26_div_s32(SFc26_hybridSysSimInstanceStruct *chartInstance,
  int32_T c26_numerator, int32_T c26_denominator);
static void init_dsm_address_info(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc26_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c26_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c26_is_active_c26_hybridSysSim = 0U;
}

static void initialize_params_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c26_update_debugger_state_c26_hybridSysSim
  (SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c26_hybridSysSim
  (SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c26_st;
  const mxArray *c26_y = NULL;
  creal_T c26_u;
  const mxArray *c26_b_y = NULL;
  uint8_T c26_hoistedGlobal;
  uint8_T c26_b_u;
  const mxArray *c26_c_y = NULL;
  c26_st = NULL;
  c26_st = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createcellmatrix(2, 1), false);
  c26_u = *chartInstance->c26_rCFC;
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_u, 0, 1U, 0U, 0U, 0), false);
  sf_mex_setcell(c26_y, 0, c26_b_y);
  c26_hoistedGlobal = chartInstance->c26_is_active_c26_hybridSysSim;
  c26_b_u = c26_hoistedGlobal;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c26_y, 1, c26_c_y);
  sf_mex_assign(&c26_st, c26_y, false);
  return c26_st;
}

static void set_sim_state_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_st)
{
  const mxArray *c26_u;
  chartInstance->c26_doneDoubleBufferReInit = true;
  c26_u = sf_mex_dup(c26_st);
  *chartInstance->c26_rCFC = c26_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c26_u, 0)), "rCFC");
  chartInstance->c26_is_active_c26_hybridSysSim = c26_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 1)),
     "is_active_c26_hybridSysSim");
  sf_mex_destroy(&c26_u);
  c26_update_debugger_state_c26_hybridSysSim(chartInstance);
  sf_mex_destroy(&c26_st);
}

static void finalize_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c26_i0;
  int32_T c26_i1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 25U, chartInstance->c26_sfEvent);
  for (c26_i0 = 0; c26_i0 < 2; c26_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c26_q)[c26_i0], 0U);
  }

  chartInstance->c26_sfEvent = CALL_EVENT;
  c26_chartstep_c26_hybridSysSim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c26_i1 = 0; c26_i1 < 2; c26_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c26_qDot)[c26_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c26_FcTilde, 3U);
}

static void mdl_start_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c26_chartstep_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  real_T c26_hoistedGlobal;
  int32_T c26_i2;
  real_T c26_b_q[2];
  int32_T c26_i3;
  real_T c26_b_qDot[2];
  real_T c26_b_FcTilde;
  uint32_T c26_debug_family_var_map[49];
  real_T c26_kP;
  real_T c26_kD;
  real_T c26_dP;
  real_T c26_dD;
  real_T c26_lP;
  real_T c26_lD;
  real_T c26_rP;
  real_T c26_rD;
  real_T c26_aP;
  real_T c26_aD;
  real_T c26_bP;
  real_T c26_bD;
  real_T c26_mP;
  real_T c26_mD;
  real_T c26_IP;
  real_T c26_ID;
  real_T c26_alpha;
  real_T c26_beta;
  real_T c26_delta;
  real_T c26_M[4];
  real_T c26_C[4];
  real_T c26_D[4];
  real_T c26_Hp[4];
  real_T c26_Hd[4];
  real_T c26_Ki[4];
  real_T c26_Kp[4];
  real_T c26_Kd;
  real_T c26_kc;
  creal_T c26_lambdaM[2];
  creal_T c26_lambdaHp[2];
  creal_T c26_lambdaHd[2];
  creal_T c26_lambdaKi[2];
  creal_T c26_kq;
  real_T c26_zero[4];
  real_T c26_one[4];
  real_T c26_L1[20];
  real_T c26_L2[20];
  real_T c26_L3[20];
  real_T c26_L4[20];
  real_T c26_L5[20];
  real_T c26_L[100];
  creal_T c26_lambdaL[10];
  creal_T c26_lambdaD[2];
  real_T c26_nargin = 3.0;
  real_T c26_nargout = 1.0;
  creal_T c26_b_rCFC;
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_d_x;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_g_x;
  real_T c26_h_x;
  real_T c26_i_x;
  real_T c26_j_x;
  real_T c26_k_x;
  real_T c26_l_x;
  int32_T c26_i4;
  static real_T c26_dv0[4] = { 0.01, 0.0, 0.0, 0.01 };

  int32_T c26_i5;
  static real_T c26_dv1[4] = { 110.0, 0.0, 0.0, 110.0 };

  int32_T c26_i6;
  static real_T c26_dv2[4] = { 1.5, 0.0, 0.0, 1.5 };

  int32_T c26_i7;
  static real_T c26_dv3[4] = { 12.0, 0.0, 0.0, 12.0 };

  int32_T c26_i8;
  static real_T c26_dv4[4] = { 50.0, 0.0, 0.0, 50.0 };

  int32_T c26_i9;
  real_T c26_c_qDot[2];
  real_T c26_d0;
  int32_T c26_i10;
  real_T c26_b_C[4];
  real_T c26_A;
  int32_T c26_i11;
  real_T c26_d_qDot[2];
  real_T c26_B;
  int32_T c26_i12;
  real_T c26_b_M[4];
  creal_T c26_dcv0[2];
  int32_T c26_i13;
  int32_T c26_i14;
  int32_T c26_i15;
  int32_T c26_i16;
  int32_T c26_i17;
  creal_T c26_varargin_1[2];
  int32_T c26_ixstart;
  creal_T c26_mtmp;
  boolean_T c26_b0;
  boolean_T c26_b1;
  boolean_T c26_b;
  int32_T c26_ix;
  int32_T c26_b_ix;
  creal_T c26_m_x;
  boolean_T c26_b2;
  boolean_T c26_b3;
  boolean_T c26_b_b;
  int32_T c26_a;
  int32_T c26_b_a;
  int32_T c26_i18;
  int32_T c26_c_a;
  int32_T c26_d_a;
  boolean_T c26_overflow;
  int32_T c26_c_ix;
  creal_T c26_b_varargin_1;
  static creal_T c26_dc0 = { 1.5, 0.0 };

  real_T c26_b_B;
  real_T c26_y;
  real_T c26_b_y;
  real_T c26_c_y;
  real_T c26_ar;
  real_T c26_ai;
  real_T c26_br;
  real_T c26_bi;
  real_T c26_brm;
  real_T c26_bim;
  real_T c26_s;
  real_T c26_d;
  real_T c26_nr;
  real_T c26_ni;
  real_T c26_sgnbr;
  real_T c26_sgnbi;
  int32_T c26_i19;
  int32_T c26_i20;
  int32_T c26_i21;
  int32_T c26_i22;
  int32_T c26_i23;
  static real_T c26_dv5[4] = { 111.51, 0.0, 0.0, 111.51 };

  int32_T c26_i24;
  int32_T c26_i25;
  int32_T c26_i26;
  int32_T c26_i27;
  int32_T c26_i28;
  int32_T c26_i29;
  int32_T c26_i30;
  int32_T c26_i31;
  int32_T c26_i32;
  int32_T c26_i33;
  int32_T c26_i34;
  int32_T c26_i35;
  int32_T c26_i36;
  int32_T c26_i37;
  int32_T c26_i38;
  int32_T c26_i39;
  int32_T c26_i40;
  int32_T c26_i41;
  int32_T c26_i42;
  int32_T c26_i43;
  int32_T c26_i44;
  int32_T c26_i45;
  int32_T c26_i46;
  int32_T c26_i47;
  int32_T c26_i48;
  int32_T c26_i49;
  int32_T c26_i50;
  int32_T c26_i51;
  static real_T c26_dv6[20] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0,
    0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c26_i52;
  int32_T c26_i53;
  int32_T c26_i54;
  int32_T c26_i55;
  int32_T c26_i56;
  int32_T c26_i57;
  int32_T c26_i58;
  int32_T c26_i59;
  int32_T c26_i60;
  int32_T c26_i61;
  int32_T c26_i62;
  int32_T c26_i63;
  int32_T c26_i64;
  int32_T c26_i65;
  int32_T c26_i66;
  int32_T c26_i67;
  real_T c26_dv7[4];
  real_T c26_dv8[4];
  int32_T c26_i68;
  int32_T c26_i69;
  int32_T c26_i70;
  int32_T c26_i71;
  int32_T c26_i72;
  int32_T c26_i73;
  int32_T c26_i74;
  int32_T c26_i75;
  int32_T c26_i76;
  int32_T c26_i77;
  int32_T c26_i78;
  int32_T c26_i79;
  int32_T c26_i80;
  int32_T c26_i81;
  int32_T c26_i82;
  int32_T c26_i83;
  int32_T c26_i84;
  int32_T c26_i85;
  int32_T c26_i86;
  int32_T c26_i87;
  int32_T c26_i88;
  int32_T c26_i89;
  int32_T c26_i90;
  int32_T c26_i91;
  int32_T c26_i92;
  int32_T c26_i93;
  int32_T c26_i94;
  int32_T c26_i95;
  int32_T c26_i96;
  int32_T c26_i97;
  int32_T c26_i98;
  int32_T c26_i99;
  int32_T c26_i100;
  int32_T c26_i101;
  int32_T c26_i102;
  int32_T c26_i103;
  real_T c26_b_L[100];
  creal_T c26_dcv1[10];
  int32_T c26_i104;
  int32_T c26_i105;
  real_T c26_c_B;
  real_T c26_d_y;
  int32_T c26_i106;
  creal_T c26_c_varargin_1[10];
  int32_T c26_b_ixstart;
  boolean_T c26_b4;
  boolean_T c26_b5;
  boolean_T c26_c_b;
  int32_T c26_d_ix;
  int32_T c26_e_ix;
  boolean_T c26_b6;
  boolean_T c26_b7;
  boolean_T c26_d_b;
  int32_T c26_e_a;
  int32_T c26_f_a;
  int32_T c26_i107;
  int32_T c26_g_a;
  int32_T c26_h_a;
  boolean_T c26_b_overflow;
  int32_T c26_f_ix;
  creal_T c26_d_varargin_1;
  int32_T c26_i108;
  int32_T c26_c_ixstart;
  creal_T c26_b_mtmp;
  boolean_T c26_b8;
  boolean_T c26_b9;
  boolean_T c26_e_b;
  int32_T c26_g_ix;
  int32_T c26_h_ix;
  boolean_T c26_b10;
  boolean_T c26_b11;
  boolean_T c26_f_b;
  int32_T c26_i_a;
  int32_T c26_j_a;
  int32_T c26_i109;
  int32_T c26_k_a;
  int32_T c26_l_a;
  boolean_T c26_c_overflow;
  int32_T c26_i_ix;
  creal_T c26_e_varargin_1;
  real_T c26_b_ar;
  real_T c26_b_ai;
  real_T c26_b_br;
  real_T c26_b_bi;
  creal_T c26_e_y;
  real_T c26_b_brm;
  real_T c26_b_bim;
  real_T c26_b_s;
  real_T c26_b_d;
  real_T c26_b_nr;
  real_T c26_b_ni;
  real_T c26_b_sgnbr;
  real_T c26_b_sgnbi;
  real_T c26_m_a;
  int32_T c26_i110;
  int32_T c26_d_ixstart;
  boolean_T c26_b12;
  boolean_T c26_b13;
  boolean_T c26_g_b;
  int32_T c26_j_ix;
  int32_T c26_k_ix;
  boolean_T c26_b14;
  boolean_T c26_b15;
  boolean_T c26_h_b;
  int32_T c26_n_a;
  int32_T c26_o_a;
  int32_T c26_i111;
  int32_T c26_p_a;
  int32_T c26_q_a;
  boolean_T c26_d_overflow;
  int32_T c26_l_ix;
  creal_T c26_f_varargin_1;
  creal_T c26_f_y;
  static creal_T c26_dc1 = { 0.01, 0.0 };

  int32_T c26_m_ix;
  int32_T c26_n_ix;
  int32_T c26_o_ix;
  creal_T c26_dc2;
  int32_T c26_p_ix;
  int32_T c26_q_ix;
  int32_T c26_r_ix;
  int32_T c26_s_ix;
  creal_T c26_dc3;
  int32_T c26_t_ix;
  creal_T c26_c_mtmp;
  int32_T c26_u_ix;
  int32_T c26_v_ix;
  int32_T c26_w_ix;
  creal_T c26_dc4;
  int32_T c26_x_ix;
  int32_T c26_i112;
  int32_T c26_e_ixstart;
  creal_T c26_d_mtmp;
  boolean_T c26_b16;
  boolean_T c26_b17;
  boolean_T c26_i_b;
  int32_T c26_y_ix;
  int32_T c26_ab_ix;
  boolean_T c26_b18;
  boolean_T c26_b19;
  boolean_T c26_j_b;
  int32_T c26_r_a;
  int32_T c26_s_a;
  int32_T c26_i113;
  int32_T c26_t_a;
  int32_T c26_u_a;
  boolean_T c26_e_overflow;
  int32_T c26_bb_ix;
  creal_T c26_g_varargin_1;
  creal_T c26_n_x;
  static creal_T c26_dc5 = { 1.0, 0.0 };

  real_T c26_c_ar;
  real_T c26_c_ai;
  real_T c26_c_br;
  real_T c26_c_bi;
  real_T c26_c_brm;
  real_T c26_c_bim;
  real_T c26_c_s;
  real_T c26_c_d;
  real_T c26_c_nr;
  real_T c26_c_ni;
  real_T c26_c_sgnbr;
  real_T c26_c_sgnbi;
  real_T c26_d_ar;
  real_T c26_d_ai;
  static creal_T c26_dc6 = { 98.0, 0.0 };

  real_T c26_d_br;
  real_T c26_d_bi;
  real_T c26_d_brm;
  real_T c26_d_bim;
  real_T c26_d_s;
  real_T c26_d_d;
  real_T c26_d_nr;
  real_T c26_d_ni;
  real_T c26_d_sgnbr;
  real_T c26_d_sgnbi;
  creal_T c26_o_x;
  static creal_T c26_dc7 = { 0.5625, 0.0 };

  creal_T c26_dc8;
  creal_T c26_g_y;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c26_sfEvent);
  c26_hoistedGlobal = *chartInstance->c26_FcTilde;
  for (c26_i2 = 0; c26_i2 < 2; c26_i2++) {
    c26_b_q[c26_i2] = (*chartInstance->c26_q)[c26_i2];
  }

  for (c26_i3 = 0; c26_i3 < 2; c26_i3++) {
    c26_b_qDot[c26_i3] = (*chartInstance->c26_qDot)[c26_i3];
  }

  c26_b_FcTilde = c26_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 49U, 49U, c26_debug_family_names,
    c26_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_kP, 0U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_kD, 1U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_dP, 2U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_dD, 3U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_lP, 4U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_lD, 5U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_rP, 6U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_rD, 7U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_aP, 8U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_aD, 9U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_bP, 10U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_bD, 11U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_mP, 12U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_mD, 13U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_IP, 14U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_ID, 15U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_alpha, 16U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_beta, 17U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_delta, 18U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_M, 19U, c26_i_sf_marshallOut,
    c26_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_C, 20U, c26_i_sf_marshallOut,
    c26_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_D, 21U, c26_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Hp, 22U, c26_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Hd, 23U, c26_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Ki, 24U, c26_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Kp, 25U, c26_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_Kd, 26U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_kc, 27U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_lambdaM, 28U, c26_e_sf_marshallOut,
    c26_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_lambdaHp, 29U, c26_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_lambdaHd, 30U, c26_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_lambdaKi, 31U, c26_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_kq, 32U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_zero, 33U, c26_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_one, 34U, c26_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_L1, 35U, c26_h_sf_marshallOut,
    c26_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_L2, 36U, c26_h_sf_marshallOut,
    c26_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_L3, 37U, c26_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_L4, 38U, c26_h_sf_marshallOut,
    c26_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_L5, 39U, c26_h_sf_marshallOut,
    c26_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_L, 40U, c26_g_sf_marshallOut,
    c26_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_lambdaL, 41U, c26_f_sf_marshallOut,
    c26_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_lambdaD, 42U, c26_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargin, 43U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargout, 44U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_b_q, 45U, c26_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_b_qDot, 46U, c26_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_b_FcTilde, 47U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_b_rCFC, 48U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 3);
  c26_kP = 0.043;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 4);
  c26_kD = 0.185;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 5);
  c26_dP = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 6);
  c26_dD = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 7);
  c26_lP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 8);
  c26_lD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 9);
  c26_rP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 10);
  c26_rD = 0.012;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 11);
  c26_aP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 12);
  c26_aD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 13);
  c26_bP = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 14);
  c26_bD = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 15);
  c26_mP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 16);
  c26_mD = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 17);
  c26_IP = 6.6666666666666683E-5;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 18);
  c26_ID = 1.6666666666666671E-5;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 20);
  c26_alpha = 0.0003833333333333334;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 21);
  c26_beta = 0.0001;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 22);
  c26_delta = c26_ID + 5.0000000000000009E-5;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 24);
  c26_x = c26_b_q[1];
  c26_b_x = c26_x;
  c26_b_x = muDoubleScalarCos(c26_b_x);
  c26_c_x = c26_b_q[1];
  c26_d_x = c26_c_x;
  c26_d_x = muDoubleScalarCos(c26_d_x);
  c26_e_x = c26_b_q[1];
  c26_f_x = c26_e_x;
  c26_f_x = muDoubleScalarCos(c26_f_x);
  c26_M[0] = c26_alpha + 0.0002 * c26_b_x;
  c26_M[2] = c26_delta + 0.0001 * c26_d_x;
  c26_M[1] = c26_delta + 0.0001 * c26_f_x;
  c26_M[3] = c26_delta;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 27);
  c26_g_x = c26_b_q[1];
  c26_h_x = c26_g_x;
  c26_h_x = muDoubleScalarSin(c26_h_x);
  c26_i_x = c26_b_q[1];
  c26_j_x = c26_i_x;
  c26_j_x = muDoubleScalarSin(c26_j_x);
  c26_k_x = c26_b_q[1];
  c26_l_x = c26_k_x;
  c26_l_x = muDoubleScalarSin(c26_l_x);
  c26_C[0] = -0.0001 * c26_h_x * c26_b_qDot[1];
  c26_C[2] = -0.0001 * c26_j_x * (c26_b_qDot[0] + c26_b_qDot[1]);
  c26_C[1] = 0.0001 * c26_l_x * c26_b_qDot[0];
  c26_C[3] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 31);
  for (c26_i4 = 0; c26_i4 < 4; c26_i4++) {
    c26_D[c26_i4] = c26_dv0[c26_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 40);
  for (c26_i5 = 0; c26_i5 < 4; c26_i5++) {
    c26_Hp[c26_i5] = c26_dv1[c26_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 42);
  for (c26_i6 = 0; c26_i6 < 4; c26_i6++) {
    c26_Hd[c26_i6] = c26_dv2[c26_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 44);
  for (c26_i7 = 0; c26_i7 < 4; c26_i7++) {
    c26_Ki[c26_i7] = c26_dv3[c26_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 47);
  for (c26_i8 = 0; c26_i8 < 4; c26_i8++) {
    c26_Kp[c26_i8] = c26_dv4[c26_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 51);
  c26_Kd = 500.0;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 54);
  for (c26_i9 = 0; c26_i9 < 2; c26_i9++) {
    c26_c_qDot[c26_i9] = c26_b_qDot[c26_i9];
  }

  c26_d0 = c26_norm(chartInstance, c26_c_qDot);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c26_d0, 0.0, -1, 0U,
        c26_d0 == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 55);
    c26_kc = 0.0001;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 57);
    for (c26_i10 = 0; c26_i10 < 4; c26_i10++) {
      c26_b_C[c26_i10] = c26_C[c26_i10];
    }

    c26_A = 1.5 * c26_b_norm(chartInstance, c26_b_C);
    for (c26_i11 = 0; c26_i11 < 2; c26_i11++) {
      c26_d_qDot[c26_i11] = c26_b_qDot[c26_i11];
    }

    c26_B = c26_norm(chartInstance, c26_d_qDot);
    c26_kc = c26_rdivide(chartInstance, c26_A, c26_B);
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 60);
  for (c26_i12 = 0; c26_i12 < 4; c26_i12++) {
    c26_b_M[c26_i12] = c26_M[c26_i12];
  }

  c26_eig(chartInstance, c26_b_M, c26_dcv0);
  for (c26_i13 = 0; c26_i13 < 2; c26_i13++) {
    c26_lambdaM[c26_i13] = c26_dcv0[c26_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 61);
  for (c26_i14 = 0; c26_i14 < 2; c26_i14++) {
    c26_lambdaHp[c26_i14].re = 110.0;
    c26_lambdaHp[c26_i14].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 62);
  for (c26_i15 = 0; c26_i15 < 2; c26_i15++) {
    c26_lambdaHd[c26_i15].re = 1.5;
    c26_lambdaHd[c26_i15].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 63);
  for (c26_i16 = 0; c26_i16 < 2; c26_i16++) {
    c26_lambdaKi[c26_i16].re = 12.0;
    c26_lambdaKi[c26_i16].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 65);
  for (c26_i17 = 0; c26_i17 < 2; c26_i17++) {
    c26_varargin_1[c26_i17] = c26_lambdaM[c26_i17];
  }

  c26_ixstart = 1;
  c26_mtmp = c26_varargin_1[0];
  c26_b0 = muDoubleScalarIsNaN(c26_mtmp.re);
  c26_b1 = muDoubleScalarIsNaN(c26_mtmp.im);
  c26_b = (c26_b0 || c26_b1);
  if (c26_b) {
    c26_eml_switch_helper(chartInstance);
    c26_eml_switch_helper(chartInstance);
    c26_ix = 2;
    exitg5 = false;
    while ((exitg5 == false) && (c26_ix < 3)) {
      c26_b_ix = c26_ix;
      c26_ixstart = c26_b_ix;
      c26_m_x.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 2, 1, 0) - 1].re;
      c26_m_x.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 2, 1, 0) - 1].im;
      c26_b2 = muDoubleScalarIsNaN(c26_m_x.re);
      c26_b3 = muDoubleScalarIsNaN(c26_m_x.im);
      c26_b_b = (c26_b2 || c26_b3);
      if (!c26_b_b) {
        c26_mtmp.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 2, 1, 0) - 1].re;
        c26_mtmp.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 2, 1, 0) - 1].im;
        exitg5 = true;
      } else {
        c26_ix++;
      }
    }
  }

  if (c26_ixstart < 2) {
    c26_a = c26_ixstart;
    c26_b_a = c26_a + 1;
    c26_i18 = c26_b_a;
    c26_c_a = c26_i18;
    c26_d_a = c26_c_a;
    if (c26_d_a > 2) {
      c26_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_overflow = false;
    }

    if (c26_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_overflow);
    }

    for (c26_c_ix = c26_i18; c26_c_ix < 3; c26_c_ix++) {
      c26_b_ix = c26_c_ix;
      c26_b_varargin_1.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 2, 1, 0) - 1].re;
      c26_b_varargin_1.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 2, 1, 0) - 1].im;
      if (c26_eml_relop(chartInstance, c26_b_varargin_1, c26_mtmp)) {
        c26_mtmp.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 2, 1, 0) - 1].re;
        c26_mtmp.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 2, 1, 0) - 1].im;
      }
    }
  }

  c26_m_x.re = c26_dc0.re * c26_mtmp.re - c26_dc0.im * c26_mtmp.im;
  c26_m_x.im = c26_dc0.re * c26_mtmp.im + c26_dc0.im * c26_mtmp.re;
  c26_b_B = 2.0 * c26_kc;
  c26_y = c26_b_B;
  c26_b_y = c26_y;
  c26_c_y = c26_b_y;
  c26_ar = c26_m_x.re;
  c26_ai = c26_m_x.im;
  c26_br = c26_c_y;
  c26_bi = 0.0;
  if (c26_bi == 0.0) {
    if (c26_ai == 0.0) {
      c26_kq.re = c26_ar / c26_br;
      c26_kq.im = 0.0;
    } else if (c26_ar == 0.0) {
      c26_kq.re = 0.0;
      c26_kq.im = c26_ai / c26_br;
    } else {
      c26_kq.re = c26_ar / c26_br;
      c26_kq.im = c26_ai / c26_br;
    }
  } else if (c26_br == 0.0) {
    if (c26_ar == 0.0) {
      c26_kq.re = c26_ai / c26_bi;
      c26_kq.im = 0.0;
    } else if (c26_ai == 0.0) {
      c26_kq.re = 0.0;
      c26_kq.im = -(c26_ar / c26_bi);
    } else {
      c26_kq.re = c26_ai / c26_bi;
      c26_kq.im = -(c26_ar / c26_bi);
    }
  } else {
    c26_brm = muDoubleScalarAbs(c26_br);
    c26_bim = muDoubleScalarAbs(c26_bi);
    if (c26_brm > c26_bim) {
      c26_s = c26_bi / c26_br;
      c26_d = c26_br + c26_s * c26_bi;
      c26_nr = c26_ar + c26_s * c26_ai;
      c26_ni = c26_ai - c26_s * c26_ar;
      c26_kq.re = c26_nr / c26_d;
      c26_kq.im = c26_ni / c26_d;
    } else if (c26_bim == c26_brm) {
      if (c26_br > 0.0) {
        c26_sgnbr = 0.5;
      } else {
        c26_sgnbr = -0.5;
      }

      if (c26_bi > 0.0) {
        c26_sgnbi = 0.5;
      } else {
        c26_sgnbi = -0.5;
      }

      c26_nr = c26_ar * c26_sgnbr + c26_ai * c26_sgnbi;
      c26_ni = c26_ai * c26_sgnbr - c26_ar * c26_sgnbi;
      c26_kq.re = c26_nr / c26_brm;
      c26_kq.im = c26_ni / c26_brm;
    } else {
      c26_s = c26_br / c26_bi;
      c26_d = c26_bi + c26_s * c26_br;
      c26_nr = c26_s * c26_ar + c26_ai;
      c26_ni = c26_s * c26_ai - c26_ar;
      c26_kq.re = c26_nr / c26_d;
      c26_kq.im = c26_ni / c26_d;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 67);
  for (c26_i19 = 0; c26_i19 < 4; c26_i19++) {
    c26_zero[c26_i19] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 68);
  for (c26_i20 = 0; c26_i20 < 4; c26_i20++) {
    c26_one[c26_i20] = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 69);
  c26_i21 = 0;
  for (c26_i22 = 0; c26_i22 < 2; c26_i22++) {
    for (c26_i23 = 0; c26_i23 < 2; c26_i23++) {
      c26_L1[c26_i23 + c26_i21] = c26_dv5[c26_i23 + c26_i21];
    }

    c26_i21 += 2;
  }

  c26_i24 = 0;
  for (c26_i25 = 0; c26_i25 < 2; c26_i25++) {
    for (c26_i26 = 0; c26_i26 < 2; c26_i26++) {
      c26_L1[(c26_i26 + c26_i24) + 4] = c26_M[c26_i26 + c26_i24];
    }

    c26_i24 += 2;
  }

  c26_i27 = 0;
  for (c26_i28 = 0; c26_i28 < 2; c26_i28++) {
    for (c26_i29 = 0; c26_i29 < 2; c26_i29++) {
      c26_L1[(c26_i29 + c26_i27) + 8] = 0.0;
    }

    c26_i27 += 2;
  }

  c26_i30 = 0;
  for (c26_i31 = 0; c26_i31 < 2; c26_i31++) {
    for (c26_i32 = 0; c26_i32 < 2; c26_i32++) {
      c26_L1[(c26_i32 + c26_i30) + 12] = 0.0;
    }

    c26_i30 += 2;
  }

  c26_i33 = 0;
  for (c26_i34 = 0; c26_i34 < 2; c26_i34++) {
    for (c26_i35 = 0; c26_i35 < 2; c26_i35++) {
      c26_L1[(c26_i35 + c26_i33) + 16] = -1.0;
    }

    c26_i33 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 70);
  c26_i36 = 0;
  for (c26_i37 = 0; c26_i37 < 2; c26_i37++) {
    for (c26_i38 = 0; c26_i38 < 2; c26_i38++) {
      c26_L2[c26_i38 + c26_i36] = c26_M[c26_i38 + c26_i36];
    }

    c26_i36 += 2;
  }

  c26_i39 = 0;
  for (c26_i40 = 0; c26_i40 < 2; c26_i40++) {
    for (c26_i41 = 0; c26_i41 < 2; c26_i41++) {
      c26_L2[(c26_i41 + c26_i39) + 4] = c26_M[c26_i41 + c26_i39];
    }

    c26_i39 += 2;
  }

  c26_i42 = 0;
  for (c26_i43 = 0; c26_i43 < 2; c26_i43++) {
    for (c26_i44 = 0; c26_i44 < 2; c26_i44++) {
      c26_L2[(c26_i44 + c26_i42) + 8] = 0.0;
    }

    c26_i42 += 2;
  }

  c26_i45 = 0;
  for (c26_i46 = 0; c26_i46 < 2; c26_i46++) {
    for (c26_i47 = 0; c26_i47 < 2; c26_i47++) {
      c26_L2[(c26_i47 + c26_i45) + 12] = 0.0;
    }

    c26_i45 += 2;
  }

  c26_i48 = 0;
  for (c26_i49 = 0; c26_i49 < 2; c26_i49++) {
    for (c26_i50 = 0; c26_i50 < 2; c26_i50++) {
      c26_L2[(c26_i50 + c26_i48) + 16] = 0.0;
    }

    c26_i48 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 71);
  for (c26_i51 = 0; c26_i51 < 20; c26_i51++) {
    c26_L3[c26_i51] = c26_dv6[c26_i51];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 72);
  c26_i52 = 0;
  for (c26_i53 = 0; c26_i53 < 2; c26_i53++) {
    for (c26_i54 = 0; c26_i54 < 2; c26_i54++) {
      c26_L4[c26_i54 + c26_i52] = 0.0;
    }

    c26_i52 += 2;
  }

  c26_i55 = 0;
  for (c26_i56 = 0; c26_i56 < 2; c26_i56++) {
    for (c26_i57 = 0; c26_i57 < 2; c26_i57++) {
      c26_L4[(c26_i57 + c26_i55) + 4] = 0.0;
    }

    c26_i55 += 2;
  }

  c26_i58 = 0;
  for (c26_i59 = 0; c26_i59 < 2; c26_i59++) {
    for (c26_i60 = 0; c26_i60 < 2; c26_i60++) {
      c26_L4[(c26_i60 + c26_i58) + 8] = 0.0;
    }

    c26_i58 += 2;
  }

  c26_i61 = 0;
  for (c26_i62 = 0; c26_i62 < 2; c26_i62++) {
    for (c26_i63 = 0; c26_i63 < 2; c26_i63++) {
      c26_L4[(c26_i63 + c26_i61) + 12] = c26_M[c26_i63 + c26_i61];
    }

    c26_i61 += 2;
  }

  c26_i64 = 0;
  for (c26_i65 = 0; c26_i65 < 2; c26_i65++) {
    for (c26_i66 = 0; c26_i66 < 2; c26_i66++) {
      c26_L4[(c26_i66 + c26_i64) + 16] = 0.0;
    }

    c26_i64 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 73);
  for (c26_i67 = 0; c26_i67 < 4; c26_i67++) {
    c26_dv7[c26_i67] = c26_dv3[c26_i67];
  }

  c26_inv(chartInstance, c26_dv7, c26_dv8);
  c26_i68 = 0;
  for (c26_i69 = 0; c26_i69 < 2; c26_i69++) {
    for (c26_i70 = 0; c26_i70 < 2; c26_i70++) {
      c26_L5[c26_i70 + c26_i68] = -1.0;
    }

    c26_i68 += 2;
  }

  c26_i71 = 0;
  for (c26_i72 = 0; c26_i72 < 2; c26_i72++) {
    for (c26_i73 = 0; c26_i73 < 2; c26_i73++) {
      c26_L5[(c26_i73 + c26_i71) + 4] = 0.0;
    }

    c26_i71 += 2;
  }

  c26_i74 = 0;
  for (c26_i75 = 0; c26_i75 < 2; c26_i75++) {
    for (c26_i76 = 0; c26_i76 < 2; c26_i76++) {
      c26_L5[(c26_i76 + c26_i74) + 8] = 0.0;
    }

    c26_i74 += 2;
  }

  c26_i77 = 0;
  for (c26_i78 = 0; c26_i78 < 2; c26_i78++) {
    for (c26_i79 = 0; c26_i79 < 2; c26_i79++) {
      c26_L5[(c26_i79 + c26_i77) + 12] = 0.0;
    }

    c26_i77 += 2;
  }

  c26_i80 = 0;
  for (c26_i81 = 0; c26_i81 < 2; c26_i81++) {
    for (c26_i82 = 0; c26_i82 < 2; c26_i82++) {
      c26_L5[(c26_i82 + c26_i80) + 16] = c26_dv8[c26_i82 + c26_i80];
    }

    c26_i80 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 74);
  c26_i83 = 0;
  c26_i84 = 0;
  for (c26_i85 = 0; c26_i85 < 10; c26_i85++) {
    for (c26_i86 = 0; c26_i86 < 2; c26_i86++) {
      c26_L[c26_i86 + c26_i83] = c26_L1[c26_i86 + c26_i84];
    }

    c26_i83 += 10;
    c26_i84 += 2;
  }

  c26_i87 = 0;
  c26_i88 = 0;
  for (c26_i89 = 0; c26_i89 < 10; c26_i89++) {
    for (c26_i90 = 0; c26_i90 < 2; c26_i90++) {
      c26_L[(c26_i90 + c26_i87) + 2] = c26_L2[c26_i90 + c26_i88];
    }

    c26_i87 += 10;
    c26_i88 += 2;
  }

  c26_i91 = 0;
  c26_i92 = 0;
  for (c26_i93 = 0; c26_i93 < 10; c26_i93++) {
    for (c26_i94 = 0; c26_i94 < 2; c26_i94++) {
      c26_L[(c26_i94 + c26_i91) + 4] = c26_dv6[c26_i94 + c26_i92];
    }

    c26_i91 += 10;
    c26_i92 += 2;
  }

  c26_i95 = 0;
  c26_i96 = 0;
  for (c26_i97 = 0; c26_i97 < 10; c26_i97++) {
    for (c26_i98 = 0; c26_i98 < 2; c26_i98++) {
      c26_L[(c26_i98 + c26_i95) + 6] = c26_L4[c26_i98 + c26_i96];
    }

    c26_i95 += 10;
    c26_i96 += 2;
  }

  c26_i99 = 0;
  c26_i100 = 0;
  for (c26_i101 = 0; c26_i101 < 10; c26_i101++) {
    for (c26_i102 = 0; c26_i102 < 2; c26_i102++) {
      c26_L[(c26_i102 + c26_i99) + 8] = c26_L5[c26_i102 + c26_i100];
    }

    c26_i99 += 10;
    c26_i100 += 2;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 76);
  for (c26_i103 = 0; c26_i103 < 100; c26_i103++) {
    c26_b_L[c26_i103] = c26_L[c26_i103];
  }

  c26_b_eig(chartInstance, c26_b_L, c26_dcv1);
  for (c26_i104 = 0; c26_i104 < 10; c26_i104++) {
    c26_lambdaL[c26_i104] = c26_dcv1[c26_i104];
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 77);
  for (c26_i105 = 0; c26_i105 < 2; c26_i105++) {
    c26_lambdaD[c26_i105].re = 0.01;
    c26_lambdaD[c26_i105].im = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 79);
  c26_c_B = 2.0 * c26_kc;
  c26_d_y = c26_rdivide(chartInstance, 1.0, c26_c_B);
  for (c26_i106 = 0; c26_i106 < 10; c26_i106++) {
    c26_c_varargin_1[c26_i106] = c26_lambdaL[c26_i106];
  }

  c26_b_ixstart = 1;
  c26_mtmp = c26_c_varargin_1[0];
  c26_b4 = muDoubleScalarIsNaN(c26_mtmp.re);
  c26_b5 = muDoubleScalarIsNaN(c26_mtmp.im);
  c26_c_b = (c26_b4 || c26_b5);
  if (c26_c_b) {
    c26_eml_switch_helper(chartInstance);
    c26_eml_switch_helper(chartInstance);
    c26_d_ix = 2;
    exitg4 = false;
    while ((exitg4 == false) && (c26_d_ix < 11)) {
      c26_e_ix = c26_d_ix;
      c26_b_ixstart = c26_e_ix;
      c26_m_x.re = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_e_ix), 1, 10, 1, 0) - 1].re;
      c26_m_x.im = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_e_ix), 1, 10, 1, 0) - 1].im;
      c26_b6 = muDoubleScalarIsNaN(c26_m_x.re);
      c26_b7 = muDoubleScalarIsNaN(c26_m_x.im);
      c26_d_b = (c26_b6 || c26_b7);
      if (!c26_d_b) {
        c26_mtmp.re = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_e_ix), 1, 10, 1, 0) - 1].re;
        c26_mtmp.im = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_e_ix), 1, 10, 1, 0) - 1].im;
        exitg4 = true;
      } else {
        c26_d_ix++;
      }
    }
  }

  if (c26_b_ixstart < 10) {
    c26_e_a = c26_b_ixstart;
    c26_f_a = c26_e_a + 1;
    c26_i107 = c26_f_a;
    c26_g_a = c26_i107;
    c26_h_a = c26_g_a;
    if (c26_h_a > 10) {
      c26_b_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_b_overflow = false;
    }

    if (c26_b_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
    }

    for (c26_f_ix = c26_i107; c26_f_ix < 11; c26_f_ix++) {
      c26_e_ix = c26_f_ix;
      c26_d_varargin_1.re = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_ix), 1, 10, 1, 0) - 1].re;
      c26_d_varargin_1.im = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_ix), 1, 10, 1, 0) - 1].im;
      if (c26_eml_relop(chartInstance, c26_d_varargin_1, c26_mtmp)) {
        c26_mtmp.re = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_e_ix), 1, 10, 1, 0) - 1].re;
        c26_mtmp.im = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_e_ix), 1, 10, 1, 0) - 1].im;
      }
    }
  }

  for (c26_i108 = 0; c26_i108 < 10; c26_i108++) {
    c26_c_varargin_1[c26_i108] = c26_lambdaL[c26_i108];
  }

  c26_c_ixstart = 1;
  c26_b_mtmp = c26_c_varargin_1[0];
  c26_b8 = muDoubleScalarIsNaN(c26_b_mtmp.re);
  c26_b9 = muDoubleScalarIsNaN(c26_b_mtmp.im);
  c26_e_b = (c26_b8 || c26_b9);
  if (c26_e_b) {
    c26_eml_switch_helper(chartInstance);
    c26_eml_switch_helper(chartInstance);
    c26_g_ix = 2;
    exitg3 = false;
    while ((exitg3 == false) && (c26_g_ix < 11)) {
      c26_h_ix = c26_g_ix;
      c26_c_ixstart = c26_h_ix;
      c26_m_x.re = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_h_ix), 1, 10, 1, 0) - 1].re;
      c26_m_x.im = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_h_ix), 1, 10, 1, 0) - 1].im;
      c26_b10 = muDoubleScalarIsNaN(c26_m_x.re);
      c26_b11 = muDoubleScalarIsNaN(c26_m_x.im);
      c26_f_b = (c26_b10 || c26_b11);
      if (!c26_f_b) {
        c26_b_mtmp.re = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_h_ix), 1, 10, 1, 0) - 1].
          re;
        c26_b_mtmp.im = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_h_ix), 1, 10, 1, 0) - 1].
          im;
        exitg3 = true;
      } else {
        c26_g_ix++;
      }
    }
  }

  if (c26_c_ixstart < 10) {
    c26_i_a = c26_c_ixstart;
    c26_j_a = c26_i_a + 1;
    c26_i109 = c26_j_a;
    c26_k_a = c26_i109;
    c26_l_a = c26_k_a;
    if (c26_l_a > 10) {
      c26_c_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_c_overflow = false;
    }

    if (c26_c_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_c_overflow);
    }

    for (c26_i_ix = c26_i109; c26_i_ix < 11; c26_i_ix++) {
      c26_h_ix = c26_i_ix;
      c26_e_varargin_1.re = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_h_ix), 1, 10, 1, 0) - 1].re;
      c26_e_varargin_1.im = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_h_ix), 1, 10, 1, 0) - 1].im;
      if (c26_b_eml_relop(chartInstance, c26_e_varargin_1, c26_b_mtmp)) {
        c26_b_mtmp.re = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_h_ix), 1, 10, 1, 0) - 1].
          re;
        c26_b_mtmp.im = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_h_ix), 1, 10, 1, 0) - 1].
          im;
      }
    }
  }

  c26_b_ar = c26_mtmp.re;
  c26_b_ai = c26_mtmp.im;
  c26_b_br = c26_b_mtmp.re;
  c26_b_bi = c26_b_mtmp.im;
  if (c26_b_bi == 0.0) {
    if (c26_b_ai == 0.0) {
      c26_e_y.re = c26_b_ar / c26_b_br;
      c26_e_y.im = 0.0;
    } else if (c26_b_ar == 0.0) {
      c26_e_y.re = 0.0;
      c26_e_y.im = c26_b_ai / c26_b_br;
    } else {
      c26_e_y.re = c26_b_ar / c26_b_br;
      c26_e_y.im = c26_b_ai / c26_b_br;
    }
  } else if (c26_b_br == 0.0) {
    if (c26_b_ar == 0.0) {
      c26_e_y.re = c26_b_ai / c26_b_bi;
      c26_e_y.im = 0.0;
    } else if (c26_b_ai == 0.0) {
      c26_e_y.re = 0.0;
      c26_e_y.im = -(c26_b_ar / c26_b_bi);
    } else {
      c26_e_y.re = c26_b_ai / c26_b_bi;
      c26_e_y.im = -(c26_b_ar / c26_b_bi);
    }
  } else {
    c26_b_brm = muDoubleScalarAbs(c26_b_br);
    c26_b_bim = muDoubleScalarAbs(c26_b_bi);
    if (c26_b_brm > c26_b_bim) {
      c26_b_s = c26_b_bi / c26_b_br;
      c26_b_d = c26_b_br + c26_b_s * c26_b_bi;
      c26_b_nr = c26_b_ar + c26_b_s * c26_b_ai;
      c26_b_ni = c26_b_ai - c26_b_s * c26_b_ar;
      c26_e_y.re = c26_b_nr / c26_b_d;
      c26_e_y.im = c26_b_ni / c26_b_d;
    } else if (c26_b_bim == c26_b_brm) {
      if (c26_b_br > 0.0) {
        c26_b_sgnbr = 0.5;
      } else {
        c26_b_sgnbr = -0.5;
      }

      if (c26_b_bi > 0.0) {
        c26_b_sgnbi = 0.5;
      } else {
        c26_b_sgnbi = -0.5;
      }

      c26_b_nr = c26_b_ar * c26_b_sgnbr + c26_b_ai * c26_b_sgnbi;
      c26_b_ni = c26_b_ai * c26_b_sgnbr - c26_b_ar * c26_b_sgnbi;
      c26_e_y.re = c26_b_nr / c26_b_brm;
      c26_e_y.im = c26_b_ni / c26_b_brm;
    } else {
      c26_b_s = c26_b_br / c26_b_bi;
      c26_b_d = c26_b_bi + c26_b_s * c26_b_br;
      c26_b_nr = c26_b_s * c26_b_ar + c26_b_ai;
      c26_b_ni = c26_b_s * c26_b_ai - c26_b_ar;
      c26_e_y.re = c26_b_nr / c26_b_d;
      c26_e_y.im = c26_b_ni / c26_b_d;
    }
  }

  c26_m_a = c26_d_y;
  c26_d_sqrt(chartInstance, &c26_e_y);
  c26_e_y.re *= c26_m_a;
  c26_e_y.im *= c26_m_a;
  for (c26_i110 = 0; c26_i110 < 2; c26_i110++) {
    c26_varargin_1[c26_i110] = c26_lambdaM[c26_i110];
  }

  c26_d_ixstart = 1;
  c26_mtmp = c26_varargin_1[0];
  c26_b12 = muDoubleScalarIsNaN(c26_mtmp.re);
  c26_b13 = muDoubleScalarIsNaN(c26_mtmp.im);
  c26_g_b = (c26_b12 || c26_b13);
  if (c26_g_b) {
    c26_eml_switch_helper(chartInstance);
    c26_eml_switch_helper(chartInstance);
    c26_j_ix = 2;
    exitg2 = false;
    while ((exitg2 == false) && (c26_j_ix < 3)) {
      c26_k_ix = c26_j_ix;
      c26_d_ixstart = c26_k_ix;
      c26_m_x.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_k_ix), 1, 2, 1, 0) - 1].re;
      c26_m_x.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_k_ix), 1, 2, 1, 0) - 1].im;
      c26_b14 = muDoubleScalarIsNaN(c26_m_x.re);
      c26_b15 = muDoubleScalarIsNaN(c26_m_x.im);
      c26_h_b = (c26_b14 || c26_b15);
      if (!c26_h_b) {
        c26_mtmp.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_k_ix), 1, 2, 1, 0) - 1].re;
        c26_mtmp.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_k_ix), 1, 2, 1, 0) - 1].im;
        exitg2 = true;
      } else {
        c26_j_ix++;
      }
    }
  }

  if (c26_d_ixstart < 2) {
    c26_n_a = c26_d_ixstart;
    c26_o_a = c26_n_a + 1;
    c26_i111 = c26_o_a;
    c26_p_a = c26_i111;
    c26_q_a = c26_p_a;
    if (c26_q_a > 2) {
      c26_d_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_d_overflow = false;
    }

    if (c26_d_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_d_overflow);
    }

    for (c26_l_ix = c26_i111; c26_l_ix < 3; c26_l_ix++) {
      c26_k_ix = c26_l_ix;
      c26_f_varargin_1.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_k_ix), 1, 2, 1, 0) - 1].re;
      c26_f_varargin_1.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_k_ix), 1, 2, 1, 0) - 1].im;
      if (c26_eml_relop(chartInstance, c26_f_varargin_1, c26_mtmp)) {
        c26_mtmp.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_k_ix), 1, 2, 1, 0) - 1].re;
        c26_mtmp.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_k_ix), 1, 2, 1, 0) - 1].im;
      }
    }
  }

  c26_f_y.re = 500.0 * c26_mtmp.re;
  c26_f_y.im = 500.0 * c26_mtmp.im;
  c26_mtmp = c26_dc1;
  c26_eml_switch_helper(chartInstance);
  c26_eml_switch_helper(chartInstance);
  for (c26_m_ix = 2; c26_m_ix < 3; c26_m_ix++) {
    c26_n_ix = c26_m_ix;
    c26_o_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c26_n_ix), 1, 2, 1, 0) - 1;
    c26_dc2.re = 0.01;
    c26_dc2.im = 0.0;
    if (c26_eml_relop(chartInstance, c26_dc2, c26_mtmp)) {
      c26_p_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c26_n_ix), 1, 2, 1, 0) - 1;
      c26_mtmp.re = 0.01;
      c26_mtmp.im = 0.0;
    }
  }

  c26_b_mtmp = c26_dc1;
  c26_eml_switch_helper(chartInstance);
  c26_eml_switch_helper(chartInstance);
  for (c26_q_ix = 2; c26_q_ix < 3; c26_q_ix++) {
    c26_r_ix = c26_q_ix;
    c26_s_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c26_r_ix), 1, 2, 1, 0) - 1;
    c26_dc3.re = 0.01;
    c26_dc3.im = 0.0;
    if (c26_eml_relop(chartInstance, c26_dc3, c26_b_mtmp)) {
      c26_t_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c26_r_ix), 1, 2, 1, 0) - 1;
      c26_b_mtmp.re = 0.01;
      c26_b_mtmp.im = 0.0;
    }
  }

  c26_c_mtmp = c26_dc0;
  c26_eml_switch_helper(chartInstance);
  c26_eml_switch_helper(chartInstance);
  for (c26_u_ix = 2; c26_u_ix < 3; c26_u_ix++) {
    c26_v_ix = c26_u_ix;
    c26_w_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c26_v_ix), 1, 2, 1, 0) - 1;
    c26_dc4.re = 1.5;
    c26_dc4.im = 0.0;
    if (c26_eml_relop(chartInstance, c26_dc4, c26_c_mtmp)) {
      c26_x_ix = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c26_v_ix), 1, 2, 1, 0) - 1;
      c26_c_mtmp.re = 1.5;
      c26_c_mtmp.im = 0.0;
    }
  }

  for (c26_i112 = 0; c26_i112 < 2; c26_i112++) {
    c26_varargin_1[c26_i112] = c26_lambdaM[c26_i112];
  }

  c26_e_ixstart = 1;
  c26_d_mtmp = c26_varargin_1[0];
  c26_b16 = muDoubleScalarIsNaN(c26_d_mtmp.re);
  c26_b17 = muDoubleScalarIsNaN(c26_d_mtmp.im);
  c26_i_b = (c26_b16 || c26_b17);
  if (c26_i_b) {
    c26_eml_switch_helper(chartInstance);
    c26_eml_switch_helper(chartInstance);
    c26_y_ix = 2;
    exitg1 = false;
    while ((exitg1 == false) && (c26_y_ix < 3)) {
      c26_ab_ix = c26_y_ix;
      c26_e_ixstart = c26_ab_ix;
      c26_m_x.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_ab_ix), 1, 2, 1, 0) - 1].re;
      c26_m_x.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_ab_ix), 1, 2, 1, 0) - 1].im;
      c26_b18 = muDoubleScalarIsNaN(c26_m_x.re);
      c26_b19 = muDoubleScalarIsNaN(c26_m_x.im);
      c26_j_b = (c26_b18 || c26_b19);
      if (!c26_j_b) {
        c26_d_mtmp.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_ab_ix), 1, 2, 1, 0) - 1].re;
        c26_d_mtmp.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_ab_ix), 1, 2, 1, 0) - 1].im;
        exitg1 = true;
      } else {
        c26_y_ix++;
      }
    }
  }

  if (c26_e_ixstart < 2) {
    c26_r_a = c26_e_ixstart;
    c26_s_a = c26_r_a + 1;
    c26_i113 = c26_s_a;
    c26_t_a = c26_i113;
    c26_u_a = c26_t_a;
    if (c26_u_a > 2) {
      c26_e_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_e_overflow = false;
    }

    if (c26_e_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_e_overflow);
    }

    for (c26_bb_ix = c26_i113; c26_bb_ix < 3; c26_bb_ix++) {
      c26_ab_ix = c26_bb_ix;
      c26_g_varargin_1.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ab_ix), 1, 2, 1, 0) - 1].re;
      c26_g_varargin_1.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ab_ix), 1, 2, 1, 0) - 1].im;
      if (c26_eml_relop(chartInstance, c26_g_varargin_1, c26_d_mtmp)) {
        c26_d_mtmp.re = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_ab_ix), 1, 2, 1, 0) - 1].re;
        c26_d_mtmp.im = c26_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_ab_ix), 1, 2, 1, 0) - 1].im;
      }
    }
  }

  c26_m_x.re = ((c26_b_mtmp.re + c26_c_mtmp.re) - c26_d_mtmp.re) - c26_kc *
    c26_b_FcTilde;
  c26_m_x.im = (c26_b_mtmp.im + c26_c_mtmp.im) - c26_d_mtmp.im;
  c26_n_x = c26_m_x;
  c26_c_ar = c26_dc5.re;
  c26_c_ai = c26_dc5.im;
  c26_c_br = c26_n_x.re;
  c26_c_bi = c26_n_x.im;
  if (c26_c_bi == 0.0) {
    if (c26_c_ai == 0.0) {
      c26_m_x.re = c26_c_ar / c26_c_br;
      c26_m_x.im = 0.0;
    } else if (c26_c_ar == 0.0) {
      c26_m_x.re = 0.0;
      c26_m_x.im = c26_c_ai / c26_c_br;
    } else {
      c26_m_x.re = c26_c_ar / c26_c_br;
      c26_m_x.im = c26_c_ai / c26_c_br;
    }
  } else if (c26_c_br == 0.0) {
    if (c26_c_ar == 0.0) {
      c26_m_x.re = c26_c_ai / c26_c_bi;
      c26_m_x.im = 0.0;
    } else if (c26_c_ai == 0.0) {
      c26_m_x.re = 0.0;
      c26_m_x.im = -(c26_c_ar / c26_c_bi);
    } else {
      c26_m_x.re = c26_c_ai / c26_c_bi;
      c26_m_x.im = -(c26_c_ar / c26_c_bi);
    }
  } else {
    c26_c_brm = muDoubleScalarAbs(c26_c_br);
    c26_c_bim = muDoubleScalarAbs(c26_c_bi);
    if (c26_c_brm > c26_c_bim) {
      c26_c_s = c26_c_bi / c26_c_br;
      c26_c_d = c26_c_br + c26_c_s * c26_c_bi;
      c26_c_nr = c26_c_ar + c26_c_s * c26_c_ai;
      c26_c_ni = c26_c_ai - c26_c_s * c26_c_ar;
      c26_m_x.re = c26_c_nr / c26_c_d;
      c26_m_x.im = c26_c_ni / c26_c_d;
    } else if (c26_c_bim == c26_c_brm) {
      if (c26_c_br > 0.0) {
        c26_c_sgnbr = 0.5;
      } else {
        c26_c_sgnbr = -0.5;
      }

      if (c26_c_bi > 0.0) {
        c26_c_sgnbi = 0.5;
      } else {
        c26_c_sgnbi = -0.5;
      }

      c26_c_nr = c26_c_ar * c26_c_sgnbr + c26_c_ai * c26_c_sgnbi;
      c26_c_ni = c26_c_ai * c26_c_sgnbr - c26_c_ar * c26_c_sgnbi;
      c26_m_x.re = c26_c_nr / c26_c_brm;
      c26_m_x.im = c26_c_ni / c26_c_brm;
    } else {
      c26_c_s = c26_c_br / c26_c_bi;
      c26_c_d = c26_c_bi + c26_c_s * c26_c_br;
      c26_c_nr = c26_c_s * c26_c_ar + c26_c_ai;
      c26_c_ni = c26_c_s * c26_c_ai - c26_c_ar;
      c26_m_x.re = c26_c_nr / c26_c_d;
      c26_m_x.im = c26_c_ni / c26_c_d;
    }
  }

  c26_d_ar = c26_dc5.re;
  c26_d_ai = c26_dc5.im;
  c26_d_br = c26_dc6.re;
  c26_d_bi = c26_dc6.im;
  if (c26_d_bi == 0.0) {
    if (c26_d_ai == 0.0) {
      c26_b_mtmp.re = c26_d_ar / c26_d_br;
      c26_b_mtmp.im = 0.0;
    } else if (c26_d_ar == 0.0) {
      c26_b_mtmp.re = 0.0;
      c26_b_mtmp.im = c26_d_ai / c26_d_br;
    } else {
      c26_b_mtmp.re = c26_d_ar / c26_d_br;
      c26_b_mtmp.im = c26_d_ai / c26_d_br;
    }
  } else if (c26_d_br == 0.0) {
    if (c26_d_ar == 0.0) {
      c26_b_mtmp.re = c26_d_ai / c26_d_bi;
      c26_b_mtmp.im = 0.0;
    } else if (c26_d_ai == 0.0) {
      c26_b_mtmp.re = 0.0;
      c26_b_mtmp.im = -(c26_d_ar / c26_d_bi);
    } else {
      c26_b_mtmp.re = c26_d_ai / c26_d_bi;
      c26_b_mtmp.im = -(c26_d_ar / c26_d_bi);
    }
  } else {
    c26_d_brm = muDoubleScalarAbs(c26_d_br);
    c26_d_bim = muDoubleScalarAbs(c26_d_bi);
    if (c26_d_brm > c26_d_bim) {
      c26_d_s = c26_d_bi / c26_d_br;
      c26_d_d = c26_d_br + c26_d_s * c26_d_bi;
      c26_d_nr = c26_d_ar + c26_d_s * c26_d_ai;
      c26_d_ni = c26_d_ai - c26_d_s * c26_d_ar;
      c26_b_mtmp.re = c26_d_nr / c26_d_d;
      c26_b_mtmp.im = c26_d_ni / c26_d_d;
    } else if (c26_d_bim == c26_d_brm) {
      if (c26_d_br > 0.0) {
        c26_d_sgnbr = 0.5;
      } else {
        c26_d_sgnbr = -0.5;
      }

      if (c26_d_bi > 0.0) {
        c26_d_sgnbi = 0.5;
      } else {
        c26_d_sgnbi = -0.5;
      }

      c26_d_nr = c26_d_ar * c26_d_sgnbr + c26_d_ai * c26_d_sgnbi;
      c26_d_ni = c26_d_ai * c26_d_sgnbr - c26_d_ar * c26_d_sgnbi;
      c26_b_mtmp.re = c26_d_nr / c26_d_brm;
      c26_b_mtmp.im = c26_d_ni / c26_d_brm;
    } else {
      c26_d_s = c26_d_br / c26_d_bi;
      c26_d_d = c26_d_bi + c26_d_s * c26_d_br;
      c26_d_nr = c26_d_s * c26_d_ar + c26_d_ai;
      c26_d_ni = c26_d_s * c26_d_ai - c26_d_ar;
      c26_b_mtmp.re = c26_d_nr / c26_d_d;
      c26_b_mtmp.im = c26_d_ni / c26_d_d;
    }
  }

  c26_o_x.re = c26_m_x.re + c26_b_mtmp.re;
  c26_o_x.im = c26_m_x.im + c26_b_mtmp.im;
  c26_dc8.re = c26_dc7.re * c26_o_x.re - c26_dc7.im * c26_o_x.im;
  c26_dc8.im = c26_dc7.re * c26_o_x.im + c26_dc7.im * c26_o_x.re;
  c26_g_y.re = (c26_f_y.re + c26_mtmp.re) - c26_dc8.re;
  c26_g_y.im = (c26_f_y.im + c26_mtmp.im) - c26_dc8.im;
  c26_b_rCFC.re = c26_e_y.re * c26_g_y.re - c26_e_y.im * c26_g_y.im;
  c26_b_rCFC.im = c26_e_y.re * c26_g_y.im + c26_e_y.im * c26_g_y.re;
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, -79);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c26_rCFC = c26_b_rCFC;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c26_sfEvent);
}

static void initSimStructsc26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber, uint32_T c26_instanceNumber)
{
  (void)c26_machineNumber;
  (void)c26_chartNumber;
  (void)c26_instanceNumber;
}

static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  creal_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(creal_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 0, 1U, 0U, 0U, 0), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static creal_T c26_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_b_rCFC, const char_T *c26_identifier)
{
  creal_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_rCFC),
    &c26_thisId);
  sf_mex_destroy(&c26_b_rCFC);
  return c26_y;
}

static creal_T c26_b_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  creal_T c26_y;
  creal_T c26_dc9;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_dc9, 1, 0, 1U, 0, 0U, 0);
  c26_y = c26_dc9;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_rCFC;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  creal_T c26_y;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_b_rCFC = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_rCFC),
    &c26_thisId);
  sf_mex_destroy(&c26_b_rCFC);
  *(creal_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  real_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(real_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i114;
  real_T c26_b_inData[2];
  int32_T c26_i115;
  real_T c26_u[2];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i114 = 0; c26_i114 < 2; c26_i114++) {
    c26_b_inData[c26_i114] = (*(real_T (*)[2])c26_inData)[c26_i114];
  }

  for (c26_i115 = 0; c26_i115 < 2; c26_i115++) {
    c26_u[c26_i115] = c26_b_inData[c26_i115];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i116;
  real_T c26_b_inData[2];
  int32_T c26_i117;
  real_T c26_u[2];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i116 = 0; c26_i116 < 2; c26_i116++) {
    c26_b_inData[c26_i116] = (*(real_T (*)[2])c26_inData)[c26_i116];
  }

  for (c26_i117 = 0; c26_i117 < 2; c26_i117++) {
    c26_u[c26_i117] = c26_b_inData[c26_i117];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static real_T c26_c_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  real_T c26_y;
  real_T c26_d1;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_d1, 1, 0, 0U, 0, 0U, 0);
  c26_y = c26_d1;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_nargout;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_nargout = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_nargout),
    &c26_thisId);
  sf_mex_destroy(&c26_nargout);
  *(real_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_e_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i118;
  creal_T c26_b_inData[2];
  int32_T c26_i119;
  creal_T c26_u[2];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i118 = 0; c26_i118 < 2; c26_i118++) {
    c26_b_inData[c26_i118] = (*(creal_T (*)[2])c26_inData)[c26_i118];
  }

  for (c26_i119 = 0; c26_i119 < 2; c26_i119++) {
    c26_u[c26_i119] = c26_b_inData[c26_i119];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 1U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static const mxArray *c26_f_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i120;
  creal_T c26_b_inData[10];
  int32_T c26_i121;
  creal_T c26_u[10];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i120 = 0; c26_i120 < 10; c26_i120++) {
    c26_b_inData[c26_i120] = (*(creal_T (*)[10])c26_inData)[c26_i120];
  }

  for (c26_i121 = 0; c26_i121 < 10; c26_i121++) {
    c26_u[c26_i121] = c26_b_inData[c26_i121];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 1U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static void c26_d_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  creal_T c26_y[10])
{
  creal_T c26_dcv2[10];
  int32_T c26_i122;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dcv2, 1, 0, 1U, 1, 0U, 1,
                10);
  for (c26_i122 = 0; c26_i122 < 10; c26_i122++) {
    c26_y[c26_i122] = c26_dcv2[c26_i122];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_lambdaL;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  creal_T c26_y[10];
  int32_T c26_i123;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_lambdaL = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_lambdaL), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_lambdaL);
  for (c26_i123 = 0; c26_i123 < 10; c26_i123++) {
    (*(creal_T (*)[10])c26_outData)[c26_i123] = c26_y[c26_i123];
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_g_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i124;
  int32_T c26_i125;
  int32_T c26_i126;
  real_T c26_b_inData[100];
  int32_T c26_i127;
  int32_T c26_i128;
  int32_T c26_i129;
  real_T c26_u[100];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_i124 = 0;
  for (c26_i125 = 0; c26_i125 < 10; c26_i125++) {
    for (c26_i126 = 0; c26_i126 < 10; c26_i126++) {
      c26_b_inData[c26_i126 + c26_i124] = (*(real_T (*)[100])c26_inData)
        [c26_i126 + c26_i124];
    }

    c26_i124 += 10;
  }

  c26_i127 = 0;
  for (c26_i128 = 0; c26_i128 < 10; c26_i128++) {
    for (c26_i129 = 0; c26_i129 < 10; c26_i129++) {
      c26_u[c26_i129 + c26_i127] = c26_b_inData[c26_i129 + c26_i127];
    }

    c26_i127 += 10;
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 2, 10, 10),
                false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static void c26_e_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[100])
{
  real_T c26_dv9[100];
  int32_T c26_i130;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv9, 1, 0, 0U, 1, 0U, 2, 10,
                10);
  for (c26_i130 = 0; c26_i130 < 100; c26_i130++) {
    c26_y[c26_i130] = c26_dv9[c26_i130];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_L;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y[100];
  int32_T c26_i131;
  int32_T c26_i132;
  int32_T c26_i133;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_L = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_L), &c26_thisId, c26_y);
  sf_mex_destroy(&c26_L);
  c26_i131 = 0;
  for (c26_i132 = 0; c26_i132 < 10; c26_i132++) {
    for (c26_i133 = 0; c26_i133 < 10; c26_i133++) {
      (*(real_T (*)[100])c26_outData)[c26_i133 + c26_i131] = c26_y[c26_i133 +
        c26_i131];
    }

    c26_i131 += 10;
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_h_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i134;
  int32_T c26_i135;
  int32_T c26_i136;
  real_T c26_b_inData[20];
  int32_T c26_i137;
  int32_T c26_i138;
  int32_T c26_i139;
  real_T c26_u[20];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_i134 = 0;
  for (c26_i135 = 0; c26_i135 < 10; c26_i135++) {
    for (c26_i136 = 0; c26_i136 < 2; c26_i136++) {
      c26_b_inData[c26_i136 + c26_i134] = (*(real_T (*)[20])c26_inData)[c26_i136
        + c26_i134];
    }

    c26_i134 += 2;
  }

  c26_i137 = 0;
  for (c26_i138 = 0; c26_i138 < 10; c26_i138++) {
    for (c26_i139 = 0; c26_i139 < 2; c26_i139++) {
      c26_u[c26_i139 + c26_i137] = c26_b_inData[c26_i139 + c26_i137];
    }

    c26_i137 += 2;
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 2, 2, 10),
                false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static void c26_f_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[20])
{
  real_T c26_dv10[20];
  int32_T c26_i140;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv10, 1, 0, 0U, 1, 0U, 2, 2,
                10);
  for (c26_i140 = 0; c26_i140 < 20; c26_i140++) {
    c26_y[c26_i140] = c26_dv10[c26_i140];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_L5;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y[20];
  int32_T c26_i141;
  int32_T c26_i142;
  int32_T c26_i143;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_L5 = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_L5), &c26_thisId, c26_y);
  sf_mex_destroy(&c26_L5);
  c26_i141 = 0;
  for (c26_i142 = 0; c26_i142 < 10; c26_i142++) {
    for (c26_i143 = 0; c26_i143 < 2; c26_i143++) {
      (*(real_T (*)[20])c26_outData)[c26_i143 + c26_i141] = c26_y[c26_i143 +
        c26_i141];
    }

    c26_i141 += 2;
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_i_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i144;
  int32_T c26_i145;
  int32_T c26_i146;
  real_T c26_b_inData[4];
  int32_T c26_i147;
  int32_T c26_i148;
  int32_T c26_i149;
  real_T c26_u[4];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_i144 = 0;
  for (c26_i145 = 0; c26_i145 < 2; c26_i145++) {
    for (c26_i146 = 0; c26_i146 < 2; c26_i146++) {
      c26_b_inData[c26_i146 + c26_i144] = (*(real_T (*)[4])c26_inData)[c26_i146
        + c26_i144];
    }

    c26_i144 += 2;
  }

  c26_i147 = 0;
  for (c26_i148 = 0; c26_i148 < 2; c26_i148++) {
    for (c26_i149 = 0; c26_i149 < 2; c26_i149++) {
      c26_u[c26_i149 + c26_i147] = c26_b_inData[c26_i149 + c26_i147];
    }

    c26_i147 += 2;
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static void c26_g_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  creal_T c26_y[2])
{
  creal_T c26_dcv3[2];
  int32_T c26_i150;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dcv3, 1, 0, 1U, 1, 0U, 1, 2);
  for (c26_i150 = 0; c26_i150 < 2; c26_i150++) {
    c26_y[c26_i150] = c26_dcv3[c26_i150];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_lambdaM;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  creal_T c26_y[2];
  int32_T c26_i151;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_lambdaM = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_lambdaM), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_lambdaM);
  for (c26_i151 = 0; c26_i151 < 2; c26_i151++) {
    (*(creal_T (*)[2])c26_outData)[c26_i151] = c26_y[c26_i151];
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

static void c26_h_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[4])
{
  real_T c26_dv11[4];
  int32_T c26_i152;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv11, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c26_i152 = 0; c26_i152 < 4; c26_i152++) {
    c26_y[c26_i152] = c26_dv11[c26_i152];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_C;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y[4];
  int32_T c26_i153;
  int32_T c26_i154;
  int32_T c26_i155;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_C = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_C), &c26_thisId, c26_y);
  sf_mex_destroy(&c26_C);
  c26_i153 = 0;
  for (c26_i154 = 0; c26_i154 < 2; c26_i154++) {
    for (c26_i155 = 0; c26_i155 < 2; c26_i155++) {
      (*(real_T (*)[4])c26_outData)[c26_i155 + c26_i153] = c26_y[c26_i155 +
        c26_i153];
    }

    c26_i153 += 2;
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

const mxArray *sf_c26_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c26_nameCaptureInfo = NULL;
  c26_nameCaptureInfo = NULL;
  sf_mex_assign(&c26_nameCaptureInfo, sf_mex_createstruct("structure", 2, 319, 1),
                false);
  c26_info_helper(&c26_nameCaptureInfo);
  c26_b_info_helper(&c26_nameCaptureInfo);
  c26_c_info_helper(&c26_nameCaptureInfo);
  c26_d_info_helper(&c26_nameCaptureInfo);
  c26_e_info_helper(&c26_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c26_nameCaptureInfo);
  return c26_nameCaptureInfo;
}

static void c26_info_helper(const mxArray **c26_info)
{
  const mxArray *c26_rhs0 = NULL;
  const mxArray *c26_lhs0 = NULL;
  const mxArray *c26_rhs1 = NULL;
  const mxArray *c26_lhs1 = NULL;
  const mxArray *c26_rhs2 = NULL;
  const mxArray *c26_lhs2 = NULL;
  const mxArray *c26_rhs3 = NULL;
  const mxArray *c26_lhs3 = NULL;
  const mxArray *c26_rhs4 = NULL;
  const mxArray *c26_lhs4 = NULL;
  const mxArray *c26_rhs5 = NULL;
  const mxArray *c26_lhs5 = NULL;
  const mxArray *c26_rhs6 = NULL;
  const mxArray *c26_lhs6 = NULL;
  const mxArray *c26_rhs7 = NULL;
  const mxArray *c26_lhs7 = NULL;
  const mxArray *c26_rhs8 = NULL;
  const mxArray *c26_lhs8 = NULL;
  const mxArray *c26_rhs9 = NULL;
  const mxArray *c26_lhs9 = NULL;
  const mxArray *c26_rhs10 = NULL;
  const mxArray *c26_lhs10 = NULL;
  const mxArray *c26_rhs11 = NULL;
  const mxArray *c26_lhs11 = NULL;
  const mxArray *c26_rhs12 = NULL;
  const mxArray *c26_lhs12 = NULL;
  const mxArray *c26_rhs13 = NULL;
  const mxArray *c26_lhs13 = NULL;
  const mxArray *c26_rhs14 = NULL;
  const mxArray *c26_lhs14 = NULL;
  const mxArray *c26_rhs15 = NULL;
  const mxArray *c26_lhs15 = NULL;
  const mxArray *c26_rhs16 = NULL;
  const mxArray *c26_lhs16 = NULL;
  const mxArray *c26_rhs17 = NULL;
  const mxArray *c26_lhs17 = NULL;
  const mxArray *c26_rhs18 = NULL;
  const mxArray *c26_lhs18 = NULL;
  const mxArray *c26_rhs19 = NULL;
  const mxArray *c26_lhs19 = NULL;
  const mxArray *c26_rhs20 = NULL;
  const mxArray *c26_lhs20 = NULL;
  const mxArray *c26_rhs21 = NULL;
  const mxArray *c26_lhs21 = NULL;
  const mxArray *c26_rhs22 = NULL;
  const mxArray *c26_lhs22 = NULL;
  const mxArray *c26_rhs23 = NULL;
  const mxArray *c26_lhs23 = NULL;
  const mxArray *c26_rhs24 = NULL;
  const mxArray *c26_lhs24 = NULL;
  const mxArray *c26_rhs25 = NULL;
  const mxArray *c26_lhs25 = NULL;
  const mxArray *c26_rhs26 = NULL;
  const mxArray *c26_lhs26 = NULL;
  const mxArray *c26_rhs27 = NULL;
  const mxArray *c26_lhs27 = NULL;
  const mxArray *c26_rhs28 = NULL;
  const mxArray *c26_lhs28 = NULL;
  const mxArray *c26_rhs29 = NULL;
  const mxArray *c26_lhs29 = NULL;
  const mxArray *c26_rhs30 = NULL;
  const mxArray *c26_lhs30 = NULL;
  const mxArray *c26_rhs31 = NULL;
  const mxArray *c26_lhs31 = NULL;
  const mxArray *c26_rhs32 = NULL;
  const mxArray *c26_lhs32 = NULL;
  const mxArray *c26_rhs33 = NULL;
  const mxArray *c26_lhs33 = NULL;
  const mxArray *c26_rhs34 = NULL;
  const mxArray *c26_lhs34 = NULL;
  const mxArray *c26_rhs35 = NULL;
  const mxArray *c26_lhs35 = NULL;
  const mxArray *c26_rhs36 = NULL;
  const mxArray *c26_lhs36 = NULL;
  const mxArray *c26_rhs37 = NULL;
  const mxArray *c26_lhs37 = NULL;
  const mxArray *c26_rhs38 = NULL;
  const mxArray *c26_lhs38 = NULL;
  const mxArray *c26_rhs39 = NULL;
  const mxArray *c26_lhs39 = NULL;
  const mxArray *c26_rhs40 = NULL;
  const mxArray *c26_lhs40 = NULL;
  const mxArray *c26_rhs41 = NULL;
  const mxArray *c26_lhs41 = NULL;
  const mxArray *c26_rhs42 = NULL;
  const mxArray *c26_lhs42 = NULL;
  const mxArray *c26_rhs43 = NULL;
  const mxArray *c26_lhs43 = NULL;
  const mxArray *c26_rhs44 = NULL;
  const mxArray *c26_lhs44 = NULL;
  const mxArray *c26_rhs45 = NULL;
  const mxArray *c26_lhs45 = NULL;
  const mxArray *c26_rhs46 = NULL;
  const mxArray *c26_lhs46 = NULL;
  const mxArray *c26_rhs47 = NULL;
  const mxArray *c26_lhs47 = NULL;
  const mxArray *c26_rhs48 = NULL;
  const mxArray *c26_lhs48 = NULL;
  const mxArray *c26_rhs49 = NULL;
  const mxArray *c26_lhs49 = NULL;
  const mxArray *c26_rhs50 = NULL;
  const mxArray *c26_lhs50 = NULL;
  const mxArray *c26_rhs51 = NULL;
  const mxArray *c26_lhs51 = NULL;
  const mxArray *c26_rhs52 = NULL;
  const mxArray *c26_lhs52 = NULL;
  const mxArray *c26_rhs53 = NULL;
  const mxArray *c26_lhs53 = NULL;
  const mxArray *c26_rhs54 = NULL;
  const mxArray *c26_lhs54 = NULL;
  const mxArray *c26_rhs55 = NULL;
  const mxArray *c26_lhs55 = NULL;
  const mxArray *c26_rhs56 = NULL;
  const mxArray *c26_lhs56 = NULL;
  const mxArray *c26_rhs57 = NULL;
  const mxArray *c26_lhs57 = NULL;
  const mxArray *c26_rhs58 = NULL;
  const mxArray *c26_lhs58 = NULL;
  const mxArray *c26_rhs59 = NULL;
  const mxArray *c26_lhs59 = NULL;
  const mxArray *c26_rhs60 = NULL;
  const mxArray *c26_lhs60 = NULL;
  const mxArray *c26_rhs61 = NULL;
  const mxArray *c26_lhs61 = NULL;
  const mxArray *c26_rhs62 = NULL;
  const mxArray *c26_lhs62 = NULL;
  const mxArray *c26_rhs63 = NULL;
  const mxArray *c26_lhs63 = NULL;
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c26_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c26_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("ismatrix"), "name", "name",
                  2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1331268858U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c26_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395292506U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c26_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c26_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c26_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c26_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c26_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c26_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677854U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c26_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c26_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c26_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c26_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c26_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 14);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 14);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c26_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 15);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("rdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c26_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c26_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 17);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c26_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_div"), "name", "name",
                  18);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c26_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 19);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c26_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("cos"), "name", "name", 20);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c26_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 21);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786322U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c26_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sin"), "name", "name", 22);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395292504U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c26_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 23);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786336U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c26_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 24);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("norm"), "name", "name", 24);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677868U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c26_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 25);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 25);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c26_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 26);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c26_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 27);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  27);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c26_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 28);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c26_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 29);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c26_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 30);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 30);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c26_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 31);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 31);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c26_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 32);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 32);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c26_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 33);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 33);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c26_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 34);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmin"), "name", "name",
                  34);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c26_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 35);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622444U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c26_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 36);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c26_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 37);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 37);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c26_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 38);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 38);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 38);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c26_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 39);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 39);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 39);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c26_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 40);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 40);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c26_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 41);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isfi"), "name", "name", 41);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 41);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1346481558U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c26_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 42);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1398846798U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c26_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 43);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("intmax"), "name", "name", 43);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c26_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 44);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c26_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 45);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("intmin"), "name", "name", 45);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c26_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 46);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c26_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 47);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 47);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c26_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 48);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c26_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 49);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786312U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c26_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 50);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("svd"), "name", "name", 50);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786432U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c26_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 51);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c26_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 52);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c26_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isfinite"), "name", "name",
                  53);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c26_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 54);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c26_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isinf"), "name", "name", 55);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c26_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 56);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c26_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnan"), "name", "name", 57);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c26_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 58);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c26_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_error"), "name", "name",
                  59);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 59);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c26_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xgesvd"), "name", "name",
                  60);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786406U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c26_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_lapack_xgesvd"), "name",
                  "name", 61);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786410U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c26_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"),
                  "context", "context", 62);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zsvdc"), "name",
                  "name", 62);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1398846806U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c26_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 63);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 63);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c26_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c26_rhs0);
  sf_mex_destroy(&c26_lhs0);
  sf_mex_destroy(&c26_rhs1);
  sf_mex_destroy(&c26_lhs1);
  sf_mex_destroy(&c26_rhs2);
  sf_mex_destroy(&c26_lhs2);
  sf_mex_destroy(&c26_rhs3);
  sf_mex_destroy(&c26_lhs3);
  sf_mex_destroy(&c26_rhs4);
  sf_mex_destroy(&c26_lhs4);
  sf_mex_destroy(&c26_rhs5);
  sf_mex_destroy(&c26_lhs5);
  sf_mex_destroy(&c26_rhs6);
  sf_mex_destroy(&c26_lhs6);
  sf_mex_destroy(&c26_rhs7);
  sf_mex_destroy(&c26_lhs7);
  sf_mex_destroy(&c26_rhs8);
  sf_mex_destroy(&c26_lhs8);
  sf_mex_destroy(&c26_rhs9);
  sf_mex_destroy(&c26_lhs9);
  sf_mex_destroy(&c26_rhs10);
  sf_mex_destroy(&c26_lhs10);
  sf_mex_destroy(&c26_rhs11);
  sf_mex_destroy(&c26_lhs11);
  sf_mex_destroy(&c26_rhs12);
  sf_mex_destroy(&c26_lhs12);
  sf_mex_destroy(&c26_rhs13);
  sf_mex_destroy(&c26_lhs13);
  sf_mex_destroy(&c26_rhs14);
  sf_mex_destroy(&c26_lhs14);
  sf_mex_destroy(&c26_rhs15);
  sf_mex_destroy(&c26_lhs15);
  sf_mex_destroy(&c26_rhs16);
  sf_mex_destroy(&c26_lhs16);
  sf_mex_destroy(&c26_rhs17);
  sf_mex_destroy(&c26_lhs17);
  sf_mex_destroy(&c26_rhs18);
  sf_mex_destroy(&c26_lhs18);
  sf_mex_destroy(&c26_rhs19);
  sf_mex_destroy(&c26_lhs19);
  sf_mex_destroy(&c26_rhs20);
  sf_mex_destroy(&c26_lhs20);
  sf_mex_destroy(&c26_rhs21);
  sf_mex_destroy(&c26_lhs21);
  sf_mex_destroy(&c26_rhs22);
  sf_mex_destroy(&c26_lhs22);
  sf_mex_destroy(&c26_rhs23);
  sf_mex_destroy(&c26_lhs23);
  sf_mex_destroy(&c26_rhs24);
  sf_mex_destroy(&c26_lhs24);
  sf_mex_destroy(&c26_rhs25);
  sf_mex_destroy(&c26_lhs25);
  sf_mex_destroy(&c26_rhs26);
  sf_mex_destroy(&c26_lhs26);
  sf_mex_destroy(&c26_rhs27);
  sf_mex_destroy(&c26_lhs27);
  sf_mex_destroy(&c26_rhs28);
  sf_mex_destroy(&c26_lhs28);
  sf_mex_destroy(&c26_rhs29);
  sf_mex_destroy(&c26_lhs29);
  sf_mex_destroy(&c26_rhs30);
  sf_mex_destroy(&c26_lhs30);
  sf_mex_destroy(&c26_rhs31);
  sf_mex_destroy(&c26_lhs31);
  sf_mex_destroy(&c26_rhs32);
  sf_mex_destroy(&c26_lhs32);
  sf_mex_destroy(&c26_rhs33);
  sf_mex_destroy(&c26_lhs33);
  sf_mex_destroy(&c26_rhs34);
  sf_mex_destroy(&c26_lhs34);
  sf_mex_destroy(&c26_rhs35);
  sf_mex_destroy(&c26_lhs35);
  sf_mex_destroy(&c26_rhs36);
  sf_mex_destroy(&c26_lhs36);
  sf_mex_destroy(&c26_rhs37);
  sf_mex_destroy(&c26_lhs37);
  sf_mex_destroy(&c26_rhs38);
  sf_mex_destroy(&c26_lhs38);
  sf_mex_destroy(&c26_rhs39);
  sf_mex_destroy(&c26_lhs39);
  sf_mex_destroy(&c26_rhs40);
  sf_mex_destroy(&c26_lhs40);
  sf_mex_destroy(&c26_rhs41);
  sf_mex_destroy(&c26_lhs41);
  sf_mex_destroy(&c26_rhs42);
  sf_mex_destroy(&c26_lhs42);
  sf_mex_destroy(&c26_rhs43);
  sf_mex_destroy(&c26_lhs43);
  sf_mex_destroy(&c26_rhs44);
  sf_mex_destroy(&c26_lhs44);
  sf_mex_destroy(&c26_rhs45);
  sf_mex_destroy(&c26_lhs45);
  sf_mex_destroy(&c26_rhs46);
  sf_mex_destroy(&c26_lhs46);
  sf_mex_destroy(&c26_rhs47);
  sf_mex_destroy(&c26_lhs47);
  sf_mex_destroy(&c26_rhs48);
  sf_mex_destroy(&c26_lhs48);
  sf_mex_destroy(&c26_rhs49);
  sf_mex_destroy(&c26_lhs49);
  sf_mex_destroy(&c26_rhs50);
  sf_mex_destroy(&c26_lhs50);
  sf_mex_destroy(&c26_rhs51);
  sf_mex_destroy(&c26_lhs51);
  sf_mex_destroy(&c26_rhs52);
  sf_mex_destroy(&c26_lhs52);
  sf_mex_destroy(&c26_rhs53);
  sf_mex_destroy(&c26_lhs53);
  sf_mex_destroy(&c26_rhs54);
  sf_mex_destroy(&c26_lhs54);
  sf_mex_destroy(&c26_rhs55);
  sf_mex_destroy(&c26_lhs55);
  sf_mex_destroy(&c26_rhs56);
  sf_mex_destroy(&c26_lhs56);
  sf_mex_destroy(&c26_rhs57);
  sf_mex_destroy(&c26_lhs57);
  sf_mex_destroy(&c26_rhs58);
  sf_mex_destroy(&c26_lhs58);
  sf_mex_destroy(&c26_rhs59);
  sf_mex_destroy(&c26_lhs59);
  sf_mex_destroy(&c26_rhs60);
  sf_mex_destroy(&c26_lhs60);
  sf_mex_destroy(&c26_rhs61);
  sf_mex_destroy(&c26_lhs61);
  sf_mex_destroy(&c26_rhs62);
  sf_mex_destroy(&c26_lhs62);
  sf_mex_destroy(&c26_rhs63);
  sf_mex_destroy(&c26_lhs63);
}

static const mxArray *c26_emlrt_marshallOut(const char * c26_u)
{
  const mxArray *c26_y = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c26_u)), false);
  return c26_y;
}

static const mxArray *c26_b_emlrt_marshallOut(const uint32_T c26_u)
{
  const mxArray *c26_y = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 7, 0U, 0U, 0U, 0), false);
  return c26_y;
}

static void c26_b_info_helper(const mxArray **c26_info)
{
  const mxArray *c26_rhs64 = NULL;
  const mxArray *c26_lhs64 = NULL;
  const mxArray *c26_rhs65 = NULL;
  const mxArray *c26_lhs65 = NULL;
  const mxArray *c26_rhs66 = NULL;
  const mxArray *c26_lhs66 = NULL;
  const mxArray *c26_rhs67 = NULL;
  const mxArray *c26_lhs67 = NULL;
  const mxArray *c26_rhs68 = NULL;
  const mxArray *c26_lhs68 = NULL;
  const mxArray *c26_rhs69 = NULL;
  const mxArray *c26_lhs69 = NULL;
  const mxArray *c26_rhs70 = NULL;
  const mxArray *c26_lhs70 = NULL;
  const mxArray *c26_rhs71 = NULL;
  const mxArray *c26_lhs71 = NULL;
  const mxArray *c26_rhs72 = NULL;
  const mxArray *c26_lhs72 = NULL;
  const mxArray *c26_rhs73 = NULL;
  const mxArray *c26_lhs73 = NULL;
  const mxArray *c26_rhs74 = NULL;
  const mxArray *c26_lhs74 = NULL;
  const mxArray *c26_rhs75 = NULL;
  const mxArray *c26_lhs75 = NULL;
  const mxArray *c26_rhs76 = NULL;
  const mxArray *c26_lhs76 = NULL;
  const mxArray *c26_rhs77 = NULL;
  const mxArray *c26_lhs77 = NULL;
  const mxArray *c26_rhs78 = NULL;
  const mxArray *c26_lhs78 = NULL;
  const mxArray *c26_rhs79 = NULL;
  const mxArray *c26_lhs79 = NULL;
  const mxArray *c26_rhs80 = NULL;
  const mxArray *c26_lhs80 = NULL;
  const mxArray *c26_rhs81 = NULL;
  const mxArray *c26_lhs81 = NULL;
  const mxArray *c26_rhs82 = NULL;
  const mxArray *c26_lhs82 = NULL;
  const mxArray *c26_rhs83 = NULL;
  const mxArray *c26_lhs83 = NULL;
  const mxArray *c26_rhs84 = NULL;
  const mxArray *c26_lhs84 = NULL;
  const mxArray *c26_rhs85 = NULL;
  const mxArray *c26_lhs85 = NULL;
  const mxArray *c26_rhs86 = NULL;
  const mxArray *c26_lhs86 = NULL;
  const mxArray *c26_rhs87 = NULL;
  const mxArray *c26_lhs87 = NULL;
  const mxArray *c26_rhs88 = NULL;
  const mxArray *c26_lhs88 = NULL;
  const mxArray *c26_rhs89 = NULL;
  const mxArray *c26_lhs89 = NULL;
  const mxArray *c26_rhs90 = NULL;
  const mxArray *c26_lhs90 = NULL;
  const mxArray *c26_rhs91 = NULL;
  const mxArray *c26_lhs91 = NULL;
  const mxArray *c26_rhs92 = NULL;
  const mxArray *c26_lhs92 = NULL;
  const mxArray *c26_rhs93 = NULL;
  const mxArray *c26_lhs93 = NULL;
  const mxArray *c26_rhs94 = NULL;
  const mxArray *c26_lhs94 = NULL;
  const mxArray *c26_rhs95 = NULL;
  const mxArray *c26_lhs95 = NULL;
  const mxArray *c26_rhs96 = NULL;
  const mxArray *c26_lhs96 = NULL;
  const mxArray *c26_rhs97 = NULL;
  const mxArray *c26_lhs97 = NULL;
  const mxArray *c26_rhs98 = NULL;
  const mxArray *c26_lhs98 = NULL;
  const mxArray *c26_rhs99 = NULL;
  const mxArray *c26_lhs99 = NULL;
  const mxArray *c26_rhs100 = NULL;
  const mxArray *c26_lhs100 = NULL;
  const mxArray *c26_rhs101 = NULL;
  const mxArray *c26_lhs101 = NULL;
  const mxArray *c26_rhs102 = NULL;
  const mxArray *c26_lhs102 = NULL;
  const mxArray *c26_rhs103 = NULL;
  const mxArray *c26_lhs103 = NULL;
  const mxArray *c26_rhs104 = NULL;
  const mxArray *c26_lhs104 = NULL;
  const mxArray *c26_rhs105 = NULL;
  const mxArray *c26_lhs105 = NULL;
  const mxArray *c26_rhs106 = NULL;
  const mxArray *c26_lhs106 = NULL;
  const mxArray *c26_rhs107 = NULL;
  const mxArray *c26_lhs107 = NULL;
  const mxArray *c26_rhs108 = NULL;
  const mxArray *c26_lhs108 = NULL;
  const mxArray *c26_rhs109 = NULL;
  const mxArray *c26_lhs109 = NULL;
  const mxArray *c26_rhs110 = NULL;
  const mxArray *c26_lhs110 = NULL;
  const mxArray *c26_rhs111 = NULL;
  const mxArray *c26_lhs111 = NULL;
  const mxArray *c26_rhs112 = NULL;
  const mxArray *c26_lhs112 = NULL;
  const mxArray *c26_rhs113 = NULL;
  const mxArray *c26_lhs113 = NULL;
  const mxArray *c26_rhs114 = NULL;
  const mxArray *c26_lhs114 = NULL;
  const mxArray *c26_rhs115 = NULL;
  const mxArray *c26_lhs115 = NULL;
  const mxArray *c26_rhs116 = NULL;
  const mxArray *c26_lhs116 = NULL;
  const mxArray *c26_rhs117 = NULL;
  const mxArray *c26_lhs117 = NULL;
  const mxArray *c26_rhs118 = NULL;
  const mxArray *c26_lhs118 = NULL;
  const mxArray *c26_rhs119 = NULL;
  const mxArray *c26_lhs119 = NULL;
  const mxArray *c26_rhs120 = NULL;
  const mxArray *c26_lhs120 = NULL;
  const mxArray *c26_rhs121 = NULL;
  const mxArray *c26_lhs121 = NULL;
  const mxArray *c26_rhs122 = NULL;
  const mxArray *c26_lhs122 = NULL;
  const mxArray *c26_rhs123 = NULL;
  const mxArray *c26_lhs123 = NULL;
  const mxArray *c26_rhs124 = NULL;
  const mxArray *c26_lhs124 = NULL;
  const mxArray *c26_rhs125 = NULL;
  const mxArray *c26_lhs125 = NULL;
  const mxArray *c26_rhs126 = NULL;
  const mxArray *c26_lhs126 = NULL;
  const mxArray *c26_rhs127 = NULL;
  const mxArray *c26_lhs127 = NULL;
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("min"), "name", "name", 64);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 64);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1311226518U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c26_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 65);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1378267184U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c26_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 66);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 66);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 66);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c26_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 67);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 67);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c26_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 68);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 68);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 68);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c26_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 69);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 69);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 69);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c26_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 70);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 70);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c26_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 71);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 71);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 71);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c26_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 72);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 72);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 72);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c26_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 73);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("max"), "name", "name", 73);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c26_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 74);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1378267184U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c26_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 75);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 75);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c26_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 76);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 76);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c26_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 77);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 77);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c26_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 78);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_relop"), "name", "name",
                  78);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 78);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 78);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1342422382U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c26_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "context",
                  "context", 79);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 79);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326692322U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c26_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 80);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 80);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c26_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 81);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 81);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c26_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 82);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("intmin"), "name", "name", 82);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 82);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1362225882U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c26_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 83);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnan"), "name", "name", 83);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 83);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c26_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 84);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 84);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 84);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c26_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 85);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("max"), "name", "name", 85);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 85);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c26_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 86);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  86);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c26_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.scaleVectorByRecip"), "name", "name", 87);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c26_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 88);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmin"), "name", "name",
                  88);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c26_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 89);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eps"), "name", "name", 89);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 89);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c26_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 90);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 90);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c26_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 91);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_eps"), "name", "name",
                  91);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 91);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c26_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 92);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 92);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c26_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 93);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  93);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 93);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c26_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 94);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 94);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 94);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c26_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 95);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.xscal"),
                  "name", "name", 95);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c26_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 96);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 96);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c26_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p!below_threshold"),
                  "context", "context", 97);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 97);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c26_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 98);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 98);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c26_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"),
                  "context", "context", 99);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.refblas.xscal"), "name", "name", 99);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c26_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 100);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 100);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c26_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 101);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 101);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 101);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c26_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 102);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 102);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 102);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c26_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"),
                  "context", "context", 103);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 103);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c26_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 104);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 104);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c26_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 105);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 105);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 105);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c26_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 106);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 106);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 106);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c26_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"),
                  "context", "context", 107);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 107);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c26_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 108);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  108);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c26_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 109);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 109);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c26_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 110);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.xdotc"),
                  "name", "name", 110);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c26_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "context", "context", 111);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 111);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c26_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 112);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 112);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c26_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 113);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 113);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c26_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 114);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 114);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c26_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 115);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 115);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c26_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 116);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 116);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c26_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 117);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 117);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c26_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 118);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 118);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 118);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c26_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 119);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  119);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 119);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c26_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 120);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xaxpy"), "name", "name",
                  120);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c26_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"), "context",
                  "context", 121);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 121);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c26_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m"), "context",
                  "context", 122);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.xaxpy"),
                  "name", "name", 122);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c26_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 123);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 123);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c26_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p!below_threshold"),
                  "context", "context", 124);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 124);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c26_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 125);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 125);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c26_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xaxpy.p"),
                  "context", "context", 126);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.refblas.xaxpy"), "name", "name", 126);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c26_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 127);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 127);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 127);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c26_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c26_rhs64);
  sf_mex_destroy(&c26_lhs64);
  sf_mex_destroy(&c26_rhs65);
  sf_mex_destroy(&c26_lhs65);
  sf_mex_destroy(&c26_rhs66);
  sf_mex_destroy(&c26_lhs66);
  sf_mex_destroy(&c26_rhs67);
  sf_mex_destroy(&c26_lhs67);
  sf_mex_destroy(&c26_rhs68);
  sf_mex_destroy(&c26_lhs68);
  sf_mex_destroy(&c26_rhs69);
  sf_mex_destroy(&c26_lhs69);
  sf_mex_destroy(&c26_rhs70);
  sf_mex_destroy(&c26_lhs70);
  sf_mex_destroy(&c26_rhs71);
  sf_mex_destroy(&c26_lhs71);
  sf_mex_destroy(&c26_rhs72);
  sf_mex_destroy(&c26_lhs72);
  sf_mex_destroy(&c26_rhs73);
  sf_mex_destroy(&c26_lhs73);
  sf_mex_destroy(&c26_rhs74);
  sf_mex_destroy(&c26_lhs74);
  sf_mex_destroy(&c26_rhs75);
  sf_mex_destroy(&c26_lhs75);
  sf_mex_destroy(&c26_rhs76);
  sf_mex_destroy(&c26_lhs76);
  sf_mex_destroy(&c26_rhs77);
  sf_mex_destroy(&c26_lhs77);
  sf_mex_destroy(&c26_rhs78);
  sf_mex_destroy(&c26_lhs78);
  sf_mex_destroy(&c26_rhs79);
  sf_mex_destroy(&c26_lhs79);
  sf_mex_destroy(&c26_rhs80);
  sf_mex_destroy(&c26_lhs80);
  sf_mex_destroy(&c26_rhs81);
  sf_mex_destroy(&c26_lhs81);
  sf_mex_destroy(&c26_rhs82);
  sf_mex_destroy(&c26_lhs82);
  sf_mex_destroy(&c26_rhs83);
  sf_mex_destroy(&c26_lhs83);
  sf_mex_destroy(&c26_rhs84);
  sf_mex_destroy(&c26_lhs84);
  sf_mex_destroy(&c26_rhs85);
  sf_mex_destroy(&c26_lhs85);
  sf_mex_destroy(&c26_rhs86);
  sf_mex_destroy(&c26_lhs86);
  sf_mex_destroy(&c26_rhs87);
  sf_mex_destroy(&c26_lhs87);
  sf_mex_destroy(&c26_rhs88);
  sf_mex_destroy(&c26_lhs88);
  sf_mex_destroy(&c26_rhs89);
  sf_mex_destroy(&c26_lhs89);
  sf_mex_destroy(&c26_rhs90);
  sf_mex_destroy(&c26_lhs90);
  sf_mex_destroy(&c26_rhs91);
  sf_mex_destroy(&c26_lhs91);
  sf_mex_destroy(&c26_rhs92);
  sf_mex_destroy(&c26_lhs92);
  sf_mex_destroy(&c26_rhs93);
  sf_mex_destroy(&c26_lhs93);
  sf_mex_destroy(&c26_rhs94);
  sf_mex_destroy(&c26_lhs94);
  sf_mex_destroy(&c26_rhs95);
  sf_mex_destroy(&c26_lhs95);
  sf_mex_destroy(&c26_rhs96);
  sf_mex_destroy(&c26_lhs96);
  sf_mex_destroy(&c26_rhs97);
  sf_mex_destroy(&c26_lhs97);
  sf_mex_destroy(&c26_rhs98);
  sf_mex_destroy(&c26_lhs98);
  sf_mex_destroy(&c26_rhs99);
  sf_mex_destroy(&c26_lhs99);
  sf_mex_destroy(&c26_rhs100);
  sf_mex_destroy(&c26_lhs100);
  sf_mex_destroy(&c26_rhs101);
  sf_mex_destroy(&c26_lhs101);
  sf_mex_destroy(&c26_rhs102);
  sf_mex_destroy(&c26_lhs102);
  sf_mex_destroy(&c26_rhs103);
  sf_mex_destroy(&c26_lhs103);
  sf_mex_destroy(&c26_rhs104);
  sf_mex_destroy(&c26_lhs104);
  sf_mex_destroy(&c26_rhs105);
  sf_mex_destroy(&c26_lhs105);
  sf_mex_destroy(&c26_rhs106);
  sf_mex_destroy(&c26_lhs106);
  sf_mex_destroy(&c26_rhs107);
  sf_mex_destroy(&c26_lhs107);
  sf_mex_destroy(&c26_rhs108);
  sf_mex_destroy(&c26_lhs108);
  sf_mex_destroy(&c26_rhs109);
  sf_mex_destroy(&c26_lhs109);
  sf_mex_destroy(&c26_rhs110);
  sf_mex_destroy(&c26_lhs110);
  sf_mex_destroy(&c26_rhs111);
  sf_mex_destroy(&c26_lhs111);
  sf_mex_destroy(&c26_rhs112);
  sf_mex_destroy(&c26_lhs112);
  sf_mex_destroy(&c26_rhs113);
  sf_mex_destroy(&c26_lhs113);
  sf_mex_destroy(&c26_rhs114);
  sf_mex_destroy(&c26_lhs114);
  sf_mex_destroy(&c26_rhs115);
  sf_mex_destroy(&c26_lhs115);
  sf_mex_destroy(&c26_rhs116);
  sf_mex_destroy(&c26_lhs116);
  sf_mex_destroy(&c26_rhs117);
  sf_mex_destroy(&c26_lhs117);
  sf_mex_destroy(&c26_rhs118);
  sf_mex_destroy(&c26_lhs118);
  sf_mex_destroy(&c26_rhs119);
  sf_mex_destroy(&c26_lhs119);
  sf_mex_destroy(&c26_rhs120);
  sf_mex_destroy(&c26_lhs120);
  sf_mex_destroy(&c26_rhs121);
  sf_mex_destroy(&c26_lhs121);
  sf_mex_destroy(&c26_rhs122);
  sf_mex_destroy(&c26_lhs122);
  sf_mex_destroy(&c26_rhs123);
  sf_mex_destroy(&c26_lhs123);
  sf_mex_destroy(&c26_rhs124);
  sf_mex_destroy(&c26_lhs124);
  sf_mex_destroy(&c26_rhs125);
  sf_mex_destroy(&c26_lhs125);
  sf_mex_destroy(&c26_rhs126);
  sf_mex_destroy(&c26_lhs126);
  sf_mex_destroy(&c26_rhs127);
  sf_mex_destroy(&c26_lhs127);
}

static void c26_c_info_helper(const mxArray **c26_info)
{
  const mxArray *c26_rhs128 = NULL;
  const mxArray *c26_lhs128 = NULL;
  const mxArray *c26_rhs129 = NULL;
  const mxArray *c26_lhs129 = NULL;
  const mxArray *c26_rhs130 = NULL;
  const mxArray *c26_lhs130 = NULL;
  const mxArray *c26_rhs131 = NULL;
  const mxArray *c26_lhs131 = NULL;
  const mxArray *c26_rhs132 = NULL;
  const mxArray *c26_lhs132 = NULL;
  const mxArray *c26_rhs133 = NULL;
  const mxArray *c26_lhs133 = NULL;
  const mxArray *c26_rhs134 = NULL;
  const mxArray *c26_lhs134 = NULL;
  const mxArray *c26_rhs135 = NULL;
  const mxArray *c26_lhs135 = NULL;
  const mxArray *c26_rhs136 = NULL;
  const mxArray *c26_lhs136 = NULL;
  const mxArray *c26_rhs137 = NULL;
  const mxArray *c26_lhs137 = NULL;
  const mxArray *c26_rhs138 = NULL;
  const mxArray *c26_lhs138 = NULL;
  const mxArray *c26_rhs139 = NULL;
  const mxArray *c26_lhs139 = NULL;
  const mxArray *c26_rhs140 = NULL;
  const mxArray *c26_lhs140 = NULL;
  const mxArray *c26_rhs141 = NULL;
  const mxArray *c26_lhs141 = NULL;
  const mxArray *c26_rhs142 = NULL;
  const mxArray *c26_lhs142 = NULL;
  const mxArray *c26_rhs143 = NULL;
  const mxArray *c26_lhs143 = NULL;
  const mxArray *c26_rhs144 = NULL;
  const mxArray *c26_lhs144 = NULL;
  const mxArray *c26_rhs145 = NULL;
  const mxArray *c26_lhs145 = NULL;
  const mxArray *c26_rhs146 = NULL;
  const mxArray *c26_lhs146 = NULL;
  const mxArray *c26_rhs147 = NULL;
  const mxArray *c26_lhs147 = NULL;
  const mxArray *c26_rhs148 = NULL;
  const mxArray *c26_lhs148 = NULL;
  const mxArray *c26_rhs149 = NULL;
  const mxArray *c26_lhs149 = NULL;
  const mxArray *c26_rhs150 = NULL;
  const mxArray *c26_lhs150 = NULL;
  const mxArray *c26_rhs151 = NULL;
  const mxArray *c26_lhs151 = NULL;
  const mxArray *c26_rhs152 = NULL;
  const mxArray *c26_lhs152 = NULL;
  const mxArray *c26_rhs153 = NULL;
  const mxArray *c26_lhs153 = NULL;
  const mxArray *c26_rhs154 = NULL;
  const mxArray *c26_lhs154 = NULL;
  const mxArray *c26_rhs155 = NULL;
  const mxArray *c26_lhs155 = NULL;
  const mxArray *c26_rhs156 = NULL;
  const mxArray *c26_lhs156 = NULL;
  const mxArray *c26_rhs157 = NULL;
  const mxArray *c26_lhs157 = NULL;
  const mxArray *c26_rhs158 = NULL;
  const mxArray *c26_lhs158 = NULL;
  const mxArray *c26_rhs159 = NULL;
  const mxArray *c26_lhs159 = NULL;
  const mxArray *c26_rhs160 = NULL;
  const mxArray *c26_lhs160 = NULL;
  const mxArray *c26_rhs161 = NULL;
  const mxArray *c26_lhs161 = NULL;
  const mxArray *c26_rhs162 = NULL;
  const mxArray *c26_lhs162 = NULL;
  const mxArray *c26_rhs163 = NULL;
  const mxArray *c26_lhs163 = NULL;
  const mxArray *c26_rhs164 = NULL;
  const mxArray *c26_lhs164 = NULL;
  const mxArray *c26_rhs165 = NULL;
  const mxArray *c26_lhs165 = NULL;
  const mxArray *c26_rhs166 = NULL;
  const mxArray *c26_lhs166 = NULL;
  const mxArray *c26_rhs167 = NULL;
  const mxArray *c26_lhs167 = NULL;
  const mxArray *c26_rhs168 = NULL;
  const mxArray *c26_lhs168 = NULL;
  const mxArray *c26_rhs169 = NULL;
  const mxArray *c26_lhs169 = NULL;
  const mxArray *c26_rhs170 = NULL;
  const mxArray *c26_lhs170 = NULL;
  const mxArray *c26_rhs171 = NULL;
  const mxArray *c26_lhs171 = NULL;
  const mxArray *c26_rhs172 = NULL;
  const mxArray *c26_lhs172 = NULL;
  const mxArray *c26_rhs173 = NULL;
  const mxArray *c26_lhs173 = NULL;
  const mxArray *c26_rhs174 = NULL;
  const mxArray *c26_lhs174 = NULL;
  const mxArray *c26_rhs175 = NULL;
  const mxArray *c26_lhs175 = NULL;
  const mxArray *c26_rhs176 = NULL;
  const mxArray *c26_lhs176 = NULL;
  const mxArray *c26_rhs177 = NULL;
  const mxArray *c26_lhs177 = NULL;
  const mxArray *c26_rhs178 = NULL;
  const mxArray *c26_lhs178 = NULL;
  const mxArray *c26_rhs179 = NULL;
  const mxArray *c26_lhs179 = NULL;
  const mxArray *c26_rhs180 = NULL;
  const mxArray *c26_lhs180 = NULL;
  const mxArray *c26_rhs181 = NULL;
  const mxArray *c26_lhs181 = NULL;
  const mxArray *c26_rhs182 = NULL;
  const mxArray *c26_lhs182 = NULL;
  const mxArray *c26_rhs183 = NULL;
  const mxArray *c26_lhs183 = NULL;
  const mxArray *c26_rhs184 = NULL;
  const mxArray *c26_lhs184 = NULL;
  const mxArray *c26_rhs185 = NULL;
  const mxArray *c26_lhs185 = NULL;
  const mxArray *c26_rhs186 = NULL;
  const mxArray *c26_lhs186 = NULL;
  const mxArray *c26_rhs187 = NULL;
  const mxArray *c26_lhs187 = NULL;
  const mxArray *c26_rhs188 = NULL;
  const mxArray *c26_lhs188 = NULL;
  const mxArray *c26_rhs189 = NULL;
  const mxArray *c26_lhs189 = NULL;
  const mxArray *c26_rhs190 = NULL;
  const mxArray *c26_lhs190 = NULL;
  const mxArray *c26_rhs191 = NULL;
  const mxArray *c26_lhs191 = NULL;
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 128);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 128);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c26_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 129);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 129);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c26_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs129), "rhs",
                  "rhs", 129);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs129), "lhs",
                  "lhs", 129);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 130);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 130);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c26_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs130), "rhs",
                  "rhs", 130);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs130), "lhs",
                  "lhs", 130);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xaxpy.p"),
                  "context", "context", 131);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 131);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 131);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 131);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c26_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs131), "rhs",
                  "rhs", 131);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs131), "lhs",
                  "lhs", 131);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 132);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 132);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 132);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c26_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs132), "rhs",
                  "rhs", 132);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs132), "lhs",
                  "lhs", 132);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 133);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 133);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 133);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 133);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c26_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs133), "rhs",
                  "rhs", 133);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs133), "lhs",
                  "lhs", 133);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 134);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmin"), "name", "name",
                  134);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 134);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c26_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs134), "rhs",
                  "rhs", 134);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs134), "lhs",
                  "lhs", 134);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 135);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eps"), "name", "name", 135);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 135);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c26_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs135), "rhs",
                  "rhs", 135);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs135), "lhs",
                  "lhs", 135);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 136);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 136);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c26_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs136), "rhs",
                  "rhs", 136);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs136), "lhs",
                  "lhs", 136);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 137);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_error"), "name", "name",
                  137);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 137);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c26_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs137), "rhs",
                  "rhs", 137);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs137), "lhs",
                  "lhs", 137);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 138);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 138);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 138);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c26_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs138), "rhs",
                  "rhs", 138);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs138), "lhs",
                  "lhs", 138);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 139);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 139);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 139);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c26_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs139), "rhs",
                  "rhs", 139);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs139), "lhs",
                  "lhs", 139);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 140);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 140);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 140);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c26_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs140), "rhs",
                  "rhs", 140);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs140), "lhs",
                  "lhs", 140);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 141);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 141);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c26_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs141), "rhs",
                  "rhs", 141);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs141), "lhs",
                  "lhs", 141);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 142);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 142);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c26_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs142), "rhs",
                  "rhs", 142);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs142), "lhs",
                  "lhs", 142);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 143);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnan"), "name", "name", 143);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 143);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c26_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs143), "rhs",
                  "rhs", 143);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs143), "lhs",
                  "lhs", 143);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 144);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 144);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 144);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c26_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs144), "rhs",
                  "rhs", 144);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs144), "lhs",
                  "lhs", 144);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 145);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 145);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 145);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c26_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs145), "rhs",
                  "rhs", 145);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs145), "lhs",
                  "lhs", 145);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 146);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 146);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 146);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c26_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs146), "rhs",
                  "rhs", 146);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs146), "lhs",
                  "lhs", 146);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 147);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_relop"), "name", "name",
                  147);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 147);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 147);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1342422382U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c26_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs147), "rhs",
                  "rhs", 147);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs147), "lhs",
                  "lhs", 147);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 148);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sqrt"), "name", "name", 148);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 148);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c26_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs148), "rhs",
                  "rhs", 148);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs148), "lhs",
                  "lhs", 148);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 149);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_error"), "name", "name",
                  149);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 149);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c26_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs149), "rhs",
                  "rhs", 149);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs149), "lhs",
                  "lhs", 149);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 150);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 150);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 150);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786338U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c26_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs150), "rhs",
                  "rhs", 150);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs150), "lhs",
                  "lhs", 150);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"),
                  "context", "context", 151);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xrotg"), "name", "name",
                  151);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951892U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c26_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs151), "rhs",
                  "rhs", 151);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs151), "lhs",
                  "lhs", 151);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"), "context",
                  "context", 152);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 152);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c26_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs152), "rhs",
                  "rhs", 152);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs152), "lhs",
                  "lhs", 152);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m"), "context",
                  "context", 153);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.blas.xrotg"),
                  "name", "name", 153);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "resolved", "resolved", 153);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c26_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs153), "rhs",
                  "rhs", 153);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs153), "lhs",
                  "lhs", 153);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "context", "context", 154);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 154);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 154);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 154);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c26_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs154), "rhs",
                  "rhs", 154);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs154), "lhs",
                  "lhs", 154);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"),
                  "context", "context", 155);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.refblas.xrotg"), "name", "name", 155);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 155);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "resolved", "resolved", 155);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c26_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs155), "rhs",
                  "rhs", 155);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs155), "lhs",
                  "lhs", 155);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 156);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 156);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 156);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 156);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c26_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs156), "rhs",
                  "rhs", 156);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs156), "lhs",
                  "lhs", 156);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 157);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  157);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 157);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c26_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs157), "rhs",
                  "rhs", 157);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs157), "lhs",
                  "lhs", 157);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xrotg.p"),
                  "context", "context", 158);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sqrt"), "name", "name", 158);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 158);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 158);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c26_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs158), "rhs",
                  "rhs", 158);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs158), "lhs",
                  "lhs", 158);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p!eml_ceval_xrotg"),
                  "context", "context", 159);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 159);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 159);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c26_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs159), "rhs",
                  "rhs", 159);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs159), "lhs",
                  "lhs", 159);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context",
                  160);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eig"), "name", "name", 160);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "resolved",
                  "resolved", 160);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1398846808U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c26_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs160), "rhs",
                  "rhs", 160);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs160), "lhs",
                  "lhs", 160);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "context",
                  "context", 161);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 161);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 161);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c26_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs161), "rhs",
                  "rhs", 161);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs161), "lhs",
                  "lhs", 161);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m!parseopts"),
                  "context", "context", 162);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("length"), "name", "name",
                  162);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("cell"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 162);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1303117406U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c26_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs162), "rhs",
                  "rhs", 162);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs162), "lhs",
                  "lhs", 162);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "context",
                  "context", 163);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 163);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 163);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c26_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs163), "rhs",
                  "rhs", 163);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs163), "lhs",
                  "lhs", 163);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "context",
                  "context", 164);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xgeev"), "name", "name",
                  164);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeev.m"),
                  "resolved", "resolved", 164);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786404U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c26_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs164), "rhs",
                  "rhs", 164);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs164), "lhs",
                  "lhs", 164);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeev.m"),
                  "context", "context", 165);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_lapack_xgeev"), "name",
                  "name", 165);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeev.m"),
                  "resolved", "resolved", 165);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1301296068U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c26_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs165), "rhs",
                  "rhs", 165);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs165), "lhs",
                  "lhs", 165);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeev.m"),
                  "context", "context", 166);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zggev"), "name",
                  "name", 166);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c26_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs166), "rhs",
                  "rhs", 166);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs166), "lhs",
                  "lhs", 166);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 167);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 167);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 167);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c26_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs167), "rhs",
                  "rhs", 167);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs167), "lhs",
                  "lhs", 167);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 168);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmin"), "name", "name",
                  168);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 168);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c26_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs168), "rhs",
                  "rhs", 168);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs168), "lhs",
                  "lhs", 168);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 169);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sqrt"), "name", "name", 169);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 169);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c26_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs169), "rhs",
                  "rhs", 169);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs169), "lhs",
                  "lhs", 169);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 170);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eps"), "name", "name", 170);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 170);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c26_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs170), "rhs",
                  "rhs", 170);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs170), "lhs",
                  "lhs", 170);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 171);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zlangeM"), "name",
                  "name", 171);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 171);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlangeM.m"),
                  "resolved", "resolved", 171);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786420U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c26_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs171), "rhs",
                  "rhs", 171);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs171), "lhs",
                  "lhs", 171);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlangeM.m"),
                  "context", "context", 172);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 172);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 172);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c26_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs172), "rhs",
                  "rhs", 172);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs172), "lhs",
                  "lhs", 172);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "context", "context", 173);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_dlapy2"), "name", "name",
                  173);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                  "resolved", 173);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1350378254U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c26_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs173), "rhs",
                  "rhs", 173);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs173), "lhs",
                  "lhs", 173);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlangeM.m"),
                  "context", "context", 174);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnan"), "name", "name", 174);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 174);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c26_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs174), "rhs",
                  "rhs", 174);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs174), "lhs",
                  "lhs", 174);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlangeM.m"),
                  "context", "context", 175);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 175);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 175);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 175);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c26_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs175), "rhs",
                  "rhs", 175);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs175), "lhs",
                  "lhs", 175);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 176);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 176);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 176);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c26_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs176), "rhs",
                  "rhs", 176);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs176), "lhs",
                  "lhs", 176);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 177);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isfinite"), "name", "name",
                  177);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 177);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c26_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs177), "rhs",
                  "rhs", 177);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs177), "lhs",
                  "lhs", 177);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 178);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 178);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 178);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 178);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c26_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs178), "rhs",
                  "rhs", 178);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs178), "lhs",
                  "lhs", 178);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 179);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zlascl"), "name",
                  "name", 179);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 179);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "resolved", "resolved", 179);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786422U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c26_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs179), "rhs",
                  "rhs", 179);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs179), "lhs",
                  "lhs", 179);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "context", "context", 180);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmin"), "name", "name",
                  180);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 180);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 180);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c26_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs180), "rhs",
                  "rhs", 180);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs180), "lhs",
                  "lhs", 180);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "context", "context", 181);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eps"), "name", "name", 181);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 181);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 181);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c26_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs181), "rhs",
                  "rhs", 181);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs181), "lhs",
                  "lhs", 181);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "context", "context", 182);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 182);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 182);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 182);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c26_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs182), "rhs",
                  "rhs", 182);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs182), "lhs",
                  "lhs", 182);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlascl.m"),
                  "context", "context", 183);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 183);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 183);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 183);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c26_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs183), "rhs",
                  "rhs", 183);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs183), "lhs",
                  "lhs", 183);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 184);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 184);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 184);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 184);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 184);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 184);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 184);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 184);
  sf_mex_assign(&c26_rhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs184), "rhs",
                  "rhs", 184);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs184), "lhs",
                  "lhs", 184);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 185);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zggbal"), "name",
                  "name", 185);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 185);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"),
                  "resolved", "resolved", 185);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786418U), "fileTimeLo",
                  "fileTimeLo", 185);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 185);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 185);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 185);
  sf_mex_assign(&c26_rhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs185), "rhs",
                  "rhs", 185);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs185), "lhs",
                  "lhs", 185);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"),
                  "context", "context", 186);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 186);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 186);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 186);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 186);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 186);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 186);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 186);
  sf_mex_assign(&c26_rhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs186), "rhs",
                  "rhs", 186);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs186), "lhs",
                  "lhs", 186);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_rows"),
                  "context", "context", 187);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 187);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 187);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 187);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 187);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 187);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 187);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 187);
  sf_mex_assign(&c26_rhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs187), "rhs",
                  "rhs", 187);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs187), "lhs",
                  "lhs", 187);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_rows"),
                  "context", "context", 188);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 188);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 188);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 188);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 188);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 188);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 188);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 188);
  sf_mex_assign(&c26_rhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs188), "rhs",
                  "rhs", 188);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs188), "lhs",
                  "lhs", 188);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_rows"),
                  "context", "context", 189);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 189);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 189);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 189);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 189);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 189);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 189);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 189);
  sf_mex_assign(&c26_rhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs189), "rhs",
                  "rhs", 189);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs189), "lhs",
                  "lhs", 189);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 190);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 190);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 190);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 190);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 190);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 190);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 190);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 190);
  sf_mex_assign(&c26_rhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs190), "rhs",
                  "rhs", 190);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs190), "lhs",
                  "lhs", 190);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_simtran"),
                  "context", "context", 191);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 191);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 191);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 191);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 191);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 191);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 191);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 191);
  sf_mex_assign(&c26_rhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs191), "rhs",
                  "rhs", 191);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs191), "lhs",
                  "lhs", 191);
  sf_mex_destroy(&c26_rhs128);
  sf_mex_destroy(&c26_lhs128);
  sf_mex_destroy(&c26_rhs129);
  sf_mex_destroy(&c26_lhs129);
  sf_mex_destroy(&c26_rhs130);
  sf_mex_destroy(&c26_lhs130);
  sf_mex_destroy(&c26_rhs131);
  sf_mex_destroy(&c26_lhs131);
  sf_mex_destroy(&c26_rhs132);
  sf_mex_destroy(&c26_lhs132);
  sf_mex_destroy(&c26_rhs133);
  sf_mex_destroy(&c26_lhs133);
  sf_mex_destroy(&c26_rhs134);
  sf_mex_destroy(&c26_lhs134);
  sf_mex_destroy(&c26_rhs135);
  sf_mex_destroy(&c26_lhs135);
  sf_mex_destroy(&c26_rhs136);
  sf_mex_destroy(&c26_lhs136);
  sf_mex_destroy(&c26_rhs137);
  sf_mex_destroy(&c26_lhs137);
  sf_mex_destroy(&c26_rhs138);
  sf_mex_destroy(&c26_lhs138);
  sf_mex_destroy(&c26_rhs139);
  sf_mex_destroy(&c26_lhs139);
  sf_mex_destroy(&c26_rhs140);
  sf_mex_destroy(&c26_lhs140);
  sf_mex_destroy(&c26_rhs141);
  sf_mex_destroy(&c26_lhs141);
  sf_mex_destroy(&c26_rhs142);
  sf_mex_destroy(&c26_lhs142);
  sf_mex_destroy(&c26_rhs143);
  sf_mex_destroy(&c26_lhs143);
  sf_mex_destroy(&c26_rhs144);
  sf_mex_destroy(&c26_lhs144);
  sf_mex_destroy(&c26_rhs145);
  sf_mex_destroy(&c26_lhs145);
  sf_mex_destroy(&c26_rhs146);
  sf_mex_destroy(&c26_lhs146);
  sf_mex_destroy(&c26_rhs147);
  sf_mex_destroy(&c26_lhs147);
  sf_mex_destroy(&c26_rhs148);
  sf_mex_destroy(&c26_lhs148);
  sf_mex_destroy(&c26_rhs149);
  sf_mex_destroy(&c26_lhs149);
  sf_mex_destroy(&c26_rhs150);
  sf_mex_destroy(&c26_lhs150);
  sf_mex_destroy(&c26_rhs151);
  sf_mex_destroy(&c26_lhs151);
  sf_mex_destroy(&c26_rhs152);
  sf_mex_destroy(&c26_lhs152);
  sf_mex_destroy(&c26_rhs153);
  sf_mex_destroy(&c26_lhs153);
  sf_mex_destroy(&c26_rhs154);
  sf_mex_destroy(&c26_lhs154);
  sf_mex_destroy(&c26_rhs155);
  sf_mex_destroy(&c26_lhs155);
  sf_mex_destroy(&c26_rhs156);
  sf_mex_destroy(&c26_lhs156);
  sf_mex_destroy(&c26_rhs157);
  sf_mex_destroy(&c26_lhs157);
  sf_mex_destroy(&c26_rhs158);
  sf_mex_destroy(&c26_lhs158);
  sf_mex_destroy(&c26_rhs159);
  sf_mex_destroy(&c26_lhs159);
  sf_mex_destroy(&c26_rhs160);
  sf_mex_destroy(&c26_lhs160);
  sf_mex_destroy(&c26_rhs161);
  sf_mex_destroy(&c26_lhs161);
  sf_mex_destroy(&c26_rhs162);
  sf_mex_destroy(&c26_lhs162);
  sf_mex_destroy(&c26_rhs163);
  sf_mex_destroy(&c26_lhs163);
  sf_mex_destroy(&c26_rhs164);
  sf_mex_destroy(&c26_lhs164);
  sf_mex_destroy(&c26_rhs165);
  sf_mex_destroy(&c26_lhs165);
  sf_mex_destroy(&c26_rhs166);
  sf_mex_destroy(&c26_lhs166);
  sf_mex_destroy(&c26_rhs167);
  sf_mex_destroy(&c26_lhs167);
  sf_mex_destroy(&c26_rhs168);
  sf_mex_destroy(&c26_lhs168);
  sf_mex_destroy(&c26_rhs169);
  sf_mex_destroy(&c26_lhs169);
  sf_mex_destroy(&c26_rhs170);
  sf_mex_destroy(&c26_lhs170);
  sf_mex_destroy(&c26_rhs171);
  sf_mex_destroy(&c26_lhs171);
  sf_mex_destroy(&c26_rhs172);
  sf_mex_destroy(&c26_lhs172);
  sf_mex_destroy(&c26_rhs173);
  sf_mex_destroy(&c26_lhs173);
  sf_mex_destroy(&c26_rhs174);
  sf_mex_destroy(&c26_lhs174);
  sf_mex_destroy(&c26_rhs175);
  sf_mex_destroy(&c26_lhs175);
  sf_mex_destroy(&c26_rhs176);
  sf_mex_destroy(&c26_lhs176);
  sf_mex_destroy(&c26_rhs177);
  sf_mex_destroy(&c26_lhs177);
  sf_mex_destroy(&c26_rhs178);
  sf_mex_destroy(&c26_lhs178);
  sf_mex_destroy(&c26_rhs179);
  sf_mex_destroy(&c26_lhs179);
  sf_mex_destroy(&c26_rhs180);
  sf_mex_destroy(&c26_lhs180);
  sf_mex_destroy(&c26_rhs181);
  sf_mex_destroy(&c26_lhs181);
  sf_mex_destroy(&c26_rhs182);
  sf_mex_destroy(&c26_lhs182);
  sf_mex_destroy(&c26_rhs183);
  sf_mex_destroy(&c26_lhs183);
  sf_mex_destroy(&c26_rhs184);
  sf_mex_destroy(&c26_lhs184);
  sf_mex_destroy(&c26_rhs185);
  sf_mex_destroy(&c26_lhs185);
  sf_mex_destroy(&c26_rhs186);
  sf_mex_destroy(&c26_lhs186);
  sf_mex_destroy(&c26_rhs187);
  sf_mex_destroy(&c26_lhs187);
  sf_mex_destroy(&c26_rhs188);
  sf_mex_destroy(&c26_lhs188);
  sf_mex_destroy(&c26_rhs189);
  sf_mex_destroy(&c26_lhs189);
  sf_mex_destroy(&c26_rhs190);
  sf_mex_destroy(&c26_lhs190);
  sf_mex_destroy(&c26_rhs191);
  sf_mex_destroy(&c26_lhs191);
}

static void c26_d_info_helper(const mxArray **c26_info)
{
  const mxArray *c26_rhs192 = NULL;
  const mxArray *c26_lhs192 = NULL;
  const mxArray *c26_rhs193 = NULL;
  const mxArray *c26_lhs193 = NULL;
  const mxArray *c26_rhs194 = NULL;
  const mxArray *c26_lhs194 = NULL;
  const mxArray *c26_rhs195 = NULL;
  const mxArray *c26_lhs195 = NULL;
  const mxArray *c26_rhs196 = NULL;
  const mxArray *c26_lhs196 = NULL;
  const mxArray *c26_rhs197 = NULL;
  const mxArray *c26_lhs197 = NULL;
  const mxArray *c26_rhs198 = NULL;
  const mxArray *c26_lhs198 = NULL;
  const mxArray *c26_rhs199 = NULL;
  const mxArray *c26_lhs199 = NULL;
  const mxArray *c26_rhs200 = NULL;
  const mxArray *c26_lhs200 = NULL;
  const mxArray *c26_rhs201 = NULL;
  const mxArray *c26_lhs201 = NULL;
  const mxArray *c26_rhs202 = NULL;
  const mxArray *c26_lhs202 = NULL;
  const mxArray *c26_rhs203 = NULL;
  const mxArray *c26_lhs203 = NULL;
  const mxArray *c26_rhs204 = NULL;
  const mxArray *c26_lhs204 = NULL;
  const mxArray *c26_rhs205 = NULL;
  const mxArray *c26_lhs205 = NULL;
  const mxArray *c26_rhs206 = NULL;
  const mxArray *c26_lhs206 = NULL;
  const mxArray *c26_rhs207 = NULL;
  const mxArray *c26_lhs207 = NULL;
  const mxArray *c26_rhs208 = NULL;
  const mxArray *c26_lhs208 = NULL;
  const mxArray *c26_rhs209 = NULL;
  const mxArray *c26_lhs209 = NULL;
  const mxArray *c26_rhs210 = NULL;
  const mxArray *c26_lhs210 = NULL;
  const mxArray *c26_rhs211 = NULL;
  const mxArray *c26_lhs211 = NULL;
  const mxArray *c26_rhs212 = NULL;
  const mxArray *c26_lhs212 = NULL;
  const mxArray *c26_rhs213 = NULL;
  const mxArray *c26_lhs213 = NULL;
  const mxArray *c26_rhs214 = NULL;
  const mxArray *c26_lhs214 = NULL;
  const mxArray *c26_rhs215 = NULL;
  const mxArray *c26_lhs215 = NULL;
  const mxArray *c26_rhs216 = NULL;
  const mxArray *c26_lhs216 = NULL;
  const mxArray *c26_rhs217 = NULL;
  const mxArray *c26_lhs217 = NULL;
  const mxArray *c26_rhs218 = NULL;
  const mxArray *c26_lhs218 = NULL;
  const mxArray *c26_rhs219 = NULL;
  const mxArray *c26_lhs219 = NULL;
  const mxArray *c26_rhs220 = NULL;
  const mxArray *c26_lhs220 = NULL;
  const mxArray *c26_rhs221 = NULL;
  const mxArray *c26_lhs221 = NULL;
  const mxArray *c26_rhs222 = NULL;
  const mxArray *c26_lhs222 = NULL;
  const mxArray *c26_rhs223 = NULL;
  const mxArray *c26_lhs223 = NULL;
  const mxArray *c26_rhs224 = NULL;
  const mxArray *c26_lhs224 = NULL;
  const mxArray *c26_rhs225 = NULL;
  const mxArray *c26_lhs225 = NULL;
  const mxArray *c26_rhs226 = NULL;
  const mxArray *c26_lhs226 = NULL;
  const mxArray *c26_rhs227 = NULL;
  const mxArray *c26_lhs227 = NULL;
  const mxArray *c26_rhs228 = NULL;
  const mxArray *c26_lhs228 = NULL;
  const mxArray *c26_rhs229 = NULL;
  const mxArray *c26_lhs229 = NULL;
  const mxArray *c26_rhs230 = NULL;
  const mxArray *c26_lhs230 = NULL;
  const mxArray *c26_rhs231 = NULL;
  const mxArray *c26_lhs231 = NULL;
  const mxArray *c26_rhs232 = NULL;
  const mxArray *c26_lhs232 = NULL;
  const mxArray *c26_rhs233 = NULL;
  const mxArray *c26_lhs233 = NULL;
  const mxArray *c26_rhs234 = NULL;
  const mxArray *c26_lhs234 = NULL;
  const mxArray *c26_rhs235 = NULL;
  const mxArray *c26_lhs235 = NULL;
  const mxArray *c26_rhs236 = NULL;
  const mxArray *c26_lhs236 = NULL;
  const mxArray *c26_rhs237 = NULL;
  const mxArray *c26_lhs237 = NULL;
  const mxArray *c26_rhs238 = NULL;
  const mxArray *c26_lhs238 = NULL;
  const mxArray *c26_rhs239 = NULL;
  const mxArray *c26_lhs239 = NULL;
  const mxArray *c26_rhs240 = NULL;
  const mxArray *c26_lhs240 = NULL;
  const mxArray *c26_rhs241 = NULL;
  const mxArray *c26_lhs241 = NULL;
  const mxArray *c26_rhs242 = NULL;
  const mxArray *c26_lhs242 = NULL;
  const mxArray *c26_rhs243 = NULL;
  const mxArray *c26_lhs243 = NULL;
  const mxArray *c26_rhs244 = NULL;
  const mxArray *c26_lhs244 = NULL;
  const mxArray *c26_rhs245 = NULL;
  const mxArray *c26_lhs245 = NULL;
  const mxArray *c26_rhs246 = NULL;
  const mxArray *c26_lhs246 = NULL;
  const mxArray *c26_rhs247 = NULL;
  const mxArray *c26_lhs247 = NULL;
  const mxArray *c26_rhs248 = NULL;
  const mxArray *c26_lhs248 = NULL;
  const mxArray *c26_rhs249 = NULL;
  const mxArray *c26_lhs249 = NULL;
  const mxArray *c26_rhs250 = NULL;
  const mxArray *c26_lhs250 = NULL;
  const mxArray *c26_rhs251 = NULL;
  const mxArray *c26_lhs251 = NULL;
  const mxArray *c26_rhs252 = NULL;
  const mxArray *c26_lhs252 = NULL;
  const mxArray *c26_rhs253 = NULL;
  const mxArray *c26_lhs253 = NULL;
  const mxArray *c26_rhs254 = NULL;
  const mxArray *c26_lhs254 = NULL;
  const mxArray *c26_rhs255 = NULL;
  const mxArray *c26_lhs255 = NULL;
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_simtran"),
                  "context", "context", 192);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 192);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 192);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 192);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 192);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 192);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 192);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 192);
  sf_mex_assign(&c26_rhs192, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs192, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs192), "rhs",
                  "rhs", 192);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs192), "lhs",
                  "lhs", 192);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"),
                  "context", "context", 193);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 193);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 193);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 193);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 193);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 193);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 193);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 193);
  sf_mex_assign(&c26_rhs193, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs193, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs193), "rhs",
                  "rhs", 193);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs193), "lhs",
                  "lhs", 193);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_cols"),
                  "context", "context", 194);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 194);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 194);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 194);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 194);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 194);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 194);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 194);
  sf_mex_assign(&c26_rhs194, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs194, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs194), "rhs",
                  "rhs", 194);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs194), "lhs",
                  "lhs", 194);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m!eml_zggbal_eigsearch_cols"),
                  "context", "context", 195);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 195);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 195);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 195);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 195);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 195);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 195);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 195);
  sf_mex_assign(&c26_rhs195, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs195, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs195), "rhs",
                  "rhs", 195);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs195), "lhs",
                  "lhs", 195);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"),
                  "context", "context", 196);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 196);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 196);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 196);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 196);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 196);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 196);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 196);
  sf_mex_assign(&c26_rhs196, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs196, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs196), "rhs",
                  "rhs", 196);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs196), "lhs",
                  "lhs", 196);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 197);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zgghrd"), "name",
                  "name", 197);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 197);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "resolved", "resolved", 197);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786420U), "fileTimeLo",
                  "fileTimeLo", 197);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 197);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 197);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 197);
  sf_mex_assign(&c26_rhs197, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs197, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs197), "rhs",
                  "rhs", 197);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs197), "lhs",
                  "lhs", 197);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 198);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 198);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 198);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 198);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 198);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 198);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 198);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 198);
  sf_mex_assign(&c26_rhs198, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs198, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs198), "rhs",
                  "rhs", 198);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs198), "lhs",
                  "lhs", 198);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 199);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 199);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 199);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 199);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 199);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 199);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 199);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 199);
  sf_mex_assign(&c26_rhs199, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs199, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs199), "rhs",
                  "rhs", 199);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs199), "lhs",
                  "lhs", 199);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 200);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 200);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 200);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 200);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 200);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 200);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 200);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 200);
  sf_mex_assign(&c26_rhs200, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs200, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs200), "rhs",
                  "rhs", 200);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs200), "lhs",
                  "lhs", 200);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 201);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 201);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 201);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 201);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 201);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 201);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 201);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 201);
  sf_mex_assign(&c26_rhs201, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs201, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs201), "rhs",
                  "rhs", 201);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs201), "lhs",
                  "lhs", 201);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 202);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 202);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 202);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 202);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 202);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 202);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 202);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 202);
  sf_mex_assign(&c26_rhs202, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs202, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs202), "rhs",
                  "rhs", 202);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs202), "lhs",
                  "lhs", 202);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 203);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zlartg"), "name",
                  "name", 203);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 203);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "resolved", "resolved", 203);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786422U), "fileTimeLo",
                  "fileTimeLo", 203);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 203);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 203);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 203);
  sf_mex_assign(&c26_rhs203, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs203, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs203), "rhs",
                  "rhs", 203);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs203), "lhs",
                  "lhs", 203);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 204);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmin"), "name", "name",
                  204);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 204);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 204);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 204);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 204);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 204);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 204);
  sf_mex_assign(&c26_rhs204, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs204, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs204), "rhs",
                  "rhs", 204);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs204), "lhs",
                  "lhs", 204);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 205);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eps"), "name", "name", 205);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 205);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 205);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 205);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 205);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 205);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 205);
  sf_mex_assign(&c26_rhs205, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs205, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs205), "rhs",
                  "rhs", 205);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs205), "lhs",
                  "lhs", 205);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 206);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("fix"), "name", "name", 206);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 206);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m"), "resolved",
                  "resolved", 206);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 206);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 206);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 206);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 206);
  sf_mex_assign(&c26_rhs206, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs206, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs206), "rhs",
                  "rhs", 206);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs206), "lhs",
                  "lhs", 206);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m"), "context",
                  "context", 207);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 207);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 207);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 207);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 207);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 207);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 207);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 207);
  sf_mex_assign(&c26_rhs207, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs207, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs207), "rhs",
                  "rhs", 207);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs207), "lhs",
                  "lhs", 207);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m"), "context",
                  "context", 208);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_fix"), "name",
                  "name", 208);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 208);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_fix.m"),
                  "resolved", "resolved", 208);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622438U), "fileTimeLo",
                  "fileTimeLo", 208);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 208);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 208);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 208);
  sf_mex_assign(&c26_rhs208, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs208, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs208), "rhs",
                  "rhs", 208);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs208), "lhs",
                  "lhs", 208);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 209);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mpower"), "name", "name",
                  209);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 209);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 209);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677878U), "fileTimeLo",
                  "fileTimeLo", 209);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 209);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 209);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 209);
  sf_mex_assign(&c26_rhs209, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs209, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs209), "rhs",
                  "rhs", 209);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs209), "lhs",
                  "lhs", 209);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 210);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 210);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 210);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 210);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 210);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 210);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 210);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 210);
  sf_mex_assign(&c26_rhs210, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs210, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs210), "rhs",
                  "rhs", 210);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs210), "lhs",
                  "lhs", 210);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m!absinf"),
                  "context", "context", 211);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 211);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 211);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 211);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 211);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 211);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 211);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 211);
  sf_mex_assign(&c26_rhs211, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs211, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs211), "rhs",
                  "rhs", 211);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs211), "lhs",
                  "lhs", 211);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 212);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 212);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 212);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 212);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 212);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 212);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 212);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 212);
  sf_mex_assign(&c26_rhs212, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs212, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs212), "rhs",
                  "rhs", 212);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs212), "lhs",
                  "lhs", 212);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 213);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 213);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 213);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 213);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 213);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 213);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 213);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 213);
  sf_mex_assign(&c26_rhs213, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs213, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs213), "rhs",
                  "rhs", 213);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs213), "lhs",
                  "lhs", 213);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 214);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_dlapy2"), "name", "name",
                  214);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 214);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                  "resolved", 214);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1350378254U), "fileTimeLo",
                  "fileTimeLo", 214);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 214);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 214);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 214);
  sf_mex_assign(&c26_rhs214, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs214, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs214), "rhs",
                  "rhs", 214);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs214), "lhs",
                  "lhs", 214);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 215);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sqrt"), "name", "name", 215);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 215);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 215);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 215);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 215);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 215);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 215);
  sf_mex_assign(&c26_rhs215, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs215, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs215), "rhs",
                  "rhs", 215);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs215), "lhs",
                  "lhs", 215);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "context", "context", 216);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 216);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 216);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 216);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 216);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 216);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 216);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 216);
  sf_mex_assign(&c26_rhs216, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs216, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs216), "rhs",
                  "rhs", 216);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs216), "lhs",
                  "lhs", 216);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 217);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_zrot_rows"), "name",
                  "name", 217);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 217);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "resolved", "resolved", 217);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1360246352U), "fileTimeLo",
                  "fileTimeLo", 217);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 217);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 217);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 217);
  sf_mex_assign(&c26_rhs217, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs217, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs217), "rhs",
                  "rhs", 217);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs217), "lhs",
                  "lhs", 217);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "context", "context", 218);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 218);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 218);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 218);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 218);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 218);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 218);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 218);
  sf_mex_assign(&c26_rhs218, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs218, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs218), "rhs",
                  "rhs", 218);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs218), "lhs",
                  "lhs", 218);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "context", "context", 219);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 219);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 219);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 219);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 219);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 219);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 219);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 219);
  sf_mex_assign(&c26_rhs219, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs219, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs219), "rhs",
                  "rhs", 219);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs219), "lhs",
                  "lhs", 219);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "context", "context", 220);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.conjtimes"),
                  "name", "name", 220);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 220);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/conjtimes.m"),
                  "resolved", "resolved", 220);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1360246586U), "fileTimeLo",
                  "fileTimeLo", 220);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 220);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 220);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 220);
  sf_mex_assign(&c26_rhs220, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs220, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs220), "rhs",
                  "rhs", 220);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs220), "lhs",
                  "lhs", 220);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"),
                  "context", "context", 221);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_zrot_cols"), "name",
                  "name", 221);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 221);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "resolved", "resolved", 221);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1360246350U), "fileTimeLo",
                  "fileTimeLo", 221);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 221);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 221);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 221);
  sf_mex_assign(&c26_rhs221, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs221, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs221), "rhs",
                  "rhs", 221);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs221), "lhs",
                  "lhs", 221);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "context", "context", 222);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 222);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 222);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 222);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 222);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 222);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 222);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 222);
  sf_mex_assign(&c26_rhs222, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs222, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs222), "rhs",
                  "rhs", 222);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs222), "lhs",
                  "lhs", 222);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "context", "context", 223);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 223);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 223);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 223);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 223);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 223);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 223);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 223);
  sf_mex_assign(&c26_rhs223, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs223, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs223), "rhs",
                  "rhs", 223);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs223), "lhs",
                  "lhs", 223);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "context", "context", 224);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.conjtimes"),
                  "name", "name", 224);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 224);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/conjtimes.m"),
                  "resolved", "resolved", 224);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1360246586U), "fileTimeLo",
                  "fileTimeLo", 224);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 224);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 224);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 224);
  sf_mex_assign(&c26_rhs224, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs224, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs224), "rhs",
                  "rhs", 224);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs224), "lhs",
                  "lhs", 224);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"),
                  "context", "context", 225);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zhgeqz"), "name",
                  "name", 225);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 225);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "resolved", "resolved", 225);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 225);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 225);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 225);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 225);
  sf_mex_assign(&c26_rhs225, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs225, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs225), "rhs",
                  "rhs", 225);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs225), "lhs",
                  "lhs", 225);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 226);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 226);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 226);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 226);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 226);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 226);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 226);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 226);
  sf_mex_assign(&c26_rhs226, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs226, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs226), "rhs",
                  "rhs", 226);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs226), "lhs",
                  "lhs", 226);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 227);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eps"), "name", "name", 227);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 227);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 227);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 227);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 227);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 227);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 227);
  sf_mex_assign(&c26_rhs227, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs227, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs227), "rhs",
                  "rhs", 227);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs227), "lhs",
                  "lhs", 227);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 228);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmin"), "name", "name",
                  228);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 228);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 228);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 228);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 228);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 228);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 228);
  sf_mex_assign(&c26_rhs228, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs228, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs228), "rhs",
                  "rhs", 228);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs228), "lhs",
                  "lhs", 228);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 229);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zlanhs"), "name",
                  "name", 229);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 229);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "resolved", "resolved", 229);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786420U), "fileTimeLo",
                  "fileTimeLo", 229);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 229);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 229);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 229);
  sf_mex_assign(&c26_rhs229, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs229, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs229), "rhs",
                  "rhs", 229);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs229), "lhs",
                  "lhs", 229);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 230);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 230);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 230);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 230);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 230);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 230);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 230);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 230);
  sf_mex_assign(&c26_rhs230, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs230, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs230), "rhs",
                  "rhs", 230);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs230), "lhs",
                  "lhs", 230);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 231);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 231);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 231);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 231);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 231);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 231);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 231);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 231);
  sf_mex_assign(&c26_rhs231, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs231, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs231), "rhs",
                  "rhs", 231);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs231), "lhs",
                  "lhs", 231);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 232);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 232);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 232);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 232);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 232);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 232);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 232);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 232);
  sf_mex_assign(&c26_rhs232, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs232, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs232), "rhs",
                  "rhs", 232);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs232), "lhs",
                  "lhs", 232);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 233);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 233);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 233);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 233);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 233);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 233);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 233);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 233);
  sf_mex_assign(&c26_rhs233, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs233, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs233), "rhs",
                  "rhs", 233);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs233), "lhs",
                  "lhs", 233);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"),
                  "context", "context", 234);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sqrt"), "name", "name", 234);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 234);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 234);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 234);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 234);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 234);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 234);
  sf_mex_assign(&c26_rhs234, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs234, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs234), "rhs",
                  "rhs", 234);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs234), "lhs",
                  "lhs", 234);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 235);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 235);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 235);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 235);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 235);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 235);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 235);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 235);
  sf_mex_assign(&c26_rhs235, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs235, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs235), "rhs",
                  "rhs", 235);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs235), "lhs",
                  "lhs", 235);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 236);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 236);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 236);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 236);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1397228622U), "fileTimeLo",
                  "fileTimeLo", 236);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 236);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 236);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 236);
  sf_mex_assign(&c26_rhs236, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs236, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs236), "rhs",
                  "rhs", 236);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs236), "lhs",
                  "lhs", 236);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 237);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 237);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 237);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 237);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 237);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 237);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 237);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 237);
  sf_mex_assign(&c26_rhs237, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs237, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs237), "rhs",
                  "rhs", 237);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs237), "lhs",
                  "lhs", 237);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 238);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 238);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 238);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 238);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372553616U), "fileTimeLo",
                  "fileTimeLo", 238);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 238);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 238);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 238);
  sf_mex_assign(&c26_rhs238, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs238, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs238), "rhs",
                  "rhs", 238);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs238), "lhs",
                  "lhs", 238);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 239);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 239);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 239);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 239);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1372554360U), "fileTimeLo",
                  "fileTimeLo", 239);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 239);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 239);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 239);
  sf_mex_assign(&c26_rhs239, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs239, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs239), "rhs",
                  "rhs", 239);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs239), "lhs",
                  "lhs", 239);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m!abs1"),
                  "context", "context", 240);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 240);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 240);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 240);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 240);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 240);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 240);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 240);
  sf_mex_assign(&c26_rhs240, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs240, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs240), "rhs",
                  "rhs", 240);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs240), "lhs",
                  "lhs", 240);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 241);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 241);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 241);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 241);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 241);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 241);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 241);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 241);
  sf_mex_assign(&c26_rhs241, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs241, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs241), "rhs",
                  "rhs", 241);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs241), "lhs",
                  "lhs", 241);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 242);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_matlab_zlartg"), "name",
                  "name", 242);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 242);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"),
                  "resolved", "resolved", 242);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786422U), "fileTimeLo",
                  "fileTimeLo", 242);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 242);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 242);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 242);
  sf_mex_assign(&c26_rhs242, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs242, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs242), "rhs",
                  "rhs", 242);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs242), "lhs",
                  "lhs", 242);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 243);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_zrot_cols"), "name",
                  "name", 243);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 243);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"),
                  "resolved", "resolved", 243);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1360246350U), "fileTimeLo",
                  "fileTimeLo", 243);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 243);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 243);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 243);
  sf_mex_assign(&c26_rhs243, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs243, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs243), "rhs",
                  "rhs", 243);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs243), "lhs",
                  "lhs", 243);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 244);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mod"), "name", "name", 244);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 244);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "resolved",
                  "resolved", 244);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677854U), "fileTimeLo",
                  "fileTimeLo", 244);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 244);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 244);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 244);
  sf_mex_assign(&c26_rhs244, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs244, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs244), "rhs",
                  "rhs", 244);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs244), "lhs",
                  "lhs", 244);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 245);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 245);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 245);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 245);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 245);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 245);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 245);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 245);
  sf_mex_assign(&c26_rhs245, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs245, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs245), "rhs",
                  "rhs", 245);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs245), "lhs",
                  "lhs", 245);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 246);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 246);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 246);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 246);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 246);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 246);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 246);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 246);
  sf_mex_assign(&c26_rhs246, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs246, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs246), "rhs",
                  "rhs", 246);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs246), "lhs",
                  "lhs", 246);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 247);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 247);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 247);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 247);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 247);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 247);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 247);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 247);
  sf_mex_assign(&c26_rhs247, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs247, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs247), "rhs",
                  "rhs", 247);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs247), "lhs",
                  "lhs", 247);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 248);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 248);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 248);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 248);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 248);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 248);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 248);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 248);
  sf_mex_assign(&c26_rhs248, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs248, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs248), "rhs",
                  "rhs", 248);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs248), "lhs",
                  "lhs", 248);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 249);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 249);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 249);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 249);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 249);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 249);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 249);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 249);
  sf_mex_assign(&c26_rhs249, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs249, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs249), "rhs",
                  "rhs", 249);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs249), "lhs",
                  "lhs", 249);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!intmod"), "context",
                  "context", 250);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 250);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 250);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 250);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 250);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 250);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 250);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 250);
  sf_mex_assign(&c26_rhs250, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs250, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs250), "rhs",
                  "rhs", 250);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs250), "lhs",
                  "lhs", 250);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 251);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_div"), "name", "name",
                  251);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 251);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 251);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 251);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 251);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 251);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 251);
  sf_mex_assign(&c26_rhs251, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs251, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs251), "rhs",
                  "rhs", 251);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs251), "lhs",
                  "lhs", 251);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                  "context", "context", 252);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 252);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 252);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 252);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 252);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 252);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 252);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 252);
  sf_mex_assign(&c26_rhs252, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs252, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs252), "rhs",
                  "rhs", 252);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs252), "lhs",
                  "lhs", 252);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                  "context", "context", 253);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 253);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 253);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 253);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 253);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 253);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 253);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 253);
  sf_mex_assign(&c26_rhs253, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs253, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs253), "rhs",
                  "rhs", 253);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs253), "lhs",
                  "lhs", 253);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                  "context", "context", 254);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 254);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 254);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 254);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 254);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 254);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 254);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 254);
  sf_mex_assign(&c26_rhs254, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs254, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs254), "rhs",
                  "rhs", 254);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs254), "lhs",
                  "lhs", 254);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 255);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sqrt"), "name", "name", 255);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 255);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 255);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 255);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 255);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 255);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 255);
  sf_mex_assign(&c26_rhs255, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs255, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs255), "rhs",
                  "rhs", 255);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs255), "lhs",
                  "lhs", 255);
  sf_mex_destroy(&c26_rhs192);
  sf_mex_destroy(&c26_lhs192);
  sf_mex_destroy(&c26_rhs193);
  sf_mex_destroy(&c26_lhs193);
  sf_mex_destroy(&c26_rhs194);
  sf_mex_destroy(&c26_lhs194);
  sf_mex_destroy(&c26_rhs195);
  sf_mex_destroy(&c26_lhs195);
  sf_mex_destroy(&c26_rhs196);
  sf_mex_destroy(&c26_lhs196);
  sf_mex_destroy(&c26_rhs197);
  sf_mex_destroy(&c26_lhs197);
  sf_mex_destroy(&c26_rhs198);
  sf_mex_destroy(&c26_lhs198);
  sf_mex_destroy(&c26_rhs199);
  sf_mex_destroy(&c26_lhs199);
  sf_mex_destroy(&c26_rhs200);
  sf_mex_destroy(&c26_lhs200);
  sf_mex_destroy(&c26_rhs201);
  sf_mex_destroy(&c26_lhs201);
  sf_mex_destroy(&c26_rhs202);
  sf_mex_destroy(&c26_lhs202);
  sf_mex_destroy(&c26_rhs203);
  sf_mex_destroy(&c26_lhs203);
  sf_mex_destroy(&c26_rhs204);
  sf_mex_destroy(&c26_lhs204);
  sf_mex_destroy(&c26_rhs205);
  sf_mex_destroy(&c26_lhs205);
  sf_mex_destroy(&c26_rhs206);
  sf_mex_destroy(&c26_lhs206);
  sf_mex_destroy(&c26_rhs207);
  sf_mex_destroy(&c26_lhs207);
  sf_mex_destroy(&c26_rhs208);
  sf_mex_destroy(&c26_lhs208);
  sf_mex_destroy(&c26_rhs209);
  sf_mex_destroy(&c26_lhs209);
  sf_mex_destroy(&c26_rhs210);
  sf_mex_destroy(&c26_lhs210);
  sf_mex_destroy(&c26_rhs211);
  sf_mex_destroy(&c26_lhs211);
  sf_mex_destroy(&c26_rhs212);
  sf_mex_destroy(&c26_lhs212);
  sf_mex_destroy(&c26_rhs213);
  sf_mex_destroy(&c26_lhs213);
  sf_mex_destroy(&c26_rhs214);
  sf_mex_destroy(&c26_lhs214);
  sf_mex_destroy(&c26_rhs215);
  sf_mex_destroy(&c26_lhs215);
  sf_mex_destroy(&c26_rhs216);
  sf_mex_destroy(&c26_lhs216);
  sf_mex_destroy(&c26_rhs217);
  sf_mex_destroy(&c26_lhs217);
  sf_mex_destroy(&c26_rhs218);
  sf_mex_destroy(&c26_lhs218);
  sf_mex_destroy(&c26_rhs219);
  sf_mex_destroy(&c26_lhs219);
  sf_mex_destroy(&c26_rhs220);
  sf_mex_destroy(&c26_lhs220);
  sf_mex_destroy(&c26_rhs221);
  sf_mex_destroy(&c26_lhs221);
  sf_mex_destroy(&c26_rhs222);
  sf_mex_destroy(&c26_lhs222);
  sf_mex_destroy(&c26_rhs223);
  sf_mex_destroy(&c26_lhs223);
  sf_mex_destroy(&c26_rhs224);
  sf_mex_destroy(&c26_lhs224);
  sf_mex_destroy(&c26_rhs225);
  sf_mex_destroy(&c26_lhs225);
  sf_mex_destroy(&c26_rhs226);
  sf_mex_destroy(&c26_lhs226);
  sf_mex_destroy(&c26_rhs227);
  sf_mex_destroy(&c26_lhs227);
  sf_mex_destroy(&c26_rhs228);
  sf_mex_destroy(&c26_lhs228);
  sf_mex_destroy(&c26_rhs229);
  sf_mex_destroy(&c26_lhs229);
  sf_mex_destroy(&c26_rhs230);
  sf_mex_destroy(&c26_lhs230);
  sf_mex_destroy(&c26_rhs231);
  sf_mex_destroy(&c26_lhs231);
  sf_mex_destroy(&c26_rhs232);
  sf_mex_destroy(&c26_lhs232);
  sf_mex_destroy(&c26_rhs233);
  sf_mex_destroy(&c26_lhs233);
  sf_mex_destroy(&c26_rhs234);
  sf_mex_destroy(&c26_lhs234);
  sf_mex_destroy(&c26_rhs235);
  sf_mex_destroy(&c26_lhs235);
  sf_mex_destroy(&c26_rhs236);
  sf_mex_destroy(&c26_lhs236);
  sf_mex_destroy(&c26_rhs237);
  sf_mex_destroy(&c26_lhs237);
  sf_mex_destroy(&c26_rhs238);
  sf_mex_destroy(&c26_lhs238);
  sf_mex_destroy(&c26_rhs239);
  sf_mex_destroy(&c26_lhs239);
  sf_mex_destroy(&c26_rhs240);
  sf_mex_destroy(&c26_lhs240);
  sf_mex_destroy(&c26_rhs241);
  sf_mex_destroy(&c26_lhs241);
  sf_mex_destroy(&c26_rhs242);
  sf_mex_destroy(&c26_lhs242);
  sf_mex_destroy(&c26_rhs243);
  sf_mex_destroy(&c26_lhs243);
  sf_mex_destroy(&c26_rhs244);
  sf_mex_destroy(&c26_lhs244);
  sf_mex_destroy(&c26_rhs245);
  sf_mex_destroy(&c26_lhs245);
  sf_mex_destroy(&c26_rhs246);
  sf_mex_destroy(&c26_lhs246);
  sf_mex_destroy(&c26_rhs247);
  sf_mex_destroy(&c26_lhs247);
  sf_mex_destroy(&c26_rhs248);
  sf_mex_destroy(&c26_lhs248);
  sf_mex_destroy(&c26_rhs249);
  sf_mex_destroy(&c26_lhs249);
  sf_mex_destroy(&c26_rhs250);
  sf_mex_destroy(&c26_lhs250);
  sf_mex_destroy(&c26_rhs251);
  sf_mex_destroy(&c26_lhs251);
  sf_mex_destroy(&c26_rhs252);
  sf_mex_destroy(&c26_lhs252);
  sf_mex_destroy(&c26_rhs253);
  sf_mex_destroy(&c26_lhs253);
  sf_mex_destroy(&c26_rhs254);
  sf_mex_destroy(&c26_lhs254);
  sf_mex_destroy(&c26_rhs255);
  sf_mex_destroy(&c26_lhs255);
}

static void c26_e_info_helper(const mxArray **c26_info)
{
  const mxArray *c26_rhs256 = NULL;
  const mxArray *c26_lhs256 = NULL;
  const mxArray *c26_rhs257 = NULL;
  const mxArray *c26_lhs257 = NULL;
  const mxArray *c26_rhs258 = NULL;
  const mxArray *c26_lhs258 = NULL;
  const mxArray *c26_rhs259 = NULL;
  const mxArray *c26_lhs259 = NULL;
  const mxArray *c26_rhs260 = NULL;
  const mxArray *c26_lhs260 = NULL;
  const mxArray *c26_rhs261 = NULL;
  const mxArray *c26_lhs261 = NULL;
  const mxArray *c26_rhs262 = NULL;
  const mxArray *c26_lhs262 = NULL;
  const mxArray *c26_rhs263 = NULL;
  const mxArray *c26_lhs263 = NULL;
  const mxArray *c26_rhs264 = NULL;
  const mxArray *c26_lhs264 = NULL;
  const mxArray *c26_rhs265 = NULL;
  const mxArray *c26_lhs265 = NULL;
  const mxArray *c26_rhs266 = NULL;
  const mxArray *c26_lhs266 = NULL;
  const mxArray *c26_rhs267 = NULL;
  const mxArray *c26_lhs267 = NULL;
  const mxArray *c26_rhs268 = NULL;
  const mxArray *c26_lhs268 = NULL;
  const mxArray *c26_rhs269 = NULL;
  const mxArray *c26_lhs269 = NULL;
  const mxArray *c26_rhs270 = NULL;
  const mxArray *c26_lhs270 = NULL;
  const mxArray *c26_rhs271 = NULL;
  const mxArray *c26_lhs271 = NULL;
  const mxArray *c26_rhs272 = NULL;
  const mxArray *c26_lhs272 = NULL;
  const mxArray *c26_rhs273 = NULL;
  const mxArray *c26_lhs273 = NULL;
  const mxArray *c26_rhs274 = NULL;
  const mxArray *c26_lhs274 = NULL;
  const mxArray *c26_rhs275 = NULL;
  const mxArray *c26_lhs275 = NULL;
  const mxArray *c26_rhs276 = NULL;
  const mxArray *c26_lhs276 = NULL;
  const mxArray *c26_rhs277 = NULL;
  const mxArray *c26_lhs277 = NULL;
  const mxArray *c26_rhs278 = NULL;
  const mxArray *c26_lhs278 = NULL;
  const mxArray *c26_rhs279 = NULL;
  const mxArray *c26_lhs279 = NULL;
  const mxArray *c26_rhs280 = NULL;
  const mxArray *c26_lhs280 = NULL;
  const mxArray *c26_rhs281 = NULL;
  const mxArray *c26_lhs281 = NULL;
  const mxArray *c26_rhs282 = NULL;
  const mxArray *c26_lhs282 = NULL;
  const mxArray *c26_rhs283 = NULL;
  const mxArray *c26_lhs283 = NULL;
  const mxArray *c26_rhs284 = NULL;
  const mxArray *c26_lhs284 = NULL;
  const mxArray *c26_rhs285 = NULL;
  const mxArray *c26_lhs285 = NULL;
  const mxArray *c26_rhs286 = NULL;
  const mxArray *c26_lhs286 = NULL;
  const mxArray *c26_rhs287 = NULL;
  const mxArray *c26_lhs287 = NULL;
  const mxArray *c26_rhs288 = NULL;
  const mxArray *c26_lhs288 = NULL;
  const mxArray *c26_rhs289 = NULL;
  const mxArray *c26_lhs289 = NULL;
  const mxArray *c26_rhs290 = NULL;
  const mxArray *c26_lhs290 = NULL;
  const mxArray *c26_rhs291 = NULL;
  const mxArray *c26_lhs291 = NULL;
  const mxArray *c26_rhs292 = NULL;
  const mxArray *c26_lhs292 = NULL;
  const mxArray *c26_rhs293 = NULL;
  const mxArray *c26_lhs293 = NULL;
  const mxArray *c26_rhs294 = NULL;
  const mxArray *c26_lhs294 = NULL;
  const mxArray *c26_rhs295 = NULL;
  const mxArray *c26_lhs295 = NULL;
  const mxArray *c26_rhs296 = NULL;
  const mxArray *c26_lhs296 = NULL;
  const mxArray *c26_rhs297 = NULL;
  const mxArray *c26_lhs297 = NULL;
  const mxArray *c26_rhs298 = NULL;
  const mxArray *c26_lhs298 = NULL;
  const mxArray *c26_rhs299 = NULL;
  const mxArray *c26_lhs299 = NULL;
  const mxArray *c26_rhs300 = NULL;
  const mxArray *c26_lhs300 = NULL;
  const mxArray *c26_rhs301 = NULL;
  const mxArray *c26_lhs301 = NULL;
  const mxArray *c26_rhs302 = NULL;
  const mxArray *c26_lhs302 = NULL;
  const mxArray *c26_rhs303 = NULL;
  const mxArray *c26_lhs303 = NULL;
  const mxArray *c26_rhs304 = NULL;
  const mxArray *c26_lhs304 = NULL;
  const mxArray *c26_rhs305 = NULL;
  const mxArray *c26_lhs305 = NULL;
  const mxArray *c26_rhs306 = NULL;
  const mxArray *c26_lhs306 = NULL;
  const mxArray *c26_rhs307 = NULL;
  const mxArray *c26_lhs307 = NULL;
  const mxArray *c26_rhs308 = NULL;
  const mxArray *c26_lhs308 = NULL;
  const mxArray *c26_rhs309 = NULL;
  const mxArray *c26_lhs309 = NULL;
  const mxArray *c26_rhs310 = NULL;
  const mxArray *c26_lhs310 = NULL;
  const mxArray *c26_rhs311 = NULL;
  const mxArray *c26_lhs311 = NULL;
  const mxArray *c26_rhs312 = NULL;
  const mxArray *c26_lhs312 = NULL;
  const mxArray *c26_rhs313 = NULL;
  const mxArray *c26_lhs313 = NULL;
  const mxArray *c26_rhs314 = NULL;
  const mxArray *c26_lhs314 = NULL;
  const mxArray *c26_rhs315 = NULL;
  const mxArray *c26_lhs315 = NULL;
  const mxArray *c26_rhs316 = NULL;
  const mxArray *c26_lhs316 = NULL;
  const mxArray *c26_rhs317 = NULL;
  const mxArray *c26_lhs317 = NULL;
  const mxArray *c26_rhs318 = NULL;
  const mxArray *c26_lhs318 = NULL;
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 256);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("rdivide"), "name", "name",
                  256);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 256);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 256);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 256);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 256);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 256);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 256);
  sf_mex_assign(&c26_rhs256, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs256, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs256), "rhs",
                  "rhs", 256);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs256), "lhs",
                  "lhs", 256);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 257);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnan"), "name", "name", 257);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 257);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 257);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 257);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 257);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 257);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 257);
  sf_mex_assign(&c26_rhs257, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs257, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs257), "rhs",
                  "rhs", 257);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs257), "lhs",
                  "lhs", 257);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 258);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 258);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 258);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 258);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 258);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 258);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 258);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 258);
  sf_mex_assign(&c26_rhs258, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs258, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs258), "rhs",
                  "rhs", 258);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs258), "lhs",
                  "lhs", 258);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 259);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isinf"), "name", "name", 259);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 259);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 259);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 259);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 259);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 259);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 259);
  sf_mex_assign(&c26_rhs259, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs259, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs259), "rhs",
                  "rhs", 259);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs259), "lhs",
                  "lhs", 259);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 260);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_guarded_inf"), "name",
                  "name", 260);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 260);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m"),
                  "resolved", "resolved", 260);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 260);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 260);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 260);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 260);
  sf_mex_assign(&c26_rhs260, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs260, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs260), "rhs",
                  "rhs", 260);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs260), "lhs",
                  "lhs", 260);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m"),
                  "context", "context", 261);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 261);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 261);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 261);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786382U), "fileTimeLo",
                  "fileTimeLo", 261);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 261);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 261);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 261);
  sf_mex_assign(&c26_rhs261, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs261, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs261), "rhs",
                  "rhs", 261);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs261), "lhs",
                  "lhs", 261);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 262);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmax"), "name", "name",
                  262);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 262);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 262);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 262);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 262);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 262);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 262);
  sf_mex_assign(&c26_rhs262, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs262, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs262), "rhs",
                  "rhs", 262);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs262), "lhs",
                  "lhs", 262);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 263);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 263);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 263);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 263);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 263);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 263);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 263);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 263);
  sf_mex_assign(&c26_rhs263, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs263, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs263), "rhs",
                  "rhs", 263);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs263), "lhs",
                  "lhs", 263);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 264);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 264);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 264);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 264);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 264);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 264);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 264);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 264);
  sf_mex_assign(&c26_rhs264, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs264, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs264), "rhs",
                  "rhs", 264);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs264), "lhs",
                  "lhs", 264);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 265);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  265);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 265);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 265);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 265);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 265);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 265);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 265);
  sf_mex_assign(&c26_rhs265, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs265, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs265), "rhs",
                  "rhs", 265);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs265), "lhs",
                  "lhs", 265);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                  "context", "context", 266);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_hypot"), "name",
                  "name", 266);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 266);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "resolved", "resolved", 266);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 266);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 266);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 266);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 266);
  sf_mex_assign(&c26_rhs266, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs266, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs266), "rhs",
                  "rhs", 266);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs266), "lhs",
                  "lhs", 266);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "context", "context", 267);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 267);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 267);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 267);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 267);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 267);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 267);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 267);
  sf_mex_assign(&c26_rhs267, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs267, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs267), "rhs",
                  "rhs", 267);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs267), "lhs",
                  "lhs", 267);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "context", "context", 268);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_dlapy2"), "name", "name",
                  268);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 268);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                  "resolved", 268);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1350378254U), "fileTimeLo",
                  "fileTimeLo", 268);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 268);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 268);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 268);
  sf_mex_assign(&c26_rhs268, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs268, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs268), "rhs",
                  "rhs", 268);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs268), "lhs",
                  "lhs", 268);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 269);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 269);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 269);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 269);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 269);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 269);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 269);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 269);
  sf_mex_assign(&c26_rhs269, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs269, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs269), "rhs",
                  "rhs", 269);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs269), "lhs",
                  "lhs", 269);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"),
                  "context", "context", 270);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_zrot_rows"), "name",
                  "name", 270);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 270);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"),
                  "resolved", "resolved", 270);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1360246352U), "fileTimeLo",
                  "fileTimeLo", 270);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 270);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 270);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 270);
  sf_mex_assign(&c26_rhs270, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs270, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs270), "rhs",
                  "rhs", 270);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs270), "lhs",
                  "lhs", 270);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m!makeD"), "context",
                  "context", 271);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("rdivide"), "name", "name",
                  271);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 271);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 271);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 271);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 271);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 271);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 271);
  sf_mex_assign(&c26_rhs271, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs271, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs271), "rhs",
                  "rhs", 271);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs271), "lhs",
                  "lhs", 271);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "context", "context", 272);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isequal"), "name", "name",
                  272);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 272);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 272);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786358U), "fileTimeLo",
                  "fileTimeLo", 272);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 272);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 272);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 272);
  sf_mex_assign(&c26_rhs272, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs272, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs272), "rhs",
                  "rhs", 272);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs272), "lhs",
                  "lhs", 272);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 273);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 273);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 273);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 273);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786386U), "fileTimeLo",
                  "fileTimeLo", 273);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 273);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 273);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 273);
  sf_mex_assign(&c26_rhs273, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs273, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs273), "rhs",
                  "rhs", 273);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs273), "lhs",
                  "lhs", 273);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 274);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnan"), "name", "name", 274);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 274);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 274);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 274);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 274);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 274);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 274);
  sf_mex_assign(&c26_rhs274, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs274, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs274), "rhs",
                  "rhs", 274);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs274), "lhs",
                  "lhs", 274);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p!equalsize"),
                  "context", "context", 275);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("max"), "name", "name", 275);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 275);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 275);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 275);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 275);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 275);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 275);
  sf_mex_assign(&c26_rhs275, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs275, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs275), "rhs",
                  "rhs", 275);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs275), "lhs",
                  "lhs", 275);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/eig.m"), "context",
                  "context", 276);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_warning"), "name",
                  "name", 276);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 276);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 276);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786402U), "fileTimeLo",
                  "fileTimeLo", 276);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 276);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 276);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 276);
  sf_mex_assign(&c26_rhs276, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs276, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs276), "rhs",
                  "rhs", 276);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs276), "lhs",
                  "lhs", 276);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context",
                  277);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("min"), "name", "name", 277);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 277);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 277);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1311226518U), "fileTimeLo",
                  "fileTimeLo", 277);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 277);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 277);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 277);
  sf_mex_assign(&c26_rhs277, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs277, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs277), "rhs",
                  "rhs", 277);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs277), "lhs",
                  "lhs", 277);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 278);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("realmax"), "name", "name",
                  278);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 278);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 278);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 278);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 278);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 278);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 278);
  sf_mex_assign(&c26_rhs278, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs278, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs278), "rhs",
                  "rhs", 278);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs278), "lhs",
                  "lhs", 278);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 279);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  279);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 279);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 279);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 279);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 279);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 279);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 279);
  sf_mex_assign(&c26_rhs279, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs279, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs279), "rhs",
                  "rhs", 279);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs279), "lhs",
                  "lhs", 279);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 280);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 280);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 280);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 280);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 280);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 280);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 280);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 280);
  sf_mex_assign(&c26_rhs280, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs280, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs280), "rhs",
                  "rhs", 280);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs280), "lhs",
                  "lhs", 280);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 281);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("hypot"), "name", "name", 281);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 281);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "resolved",
                  "resolved", 281);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395292500U), "fileTimeLo",
                  "fileTimeLo", 281);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 281);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 281);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 281);
  sf_mex_assign(&c26_rhs281, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs281, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs281), "rhs",
                  "rhs", 281);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs281), "lhs",
                  "lhs", 281);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 282);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 282);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 282);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 282);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 282);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 282);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 282);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 282);
  sf_mex_assign(&c26_rhs282, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs282, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs282), "rhs",
                  "rhs", 282);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs282), "lhs",
                  "lhs", 282);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 283);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 283);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 283);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 283);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 283);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 283);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 283);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 283);
  sf_mex_assign(&c26_rhs283, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs283, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs283), "rhs",
                  "rhs", 283);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs283), "lhs",
                  "lhs", 283);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/hypot.m"), "context",
                  "context", 284);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_hypot"), "name",
                  "name", 284);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 284);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                  "resolved", "resolved", 284);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 284);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 284);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 284);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 284);
  sf_mex_assign(&c26_rhs284, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs284, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs284), "rhs",
                  "rhs", 284);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs284), "lhs",
                  "lhs", 284);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 285);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_safe_eq"), "name",
                  "name", 285);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 285);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "resolved",
                  "resolved", 285);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1383841286U), "fileTimeLo",
                  "fileTimeLo", 285);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 285);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 285);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 285);
  sf_mex_assign(&c26_rhs285, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs285, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs285), "rhs",
                  "rhs", 285);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs285), "lhs",
                  "lhs", 285);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 286);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 286);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 286);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 286);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 286);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 286);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 286);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 286);
  sf_mex_assign(&c26_rhs286, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs286, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs286), "rhs",
                  "rhs", 286);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs286), "lhs",
                  "lhs", 286);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 287);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  287);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 287);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 287);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 287);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 287);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 287);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 287);
  sf_mex_assign(&c26_rhs287, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs287, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs287), "rhs",
                  "rhs", 287);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs287), "lhs",
                  "lhs", 287);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 288);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eps"), "name", "name", 288);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 288);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 288);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 288);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 288);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 288);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 288);
  sf_mex_assign(&c26_rhs288, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs288, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs288), "rhs",
                  "rhs", 288);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs288), "lhs",
                  "lhs", 288);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 289);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_mantissa_nbits"), "name",
                  "name", 289);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 289);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m"),
                  "resolved", "resolved", 289);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622442U), "fileTimeLo",
                  "fileTimeLo", 289);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 289);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 289);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 289);
  sf_mex_assign(&c26_rhs289, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs289, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs289), "rhs",
                  "rhs", 289);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs289), "lhs",
                  "lhs", 289);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m"),
                  "context", "context", 290);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 290);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 290);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 290);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 290);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 290);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 290);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 290);
  sf_mex_assign(&c26_rhs290, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs290, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs290), "rhs",
                  "rhs", 290);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs290), "lhs",
                  "lhs", 290);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 291);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 291);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 291);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 291);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1307622444U), "fileTimeLo",
                  "fileTimeLo", 291);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 291);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 291);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 291);
  sf_mex_assign(&c26_rhs291, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs291, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs291), "rhs",
                  "rhs", 291);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs291), "lhs",
                  "lhs", 291);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 292);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_realmin_denormal"),
                  "name", "name", 292);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 292);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m"),
                  "resolved", "resolved", 292);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691998U), "fileTimeLo",
                  "fileTimeLo", 292);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 292);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 292);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 292);
  sf_mex_assign(&c26_rhs292, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs292, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs292), "rhs",
                  "rhs", 292);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs292), "lhs",
                  "lhs", 292);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m"),
                  "context", "context", 293);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 293);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 293);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 293);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 293);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 293);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 293);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 293);
  sf_mex_assign(&c26_rhs293, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs293, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs293), "rhs",
                  "rhs", 293);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs293), "lhs",
                  "lhs", 293);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 294);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 294);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 294);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 294);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 294);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 294);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 294);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 294);
  sf_mex_assign(&c26_rhs294, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs294, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs294), "rhs",
                  "rhs", 294);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs294), "lhs",
                  "lhs", 294);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 295);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isfinite"), "name", "name",
                  295);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 295);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 295);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 295);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 295);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 295);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 295);
  sf_mex_assign(&c26_rhs295, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs295, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs295), "rhs",
                  "rhs", 295);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs295), "lhs",
                  "lhs", 295);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 296);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 296);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 296);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 296);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 296);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 296);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 296);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 296);
  sf_mex_assign(&c26_rhs296, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs296, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs296), "rhs",
                  "rhs", 296);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs296), "lhs",
                  "lhs", 296);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 297);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isinf"), "name", "name", 297);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 297);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 297);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 297);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 297);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 297);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 297);
  sf_mex_assign(&c26_rhs297, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs297, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs297), "rhs",
                  "rhs", 297);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs297), "lhs",
                  "lhs", 297);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m!map_to_real_proxies"),
                  "context", "context", 298);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("angle"), "name", "name", 298);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 298);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/angle.m"), "resolved",
                  "resolved", 298);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801570U), "fileTimeLo",
                  "fileTimeLo", 298);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 298);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 298);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 298);
  sf_mex_assign(&c26_rhs298, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs298, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs298), "rhs",
                  "rhs", 298);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs298), "lhs",
                  "lhs", 298);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/angle.m"), "context",
                  "context", 299);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_angle"), "name",
                  "name", 299);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 299);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_angle.m"),
                  "resolved", "resolved", 299);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786316U), "fileTimeLo",
                  "fileTimeLo", 299);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 299);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 299);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 299);
  sf_mex_assign(&c26_rhs299, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs299, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs299), "rhs",
                  "rhs", 299);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs299), "lhs",
                  "lhs", 299);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_angle.m"),
                  "context", "context", 300);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 300);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 300);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 300);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786320U), "fileTimeLo",
                  "fileTimeLo", 300);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 300);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 300);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 300);
  sf_mex_assign(&c26_rhs300, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs300, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs300), "rhs",
                  "rhs", 300);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs300), "lhs",
                  "lhs", 300);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context",
                  301);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("inv"), "name", "name", 301);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 301);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m"), "resolved",
                  "resolved", 301);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1305289200U), "fileTimeLo",
                  "fileTimeLo", 301);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 301);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 301);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 301);
  sf_mex_assign(&c26_rhs301, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs301, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs301), "rhs",
                  "rhs", 301);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs301), "lhs",
                  "lhs", 301);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2"), "context",
                  "context", 302);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  302);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 302);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 302);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 302);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 302);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 302);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 302);
  sf_mex_assign(&c26_rhs302, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs302, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs302), "rhs",
                  "rhs", 302);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs302), "lhs",
                  "lhs", 302);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 303);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 303);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 303);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 303);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 303);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 303);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 303);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 303);
  sf_mex_assign(&c26_rhs303, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs303, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs303), "rhs",
                  "rhs", 303);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs303), "lhs",
                  "lhs", 303);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 304);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 304);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 304);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 304);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 304);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 304);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 304);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 304);
  sf_mex_assign(&c26_rhs304, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs304, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs304), "rhs",
                  "rhs", 304);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs304), "lhs",
                  "lhs", 304);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2"), "context",
                  "context", 305);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("mrdivide"), "name", "name",
                  305);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 305);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 305);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 305);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 305);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 305);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 305);
  sf_mex_assign(&c26_rhs305, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs305, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs305), "rhs",
                  "rhs", 305);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs305), "lhs",
                  "lhs", 305);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 306);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("norm"), "name", "name", 306);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 306);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 306);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677868U), "fileTimeLo",
                  "fileTimeLo", 306);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 306);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 306);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 306);
  sf_mex_assign(&c26_rhs306, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs306, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs306), "rhs",
                  "rhs", 306);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs306), "lhs",
                  "lhs", 306);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 307);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 307);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 307);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 307);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 307);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 307);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 307);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 307);
  sf_mex_assign(&c26_rhs307, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs307, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs307), "rhs",
                  "rhs", 307);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs307), "lhs",
                  "lhs", 307);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 308);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("abs"), "name", "name", 308);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 308);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 308);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 308);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 308);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 308);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 308);
  sf_mex_assign(&c26_rhs308, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs308, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs308), "rhs",
                  "rhs", 308);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs308), "lhs",
                  "lhs", 308);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 309);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnan"), "name", "name", 309);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 309);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 309);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 309);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 309);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 309);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 309);
  sf_mex_assign(&c26_rhs309, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs309, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs309), "rhs",
                  "rhs", 309);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs309), "lhs",
                  "lhs", 309);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 310);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 310);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 310);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 310);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786376U), "fileTimeLo",
                  "fileTimeLo", 310);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 310);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 310);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 310);
  sf_mex_assign(&c26_rhs310, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs310, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs310), "rhs",
                  "rhs", 310);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs310), "lhs",
                  "lhs", 310);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 311);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_warning"), "name",
                  "name", 311);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 311);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 311);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786402U), "fileTimeLo",
                  "fileTimeLo", 311);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 311);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 311);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 311);
  sf_mex_assign(&c26_rhs311, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs311, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs311), "rhs",
                  "rhs", 311);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs311), "lhs",
                  "lhs", 311);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 312);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("isnan"), "name", "name", 312);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 312);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 312);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1363677858U), "fileTimeLo",
                  "fileTimeLo", 312);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 312);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 312);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 312);
  sf_mex_assign(&c26_rhs312, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs312, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs312), "rhs",
                  "rhs", 312);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs312), "lhs",
                  "lhs", 312);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 313);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eps"), "name", "name", 313);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 313);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 313);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1326691996U), "fileTimeLo",
                  "fileTimeLo", 313);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 313);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 313);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 313);
  sf_mex_assign(&c26_rhs313, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs313, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs313), "rhs",
                  "rhs", 313);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs313), "lhs",
                  "lhs", 313);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 314);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_flt2str"), "name",
                  "name", 314);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 314);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "resolved",
                  "resolved", 314);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1360246350U), "fileTimeLo",
                  "fileTimeLo", 314);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 314);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 314);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 314);
  sf_mex_assign(&c26_rhs314, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs314, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs314), "rhs",
                  "rhs", 314);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs314), "lhs",
                  "lhs", 314);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "context",
                  "context", 315);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "name", "name", 315);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 315);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 315);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1319697568U), "fileTimeLo",
                  "fileTimeLo", 315);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 315);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 315);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 315);
  sf_mex_assign(&c26_rhs315, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs315, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs315), "rhs",
                  "rhs", 315);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs315), "lhs",
                  "lhs", 315);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context",
                  316);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("max"), "name", "name", 316);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 316);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 316);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1311226516U), "fileTimeLo",
                  "fileTimeLo", 316);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 316);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 316);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 316);
  sf_mex_assign(&c26_rhs316, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs316, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs316), "rhs",
                  "rhs", 316);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs316), "lhs",
                  "lhs", 316);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context",
                  317);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sqrt"), "name", "name", 317);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 317);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 317);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 317);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 317);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 317);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 317);
  sf_mex_assign(&c26_rhs317, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs317, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs317), "rhs",
                  "rhs", 317);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs317), "lhs",
                  "lhs", 317);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context",
                  318);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 318);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 318);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 318);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 318);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 318);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 318);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 318);
  sf_mex_assign(&c26_rhs318, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c26_lhs318, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_rhs318), "rhs",
                  "rhs", 318);
  sf_mex_addfield(*c26_info, sf_mex_duplicatearraysafe(&c26_lhs318), "lhs",
                  "lhs", 318);
  sf_mex_destroy(&c26_rhs256);
  sf_mex_destroy(&c26_lhs256);
  sf_mex_destroy(&c26_rhs257);
  sf_mex_destroy(&c26_lhs257);
  sf_mex_destroy(&c26_rhs258);
  sf_mex_destroy(&c26_lhs258);
  sf_mex_destroy(&c26_rhs259);
  sf_mex_destroy(&c26_lhs259);
  sf_mex_destroy(&c26_rhs260);
  sf_mex_destroy(&c26_lhs260);
  sf_mex_destroy(&c26_rhs261);
  sf_mex_destroy(&c26_lhs261);
  sf_mex_destroy(&c26_rhs262);
  sf_mex_destroy(&c26_lhs262);
  sf_mex_destroy(&c26_rhs263);
  sf_mex_destroy(&c26_lhs263);
  sf_mex_destroy(&c26_rhs264);
  sf_mex_destroy(&c26_lhs264);
  sf_mex_destroy(&c26_rhs265);
  sf_mex_destroy(&c26_lhs265);
  sf_mex_destroy(&c26_rhs266);
  sf_mex_destroy(&c26_lhs266);
  sf_mex_destroy(&c26_rhs267);
  sf_mex_destroy(&c26_lhs267);
  sf_mex_destroy(&c26_rhs268);
  sf_mex_destroy(&c26_lhs268);
  sf_mex_destroy(&c26_rhs269);
  sf_mex_destroy(&c26_lhs269);
  sf_mex_destroy(&c26_rhs270);
  sf_mex_destroy(&c26_lhs270);
  sf_mex_destroy(&c26_rhs271);
  sf_mex_destroy(&c26_lhs271);
  sf_mex_destroy(&c26_rhs272);
  sf_mex_destroy(&c26_lhs272);
  sf_mex_destroy(&c26_rhs273);
  sf_mex_destroy(&c26_lhs273);
  sf_mex_destroy(&c26_rhs274);
  sf_mex_destroy(&c26_lhs274);
  sf_mex_destroy(&c26_rhs275);
  sf_mex_destroy(&c26_lhs275);
  sf_mex_destroy(&c26_rhs276);
  sf_mex_destroy(&c26_lhs276);
  sf_mex_destroy(&c26_rhs277);
  sf_mex_destroy(&c26_lhs277);
  sf_mex_destroy(&c26_rhs278);
  sf_mex_destroy(&c26_lhs278);
  sf_mex_destroy(&c26_rhs279);
  sf_mex_destroy(&c26_lhs279);
  sf_mex_destroy(&c26_rhs280);
  sf_mex_destroy(&c26_lhs280);
  sf_mex_destroy(&c26_rhs281);
  sf_mex_destroy(&c26_lhs281);
  sf_mex_destroy(&c26_rhs282);
  sf_mex_destroy(&c26_lhs282);
  sf_mex_destroy(&c26_rhs283);
  sf_mex_destroy(&c26_lhs283);
  sf_mex_destroy(&c26_rhs284);
  sf_mex_destroy(&c26_lhs284);
  sf_mex_destroy(&c26_rhs285);
  sf_mex_destroy(&c26_lhs285);
  sf_mex_destroy(&c26_rhs286);
  sf_mex_destroy(&c26_lhs286);
  sf_mex_destroy(&c26_rhs287);
  sf_mex_destroy(&c26_lhs287);
  sf_mex_destroy(&c26_rhs288);
  sf_mex_destroy(&c26_lhs288);
  sf_mex_destroy(&c26_rhs289);
  sf_mex_destroy(&c26_lhs289);
  sf_mex_destroy(&c26_rhs290);
  sf_mex_destroy(&c26_lhs290);
  sf_mex_destroy(&c26_rhs291);
  sf_mex_destroy(&c26_lhs291);
  sf_mex_destroy(&c26_rhs292);
  sf_mex_destroy(&c26_lhs292);
  sf_mex_destroy(&c26_rhs293);
  sf_mex_destroy(&c26_lhs293);
  sf_mex_destroy(&c26_rhs294);
  sf_mex_destroy(&c26_lhs294);
  sf_mex_destroy(&c26_rhs295);
  sf_mex_destroy(&c26_lhs295);
  sf_mex_destroy(&c26_rhs296);
  sf_mex_destroy(&c26_lhs296);
  sf_mex_destroy(&c26_rhs297);
  sf_mex_destroy(&c26_lhs297);
  sf_mex_destroy(&c26_rhs298);
  sf_mex_destroy(&c26_lhs298);
  sf_mex_destroy(&c26_rhs299);
  sf_mex_destroy(&c26_lhs299);
  sf_mex_destroy(&c26_rhs300);
  sf_mex_destroy(&c26_lhs300);
  sf_mex_destroy(&c26_rhs301);
  sf_mex_destroy(&c26_lhs301);
  sf_mex_destroy(&c26_rhs302);
  sf_mex_destroy(&c26_lhs302);
  sf_mex_destroy(&c26_rhs303);
  sf_mex_destroy(&c26_lhs303);
  sf_mex_destroy(&c26_rhs304);
  sf_mex_destroy(&c26_lhs304);
  sf_mex_destroy(&c26_rhs305);
  sf_mex_destroy(&c26_lhs305);
  sf_mex_destroy(&c26_rhs306);
  sf_mex_destroy(&c26_lhs306);
  sf_mex_destroy(&c26_rhs307);
  sf_mex_destroy(&c26_lhs307);
  sf_mex_destroy(&c26_rhs308);
  sf_mex_destroy(&c26_lhs308);
  sf_mex_destroy(&c26_rhs309);
  sf_mex_destroy(&c26_lhs309);
  sf_mex_destroy(&c26_rhs310);
  sf_mex_destroy(&c26_lhs310);
  sf_mex_destroy(&c26_rhs311);
  sf_mex_destroy(&c26_lhs311);
  sf_mex_destroy(&c26_rhs312);
  sf_mex_destroy(&c26_lhs312);
  sf_mex_destroy(&c26_rhs313);
  sf_mex_destroy(&c26_lhs313);
  sf_mex_destroy(&c26_rhs314);
  sf_mex_destroy(&c26_lhs314);
  sf_mex_destroy(&c26_rhs315);
  sf_mex_destroy(&c26_lhs315);
  sf_mex_destroy(&c26_rhs316);
  sf_mex_destroy(&c26_lhs316);
  sf_mex_destroy(&c26_rhs317);
  sf_mex_destroy(&c26_lhs317);
  sf_mex_destroy(&c26_rhs318);
  sf_mex_destroy(&c26_lhs318);
}

static void c26_eml_scalar_eg(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c26_assert(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c26_rdivide(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_x, real_T c26_y)
{
  real_T c26_b_x;
  real_T c26_b_y;
  real_T c26_c_x;
  real_T c26_c_y;
  (void)chartInstance;
  c26_b_x = c26_x;
  c26_b_y = c26_y;
  c26_c_x = c26_b_x;
  c26_c_y = c26_b_y;
  return c26_c_x / c26_c_y;
}

static real_T c26_norm(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x[2])
{
  real_T c26_y;
  real_T c26_scale;
  int32_T c26_k;
  int32_T c26_b_k;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_absxk;
  real_T c26_t;
  c26_threshold(chartInstance);
  c26_y = 0.0;
  c26_eml_realmin(chartInstance);
  c26_scale = 2.2250738585072014E-308;
  c26_eml_switch_helper(chartInstance);
  for (c26_k = 1; c26_k < 3; c26_k++) {
    c26_b_k = c26_k;
    c26_b_x = c26_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c26_b_k), 1, 2, 1, 0) - 1];
    c26_c_x = c26_b_x;
    c26_absxk = muDoubleScalarAbs(c26_c_x);
    if (c26_absxk > c26_scale) {
      c26_t = c26_scale / c26_absxk;
      c26_y = 1.0 + c26_y * c26_t * c26_t;
      c26_scale = c26_absxk;
    } else {
      c26_t = c26_absxk / c26_scale;
      c26_y += c26_t * c26_t;
    }
  }

  return c26_scale * muDoubleScalarSqrt(c26_y);
}

static void c26_threshold(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c26_realmin(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  c26_eml_realmin(chartInstance);
}

static void c26_eml_realmin(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c26_eml_switch_helper(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c26_abs(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
                      c26_x)
{
  real_T c26_b_x;
  (void)chartInstance;
  c26_b_x = c26_x;
  return muDoubleScalarAbs(c26_b_x);
}

static real_T c26_b_norm(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x[4])
{
  int32_T c26_k;
  int32_T c26_b_k;
  int32_T c26_i156;
  real_T c26_b_x[4];
  real_T c26_s[2];
  c26_eml_switch_helper(chartInstance);
  for (c26_k = 1; c26_k < 5; c26_k++) {
    c26_b_k = c26_k;
    if (!c26_isfinite(chartInstance, c26_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 4, 1, 0) - 1])) {
      c26_eml_error(chartInstance);
    }
  }

  for (c26_i156 = 0; c26_i156 < 4; c26_i156++) {
    c26_b_x[c26_i156] = c26_x[c26_i156];
  }

  c26_eml_matlab_zsvdc(chartInstance, c26_b_x, c26_s);
  return c26_s[0];
}

static boolean_T c26_isfinite(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_x)
{
  real_T c26_b_x;
  boolean_T c26_b_b;
  boolean_T c26_b20;
  real_T c26_c_x;
  boolean_T c26_c_b;
  boolean_T c26_b21;
  (void)chartInstance;
  c26_b_x = c26_x;
  c26_b_b = muDoubleScalarIsInf(c26_b_x);
  c26_b20 = !c26_b_b;
  c26_c_x = c26_x;
  c26_c_b = muDoubleScalarIsNaN(c26_c_x);
  c26_b21 = !c26_c_b;
  return c26_b20 && c26_b21;
}

static void c26_eml_error(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c26_i157;
  static char_T c26_cv0[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c26_u[33];
  const mxArray *c26_y = NULL;
  (void)chartInstance;
  for (c26_i157 = 0; c26_i157 < 33; c26_i157++) {
    c26_u[c26_i157] = c26_cv0[c26_i157];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c26_y));
}

static void c26_eml_matlab_zsvdc(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_A[4], real_T c26_S[2])
{
  boolean_T c26_apply_transform;
  int32_T c26_i158;
  real_T c26_b_A[4];
  real_T c26_nrm;
  real_T c26_absx;
  real_T c26_d;
  real_T c26_y;
  real_T c26_s[2];
  real_T c26_a;
  real_T c26_SAFMIN;
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_b_y;
  real_T c26_B;
  real_T c26_c_y;
  real_T c26_b_a;
  real_T c26_c_a;
  int32_T c26_k;
  int32_T c26_b_k;
  int32_T c26_c_k;
  int32_T c26_d_k;
  real_T c26_c_A;
  real_T c26_b_B;
  real_T c26_d_y;
  int32_T c26_i159;
  real_T c26_d_A[4];
  int32_T c26_i160;
  real_T c26_e_A[4];
  real_T c26_t;
  real_T c26_f_A;
  real_T c26_c_B;
  real_T c26_e_y;
  int32_T c26_m;
  real_T c26_e[2];
  int32_T c26_b_q;
  int32_T c26_c_q;
  real_T c26_rt;
  real_T c26_g_A;
  real_T c26_d_B;
  real_T c26_r;
  real_T c26_h_A;
  real_T c26_e_B;
  real_T c26_f_y;
  real_T c26_i_A;
  real_T c26_f_B;
  real_T c26_iter;
  real_T c26_tiny;
  real_T c26_snorm;
  int32_T c26_ii;
  int32_T c26_b_ii;
  real_T c26_varargin_1;
  real_T c26_varargin_2;
  real_T c26_b_varargin_2;
  real_T c26_varargin_3;
  real_T c26_c_x;
  real_T c26_g_y;
  real_T c26_d_x;
  real_T c26_h_y;
  real_T c26_xk;
  real_T c26_yk;
  real_T c26_e_x;
  real_T c26_i_y;
  real_T c26_maxval;
  real_T c26_b_varargin_1;
  real_T c26_c_varargin_2;
  real_T c26_d_varargin_2;
  real_T c26_b_varargin_3;
  real_T c26_f_x;
  real_T c26_j_y;
  real_T c26_g_x;
  real_T c26_k_y;
  real_T c26_b_xk;
  real_T c26_b_yk;
  real_T c26_h_x;
  real_T c26_l_y;
  int32_T c26_i161;
  int32_T c26_d_a;
  int32_T c26_e_a;
  boolean_T c26_overflow;
  int32_T c26_c_ii;
  real_T c26_test0;
  real_T c26_ztest0;
  real_T c26_kase;
  int32_T c26_qs;
  int32_T c26_b_m;
  int32_T c26_d_q;
  int32_T c26_f_a;
  int32_T c26_b;
  int32_T c26_g_a;
  int32_T c26_b_b;
  boolean_T c26_b_overflow;
  int32_T c26_d_ii;
  real_T c26_test;
  real_T c26_ztest;
  real_T c26_f;
  int32_T c26_i162;
  int32_T c26_e_q;
  int32_T c26_h_a;
  int32_T c26_c_b;
  int32_T c26_i_a;
  int32_T c26_d_b;
  boolean_T c26_c_overflow;
  int32_T c26_e_k;
  int32_T c26_f_k;
  real_T c26_t1;
  real_T c26_b_t1;
  real_T c26_b_f;
  real_T c26_sn;
  real_T c26_cs;
  real_T c26_b_cs;
  real_T c26_b_sn;
  int32_T c26_km1;
  int32_T c26_qm1;
  int32_T c26_f_q;
  int32_T c26_c_m;
  int32_T c26_j_a;
  int32_T c26_e_b;
  int32_T c26_k_a;
  int32_T c26_f_b;
  boolean_T c26_d_overflow;
  int32_T c26_g_k;
  real_T c26_c_t1;
  real_T c26_unusedU0;
  real_T c26_c_sn;
  real_T c26_c_cs;
  int32_T c26_mm1;
  real_T c26_d2;
  real_T c26_d3;
  real_T c26_d4;
  real_T c26_d5;
  real_T c26_d6;
  real_T c26_c_varargin_1[5];
  int32_T c26_ixstart;
  real_T c26_mtmp;
  real_T c26_i_x;
  boolean_T c26_g_b;
  int32_T c26_ix;
  int32_T c26_b_ix;
  real_T c26_j_x;
  boolean_T c26_h_b;
  int32_T c26_l_a;
  int32_T c26_m_a;
  int32_T c26_i163;
  int32_T c26_n_a;
  int32_T c26_o_a;
  boolean_T c26_e_overflow;
  int32_T c26_c_ix;
  real_T c26_p_a;
  real_T c26_i_b;
  boolean_T c26_p;
  real_T c26_b_mtmp;
  real_T c26_scale;
  real_T c26_j_A;
  real_T c26_g_B;
  real_T c26_sm;
  real_T c26_k_A;
  real_T c26_h_B;
  real_T c26_smm1;
  real_T c26_l_A;
  real_T c26_i_B;
  real_T c26_emm1;
  real_T c26_m_A;
  real_T c26_j_B;
  real_T c26_sqds;
  real_T c26_n_A;
  real_T c26_k_B;
  real_T c26_eqds;
  real_T c26_o_A;
  real_T c26_j_b;
  real_T c26_c;
  real_T c26_shift;
  real_T c26_p_A;
  real_T c26_l_B;
  real_T c26_g;
  int32_T c26_g_q;
  int32_T c26_b_mm1;
  int32_T c26_q_a;
  int32_T c26_k_b;
  int32_T c26_r_a;
  int32_T c26_l_b;
  boolean_T c26_f_overflow;
  int32_T c26_h_k;
  int32_T c26_kp1;
  real_T c26_c_f;
  real_T c26_unusedU1;
  real_T c26_d_sn;
  real_T c26_d_cs;
  real_T c26_d_f;
  real_T c26_unusedU2;
  real_T c26_e_sn;
  real_T c26_e_cs;
  int32_T c26_i_k;
  int32_T c26_qp1;
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
  c26_b_eml_scalar_eg(chartInstance);
  c26_apply_transform = false;
  for (c26_i158 = 0; c26_i158 < 4; c26_i158++) {
    c26_b_A[c26_i158] = c26_A[c26_i158];
  }

  c26_nrm = c26_eml_xnrm2(chartInstance, c26_b_A);
  if (c26_nrm > 0.0) {
    c26_apply_transform = true;
    c26_absx = c26_nrm;
    c26_d = c26_A[0];
    if (c26_d < 0.0) {
      c26_y = -c26_absx;
    } else {
      c26_y = c26_absx;
    }

    c26_s[0] = c26_y;
    c26_a = c26_s[0];
    c26_eml_realmin(chartInstance);
    c26_eps(chartInstance);
    c26_SAFMIN = c26_rdivide(chartInstance, 2.2250738585072014E-308,
      2.2204460492503131E-16);
    c26_x = c26_a;
    c26_b_x = c26_x;
    c26_b_y = muDoubleScalarAbs(c26_b_x);
    if (c26_b_y >= c26_SAFMIN) {
      c26_B = c26_a;
      c26_c_y = c26_rdivide(chartInstance, 1.0, c26_B);
      c26_b_a = c26_c_y;
      c26_b_eml_switch_helper(chartInstance);
      c26_c_a = c26_b_a;
      c26_eml_switch_helper(chartInstance);
      for (c26_k = 1; c26_k < 3; c26_k++) {
        c26_b_k = c26_k;
        c26_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_k), 1, 4, 1, 0) - 1] = c26_c_a *
          c26_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_k), 1, 4, 1, 0) - 1];
      }
    } else {
      c26_eml_switch_helper(chartInstance);
      for (c26_c_k = 1; c26_c_k < 3; c26_c_k++) {
        c26_d_k = c26_c_k;
        c26_c_A = c26_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_d_k), 1, 4, 1, 0) - 1];
        c26_b_B = c26_a;
        c26_d_y = c26_rdivide(chartInstance, c26_c_A, c26_b_B);
        c26_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_d_k), 1, 4, 1, 0) - 1] = c26_d_y;
      }
    }

    c26_A[0]++;
    c26_s[0] = -c26_s[0];
  } else {
    c26_s[0] = 0.0;
  }

  if (c26_apply_transform) {
    for (c26_i159 = 0; c26_i159 < 4; c26_i159++) {
      c26_d_A[c26_i159] = c26_A[c26_i159];
    }

    for (c26_i160 = 0; c26_i160 < 4; c26_i160++) {
      c26_e_A[c26_i160] = c26_A[c26_i160];
    }

    c26_t = c26_eml_xdotc(chartInstance, c26_d_A, c26_e_A);
    c26_f_A = c26_t;
    c26_c_B = c26_A[0];
    c26_e_y = c26_rdivide(chartInstance, c26_f_A, c26_c_B);
    c26_t = -c26_e_y;
    c26_b_eml_xaxpy(chartInstance, c26_t, c26_A);
  }

  c26_m = 1;
  c26_s[1] = c26_A[3];
  c26_e[0] = c26_A[2];
  c26_e[1] = 0.0;
  c26_eml_switch_helper(chartInstance);
  for (c26_b_q = 1; c26_b_q < 3; c26_b_q++) {
    c26_c_q = c26_b_q;
    if (c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_c_q), 1, 2, 1, 0) - 1] != 0.0) {
      c26_rt = c26_abs(chartInstance, c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1]);
      c26_g_A = c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1];
      c26_d_B = c26_rt;
      c26_r = c26_rdivide(chartInstance, c26_g_A, c26_d_B);
      c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c26_c_q), 1, 2, 1, 0) - 1] = c26_rt;
      if (c26_c_q < 2) {
        c26_h_A = c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1];
        c26_e_B = c26_r;
        c26_f_y = c26_rdivide(chartInstance, c26_h_A, c26_e_B);
        c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_c_q), 1, 2, 1, 0) - 1] = c26_f_y;
      }
    }

    if (c26_c_q < 2) {
      if (c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_c_q), 1, 2, 1, 0) - 1] != 0.0) {
        c26_rt = c26_abs(chartInstance, c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1]);
        c26_i_A = c26_rt;
        c26_f_B = c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1];
        c26_r = c26_rdivide(chartInstance, c26_i_A, c26_f_B);
        c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_c_q), 1, 2, 1, 0) - 1] = c26_rt;
        c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c26_c_q + 1)), 1, 2, 1, 0) - 1] =
          c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c26_c_q + 1)), 1, 2, 1, 0) - 1] * c26_r;
      }
    }
  }

  c26_iter = 0.0;
  c26_realmin(chartInstance);
  c26_eps(chartInstance);
  c26_tiny = c26_rdivide(chartInstance, 2.2250738585072014E-308,
    2.2204460492503131E-16);
  c26_snorm = 0.0;
  c26_eml_switch_helper(chartInstance);
  for (c26_ii = 1; c26_ii < 3; c26_ii++) {
    c26_b_ii = c26_ii;
    c26_varargin_1 = c26_abs(chartInstance, c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ii),
      1, 2, 1, 0) - 1]);
    c26_varargin_2 = c26_abs(chartInstance, c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ii),
      1, 2, 1, 0) - 1]);
    c26_b_varargin_2 = c26_varargin_1;
    c26_varargin_3 = c26_varargin_2;
    c26_c_x = c26_b_varargin_2;
    c26_g_y = c26_varargin_3;
    c26_d_x = c26_c_x;
    c26_h_y = c26_g_y;
    c26_eml_scalar_eg(chartInstance);
    c26_xk = c26_d_x;
    c26_yk = c26_h_y;
    c26_e_x = c26_xk;
    c26_i_y = c26_yk;
    c26_eml_scalar_eg(chartInstance);
    c26_maxval = muDoubleScalarMax(c26_e_x, c26_i_y);
    c26_b_varargin_1 = c26_snorm;
    c26_c_varargin_2 = c26_maxval;
    c26_d_varargin_2 = c26_b_varargin_1;
    c26_b_varargin_3 = c26_c_varargin_2;
    c26_f_x = c26_d_varargin_2;
    c26_j_y = c26_b_varargin_3;
    c26_g_x = c26_f_x;
    c26_k_y = c26_j_y;
    c26_eml_scalar_eg(chartInstance);
    c26_b_xk = c26_g_x;
    c26_b_yk = c26_k_y;
    c26_h_x = c26_b_xk;
    c26_l_y = c26_b_yk;
    c26_eml_scalar_eg(chartInstance);
    c26_snorm = muDoubleScalarMax(c26_h_x, c26_l_y);
  }

  exitg1 = false;
  while ((exitg1 == false) && (c26_m + 1 > 0)) {
    if (c26_iter >= 75.0) {
      c26_b_eml_error(chartInstance);
      exitg1 = true;
    } else {
      c26_c_q = c26_m;
      c26_i161 = c26_m;
      c26_d_a = c26_i161;
      c26_e_a = c26_d_a;
      if (c26_e_a < 0) {
        c26_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_overflow = false;
      }

      if (c26_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_overflow);
      }

      c26_c_ii = c26_i161;
      guard3 = false;
      guard4 = false;
      exitg5 = false;
      while ((exitg5 == false) && (c26_c_ii > -1)) {
        c26_b_ii = c26_c_ii;
        c26_c_q = c26_b_ii;
        if (c26_b_ii == 0) {
          exitg5 = true;
        } else {
          c26_test0 = c26_abs(chartInstance, c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ii), 1, 2, 1, 0) -
                              1]) + c26_abs(chartInstance,
            c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c26_b_ii + 1)), 1, 2, 1, 0) - 1]);
          c26_ztest0 = c26_abs(chartInstance, c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ii), 1, 2, 1, 0) -
                               1]);
          c26_eps(chartInstance);
          if (c26_ztest0 <= 2.2204460492503131E-16 * c26_test0) {
            guard4 = true;
            exitg5 = true;
          } else if (c26_ztest0 <= c26_tiny) {
            guard4 = true;
            exitg5 = true;
          } else {
            guard11 = false;
            if (c26_iter > 20.0) {
              c26_eps(chartInstance);
              if (c26_ztest0 <= 2.2204460492503131E-16 * c26_snorm) {
                guard3 = true;
                exitg5 = true;
              } else {
                guard11 = true;
              }
            } else {
              guard11 = true;
            }

            if (guard11 == true) {
              c26_c_ii--;
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
        c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_ii), 1, 2, 1, 0) - 1] = 0.0;
      }

      if (c26_c_q == c26_m) {
        c26_kase = 4.0;
      } else {
        c26_qs = c26_m + 1;
        c26_b_m = c26_m + 1;
        c26_d_q = c26_c_q;
        c26_f_a = c26_b_m;
        c26_b = c26_d_q;
        c26_g_a = c26_f_a;
        c26_b_b = c26_b;
        if (c26_g_a < c26_b_b) {
          c26_b_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_b_overflow = (c26_b_b < -2147483647);
        }

        if (c26_b_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
        }

        c26_d_ii = c26_b_m;
        guard2 = false;
        exitg4 = false;
        while ((exitg4 == false) && (c26_d_ii >= c26_d_q)) {
          c26_b_ii = c26_d_ii;
          c26_qs = c26_b_ii;
          if (c26_b_ii == c26_c_q) {
            exitg4 = true;
          } else {
            c26_test = 0.0;
            if (c26_b_ii < c26_m + 1) {
              c26_test = c26_abs(chartInstance,
                                 c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_ii), 1, 2, 1, 0) - 1]);
            }

            if (c26_b_ii > c26_c_q + 1) {
              c26_test += c26_abs(chartInstance,
                                  c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)(c26_b_ii - 1)), 1, 2, 1, 0) - 1]);
            }

            c26_ztest = c26_abs(chartInstance, c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK
                                ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
              c26_b_ii), 1, 2, 1, 0) - 1]);
            c26_eps(chartInstance);
            if (c26_ztest <= 2.2204460492503131E-16 * c26_test) {
              guard2 = true;
              exitg4 = true;
            } else if (c26_ztest <= c26_tiny) {
              guard2 = true;
              exitg4 = true;
            } else {
              c26_d_ii--;
              guard2 = false;
            }
          }
        }

        if (guard2 == true) {
          c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_b_ii), 1, 2, 1, 0) - 1] = 0.0;
        }

        if (c26_qs == c26_c_q) {
          c26_kase = 3.0;
        } else if (c26_qs == c26_m + 1) {
          c26_kase = 1.0;
        } else {
          c26_kase = 2.0;
          c26_c_q = c26_qs;
        }
      }

      c26_c_q++;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c26_kase)) {
       case 1:
        c26_f = c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_m), 1, 2, 1, 0) - 1];
        c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_m), 1, 2, 1, 0) - 1] = 0.0;
        c26_i162 = c26_m;
        c26_e_q = c26_c_q;
        c26_h_a = c26_i162;
        c26_c_b = c26_e_q;
        c26_i_a = c26_h_a;
        c26_d_b = c26_c_b;
        if (c26_i_a < c26_d_b) {
          c26_c_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_c_overflow = (c26_d_b < -2147483647);
        }

        if (c26_c_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_c_overflow);
        }

        for (c26_e_k = c26_i162; c26_e_k >= c26_e_q; c26_e_k--) {
          c26_f_k = c26_e_k;
          c26_t1 = c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_f_k), 1, 2, 1, 0) - 1];
          c26_b_t1 = c26_t1;
          c26_b_f = c26_f;
          c26_b_eml_xrotg(chartInstance, &c26_b_t1, &c26_b_f, &c26_cs, &c26_sn);
          c26_t1 = c26_b_t1;
          c26_f = c26_b_f;
          c26_b_cs = c26_cs;
          c26_b_sn = c26_sn;
          c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1] = c26_t1;
          if (c26_f_k > c26_c_q) {
            c26_km1 = c26_f_k - 1;
            c26_f = -c26_b_sn * c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_km1), 1, 2, 1, 0) - 1];
            c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c26_km1), 1, 2, 1, 0) - 1] =
              c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c26_km1), 1, 2, 1, 0) - 1] * c26_b_cs;
          }
        }
        break;

       case 2:
        c26_qm1 = c26_c_q - 1;
        c26_f = c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_qm1), 1, 2, 1, 0) - 1];
        c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_qm1), 1, 2, 1, 0) - 1] = 0.0;
        c26_f_q = c26_c_q;
        c26_c_m = c26_m + 1;
        c26_j_a = c26_f_q;
        c26_e_b = c26_c_m;
        c26_k_a = c26_j_a;
        c26_f_b = c26_e_b;
        if (c26_k_a > c26_f_b) {
          c26_d_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_d_overflow = (c26_f_b > 2147483646);
        }

        if (c26_d_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_d_overflow);
        }

        for (c26_g_k = c26_f_q; c26_g_k <= c26_c_m; c26_g_k++) {
          c26_f_k = c26_g_k;
          c26_t1 = c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_f_k), 1, 2, 1, 0) - 1];
          c26_c_t1 = c26_t1;
          c26_unusedU0 = c26_f;
          c26_b_eml_xrotg(chartInstance, &c26_c_t1, &c26_unusedU0, &c26_c_cs,
                          &c26_c_sn);
          c26_t1 = c26_c_t1;
          c26_b_cs = c26_c_cs;
          c26_b_sn = c26_c_sn;
          c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1] = c26_t1;
          c26_f = -c26_b_sn * c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_f_k), 1, 2, 1, 0) - 1];
          c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1] =
            c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1] * c26_b_cs;
        }
        break;

       case 3:
        c26_mm1 = c26_m;
        c26_d2 = c26_abs(chartInstance, c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c26_m + 1)), 1, 2, 1, 0) - 1]);
        c26_d3 = c26_abs(chartInstance, c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_mm1), 1, 2, 1, 0) - 1]);
        c26_d4 = c26_abs(chartInstance, c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_mm1), 1, 2, 1, 0) - 1]);
        c26_d5 = c26_abs(chartInstance, c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1]);
        c26_d6 = c26_abs(chartInstance, c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1]);
        c26_c_varargin_1[0] = c26_d2;
        c26_c_varargin_1[1] = c26_d3;
        c26_c_varargin_1[2] = c26_d4;
        c26_c_varargin_1[3] = c26_d5;
        c26_c_varargin_1[4] = c26_d6;
        c26_ixstart = 1;
        c26_mtmp = c26_c_varargin_1[0];
        c26_i_x = c26_mtmp;
        c26_g_b = muDoubleScalarIsNaN(c26_i_x);
        if (c26_g_b) {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_ix = 2;
          exitg2 = false;
          while ((exitg2 == false) && (c26_ix < 6)) {
            c26_b_ix = c26_ix;
            c26_ixstart = c26_b_ix;
            c26_j_x = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 5, 1, 0) - 1];
            c26_h_b = muDoubleScalarIsNaN(c26_j_x);
            if (!c26_h_b) {
              c26_mtmp = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 5, 1, 0) -
                1];
              exitg2 = true;
            } else {
              c26_ix++;
            }
          }
        }

        if (c26_ixstart < 5) {
          c26_l_a = c26_ixstart;
          c26_m_a = c26_l_a + 1;
          c26_i163 = c26_m_a;
          c26_n_a = c26_i163;
          c26_o_a = c26_n_a;
          if (c26_o_a > 5) {
            c26_e_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_e_overflow = false;
          }

          if (c26_e_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_e_overflow);
          }

          for (c26_c_ix = c26_i163; c26_c_ix < 6; c26_c_ix++) {
            c26_b_ix = c26_c_ix;
            c26_p_a = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 5, 1, 0) - 1];
            c26_i_b = c26_mtmp;
            c26_p = (c26_p_a > c26_i_b);
            if (c26_p) {
              c26_mtmp = c26_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ix), 1, 5, 1, 0) -
                1];
            }
          }
        }

        c26_b_mtmp = c26_mtmp;
        c26_scale = c26_b_mtmp;
        c26_j_A = c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c26_m + 1)), 1, 2, 1, 0) - 1];
        c26_g_B = c26_scale;
        c26_sm = c26_rdivide(chartInstance, c26_j_A, c26_g_B);
        c26_k_A = c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_mm1), 1, 2, 1, 0) - 1];
        c26_h_B = c26_scale;
        c26_smm1 = c26_rdivide(chartInstance, c26_k_A, c26_h_B);
        c26_l_A = c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_mm1), 1, 2, 1, 0) - 1];
        c26_i_B = c26_scale;
        c26_emm1 = c26_rdivide(chartInstance, c26_l_A, c26_i_B);
        c26_m_A = c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1];
        c26_j_B = c26_scale;
        c26_sqds = c26_rdivide(chartInstance, c26_m_A, c26_j_B);
        c26_n_A = c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1];
        c26_k_B = c26_scale;
        c26_eqds = c26_rdivide(chartInstance, c26_n_A, c26_k_B);
        c26_o_A = (c26_smm1 + c26_sm) * (c26_smm1 - c26_sm) + c26_emm1 *
          c26_emm1;
        c26_j_b = c26_rdivide(chartInstance, c26_o_A, 2.0);
        c26_c = c26_sm * c26_emm1;
        c26_c *= c26_c;
        guard1 = false;
        if (c26_j_b != 0.0) {
          guard1 = true;
        } else if (c26_c != 0.0) {
          guard1 = true;
        } else {
          c26_shift = 0.0;
        }

        if (guard1 == true) {
          c26_shift = c26_j_b * c26_j_b + c26_c;
          c26_c_sqrt(chartInstance, &c26_shift);
          if (c26_j_b < 0.0) {
            c26_shift = -c26_shift;
          }

          c26_p_A = c26_c;
          c26_l_B = c26_j_b + c26_shift;
          c26_shift = c26_rdivide(chartInstance, c26_p_A, c26_l_B);
        }

        c26_f = (c26_sqds + c26_sm) * (c26_sqds - c26_sm) + c26_shift;
        c26_g = c26_sqds * c26_eqds;
        c26_g_q = c26_c_q;
        c26_b_mm1 = c26_mm1;
        c26_q_a = c26_g_q;
        c26_k_b = c26_b_mm1;
        c26_r_a = c26_q_a;
        c26_l_b = c26_k_b;
        if (c26_r_a > c26_l_b) {
          c26_f_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_f_overflow = (c26_l_b > 2147483646);
        }

        if (c26_f_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_f_overflow);
        }

        for (c26_h_k = c26_g_q; c26_h_k <= c26_b_mm1; c26_h_k++) {
          c26_f_k = c26_h_k;
          c26_km1 = c26_f_k;
          c26_kp1 = c26_f_k + 1;
          c26_c_f = c26_f;
          c26_unusedU1 = c26_g;
          c26_b_eml_xrotg(chartInstance, &c26_c_f, &c26_unusedU1, &c26_d_cs,
                          &c26_d_sn);
          c26_f = c26_c_f;
          c26_b_cs = c26_d_cs;
          c26_b_sn = c26_d_sn;
          if (c26_f_k > c26_c_q) {
            c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c26_km1 - 1)), 1, 2, 1, 0) - 1] = c26_f;
          }

          c26_f = c26_b_cs * c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_f_k), 1, 2, 1, 0) - 1] + c26_b_sn
            * c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c26_f_k), 1, 2, 1, 0) - 1];
          c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1] = c26_b_cs *
            c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1] - c26_b_sn *
            c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1];
          c26_g = c26_b_sn * c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_kp1), 1, 2, 1, 0) - 1];
          c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_kp1), 1, 2, 1, 0) - 1] =
            c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_kp1), 1, 2, 1, 0) - 1] * c26_b_cs;
          c26_d_f = c26_f;
          c26_unusedU2 = c26_g;
          c26_b_eml_xrotg(chartInstance, &c26_d_f, &c26_unusedU2, &c26_e_cs,
                          &c26_e_sn);
          c26_f = c26_d_f;
          c26_b_cs = c26_e_cs;
          c26_b_sn = c26_e_sn;
          c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1] = c26_f;
          c26_f = c26_b_cs * c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_f_k), 1, 2, 1, 0) - 1] + c26_b_sn
            * c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c26_kp1), 1, 2, 1, 0) - 1];
          c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_kp1), 1, 2, 1, 0) - 1] = -c26_b_sn *
            c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_f_k), 1, 2, 1, 0) - 1] + c26_b_cs *
            c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_kp1), 1, 2, 1, 0) - 1];
          c26_g = c26_b_sn * c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_kp1), 1, 2, 1, 0) - 1];
          c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_kp1), 1, 2, 1, 0) - 1] =
            c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_kp1), 1, 2, 1, 0) - 1] * c26_b_cs;
        }

        c26_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_m), 1, 2, 1, 0) - 1] = c26_f;
        c26_iter++;
        break;

       default:
        if (c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c26_c_q), 1, 2, 1, 0) - 1] < 0.0) {
          c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_c_q), 1, 2, 1, 0) - 1] =
            -c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c26_c_q), 1, 2, 1, 0) - 1];
        }

        c26_qp1 = c26_c_q + 1;
        exitg3 = false;
        while ((exitg3 == false) && (c26_c_q < 2)) {
          if (c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c26_c_q), 1, 2, 1, 0) - 1] <
              c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c26_qp1), 1, 2, 1, 0) - 1]) {
            c26_rt = c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_c_q), 1, 2, 1, 0) - 1];
            c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c26_c_q), 1, 2, 1, 0) - 1] =
              c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c26_qp1), 1, 2, 1, 0) - 1];
            c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c26_qp1), 1, 2, 1, 0) - 1] = c26_rt;
            c26_c_q = c26_qp1;
            c26_qp1 = c26_c_q + 1;
          } else {
            exitg3 = true;
          }
        }

        c26_iter = 0.0;
        c26_m--;
        break;
      }
    }
  }

  c26_eml_switch_helper(chartInstance);
  for (c26_i_k = 1; c26_i_k < 3; c26_i_k++) {
    c26_f_k = c26_i_k;
    c26_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c26_f_k), 1, 2, 1, 0) - 1] = c26_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_f_k), 1, 2, 1, 0) - 1];
  }
}

static void c26_b_eml_scalar_eg(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c26_eml_xnrm2(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_x[4])
{
  real_T c26_y;
  real_T c26_scale;
  int32_T c26_k;
  int32_T c26_b_k;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_absxk;
  real_T c26_t;
  c26_threshold(chartInstance);
  c26_y = 0.0;
  c26_eml_realmin(chartInstance);
  c26_scale = 2.2250738585072014E-308;
  c26_eml_switch_helper(chartInstance);
  for (c26_k = 1; c26_k < 3; c26_k++) {
    c26_b_k = c26_k;
    c26_b_x = c26_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c26_b_k), 1, 4, 1, 0) - 1];
    c26_c_x = c26_b_x;
    c26_absxk = muDoubleScalarAbs(c26_c_x);
    if (c26_absxk > c26_scale) {
      c26_t = c26_scale / c26_absxk;
      c26_y = 1.0 + c26_y * c26_t * c26_t;
      c26_scale = c26_absxk;
    } else {
      c26_t = c26_absxk / c26_scale;
      c26_y += c26_t * c26_t;
    }
  }

  return c26_scale * muDoubleScalarSqrt(c26_y);
}

static void c26_eps(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c26_b_eml_switch_helper(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c26_eml_xdotc(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_x[4], real_T c26_y[4])
{
  real_T c26_d;
  int32_T c26_ix;
  int32_T c26_iy;
  int32_T c26_k;
  int32_T c26_a;
  int32_T c26_b_a;
  c26_d = 0.0;
  c26_ix = 1;
  c26_iy = 3;
  c26_eml_switch_helper(chartInstance);
  for (c26_k = 1; c26_k < 3; c26_k++) {
    c26_d += c26_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c26_ix), 1, 4, 1, 0) - 1] * c26_y[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_iy), 1, 4, 1, 0) - 1];
    c26_a = c26_ix + 1;
    c26_ix = c26_a;
    c26_b_a = c26_iy + 1;
    c26_iy = c26_b_a;
  }

  return c26_d;
}

static void c26_eml_xaxpy(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_a, real_T c26_y[4], real_T c26_b_y[4])
{
  int32_T c26_i164;
  for (c26_i164 = 0; c26_i164 < 4; c26_i164++) {
    c26_b_y[c26_i164] = c26_y[c26_i164];
  }

  c26_b_eml_xaxpy(chartInstance, c26_a, c26_b_y);
}

static void c26_b_eml_error(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c26_i165;
  static char_T c26_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c26_u[30];
  const mxArray *c26_y = NULL;
  (void)chartInstance;
  for (c26_i165 = 0; c26_i165 < 30; c26_i165++) {
    c26_u[c26_i165] = c26_cv1[c26_i165];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c26_y));
}

static void c26_check_forloop_overflow_error(SFc26_hybridSysSimInstanceStruct
  *chartInstance, boolean_T c26_overflow)
{
  int32_T c26_i166;
  static char_T c26_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c26_u[34];
  const mxArray *c26_y = NULL;
  int32_T c26_i167;
  static char_T c26_cv3[5] = { 'i', 'n', 't', '3', '2' };

  char_T c26_b_u[5];
  const mxArray *c26_b_y = NULL;
  (void)chartInstance;
  if (!c26_overflow) {
  } else {
    for (c26_i166 = 0; c26_i166 < 34; c26_i166++) {
      c26_u[c26_i166] = c26_cv2[c26_i166];
    }

    c26_y = NULL;
    sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c26_i167 = 0; c26_i167 < 5; c26_i167++) {
      c26_b_u[c26_i167] = c26_cv3[c26_i167];
    }

    c26_b_y = NULL;
    sf_mex_assign(&c26_b_y, sf_mex_create("y", c26_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c26_y, 14, c26_b_y));
  }
}

static real_T c26_sqrt(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x)
{
  real_T c26_b_x;
  c26_b_x = c26_x;
  c26_c_sqrt(chartInstance, &c26_b_x);
  return c26_b_x;
}

static void c26_c_eml_error(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c26_i168;
  static char_T c26_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c26_u[30];
  const mxArray *c26_y = NULL;
  int32_T c26_i169;
  static char_T c26_cv5[4] = { 's', 'q', 'r', 't' };

  char_T c26_b_u[4];
  const mxArray *c26_b_y = NULL;
  (void)chartInstance;
  for (c26_i168 = 0; c26_i168 < 30; c26_i168++) {
    c26_u[c26_i168] = c26_cv4[c26_i168];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c26_i169 = 0; c26_i169 < 4; c26_i169++) {
    c26_b_u[c26_i169] = c26_cv5[c26_i169];
  }

  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", c26_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c26_y, 14, c26_b_y));
}

static void c26_eml_xrotg(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_a, real_T c26_b, real_T *c26_b_a, real_T *c26_b_b, real_T *c26_c,
  real_T *c26_s)
{
  *c26_b_a = c26_a;
  *c26_b_b = c26_b;
  c26_b_eml_xrotg(chartInstance, c26_b_a, c26_b_b, c26_c, c26_s);
}

static void c26_eig(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
                    c26_A[4], creal_T c26_V[2])
{
  int32_T c26_i170;
  static creal_T c26_dc10 = { 0.0, 0.0 };

  creal_T c26_b_A[4];
  int32_T c26_info;
  int32_T c26_i171;
  creal_T c26_c_A[4];
  real_T c26_anrm;
  int32_T c26_i172;
  int32_T c26_i173;
  creal_T c26_beta1[2];
  boolean_T c26_ilascl;
  real_T c26_anrmto;
  int32_T c26_rscale[2];
  int32_T c26_ihi;
  int32_T c26_ilo;
  int32_T c26_b_ilo;
  int32_T c26_b_ihi;
  int32_T c26_c_ilo;
  int32_T c26_c_ihi;
  int32_T c26_a;
  int32_T c26_b_a;
  int32_T c26_c;
  int32_T c26_c_a;
  int32_T c26_d_a;
  int32_T c26_ihim1;
  int32_T c26_jcol;
  int32_T c26_e_a;
  int32_T c26_f_a;
  int32_T c26_jcolp1;
  int32_T c26_jrow;
  int32_T c26_g_a;
  int32_T c26_h_a;
  int32_T c26_jrowm1;
  creal_T c26_d_A;
  creal_T c26_e_A;
  creal_T c26_b;
  creal_T c26_s;
  real_T c26_b_c;
  real_T c26_c_c;
  real_T c26_d_c;
  int32_T c26_xrow;
  int32_T c26_yrow;
  int32_T c26_jlo;
  int32_T c26_jhi;
  int32_T c26_b_jlo;
  int32_T c26_b_jhi;
  int32_T c26_i_a;
  int32_T c26_b_b;
  int32_T c26_j_a;
  int32_T c26_c_b;
  boolean_T c26_overflow;
  int32_T c26_j;
  int32_T c26_b_j;
  real_T c26_k_a;
  creal_T c26_y;
  creal_T c26_b_s;
  creal_T c26_stemp;
  real_T c26_l_a;
  creal_T c26_d_b;
  creal_T c26_e_b;
  creal_T c26_f_b;
  creal_T c26_g_b;
  real_T c26_e_c;
  int32_T c26_xcol;
  int32_T c26_ycol;
  int32_T c26_d_ilo;
  int32_T c26_d_ihi;
  int32_T c26_e_ilo;
  int32_T c26_e_ihi;
  int32_T c26_m_a;
  int32_T c26_h_b;
  int32_T c26_n_a;
  int32_T c26_i_b;
  boolean_T c26_b_overflow;
  int32_T c26_i;
  int32_T c26_b_i;
  real_T c26_o_a;
  creal_T c26_c_s;
  real_T c26_p_a;
  creal_T c26_j_b;
  creal_T c26_k_b;
  creal_T c26_l_b;
  creal_T c26_m_b;
  int32_T c26_i174;
  creal_T c26_f_A[4];
  int32_T c26_b_info;
  real_T c26_cfrom;
  real_T c26_cto;
  real_T c26_cfromc;
  real_T c26_ctoc;
  boolean_T c26_notdone;
  real_T c26_cfrom1;
  real_T c26_cto1;
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_b_y;
  real_T c26_c_x;
  real_T c26_d_x;
  real_T c26_c_y;
  real_T c26_mul;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_d_y;
  real_T c26_g_x;
  real_T c26_h_x;
  real_T c26_e_y;
  real_T c26_q_a;
  int32_T c26_i175;
  int32_T c26_c_info;
  int32_T c26_d_info;
  int32_T c26_e_info;
  int32_T c26_i176;
  creal_T c26_b_V;
  real_T c26_ar;
  real_T c26_ai;
  real_T c26_br;
  real_T c26_bi;
  real_T c26_brm;
  real_T c26_bim;
  real_T c26_d_s;
  real_T c26_d;
  real_T c26_nr;
  real_T c26_ni;
  real_T c26_sgnbr;
  real_T c26_sgnbi;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c26_assert(chartInstance);
  c26_b_assert(chartInstance);
  c26_c_assert(chartInstance);
  c26_parseopts(chartInstance);
  c26_b_eml_scalar_eg(chartInstance);
  for (c26_i170 = 0; c26_i170 < 4; c26_i170++) {
    c26_b_A[c26_i170].re = c26_A[c26_i170] + c26_dc10.re;
    c26_b_A[c26_i170].im = c26_dc10.im;
  }

  c26_info = 0;
  c26_eml_realmin(chartInstance);
  c26_eps(chartInstance);
  for (c26_i171 = 0; c26_i171 < 4; c26_i171++) {
    c26_c_A[c26_i171] = c26_b_A[c26_i171];
  }

  c26_anrm = c26_eml_matlab_zlangeM(chartInstance, c26_c_A);
  if (!c26_isfinite(chartInstance, c26_anrm)) {
    for (c26_i172 = 0; c26_i172 < 2; c26_i172++) {
      c26_V[c26_i172].re = rtNaN;
      c26_V[c26_i172].im = 0.0;
    }

    for (c26_i173 = 0; c26_i173 < 2; c26_i173++) {
      c26_beta1[c26_i173].re = rtNaN;
      c26_beta1[c26_i173].im = 0.0;
    }
  } else {
    c26_ilascl = false;
    c26_anrmto = c26_anrm;
    guard2 = false;
    if (c26_anrm > 0.0) {
      if (c26_anrm < 6.7178761075670888E-139) {
        c26_anrmto = 6.7178761075670888E-139;
        c26_ilascl = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      if (c26_anrm > 1.4885657073574029E+138) {
        c26_anrmto = 1.4885657073574029E+138;
        c26_ilascl = true;
      }
    }

    if (c26_ilascl) {
      c26_b_eml_matlab_zlascl(chartInstance, c26_anrm, c26_anrmto, c26_b_A);
    }

    c26_c_eml_matlab_zggbal(chartInstance, c26_b_A, &c26_ilo, &c26_ihi,
      c26_rscale);
    c26_b_ilo = c26_ilo;
    c26_b_ihi = c26_ihi;
    c26_c_ilo = c26_b_ilo;
    c26_c_ihi = c26_b_ihi;
    c26_a = c26_c_ilo;
    c26_b_a = c26_a + 2;
    c26_c = c26_b_a;
    if (c26_c_ihi < c26_c) {
    } else {
      c26_c_a = c26_c_ihi;
      c26_d_a = c26_c_a - 1;
      c26_ihim1 = c26_d_a;
      c26_jcol = c26_c_ilo;
      while (c26_jcol < c26_ihim1) {
        c26_e_a = c26_jcol;
        c26_f_a = c26_e_a + 1;
        c26_jcolp1 = c26_f_a;
        c26_jrow = c26_c_ihi;
        while (c26_jrow > c26_jcolp1) {
          c26_g_a = c26_jrow;
          c26_h_a = c26_g_a - 1;
          c26_jrowm1 = c26_h_a;
          c26_d_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_jrowm1), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_jcol), 1, 2, 2, 0) - 1) << 1)) -
            1].re;
          c26_d_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_jrowm1), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_jcol), 1, 2, 2, 0) - 1) << 1)) -
            1].im;
          c26_e_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_jrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_jcol), 1, 2, 2, 0) - 1) << 1)) -
            1].re;
          c26_e_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_jrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_jcol), 1, 2, 2, 0) - 1) << 1)) -
            1].im;
          c26_eml_matlab_zlartg(chartInstance, c26_d_A, c26_e_A, &c26_b_c,
                                &c26_s, &c26_b);
          c26_c_c = c26_b_c;
          c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_jrowm1), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_jcol), 1, 2, 2, 0) - 1) << 1)) - 1].re =
            c26_b.re;
          c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_jrowm1), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_jcol), 1, 2, 2, 0) - 1) << 1)) - 1].im =
            c26_b.im;
          c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_jrow), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_jcol), 1, 2, 2, 0) - 1) << 1)) - 1].re =
            c26_dc10.re;
          c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_jrow), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_jcol), 1, 2, 2, 0) - 1) << 1)) - 1].im =
            c26_dc10.im;
          c26_d_c = c26_c_c;
          c26_xrow = c26_jrowm1;
          c26_yrow = c26_jrow;
          c26_jlo = c26_jcolp1;
          c26_jhi = c26_c_ihi;
          c26_b_jlo = c26_jlo;
          c26_b_jhi = c26_jhi;
          c26_i_a = c26_b_jlo;
          c26_b_b = c26_b_jhi;
          c26_j_a = c26_i_a;
          c26_c_b = c26_b_b;
          if (c26_j_a > c26_c_b) {
            c26_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_overflow = (c26_c_b > 2147483646);
          }

          if (c26_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_overflow);
          }

          for (c26_j = c26_b_jlo; c26_j <= c26_b_jhi; c26_j++) {
            c26_b_j = c26_j;
            c26_k_a = c26_d_c;
            c26_b.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c26_b.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c26_y.re = c26_k_a * c26_b.re;
            c26_y.im = c26_k_a * c26_b.im;
            c26_b_s.re = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
              ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].re - c26_s.im *
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c26_b_s.im = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
              ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].im + c26_s.im *
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c26_stemp.re = c26_y.re + c26_b_s.re;
            c26_stemp.im = c26_y.im + c26_b_s.im;
            c26_l_a = c26_d_c;
            c26_b.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c26_b.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c26_y.re = c26_l_a * c26_b.re;
            c26_y.im = c26_l_a * c26_b.im;
            c26_b.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c26_b.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c26_d_b = c26_b;
            c26_e_b = c26_b;
            c26_f_b = c26_b;
            c26_g_b = c26_b;
            c26_b.re = c26_s.re * c26_d_b.re + c26_s.im * c26_e_b.im;
            c26_b.im = c26_s.re * c26_f_b.im - c26_s.im * c26_g_b.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_yrow), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1)
                      << 1)) - 1].re = c26_y.re - c26_b.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_yrow), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1)
                      << 1)) - 1].im = c26_y.im - c26_b.im;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_xrow), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1)
                      << 1)) - 1].re = c26_stemp.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_xrow), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1)
                      << 1)) - 1].im = c26_stemp.im;
          }

          c26_s.re = -c26_s.re;
          c26_s.im = -c26_s.im;
          c26_e_c = c26_c_c;
          c26_xcol = c26_jrow;
          c26_ycol = c26_jrowm1;
          c26_d_ilo = c26_c_ilo;
          c26_d_ihi = c26_c_ihi;
          c26_e_ilo = c26_d_ilo;
          c26_e_ihi = c26_d_ihi;
          c26_m_a = c26_e_ilo;
          c26_h_b = c26_e_ihi;
          c26_n_a = c26_m_a;
          c26_i_b = c26_h_b;
          if (c26_n_a > c26_i_b) {
            c26_b_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_b_overflow = (c26_i_b > 2147483646);
          }

          if (c26_b_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
          }

          for (c26_i = c26_e_ilo; c26_i <= c26_e_ihi; c26_i++) {
            c26_b_i = c26_i;
            c26_o_a = c26_e_c;
            c26_b.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c26_b.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c26_y.re = c26_o_a * c26_b.re;
            c26_y.im = c26_o_a * c26_b.im;
            c26_c_s.re = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
              ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1)) - 1].re - c26_s.im *
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c26_c_s.im = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
              ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1)) - 1].im + c26_s.im *
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c26_stemp.re = c26_y.re + c26_c_s.re;
            c26_stemp.im = c26_y.im + c26_c_s.im;
            c26_p_a = c26_e_c;
            c26_b.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c26_b.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c26_y.re = c26_p_a * c26_b.re;
            c26_y.im = c26_p_a * c26_b.im;
            c26_b.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c26_b.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c26_j_b = c26_b;
            c26_k_b = c26_b;
            c26_l_b = c26_b;
            c26_m_b = c26_b;
            c26_b.re = c26_s.re * c26_j_b.re + c26_s.im * c26_k_b.im;
            c26_b.im = c26_s.re * c26_l_b.im - c26_s.im * c26_m_b.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_i), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) -
                       1) << 1)) - 1].re = c26_y.re - c26_b.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_i), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) -
                       1) << 1)) - 1].im = c26_y.im - c26_b.im;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_i), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) -
                       1) << 1)) - 1].re = c26_stemp.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_i), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) -
                       1) << 1)) - 1].im = c26_stemp.im;
          }

          c26_jrow = c26_jrowm1;
        }

        c26_jcol = c26_jcolp1;
      }
    }

    for (c26_i174 = 0; c26_i174 < 4; c26_i174++) {
      c26_f_A[c26_i174] = c26_b_A[c26_i174];
    }

    c26_eml_matlab_zhgeqz(chartInstance, c26_f_A, c26_b_ilo, c26_b_ihi,
                          &c26_b_info, c26_V, c26_beta1);
    c26_info = c26_b_info;
    if (c26_info != 0) {
    } else {
      if (c26_ilascl) {
        c26_cfrom = c26_anrmto;
        c26_cto = c26_anrm;
        c26_eml_realmin(chartInstance);
        c26_eps(chartInstance);
        c26_cfromc = c26_cfrom;
        c26_ctoc = c26_cto;
        c26_notdone = true;
        while (c26_notdone) {
          c26_cfrom1 = c26_cfromc * 2.0041683600089728E-292;
          c26_cto1 = c26_ctoc / 4.9896007738368E+291;
          c26_x = c26_cfrom1;
          c26_b_x = c26_x;
          c26_b_y = muDoubleScalarAbs(c26_b_x);
          c26_c_x = c26_ctoc;
          c26_d_x = c26_c_x;
          c26_c_y = muDoubleScalarAbs(c26_d_x);
          guard1 = false;
          if (c26_b_y > c26_c_y) {
            if (c26_ctoc != 0.0) {
              c26_mul = 2.0041683600089728E-292;
              c26_notdone = true;
              c26_cfromc = c26_cfrom1;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1 == true) {
            c26_e_x = c26_cto1;
            c26_f_x = c26_e_x;
            c26_d_y = muDoubleScalarAbs(c26_f_x);
            c26_g_x = c26_cfromc;
            c26_h_x = c26_g_x;
            c26_e_y = muDoubleScalarAbs(c26_h_x);
            if (c26_d_y > c26_e_y) {
              c26_mul = 4.9896007738368E+291;
              c26_notdone = true;
              c26_ctoc = c26_cto1;
            } else {
              c26_mul = c26_ctoc / c26_cfromc;
              c26_notdone = false;
            }
          }

          c26_q_a = c26_mul;
          for (c26_i175 = 0; c26_i175 < 2; c26_i175++) {
            c26_V[c26_i175].re *= c26_q_a;
            c26_V[c26_i175].im *= c26_q_a;
          }
        }
      }
    }
  }

  c26_c_info = c26_info;
  c26_d_info = c26_c_info;
  c26_e_info = c26_d_info;
  for (c26_i176 = 0; c26_i176 < 2; c26_i176++) {
    c26_b_V = c26_V[c26_i176];
    c26_ar = c26_b_V.re;
    c26_ai = c26_b_V.im;
    c26_br = c26_beta1[c26_i176].re;
    c26_bi = c26_beta1[c26_i176].im;
    if (c26_bi == 0.0) {
      if (c26_ai == 0.0) {
        c26_V[c26_i176].re = c26_ar / c26_br;
        c26_V[c26_i176].im = 0.0;
      } else if (c26_ar == 0.0) {
        c26_V[c26_i176].re = 0.0;
        c26_V[c26_i176].im = c26_ai / c26_br;
      } else {
        c26_V[c26_i176].re = c26_ar / c26_br;
        c26_V[c26_i176].im = c26_ai / c26_br;
      }
    } else if (c26_br == 0.0) {
      if (c26_ar == 0.0) {
        c26_V[c26_i176].re = c26_ai / c26_bi;
        c26_V[c26_i176].im = 0.0;
      } else if (c26_ai == 0.0) {
        c26_V[c26_i176].re = 0.0;
        c26_V[c26_i176].im = -(c26_ar / c26_bi);
      } else {
        c26_V[c26_i176].re = c26_ai / c26_bi;
        c26_V[c26_i176].im = -(c26_ar / c26_bi);
      }
    } else {
      c26_brm = muDoubleScalarAbs(c26_br);
      c26_bim = muDoubleScalarAbs(c26_bi);
      if (c26_brm > c26_bim) {
        c26_d_s = c26_bi / c26_br;
        c26_d = c26_br + c26_d_s * c26_bi;
        c26_nr = c26_ar + c26_d_s * c26_ai;
        c26_ni = c26_ai - c26_d_s * c26_ar;
        c26_V[c26_i176].re = c26_nr / c26_d;
        c26_V[c26_i176].im = c26_ni / c26_d;
      } else if (c26_bim == c26_brm) {
        if (c26_br > 0.0) {
          c26_sgnbr = 0.5;
        } else {
          c26_sgnbr = -0.5;
        }

        if (c26_bi > 0.0) {
          c26_sgnbi = 0.5;
        } else {
          c26_sgnbi = -0.5;
        }

        c26_nr = c26_ar * c26_sgnbr + c26_ai * c26_sgnbi;
        c26_ni = c26_ai * c26_sgnbr - c26_ar * c26_sgnbi;
        c26_V[c26_i176].re = c26_nr / c26_brm;
        c26_V[c26_i176].im = c26_ni / c26_brm;
      } else {
        c26_d_s = c26_br / c26_bi;
        c26_d = c26_bi + c26_d_s * c26_br;
        c26_nr = c26_d_s * c26_ar + c26_ai;
        c26_ni = c26_d_s * c26_ai - c26_ar;
        c26_V[c26_i176].re = c26_nr / c26_d;
        c26_V[c26_i176].im = c26_ni / c26_d;
      }
    }
  }

  if (c26_e_info != 0) {
    c26_eml_warning(chartInstance);
  }
}

static void c26_b_assert(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c26_c_assert(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c26_parseopts(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c26_eml_matlab_zlangeM(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_x[4])
{
  real_T c26_y;
  int32_T c26_k;
  real_T c26_b_k;
  creal_T c26_b_x;
  real_T c26_x1;
  real_T c26_x2;
  real_T c26_a;
  real_T c26_b;
  real_T c26_absxk;
  real_T c26_c_x;
  boolean_T c26_b_b;
  boolean_T exitg1;
  (void)chartInstance;
  c26_y = 0.0;
  c26_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c26_k < 4)) {
    c26_b_k = 1.0 + (real_T)c26_k;
    c26_b_x.re = c26_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c26_b_k), 1, 4, 1, 0) - 1].re;
    c26_b_x.im = c26_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c26_b_k), 1, 4, 1, 0) - 1].im;
    c26_x1 = c26_b_x.re;
    c26_x2 = c26_b_x.im;
    c26_a = c26_x1;
    c26_b = c26_x2;
    c26_absxk = muDoubleScalarHypot(c26_a, c26_b);
    c26_c_x = c26_absxk;
    c26_b_b = muDoubleScalarIsNaN(c26_c_x);
    if (c26_b_b) {
      c26_y = rtNaN;
      exitg1 = true;
    } else {
      if (c26_absxk > c26_y) {
        c26_y = c26_absxk;
      }

      c26_k++;
    }
  }

  return c26_y;
}

static real_T c26_b_abs(SFc26_hybridSysSimInstanceStruct *chartInstance, creal_T
  c26_x)
{
  real_T c26_x1;
  real_T c26_x2;
  real_T c26_a;
  real_T c26_b;
  (void)chartInstance;
  c26_x1 = c26_x.re;
  c26_x2 = c26_x.im;
  c26_a = c26_x1;
  c26_b = c26_x2;
  return muDoubleScalarHypot(c26_a, c26_b);
}

static void c26_eml_matlab_zlascl(SFc26_hybridSysSimInstanceStruct
  *chartInstance, real_T c26_cfrom, real_T c26_cto, creal_T c26_A[4], creal_T
  c26_b_A[4])
{
  int32_T c26_i177;
  for (c26_i177 = 0; c26_i177 < 4; c26_i177++) {
    c26_b_A[c26_i177] = c26_A[c26_i177];
  }

  c26_b_eml_matlab_zlascl(chartInstance, c26_cfrom, c26_cto, c26_b_A);
}

static void c26_eml_matlab_zggbal(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[4], creal_T c26_b_A[4], int32_T *c26_ilo,
  int32_T *c26_ihi, int32_T c26_rscale[2])
{
  int32_T c26_i178;
  for (c26_i178 = 0; c26_i178 < 4; c26_i178++) {
    c26_b_A[c26_i178] = c26_A[c26_i178];
  }

  c26_c_eml_matlab_zggbal(chartInstance, c26_b_A, c26_ilo, c26_ihi, c26_rscale);
}

static void c26_eml_matlab_zlartg(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_f, creal_T c26_g, real_T *c26_cs, creal_T *c26_sn,
  creal_T *c26_r)
{
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_y;
  real_T c26_c_x;
  real_T c26_d_x;
  real_T c26_b_y;
  real_T c26_e_x;
  real_T c26_c_y;
  real_T c26_d_y;
  real_T c26_f_x;
  real_T c26_g_x;
  real_T c26_e_y;
  real_T c26_h_x;
  real_T c26_i_x;
  real_T c26_f_y;
  real_T c26_j_x;
  real_T c26_g_y;
  real_T c26_h_y;
  real_T c26_k_x;
  real_T c26_i_y;
  real_T c26_scale;
  creal_T c26_fs;
  creal_T c26_gs;
  int32_T c26_count;
  real_T c26_rescaledir;
  int32_T c26_a;
  int32_T c26_b_a;
  static creal_T c26_dc11 = { 0.0, 0.0 };

  boolean_T c26_b_g;
  int32_T c26_c_a;
  int32_T c26_d_a;
  real_T c26_f2;
  real_T c26_g2;
  real_T c26_l_x;
  real_T c26_m_x;
  boolean_T c26_b_f;
  real_T c26_x1;
  real_T c26_x2;
  real_T c26_e_a;
  real_T c26_b;
  real_T c26_j_y;
  real_T c26_b_x1;
  real_T c26_b_x2;
  real_T c26_f_a;
  real_T c26_b_b;
  real_T c26_d;
  real_T c26_c_x1;
  real_T c26_c_x2;
  real_T c26_g_a;
  real_T c26_c_b;
  real_T c26_f2s;
  real_T c26_n_x;
  real_T c26_g2s;
  real_T c26_o_x;
  real_T c26_p_x;
  real_T c26_k_y;
  real_T c26_q_x;
  real_T c26_r_x;
  real_T c26_l_y;
  real_T c26_s_x;
  real_T c26_m_y;
  real_T c26_n_y;
  real_T c26_d_x1;
  real_T c26_d_x2;
  real_T c26_h_a;
  real_T c26_d_b;
  real_T c26_dr;
  real_T c26_di;
  real_T c26_e_x1;
  real_T c26_e_x2;
  real_T c26_i_a;
  real_T c26_e_b;
  creal_T c26_b_gs;
  real_T c26_j_a;
  creal_T c26_b_sn;
  real_T c26_t_x;
  creal_T c26_c_gs;
  creal_T c26_c_sn;
  int32_T c26_b_count;
  int32_T c26_f_b;
  int32_T c26_g_b;
  boolean_T c26_overflow;
  int32_T c26_i;
  int32_T c26_c_count;
  int32_T c26_h_b;
  int32_T c26_i_b;
  boolean_T c26_b_overflow;
  int32_T c26_b_i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c26_eml_realmin(chartInstance);
  c26_eps(chartInstance);
  c26_eps(chartInstance);
  c26_x = c26_f.re;
  c26_b_x = c26_x;
  c26_y = muDoubleScalarAbs(c26_b_x);
  c26_c_x = c26_f.im;
  c26_d_x = c26_c_x;
  c26_b_y = muDoubleScalarAbs(c26_d_x);
  c26_e_x = c26_y;
  c26_c_y = c26_b_y;
  c26_d_y = c26_e_x;
  if (c26_c_y > c26_d_y) {
    c26_d_y = c26_c_y;
  }

  c26_f_x = c26_g.re;
  c26_g_x = c26_f_x;
  c26_e_y = muDoubleScalarAbs(c26_g_x);
  c26_h_x = c26_g.im;
  c26_i_x = c26_h_x;
  c26_f_y = muDoubleScalarAbs(c26_i_x);
  c26_j_x = c26_e_y;
  c26_g_y = c26_f_y;
  c26_h_y = c26_j_x;
  if (c26_g_y > c26_h_y) {
    c26_h_y = c26_g_y;
  }

  c26_k_x = c26_d_y;
  c26_i_y = c26_h_y;
  c26_scale = c26_k_x;
  if (c26_i_y > c26_scale) {
    c26_scale = c26_i_y;
  }

  c26_fs = c26_f;
  c26_gs = c26_g;
  c26_count = 0;
  c26_rescaledir = 0.0;
  guard1 = false;
  guard2 = false;
  if (c26_scale >= 7.4428285367870146E+137) {
    do {
      c26_a = c26_count;
      c26_b_a = c26_a + 1;
      c26_count = c26_b_a;
      c26_fs.re *= 1.3435752215134178E-138;
      c26_fs.im *= 1.3435752215134178E-138;
      c26_gs.re *= 1.3435752215134178E-138;
      c26_gs.im *= 1.3435752215134178E-138;
      c26_scale *= 1.3435752215134178E-138;
    } while (!(c26_scale < 7.4428285367870146E+137));

    c26_rescaledir = 1.0;
    guard1 = true;
  } else if (c26_scale <= 1.3435752215134178E-138) {
    c26_b_g = ((c26_g.re == c26_dc11.re) && (c26_g.im == c26_dc11.im));
    if (c26_b_g) {
      *c26_cs = 1.0;
      *c26_sn = c26_dc11;
      *c26_r = c26_f;
    } else {
      do {
        c26_c_a = c26_count;
        c26_d_a = c26_c_a + 1;
        c26_count = c26_d_a;
        c26_fs.re *= 7.4428285367870146E+137;
        c26_fs.im *= 7.4428285367870146E+137;
        c26_gs.re *= 7.4428285367870146E+137;
        c26_gs.im *= 7.4428285367870146E+137;
        c26_scale *= 7.4428285367870146E+137;
      } while (!(c26_scale > 1.3435752215134178E-138));

      c26_rescaledir = -1.0;
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c26_f2 = c26_fs.re * c26_fs.re + c26_fs.im * c26_fs.im;
    c26_g2 = c26_gs.re * c26_gs.re + c26_gs.im * c26_gs.im;
    c26_l_x = c26_g2;
    c26_m_x = c26_l_x;
    if (1.0 > c26_m_x) {
      c26_m_x = 1.0;
    }

    if (c26_f2 <= c26_m_x * 2.0041683600089728E-292) {
      c26_b_f = ((c26_f.re == c26_dc11.re) && (c26_f.im == c26_dc11.im));
      if (c26_b_f) {
        *c26_cs = 0.0;
        c26_x1 = c26_g.re;
        c26_x2 = c26_g.im;
        c26_e_a = c26_x1;
        c26_b = c26_x2;
        c26_j_y = muDoubleScalarHypot(c26_e_a, c26_b);
        c26_r->re = c26_j_y;
        c26_r->im = 0.0;
        c26_b_x1 = c26_gs.re;
        c26_b_x2 = c26_gs.im;
        c26_f_a = c26_b_x1;
        c26_b_b = c26_b_x2;
        c26_d = muDoubleScalarHypot(c26_f_a, c26_b_b);
        c26_sn->re = c26_gs.re / c26_d;
        c26_sn->im = -c26_gs.im / c26_d;
      } else {
        c26_c_x1 = c26_fs.re;
        c26_c_x2 = c26_fs.im;
        c26_g_a = c26_c_x1;
        c26_c_b = c26_c_x2;
        c26_f2s = muDoubleScalarHypot(c26_g_a, c26_c_b);
        c26_n_x = c26_g2;
        c26_g2s = c26_n_x;
        if (c26_g2s < 0.0) {
          c26_c_eml_error(chartInstance);
        }

        c26_g2s = muDoubleScalarSqrt(c26_g2s);
        *c26_cs = c26_f2s / c26_g2s;
        c26_o_x = c26_f.re;
        c26_p_x = c26_o_x;
        c26_k_y = muDoubleScalarAbs(c26_p_x);
        c26_q_x = c26_f.im;
        c26_r_x = c26_q_x;
        c26_l_y = muDoubleScalarAbs(c26_r_x);
        c26_s_x = c26_k_y;
        c26_m_y = c26_l_y;
        c26_n_y = c26_s_x;
        if (c26_m_y > c26_n_y) {
          c26_n_y = c26_m_y;
        }

        if (c26_n_y > 1.0) {
          c26_d_x1 = c26_f.re;
          c26_d_x2 = c26_f.im;
          c26_h_a = c26_d_x1;
          c26_d_b = c26_d_x2;
          c26_d = muDoubleScalarHypot(c26_h_a, c26_d_b);
          c26_fs.re = c26_f.re / c26_d;
          c26_fs.im = c26_f.im / c26_d;
        } else {
          c26_dr = 7.4428285367870146E+137 * c26_f.re;
          c26_di = 7.4428285367870146E+137 * c26_f.im;
          c26_e_x1 = c26_dr;
          c26_e_x2 = c26_di;
          c26_i_a = c26_e_x1;
          c26_e_b = c26_e_x2;
          c26_d = muDoubleScalarHypot(c26_i_a, c26_e_b);
          c26_fs.re = c26_dr / c26_d;
          c26_fs.im = c26_di / c26_d;
        }

        c26_b_gs.re = c26_gs.re / c26_g2s;
        c26_b_gs.im = -c26_gs.im / c26_g2s;
        c26_sn->re = c26_fs.re * c26_b_gs.re - c26_fs.im * c26_b_gs.im;
        c26_sn->im = c26_fs.re * c26_b_gs.im + c26_fs.im * c26_b_gs.re;
        c26_j_a = *c26_cs;
        c26_fs.re = c26_j_a * c26_f.re;
        c26_fs.im = c26_j_a * c26_f.im;
        c26_b_sn.re = c26_sn->re * c26_g.re - c26_sn->im * c26_g.im;
        c26_b_sn.im = c26_sn->re * c26_g.im + c26_sn->im * c26_g.re;
        c26_r->re = c26_fs.re + c26_b_sn.re;
        c26_r->im = c26_fs.im + c26_b_sn.im;
      }
    } else {
      c26_t_x = 1.0 + c26_g2 / c26_f2;
      c26_f2s = c26_t_x;
      if (c26_f2s < 0.0) {
        c26_c_eml_error(chartInstance);
      }

      c26_f2s = muDoubleScalarSqrt(c26_f2s);
      c26_r->re = c26_f2s * c26_fs.re;
      c26_r->im = c26_f2s * c26_fs.im;
      *c26_cs = 1.0 / c26_f2s;
      c26_d = c26_f2 + c26_g2;
      c26_sn->re = c26_r->re / c26_d;
      c26_sn->im = c26_r->im / c26_d;
      c26_c_gs.re = c26_gs.re;
      c26_c_gs.im = -c26_gs.im;
      c26_c_sn = *c26_sn;
      c26_sn->re = c26_c_sn.re * c26_c_gs.re - c26_c_sn.im * c26_c_gs.im;
      c26_sn->im = c26_c_sn.re * c26_c_gs.im + c26_c_sn.im * c26_c_gs.re;
      if (c26_rescaledir > 0.0) {
        c26_b_count = c26_count;
        c26_f_b = c26_b_count;
        c26_g_b = c26_f_b;
        if (1 > c26_g_b) {
          c26_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_overflow = (c26_g_b > 2147483646);
        }

        if (c26_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_overflow);
        }

        for (c26_i = 1; c26_i <= c26_b_count; c26_i++) {
          c26_r->re *= 7.4428285367870146E+137;
          c26_r->im *= 7.4428285367870146E+137;
        }
      } else {
        if (c26_rescaledir < 0.0) {
          c26_c_count = c26_count;
          c26_h_b = c26_c_count;
          c26_i_b = c26_h_b;
          if (1 > c26_i_b) {
            c26_b_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_b_overflow = (c26_i_b > 2147483646);
          }

          if (c26_b_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
          }

          for (c26_b_i = 1; c26_b_i <= c26_c_count; c26_b_i++) {
            c26_r->re *= 1.3435752215134178E-138;
            c26_r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

static void c26_eml_matlab_zhgeqz(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[4], int32_T c26_ilo, int32_T c26_ihi, int32_T
  *c26_info, creal_T c26_alpha1[2], creal_T c26_beta1[2])
{
  static creal_T c26_dc12 = { 0.0, 0.0 };

  int32_T c26_i179;
  creal_T c26_b_A[4];
  int32_T c26_i180;
  int32_T c26_i181;
  static creal_T c26_dc13 = { 0.0, 0.0 };

  creal_T c26_eshift;
  creal_T c26_ctemp;
  creal_T c26_rho;
  int32_T c26_i182;
  creal_T c26_c_A[4];
  real_T c26_anorm;
  real_T c26_y;
  real_T c26_atol;
  real_T c26_b_y;
  real_T c26_x;
  real_T c26_ascale;
  boolean_T c26_failed;
  int32_T c26_a;
  int32_T c26_b_a;
  int32_T c26_i183;
  int32_T c26_c_a;
  int32_T c26_d_a;
  boolean_T c26_overflow;
  int32_T c26_j;
  int32_T c26_b_j;
  int32_T c26_ifirst;
  int32_T c26_istart;
  int32_T c26_ilast;
  int32_T c26_e_a;
  int32_T c26_f_a;
  int32_T c26_ilastm1;
  int32_T c26_ifrstm;
  int32_T c26_ilastm;
  int32_T c26_iiter;
  int32_T c26_g_a;
  int32_T c26_b;
  int32_T c26_h_a;
  int32_T c26_b_b;
  int32_T c26_c;
  int32_T c26_i_a;
  int32_T c26_j_a;
  int32_T c26_b_c;
  int32_T c26_c_b;
  int32_T c26_d_b;
  int32_T c26_maxit;
  boolean_T c26_goto50;
  boolean_T c26_goto60;
  boolean_T c26_goto70;
  boolean_T c26_goto90;
  int32_T c26_b_maxit;
  int32_T c26_e_b;
  int32_T c26_f_b;
  boolean_T c26_b_overflow;
  int32_T c26_jiter;
  creal_T c26_a22;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_c_y;
  real_T c26_d_x;
  real_T c26_e_x;
  real_T c26_d_y;
  real_T c26_e_y;
  int32_T c26_k_a;
  int32_T c26_l_a;
  int32_T c26_jm1;
  boolean_T c26_ilazro;
  real_T c26_f_x;
  real_T c26_g_x;
  real_T c26_f_y;
  real_T c26_h_x;
  real_T c26_i_x;
  real_T c26_g_y;
  real_T c26_h_y;
  boolean_T c26_b22;
  int32_T c26_i184;
  int32_T c26_i185;
  creal_T c26_d_A;
  creal_T c26_e_A;
  creal_T c26_s;
  real_T c26_c_c;
  real_T c26_d_c;
  real_T c26_e_c;
  int32_T c26_xcol;
  int32_T c26_ycol;
  int32_T c26_b_ilo;
  int32_T c26_b_ihi;
  int32_T c26_c_ilo;
  int32_T c26_c_ihi;
  int32_T c26_m_a;
  int32_T c26_g_b;
  int32_T c26_n_a;
  int32_T c26_h_b;
  boolean_T c26_c_overflow;
  int32_T c26_i;
  int32_T c26_b_i;
  real_T c26_o_a;
  creal_T c26_a12;
  creal_T c26_b_s;
  creal_T c26_a21;
  real_T c26_p_a;
  creal_T c26_b_a22;
  creal_T c26_c_a22;
  creal_T c26_d_a22;
  creal_T c26_e_a22;
  int32_T c26_q_a;
  int32_T c26_r_a;
  int32_T c26_s_a;
  int32_T c26_t_a;
  creal_T c26_r2;
  real_T c26_ar;
  real_T c26_ai;
  static creal_T c26_dc14 = { 2.0, 0.0 };

  real_T c26_br;
  real_T c26_bi;
  real_T c26_brm;
  real_T c26_bim;
  real_T c26_c_s;
  real_T c26_d;
  real_T c26_nr;
  real_T c26_ni;
  real_T c26_sgnbr;
  real_T c26_sgnbi;
  creal_T c26_d_s;
  creal_T c26_b_a12;
  creal_T c26_c_a12;
  creal_T c26_b_a21;
  real_T c26_d7;
  real_T c26_d8;
  int32_T c26_u_a;
  int32_T c26_v_a;
  int32_T c26_jp1;
  int32_T c26_w_a;
  int32_T c26_x_a;
  real_T c26_j_x;
  real_T c26_k_x;
  real_T c26_i_y;
  real_T c26_l_x;
  real_T c26_m_x;
  real_T c26_j_y;
  real_T c26_k_y;
  real_T c26_temp;
  real_T c26_n_x;
  real_T c26_o_x;
  real_T c26_l_y;
  real_T c26_p_x;
  real_T c26_q_x;
  real_T c26_m_y;
  real_T c26_n_y;
  real_T c26_temp2;
  real_T c26_r_x;
  real_T c26_o_y;
  real_T c26_tempr;
  real_T c26_s_x;
  real_T c26_t_x;
  real_T c26_p_y;
  real_T c26_u_x;
  real_T c26_v_x;
  real_T c26_q_y;
  real_T c26_r_y;
  int32_T c26_y_a;
  int32_T c26_ab_a;
  int32_T c26_f_c;
  real_T c26_g_c;
  int32_T c26_bb_a;
  int32_T c26_cb_a;
  int32_T c26_db_a;
  int32_T c26_eb_a;
  creal_T c26_f_A;
  creal_T c26_g_A;
  real_T c26_h_c;
  real_T c26_i_c;
  int32_T c26_xrow;
  int32_T c26_yrow;
  int32_T c26_jlo;
  int32_T c26_jhi;
  int32_T c26_b_jlo;
  int32_T c26_b_jhi;
  int32_T c26_fb_a;
  int32_T c26_i_b;
  int32_T c26_gb_a;
  int32_T c26_j_b;
  boolean_T c26_d_overflow;
  int32_T c26_c_j;
  int32_T c26_d_j;
  real_T c26_hb_a;
  creal_T c26_e_s;
  real_T c26_ib_a;
  creal_T c26_f_a22;
  creal_T c26_g_a22;
  creal_T c26_h_a22;
  creal_T c26_i_a22;
  int32_T c26_jb_a;
  int32_T c26_kb_a;
  int32_T c26_j_c;
  int32_T c26_w_x;
  int32_T c26_s_y;
  int32_T c26_x_x;
  real_T c26_k_c;
  int32_T c26_b_xcol;
  int32_T c26_b_ycol;
  int32_T c26_d_ilo;
  int32_T c26_d_ihi;
  int32_T c26_e_ilo;
  int32_T c26_e_ihi;
  int32_T c26_lb_a;
  int32_T c26_k_b;
  int32_T c26_mb_a;
  int32_T c26_l_b;
  boolean_T c26_e_overflow;
  int32_T c26_c_i;
  int32_T c26_d_i;
  real_T c26_nb_a;
  creal_T c26_f_s;
  real_T c26_ob_a;
  creal_T c26_j_a22;
  creal_T c26_k_a22;
  creal_T c26_l_a22;
  creal_T c26_m_a22;
  int32_T c26_b_ilast;
  int32_T c26_m_b;
  int32_T c26_n_b;
  boolean_T c26_f_overflow;
  int32_T c26_k;
  int32_T c26_b_k;
  int32_T c26_pb_a;
  int32_T c26_qb_a;
  int32_T c26_i186;
  int32_T c26_o_b;
  int32_T c26_p_b;
  boolean_T c26_g_overflow;
  int32_T c26_e_j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T guard11 = false;
  c26_dc12.re = rtNaN;
  for (c26_i179 = 0; c26_i179 < 4; c26_i179++) {
    c26_b_A[c26_i179] = c26_A[c26_i179];
  }

  *c26_info = 0;
  for (c26_i180 = 0; c26_i180 < 2; c26_i180++) {
    c26_alpha1[c26_i180].re = 0.0;
    c26_alpha1[c26_i180].im = 0.0;
  }

  for (c26_i181 = 0; c26_i181 < 2; c26_i181++) {
    c26_beta1[c26_i181].re = 1.0;
    c26_beta1[c26_i181].im = 0.0;
  }

  c26_eps(chartInstance);
  c26_realmin(chartInstance);
  c26_eshift = c26_dc13;
  c26_ctemp = c26_dc13;
  c26_rho = c26_dc13;
  for (c26_i182 = 0; c26_i182 < 4; c26_i182++) {
    c26_c_A[c26_i182] = c26_b_A[c26_i182];
  }

  c26_anorm = c26_eml_matlab_zlanhs(chartInstance, c26_c_A, c26_ilo, c26_ihi);
  c26_y = 2.2204460492503131E-16 * c26_anorm;
  c26_atol = 2.2250738585072014E-308;
  if (c26_y > 2.2250738585072014E-308) {
    c26_atol = c26_y;
  }

  c26_b_y = c26_anorm;
  c26_x = 2.2250738585072014E-308;
  if (c26_b_y > 2.2250738585072014E-308) {
    c26_x = c26_b_y;
  }

  c26_ascale = 1.0 / c26_x;
  c26_failed = true;
  c26_a = c26_ihi;
  c26_b_a = c26_a + 1;
  c26_i183 = c26_b_a;
  c26_c_a = c26_i183;
  c26_d_a = c26_c_a;
  if (c26_d_a > 2) {
    c26_overflow = false;
  } else {
    c26_eml_switch_helper(chartInstance);
    c26_eml_switch_helper(chartInstance);
    c26_overflow = false;
  }

  if (c26_overflow) {
    c26_check_forloop_overflow_error(chartInstance, c26_overflow);
  }

  for (c26_j = c26_i183; c26_j < 3; c26_j++) {
    c26_b_j = c26_j;
    c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c26_b_j), 1, 2, 1, 0) - 1].re = c26_b_A
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c26_b_j), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1]
      .re;
    c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c26_b_j), 1, 2, 1, 0) - 1].im = c26_b_A
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c26_b_j), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1]
      .im;
  }

  guard1 = false;
  guard2 = false;
  if (c26_ihi >= c26_ilo) {
    c26_ifirst = c26_ilo;
    c26_istart = c26_ilo;
    c26_ilast = c26_ihi;
    c26_e_a = c26_ilast;
    c26_f_a = c26_e_a - 1;
    c26_ilastm1 = c26_f_a;
    c26_ifrstm = c26_ilo;
    c26_ilastm = c26_ihi;
    c26_iiter = 0;
    c26_g_a = c26_ihi;
    c26_b = c26_ilo;
    c26_h_a = c26_g_a;
    c26_b_b = c26_b;
    c26_c = c26_h_a - c26_b_b;
    c26_i_a = c26_c;
    c26_j_a = c26_i_a + 1;
    c26_b_c = c26_j_a;
    c26_c_b = c26_b_c;
    c26_d_b = c26_c_b;
    c26_maxit = 30 * c26_d_b;
    c26_goto50 = false;
    c26_goto60 = false;
    c26_goto70 = false;
    c26_goto90 = false;
    c26_b_maxit = c26_maxit;
    c26_e_b = c26_b_maxit;
    c26_f_b = c26_e_b;
    if (1 > c26_f_b) {
      c26_b_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_b_overflow = (c26_f_b > 2147483646);
    }

    if (c26_b_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
    }

    c26_jiter = 1;
    do {
      exitg1 = 0;
      if (c26_jiter <= c26_b_maxit) {
        if (c26_ilast == c26_ilo) {
          c26_goto60 = true;
        } else {
          c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) << 1))
            - 1].re;
          c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) << 1))
            - 1].im;
          c26_b_x = c26_a22.re;
          c26_c_x = c26_b_x;
          c26_c_y = muDoubleScalarAbs(c26_c_x);
          c26_d_x = c26_a22.im;
          c26_e_x = c26_d_x;
          c26_d_y = muDoubleScalarAbs(c26_e_x);
          c26_e_y = c26_c_y + c26_d_y;
          if (c26_e_y <= c26_atol) {
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0)
                       - 1) << 1)) - 1].re = c26_dc13.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0)
                       - 1) << 1)) - 1].im = c26_dc13.im;
            c26_goto60 = true;
          } else {
            c26_b_j = c26_ilastm1;
            exitg3 = false;
            while ((exitg3 == false) && (c26_b_j >= c26_ilo)) {
              c26_k_a = c26_b_j;
              c26_l_a = c26_k_a - 1;
              c26_jm1 = c26_l_a;
              if (c26_b_j == c26_ilo) {
                c26_ilazro = true;
              } else {
                c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2, 0) - 1) << 1))
                  - 1].re;
                c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2, 0) - 1) << 1))
                  - 1].im;
                c26_f_x = c26_a22.re;
                c26_g_x = c26_f_x;
                c26_f_y = muDoubleScalarAbs(c26_g_x);
                c26_h_x = c26_a22.im;
                c26_i_x = c26_h_x;
                c26_g_y = muDoubleScalarAbs(c26_i_x);
                c26_h_y = c26_f_y + c26_g_y;
                if (c26_h_y <= c26_atol) {
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c26_dc13.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c26_dc13.im;
                  c26_ilazro = true;
                } else {
                  c26_ilazro = false;
                }
              }

              if (c26_ilazro) {
                c26_ifirst = c26_b_j;
                c26_goto70 = true;
                exitg3 = true;
              } else {
                c26_b_j = c26_jm1;
              }
            }
          }
        }

        guard3 = false;
        guard4 = false;
        if (c26_goto50) {
          guard4 = true;
        } else if (c26_goto60) {
          guard4 = true;
        } else if (c26_goto70) {
          guard3 = true;
        } else {
          c26_b22 = false;
        }

        if (guard4 == true) {
          guard3 = true;
        }

        if (guard3 == true) {
          c26_b22 = true;
        }

        if (!c26_b22) {
          for (c26_i184 = 0; c26_i184 < 2; c26_i184++) {
            c26_alpha1[c26_i184] = c26_dc12;
          }

          for (c26_i185 = 0; c26_i185 < 2; c26_i185++) {
            c26_beta1[c26_i185] = c26_dc12;
          }

          *c26_info = 1;
          exitg1 = 1;
        } else {
          if (c26_goto50) {
            c26_goto50 = false;
            c26_d_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c26_d_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c26_e_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c26_e_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c26_eml_matlab_zlartg(chartInstance, c26_d_A, c26_e_A, &c26_c_c,
                                  &c26_s, &c26_a22);
            c26_d_c = c26_c_c;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) -
                       1) << 1)) - 1].re = c26_a22.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) -
                       1) << 1)) - 1].im = c26_a22.im;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0)
                       - 1) << 1)) - 1].re = c26_dc13.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0)
                       - 1) << 1)) - 1].im = c26_dc13.im;
            c26_e_c = c26_d_c;
            c26_xcol = c26_ilast;
            c26_ycol = c26_ilastm1;
            c26_b_ilo = c26_ifrstm;
            c26_b_ihi = c26_ilastm1;
            c26_c_ilo = c26_b_ilo;
            c26_c_ihi = c26_b_ihi;
            c26_m_a = c26_c_ilo;
            c26_g_b = c26_c_ihi;
            c26_n_a = c26_m_a;
            c26_h_b = c26_g_b;
            if (c26_n_a > c26_h_b) {
              c26_c_overflow = false;
            } else {
              c26_eml_switch_helper(chartInstance);
              c26_eml_switch_helper(chartInstance);
              c26_c_overflow = (c26_h_b > 2147483646);
            }

            if (c26_c_overflow) {
              c26_check_forloop_overflow_error(chartInstance, c26_c_overflow);
            }

            for (c26_i = c26_c_ilo; c26_i <= c26_c_ihi; c26_i++) {
              c26_b_i = c26_i;
              c26_o_a = c26_e_c;
              c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) - 1) << 1))
                - 1].re;
              c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) - 1) << 1))
                - 1].im;
              c26_a12.re = c26_o_a * c26_a22.re;
              c26_a12.im = c26_o_a * c26_a22.im;
              c26_b_s.re = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1)) - 1].re - c26_s.im *
                c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                         ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1))
                - 1].im;
              c26_b_s.im = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1)) - 1].im + c26_s.im *
                c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                         ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1))
                - 1].re;
              c26_a21.re = c26_a12.re + c26_b_s.re;
              c26_a21.im = c26_a12.im + c26_b_s.im;
              c26_p_a = c26_e_c;
              c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1))
                - 1].re;
              c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0) - 1) << 1))
                - 1].im;
              c26_a12.re = c26_p_a * c26_a22.re;
              c26_a12.im = c26_p_a * c26_a22.im;
              c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) - 1) << 1))
                - 1].re;
              c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0) - 1) << 1))
                - 1].im;
              c26_b_a22 = c26_a22;
              c26_c_a22 = c26_a22;
              c26_d_a22 = c26_a22;
              c26_e_a22 = c26_a22;
              c26_a22.re = c26_s.re * c26_b_a22.re + c26_s.im * c26_c_a22.im;
              c26_a22.im = c26_s.re * c26_d_a22.im - c26_s.im * c26_e_a22.re;
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0)
                         - 1) << 1)) - 1].re = c26_a12.re - c26_a22.re;
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 2, 2, 0)
                         - 1) << 1)) - 1].im = c26_a12.im - c26_a22.im;
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0)
                         - 1) << 1)) - 1].re = c26_a21.re;
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                          _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 2, 2, 0)
                         - 1) << 1)) - 1].im = c26_a21.im;
            }

            c26_goto60 = true;
          }

          guard11 = false;
          if (c26_goto60) {
            c26_goto60 = false;
            c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) - 1].re =
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) - 1) << 1))
              - 1].re;
            c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) - 1].im =
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) - 1) << 1))
              - 1].im;
            c26_ilast = c26_ilastm1;
            c26_q_a = c26_ilast;
            c26_r_a = c26_q_a - 1;
            c26_ilastm1 = c26_r_a;
            if (c26_ilast < c26_ilo) {
              c26_failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              c26_iiter = 0;
              c26_eshift = c26_dc13;
              c26_ilastm = c26_ilast;
              if (c26_ifrstm > c26_ilast) {
                c26_ifrstm = c26_ilo;
              }

              guard11 = true;
            }
          } else {
            if (c26_goto70) {
              c26_goto70 = false;
              c26_s_a = c26_iiter;
              c26_t_a = c26_s_a + 1;
              c26_iiter = c26_t_a;
              c26_ifrstm = c26_ifirst;
              if (c26_mod(chartInstance, c26_iiter) != 0) {
                c26_rho.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) <<
                  1)) - 1].re;
                c26_rho.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) <<
                  1)) - 1].im;
                c26_r2.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) - 1) <<
                                      1)) - 1].re;
                c26_r2.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) - 1) <<
                                      1)) - 1].im;
                c26_a12.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) - 1) <<
                  1)) - 1].re;
                c26_a12.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 2, 0) - 1) <<
                  1)) - 1].im;
                c26_a21.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) <<
                  1)) - 1].re;
                c26_a21.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) <<
                  1)) - 1].im;
                c26_a22.re = c26_r2.re - c26_rho.re;
                c26_a22.im = c26_r2.im - c26_rho.im;
                c26_a22.re = -c26_a22.re;
                c26_a22.im = -c26_a22.im;
                c26_ar = c26_a22.re;
                c26_ai = c26_a22.im;
                c26_br = c26_dc14.re;
                c26_bi = c26_dc14.im;
                if (c26_bi == 0.0) {
                  if (c26_ai == 0.0) {
                    c26_s.re = c26_ar / c26_br;
                    c26_s.im = 0.0;
                  } else if (c26_ar == 0.0) {
                    c26_s.re = 0.0;
                    c26_s.im = c26_ai / c26_br;
                  } else {
                    c26_s.re = c26_ar / c26_br;
                    c26_s.im = c26_ai / c26_br;
                  }
                } else if (c26_br == 0.0) {
                  if (c26_ar == 0.0) {
                    c26_s.re = c26_ai / c26_bi;
                    c26_s.im = 0.0;
                  } else if (c26_ai == 0.0) {
                    c26_s.re = 0.0;
                    c26_s.im = -(c26_ar / c26_bi);
                  } else {
                    c26_s.re = c26_ai / c26_bi;
                    c26_s.im = -(c26_ar / c26_bi);
                  }
                } else {
                  c26_brm = muDoubleScalarAbs(c26_br);
                  c26_bim = muDoubleScalarAbs(c26_bi);
                  if (c26_brm > c26_bim) {
                    c26_c_s = c26_bi / c26_br;
                    c26_d = c26_br + c26_c_s * c26_bi;
                    c26_nr = c26_ar + c26_c_s * c26_ai;
                    c26_ni = c26_ai - c26_c_s * c26_ar;
                    c26_s.re = c26_nr / c26_d;
                    c26_s.im = c26_ni / c26_d;
                  } else if (c26_bim == c26_brm) {
                    if (c26_br > 0.0) {
                      c26_sgnbr = 0.5;
                    } else {
                      c26_sgnbr = -0.5;
                    }

                    if (c26_bi > 0.0) {
                      c26_sgnbi = 0.5;
                    } else {
                      c26_sgnbi = -0.5;
                    }

                    c26_nr = c26_ar * c26_sgnbr + c26_ai * c26_sgnbi;
                    c26_ni = c26_ai * c26_sgnbr - c26_ar * c26_sgnbi;
                    c26_s.re = c26_nr / c26_brm;
                    c26_s.im = c26_ni / c26_brm;
                  } else {
                    c26_c_s = c26_br / c26_bi;
                    c26_d = c26_bi + c26_c_s * c26_br;
                    c26_nr = c26_c_s * c26_ar + c26_ai;
                    c26_ni = c26_c_s * c26_ai - c26_ar;
                    c26_s.re = c26_nr / c26_d;
                    c26_s.im = c26_ni / c26_d;
                  }
                }

                c26_d_s.re = c26_s.re * c26_s.re - c26_s.im * c26_s.im;
                c26_d_s.im = c26_s.re * c26_s.im + c26_s.im * c26_s.re;
                c26_b_a12.re = c26_a12.re * c26_a21.re - c26_a12.im * c26_a21.im;
                c26_b_a12.im = c26_a12.re * c26_a21.im + c26_a12.im * c26_a21.re;
                c26_a22.re = c26_d_s.re + c26_b_a12.re;
                c26_a22.im = c26_d_s.im + c26_b_a12.im;
                c26_d_sqrt(chartInstance, &c26_a22);
                c26_a12.re = c26_rho.re - (c26_s.re - c26_a22.re);
                c26_a12.im = c26_rho.im - (c26_s.im - c26_a22.im);
                c26_a21.re = c26_rho.re - (c26_s.re + c26_a22.re);
                c26_a21.im = c26_rho.im - (c26_s.im + c26_a22.im);
                c26_c_a12.re = c26_a12.re - c26_r2.re;
                c26_c_a12.im = c26_a12.im - c26_r2.im;
                c26_b_a21.re = c26_a21.re - c26_r2.re;
                c26_b_a21.im = c26_a21.im - c26_r2.im;
                c26_d7 = c26_b_abs(chartInstance, c26_c_a12);
                c26_d8 = c26_b_abs(chartInstance, c26_b_a21);
                if (c26_d7 <= c26_d8) {
                  c26_a21 = c26_a12;
                  c26_rho.re = c26_s.re - c26_a22.re;
                  c26_rho.im = c26_s.im - c26_a22.im;
                } else {
                  c26_rho.re = c26_s.re + c26_a22.re;
                  c26_rho.im = c26_s.im + c26_a22.im;
                }
              } else {
                c26_eshift.re += c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0)
                  + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) <<
                     1)) - 1].re;
                c26_eshift.im += c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 2, 1, 0)
                  + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 2, 2, 0) - 1) <<
                     1)) - 1].im;
                c26_a21 = c26_eshift;
              }

              c26_b_j = c26_ilastm1;
              c26_u_a = c26_b_j;
              c26_v_a = c26_u_a + 1;
              c26_jp1 = c26_v_a;
              exitg2 = false;
              while ((exitg2 == false) && (c26_b_j > c26_ifirst)) {
                c26_w_a = c26_b_j;
                c26_x_a = c26_w_a - 1;
                c26_jm1 = c26_x_a;
                c26_istart = c26_b_j;
                c26_ctemp.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0) +
                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                  "", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].re -
                  c26_a21.re;
                c26_ctemp.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0) +
                  ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                  "", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].im -
                  c26_a21.im;
                c26_j_x = c26_ctemp.re;
                c26_k_x = c26_j_x;
                c26_i_y = muDoubleScalarAbs(c26_k_x);
                c26_l_x = c26_ctemp.im;
                c26_m_x = c26_l_x;
                c26_j_y = muDoubleScalarAbs(c26_m_x);
                c26_k_y = c26_i_y + c26_j_y;
                c26_temp = c26_ascale * c26_k_y;
                c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1))
                  - 1].re;
                c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1))
                  - 1].im;
                c26_n_x = c26_a22.re;
                c26_o_x = c26_n_x;
                c26_l_y = muDoubleScalarAbs(c26_o_x);
                c26_p_x = c26_a22.im;
                c26_q_x = c26_p_x;
                c26_m_y = muDoubleScalarAbs(c26_q_x);
                c26_n_y = c26_l_y + c26_m_y;
                c26_temp2 = c26_ascale * c26_n_y;
                c26_r_x = c26_temp;
                c26_o_y = c26_temp2;
                c26_tempr = c26_r_x;
                if (c26_o_y > c26_tempr) {
                  c26_tempr = c26_o_y;
                }

                if (c26_tempr < 1.0) {
                  if (c26_tempr != 0.0) {
                    c26_temp /= c26_tempr;
                    c26_temp2 /= c26_tempr;
                  }
                }

                c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2, 0) - 1) << 1))
                  - 1].re;
                c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0) +
                                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2, 0) - 1) << 1))
                  - 1].im;
                c26_s_x = c26_a22.re;
                c26_t_x = c26_s_x;
                c26_p_y = muDoubleScalarAbs(c26_t_x);
                c26_u_x = c26_a22.im;
                c26_v_x = c26_u_x;
                c26_q_y = muDoubleScalarAbs(c26_v_x);
                c26_r_y = c26_p_y + c26_q_y;
                if (c26_r_y * c26_temp2 <= c26_temp * c26_atol) {
                  c26_goto90 = true;
                  exitg2 = true;
                } else {
                  c26_jp1 = c26_b_j;
                  c26_b_j = c26_jm1;
                }
              }

              if (!c26_goto90) {
                c26_istart = c26_ifirst;
                if (c26_istart == c26_ilastm1) {
                  c26_ctemp = c26_rho;
                } else {
                  c26_ctemp.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 2, 1,
                    0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 2, 2, 0) - 1)
                          << 1)) - 1].re - c26_a21.re;
                  c26_ctemp.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 2, 1,
                    0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 2, 2, 0) - 1)
                          << 1)) - 1].im - c26_a21.im;
                }

                c26_goto90 = true;
              }
            }

            if (c26_goto90) {
              c26_goto90 = false;
              c26_y_a = c26_istart;
              c26_ab_a = c26_y_a + 1;
              c26_f_c = c26_ab_a;
              c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_f_c), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 2, 2, 0) - 1) <<
                1)) - 1].re;
              c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_f_c), 1, 2, 1, 0) +
                                    ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 2, 2, 0) - 1) <<
                1)) - 1].im;
              c26_b_eml_matlab_zlartg(chartInstance, c26_ctemp, c26_a22,
                &c26_g_c, &c26_s);
              c26_d_c = c26_g_c;
              c26_b_j = c26_istart;
              c26_bb_a = c26_b_j;
              c26_cb_a = c26_bb_a - 1;
              c26_jm1 = c26_cb_a;
              while (c26_b_j < c26_ilast) {
                c26_db_a = c26_b_j;
                c26_eb_a = c26_db_a + 1;
                c26_jp1 = c26_eb_a;
                if (c26_b_j > c26_istart) {
                  c26_f_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c26_f_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c26_g_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c26_g_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c26_eml_matlab_zlartg(chartInstance, c26_f_A, c26_g_A,
                                        &c26_h_c, &c26_s, &c26_a22);
                  c26_d_c = c26_h_c;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c26_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c26_a22.im;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c26_dc13.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c26_dc13.im;
                }

                c26_i_c = c26_d_c;
                c26_xrow = c26_b_j;
                c26_yrow = c26_jp1;
                c26_jlo = c26_b_j;
                c26_jhi = c26_ilastm;
                c26_b_jlo = c26_jlo;
                c26_b_jhi = c26_jhi;
                c26_fb_a = c26_b_jlo;
                c26_i_b = c26_b_jhi;
                c26_gb_a = c26_fb_a;
                c26_j_b = c26_i_b;
                if (c26_gb_a > c26_j_b) {
                  c26_d_overflow = false;
                } else {
                  c26_eml_switch_helper(chartInstance);
                  c26_eml_switch_helper(chartInstance);
                  c26_d_overflow = (c26_j_b > 2147483646);
                }

                if (c26_d_overflow) {
                  c26_check_forloop_overflow_error(chartInstance, c26_d_overflow);
                }

                for (c26_c_j = c26_b_jlo; c26_c_j <= c26_b_jhi; c26_c_j++) {
                  c26_d_j = c26_c_j;
                  c26_hb_a = c26_i_c;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c26_a12.re = c26_hb_a * c26_a22.re;
                  c26_a12.im = c26_hb_a * c26_a22.im;
                  c26_e_s.re = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2,
                    1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0) - 1) <<
                             1)) - 1].re - c26_s.im * c26_b_A
                    [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0) -
                        1) << 1)) - 1].im;
                  c26_e_s.im = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2,
                    1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0) - 1) <<
                             1)) - 1].im + c26_s.im * c26_b_A
                    [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0) -
                        1) << 1)) - 1].re;
                  c26_a21.re = c26_a12.re + c26_e_s.re;
                  c26_a21.im = c26_a12.im + c26_e_s.im;
                  c26_ib_a = c26_i_c;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c26_a12.re = c26_ib_a * c26_a22.re;
                  c26_a12.im = c26_ib_a * c26_a22.im;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0)
                    - 1) << 1)) - 1].im;
                  c26_f_a22 = c26_a22;
                  c26_g_a22 = c26_a22;
                  c26_h_a22 = c26_a22;
                  c26_i_a22 = c26_a22;
                  c26_a22.re = c26_s.re * c26_f_a22.re + c26_s.im * c26_g_a22.im;
                  c26_a22.im = c26_s.re * c26_h_a22.im - c26_s.im * c26_i_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c26_a12.re - c26_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c26_a12.im - c26_a22.im;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2,
                              0) - 1) << 1)) - 1].re = c26_a21.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2,
                              0) - 1) << 1)) - 1].im = c26_a21.im;
                }

                c26_s.re = -c26_s.re;
                c26_s.im = -c26_s.im;
                c26_jb_a = c26_jp1;
                c26_kb_a = c26_jb_a + 1;
                c26_j_c = c26_kb_a;
                c26_w_x = c26_j_c;
                c26_s_y = c26_ilast;
                c26_x_x = c26_w_x;
                if (c26_s_y < c26_x_x) {
                  c26_x_x = c26_s_y;
                }

                c26_k_c = c26_d_c;
                c26_b_xcol = c26_jp1;
                c26_b_ycol = c26_b_j;
                c26_d_ilo = c26_ifrstm;
                c26_d_ihi = c26_x_x;
                c26_e_ilo = c26_d_ilo;
                c26_e_ihi = c26_d_ihi;
                c26_lb_a = c26_e_ilo;
                c26_k_b = c26_e_ihi;
                c26_mb_a = c26_lb_a;
                c26_l_b = c26_k_b;
                if (c26_mb_a > c26_l_b) {
                  c26_e_overflow = false;
                } else {
                  c26_eml_switch_helper(chartInstance);
                  c26_eml_switch_helper(chartInstance);
                  c26_e_overflow = (c26_l_b > 2147483646);
                }

                if (c26_e_overflow) {
                  c26_check_forloop_overflow_error(chartInstance, c26_e_overflow);
                }

                for (c26_c_i = c26_e_ilo; c26_c_i <= c26_e_ihi; c26_c_i++) {
                  c26_d_i = c26_c_i;
                  c26_nb_a = c26_k_c;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 2, 2,
                    0) - 1) << 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 2, 2,
                    0) - 1) << 1)) - 1].im;
                  c26_a12.re = c26_nb_a * c26_a22.re;
                  c26_a12.im = c26_nb_a * c26_a22.im;
                  c26_f_s.re = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2,
                    1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 2, 2, 0) - 1)
                             << 1)) - 1].re - c26_s.im * c26_b_A
                    [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 2, 2, 0)
                        - 1) << 1)) - 1].im;
                  c26_f_s.im = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2,
                    1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 2, 2, 0) - 1)
                             << 1)) - 1].im + c26_s.im * c26_b_A
                    [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 2, 2, 0)
                        - 1) << 1)) - 1].re;
                  c26_a21.re = c26_a12.re + c26_f_s.re;
                  c26_a21.im = c26_a12.im + c26_f_s.im;
                  c26_ob_a = c26_k_c;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 2, 2,
                    0) - 1) << 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 2, 2,
                    0) - 1) << 1)) - 1].im;
                  c26_a12.re = c26_ob_a * c26_a22.re;
                  c26_a12.im = c26_ob_a * c26_a22.im;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 2, 2,
                    0) - 1) << 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 2, 2,
                    0) - 1) << 1)) - 1].im;
                  c26_j_a22 = c26_a22;
                  c26_k_a22 = c26_a22;
                  c26_l_a22 = c26_a22;
                  c26_m_a22 = c26_a22;
                  c26_a22.re = c26_s.re * c26_j_a22.re + c26_s.im * c26_k_a22.im;
                  c26_a22.im = c26_s.re * c26_l_a22.im - c26_s.im * c26_m_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 2,
                              2, 0) - 1) << 1)) - 1].re = c26_a12.re -
                    c26_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 2,
                              2, 0) - 1) << 1)) - 1].im = c26_a12.im -
                    c26_a22.im;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 2,
                              2, 0) - 1) << 1)) - 1].re = c26_a21.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0)
                           + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                              _SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 2,
                              2, 0) - 1) << 1)) - 1].im = c26_a21.im;
                }

                c26_jm1 = c26_b_j;
                c26_b_j = c26_jp1;
              }
            }

            guard11 = true;
          }

          if (guard11 == true) {
            c26_jiter++;
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
    if (c26_failed) {
      *c26_info = c26_ilast;
      c26_b_ilast = c26_ilast;
      c26_m_b = c26_b_ilast;
      c26_n_b = c26_m_b;
      if (1 > c26_n_b) {
        c26_f_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_f_overflow = (c26_n_b > 2147483646);
      }

      if (c26_f_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_f_overflow);
      }

      for (c26_k = 1; c26_k <= c26_b_ilast; c26_k++) {
        c26_b_k = c26_k;
        c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c26_b_k), 1, 2, 1, 0) - 1].re = c26_dc12.re;
        c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c26_b_k), 1, 2, 1, 0) - 1].im = c26_dc12.im;
        c26_beta1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_k), 1, 2, 1, 0) - 1].re = c26_dc12.re;
        c26_beta1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_k), 1, 2, 1, 0) - 1].im = c26_dc12.im;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    c26_pb_a = c26_ilo;
    c26_qb_a = c26_pb_a - 1;
    c26_i186 = c26_qb_a;
    c26_o_b = c26_i186;
    c26_p_b = c26_o_b;
    if (1 > c26_p_b) {
      c26_g_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_g_overflow = (c26_p_b > 2147483646);
    }

    if (c26_g_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_g_overflow);
    }

    for (c26_e_j = 1; c26_e_j <= c26_i186; c26_e_j++) {
      c26_b_j = c26_e_j;
      c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c26_b_j), 1, 2, 1, 0) - 1].re = c26_b_A
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_b_j), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) <<
           1)) - 1].re;
      c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c26_b_j), 1, 2, 1, 0) - 1].im = c26_b_A
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_b_j), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) <<
           1)) - 1].im;
    }
  }
}

static real_T c26_eml_matlab_zlanhs(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[4], int32_T c26_ilo, int32_T c26_ihi)
{
  real_T c26_f;
  real_T c26_scale;
  real_T c26_sumsq;
  boolean_T c26_firstNonZero;
  int32_T c26_b_ilo;
  int32_T c26_b_ihi;
  int32_T c26_a;
  int32_T c26_b;
  int32_T c26_b_a;
  int32_T c26_b_b;
  boolean_T c26_overflow;
  int32_T c26_j;
  int32_T c26_b_j;
  int32_T c26_c_ilo;
  int32_T c26_c_a;
  int32_T c26_d_a;
  int32_T c26_c;
  int32_T c26_x;
  int32_T c26_y;
  int32_T c26_i187;
  int32_T c26_e_a;
  int32_T c26_c_b;
  int32_T c26_f_a;
  int32_T c26_d_b;
  boolean_T c26_b_overflow;
  int32_T c26_i;
  int32_T c26_b_i;
  creal_T c26_Aij;
  real_T c26_reAij;
  real_T c26_imAij;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_temp1;
  real_T c26_temp2;
  real_T c26_d_x;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_g_x;
  c26_f = 0.0;
  if (c26_ilo > c26_ihi) {
  } else {
    c26_scale = 0.0;
    c26_sumsq = 0.0;
    c26_firstNonZero = true;
    c26_b_ilo = c26_ilo;
    c26_b_ihi = c26_ihi;
    c26_a = c26_b_ilo;
    c26_b = c26_b_ihi;
    c26_b_a = c26_a;
    c26_b_b = c26_b;
    if (c26_b_a > c26_b_b) {
      c26_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_overflow = (c26_b_b > 2147483646);
    }

    if (c26_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_overflow);
    }

    for (c26_j = c26_b_ilo; c26_j <= c26_b_ihi; c26_j++) {
      c26_b_j = c26_j;
      c26_c_ilo = c26_ilo;
      c26_c_a = c26_b_j;
      c26_d_a = c26_c_a;
      c26_c = c26_d_a;
      c26_x = c26_c + 1;
      c26_y = c26_ihi;
      c26_i187 = c26_x;
      if (c26_y < c26_i187) {
        c26_i187 = c26_y;
      }

      c26_e_a = c26_c_ilo;
      c26_c_b = c26_i187;
      c26_f_a = c26_e_a;
      c26_d_b = c26_c_b;
      if (c26_f_a > c26_d_b) {
        c26_b_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_b_overflow = (c26_d_b > 2147483646);
      }

      if (c26_b_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
      }

      for (c26_i = c26_c_ilo; c26_i <= c26_i187; c26_i++) {
        c26_b_i = c26_i;
        c26_Aij.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].
          re;
        c26_Aij.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 2, 1, 0) +
                            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1].
          im;
        c26_reAij = c26_Aij.re;
        c26_imAij = c26_Aij.im;
        if (c26_reAij != 0.0) {
          c26_b_x = c26_reAij;
          c26_c_x = c26_b_x;
          c26_temp1 = muDoubleScalarAbs(c26_c_x);
          if (c26_firstNonZero) {
            c26_sumsq = 1.0;
            c26_scale = c26_temp1;
            c26_firstNonZero = false;
          } else if (c26_scale < c26_temp1) {
            c26_temp2 = c26_scale / c26_temp1;
            c26_sumsq = 1.0 + c26_sumsq * c26_temp2 * c26_temp2;
            c26_scale = c26_temp1;
          } else {
            c26_temp2 = c26_temp1 / c26_scale;
            c26_sumsq += c26_temp2 * c26_temp2;
          }
        }

        if (c26_imAij != 0.0) {
          c26_d_x = c26_imAij;
          c26_e_x = c26_d_x;
          c26_temp1 = muDoubleScalarAbs(c26_e_x);
          if (c26_firstNonZero) {
            c26_sumsq = 1.0;
            c26_scale = c26_temp1;
            c26_firstNonZero = false;
          } else if (c26_scale < c26_temp1) {
            c26_temp2 = c26_scale / c26_temp1;
            c26_sumsq = 1.0 + c26_sumsq * c26_temp2 * c26_temp2;
            c26_scale = c26_temp1;
          } else {
            c26_temp2 = c26_temp1 / c26_scale;
            c26_sumsq += c26_temp2 * c26_temp2;
          }
        }
      }
    }

    c26_f_x = c26_sumsq;
    c26_g_x = c26_f_x;
    if (c26_g_x < 0.0) {
      c26_c_eml_error(chartInstance);
    }

    c26_g_x = muDoubleScalarSqrt(c26_g_x);
    c26_f = c26_scale * c26_g_x;
  }

  return c26_f;
}

static int32_T c26_mod(SFc26_hybridSysSimInstanceStruct *chartInstance, int32_T
  c26_x)
{
  int32_T c26_b_x;
  int32_T c26_t;
  c26_b_x = c26_x;
  c26_t = c26_div_s32(chartInstance, c26_b_x, 10);
  c26_t *= 10;
  return c26_b_x - c26_t;
}

static creal_T c26_b_sqrt(SFc26_hybridSysSimInstanceStruct *chartInstance,
  creal_T c26_x)
{
  creal_T c26_b_x;
  c26_b_x = c26_x;
  c26_d_sqrt(chartInstance, &c26_b_x);
  return c26_b_x;
}

static void c26_realmax(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c26_b_eml_matlab_zlartg(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_f, creal_T c26_g, real_T *c26_cs, creal_T *c26_sn)
{
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_y;
  real_T c26_c_x;
  real_T c26_d_x;
  real_T c26_b_y;
  real_T c26_e_x;
  real_T c26_c_y;
  real_T c26_d_y;
  real_T c26_f_x;
  real_T c26_g_x;
  real_T c26_e_y;
  real_T c26_h_x;
  real_T c26_i_x;
  real_T c26_f_y;
  real_T c26_j_x;
  real_T c26_g_y;
  real_T c26_h_y;
  real_T c26_k_x;
  real_T c26_i_y;
  real_T c26_scale;
  creal_T c26_fs;
  creal_T c26_gs;
  int32_T c26_count;
  real_T c26_rescaledir;
  int32_T c26_a;
  int32_T c26_b_a;
  static creal_T c26_dc15 = { 0.0, 0.0 };

  boolean_T c26_b_g;
  int32_T c26_c_a;
  int32_T c26_d_a;
  real_T c26_f2;
  real_T c26_g2;
  real_T c26_l_x;
  real_T c26_m_x;
  boolean_T c26_b_f;
  real_T c26_x1;
  real_T c26_x2;
  real_T c26_e_a;
  real_T c26_b;
  real_T c26_d;
  real_T c26_b_x1;
  real_T c26_b_x2;
  real_T c26_f_a;
  real_T c26_b_b;
  real_T c26_f2s;
  real_T c26_n_x;
  real_T c26_g2s;
  real_T c26_o_x;
  real_T c26_p_x;
  real_T c26_j_y;
  real_T c26_q_x;
  real_T c26_r_x;
  real_T c26_k_y;
  real_T c26_s_x;
  real_T c26_l_y;
  real_T c26_m_y;
  real_T c26_c_x1;
  real_T c26_c_x2;
  real_T c26_g_a;
  real_T c26_c_b;
  real_T c26_dr;
  real_T c26_di;
  real_T c26_d_x1;
  real_T c26_d_x2;
  real_T c26_h_a;
  real_T c26_d_b;
  creal_T c26_b_gs;
  real_T c26_t_x;
  creal_T c26_b_fs;
  creal_T c26_c_fs;
  creal_T c26_c_gs;
  creal_T c26_b_sn;
  int32_T c26_b_count;
  int32_T c26_e_b;
  int32_T c26_f_b;
  boolean_T c26_overflow;
  int32_T c26_c_count;
  int32_T c26_g_b;
  int32_T c26_h_b;
  boolean_T c26_b_overflow;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c26_eml_realmin(chartInstance);
  c26_eps(chartInstance);
  c26_eps(chartInstance);
  c26_x = c26_f.re;
  c26_b_x = c26_x;
  c26_y = muDoubleScalarAbs(c26_b_x);
  c26_c_x = c26_f.im;
  c26_d_x = c26_c_x;
  c26_b_y = muDoubleScalarAbs(c26_d_x);
  c26_e_x = c26_y;
  c26_c_y = c26_b_y;
  c26_d_y = c26_e_x;
  if (c26_c_y > c26_d_y) {
    c26_d_y = c26_c_y;
  }

  c26_f_x = c26_g.re;
  c26_g_x = c26_f_x;
  c26_e_y = muDoubleScalarAbs(c26_g_x);
  c26_h_x = c26_g.im;
  c26_i_x = c26_h_x;
  c26_f_y = muDoubleScalarAbs(c26_i_x);
  c26_j_x = c26_e_y;
  c26_g_y = c26_f_y;
  c26_h_y = c26_j_x;
  if (c26_g_y > c26_h_y) {
    c26_h_y = c26_g_y;
  }

  c26_k_x = c26_d_y;
  c26_i_y = c26_h_y;
  c26_scale = c26_k_x;
  if (c26_i_y > c26_scale) {
    c26_scale = c26_i_y;
  }

  c26_fs = c26_f;
  c26_gs = c26_g;
  c26_count = 0;
  c26_rescaledir = 0.0;
  guard1 = false;
  guard2 = false;
  if (c26_scale >= 7.4428285367870146E+137) {
    do {
      c26_a = c26_count;
      c26_b_a = c26_a + 1;
      c26_count = c26_b_a;
      c26_fs.re *= 1.3435752215134178E-138;
      c26_fs.im *= 1.3435752215134178E-138;
      c26_gs.re *= 1.3435752215134178E-138;
      c26_gs.im *= 1.3435752215134178E-138;
      c26_scale *= 1.3435752215134178E-138;
    } while (!(c26_scale < 7.4428285367870146E+137));

    c26_rescaledir = 1.0;
    guard1 = true;
  } else if (c26_scale <= 1.3435752215134178E-138) {
    c26_b_g = ((c26_g.re == c26_dc15.re) && (c26_g.im == c26_dc15.im));
    if (c26_b_g) {
      *c26_cs = 1.0;
      *c26_sn = c26_dc15;
    } else {
      do {
        c26_c_a = c26_count;
        c26_d_a = c26_c_a + 1;
        c26_count = c26_d_a;
        c26_fs.re *= 7.4428285367870146E+137;
        c26_fs.im *= 7.4428285367870146E+137;
        c26_gs.re *= 7.4428285367870146E+137;
        c26_gs.im *= 7.4428285367870146E+137;
        c26_scale *= 7.4428285367870146E+137;
      } while (!(c26_scale > 1.3435752215134178E-138));

      c26_rescaledir = -1.0;
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c26_f2 = c26_fs.re * c26_fs.re + c26_fs.im * c26_fs.im;
    c26_g2 = c26_gs.re * c26_gs.re + c26_gs.im * c26_gs.im;
    c26_l_x = c26_g2;
    c26_m_x = c26_l_x;
    if (1.0 > c26_m_x) {
      c26_m_x = 1.0;
    }

    if (c26_f2 <= c26_m_x * 2.0041683600089728E-292) {
      c26_b_f = ((c26_f.re == c26_dc15.re) && (c26_f.im == c26_dc15.im));
      if (c26_b_f) {
        *c26_cs = 0.0;
        c26_x1 = c26_gs.re;
        c26_x2 = c26_gs.im;
        c26_e_a = c26_x1;
        c26_b = c26_x2;
        c26_d = muDoubleScalarHypot(c26_e_a, c26_b);
        c26_sn->re = c26_gs.re / c26_d;
        c26_sn->im = -c26_gs.im / c26_d;
      } else {
        c26_b_x1 = c26_fs.re;
        c26_b_x2 = c26_fs.im;
        c26_f_a = c26_b_x1;
        c26_b_b = c26_b_x2;
        c26_f2s = muDoubleScalarHypot(c26_f_a, c26_b_b);
        c26_n_x = c26_g2;
        c26_g2s = c26_n_x;
        if (c26_g2s < 0.0) {
          c26_c_eml_error(chartInstance);
        }

        c26_g2s = muDoubleScalarSqrt(c26_g2s);
        *c26_cs = c26_f2s / c26_g2s;
        c26_o_x = c26_f.re;
        c26_p_x = c26_o_x;
        c26_j_y = muDoubleScalarAbs(c26_p_x);
        c26_q_x = c26_f.im;
        c26_r_x = c26_q_x;
        c26_k_y = muDoubleScalarAbs(c26_r_x);
        c26_s_x = c26_j_y;
        c26_l_y = c26_k_y;
        c26_m_y = c26_s_x;
        if (c26_l_y > c26_m_y) {
          c26_m_y = c26_l_y;
        }

        if (c26_m_y > 1.0) {
          c26_c_x1 = c26_f.re;
          c26_c_x2 = c26_f.im;
          c26_g_a = c26_c_x1;
          c26_c_b = c26_c_x2;
          c26_d = muDoubleScalarHypot(c26_g_a, c26_c_b);
          c26_fs.re = c26_f.re / c26_d;
          c26_fs.im = c26_f.im / c26_d;
        } else {
          c26_dr = 7.4428285367870146E+137 * c26_f.re;
          c26_di = 7.4428285367870146E+137 * c26_f.im;
          c26_d_x1 = c26_dr;
          c26_d_x2 = c26_di;
          c26_h_a = c26_d_x1;
          c26_d_b = c26_d_x2;
          c26_d = muDoubleScalarHypot(c26_h_a, c26_d_b);
          c26_fs.re = c26_dr / c26_d;
          c26_fs.im = c26_di / c26_d;
        }

        c26_b_gs.re = c26_gs.re / c26_g2s;
        c26_b_gs.im = -c26_gs.im / c26_g2s;
        c26_sn->re = c26_fs.re * c26_b_gs.re - c26_fs.im * c26_b_gs.im;
        c26_sn->im = c26_fs.re * c26_b_gs.im + c26_fs.im * c26_b_gs.re;
      }
    } else {
      c26_t_x = 1.0 + c26_g2 / c26_f2;
      c26_f2s = c26_t_x;
      if (c26_f2s < 0.0) {
        c26_c_eml_error(chartInstance);
      }

      c26_f2s = muDoubleScalarSqrt(c26_f2s);
      c26_b_fs = c26_fs;
      c26_c_fs = c26_fs;
      c26_fs.re = c26_f2s * c26_b_fs.re;
      c26_fs.im = c26_f2s * c26_c_fs.im;
      *c26_cs = 1.0 / c26_f2s;
      c26_d = c26_f2 + c26_g2;
      c26_sn->re = c26_fs.re / c26_d;
      c26_sn->im = c26_fs.im / c26_d;
      c26_c_gs.re = c26_gs.re;
      c26_c_gs.im = -c26_gs.im;
      c26_b_sn = *c26_sn;
      c26_sn->re = c26_b_sn.re * c26_c_gs.re - c26_b_sn.im * c26_c_gs.im;
      c26_sn->im = c26_b_sn.re * c26_c_gs.im + c26_b_sn.im * c26_c_gs.re;
      if (c26_rescaledir > 0.0) {
        c26_b_count = c26_count;
        c26_e_b = c26_b_count;
        c26_f_b = c26_e_b;
        if (1 > c26_f_b) {
          c26_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_overflow = (c26_f_b > 2147483646);
        }

        if (c26_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_overflow);
        }
      } else {
        if (c26_rescaledir < 0.0) {
          c26_c_count = c26_count;
          c26_g_b = c26_c_count;
          c26_h_b = c26_g_b;
          if (1 > c26_h_b) {
            c26_b_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_b_overflow = (c26_h_b > 2147483646);
          }

          if (c26_b_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
          }
        }
      }
    }
  }
}

static void c26_eml_warning(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c26_i188;
  static char_T c26_varargin_1[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e',
    'i', 'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c',
    'e' };

  char_T c26_u[24];
  const mxArray *c26_y = NULL;
  (void)chartInstance;
  for (c26_i188 = 0; c26_i188 < 24; c26_i188++) {
    c26_u[c26_i188] = c26_varargin_1[c26_i188];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c26_y));
}

static boolean_T c26_eml_relop(SFc26_hybridSysSimInstanceStruct *chartInstance,
  creal_T c26_a, creal_T c26_b)
{
  real_T c26_RMAXA;
  real_T c26_RMAXB;
  real_T c26_d9;
  real_T c26_d10;
  real_T c26_d11;
  real_T c26_d12;
  real_T c26_A;
  real_T c26_y;
  real_T c26_b_A;
  real_T c26_b_y;
  real_T c26_x;
  real_T c26_c_A;
  real_T c26_c_y;
  real_T c26_d_A;
  real_T c26_d_y;
  real_T c26_e_y;
  real_T c26_b_a;
  real_T c26_b_b;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_f_y;
  real_T c26_e_A;
  real_T c26_g_y;
  real_T c26_d_x;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_absxk;
  real_T c26_r;
  int32_T c26_exponent;
  int32_T c26_b_exponent;
  int32_T c26_c_exponent;
  real_T c26_g_x;
  boolean_T c26_c_b;
  real_T c26_h_x;
  boolean_T c26_d_b;
  boolean_T c26_b23;
  boolean_T c26_b_p;
  real_T c26_ar;
  real_T c26_absar;
  real_T c26_ai;
  real_T c26_absai;
  real_T c26_br;
  real_T c26_absbr;
  real_T c26_bi;
  real_T c26_absbi;
  real_T c26_Ma;
  real_T c26_ma;
  real_T c26_Mb;
  real_T c26_mb;
  real_T c26_f_A;
  real_T c26_h_y;
  real_T c26_g_A;
  real_T c26_i_y;
  real_T c26_Mbar;
  real_T c26_h_A;
  real_T c26_j_y;
  real_T c26_i_A;
  real_T c26_k_y;
  real_T c26_mbar;
  real_T c26_j_A;
  real_T c26_B;
  real_T c26_l_y;
  real_T c26_k_A;
  real_T c26_m_y;
  real_T c26_l_A;
  real_T c26_n_y;
  real_T c26_m_A;
  real_T c26_o_y;
  real_T c26_n_A;
  real_T c26_p_y;
  real_T c26_o_A;
  real_T c26_b_B;
  real_T c26_q_y;
  real_T c26_c_a;
  real_T c26_e_b;
  real_T c26_i_x;
  real_T c26_j_x;
  real_T c26_r_y;
  real_T c26_p_A;
  real_T c26_s_y;
  real_T c26_k_x;
  real_T c26_l_x;
  real_T c26_m_x;
  real_T c26_b_absxk;
  real_T c26_b_r;
  int32_T c26_d_exponent;
  int32_T c26_e_exponent;
  int32_T c26_f_exponent;
  real_T c26_n_x;
  boolean_T c26_f_b;
  real_T c26_o_x;
  boolean_T c26_g_b;
  boolean_T c26_b24;
  boolean_T c26_c_p;
  real_T c26_d_a;
  real_T c26_h_b;
  real_T c26_p_x;
  real_T c26_q_x;
  real_T c26_t_y;
  real_T c26_q_A;
  real_T c26_u_y;
  real_T c26_r_x;
  real_T c26_s_x;
  real_T c26_t_x;
  real_T c26_c_absxk;
  real_T c26_c_r;
  int32_T c26_g_exponent;
  int32_T c26_h_exponent;
  int32_T c26_i_exponent;
  real_T c26_u_x;
  boolean_T c26_i_b;
  real_T c26_v_x;
  boolean_T c26_j_b;
  boolean_T c26_b25;
  boolean_T c26_d_p;
  real_T c26_v_y;
  real_T c26_w_y;
  real_T c26_x_y;
  real_T c26_y_y;
  real_T c26_e_a;
  real_T c26_k_b;
  real_T c26_w_x;
  real_T c26_x_x;
  real_T c26_ab_y;
  real_T c26_r_A;
  real_T c26_bb_y;
  real_T c26_y_x;
  real_T c26_ab_x;
  real_T c26_bb_x;
  real_T c26_d_absxk;
  real_T c26_d_r;
  int32_T c26_j_exponent;
  int32_T c26_k_exponent;
  int32_T c26_l_exponent;
  real_T c26_cb_x;
  boolean_T c26_l_b;
  real_T c26_db_x;
  boolean_T c26_m_b;
  boolean_T c26_b26;
  boolean_T c26_e_p;
  real_T c26_eb_x;
  real_T c26_cb_y;
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
  c26_realmax(chartInstance);
  c26_RMAXA = c26_rdivide(chartInstance, 1.7976931348623157E+308, 2.0);
  c26_realmax(chartInstance);
  c26_RMAXB = c26_rdivide(chartInstance, 1.7976931348623157E+308, 2.0);
  c26_d9 = c26_abs(chartInstance, c26_a.re);
  guard13 = false;
  guard14 = false;
  guard15 = false;
  if (c26_d9 > c26_RMAXA) {
    guard15 = true;
  } else {
    c26_d10 = c26_abs(chartInstance, c26_a.im);
    if (c26_d10 > c26_RMAXA) {
      guard15 = true;
    } else {
      c26_d11 = c26_abs(chartInstance, c26_b.re);
      if (c26_d11 > c26_RMAXB) {
        guard14 = true;
      } else {
        c26_d12 = c26_abs(chartInstance, c26_b.im);
        if (c26_d12 > c26_RMAXB) {
          guard13 = true;
        } else {
          c26_x = c26_b_abs(chartInstance, c26_a);
          c26_e_y = c26_b_abs(chartInstance, c26_b);
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
    c26_A = c26_a.re;
    c26_y = c26_rdivide(chartInstance, c26_A, 2.0);
    c26_b_A = c26_a.im;
    c26_b_y = c26_rdivide(chartInstance, c26_b_A, 2.0);
    c26_x = c26_hypot(chartInstance, c26_y, c26_b_y);
    c26_c_A = c26_b.re;
    c26_c_y = c26_rdivide(chartInstance, c26_c_A, 2.0);
    c26_d_A = c26_b.im;
    c26_d_y = c26_rdivide(chartInstance, c26_d_A, 2.0);
    c26_e_y = c26_hypot(chartInstance, c26_c_y, c26_d_y);
  }

  c26_b_a = c26_x;
  c26_b_b = c26_e_y;
  c26_b_x = c26_b_b - c26_b_a;
  c26_c_x = c26_b_x;
  c26_f_y = muDoubleScalarAbs(c26_c_x);
  c26_e_A = c26_b_b;
  c26_g_y = c26_rdivide(chartInstance, c26_e_A, 2.0);
  c26_d_x = c26_g_y;
  c26_eml_realmin(chartInstance);
  c26_e_x = c26_d_x;
  c26_f_x = c26_e_x;
  c26_absxk = muDoubleScalarAbs(c26_f_x);
  if (c26_isfinite(chartInstance, c26_absxk)) {
    if (c26_absxk <= 2.2250738585072014E-308) {
      c26_r = 4.94065645841247E-324;
    } else {
      frexp(c26_absxk, &c26_exponent);
      c26_b_exponent = c26_exponent;
      c26_c_exponent = c26_b_exponent;
      c26_c_exponent;
      c26_r = ldexp(1.0, c26_c_exponent - 53);
    }
  } else {
    c26_r = rtNaN;
  }

  guard10 = false;
  guard11 = false;
  guard12 = false;
  if (c26_f_y < c26_r) {
    guard11 = true;
  } else {
    c26_g_x = c26_b_a;
    c26_c_b = muDoubleScalarIsInf(c26_g_x);
    if (c26_c_b) {
      c26_h_x = c26_b_b;
      c26_d_b = muDoubleScalarIsInf(c26_h_x);
      if (c26_d_b) {
        if (c26_b_a > 0.0 == c26_b_b > 0.0) {
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
    c26_b23 = true;
  }

  if (guard10 == true) {
    c26_b23 = false;
  }

  c26_b_p = c26_b23;
  if (c26_b_p) {
    c26_ar = c26_a.re;
    c26_absar = c26_abs(chartInstance, c26_ar);
    c26_ai = c26_a.im;
    c26_absai = c26_abs(chartInstance, c26_ai);
    c26_br = c26_b.re;
    c26_absbr = c26_abs(chartInstance, c26_br);
    c26_bi = c26_b.im;
    c26_absbi = c26_abs(chartInstance, c26_bi);
    if (c26_absar > c26_absai) {
      c26_Ma = c26_absar;
      c26_ma = c26_absai;
    } else {
      c26_Ma = c26_absai;
      c26_ma = c26_absar;
    }

    if (c26_absbr > c26_absbi) {
      c26_Mb = c26_absbr;
      c26_mb = c26_absbi;
    } else {
      c26_Mb = c26_absbi;
      c26_mb = c26_absbr;
    }

    if (c26_Ma > c26_Mb) {
      if (c26_ma < c26_mb) {
        c26_x = c26_Ma - c26_Mb;
        c26_f_A = c26_Ma;
        c26_h_y = c26_rdivide(chartInstance, c26_f_A, 2.0);
        c26_g_A = c26_Mb;
        c26_i_y = c26_rdivide(chartInstance, c26_g_A, 2.0);
        c26_Mbar = c26_h_y + c26_i_y;
        c26_h_A = c26_ma;
        c26_j_y = c26_rdivide(chartInstance, c26_h_A, 2.0);
        c26_i_A = c26_mb;
        c26_k_y = c26_rdivide(chartInstance, c26_i_A, 2.0);
        c26_mbar = c26_j_y + c26_k_y;
        c26_j_A = c26_mbar;
        c26_B = c26_Mbar;
        c26_l_y = c26_rdivide(chartInstance, c26_j_A, c26_B);
        c26_e_y = c26_l_y * (c26_mb - c26_ma);
      } else {
        c26_x = c26_Ma;
        c26_e_y = c26_Mb;
      }
    } else if (c26_Ma < c26_Mb) {
      if (c26_ma > c26_mb) {
        c26_e_y = c26_Mb - c26_Ma;
        c26_k_A = c26_Ma;
        c26_m_y = c26_rdivide(chartInstance, c26_k_A, 2.0);
        c26_l_A = c26_Mb;
        c26_n_y = c26_rdivide(chartInstance, c26_l_A, 2.0);
        c26_Mbar = c26_m_y + c26_n_y;
        c26_m_A = c26_ma;
        c26_o_y = c26_rdivide(chartInstance, c26_m_A, 2.0);
        c26_n_A = c26_mb;
        c26_p_y = c26_rdivide(chartInstance, c26_n_A, 2.0);
        c26_mbar = c26_o_y + c26_p_y;
        c26_o_A = c26_mbar;
        c26_b_B = c26_Mbar;
        c26_q_y = c26_rdivide(chartInstance, c26_o_A, c26_b_B);
        c26_x = c26_q_y * (c26_ma - c26_mb);
      } else {
        c26_x = c26_Ma;
        c26_e_y = c26_Mb;
      }
    } else {
      c26_x = c26_ma;
      c26_e_y = c26_mb;
    }

    c26_c_a = c26_x;
    c26_e_b = c26_e_y;
    c26_i_x = c26_e_b - c26_c_a;
    c26_j_x = c26_i_x;
    c26_r_y = muDoubleScalarAbs(c26_j_x);
    c26_p_A = c26_e_b;
    c26_s_y = c26_rdivide(chartInstance, c26_p_A, 2.0);
    c26_k_x = c26_s_y;
    c26_eml_realmin(chartInstance);
    c26_l_x = c26_k_x;
    c26_m_x = c26_l_x;
    c26_b_absxk = muDoubleScalarAbs(c26_m_x);
    if (c26_isfinite(chartInstance, c26_b_absxk)) {
      if (c26_b_absxk <= 2.2250738585072014E-308) {
        c26_b_r = 4.94065645841247E-324;
      } else {
        frexp(c26_b_absxk, &c26_d_exponent);
        c26_e_exponent = c26_d_exponent;
        c26_f_exponent = c26_e_exponent;
        c26_f_exponent;
        c26_b_r = ldexp(1.0, c26_f_exponent - 53);
      }
    } else {
      c26_b_r = rtNaN;
    }

    guard7 = false;
    guard8 = false;
    guard9 = false;
    if (c26_r_y < c26_b_r) {
      guard8 = true;
    } else {
      c26_n_x = c26_c_a;
      c26_f_b = muDoubleScalarIsInf(c26_n_x);
      if (c26_f_b) {
        c26_o_x = c26_e_b;
        c26_g_b = muDoubleScalarIsInf(c26_o_x);
        if (c26_g_b) {
          if (c26_c_a > 0.0 == c26_e_b > 0.0) {
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
      c26_b24 = true;
    }

    if (guard7 == true) {
      c26_b24 = false;
    }

    c26_c_p = c26_b24;
    if (c26_c_p) {
      c26_x = c26_angle(chartInstance, c26_a);
      c26_e_y = c26_angle(chartInstance, c26_b);
      c26_d_a = c26_x;
      c26_h_b = c26_e_y;
      c26_p_x = c26_h_b - c26_d_a;
      c26_q_x = c26_p_x;
      c26_t_y = muDoubleScalarAbs(c26_q_x);
      c26_q_A = c26_h_b;
      c26_u_y = c26_rdivide(chartInstance, c26_q_A, 2.0);
      c26_r_x = c26_u_y;
      c26_eml_realmin(chartInstance);
      c26_s_x = c26_r_x;
      c26_t_x = c26_s_x;
      c26_c_absxk = muDoubleScalarAbs(c26_t_x);
      if (c26_isfinite(chartInstance, c26_c_absxk)) {
        if (c26_c_absxk <= 2.2250738585072014E-308) {
          c26_c_r = 4.94065645841247E-324;
        } else {
          frexp(c26_c_absxk, &c26_g_exponent);
          c26_h_exponent = c26_g_exponent;
          c26_i_exponent = c26_h_exponent;
          c26_i_exponent;
          c26_c_r = ldexp(1.0, c26_i_exponent - 53);
        }
      } else {
        c26_c_r = rtNaN;
      }

      guard4 = false;
      guard5 = false;
      guard6 = false;
      if (c26_t_y < c26_c_r) {
        guard5 = true;
      } else {
        c26_u_x = c26_d_a;
        c26_i_b = muDoubleScalarIsInf(c26_u_x);
        if (c26_i_b) {
          c26_v_x = c26_h_b;
          c26_j_b = muDoubleScalarIsInf(c26_v_x);
          if (c26_j_b) {
            if (c26_d_a > 0.0 == c26_h_b > 0.0) {
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
        c26_b25 = true;
      }

      if (guard4 == true) {
        c26_b25 = false;
      }

      c26_d_p = c26_b25;
      if (c26_d_p) {
        c26_v_y = c26_rdivide(chartInstance, 3.1415926535897931, 4.0);
        if (c26_x > c26_v_y) {
          c26_w_y = c26_rdivide(chartInstance, 9.42477796076938, 4.0);
          if (c26_x > c26_w_y) {
            c26_x = -c26_ai;
            c26_e_y = -c26_bi;
          } else {
            c26_x = -c26_ar;
            c26_e_y = -c26_br;
          }
        } else {
          c26_x_y = c26_rdivide(chartInstance, -3.1415926535897931, 4.0);
          if (c26_x > c26_x_y) {
            c26_x = c26_ai;
            c26_e_y = c26_bi;
          } else {
            c26_y_y = c26_rdivide(chartInstance, -9.42477796076938, 4.0);
            if (c26_x > c26_y_y) {
              c26_x = c26_ar;
              c26_e_y = c26_br;
            } else {
              c26_x = -c26_ai;
              c26_e_y = -c26_bi;
            }
          }
        }

        c26_e_a = c26_x;
        c26_k_b = c26_e_y;
        c26_w_x = c26_k_b - c26_e_a;
        c26_x_x = c26_w_x;
        c26_ab_y = muDoubleScalarAbs(c26_x_x);
        c26_r_A = c26_k_b;
        c26_bb_y = c26_rdivide(chartInstance, c26_r_A, 2.0);
        c26_y_x = c26_bb_y;
        c26_eml_realmin(chartInstance);
        c26_ab_x = c26_y_x;
        c26_bb_x = c26_ab_x;
        c26_d_absxk = muDoubleScalarAbs(c26_bb_x);
        if (c26_isfinite(chartInstance, c26_d_absxk)) {
          if (c26_d_absxk <= 2.2250738585072014E-308) {
            c26_d_r = 4.94065645841247E-324;
          } else {
            frexp(c26_d_absxk, &c26_j_exponent);
            c26_k_exponent = c26_j_exponent;
            c26_l_exponent = c26_k_exponent;
            c26_l_exponent;
            c26_d_r = ldexp(1.0, c26_l_exponent - 53);
          }
        } else {
          c26_d_r = rtNaN;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (c26_ab_y < c26_d_r) {
          guard2 = true;
        } else {
          c26_cb_x = c26_e_a;
          c26_l_b = muDoubleScalarIsInf(c26_cb_x);
          if (c26_l_b) {
            c26_db_x = c26_k_b;
            c26_m_b = muDoubleScalarIsInf(c26_db_x);
            if (c26_m_b) {
              if (c26_e_a > 0.0 == c26_k_b > 0.0) {
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
          c26_b26 = true;
        }

        if (guard1 == true) {
          c26_b26 = false;
        }

        c26_e_p = c26_b26;
        if (c26_e_p) {
          c26_x = 0.0;
          c26_e_y = 0.0;
        }
      }
    }
  }

  c26_eb_x = c26_x;
  c26_cb_y = c26_e_y;
  return c26_eb_x < c26_cb_y;
}

static real_T c26_hypot(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x, real_T c26_y)
{
  real_T c26_b_x;
  real_T c26_b_y;
  real_T c26_x1;
  real_T c26_x2;
  real_T c26_a;
  real_T c26_b;
  c26_eml_scalar_eg(chartInstance);
  c26_b_x = c26_x;
  c26_b_y = c26_y;
  c26_eml_scalar_eg(chartInstance);
  c26_x1 = c26_b_x;
  c26_x2 = c26_b_y;
  c26_a = c26_x1;
  c26_b = c26_x2;
  return muDoubleScalarHypot(c26_a, c26_b);
}

static real_T c26_angle(SFc26_hybridSysSimInstanceStruct *chartInstance, creal_T
  c26_x)
{
  real_T c26_b_y;
  real_T c26_b_x;
  (void)chartInstance;
  c26_b_y = c26_x.im;
  c26_b_x = c26_x.re;
  return muDoubleScalarAtan2(c26_b_y, c26_b_x);
}

static void c26_inv(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
                    c26_x[4], real_T c26_y[4])
{
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_d_x;
  real_T c26_e_x;
  real_T c26_b_y;
  real_T c26_f_x;
  real_T c26_g_x;
  real_T c26_c_y;
  real_T c26_d;
  real_T c26_h_x;
  real_T c26_i_x;
  real_T c26_j_x;
  real_T c26_k_x;
  real_T c26_d_y;
  real_T c26_l_x;
  real_T c26_m_x;
  real_T c26_e_y;
  real_T c26_b_d;
  real_T c26_A;
  real_T c26_B;
  real_T c26_r;
  real_T c26_b_B;
  real_T c26_t;
  real_T c26_b_A;
  real_T c26_c_B;
  real_T c26_f_y;
  real_T c26_c_A;
  real_T c26_d_B;
  real_T c26_g_y;
  real_T c26_d_A;
  real_T c26_e_B;
  real_T c26_f_B;
  real_T c26_e_A;
  real_T c26_g_B;
  real_T c26_h_y;
  real_T c26_f_A;
  real_T c26_h_B;
  real_T c26_i_y;
  int32_T c26_i189;
  real_T c26_n_x[4];
  real_T c26_n1x;
  int32_T c26_i190;
  real_T c26_j_y[4];
  real_T c26_n1xinv;
  real_T c26_rc;
  real_T c26_o_x;
  boolean_T c26_b;
  real_T c26_p_x;
  int32_T c26_i191;
  static char_T c26_cv6[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c26_u[8];
  const mxArray *c26_k_y = NULL;
  real_T c26_b_u;
  const mxArray *c26_l_y = NULL;
  real_T c26_c_u;
  const mxArray *c26_m_y = NULL;
  real_T c26_d_u;
  const mxArray *c26_n_y = NULL;
  char_T c26_str[14];
  int32_T c26_i192;
  char_T c26_b_str[14];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c26_b_x = c26_x[1];
  c26_c_x = c26_b_x;
  c26_d_x = c26_c_x;
  c26_e_x = c26_d_x;
  c26_b_y = muDoubleScalarAbs(c26_e_x);
  c26_f_x = 0.0;
  c26_g_x = c26_f_x;
  c26_c_y = muDoubleScalarAbs(c26_g_x);
  c26_d = c26_b_y + c26_c_y;
  c26_h_x = c26_x[0];
  c26_i_x = c26_h_x;
  c26_j_x = c26_i_x;
  c26_k_x = c26_j_x;
  c26_d_y = muDoubleScalarAbs(c26_k_x);
  c26_l_x = 0.0;
  c26_m_x = c26_l_x;
  c26_e_y = muDoubleScalarAbs(c26_m_x);
  c26_b_d = c26_d_y + c26_e_y;
  if (c26_d > c26_b_d) {
    c26_A = c26_x[0];
    c26_B = c26_x[1];
    c26_r = c26_rdivide(chartInstance, c26_A, c26_B);
    c26_b_B = c26_r * c26_x[3] - c26_x[2];
    c26_t = c26_rdivide(chartInstance, 1.0, c26_b_B);
    c26_b_A = c26_x[3];
    c26_c_B = c26_x[1];
    c26_f_y = c26_rdivide(chartInstance, c26_b_A, c26_c_B);
    c26_y[0] = c26_f_y * c26_t;
    c26_y[1] = -c26_t;
    c26_c_A = -c26_x[2];
    c26_d_B = c26_x[1];
    c26_g_y = c26_rdivide(chartInstance, c26_c_A, c26_d_B);
    c26_y[2] = c26_g_y * c26_t;
    c26_y[3] = c26_r * c26_t;
  } else {
    c26_d_A = c26_x[1];
    c26_e_B = c26_x[0];
    c26_r = c26_rdivide(chartInstance, c26_d_A, c26_e_B);
    c26_f_B = c26_x[3] - c26_r * c26_x[2];
    c26_t = c26_rdivide(chartInstance, 1.0, c26_f_B);
    c26_e_A = c26_x[3];
    c26_g_B = c26_x[0];
    c26_h_y = c26_rdivide(chartInstance, c26_e_A, c26_g_B);
    c26_y[0] = c26_h_y * c26_t;
    c26_y[1] = -c26_r * c26_t;
    c26_f_A = -c26_x[2];
    c26_h_B = c26_x[0];
    c26_i_y = c26_rdivide(chartInstance, c26_f_A, c26_h_B);
    c26_y[2] = c26_i_y * c26_t;
    c26_y[3] = c26_t;
  }

  for (c26_i189 = 0; c26_i189 < 4; c26_i189++) {
    c26_n_x[c26_i189] = c26_x[c26_i189];
  }

  c26_n1x = c26_c_norm(chartInstance, c26_n_x);
  for (c26_i190 = 0; c26_i190 < 4; c26_i190++) {
    c26_j_y[c26_i190] = c26_y[c26_i190];
  }

  c26_n1xinv = c26_c_norm(chartInstance, c26_j_y);
  c26_rc = 1.0 / (c26_n1x * c26_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c26_n1x == 0.0) {
    guard2 = true;
  } else if (c26_n1xinv == 0.0) {
    guard2 = true;
  } else if (c26_rc == 0.0) {
    guard1 = true;
  } else {
    c26_o_x = c26_rc;
    c26_b = muDoubleScalarIsNaN(c26_o_x);
    guard3 = false;
    if (c26_b) {
      guard3 = true;
    } else {
      c26_eps(chartInstance);
      if (c26_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c26_p_x = c26_rc;
      for (c26_i191 = 0; c26_i191 < 8; c26_i191++) {
        c26_u[c26_i191] = c26_cv6[c26_i191];
      }

      c26_k_y = NULL;
      sf_mex_assign(&c26_k_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    false);
      c26_b_u = 14.0;
      c26_l_y = NULL;
      sf_mex_assign(&c26_l_y, sf_mex_create("y", &c26_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c26_c_u = 6.0;
      c26_m_y = NULL;
      sf_mex_assign(&c26_m_y, sf_mex_create("y", &c26_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c26_d_u = c26_p_x;
      c26_n_y = NULL;
      sf_mex_assign(&c26_n_y, sf_mex_create("y", &c26_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      c26_i_emlrt_marshallIn(chartInstance, sf_mex_call_debug
        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14, sf_mex_call_debug
         (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14, c26_k_y, 14,
          c26_l_y, 14, c26_m_y), 14, c26_n_y), "sprintf", c26_str);
      for (c26_i192 = 0; c26_i192 < 14; c26_i192++) {
        c26_b_str[c26_i192] = c26_str[c26_i192];
      }

      c26_c_eml_warning(chartInstance, c26_b_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c26_b_eml_warning(chartInstance);
  }
}

static real_T c26_c_norm(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_x[4])
{
  real_T c26_y;
  int32_T c26_j;
  real_T c26_b_j;
  real_T c26_s;
  int32_T c26_i;
  real_T c26_b_i;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_b_y;
  real_T c26_d_x;
  boolean_T c26_b;
  boolean_T exitg1;
  (void)chartInstance;
  c26_y = 0.0;
  c26_j = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c26_j < 2)) {
    c26_b_j = 1.0 + (real_T)c26_j;
    c26_s = 0.0;
    for (c26_i = 0; c26_i < 2; c26_i++) {
      c26_b_i = 1.0 + (real_T)c26_i;
      c26_b_x = c26_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c26_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c26_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c26_c_x = c26_b_x;
      c26_b_y = muDoubleScalarAbs(c26_c_x);
      c26_s += c26_b_y;
    }

    c26_d_x = c26_s;
    c26_b = muDoubleScalarIsNaN(c26_d_x);
    if (c26_b) {
      c26_y = rtNaN;
      exitg1 = true;
    } else {
      if (c26_s > c26_y) {
        c26_y = c26_s;
      }

      c26_j++;
    }
  }

  return c26_y;
}

static void c26_b_eml_warning(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c26_i193;
  static char_T c26_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c26_u[27];
  const mxArray *c26_y = NULL;
  (void)chartInstance;
  for (c26_i193 = 0; c26_i193 < 27; c26_i193++) {
    c26_u[c26_i193] = c26_varargin_1[c26_i193];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c26_y));
}

static void c26_c_eml_warning(SFc26_hybridSysSimInstanceStruct *chartInstance,
  char_T c26_varargin_2[14])
{
  int32_T c26_i194;
  static char_T c26_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c26_u[33];
  const mxArray *c26_y = NULL;
  int32_T c26_i195;
  char_T c26_b_u[14];
  const mxArray *c26_b_y = NULL;
  (void)chartInstance;
  for (c26_i194 = 0; c26_i194 < 33; c26_i194++) {
    c26_u[c26_i194] = c26_varargin_1[c26_i194];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  for (c26_i195 = 0; c26_i195 < 14; c26_i195++) {
    c26_b_u[c26_i195] = c26_varargin_2[c26_i195];
  }

  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", c26_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c26_y, 14, c26_b_y));
}

static void c26_b_eig(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
                      c26_A[100], creal_T c26_V[10])
{
  int32_T c26_i196;
  static creal_T c26_dc16 = { 0.0, 0.0 };

  creal_T c26_b_A[100];
  int32_T c26_info;
  int32_T c26_i197;
  creal_T c26_c_A[100];
  real_T c26_anrm;
  int32_T c26_i198;
  int32_T c26_i199;
  creal_T c26_beta1[10];
  boolean_T c26_ilascl;
  real_T c26_anrmto;
  real_T c26_cfrom;
  real_T c26_cto;
  real_T c26_cfromc;
  real_T c26_ctoc;
  boolean_T c26_notdone;
  real_T c26_cfrom1;
  real_T c26_cto1;
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_y;
  real_T c26_c_x;
  real_T c26_d_x;
  real_T c26_b_y;
  real_T c26_mul;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_c_y;
  real_T c26_g_x;
  real_T c26_h_x;
  real_T c26_d_y;
  real_T c26_a;
  int32_T c26_i200;
  int32_T c26_rscale[10];
  int32_T c26_ihi;
  int32_T c26_ilo;
  int32_T c26_b_ilo;
  int32_T c26_b_ihi;
  int32_T c26_i201;
  creal_T c26_d_A[100];
  int32_T c26_b_info;
  real_T c26_b_cfrom;
  real_T c26_b_cto;
  real_T c26_b_cfromc;
  real_T c26_b_ctoc;
  boolean_T c26_b_notdone;
  real_T c26_b_cfrom1;
  real_T c26_b_cto1;
  real_T c26_i_x;
  real_T c26_j_x;
  real_T c26_e_y;
  real_T c26_k_x;
  real_T c26_l_x;
  real_T c26_f_y;
  real_T c26_b_mul;
  real_T c26_m_x;
  real_T c26_n_x;
  real_T c26_g_y;
  real_T c26_o_x;
  real_T c26_p_x;
  real_T c26_h_y;
  real_T c26_b_a;
  int32_T c26_i202;
  int32_T c26_c_info;
  int32_T c26_d_info;
  int32_T c26_e_info;
  int32_T c26_i203;
  creal_T c26_b_V;
  real_T c26_ar;
  real_T c26_ai;
  real_T c26_br;
  real_T c26_bi;
  real_T c26_brm;
  real_T c26_bim;
  real_T c26_s;
  real_T c26_d;
  real_T c26_nr;
  real_T c26_ni;
  real_T c26_sgnbr;
  real_T c26_sgnbi;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  c26_assert(chartInstance);
  c26_b_assert(chartInstance);
  c26_c_assert(chartInstance);
  c26_parseopts(chartInstance);
  c26_c_eml_scalar_eg(chartInstance);
  for (c26_i196 = 0; c26_i196 < 100; c26_i196++) {
    c26_b_A[c26_i196].re = c26_A[c26_i196] + c26_dc16.re;
    c26_b_A[c26_i196].im = c26_dc16.im;
  }

  c26_info = 0;
  c26_eml_realmin(chartInstance);
  c26_eps(chartInstance);
  for (c26_i197 = 0; c26_i197 < 100; c26_i197++) {
    c26_c_A[c26_i197] = c26_b_A[c26_i197];
  }

  c26_anrm = c26_b_eml_matlab_zlangeM(chartInstance, c26_c_A);
  if (!c26_isfinite(chartInstance, c26_anrm)) {
    for (c26_i198 = 0; c26_i198 < 10; c26_i198++) {
      c26_V[c26_i198].re = rtNaN;
      c26_V[c26_i198].im = 0.0;
    }

    for (c26_i199 = 0; c26_i199 < 10; c26_i199++) {
      c26_beta1[c26_i199].re = rtNaN;
      c26_beta1[c26_i199].im = 0.0;
    }
  } else {
    c26_ilascl = false;
    c26_anrmto = c26_anrm;
    guard3 = false;
    if (c26_anrm > 0.0) {
      if (c26_anrm < 6.7178761075670888E-139) {
        c26_anrmto = 6.7178761075670888E-139;
        c26_ilascl = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      if (c26_anrm > 1.4885657073574029E+138) {
        c26_anrmto = 1.4885657073574029E+138;
        c26_ilascl = true;
      }
    }

    if (c26_ilascl) {
      c26_cfrom = c26_anrm;
      c26_cto = c26_anrmto;
      c26_eml_realmin(chartInstance);
      c26_eps(chartInstance);
      c26_cfromc = c26_cfrom;
      c26_ctoc = c26_cto;
      c26_notdone = true;
      while (c26_notdone) {
        c26_cfrom1 = c26_cfromc * 2.0041683600089728E-292;
        c26_cto1 = c26_ctoc / 4.9896007738368E+291;
        c26_x = c26_cfrom1;
        c26_b_x = c26_x;
        c26_y = muDoubleScalarAbs(c26_b_x);
        c26_c_x = c26_ctoc;
        c26_d_x = c26_c_x;
        c26_b_y = muDoubleScalarAbs(c26_d_x);
        guard2 = false;
        if (c26_y > c26_b_y) {
          if (c26_ctoc != 0.0) {
            c26_mul = 2.0041683600089728E-292;
            c26_notdone = true;
            c26_cfromc = c26_cfrom1;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2 == true) {
          c26_e_x = c26_cto1;
          c26_f_x = c26_e_x;
          c26_c_y = muDoubleScalarAbs(c26_f_x);
          c26_g_x = c26_cfromc;
          c26_h_x = c26_g_x;
          c26_d_y = muDoubleScalarAbs(c26_h_x);
          if (c26_c_y > c26_d_y) {
            c26_mul = 4.9896007738368E+291;
            c26_notdone = true;
            c26_ctoc = c26_cto1;
          } else {
            c26_mul = c26_ctoc / c26_cfromc;
            c26_notdone = false;
          }
        }

        c26_a = c26_mul;
        for (c26_i200 = 0; c26_i200 < 100; c26_i200++) {
          c26_b_A[c26_i200].re *= c26_a;
          c26_b_A[c26_i200].im *= c26_a;
        }
      }
    }

    c26_d_eml_matlab_zggbal(chartInstance, c26_b_A, &c26_ilo, &c26_ihi,
      c26_rscale);
    c26_b_ilo = c26_ilo;
    c26_b_ihi = c26_ihi;
    c26_b_eml_matlab_zgghrd(chartInstance, c26_b_ilo, c26_b_ihi, c26_b_A);
    for (c26_i201 = 0; c26_i201 < 100; c26_i201++) {
      c26_d_A[c26_i201] = c26_b_A[c26_i201];
    }

    c26_b_eml_matlab_zhgeqz(chartInstance, c26_d_A, c26_b_ilo, c26_b_ihi,
      &c26_b_info, c26_V, c26_beta1);
    c26_info = c26_b_info;
    if (c26_info != 0) {
    } else {
      if (c26_ilascl) {
        c26_b_cfrom = c26_anrmto;
        c26_b_cto = c26_anrm;
        c26_eml_realmin(chartInstance);
        c26_eps(chartInstance);
        c26_b_cfromc = c26_b_cfrom;
        c26_b_ctoc = c26_b_cto;
        c26_b_notdone = true;
        while (c26_b_notdone) {
          c26_b_cfrom1 = c26_b_cfromc * 2.0041683600089728E-292;
          c26_b_cto1 = c26_b_ctoc / 4.9896007738368E+291;
          c26_i_x = c26_b_cfrom1;
          c26_j_x = c26_i_x;
          c26_e_y = muDoubleScalarAbs(c26_j_x);
          c26_k_x = c26_b_ctoc;
          c26_l_x = c26_k_x;
          c26_f_y = muDoubleScalarAbs(c26_l_x);
          guard1 = false;
          if (c26_e_y > c26_f_y) {
            if (c26_b_ctoc != 0.0) {
              c26_b_mul = 2.0041683600089728E-292;
              c26_b_notdone = true;
              c26_b_cfromc = c26_b_cfrom1;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1 == true) {
            c26_m_x = c26_b_cto1;
            c26_n_x = c26_m_x;
            c26_g_y = muDoubleScalarAbs(c26_n_x);
            c26_o_x = c26_b_cfromc;
            c26_p_x = c26_o_x;
            c26_h_y = muDoubleScalarAbs(c26_p_x);
            if (c26_g_y > c26_h_y) {
              c26_b_mul = 4.9896007738368E+291;
              c26_b_notdone = true;
              c26_b_ctoc = c26_b_cto1;
            } else {
              c26_b_mul = c26_b_ctoc / c26_b_cfromc;
              c26_b_notdone = false;
            }
          }

          c26_b_a = c26_b_mul;
          for (c26_i202 = 0; c26_i202 < 10; c26_i202++) {
            c26_V[c26_i202].re *= c26_b_a;
            c26_V[c26_i202].im *= c26_b_a;
          }
        }
      }
    }
  }

  c26_c_info = c26_info;
  c26_d_info = c26_c_info;
  c26_e_info = c26_d_info;
  for (c26_i203 = 0; c26_i203 < 10; c26_i203++) {
    c26_b_V = c26_V[c26_i203];
    c26_ar = c26_b_V.re;
    c26_ai = c26_b_V.im;
    c26_br = c26_beta1[c26_i203].re;
    c26_bi = c26_beta1[c26_i203].im;
    if (c26_bi == 0.0) {
      if (c26_ai == 0.0) {
        c26_V[c26_i203].re = c26_ar / c26_br;
        c26_V[c26_i203].im = 0.0;
      } else if (c26_ar == 0.0) {
        c26_V[c26_i203].re = 0.0;
        c26_V[c26_i203].im = c26_ai / c26_br;
      } else {
        c26_V[c26_i203].re = c26_ar / c26_br;
        c26_V[c26_i203].im = c26_ai / c26_br;
      }
    } else if (c26_br == 0.0) {
      if (c26_ar == 0.0) {
        c26_V[c26_i203].re = c26_ai / c26_bi;
        c26_V[c26_i203].im = 0.0;
      } else if (c26_ai == 0.0) {
        c26_V[c26_i203].re = 0.0;
        c26_V[c26_i203].im = -(c26_ar / c26_bi);
      } else {
        c26_V[c26_i203].re = c26_ai / c26_bi;
        c26_V[c26_i203].im = -(c26_ar / c26_bi);
      }
    } else {
      c26_brm = muDoubleScalarAbs(c26_br);
      c26_bim = muDoubleScalarAbs(c26_bi);
      if (c26_brm > c26_bim) {
        c26_s = c26_bi / c26_br;
        c26_d = c26_br + c26_s * c26_bi;
        c26_nr = c26_ar + c26_s * c26_ai;
        c26_ni = c26_ai - c26_s * c26_ar;
        c26_V[c26_i203].re = c26_nr / c26_d;
        c26_V[c26_i203].im = c26_ni / c26_d;
      } else if (c26_bim == c26_brm) {
        if (c26_br > 0.0) {
          c26_sgnbr = 0.5;
        } else {
          c26_sgnbr = -0.5;
        }

        if (c26_bi > 0.0) {
          c26_sgnbi = 0.5;
        } else {
          c26_sgnbi = -0.5;
        }

        c26_nr = c26_ar * c26_sgnbr + c26_ai * c26_sgnbi;
        c26_ni = c26_ai * c26_sgnbr - c26_ar * c26_sgnbi;
        c26_V[c26_i203].re = c26_nr / c26_brm;
        c26_V[c26_i203].im = c26_ni / c26_brm;
      } else {
        c26_s = c26_br / c26_bi;
        c26_d = c26_bi + c26_s * c26_br;
        c26_nr = c26_s * c26_ar + c26_ai;
        c26_ni = c26_s * c26_ai - c26_ar;
        c26_V[c26_i203].re = c26_nr / c26_d;
        c26_V[c26_i203].im = c26_ni / c26_d;
      }
    }
  }

  if (c26_e_info != 0) {
    c26_eml_warning(chartInstance);
  }
}

static void c26_c_eml_scalar_eg(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c26_b_eml_matlab_zlangeM(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_x[100])
{
  real_T c26_y;
  int32_T c26_k;
  real_T c26_b_k;
  creal_T c26_b_x;
  real_T c26_x1;
  real_T c26_x2;
  real_T c26_a;
  real_T c26_b;
  real_T c26_absxk;
  real_T c26_c_x;
  boolean_T c26_b_b;
  boolean_T exitg1;
  (void)chartInstance;
  c26_y = 0.0;
  c26_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c26_k < 100)) {
    c26_b_k = 1.0 + (real_T)c26_k;
    c26_b_x.re = c26_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c26_b_k), 1, 100, 1, 0) - 1].re;
    c26_b_x.im = c26_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c26_b_k), 1, 100, 1, 0) - 1].im;
    c26_x1 = c26_b_x.re;
    c26_x2 = c26_b_x.im;
    c26_a = c26_x1;
    c26_b = c26_x2;
    c26_absxk = muDoubleScalarHypot(c26_a, c26_b);
    c26_c_x = c26_absxk;
    c26_b_b = muDoubleScalarIsNaN(c26_c_x);
    if (c26_b_b) {
      c26_y = rtNaN;
      exitg1 = true;
    } else {
      if (c26_absxk > c26_y) {
        c26_y = c26_absxk;
      }

      c26_k++;
    }
  }

  return c26_y;
}

static void c26_b_eml_matlab_zggbal(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[100], creal_T c26_b_A[100], int32_T *c26_ilo,
  int32_T *c26_ihi, int32_T c26_rscale[10])
{
  int32_T c26_i204;
  for (c26_i204 = 0; c26_i204 < 100; c26_i204++) {
    c26_b_A[c26_i204] = c26_A[c26_i204];
  }

  c26_d_eml_matlab_zggbal(chartInstance, c26_b_A, c26_ilo, c26_ihi, c26_rscale);
}

static void c26_eml_matlab_zgghrd(SFc26_hybridSysSimInstanceStruct
  *chartInstance, int32_T c26_ilo, int32_T c26_ihi, creal_T c26_A[100], creal_T
  c26_b_A[100])
{
  int32_T c26_i205;
  for (c26_i205 = 0; c26_i205 < 100; c26_i205++) {
    c26_b_A[c26_i205] = c26_A[c26_i205];
  }

  c26_b_eml_matlab_zgghrd(chartInstance, c26_ilo, c26_ihi, c26_b_A);
}

static void c26_b_eml_matlab_zhgeqz(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[100], int32_T c26_ilo, int32_T c26_ihi, int32_T *
  c26_info, creal_T c26_alpha1[10], creal_T c26_beta1[10])
{
  static creal_T c26_dc17 = { 0.0, 0.0 };

  int32_T c26_i206;
  creal_T c26_b_A[100];
  int32_T c26_i207;
  int32_T c26_i208;
  static creal_T c26_dc18 = { 0.0, 0.0 };

  creal_T c26_eshift;
  creal_T c26_ctemp;
  creal_T c26_rho;
  int32_T c26_i209;
  creal_T c26_c_A[100];
  real_T c26_anorm;
  real_T c26_y;
  real_T c26_atol;
  real_T c26_b_y;
  real_T c26_x;
  real_T c26_ascale;
  boolean_T c26_failed;
  int32_T c26_a;
  int32_T c26_b_a;
  int32_T c26_i210;
  int32_T c26_c_a;
  int32_T c26_d_a;
  boolean_T c26_overflow;
  int32_T c26_j;
  int32_T c26_b_j;
  int32_T c26_ifirst;
  int32_T c26_istart;
  int32_T c26_ilast;
  int32_T c26_e_a;
  int32_T c26_f_a;
  int32_T c26_ilastm1;
  int32_T c26_ifrstm;
  int32_T c26_ilastm;
  int32_T c26_iiter;
  int32_T c26_g_a;
  int32_T c26_b;
  int32_T c26_h_a;
  int32_T c26_b_b;
  int32_T c26_c;
  int32_T c26_i_a;
  int32_T c26_j_a;
  int32_T c26_b_c;
  int32_T c26_c_b;
  int32_T c26_d_b;
  int32_T c26_maxit;
  boolean_T c26_goto50;
  boolean_T c26_goto60;
  boolean_T c26_goto70;
  boolean_T c26_goto90;
  int32_T c26_b_maxit;
  int32_T c26_e_b;
  int32_T c26_f_b;
  boolean_T c26_b_overflow;
  int32_T c26_jiter;
  creal_T c26_a22;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_c_y;
  real_T c26_d_x;
  real_T c26_e_x;
  real_T c26_d_y;
  real_T c26_e_y;
  int32_T c26_k_a;
  int32_T c26_l_a;
  int32_T c26_jm1;
  boolean_T c26_ilazro;
  real_T c26_f_x;
  real_T c26_g_x;
  real_T c26_f_y;
  real_T c26_h_x;
  real_T c26_i_x;
  real_T c26_g_y;
  real_T c26_h_y;
  boolean_T c26_b27;
  int32_T c26_i211;
  int32_T c26_i212;
  creal_T c26_d_A;
  creal_T c26_e_A;
  creal_T c26_s;
  real_T c26_c_c;
  real_T c26_d_c;
  real_T c26_e_c;
  int32_T c26_xcol;
  int32_T c26_ycol;
  int32_T c26_b_ilo;
  int32_T c26_b_ihi;
  int32_T c26_c_ilo;
  int32_T c26_c_ihi;
  int32_T c26_m_a;
  int32_T c26_g_b;
  int32_T c26_n_a;
  int32_T c26_h_b;
  boolean_T c26_c_overflow;
  int32_T c26_i;
  int32_T c26_b_i;
  real_T c26_o_a;
  creal_T c26_a12;
  creal_T c26_b_s;
  creal_T c26_a21;
  real_T c26_p_a;
  creal_T c26_b_a22;
  creal_T c26_c_a22;
  creal_T c26_d_a22;
  creal_T c26_e_a22;
  int32_T c26_q_a;
  int32_T c26_r_a;
  int32_T c26_s_a;
  int32_T c26_t_a;
  creal_T c26_r2;
  real_T c26_ar;
  real_T c26_ai;
  static creal_T c26_dc19 = { 2.0, 0.0 };

  real_T c26_br;
  real_T c26_bi;
  real_T c26_brm;
  real_T c26_bim;
  real_T c26_c_s;
  real_T c26_d;
  real_T c26_nr;
  real_T c26_ni;
  real_T c26_sgnbr;
  real_T c26_sgnbi;
  creal_T c26_d_s;
  creal_T c26_b_a12;
  creal_T c26_c_a12;
  creal_T c26_b_a21;
  real_T c26_d13;
  real_T c26_d14;
  int32_T c26_u_a;
  int32_T c26_v_a;
  int32_T c26_jp1;
  int32_T c26_w_a;
  int32_T c26_x_a;
  real_T c26_j_x;
  real_T c26_k_x;
  real_T c26_i_y;
  real_T c26_l_x;
  real_T c26_m_x;
  real_T c26_j_y;
  real_T c26_k_y;
  real_T c26_temp;
  real_T c26_n_x;
  real_T c26_o_x;
  real_T c26_l_y;
  real_T c26_p_x;
  real_T c26_q_x;
  real_T c26_m_y;
  real_T c26_n_y;
  real_T c26_temp2;
  real_T c26_r_x;
  real_T c26_o_y;
  real_T c26_tempr;
  real_T c26_s_x;
  real_T c26_t_x;
  real_T c26_p_y;
  real_T c26_u_x;
  real_T c26_v_x;
  real_T c26_q_y;
  real_T c26_r_y;
  int32_T c26_y_a;
  int32_T c26_ab_a;
  int32_T c26_f_c;
  real_T c26_g_c;
  int32_T c26_bb_a;
  int32_T c26_cb_a;
  int32_T c26_db_a;
  int32_T c26_eb_a;
  creal_T c26_f_A;
  creal_T c26_g_A;
  real_T c26_h_c;
  real_T c26_i_c;
  int32_T c26_xrow;
  int32_T c26_yrow;
  int32_T c26_jlo;
  int32_T c26_jhi;
  int32_T c26_b_jlo;
  int32_T c26_b_jhi;
  int32_T c26_fb_a;
  int32_T c26_i_b;
  int32_T c26_gb_a;
  int32_T c26_j_b;
  boolean_T c26_d_overflow;
  int32_T c26_c_j;
  int32_T c26_d_j;
  real_T c26_hb_a;
  creal_T c26_e_s;
  real_T c26_ib_a;
  creal_T c26_f_a22;
  creal_T c26_g_a22;
  creal_T c26_h_a22;
  creal_T c26_i_a22;
  int32_T c26_jb_a;
  int32_T c26_kb_a;
  int32_T c26_j_c;
  int32_T c26_w_x;
  int32_T c26_s_y;
  int32_T c26_x_x;
  real_T c26_k_c;
  int32_T c26_b_xcol;
  int32_T c26_b_ycol;
  int32_T c26_d_ilo;
  int32_T c26_d_ihi;
  int32_T c26_e_ilo;
  int32_T c26_e_ihi;
  int32_T c26_lb_a;
  int32_T c26_k_b;
  int32_T c26_mb_a;
  int32_T c26_l_b;
  boolean_T c26_e_overflow;
  int32_T c26_c_i;
  int32_T c26_d_i;
  real_T c26_nb_a;
  creal_T c26_f_s;
  real_T c26_ob_a;
  creal_T c26_j_a22;
  creal_T c26_k_a22;
  creal_T c26_l_a22;
  creal_T c26_m_a22;
  int32_T c26_b_ilast;
  int32_T c26_m_b;
  int32_T c26_n_b;
  boolean_T c26_f_overflow;
  int32_T c26_k;
  int32_T c26_b_k;
  int32_T c26_pb_a;
  int32_T c26_qb_a;
  int32_T c26_i213;
  int32_T c26_o_b;
  int32_T c26_p_b;
  boolean_T c26_g_overflow;
  int32_T c26_e_j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T guard11 = false;
  c26_dc17.re = rtNaN;
  for (c26_i206 = 0; c26_i206 < 100; c26_i206++) {
    c26_b_A[c26_i206] = c26_A[c26_i206];
  }

  *c26_info = 0;
  for (c26_i207 = 0; c26_i207 < 10; c26_i207++) {
    c26_alpha1[c26_i207].re = 0.0;
    c26_alpha1[c26_i207].im = 0.0;
  }

  for (c26_i208 = 0; c26_i208 < 10; c26_i208++) {
    c26_beta1[c26_i208].re = 1.0;
    c26_beta1[c26_i208].im = 0.0;
  }

  c26_eps(chartInstance);
  c26_realmin(chartInstance);
  c26_eshift = c26_dc18;
  c26_ctemp = c26_dc18;
  c26_rho = c26_dc18;
  for (c26_i209 = 0; c26_i209 < 100; c26_i209++) {
    c26_c_A[c26_i209] = c26_b_A[c26_i209];
  }

  c26_anorm = c26_b_eml_matlab_zlanhs(chartInstance, c26_c_A, c26_ilo, c26_ihi);
  c26_y = 2.2204460492503131E-16 * c26_anorm;
  c26_atol = 2.2250738585072014E-308;
  if (c26_y > 2.2250738585072014E-308) {
    c26_atol = c26_y;
  }

  c26_b_y = c26_anorm;
  c26_x = 2.2250738585072014E-308;
  if (c26_b_y > 2.2250738585072014E-308) {
    c26_x = c26_b_y;
  }

  c26_ascale = 1.0 / c26_x;
  c26_failed = true;
  c26_a = c26_ihi;
  c26_b_a = c26_a + 1;
  c26_i210 = c26_b_a;
  c26_c_a = c26_i210;
  c26_d_a = c26_c_a;
  if (c26_d_a > 10) {
    c26_overflow = false;
  } else {
    c26_eml_switch_helper(chartInstance);
    c26_eml_switch_helper(chartInstance);
    c26_overflow = false;
  }

  if (c26_overflow) {
    c26_check_forloop_overflow_error(chartInstance, c26_overflow);
  }

  for (c26_j = c26_i210; c26_j < 11; c26_j++) {
    c26_b_j = c26_j;
    c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c26_b_j), 1, 10, 1, 0) - 1].re = c26_b_A
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c26_b_j), 1, 10, 1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) -
      1].re;
    c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c26_b_j), 1, 10, 1, 0) - 1].im = c26_b_A
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c26_b_j), 1, 10, 1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) -
      1].im;
  }

  guard1 = false;
  guard2 = false;
  if (c26_ihi >= c26_ilo) {
    c26_ifirst = c26_ilo;
    c26_istart = c26_ilo;
    c26_ilast = c26_ihi;
    c26_e_a = c26_ilast;
    c26_f_a = c26_e_a - 1;
    c26_ilastm1 = c26_f_a;
    c26_ifrstm = c26_ilo;
    c26_ilastm = c26_ihi;
    c26_iiter = 0;
    c26_g_a = c26_ihi;
    c26_b = c26_ilo;
    c26_h_a = c26_g_a;
    c26_b_b = c26_b;
    c26_c = c26_h_a - c26_b_b;
    c26_i_a = c26_c;
    c26_j_a = c26_i_a + 1;
    c26_b_c = c26_j_a;
    c26_c_b = c26_b_c;
    c26_d_b = c26_c_b;
    c26_maxit = 30 * c26_d_b;
    c26_goto50 = false;
    c26_goto60 = false;
    c26_goto70 = false;
    c26_goto90 = false;
    c26_b_maxit = c26_maxit;
    c26_e_b = c26_b_maxit;
    c26_f_b = c26_e_b;
    if (1 > c26_f_b) {
      c26_b_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_b_overflow = (c26_f_b > 2147483646);
    }

    if (c26_b_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
    }

    c26_jiter = 1;
    do {
      exitg1 = 0;
      if (c26_jiter <= c26_b_maxit) {
        if (c26_ilast == c26_ilo) {
          c26_goto60 = true;
        } else {
          c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0) - 1)) - 1]
            .re;
          c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0) - 1)) - 1]
            .im;
          c26_b_x = c26_a22.re;
          c26_c_x = c26_b_x;
          c26_c_y = muDoubleScalarAbs(c26_c_x);
          c26_d_x = c26_a22.im;
          c26_e_x = c26_d_x;
          c26_d_y = muDoubleScalarAbs(c26_e_x);
          c26_e_y = c26_c_y + c26_d_y;
          if (c26_e_y <= c26_atol) {
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0)
                      - 1)) - 1].re = c26_dc18.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0)
                      - 1)) - 1].im = c26_dc18.im;
            c26_goto60 = true;
          } else {
            c26_b_j = c26_ilastm1;
            exitg3 = false;
            while ((exitg3 == false) && (c26_b_j >= c26_ilo)) {
              c26_k_a = c26_b_j;
              c26_l_a = c26_k_a - 1;
              c26_jm1 = c26_l_a;
              if (c26_b_j == c26_ilo) {
                c26_ilazro = true;
              } else {
                c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2, 0) - 1)) -
                  1].re;
                c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2, 0) - 1)) -
                  1].im;
                c26_f_x = c26_a22.re;
                c26_g_x = c26_f_x;
                c26_f_y = muDoubleScalarAbs(c26_g_x);
                c26_h_x = c26_a22.im;
                c26_i_x = c26_h_x;
                c26_g_y = muDoubleScalarAbs(c26_i_x);
                c26_h_y = c26_f_y + c26_g_y;
                if (c26_h_y <= c26_atol) {
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                             0) - 1)) - 1].re = c26_dc18.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                             0) - 1)) - 1].im = c26_dc18.im;
                  c26_ilazro = true;
                } else {
                  c26_ilazro = false;
                }
              }

              if (c26_ilazro) {
                c26_ifirst = c26_b_j;
                c26_goto70 = true;
                exitg3 = true;
              } else {
                c26_b_j = c26_jm1;
              }
            }
          }
        }

        guard3 = false;
        guard4 = false;
        if (c26_goto50) {
          guard4 = true;
        } else if (c26_goto60) {
          guard4 = true;
        } else if (c26_goto70) {
          guard3 = true;
        } else {
          c26_b27 = false;
        }

        if (guard4 == true) {
          guard3 = true;
        }

        if (guard3 == true) {
          c26_b27 = true;
        }

        if (!c26_b27) {
          for (c26_i211 = 0; c26_i211 < 10; c26_i211++) {
            c26_alpha1[c26_i211] = c26_dc17;
          }

          for (c26_i212 = 0; c26_i212 < 10; c26_i212++) {
            c26_beta1[c26_i212] = c26_dc17;
          }

          *c26_info = 1;
          exitg1 = 1;
        } else {
          if (c26_goto50) {
            c26_goto50 = false;
            c26_d_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2, 0) - 1)) - 1]
              .re;
            c26_d_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2, 0) - 1)) - 1]
              .im;
            c26_e_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0) - 1)) -
              1].re;
            c26_e_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0) - 1)) -
              1].im;
            c26_eml_matlab_zlartg(chartInstance, c26_d_A, c26_e_A, &c26_c_c,
                                  &c26_s, &c26_a22);
            c26_d_c = c26_c_c;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2, 0) -
                      1)) - 1].re = c26_a22.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2, 0) -
                      1)) - 1].im = c26_a22.im;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0)
                      - 1)) - 1].re = c26_dc18.re;
            c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                       _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0)
                      - 1)) - 1].im = c26_dc18.im;
            c26_e_c = c26_d_c;
            c26_xcol = c26_ilast;
            c26_ycol = c26_ilastm1;
            c26_b_ilo = c26_ifrstm;
            c26_b_ihi = c26_ilastm1;
            c26_c_ilo = c26_b_ilo;
            c26_c_ihi = c26_b_ihi;
            c26_m_a = c26_c_ilo;
            c26_g_b = c26_c_ihi;
            c26_n_a = c26_m_a;
            c26_h_b = c26_g_b;
            if (c26_n_a > c26_h_b) {
              c26_c_overflow = false;
            } else {
              c26_eml_switch_helper(chartInstance);
              c26_eml_switch_helper(chartInstance);
              c26_c_overflow = (c26_h_b > 2147483646);
            }

            if (c26_c_overflow) {
              c26_check_forloop_overflow_error(chartInstance, c26_c_overflow);
            }

            for (c26_i = c26_c_ilo; c26_i <= c26_c_ihi; c26_i++) {
              c26_b_i = c26_i;
              c26_o_a = c26_e_c;
              c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1]
                .re;
              c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1]
                .im;
              c26_a12.re = c26_o_a * c26_a22.re;
              c26_a12.im = c26_o_a * c26_a22.im;
              c26_b_s.re = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) +
                10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1]
                .re - c26_s.im * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) +
                10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1]
                .im;
              c26_b_s.im = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) +
                10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1]
                .im + c26_s.im * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) +
                10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1]
                .re;
              c26_a21.re = c26_a12.re + c26_b_s.re;
              c26_a21.im = c26_a12.im + c26_b_s.im;
              c26_p_a = c26_e_c;
              c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1]
                .re;
              c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1]
                .im;
              c26_a12.re = c26_p_a * c26_a22.re;
              c26_a12.im = c26_p_a * c26_a22.im;
              c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1]
                .re;
              c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1]
                .im;
              c26_b_a22 = c26_a22;
              c26_c_a22 = c26_a22;
              c26_d_a22 = c26_a22;
              c26_e_a22 = c26_a22;
              c26_a22.re = c26_s.re * c26_b_a22.re + c26_s.im * c26_c_a22.im;
              c26_a22.im = c26_s.re * c26_d_a22.im - c26_s.im * c26_e_a22.re;
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) +
                       10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0)
                             - 1)) - 1].re = c26_a12.re - c26_a22.re;
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) +
                       10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0)
                             - 1)) - 1].im = c26_a12.im - c26_a22.im;
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) +
                       10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0)
                             - 1)) - 1].re = c26_a21.re;
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) +
                       10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                         _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0)
                             - 1)) - 1].im = c26_a21.im;
            }

            c26_goto60 = true;
          }

          guard11 = false;
          if (c26_goto60) {
            c26_goto60 = false;
            c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) - 1].re =
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0)
                       + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2, 0) - 1)) - 1]
              .re;
            c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) - 1].im =
              c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0)
                       + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2, 0) - 1)) - 1]
              .im;
            c26_ilast = c26_ilastm1;
            c26_q_a = c26_ilast;
            c26_r_a = c26_q_a - 1;
            c26_ilastm1 = c26_r_a;
            if (c26_ilast < c26_ilo) {
              c26_failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              c26_iiter = 0;
              c26_eshift = c26_dc18;
              c26_ilastm = c26_ilast;
              if (c26_ifrstm > c26_ilast) {
                c26_ifrstm = c26_ilo;
              }

              guard11 = true;
            }
          } else {
            if (c26_goto70) {
              c26_goto70 = false;
              c26_s_a = c26_iiter;
              c26_t_a = c26_s_a + 1;
              c26_iiter = c26_t_a;
              c26_ifrstm = c26_ifirst;
              if (c26_mod(chartInstance, c26_iiter) != 0) {
                c26_rho.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 1, 0) + 10
                                      * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2,
                  0) - 1)) - 1].re;
                c26_rho.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 1, 0) + 10
                                      * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2,
                  0) - 1)) - 1].im;
                c26_r2.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2, 0) - 1))
                  - 1].re;
                c26_r2.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2, 0) - 1))
                  - 1].im;
                c26_a12.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 1, 0) + 10
                                      * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2,
                  0) - 1)) - 1].re;
                c26_a12.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 1, 0) + 10
                                      * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 2,
                  0) - 1)) - 1].im;
                c26_a21.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0) - 1))
                  - 1].re;
                c26_a21.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0) - 1))
                  - 1].im;
                c26_a22.re = c26_r2.re - c26_rho.re;
                c26_a22.im = c26_r2.im - c26_rho.im;
                c26_a22.re = -c26_a22.re;
                c26_a22.im = -c26_a22.im;
                c26_ar = c26_a22.re;
                c26_ai = c26_a22.im;
                c26_br = c26_dc19.re;
                c26_bi = c26_dc19.im;
                if (c26_bi == 0.0) {
                  if (c26_ai == 0.0) {
                    c26_s.re = c26_ar / c26_br;
                    c26_s.im = 0.0;
                  } else if (c26_ar == 0.0) {
                    c26_s.re = 0.0;
                    c26_s.im = c26_ai / c26_br;
                  } else {
                    c26_s.re = c26_ar / c26_br;
                    c26_s.im = c26_ai / c26_br;
                  }
                } else if (c26_br == 0.0) {
                  if (c26_ar == 0.0) {
                    c26_s.re = c26_ai / c26_bi;
                    c26_s.im = 0.0;
                  } else if (c26_ai == 0.0) {
                    c26_s.re = 0.0;
                    c26_s.im = -(c26_ar / c26_bi);
                  } else {
                    c26_s.re = c26_ai / c26_bi;
                    c26_s.im = -(c26_ar / c26_bi);
                  }
                } else {
                  c26_brm = muDoubleScalarAbs(c26_br);
                  c26_bim = muDoubleScalarAbs(c26_bi);
                  if (c26_brm > c26_bim) {
                    c26_c_s = c26_bi / c26_br;
                    c26_d = c26_br + c26_c_s * c26_bi;
                    c26_nr = c26_ar + c26_c_s * c26_ai;
                    c26_ni = c26_ai - c26_c_s * c26_ar;
                    c26_s.re = c26_nr / c26_d;
                    c26_s.im = c26_ni / c26_d;
                  } else if (c26_bim == c26_brm) {
                    if (c26_br > 0.0) {
                      c26_sgnbr = 0.5;
                    } else {
                      c26_sgnbr = -0.5;
                    }

                    if (c26_bi > 0.0) {
                      c26_sgnbi = 0.5;
                    } else {
                      c26_sgnbi = -0.5;
                    }

                    c26_nr = c26_ar * c26_sgnbr + c26_ai * c26_sgnbi;
                    c26_ni = c26_ai * c26_sgnbr - c26_ar * c26_sgnbi;
                    c26_s.re = c26_nr / c26_brm;
                    c26_s.im = c26_ni / c26_brm;
                  } else {
                    c26_c_s = c26_br / c26_bi;
                    c26_d = c26_bi + c26_c_s * c26_br;
                    c26_nr = c26_c_s * c26_ar + c26_ai;
                    c26_ni = c26_c_s * c26_ai - c26_ar;
                    c26_s.re = c26_nr / c26_d;
                    c26_s.im = c26_ni / c26_d;
                  }
                }

                c26_d_s.re = c26_s.re * c26_s.re - c26_s.im * c26_s.im;
                c26_d_s.im = c26_s.re * c26_s.im + c26_s.im * c26_s.re;
                c26_b_a12.re = c26_a12.re * c26_a21.re - c26_a12.im * c26_a21.im;
                c26_b_a12.im = c26_a12.re * c26_a21.im + c26_a12.im * c26_a21.re;
                c26_a22.re = c26_d_s.re + c26_b_a12.re;
                c26_a22.im = c26_d_s.im + c26_b_a12.im;
                c26_d_sqrt(chartInstance, &c26_a22);
                c26_a12.re = c26_rho.re - (c26_s.re - c26_a22.re);
                c26_a12.im = c26_rho.im - (c26_s.im - c26_a22.im);
                c26_a21.re = c26_rho.re - (c26_s.re + c26_a22.re);
                c26_a21.im = c26_rho.im - (c26_s.im + c26_a22.im);
                c26_c_a12.re = c26_a12.re - c26_r2.re;
                c26_c_a12.im = c26_a12.im - c26_r2.im;
                c26_b_a21.re = c26_a21.re - c26_r2.re;
                c26_b_a21.im = c26_a21.im - c26_r2.im;
                c26_d13 = c26_b_abs(chartInstance, c26_c_a12);
                c26_d14 = c26_b_abs(chartInstance, c26_b_a21);
                if (c26_d13 <= c26_d14) {
                  c26_a21 = c26_a12;
                  c26_rho.re = c26_s.re - c26_a22.re;
                  c26_rho.im = c26_s.im - c26_a22.im;
                } else {
                  c26_rho.re = c26_s.re + c26_a22.re;
                  c26_rho.im = c26_s.im + c26_a22.im;
                }
              } else {
                c26_eshift.re += c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1,
                  0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0) - 1))
                  - 1].re;
                c26_eshift.im += c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ilast), 1, 10, 1,
                  0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_ilastm1), 1, 10, 2, 0) - 1))
                  - 1].im;
                c26_a21 = c26_eshift;
              }

              c26_b_j = c26_ilastm1;
              c26_u_a = c26_b_j;
              c26_v_a = c26_u_a + 1;
              c26_jp1 = c26_v_a;
              exitg2 = false;
              while ((exitg2 == false) && (c26_b_j > c26_ifirst)) {
                c26_w_a = c26_b_j;
                c26_x_a = c26_w_a - 1;
                c26_jm1 = c26_x_a;
                c26_istart = c26_b_j;
                c26_ctemp.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0) + 10 *
                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                  "", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re - c26_a21.re;
                c26_ctemp.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0) + 10 *
                  (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                  "", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im - c26_a21.im;
                c26_j_x = c26_ctemp.re;
                c26_k_x = c26_j_x;
                c26_i_y = muDoubleScalarAbs(c26_k_x);
                c26_l_x = c26_ctemp.im;
                c26_m_x = c26_l_x;
                c26_j_y = muDoubleScalarAbs(c26_m_x);
                c26_k_y = c26_i_y + c26_j_y;
                c26_temp = c26_ascale * c26_k_y;
                c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) -
                  1].re;
                c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) -
                  1].im;
                c26_n_x = c26_a22.re;
                c26_o_x = c26_n_x;
                c26_l_y = muDoubleScalarAbs(c26_o_x);
                c26_p_x = c26_a22.im;
                c26_q_x = c26_p_x;
                c26_m_y = muDoubleScalarAbs(c26_q_x);
                c26_n_y = c26_l_y + c26_m_y;
                c26_temp2 = c26_ascale * c26_n_y;
                c26_r_x = c26_temp;
                c26_o_y = c26_temp2;
                c26_tempr = c26_r_x;
                if (c26_o_y > c26_tempr) {
                  c26_tempr = c26_o_y;
                }

                if (c26_tempr < 1.0) {
                  if (c26_tempr != 0.0) {
                    c26_temp /= c26_tempr;
                    c26_temp2 /= c26_tempr;
                  }
                }

                c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2, 0) - 1)) -
                  1].re;
                c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0) + 10 *
                                      (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                  _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2, 0) - 1)) -
                  1].im;
                c26_s_x = c26_a22.re;
                c26_t_x = c26_s_x;
                c26_p_y = muDoubleScalarAbs(c26_t_x);
                c26_u_x = c26_a22.im;
                c26_v_x = c26_u_x;
                c26_q_y = muDoubleScalarAbs(c26_v_x);
                c26_r_y = c26_p_y + c26_q_y;
                if (c26_r_y * c26_temp2 <= c26_temp * c26_atol) {
                  c26_goto90 = true;
                  exitg2 = true;
                } else {
                  c26_jp1 = c26_b_j;
                  c26_b_j = c26_jm1;
                }
              }

              if (!c26_goto90) {
                c26_istart = c26_ifirst;
                if (c26_istart == c26_ilastm1) {
                  c26_ctemp = c26_rho;
                } else {
                  c26_ctemp.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 10, 2, 0) - 1))
                    - 1].re - c26_a21.re;
                  c26_ctemp.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 10, 2, 0) - 1))
                    - 1].im - c26_a21.im;
                }

                c26_goto90 = true;
              }
            }

            if (c26_goto90) {
              c26_goto90 = false;
              c26_y_a = c26_istart;
              c26_ab_a = c26_y_a + 1;
              c26_f_c = c26_ab_a;
              c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_f_c), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 10, 2, 0) - 1)) -
                1].re;
              c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_f_c), 1, 10, 1, 0) + 10 *
                                    (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c26_istart), 1, 10, 2, 0) - 1)) -
                1].im;
              c26_b_eml_matlab_zlartg(chartInstance, c26_ctemp, c26_a22,
                &c26_g_c, &c26_s);
              c26_d_c = c26_g_c;
              c26_b_j = c26_istart;
              c26_bb_a = c26_b_j;
              c26_cb_a = c26_bb_a - 1;
              c26_jm1 = c26_cb_a;
              while (c26_b_j < c26_ilast) {
                c26_db_a = c26_b_j;
                c26_eb_a = c26_db_a + 1;
                c26_jp1 = c26_eb_a;
                if (c26_b_j > c26_istart) {
                  c26_f_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c26_f_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c26_g_A.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c26_g_A.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c26_eml_matlab_zlartg(chartInstance, c26_f_A, c26_g_A,
                                        &c26_h_c, &c26_s, &c26_a22);
                  c26_d_c = c26_h_c;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                             0) - 1)) - 1].re = c26_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                             0) - 1)) - 1].im = c26_a22.im;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                             0) - 1)) - 1].re = c26_dc18.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_jp1), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_jm1), 1, 10, 2,
                             0) - 1)) - 1].im = c26_dc18.im;
                }

                c26_i_c = c26_d_c;
                c26_xrow = c26_b_j;
                c26_yrow = c26_jp1;
                c26_jlo = c26_b_j;
                c26_jhi = c26_ilastm;
                c26_b_jlo = c26_jlo;
                c26_b_jhi = c26_jhi;
                c26_fb_a = c26_b_jlo;
                c26_i_b = c26_b_jhi;
                c26_gb_a = c26_fb_a;
                c26_j_b = c26_i_b;
                if (c26_gb_a > c26_j_b) {
                  c26_d_overflow = false;
                } else {
                  c26_eml_switch_helper(chartInstance);
                  c26_eml_switch_helper(chartInstance);
                  c26_d_overflow = (c26_j_b > 2147483646);
                }

                if (c26_d_overflow) {
                  c26_check_forloop_overflow_error(chartInstance, c26_d_overflow);
                }

                for (c26_c_j = c26_b_jlo; c26_c_j <= c26_b_jhi; c26_c_j++) {
                  c26_d_j = c26_c_j;
                  c26_hb_a = c26_i_c;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c26_a12.re = c26_hb_a * c26_a22.re;
                  c26_a12.im = c26_hb_a * c26_a22.im;
                  c26_e_s.re = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2, 0) - 1))
                    - 1].re - c26_s.im * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1,
                    0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2, 0) - 1))
                    - 1].im;
                  c26_e_s.im = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2, 0) - 1))
                    - 1].im + c26_s.im * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1,
                    0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2, 0) - 1))
                    - 1].re;
                  c26_a21.re = c26_a12.re + c26_e_s.re;
                  c26_a21.im = c26_a12.im + c26_e_s.im;
                  c26_ib_a = c26_i_c;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c26_a12.re = c26_ib_a * c26_a22.re;
                  c26_a12.im = c26_ib_a * c26_a22.im;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                    0) - 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                    0) - 1)) - 1].im;
                  c26_f_a22 = c26_a22;
                  c26_g_a22 = c26_a22;
                  c26_h_a22 = c26_a22;
                  c26_i_a22 = c26_a22;
                  c26_a22.re = c26_s.re * c26_f_a22.re + c26_s.im * c26_g_a22.im;
                  c26_a22.im = c26_s.re * c26_h_a22.im - c26_s.im * c26_i_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1,
                            0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                             0) - 1)) - 1].re = c26_a12.re - c26_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1,
                            0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                             0) - 1)) - 1].im = c26_a12.im - c26_a22.im;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1,
                            0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                             0) - 1)) - 1].re = c26_a21.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1,
                            0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2,
                             0) - 1)) - 1].im = c26_a21.im;
                }

                c26_s.re = -c26_s.re;
                c26_s.im = -c26_s.im;
                c26_jb_a = c26_jp1;
                c26_kb_a = c26_jb_a + 1;
                c26_j_c = c26_kb_a;
                c26_w_x = c26_j_c;
                c26_s_y = c26_ilast;
                c26_x_x = c26_w_x;
                if (c26_s_y < c26_x_x) {
                  c26_x_x = c26_s_y;
                }

                c26_k_c = c26_d_c;
                c26_b_xcol = c26_jp1;
                c26_b_ycol = c26_b_j;
                c26_d_ilo = c26_ifrstm;
                c26_d_ihi = c26_x_x;
                c26_e_ilo = c26_d_ilo;
                c26_e_ihi = c26_d_ihi;
                c26_lb_a = c26_e_ilo;
                c26_k_b = c26_e_ihi;
                c26_mb_a = c26_lb_a;
                c26_l_b = c26_k_b;
                if (c26_mb_a > c26_l_b) {
                  c26_e_overflow = false;
                } else {
                  c26_eml_switch_helper(chartInstance);
                  c26_eml_switch_helper(chartInstance);
                  c26_e_overflow = (c26_l_b > 2147483646);
                }

                if (c26_e_overflow) {
                  c26_check_forloop_overflow_error(chartInstance, c26_e_overflow);
                }

                for (c26_c_i = c26_e_ilo; c26_c_i <= c26_e_ihi; c26_c_i++) {
                  c26_d_i = c26_c_i;
                  c26_nb_a = c26_k_c;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 10,
                    2, 0) - 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 10,
                    2, 0) - 1)) - 1].im;
                  c26_a12.re = c26_nb_a * c26_a22.re;
                  c26_a12.im = c26_nb_a * c26_a22.im;
                  c26_f_s.re = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 10, 2, 0) - 1))
                    - 1].re - c26_s.im * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1,
                    0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 10, 2, 0) - 1))
                    - 1].im;
                  c26_f_s.im = c26_s.re * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10,
                    1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 10, 2, 0) - 1))
                    - 1].im + c26_s.im * c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1,
                    0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 10, 2, 0) - 1))
                    - 1].re;
                  c26_a21.re = c26_a12.re + c26_f_s.re;
                  c26_a21.im = c26_a12.im + c26_f_s.im;
                  c26_ob_a = c26_k_c;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 10,
                    2, 0) - 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 10,
                    2, 0) - 1)) - 1].im;
                  c26_a12.re = c26_ob_a * c26_a22.re;
                  c26_a12.im = c26_ob_a * c26_a22.im;
                  c26_a22.re = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 10,
                    2, 0) - 1)) - 1].re;
                  c26_a22.im = c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                    _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                                        (_SFD_EML_ARRAY_BOUNDS_CHECK("",
                    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 10,
                    2, 0) - 1)) - 1].im;
                  c26_j_a22 = c26_a22;
                  c26_k_a22 = c26_a22;
                  c26_l_a22 = c26_a22;
                  c26_m_a22 = c26_a22;
                  c26_a22.re = c26_s.re * c26_j_a22.re + c26_s.im * c26_k_a22.im;
                  c26_a22.im = c26_s.re * c26_l_a22.im - c26_s.im * c26_m_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 10,
                             2, 0) - 1)) - 1].re = c26_a12.re - c26_a22.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_b_ycol), 1, 10,
                             2, 0) - 1)) - 1].im = c26_a12.im - c26_a22.im;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 10,
                             2, 0) - 1)) - 1].re = c26_a21.re;
                  c26_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                            _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0)
                           + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                             _SFD_INTEGER_CHECK("", (real_T)c26_b_xcol), 1, 10,
                             2, 0) - 1)) - 1].im = c26_a21.im;
                }

                c26_jm1 = c26_b_j;
                c26_b_j = c26_jp1;
              }
            }

            guard11 = true;
          }

          if (guard11 == true) {
            c26_jiter++;
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
    if (c26_failed) {
      *c26_info = c26_ilast;
      c26_b_ilast = c26_ilast;
      c26_m_b = c26_b_ilast;
      c26_n_b = c26_m_b;
      if (1 > c26_n_b) {
        c26_f_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_f_overflow = (c26_n_b > 2147483646);
      }

      if (c26_f_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_f_overflow);
      }

      for (c26_k = 1; c26_k <= c26_b_ilast; c26_k++) {
        c26_b_k = c26_k;
        c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c26_b_k), 1, 10, 1, 0) - 1].re = c26_dc17.re;
        c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c26_b_k), 1, 10, 1, 0) - 1].im = c26_dc17.im;
        c26_beta1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_k), 1, 10, 1, 0) - 1].re = c26_dc17.re;
        c26_beta1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_k), 1, 10, 1, 0) - 1].im = c26_dc17.im;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    c26_pb_a = c26_ilo;
    c26_qb_a = c26_pb_a - 1;
    c26_i213 = c26_qb_a;
    c26_o_b = c26_i213;
    c26_p_b = c26_o_b;
    if (1 > c26_p_b) {
      c26_g_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_g_overflow = (c26_p_b > 2147483646);
    }

    if (c26_g_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_g_overflow);
    }

    for (c26_e_j = 1; c26_e_j <= c26_i213; c26_e_j++) {
      c26_b_j = c26_e_j;
      c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c26_b_j), 1, 10, 1, 0) - 1].re = c26_b_A
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_b_j), 1, 10, 1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) -
           1)) - 1].re;
      c26_alpha1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c26_b_j), 1, 10, 1, 0) - 1].im = c26_b_A
        [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_b_j), 1, 10, 1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) -
           1)) - 1].im;
    }
  }
}

static real_T c26_b_eml_matlab_zlanhs(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[100], int32_T c26_ilo, int32_T c26_ihi)
{
  real_T c26_f;
  real_T c26_scale;
  real_T c26_sumsq;
  boolean_T c26_firstNonZero;
  int32_T c26_b_ilo;
  int32_T c26_b_ihi;
  int32_T c26_a;
  int32_T c26_b;
  int32_T c26_b_a;
  int32_T c26_b_b;
  boolean_T c26_overflow;
  int32_T c26_j;
  int32_T c26_b_j;
  int32_T c26_c_ilo;
  int32_T c26_c_a;
  int32_T c26_d_a;
  int32_T c26_c;
  int32_T c26_x;
  int32_T c26_y;
  int32_T c26_i214;
  int32_T c26_e_a;
  int32_T c26_c_b;
  int32_T c26_f_a;
  int32_T c26_d_b;
  boolean_T c26_b_overflow;
  int32_T c26_i;
  int32_T c26_b_i;
  creal_T c26_Aij;
  real_T c26_reAij;
  real_T c26_imAij;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_temp1;
  real_T c26_temp2;
  real_T c26_d_x;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_g_x;
  c26_f = 0.0;
  if (c26_ilo > c26_ihi) {
  } else {
    c26_scale = 0.0;
    c26_sumsq = 0.0;
    c26_firstNonZero = true;
    c26_b_ilo = c26_ilo;
    c26_b_ihi = c26_ihi;
    c26_a = c26_b_ilo;
    c26_b = c26_b_ihi;
    c26_b_a = c26_a;
    c26_b_b = c26_b;
    if (c26_b_a > c26_b_b) {
      c26_overflow = false;
    } else {
      c26_eml_switch_helper(chartInstance);
      c26_eml_switch_helper(chartInstance);
      c26_overflow = (c26_b_b > 2147483646);
    }

    if (c26_overflow) {
      c26_check_forloop_overflow_error(chartInstance, c26_overflow);
    }

    for (c26_j = c26_b_ilo; c26_j <= c26_b_ihi; c26_j++) {
      c26_b_j = c26_j;
      c26_c_ilo = c26_ilo;
      c26_c_a = c26_b_j;
      c26_d_a = c26_c_a;
      c26_c = c26_d_a;
      c26_x = c26_c + 1;
      c26_y = c26_ihi;
      c26_i214 = c26_x;
      if (c26_y < c26_i214) {
        c26_i214 = c26_y;
      }

      c26_e_a = c26_c_ilo;
      c26_c_b = c26_i214;
      c26_f_a = c26_e_a;
      c26_d_b = c26_c_b;
      if (c26_f_a > c26_d_b) {
        c26_b_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_b_overflow = (c26_d_b > 2147483646);
      }

      if (c26_b_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
      }

      for (c26_i = c26_c_ilo; c26_i <= c26_i214; c26_i++) {
        c26_b_i = c26_i;
        c26_Aij.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re;
        c26_Aij.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im;
        c26_reAij = c26_Aij.re;
        c26_imAij = c26_Aij.im;
        if (c26_reAij != 0.0) {
          c26_b_x = c26_reAij;
          c26_c_x = c26_b_x;
          c26_temp1 = muDoubleScalarAbs(c26_c_x);
          if (c26_firstNonZero) {
            c26_sumsq = 1.0;
            c26_scale = c26_temp1;
            c26_firstNonZero = false;
          } else if (c26_scale < c26_temp1) {
            c26_temp2 = c26_scale / c26_temp1;
            c26_sumsq = 1.0 + c26_sumsq * c26_temp2 * c26_temp2;
            c26_scale = c26_temp1;
          } else {
            c26_temp2 = c26_temp1 / c26_scale;
            c26_sumsq += c26_temp2 * c26_temp2;
          }
        }

        if (c26_imAij != 0.0) {
          c26_d_x = c26_imAij;
          c26_e_x = c26_d_x;
          c26_temp1 = muDoubleScalarAbs(c26_e_x);
          if (c26_firstNonZero) {
            c26_sumsq = 1.0;
            c26_scale = c26_temp1;
            c26_firstNonZero = false;
          } else if (c26_scale < c26_temp1) {
            c26_temp2 = c26_scale / c26_temp1;
            c26_sumsq = 1.0 + c26_sumsq * c26_temp2 * c26_temp2;
            c26_scale = c26_temp1;
          } else {
            c26_temp2 = c26_temp1 / c26_scale;
            c26_sumsq += c26_temp2 * c26_temp2;
          }
        }
      }
    }

    c26_f_x = c26_sumsq;
    c26_g_x = c26_f_x;
    if (c26_g_x < 0.0) {
      c26_c_eml_error(chartInstance);
    }

    c26_g_x = muDoubleScalarSqrt(c26_g_x);
    c26_f = c26_scale * c26_g_x;
  }

  return c26_f;
}

static boolean_T c26_b_eml_relop(SFc26_hybridSysSimInstanceStruct *chartInstance,
  creal_T c26_a, creal_T c26_b)
{
  real_T c26_RMAXA;
  real_T c26_RMAXB;
  real_T c26_d15;
  real_T c26_d16;
  real_T c26_d17;
  real_T c26_d18;
  real_T c26_A;
  real_T c26_y;
  real_T c26_b_A;
  real_T c26_b_y;
  real_T c26_x;
  real_T c26_c_A;
  real_T c26_c_y;
  real_T c26_d_A;
  real_T c26_d_y;
  real_T c26_e_y;
  real_T c26_b_a;
  real_T c26_b_b;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_f_y;
  real_T c26_e_A;
  real_T c26_g_y;
  real_T c26_d_x;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_absxk;
  real_T c26_r;
  int32_T c26_exponent;
  int32_T c26_b_exponent;
  int32_T c26_c_exponent;
  real_T c26_g_x;
  boolean_T c26_c_b;
  real_T c26_h_x;
  boolean_T c26_d_b;
  boolean_T c26_b28;
  boolean_T c26_b_p;
  real_T c26_ar;
  real_T c26_absar;
  real_T c26_ai;
  real_T c26_absai;
  real_T c26_br;
  real_T c26_absbr;
  real_T c26_bi;
  real_T c26_absbi;
  real_T c26_Ma;
  real_T c26_ma;
  real_T c26_Mb;
  real_T c26_mb;
  real_T c26_f_A;
  real_T c26_h_y;
  real_T c26_g_A;
  real_T c26_i_y;
  real_T c26_Mbar;
  real_T c26_h_A;
  real_T c26_j_y;
  real_T c26_i_A;
  real_T c26_k_y;
  real_T c26_mbar;
  real_T c26_j_A;
  real_T c26_B;
  real_T c26_l_y;
  real_T c26_k_A;
  real_T c26_m_y;
  real_T c26_l_A;
  real_T c26_n_y;
  real_T c26_m_A;
  real_T c26_o_y;
  real_T c26_n_A;
  real_T c26_p_y;
  real_T c26_o_A;
  real_T c26_b_B;
  real_T c26_q_y;
  real_T c26_c_a;
  real_T c26_e_b;
  real_T c26_i_x;
  real_T c26_j_x;
  real_T c26_r_y;
  real_T c26_p_A;
  real_T c26_s_y;
  real_T c26_k_x;
  real_T c26_l_x;
  real_T c26_m_x;
  real_T c26_b_absxk;
  real_T c26_b_r;
  int32_T c26_d_exponent;
  int32_T c26_e_exponent;
  int32_T c26_f_exponent;
  real_T c26_n_x;
  boolean_T c26_f_b;
  real_T c26_o_x;
  boolean_T c26_g_b;
  boolean_T c26_b29;
  boolean_T c26_c_p;
  real_T c26_d_a;
  real_T c26_h_b;
  real_T c26_p_x;
  real_T c26_q_x;
  real_T c26_t_y;
  real_T c26_q_A;
  real_T c26_u_y;
  real_T c26_r_x;
  real_T c26_s_x;
  real_T c26_t_x;
  real_T c26_c_absxk;
  real_T c26_c_r;
  int32_T c26_g_exponent;
  int32_T c26_h_exponent;
  int32_T c26_i_exponent;
  real_T c26_u_x;
  boolean_T c26_i_b;
  real_T c26_v_x;
  boolean_T c26_j_b;
  boolean_T c26_b30;
  boolean_T c26_d_p;
  real_T c26_v_y;
  real_T c26_w_y;
  real_T c26_x_y;
  real_T c26_y_y;
  real_T c26_e_a;
  real_T c26_k_b;
  real_T c26_w_x;
  real_T c26_x_x;
  real_T c26_ab_y;
  real_T c26_r_A;
  real_T c26_bb_y;
  real_T c26_y_x;
  real_T c26_ab_x;
  real_T c26_bb_x;
  real_T c26_d_absxk;
  real_T c26_d_r;
  int32_T c26_j_exponent;
  int32_T c26_k_exponent;
  int32_T c26_l_exponent;
  real_T c26_cb_x;
  boolean_T c26_l_b;
  real_T c26_db_x;
  boolean_T c26_m_b;
  boolean_T c26_b31;
  boolean_T c26_e_p;
  real_T c26_eb_x;
  real_T c26_cb_y;
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
  c26_realmax(chartInstance);
  c26_RMAXA = c26_rdivide(chartInstance, 1.7976931348623157E+308, 2.0);
  c26_realmax(chartInstance);
  c26_RMAXB = c26_rdivide(chartInstance, 1.7976931348623157E+308, 2.0);
  c26_d15 = c26_abs(chartInstance, c26_a.re);
  guard13 = false;
  guard14 = false;
  guard15 = false;
  if (c26_d15 > c26_RMAXA) {
    guard15 = true;
  } else {
    c26_d16 = c26_abs(chartInstance, c26_a.im);
    if (c26_d16 > c26_RMAXA) {
      guard15 = true;
    } else {
      c26_d17 = c26_abs(chartInstance, c26_b.re);
      if (c26_d17 > c26_RMAXB) {
        guard14 = true;
      } else {
        c26_d18 = c26_abs(chartInstance, c26_b.im);
        if (c26_d18 > c26_RMAXB) {
          guard13 = true;
        } else {
          c26_x = c26_b_abs(chartInstance, c26_a);
          c26_e_y = c26_b_abs(chartInstance, c26_b);
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
    c26_A = c26_a.re;
    c26_y = c26_rdivide(chartInstance, c26_A, 2.0);
    c26_b_A = c26_a.im;
    c26_b_y = c26_rdivide(chartInstance, c26_b_A, 2.0);
    c26_x = c26_hypot(chartInstance, c26_y, c26_b_y);
    c26_c_A = c26_b.re;
    c26_c_y = c26_rdivide(chartInstance, c26_c_A, 2.0);
    c26_d_A = c26_b.im;
    c26_d_y = c26_rdivide(chartInstance, c26_d_A, 2.0);
    c26_e_y = c26_hypot(chartInstance, c26_c_y, c26_d_y);
  }

  c26_b_a = c26_x;
  c26_b_b = c26_e_y;
  c26_b_x = c26_b_b - c26_b_a;
  c26_c_x = c26_b_x;
  c26_f_y = muDoubleScalarAbs(c26_c_x);
  c26_e_A = c26_b_b;
  c26_g_y = c26_rdivide(chartInstance, c26_e_A, 2.0);
  c26_d_x = c26_g_y;
  c26_eml_realmin(chartInstance);
  c26_e_x = c26_d_x;
  c26_f_x = c26_e_x;
  c26_absxk = muDoubleScalarAbs(c26_f_x);
  if (c26_isfinite(chartInstance, c26_absxk)) {
    if (c26_absxk <= 2.2250738585072014E-308) {
      c26_r = 4.94065645841247E-324;
    } else {
      frexp(c26_absxk, &c26_exponent);
      c26_b_exponent = c26_exponent;
      c26_c_exponent = c26_b_exponent;
      c26_c_exponent;
      c26_r = ldexp(1.0, c26_c_exponent - 53);
    }
  } else {
    c26_r = rtNaN;
  }

  guard10 = false;
  guard11 = false;
  guard12 = false;
  if (c26_f_y < c26_r) {
    guard11 = true;
  } else {
    c26_g_x = c26_b_a;
    c26_c_b = muDoubleScalarIsInf(c26_g_x);
    if (c26_c_b) {
      c26_h_x = c26_b_b;
      c26_d_b = muDoubleScalarIsInf(c26_h_x);
      if (c26_d_b) {
        if (c26_b_a > 0.0 == c26_b_b > 0.0) {
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
    c26_b28 = true;
  }

  if (guard10 == true) {
    c26_b28 = false;
  }

  c26_b_p = c26_b28;
  if (c26_b_p) {
    c26_ar = c26_a.re;
    c26_absar = c26_abs(chartInstance, c26_ar);
    c26_ai = c26_a.im;
    c26_absai = c26_abs(chartInstance, c26_ai);
    c26_br = c26_b.re;
    c26_absbr = c26_abs(chartInstance, c26_br);
    c26_bi = c26_b.im;
    c26_absbi = c26_abs(chartInstance, c26_bi);
    if (c26_absar > c26_absai) {
      c26_Ma = c26_absar;
      c26_ma = c26_absai;
    } else {
      c26_Ma = c26_absai;
      c26_ma = c26_absar;
    }

    if (c26_absbr > c26_absbi) {
      c26_Mb = c26_absbr;
      c26_mb = c26_absbi;
    } else {
      c26_Mb = c26_absbi;
      c26_mb = c26_absbr;
    }

    if (c26_Ma > c26_Mb) {
      if (c26_ma < c26_mb) {
        c26_x = c26_Ma - c26_Mb;
        c26_f_A = c26_Ma;
        c26_h_y = c26_rdivide(chartInstance, c26_f_A, 2.0);
        c26_g_A = c26_Mb;
        c26_i_y = c26_rdivide(chartInstance, c26_g_A, 2.0);
        c26_Mbar = c26_h_y + c26_i_y;
        c26_h_A = c26_ma;
        c26_j_y = c26_rdivide(chartInstance, c26_h_A, 2.0);
        c26_i_A = c26_mb;
        c26_k_y = c26_rdivide(chartInstance, c26_i_A, 2.0);
        c26_mbar = c26_j_y + c26_k_y;
        c26_j_A = c26_mbar;
        c26_B = c26_Mbar;
        c26_l_y = c26_rdivide(chartInstance, c26_j_A, c26_B);
        c26_e_y = c26_l_y * (c26_mb - c26_ma);
      } else {
        c26_x = c26_Ma;
        c26_e_y = c26_Mb;
      }
    } else if (c26_Ma < c26_Mb) {
      if (c26_ma > c26_mb) {
        c26_e_y = c26_Mb - c26_Ma;
        c26_k_A = c26_Ma;
        c26_m_y = c26_rdivide(chartInstance, c26_k_A, 2.0);
        c26_l_A = c26_Mb;
        c26_n_y = c26_rdivide(chartInstance, c26_l_A, 2.0);
        c26_Mbar = c26_m_y + c26_n_y;
        c26_m_A = c26_ma;
        c26_o_y = c26_rdivide(chartInstance, c26_m_A, 2.0);
        c26_n_A = c26_mb;
        c26_p_y = c26_rdivide(chartInstance, c26_n_A, 2.0);
        c26_mbar = c26_o_y + c26_p_y;
        c26_o_A = c26_mbar;
        c26_b_B = c26_Mbar;
        c26_q_y = c26_rdivide(chartInstance, c26_o_A, c26_b_B);
        c26_x = c26_q_y * (c26_ma - c26_mb);
      } else {
        c26_x = c26_Ma;
        c26_e_y = c26_Mb;
      }
    } else {
      c26_x = c26_ma;
      c26_e_y = c26_mb;
    }

    c26_c_a = c26_x;
    c26_e_b = c26_e_y;
    c26_i_x = c26_e_b - c26_c_a;
    c26_j_x = c26_i_x;
    c26_r_y = muDoubleScalarAbs(c26_j_x);
    c26_p_A = c26_e_b;
    c26_s_y = c26_rdivide(chartInstance, c26_p_A, 2.0);
    c26_k_x = c26_s_y;
    c26_eml_realmin(chartInstance);
    c26_l_x = c26_k_x;
    c26_m_x = c26_l_x;
    c26_b_absxk = muDoubleScalarAbs(c26_m_x);
    if (c26_isfinite(chartInstance, c26_b_absxk)) {
      if (c26_b_absxk <= 2.2250738585072014E-308) {
        c26_b_r = 4.94065645841247E-324;
      } else {
        frexp(c26_b_absxk, &c26_d_exponent);
        c26_e_exponent = c26_d_exponent;
        c26_f_exponent = c26_e_exponent;
        c26_f_exponent;
        c26_b_r = ldexp(1.0, c26_f_exponent - 53);
      }
    } else {
      c26_b_r = rtNaN;
    }

    guard7 = false;
    guard8 = false;
    guard9 = false;
    if (c26_r_y < c26_b_r) {
      guard8 = true;
    } else {
      c26_n_x = c26_c_a;
      c26_f_b = muDoubleScalarIsInf(c26_n_x);
      if (c26_f_b) {
        c26_o_x = c26_e_b;
        c26_g_b = muDoubleScalarIsInf(c26_o_x);
        if (c26_g_b) {
          if (c26_c_a > 0.0 == c26_e_b > 0.0) {
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
      c26_b29 = true;
    }

    if (guard7 == true) {
      c26_b29 = false;
    }

    c26_c_p = c26_b29;
    if (c26_c_p) {
      c26_x = c26_angle(chartInstance, c26_a);
      c26_e_y = c26_angle(chartInstance, c26_b);
      c26_d_a = c26_x;
      c26_h_b = c26_e_y;
      c26_p_x = c26_h_b - c26_d_a;
      c26_q_x = c26_p_x;
      c26_t_y = muDoubleScalarAbs(c26_q_x);
      c26_q_A = c26_h_b;
      c26_u_y = c26_rdivide(chartInstance, c26_q_A, 2.0);
      c26_r_x = c26_u_y;
      c26_eml_realmin(chartInstance);
      c26_s_x = c26_r_x;
      c26_t_x = c26_s_x;
      c26_c_absxk = muDoubleScalarAbs(c26_t_x);
      if (c26_isfinite(chartInstance, c26_c_absxk)) {
        if (c26_c_absxk <= 2.2250738585072014E-308) {
          c26_c_r = 4.94065645841247E-324;
        } else {
          frexp(c26_c_absxk, &c26_g_exponent);
          c26_h_exponent = c26_g_exponent;
          c26_i_exponent = c26_h_exponent;
          c26_i_exponent;
          c26_c_r = ldexp(1.0, c26_i_exponent - 53);
        }
      } else {
        c26_c_r = rtNaN;
      }

      guard4 = false;
      guard5 = false;
      guard6 = false;
      if (c26_t_y < c26_c_r) {
        guard5 = true;
      } else {
        c26_u_x = c26_d_a;
        c26_i_b = muDoubleScalarIsInf(c26_u_x);
        if (c26_i_b) {
          c26_v_x = c26_h_b;
          c26_j_b = muDoubleScalarIsInf(c26_v_x);
          if (c26_j_b) {
            if (c26_d_a > 0.0 == c26_h_b > 0.0) {
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
        c26_b30 = true;
      }

      if (guard4 == true) {
        c26_b30 = false;
      }

      c26_d_p = c26_b30;
      if (c26_d_p) {
        c26_v_y = c26_rdivide(chartInstance, 3.1415926535897931, 4.0);
        if (c26_x > c26_v_y) {
          c26_w_y = c26_rdivide(chartInstance, 9.42477796076938, 4.0);
          if (c26_x > c26_w_y) {
            c26_x = -c26_ai;
            c26_e_y = -c26_bi;
          } else {
            c26_x = -c26_ar;
            c26_e_y = -c26_br;
          }
        } else {
          c26_x_y = c26_rdivide(chartInstance, -3.1415926535897931, 4.0);
          if (c26_x > c26_x_y) {
            c26_x = c26_ai;
            c26_e_y = c26_bi;
          } else {
            c26_y_y = c26_rdivide(chartInstance, -9.42477796076938, 4.0);
            if (c26_x > c26_y_y) {
              c26_x = c26_ar;
              c26_e_y = c26_br;
            } else {
              c26_x = -c26_ai;
              c26_e_y = -c26_bi;
            }
          }
        }

        c26_e_a = c26_x;
        c26_k_b = c26_e_y;
        c26_w_x = c26_k_b - c26_e_a;
        c26_x_x = c26_w_x;
        c26_ab_y = muDoubleScalarAbs(c26_x_x);
        c26_r_A = c26_k_b;
        c26_bb_y = c26_rdivide(chartInstance, c26_r_A, 2.0);
        c26_y_x = c26_bb_y;
        c26_eml_realmin(chartInstance);
        c26_ab_x = c26_y_x;
        c26_bb_x = c26_ab_x;
        c26_d_absxk = muDoubleScalarAbs(c26_bb_x);
        if (c26_isfinite(chartInstance, c26_d_absxk)) {
          if (c26_d_absxk <= 2.2250738585072014E-308) {
            c26_d_r = 4.94065645841247E-324;
          } else {
            frexp(c26_d_absxk, &c26_j_exponent);
            c26_k_exponent = c26_j_exponent;
            c26_l_exponent = c26_k_exponent;
            c26_l_exponent;
            c26_d_r = ldexp(1.0, c26_l_exponent - 53);
          }
        } else {
          c26_d_r = rtNaN;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (c26_ab_y < c26_d_r) {
          guard2 = true;
        } else {
          c26_cb_x = c26_e_a;
          c26_l_b = muDoubleScalarIsInf(c26_cb_x);
          if (c26_l_b) {
            c26_db_x = c26_k_b;
            c26_m_b = muDoubleScalarIsInf(c26_db_x);
            if (c26_m_b) {
              if (c26_e_a > 0.0 == c26_k_b > 0.0) {
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
          c26_b31 = true;
        }

        if (guard1 == true) {
          c26_b31 = false;
        }

        c26_e_p = c26_b31;
        if (c26_e_p) {
          c26_x = 0.0;
          c26_e_y = 0.0;
        }
      }
    }
  }

  c26_eb_x = c26_x;
  c26_cb_y = c26_e_y;
  return c26_eb_x > c26_cb_y;
}

static void c26_i_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_sprintf, const char_T *c26_identifier,
  char_T c26_y[14])
{
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_sprintf), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_sprintf);
}

static void c26_j_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  char_T c26_y[14])
{
  char_T c26_cv7[14];
  int32_T c26_i215;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_cv7, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c26_i215 = 0; c26_i215 < 14; c26_i215++) {
    c26_y[c26_i215] = c26_cv7[c26_i215];
  }

  sf_mex_destroy(&c26_u);
}

static const mxArray *c26_j_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(int32_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static int32_T c26_k_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  int32_T c26_y;
  int32_T c26_i216;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_i216, 1, 6, 0U, 0, 0U, 0);
  c26_y = c26_i216;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_sfEvent;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  int32_T c26_y;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_b_sfEvent = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_sfEvent),
    &c26_thisId);
  sf_mex_destroy(&c26_b_sfEvent);
  *(int32_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static uint8_T c26_l_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_hybridSysSim, const char_T *
  c26_identifier)
{
  uint8_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c26_b_is_active_c26_hybridSysSim), &c26_thisId);
  sf_mex_destroy(&c26_b_is_active_c26_hybridSysSim);
  return c26_y;
}

static uint8_T c26_m_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  uint8_T c26_y;
  uint8_T c26_u0;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_u0, 1, 3, 0U, 0, 0U, 0);
  c26_y = c26_u0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_b_eml_xaxpy(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T c26_a, real_T c26_y[4])
{
  real_T c26_b_a;
  real_T c26_c_a;
  int32_T c26_ix;
  int32_T c26_iy;
  int32_T c26_k;
  int32_T c26_d_a;
  int32_T c26_c;
  int32_T c26_e_a;
  int32_T c26_b_c;
  int32_T c26_f_a;
  int32_T c26_c_c;
  int32_T c26_g_a;
  int32_T c26_h_a;
  c26_b_a = c26_a;
  c26_c_a = c26_b_a;
  if (c26_c_a == 0.0) {
  } else {
    c26_ix = 0;
    c26_iy = 2;
    c26_eml_switch_helper(chartInstance);
    for (c26_k = 0; c26_k < 2; c26_k++) {
      c26_d_a = c26_iy;
      c26_c = c26_d_a;
      c26_e_a = c26_iy;
      c26_b_c = c26_e_a;
      c26_f_a = c26_ix;
      c26_c_c = c26_f_a;
      c26_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c26_c + 1)), 1, 4, 1, 0) - 1] =
        c26_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c26_b_c + 1)), 1, 4, 1, 0) - 1] + c26_c_a *
        c26_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c26_c_c + 1)), 1, 4, 1, 0) - 1];
      c26_g_a = c26_ix + 1;
      c26_ix = c26_g_a;
      c26_h_a = c26_iy + 1;
      c26_iy = c26_h_a;
    }
  }
}

static void c26_c_sqrt(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  *c26_x)
{
  if (*c26_x < 0.0) {
    c26_c_eml_error(chartInstance);
  }

  *c26_x = muDoubleScalarSqrt(*c26_x);
}

static void c26_b_eml_xrotg(SFc26_hybridSysSimInstanceStruct *chartInstance,
  real_T *c26_a, real_T *c26_b, real_T *c26_c, real_T *c26_s)
{
  real_T c26_b_a;
  real_T c26_b_b;
  real_T c26_c_b;
  real_T c26_c_a;
  real_T c26_d_a;
  real_T c26_d_b;
  real_T c26_e_b;
  real_T c26_e_a;
  real_T c26_b_c;
  real_T c26_b_s;
  double * c26_a_t;
  double * c26_b_t;
  double * c26_c_t;
  double * c26_s_t;
  real_T c26_c_c;
  real_T c26_c_s;
  (void)chartInstance;
  c26_b_a = *c26_a;
  c26_b_b = *c26_b;
  c26_c_b = c26_b_b;
  c26_c_a = c26_b_a;
  c26_d_a = c26_c_a;
  c26_d_b = c26_c_b;
  c26_e_b = c26_d_b;
  c26_e_a = c26_d_a;
  c26_b_c = 0.0;
  c26_b_s = 0.0;
  c26_a_t = (double *)(&c26_e_a);
  c26_b_t = (double *)(&c26_e_b);
  c26_c_t = (double *)(&c26_b_c);
  c26_s_t = (double *)(&c26_b_s);
  drotg(c26_a_t, c26_b_t, c26_c_t, c26_s_t);
  c26_c_a = c26_e_a;
  c26_c_b = c26_e_b;
  c26_c_c = c26_b_c;
  c26_c_s = c26_b_s;
  *c26_a = c26_c_a;
  *c26_b = c26_c_b;
  *c26_c = c26_c_c;
  *c26_s = c26_c_s;
}

static void c26_b_eml_matlab_zlascl(SFc26_hybridSysSimInstanceStruct
  *chartInstance, real_T c26_cfrom, real_T c26_cto, creal_T c26_A[4])
{
  real_T c26_cfromc;
  real_T c26_ctoc;
  boolean_T c26_notdone;
  real_T c26_cfrom1;
  real_T c26_cto1;
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_y;
  real_T c26_c_x;
  real_T c26_d_x;
  real_T c26_b_y;
  real_T c26_mul;
  real_T c26_e_x;
  real_T c26_f_x;
  real_T c26_c_y;
  real_T c26_g_x;
  real_T c26_h_x;
  real_T c26_d_y;
  real_T c26_a;
  int32_T c26_i217;
  boolean_T guard1 = false;
  c26_eml_realmin(chartInstance);
  c26_eps(chartInstance);
  c26_cfromc = c26_cfrom;
  c26_ctoc = c26_cto;
  c26_notdone = true;
  while (c26_notdone) {
    c26_cfrom1 = c26_cfromc * 2.0041683600089728E-292;
    c26_cto1 = c26_ctoc / 4.9896007738368E+291;
    c26_x = c26_cfrom1;
    c26_b_x = c26_x;
    c26_y = muDoubleScalarAbs(c26_b_x);
    c26_c_x = c26_ctoc;
    c26_d_x = c26_c_x;
    c26_b_y = muDoubleScalarAbs(c26_d_x);
    guard1 = false;
    if (c26_y > c26_b_y) {
      if (c26_ctoc != 0.0) {
        c26_mul = 2.0041683600089728E-292;
        c26_notdone = true;
        c26_cfromc = c26_cfrom1;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      c26_e_x = c26_cto1;
      c26_f_x = c26_e_x;
      c26_c_y = muDoubleScalarAbs(c26_f_x);
      c26_g_x = c26_cfromc;
      c26_h_x = c26_g_x;
      c26_d_y = muDoubleScalarAbs(c26_h_x);
      if (c26_c_y > c26_d_y) {
        c26_mul = 4.9896007738368E+291;
        c26_notdone = true;
        c26_ctoc = c26_cto1;
      } else {
        c26_mul = c26_ctoc / c26_cfromc;
        c26_notdone = false;
      }
    }

    c26_a = c26_mul;
    for (c26_i217 = 0; c26_i217 < 4; c26_i217++) {
      c26_A[c26_i217].re *= c26_a;
      c26_A[c26_i217].im *= c26_a;
    }
  }
}

static void c26_c_eml_matlab_zggbal(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[4], int32_T *c26_ilo, int32_T *c26_ihi, int32_T
  c26_rscale[2])
{
  int32_T c26_i218;
  int32_T c26_b_ihi;
  int32_T c26_i;
  int32_T c26_j;
  boolean_T c26_found;
  int32_T c26_ii;
  real_T c26_nzcount;
  int32_T c26_c_ihi;
  int32_T c26_b;
  int32_T c26_b_b;
  boolean_T c26_overflow;
  int32_T c26_jj;
  int32_T c26_b_jj;
  static creal_T c26_dc20 = { 0.0, 0.0 };

  boolean_T c26_b_A;
  int32_T c26_a;
  int32_T c26_b_a;
  int32_T c26_b_i;
  int32_T c26_b_j;
  boolean_T c26_b_found;
  int32_T c26_b_ilo;
  int32_T c26_d_ihi;
  int32_T c26_c_i;
  int32_T c26_c_j;
  boolean_T c26_c_found;
  int32_T c26_c_ilo;
  int32_T c26_e_ihi;
  int32_T c26_c_a;
  int32_T c26_c_b;
  int32_T c26_d_a;
  int32_T c26_d_b;
  boolean_T c26_b_overflow;
  int32_T c26_c_jj;
  int32_T c26_d_jj;
  real_T c26_b_nzcount;
  int32_T c26_d_ilo;
  int32_T c26_f_ihi;
  int32_T c26_e_a;
  int32_T c26_e_b;
  int32_T c26_f_a;
  int32_T c26_f_b;
  boolean_T c26_c_overflow;
  int32_T c26_b_ii;
  int32_T c26_c_ii;
  boolean_T c26_c_A;
  int32_T c26_m;
  int32_T c26_d_i;
  int32_T c26_d_j;
  int32_T c26_e_ilo;
  int32_T c26_g_ihi;
  int32_T c26_f_ilo;
  int32_T c26_g_a;
  int32_T c26_h_a;
  boolean_T c26_d_overflow;
  int32_T c26_k;
  int32_T c26_b_k;
  creal_T c26_atmp;
  int32_T c26_h_ihi;
  int32_T c26_g_b;
  int32_T c26_h_b;
  boolean_T c26_e_overflow;
  int32_T c26_c_k;
  int32_T c26_i_a;
  int32_T c26_j_a;
  int32_T c26_b_m;
  int32_T c26_e_i;
  int32_T c26_e_j;
  int32_T c26_i_ihi;
  int32_T c26_d_k;
  int32_T c26_e_k;
  int32_T c26_j_ihi;
  int32_T c26_i_b;
  int32_T c26_j_b;
  boolean_T c26_f_overflow;
  int32_T c26_f_k;
  int32_T c26_k_a;
  int32_T c26_l_a;
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
  for (c26_i218 = 0; c26_i218 < 2; c26_i218++) {
    c26_rscale[c26_i218] = 0;
  }

  *c26_ilo = 1;
  *c26_ihi = 2;
  do {
    exitg2 = 0;
    c26_b_ihi = *c26_ihi;
    c26_i = 0;
    c26_j = 0;
    c26_found = false;
    c26_ii = c26_b_ihi;
    exitg5 = false;
    while ((exitg5 == false) && (c26_ii > 0)) {
      c26_nzcount = 0.0;
      c26_i = c26_ii;
      c26_j = c26_b_ihi;
      c26_c_ihi = c26_b_ihi;
      c26_b = c26_c_ihi;
      c26_b_b = c26_b;
      if (1 > c26_b_b) {
        c26_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_overflow = (c26_b_b > 2147483646);
      }

      if (c26_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_overflow);
      }

      c26_jj = 1;
      exitg6 = false;
      while ((exitg6 == false) && (c26_jj <= c26_c_ihi)) {
        c26_b_jj = c26_jj;
        c26_b_A = ((c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_ii), 1, 2, 1, 0) +
                           ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_jj), 1, 2, 2, 0) - 1) << 1)) - 1]
                    .re != c26_dc20.re) || (c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ii), 1, 2, 1, 0) +
          ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_jj), 1, 2, 2, 0) - 1) << 1)) - 1].im != c26_dc20.im));
        guard3 = false;
        guard4 = false;
        if (c26_b_A) {
          guard4 = true;
        } else if (c26_ii == c26_b_jj) {
          guard4 = true;
        } else {
          guard3 = true;
        }

        if (guard4 == true) {
          if (c26_nzcount == 0.0) {
            c26_j = c26_b_jj;
            c26_nzcount = 1.0;
            guard3 = true;
          } else {
            c26_nzcount = 2.0;
            exitg6 = true;
          }
        }

        if (guard3 == true) {
          c26_jj++;
        }
      }

      if (c26_nzcount < 2.0) {
        c26_found = true;
        exitg5 = true;
      } else {
        c26_a = c26_ii;
        c26_b_a = c26_a - 1;
        c26_ii = c26_b_a;
      }
    }

    c26_b_i = c26_i;
    c26_b_j = c26_j;
    c26_b_found = c26_found;
    if (!c26_b_found) {
      exitg2 = 2;
    } else {
      c26_b_m = *c26_ihi;
      c26_e_i = c26_b_i;
      c26_e_j = c26_b_j;
      c26_i_ihi = *c26_ihi;
      if (c26_e_i != c26_b_m) {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        for (c26_d_k = 1; c26_d_k < 3; c26_d_k++) {
          c26_e_k = c26_d_k;
          c26_atmp.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_i), 1, 2, 1, 0) +
                               ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2, 2, 0) - 1) << 1)) - 1]
            .re;
          c26_atmp.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_i), 1, 2, 1, 0) +
                               ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2, 2, 0) - 1) << 1)) - 1]
            .im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2,
                    2, 0) - 1) << 1)) - 1].re = c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_b_m), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2, 2, 0) -
                1) << 1)) - 1].re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2,
                    2, 0) - 1) << 1)) - 1].im = c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_b_m), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2, 2, 0) -
                1) << 1)) - 1].im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_m), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2,
                    2, 0) - 1) << 1)) - 1].re = c26_atmp.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_m), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2,
                    2, 0) - 1) << 1)) - 1].im = c26_atmp.im;
        }
      }

      if (c26_e_j != c26_b_m) {
        c26_j_ihi = c26_i_ihi;
        c26_i_b = c26_j_ihi;
        c26_j_b = c26_i_b;
        if (1 > c26_j_b) {
          c26_f_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_f_overflow = (c26_j_b > 2147483646);
        }

        if (c26_f_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_f_overflow);
        }

        for (c26_f_k = 1; c26_f_k <= c26_j_ihi; c26_f_k++) {
          c26_e_k = c26_f_k;
          c26_atmp.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2, 1, 0) +
                               ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_j), 1, 2, 2, 0) - 1) << 1)) - 1]
            .re;
          c26_atmp.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 2, 1, 0) +
                               ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_j), 1, 2, 2, 0) - 1) << 1)) - 1]
            .im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_j), 1, 2,
                    2, 0) - 1) << 1)) - 1].re = c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_m), 1, 2, 2, 0) -
                1) << 1)) - 1].re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_e_j), 1, 2,
                    2, 0) - 1) << 1)) - 1].im = c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                 (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_m), 1, 2, 2, 0) -
                1) << 1)) - 1].im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_m), 1, 2,
                    2, 0) - 1) << 1)) - 1].re = c26_atmp.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_m), 1, 2,
                    2, 0) - 1) << 1)) - 1].im = c26_atmp.im;
        }
      }

      c26_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)*c26_ihi), 1, 2, 1, 0) - 1] = c26_b_j;
      c26_k_a = *c26_ihi;
      c26_l_a = c26_k_a - 1;
      *c26_ihi = c26_l_a;
      if (*c26_ihi == 1) {
        c26_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)*c26_ihi), 1, 2, 1, 0) - 1] = *c26_ihi;
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
  } else {
    do {
      exitg1 = 0;
      c26_b_ilo = *c26_ilo;
      c26_d_ihi = *c26_ihi;
      c26_c_i = 0;
      c26_c_j = 0;
      c26_c_found = false;
      c26_c_ilo = c26_b_ilo;
      c26_e_ihi = c26_d_ihi;
      c26_c_a = c26_c_ilo;
      c26_c_b = c26_e_ihi;
      c26_d_a = c26_c_a;
      c26_d_b = c26_c_b;
      if (c26_d_a > c26_d_b) {
        c26_b_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_b_overflow = (c26_d_b > 2147483646);
      }

      if (c26_b_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
      }

      c26_c_jj = c26_c_ilo;
      exitg3 = false;
      while ((exitg3 == false) && (c26_c_jj <= c26_e_ihi)) {
        c26_d_jj = c26_c_jj;
        c26_b_nzcount = 0.0;
        c26_c_i = c26_d_ihi;
        c26_c_j = c26_d_jj;
        c26_d_ilo = c26_b_ilo;
        c26_f_ihi = c26_d_ihi;
        c26_e_a = c26_d_ilo;
        c26_e_b = c26_f_ihi;
        c26_f_a = c26_e_a;
        c26_f_b = c26_e_b;
        if (c26_f_a > c26_f_b) {
          c26_c_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_c_overflow = (c26_f_b > 2147483646);
        }

        if (c26_c_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_c_overflow);
        }

        c26_b_ii = c26_d_ilo;
        exitg4 = false;
        while ((exitg4 == false) && (c26_b_ii <= c26_f_ihi)) {
          c26_c_ii = c26_b_ii;
          c26_c_A = ((c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_c_ii), 1, 2, 1, 0) +
                             ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_d_jj), 1, 2, 2, 0) - 1) << 1)) -
                      1].re != c26_dc20.re) || (c26_A
                      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_c_ii), 1, 2, 1, 0) +
                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_d_jj), 1, 2, 2, 0) - 1) << 1)) -
                      1].im != c26_dc20.im));
          guard1 = false;
          guard2 = false;
          if (c26_c_A) {
            guard2 = true;
          } else if (c26_c_ii == c26_d_jj) {
            guard2 = true;
          } else {
            guard1 = true;
          }

          if (guard2 == true) {
            if (c26_b_nzcount == 0.0) {
              c26_c_i = c26_c_ii;
              c26_b_nzcount = 1.0;
              guard1 = true;
            } else {
              c26_b_nzcount = 2.0;
              exitg4 = true;
            }
          }

          if (guard1 == true) {
            c26_b_ii++;
          }
        }

        if (c26_b_nzcount < 2.0) {
          c26_c_found = true;
          exitg3 = true;
        } else {
          c26_c_jj++;
        }
      }

      c26_b_i = c26_c_i;
      c26_b_j = c26_c_j;
      c26_b_found = c26_c_found;
      if (!c26_b_found) {
        exitg1 = 1;
      } else {
        c26_m = *c26_ilo;
        c26_d_i = c26_b_i;
        c26_d_j = c26_b_j;
        c26_e_ilo = *c26_ilo;
        c26_g_ihi = *c26_ihi;
        if (c26_d_i != c26_m) {
          c26_f_ilo = c26_e_ilo;
          c26_g_a = c26_f_ilo;
          c26_h_a = c26_g_a;
          if (c26_h_a > 2) {
            c26_d_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_d_overflow = false;
          }

          if (c26_d_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_d_overflow);
          }

          for (c26_k = c26_f_ilo; c26_k < 3; c26_k++) {
            c26_b_k = c26_k;
            c26_atmp.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                                 ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c26_atmp.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 2, 1, 0) +
                                 ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_d_i), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_k), 1, 2, 2, 0) - 1) << 1)) - 1].re =
              c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_m), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 2, 2, 0) - 1)
                      << 1)) - 1].re;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_d_i), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_k), 1, 2, 2, 0) - 1) << 1)) - 1].im =
              c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_m), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 2, 2, 0) - 1)
                      << 1)) - 1].im;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_m), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_k), 1, 2, 2, 0) - 1) << 1)) - 1].re =
              c26_atmp.re;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_m), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_k), 1, 2, 2, 0) - 1) << 1)) - 1].im =
              c26_atmp.im;
          }
        }

        if (c26_d_j != c26_m) {
          c26_h_ihi = c26_g_ihi;
          c26_g_b = c26_h_ihi;
          c26_h_b = c26_g_b;
          if (1 > c26_h_b) {
            c26_e_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_e_overflow = (c26_h_b > 2147483646);
          }

          if (c26_e_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_e_overflow);
          }

          for (c26_c_k = 1; c26_c_k <= c26_h_ihi; c26_c_k++) {
            c26_b_k = c26_c_k;
            c26_atmp.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 2, 1, 0) +
                                 ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0) - 1) << 1)) -
              1].re;
            c26_atmp.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 2, 1, 0) +
                                 ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 2, 2, 0) - 1) << 1)) -
              1].im;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_b_k), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_d_j), 1, 2, 2, 0) - 1) << 1)) - 1].re =
              c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_k), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_m), 1, 2, 2, 0) - 1) <<
                      1)) - 1].re;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_b_k), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_d_j), 1, 2, 2, 0) - 1) << 1)) - 1].im =
              c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_b_k), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                        _SFD_INTEGER_CHECK("", (real_T)c26_m), 1, 2, 2, 0) - 1) <<
                      1)) - 1].im;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_b_k), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_m), 1, 2, 2, 0) - 1) << 1)) - 1].re =
              c26_atmp.re;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_b_k), 1, 2, 1, 0) +
                   ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c26_m), 1, 2, 2, 0) - 1) << 1)) - 1].im =
              c26_atmp.im;
          }
        }

        c26_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)*c26_ilo), 1, 2, 1, 0) - 1] = c26_b_j;
        c26_i_a = *c26_ilo;
        c26_j_a = c26_i_a + 1;
        *c26_ilo = c26_j_a;
        if (*c26_ilo == *c26_ihi) {
          c26_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", (real_T)*c26_ilo), 1, 2, 1, 0) - 1] = *c26_ilo;
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void c26_d_sqrt(SFc26_hybridSysSimInstanceStruct *chartInstance, creal_T *
  c26_x)
{
  real_T c26_yr;
  real_T c26_yi;
  boolean_T c26_b32;
  boolean_T c26_b33;
  boolean_T c26_b;
  real_T c26_b_x;
  boolean_T c26_b_b;
  real_T c26_c_x;
  boolean_T c26_c_b;
  real_T c26_absxr;
  real_T c26_absxi;
  real_T c26_y;
  real_T c26_b_y;
  real_T c26_d_x;
  real_T c26_c_y;
  real_T c26_x1;
  real_T c26_x2;
  real_T c26_a;
  real_T c26_d_b;
  real_T c26_absxd2;
  real_T c26_e_x;
  real_T c26_d_y;
  real_T c26_b_x1;
  real_T c26_b_x2;
  real_T c26_b_a;
  real_T c26_e_b;
  real_T c26_z;
  real_T c26_d19;
  real_T c26_d20;
  boolean_T guard1 = false;
  if (c26_x->im == 0.0) {
    if (c26_x->re < 0.0) {
      c26_yr = 0.0;
      c26_yi = muDoubleScalarSqrt(muDoubleScalarAbs(c26_x->re));
    } else {
      c26_yr = muDoubleScalarSqrt(c26_x->re);
      c26_yi = 0.0;
    }
  } else if (c26_x->re == 0.0) {
    if (c26_x->im < 0.0) {
      c26_yr = muDoubleScalarSqrt(c26_rdivide(chartInstance, -c26_x->im, 2.0));
      c26_yi = -c26_yr;
    } else {
      c26_yr = muDoubleScalarSqrt(c26_rdivide(chartInstance, c26_x->im, 2.0));
      c26_yi = c26_yr;
    }
  } else {
    c26_b32 = muDoubleScalarIsNaN(c26_x->re);
    c26_b33 = muDoubleScalarIsNaN(c26_x->im);
    c26_b = (c26_b32 || c26_b33);
    if (c26_b) {
      c26_yr = rtNaN;
      c26_yi = rtNaN;
    } else {
      c26_b_x = c26_x->im;
      c26_b_b = muDoubleScalarIsInf(c26_b_x);
      if (c26_b_b) {
        c26_yr = rtInf;
        c26_yi = c26_x->im;
      } else {
        c26_c_x = c26_x->re;
        c26_c_b = muDoubleScalarIsInf(c26_c_x);
        if (c26_c_b) {
          if (c26_x->re < 0.0) {
            c26_yr = 0.0;
            c26_yi = rtInf;
          } else {
            c26_yr = rtInf;
            c26_yi = 0.0;
          }
        } else {
          c26_absxr = muDoubleScalarAbs(c26_x->re);
          c26_absxi = muDoubleScalarAbs(c26_x->im);
          c26_realmax(chartInstance);
          c26_y = c26_rdivide(chartInstance, 1.7976931348623157E+308, 4.0);
          guard1 = false;
          if (c26_absxr > c26_y) {
            guard1 = true;
          } else {
            c26_realmax(chartInstance);
            c26_b_y = c26_rdivide(chartInstance, 1.7976931348623157E+308, 4.0);
            if (c26_absxi > c26_b_y) {
              guard1 = true;
            } else {
              c26_e_x = c26_absxr;
              c26_d_y = c26_absxi;
              c26_eml_scalar_eg(chartInstance);
              c26_b_x1 = c26_e_x;
              c26_b_x2 = c26_d_y;
              c26_b_a = c26_b_x1;
              c26_e_b = c26_b_x2;
              c26_z = muDoubleScalarHypot(c26_b_a, c26_e_b);
              c26_yr = muDoubleScalarSqrt((c26_z + c26_absxr) * 0.5);
            }
          }

          if (guard1 == true) {
            c26_absxr *= 0.5;
            c26_absxi *= 0.5;
            c26_d_x = c26_absxr;
            c26_c_y = c26_absxi;
            c26_eml_scalar_eg(chartInstance);
            c26_x1 = c26_d_x;
            c26_x2 = c26_c_y;
            c26_a = c26_x1;
            c26_d_b = c26_x2;
            c26_absxd2 = muDoubleScalarHypot(c26_a, c26_d_b);
            if (c26_absxd2 > c26_absxr) {
              c26_yr = muDoubleScalarSqrt(c26_absxd2) * muDoubleScalarSqrt(1.0 +
                c26_rdivide(chartInstance, c26_absxr, c26_absxd2));
            } else {
              c26_yr = muDoubleScalarSqrt(c26_absxd2) * 1.4142135623730951;
            }
          }

          if (c26_x->re > 0.0) {
            c26_d19 = c26_rdivide(chartInstance, c26_x->im, c26_yr);
            c26_yi = 0.5 * c26_d19;
          } else {
            if (c26_x->im < 0.0) {
              c26_yi = -c26_yr;
            } else {
              c26_yi = c26_yr;
            }

            c26_d20 = c26_rdivide(chartInstance, c26_x->im, c26_yi);
            c26_yr = 0.5 * c26_d20;
          }
        }
      }
    }
  }

  c26_x->re = c26_yr;
  c26_x->im = c26_yi;
}

static void c26_d_eml_matlab_zggbal(SFc26_hybridSysSimInstanceStruct
  *chartInstance, creal_T c26_A[100], int32_T *c26_ilo, int32_T *c26_ihi,
  int32_T c26_rscale[10])
{
  int32_T c26_i219;
  int32_T c26_b_ihi;
  int32_T c26_i;
  int32_T c26_j;
  boolean_T c26_found;
  int32_T c26_ii;
  real_T c26_nzcount;
  int32_T c26_c_ihi;
  int32_T c26_b;
  int32_T c26_b_b;
  boolean_T c26_overflow;
  int32_T c26_jj;
  int32_T c26_b_jj;
  static creal_T c26_dc21 = { 0.0, 0.0 };

  boolean_T c26_b_A;
  int32_T c26_a;
  int32_T c26_b_a;
  int32_T c26_b_i;
  int32_T c26_b_j;
  boolean_T c26_b_found;
  int32_T c26_b_ilo;
  int32_T c26_d_ihi;
  int32_T c26_c_i;
  int32_T c26_c_j;
  boolean_T c26_c_found;
  int32_T c26_c_ilo;
  int32_T c26_e_ihi;
  int32_T c26_c_a;
  int32_T c26_c_b;
  int32_T c26_d_a;
  int32_T c26_d_b;
  boolean_T c26_b_overflow;
  int32_T c26_c_jj;
  int32_T c26_d_jj;
  real_T c26_b_nzcount;
  int32_T c26_d_ilo;
  int32_T c26_f_ihi;
  int32_T c26_e_a;
  int32_T c26_e_b;
  int32_T c26_f_a;
  int32_T c26_f_b;
  boolean_T c26_c_overflow;
  int32_T c26_b_ii;
  int32_T c26_c_ii;
  boolean_T c26_c_A;
  int32_T c26_m;
  int32_T c26_d_i;
  int32_T c26_d_j;
  int32_T c26_e_ilo;
  int32_T c26_g_ihi;
  int32_T c26_f_ilo;
  int32_T c26_g_a;
  int32_T c26_h_a;
  boolean_T c26_d_overflow;
  int32_T c26_k;
  int32_T c26_b_k;
  creal_T c26_atmp;
  int32_T c26_h_ihi;
  int32_T c26_g_b;
  int32_T c26_h_b;
  boolean_T c26_e_overflow;
  int32_T c26_c_k;
  int32_T c26_i_a;
  int32_T c26_j_a;
  int32_T c26_b_m;
  int32_T c26_e_i;
  int32_T c26_e_j;
  int32_T c26_i_ihi;
  int32_T c26_d_k;
  int32_T c26_e_k;
  int32_T c26_j_ihi;
  int32_T c26_i_b;
  int32_T c26_j_b;
  boolean_T c26_f_overflow;
  int32_T c26_f_k;
  int32_T c26_k_a;
  int32_T c26_l_a;
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
  for (c26_i219 = 0; c26_i219 < 10; c26_i219++) {
    c26_rscale[c26_i219] = 0;
  }

  *c26_ilo = 1;
  *c26_ihi = 10;
  do {
    exitg2 = 0;
    c26_b_ihi = *c26_ihi;
    c26_i = 0;
    c26_j = 0;
    c26_found = false;
    c26_ii = c26_b_ihi;
    exitg5 = false;
    while ((exitg5 == false) && (c26_ii > 0)) {
      c26_nzcount = 0.0;
      c26_i = c26_ii;
      c26_j = c26_b_ihi;
      c26_c_ihi = c26_b_ihi;
      c26_b = c26_c_ihi;
      c26_b_b = c26_b;
      if (1 > c26_b_b) {
        c26_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_overflow = (c26_b_b > 2147483646);
      }

      if (c26_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_overflow);
      }

      c26_jj = 1;
      exitg6 = false;
      while ((exitg6 == false) && (c26_jj <= c26_c_ihi)) {
        c26_b_jj = c26_jj;
        c26_b_A = ((c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_ii), 1, 10, 1, 0) + 10 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_b_jj), 1, 10, 2, 0) - 1)) - 1].re
                    != c26_dc21.re) || (c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_ii), 1, 10, 1, 0) + 10 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c26_b_jj), 1, 10, 2, 0) - 1)) - 1].im != c26_dc21.im));
        guard3 = false;
        guard4 = false;
        if (c26_b_A) {
          guard4 = true;
        } else if (c26_ii == c26_b_jj) {
          guard4 = true;
        } else {
          guard3 = true;
        }

        if (guard4 == true) {
          if (c26_nzcount == 0.0) {
            c26_j = c26_b_jj;
            c26_nzcount = 1.0;
            guard3 = true;
          } else {
            c26_nzcount = 2.0;
            exitg6 = true;
          }
        }

        if (guard3 == true) {
          c26_jj++;
        }
      }

      if (c26_nzcount < 2.0) {
        c26_found = true;
        exitg5 = true;
      } else {
        c26_a = c26_ii;
        c26_b_a = c26_a - 1;
        c26_ii = c26_b_a;
      }
    }

    c26_b_i = c26_i;
    c26_b_j = c26_j;
    c26_b_found = c26_found;
    if (!c26_b_found) {
      exitg2 = 2;
    } else {
      c26_b_m = *c26_ihi;
      c26_e_i = c26_b_i;
      c26_e_j = c26_b_j;
      c26_i_ihi = *c26_ihi;
      if (c26_e_i != c26_b_m) {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        for (c26_d_k = 1; c26_d_k < 11; c26_d_k++) {
          c26_e_k = c26_d_k;
          c26_atmp.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_i), 1, 10, 1, 0) + 10 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 10, 2, 0) - 1)) - 1].re;
          c26_atmp.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_i), 1, 10, 1, 0) + 10 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 10, 2, 0) - 1)) - 1].im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_e_k), 1, 10, 2, 0) - 1)) - 1].re = c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_b_m), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_e_k), 1, 10, 2, 0) - 1)) - 1].re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_e_k), 1, 10, 2, 0) - 1)) - 1].im = c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_b_m), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_e_k), 1, 10, 2, 0) - 1)) - 1].im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_m), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_e_k), 1, 10, 2, 0) - 1)) - 1].re = c26_atmp.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_m), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_e_k), 1, 10, 2, 0) - 1)) - 1].im = c26_atmp.im;
        }
      }

      if (c26_e_j != c26_b_m) {
        c26_j_ihi = c26_i_ihi;
        c26_i_b = c26_j_ihi;
        c26_j_b = c26_i_b;
        if (1 > c26_j_b) {
          c26_f_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_f_overflow = (c26_j_b > 2147483646);
        }

        if (c26_f_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_f_overflow);
        }

        for (c26_f_k = 1; c26_f_k <= c26_j_ihi; c26_f_k++) {
          c26_e_k = c26_f_k;
          c26_atmp.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 10, 1, 0) + 10 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_j), 1, 10, 2, 0) - 1)) - 1].re;
          c26_atmp.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_k), 1, 10, 1, 0) + 10 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_e_j), 1, 10, 2, 0) - 1)) - 1].im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_k), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_e_j), 1, 10, 2, 0) - 1)) - 1].re = c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_e_k), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_b_m), 1, 10, 2, 0) - 1)) - 1].re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_k), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_e_j), 1, 10, 2, 0) - 1)) - 1].im = c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_e_k), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_b_m), 1, 10, 2, 0) - 1)) - 1].im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_k), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_b_m), 1, 10, 2, 0) - 1)) - 1].re = c26_atmp.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_e_k), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_b_m), 1, 10, 2, 0) - 1)) - 1].im = c26_atmp.im;
        }
      }

      c26_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)*c26_ihi), 1, 10, 1, 0) - 1] = c26_b_j;
      c26_k_a = *c26_ihi;
      c26_l_a = c26_k_a - 1;
      *c26_ihi = c26_l_a;
      if (*c26_ihi == 1) {
        c26_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)*c26_ihi), 1, 10, 1, 0) - 1] = *c26_ihi;
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
  } else {
    do {
      exitg1 = 0;
      c26_b_ilo = *c26_ilo;
      c26_d_ihi = *c26_ihi;
      c26_c_i = 0;
      c26_c_j = 0;
      c26_c_found = false;
      c26_c_ilo = c26_b_ilo;
      c26_e_ihi = c26_d_ihi;
      c26_c_a = c26_c_ilo;
      c26_c_b = c26_e_ihi;
      c26_d_a = c26_c_a;
      c26_d_b = c26_c_b;
      if (c26_d_a > c26_d_b) {
        c26_b_overflow = false;
      } else {
        c26_eml_switch_helper(chartInstance);
        c26_eml_switch_helper(chartInstance);
        c26_b_overflow = (c26_d_b > 2147483646);
      }

      if (c26_b_overflow) {
        c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
      }

      c26_c_jj = c26_c_ilo;
      exitg3 = false;
      while ((exitg3 == false) && (c26_c_jj <= c26_e_ihi)) {
        c26_d_jj = c26_c_jj;
        c26_b_nzcount = 0.0;
        c26_c_i = c26_d_ihi;
        c26_c_j = c26_d_jj;
        c26_d_ilo = c26_b_ilo;
        c26_f_ihi = c26_d_ihi;
        c26_e_a = c26_d_ilo;
        c26_e_b = c26_f_ihi;
        c26_f_a = c26_e_a;
        c26_f_b = c26_e_b;
        if (c26_f_a > c26_f_b) {
          c26_c_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_c_overflow = (c26_f_b > 2147483646);
        }

        if (c26_c_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_c_overflow);
        }

        c26_b_ii = c26_d_ilo;
        exitg4 = false;
        while ((exitg4 == false) && (c26_b_ii <= c26_f_ihi)) {
          c26_c_ii = c26_b_ii;
          c26_c_A = ((c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_c_ii), 1, 10, 1, 0) + 10 *
                             (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_d_jj), 1, 10, 2, 0) - 1)) - 1].re
                      != c26_dc21.re) || (c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
                        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_c_ii), 1, 10,
            1, 0) + 10 * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_d_jj), 1, 10, 2, 0) - 1)) - 1].im
                      != c26_dc21.im));
          guard1 = false;
          guard2 = false;
          if (c26_c_A) {
            guard2 = true;
          } else if (c26_c_ii == c26_d_jj) {
            guard2 = true;
          } else {
            guard1 = true;
          }

          if (guard2 == true) {
            if (c26_b_nzcount == 0.0) {
              c26_c_i = c26_c_ii;
              c26_b_nzcount = 1.0;
              guard1 = true;
            } else {
              c26_b_nzcount = 2.0;
              exitg4 = true;
            }
          }

          if (guard1 == true) {
            c26_b_ii++;
          }
        }

        if (c26_b_nzcount < 2.0) {
          c26_c_found = true;
          exitg3 = true;
        } else {
          c26_c_jj++;
        }
      }

      c26_b_i = c26_c_i;
      c26_b_j = c26_c_j;
      c26_b_found = c26_c_found;
      if (!c26_b_found) {
        exitg1 = 1;
      } else {
        c26_m = *c26_ilo;
        c26_d_i = c26_b_i;
        c26_d_j = c26_b_j;
        c26_e_ilo = *c26_ilo;
        c26_g_ihi = *c26_ihi;
        if (c26_d_i != c26_m) {
          c26_f_ilo = c26_e_ilo;
          c26_g_a = c26_f_ilo;
          c26_h_a = c26_g_a;
          if (c26_h_a > 10) {
            c26_d_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_d_overflow = false;
          }

          if (c26_d_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_d_overflow);
          }

          for (c26_k = c26_f_ilo; c26_k < 11; c26_k++) {
            c26_b_k = c26_k;
            c26_atmp.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 10, 2, 0) - 1)) - 1].
              re;
            c26_atmp.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 10, 2, 0) - 1)) - 1].
              im;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c26_b_k), 1, 10, 2, 0) - 1)) - 1].re = c26_A
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c26_m), 1, 10, 1, 0) + 10 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_k), 1, 10, 2, 0) - 1)) - 1].re;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_d_i), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c26_b_k), 1, 10, 2, 0) - 1)) - 1].im = c26_A
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c26_m), 1, 10, 1, 0) + 10 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_k), 1, 10, 2, 0) - 1)) - 1].im;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_m), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c26_b_k), 1, 10, 2, 0) - 1)) - 1].re =
              c26_atmp.re;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_m), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c26_b_k), 1, 10, 2, 0) - 1)) - 1].im =
              c26_atmp.im;
          }
        }

        if (c26_d_j != c26_m) {
          c26_h_ihi = c26_g_ihi;
          c26_g_b = c26_h_ihi;
          c26_h_b = c26_g_b;
          if (1 > c26_h_b) {
            c26_e_overflow = false;
          } else {
            c26_eml_switch_helper(chartInstance);
            c26_eml_switch_helper(chartInstance);
            c26_e_overflow = (c26_h_b > 2147483646);
          }

          if (c26_e_overflow) {
            c26_check_forloop_overflow_error(chartInstance, c26_e_overflow);
          }

          for (c26_c_k = 1; c26_c_k <= c26_h_ihi; c26_c_k++) {
            c26_b_k = c26_c_k;
            c26_atmp.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 10, 1, 0) + 10 *
                                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2, 0) - 1)) - 1].
              re;
            c26_atmp.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_b_k), 1, 10, 1, 0) + 10 *
                                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c26_d_j), 1, 10, 2, 0) - 1)) - 1].
              im;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_b_k), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c26_d_j), 1, 10, 2, 0) - 1)) - 1].re = c26_A
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c26_b_k), 1, 10, 1, 0) + 10 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_m), 1, 10, 2, 0) - 1)) - 1].re;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_b_k), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c26_d_j), 1, 10, 2, 0) - 1)) - 1].im = c26_A
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c26_b_k), 1, 10, 1, 0) + 10 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_m), 1, 10, 2, 0) - 1)) - 1].im;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_b_k), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c26_m), 1, 10, 2, 0) - 1)) - 1].re =
              c26_atmp.re;
            c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                     "", (real_T)c26_b_k), 1, 10, 1, 0) + 10 *
                   (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                      "", (real_T)c26_m), 1, 10, 2, 0) - 1)) - 1].im =
              c26_atmp.im;
          }
        }

        c26_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)*c26_ilo), 1, 10, 1, 0) - 1] = c26_b_j;
        c26_i_a = *c26_ilo;
        c26_j_a = c26_i_a + 1;
        *c26_ilo = c26_j_a;
        if (*c26_ilo == *c26_ihi) {
          c26_rscale[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
            ("", (real_T)*c26_ilo), 1, 10, 1, 0) - 1] = *c26_ilo;
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void c26_b_eml_matlab_zgghrd(SFc26_hybridSysSimInstanceStruct
  *chartInstance, int32_T c26_ilo, int32_T c26_ihi, creal_T c26_A[100])
{
  int32_T c26_a;
  int32_T c26_b_a;
  int32_T c26_c;
  int32_T c26_c_a;
  int32_T c26_d_a;
  int32_T c26_ihim1;
  int32_T c26_jcol;
  int32_T c26_e_a;
  int32_T c26_f_a;
  int32_T c26_jcolp1;
  int32_T c26_jrow;
  int32_T c26_g_a;
  int32_T c26_h_a;
  int32_T c26_jrowm1;
  creal_T c26_b_A;
  creal_T c26_c_A;
  creal_T c26_b;
  creal_T c26_s;
  real_T c26_b_c;
  real_T c26_c_c;
  static creal_T c26_dc22 = { 0.0, 0.0 };

  real_T c26_d_c;
  int32_T c26_xrow;
  int32_T c26_yrow;
  int32_T c26_jlo;
  int32_T c26_jhi;
  int32_T c26_b_jlo;
  int32_T c26_b_jhi;
  int32_T c26_i_a;
  int32_T c26_b_b;
  int32_T c26_j_a;
  int32_T c26_c_b;
  boolean_T c26_overflow;
  int32_T c26_j;
  int32_T c26_b_j;
  real_T c26_k_a;
  creal_T c26_y;
  creal_T c26_b_s;
  creal_T c26_stemp;
  real_T c26_l_a;
  creal_T c26_d_b;
  creal_T c26_e_b;
  creal_T c26_f_b;
  creal_T c26_g_b;
  real_T c26_e_c;
  int32_T c26_xcol;
  int32_T c26_ycol;
  int32_T c26_b_ilo;
  int32_T c26_b_ihi;
  int32_T c26_c_ilo;
  int32_T c26_c_ihi;
  int32_T c26_m_a;
  int32_T c26_h_b;
  int32_T c26_n_a;
  int32_T c26_i_b;
  boolean_T c26_b_overflow;
  int32_T c26_i;
  int32_T c26_b_i;
  real_T c26_o_a;
  creal_T c26_c_s;
  real_T c26_p_a;
  creal_T c26_j_b;
  creal_T c26_k_b;
  creal_T c26_l_b;
  creal_T c26_m_b;
  c26_a = c26_ilo;
  c26_b_a = c26_a;
  c26_c = c26_b_a;
  if (c26_ihi < c26_c + 2) {
  } else {
    c26_c_a = c26_ihi;
    c26_d_a = c26_c_a;
    c26_ihim1 = c26_d_a;
    c26_jcol = c26_ilo;
    while (c26_jcol < c26_ihim1 - 1) {
      c26_e_a = c26_jcol;
      c26_f_a = c26_e_a + 1;
      c26_jcolp1 = c26_f_a;
      c26_jrow = c26_ihi;
      while (c26_jrow > c26_jcolp1) {
        c26_g_a = c26_jrow;
        c26_h_a = c26_g_a - 1;
        c26_jrowm1 = c26_h_a;
        c26_b_A.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_jrowm1), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_jcol), 1, 10, 2, 0) - 1)) - 1].re;
        c26_b_A.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_jrowm1), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_jcol), 1, 10, 2, 0) - 1)) - 1].im;
        c26_c_A.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_jrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_jcol), 1, 10, 2, 0) - 1)) - 1].re;
        c26_c_A.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_jrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c26_jcol), 1, 10, 2, 0) - 1)) - 1].im;
        c26_eml_matlab_zlartg(chartInstance, c26_b_A, c26_c_A, &c26_b_c, &c26_s,
                              &c26_b);
        c26_c_c = c26_b_c;
        c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_jrowm1), 1, 10, 1, 0) + 10 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c26_jcol), 1, 10, 2, 0) - 1)) - 1].re = c26_b.re;
        c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_jrowm1), 1, 10, 1, 0) + 10 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c26_jcol), 1, 10, 2, 0) - 1)) - 1].im = c26_b.im;
        c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_jrow), 1, 10, 1, 0) + 10 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c26_jcol), 1, 10, 2, 0) - 1)) - 1].re = c26_dc22.re;
        c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_jrow), 1, 10, 1, 0) + 10 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c26_jcol), 1, 10, 2, 0) - 1)) - 1].im = c26_dc22.im;
        c26_d_c = c26_c_c;
        c26_xrow = c26_jrowm1;
        c26_yrow = c26_jrow;
        c26_jlo = c26_jcolp1;
        c26_jhi = c26_ihi;
        c26_b_jlo = c26_jlo;
        c26_b_jhi = c26_jhi;
        c26_i_a = c26_b_jlo;
        c26_b_b = c26_b_jhi;
        c26_j_a = c26_i_a;
        c26_c_b = c26_b_b;
        if (c26_j_a > c26_c_b) {
          c26_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_overflow = (c26_c_b > 2147483646);
        }

        if (c26_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_overflow);
        }

        for (c26_j = c26_b_jlo; c26_j <= c26_b_jhi; c26_j++) {
          c26_b_j = c26_j;
          c26_k_a = c26_d_c;
          c26_b.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re;
          c26_b.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im;
          c26_y.re = c26_k_a * c26_b.re;
          c26_y.im = c26_k_a * c26_b.im;
          c26_b_s.re = c26_s.re * c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1, 0) + 10
            * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re - c26_s.im * c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_yrow), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im;
          c26_b_s.im = c26_s.re * c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1, 0) + 10
            * (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im + c26_s.im * c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_yrow), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re;
          c26_stemp.re = c26_y.re + c26_b_s.re;
          c26_stemp.im = c26_y.im + c26_b_s.im;
          c26_l_a = c26_d_c;
          c26_b.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re;
          c26_b.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_yrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im;
          c26_y.re = c26_l_a * c26_b.re;
          c26_y.im = c26_l_a * c26_b.im;
          c26_b.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re;
          c26_b.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im;
          c26_d_b = c26_b;
          c26_e_b = c26_b;
          c26_f_b = c26_b;
          c26_g_b = c26_b;
          c26_b.re = c26_s.re * c26_d_b.re + c26_s.im * c26_e_b.im;
          c26_b.im = c26_s.re * c26_f_b.im - c26_s.im * c26_g_b.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_yrow), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re = c26_y.re -
            c26_b.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_yrow), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im = c26_y.im -
            c26_b.im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].re = c26_stemp.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_xrow), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_b_j), 1, 10, 2, 0) - 1)) - 1].im = c26_stemp.im;
        }

        c26_s.re = -c26_s.re;
        c26_s.im = -c26_s.im;
        c26_e_c = c26_c_c;
        c26_xcol = c26_jrow;
        c26_ycol = c26_jrowm1;
        c26_b_ilo = c26_ilo;
        c26_b_ihi = c26_ihi;
        c26_c_ilo = c26_b_ilo;
        c26_c_ihi = c26_b_ihi;
        c26_m_a = c26_c_ilo;
        c26_h_b = c26_c_ihi;
        c26_n_a = c26_m_a;
        c26_i_b = c26_h_b;
        if (c26_n_a > c26_i_b) {
          c26_b_overflow = false;
        } else {
          c26_eml_switch_helper(chartInstance);
          c26_eml_switch_helper(chartInstance);
          c26_b_overflow = (c26_i_b > 2147483646);
        }

        if (c26_b_overflow) {
          c26_check_forloop_overflow_error(chartInstance, c26_b_overflow);
        }

        for (c26_i = c26_c_ilo; c26_i <= c26_c_ihi; c26_i++) {
          c26_b_i = c26_i;
          c26_o_a = c26_e_c;
          c26_b.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1].re;
          c26_b.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1].im;
          c26_y.re = c26_o_a * c26_b.re;
          c26_y.im = c26_o_a * c26_b.im;
          c26_c_s.re = c26_s.re * c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1].re - c26_s.im * c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1].im;
          c26_c_s.im = c26_s.re * c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1].im + c26_s.im * c26_A
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1].re;
          c26_stemp.re = c26_y.re + c26_c_s.re;
          c26_stemp.im = c26_y.im + c26_c_s.im;
          c26_p_a = c26_e_c;
          c26_b.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1].re;
          c26_b.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1].im;
          c26_y.re = c26_p_a * c26_b.re;
          c26_y.im = c26_p_a * c26_b.im;
          c26_b.re = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1].re;
          c26_b.im = c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1].im;
          c26_j_b = c26_b;
          c26_k_b = c26_b;
          c26_l_b = c26_b;
          c26_m_b = c26_b;
          c26_b.re = c26_s.re * c26_j_b.re + c26_s.im * c26_k_b.im;
          c26_b.im = c26_s.re * c26_l_b.im - c26_s.im * c26_m_b.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1].re = c26_y.re -
            c26_b.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_ycol), 1, 10, 2, 0) - 1)) - 1].im = c26_y.im -
            c26_b.im;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1].re = c26_stemp.re;
          c26_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c26_b_i), 1, 10, 1, 0) + 10 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c26_xcol), 1, 10, 2, 0) - 1)) - 1].im = c26_stemp.im;
        }

        c26_jrow = c26_jrowm1;
      }

      c26_jcol = c26_jcolp1;
    }
  }
}

static int32_T c26_div_s32(SFc26_hybridSysSimInstanceStruct *chartInstance,
  int32_T c26_numerator, int32_T c26_denominator)
{
  int32_T c26_quotient;
  uint32_T c26_absNumerator;
  uint32_T c26_absDenominator;
  boolean_T c26_quotientNeedsNegation;
  uint32_T c26_tempAbsQuotient;
  (void)chartInstance;
  if (c26_denominator == 0) {
    if (c26_numerator >= 0) {
      c26_quotient = MAX_int32_T;
    } else {
      c26_quotient = MIN_int32_T;
    }

    _SFD_OVERFLOW_DETECTION(SFDB_DIVIDE_BY_ZERO);
  } else {
    if (c26_numerator >= 0) {
      c26_absNumerator = (uint32_T)c26_numerator;
    } else {
      c26_absNumerator = (uint32_T)-c26_numerator;
    }

    if (c26_denominator >= 0) {
      c26_absDenominator = (uint32_T)c26_denominator;
    } else {
      c26_absDenominator = (uint32_T)-c26_denominator;
    }

    c26_quotientNeedsNegation = (c26_numerator < 0 != c26_denominator < 0);
    c26_tempAbsQuotient = c26_absNumerator / c26_absDenominator;
    if (c26_quotientNeedsNegation) {
      c26_quotient = -(int32_T)c26_tempAbsQuotient;
    } else {
      c26_quotient = (int32_T)c26_tempAbsQuotient;
    }
  }

  return c26_quotient;
}

static void init_dsm_address_info(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c26_q = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c26_rCFC = (creal_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c26_qDot = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c26_FcTilde = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c26_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(585684710U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2132265619U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(56535814U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1586608780U);
}

mxArray* sf_c26_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c26_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kaFld4w1mrGpnzF3wt940E");
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
    mxArray* mxPostCodegenInfo = sf_c26_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c26_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c26_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c26_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c26_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c26_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"rCFC\",},{M[8],M[0],T\"is_active_c26_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c26_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc26_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc26_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           26,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"rCFC");
          _SFD_SET_DATA_PROPS(2,1,1,0,"qDot");
          _SFD_SET_DATA_PROPS(3,1,1,0,"FcTilde");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2195);
        _SFD_CV_INIT_EML_IF(0,1,0,1270,1287,1313,1362);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,1273,1286,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,1,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)c26_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c26_q);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c26_rCFC);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c26_qDot);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c26_FcTilde);
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
  return "PpzwZC6G8DVZAAMBxZGViE";
}

static void sf_opaque_initialize_c26_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc26_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c26_hybridSysSim(void *chartInstanceVar)
{
  enable_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c26_hybridSysSim(void *chartInstanceVar)
{
  disable_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c26_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c26_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c26_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c26_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc26_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*)
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
  initSimStructsc26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c26_hybridSysSim(SimStruct *S)
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
    initialize_params_c26_hybridSysSim((SFc26_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c26_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      26);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,26,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,26,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,26);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,26,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,26,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,26);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2239828450U));
  ssSetChecksum1(S,(3252907164U));
  ssSetChecksum2(S,(3599940234U));
  ssSetChecksum3(S,(3572422531U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c26_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c26_hybridSysSim(SimStruct *S)
{
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc26_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc26_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c26_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c26_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c26_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c26_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c26_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c26_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c26_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c26_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c26_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c26_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c26_hybridSysSim;
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

void c26_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c26_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c26_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c26_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c26_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
