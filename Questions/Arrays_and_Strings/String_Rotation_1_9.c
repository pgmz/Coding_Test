#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

#define MYSOL		false

int main(void) {

	char s2[] = "erbottlewat";
	char s1[] = "waterbottle";

	int size_s2 = sizeof(s2);
	int size_s1 = sizeof(s1);

	if(size_s2 != size_s1){
		printf("s1 isn't a rotation of s2, they are different");
		return 0;
	}

#if MYSOL

	int index = 0;
	int index_aux = 0;

	for(index = 0; index < size_s2; index++){

		if(s2[index] == s1[index_aux]){
			index_aux++;
		}
	}

	char * a = strstr(s2, &s1[index_aux]);
#else

	char * sdoubled = malloc(sizeof(s2)*2);

	strcat(sdoubled, s2);
	strcat(sdoubled, s2);

	char * a = strstr(sdoubled, s1);
#endif

	if(a != NULL){
		printf("%s is a rotation of %s", s2, s1);
	}

	return EXIT_SUCCESS;
}
