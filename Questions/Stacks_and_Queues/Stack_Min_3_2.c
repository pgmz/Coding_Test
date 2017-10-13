#include <stdio.h>
#include <stdlib.h>

/* Code not fully implemented, functions pushToStack,
 * popFromStack, getPeak, isEmpty, aren't implemented.
 * Neither the type "Stack_t"
 */

Stack_t main_stack;
Stack_t min_stack;

int min_val = 0;

void push(int data){

	if(!isEmpty(main_stack)){
		if(min_val > data){
			pushToStack(min_stack, min_val);
			min_val = data;
		} else if(getPeak(min_stack) > data){
			pushToStack(min_stack, data);
		} else {

		}
	} else {
		min_val = data;
	}

	pushToStack(main_stack, data);

}
