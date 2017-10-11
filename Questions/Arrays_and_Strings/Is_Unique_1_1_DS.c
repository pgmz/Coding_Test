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

  char snu[] = "quesomanchego";

  int i;
  for(i=0; i<sizeof(snu)-1;i++){

    if(getValue(snu[i]) == 0){
      hash_function(snu[i], 1);
    }else{
      printf("%s\n", "not unique");
      break;
    }

  }

  if(i == (sizeof(snu) - 1)){
    printf("%s\n", "unique");

  }

	return 0;

}
