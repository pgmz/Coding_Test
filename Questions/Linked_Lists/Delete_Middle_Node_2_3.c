#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct Node_Struct{
	int myData;
	struct Node_Struct *next;
}myNode_t;

void addNode(int myData);
myNode_t * searchNodePos(int pos);
myNode_t ** searchNodeData(int myData);
void displayList();
bool isListEmpty();
int listSize();

myNode_t * head;
bool isEmpty = true;
bool isFull = false;
int counter;


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

myNode_t ** searchNodeData(int myData){

	myNode_t ** temp = &head;

	do{

		if((**temp).myData == myData){
			break;
		}

		temp = &(**(temp)).next;

	}while(temp);

	return temp;
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

		printf("%d, ", temp->myData);
		temp = temp->next;
	}while(temp);

	printf("\n");

}

void Delete_Middle_Node(myNode_t ** del_node){

	(*del_node) = (*del_node)->next;

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

	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);
	addNode(6);
	displayList();

	myNode_t ** del_node = (searchNodeData(3));

	Delete_Middle_Node(del_node);
	displayList();

	return EXIT_SUCCESS;
}
