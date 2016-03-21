/* Include files */

#include "oneFingerSim_cgxe.h"
#include "m_ueo0WoZtTTZrQq4OwFcAGD.h"

unsigned int cgxe_oneFingerSim_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 1560620240 &&
      ssGetChecksum1(S) == 3954392140 &&
      ssGetChecksum2(S) == 3056767230 &&
      ssGetChecksum3(S) == 4272595228) {
    method_dispatcher_ueo0WoZtTTZrQq4OwFcAGD(S, method, data);
    return 1;
  }

  return 0;
}
