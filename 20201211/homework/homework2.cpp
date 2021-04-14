#include <iostream>
using namespace std;

string reverse(string str)
{
    string re_str;
    int i;
    for (i = 0; i < str.length(); i++)
    {
        re_str.insert(i, 1, str[str.length() - 1 - i]);
    }

    return re_str;
}

int main(int argc, char const *argv[])
{
    string str = "ABCDE";
    cout << reverse(str) << endl;

    return 0;
}
