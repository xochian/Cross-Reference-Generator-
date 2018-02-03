#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define SIZE 30

#include <stdio.h>
#include <stdlib.h>
#include <String.h>

struct list
{
	int key;
	int lines[SIZE];
	char variable[SIZE];
	struct list *next;
};


struct list *constructList(int, int[], char *);
void sInsert(struct list *, int, int[SIZE], char *);
int sFind(struct list *, int);
void displayList(struct list *);

#endif
