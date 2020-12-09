#include <iostream>
using namespace std;

#define PI 3.14

class Round
{
public:
    Round()
    {
        radius = 10;
    }

    float get_area()
    {
        return radius * radius * PI;
    }

    int radius;
};

class Table
{
public:
    Table()
    {
        high = 0.8;
        color = "black";
    }

    float high;
    string color;
};

class Round_Table : public Round, public Table
{
public:
    void display()
    {
        cout << get_area() << "\n"
             << high << "\n"
             << color << endl;
    }
};

int main(int argc, char const *argv[])
{
    Round_Table arthur;
    arthur.display();

    return 0;
}
