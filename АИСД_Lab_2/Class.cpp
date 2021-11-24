#include <iostream>

using namespace std;

#include "Class.h"

bool myiterator::has_next()
{
	return false;
}

int myiterator::next(ListStack* stack)
{
	return -1;
}

int myiterator::next(ListQueue* queue)
{
	return -2;
}

Binary_Tree::Binary_Tree()
{
	root = NULL;
}

Binary_Tree::~Binary_Tree(){}

bool Binary_Tree::contains(int key)
{
	Tree* current;
	current = root;
	if (current != NULL)
	{
		while (key != current->data)
		{
			if (key < current->data)
			{
				if (current->left != NULL)
					current = current->left;
				else
				{
					current = NULL;
					break;
				}
			}
			else if (key > current->data)
			{
				if (current->right != NULL)
					current = current->right;
				else
				{
					current = NULL;
					break;
				}
			}
		}
	}
	if (current == NULL)
		return false;
	else
		return true;
}

void Binary_Tree::insert(int key)
{
	if (root != NULL)
	{
		Tree* current;
		current = root;
		while (1)
		{
			if (key <= current->data)
			{
				if (current->left != NULL)
					current = current->left;
				else
				{
					current->left = new Tree(key);
					break;
				}
			}
			else if (key > current->data)
			{
				if (current->right != NULL)
					current = current->right;
				else
				{
					current->right = new Tree(key);
					break;
				}
			}
		}
	}
	else
	{
		root = new Tree(key);
	}
}

void Binary_Tree::remove(int key)
{
	Tree* current = root;
	Tree* previous = NULL;
	Tree* leftleaf = NULL;
	Tree* leftleafprevious = NULL;
	Tree* newunit = NULL;
	while (1)
	{
		if (key < current->data)
		{
			if (current->left != NULL)
			{
				previous = current;
				current = current->left;
			}
			else
			{
				current = NULL;
				break;
			}
		}
		else if (key > current->data)
		{
			if (current->right != NULL)
			{
				previous = current;
				current = current->right;
			}
			else
			{
				current = NULL;
				break;
			}
		}
		else if (key == current->data)
		{
			break;
		}
	}
	if (current == NULL)
		throw invalid_argument("The given value is not present in the tree");
	else
	{
		if ((current->left == NULL) && (current->right == NULL))
		{
			if (previous != NULL)
			{
				if (previous->left == current)
					previous->left = NULL;
				if (previous->right == current)
					previous->right = NULL;
				delete(current);
			}
			else
			{
				delete(current);
				root = NULL;
			}
		}
		else if ((current->left == NULL) || (current->right == NULL))
		{
			if (previous != NULL)
			{
				if (current->left != NULL)
				{
					if (previous->left == current)
					{
						previous->left = current->left;
					}
					if (previous->right == current)
					{
						previous->right = current->left;
					}
					delete(current);
				}
				else if (current->right != NULL)
				{
					if (previous->left == current)
					{
						previous->left = current->right;
					}
					if (previous->right == current)
					{
						previous->right = current->right;
					}
					delete(current);
				}
			}
			else
			{
				if (current->left != NULL)
				{
					root = current->left;
					delete(current);
				}
				else if(current->right != NULL)
				{
					root = current->right;
					delete(current);
				}
			}
		}
		else
		{
			leftleaf = current->right;
			leftleafprevious = current;
			while (leftleaf->left != NULL)
			{
				leftleafprevious = leftleaf;
				leftleaf = leftleaf->left;
			}
			newunit = new Tree(leftleaf->data);
			if (leftleafprevious->left == leftleaf)
				leftleafprevious->left = NULL;
			if (leftleafprevious->right == leftleaf)
				leftleafprevious->right = NULL;
			delete(leftleaf);
			if (previous != NULL)
			{
				if (previous->left == current)
				{
					previous->left = newunit;
				}
				if (previous->right == current)
				{
					previous->right = newunit;
				}
			}
			else
			{
				root = newunit;
			}
			newunit->left = current->left;
			newunit->right = current->right;
			delete(current);
		}
	}


}

myiterator* Binary_Tree::create_DFT_itetator()
{
	return new DFT_Iterator(root);
}

Binary_Tree::DFT_Iterator::DFT_Iterator(Tree* root)
{
	current = root;
}

int Binary_Tree::DFT_Iterator::next(ListStack* stack)
{
	if (current == NULL)
	{
		throw out_of_range("No more elements");
	}
	Tree* temp = current;
	if(current->right != NULL)
		stack->add_item(current->right);
	if (current->left != NULL)
	{
		current = current->left;
	}
	else
	{
		if (!stack->Empty())
		{
			current = stack->gettree();
			stack->delete_item();
		}
		else
			current = NULL;
	}
	return temp->data;
}

bool Binary_Tree::DFT_Iterator::has_next()
{
	return current != nullptr;
}

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
	if(head != NULL)
	    return head->tree;
	else
		throw out_of_range("The stack is empty");
}

bool ListStack::Empty()
{
	return head == NULL;
}

myiterator* Binary_Tree::create_BFT_itetator()
{
	return new BFT_Iterator(root);
}

Binary_Tree::BFT_Iterator::BFT_Iterator(Tree* root)
{
	current = root;
}

int Binary_Tree::BFT_Iterator::next(ListQueue* queue)
{
	if (current == NULL)
	{
		throw out_of_range("No more elements");
	}
	Tree* temp = current;
	if (current->left != NULL)
		queue->add_item(current->left);
	if (current->right != NULL)
		queue->add_item(current->right);
	if (!queue->Empty())
	{
		current = queue->gettree();
		queue->delete_item();
	}
	else
		current = NULL;
	return temp->data;
}

bool Binary_Tree::BFT_Iterator::has_next()
{
	return current != nullptr;
}



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