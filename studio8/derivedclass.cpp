#include "derivedclass.h"
#include <iostream>

DerivedClass::DerivedClass() {
    std::cout << "DerivedClass::DerivedClass()" << std::endl;
}

DerivedClass::~DerivedClass() {
    std::cout << "DerivedClass::~DerivedClass()" << std::endl;
}

void DerivedClass::a() {
    std::cout << "DerivedClass::a()" << std::endl;
}

