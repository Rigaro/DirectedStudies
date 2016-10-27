#ifndef __c26_hybridSysSim_h__
#define __c26_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc26_hybridSysSimInstanceStruct
#define typedef_SFc26_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c26_sfEvent;
  boolean_T c26_isStable;
  boolean_T c26_doneDoubleBufferReInit;
  uint8_T c26_is_active_c26_hybridSysSim;
  real_T (*c26_q)[2];
  creal_T *c26_rCFC;
  real_T (*c26_qDot)[2];
  real_T *c26_FcTilde;
} SFc26_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc26_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c26_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c26_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c26_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
