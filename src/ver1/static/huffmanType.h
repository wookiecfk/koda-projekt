#include <iostream>

#define dictionarySize 256

struct node
{
	int value;
	int sign;
	struct node *left;
	struct node *right;
};