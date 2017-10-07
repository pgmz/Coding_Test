#include <stdio.h>
#include <stdlib.h>

#define BINARY_TREE_ARRAY_SIZE          32
#define BINARY_TREE_INDEX_LEFT(i)       ((2*i) + 1)
#define BINARY_TREE_INDEX_RIGHT(i)      ((2*i) + 2)
#define BINARY_TREE_INDEX_ROOT          0

typedef enum { false, true } bool;

int BinaryTreeArray[BINARY_TREE_ARRAY_SIZE];

bool isEmpty = true;
bool isFull = false;

void insertNode(int data, int pos, int side);
int searchNode(int deep, int side);

void preTraversal();
void inTraversal();
void postTraversal();

void insertNode(int data, int pos, int side){



	if(isEmpty){

    BinaryTreeArray[BINARY_TREE_INDEX_ROOT] = data;

	} else {

    if(side){
      BinaryTreeArray[BINARY_TREE_INDEX_LEFT(pos)] = data;

    } else {
      BinaryTreeArray[BINARY_TREE_INDEX_RIGHT(pos)] = data;

    }
	}

	isEmpty = false;
}

int searchNode(int deep, int side){



	return 1;

}

void preTraversal(){

  int counter = 0;
	for(counter = 0; counter < BINARY_TREE_ARRAY_SIZE; counter++){
    printf("%d\n", BinaryTreeArray[counter]);
  }

}


int main(void) {

  insertNode(5, 0, 0);
  insertNode(1, 0, 0);
  insertNode(2, 0, 1);
  insertNode(7, 1, 0);
  insertNode(8, 1, 1)
  preTraversal();
	return EXIT_SUCCESS;
}
