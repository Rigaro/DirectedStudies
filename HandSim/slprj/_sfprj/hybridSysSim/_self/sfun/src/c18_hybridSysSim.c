/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c18_hybridSysSim.h"
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
static const char * c18_debug_family_names[4] = { "nargin", "nargout", "r",
  "pos" };

/* Function Declarations */
static void initialize_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct *
  chartInstance);
static void enable_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance);
static void c18_update_debugger_state_c18_hybridSysSim
  (SFc18_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_hybridSysSim
  (SFc18_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_st);
static void finalize_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c18_b_pos, const char_T *c18_identifier, real_T c18_y[2]);
static void c18_b_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_y[2]);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_c_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_d_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_e_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_b_is_active_c18_hybridSysSim, const char_T *
  c18_identifier);
static uint8_T c18_f_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info(SFc18_hybridSysSimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc18_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_is_active_c18_hybridSysSim = 0U;
}

static void initialize_params_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c18_update_debugger_state_c18_hybridSysSim
  (SFc18_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c18_hybridSysSim
  (SFc18_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  int32_T c18_i0;
  real_T c18_u[2];
  const mxArray *c18_b_y = NULL;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellmatrix(2, 1), false);
  for (c18_i0 = 0; c18_i0 < 2; c18_i0++) {
    c18_u[c18_i0] = (*chartInstance->c18_pos)[c18_i0];
  }

  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_hoistedGlobal = chartInstance->c18_is_active_c18_hybridSysSim;
  c18_b_u = c18_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y, false);
  return c18_st;
}

static void set_sim_state_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_st)
{
  const mxArray *c18_u;
  real_T c18_dv0[2];
  int32_T c18_i1;
  chartInstance->c18_doneDoubleBufferReInit = true;
  c18_u = sf_mex_dup(c18_st);
  c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 0)),
                       "pos", c18_dv0);
  for (c18_i1 = 0; c18_i1 < 2; c18_i1++) {
    (*chartInstance->c18_pos)[c18_i1] = c18_dv0[c18_i1];
  }

  chartInstance->c18_is_active_c18_hybridSysSim = c18_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 1)),
     "is_active_c18_hybridSysSim");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_hybridSysSim(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  real_T c18_hoistedGlobal;
  real_T c18_b_r;
  uint32_T c18_debug_family_var_map[4];
  real_T c18_nargin = 1.0;
  real_T c18_nargout = 1.0;
  real_T c18_b_pos[2];
  int32_T c18_i2;
  int32_T c18_i3;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c18_r, 0U);
  chartInstance->c18_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
  c18_hoistedGlobal = *chartInstance->c18_r;
  c18_b_r = c18_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c18_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 0U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 1U, c18_b_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_b_r, 2U, c18_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_b_pos, 3U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 3);
  c18_b_pos[0] = 0.0;
  c18_b_pos[1] = c18_b_r;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c18_i2 = 0; c18_i2 < 2; c18_i2++) {
    (*chartInstance->c18_pos)[c18_i2] = c18_b_pos[c18_i2];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c18_i3 = 0; c18_i3 < 2; c18_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c18_pos)[c18_i3], 1U);
  }
}

static void mdl_start_c18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc18_hybridSysSim(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber)
{
  (void)c18_machineNumber;
  (void)c18_chartNumber;
  (void)c18_instanceNumber;
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i4;
  real_T c18_b_inData[2];
  int32_T c18_i5;
  real_T c18_u[2];
  const mxArray *c18_y = NULL;
  SFc18_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i4 = 0; c18_i4 < 2; c18_i4++) {
    c18_b_inData[c18_i4] = (*(real_T (*)[2])c18_inData)[c18_i4];
  }

  for (c18_i5 = 0; c18_i5 < 2; c18_i5++) {
    c18_u[c18_i5] = c18_b_inData[c18_i5];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c18_b_pos, const char_T *c18_identifier, real_T c18_y[2])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_pos), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_pos);
}

static void c18_b_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_y[2])
{
  real_T c18_dv1[2];
  int32_T c18_i6;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c18_i6 = 0; c18_i6 < 2; c18_i6++) {
    c18_y[c18_i6] = c18_dv1[c18_i6];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_pos;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[2];
  int32_T c18_i7;
  SFc18_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c18_b_pos = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_pos), &c18_thisId,
    c18_y);
  sf_mex_destroy(&c18_b_pos);
  for (c18_i7 = 0; c18_i7 < 2; c18_i7++) {
    (*(real_T (*)[2])c18_outData)[c18_i7] = c18_y[c18_i7];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static real_T c18_c_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d0, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_nargout;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c18_nargout = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_nargout),
    &c18_thisId);
  sf_mex_destroy(&c18_nargout);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray *sf_c18_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  sf_mex_assign(&c18_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c18_nameCaptureInfo;
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static int32_T c18_d_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i8;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i8, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i8;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc18_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_e_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_b_is_active_c18_hybridSysSim, const char_T *
  c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_hybridSysSim), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_hybridSysSim);
  return c18_y;
}

static uint8_T c18_f_emlrt_marshallIn(SFc18_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc18_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c18_r = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c18_pos = (real_T (*)[2])ssGetOutputPortSignal_wrapper
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

void sf_c18_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2906270375U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(491573123U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1394548031U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1349837021U);
}

mxArray* sf_c18_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c18_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lQeJhGs7jHh7E9URJzLTYC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxArray* mxPostCodegenInfo = sf_c18_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c18_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c18_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c18_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c18_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c18_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"pos\",},{M[8],M[0],T\"is_active_c18_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc18_hybridSysSimInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           18,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"r");
          _SFD_SET_DATA_PROPS(1,2,0,1,"pos");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,50);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)
            c18_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c18_r);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c18_pos);
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
  return "HWBjNkruhYvliTGXBlpQd";
}

static void sf_opaque_initialize_c18_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc18_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c18_hybridSysSim(void *chartInstanceVar)
{
  enable_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_hybridSysSim(void *chartInstanceVar)
{
  disable_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c18_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c18_hybridSysSim(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c18_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*)
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
  initSimStructsc18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_hybridSysSim(SimStruct *S)
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
    initialize_params_c18_hybridSysSim((SFc18_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,18,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,18);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(549085431U));
  ssSetChecksum1(S,(3158216571U));
  ssSetChecksum2(S,(2297662016U));
  ssSetChecksum3(S,(3005606762U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_hybridSysSim(SimStruct *S)
{
  SFc18_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc18_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc18_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c18_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c18_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c18_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c18_hybridSysSim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_hybridSysSim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c18_hybridSysSim;
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

void c18_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
