#pragma once

class Tree;

class ListQueue {
private:
	class Queue {
	public:
		Tree* tree;
		Queue* next;
		Queue(Tree* tree)
		{
			this->tree = tree;
			this->next = NULL;
		}
		~Queue() {}
	};
	Queue* head;
	Queue* last;
	size_t size;
public:
	ListQueue();
	~ListQueue();
	bool Empty();
	void add_item(Tree* tree);
	void delete_item();
	Tree* gettree();
};