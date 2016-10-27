/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c26_hybridSysSim.h"
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
static const char * c26_debug_family_names[11] = { "ri", "nargin", "nargout",
  "irOtoL", "irOtoLDot", "iFcComp", "posG3", "R", "iCol", "iColPos", "cRc" };

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
static void initSimStructsc26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber, uint32_T c26_instanceNumber);
static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c26_b_cRc, const char_T *c26_identifier, real_T c26_y[2]);
static void c26_b_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[2]);
static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static real_T c26_c_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_b_iCol, const char_T *c26_identifier);
static real_T c26_d_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_info_helper(const mxArray **c26_info);
static const mxArray *c26_emlrt_marshallOut(const char * c26_u);
static const mxArray *c26_b_emlrt_marshallOut(const uint32_T c26_u);
static real_T c26_mpower(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_a);
static void c26_eml_scalar_eg(SFc26_hybridSysSimInstanceStruct *chartInstance);
static void c26_eml_error(SFc26_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *c26_e_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static int32_T c26_e_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static uint8_T c26_f_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_hybridSysSim, const char_T *
  c26_identifier);
static uint8_T c26_g_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
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
  int32_T c26_i0;
  real_T c26_u[2];
  const mxArray *c26_b_y = NULL;
  real_T c26_hoistedGlobal;
  real_T c26_b_u;
  const mxArray *c26_c_y = NULL;
  int32_T c26_i1;
  real_T c26_c_u[2];
  const mxArray *c26_d_y = NULL;
  uint8_T c26_b_hoistedGlobal;
  uint8_T c26_d_u;
  const mxArray *c26_e_y = NULL;
  c26_st = NULL;
  c26_st = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createcellmatrix(4, 1), false);
  for (c26_i0 = 0; c26_i0 < 2; c26_i0++) {
    c26_u[c26_i0] = (*chartInstance->c26_cRc)[c26_i0];
  }

  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c26_y, 0, c26_b_y);
  c26_hoistedGlobal = *chartInstance->c26_iCol;
  c26_b_u = c26_hoistedGlobal;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c26_y, 1, c26_c_y);
  for (c26_i1 = 0; c26_i1 < 2; c26_i1++) {
    c26_c_u[c26_i1] = (*chartInstance->c26_iColPos)[c26_i1];
  }

  c26_d_y = NULL;
  sf_mex_assign(&c26_d_y, sf_mex_create("y", c26_c_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setcell(c26_y, 2, c26_d_y);
  c26_b_hoistedGlobal = chartInstance->c26_is_active_c26_hybridSysSim;
  c26_d_u = c26_b_hoistedGlobal;
  c26_e_y = NULL;
  sf_mex_assign(&c26_e_y, sf_mex_create("y", &c26_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c26_y, 3, c26_e_y);
  sf_mex_assign(&c26_st, c26_y, false);
  return c26_st;
}

static void set_sim_state_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_st)
{
  const mxArray *c26_u;
  real_T c26_dv0[2];
  int32_T c26_i2;
  real_T c26_dv1[2];
  int32_T c26_i3;
  chartInstance->c26_doneDoubleBufferReInit = true;
  c26_u = sf_mex_dup(c26_st);
  c26_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 0)),
                       "cRc", c26_dv0);
  for (c26_i2 = 0; c26_i2 < 2; c26_i2++) {
    (*chartInstance->c26_cRc)[c26_i2] = c26_dv0[c26_i2];
  }

  *chartInstance->c26_iCol = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c26_u, 1)), "iCol");
  c26_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 2)),
                       "iColPos", c26_dv1);
  for (c26_i3 = 0; c26_i3 < 2; c26_i3++) {
    (*chartInstance->c26_iColPos)[c26_i3] = c26_dv1[c26_i3];
  }

  chartInstance->c26_is_active_c26_hybridSysSim = c26_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 3)),
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
  int32_T c26_i4;
  real_T c26_hoistedGlobal;
  int32_T c26_i5;
  real_T c26_b_irOtoL[4];
  int32_T c26_i6;
  real_T c26_b_irOtoLDot[2];
  int32_T c26_i7;
  real_T c26_b_iFcComp[2];
  int32_T c26_i8;
  real_T c26_b_posG3[2];
  real_T c26_b_R;
  uint32_T c26_debug_family_var_map[11];
  real_T c26_ri;
  real_T c26_nargin = 5.0;
  real_T c26_nargout = 3.0;
  real_T c26_b_iCol;
  real_T c26_b_iColPos[2];
  real_T c26_b_cRc[2];
  int32_T c26_i9;
  real_T c26_x;
  real_T c26_b_x;
  int32_T c26_i10;
  int32_T c26_i11;
  real_T c26_b[2];
  int32_T c26_i12;
  int32_T c26_i13;
  int32_T c26_i14;
  int32_T c26_i15;
  int32_T c26_i16;
  int32_T c26_i17;
  int32_T c26_i18;
  int32_T c26_i19;
  int32_T c26_i20;
  int32_T c26_i21;
  int32_T c26_i22;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 23U, chartInstance->c26_sfEvent);
  for (c26_i4 = 0; c26_i4 < 4; c26_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c26_irOtoL)[c26_i4], 0U);
  }

  chartInstance->c26_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c26_sfEvent);
  c26_hoistedGlobal = *chartInstance->c26_R;
  for (c26_i5 = 0; c26_i5 < 4; c26_i5++) {
    c26_b_irOtoL[c26_i5] = (*chartInstance->c26_irOtoL)[c26_i5];
  }

  for (c26_i6 = 0; c26_i6 < 2; c26_i6++) {
    c26_b_irOtoLDot[c26_i6] = (*chartInstance->c26_irOtoLDot)[c26_i6];
  }

  for (c26_i7 = 0; c26_i7 < 2; c26_i7++) {
    c26_b_iFcComp[c26_i7] = (*chartInstance->c26_iFcComp)[c26_i7];
  }

  for (c26_i8 = 0; c26_i8 < 2; c26_i8++) {
    c26_b_posG3[c26_i8] = (*chartInstance->c26_posG3)[c26_i8];
  }

  c26_b_R = c26_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c26_debug_family_names,
    c26_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_ri, 0U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargin, 1U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargout, 2U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_b_irOtoL, 3U, c26_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_b_irOtoLDot, 4U, c26_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_b_iFcComp, 5U, c26_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_b_posG3, 6U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c26_b_R, 7U, c26_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_b_iCol, 8U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_b_iColPos, 9U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_b_cRc, 10U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 11);
  for (c26_i9 = 0; c26_i9 < 2; c26_i9++) {
    c26_b_iColPos[c26_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 13);
  c26_x = c26_mpower(chartInstance, c26_b_irOtoL[2] - c26_b_posG3[0]) +
    c26_mpower(chartInstance, c26_b_irOtoL[3] - c26_b_posG3[1]);
  c26_ri = c26_x;
  if (c26_ri < 0.0) {
    c26_eml_error(chartInstance);
  }

  c26_b_x = c26_ri;
  c26_ri = c26_b_x;
  c26_ri = muDoubleScalarSqrt(c26_ri);
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 15);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c26_ri, c26_b_R + 0.006,
        -1, 3U, c26_ri <= c26_b_R + 0.006))) {
    _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 16);
    c26_b_iCol = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 17);
    for (c26_i10 = 0; c26_i10 < 2; c26_i10++) {
      c26_b_iColPos[c26_i10] = c26_b_irOtoL[c26_i10 + 2];
    }

    _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 18);
    for (c26_i11 = 0; c26_i11 < 2; c26_i11++) {
      c26_b[c26_i11] = c26_b_irOtoLDot[c26_i11];
    }

    for (c26_i12 = 0; c26_i12 < 2; c26_i12++) {
      c26_b[c26_i12] *= 1.76;
    }

    for (c26_i13 = 0; c26_i13 < 2; c26_i13++) {
      c26_b_cRc[c26_i13] = c26_b[c26_i13] + c26_b_iFcComp[c26_i13];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 20);
    c26_b_iCol = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 21);
    for (c26_i14 = 0; c26_i14 < 2; c26_i14++) {
      c26_b_iColPos[c26_i14] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 22);
    for (c26_i15 = 0; c26_i15 < 2; c26_i15++) {
      c26_b_cRc[c26_i15] = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c26_iCol = c26_b_iCol;
  for (c26_i16 = 0; c26_i16 < 2; c26_i16++) {
    (*chartInstance->c26_iColPos)[c26_i16] = c26_b_iColPos[c26_i16];
  }

  for (c26_i17 = 0; c26_i17 < 2; c26_i17++) {
    (*chartInstance->c26_cRc)[c26_i17] = c26_b_cRc[c26_i17];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c26_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c26_iCol, 1U);
  for (c26_i18 = 0; c26_i18 < 2; c26_i18++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c26_irOtoLDot)[c26_i18], 2U);
  }

  for (c26_i19 = 0; c26_i19 < 2; c26_i19++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c26_iFcComp)[c26_i19], 3U);
  }

  for (c26_i20 = 0; c26_i20 < 2; c26_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c26_posG3)[c26_i20], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c26_R, 5U);
  for (c26_i21 = 0; c26_i21 < 2; c26_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c26_iColPos)[c26_i21], 6U);
  }

  for (c26_i22 = 0; c26_i22 < 2; c26_i22++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c26_cRc)[c26_i22], 7U);
  }
}

static void mdl_start_c26_hybridSysSim(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
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
  int32_T c26_i23;
  real_T c26_b_inData[2];
  int32_T c26_i24;
  real_T c26_u[2];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i23 = 0; c26_i23 < 2; c26_i23++) {
    c26_b_inData[c26_i23] = (*(real_T (*)[2])c26_inData)[c26_i23];
  }

  for (c26_i24 = 0; c26_i24 < 2; c26_i24++) {
    c26_u[c26_i24] = c26_b_inData[c26_i24];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

static void c26_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c26_b_cRc, const char_T *c26_identifier, real_T c26_y[2])
{
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_cRc), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_b_cRc);
}

static void c26_b_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[2])
{
  real_T c26_dv2[2];
  int32_T c26_i25;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c26_i25 = 0; c26_i25 < 2; c26_i25++) {
    c26_y[c26_i25] = c26_dv2[c26_i25];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_cRc;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y[2];
  int32_T c26_i26;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_b_cRc = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_cRc), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_b_cRc);
  for (c26_i26 = 0; c26_i26 < 2; c26_i26++) {
    (*(real_T (*)[2])c26_outData)[c26_i26] = c26_y[c26_i26];
  }

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

static real_T c26_c_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_b_iCol, const char_T *c26_identifier)
{
  real_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_iCol),
    &c26_thisId);
  sf_mex_destroy(&c26_b_iCol);
  return c26_y;
}

static real_T c26_d_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  real_T c26_y;
  real_T c26_d0;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_d0, 1, 0, 0U, 0, 0U, 0);
  c26_y = c26_d0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_iCol;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_b_iCol = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_iCol),
    &c26_thisId);
  sf_mex_destroy(&c26_b_iCol);
  *(real_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i27;
  real_T c26_b_inData[2];
  int32_T c26_i28;
  real_T c26_u[2];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i27 = 0; c26_i27 < 2; c26_i27++) {
    c26_b_inData[c26_i27] = (*(real_T (*)[2])c26_inData)[c26_i27];
  }

  for (c26_i28 = 0; c26_i28 < 2; c26_i28++) {
    c26_u[c26_i28] = c26_b_inData[c26_i28];
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
  int32_T c26_i29;
  int32_T c26_i30;
  int32_T c26_i31;
  real_T c26_b_inData[4];
  int32_T c26_i32;
  int32_T c26_i33;
  int32_T c26_i34;
  real_T c26_u[4];
  const mxArray *c26_y = NULL;
  SFc26_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc26_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_i29 = 0;
  for (c26_i30 = 0; c26_i30 < 2; c26_i30++) {
    for (c26_i31 = 0; c26_i31 < 2; c26_i31++) {
      c26_b_inData[c26_i31 + c26_i29] = (*(real_T (*)[4])c26_inData)[c26_i31 +
        c26_i29];
    }

    c26_i29 += 2;
  }

  c26_i32 = 0;
  for (c26_i33 = 0; c26_i33 < 2; c26_i33++) {
    for (c26_i34 = 0; c26_i34 < 2; c26_i34++) {
      c26_u[c26_i34 + c26_i32] = c26_b_inData[c26_i34 + c26_i32];
    }

    c26_i32 += 2;
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, false);
  return c26_mxArrayOutData;
}

const mxArray *sf_c26_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c26_nameCaptureInfo = NULL;
  c26_nameCaptureInfo = NULL;
  sf_mex_assign(&c26_nameCaptureInfo, sf_mex_createstruct("structure", 2, 18, 1),
                false);
  c26_info_helper(&c26_nameCaptureInfo);
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
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("sqrt"), "name", "name", 13);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801586U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(0U), "mFileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_error"), "name", "name",
                  14);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1343801558U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 15);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1286786338U), "fileTimeLo",
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
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "context", "context", 16);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 17);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c26_info, c26_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c26_info, c26_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
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

static real_T c26_mpower(SFc26_hybridSysSimInstanceStruct *chartInstance, real_T
  c26_a)
{
  real_T c26_b_a;
  real_T c26_c_a;
  real_T c26_ak;
  real_T c26_d_a;
  c26_b_a = c26_a;
  c26_c_a = c26_b_a;
  c26_eml_scalar_eg(chartInstance);
  c26_ak = c26_c_a;
  c26_d_a = c26_ak;
  c26_eml_scalar_eg(chartInstance);
  return c26_d_a * c26_d_a;
}

static void c26_eml_scalar_eg(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c26_eml_error(SFc26_hybridSysSimInstanceStruct *chartInstance)
{
  int32_T c26_i35;
  static char_T c26_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c26_u[30];
  const mxArray *c26_y = NULL;
  int32_T c26_i36;
  static char_T c26_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c26_b_u[4];
  const mxArray *c26_b_y = NULL;
  (void)chartInstance;
  for (c26_i35 = 0; c26_i35 < 30; c26_i35++) {
    c26_u[c26_i35] = c26_cv0[c26_i35];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c26_i36 = 0; c26_i36 < 4; c26_i36++) {
    c26_b_u[c26_i36] = c26_cv1[c26_i36];
  }

  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", c26_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c26_y, 14, c26_b_y));
}

static const mxArray *c26_e_sf_marshallOut(void *chartInstanceVoid, void
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

static int32_T c26_e_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  int32_T c26_y;
  int32_T c26_i37;
  (void)chartInstance;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_i37, 1, 6, 0U, 0, 0U, 0);
  c26_y = c26_i37;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
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
  c26_y = c26_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_sfEvent),
    &c26_thisId);
  sf_mex_destroy(&c26_b_sfEvent);
  *(int32_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static uint8_T c26_f_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_hybridSysSim, const char_T *
  c26_identifier)
{
  uint8_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c26_b_is_active_c26_hybridSysSim), &c26_thisId);
  sf_mex_destroy(&c26_b_is_active_c26_hybridSysSim);
  return c26_y;
}

static uint8_T c26_g_emlrt_marshallIn(SFc26_hybridSysSimInstanceStruct
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

static void init_dsm_address_info(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc26_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c26_irOtoL = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c26_iCol = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c26_irOtoLDot = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c26_iFcComp = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c26_posG3 = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c26_R = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c26_iColPos = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c26_cRc = (real_T (*)[2])ssGetOutputPortSignal_wrapper
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

void sf_c26_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2470864416U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1220117392U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4079595176U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3975254439U);
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
    mxArray *mxChecksum = mxCreateString("BTZR7D6zpJM8V0W55xjqrE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[0] = (double)(1);
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[11],T\"cRc\",},{M[1],M[5],T\"iCol\",},{M[1],M[10],T\"iColPos\",},{M[8],M[0],T\"is_active_c26_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
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
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"irOtoL");
          _SFD_SET_DATA_PROPS(1,2,0,1,"iCol");
          _SFD_SET_DATA_PROPS(2,1,1,0,"irOtoLDot");
          _SFD_SET_DATA_PROPS(3,1,1,0,"iFcComp");
          _SFD_SET_DATA_PROPS(4,1,1,0,"posG3");
          _SFD_SET_DATA_PROPS(5,1,1,0,"R");
          _SFD_SET_DATA_PROPS(6,2,0,1,"iColPos");
          _SFD_SET_DATA_PROPS(7,2,0,1,"cRc");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",342,-1,968);
        _SFD_CV_INIT_EML_IF(0,1,0,771,786,883,959);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,774,785,-1,3);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_b_sf_marshallOut,(MexInFcnForType)
          c26_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)
            c26_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)
            c26_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c26_irOtoL);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c26_iCol);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c26_irOtoLDot);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c26_iFcComp);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c26_posG3);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c26_R);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c26_iColPos);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c26_cRc);
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
  return "7tAu0Ax15notrp4GOp2i4";
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
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,26,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,26,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,26);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2084816719U));
  ssSetChecksum1(S,(792576401U));
  ssSetChecksum2(S,(3172708529U));
  ssSetChecksum3(S,(4284650294U));
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
