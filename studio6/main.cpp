/*
 *  Richard Meyer
 *
 *  main.cpp
 */
#include "studio6.h"
#include <iostream>

using namespace std;

int main()
{
    S s1;
    const S s2;

    cout << "non-const object: " << s1.getA() << " " << s1.getB() << endl;

    s1.setA(1).setB(2);
    
    cout << "non-const object: " << s1.getA() << " " << s1.getB() << endl;

    // s2.setA(1); compiler error

    return 0;
}
