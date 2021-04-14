//自己通用的数组类
#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
    //有参构造
    MyArray(int capacity)
    {
        cout << "有参构造函数" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    //拷贝构造函数
    MyArray(const MyArray &arr)
    {
        cout << "拷贝构造函数" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //this->pAddress = arr.pAddress;  //编译器默认是浅拷贝。

        //深拷贝
        this->pAddress = new T[arr.m_Capacity];

        //将arr中的数据全部拷贝过来
        int i;
        for (i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= 防止浅拷贝
    MyArray &operator=(const MyArray &arr)
    {
        cout << "operator=函数的调用" << endl;

        //先判断下原来的堆区是否有数据，如果有先释放。
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];

        //将arr数组中数据全部拷贝过来
        int i;
        for (i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

        //返回对象自身
        return *this;
    }

    //尾插法
    void Push_Back(const T &val)
    {
        //判断容量是否等于大小
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }

        this->pAddress[this->m_Size] = val; //在数组的末尾插入数据
        this->m_Size++;                     //更新数组的大小
    }

    //尾删法
    void Pop_Back()
    {
        //先判断一下数组是不是没有元素
        if (this->m_Size == 0)
        {
            return;
        }

        this->m_Size--;
    }

    //通过下标访问数组中的元素
    T &operator[](int index)
    {
        return this->pAddress[index];
    }

    //获取容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //获取大小
    int getSize()
    {
        return this->m_Size;
    }

    //析构函数
    ~MyArray()
    {
        cout << "析构函数的调用" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress;    //指向开辟到堆区的数组
    int m_Capacity; //容量
    int m_Size;     //大小  当前数组中元素的个数
};

#endif
