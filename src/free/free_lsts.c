
#include "minishell.h"

void	free_token(t_token **token)
{
	t_token	*lst;
	t_token	*tmp;

	if (*token == NULL)
		return ;
	tmp = NULL;
	lst = *token;
	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	*token = NULL;
}

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*lst;
	t_cmd	*tmp;

	if (*cmd == NULL)
		return ;
	tmp = NULL;
	lst = *cmd;
	while (lst)
	{
		tmp = lst->next;
		free(lst->comand);
		if (lst->fd_in > 2)
			close(lst->fd_in);
		if (lst->fd_out > 2)
			close(lst->fd_out);
		free(lst);
		lst = tmp;
	}
	*cmd = NULL;
}

void	free_envp(t_env_list **envp)
{
	t_env_list	*lst;
	t_env_list	*tmp;

	lst = *envp;
	tmp = NULL;
	while (lst)
	{
		tmp = lst->next;
		free(lst->key);
		free(lst->value);
		free(lst);
		lst = tmp;
	}
	*envp = NULL;
}

void	free_all(t_data *data)
{
	int	i; 

	i = 0;
	while (data->built_in_cmd[i])
		free(data->built_in_cmd[i++]);
	i = 0;
	while (data->envp[i])
		free(data->envp[i++]);
	free(data->envp);
	free_envp(&data->envp_list);
	if (data->token_list)
		free_token(&data->token_list);
	if (data->cmd_list)
		free_cmd(&data->cmd_list);
	free(data);
}

void	restore_lists(t_data **data, char *input)
{
	free_token(&(*data)->token_list);
	free_cmd(&(*data)->cmd_list);
	free(input);
}
