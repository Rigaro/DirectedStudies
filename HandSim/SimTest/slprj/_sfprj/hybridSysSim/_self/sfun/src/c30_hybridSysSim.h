#ifndef __c30_hybridSysSim_h__
#define __c30_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc30_hybridSysSimInstanceStruct
#define typedef_SFc30_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c30_sfEvent;
  boolean_T c30_isStable;
  boolean_T c30_doneDoubleBufferReInit;
  uint8_T c30_is_active_c30_hybridSysSim;
  real_T (*c30_theta)[2];
  real_T *c30_fa;
  real_T (*c30_thetaDot)[2];
  real_T *c30_thetaR;
  real_T *c30_thetaDotR;
} SFc30_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc30_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c30_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c30_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c30_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
