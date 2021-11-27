#include <iostream>

using namespace std;

#include "Queue.h"
#include "Binary_tree.h"

ListQueue::ListQueue()
{
	head = NULL;
	last = NULL;
	size = 0;
}
ListQueue::~ListQueue()
{
	while (size)
		delete_item();
}
void ListQueue::add_item(Tree* tree)
{
	if (head == NULL)
	{
		Queue* temp = new Queue(tree);
		head = temp;
		last = temp;
	}
	else
	{
		Queue* temp = new Queue(tree);
		last->next = temp;
		last = temp;
	}
	size++;
}
void ListQueue::delete_item()
{
	if (head != NULL)
	{
		Queue* current;
		current = head->next;
		delete(head);
		head = current;
		if (head == NULL)
			last = NULL;
		size--;
	}
	else
	{
		throw out_of_range("deletion isn't possible, the list is empty");  //Exception if list is empty
	}
}

Tree* ListQueue::gettree()
{
	if (head != NULL)
		return head->tree;
	else
		throw out_of_range("The stack is empty");
}

bool ListQueue::Empty()
{
	return head == NULL;
}