/*
 * Richard Meyer
 *
 * studio1.cpp
 */
#include "studio1.h"

template <typename T>
S<T>::S(T v) : val(v) {}

//define operator<<
template <typename N>
std::ostream& operator<<(ostream& os, const S<N>& obj)
{
    return os << obj.val;
}

