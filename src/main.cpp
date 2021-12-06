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

    int nResult = workObj.func1();
    if(nResult) {
      std::cout << "Error in func1(), code: " << nResult << std::endl;
      return nResult;
    }


    nResult = workObj.func2();
    if (nResult) {
      std::cout << "Error in func2(), code: " << nResult << std::endl;
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

