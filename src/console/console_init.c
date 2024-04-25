
#include "minishell.h"


void	console_init(t_data *data)
{
	char	*input;
	char	*user;

	user = ft_strjoin(getenv("USER"), "$ ");
	while (data->exit != 1)
	{
		signals_call();
		input = readline(user);
		if (!input)
		{
			free(input);
			printf("exit\n");
			data->exit = 1;
			continue;
		}
		if(token_maker(data, input))
			continue;
		
		expand(data, input);
		cmd_create(data);
		// print_cmd(data->cmd_list);
		// print_token(data);
		if (*input != '\0')
			add_history(input);
		restore_lists(&data, input);
	}
	free(user);
	clear_history();
}
