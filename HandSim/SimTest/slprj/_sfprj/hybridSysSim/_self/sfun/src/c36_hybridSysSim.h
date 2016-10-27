#ifndef __c36_hybridSysSim_h__
#define __c36_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc36_hybridSysSimInstanceStruct
#define typedef_SFc36_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c36_sfEvent;
  boolean_T c36_isStable;
  boolean_T c36_doneDoubleBufferReInit;
  uint8_T c36_is_active_c36_hybridSysSim;
  real_T (*c36_thetaDotHat)[2];
  real_T (*c36_thetaDotDer)[2];
  real_T (*c36_thetaDotMod)[2];
  real_T (*c36_thetaDot)[2];
} SFc36_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc36_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c36_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c36_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c36_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
