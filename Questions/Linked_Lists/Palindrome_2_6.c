#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;


#define MAX_STACK_SIZE    100

char myStack[MAX_STACK_SIZE];
int StackIndex = 0;

bool isEmptyStack = true;
bool isFullStack = false;

void pushNode(char data);
char popNode();

void pushNode(char data){

  if(isFullStack){
    return;
  }

  myStack[StackIndex] = data;
  StackIndex++;
  isEmptyStack = false;

  if(StackIndex == MAX_STACK_SIZE){
	  isFullStack = true;
  }


}

char popNode(){

  char pop;

  if(isEmptyStack){
    return 0;
  }

  pop = myStack[StackIndex - 1];
  StackIndex--;

  if(StackIndex == -1){
    isEmptyStack = true;
  }

  return pop;

}

void displayStack(){

  int index;
	for(index = StackIndex-1; index >= 0; index--){
    printf("%d\n", myStack[index]);
  }

}

typedef struct Node_Struct{
	char myData;
	struct Node_Struct *next;
}myNode_t;

void addNode(char myData);
myNode_t * searchNodePos(int pos);
myNode_t * searchNodeData(int myData);
void displayList();
bool isListEmpty();
int listSize();

myNode_t * head;
bool isEmpty = true;
bool isFull = false;
int counter;


void addNode(char myData){

	myNode_t * temp;
	myNode_t * new = malloc(sizeof(myNode_t));

	new->myData = myData;
	new->next = NULL;

	if(isEmpty){
		head =  new;
	} else {
		temp = searchNodePos(counter);
		temp->next = new;

	}
	isEmpty = false;
	counter++;
}

myNode_t * searchNodeData(int myData){

	myNode_t * temp = head;
	myNode_t * node = NULL;

	do{

		if(temp->myData == myData){
			node = temp;
			break;
		}

		temp = temp->next;
	}while(temp);

	return node;
}

myNode_t * searchNodePos(int pos){
	int count = 1;
	myNode_t * node = NULL;
	myNode_t * temp = head;

	do{

		if(pos == count){
			node = temp;
			break;
		}
		count++;
		temp = temp->next;

	}while(temp);

	return node;
}

void displayList(){

	myNode_t * temp = head;

	do{

		printf("%c \n", temp->myData);
		temp = temp->next;
	}while(temp);

}

bool isListEmpty(){
	return isEmpty;
}

int listSize(){
	return counter;
}

int isPalindrome(myNode_t * n){

	int size = 0;
	myNode_t * p = n;

	while(p != NULL){
		size++;
		p = p->next;
	}

	int index;
	for(index = 0; index < size/2; index++){

		pushNode(n->myData);
		n = n->next;

	}

	if(size%2 != 0){
		n = n->next;
	}

	for(index = (size/2)+(size%2); index < size; index++){

		if(popNode() != n->myData){
			return false;
		} else {
			n = n->next;
		}

	}



	return true;

}

int main(void) {

	head = NULL;
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	addNode('a');
	addNode('b');
	addNode('c');
	addNode('c');
	addNode('b');
	addNode('a');
	if(isPalindrome(head)){
		printf("Is palindrome");
	} else {
		printf("Is not palindrome");
	}

	return EXIT_SUCCESS;
}
