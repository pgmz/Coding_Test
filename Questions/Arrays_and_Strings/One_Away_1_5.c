#include <stdio.h>

int main (void){

  char s1[] = "pale";
  char s2[] = "bake";

  int err = 0;
  int index = 0;
  int index_s1 = 0;

  for(index= 0; index < sizeof(s2)-1; index++){

    if(s1[index_s1] == s2[index]){
    } else if(s1[index_s1 + 1] == s2[index]){
      err++;
      index_s1++;
    } else {
      err++;
    }

    index_s1++;


  }

  printf("%d \n", err);
  return 0;

}
