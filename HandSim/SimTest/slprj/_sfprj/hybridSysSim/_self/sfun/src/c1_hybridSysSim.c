/* Include files */

#include <stddef.h>
#include "blas.h"
#include "hybridSysSim_sfun.h"
#include "c1_hybridSysSim.h"
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
static const char * c1_debug_family_names[28] = { "CollisionIndexForce",
  "CollisionThumbForce", "GenCordExt", "GeneralCoordinatesDoubleDot",
  "ForceReactionIndex", "ForceReactionThumb", "xDoubleDot", "yDoubleDot",
  "angleDoubleDot", "Positions", "Velocities", "Accelerations", "nargin",
  "nargout", "IndexFext", "ThumbFext", "CollisionCondition", "CollisionPosition",
  "xDotG3", "yDotG3", "angleDot", "xPositionG3", "yPositionG3", "angle", "Acce",
  "Pos", "ForceReactIndex", "ForceReactThumb" };

static const char * c1_b_debug_family_names[5] = { "nargin", "nargout",
  "CollisionCondition", "FingerForce", "ForcesInCollision" };

static const char * c1_c_debug_family_names[7] = { "Theta", "nargin", "nargout",
  "CollisionPosition", "xPositionG3", "yPositionG3", "RotMatrix_0_4" };

static const char * c1_d_debug_family_names[5] = { "nargin", "nargout",
  "RotMatrix_0_4", "Force", "RotatedForce" };

static const char * c1_e_debug_family_names[5] = { "nargin", "nargout",
  "RotatedForceIndex", "RotatedForceThumb", "ResultantTorque" };

static const char * c1_f_debug_family_names[5] = { "nargin", "nargout",
  "IndexForceX", "ThumbForceX", "ResultantForceX" };

static const char * c1_g_debug_family_names[5] = { "nargin", "nargout",
  "IndexForceY", "ThumbForceY", "ResultantForceY" };

static const char * c1_h_debug_family_names[15] = { "RotMatrix_0_4_Index",
  "RotMatrix_0_4_Thumb", "RotatedForceIndex", "RotatedForceThumb",
  "ResultantTorque", "ResultantForceX", "ResultantForceY", "nargin", "nargout",
  "CollisionIndexForce", "CollisionThumbForce", "CollisionPosition",
  "xPositionG3", "yPositionG3", "GenCordExt" };

static const char * c1_i_debug_family_names[6] = { "ForceEvaluation", "Election",
  "nargin", "nargout", "GenCordExt", "FrictionCondition" };

static const char * c1_j_debug_family_names[6] = { "ForceEvaluation", "Election",
  "nargin", "nargout", "GenCordExt", "FrictionCondition" };

static const char * c1_k_debug_family_names[6] = { "ForceEvaluation", "Election",
  "nargin", "nargout", "GenCordExt", "FrictionCondition" };

static const char * c1_l_debug_family_names[5] = { "SignOposite", "nargin",
  "nargout", "GenCordExt", "GeneralCoordinatesDoubleDot" };

static const char * c1_m_debug_family_names[5] = { "nargin", "nargout",
  "GeneralCoordinatesDoubleDot", "ForceFingerComp", "ForceComponent" };

static const char * c1_n_debug_family_names[7] = { "ForceComponentIndex",
  "ForceComponentThumb", "nargin", "nargout", "GeneralCoordinatesDoubleDot",
  "ForceFinger", "ForceReaction" };

static const char * c1_o_debug_family_names[9] = { "Rotation_o_3",
  "Position_G3_P3_frame_0", "Position_o_P3", "nargin", "nargout", "angle",
  "xPositionG3", "yPositionG3", "Positions" };

static const char * c1_p_debug_family_names[9] = { "Velocity_o_G3_frame_0",
  "Velocity_o_P3_frame_0", "nargin", "nargout", "angle", "angleDot", "xDotG3",
  "yDotG3", "Velocities" };

static const char * c1_q_debug_family_names[10] = { "Acceleration_o_G3_frame_0",
  "Acceleration_o_P3_frame_0", "nargin", "nargout", "angle", "angleDot",
  "angleDoubleDot", "xDoubleDot", "yDoubleDot", "Accelerations" };

/* Function Declarations */
static void initialize_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void initialize_params_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void enable_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void disable_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_hybridSysSim
  (SFc1_hybridSysSimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_hybridSysSim
  (SFc1_hybridSysSimInstanceStruct *chartInstance);
static void set_sim_state_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void sf_gateway_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void mdl_start_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void c1_chartstep_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void initSimStructsc1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_b_ForceReactThumb, const char_T *c1_identifier, real_T c1_y
  [2]);
static void c1_b_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_b_Acce, const char_T *c1_identifier, real_T c1_y[3]);
static void c1_d_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_f_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[6]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_g_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_i_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static void c1_RotationToContactFrame(SFc1_hybridSysSimInstanceStruct
  *chartInstance, real_T c1_b_CollisionPosition[2], real_T c1_b_xPositionG3,
  real_T c1_b_yPositionG3, real_T c1_RotMatrix_0_4[4]);
static void c1_eml_scalar_eg(SFc1_hybridSysSimInstanceStruct *chartInstance);
static void c1_ConvesrsionForceContactPoint(SFc1_hybridSysSimInstanceStruct
  *chartInstance, real_T c1_RotMatrix_0_4[4], real_T c1_Force[2], real_T
  c1_RotatedForce[2]);
static void c1_b_eml_scalar_eg(SFc1_hybridSysSimInstanceStruct *chartInstance);
static void c1_eml_xgemm(SFc1_hybridSysSimInstanceStruct *chartInstance, real_T
  c1_A[4], real_T c1_B[2], real_T c1_C[2], real_T c1_b_C[2]);
static void c1_Equation_Of_Motion(SFc1_hybridSysSimInstanceStruct *chartInstance,
  real_T c1_GenCordExt[3], real_T c1_GeneralCoordinatesDoubleDot[9]);
static void c1_ForceReactionFinger(SFc1_hybridSysSimInstanceStruct
  *chartInstance, real_T c1_GeneralCoordinatesDoubleDot[9], real_T
  c1_ForceFinger[2], real_T c1_ForceReaction[2]);
static real_T c1_ForceVectorAnalysis(SFc1_hybridSysSimInstanceStruct
  *chartInstance, real_T c1_GeneralCoordinatesDoubleDot, real_T
  c1_ForceFingerComp);
static real_T c1_mpower(SFc1_hybridSysSimInstanceStruct *chartInstance, real_T
  c1_a);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_j_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_k_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_hybridSysSim, const char_T
  *c1_identifier);
static uint8_T c1_l_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_eml_xgemm(SFc1_hybridSysSimInstanceStruct *chartInstance,
  real_T c1_A[4], real_T c1_B[2], real_T c1_C[2]);
static real_T c1_get_F_k_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_F_k_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_F_k_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_F_k_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_F_k_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_F_k_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_F_s_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_F_s_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_F_s_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_F_s_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_F_s_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_F_s_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_Iz(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex);
static void c1_set_Iz(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                      c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Iz(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_M(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex);
static void c1_set_M(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                     c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_M(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_Position_G3_P3_frame_cylinder
  (SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T c1_elementIndex);
static void c1_set_Position_G3_P3_frame_cylinder(SFc1_hybridSysSimInstanceStruct
  *chartInstance, uint32_T c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Position_G3_P3_frame_cylinder
  (SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T c1_rdOnly);
static real_T c1_get_Position_o_G3(SFc1_hybridSysSimInstanceStruct
  *chartInstance, uint32_T c1_elementIndex);
static void c1_set_Position_o_G3(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Position_o_G3(SFc1_hybridSysSimInstanceStruct
  *chartInstance, uint32_T c1_rdOnly);
static real_T c1_get_R(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex);
static void c1_set_R(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                     c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_R(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_T_k(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_T_k(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_T_k(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_T_s(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_T_s(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_T_s(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_Uck(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_Uck(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Uck(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_Ucs(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_Ucs(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Ucs(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_Uk(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex);
static void c1_set_Uk(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                      c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Uk(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_Urk(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_Urk(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Urk(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_Urs(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex);
static void c1_set_Urs(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Urs(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_Us(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex);
static void c1_set_Us(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                      c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_Us(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static real_T c1_get_g(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex);
static void c1_set_g(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                     c1_elementIndex, real_T c1_elementValue);
static real_T *c1_access_g(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly);
static void init_dsm_address_info(SFc1_hybridSysSimInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_hybridSysSimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_hybridSysSim = 0U;
}

static void initialize_params_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_hybridSysSim
  (SFc1_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_hybridSysSim
  (SFc1_hybridSysSimInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  real_T c1_b_u[2];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i2;
  real_T c1_c_u[2];
  const mxArray *c1_d_y = NULL;
  int32_T c1_i3;
  real_T c1_d_u[2];
  const mxArray *c1_e_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(5, 1), false);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_u[c1_i0] = (*chartInstance->c1_Acce)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_b_u[c1_i1] = (*chartInstance->c1_ForceReactIndex)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_c_u[c1_i2] = (*chartInstance->c1_ForceReactThumb)[c1_i2];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_d_u[c1_i3] = (*chartInstance->c1_Pos)[c1_i3];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_d_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_hybridSysSim;
  c1_e_u = c1_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i4;
  real_T c1_dv1[2];
  int32_T c1_i5;
  real_T c1_dv2[2];
  int32_T c1_i6;
  real_T c1_dv3[2];
  int32_T c1_i7;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "Acce", c1_dv0);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    (*chartInstance->c1_Acce)[c1_i4] = c1_dv0[c1_i4];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "ForceReactIndex", c1_dv1);
  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    (*chartInstance->c1_ForceReactIndex)[c1_i5] = c1_dv1[c1_i5];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                      "ForceReactThumb", c1_dv2);
  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    (*chartInstance->c1_ForceReactThumb)[c1_i6] = c1_dv2[c1_i6];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)), "Pos",
                      c1_dv3);
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    (*chartInstance->c1_Pos)[c1_i7] = c1_dv3[c1_i7];
  }

  chartInstance->c1_is_active_c1_hybridSysSim = c1_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
     "is_active_c1_hybridSysSim");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_hybridSysSim(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_IndexFext)[c1_i8], 0U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_hybridSysSim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_hybridSysSimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_Acce)[c1_i9], 1U);
  }

  for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_ThumbFext)[c1_i10], 2U);
  }

  for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_CollisionCondition)[c1_i11], 3U);
  }

  for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_CollisionPosition)[c1_i12], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_xDotG3, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_yDotG3, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_angleDot, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_xPositionG3, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_yPositionG3, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_angle, 10U);
  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_Pos)[c1_i13], 11U);
  }

  for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_ForceReactIndex)[c1_i14], 12U);
  }

  for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_ForceReactThumb)[c1_i15], 13U);
  }
}

static void mdl_start_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c1_chartstep_c1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  int32_T c1_i16;
  real_T c1_b_IndexFext[2];
  int32_T c1_i17;
  real_T c1_b_ThumbFext[2];
  int32_T c1_i18;
  real_T c1_b_CollisionCondition[2];
  int32_T c1_i19;
  real_T c1_b_CollisionPosition[4];
  real_T c1_b_xDotG3;
  real_T c1_b_yDotG3;
  real_T c1_b_angleDot;
  real_T c1_b_xPositionG3;
  real_T c1_b_yPositionG3;
  real_T c1_b_angle;
  uint32_T c1_debug_family_var_map[28];
  real_T c1_CollisionIndexForce[2];
  real_T c1_CollisionThumbForce[2];
  real_T c1_GenCordExt[3];
  real_T c1_GeneralCoordinatesDoubleDot[9];
  real_T c1_ForceReactionIndex[2];
  real_T c1_ForceReactionThumb[2];
  real_T c1_xDoubleDot;
  real_T c1_yDoubleDot;
  real_T c1_angleDoubleDot;
  real_T c1_Positions[4];
  real_T c1_Velocities[4];
  real_T c1_Accelerations[6];
  real_T c1_nargin = 10.0;
  real_T c1_nargout = 4.0;
  real_T c1_b_Acce[3];
  real_T c1_b_Pos[2];
  real_T c1_b_ForceReactIndex[2];
  real_T c1_b_ForceReactThumb[2];
  real_T c1_c_CollisionCondition;
  int32_T c1_i20;
  real_T c1_FingerForce[2];
  uint32_T c1_b_debug_family_var_map[5];
  real_T c1_b_nargin = 2.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_d_CollisionCondition;
  int32_T c1_i23;
  real_T c1_b_FingerForce[2];
  real_T c1_c_nargin = 2.0;
  real_T c1_c_nargout = 1.0;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  real_T c1_b_CollisionIndexForce[2];
  int32_T c1_i27;
  real_T c1_b_CollisionThumbForce[2];
  int32_T c1_i28;
  real_T c1_c_CollisionPosition[4];
  real_T c1_c_xPositionG3;
  real_T c1_c_yPositionG3;
  uint32_T c1_c_debug_family_var_map[15];
  real_T c1_RotMatrix_0_4_Index[4];
  real_T c1_RotMatrix_0_4_Thumb[4];
  real_T c1_RotatedForceIndex[2];
  real_T c1_RotatedForceThumb[2];
  real_T c1_ResultantTorque;
  real_T c1_ResultantForceX;
  real_T c1_ResultantForceY;
  real_T c1_d_nargin = 5.0;
  real_T c1_d_nargout = 1.0;
  int32_T c1_i29;
  real_T c1_d_CollisionPosition[2];
  real_T c1_dv4[4];
  int32_T c1_i30;
  int32_T c1_i31;
  real_T c1_e_CollisionPosition[2];
  real_T c1_dv5[4];
  int32_T c1_i32;
  int32_T c1_i33;
  real_T c1_b_RotMatrix_0_4_Index[4];
  int32_T c1_i34;
  real_T c1_c_CollisionIndexForce[2];
  real_T c1_dv6[2];
  int32_T c1_i35;
  int32_T c1_i36;
  real_T c1_b_RotMatrix_0_4_Thumb[4];
  int32_T c1_i37;
  real_T c1_c_CollisionThumbForce[2];
  real_T c1_dv7[2];
  int32_T c1_i38;
  real_T c1_b_RotatedForceIndex;
  real_T c1_b_RotatedForceThumb;
  real_T c1_e_nargin = 2.0;
  real_T c1_e_nargout = 1.0;
  real_T c1_IndexForceX;
  real_T c1_ThumbForceX;
  real_T c1_f_nargin = 2.0;
  real_T c1_f_nargout = 1.0;
  real_T c1_IndexForceY;
  real_T c1_ThumbForceY;
  real_T c1_g_nargin = 2.0;
  real_T c1_g_nargout = 1.0;
  int32_T c1_i39;
  real_T c1_b_GenCordExt[3];
  real_T c1_dv8[9];
  int32_T c1_i40;
  int32_T c1_i41;
  real_T c1_b_GeneralCoordinatesDoubleDot[9];
  int32_T c1_i42;
  real_T c1_d_CollisionIndexForce[2];
  real_T c1_dv9[2];
  int32_T c1_i43;
  int32_T c1_i44;
  real_T c1_c_GeneralCoordinatesDoubleDot[9];
  int32_T c1_i45;
  real_T c1_d_CollisionThumbForce[2];
  real_T c1_dv10[2];
  int32_T c1_i46;
  real_T c1_c_angle;
  real_T c1_d_xPositionG3;
  real_T c1_d_yPositionG3;
  uint32_T c1_d_debug_family_var_map[9];
  real_T c1_Rotation_o_3[4];
  real_T c1_Position_G3_P3_frame_0[2];
  real_T c1_Position_o_P3[2];
  real_T c1_h_nargin = 3.0;
  real_T c1_h_nargout = 1.0;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  int32_T c1_i47;
  real_T c1_a[4];
  int32_T c1_i48;
  int32_T c1_i49;
  real_T c1_b_angleDoubleDot[2];
  int32_T c1_i50;
  real_T c1_b_a[4];
  int32_T c1_i51;
  real_T c1_dv11[2];
  int32_T c1_i52;
  real_T c1_e_xPositionG3[2];
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  real_T c1_d_angle;
  real_T c1_c_angleDot;
  real_T c1_c_xDotG3;
  real_T c1_c_yDotG3;
  real_T c1_Velocity_o_G3_frame_0[2];
  real_T c1_Velocity_o_P3_frame_0[2];
  real_T c1_i_nargin = 4.0;
  real_T c1_i_nargout = 1.0;
  real_T c1_g_hoistedGlobal;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_h_hoistedGlobal;
  real_T c1_k_x;
  real_T c1_l_x;
  int32_T c1_i56;
  int32_T c1_i57;
  real_T c1_e_angle;
  real_T c1_d_angleDot;
  real_T c1_c_angleDoubleDot;
  real_T c1_b_xDoubleDot;
  real_T c1_b_yDoubleDot;
  uint32_T c1_e_debug_family_var_map[10];
  real_T c1_Acceleration_o_G3_frame_0[2];
  real_T c1_Acceleration_o_P3_frame_0[2];
  real_T c1_j_nargin = 5.0;
  real_T c1_j_nargout = 1.0;
  real_T c1_i_hoistedGlobal;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_j_hoistedGlobal;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_k_hoistedGlobal;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_l_hoistedGlobal;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_d0;
  real_T c1_d1;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i60;
  int32_T c1_i61;
  static int32_T c1_iv0[3] = { 0, 1, 4 };

  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *chartInstance->c1_xDotG3;
  c1_b_hoistedGlobal = *chartInstance->c1_yDotG3;
  c1_c_hoistedGlobal = *chartInstance->c1_angleDot;
  c1_d_hoistedGlobal = *chartInstance->c1_xPositionG3;
  c1_e_hoistedGlobal = *chartInstance->c1_yPositionG3;
  c1_f_hoistedGlobal = *chartInstance->c1_angle;
  for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
    c1_b_IndexFext[c1_i16] = (*chartInstance->c1_IndexFext)[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
    c1_b_ThumbFext[c1_i17] = (*chartInstance->c1_ThumbFext)[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
    c1_b_CollisionCondition[c1_i18] = (*chartInstance->c1_CollisionCondition)
      [c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 4; c1_i19++) {
    c1_b_CollisionPosition[c1_i19] = (*chartInstance->c1_CollisionPosition)
      [c1_i19];
  }

  c1_b_xDotG3 = c1_hoistedGlobal;
  c1_b_yDotG3 = c1_b_hoistedGlobal;
  c1_b_angleDot = c1_c_hoistedGlobal;
  c1_b_xPositionG3 = c1_d_hoistedGlobal;
  c1_b_yPositionG3 = c1_e_hoistedGlobal;
  c1_b_angle = c1_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 28U, 28U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_CollisionIndexForce, 0U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_CollisionThumbForce, 1U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_GenCordExt, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_GeneralCoordinatesDoubleDot, 3U,
    c1_g_sf_marshallOut, c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ForceReactionIndex, 4U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ForceReactionThumb, 5U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_xDoubleDot, 6U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_yDoubleDot, 7U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_angleDoubleDot, 8U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Positions, 9U, c1_d_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Velocities, 10U, c1_d_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Accelerations, 11U,
    c1_f_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 12U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 13U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_IndexFext, 14U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_ThumbFext, 15U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_CollisionCondition, 16U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_CollisionPosition, 17U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_xDotG3, 18U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_yDotG3, 19U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_angleDot, 20U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_xPositionG3, 21U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_yPositionG3, 22U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_angle, 23U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_Acce, 24U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_Pos, 25U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_ForceReactIndex, 26U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_ForceReactThumb, 27U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_c_CollisionCondition = c1_b_CollisionCondition[0];
  for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
    c1_FingerForce[c1_i20] = c1_b_IndexFext[c1_i20];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_b_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_CollisionCondition, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_FingerForce, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_CollisionIndexForce, 4U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 12);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 161U);
  if (CV_EML_IF(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, c1_c_CollisionCondition,
        1.0, -1, 0U, c1_c_CollisionCondition == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 162U);
    for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
      c1_CollisionIndexForce[c1_i21] = c1_FingerForce[c1_i21];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 164U);
    for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
      c1_CollisionIndexForce[c1_i22] = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -164);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_d_CollisionCondition = c1_b_CollisionCondition[1];
  for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
    c1_b_FingerForce[c1_i23] = c1_b_ThumbFext[c1_i23];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_b_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_CollisionCondition, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_FingerForce, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_CollisionThumbForce, 4U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 12);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 161U);
  if (CV_EML_IF(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, c1_d_CollisionCondition,
        1.0, -1, 0U, c1_d_CollisionCondition == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 162U);
    for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
      c1_CollisionThumbForce[c1_i24] = c1_b_FingerForce[c1_i24];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 164U);
    for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
      c1_CollisionThumbForce[c1_i25] = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -164);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    c1_b_CollisionIndexForce[c1_i26] = c1_CollisionIndexForce[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
    c1_b_CollisionThumbForce[c1_i27] = c1_CollisionThumbForce[c1_i27];
  }

  for (c1_i28 = 0; c1_i28 < 4; c1_i28++) {
    c1_c_CollisionPosition[c1_i28] = c1_b_CollisionPosition[c1_i28];
  }

  c1_c_xPositionG3 = c1_b_xPositionG3;
  c1_c_yPositionG3 = c1_b_yPositionG3;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c1_h_debug_family_names,
    c1_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_RotMatrix_0_4_Index, 0U,
    c1_d_sf_marshallOut, c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_RotMatrix_0_4_Thumb, 1U,
    c1_d_sf_marshallOut, c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_RotatedForceIndex, 2U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_RotatedForceThumb, 3U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ResultantTorque, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ResultantForceX, 5U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ResultantForceY, 6U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 7U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 8U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_CollisionIndexForce, 9U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_CollisionThumbForce, 10U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_c_CollisionPosition, 11U,
    c1_d_sf_marshallOut, c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_xPositionG3, 12U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_yPositionG3, 13U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_GenCordExt, 14U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  CV_EML_FCN(0, 15);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 194U);
  for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
    c1_d_CollisionPosition[c1_i29] = c1_c_CollisionPosition[c1_i29];
  }

  c1_RotationToContactFrame(chartInstance, c1_d_CollisionPosition,
    c1_c_xPositionG3, c1_c_yPositionG3, c1_dv4);
  for (c1_i30 = 0; c1_i30 < 4; c1_i30++) {
    c1_RotMatrix_0_4_Index[c1_i30] = c1_dv4[c1_i30];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 195U);
  for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
    c1_e_CollisionPosition[c1_i31] = c1_c_CollisionPosition[c1_i31 + 2];
  }

  c1_RotationToContactFrame(chartInstance, c1_e_CollisionPosition,
    c1_c_xPositionG3, c1_c_yPositionG3, c1_dv5);
  for (c1_i32 = 0; c1_i32 < 4; c1_i32++) {
    c1_RotMatrix_0_4_Thumb[c1_i32] = c1_dv5[c1_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 196U);
  for (c1_i33 = 0; c1_i33 < 4; c1_i33++) {
    c1_b_RotMatrix_0_4_Index[c1_i33] = c1_RotMatrix_0_4_Index[c1_i33];
  }

  for (c1_i34 = 0; c1_i34 < 2; c1_i34++) {
    c1_c_CollisionIndexForce[c1_i34] = c1_b_CollisionIndexForce[c1_i34];
  }

  c1_ConvesrsionForceContactPoint(chartInstance, c1_b_RotMatrix_0_4_Index,
    c1_c_CollisionIndexForce, c1_dv6);
  for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
    c1_RotatedForceIndex[c1_i35] = c1_dv6[c1_i35];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 197U);
  for (c1_i36 = 0; c1_i36 < 4; c1_i36++) {
    c1_b_RotMatrix_0_4_Thumb[c1_i36] = c1_RotMatrix_0_4_Thumb[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
    c1_c_CollisionThumbForce[c1_i37] = c1_b_CollisionThumbForce[c1_i37];
  }

  c1_ConvesrsionForceContactPoint(chartInstance, c1_b_RotMatrix_0_4_Thumb,
    c1_c_CollisionThumbForce, c1_dv7);
  for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
    c1_RotatedForceThumb[c1_i38] = c1_dv7[c1_i38];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 198U);
  c1_b_RotatedForceIndex = c1_RotatedForceIndex[1];
  c1_b_RotatedForceThumb = c1_RotatedForceThumb[1];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_e_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_RotatedForceIndex, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_RotatedForceThumb, 3U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ResultantTorque, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  CV_EML_FCN(0, 9);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 142U);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 143U);
  c1_ResultantTorque = c1_get_R(chartInstance, 0) * c1_b_RotatedForceIndex +
    c1_get_R(chartInstance, 0) * c1_b_RotatedForceThumb;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -143);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 199U);
  c1_IndexForceX = c1_b_CollisionIndexForce[0];
  c1_ThumbForceX = c1_b_CollisionThumbForce[0];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_f_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_IndexForceX, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThumbForceX, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ResultantForceX, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  CV_EML_FCN(0, 10);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 149U);
  c1_ResultantForceX = c1_IndexForceX + c1_ThumbForceX;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -149);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 200U);
  c1_IndexForceY = c1_b_CollisionIndexForce[1];
  c1_ThumbForceY = c1_b_CollisionThumbForce[1];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_g_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_IndexForceY, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThumbForceY, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ResultantForceY, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  CV_EML_FCN(0, 11);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 155U);
  c1_ResultantForceY = c1_IndexForceY + c1_ThumbForceY;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -155);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 201U);
  c1_GenCordExt[0] = c1_ResultantForceX;
  c1_GenCordExt[1] = c1_ResultantForceY;
  c1_GenCordExt[2] = c1_ResultantTorque;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -201);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  for (c1_i39 = 0; c1_i39 < 3; c1_i39++) {
    c1_b_GenCordExt[c1_i39] = c1_GenCordExt[c1_i39];
  }

  c1_Equation_Of_Motion(chartInstance, c1_b_GenCordExt, c1_dv8);
  for (c1_i40 = 0; c1_i40 < 9; c1_i40++) {
    c1_GeneralCoordinatesDoubleDot[c1_i40] = c1_dv8[c1_i40];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  for (c1_i41 = 0; c1_i41 < 9; c1_i41++) {
    c1_b_GeneralCoordinatesDoubleDot[c1_i41] =
      c1_GeneralCoordinatesDoubleDot[c1_i41];
  }

  for (c1_i42 = 0; c1_i42 < 2; c1_i42++) {
    c1_d_CollisionIndexForce[c1_i42] = c1_CollisionIndexForce[c1_i42];
  }

  c1_ForceReactionFinger(chartInstance, c1_b_GeneralCoordinatesDoubleDot,
    c1_d_CollisionIndexForce, c1_dv9);
  for (c1_i43 = 0; c1_i43 < 2; c1_i43++) {
    c1_ForceReactionIndex[c1_i43] = c1_dv9[c1_i43];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  for (c1_i44 = 0; c1_i44 < 9; c1_i44++) {
    c1_c_GeneralCoordinatesDoubleDot[c1_i44] =
      c1_GeneralCoordinatesDoubleDot[c1_i44];
  }

  for (c1_i45 = 0; c1_i45 < 2; c1_i45++) {
    c1_d_CollisionThumbForce[c1_i45] = c1_CollisionThumbForce[c1_i45];
  }

  c1_ForceReactionFinger(chartInstance, c1_c_GeneralCoordinatesDoubleDot,
    c1_d_CollisionThumbForce, c1_dv10);
  for (c1_i46 = 0; c1_i46 < 2; c1_i46++) {
    c1_ForceReactionThumb[c1_i46] = c1_dv10[c1_i46];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_xDoubleDot = c1_GeneralCoordinatesDoubleDot[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  c1_yDoubleDot = c1_GeneralCoordinatesDoubleDot[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
  c1_angleDoubleDot = c1_GeneralCoordinatesDoubleDot[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  c1_c_angle = c1_b_angle;
  c1_d_xPositionG3 = c1_b_xPositionG3;
  c1_d_yPositionG3 = c1_b_yPositionG3;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_o_debug_family_names,
    c1_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Rotation_o_3, 0U, c1_d_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Position_G3_P3_frame_0, 1U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Position_o_P3, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_angle, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_xPositionG3, 6U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_yPositionG3, 7U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Positions, 8U, c1_d_sf_marshallOut,
    c1_e_sf_marshallIn);
  CV_EML_FCN(0, 3);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 93);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 94);
  c1_x = c1_c_angle;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarCos(c1_b_x);
  c1_c_x = c1_c_angle;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarSin(c1_d_x);
  c1_e_x = c1_c_angle;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarSin(c1_f_x);
  c1_g_x = c1_c_angle;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_Rotation_o_3[0] = c1_b_x;
  c1_Rotation_o_3[2] = -c1_d_x;
  c1_Rotation_o_3[1] = c1_f_x;
  c1_Rotation_o_3[3] = c1_h_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 95);
  for (c1_i47 = 0; c1_i47 < 4; c1_i47++) {
    c1_a[c1_i47] = c1_Rotation_o_3[c1_i47];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i48 = 0; c1_i48 < 2; c1_i48++) {
    c1_Position_G3_P3_frame_0[c1_i48] = 0.0;
  }

  for (c1_i49 = 0; c1_i49 < 2; c1_i49++) {
    c1_b_angleDoubleDot[c1_i49] = 0.0;
  }

  for (c1_i50 = 0; c1_i50 < 4; c1_i50++) {
    c1_b_a[c1_i50] = c1_a[c1_i50];
  }

  for (c1_i51 = 0; c1_i51 < 2; c1_i51++) {
    c1_dv11[c1_i51] = c1_get_Position_G3_P3_frame_cylinder(chartInstance, c1_i51);
  }

  c1_b_eml_xgemm(chartInstance, c1_b_a, c1_dv11, c1_b_angleDoubleDot);
  for (c1_i52 = 0; c1_i52 < 2; c1_i52++) {
    c1_Position_G3_P3_frame_0[c1_i52] = c1_b_angleDoubleDot[c1_i52];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 96);
  c1_e_xPositionG3[0] = c1_d_xPositionG3;
  c1_e_xPositionG3[1] = c1_d_yPositionG3;
  for (c1_i53 = 0; c1_i53 < 2; c1_i53++) {
    c1_Position_o_P3[c1_i53] = c1_e_xPositionG3[c1_i53] +
      c1_Position_G3_P3_frame_0[c1_i53];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 97);
  for (c1_i54 = 0; c1_i54 < 2; c1_i54++) {
    c1_Positions[c1_i54] = c1_get_Position_o_G3(chartInstance, c1_i54);
  }

  for (c1_i55 = 0; c1_i55 < 2; c1_i55++) {
    c1_Positions[c1_i55 + 2] = c1_Position_o_P3[c1_i55];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -97);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  c1_d_angle = c1_b_angle;
  c1_c_angleDot = c1_b_angleDot;
  c1_c_xDotG3 = c1_b_xDotG3;
  c1_c_yDotG3 = c1_b_yDotG3;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_p_debug_family_names,
    c1_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Velocity_o_G3_frame_0, 0U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Velocity_o_P3_frame_0, 1U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_angle, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_angleDot, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_xDotG3, 6U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_yDotG3, 7U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Velocities, 8U, c1_d_sf_marshallOut,
    c1_e_sf_marshallIn);
  CV_EML_FCN(0, 4);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 103);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 104);
  c1_Velocity_o_G3_frame_0[0] = c1_c_xDotG3;
  c1_Velocity_o_G3_frame_0[1] = c1_c_yDotG3;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 105);
  c1_g_hoistedGlobal = c1_get_R(chartInstance, 0);
  c1_i_x = c1_d_angle;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarCos(c1_j_x);
  c1_h_hoistedGlobal = c1_get_R(chartInstance, 0);
  c1_k_x = c1_d_angle;
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarSin(c1_l_x);
  c1_Velocity_o_P3_frame_0[0] = c1_c_xDotG3 - c1_g_hoistedGlobal * c1_j_x *
    c1_c_angleDot;
  c1_Velocity_o_P3_frame_0[1] = c1_c_yDotG3 - c1_h_hoistedGlobal * c1_l_x *
    c1_c_angleDot;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 106);
  for (c1_i56 = 0; c1_i56 < 2; c1_i56++) {
    c1_Velocities[c1_i56] = c1_Velocity_o_G3_frame_0[c1_i56];
  }

  for (c1_i57 = 0; c1_i57 < 2; c1_i57++) {
    c1_Velocities[c1_i57 + 2] = c1_Velocity_o_P3_frame_0[c1_i57];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -106);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_e_angle = c1_b_angle;
  c1_d_angleDot = c1_b_angleDot;
  c1_c_angleDoubleDot = c1_angleDoubleDot;
  c1_b_xDoubleDot = c1_xDoubleDot;
  c1_b_yDoubleDot = c1_yDoubleDot;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c1_q_debug_family_names,
    c1_e_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Acceleration_o_G3_frame_0, 0U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Acceleration_o_P3_frame_0, 1U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_angle, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_angleDot, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_angleDoubleDot, 6U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_xDoubleDot, 7U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_yDoubleDot, 8U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Accelerations, 9U, c1_f_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_EML_FCN(0, 5);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 112);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 113);
  c1_Acceleration_o_G3_frame_0[0] = c1_b_xDoubleDot;
  c1_Acceleration_o_G3_frame_0[1] = c1_b_yDoubleDot;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 114);
  c1_i_hoistedGlobal = c1_get_R(chartInstance, 0);
  c1_m_x = c1_e_angle;
  c1_n_x = c1_m_x;
  c1_n_x = muDoubleScalarSin(c1_n_x);
  c1_j_hoistedGlobal = c1_get_R(chartInstance, 0);
  c1_o_x = c1_e_angle;
  c1_p_x = c1_o_x;
  c1_p_x = muDoubleScalarCos(c1_p_x);
  c1_k_hoistedGlobal = c1_get_R(chartInstance, 0);
  c1_q_x = c1_e_angle;
  c1_r_x = c1_q_x;
  c1_r_x = muDoubleScalarCos(c1_r_x);
  c1_l_hoistedGlobal = c1_get_R(chartInstance, 0);
  c1_s_x = c1_e_angle;
  c1_t_x = c1_s_x;
  c1_t_x = muDoubleScalarSin(c1_t_x);
  c1_d0 = c1_mpower(chartInstance, c1_d_angleDot);
  c1_d1 = c1_mpower(chartInstance, c1_d_angleDot);
  c1_Acceleration_o_P3_frame_0[0] = (c1_b_xDoubleDot + c1_i_hoistedGlobal *
    c1_n_x * c1_d0) - c1_j_hoistedGlobal * c1_p_x * c1_c_angleDoubleDot;
  c1_Acceleration_o_P3_frame_0[1] = (c1_b_yDoubleDot - c1_k_hoistedGlobal *
    c1_r_x * c1_d1) - c1_l_hoistedGlobal * c1_t_x * c1_c_angleDoubleDot;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 116);
  c1_b_angleDoubleDot[0] = c1_c_angleDoubleDot;
  c1_b_angleDoubleDot[1] = 0.0;
  for (c1_i58 = 0; c1_i58 < 2; c1_i58++) {
    c1_Accelerations[c1_i58] = c1_Acceleration_o_G3_frame_0[c1_i58];
  }

  for (c1_i59 = 0; c1_i59 < 2; c1_i59++) {
    c1_Accelerations[c1_i59 + 2] = c1_Acceleration_o_P3_frame_0[c1_i59];
  }

  for (c1_i60 = 0; c1_i60 < 2; c1_i60++) {
    c1_Accelerations[c1_i60 + 4] = c1_b_angleDoubleDot[c1_i60];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -116);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
  for (c1_i61 = 0; c1_i61 < 3; c1_i61++) {
    c1_b_Acce[c1_i61] = c1_Accelerations[c1_iv0[c1_i61]];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
  for (c1_i62 = 0; c1_i62 < 2; c1_i62++) {
    c1_b_Pos[c1_i62] = c1_Positions[c1_i62 + 2];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
  for (c1_i63 = 0; c1_i63 < 2; c1_i63++) {
    c1_b_ForceReactIndex[c1_i63] = c1_ForceReactionIndex[c1_i63];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  for (c1_i64 = 0; c1_i64 < 2; c1_i64++) {
    c1_b_ForceReactThumb[c1_i64] = c1_ForceReactionThumb[c1_i64];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -39);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i65 = 0; c1_i65 < 3; c1_i65++) {
    (*chartInstance->c1_Acce)[c1_i65] = c1_b_Acce[c1_i65];
  }

  for (c1_i66 = 0; c1_i66 < 2; c1_i66++) {
    (*chartInstance->c1_Pos)[c1_i66] = c1_b_Pos[c1_i66];
  }

  for (c1_i67 = 0; c1_i67 < 2; c1_i67++) {
    (*chartInstance->c1_ForceReactIndex)[c1_i67] = c1_b_ForceReactIndex[c1_i67];
  }

  for (c1_i68 = 0; c1_i68 < 2; c1_i68++) {
    (*chartInstance->c1_ForceReactThumb)[c1_i68] = c1_b_ForceReactThumb[c1_i68];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_hybridSysSim(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i69;
  real_T c1_b_inData[2];
  int32_T c1_i70;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i69 = 0; c1_i69 < 2; c1_i69++) {
    c1_b_inData[c1_i69] = (*(real_T (*)[2])c1_inData)[c1_i69];
  }

  for (c1_i70 = 0; c1_i70 < 2; c1_i70++) {
    c1_u[c1_i70] = c1_b_inData[c1_i70];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_b_ForceReactThumb, const char_T *c1_identifier, real_T c1_y
  [2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_ForceReactThumb),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_ForceReactThumb);
}

static void c1_b_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv12[2];
  int32_T c1_i71;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv12, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i71 = 0; c1_i71 < 2; c1_i71++) {
    c1_y[c1_i71] = c1_dv12[c1_i71];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_ForceReactThumb;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i72;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_b_ForceReactThumb = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_ForceReactThumb),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_ForceReactThumb);
  for (c1_i72 = 0; c1_i72 < 2; c1_i72++) {
    (*(real_T (*)[2])c1_outData)[c1_i72] = c1_y[c1_i72];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i73;
  real_T c1_b_inData[3];
  int32_T c1_i74;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i73 = 0; c1_i73 < 3; c1_i73++) {
    c1_b_inData[c1_i73] = (*(real_T (*)[3])c1_inData)[c1_i73];
  }

  for (c1_i74 = 0; c1_i74 < 3; c1_i74++) {
    c1_u[c1_i74] = c1_b_inData[c1_i74];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_b_Acce, const char_T *c1_identifier, real_T c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Acce), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Acce);
}

static void c1_d_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv13[3];
  int32_T c1_i75;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv13, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i75 = 0; c1_i75 < 3; c1_i75++) {
    c1_y[c1_i75] = c1_dv13[c1_i75];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Acce;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i76;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_b_Acce = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Acce), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_Acce);
  for (c1_i76 = 0; c1_i76 < 3; c1_i76++) {
    (*(real_T (*)[3])c1_outData)[c1_i76] = c1_y[c1_i76];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  real_T c1_b_inData[4];
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i77 = 0;
  for (c1_i78 = 0; c1_i78 < 2; c1_i78++) {
    for (c1_i79 = 0; c1_i79 < 2; c1_i79++) {
      c1_b_inData[c1_i79 + c1_i77] = (*(real_T (*)[4])c1_inData)[c1_i79 + c1_i77];
    }

    c1_i77 += 2;
  }

  c1_i80 = 0;
  for (c1_i81 = 0; c1_i81 < 2; c1_i81++) {
    for (c1_i82 = 0; c1_i82 < 2; c1_i82++) {
      c1_u[c1_i82 + c1_i80] = c1_b_inData[c1_i82 + c1_i80];
    }

    c1_i80 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i83;
  real_T c1_b_inData[2];
  int32_T c1_i84;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i83 = 0; c1_i83 < 2; c1_i83++) {
    c1_b_inData[c1_i83] = (*(real_T (*)[2])c1_inData)[c1_i83];
  }

  for (c1_i84 = 0; c1_i84 < 2; c1_i84++) {
    c1_u[c1_i84] = c1_b_inData[c1_i84];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  real_T c1_b_inData[6];
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i90;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i85 = 0;
  for (c1_i86 = 0; c1_i86 < 3; c1_i86++) {
    for (c1_i87 = 0; c1_i87 < 2; c1_i87++) {
      c1_b_inData[c1_i87 + c1_i85] = (*(real_T (*)[6])c1_inData)[c1_i87 + c1_i85];
    }

    c1_i85 += 2;
  }

  c1_i88 = 0;
  for (c1_i89 = 0; c1_i89 < 3; c1_i89++) {
    for (c1_i90 = 0; c1_i90 < 2; c1_i90++) {
      c1_u[c1_i90 + c1_i88] = c1_b_inData[c1_i90 + c1_i88];
    }

    c1_i88 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[6])
{
  real_T c1_dv14[6];
  int32_T c1_i91;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv14, 1, 0, 0U, 1, 0U, 2, 2, 3);
  for (c1_i91 = 0; c1_i91 < 6; c1_i91++) {
    c1_y[c1_i91] = c1_dv14[c1_i91];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Accelerations;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[6];
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_Accelerations = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Accelerations), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_Accelerations);
  c1_i92 = 0;
  for (c1_i93 = 0; c1_i93 < 3; c1_i93++) {
    for (c1_i94 = 0; c1_i94 < 2; c1_i94++) {
      (*(real_T (*)[6])c1_outData)[c1_i94 + c1_i92] = c1_y[c1_i94 + c1_i92];
    }

    c1_i92 += 2;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_g_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv15[4];
  int32_T c1_i95;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv15, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c1_i95 = 0; c1_i95 < 4; c1_i95++) {
    c1_y[c1_i95] = c1_dv15[c1_i95];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Velocities;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_Velocities = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Velocities), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_Velocities);
  c1_i96 = 0;
  for (c1_i97 = 0; c1_i97 < 2; c1_i97++) {
    for (c1_i98 = 0; c1_i98 < 2; c1_i98++) {
      (*(real_T (*)[4])c1_outData)[c1_i98 + c1_i96] = c1_y[c1_i98 + c1_i96];
    }

    c1_i96 += 2;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i99;
  int32_T c1_i100;
  int32_T c1_i101;
  real_T c1_b_inData[9];
  int32_T c1_i102;
  int32_T c1_i103;
  int32_T c1_i104;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i99 = 0;
  for (c1_i100 = 0; c1_i100 < 3; c1_i100++) {
    for (c1_i101 = 0; c1_i101 < 3; c1_i101++) {
      c1_b_inData[c1_i101 + c1_i99] = (*(real_T (*)[9])c1_inData)[c1_i101 +
        c1_i99];
    }

    c1_i99 += 3;
  }

  c1_i102 = 0;
  for (c1_i103 = 0; c1_i103 < 3; c1_i103++) {
    for (c1_i104 = 0; c1_i104 < 3; c1_i104++) {
      c1_u[c1_i104 + c1_i102] = c1_b_inData[c1_i104 + c1_i102];
    }

    c1_i102 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv16[9];
  int32_T c1_i105;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv16, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i105 = 0; c1_i105 < 9; c1_i105++) {
    c1_y[c1_i105] = c1_dv16[c1_i105];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_GeneralCoordinatesDoubleDot;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i106;
  int32_T c1_i107;
  int32_T c1_i108;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_GeneralCoordinatesDoubleDot = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_GeneralCoordinatesDoubleDot),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_GeneralCoordinatesDoubleDot);
  c1_i106 = 0;
  for (c1_i107 = 0; c1_i107 < 3; c1_i107++) {
    for (c1_i108 = 0; c1_i108 < 3; c1_i108++) {
      (*(real_T (*)[9])c1_outData)[c1_i108 + c1_i106] = c1_y[c1_i108 + c1_i106];
    }

    c1_i106 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_i_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv17[2];
  int32_T c1_i109;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv17, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c1_i109 = 0; c1_i109 < 2; c1_i109++) {
    c1_y[c1_i109] = c1_dv17[c1_i109];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_CollisionPosition;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i110;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_b_CollisionPosition = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_CollisionPosition),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_CollisionPosition);
  for (c1_i110 = 0; c1_i110 < 2; c1_i110++) {
    (*(real_T (*)[2])c1_outData)[c1_i110] = c1_y[c1_i110];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i111;
  char_T c1_b_inData[5];
  int32_T c1_i112;
  char_T c1_u[5];
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i111 = 0; c1_i111 < 5; c1_i111++) {
    c1_b_inData[c1_i111] = (*(char_T (*)[5])c1_inData)[c1_i111];
  }

  for (c1_i112 = 0; c1_i112 < 5; c1_i112++) {
    c1_u[c1_i112] = c1_b_inData[c1_i112];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 5), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i113;
  char_T c1_b_inData[3];
  int32_T c1_i114;
  char_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i113 = 0; c1_i113 < 3; c1_i113++) {
    c1_b_inData[c1_i113] = (*(char_T (*)[3])c1_inData)[c1_i113];
  }

  for (c1_i114 = 0; c1_i114 < 3; c1_i114++) {
    c1_u[c1_i114] = c1_b_inData[c1_i114];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_hybridSysSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 46, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  const mxArray *c1_rhs23 = NULL;
  const mxArray *c1_lhs23 = NULL;
  const mxArray *c1_rhs24 = NULL;
  const mxArray *c1_lhs24 = NULL;
  const mxArray *c1_rhs25 = NULL;
  const mxArray *c1_lhs25 = NULL;
  const mxArray *c1_rhs26 = NULL;
  const mxArray *c1_lhs26 = NULL;
  const mxArray *c1_rhs27 = NULL;
  const mxArray *c1_lhs27 = NULL;
  const mxArray *c1_rhs28 = NULL;
  const mxArray *c1_lhs28 = NULL;
  const mxArray *c1_rhs29 = NULL;
  const mxArray *c1_lhs29 = NULL;
  const mxArray *c1_rhs30 = NULL;
  const mxArray *c1_lhs30 = NULL;
  const mxArray *c1_rhs31 = NULL;
  const mxArray *c1_lhs31 = NULL;
  const mxArray *c1_rhs32 = NULL;
  const mxArray *c1_lhs32 = NULL;
  const mxArray *c1_rhs33 = NULL;
  const mxArray *c1_lhs33 = NULL;
  const mxArray *c1_rhs34 = NULL;
  const mxArray *c1_lhs34 = NULL;
  const mxArray *c1_rhs35 = NULL;
  const mxArray *c1_lhs35 = NULL;
  const mxArray *c1_rhs36 = NULL;
  const mxArray *c1_lhs36 = NULL;
  const mxArray *c1_rhs37 = NULL;
  const mxArray *c1_lhs37 = NULL;
  const mxArray *c1_rhs38 = NULL;
  const mxArray *c1_lhs38 = NULL;
  const mxArray *c1_rhs39 = NULL;
  const mxArray *c1_lhs39 = NULL;
  const mxArray *c1_rhs40 = NULL;
  const mxArray *c1_lhs40 = NULL;
  const mxArray *c1_rhs41 = NULL;
  const mxArray *c1_lhs41 = NULL;
  const mxArray *c1_rhs42 = NULL;
  const mxArray *c1_lhs42 = NULL;
  const mxArray *c1_rhs43 = NULL;
  const mxArray *c1_lhs43 = NULL;
  const mxArray *c1_rhs44 = NULL;
  const mxArray *c1_lhs44 = NULL;
  const mxArray *c1_rhs45 = NULL;
  const mxArray *c1_lhs45 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("atan2"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286786320U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("cos"), "name", "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395292496U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286786322U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("sin"), "name", "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395292504U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286786336U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1383841294U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1323134578U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375951890U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1393294858U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778972U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("sign"), "name", "name", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363677856U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c1_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1356505494U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c1_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("abs"), "name", "name", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363677852U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c1_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c1_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286786312U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c1_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778848U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1369981086U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c1_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389681774U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c1_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rdivide"), "name", "name", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363677880U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c1_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c1_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286786396U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c1_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_div"), "name", "name", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1386387952U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c1_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1410778970U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c1_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mpower"), "name", "name", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363677878U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c1_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c1_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("ismatrix"), "name", "name", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1331268858U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c1_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("power"), "name", "name", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395292506U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c1_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c1_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c1_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c1_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("floor"), "name", "name", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363677854U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c1_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395895856U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c1_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286786326U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c1_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375951888U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c1_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs45), "lhs", "lhs",
                  45);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
  sf_mex_destroy(&c1_rhs23);
  sf_mex_destroy(&c1_lhs23);
  sf_mex_destroy(&c1_rhs24);
  sf_mex_destroy(&c1_lhs24);
  sf_mex_destroy(&c1_rhs25);
  sf_mex_destroy(&c1_lhs25);
  sf_mex_destroy(&c1_rhs26);
  sf_mex_destroy(&c1_lhs26);
  sf_mex_destroy(&c1_rhs27);
  sf_mex_destroy(&c1_lhs27);
  sf_mex_destroy(&c1_rhs28);
  sf_mex_destroy(&c1_lhs28);
  sf_mex_destroy(&c1_rhs29);
  sf_mex_destroy(&c1_lhs29);
  sf_mex_destroy(&c1_rhs30);
  sf_mex_destroy(&c1_lhs30);
  sf_mex_destroy(&c1_rhs31);
  sf_mex_destroy(&c1_lhs31);
  sf_mex_destroy(&c1_rhs32);
  sf_mex_destroy(&c1_lhs32);
  sf_mex_destroy(&c1_rhs33);
  sf_mex_destroy(&c1_lhs33);
  sf_mex_destroy(&c1_rhs34);
  sf_mex_destroy(&c1_lhs34);
  sf_mex_destroy(&c1_rhs35);
  sf_mex_destroy(&c1_lhs35);
  sf_mex_destroy(&c1_rhs36);
  sf_mex_destroy(&c1_lhs36);
  sf_mex_destroy(&c1_rhs37);
  sf_mex_destroy(&c1_lhs37);
  sf_mex_destroy(&c1_rhs38);
  sf_mex_destroy(&c1_lhs38);
  sf_mex_destroy(&c1_rhs39);
  sf_mex_destroy(&c1_lhs39);
  sf_mex_destroy(&c1_rhs40);
  sf_mex_destroy(&c1_lhs40);
  sf_mex_destroy(&c1_rhs41);
  sf_mex_destroy(&c1_lhs41);
  sf_mex_destroy(&c1_rhs42);
  sf_mex_destroy(&c1_lhs42);
  sf_mex_destroy(&c1_rhs43);
  sf_mex_destroy(&c1_lhs43);
  sf_mex_destroy(&c1_rhs44);
  sf_mex_destroy(&c1_lhs44);
  sf_mex_destroy(&c1_rhs45);
  sf_mex_destroy(&c1_lhs45);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static void c1_RotationToContactFrame(SFc1_hybridSysSimInstanceStruct
  *chartInstance, real_T c1_b_CollisionPosition[2], real_T c1_b_xPositionG3,
  real_T c1_b_yPositionG3, real_T c1_RotMatrix_0_4[4])
{
  uint32_T c1_debug_family_var_map[7];
  real_T c1_Theta;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_y;
  real_T c1_x;
  real_T c1_b_y;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_c_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Theta, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_CollisionPosition, 3U,
    c1_e_sf_marshallOut, c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_xPositionG3, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_yPositionG3, 5U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_RotMatrix_0_4, 6U, c1_d_sf_marshallOut,
    c1_e_sf_marshallIn);
  CV_EML_FCN(0, 6);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 122);
  c1_y = c1_b_CollisionPosition[1] - c1_b_yPositionG3;
  c1_x = c1_b_CollisionPosition[0] - c1_b_xPositionG3;
  c1_eml_scalar_eg(chartInstance);
  c1_b_y = c1_y;
  c1_b_x = c1_x;
  c1_Theta = muDoubleScalarAtan2(c1_b_y, c1_b_x);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 123);
  c1_c_x = c1_Theta;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarCos(c1_d_x);
  c1_e_x = c1_Theta;
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarSin(c1_f_x);
  c1_g_x = c1_Theta;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarSin(c1_h_x);
  c1_i_x = c1_Theta;
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarCos(c1_j_x);
  c1_RotMatrix_0_4[0] = c1_d_x;
  c1_RotMatrix_0_4[2] = -c1_f_x;
  c1_RotMatrix_0_4[1] = c1_h_x;
  c1_RotMatrix_0_4[3] = c1_j_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -123);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_eml_scalar_eg(SFc1_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_ConvesrsionForceContactPoint(SFc1_hybridSysSimInstanceStruct
  *chartInstance, real_T c1_RotMatrix_0_4[4], real_T c1_Force[2], real_T
  c1_RotatedForce[2])
{
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i115;
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  real_T c1_a[4];
  int32_T c1_i119;
  real_T c1_b[2];
  int32_T c1_i120;
  int32_T c1_i121;
  real_T c1_dv18[2];
  int32_T c1_i122;
  real_T c1_b_a[4];
  int32_T c1_i123;
  real_T c1_b_b[2];
  int32_T c1_i124;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_d_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_RotMatrix_0_4, 2U, c1_d_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Force, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_RotatedForce, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 7);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 129U);
  c1_i115 = 0;
  for (c1_i116 = 0; c1_i116 < 2; c1_i116++) {
    c1_i117 = 0;
    for (c1_i118 = 0; c1_i118 < 2; c1_i118++) {
      c1_a[c1_i118 + c1_i115] = c1_RotMatrix_0_4[c1_i117 + c1_i116];
      c1_i117 += 2;
    }

    c1_i115 += 2;
  }

  for (c1_i119 = 0; c1_i119 < 2; c1_i119++) {
    c1_b[c1_i119] = c1_Force[c1_i119];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i120 = 0; c1_i120 < 2; c1_i120++) {
    c1_RotatedForce[c1_i120] = 0.0;
  }

  for (c1_i121 = 0; c1_i121 < 2; c1_i121++) {
    c1_dv18[c1_i121] = 0.0;
  }

  for (c1_i122 = 0; c1_i122 < 4; c1_i122++) {
    c1_b_a[c1_i122] = c1_a[c1_i122];
  }

  for (c1_i123 = 0; c1_i123 < 2; c1_i123++) {
    c1_b_b[c1_i123] = c1_b[c1_i123];
  }

  c1_b_eml_xgemm(chartInstance, c1_b_a, c1_b_b, c1_dv18);
  for (c1_i124 = 0; c1_i124 < 2; c1_i124++) {
    c1_RotatedForce[c1_i124] = c1_dv18[c1_i124];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -129);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_b_eml_scalar_eg(SFc1_hybridSysSimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_eml_xgemm(SFc1_hybridSysSimInstanceStruct *chartInstance, real_T
  c1_A[4], real_T c1_B[2], real_T c1_C[2], real_T c1_b_C[2])
{
  int32_T c1_i125;
  int32_T c1_i126;
  real_T c1_b_A[4];
  int32_T c1_i127;
  real_T c1_b_B[2];
  for (c1_i125 = 0; c1_i125 < 2; c1_i125++) {
    c1_b_C[c1_i125] = c1_C[c1_i125];
  }

  for (c1_i126 = 0; c1_i126 < 4; c1_i126++) {
    c1_b_A[c1_i126] = c1_A[c1_i126];
  }

  for (c1_i127 = 0; c1_i127 < 2; c1_i127++) {
    c1_b_B[c1_i127] = c1_B[c1_i127];
  }

  c1_b_eml_xgemm(chartInstance, c1_b_A, c1_b_B, c1_b_C);
}

static void c1_Equation_Of_Motion(SFc1_hybridSysSimInstanceStruct *chartInstance,
  real_T c1_GenCordExt[3], real_T c1_GeneralCoordinatesDoubleDot[9])
{
  uint32_T c1_debug_family_var_map[5];
  real_T c1_SignOposite[3];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i128;
  int32_T c1_i129;
  real_T c1_x[3];
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  int32_T c1_i130;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_y;
  real_T c1_b_GenCordExt;
  uint32_T c1_b_debug_family_var_map[6];
  real_T c1_ForceEvaluation;
  char_T c1_Election[5];
  real_T c1_b_nargin = 2.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_d3;
  int32_T c1_i131;
  static char_T c1_cv0[5] = { 'F', '_', 's', '_', 'x' };

  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_A;
  real_T c1_B;
  real_T c1_f_x;
  real_T c1_b_y;
  real_T c1_g_x;
  real_T c1_c_y;
  real_T c1_h_x;
  real_T c1_d_y;
  real_T c1_e_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_f_y;
  real_T c1_c_GenCordExt;
  real_T c1_b_ForceEvaluation;
  char_T c1_b_Election[5];
  real_T c1_c_nargin = 2.0;
  real_T c1_c_nargout = 1.0;
  real_T c1_d4;
  int32_T c1_i132;
  static char_T c1_cv1[5] = { 'F', '_', 's', '_', 'y' };

  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_k_x;
  real_T c1_g_y;
  real_T c1_l_x;
  real_T c1_h_y;
  real_T c1_m_x;
  real_T c1_i_y;
  real_T c1_j_y;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_k_y;
  real_T c1_d_GenCordExt;
  real_T c1_c_ForceEvaluation;
  char_T c1_c_Election[3];
  real_T c1_d_nargin = 2.0;
  real_T c1_d_nargout = 1.0;
  real_T c1_d5;
  int32_T c1_i133;
  static char_T c1_cv2[3] = { 'T', '_', 's' };

  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_c_A;
  real_T c1_c_B;
  real_T c1_p_x;
  real_T c1_l_y;
  real_T c1_q_x;
  real_T c1_m_y;
  real_T c1_r_x;
  real_T c1_n_y;
  real_T c1_o_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_l_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_SignOposite, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_GenCordExt, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_GeneralCoordinatesDoubleDot, 4U,
    c1_g_sf_marshallOut, c1_f_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 67);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 68);
  for (c1_i128 = 0; c1_i128 < 9; c1_i128++) {
    c1_GeneralCoordinatesDoubleDot[c1_i128] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
  for (c1_i129 = 0; c1_i129 < 3; c1_i129++) {
    c1_x[c1_i129] = c1_GenCordExt[c1_i129];
  }

  for (c1_k = 0; c1_k < 3; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 3, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_c_x = muDoubleScalarSign(c1_c_x);
    c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 3, 1, 0) - 1] = c1_c_x;
  }

  for (c1_i130 = 0; c1_i130 < 3; c1_i130++) {
    c1_SignOposite[c1_i130] = -c1_x[c1_i130];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
  c1_d_x = c1_GenCordExt[0];
  c1_e_x = c1_d_x;
  c1_y = muDoubleScalarAbs(c1_e_x);
  c1_b_GenCordExt = c1_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_i_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ForceEvaluation, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Election, 1U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_GenCordExt, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d3, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  for (c1_i131 = 0; c1_i131 < 5; c1_i131++) {
    c1_Election[c1_i131] = c1_cv0[c1_i131];
  }

  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
  CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, 1.0, 1.0, -1, 0U, 1));
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
  c1_ForceEvaluation = c1_get_F_s_x(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c1_b_GenCordExt,
        c1_ForceEvaluation, -1, 3U, c1_b_GenCordExt <= c1_ForceEvaluation))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
    c1_d3 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
    c1_d3 = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -59);
  _SFD_SYMBOL_SCOPE_POP();
  if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c1_d3, 1.0, -1, 0U, c1_d3
        == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 72);
    c1_hoistedGlobal = c1_get_F_k_x(chartInstance, 0);
    c1_b_hoistedGlobal = c1_get_M(chartInstance, 0);
    c1_A = c1_GenCordExt[0] + c1_SignOposite[0] * c1_hoistedGlobal;
    c1_B = c1_b_hoistedGlobal;
    c1_f_x = c1_A;
    c1_b_y = c1_B;
    c1_g_x = c1_f_x;
    c1_c_y = c1_b_y;
    c1_h_x = c1_g_x;
    c1_d_y = c1_c_y;
    c1_e_y = c1_h_x / c1_d_y;
    c1_GeneralCoordinatesDoubleDot[0] = c1_e_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 74);
    c1_GeneralCoordinatesDoubleDot[0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 77);
  c1_i_x = c1_GenCordExt[1];
  c1_j_x = c1_i_x;
  c1_f_y = muDoubleScalarAbs(c1_j_x);
  c1_c_GenCordExt = c1_f_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_j_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_ForceEvaluation, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_Election, 1U, c1_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_GenCordExt, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d4, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  for (c1_i132 = 0; c1_i132 < 5; c1_i132++) {
    c1_b_Election[c1_i132] = c1_cv1[c1_i132];
  }

  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
  CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, 0.0, 1.0, -1, 0U, 0));
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
  CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, 1.0, 1.0, -1, 0U, 1));
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
  c1_b_ForceEvaluation = c1_get_F_s_y(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c1_c_GenCordExt,
        c1_b_ForceEvaluation, -1, 3U, c1_c_GenCordExt <= c1_b_ForceEvaluation)))
  {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
    c1_d4 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
    c1_d4 = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -59);
  _SFD_SYMBOL_SCOPE_POP();
  if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c1_d4, 1.0, -1, 0U, c1_d4
        == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 78);
    c1_c_hoistedGlobal = c1_get_F_k_y(chartInstance, 0);
    c1_d_hoistedGlobal = c1_get_M(chartInstance, 0);
    c1_b_A = c1_GenCordExt[1] + c1_SignOposite[1] * c1_c_hoistedGlobal;
    c1_b_B = c1_d_hoistedGlobal;
    c1_k_x = c1_b_A;
    c1_g_y = c1_b_B;
    c1_l_x = c1_k_x;
    c1_h_y = c1_g_y;
    c1_m_x = c1_l_x;
    c1_i_y = c1_h_y;
    c1_j_y = c1_m_x / c1_i_y;
    c1_GeneralCoordinatesDoubleDot[1] = c1_j_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 80);
    c1_GeneralCoordinatesDoubleDot[1] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 83);
  c1_n_x = c1_GenCordExt[2];
  c1_o_x = c1_n_x;
  c1_k_y = muDoubleScalarAbs(c1_o_x);
  c1_d_GenCordExt = c1_k_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_k_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_ForceEvaluation, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_c_Election, 1U, c1_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_GenCordExt, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d5, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  for (c1_i133 = 0; c1_i133 < 3; c1_i133++) {
    c1_c_Election[c1_i133] = c1_cv2[c1_i133];
  }

  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
  CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, 0.0, 1.0, -1, 0U, 0));
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
  CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, 0.0, 1.0, -1, 0U, 0));
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
  c1_c_ForceEvaluation = c1_get_T_s(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c1_d_GenCordExt,
        c1_c_ForceEvaluation, -1, 3U, c1_d_GenCordExt <= c1_c_ForceEvaluation)))
  {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
    c1_d5 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
    c1_d5 = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -59);
  _SFD_SYMBOL_SCOPE_POP();
  if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, c1_d5, 1.0, -1, 0U, c1_d5
        == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 84);
    c1_e_hoistedGlobal = c1_get_T_k(chartInstance, 0);
    c1_f_hoistedGlobal = c1_get_Iz(chartInstance, 0);
    c1_c_A = c1_GenCordExt[2] + c1_SignOposite[2] * c1_e_hoistedGlobal;
    c1_c_B = c1_f_hoistedGlobal;
    c1_p_x = c1_c_A;
    c1_l_y = c1_c_B;
    c1_q_x = c1_p_x;
    c1_m_y = c1_l_y;
    c1_r_x = c1_q_x;
    c1_n_y = c1_m_y;
    c1_o_y = c1_r_x / c1_n_y;
    c1_GeneralCoordinatesDoubleDot[2] = c1_o_y;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 86);
    c1_GeneralCoordinatesDoubleDot[2] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -86);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c1_ForceReactionFinger(SFc1_hybridSysSimInstanceStruct
  *chartInstance, real_T c1_GeneralCoordinatesDoubleDot[9], real_T
  c1_ForceFinger[2], real_T c1_ForceReaction[2])
{
  uint32_T c1_debug_family_var_map[7];
  real_T c1_ForceComponentIndex;
  real_T c1_ForceComponentThumb;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i134;
  real_T c1_b_ForceReaction;
  real_T c1_c_ForceReaction;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_n_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ForceComponentIndex, 0U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ForceComponentThumb, 1U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_GeneralCoordinatesDoubleDot, 4U,
    c1_g_sf_marshallOut, c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ForceFinger, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_ForceReaction, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 14);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 182U);
  for (c1_i134 = 0; c1_i134 < 2; c1_i134++) {
    c1_ForceReaction[c1_i134] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 183U);
  c1_ForceComponentIndex = c1_ForceVectorAnalysis(chartInstance,
    c1_GeneralCoordinatesDoubleDot[0], c1_ForceFinger[0]);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 184U);
  c1_ForceComponentThumb = c1_ForceVectorAnalysis(chartInstance,
    c1_GeneralCoordinatesDoubleDot[1], c1_ForceFinger[1]);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 185U);
  c1_ForceReaction[0] = c1_ForceComponentIndex;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 186U);
  c1_ForceReaction[1] = c1_ForceComponentThumb;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 187U);
  c1_b_ForceReaction = c1_ForceReaction[0];
  c1_c_ForceReaction = c1_ForceReaction[1];
  c1_ForceReaction[0] = c1_b_ForceReaction;
  c1_ForceReaction[1] = c1_c_ForceReaction;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -187);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c1_ForceVectorAnalysis(SFc1_hybridSysSimInstanceStruct
  *chartInstance, real_T c1_GeneralCoordinatesDoubleDot, real_T
  c1_ForceFingerComp)
{
  real_T c1_ForceComponent;
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_d6;
  real_T c1_hoistedGlobal;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_d7;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_m_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_GeneralCoordinatesDoubleDot, 2U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ForceFingerComp, 3U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ForceComponent, 4U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  CV_EML_FCN(0, 13);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 171U);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 172U);
  c1_x = c1_ForceFingerComp;
  c1_b_x = c1_x;
  c1_d6 = muDoubleScalarAbs(c1_b_x);
  c1_hoistedGlobal = c1_get_M(chartInstance, 0);
  c1_c_x = c1_GeneralCoordinatesDoubleDot * c1_hoistedGlobal;
  c1_d_x = c1_c_x;
  c1_d7 = muDoubleScalarAbs(c1_d_x);
  if (CV_EML_IF(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 7, c1_d6, c1_d7, -1, 5U,
        c1_d6 >= c1_d7))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 173U);
    c1_ForceComponent = -c1_ForceFingerComp + c1_GeneralCoordinatesDoubleDot *
      c1_get_M(chartInstance, 0);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 175U);
    c1_ForceComponent = c1_GeneralCoordinatesDoubleDot * c1_get_M(chartInstance,
      0);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -175);
  _SFD_SYMBOL_SCOPE_POP();
  return c1_ForceComponent;
}

static real_T c1_mpower(SFc1_hybridSysSimInstanceStruct *chartInstance, real_T
  c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  real_T c1_d_a;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_d_a = c1_ak;
  c1_eml_scalar_eg(chartInstance);
  return c1_d_a * c1_d_a;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_j_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i135;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i135, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i135;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_k_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_hybridSysSim, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_hybridSysSim), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_hybridSysSim);
  return c1_y;
}

static uint8_T c1_l_emlrt_marshallIn(SFc1_hybridSysSimInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_eml_xgemm(SFc1_hybridSysSimInstanceStruct *chartInstance,
  real_T c1_A[4], real_T c1_B[2], real_T c1_C[2])
{
  int32_T c1_i136;
  int32_T c1_i137;
  int32_T c1_i138;
  (void)chartInstance;
  for (c1_i136 = 0; c1_i136 < 2; c1_i136++) {
    c1_C[c1_i136] = 0.0;
    c1_i137 = 0;
    for (c1_i138 = 0; c1_i138 < 2; c1_i138++) {
      c1_C[c1_i136] += c1_A[c1_i137 + c1_i136] * c1_B[c1_i138];
      c1_i137 += 2;
    }
  }
}

static real_T c1_get_F_k_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 0, NULL, c1_elementIndex);
  return *chartInstance->c1_F_k_x_address;
}

static void c1_set_F_k_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 0, NULL, c1_elementIndex);
  *chartInstance->c1_F_k_x_address = c1_elementValue;
}

static real_T *c1_access_F_k_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 0, NULL);
  c1_dsmAddr = chartInstance->c1_F_k_x_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 0, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_F_k_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 1, NULL, c1_elementIndex);
  return *chartInstance->c1_F_k_y_address;
}

static void c1_set_F_k_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 1, NULL, c1_elementIndex);
  *chartInstance->c1_F_k_y_address = c1_elementValue;
}

static real_T *c1_access_F_k_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 1, NULL);
  c1_dsmAddr = chartInstance->c1_F_k_y_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 1, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_F_s_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 2, NULL, c1_elementIndex);
  return *chartInstance->c1_F_s_x_address;
}

static void c1_set_F_s_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 2, NULL, c1_elementIndex);
  *chartInstance->c1_F_s_x_address = c1_elementValue;
}

static real_T *c1_access_F_s_x(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 2, NULL);
  c1_dsmAddr = chartInstance->c1_F_s_x_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 2, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_F_s_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 3, NULL, c1_elementIndex);
  return *chartInstance->c1_F_s_y_address;
}

static void c1_set_F_s_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 3, NULL, c1_elementIndex);
  *chartInstance->c1_F_s_y_address = c1_elementValue;
}

static real_T *c1_access_F_s_y(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 3, NULL);
  c1_dsmAddr = chartInstance->c1_F_s_y_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 3, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Iz(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 4, NULL, c1_elementIndex);
  return *chartInstance->c1_Iz_address;
}

static void c1_set_Iz(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                      c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 4, NULL, c1_elementIndex);
  *chartInstance->c1_Iz_address = c1_elementValue;
}

static real_T *c1_access_Iz(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 4, NULL);
  c1_dsmAddr = chartInstance->c1_Iz_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 4, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_M(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 5, NULL, c1_elementIndex);
  return *chartInstance->c1_M_address;
}

static void c1_set_M(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                     c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 5, NULL, c1_elementIndex);
  *chartInstance->c1_M_address = c1_elementValue;
}

static real_T *c1_access_M(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 5, NULL);
  c1_dsmAddr = chartInstance->c1_M_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 5, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Position_G3_P3_frame_cylinder
  (SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 6, NULL, c1_elementIndex);
  return (*chartInstance->c1_Position_G3_P3_frame_cylinder_address)
    [c1_elementIndex];
}

static void c1_set_Position_G3_P3_frame_cylinder(SFc1_hybridSysSimInstanceStruct
  *chartInstance, uint32_T c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 6, NULL, c1_elementIndex);
  (*chartInstance->c1_Position_G3_P3_frame_cylinder_address)[c1_elementIndex] =
    c1_elementValue;
}

static real_T *c1_access_Position_G3_P3_frame_cylinder
  (SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 6, NULL);
  c1_dsmAddr = &(*chartInstance->c1_Position_G3_P3_frame_cylinder_address)[0U];
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 6, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Position_o_G3(SFc1_hybridSysSimInstanceStruct
  *chartInstance, uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 7, NULL, c1_elementIndex);
  return (*chartInstance->c1_Position_o_G3_address)[c1_elementIndex];
}

static void c1_set_Position_o_G3(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 7, NULL, c1_elementIndex);
  (*chartInstance->c1_Position_o_G3_address)[c1_elementIndex] = c1_elementValue;
}

static real_T *c1_access_Position_o_G3(SFc1_hybridSysSimInstanceStruct
  *chartInstance, uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 7, NULL);
  c1_dsmAddr = &(*chartInstance->c1_Position_o_G3_address)[0U];
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 7, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_R(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 8, NULL, c1_elementIndex);
  return *chartInstance->c1_R_address;
}

static void c1_set_R(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                     c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 8, NULL, c1_elementIndex);
  *chartInstance->c1_R_address = c1_elementValue;
}

static real_T *c1_access_R(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 8, NULL);
  c1_dsmAddr = chartInstance->c1_R_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 8, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_T_k(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 9, NULL, c1_elementIndex);
  return *chartInstance->c1_T_k_address;
}

static void c1_set_T_k(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 9, NULL, c1_elementIndex);
  *chartInstance->c1_T_k_address = c1_elementValue;
}

static real_T *c1_access_T_k(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 9, NULL);
  c1_dsmAddr = chartInstance->c1_T_k_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 9, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_T_s(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 10, NULL, c1_elementIndex);
  return *chartInstance->c1_T_s_address;
}

static void c1_set_T_s(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 10, NULL, c1_elementIndex);
  *chartInstance->c1_T_s_address = c1_elementValue;
}

static real_T *c1_access_T_s(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 10, NULL);
  c1_dsmAddr = chartInstance->c1_T_s_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 10, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Uck(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 11, NULL, c1_elementIndex);
  return *chartInstance->c1_Uck_address;
}

static void c1_set_Uck(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 11, NULL, c1_elementIndex);
  *chartInstance->c1_Uck_address = c1_elementValue;
}

static real_T *c1_access_Uck(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 11, NULL);
  c1_dsmAddr = chartInstance->c1_Uck_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 11, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Ucs(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 12, NULL, c1_elementIndex);
  return *chartInstance->c1_Ucs_address;
}

static void c1_set_Ucs(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 12, NULL, c1_elementIndex);
  *chartInstance->c1_Ucs_address = c1_elementValue;
}

static real_T *c1_access_Ucs(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 12, NULL);
  c1_dsmAddr = chartInstance->c1_Ucs_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 12, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Uk(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 13, NULL, c1_elementIndex);
  return *chartInstance->c1_Uk_address;
}

static void c1_set_Uk(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                      c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 13, NULL, c1_elementIndex);
  *chartInstance->c1_Uk_address = c1_elementValue;
}

static real_T *c1_access_Uk(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 13, NULL);
  c1_dsmAddr = chartInstance->c1_Uk_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 13, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Urk(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 14, NULL, c1_elementIndex);
  return *chartInstance->c1_Urk_address;
}

static void c1_set_Urk(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 14, NULL, c1_elementIndex);
  *chartInstance->c1_Urk_address = c1_elementValue;
}

static real_T *c1_access_Urk(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 14, NULL);
  c1_dsmAddr = chartInstance->c1_Urk_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 14, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Urs(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 15, NULL, c1_elementIndex);
  return *chartInstance->c1_Urs_address;
}

static void c1_set_Urs(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 15, NULL, c1_elementIndex);
  *chartInstance->c1_Urs_address = c1_elementValue;
}

static real_T *c1_access_Urs(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 15, NULL);
  c1_dsmAddr = chartInstance->c1_Urs_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 15, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_Us(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 16, NULL, c1_elementIndex);
  return *chartInstance->c1_Us_address;
}

static void c1_set_Us(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                      c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 16, NULL, c1_elementIndex);
  *chartInstance->c1_Us_address = c1_elementValue;
}

static real_T *c1_access_Us(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 16, NULL);
  c1_dsmAddr = chartInstance->c1_Us_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 16, NULL);
  }

  return c1_dsmAddr;
}

static real_T c1_get_g(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
  c1_elementIndex)
{
  ssReadFromDataStoreElement_wrapper(chartInstance->S, 17, NULL, c1_elementIndex);
  return *chartInstance->c1_g_address;
}

static void c1_set_g(SFc1_hybridSysSimInstanceStruct *chartInstance, uint32_T
                     c1_elementIndex, real_T c1_elementValue)
{
  ssWriteToDataStoreElement_wrapper(chartInstance->S, 17, NULL, c1_elementIndex);
  *chartInstance->c1_g_address = c1_elementValue;
}

static real_T *c1_access_g(SFc1_hybridSysSimInstanceStruct *chartInstance,
  uint32_T c1_rdOnly)
{
  real_T *c1_dsmAddr;
  ssReadFromDataStore_wrapper(chartInstance->S, 17, NULL);
  c1_dsmAddr = chartInstance->c1_g_address;
  if (c1_rdOnly == 0U) {
    ssWriteToDataStore_wrapper(chartInstance->S, 17, NULL);
  }

  return c1_dsmAddr;
}

static void init_dsm_address_info(SFc1_hybridSysSimInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "F_k_x", (void **)
    &chartInstance->c1_F_k_x_address, &chartInstance->c1_F_k_x_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "F_k_y", (void **)
    &chartInstance->c1_F_k_y_address, &chartInstance->c1_F_k_y_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "F_s_x", (void **)
    &chartInstance->c1_F_s_x_address, &chartInstance->c1_F_s_x_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "F_s_y", (void **)
    &chartInstance->c1_F_s_y_address, &chartInstance->c1_F_s_y_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "Iz", (void **)
    &chartInstance->c1_Iz_address, &chartInstance->c1_Iz_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "M", (void **)
    &chartInstance->c1_M_address, &chartInstance->c1_M_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S,
    "Position_G3_P3_frame_cylinder", (void **)
    &chartInstance->c1_Position_G3_P3_frame_cylinder_address,
    &chartInstance->c1_Position_G3_P3_frame_cylinder_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "Position_o_G3", (void
    **)&chartInstance->c1_Position_o_G3_address,
    &chartInstance->c1_Position_o_G3_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "R", (void **)
    &chartInstance->c1_R_address, &chartInstance->c1_R_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "T_k", (void **)
    &chartInstance->c1_T_k_address, &chartInstance->c1_T_k_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "T_s", (void **)
    &chartInstance->c1_T_s_address, &chartInstance->c1_T_s_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "Uck", (void **)
    &chartInstance->c1_Uck_address, &chartInstance->c1_Uck_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "Ucs", (void **)
    &chartInstance->c1_Ucs_address, &chartInstance->c1_Ucs_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "Uk", (void **)
    &chartInstance->c1_Uk_address, &chartInstance->c1_Uk_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "Urk", (void **)
    &chartInstance->c1_Urk_address, &chartInstance->c1_Urk_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "Urs", (void **)
    &chartInstance->c1_Urs_address, &chartInstance->c1_Urs_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "Us", (void **)
    &chartInstance->c1_Us_address, &chartInstance->c1_Us_index);
  ssGetSFcnDataStoreNameAddrIdx_wrapper(chartInstance->S, "g", (void **)
    &chartInstance->c1_g_address, &chartInstance->c1_g_index);
}

static void init_simulink_io_address(SFc1_hybridSysSimInstanceStruct
  *chartInstance)
{
  chartInstance->c1_IndexFext = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_Acce = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_ThumbFext = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_CollisionCondition = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c1_CollisionPosition = (real_T (*)[4])
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c1_xDotG3 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c1_yDotG3 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c1_angleDot = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c1_xPositionG3 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c1_yPositionG3 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c1_angle = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c1_Pos = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_ForceReactIndex = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c1_ForceReactThumb = (real_T (*)[2])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 4);
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

void sf_c1_hybridSysSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1686243667U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2236175748U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2122913506U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3032891597U);
}

mxArray* sf_c1_hybridSysSim_get_post_codegen_info(void);
mxArray *sf_c1_hybridSysSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tbaNZO7NZCGSkY3jATXZ9B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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
      pr[1] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_hybridSysSim_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_hybridSysSim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_hybridSysSim_jit_fallback_info(void)
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

mxArray *sf_c1_hybridSysSim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_hybridSysSim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_hybridSysSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"Acce\",},{M[1],M[16],T\"ForceReactIndex\",},{M[1],M[17],T\"ForceReactThumb\",},{M[1],M[15],T\"Pos\",},{M[8],M[0],T\"is_active_c1_hybridSysSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_hybridSysSim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_hybridSysSimInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_hybridSysSimInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _hybridSysSimMachineNumber_,
           1,
           1,
           1,
           0,
           32,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"IndexFext");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Acce");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ThumbFext");
          _SFD_SET_DATA_PROPS(3,1,1,0,"CollisionCondition");
          _SFD_SET_DATA_PROPS(4,1,1,0,"CollisionPosition");
          _SFD_SET_DATA_PROPS(5,1,1,0,"xDotG3");
          _SFD_SET_DATA_PROPS(6,1,1,0,"yDotG3");
          _SFD_SET_DATA_PROPS(7,1,1,0,"angleDot");
          _SFD_SET_DATA_PROPS(8,1,1,0,"xPositionG3");
          _SFD_SET_DATA_PROPS(9,1,1,0,"yPositionG3");
          _SFD_SET_DATA_PROPS(10,1,1,0,"angle");
          _SFD_SET_DATA_PROPS(11,2,0,1,"Pos");
          _SFD_SET_DATA_PROPS(12,2,0,1,"ForceReactIndex");
          _SFD_SET_DATA_PROPS(13,2,0,1,"ForceReactThumb");
          _SFD_SET_DATA_PROPS(14,11,0,0,"R");
          _SFD_SET_DATA_PROPS(15,11,0,0,"M");
          _SFD_SET_DATA_PROPS(16,11,0,0,"g");
          _SFD_SET_DATA_PROPS(17,11,0,0,"Us");
          _SFD_SET_DATA_PROPS(18,11,0,0,"Uk");
          _SFD_SET_DATA_PROPS(19,11,0,0,"Urs");
          _SFD_SET_DATA_PROPS(20,11,0,0,"Urk");
          _SFD_SET_DATA_PROPS(21,11,0,0,"Ucs");
          _SFD_SET_DATA_PROPS(22,11,0,0,"Uck");
          _SFD_SET_DATA_PROPS(23,11,0,0,"Iz");
          _SFD_SET_DATA_PROPS(24,11,0,0,"F_s_x");
          _SFD_SET_DATA_PROPS(25,11,0,0,"F_s_y");
          _SFD_SET_DATA_PROPS(26,11,0,0,"F_k_x");
          _SFD_SET_DATA_PROPS(27,11,0,0,"F_k_y");
          _SFD_SET_DATA_PROPS(28,11,0,0,"T_s");
          _SFD_SET_DATA_PROPS(29,11,0,0,"T_k");
          _SFD_SET_DATA_PROPS(30,11,0,0,"Position_o_G3");
          _SFD_SET_DATA_PROPS(31,11,0,0,"Position_G3_P3_frame_cylinder");
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
        _SFD_CV_INIT_EML(0,1,16,8,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2422);
        _SFD_CV_INIT_EML_FCN(0,1,"NonLinearFriction",2683,-1,3364);
        _SFD_CV_INIT_EML_FCN(0,2,"Equation_Of_Motion",3655,-1,4713);
        _SFD_CV_INIT_EML_FCN(0,3,"PosCalculation",4937,-1,5342);
        _SFD_CV_INIT_EML_FCN(0,4,"VelCalculation",5567,-1,5864);
        _SFD_CV_INIT_EML_FCN(0,5,"AccCalculation",6092,-1,6576);
        _SFD_CV_INIT_EML_FCN(0,6,"RotationToContactFrame",6804,-1,7063);
        _SFD_CV_INIT_EML_FCN(0,7,"ConvesrsionForceContactPoint",7274,-1,7398);
        _SFD_CV_INIT_EML_FCN(0,8,"ConvesrsionContactPointFrame0",7635,-1,7783);
        _SFD_CV_INIT_EML_FCN(0,9,"ResultantTorqueCalc",8019,-1,8201);
        _SFD_CV_INIT_EML_FCN(0,10,"ResultantXForceWithoutFloorFrictionX",8437,-1,
                             8588);
        _SFD_CV_INIT_EML_FCN(0,11,"ResultantXForceWithoutFloorFrictionY",8824,-1,
                             8975);
        _SFD_CV_INIT_EML_FCN(0,12,"CollisionConditionFunct",9211,-1,9504);
        _SFD_CV_INIT_EML_FCN(0,13,"ForceVectorAnalysis",9740,-1,10100);
        _SFD_CV_INIT_EML_FCN(0,14,"ForceReactionFinger",10336,-1,10821);
        _SFD_CV_INIT_EML_FCN(0,15,"ForcesCalculator",10992,-1,11968);
        _SFD_CV_INIT_EML_IF(0,1,0,2849,2881,2933,3077);
        _SFD_CV_INIT_EML_IF(0,1,1,2933,2968,3020,3077);
        _SFD_CV_INIT_EML_IF(0,1,2,3121,3152,3254,3360);
        _SFD_CV_INIT_EML_IF(0,1,3,3912,3965,4067,4138);
        _SFD_CV_INIT_EML_IF(0,1,4,4197,4250,4352,4423);
        _SFD_CV_INIT_EML_IF(0,1,5,4486,4537,4638,4709);
        _SFD_CV_INIT_EML_IF(0,1,6,9314,9339,9415,9492);
        _SFD_CV_INIT_EML_IF(0,1,7,9858,9918,10008,10088);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,2853,2880,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,2940,2967,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,3124,3151,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,3915,3964,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,4200,4249,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,4489,4536,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,9317,9338,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,9861,9917,-1,5);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c1_IndexFext);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c1_Acce);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c1_ThumbFext);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c1_CollisionCondition);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c1_CollisionPosition);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c1_xDotG3);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c1_yDotG3);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c1_angleDot);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c1_xPositionG3);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c1_yPositionG3);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c1_angle);
        _SFD_SET_DATA_VALUE_PTR(11U, *chartInstance->c1_Pos);
        _SFD_SET_DATA_VALUE_PTR(12U, *chartInstance->c1_ForceReactIndex);
        _SFD_SET_DATA_VALUE_PTR(13U, *chartInstance->c1_ForceReactThumb);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c1_R_address);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c1_M_address);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c1_g_address);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c1_Us_address);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c1_Uk_address);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c1_Urs_address);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c1_Urk_address);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c1_Ucs_address);
        _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c1_Uck_address);
        _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c1_Iz_address);
        _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c1_F_s_x_address);
        _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c1_F_s_y_address);
        _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c1_F_k_x_address);
        _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c1_F_k_y_address);
        _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c1_T_s_address);
        _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c1_T_k_address);
        _SFD_SET_DATA_VALUE_PTR(30U, *chartInstance->c1_Position_o_G3_address);
        _SFD_SET_DATA_VALUE_PTR(31U,
          *chartInstance->c1_Position_G3_P3_frame_cylinder_address);
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
  return "F4ragC5OGhjVmPLPLkjq4";
}

static void sf_opaque_initialize_c1_hybridSysSim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_hybridSysSimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*)
    chartInstanceVar);
  initialize_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_hybridSysSim(void *chartInstanceVar)
{
  enable_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_hybridSysSim(void *chartInstanceVar)
{
  disable_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_hybridSysSim(void *chartInstanceVar)
{
  sf_gateway_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_hybridSysSim(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_hybridSysSim(SimStruct* S, const mxArray *
  st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c1_hybridSysSim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_hybridSysSimInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_hybridSysSim_optimization_info();
    }

    finalize_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_hybridSysSim(SimStruct *S)
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
    initialize_params_c1_hybridSysSim((SFc1_hybridSysSimInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_hybridSysSim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 10; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1778019284U));
  ssSetChecksum1(S,(3856815188U));
  ssSetChecksum2(S,(2244547749U));
  ssSetChecksum3(S,(1580873445U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c1_hybridSysSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_hybridSysSim(SimStruct *S)
{
  SFc1_hybridSysSimInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_hybridSysSimInstanceStruct *)utMalloc(sizeof
    (SFc1_hybridSysSimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_hybridSysSimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_hybridSysSim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_hybridSysSim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_hybridSysSim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_hybridSysSim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_hybridSysSim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_hybridSysSim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_hybridSysSim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_hybridSysSim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_hybridSysSim;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_hybridSysSim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_hybridSysSim;
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

void c1_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_hybridSysSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_hybridSysSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_hybridSysSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_hybridSysSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
