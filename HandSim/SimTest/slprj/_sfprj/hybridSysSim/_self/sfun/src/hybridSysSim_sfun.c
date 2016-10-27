/* Include files */

#include "hybridSysSim_sfun.h"
#include "hybridSysSim_sfun_debug_macros.h"
#include "c1_hybridSysSim.h"
#include "c2_hybridSysSim.h"
#include "c3_hybridSysSim.h"
#include "c4_hybridSysSim.h"
#include "c5_hybridSysSim.h"
#include "c6_hybridSysSim.h"
#include "c7_hybridSysSim.h"
#include "c8_hybridSysSim.h"
#include "c9_hybridSysSim.h"
#include "c10_hybridSysSim.h"
#include "c11_hybridSysSim.h"
#include "c12_hybridSysSim.h"
#include "c13_hybridSysSim.h"
#include "c14_hybridSysSim.h"
#include "c15_hybridSysSim.h"
#include "c16_hybridSysSim.h"
#include "c17_hybridSysSim.h"
#include "c18_hybridSysSim.h"
#include "c19_hybridSysSim.h"
#include "c20_hybridSysSim.h"
#include "c21_hybridSysSim.h"
#include "c22_hybridSysSim.h"
#include "c23_hybridSysSim.h"
#include "c24_hybridSysSim.h"
#include "c25_hybridSysSim.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _hybridSysSimMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void hybridSysSim_initializer(void)
{
}

void hybridSysSim_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_hybridSysSim_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_hybridSysSim_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_hybridSysSim_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_hybridSysSim_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1052756615U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1152232144U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2011327441U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1425305357U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2306805129U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(205724906U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2557634419U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(747296755U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c1_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c2_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c3_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c4_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c5_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c6_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c7_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c8_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c9_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c10_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c11_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c12_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c13_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c14_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c15_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c16_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c17_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c18_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c19_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c20_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c21_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c22_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c23_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c24_hybridSysSim_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_hybridSysSim_get_check_sum(mxArray *plhs[]);
          sf_c25_hybridSysSim_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3061339410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1991824845U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3599338742U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2357874978U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(459528742U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1354992904U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1424628056U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3652580129U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hybridSysSim_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "tbaNZO7NZCGSkY3jATXZ9B") == 0) {
          extern mxArray *sf_c1_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c1_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "o7RPMzabfleIu2CGK4JuHE") == 0) {
          extern mxArray *sf_c2_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c2_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "1ZZUooBIsWN41NhGMKHc1G") == 0) {
          extern mxArray *sf_c3_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c3_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "gXQMGpbi8DSlF34j5el3e") == 0) {
          extern mxArray *sf_c4_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c4_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "0l0BxrqB1CxqUt6GbC29h") == 0) {
          extern mxArray *sf_c5_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c5_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "SbKwO8ksv6ED6gsQrrN8zG") == 0) {
          extern mxArray *sf_c6_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c6_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "ExZRpC0cULSoASp4LuhomH") == 0) {
          extern mxArray *sf_c7_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c7_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "9Ph8V9VID1q3TWPaDcaDRD") == 0) {
          extern mxArray *sf_c8_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c8_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "KB5X9altXZdOW6qQu3e99D") == 0) {
          extern mxArray *sf_c9_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c9_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "BmERL23eliMdsyagqpQLi") == 0) {
          extern mxArray *sf_c10_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c10_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "W8B2OOxjG7vdGItEOSmW9D") == 0) {
          extern mxArray *sf_c11_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c11_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "BTZR7D6zpJM8V0W55xjqrE") == 0) {
          extern mxArray *sf_c12_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c12_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "BTZR7D6zpJM8V0W55xjqrE") == 0) {
          extern mxArray *sf_c13_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c13_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "ud4ZFpqmIvXV4LPCBpYfCB") == 0) {
          extern mxArray *sf_c14_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c14_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "PpSLXNpwkKdR58cfnnPWTH") == 0) {
          extern mxArray *sf_c15_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c15_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "Vwp0RGwjr2uCoRKtNQtmmC") == 0) {
          extern mxArray *sf_c16_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c16_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "Gqta9sNzlfMfHuuB2xu1GB") == 0) {
          extern mxArray *sf_c17_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c17_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "lQeJhGs7jHh7E9URJzLTYC") == 0) {
          extern mxArray *sf_c18_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c18_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "R09Kl00JzugqV4WiHMKVIE") == 0) {
          extern mxArray *sf_c19_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c19_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "SC3pK58jeKzfvIEUQ9476G") == 0) {
          extern mxArray *sf_c20_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c20_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "b1D6od9Mp8FwheU31CnRg") == 0) {
          extern mxArray *sf_c21_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c21_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "s4n9yvMf7tawY88m93IZaE") == 0) {
          extern mxArray *sf_c22_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c22_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "xBrqthwaCteYYbxNEIu4aC") == 0) {
          extern mxArray *sf_c23_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c23_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 24:
      {
        if (strcmp(aiChksum, "NgPe27et3ba7ZxTLl9eqAF") == 0) {
          extern mxArray *sf_c24_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c24_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 25:
      {
        if (strcmp(aiChksum, "bqzfCksgMeF7LYdLk324NE") == 0) {
          extern mxArray *sf_c25_hybridSysSim_get_autoinheritance_info(void);
          plhs[0] = sf_c25_hybridSysSim_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hybridSysSim_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_hybridSysSim_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray
          *sf_c24_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray
          *sf_c25_hybridSysSim_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_hybridSysSim_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hybridSysSim_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "F4ragC5OGhjVmPLPLkjq4") == 0) {
          extern mxArray *sf_c1_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c1_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "DBg0JN7X6l9c0MD6n6pjb") == 0) {
          extern mxArray *sf_c2_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c2_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ARKfkTMnibuO7dIfGKiArE") == 0) {
          extern mxArray *sf_c3_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c3_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "M2yufFAqc6oQbpR9kj0I8B") == 0) {
          extern mxArray *sf_c4_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c4_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "P789GVT5D4MWRw1AvPsSf") == 0) {
          extern mxArray *sf_c5_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c5_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "oYpZVwxHBcO5Uip9oCkVAD") == 0) {
          extern mxArray *sf_c6_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c6_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "DtaUjqxiKnvPTiPsA8ZgGH") == 0) {
          extern mxArray *sf_c7_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c7_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "RjsIdLcEcOeCCAZdAErvG") == 0) {
          extern mxArray *sf_c8_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c8_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "Sryq9CLeDmV0yss2EvSFfC") == 0) {
          extern mxArray *sf_c9_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c9_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "AyshRuYrHCq7DTRoTcEzr") == 0) {
          extern mxArray *sf_c10_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c10_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "6Kr2OQ8aw8EjGOqMgVqx3D") == 0) {
          extern mxArray *sf_c11_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c11_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "7tAu0Ax15notrp4GOp2i4") == 0) {
          extern mxArray *sf_c12_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c12_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "7tAu0Ax15notrp4GOp2i4") == 0) {
          extern mxArray *sf_c13_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c13_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "3dUQY90nZeThhvaDrwSAcE") == 0) {
          extern mxArray *sf_c14_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c14_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "vVhGBrluOUsT0mpLRdUdlC") == 0) {
          extern mxArray *sf_c15_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c15_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "FYuyQAQvwWuVcIXDL6C7bC") == 0) {
          extern mxArray *sf_c16_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c16_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "1la7Og7kRIVOPTIKclEqp") == 0) {
          extern mxArray *sf_c17_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c17_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "HWBjNkruhYvliTGXBlpQd") == 0) {
          extern mxArray *sf_c18_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c18_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "Hq6TotkqDHEM5YoNG9xOR") == 0) {
          extern mxArray *sf_c19_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c19_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "HJoKQAZoGPEQhIOre5tC6E") == 0) {
          extern mxArray *sf_c20_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c20_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "cgAVEatbJpTuHUXea2WbjF") == 0) {
          extern mxArray *sf_c21_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c21_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "fW5WKNIAfuC3dkdNLyW34G") == 0) {
          extern mxArray *sf_c22_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c22_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "PbmhDrkHFNvhg1b4JSCOdF") == 0) {
          extern mxArray *sf_c23_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c23_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "NoqzfvicKW5VxuymmASYuE") == 0) {
          extern mxArray *sf_c24_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c24_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "KQnN28QdDFzUt1fEhIs7GD") == 0) {
          extern mxArray *sf_c25_hybridSysSim_third_party_uses_info(void);
          plhs[0] = sf_c25_hybridSysSim_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_hybridSysSim_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "F4ragC5OGhjVmPLPLkjq4") == 0) {
          extern mxArray *sf_c1_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c1_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "DBg0JN7X6l9c0MD6n6pjb") == 0) {
          extern mxArray *sf_c2_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c2_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ARKfkTMnibuO7dIfGKiArE") == 0) {
          extern mxArray *sf_c3_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c3_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "M2yufFAqc6oQbpR9kj0I8B") == 0) {
          extern mxArray *sf_c4_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c4_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "P789GVT5D4MWRw1AvPsSf") == 0) {
          extern mxArray *sf_c5_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c5_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "oYpZVwxHBcO5Uip9oCkVAD") == 0) {
          extern mxArray *sf_c6_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c6_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "DtaUjqxiKnvPTiPsA8ZgGH") == 0) {
          extern mxArray *sf_c7_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c7_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "RjsIdLcEcOeCCAZdAErvG") == 0) {
          extern mxArray *sf_c8_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c8_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "Sryq9CLeDmV0yss2EvSFfC") == 0) {
          extern mxArray *sf_c9_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c9_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "AyshRuYrHCq7DTRoTcEzr") == 0) {
          extern mxArray *sf_c10_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c10_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "6Kr2OQ8aw8EjGOqMgVqx3D") == 0) {
          extern mxArray *sf_c11_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c11_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "7tAu0Ax15notrp4GOp2i4") == 0) {
          extern mxArray *sf_c12_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c12_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "7tAu0Ax15notrp4GOp2i4") == 0) {
          extern mxArray *sf_c13_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c13_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "3dUQY90nZeThhvaDrwSAcE") == 0) {
          extern mxArray *sf_c14_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c14_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "vVhGBrluOUsT0mpLRdUdlC") == 0) {
          extern mxArray *sf_c15_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c15_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "FYuyQAQvwWuVcIXDL6C7bC") == 0) {
          extern mxArray *sf_c16_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c16_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "1la7Og7kRIVOPTIKclEqp") == 0) {
          extern mxArray *sf_c17_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c17_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "HWBjNkruhYvliTGXBlpQd") == 0) {
          extern mxArray *sf_c18_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c18_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "Hq6TotkqDHEM5YoNG9xOR") == 0) {
          extern mxArray *sf_c19_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c19_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "HJoKQAZoGPEQhIOre5tC6E") == 0) {
          extern mxArray *sf_c20_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c20_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "cgAVEatbJpTuHUXea2WbjF") == 0) {
          extern mxArray *sf_c21_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c21_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "fW5WKNIAfuC3dkdNLyW34G") == 0) {
          extern mxArray *sf_c22_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c22_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "PbmhDrkHFNvhg1b4JSCOdF") == 0) {
          extern mxArray *sf_c23_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c23_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "NoqzfvicKW5VxuymmASYuE") == 0) {
          extern mxArray *sf_c24_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c24_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "KQnN28QdDFzUt1fEhIs7GD") == 0) {
          extern mxArray *sf_c25_hybridSysSim_jit_fallback_info(void);
          plhs[0] = sf_c25_hybridSysSim_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_hybridSysSim_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "F4ragC5OGhjVmPLPLkjq4") == 0) {
          extern mxArray *sf_c1_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "DBg0JN7X6l9c0MD6n6pjb") == 0) {
          extern mxArray *sf_c2_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "ARKfkTMnibuO7dIfGKiArE") == 0) {
          extern mxArray *sf_c3_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "M2yufFAqc6oQbpR9kj0I8B") == 0) {
          extern mxArray *sf_c4_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "P789GVT5D4MWRw1AvPsSf") == 0) {
          extern mxArray *sf_c5_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "oYpZVwxHBcO5Uip9oCkVAD") == 0) {
          extern mxArray *sf_c6_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "DtaUjqxiKnvPTiPsA8ZgGH") == 0) {
          extern mxArray *sf_c7_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "RjsIdLcEcOeCCAZdAErvG") == 0) {
          extern mxArray *sf_c8_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "Sryq9CLeDmV0yss2EvSFfC") == 0) {
          extern mxArray *sf_c9_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "AyshRuYrHCq7DTRoTcEzr") == 0) {
          extern mxArray *sf_c10_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "6Kr2OQ8aw8EjGOqMgVqx3D") == 0) {
          extern mxArray *sf_c11_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "7tAu0Ax15notrp4GOp2i4") == 0) {
          extern mxArray *sf_c12_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "7tAu0Ax15notrp4GOp2i4") == 0) {
          extern mxArray *sf_c13_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "3dUQY90nZeThhvaDrwSAcE") == 0) {
          extern mxArray *sf_c14_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "vVhGBrluOUsT0mpLRdUdlC") == 0) {
          extern mxArray *sf_c15_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "FYuyQAQvwWuVcIXDL6C7bC") == 0) {
          extern mxArray *sf_c16_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "1la7Og7kRIVOPTIKclEqp") == 0) {
          extern mxArray *sf_c17_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "HWBjNkruhYvliTGXBlpQd") == 0) {
          extern mxArray *sf_c18_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "Hq6TotkqDHEM5YoNG9xOR") == 0) {
          extern mxArray *sf_c19_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "HJoKQAZoGPEQhIOre5tC6E") == 0) {
          extern mxArray *sf_c20_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "cgAVEatbJpTuHUXea2WbjF") == 0) {
          extern mxArray *sf_c21_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "fW5WKNIAfuC3dkdNLyW34G") == 0) {
          extern mxArray *sf_c22_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "PbmhDrkHFNvhg1b4JSCOdF") == 0) {
          extern mxArray *sf_c23_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c23_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "NoqzfvicKW5VxuymmASYuE") == 0) {
          extern mxArray *sf_c24_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c24_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "KQnN28QdDFzUt1fEhIs7GD") == 0) {
          extern mxArray *sf_c25_hybridSysSim_updateBuildInfo_args_info(void);
          plhs[0] = sf_c25_hybridSysSim_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_hybridSysSim_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "F4ragC5OGhjVmPLPLkjq4") == 0) {
        extern mxArray *sf_c1_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c1_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "DBg0JN7X6l9c0MD6n6pjb") == 0) {
        extern mxArray *sf_c2_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c2_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "ARKfkTMnibuO7dIfGKiArE") == 0) {
        extern mxArray *sf_c3_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c3_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "M2yufFAqc6oQbpR9kj0I8B") == 0) {
        extern mxArray *sf_c4_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c4_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "P789GVT5D4MWRw1AvPsSf") == 0) {
        extern mxArray *sf_c5_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c5_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "oYpZVwxHBcO5Uip9oCkVAD") == 0) {
        extern mxArray *sf_c6_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c6_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "DtaUjqxiKnvPTiPsA8ZgGH") == 0) {
        extern mxArray *sf_c7_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c7_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "RjsIdLcEcOeCCAZdAErvG") == 0) {
        extern mxArray *sf_c8_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c8_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "Sryq9CLeDmV0yss2EvSFfC") == 0) {
        extern mxArray *sf_c9_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c9_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "AyshRuYrHCq7DTRoTcEzr") == 0) {
        extern mxArray *sf_c10_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c10_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "6Kr2OQ8aw8EjGOqMgVqx3D") == 0) {
        extern mxArray *sf_c11_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c11_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "7tAu0Ax15notrp4GOp2i4") == 0) {
        extern mxArray *sf_c12_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c12_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "7tAu0Ax15notrp4GOp2i4") == 0) {
        extern mxArray *sf_c13_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c13_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 14:
    {
      if (strcmp(tpChksum, "3dUQY90nZeThhvaDrwSAcE") == 0) {
        extern mxArray *sf_c14_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c14_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "vVhGBrluOUsT0mpLRdUdlC") == 0) {
        extern mxArray *sf_c15_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c15_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 16:
    {
      if (strcmp(tpChksum, "FYuyQAQvwWuVcIXDL6C7bC") == 0) {
        extern mxArray *sf_c16_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c16_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 17:
    {
      if (strcmp(tpChksum, "1la7Og7kRIVOPTIKclEqp") == 0) {
        extern mxArray *sf_c17_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c17_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 18:
    {
      if (strcmp(tpChksum, "HWBjNkruhYvliTGXBlpQd") == 0) {
        extern mxArray *sf_c18_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c18_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 19:
    {
      if (strcmp(tpChksum, "Hq6TotkqDHEM5YoNG9xOR") == 0) {
        extern mxArray *sf_c19_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c19_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 20:
    {
      if (strcmp(tpChksum, "HJoKQAZoGPEQhIOre5tC6E") == 0) {
        extern mxArray *sf_c20_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c20_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 21:
    {
      if (strcmp(tpChksum, "cgAVEatbJpTuHUXea2WbjF") == 0) {
        extern mxArray *sf_c21_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c21_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 22:
    {
      if (strcmp(tpChksum, "fW5WKNIAfuC3dkdNLyW34G") == 0) {
        extern mxArray *sf_c22_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c22_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 23:
    {
      if (strcmp(tpChksum, "PbmhDrkHFNvhg1b4JSCOdF") == 0) {
        extern mxArray *sf_c23_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c23_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 24:
    {
      if (strcmp(tpChksum, "NoqzfvicKW5VxuymmASYuE") == 0) {
        extern mxArray *sf_c24_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c24_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   case 25:
    {
      if (strcmp(tpChksum, "KQnN28QdDFzUt1fEhIs7GD") == 0) {
        extern mxArray *sf_c25_hybridSysSim_get_post_codegen_info(void);
        plhs[0] = sf_c25_hybridSysSim_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void hybridSysSim_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _hybridSysSimMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "hybridSysSim","sfun",0,25,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _hybridSysSimMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_hybridSysSimMachineNumber_,
    0);
}

void hybridSysSim_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_hybridSysSim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("hybridSysSim",
      "hybridSysSim");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_hybridSysSim_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
