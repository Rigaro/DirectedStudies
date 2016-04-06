/* Include files */

#include "CylinderSim_cgxe.h"
<<<<<<< HEAD
#include "m_eJG1O6WbMNFUvHWZ3mwzSC.h"
=======
<<<<<<< HEAD
#include "m_GnKguKH8AZspcA0U7Ie8uE.h"
=======
#include "m_31jpglTIC8bwLycVokar5F.h"
>>>>>>> 3b6785beae7b1b91d671d3400db927969db90f62

static unsigned int cgxeModelInitialized = 0;
emlrtContext emlrtContextGlobal = { true, true, EMLRT_VERSION_INFO, NULL, "",
  NULL, false, { 0, 0, 0, 0 }, NULL };

void *emlrtRootTLSGlobal = NULL;
char cgxeRtErrBuf[4096];

/* CGXE Glue Code */
void cgxe_CylinderSim_initializer(void)
{
  if (cgxeModelInitialized == 0) {
    cgxeModelInitialized = 1;
    emlrtRootTLSGlobal = NULL;
    emlrtCreateSimulinkRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
      false, 0);
  }
}

void cgxe_CylinderSim_terminator(void)
{
  if (cgxeModelInitialized != 0) {
    cgxeModelInitialized = 0;
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtRootTLSGlobal = NULL;
  }
}
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da

unsigned int cgxe_CylinderSim_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
<<<<<<< HEAD
  if (ssGetChecksum0(S) == 106978902 &&
      ssGetChecksum1(S) == 377345797 &&
      ssGetChecksum2(S) == 3171370533 &&
      ssGetChecksum3(S) == 4112056921) {
    method_dispatcher_eJG1O6WbMNFUvHWZ3mwzSC(S, method, data);
=======
<<<<<<< HEAD
  if (ssGetChecksum0(S) == 2385195304 &&
      ssGetChecksum1(S) == 3350137730 &&
      ssGetChecksum2(S) == 2965100561 &&
      ssGetChecksum3(S) == 1743320912) {
    method_dispatcher_GnKguKH8AZspcA0U7Ie8uE(S, method, data);
=======
  if (ssGetChecksum0(S) == 2830806677 &&
      ssGetChecksum1(S) == 1022949638 &&
      ssGetChecksum2(S) == 1888281655 &&
      ssGetChecksum3(S) == 1789682460) {
    method_dispatcher_31jpglTIC8bwLycVokar5F(S, method, data);
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da
>>>>>>> 3b6785beae7b1b91d671d3400db927969db90f62
    return 1;
  }

  return 0;
}
<<<<<<< HEAD
=======

int cgxe_CylinderSim_autoInfer_dispatcher(const mxArray* prhs, mxArray* lhs[],
  const char* commandName)
{
  char sid[64];
  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "CylinderSim:68") == 0 ) {
    return autoInfer_dispatcher_eJG1O6WbMNFUvHWZ3mwzSC(lhs, commandName);
  }

  return 0;
}
>>>>>>> 438a19e020e85c521f6c228923ac4e5b4c6e50da
