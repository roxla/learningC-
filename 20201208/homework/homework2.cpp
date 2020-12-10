#include <iostream>
using namespace std;

const float PI = 3.14; //圆周率

//设计圆类
class round
{
public:
    round()
    {
        cout << "round默认构造函数" << endl;
    }

    round(float r)
    {
        this->m_R = r;
    }

    float get_area()
    {
        return PI * m_R * m_R;
    }

    float m_R; //半径
};

//设计桌子类
class table
{
public:
    table()
    {
        cout << "table的默认构造函数" << endl;
    }

    table(float height, string color)
    {
        this->m_Height = height;
        this->m_Color = color;
    }

    float m_Height;
    string m_Color;
};

//设计圆桌类
class roundtable : public table, public round
{
public:
    roundtable(float r, float h, string c)
    {
        this->m_R = r;
        this->m_Height = h;
        this->m_Color = c;
    }

    void show_info()
    {
        cout << "圆桌的面积:" << this->get_area() << endl;
        cout << "圆桌的高度:" << this->m_Height << endl;
        cout << "圆桌的颜色:" << this->m_Color << endl;
    }
};

int main()
{
    roundtable rt(3.3, 7.6, "red");
    rt.show_info();

    return 0;
}