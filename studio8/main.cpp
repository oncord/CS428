#include "baseclass.h"
#include "derivedclass.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

const int SUCCESS = 0;

int main()
{
    BaseClass* basePtr = new BaseClass();
    BaseClass* polyPtr = new DerivedClass();
    DerivedClass* derivedPtr = new DerivedClass();

    basePtr->a();
    polyPtr->a();
    derivedPtr->a();

    delete basePtr;
    delete polyPtr;
    delete derivedPtr;

    return SUCCESS;
}
