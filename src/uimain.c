#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "uimain.h"
#include "history.h"

int main()
{
  char input[100];
  int count = 0;
  List *history = init_history();
  printf("Hello, there!\n");

  //inf loop till "exit"
  while (1){
    printf("Please enter a string, type history, or history #, or exit: \n");
    fgets(input, sizeof(input), stdin);

    add_history(history, input);
    count++;
    rem_newline(input);
    
    //check exit condition
    if (comp_str(input, "exit")){
      break;
    }
    if (comp_str(input, "history")){
      print_history(history);
      continue;
    }
    if (input[0] == '!'){

	if (!(input[1] == ' ')){
	  int id = get_id(&input[1]);

	  if (id >= 0){
	    char *item = get_history(history, id);

	    if (item){
	      printf("%d %s\n", id, item);
	    } else{ printf("No history entry found for ID %d.\n", id); }

	  } else{  printf("Invalid Id format.\n"); }
	} else{ printf("Invalid format. Use '!#'"); }
	continue;
      }
      
    char **tokens = tokenize(input);
    print_tokens(tokens);
    free_tokens(tokens);

  }
  free_history(history);
  return 0;
}

void rem_newline(char *str){
  for (int i = 0; str[i] != '\0'; i++){
    if (str[i] == '\n'){
      str[i] = '\0';
      break;
    }
  }
}

int comp_str(const char *str1, const char *str2){
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *str1 == *str2;
}
int get_id(const char *str){
  int id = 0;
  while (*str){
    if (*str < '0' || *str > '9'){

      return -1;
    }//convert str to int
    id = id*10 + (*str -'0');
    str++;
  }
  return id;
}
