#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_intArray[26] = {0};

int main(void){

	char s[] = "ttaco ttaco";

	int counter = 0;
	int i = 0;
	char curr;

	for(i = 0; i < sizeof(s); i++){

		if(s[i] >= 'A' && s[i] <= 'Z'){
			curr = s[i] + 32;
		}else if(s[i] < 'a' || s[i] > 'z'){
			continue;
		}else{
			curr = s[i];
		}

		if(my_intArray[curr - 'a'] == 0){
			my_intArray[curr - 'a']++;
			counter++;
		} else{
			my_intArray[curr - 'a']--;
			counter--;
		}

	}

	if(counter == (sizeof(s)%2)){
		printf("%s\n", "true");
	} else {
		printf("%s\n", "false");
	}

	return 0;

}
