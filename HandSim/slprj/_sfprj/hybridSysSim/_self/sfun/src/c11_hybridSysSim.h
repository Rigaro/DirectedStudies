#ifndef __c11_hybridSysSim_h__
#define __c11_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_hybridSysSimInstanceStruct
#define typedef_SFc11_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_hybridSysSim;
  real_T (*c11_posG3)[2];
  real_T (*c11_Position_o_P3)[2];
  real_T *c11_R;
  real_T *c11_figNum;
} SFc11_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc11_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c11_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c11_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
