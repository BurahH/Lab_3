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