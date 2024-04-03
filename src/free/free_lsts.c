
#include "minishell.h"

void	free_token(t_token **token)
{
	t_token *lst;

	if (*token == NULL)
		return ;

	lst = *token;
	while (lst)
	{
		free(lst->content);
		free(lst);
		lst = lst->next;
	}
	*token = NULL;
}
