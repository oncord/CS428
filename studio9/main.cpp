#include "baseclass.h"
#include "derivedclass.h"
#include <memory>
#include <functional>

using std::shared_ptr;
using std::make_shared;

const int SUCCESS = 0;

int main()
{
    BaseClass base;
    DerivedClass derived;

    auto func_to_base = std::mem_fn(&BaseClass::a);
    auto func_to_base_in_derived = std::mem_fn(&BaseClass::a);
    auto func_to_derived = std::mem_fn(&DerivedClass::a);

    std::cout << "\nfetching derived class member from derived object: " << std::endl; 
    func_to_base(base);
    std::cout << "\nfetching base class member from derived object: " << std::endl; 
    func_to_base_in_derived(derived);    
    std::cout << "\nfetching base class member from base object: " << std::endl; 
    func_to_derived(derived);

    return SUCCESS;
}
