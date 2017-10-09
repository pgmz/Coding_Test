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

myNode_t * Return_Kth_Last_Counter(int k){

	myNode_t * temp = head;

	int kth = counter - k;
	int to_k = 0;
	while(temp != NULL){

		if(to_k >= kth){

			printf("%d, ",temp->myData);

		}

		to_k++;
		temp = temp->next;

	}

	printf("\n");
	return NULL;

}

int Return_Kth_Last_recursive(myNode_t * nd, int k){

	int my_k;

	if(nd->next == NULL){

		printf("%d, ", nd->myData);
		return 1;

	}else{

		my_k = Return_Kth_Last_recursive(nd->next, k);
		if(my_k < k){
			printf("%d, ", nd->myData);
		}
	}

	return my_k + 1;

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

	int x = 0;
	for(x = 0; x < 15; x++){
		addNode(x);
	}

	displayList();

	Return_Kth_Last_recursive(head, 5);

	return EXIT_SUCCESS;
}
