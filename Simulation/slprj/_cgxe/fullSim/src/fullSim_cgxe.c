/* Include files */

#include "fullSim_cgxe.h"
#include "m_CynCoNzEkJ1QVd5zEkhIm.h"

unsigned int cgxe_fullSim_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 232231966 &&
      ssGetChecksum1(S) == 61132416 &&
      ssGetChecksum2(S) == 985463208 &&
      ssGetChecksum3(S) == 2034269675) {
    method_dispatcher_CynCoNzEkJ1QVd5zEkhIm(S, method, data);
    return 1;
  }

  return 0;
}
