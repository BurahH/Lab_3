#pragma once

#include "Iterator.h"

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