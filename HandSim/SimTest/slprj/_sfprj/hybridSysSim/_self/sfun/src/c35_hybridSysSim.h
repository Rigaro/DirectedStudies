#ifndef __c35_hybridSysSim_h__
#define __c35_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc35_hybridSysSimInstanceStruct
#define typedef_SFc35_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c35_sfEvent;
  boolean_T c35_isStable;
  boolean_T c35_doneDoubleBufferReInit;
  uint8_T c35_is_active_c35_hybridSysSim;
  real_T (*c35_theta)[2];
  real_T (*c35_estimatedVelocityX2)[2];
  real_T (*c35_Kd)[4];
  real_T (*c35_estimatedVelocity)[2];
  real_T (*c35_estimatedTheta)[2];
} SFc35_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc35_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c35_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c35_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c35_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
