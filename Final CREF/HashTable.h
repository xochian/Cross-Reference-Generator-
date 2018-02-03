#ifndef HASHTABLE_H
#define HASHTABLE_H
#define TSIZE 17 //Table size is set to a prime number, the table size is small as i'm using chaining to handle collisions.

#include "LinkedList.h"

struct HT *hashTable = NULL;

int elementCount = 0;

typedef struct HT
{
	int count;       /* the size of the table */
	struct list *table; /* the table elements */
};

void insertToHash(int , int[], char *);
void deleteFromHash(int);
void searchInHash(int);
void display();

#endif


