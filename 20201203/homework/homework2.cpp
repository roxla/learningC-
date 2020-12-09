#include <iostream>
using namespace std;

/*
设计链表类
1. 属性  -> 头节点指针
2. 行为  -> 初始化头节点、插入数据、遍历链表。
*/
struct list_node
{
    int data;               //数据域
    struct list_node *next; //指针域
};

class MyList
{
public:
    /*
	void init_list_head()
	{
		head = new list_node;  
		head->next = NULL;
	}
	*/

    MyList()
    {
        cout << "默认构造函数" << endl;
        head = new list_node;
        head->next = NULL;
    }

    void insert_list_node(int num)
    {
        list_node *Node = new list_node;
        Node->data = num;
        Node->next = NULL;

        list_node *p;
        for (p = head; p->next != NULL; p = p->next)
            ;

        p->next = Node;
    }

    void show_list_node()
    {
        list_node *p;
        for (p = head->next; p != NULL; p = p->next)
        {
            cout << "p->data:" << p->data << endl;
        }
    }

    /*
	void destroy_list()
	{
		
	}
	*/

    ~MyList()
    {
        cout << "析构函数调用" << endl;
        list_node *q, *p;
        for (p = q = head; p != NULL; p = q)
        {
            q = p->next;
            delete p;
        }
    }

private:
    list_node *head; //头节点的指针域
};

int main()
{
    MyList L;

    L.insert_list_node(10);
    L.insert_list_node(20);
    L.insert_list_node(30);

    L.show_list_node();

    return 0;
}