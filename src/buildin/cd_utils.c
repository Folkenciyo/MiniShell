/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/04/12 17:39:55 by juguerre          #+#    #+#             */
/*   Updated: 2024/04/12 17:39:55 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_upd_pwds(t_data *data, char *c_dir, char *new_dir)
{
	char	*path;

	path = ft_strjoin("OLDPWD=", c_dir);
	ft_export(data, path);
	free(path);
	path = ft_strjoin("PWD=", new_dir);
	ft_export(data, path);
	free(path);
	return ;
}

int	ft_cd_home(t_data *data)
{
	char	*new_dir;
	char	*current_dir;
	int		status;
	char	cwd[PATH_SIZE];

	new_dir = ft_get_env_value(data, "HOME");
	if (!new_dir)
	{
		ft_putendl_fd("cd: HOME not set", 2);
		return (EXIT_FAILURE);
	}
	current_dir = ft_get_env_value(data, "PWD");
	status = chdir(new_dir);
	if (status == -1)
	{
		free(current_dir);
		free(new_dir);
		return (EXIT_FAILURE);
	}
	free(new_dir);
	new_dir = ft_strdup(getcwd(cwd, PATH_SIZE));
	ft_upd_pwds(data, current_dir, new_dir);
	ft_free_dirs(current_dir, new_dir, NULL);
	return (EXIT_SUCCESS);
}

int	ft_cd_lastdir(t_data *data)
{
	char	*new_dir;
	char	*current_dir;
	char	cwd[PATH_SIZE];

	current_dir = ft_strdup(getcwd(cwd, PATH_SIZE));
	new_dir = ft_get_env_value(data, "OLDPWD");
	if (!new_dir)
	{
		free(current_dir);
		ft_putendl_fd("OLDPWD not set", 2);
		return (EXIT_FAILURE);
	}
	if (chdir(new_dir) == -1)
		return (ft_free_dirs(current_dir, new_dir, NULL), EXIT_FAILURE);
	free(new_dir);
	if (getcwd(cwd, PATH_SIZE))
	{
		new_dir = ft_strdup(getcwd(cwd, PATH_SIZE));
		ft_upd_pwds(data, current_dir, new_dir);
		printf("%s\n", new_dir);
	}
	else
		perror("cd: ");
	ft_free_dirs(current_dir, new_dir, NULL);
	return (EXIT_SUCCESS);
}

int	ft_cd_home_relat(t_data *data, char *string)
{
	char	*new_dir;
	char	*current_dir;
	char	*tmp;
	char	cwd[PATH_SIZE];
	char	*home_dir;

	home_dir = ft_get_env_value(data, "HOME");
	if (!home_dir)
		return (ft_print_error("home_relat:"));
	current_dir = ft_get_env_value(data, "PWD");
	tmp = ft_strtrim(string, "~");
	new_dir = ft_strjoin(home_dir, tmp);
	if (chdir(new_dir) == -1)
	{
		ft_free_dirs(current_dir, home_dir, new_dir);
		free(tmp);
		return (EXIT_FAILURE);
	}
	free(new_dir);
	new_dir = ft_strdup(getcwd(cwd, PATH_SIZE));
	ft_upd_pwds(data, current_dir, new_dir);
	ft_free_dirs(current_dir, new_dir, NULL);
	ft_free_dirs(tmp, home_dir, NULL);
	return (EXIT_SUCCESS);
}

int	ft_cd_other(t_data *data, char *string)
{
	char	*current_dir;	
	char	*new_dir;	
	char	cwd[PATH_SIZE];	
	int		status;

	current_dir = ft_get_env_value(data, "PWD");
	status = chdir(string);
	new_dir = NULL;
	if (status == -1)
	{
		free(current_dir);
		return (EXIT_FAILURE);
	}
	if (getcwd(cwd, PATH_SIZE))
	{
		new_dir = ft_strdup(getcwd(cwd, PATH_SIZE));
		ft_upd_pwds(data, current_dir, new_dir);
	}
	else
		perror("cd: ");
	ft_free_dirs(new_dir, current_dir, NULL);
	return (EXIT_SUCCESS);
}
