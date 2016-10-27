#ifndef __c12_hybridSysSim_h__
#define __c12_hybridSysSim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc12_hybridSysSimInstanceStruct
#define typedef_SFc12_hybridSysSimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_isStable;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_hybridSysSim;
  real_T (*c12_irOtoL)[4];
  real_T *c12_iCol;
  real_T (*c12_irOtoLDot)[2];
  real_T (*c12_iFcComp)[2];
  real_T (*c12_posG3)[2];
  real_T *c12_R;
  real_T (*c12_iColPos)[2];
  real_T (*c12_cRc)[2];
} SFc12_hybridSysSimInstanceStruct;

#endif                                 /*typedef_SFc12_hybridSysSimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_hybridSysSim_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_hybridSysSim_get_check_sum(mxArray *plhs[]);
extern void c12_hybridSysSim_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
