#ifndef __c14_hybridSysSim_h__
#define __c14_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc14_hybridSysSimInstanceStruct
#define typedef_SFc14_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c14_sfEvent;
  boolean_T c14_isStable;
  boolean_T c14_doneDoubleBufferReInit;
  uint8_T c14_is_active_c14_hybridSysSim;
  real_T (*c14_o)[2];
  real_T (*c14_rOtoL)[4];
  real_T *c14_figNum;
} SFc14_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc14_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c14_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c14_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c14_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
