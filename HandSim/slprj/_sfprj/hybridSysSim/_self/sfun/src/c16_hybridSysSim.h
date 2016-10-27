#ifndef __c16_hybridSysSim_h__
#define __c16_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc16_hybridSysSimInstanceStruct
#define typedef_SFc16_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c16_sfEvent;
  boolean_T c16_isStable;
  boolean_T c16_doneDoubleBufferReInit;
  uint8_T c16_is_active_c16_hybridSysSim;
  real_T *c16_FcRef;
  real_T *c16_FcSense;
  real_T (*c16_q)[2];
  real_T *c16_fa;
  real_T (*c16_qDot)[2];
} SFc16_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc16_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c16_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c16_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
