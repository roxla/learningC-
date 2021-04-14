#include <iostream>

using namespace std;

class Base
{
public:
    Base() { cout << "construct in B" << endl; }
    Base(Base &b) { cout << "copy in B" << endl; }
    ~Base() { cout << "deconstruct in B" << endl; }

public:
    int a;
};

class Derive : public Base
{
public:
    Derive() {}
    Derive(Derive &d) { cout << "copy in D" << endl; }
    ~Derive() {}
    int GetDerive(Derive dd) { return a; }
};

int main()
{
    Derive d;
    d.GetDerive(d);
    return 0;
}