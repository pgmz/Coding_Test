#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

#define MAX_HASH_SIZE 15

typedef struct Value_Struct{
	char Key[10];
	char Value[10];
}Value_t;

typedef struct Node_Struct{
	Value_t Value;
	struct Node_Struct *chain;
}myNode_t;

myNode_t * node[MAX_HASH_SIZE];

unsigned int hash_function(char Key[10], char Value[10]);
void insert(unsigned int key, myNode_t * node);
Value_t getValue(char Key[10]);

unsigned int hash_function(char Key[10], char Value[10]){

	myNode_t * new_node = malloc(sizeof(myNode_t));
	strcpy(new_node->Value.Key, Key);
	strcpy(new_node->Value.Value, Value);

	new_node->chain = NULL;

	unsigned int this_key = Key[0] % MAX_HASH_SIZE;

	insert(this_key, new_node);

	return this_key;

}

void insert(unsigned int key, myNode_t * new){

	myNode_t ** ret_node = &node[key];

	while(*(ret_node) != NULL){

		((ret_node)) = &(**(ret_node)).chain;

	}

	(*(ret_node)) = new;

	return;
}

Value_t getValue(char Key[10]){

	unsigned int this_key = Key[0] % MAX_HASH_SIZE;
	myNode_t * chain = node[this_key];

	while(strcmp(Key, chain->Value.Key)){

		chain = chain->chain;

	}

	return chain->Value;

}

int main(void){

	hash_function("Pato", "Patricio");
	hash_function("Said", "Josué");
	hash_function("Moik", "Miguel");
	hash_function("Tachi", "Alberto");
	hash_function("Ramiro", "Erick");
	hash_function("Ricardo", "Erick");
	hash_function("Ricky", "Erick");

	Value_t new = getValue("Ricardo");
	printf("Key: %s, Value: %s", new.Key, new.Value);

	return 0;

}
