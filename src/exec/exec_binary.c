/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_binary.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:29:03 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 13:38:02 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_binary(t_cmd *cmd, t_env_var_list *env_vars)
{
	pid_t	pid;
	int		err;

	pid = fork();
	if (pid > 0)
	{
		err = execve(cmd->argv[0], cmd->argv, env_var_list_to_envp(env_vars));
		if (err)
		{
			printf("error launching %s\n", cmd->argv[0]);
			exit(EXIT_FAILURE);
		}
	}
}
