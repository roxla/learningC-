#include <iostream>
#include "myarray.hpp"
using namespace std;

/*
void prinfIntArray(MyArray<int> &arr)
{
	int i;
	for(i = 0 ;i < arr.getSize() ; i++)
	{
		cout << arr[i] << endl;
	}
}
*/

class Person
{
public:
    //因为申请数组的空间时，会调用默认构造函数。
    Person()
    {
    }

    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &arr)
{
    int i;
    for (i = 0; i < arr.getSize(); i++)
    {
        cout << "姓名:" << arr[i].m_Name << "年龄:" << arr[i].m_Age << endl;
    }
}

int main()
{
    MyArray<Person> arr(10);

    Person p1("aaa", 10);
    Person p2("bbb", 30);
    Person p3("ccc", 40);
    Person p4("ddd", 20);
    Person p5("eee", 60);

    //将数据写入数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    //打印数组中
    printPersonArray(arr);

    //输出容量和大小
    cout << "arr的容量:" << arr.getCapacity() << endl;
    cout << "arr的大小:" << arr.getSize() << endl;

    /*
	MyArray<int> arr1(5);  //这个数组一共有5个容量，每一个元素都是int类型的。

	int i;
	for(i = 0 ; i < 5 ;i++)
	{
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}

	cout << "arr1的打印输出:" << endl;
	prinfIntArray(arr1);

	cout << "arr1的容量:" << arr1.getCapacity() << endl;
	cout << "arr1的大小:" << arr1.getSize() << endl;

	MyArray<int> arr2(arr1);

	cout << "arr2的打印输出:" << endl;
	prinfIntArray(arr2);

	//尾删法	
	arr2.Pop_Back();
	cout << "arr2尾删后:" << endl;
	cout << "arr2的容量:" << arr2.getCapacity() << endl;
	cout << "arr2的大小:" << arr2.getSize() << endl;
	prinfIntArray(arr2);

	MyArray<int> arr3(100);
	arr3 = arr1;

	prinfIntArray(arr3);
	*/

    return 0;
}