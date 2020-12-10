#include <iostream>
using namespace std;

template <class T>
T arr_max(T arr[], int len)
{
    int i;
    T tmp = arr[0];
    for (i = 1; i < len; i++)
    {
        if (tmp < arr[i])
            tmp = arr[i];
    }

    return tmp;
}

int main(int argc, char const *argv[])
{
    float arr1[] = {5.3, 4.6, 8.1, 7.8, 8.3, 0.9, 6.2};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {6, 9, 5, 7, 3, 0, 4, 8};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << arr_max(arr1, len1) << endl;
    cout << "-----------------" << endl;
    cout << arr_max(arr2, len2) << endl;

    return 0;
}
