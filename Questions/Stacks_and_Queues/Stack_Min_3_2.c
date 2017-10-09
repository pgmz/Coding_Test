#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

#define START_STACK		0
#define END_STACK		20


int array[END_STACK];

int pointer = START_STACK;
int min = 0x7FFFFFFF;

void push(int data){

	min = (min > data)?(data):(min);

	if(pointer > END_STACK){
		printf("%s \n", "Stack is full");
		return;
	}

	array[pointer] = data;
	pointer++;


}

int pop(){

	int popped;

	if(pointer == START_STACK){
		printf("%s \n", "Stack is Empty");
		return 0;
	}

	popped =  array[pointer];
	pointer--;

	return popped;

}

int getMin(){
	return min;
}

int main(void) {


	int x;
	for(x = 20; x >= 0; x--){
		push(10*x);
		printf("%d, ", getMin());


	}
	printf("\n");

	for(x = 0; x < 20; x++){
		printf("%d, ", pop());
		printf("%d, ", getMin());


	}

	printf("\n");

	return EXIT_SUCCESS;
}
