#ifndef HASH_TBL_H
#define HASH_TBL_H

typedef struct Node{
	char *key;
	int value;
        struct Node* next;
}Node;


typedef struct HashTable HashTable; //forward declaration

typedef void (*PrintHashTable)(const HashTable tbl);


struct HashTable {
	int size;
	Node** dataMap;
	PrintHashTable print;
};

void print_hash_table(HashTable tbl);

int hash(char *key, int size);

void set(char *key, int value, HashTable *tbl);

void destroy_hasht(HashTable *tbl); //free memory

int get(char *key, HashTable *tbl);





#endif
