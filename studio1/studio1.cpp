/*
 * Author: Richard Meyer
 *
 * studio1.cpp
 */

#include "studio1.h"
#include <iostream>
#include <utility>
#include <string>

const int SUCCESS = 0;

using namespace std;

int main()
{
    S<std::string> obj1("test1"); // empty type parameter list
    S<std::string> obj2("test2"); // empty type parameter list

    cout << obj1 << " " << obj2 <<  "\n" << endl;

    swap(obj1, obj2);

    cout << obj1 << " " << obj2 << endl;

    return SUCCESS;
}
