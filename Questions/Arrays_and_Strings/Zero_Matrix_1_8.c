#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

int main(void) {

	int row, col;
	int matrix[5][5] = {{0,1,2,3,4},
			{5,6,7,8,9},
			{1,0,1,1,1},
			{2,1,3,1,4},
			{1,5,1,6,1}};

	int row_tz = 0;
	int col_tz = 0;
	int index;

	for(row = 0; row < 5; row++){
		for(col = 0; col < 5; col++){

			printf("%d, ", matrix[row][col]);

		}
		printf("\n");
	}

	for(row = 0; row < 5; row++){
		for(col = 0; col < 5; col++){

			if(matrix[row][col] == 0){
				row_tz = row_tz | (1 << row);
				col_tz = col_tz | (1 << col);
			}

		}
	}

	if((col_tz == 0) && (row_tz == 0)){
		printf("No zeros found! :D");
	}

	for(row = 0; row < 5; row++){

		if(0 != ((1 << row) & row_tz)){

			for(index = 0; index < 5; index++){
				matrix[row][index] = 0;
			}

		}

	}

	for(col = 0; col < 5; col++){

		if(0 != ((1 << col) & col_tz)){

			for(index = 0; index < 5; index++){
				matrix[index][col] = 0;
			}

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
