#ifndef __c23_hybridSysSim_h__
#define __c23_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_hybridSysSimInstanceStruct
#define typedef_SFc23_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c23_sfEvent;
  boolean_T c23_isStable;
  boolean_T c23_doneDoubleBufferReInit;
  uint8_T c23_is_active_c23_hybridSysSim;
  real_T (*c23_theta)[2];
  real_T (*c23_inertia)[4];
} SFc23_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc23_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c23_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c23_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
