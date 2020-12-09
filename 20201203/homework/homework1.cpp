#include <iostream>
using namespace std;

class homework1
{
private:
    int x;
    int y;

public:
    void set_x(int num = 0)
    {
        x = num;
    }
    void set_y(int num = 0)
    {
        y = num;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
};

int main(int argc, char const *argv[])
{
    homework1 h;
    int x;
    int y;
    cout << "pls input int x:" << endl;
	cin >> x;
    h.set_x(x);
    cout << "pls input int y:" << endl;
	cin >> y;
    h.set_y(y);
    cout << "(x," << h.get_x() << "y)" << h.get_y() << endl;
    return 0;
}
