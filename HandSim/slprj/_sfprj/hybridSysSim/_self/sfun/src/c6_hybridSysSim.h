#ifndef __c6_hybridSysSim_h__
#define __c6_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_hybridSysSimInstanceStruct
#define typedef_SFc6_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_hybridSysSim;
  real_T *c6_m;
  real_T *c6_fkx;
  real_T *c6_g;
  real_T *c6_uk;
} SFc6_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc6_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c6_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
