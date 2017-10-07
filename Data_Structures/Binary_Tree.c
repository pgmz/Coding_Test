#include <stdio.h>
#include <stdlib.h>

//BST

typedef enum { false, true } bool;

typedef struct Node_Struct{
	int myData;
	struct Node_Struct *left;
  struct Node_Struct *right;
}myNode_t;

myNode_t * root = NULL;

void insertNode(int data);
void searchNode(myNode_t * r, myNode_t * new);
void preTraversal(myNode_t * r);
void inTraversal(myNode_t * r);
void postTraversal(myNode_t * r);

bool isEmpty = true;

void insertNode(int data){

	if(isEmpty){
		root = malloc(sizeof(myNode_t));
		root->myData = data;
		root->left = NULL;
		root->right = NULL;
		isEmpty = false;
		return;
	}

	myNode_t * branch = malloc(sizeof(myNode_t));
	branch->myData = data;
	branch->left = NULL;
	branch->right = NULL;
	searchNode(root, branch);


}

void searchNode(myNode_t * r, myNode_t * new){

	if(new->myData > r->myData){

		if(r->right != NULL){
			searchNode(r->right, new);
		} else {
			r->right = new;
			return;
		}
	}

	if(new->myData <= r->myData){

		if(r->left != NULL){
			searchNode(r->left, new);
		} else {
			r->left = new;
			return;
		}

	}

	return;

}

void preTraversal(myNode_t * r){

	if(r == NULL){
		return;
	} else {
		printf("%d, ", r->myData);
	}

	preTraversal(r->left);
	preTraversal(r->right);

}

void inTraversal(myNode_t * r){

	if(r == NULL){
		return;
	} else {
		inTraversal(r->left);
		printf("%d, ", r->myData);
		inTraversal(r->right);
	}

}

void postTraversal(myNode_t * r){

	if(r == NULL){
		return;
	} else {
		postTraversal(r->left);
		postTraversal(r->right);
		printf("%d, ", r->myData);
	}

}

int main(void) {
	insertNode(20);
	insertNode(10);
	insertNode(25);
	insertNode(9);
	insertNode(26);
	insertNode(24);
	insertNode(15);

	inTraversal(root);


	return EXIT_SUCCESS;
}
