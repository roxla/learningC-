#include <iostream>
using namespace std;

//实现通用数组进行排序的函数
//规则: 从大到小
//算法: 选择
//测试: char数组和int数组

template <class T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void mySort(T arr[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] < arr[j])
			{
				mySwap(arr[i], arr[j]);
			}
		}
	}
}

template <class T>
void printArray(T arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

//char数组
void test01()
{
	//测试char数组
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);

	mySort(charArr, num);

	printArray(charArr, num);
}

//int数组
void test02()
{
	//测试int数组
	int intArr[] = {7, 5, 1, 3, 9, 2, 4, 6, 8};
	int num = sizeof(intArr) / sizeof(int);

	mySort(intArr, num);

	printArray(intArr, num);
}

int main()
{
	test01();
	test02();

	return 0;
}