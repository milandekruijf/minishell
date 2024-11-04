/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_bin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:29:03 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:45:48 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_bin(t_cmd *cmd, t_env_var_list *env_vars)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (exec_abs(cmd, env_vars) != -1)
			exit(EXIT_SUCCESS);
		if (exec_path(cmd, env_vars) != -1)
			exit(EXIT_SUCCESS);
		printf("minishell: %s: command not found\n", cmd->argv[0]);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}
