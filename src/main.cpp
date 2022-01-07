//-----------------------------------------------------------------------------
#include <iostream>
//-----------------------------------------------------------------------------
#include "work_obj.h"
//-----------------------------------------------------------------------------



int main(int, const char* [])
{
  t_work_obj workObj;

  try 
  {

    int nResult = workObj.task();
    if(nResult) {
      std::cout << "Error in task(), code: " << nResult << std::endl;
      return nResult;
    }


  }
  catch(const std::exception& exc)
  {
    std::cout << "Exception caught. Info: " << exc.what() << std::endl;
    return -33;
  }

  return 0;
}
//-----------------------------------------------------------------------------

