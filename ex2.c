
#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

main()
{
  char Strings[NUM][LEN];
  char tempString[LEN];

  printf("Please enter %d strings, one per line:\n", NUM);

  int i, j, k, l;
  int inner, outer;
  for(i = 0; i < NUM; i++){
    fgets(Strings[i], LEN-2, stdin);  // must fix this line
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
        int originalLengthOuter = strlen(Strings[outer]);
        int originalLengthInner = strlen(Strings[inner]);

        strcpy(tempString, Strings[outer]);
        strcpy(Strings[outer], Strings[inner]);
        strcpy(Strings[inner], tempString);

        Strings[outer][originalLengthInner] = '\0';
        Strings[inner][originalLengthOuter] = '\0';

        swapped = 1;
      }

      // if(swapped = 0){
      //   break;
      // }
    }
  }

  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  
  for(i = 0; i < NUM; i++){
    printf("%s", Strings[i]);
  }

  return 0;
}