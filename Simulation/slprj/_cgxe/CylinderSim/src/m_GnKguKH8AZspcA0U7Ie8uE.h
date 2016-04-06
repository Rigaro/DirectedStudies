#ifndef __GnKguKH8AZspcA0U7Ie8uE_h__
#define __GnKguKH8AZspcA0U7Ie8uE_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_tag_s5MzoChRkvOLl9tQrcA5ahE
#define struct_tag_s5MzoChRkvOLl9tQrcA5ahE

struct tag_s5MzoChRkvOLl9tQrcA5ahE
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T R;
  real_T M;
  real_T g;
  real_T Us;
  real_T Uk;
  real_T Iz;
  real_T F_s_x;
  real_T F_s_y;
  real_T F_k_x;
  real_T F_k_y;
  real_T T_s;
  real_T T_k;
  real_T Position_o_G3[2];
  real_T Position_G3_P3_frame_cylinder[2];
};

#endif                                 /*struct_tag_s5MzoChRkvOLl9tQrcA5ahE*/

#ifndef typedef_Cylinder
#define typedef_Cylinder

typedef struct tag_s5MzoChRkvOLl9tQrcA5ahE Cylinder;

#endif                                 /*typedef_Cylinder*/

#ifndef typedef_InstanceStruct_GnKguKH8AZspcA0U7Ie8uE
#define typedef_InstanceStruct_GnKguKH8AZspcA0U7Ie8uE

typedef struct {
  SimStruct *S;
  Cylinder sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  covrtInstance *covInst;
  real_T *u0;
  real_T *u1;
  real_T *u2;
  real_T *u3;
  real_T *u4;
  real_T *u5;
  real_T *u6;
  real_T *u7;
  real_T *u8;
  real_T (*b_y0)[6];
} InstanceStruct_GnKguKH8AZspcA0U7Ie8uE;

#endif                                 /*typedef_InstanceStruct_GnKguKH8AZspcA0U7Ie8uE*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_GnKguKH8AZspcA0U7Ie8uE(SimStruct *S, int_T method,
  void* data);

#endif
