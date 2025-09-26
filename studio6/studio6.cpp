/*
 *  Richard Meyer
 *
 *  studio6.cpp
 */
#include "studio6.h"
#include <iostream>

// copy constructor
S::S(const S& copy) : a(copy.a), b(copy.b) {}

// getters
int S::getA() const {
    return a;
}

int S::getB() const {
    return b;
}

// setters
S& S::setA(int val) {
    a = val;
    return *this;
}
S& S::setB(int val) {
    b = val;
    return *this;
}
