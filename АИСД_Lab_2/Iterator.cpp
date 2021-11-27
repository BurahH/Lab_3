#include "Iterator.h"

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
