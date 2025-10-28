#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H

#include "baseclass.h"

class DerivedClass : public BaseClass {
public:
    DerivedClass();
    virtual ~DerivedClass();
    void a() override;
};

#endif // DERIVEDCLASS_H
