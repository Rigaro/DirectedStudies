#ifndef __c31_hybridSysSim_h__
#define __c31_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc31_hybridSysSimInstanceStruct
#define typedef_SFc31_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c31_sfEvent;
  boolean_T c31_isStable;
  boolean_T c31_doneDoubleBufferReInit;
  uint8_T c31_is_active_c31_hybridSysSim;
  real_T (*c31_iInitVal)[4];
  real_T (*c31_xDot)[4];
  real_T *c31_iFa;
  real_T (*c31_iFcSense)[2];
  real_T (*c31_iFeDist)[2];
  real_T (*c31_iO)[2];
  real_T (*c31_rOtoL)[4];
  real_T (*c31_iFcComp)[2];
  real_T (*c31_rOtoLDot)[2];
} SFc31_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc31_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c31_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c31_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c31_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
