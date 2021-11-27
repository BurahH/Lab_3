#pragma once

class Tree;

class ListStack {
private:
	class Stack {
	public:
		Tree *tree;
		Stack* next;
		Stack(Tree* tree)
		{
			this->tree = tree;
			this->next = NULL;
		}
		~Stack() {}
	};
	Stack* head;
	size_t size;
public:
	ListStack();
	~ListStack();
	bool Empty();
	void add_item(Tree* tree);
	void delete_item();
	Tree* gettree();
};