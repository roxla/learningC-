#include <iostream>
using namespace std;

template <class T>
void arr_sort(T arr[], int len)
{
    int i, j;
    T temp;
    for (i = 0; i < len - 1; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (i = 0; i < len; i++)
        cout << arr[i] << endl;
}

int main(int argc, char const *argv[])
{
    int len1, len2;

    char arr1[] = "BECADF";
    len1 = sizeof(arr1) - 1;

    int arr2[] = {6, 9, 5, 7, 3, 0, 4, 8};
    len2 = sizeof(arr2) / sizeof(arr2[0]);

    arr_sort(arr1, len1);
    cout << "-----------------" << endl;
    arr_sort(arr2, len2);

    return 0;
}
