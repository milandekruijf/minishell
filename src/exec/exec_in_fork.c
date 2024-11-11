/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_in_fork.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: daria <daria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/11 17:33:35 by daria         #+#    #+#                 */
/*   Updated: 2024/11/11 23:31:22 by daria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_in_fork(t_cmd *cmd, t_env_var_list *env_vars)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (is_builtin(cmd->argv[0]))
			exec_builtin(cmd, env_vars);
		else
			exec_bin(cmd, env_vars);
	}
	else
		waitpid(pid, NULL, 0);
}
