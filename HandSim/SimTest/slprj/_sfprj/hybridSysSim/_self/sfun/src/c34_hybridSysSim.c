/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c34_hybridSysSim.h"
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
static const char * c34_debug_family_names[14] = { "lP", "lD", "mP", "mD", "IP",
  "ID", "alpha", "beta", "delta", "M", "nargin", "nargout", "theta", "inertia" };

/* Function Declarations */
static void initialize_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance);
static void c34_update_debugger_state_c34_hybridSysSim
  (SFc34_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c34_hybridSysSim
  (SFc34_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_st);
static void finalize_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber, uint32_T c34_instanceNumber);
static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static void c34_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c34_b_inertia, const char_T *c34_identifier, real_T c34_y[4]);
static void c34_b_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  real_T c34_y[4]);
static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static real_T c34_c_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static void c34_info_helper(const mxArray **c34_info);
static const mxArray *c34_emlrt_marshallOut(const char * c34_u);
static const mxArray *c34_b_emlrt_marshallOut(const uint32_T c34_u);
static const mxArray *c34_d_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static int32_T c34_d_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static uint8_T c34_e_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_b_is_active_c34_hybridSysSim, const char_T *
  c34_identifier);
static uint8_T c34_f_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void init_dsm_address_info(SFc34_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc34_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c34_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c34_is_active_c34_hybridSysSim = 0U;
}

static void initialize_params_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c34_update_debugger_state_c34_hybridSysSim
  (SFc34_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c34_hybridSysSim
  (SFc34_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c34_st;
  const mxArray *c34_y = NULL;
  int32_T c34_i0;
  real_T c34_u[4];
  const mxArray *c34_b_y = NULL;
  uint8_T c34_hoistedGlobal;
  uint8_T c34_b_u;
  const mxArray *c34_c_y = NULL;
  c34_st = NULL;
  c34_st = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_createcellmatrix(2, 1), false);
  for (c34_i0 = 0; c34_i0 < 4; c34_i0++) {
    c34_u[c34_i0] = (*chartInstance->c34_inertia)[c34_i0];
  }

  c34_b_y = NULL;
  sf_mex_assign(&c34_b_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 2, 2, 2),
                false);
  sf_mex_setcell(c34_y, 0, c34_b_y);
  c34_hoistedGlobal = chartInstance->c34_is_active_c34_hybridSysSim;
  c34_b_u = c34_hoistedGlobal;
  c34_c_y = NULL;
  sf_mex_assign(&c34_c_y, sf_mex_create("y", &c34_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c34_y, 1, c34_c_y);
  sf_mex_assign(&c34_st, c34_y, false);
  return c34_st;
}

static void set_sim_state_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_st)
{
  const mxArray *c34_u;
  real_T c34_dv0[4];
  int32_T c34_i1;
  chartInstance->c34_doneDoubleBufferReInit = true;
  c34_u = sf_mex_dup(c34_st);
  c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 0)),
                       "inertia", c34_dv0);
  for (c34_i1 = 0; c34_i1 < 4; c34_i1++) {
    (*chartInstance->c34_inertia)[c34_i1] = c34_dv0[c34_i1];
  }

  chartInstance->c34_is_active_c34_hybridSysSim = c34_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 1)),
     "is_active_c34_hybridSysSim");
  sf_mex_destroy(&c34_u);
  c34_update_debugger_state_c34_hybridSysSim(chartInstance);
  sf_mex_destroy(&c34_st);
}

static void finalize_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c34_i2;
  int32_T c34_i3;
  real_T c34_b_theta[2];
  uint32_T c34_debug_family_var_map[14];
  real_T c34_lP;
  real_T c34_lD;
  real_T c34_mP;
  real_T c34_mD;
  real_T c34_IP;
  real_T c34_ID;
  real_T c34_alpha;
  real_T c34_beta;
  real_T c34_delta;
  real_T c34_M[4];
  real_T c34_nargin = 1.0;
  real_T c34_nargout = 1.0;
  real_T c34_b_inertia[4];
  real_T c34_x;
  real_T c34_b_x;
  real_T c34_c_x;
  real_T c34_d_x;
  real_T c34_e_x;
  real_T c34_f_x;
  int32_T c34_i4;
  int32_T c34_i5;
  int32_T c34_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 31U, chartInstance->c34_sfEvent);
  for (c34_i2 = 0; c34_i2 < 2; c34_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_theta)[c34_i2], 0U);
  }

  chartInstance->c34_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 31U, chartInstance->c34_sfEvent);
  for (c34_i3 = 0; c34_i3 < 2; c34_i3++) {
    c34_b_theta[c34_i3] = (*chartInstance->c34_theta)[c34_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c34_debug_family_names,
    c34_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c34_lP, 0U, c34_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c34_lD, 1U, c34_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c34_mP, 2U, c34_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c34_mD, 3U, c34_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_IP, 4U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_ID, 5U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_alpha, 6U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c34_beta, 7U, c34_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_delta, 8U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_M, 9U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargin, 10U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargout, 11U, c34_c_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c34_b_theta, 12U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_b_inertia, 13U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 2);
  c34_lP = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 3);
  c34_lD = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 4);
  c34_mP = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 5);
  c34_mD = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 6);
  c34_IP = 6.6666666666666683E-5;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 7);
  c34_ID = 1.6666666666666671E-5;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 9);
  c34_alpha = ((c34_IP + c34_ID) + 5.0000000000000009E-5) +
    0.00025000000000000006;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 10);
  c34_beta = 0.0001;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 11);
  c34_delta = c34_ID + 5.0000000000000009E-5;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 13);
  c34_x = c34_b_theta[1];
  c34_b_x = c34_x;
  c34_b_x = muDoubleScalarCos(c34_b_x);
  c34_c_x = c34_b_theta[1];
  c34_d_x = c34_c_x;
  c34_d_x = muDoubleScalarCos(c34_d_x);
  c34_e_x = c34_b_theta[1];
  c34_f_x = c34_e_x;
  c34_f_x = muDoubleScalarCos(c34_f_x);
  c34_M[0] = c34_alpha + 0.0002 * c34_b_x;
  c34_M[2] = c34_delta + 0.0001 * c34_d_x;
  c34_M[1] = c34_delta + 0.0001 * c34_f_x;
  c34_M[3] = c34_delta;
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 15);
  for (c34_i4 = 0; c34_i4 < 4; c34_i4++) {
    c34_b_inertia[c34_i4] = c34_M[c34_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, -15);
  _SFD_SYMBOL_SCOPE_POP();
  for (c34_i5 = 0; c34_i5 < 4; c34_i5++) {
    (*chartInstance->c34_inertia)[c34_i5] = c34_b_inertia[c34_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c34_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c34_i6 = 0; c34_i6 < 4; c34_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c34_inertia)[c34_i6], 1U);
  }
}

static void mdl_start_c34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc34_hybridSysSim(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber, uint32_T c34_instanceNumber)
{
  (void)c34_machineNumber;
  (void)c34_chartNumber;
  (void)c34_instanceNumber;
}

static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_i7;
  int32_T c34_i8;
  int32_T c34_i9;
  real_T c34_b_inData[4];
  int32_T c34_i10;
  int32_T c34_i11;
  int32_T c34_i12;
  real_T c34_u[4];
  const mxArray *c34_y = NULL;
  SFc34_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc34_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_i7 = 0;
  for (c34_i8 = 0; c34_i8 < 2; c34_i8++) {
    for (c34_i9 = 0; c34_i9 < 2; c34_i9++) {
      c34_b_inData[c34_i9 + c34_i7] = (*(real_T (*)[4])c34_inData)[c34_i9 +
        c34_i7];
    }

    c34_i7 += 2;
  }

  c34_i10 = 0;
  for (c34_i11 = 0; c34_i11 < 2; c34_i11++) {
    for (c34_i12 = 0; c34_i12 < 2; c34_i12++) {
      c34_u[c34_i12 + c34_i10] = c34_b_inData[c34_i12 + c34_i10];
    }

    c34_i10 += 2;
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static void c34_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c34_b_inertia, const char_T *c34_identifier, real_T c34_y[4])
{
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_inertia), &c34_thisId,
    c34_y);
  sf_mex_destroy(&c34_b_inertia);
}

static void c34_b_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  real_T c34_y[4])
{
  real_T c34_dv1[4];
  int32_T c34_i13;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), c34_dv1, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c34_i13 = 0; c34_i13 < 4; c34_i13++) {
    c34_y[c34_i13] = c34_dv1[c34_i13];
  }

  sf_mex_destroy(&c34_u);
}

static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_b_inertia;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  real_T c34_y[4];
  int32_T c34_i14;
  int32_T c34_i15;
  int32_T c34_i16;
  SFc34_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc34_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c34_b_inertia = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_inertia), &c34_thisId,
    c34_y);
  sf_mex_destroy(&c34_b_inertia);
  c34_i14 = 0;
  for (c34_i15 = 0; c34_i15 < 2; c34_i15++) {
    for (c34_i16 = 0; c34_i16 < 2; c34_i16++) {
      (*(real_T (*)[4])c34_outData)[c34_i16 + c34_i14] = c34_y[c34_i16 + c34_i14];
    }

    c34_i14 += 2;
  }

  sf_mex_destroy(&c34_mxArrayInData);
}

static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_i17;
  real_T c34_b_inData[2];
  int32_T c34_i18;
  real_T c34_u[2];
  const mxArray *c34_y = NULL;
  SFc34_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc34_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  for (c34_i17 = 0; c34_i17 < 2; c34_i17++) {
    c34_b_inData[c34_i17] = (*(real_T (*)[2])c34_inData)[c34_i17];
  }

  for (c34_i18 = 0; c34_i18 < 2; c34_i18++) {
    c34_u[c34_i18] = c34_b_inData[c34_i18];
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  real_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc34_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(real_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static real_T c34_c_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  real_T c34_y;
  real_T c34_d0;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_d0, 1, 0, 0U, 0, 0U, 0);
  c34_y = c34_d0;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_nargout;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  real_T c34_y;
  SFc34_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc34_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c34_nargout = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_nargout),
    &c34_thisId);
  sf_mex_destroy(&c34_nargout);
  *(real_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

const mxArray *sf_c34_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c34_nameCaptureInfo = NULL;
  c34_nameCaptureInfo = NULL;
  sf_mex_assign(&c34_nameCaptureInfo, sf_mex_createstruct("structure", 2, 22, 1),
                false);
  c34_info_helper(&c34_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c34_nameCaptureInfo);
  return c34_nameCaptureInfo;
}

static void c34_info_helper(const mxArray **c34_info)
{
  const mxArray *c34_rhs0 = NULL;
  const mxArray *c34_lhs0 = NULL;
  const mxArray *c34_rhs1 = NULL;
  const mxArray *c34_lhs1 = NULL;
  const mxArray *c34_rhs2 = NULL;
  const mxArray *c34_lhs2 = NULL;
  const mxArray *c34_rhs3 = NULL;
  const mxArray *c34_lhs3 = NULL;
  const mxArray *c34_rhs4 = NULL;
  const mxArray *c34_lhs4 = NULL;
  const mxArray *c34_rhs5 = NULL;
  const mxArray *c34_lhs5 = NULL;
  const mxArray *c34_rhs6 = NULL;
  const mxArray *c34_lhs6 = NULL;
  const mxArray *c34_rhs7 = NULL;
  const mxArray *c34_lhs7 = NULL;
  const mxArray *c34_rhs8 = NULL;
  const mxArray *c34_lhs8 = NULL;
  const mxArray *c34_rhs9 = NULL;
  const mxArray *c34_lhs9 = NULL;
  const mxArray *c34_rhs10 = NULL;
  const mxArray *c34_lhs10 = NULL;
  const mxArray *c34_rhs11 = NULL;
  const mxArray *c34_lhs11 = NULL;
  const mxArray *c34_rhs12 = NULL;
  const mxArray *c34_lhs12 = NULL;
  const mxArray *c34_rhs13 = NULL;
  const mxArray *c34_lhs13 = NULL;
  const mxArray *c34_rhs14 = NULL;
  const mxArray *c34_lhs14 = NULL;
  const mxArray *c34_rhs15 = NULL;
  const mxArray *c34_lhs15 = NULL;
  const mxArray *c34_rhs16 = NULL;
  const mxArray *c34_lhs16 = NULL;
  const mxArray *c34_rhs17 = NULL;
  const mxArray *c34_lhs17 = NULL;
  const mxArray *c34_rhs18 = NULL;
  const mxArray *c34_lhs18 = NULL;
  const mxArray *c34_rhs19 = NULL;
  const mxArray *c34_lhs19 = NULL;
  const mxArray *c34_rhs20 = NULL;
  const mxArray *c34_lhs20 = NULL;
  const mxArray *c34_rhs21 = NULL;
  const mxArray *c34_lhs21 = NULL;
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363677878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c34_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c34_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("ismatrix"), "name", "name",
                  2);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1331268858U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c34_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1395292506U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c34_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c34_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c34_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c34_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c34_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c34_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363677854U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c34_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c34_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c34_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c34_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("mrdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c34_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 14);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 14);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c34_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 15);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("rdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c34_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c34_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 17);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286786396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c34_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_div"), "name", "name",
                  18);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c34_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 19);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c34_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("cos"), "name", "name", 20);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c34_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 21);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c34_info, c34_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(1286786322U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c34_info, c34_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c34_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c34_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c34_info, sf_mex_duplicatearraysafe(&c34_lhs21), "lhs", "lhs",
                  21);
  sf_mex_destroy(&c34_rhs0);
  sf_mex_destroy(&c34_lhs0);
  sf_mex_destroy(&c34_rhs1);
  sf_mex_destroy(&c34_lhs1);
  sf_mex_destroy(&c34_rhs2);
  sf_mex_destroy(&c34_lhs2);
  sf_mex_destroy(&c34_rhs3);
  sf_mex_destroy(&c34_lhs3);
  sf_mex_destroy(&c34_rhs4);
  sf_mex_destroy(&c34_lhs4);
  sf_mex_destroy(&c34_rhs5);
  sf_mex_destroy(&c34_lhs5);
  sf_mex_destroy(&c34_rhs6);
  sf_mex_destroy(&c34_lhs6);
  sf_mex_destroy(&c34_rhs7);
  sf_mex_destroy(&c34_lhs7);
  sf_mex_destroy(&c34_rhs8);
  sf_mex_destroy(&c34_lhs8);
  sf_mex_destroy(&c34_rhs9);
  sf_mex_destroy(&c34_lhs9);
  sf_mex_destroy(&c34_rhs10);
  sf_mex_destroy(&c34_lhs10);
  sf_mex_destroy(&c34_rhs11);
  sf_mex_destroy(&c34_lhs11);
  sf_mex_destroy(&c34_rhs12);
  sf_mex_destroy(&c34_lhs12);
  sf_mex_destroy(&c34_rhs13);
  sf_mex_destroy(&c34_lhs13);
  sf_mex_destroy(&c34_rhs14);
  sf_mex_destroy(&c34_lhs14);
  sf_mex_destroy(&c34_rhs15);
  sf_mex_destroy(&c34_lhs15);
  sf_mex_destroy(&c34_rhs16);
  sf_mex_destroy(&c34_lhs16);
  sf_mex_destroy(&c34_rhs17);
  sf_mex_destroy(&c34_lhs17);
  sf_mex_destroy(&c34_rhs18);
  sf_mex_destroy(&c34_lhs18);
  sf_mex_destroy(&c34_rhs19);
  sf_mex_destroy(&c34_lhs19);
  sf_mex_destroy(&c34_rhs20);
  sf_mex_destroy(&c34_lhs20);
  sf_mex_destroy(&c34_rhs21);
  sf_mex_destroy(&c34_lhs21);
}

static const mxArray *c34_emlrt_marshallOut(const char * c34_u)
{
  const mxArray *c34_y = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c34_u)), false);
  return c34_y;
}

static const mxArray *c34_b_emlrt_marshallOut(const uint32_T c34_u)
{
  const mxArray *c34_y = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 7, 0U, 0U, 0U, 0), false);
  return c34_y;
}

static const mxArray *c34_d_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc34_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(int32_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, false);
  return c34_mxArrayOutData;
}

static int32_T c34_d_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  int32_T c34_y;
  int32_T c34_i19;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_i19, 1, 6, 0U, 0, 0U, 0);
  c34_y = c34_i19;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_b_sfEvent;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  int32_T c34_y;
  SFc34_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc34_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c34_b_sfEvent = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_sfEvent),
    &c34_thisId);
  sf_mex_destroy(&c34_b_sfEvent);
  *(int32_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

static uint8_T c34_e_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_b_is_active_c34_hybridSysSim, const char_T *
  c34_identifier)
{
  uint8_T c34_y;
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c34_b_is_active_c34_hybridSysSim), &c34_thisId);
  sf_mex_destroy(&c34_b_is_active_c34_hybridSysSim);
  return c34_y;
}

static uint8_T c34_f_emlrt_marshallIn(SFc34_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  uint8_T c34_y;
  uint8_T c34_u0;
  (void)chartInstance;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_u0, 1, 3, 0U, 0, 0U, 0);
  c34_y = c34_u0;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void init_dsm_address_info(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc34_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c34_theta = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c34_inertia = (real_T (*)[4])ssGetOutputPortSignal_wrapper
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

void sf_c34_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(817495482U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3626483086U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2014272259U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2148364714U);
}

mxArray* sf_c34_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c34_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xBrqthwaCteYYbxNEIu4aC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxArray* mxPostCodegenInfo = sf_c34_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c34_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c34_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c34_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c34_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c34_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"inertia\",},{M[8],M[0],T\"is_active_c34_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c34_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc34_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc34_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           34,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"inertia");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,441);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)
            c34_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c34_theta);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c34_inertia);
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
  return "PbmhDrkHFNvhg1b4JSCOdF";
}

static void sf_opaque_initialize_c34_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc34_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c34_hybridSysSim(void *chartInstanceVar)
{
  enable_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c34_hybridSysSim(void *chartInstanceVar)
{
  disable_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c34_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c34_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c34_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c34_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc34_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*)
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
  initSimStructsc34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c34_hybridSysSim(SimStruct *S)
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
    initialize_params_c34_hybridSysSim((SFc34_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c34_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      34);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,34,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,34,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,34);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,34,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,34,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,34);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2661684641U));
  ssSetChecksum1(S,(2951278820U));
  ssSetChecksum2(S,(1945943818U));
  ssSetChecksum3(S,(4244558649U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c34_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c34_hybridSysSim(SimStruct *S)
{
  SFc34_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc34_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc34_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc34_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c34_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c34_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c34_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c34_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c34_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c34_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c34_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c34_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c34_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c34_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c34_hybridSysSim;
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

void c34_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c34_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c34_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c34_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c34_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
