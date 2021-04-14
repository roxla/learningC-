// count    -> 计算自定义数据类型

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator==(const Person &p)
    {
        if (this->age == p.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string name;
    int age;
};

void test()
{
    vector<Person> v;
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("诸葛亮", 35);
    int num = count(v.begin(), v.end(), p);
    cout << "和诸葛亮同岁数的人员个数:" << num << endl;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
