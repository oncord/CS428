#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H

#include "baseclass.h"

class DerivedClass : public BaseClass {
public:
    DerivedClass();
    virtual ~DerivedClass();
    void a();
    static const std::string DerivedClass::* get_s_ptr();
private:
    std::string s;
};

#endif // DERIVEDCLASS_H
