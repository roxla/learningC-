#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
using namespace std;

struct list_node
{
	int data;				//数据域
	struct list_node *next; //指针域
};

class MyList
{
public:
	MyList();
	void insert_list_node(int num);
	void show_list_node();
	~MyList();

private:
	list_node *head; //头节点的指针域
};

#endif