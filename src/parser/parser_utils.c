#include "minishell.h"

int special_chars(char c)
{
    if (c == '\"' || c == '\'' || c == '>' 
    || c == '<' || c == ' ' || c == '|')
        return (1);
    return (0);
}

int is_space(char c)
{
    if (c == '\f' || c == '\n' || c == '\r' \
	    || c == '\t' || c == '\v' || c == ' ')
        return (1);
    return (0);
}