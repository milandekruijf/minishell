/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_bin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:29:03 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/31 14:18:17 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_bin(t_cmd *cmd, t_env_var_list *env_vars)
{
	pid_t	pid;
	int		err;
	char	*path;
	char	*full_path;

	pid = fork();
	if (pid == 0)
	{
		path = get_env_var(env_vars, "PATH")->value;
		path = ft_strtok(ft_strdup(path), ':');
		while (path)
		{
			full_path = ft_strdup(path);
			ft_strcat(full_path, "/");
			ft_strcat(full_path, cmd->argv[0]);
			err = execve(full_path, cmd->argv, env_var_list_to_envp(env_vars));
			if (err != -1)
				exit(EXIT_SUCCESS);
			path = ft_strtok(NULL, ':');
		}
		printf("minishell: %s: command not found\n", cmd->argv[0]);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}
