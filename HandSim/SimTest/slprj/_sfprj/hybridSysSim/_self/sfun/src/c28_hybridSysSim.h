#ifndef __c28_hybridSysSim_h__
#define __c28_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc28_hybridSysSimInstanceStruct
#define typedef_SFc28_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c28_sfEvent;
  boolean_T c28_isStable;
  boolean_T c28_doneDoubleBufferReInit;
  uint8_T c28_is_active_c28_hybridSysSim;
  real_T (*c28_FcSense)[2];
  real_T *c28_fcD;
  real_T (*c28_theta)[2];
} SFc28_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc28_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c28_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c28_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c28_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
