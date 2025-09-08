#ifndef STUDIO1_H
#define STUDIO1_H

#include <ostream>
using std::ostream;

template <typename T = int>
class S {
private:
    T x;
public:
    S(T v);

    template <typename N>
    friend ostream& operator<<(ostream& os, const S<N>& obj);
};

#include "template.cpp"

#endif // STUDIO1_H
