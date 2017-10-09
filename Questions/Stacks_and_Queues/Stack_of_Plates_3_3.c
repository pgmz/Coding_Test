#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

#define START_STACK		0
#define END_STACK		15

typedef struct ssStacks{
	int stack [END_STACK];
	struct ssStacks * plts;
}sstacks;

typedef struct SetOfStacks{
	sstacks * first;
	int pointer;
	int stacks;
}setofstacks;

void newStack(setofstacks * ss);
void pushTo(setofstacks * ss, int stack, int pointer, int data);

void push(setofstacks * ss, int data){

	int this_stack;
	int this_pointer;

	if(ss->pointer >= END_STACK*(ss->stacks)){

		newStack(ss);
		ss->stacks++;

	}

	this_stack = ss->pointer%ss->stacks;
	this_pointer = ss->pointer - this_stack*END_STACK;

	pushTo(ss, this_stack, this_pointer, data);
	ss->pointer++;
}

int pop(setofstacks * ss){

	int popped = 0;

	return popped;

}


void newStack(setofstacks * ss){

	if(ss->first == NULL){
		ss->first = (sstacks *) malloc(sizeof(sstacks));
		ss->first->plts = NULL;
		return;
	}

	sstacks * temp = ss->first;

	while(temp->plts != NULL){
		temp = temp->plts;
	}

	temp->plts = (sstacks *) malloc(sizeof(sstacks));
	temp->plts->plts = NULL;

}

void pushTo(setofstacks * ss, int stack, int pointer, int data){

	sstacks * temp = ss->first;

	int counter = 0;

	while(counter != stack){

		temp = temp->plts;
		counter++;
	}

	temp->stack[pointer] = data;

}

int main(void) {

	setofstacks * ss = malloc(sizeof(setofstacks));
	ss->pointer = 0;
	ss->stacks = 0;
	ss->first = NULL;

	int x = 0;
	for(x = 0; x < 16; x++){
		push(ss, x);
	}

	return EXIT_SUCCESS;
}
