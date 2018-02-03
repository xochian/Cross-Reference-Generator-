#include "HashTable.h"


void insertToHash(int key, int lines[], char *variable)
{

	int hashIndex = key % elementCount;

	struct list *newList = constructList(key, lines, variable);

	if (!hashTable[hashIndex].table)
	{

		hashTable[hashIndex].table = newList;

		hashTable[hashIndex].count = 1;

		return;

	}

	/* adding new node to the list */

	newList->next = (hashTable[hashIndex].table);

	hashTable[hashIndex].table = newList;

	hashTable[hashIndex].count++;

	return;

}

void deleteFromHash(int key)
{

	/* find the bucket using hash index */

	int hashIndex = key % elementCount;
	int flag = 0;

	struct list *temp;
	struct list *newList;

	/* get the list head from current bucket */

	newList = hashTable[hashIndex].table;

	if (!newList)
	{
		printf("Given data is not present in hash Table!!\n");
		return;
	}

	temp = newList;

	while (newList != NULL)
	{

		/* delete the node with given key */
		if (newList->key == key)
		{

			flag = 1;

			if (newList == hashTable[hashIndex].table)
			{
				hashTable[hashIndex].table = newList->next;
			}

			else
			{
				temp->next = newList->next;
			}



			hashTable[hashIndex].count--;

			free(newList);
			break;

		}

		temp = newList;

		newList = newList->next;


	}

	if (flag)
	{
		printf("Data deleted successfully from Hash Table\n");
	}

	else
	{
		printf("Given data is not present in hash Table!!!!\n");
	}

	return;


}

void searchInHash(int key)
{
	int hashIndex = key % elementCount, flag = 0;

	struct list *newList;

	newList = hashTable[hashIndex].table;

	if (!newList)
	{
		printf("Search element unavailable in hash table\n");
		return;
	}

	while (newList != NULL)
	{
		if (newList->key == key)
		{
			printf("Key		: %d\n", newList->key);
			printf("Variable: %s\n", newList->variable);
			for (int i = 0; i < SIZE - 1 && newList->lines[i] >= 0; i++)
			{
				printf("Lines   :%d ", newList->lines[i]);
			}
			printf("\n");

			flag = 1;
			break;
		}

		newList = newList->next;

	}

	if (!flag)
	{
		printf("Search element unavailable in hash table\n");
	}

	return;
}

void display()
{

	struct list *newList;

	int i;

	for (i = 0; i < elementCount; i++)
	{
		if (hashTable[i].count == 0)
		{
			continue;
		}

		newList = hashTable[i].table;

		if (!newList)
		{
			continue;
		}
		printf("\nData at index %d in Hash Table:\n", i);

		printf("Key     Variable          Lines   \n");

		printf("--------------------------------\n");

		while (newList != NULL)
		{
			printf("%-12d", newList->key);
			printf("%-15s", newList->variable);

			for (int i = 0; i < SIZE - 1 && newList->lines[i] >= 0; i++)
			{
				printf("%d ", newList->lines[i]);
			}

			printf("\n--------------------------------\n");
			newList = newList->next;
		}
	}

	return;

}
