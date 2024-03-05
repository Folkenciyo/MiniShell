/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_manage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:54:06 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/05 20:20:13 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list	*envp_list_new(char *key, char *value)
{
	t_env_list	*new;

	new = (t_env_list *)malloc(sizeof(t_env_list));
	if (!new)
	{
		printf("\033[0;31mError:\t\033[0;21mMalloc failed\n\033[0;m");
		exit(1);
	}
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_env_list	*envp_list_add_back(t_env_list *lst, t_env_list *new)
{
	t_env_list	*tmp;

	if (!lst)
		return (new);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (lst);
}

void	envp_list_add_front(t_env_list *lst, t_env_list *new)
{
	if (lst && new)
	{
		new->next = lst;
		lst = new;
	}
}

/* hacer una variable xq al poner env la ultima variable de entorno es una variable 
que guarda el útimo phat del comando ejecutaado, asiq hay q reemplazar el anterior x 
el nuevo ejemplo:
...
HOMEBREW_TEMP=/tmp/juguerre/Homebrew/Temp
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.86.0
LANG=en_US.UTF-8
COLORTERM=truecolor
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
VSCODE_GIT_IPC_HANDLE=/var/folders/zz/zyxvpxvq6csfxvn_n000ckfw0034lq/T/vscode-git-bb7ae329ff.sock
VSCODE_INJECTION=1
ZDOTDIR=/Users/juguerre
USER_ZDOTDIR=/Users/juguerre
TERM=xterm-256color
_=/usr/bin/env <-------------------------ESTO ES LO QUE HAY QUE CAMBIAR
		   ...
. PUTA

 */

