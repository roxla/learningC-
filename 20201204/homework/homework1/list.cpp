#include "list.h"

MyList::MyList()
{
	cout << "默认构造函数" << endl;
	head = new list_node;  
	head->next = NULL;
}

void MyList::insert_list_node(int num)
{
	list_node *Node = new list_node;
	Node->data = num;
	Node->next = NULL;

	list_node *p;
	for(p=head;p->next!=NULL;p=p->next);

	p->next = Node;
}

void MyList::show_list_node()
{
	list_node *p;
	for(p=head->next;p!=NULL;p=p->next)
	{
		cout << "p->data:" << p->data << endl;
		}
}

MyList::~MyList()
{
	cout << "析构函数调用" << endl;
	list_node *q,*p;
	for(p=q=head;p!=NULL;p=q)
	{
		q = p->next;
		delete p;
	}
}