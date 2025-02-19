#include "tokenizer.h"
#include "stdlib.h"


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
  return (*str == '\0') ? NULL : str;
}

char *token_terminator(char *token)
{
  while (non_space_char(*token)){
    token++;
  }
  return token
}

int count_tokens(char *str)
{
  int count = 0;
    char *token = token_start(str);
  while (non_space_char(*token)){
    count++;
    token = token_start(token_terminator(token));
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *copy_str = (char *)malloc((len +1) *sizeof(char));

  for(short i = 0; i < len; i++){
    copy_str[1]
}

char **tokenize(char *str);

void print_tokens(char **tokens);

void free_tokens(char **tokens);
