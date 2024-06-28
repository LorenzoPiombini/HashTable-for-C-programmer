#include <stdio.h>
#include <stdlib.h>
#include "hash_tbl.h"
#include <string.h>


int main(){

	Node** dataMap = calloc(7, sizeof(Node));
	HashTable ht = {7,dataMap, print_hash_table};
	
	if(!dataMap){
		printf("error in allocating memory for the node");
		return 1;
	}


	set("nails",100, &ht);
	set("tile",100, &ht);
	set("lumber",80, &ht);

	set("bolts",1200, &ht);
	set("screw",240, &ht);

	char *name = "lumber";

	ht.print(ht);

	int found = get(name,&ht);
	if(found){

		printf("%s: %d.\n", name, found);
		
	} else {
		printf("\"%s\" not found.\n",name);
	}


	destroy_hasht(&ht);
	return 0;
}
