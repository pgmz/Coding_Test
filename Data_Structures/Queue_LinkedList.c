#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct Node_Struct{
	int myData;
	struct Node_Struct *next;
}myNode_t;

myNode_t * QueueRearInd = NULL;
myNode_t * QueueFrontInd = NULL;

bool isEmpty = true;
bool isFull = false;

void add(int data);
myNode_t * take();

void add(int data){

	myNode_t * new = malloc(sizeof(myNode_t));

	new->myData = data;
	new->next = NULL;

	if(isEmpty){
		new->next = NULL;
		QueueRearInd = new;
		QueueFrontInd = new;

	} else {
		QueueRearInd->next = new;
		QueueRearInd = new;
	}

	isEmpty = false;
}

myNode_t *  take(){

	myNode_t * pop;

	if(isEmpty){
		return 0;
	}

	pop = QueueFrontInd;
	QueueFrontInd = QueueFrontInd->next;
	free(pop);

	return NULL;

}

void displayQueue(){

	myNode_t * temp = QueueFrontInd;

	do{

		printf("%d \n", temp->myData);
		temp = temp->next;
	}while(temp);

}


int main(void) {

	add(12);
	add(6);
	add(5);
	displayQueue();
	add(20);
	add(22);
	displayQueue();
	take();
	take();
	take();
	displayQueue();
	add(22);
	take();
	displayQueue();

	return EXIT_SUCCESS;
}
