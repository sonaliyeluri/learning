#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 20

struct hashTable {
	int data;
	int key;
};

struct hashTable* hashArray[SIZE];
struct hashTable* dummyItem;
struct hashTable* item;

int hashCode (int key) {
	return key%SIZE;
}

void insert(int key, int data) {
	struct hashTable *item = malloc(sizeof(struct hashTable));
	item->data = data;
	item->key = key;
	int hashIndex = hashCode(key);
	while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
		hashIndex = hashIndex + 1;
		hashIndex %= SIZE;
	}
	hashArray[hashIndex] = item;
}

struct hashTable *delete(struct hashTable *item) {
	int key = item->key;
	int hashIndex = hashCode(key);
	while (hashArray[hashIndex] != NULL) {
		if (hashArray[hashIndex]->key == key) {
			struct hashTable *temp = hashArray[hashIndex];
			hashArray[hashIndex] = dummyItem;
			return temp;
		}
		hashIndex = hashIndex + 1;
		hashIndex %= SIZE;
	}
	return NULL;
}

struct hashTable *search(int key) {
	int hashIndex = hashCode(key);
	while (hashArray[hashIndex] != NULL) {
		if (hashArray[hashIndex]->key == key)
			return hashArray[hashIndex];
		hashIndex = hashIndex + 1;
		hashIndex %= SIZE;
	}
	return NULL;
}

void display() {
	int i;
	for (i=0;i<SIZE;i++) {
		if (hashArray[i] != NULL)
			printf("(%d,%d)",hashArray[i]->key, hashArray[i]->data);
		else
			printf("~~~");
	}
	printf("\n");
}

int main() {
	dummyItem = malloc(sizeof(struct hashTable));
	dummyItem->data = -1;
	dummyItem->key = -1;
	insert(1,20);
	insert(2,30);
	insert(42,50);
	insert(9,99);
	insert(37,97);
	insert(17,11);
	insert(17,13);
	insert(12,29);
	display();
	item = search(37);
	if (item != NULL)
		printf("Element found: %d\n",item->data);
	else
		printf("Element Not found\n");
	item = search(17);
	if (item != NULL)
                printf("Element found: %d\n",item->data);
        else
                printf("Element Not found\n");
	delete(item);
	item = search(17);
	if (item != NULL)
                printf("Element found: %d\n",item->data);
        else
                printf("Element Not found\n");
	delete(item);
	item = search(17);
        if (item != NULL)
                printf("Element found: %d\n",item->data);
        else
                printf("Element Not found\n");
}
