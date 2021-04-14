#include <iostream>
using namespace std;
// #define LEN 10

template <class T, int N>
class Array
{
public:
    Array()
    {
        arr[N] = {0};
    }
    T &operator[](int i);
    T sum_array()
    {
        T sum = 0;
        int i;
        for (i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    T arr[N];
};

template <class T, int N>
T &Array<T, N>::operator[](int i)
{
    return arr[i];
}

int main(int argc, char const *argv[])
{
    int i;
    Array<int, 4> int_arr;
    for (i = 0; i < 4; i++)
    {
        int_arr[i] = i + 1;
    }
    cout << int_arr.sum_array() << endl;
    cout << "------------------------" << endl;
    Array<float, 5> float_arr;
    for (i = 0; i < 5; i++)
    {
        float_arr[i] = (i + 1.0) / 2.0;
    }
    cout << float_arr.sum_array() << endl;
    return 0;
}
