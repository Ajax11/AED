        //#define USEDEBUG
        #ifdef USEDEBUG
        #define Debug(x)  std::cout<<x
        #else
        #define Debug(x)
        #endif // USEDEBUG

#include <iostream>
#include "Tester.h"

using namespace std;

int main()
{
    Tester run;
    run.testerList();

    return 0;
}
