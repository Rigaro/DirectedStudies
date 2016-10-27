#ifndef __c1_hybridSysSim_h__
#define __c1_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_hybridSysSimInstanceStruct
#define typedef_SFc1_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_hybridSysSim;
  real_T *c1_F_k_x_address;
  int32_T c1_F_k_x_index;
  real_T *c1_F_k_y_address;
  int32_T c1_F_k_y_index;
  real_T *c1_F_s_x_address;
  int32_T c1_F_s_x_index;
  real_T *c1_F_s_y_address;
  int32_T c1_F_s_y_index;
  real_T *c1_Iz_address;
  int32_T c1_Iz_index;
  real_T *c1_M_address;
  int32_T c1_M_index;
  real_T (*c1_Position_G3_P3_frame_cylinder_address)[2];
  int32_T c1_Position_G3_P3_frame_cylinder_index;
  real_T (*c1_Position_o_G3_address)[2];
  int32_T c1_Position_o_G3_index;
  real_T *c1_R_address;
  int32_T c1_R_index;
  real_T *c1_T_k_address;
  int32_T c1_T_k_index;
  real_T *c1_T_s_address;
  int32_T c1_T_s_index;
  real_T *c1_Uck_address;
  int32_T c1_Uck_index;
  real_T *c1_Ucs_address;
  int32_T c1_Ucs_index;
  real_T *c1_Uk_address;
  int32_T c1_Uk_index;
  real_T *c1_Urk_address;
  int32_T c1_Urk_index;
  real_T *c1_Urs_address;
  int32_T c1_Urs_index;
  real_T *c1_Us_address;
  int32_T c1_Us_index;
  real_T *c1_g_address;
  int32_T c1_g_index;
  real_T (*c1_IndexFext)[2];
  real_T (*c1_Acce)[3];
  real_T (*c1_ThumbFext)[2];
  real_T (*c1_CollisionCondition)[2];
  real_T (*c1_CollisionPosition)[4];
  real_T *c1_xDotG3;
  real_T *c1_yDotG3;
  real_T *c1_angleDot;
  real_T *c1_xPositionG3;
  real_T *c1_yPositionG3;
  real_T *c1_angle;
  real_T (*c1_Pos)[2];
  real_T (*c1_ForceReactIndex)[2];
  real_T (*c1_ForceReactThumb)[2];
} SFc1_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc1_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c1_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
