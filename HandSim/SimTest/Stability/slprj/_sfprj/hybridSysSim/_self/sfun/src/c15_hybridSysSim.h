#ifndef __c15_hybridSysSim_h__
#define __c15_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_hybridSysSimInstanceStruct
#define typedef_SFc15_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_hybridSysSim;
  real_T (*c15_iInitVal)[4];
  real_T (*c15_xDot)[4];
  real_T *c15_iFa;
  real_T (*c15_iFcSense)[2];
  real_T (*c15_iFeDist)[2];
  real_T (*c15_iO)[2];
  real_T (*c15_rOtoL)[4];
  real_T (*c15_iFcComp)[2];
  real_T (*c15_rOtoLDot)[2];
} SFc15_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc15_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c15_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
