/* Include files */

#include "twoFingerSim_cgxe.h"
#include "m_6Fp6Co2TWZGurNaXqomZw.h"
#include "m_ofpynhcn5LFnvtv82bGDI.h"

unsigned int cgxe_twoFingerSim_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 37339060 &&
      ssGetChecksum1(S) == 1884503335 &&
      ssGetChecksum2(S) == 157375355 &&
      ssGetChecksum3(S) == 1641477560) {
    method_dispatcher_6Fp6Co2TWZGurNaXqomZw(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 332868605 &&
      ssGetChecksum1(S) == 770330876 &&
      ssGetChecksum2(S) == 4079614797 &&
      ssGetChecksum3(S) == 619031846) {
    method_dispatcher_ofpynhcn5LFnvtv82bGDI(S, method, data);
    return 1;
  }

  return 0;
}
