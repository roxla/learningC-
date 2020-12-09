#include <iostream>
using namespace std;

class homework3
{
private:
    string s_name;
    int s_id;
    int s_num;

public:
    void set_student(string name, int id, int num)
    {
        s_name = name;
        s_id = id;
        s_num = num;
    }
    void get_student()
    {
        cout << "student:\nname:" << s_name << "\nid:" << s_id << "\nnum:" << s_num << "\n"
             << endl;
    }
};

int main(int argc, char const *argv[])
{
    homework3 std1, std2;
    std1.set_student("张三", 123, 105);
    std2.set_student("李四", 152, 90);
    std1.get_student();
    std2.get_student();

    return 0;
}
