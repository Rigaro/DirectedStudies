/* Include files */

#include "CylinderSim_cgxe.h"
#include "m_l3wxmHqEjOydUYR4mHiKZH.h"

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

unsigned int cgxe_CylinderSim_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 4283442150 &&
      ssGetChecksum1(S) == 1105907404 &&
      ssGetChecksum2(S) == 2711123900 &&
      ssGetChecksum3(S) == 1381787311) {
    method_dispatcher_l3wxmHqEjOydUYR4mHiKZH(S, method, data);
    return 1;
  }

  return 0;
}

int cgxe_CylinderSim_autoInfer_dispatcher(const mxArray* prhs, mxArray* lhs[],
  const char* commandName)
{
  char sid[64];
  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "CylinderSim:293") == 0 ) {
    return autoInfer_dispatcher_l3wxmHqEjOydUYR4mHiKZH(lhs, commandName);
  }

  if (strcmp(sid, "CylinderSim:341") == 0 ) {
    return autoInfer_dispatcher_l3wxmHqEjOydUYR4mHiKZH(lhs, commandName);
  }

  return 0;
}
