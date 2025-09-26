#ifndef STUDIO6_H
#define STUDIO6_H

class S {
public:
    S() = default; // default constructor
    S(const S& copy); // copy constructor

    int getA() const;
    S& setA(int val);
    int getB() const;
    S& setB(int val);

private:
    int a;
    int b;
};


#endif // STUDIO6_H
