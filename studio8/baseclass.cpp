#include "baseclass.h"

BaseClass::BaseClass()
{
    std::cout << "BaseClass::BaseClass()" << std::endl;
}

BaseClass::~BaseClass() {
    std::cout << "BaseClass::~BaseClass()" << std::endl;
}

void BaseClass::a() {
    std::cout << "BaseClass::a()" << std::endl;
}
