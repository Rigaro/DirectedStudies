#ifndef __c29_hybridSysSim_h__
#define __c29_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc29_hybridSysSimInstanceStruct
#define typedef_SFc29_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c29_sfEvent;
  boolean_T c29_isStable;
  boolean_T c29_doneDoubleBufferReInit;
  uint8_T c29_is_active_c29_hybridSysSim;
  real_T (*c29_FcSense)[2];
  real_T *c29_CFC;
  real_T *c29_GAC;
  real_T (*c29_theta)[2];
  real_T *c29_Fa;
} SFc29_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc29_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c29_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c29_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c29_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
