#ifndef __c32_hybridSysSim_h__
#define __c32_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc32_hybridSysSimInstanceStruct
#define typedef_SFc32_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c32_sfEvent;
  boolean_T c32_isStable;
  boolean_T c32_doneDoubleBufferReInit;
  uint8_T c32_is_active_c32_hybridSysSim;
  real_T (*c32_theta)[2];
  real_T (*c32_Inertia)[4];
  real_T *c32_iFa;
  real_T (*c32_iFcSense)[2];
  real_T (*c32_estimatedAcceleration)[2];
  real_T (*c32_Coriolis)[4];
  real_T (*c32_estimatedVelocity)[2];
  real_T (*c32_estimatedTheta)[2];
  real_T (*c32_Kp)[4];
} SFc32_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc32_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c32_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c32_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c32_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
