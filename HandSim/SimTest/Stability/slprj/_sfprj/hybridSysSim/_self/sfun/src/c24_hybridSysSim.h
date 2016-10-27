#ifndef __c24_hybridSysSim_h__
#define __c24_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc24_hybridSysSimInstanceStruct
#define typedef_SFc24_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_hybridSysSim;
  real_T (*c24_theta)[2];
  real_T (*c24_estimatedVelocityX2)[2];
  real_T (*c24_Kd)[4];
  real_T (*c24_estimatedVelocity)[2];
  real_T (*c24_estimatedTheta)[2];
} SFc24_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc24_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c24_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
