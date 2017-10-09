#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

int main(void) {

	int row, col;
	int matrix[5][5] =
	{
			{0,1,2,3,4},
			{0,1,2,3,4},
			{0,1,2,3,4},
			{0,1,2,3,4},
			{0,1,2,3,4}
	};

	int aux;

	for(row = 0; row < 5; row++){
		for(col = 0; col < 5; col++){

			printf("%d, ", matrix[row][col]);

		}
		printf("\n");
	}

	for(row = 0; row < 5; row++){
		for(col = 0; col < 5; col++){

			aux = matrix[row][col];
			matrix[row][col] = matrix[4 - col][row];
			matrix[4 - col][row] = aux;

		}
	}

	for(row = 0; row < 5; row++){
		for(col = 0; col < 5; col++){

			printf("%d, ", matrix[row][col]);

		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}
