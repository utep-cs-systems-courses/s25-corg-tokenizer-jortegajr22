#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char input[100];
  puts("Hello,there!\n");

  printf("Please enter a string, type 'history', 'history #', or exit: \n");
  fgets(input, sizeof(input), stdin);

  printf("You entered: %s \n", input);
  
  char **tokens = tokenize(input);
  print_tokens(tokens);
  //  free_tokens(tokens);
  
  return 0;
}
