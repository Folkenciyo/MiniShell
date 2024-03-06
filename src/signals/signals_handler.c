#include "minishell.h"

static void	handler_c(int signal)
{
	(void)signal;
	// if (g_batch_flag == 0)
	// {
		// rl_on_new_line();
		// rl_redisplay();
		// rl_replace_line("", 0);
		// write(1, "\033[K\n", 5);
		// rl_on_new_line();
		// rl_redisplay();
		// rl_replace_line("", 0);
	// }
	// else if (g_batch_flag == 1)
	// {
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
        rl_redisplay();
	// }
}

void	signals_call(void)
{
	signal(SIGINT, handler_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}