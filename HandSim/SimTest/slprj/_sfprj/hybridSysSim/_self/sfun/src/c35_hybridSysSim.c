/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c35_hybridSysSim.h"
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
static const char * c35_debug_family_names[7] = { "nargin", "nargout", "theta",
  "estimatedVelocityX2", "Kd", "estimatedTheta", "estimatedVelocity" };

/* Function Declarations */
static void initialize_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance);
static void c35_update_debugger_state_c35_hybridSysSim
  (SFc35_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_hybridSysSim
  (SFc35_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_st);
static void finalize_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c35_b_estimatedVelocity, const char_T *c35_identifier, real_T
  c35_y[2]);
static void c35_b_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[2]);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_c_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static void c35_info_helper(const mxArray **c35_info);
static const mxArray *c35_emlrt_marshallOut(const char * c35_u);
static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u);
static void c35_eml_scalar_eg(SFc35_hybridSysSimInstanceStruct *chartInstance);
static void c35_eml_xgemm(SFc35_hybridSysSimInstanceStruct *chartInstance,
  real_T c35_A[4], real_T c35_B[2], real_T c35_C[2], real_T c35_b_C[2]);
static const mxArray *c35_e_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_d_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static uint8_T c35_e_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_hybridSysSim, const char_T *
  c35_identifier);
static uint8_T c35_f_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_b_eml_xgemm(SFc35_hybridSysSimInstanceStruct *chartInstance,
  real_T c35_A[4], real_T c35_B[2], real_T c35_C[2]);
static void init_dsm_address_info(SFc35_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc35_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c35_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c35_is_active_c35_hybridSysSim = 0U;
}

static void initialize_params_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c35_update_debugger_state_c35_hybridSysSim
  (SFc35_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c35_hybridSysSim
  (SFc35_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  int32_T c35_i0;
  real_T c35_u[2];
  const mxArray *c35_b_y = NULL;
  uint8_T c35_hoistedGlobal;
  uint8_T c35_b_u;
  const mxArray *c35_c_y = NULL;
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellmatrix(2, 1), false);
  for (c35_i0 = 0; c35_i0 < 2; c35_i0++) {
    c35_u[c35_i0] = (*chartInstance->c35_estimatedVelocity)[c35_i0];
  }

  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  c35_hoistedGlobal = chartInstance->c35_is_active_c35_hybridSysSim;
  c35_b_u = c35_hoistedGlobal;
  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", &c35_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  sf_mex_assign(&c35_st, c35_y, false);
  return c35_st;
}

static void set_sim_state_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  real_T c35_dv0[2];
  int32_T c35_i1;
  chartInstance->c35_doneDoubleBufferReInit = true;
  c35_u = sf_mex_dup(c35_st);
  c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 0)),
                       "estimatedVelocity", c35_dv0);
  for (c35_i1 = 0; c35_i1 < 2; c35_i1++) {
    (*chartInstance->c35_estimatedVelocity)[c35_i1] = c35_dv0[c35_i1];
  }

  chartInstance->c35_is_active_c35_hybridSysSim = c35_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 1)),
     "is_active_c35_hybridSysSim");
  sf_mex_destroy(&c35_u);
  c35_update_debugger_state_c35_hybridSysSim(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void finalize_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c35_i2;
  int32_T c35_i3;
  int32_T c35_i4;
  int32_T c35_i5;
  real_T c35_b_theta[2];
  int32_T c35_i6;
  real_T c35_b_estimatedVelocityX2[2];
  int32_T c35_i7;
  real_T c35_b_Kd[4];
  int32_T c35_i8;
  real_T c35_b_estimatedTheta[2];
  uint32_T c35_debug_family_var_map[7];
  real_T c35_nargin = 4.0;
  real_T c35_nargout = 1.0;
  real_T c35_b_estimatedVelocity[2];
  int32_T c35_i9;
  real_T c35_a[4];
  int32_T c35_i10;
  real_T c35_b[2];
  int32_T c35_i11;
  real_T c35_y[2];
  int32_T c35_i12;
  real_T c35_b_a[4];
  int32_T c35_i13;
  real_T c35_b_b[2];
  int32_T c35_i14;
  int32_T c35_i15;
  int32_T c35_i16;
  int32_T c35_i17;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 32U, chartInstance->c35_sfEvent);
  for (c35_i2 = 0; c35_i2 < 2; c35_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_theta)[c35_i2], 0U);
  }

  for (c35_i3 = 0; c35_i3 < 2; c35_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_estimatedVelocityX2)[c35_i3], 1U);
  }

  for (c35_i4 = 0; c35_i4 < 4; c35_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_Kd)[c35_i4], 2U);
  }

  chartInstance->c35_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 32U, chartInstance->c35_sfEvent);
  for (c35_i5 = 0; c35_i5 < 2; c35_i5++) {
    c35_b_theta[c35_i5] = (*chartInstance->c35_theta)[c35_i5];
  }

  for (c35_i6 = 0; c35_i6 < 2; c35_i6++) {
    c35_b_estimatedVelocityX2[c35_i6] = (*chartInstance->c35_estimatedVelocityX2)
      [c35_i6];
  }

  for (c35_i7 = 0; c35_i7 < 4; c35_i7++) {
    c35_b_Kd[c35_i7] = (*chartInstance->c35_Kd)[c35_i7];
  }

  for (c35_i8 = 0; c35_i8 < 2; c35_i8++) {
    c35_b_estimatedTheta[c35_i8] = (*chartInstance->c35_estimatedTheta)[c35_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c35_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 0U, c35_d_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 1U, c35_d_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_theta, 2U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_estimatedVelocityX2, 3U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_Kd, 4U, c35_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_b_estimatedTheta, 5U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_b_estimatedVelocity, 6U,
    c35_sf_marshallOut, c35_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 3);
  for (c35_i9 = 0; c35_i9 < 4; c35_i9++) {
    c35_a[c35_i9] = c35_b_Kd[c35_i9];
  }

  for (c35_i10 = 0; c35_i10 < 2; c35_i10++) {
    c35_b[c35_i10] = c35_b_theta[c35_i10] - c35_b_estimatedTheta[c35_i10];
  }

  c35_eml_scalar_eg(chartInstance);
  c35_eml_scalar_eg(chartInstance);
  for (c35_i11 = 0; c35_i11 < 2; c35_i11++) {
    c35_y[c35_i11] = 0.0;
  }

  for (c35_i12 = 0; c35_i12 < 4; c35_i12++) {
    c35_b_a[c35_i12] = c35_a[c35_i12];
  }

  for (c35_i13 = 0; c35_i13 < 2; c35_i13++) {
    c35_b_b[c35_i13] = c35_b[c35_i13];
  }

  c35_b_eml_xgemm(chartInstance, c35_b_a, c35_b_b, c35_y);
  for (c35_i14 = 0; c35_i14 < 2; c35_i14++) {
    c35_b_estimatedVelocity[c35_i14] = c35_b_estimatedVelocityX2[c35_i14] +
      c35_y[c35_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c35_i15 = 0; c35_i15 < 2; c35_i15++) {
    (*chartInstance->c35_estimatedVelocity)[c35_i15] =
      c35_b_estimatedVelocity[c35_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c35_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c35_i16 = 0; c35_i16 < 2; c35_i16++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_estimatedVelocity)[c35_i16], 3U);
  }

  for (c35_i17 = 0; c35_i17 < 2; c35_i17++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c35_estimatedTheta)[c35_i17], 4U);
  }
}

static void mdl_start_c35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc35_hybridSysSim(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber, uint32_T c35_instanceNumber)
{
  (void)c35_machineNumber;
  (void)c35_chartNumber;
  (void)c35_instanceNumber;
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i18;
  real_T c35_b_inData[2];
  int32_T c35_i19;
  real_T c35_u[2];
  const mxArray *c35_y = NULL;
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i18 = 0; c35_i18 < 2; c35_i18++) {
    c35_b_inData[c35_i18] = (*(real_T (*)[2])c35_inData)[c35_i18];
  }

  for (c35_i19 = 0; c35_i19 < 2; c35_i19++) {
    c35_u[c35_i19] = c35_b_inData[c35_i19];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static void c35_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c35_b_estimatedVelocity, const char_T *c35_identifier, real_T
  c35_y[2])
{
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_estimatedVelocity),
    &c35_thisId, c35_y);
  sf_mex_destroy(&c35_b_estimatedVelocity);
}

static void c35_b_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[2])
{
  real_T c35_dv1[2];
  int32_T c35_i20;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c35_i20 = 0; c35_i20 < 2; c35_i20++) {
    c35_y[c35_i20] = c35_dv1[c35_i20];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_estimatedVelocity;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[2];
  int32_T c35_i21;
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c35_b_estimatedVelocity = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_estimatedVelocity),
    &c35_thisId, c35_y);
  sf_mex_destroy(&c35_b_estimatedVelocity);
  for (c35_i21 = 0; c35_i21 < 2; c35_i21++) {
    (*(real_T (*)[2])c35_outData)[c35_i21] = c35_y[c35_i21];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i22;
  real_T c35_b_inData[2];
  int32_T c35_i23;
  real_T c35_u[2];
  const mxArray *c35_y = NULL;
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i22 = 0; c35_i22 < 2; c35_i22++) {
    c35_b_inData[c35_i22] = (*(real_T (*)[2])c35_inData)[c35_i22];
  }

  for (c35_i23 = 0; c35_i23 < 2; c35_i23++) {
    c35_u[c35_i23] = c35_b_inData[c35_i23];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 2, 2, 1), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i24;
  int32_T c35_i25;
  int32_T c35_i26;
  real_T c35_b_inData[4];
  int32_T c35_i27;
  int32_T c35_i28;
  int32_T c35_i29;
  real_T c35_u[4];
  const mxArray *c35_y = NULL;
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_i24 = 0;
  for (c35_i25 = 0; c35_i25 < 2; c35_i25++) {
    for (c35_i26 = 0; c35_i26 < 2; c35_i26++) {
      c35_b_inData[c35_i26 + c35_i24] = (*(real_T (*)[4])c35_inData)[c35_i26 +
        c35_i24];
    }

    c35_i24 += 2;
  }

  c35_i27 = 0;
  for (c35_i28 = 0; c35_i28 < 2; c35_i28++) {
    for (c35_i29 = 0; c35_i29 < 2; c35_i29++) {
      c35_u[c35_i29 + c35_i27] = c35_b_inData[c35_i29 + c35_i27];
    }

    c35_i27 += 2;
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static real_T c35_c_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d0, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_nargout;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c35_nargout = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_nargout),
    &c35_thisId);
  sf_mex_destroy(&c35_nargout);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

const mxArray *sf_c35_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  sf_mex_assign(&c35_nameCaptureInfo, sf_mex_createstruct("structure", 2, 13, 1),
                false);
  c35_info_helper(&c35_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c35_nameCaptureInfo);
  return c35_nameCaptureInfo;
}

static void c35_info_helper(const mxArray **c35_info)
{
  const mxArray *c35_rhs0 = NULL;
  const mxArray *c35_lhs0 = NULL;
  const mxArray *c35_rhs1 = NULL;
  const mxArray *c35_lhs1 = NULL;
  const mxArray *c35_rhs2 = NULL;
  const mxArray *c35_lhs2 = NULL;
  const mxArray *c35_rhs3 = NULL;
  const mxArray *c35_lhs3 = NULL;
  const mxArray *c35_rhs4 = NULL;
  const mxArray *c35_lhs4 = NULL;
  const mxArray *c35_rhs5 = NULL;
  const mxArray *c35_lhs5 = NULL;
  const mxArray *c35_rhs6 = NULL;
  const mxArray *c35_lhs6 = NULL;
  const mxArray *c35_rhs7 = NULL;
  const mxArray *c35_lhs7 = NULL;
  const mxArray *c35_rhs8 = NULL;
  const mxArray *c35_lhs8 = NULL;
  const mxArray *c35_rhs9 = NULL;
  const mxArray *c35_lhs9 = NULL;
  const mxArray *c35_rhs10 = NULL;
  const mxArray *c35_lhs10 = NULL;
  const mxArray *c35_rhs11 = NULL;
  const mxArray *c35_lhs11 = NULL;
  const mxArray *c35_rhs12 = NULL;
  const mxArray *c35_lhs12 = NULL;
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c35_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c35_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c35_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c35_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c35_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c35_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c35_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c35_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c35_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c35_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c35_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c35_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c35_info, c35_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c35_info, c35_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c35_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c35_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c35_info, sf_mex_duplicatearraysafe(&c35_lhs12), "lhs", "lhs",
                  12);
  sf_mex_destroy(&c35_rhs0);
  sf_mex_destroy(&c35_lhs0);
  sf_mex_destroy(&c35_rhs1);
  sf_mex_destroy(&c35_lhs1);
  sf_mex_destroy(&c35_rhs2);
  sf_mex_destroy(&c35_lhs2);
  sf_mex_destroy(&c35_rhs3);
  sf_mex_destroy(&c35_lhs3);
  sf_mex_destroy(&c35_rhs4);
  sf_mex_destroy(&c35_lhs4);
  sf_mex_destroy(&c35_rhs5);
  sf_mex_destroy(&c35_lhs5);
  sf_mex_destroy(&c35_rhs6);
  sf_mex_destroy(&c35_lhs6);
  sf_mex_destroy(&c35_rhs7);
  sf_mex_destroy(&c35_lhs7);
  sf_mex_destroy(&c35_rhs8);
  sf_mex_destroy(&c35_lhs8);
  sf_mex_destroy(&c35_rhs9);
  sf_mex_destroy(&c35_lhs9);
  sf_mex_destroy(&c35_rhs10);
  sf_mex_destroy(&c35_lhs10);
  sf_mex_destroy(&c35_rhs11);
  sf_mex_destroy(&c35_lhs11);
  sf_mex_destroy(&c35_rhs12);
  sf_mex_destroy(&c35_lhs12);
}

static const mxArray *c35_emlrt_marshallOut(const char * c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c35_u)), false);
  return c35_y;
}

static const mxArray *c35_b_emlrt_marshallOut(const uint32_T c35_u)
{
  const mxArray *c35_y = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 7, 0U, 0U, 0U, 0), false);
  return c35_y;
}

static void c35_eml_scalar_eg(SFc35_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c35_eml_xgemm(SFc35_hybridSysSimInstanceStruct *chartInstance,
  real_T c35_A[4], real_T c35_B[2], real_T c35_C[2], real_T c35_b_C[2])
{
  int32_T c35_i30;
  int32_T c35_i31;
  real_T c35_b_A[4];
  int32_T c35_i32;
  real_T c35_b_B[2];
  for (c35_i30 = 0; c35_i30 < 2; c35_i30++) {
    c35_b_C[c35_i30] = c35_C[c35_i30];
  }

  for (c35_i31 = 0; c35_i31 < 4; c35_i31++) {
    c35_b_A[c35_i31] = c35_A[c35_i31];
  }

  for (c35_i32 = 0; c35_i32 < 2; c35_i32++) {
    c35_b_B[c35_i32] = c35_B[c35_i32];
  }

  c35_b_eml_xgemm(chartInstance, c35_b_A, c35_b_B, c35_b_C);
}

static const mxArray *c35_e_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, false);
  return c35_mxArrayOutData;
}

static int32_T c35_d_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i33;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i33, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i33;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c35_b_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_b_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static uint8_T c35_e_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_hybridSysSim, const char_T *
  c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_is_active_c35_hybridSysSim), &c35_thisId);
  sf_mex_destroy(&c35_b_is_active_c35_hybridSysSim);
  return c35_y;
}

static uint8_T c35_f_emlrt_marshallIn(SFc35_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  (void)chartInstance;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_b_eml_xgemm(SFc35_hybridSysSimInstanceStruct *chartInstance,
  real_T c35_A[4], real_T c35_B[2], real_T c35_C[2])
{
  int32_T c35_i34;
  int32_T c35_i35;
  int32_T c35_i36;
  (void)chartInstance;
  for (c35_i34 = 0; c35_i34 < 2; c35_i34++) {
    c35_C[c35_i34] = 0.0;
    c35_i35 = 0;
    for (c35_i36 = 0; c35_i36 < 2; c35_i36++) {
      c35_C[c35_i34] += c35_A[c35_i35 + c35_i34] * c35_B[c35_i36];
      c35_i35 += 2;
    }
  }
}

static void init_dsm_address_info(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc35_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c35_theta = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c35_estimatedVelocityX2 = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c35_Kd = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c35_estimatedVelocity = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c35_estimatedTheta = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
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

void sf_c35_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1158309486U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3408513092U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2955597552U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1866794447U);
}

mxArray* sf_c35_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c35_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NgPe27et3ba7ZxTLl9eqAF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[1] = (double)(2);
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
    mxArray* mxPostCodegenInfo = sf_c35_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c35_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c35_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c35_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c35_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c35_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"estimatedVelocity\",},{M[8],M[0],T\"is_active_c35_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc35_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           35,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(1,1,1,0,"estimatedVelocityX2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Kd");
          _SFD_SET_DATA_PROPS(3,2,0,1,"estimatedVelocity");
          _SFD_SET_DATA_PROPS(4,1,1,0,"estimatedTheta");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,174);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)
            c35_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c35_theta);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c35_estimatedVelocityX2);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c35_Kd);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c35_estimatedVelocity);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c35_estimatedTheta);
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
  return "NoqzfvicKW5VxuymmASYuE";
}

static void sf_opaque_initialize_c35_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc35_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c35_hybridSysSim(void *chartInstanceVar)
{
  enable_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c35_hybridSysSim(void *chartInstanceVar)
{
  disable_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c35_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c35_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c35_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c35_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*)
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
  initSimStructsc35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_hybridSysSim(SimStruct *S)
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
    initialize_params_c35_hybridSysSim((SFc35_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c35_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,35,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,35);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,35,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,35,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4228376078U));
  ssSetChecksum1(S,(1520116566U));
  ssSetChecksum2(S,(2743405915U));
  ssSetChecksum3(S,(731534578U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c35_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c35_hybridSysSim(SimStruct *S)
{
  SFc35_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc35_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc35_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c35_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c35_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c35_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c35_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c35_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c35_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c35_hybridSysSim;
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

void c35_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
