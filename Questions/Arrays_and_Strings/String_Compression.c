#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

int main(void) {

	char s[] = "aaa";
	char s1[sizeof(s)];
	int sum = 1;
	int counter = 1;
	int index = 0;

	printf("%s \n", s);


	for(index = 0; index < sizeof(s)-1; index++){

		if(s[index] == s[index+1]){
			sum++;
		}else{
			s1[counter - 1] = s[index];
			s1[counter] = (sum + '0');
			counter = counter + 2;
			sum=1;

		}

	}
	s1[counter-1] = '\0';

	if(strlen(s1) >= strlen(s)){
		printf("Compression not useful :( \n");
	} else {
		printf("Compression useful :D \n");
	}

	printf("%s \n%s", s, s1);

	return EXIT_SUCCESS;
}
