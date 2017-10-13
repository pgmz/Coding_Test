#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct Node_Struct{
	int myData;
	struct Node_Struct *next;
}myNode_t;

void addNode(myNode_t ** node, int myData);
void displayList(myNode_t * head);


bool isEmpty = true;
bool isFull = false;
int counter;


void addNode(myNode_t ** node, int myData){

	myNode_t * temp = *(node);
	myNode_t * new = malloc(sizeof(myNode_t));

	new->myData = myData;
	new->next = NULL;

	if((*node) == NULL){
		(*node) = new;
	} else {

		while((*node)->next != NULL){

			(*node) = (myNode_t *)((*node)->next);

		}

		(*node)->next = new;
		*(node) = temp;

	}


	isEmpty = false;
	counter++;
}


void displayList(myNode_t * head){

	myNode_t * temp = head;

	do{

		printf("%d", temp->myData);
		temp = temp->next;
	}while(temp);
	printf("\n");

}

myNode_t * sumLists(myNode_t * l1, myNode_t * l2){

	int aux, carry, val;
	myNode_t * new = NULL;

	while(l1 != NULL || l2 != NULL){

		val = 0;

		if(l1 != NULL){
			val = val + l1->myData;
		}
		if(l2 != NULL){
			val = val + l2->myData;
		}

		val = val + carry;
		aux = val % 10;
		carry = (val - aux)/10;
		val = aux;

		addNode(&new, val);
		l1 = l1->next;
		l2 = l2->next;


	}

	return new;


}

int main(void) {

	myNode_t * l1 = NULL;
	myNode_t * l2 = NULL;

	addNode(&l1, 7);
	addNode(&l1, 1);
	addNode(&l1, 6);
	addNode(&l2, 5);
	addNode(&l2, 9);
	addNode(&l2, 2);
	displayList(l1);
	displayList(l2);

	myNode_t * res = sumLists(l1, l2);
	displayList(res);

	return EXIT_SUCCESS;
}
