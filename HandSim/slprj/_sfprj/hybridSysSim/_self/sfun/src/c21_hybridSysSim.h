#ifndef __c21_hybridSysSim_h__
#define __c21_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc21_hybridSysSimInstanceStruct
#define typedef_SFc21_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_isStable;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_hybridSysSim;
  real_T (*c21_theta)[2];
  real_T (*c21_Inertia)[4];
  real_T *c21_iFa;
  real_T (*c21_iFcSense)[2];
  real_T (*c21_estimatedAcceleration)[2];
  real_T (*c21_Coriolis)[4];
  real_T (*c21_estimatedVelocity)[2];
  real_T (*c21_estimatedTheta)[2];
  real_T (*c21_Kp)[4];
} SFc21_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc21_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c21_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
