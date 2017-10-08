#include <stdlib.h>
#include <stdio.h>

int main(void){

  char s[] = "abbc";

  char b[] = "babcabbacaabcbabcacbb";

  unsigned int index;
  unsigned int count = 0;
  unsigned int perm = 0;

  for(index = 0; index < sizeof(s); index++){
    count = count + (s[index]);

  }

  for(index = 3; index < sizeof(b); index++){
    if((b[index - 3] + b[index - 2] + b[index - 1] + b[index]) == count){
      perm++;
    }
  }

  printf("%d\n", perm);

}
