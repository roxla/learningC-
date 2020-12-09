#include "list.h"

int main()
{
	MyList L;

	L.insert_list_node(10);
	L.insert_list_node(20);
	L.insert_list_node(30);

	L.show_list_node();

	return 0;
}