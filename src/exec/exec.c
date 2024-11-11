/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:03:45 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/11 23:33:47 by daria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_cmd_list *cmds, t_env_var_list *env_vars)
{
	t_cmd	*cmd;

	cmd = cmds->head;
	if (cmd->next == NULL)
	{
		if (is_builtin(cmd->argv[0]))
			exec_builtin(cmd, env_vars);
		else
			exec_in_fork(cmd, env_vars);
	}
	else
	{
		while (cmd)
		{
			exec_in_fork(cmd, env_vars);
			cmd = cmd->next;
		}
	}
}
