/* Include files */

#include "CylinderSim_cgxe.h"
#include "m_GnKguKH8AZspcA0U7Ie8uE.h"

unsigned int cgxe_CylinderSim_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 2385195304 &&
      ssGetChecksum1(S) == 3350137730 &&
      ssGetChecksum2(S) == 2965100561 &&
      ssGetChecksum3(S) == 1743320912) {
    method_dispatcher_GnKguKH8AZspcA0U7Ie8uE(S, method, data);
    return 1;
  }

  return 0;
}
