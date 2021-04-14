#include <iostream>
#include <list>
using namespace std;

class Person
{
public:
    string name;
    int age;
    float height;

    Person(string name, int age, float height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
    ~Person() {}
};

void addPerson(list<Person> &l, string name, int age, float height)
{
    Person p(name, age, height);
    l.push_back(p);
}

bool sortList(Person p1, Person p2)
{
    if (p1.age < p2.age)
    {
        return true;
    }
    else if (p1.age == p2.age)
    {
        if (p1.height >= p2.height)
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));

    list<Person> lst;

    string nameSeed = "ABCDEFGHIJ";
    string name;
    int i, age;
    float h;
    for (i = 0; i < 10; i++)
    {
        name = "ID_";
        name += nameSeed[i];
        age = rand() % 60 + 16;
        h = (rand() % 75 + 25) / 100.0 + 1;
        addPerson(lst, name, age, h);
    }

    lst.sort(sortList);

    for (list<Person>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        cout << (*it).name << " " << (*it).age << " " << (*it).height << endl;
    }

    return 0;
}
