#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct Node_Struct{
	int myData;
	struct Node_Struct *next;
}myNode_t;

myNode_t * headPtr = NULL;
myNode_t * stackPtr;

bool isEmpty = true;
bool isFull = false;

void pushNode(int data);
myNode_t * popNode();

void pushNode(int data){

  myNode_t * new = malloc(sizeof(myNode_t));
  new->myData = data;

  if(isEmpty){

    new->next =NULL;
    headPtr = new;
    stackPtr = headPtr;

  } else {

	new->next = stackPtr;
	stackPtr = new;

  }

  isEmpty = false;


}

myNode_t * popNode(){

  myNode_t * temp;

  if(isEmpty){

	  return NULL;

  } else {

	temp = stackPtr;
	stackPtr = stackPtr->next;
	free(temp);
  }

  return temp;
}

void displayStack(){

	myNode_t * temp = stackPtr;

	do{

		printf("%d \n", temp->myData);
		temp = temp->next;
	}while(temp);

}


int main(void) {

  stackPtr = headPtr;

	pushNode(12);
	pushNode(6);
	pushNode(5);
	displayStack();

	popNode();
	popNode();

	displayStack();

	pushNode(30);
	pushNode(31);
	pushNode(32);
	displayStack();

	popNode();
	displayStack();

	popNode();
	displayStack();

	return EXIT_SUCCESS;
}
