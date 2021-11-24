#pragma once

class ListStack;
class ListQueue;

class myiterator
{
public:
	virtual bool has_next();
	virtual int next(ListStack*);
	virtual int next(ListQueue*);
};

class ListStack;

class Tree {
public:
	int data;
	class Tree* left;
	class Tree* right;
	Tree(int initdata)
	{
		this->left = NULL;
		this->right = NULL;
		this->data = initdata;
	}
	~Tree() {}
};

class Binary_Tree {
private:
	Tree* root;
public:
	Binary_Tree();
	~Binary_Tree();
	bool contains(int key);
	void insert(int key);
	void remove(int key);
	myiterator* create_DFT_itetator();
	class DFT_Iterator : public myiterator
	{
	public:
		DFT_Iterator(Tree* root);
		virtual bool has_next();
		virtual int next(ListStack*);
	private:
		Tree* current;
	};
	myiterator* create_BFT_itetator();
	class BFT_Iterator : public myiterator
	{
	public:
		BFT_Iterator(Tree* root);
		virtual bool has_next();
		virtual int next(ListQueue*);
	private:
		Tree* current;
	};
};

class ListStack{
private:
	class Stack{
	public:
		Tree* tree;
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