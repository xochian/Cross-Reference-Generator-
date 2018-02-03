#include "LinkedList.h"

struct list *constructList(int key, int lines[], char *variable)
{
	struct list *newList;

	newList = (struct list *)malloc(sizeof(struct list));
	newList->key = key;

	for (int i = 0; i < SIZE - 1; i++)
	{
		newList->lines[i] = lines[i];
	}

	strcpy_s(newList->variable, sizeof(newList->variable), variable);

	newList->next = NULL;

	return newList;
}



void sInsert(struct list *pointer, int key, int lines[SIZE], char *variable)
{
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
	}

	pointer->next = (struct list *)malloc(sizeof(struct list));
	pointer->key = key;

	for (int i = 0; i < SIZE - 1; i++)
	{
		pointer->lines[i] = lines[i];
	}

	strcpy_s(pointer->variable, sizeof(pointer->variable), variable);

	pointer->next = NULL;
}

int sFind(struct list *pointer, int key)
{
	pointer = pointer->next;

	while (pointer != NULL)
	{
		if (pointer->key == key)
		{
			return 1;
		}
		pointer = pointer->next;
	}

	return 0;
}

void displayList(struct list *pointer)
{
	if (pointer == NULL)
	{
		return;
	}

	while (pointer != NULL)
	{
		printf("%-12d", pointer->key);
		printf("%-15s", pointer->variable);

		for (int i = 0; i < SIZE - 1; i++)
		{
			printf("%d ", pointer->lines[i]);
		}

		printf("--------------------------------\n");
		displayList(pointer->next);
	}

	return;
}