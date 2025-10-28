#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class BaseClass {
public:
    BaseClass();
    virtual ~BaseClass();
    void a();
    static const std::string BaseClass::* get_s_ptr();
private:
    std::string s;
};

#endif // BASECLASS_H
