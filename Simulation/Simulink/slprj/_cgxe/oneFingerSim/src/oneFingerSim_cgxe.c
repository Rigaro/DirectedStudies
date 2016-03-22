/* Include files */

#include "oneFingerSim_cgxe.h"
#include "m_gNahLr7d449KlyI8HQN75D.h"

unsigned int cgxe_oneFingerSim_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 502960265 &&
      ssGetChecksum1(S) == 1531573362 &&
      ssGetChecksum2(S) == 4127056403 &&
      ssGetChecksum3(S) == 1414438957) {
    method_dispatcher_gNahLr7d449KlyI8HQN75D(S, method, data);
    return 1;
  }

  return 0;
}
