#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

#define MAX_QUEUE_SIZE    100

int myQueue[MAX_QUEUE_SIZE];
int QueueRearInd = 0;
int QueueFrontInd = 0;

bool isEmpty = true;
bool isFull = false;

void add(int data);
int take();

void add(int data){

	if(isFull){
		return;
	}

	myQueue[QueueRearInd] = data;
	QueueRearInd++;
	isEmpty = false;

	if(QueueRearInd == MAX_QUEUE_SIZE){
		isFull = true;
	}
}

int take(){

	int pop;

	if(isEmpty){
		return 0;
	}

	pop = myQueue[QueueFrontInd];
	myQueue[QueueFrontInd] = 0;
	QueueFrontInd++;

	if(QueueFrontInd == QueueRearInd){
		isEmpty = true;
	}

	return pop;

}

void displayQueue(){

	int index;
	for(index = QueueFrontInd; index < QueueRearInd; index++){
		printf("%d\n", myQueue[index]);
	}

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
