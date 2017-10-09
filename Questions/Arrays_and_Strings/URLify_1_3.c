#include <stdio.h>
#include <string.h>

int main (void){

  char s1[] = "Mr John Smith    ";
  int length = 13;
  char s2[] = "Mr John Smith    ";

  int index = 0;
  int move = 0;

  //METHOD 1
  for(index= 0; index < length; index++){

	  if(s1[index] != ' '){
		  s2[move + index] = s1[index];
	  } else {
		  strcpy(&s2[move + index], "%20");
		  move = move + 2;
	  }

  }

  //METHOD 2
  for(index= 0; index < length; index++){

	  if(s1[index] != ' '){
		  s2[move + index] = s1[index];
	  } else {
		  strcpy(&s2[move + index], "%20");
		  move = move + 2;
	  }

  }

  printf("%s \n", s2);
  return 0;

}
