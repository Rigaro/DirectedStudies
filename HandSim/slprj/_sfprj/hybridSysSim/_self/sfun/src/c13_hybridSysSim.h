#ifndef __c13_hybridSysSim_h__
#define __c13_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_hybridSysSimInstanceStruct
#define typedef_SFc13_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_hybridSysSim;
  real_T (*c13_irOtoL)[4];
  real_T *c13_iCol;
  real_T (*c13_irOtoLDot)[2];
  real_T (*c13_iFcComp)[2];
  real_T (*c13_posG3)[2];
  real_T *c13_R;
  real_T (*c13_iColPos)[2];
  real_T (*c13_cRc)[2];
} SFc13_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc13_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c13_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
