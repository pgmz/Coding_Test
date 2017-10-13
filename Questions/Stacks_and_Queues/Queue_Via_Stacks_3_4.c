#include <stdio.h>
#include <stdlib.h>

/* Code not fully implemented, functions pushToStack,
 * popFromStack, getPeak, isEmpty, aren't implemented.
 * Neither the type "Stack_t"
 */

Stack_t S_order;
Stack_t S_norder;

void push(int data){

	while(!isEmpty(S_norder)){

    pushToStack(S_order, popFromStack(S_norder));

	}

  pushToStack(S_order, data;

}

int pop(){

	while(!isEmpty(S_order)){

    pushToStack(S_norder, popFromStack(S_order));

	}

  pushToStack(S_norder, data;

}
