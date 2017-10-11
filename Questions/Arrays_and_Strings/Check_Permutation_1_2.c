#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

#define MAX_HASH_SIZE 27

typedef struct Value_Struct{
	char Key;
	int Value;
}Value_t;

typedef struct Node_Struct{
	Value_t Value;
	struct Node_Struct *chain;
}myNode_t;

myNode_t * node[MAX_HASH_SIZE];

unsigned int hash_function(char Key, int Value);
void insert(unsigned int key, myNode_t * node);
int getValue(char Key);

unsigned int hash_function(char Key, int Value){

	myNode_t * new_node = malloc(sizeof(myNode_t));
	new_node->Value.Key = Key;
	new_node->Value.Value = Value;

	new_node->chain = NULL;

	unsigned int this_key = Key % MAX_HASH_SIZE;

	insert(this_key, new_node);

	return this_key;

}

unsigned int hash_update(char Key, int Value){

	unsigned int this_key = Key % MAX_HASH_SIZE;
	node[this_key]->Value.Value = Value;

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

int getValue(char Key){

	unsigned int this_key = Key % MAX_HASH_SIZE;
	myNode_t * chain = node[this_key];

	if(&chain->Value.Key == NULL){
		return 0;
	}

	while(Key != chain->Value.Key){

		chain = chain->chain;

	}

	return chain->Value.Value;

}

int main(void){

  char s1[] = "adec";
  char s2[] = "cead";

  int i;

  if(sizeof(s1) != sizeof(s2)){
	  printf("%s\n", "Strings have different sizes, not permutation possible");
	  return 0;
  }

  for(i=0; i<sizeof(s1);i++){

	  hash_function(s1[i], getValue(s1[i]) + 1);

  }

  for(i=0; i<sizeof(s2);i++){

	  hash_update(s2[i], getValue(s2[i]) - 1);
	  if(getValue(s2[i]) < 0){
		  printf("%s\n", "String s2 isn't a permutation of s1");
		  return 0;
	  }
  }

  	printf("%s\n", "String s2 is a permutation of s1");
	return 0;

}
