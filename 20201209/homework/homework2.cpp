#include <iostream>
using namespace std;

//定义图形的抽象类
class shape
{
public:
    virtual float area() = 0;
};

//定义圆类
class circle : public shape
{
public:
    circle(float radius)
    {
        r = radius;
    }

    virtual float area()
    {
        return 3.14 * r * r;
    }

private:
    float r;
};

//定义正方形
class square : public shape
{
public:
    square(float l)
    {
        len = l;
    }

    virtual float area()
    {
        return len * len;
    }

private:
    float len;
};

class rectangle : public shape
{
public:
    rectangle(float l, float w)
    {
        length = l;
        wide = w;
    }

    virtual float area()
    {
        return length * wide;
    }

private:
    float length;
    float wide;
};

int main()
{
    shape *pshape[3];

    pshape[0] = new circle(10);        //314
    pshape[1] = new square(10);        //100
    pshape[2] = new rectangle(10, 10); //100

    cout << pshape[0]->area() + pshape[1]->area() + pshape[2]->area() << endl;

    delete pshape[0];
    delete pshape[1];
    delete pshape[2];
    return 0;
}