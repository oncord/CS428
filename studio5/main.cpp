/*
 *  Richard Meyer
 *
 *  main.cpp
 */
#include "studio5.h"
#include "Compose_T.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <functional>

using namespace std;

int main()
{
    const char * c1 = "test1";
    const char * c2 = "test2"; 
    size_t (*p) (const char *) = strlen;
    float f = 1.0;

    function<double(double)> s = [] (double x) {
        return sin(x);
    };

    function <double(double)> c = [] (double x) {
        return cos (x);
    };

    auto co = compose(s, c);
    auto b = bind(s, f);

    //cout << "first string: \"" << c1 << "\"" << endl;
    //cout << "second string: \"" << c2 << "\"" << endl;

    //cout << "string1 len: " << strlen(c1) << "\nstring2 len: " << strlen(c2);
    //cout << "string1 len: " << (*p)(c1)  << "\nstring2 len: " << (*p)(c2) << endl;

    //cout << "original value: " << f << "\nafter sine and cosine: " << co(f) << endl;

    cout << b() << endl;

    return 0;
}
