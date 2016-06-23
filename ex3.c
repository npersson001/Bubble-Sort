
#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for string functions */
#include <stdlib.h>


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

main()
{
  char* Strings[NUM];
  char temp[LEN]; 
  char* tempSwap;
  int outer, inner, i, j;

  printf("Please enter %d strings, one per line:\n", NUM);

  for (i=0; i < NUM; i++){

    fgets(temp, LEN, stdin);

    int length = strlen(temp);

    Strings[i] = malloc(length+1); /* Plus one for the NULL at end */

    for(j=0; j < length; j++){
      Strings[i][j] = temp[j];
    }
  }

  puts("\nHere are the strings in the order you entered:");

  for(i = 0; i < NUM; i++){
    printf("%s", Strings[i]);
  }

  for(outer = 0; outer < NUM-1; outer++){
    for(inner = outer; inner < NUM; inner++){
      int swapped = 0;

      int compare = strcmp(Strings[inner], Strings[outer]);

      if(compare < 0){

        tempSwap = Strings[outer];
        Strings[outer] = Strings[inner];
        Strings[inner] = tempSwap;

        swapped = 1;
      }

      // if(swapped = 0){
      //   break;
      // }
    }
  }
  
  puts("\nIn alphabetical order, the strings are:");     

  for(i = 0; i < NUM; i++){
    printf("%s", Strings[i]);
  }

  for(i = 0; i < NUM; i++){
    free(Strings[i]);
  }

  return 0;
}