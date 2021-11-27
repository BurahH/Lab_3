#include <iostream>

using namespace std;

#include "Binary_tree.h"
#include "Stack.h"

ListStack::ListStack()
{
	head = NULL;
	size = 0;
}
ListStack::~ListStack()
{
	while (size)
		delete_item();
}
void ListStack::add_item(Tree* tree)
{
	if (head == NULL)
		head = new Stack(tree);
	else
	{
		Stack* temp = new Stack(tree);
		temp->next = head;
		head = temp;
	}
	size++;
}
void ListStack::delete_item()
{
	if (head != NULL)
	{
		Stack* current;
		current = head->next;
		delete(head);
		head = current;
		size--;
	}
	else
	{
		throw out_of_range("deletion isn't possible, the list is empty");
	}
}

Tree* ListStack::gettree()
{
	if (head != NULL)
		return head->tree;
	else
		throw out_of_range("The stack is empty");
}

bool ListStack::Empty()
{
	return head == NULL;
}
