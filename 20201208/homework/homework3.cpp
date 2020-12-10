#include <iostream>
using namespace std;

/*
（考点：继承，运算符重载<<）
先建立一个point类，包含数据成员x，y，以它为基类，派生出一个circle类，增加数据成员r，再以circle为直接类，派生出一个cylinder类，增加数据成员h。
point得到x，y坐标
circle可以设置半径，读取半径，计算圆面积
cylinder可以设置圆柱的高，读取圆柱的高，计算圆柱的表面积，计算圆柱的体积
每个类都定义一个对象，重载运算符“ <<”输出以上对象信息
*/

//设计点类
class Point
{
    friend ostream &operator<<(ostream &cout, Point &p);

public:
    void setX(float value)
    {
        x = value;
    }

    void setY(float value)
    {
        y = value;
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }

private:
    float x;
    float y;
};

class Circle : public Point
{
    friend ostream &operator<<(ostream &cout, Circle &c);

public:
    float get_area()
    {
        return 3.14 * r * r;
    }

    void setR(float radius)
    {
        r = radius;
    }

    float getR()
    {
        return r;
    }

private:
    float r;
};

class Cylinder : public Circle
{
    friend ostream &operator<<(ostream &cout, Cylinder &cy);

public:
    void setH(float height)
    {
        h = height;
    }

    float getH()
    {
        return h;
    }

    float getCylinderS()
    {
        float R = getR();
        return 3.14 * R * R * 2 + 2 * 3.14 * R * h;
    }

    float getCylinderV()
    {
        float R = getR();
        return 3.14 * R * R * h;
    }

private:
    float h;
};

ostream &operator<<(ostream &cout, Cylinder &cy)
{
    cout << "x = " << cy.getX() << " y = " << cy.getY() << " r = " << cy.getR() << " h = " << cy.h << " s = " << cy.getCylinderS() << " v = " << cy.getCylinderV();
    return cout;
}

ostream &operator<<(ostream &cout, Circle &c)
{
    cout << "x = " << c.getX() << " y = " << c.getY() << " r = " << c.getR() << " s = " << c.get_area();
    return cout;
}

ostream &operator<<(ostream &cout, Point &p)
{
    cout << "x = " << p.x << " y = " << p.y;
    return cout;
}

int main()
{
    Point p;
    p.setX(1);
    p.setY(2.1);
    cout << p << endl;

    Circle c;
    c.setR(10);
    c.setX(5);
    c.setY(9);
    cout << c << endl;

    Cylinder cy;
    cy.setR(10);
    cy.setX(10);
    cy.setY(10);
    cy.setH(10);
    cout << cy << endl;

    return 0;
}
