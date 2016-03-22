#ifndef __6Fp6Co2TWZGurNaXqomZw_h__
#define __6Fp6Co2TWZGurNaXqomZw_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_tag_s3poEWU7DjEgOeKMBaXTOFE
#define struct_tag_s3poEWU7DjEgOeKMBaXTOFE

struct tag_s3poEWU7DjEgOeKMBaXTOFE
{
  real_T fv[2];
};

#endif                                 /*struct_tag_s3poEWU7DjEgOeKMBaXTOFE*/

#ifndef typedef_ForceNormal
#define typedef_ForceNormal

typedef struct tag_s3poEWU7DjEgOeKMBaXTOFE ForceNormal;

#endif                                 /*typedef_ForceNormal*/

#ifndef struct_tag_sCTY85yGnmLe0eDqTTvvQEF
#define struct_tag_sCTY85yGnmLe0eDqTTvvQEF

struct tag_sCTY85yGnmLe0eDqTTvvQEF
{
  real_T k;
  real_T d;
  real_T l;
  real_T r;
  real_T m;
  real_T I;
  real_T miuC;
  real_T miuE;
  real_T theta0;
  real_T theta;
  real_T thetaDot;
  real_T a;
  ForceNormal fc;
  real_T b;
  ForceNormal fe;
};

#endif                                 /*struct_tag_sCTY85yGnmLe0eDqTTvvQEF*/

#ifndef typedef_Phalanx_3
#define typedef_Phalanx_3

typedef struct tag_sCTY85yGnmLe0eDqTTvvQEF Phalanx_3;

#endif                                 /*typedef_Phalanx_3*/

#ifndef struct_tag_sVhVjj3EoNybWK5FBNooipH
#define struct_tag_sVhVjj3EoNybWK5FBNooipH

struct tag_sVhVjj3EoNybWK5FBNooipH
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T kP;
  real_T kD;
  real_T dP;
  real_T dD;
  real_T lP;
  real_T lD;
  real_T rP;
  real_T rD;
  real_T mP;
  real_T mD;
  real_T thetaP;
  real_T thetaD;
  Phalanx_3 prox;
  Phalanx_3 dist;
};

#endif                                 /*struct_tag_sVhVjj3EoNybWK5FBNooipH*/

#ifndef typedef_Index_2
#define typedef_Index_2

typedef struct tag_sVhVjj3EoNybWK5FBNooipH Index_2;

#endif                                 /*typedef_Index_2*/

#ifndef typedef_InstanceStruct_6Fp6Co2TWZGurNaXqomZw
#define typedef_InstanceStruct_6Fp6Co2TWZGurNaXqomZw

typedef struct {
  SimStruct *S;
  Index_2 sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  covrtInstance *covInst;
  real_T (*u0)[4];
  real_T *u1;
  real_T *u2;
  real_T *u3;
  real_T (*b_y0)[4];
  real_T (*b_y1)[4];
} InstanceStruct_6Fp6Co2TWZGurNaXqomZw;

#endif                                 /*typedef_InstanceStruct_6Fp6Co2TWZGurNaXqomZw*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_6Fp6Co2TWZGurNaXqomZw(SimStruct *S, int_T method,
  void* data);

#endif
