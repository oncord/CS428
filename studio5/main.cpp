/*
 *  Richard Meyer
 *
 *  main.cpp
 */
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char * c1 = "test1";
    const char * c2 = "test2"; 

    cout << "\0" << c1 << "\0" << endl;
    cout << "\0" << c2 << "\0"<< endl;

    cout << "string1 len: " << strlen(c1) << "\nstring2 len: " << strlen(c2) << endl;

    return 0;
}
