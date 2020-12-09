#include <iostream>
using namespace std;

class cuboid
{
private:
    int length;
    int width;
    int height;

public:
    int get_length()
    {
        return length;
    }
    int get_width()
    {
        return width;
    }
    int get_height()
    {
        return height;
    }
    void created_cuboid(int l = 3, int w = 2, int h = 1)
    {
        length = l;
        width = w;
        height = h;
    }
    int v_cuboid()
    {
        return length * width * height;
    }
    bool isSameByClass(cuboid &c)
    {
        if (v_cuboid() == c.v_cuboid())
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    cuboid c1, c2, c3;
    c1.created_cuboid(6, 3, 2);
    c2.created_cuboid(8, 2, 3);
    c3.created_cuboid();

    cout << "c1: " << c1.v_cuboid() << "\nc2: " << c2.v_cuboid() << "\nc3: " << c3.v_cuboid() << endl;

    return 0;
}
