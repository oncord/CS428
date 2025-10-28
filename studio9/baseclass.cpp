#include "baseclass.h"

BaseClass::BaseClass() : s("BaseClass")
{
    std::cout << "BaseClass::BaseClass()" << std::endl;
}

BaseClass::~BaseClass() {
    std::cout << "BaseClass::~BaseClass()" << std::endl;
}

void BaseClass::a() {
    std::cout << "BaseClass::a()" << std::endl;
}

const std::string BaseClass::* BaseClass::get_s_ptr() {
    return &BaseClass::s;
}
