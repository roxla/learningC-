// sort     -> 实现自定义数据类型降序

#include <iostream>
#include <algorithm>
#include <vector>
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

class MyCompare
{
public:
    bool operator()(Person p1, Person p2)
    {
        return p1.age > p2.age;
    }
};

void printPerson(Person &p)
{
    cout << "姓名:" << p.name << " 年龄:" << p.age << endl;
}

int main(int argc, char const *argv[])
{
    vector<Person> v;

    Person p1("刘备", 40);
    Person p2("关羽", 50);
    Person p3("张飞", 15);
    Person p4("赵云", 20);
    Person p5("曹操", 36);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //排序前
    cout << "排序前:" << endl;
    for_each(v.begin(), v.end(), printPerson);
    sort(v.begin(), v.end(), MyCompare());
    //排序后
    cout << "排序后:" << endl;
    for_each(v.begin(), v.end(), printPerson);

    return 0;
}
