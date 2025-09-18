/*
 * Author: Richard Meyer
 *
 * main.cpp
 */

#include "studio1.h"
#include <iostream>
#include <utility>

const int SUCCESS = 0;

using namespace std;

int main()
{
    S<> s1(41);
    S<> s2(67);

    cout << s1 << " " << s2;

    swap(s1, s2);

    cout << "\nafter call to swap\n" << s1 << " " << s2 << endl;

    return SUCCESS;
}
