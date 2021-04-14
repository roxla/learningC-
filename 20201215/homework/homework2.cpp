// count_if -> 计算自定义数据类型

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

    string name;
    int age;
};

class AgeGreater20
{
public:
    bool operator()(const Person &p)
    {
        return p.age > 20;
    }
};

void test()
{
    vector<Person> v;
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 40);
    Person p5("曹操", 20);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    int num = count_if(v.begin(), v.end(), AgeGreater20());
    cout << "大于20岁人员个数: " << num << endl;
}

int main(int argc, char const *argv[])
{
    test();
    
    return 0;
}
