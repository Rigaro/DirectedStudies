#ifndef __c10_hybridSysSim_h__
#define __c10_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc10_hybridSysSimInstanceStruct
#define typedef_SFc10_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  boolean_T c10_isStable;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_hybridSysSim;
  real_T *c10_urk;
  real_T *c10_tk;
  real_T *c10_m;
  real_T *c10_g;
  real_T *c10_r;
} SFc10_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc10_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c10_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c10_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
