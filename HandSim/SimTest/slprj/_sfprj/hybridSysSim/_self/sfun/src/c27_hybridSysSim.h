#ifndef __c27_hybridSysSim_h__
#define __c27_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc27_hybridSysSimInstanceStruct
#define typedef_SFc27_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c27_sfEvent;
  boolean_T c27_isStable;
  boolean_T c27_doneDoubleBufferReInit;
  uint8_T c27_is_active_c27_hybridSysSim;
  real_T *c27_FcRef;
  real_T *c27_FcSense;
  real_T (*c27_theta)[2];
  real_T *c27_fa;
  real_T (*c27_thetaDot)[2];
} SFc27_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc27_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c27_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c27_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c27_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
