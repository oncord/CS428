#include <iostream>

using namespace std;

typedef int Int;
typedef const int ConstInt;
typedef int* PtrToInt;
typedef const int* PtrToConstInt;
typedef int* const ConstPtrToInt;
typedef const int* const ConstPtrToConstInt;

int main()
{
    const int a = 0;
    auto a_auto = a;
    ++a_auto;
    decltype(a) a_decl = a;
    ++a_decl;
    

    int b = 1;
    auto b_auto = b;
    ++b_auto;
    decltype(b) b_decl = b;
    ++b_decl;
    

    const int * const c = &a;
    auto c_auto = c;
    ++c_auto;
    //++(*c_auto);
    decltype(c) c_decl = c;


    const int * const d = &b;
    auto d_auto = d;
    ++d_auto;
    //++(*d_auto);

    
    //int * const e = &a;
    int * const f = &b;
    auto f_auto = f;
    ++f_auto;
    ++(*f_auto);
    
    
    const int * g = &a;
    auto g_auto = g;
    ++g_auto;
    //++(*g_auto);
    
    const int * h = &b;
    auto h_auto = h;
    ++h_auto;
    //++(*h_auto);
    
    //int * i = &a;
    int * j = &b;
    auto j_auto = j;
    ++j_auto;
    ++(*j_auto);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "c-> address: " << c << ", value: " << *c << endl;
    cout << "d -> address: " << d << ", value: " << *d << endl;
    //cout << "e -> address: " << e << ", value: " << *e << endl;
    cout << "f -> address: " << f << ", value: " << *f << endl;
    cout << "g -> address: " << g << ", value: " << *g << endl;
    cout << "h -> address: " << h << ", value: " << *h << endl;
    //cout << "i -> address: " << i << ", value: " << *i << endl;
    cout << "j -> address: " << j << ", value: " << *j << endl;

    //++a;
    ++b;
    //++c;
    //++d;
    //++e;
    //++f;
    ++g;
    ++h;
    //++i;
    ++j;

    //++(*c);
    //++(*d);
    //++(*e);
    ++(*f);
    //++(*g);
    //++(*h);
    //++(*i);
    ++(*j);

    return 0;
}
