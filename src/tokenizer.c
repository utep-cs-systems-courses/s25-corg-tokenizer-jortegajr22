#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>


int space_char(char c)
{
  return (c == ' ' || c == '\t');
}

int non_space_char(char c)
{
  return  !space_char(c) && c != '\0';
}

char *token_start(char *str)
{
  while (*str != '\0' && space_char(*str)){
    str++;
  }
  return (*str != '\0') ? str : NULL;
}

char *token_terminator(char *token)
{
  while (non_space_char(*token)){
    token++;
  }
  return token;
}

int count_tokens(char *str)
{
  int count = 0;
  char *token = token_start(str);
  while (token != NULL){
    count++;
    token = token_start(token_terminator(token));
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *copy_str = (char *)malloc((len +1) * sizeof(char));

  for(short i = 0; i < len; i++){
    copy_str[1] = inStr[i];
  }
  copy_str[len] = '\0';
  return copy_str;
  
}

char **tokenize(char *str)
{
  int count = count_tokens(str);
  char **tokens = (char **)malloc((count+1) * sizeof(char *));
  if (!tokens) return NULL;
  int t_index = 0;
  char *token = token_start(str);

  while (token != NULL){
    char *end_token = token_terminator(token);
    int len = end_token - token;
    tokens[t_index] = copy_str(token, len);

    if (tokens[t_index] == NULL){
      printf("copy fail");
      return NULL;
    }
    t_index++;
    token = token_start(end_token);
  }
  tokens[t_index] = NULL;
  return tokens;

}

void print_tokens(char **tokens)
{
  int i=0;
  while (tokens[i] != NULL){
    printf("tokens[%d] = '%s' length of '%d' \n", i, tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while (tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
