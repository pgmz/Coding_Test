#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

#define START_STACK_1	0
#define START_STACK_2	20
#define START_STACK_3	40

#define END_STACK		60

#define END_STACK_1 	(START_STACK_2) - 1
#define END_STACK_2 	(START_STACK_3) - 1
#define END_STACK_3 	(END_STACK) - 1

int array[60];

int index_1 = START_STACK_1;
int index_2 = START_STACK_2;
int index_3 = START_STACK_3;

void push(int stack, int data){

	switch(stack){

	case 1:

		if(index_1 > END_STACK_1){
			printf("%s \n", "First Stack is full");
			return;
		}

		array[index_1] = data;
		index_1++;
		break;

	case 2:

		if(index_2 > END_STACK_2){
			printf("%s \n", "Second Stack is full");
			return;
		}

		array[index_2] = data;
		index_2++;
		break;

	case 3:

		if(index_3 > END_STACK_3){
			printf("%s \n", "Third Stack is full");
			return;
		}

		array[index_3] = data;
		index_3++;
		break;

	}

}

int pop(int stack){


	switch(stack){

	case 1:

		if(index_1 == START_STACK_1){
			printf("%s \n", "First Stack is Empty");
			return 0;
		}

		index_1--;
		return array[index_1 + 1];
		break;

	case 2:

		if(index_2 == START_STACK_2){
			printf("%s \n", "Second Stack is Empty");
			return 0;
		}

		index_2--;
		return array[index_2 + 1];
		break;

	case 3:

		if(index_3 == START_STACK_3){
			printf("%s \n", "Third Stack is Empty");
			return 0;
		}

		index_3--;
		return array[index_3 + 1];
		break;

	}

	return 0;

}

int main(void) {


	int x;
	for(x = 0; x < 22; x++){
		push(1, x);
		push(2, x);
		push(3, x);
	}

	for(x=0; x < 20; x++){
		printf("%d, ", array[x]);
	}
	printf("\n");

	for(x = 0; x < 22; x++){
		printf("%d, ", pop(1));
		printf("%d, ", pop(2));
		printf("%d, ", pop(3));

	}

	printf("\n");

	return EXIT_SUCCESS;
}
