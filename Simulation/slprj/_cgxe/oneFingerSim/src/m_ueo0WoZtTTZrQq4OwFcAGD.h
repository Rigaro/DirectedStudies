#ifndef __ueo0WoZtTTZrQq4OwFcAGD_h__
#define __ueo0WoZtTTZrQq4OwFcAGD_h__

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

#ifndef struct_tag_sDVKy8ibiBuxECMJMfCyICB
#define struct_tag_sDVKy8ibiBuxECMJMfCyICB

struct tag_sDVKy8ibiBuxECMJMfCyICB
{
  real_T k;
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

#endif                                 /*struct_tag_sDVKy8ibiBuxECMJMfCyICB*/

#ifndef typedef_Phalanx_3
#define typedef_Phalanx_3

typedef struct tag_sDVKy8ibiBuxECMJMfCyICB Phalanx_3;

#endif                                 /*typedef_Phalanx_3*/

#ifndef struct_tag_syT1euqkhfufU7t5keyXb7C
#define struct_tag_syT1euqkhfufU7t5keyXb7C

struct tag_syT1euqkhfufU7t5keyXb7C
{
  int32_T isInitialized;
  Phalanx_3 prox;
  Phalanx_3 dist;
  real_T K[4];
  real_T Ja[2];
  real_T fa;
  real_T Jc[4];
  real_T Je[4];
};

#endif                                 /*struct_tag_syT1euqkhfufU7t5keyXb7C*/

#ifndef typedef_Finger_2
#define typedef_Finger_2

typedef struct tag_syT1euqkhfufU7t5keyXb7C Finger_2;

#endif                                 /*typedef_Finger_2*/

#ifndef typedef_InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD
#define typedef_InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD

typedef struct {
  SimStruct *S;
  Finger_2 sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  covrtInstance *covInst;
  real_T (*u0)[4];
  real_T *u1;
  real_T (*b_y0)[4];
} InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD;

#endif                                 /*typedef_InstanceStruct_ueo0WoZtTTZrQq4OwFcAGD*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_ueo0WoZtTTZrQq4OwFcAGD(SimStruct *S, int_T method,
  void* data);

#endif
