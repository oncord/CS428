#include "derivedclass.h"
#include <iostream>

DerivedClass::DerivedClass() : s("DerivedClass"){
    std::cout << "DerivedClass::DerivedClass()" << std::endl;
}

DerivedClass::~DerivedClass() {
    std::cout << "DerivedClass::~DerivedClass()" << std::endl;
}

void DerivedClass::a() {
    std::cout << "DerivedClass::a()" << std::endl;
}

const std::string DerivedClass::* DerivedClass::get_s_ptr() {
    return &DerivedClass::s;
}
