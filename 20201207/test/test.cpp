#include <iostream>
using namespace std;

//构造函数分类以及调用
//分类
//按照参数分类: 无参构造和有参构造
//按照类型分类: 普通构造和拷贝构造

class Person
{
public:
    //构造函数
    //普通无参构造函数
    Person()
    {
        cout << "Person的无参构造函数调用" << endl;
    }

    //普通有参构造函数
    Person(int a)
    {
        m_Age = a;
        cout << "Person的有参构造函数调用" << endl;
    }

    //拷贝构造函数
    Person(const Person &p) //将传入的参数p的所有属性拷贝到自己身上。
    {
        m_Age = p.m_Age;
        cout << "Person拷贝构造函数的调用" << endl;
    }

    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }

    int m_Age;
};

int main()
{
    //调用
    //1. 括号法
    Person p1;     //默认构造函数的调用，即无参构造。
    Person p2(10); //有参构造函数
    Person p3(p2); //拷贝构造函数

    //注意事项:
    //调用默认构造函数时，不要加()
    //因为下面这行代码，编译器会认为是一个函数的声明，不会认为在创建对象。
    //Person p1();

    //cout << "p2的年龄为:" << p2.m_Age << endl;
    //cout << "p3的年龄为:" << p3.m_Age << endl;

    //2. 显示法
    //Person p1;                //无参构造
    //Person p2 = Person(10);   //有参构造
    //Person p3 = Person(p2);   //拷贝构造

    //Person(10); //这也是一个对象，只是没有名字而已，系统创建了这个没有名字的对象之后，赋值给Person p2，这个对象就有名字了，叫p2。
    //匿名对象  特点： 当前行执行结束后，系统会立即回收掉匿名对象。

    //cout << "aaa" << endl;

    //cout << "p2的年龄为:" << p2.m_Age << endl;
    //cout << "p3的年龄为:" << p3.m_Age << endl;

    //3. 隐式转换法。
    // Person p1 = 10; //相等于 Person p1 = Person(10);
    // Person p2 = p1; //拷贝构造

    cout << "p1的年龄为:" << p1.m_Age << endl;
    cout << "p2的年龄为:" << p2.m_Age << endl;

    return 0;
}