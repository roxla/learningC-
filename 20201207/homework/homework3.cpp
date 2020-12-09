#include <iostream>
using namespace std;
#include <unistd.h>

/*
（考点: 运算符重载前置后置++，占位参数）
有一个Time类，包含数据成员分秒，模拟秒表，每次走一秒，满六十秒就进一分钟，此时秒表又从0开始。输出分秒的值。（前置、后置自增运算符）
在main函数中做一个循环，每循环一次相当于秒钟走一次，Time对象++，显示运行之后当前时间
 */

class Time
{
public:
    Time()
    {
        cout << "默认构造函数" << endl;
    }

    //重载前置++符号
    Time &operator++()
    {
        m_S++;
        if (m_S >= 60)
        {
            m_S = 0;
            m_M++;
        }

        if (m_M >= 60)
        {
            m_M = 0;
            m_H++;
        }

        return *this;
    }

    Time operator++(int)
    {
        //先记录当前的结果
        Time temp = *this;

        //再自身++
        m_S++;
        if (m_S >= 60)
        {
            m_S = 0;
            m_M++;
        }

        if (m_M >= 60)
        {
            m_M = 0;
            m_H++;
        }

        //再将记录结果返回
        return temp;
    }

    void setTime(int h, int m, int s)
    {
        this->m_H = h;
        this->m_M = m;
        this->m_S = s;
    }

    void showTime()
    {
        cout << "h = " << m_H << " m = " << m_M << " s = " << m_S << endl;
    }

private:
    int m_H; //时
    int m_M; //分
    int m_S; //秒
};

int main()
{
    Time t;
    t.setTime(10, 56, 40);

    int i;
    for (i = 0; i < 60; i++)
    {
        t++;
        sleep(1);
        t.showTime();
    }

    return 0;
}