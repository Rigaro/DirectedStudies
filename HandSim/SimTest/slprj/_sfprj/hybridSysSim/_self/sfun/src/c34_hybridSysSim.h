#ifndef __c34_hybridSysSim_h__
#define __c34_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc34_hybridSysSimInstanceStruct
#define typedef_SFc34_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c34_sfEvent;
  boolean_T c34_isStable;
  boolean_T c34_doneDoubleBufferReInit;
  uint8_T c34_is_active_c34_hybridSysSim;
  real_T (*c34_theta)[2];
  real_T (*c34_inertia)[4];
} SFc34_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc34_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c34_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c34_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c34_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
