#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

  char snu[] = "todos iguales";

  int i;
  for(i=0; i<sizeof(snu)-1;i++){

    if(NULL == strchr(&(snu[i+1]), snu[i])){
    	continue;
    }else{
      printf("%s%c\n", "not unique: ", snu[i]);
      break;
    }

  }

  if(i == (sizeof(snu) - 1)){
    printf("%s\n", "unique");

  }

	return 0;

}
