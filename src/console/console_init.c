
#include "minishell.h"

void	console_init(t_data *data)
{
	char	*input;
	char	*user;

	user = ft_strjoin(getenv("USER"), "$ ");
	while (!data->exit)
	{
		signals_call();
		input = readline(user);
		if (!input)
		{
			printf("exit\n");
			data->exit = 1;
			break ;
		}
		add_history(input);
		token_maker(data, input);
		expand(data, input);
		cmd_create(data);
		print_cmd(data->cmd_list);
		if (*input != '\0')
			add_history(input);
		free(input);
		// free_token(&data->token_list);
		rl_on_new_line();
	}
	free(user);
	clear_history();
}