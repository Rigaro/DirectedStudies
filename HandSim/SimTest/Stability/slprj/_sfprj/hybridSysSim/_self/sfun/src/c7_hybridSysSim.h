#ifndef __c7_hybridSysSim_h__
#define __c7_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_hybridSysSimInstanceStruct
#define typedef_SFc7_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_hybridSysSim;
  real_T *c7_m;
  real_T *c7_fky;
  real_T *c7_g;
  real_T *c7_uk;
} SFc7_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc7_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c7_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
