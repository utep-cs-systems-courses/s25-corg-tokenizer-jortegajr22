#include "tokenizer.h"
#include "stdlib.h"

int space_char(char c)
{
  return (c==' ') ?  1 : 0;
}

int non_space_char(char c)
{
  return  (c != ' ') ? 1 : 0;
}

char *token_start(char *str);

char *token_terminator(char *token);

int count_tokens(char *str);

char *copy_str(char *inStr, short len);

char **tokenize(char *str);

void print_tokens(char **tokens);

void free_tokens(char **tokens);
