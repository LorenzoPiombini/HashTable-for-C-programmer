#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tbl.h"


void print_hash_table(HashTable tbl){
        int i = 0;
        for(i; i < tbl.size;i++ ){
                printf("%d: \n",i);
                Node *node = tbl.dataMap[i];

                        while(node) {
                                if(node->key){
                                printf("\t{ %s,%d }\n",node->key,node->value);
                                }
                                node = node->next;
                        }

        }


}

int hash(char *key, int size){
	int hash = 0;
	int i = 0;

	int len = strlen(key);
	for (i ; i < len; i++){
		int asciiValue = (int)key[i];
		hash = (hash + asciiValue * 23) % size;
	}

	return hash;
}

int get(char *key, HashTable *tbl){
	int index = hash(key, tbl->size);
	Node* temp = tbl->dataMap[index];
	while(temp != NULL){
		if (temp->key == key) return temp->value;
		temp = temp->next;
	}

	return 0;

}


void set(char *key, int value, HashTable* tbl){
	int index = hash(key, tbl->size);
	Node* newNode = malloc(sizeof(Node));
	if(!newNode){
		printf("failed to allocate memory while setting the HashTable.\n");
		return;
	}
	newNode->key = key;
	newNode->value= value;
	newNode->next = NULL;

	if(tbl->dataMap[index] == NULL){
		tbl->dataMap[index]= newNode;
	}else {
		Node* temp = tbl->dataMap[index];
		while(temp->next != NULL){
			temp= temp->next;
		}
		temp->next = newNode;
	}

}

void destroy_hasht(HashTable *tbl){
	int i = 0;
	for(i; i < tbl->size; i++){
		Node* current = tbl->dataMap[i];
		while( current != NULL){
			Node* next = current->next;
			free(current);
			current = next;

		}
	}

	free(tbl->dataMap);

}

