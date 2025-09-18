// define constructor
template <typename T>
S<T>::S(T v) : x(v) {}

//define operator<<
template <typename N>
std::ostream& operator<<(ostream& os, const S<N>& obj)
{
    return os << obj.x;
}
