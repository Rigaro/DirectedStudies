#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                CylinderSim_cgxe
#include "simstruc.h"
#include "CylinderSim_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_CylinderSim_method_dispatcher(S, SS_CALL_MDL_START, NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlOutputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(1, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
<<<<<<< HEAD
  checksumData[0] = 106978902;
  checksumData[1] = 377345797;
  checksumData[2] = 3171370533;
  checksumData[3] = 4112056921;
=======
<<<<<<< HEAD
  checksumData[0] = 2385195304;
  checksumData[1] = 3350137730;
  checksumData[2] = 2965100561;
  checksumData[3] = 1743320912;
=======
  checksumData[0] = 2830806677;
  checksumData[1] = 1022949638;
  checksumData[2] = 1888281655;
  checksumData[3] = 1789682460;
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da
>>>>>>> 3b6785beae7b1b91d671d3400db927969db90f62
  mxSetCell(mxModules, 0, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
<<<<<<< HEAD
    checksumData[0] = 4045158047;
    checksumData[1] = 1886551100;
    checksumData[2] = 3933028082;
    checksumData[3] = 876979045;
=======
<<<<<<< HEAD
    checksumData[0] = 3327881038;
    checksumData[1] = 2699809805;
    checksumData[2] = 2477652977;
    checksumData[3] = 97382005;
=======
    checksumData[0] = 4219585351;
    checksumData[1] = 1410500254;
    checksumData[2] = 998849182;
    checksumData[3] = 3779145693;
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da
>>>>>>> 3b6785beae7b1b91d671d3400db927969db90f62
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
<<<<<<< HEAD
    checksumData[0] = 717330753;
    checksumData[1] = 4285118029;
    checksumData[2] = 3693911560;
    checksumData[3] = 397877149;
=======
<<<<<<< HEAD
    checksumData[0] = 3184066827;
    checksumData[1] = 4154336025;
    checksumData[2] = 3452633940;
    checksumData[3] = 1870940251;
=======
    checksumData[0] = 1107892207;
    checksumData[1] = 1166504183;
    checksumData[2] = 2199647629;
    checksumData[3] = 3306514579;
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da
>>>>>>> 3b6785beae7b1b91d671d3400db927969db90f62
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
<<<<<<< HEAD
    checksumData[0] = 2443141041;
    checksumData[1] = 3932355902;
    checksumData[2] = 2166964269;
    checksumData[3] = 2245392606;
=======
    checksumData[0] = 4201015399;
    checksumData[1] = 462648460;
    checksumData[2] = 3089484632;
    checksumData[3] = 1933583925;
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
<<<<<<< HEAD
    checksumData[0] = 3516915105;
    checksumData[1] = 1053522604;
    checksumData[2] = 3898752351;
    checksumData[3] = 906556076;
=======
<<<<<<< HEAD
    checksumData[0] = 19867262;
    checksumData[1] = 3309020895;
    checksumData[2] = 2192358092;
    checksumData[3] = 1753692896;
=======
    checksumData[0] = 2012280677;
    checksumData[1] = 492211778;
    checksumData[2] = 2452286334;
    checksumData[3] = 2040889177;
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da
>>>>>>> 3b6785beae7b1b91d671d3400db927969db90f62
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  uint32_T *uintPtr = (uint32_T*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(uint32_T);
  uint32_T *uintDataPtr = (uint32_T *)mxGetData(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    uintPtr[el] = uintDataPtr[el];
  }

  memcpy(&S,uintPtr,sizeof(SimStruct*));
  free(uintPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_CylinderSim_method_dispatcher(S, SS_CALL_MDL_GET_SIM_STATE,
    (void *) (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_CylinderSim_method_dispatcher(S, SS_CALL_MDL_SET_SIM_STATE,
    (void *) prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
<<<<<<< HEAD
  if (strcmp(tpChksum, "eJG1O6WbMNFUvHWZ3mwzSC") == 0) {
    extern mxArray *cgxe_eJG1O6WbMNFUvHWZ3mwzSC_BuildInfoUpdate(void);
    plhs[0] = cgxe_eJG1O6WbMNFUvHWZ3mwzSC_BuildInfoUpdate();
=======
<<<<<<< HEAD
  if (strcmp(tpChksum, "GnKguKH8AZspcA0U7Ie8uE") == 0) {
    extern mxArray *cgxe_GnKguKH8AZspcA0U7Ie8uE_BuildInfoUpdate(void);
    plhs[0] = cgxe_GnKguKH8AZspcA0U7Ie8uE_BuildInfoUpdate();
=======
  if (strcmp(tpChksum, "31jpglTIC8bwLycVokar5F") == 0) {
    extern mxArray *cgxe_31jpglTIC8bwLycVokar5F_BuildInfoUpdate(void);
    plhs[0] = cgxe_31jpglTIC8bwLycVokar5F_BuildInfoUpdate();
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da
>>>>>>> 3b6785beae7b1b91d671d3400db927969db90f62
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  return 0;
}

#include "simulink.c"
