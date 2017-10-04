#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

#define MAX_STACK_SIZE    100

int myStack[MAX_STACK_SIZE];
int StackIndex = 0;

bool isEmpty = true;
bool isFull = false;

void pushNode(int data);
int popNode();

void pushNode(int data){

  if(isFull){
    return;
  }

  myStack[StackIndex] = data;
  StackIndex++;
  isEmpty = false;

  if(StackIndex == MAX_STACK_SIZE){
    isFull = true;
  }


}

int popNode(){

  int pop;

  if(isEmpty){
    return;
  }

  pop = myStack[StackIndex];
  StackIndex--;

  if(StackIndex == -1){
    isEmpty = true;
  }

}

void displayStack(){

  int index;
	for(index = StackIndex-1; index >= 0; index--){
    printf("%d\n", myStack[index]);
  }

}


int main(void) {

	pushNode(12);
	pushNode(6);
	pushNode(5);
	displayStack();
  pushNode(20);
  pushNode(22);
  displayStack();
  popNode();
  popNode();
  popNode();
  displayStack();

	return EXIT_SUCCESS;
}
