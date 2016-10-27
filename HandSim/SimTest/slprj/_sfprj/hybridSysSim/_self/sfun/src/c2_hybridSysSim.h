#ifndef __c2_hybridSysSim_h__
#define __c2_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_hybridSysSimInstanceStruct
#define typedef_SFc2_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_hybridSysSim;
  real_T (*c2_iInitVal)[4];
  real_T (*c2_xDot)[4];
  real_T *c2_iFa;
  real_T (*c2_iFcSense)[2];
  real_T (*c2_iFeDist)[2];
  real_T (*c2_iO)[2];
  real_T (*c2_rOtoL)[4];
  real_T (*c2_iFcComp)[2];
  real_T (*c2_rOtoLDot)[2];
} SFc2_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc2_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c2_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
