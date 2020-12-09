#include <iostream>
using namespace std;

#define PI 3.14

class Point
{
public:
    void set_xy(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int x;
    int y;
};

class Circle : public Point
{
protected:
    int r;

public:
    void set_r(int r)
    {
        this->r = r;
    }
    int get_r()
    {
        return r;
    }
    float get_area()
    {
        return r * r * PI;
    }
};

class Cylinder : public Circle
{
protected:
    int h;

public:
    void set_h(int h)
    {
        this->h = h;
    }
    int get_h()
    {
        return h;
    }
    float get_surface_area()
    {
        return 2 * r * PI * h + 2 * get_area();
    }
    float get_()
    {
        return get_area() * h;
    }
};

//重载<<运算符
ostream &operator<<(ostream &cout, Point p)
{
    cout << p.x << "," << p.y;
    return cout;
}

//重载<<运算符
ostream &operator<<(ostream &cout, Circle o)
{
    cout << o.get_r() << " " << o.get_area() << " " << o.x << "," << o.y;
    return cout;
}

//重载<<运算符
ostream &operator<<(ostream &cout, Cylinder c)
{
    cout << c.get_h() << " " << c.get_surface_area() << " " << c.x << "," << c.y;
    return cout;
}

int main(int argc, char const *argv[])
{
    Point p;
    Circle o;
    Cylinder c;
    p.set_xy(6, 9);
    o.set_r(4);
    c.set_r(3);
    c.set_h(6);
    cout << p << "\n"
         << o << "\n"
         << c << endl;

    return 0;
}
