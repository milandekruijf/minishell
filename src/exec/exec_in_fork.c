/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_in_fork.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: daria <daria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/11 17:33:35 by daria         #+#    #+#                 */
/*   Updated: 2024/11/12 01:24:51 by daria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_in_fork(t_cmd *cmd, t_env_var_list *env_vars, t_piping piping)
{
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		fprintf(stderr, "executing %s pipes %d %d\n", cmd->argv[0], piping.in,
			piping.out);
		dup2(piping.in, STDIN_FILENO);
		dup2(piping.out, STDOUT_FILENO);
		close_pipes(piping.pipes, piping.count, piping.in, piping.out);
		if (is_builtin(cmd->argv[0]))
		{
			exec_builtin(cmd, env_vars);
			exit(EXIT_SUCCESS);
		}
		else
			exec_bin(cmd, env_vars);
	}
}
