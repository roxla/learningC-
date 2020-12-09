#include <iostream>
using namespace std;

/*
（考点：继承的使用）
1、已学生类(姓名，年龄，分数)为基类，创建一个graduate类。编写一个程序实现以下功能：
1）graduate类增加了新的变量：float wage
2）graduate类也提供一个display函数，用来打印研究生类的信息
定义 graduate对象，打印研究生类的信息
*/

//父类
class Student
{
public:
    Student() //因为定义研究生对象(子类)，那么他就要去调用父类的构造函数，我们必须提供默认构造函数。
    {
    }

    Student(string name, int age, float score)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Score = score;
    }

    string m_Name;
    int m_Age;
    float m_Score;
};

//子类
class Graduate : public Student
{
public:
    Graduate(string name, int age, float score, float wage)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Score = score;
        this->m_Wage = wage;
    }

    void display()
    {
        cout << "姓名:" << this->m_Name << " 年龄:" << this->m_Age << " 分数:" << this->m_Score << " 工资: " << this->m_Wage << endl;
    }

    float m_Wage; //工资
};

int main()
{
    Graduate g("关国源", 18, 98, 20000);
    g.display();

    return 0;
}