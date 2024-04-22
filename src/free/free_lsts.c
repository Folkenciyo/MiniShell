
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

void free_cmd(t_cmd **cmd)
{
	t_cmd *lst;

	if (*cmd == NULL)
		return ;

	lst = *cmd;
	while (lst)
	{

		free(lst->comand);
		if(lst->fd_in > 2)
			close(lst->fd_in);
		if(lst->fd_out > 2)
			close(lst->fd_out);
		free(lst);
		lst = lst->next;
	}
	*cmd = NULL;
}

void free_envp(t_env_list **envp)
{
	t_env_list *lst;

	if (*envp == NULL)
		return ;

	lst = *envp;
	while (lst)
	{
		free(lst->key);
		free(lst->value);
		free(lst);
		lst = lst->next;
	}
	*envp = NULL;
}

void free_all(t_data *data)
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

void	restore_lists(t_data **data,char *input)
{
	free_token(&(*data)->token_list);
	free_cmd(&(*data)->cmd_list);
	free(input);
}