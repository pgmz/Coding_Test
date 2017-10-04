#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct Node_Struct{
	int myData;
	struct Node_Struct *next;
}myNode_t;

myNode_t * head;
bool isEmpty = true;
bool isFull = false;
int counter;

void addNode(int myData);
myNode_t * searchNodePos(int pos);
myNode_t * searchNodeData(int myData);
void displayList();
bool isListEmpty();
int listSize();

void addNode(int myData){

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

		printf("%d \n", temp->myData);
		temp = temp->next;
	}while(temp);

}

bool isListEmpty(){
	return isEmpty;
}

int listSize(){
	return counter;
}

int main(void) {

	head = NULL;
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	addNode(12);
	addNode(6);
	addNode(5);
	addNode(10);
	addNode(100);
	addNode(50);
	addNode(10);
	displayList();



	return EXIT_SUCCESS;
}
