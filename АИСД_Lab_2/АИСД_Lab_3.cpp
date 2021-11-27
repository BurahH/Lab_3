#include <iostream>

using namespace std;

#include "Binary_tree.h"
#include "Stack.h"
#include "Queue.h"
#include "Iterator.h"

int main()
{
	Binary_Tree tree;
	ListQueue queue;
	ListStack stack;
	int counter;
	bool check;
	tree.insert(8);
	tree.insert(10);
	tree.insert(14);
	tree.insert(13);
	tree.insert(3);
	tree.insert(1);
	tree.insert(6);
	tree.insert(4);
	tree.insert(7);
	cout << "A tree is created from the following elements: 8, 10, 14, 13, 3, 1, 6, 4, 7.\n";
	cout << "Breadth-first traversal begins\n";
	myiterator* BFT_iterator = tree.create_BFT_itetator();
	while (BFT_iterator->has_next())
	{
		cout << BFT_iterator->next(&queue) << ' ';
	}
	cout << "\nDepth-first traverse begins\n";
	myiterator* DFT_iterator = tree.create_DFT_itetator();
	while (DFT_iterator->has_next())
	{
		cout << DFT_iterator->next(&stack) << ' ';
	}
	cout << "\nThe following items will now be removed: 10, 13, 6 \n";
	tree.remove(10);
	tree.remove(13);
	tree.remove(6);
	for (counter = 0; counter < 20; counter++)
	{
		check = tree.contains(counter);
		if (check)
			cout << counter << " is present\n";
		else
			cout << counter << " is not present\n";
	}
	return 0;
}