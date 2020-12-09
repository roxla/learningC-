#include <iostream>
using namespace std;

/*
编写一个程序包含两个类，一个为Time类通过display函数显示时间，
一个为Date类通过display函数显示日期，要求能在一个函数中将时间和日期都打印出来。
A.在函数体外声明一个display函数，在Date和Time中分别将此函数声明为友元函数。
B.在Date中将Time声明成友元类，这样Time就能访问日期
*/

//日期类
class Time;
class Date
{
    friend void display(Time &t, Date &d);
    friend class Time; //Time是Date的好朋友，Time可以访问Date私有的属性。

public:
    Date(int year, int month, int day)
    {
        m_Year = year;
        m_Month = month;
        m_Day = day;
    }

private:
    int m_Year;  //年
    int m_Month; //月
    int m_Day;   //日
};

//时间类
class Time
{
    friend void display(Time &t, Date &d);

public:
    Time(int hour, int minute, int second)
    {
        m_Hour = hour;
        m_Minute = minute;
        m_Seconds = second;
    }

    void display(Date &d)
    {
        cout << "日期:" << d.m_Year << ":" << d.m_Month << ":" << d.m_Day << endl;
        cout << "时间:" << m_Hour << ":" << m_Minute << ":" << m_Seconds << endl;
    }

private:
    int m_Hour;    //时
    int m_Minute;  //分
    int m_Seconds; //秒
};

//全局函数display函数显示时间和日期
void display(Time &t, Date &d)
{
    cout << "日期:" << d.m_Year << ":" << d.m_Month << ":" << d.m_Day << endl;
    cout << "时间:" << t.m_Hour << ":" << t.m_Minute << ":" << t.m_Seconds << endl;
}

int main()
{
    Date d(2020, 12, 8);
    Time t(10, 37, 30);

    //display(t,d);
    t.display(d);

    return 0;
}