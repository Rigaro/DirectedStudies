#ifndef __c22_hybridSysSim_h__
#define __c22_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc22_hybridSysSimInstanceStruct
#define typedef_SFc22_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  boolean_T c22_isStable;
  boolean_T c22_doneDoubleBufferReInit;
  uint8_T c22_is_active_c22_hybridSysSim;
  real_T (*c22_theta)[2];
  real_T (*c22_coriolis)[4];
  real_T (*c22_x1DotEstimated)[2];
} SFc22_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc22_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c22_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
