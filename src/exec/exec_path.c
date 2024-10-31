/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_rel.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:55:49 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 15:05:47 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_path(t_cmd *cmd, t_env_var_list *env_vars)
{
	char	*path;
	char	*full_path;
	int		err;

	path = get_env_var(env_vars, "PATH")->value;
	path = ft_strtok(ft_strdup(path), ':');
	err = -1;
	while (path)
	{
		full_path = ft_strdup(path);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, cmd->argv[0]);
		err = execve(full_path, cmd->argv, env_var_list_to_envp(env_vars));
		if (err != -1)
			return (err);
		path = ft_strtok(NULL, ':');
	}
	return (err);
}
