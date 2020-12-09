#include <iostream>
using namespace std;

class Student
{
public:
    Student(string name, int age, int score)
    {
        this->name = name;
        this->age = age;
        this->score = score;
    }

    string name;
    int age;
    int score;
};

class Graduate : public Student
{
public:
    Graduate(float wage) : Student("zhangsan", 22, 76)
    {
        this->wage = wage;
    }
    void display()
    {
        cout << name << "\n"
             << age << "\n"
             << score << "\n"
             << wage << endl;
    }

    float wage;
};

int main(int argc, char const *argv[])
{
    Graduate s1(7000);
    s1.display();
    return 0;
}
