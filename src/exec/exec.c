/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:03:45 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 16:20:57 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_cmd_list *cmds, t_env_var_list *env_vars)
{
	t_cmd	*cmd;

	cmd = cmds->head;
	while (cmd)
	{
		if (ft_strcmp(cmd->argv[0], "exit") == 0)
			exec_exit();
		else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
			exec_pwd();
		else
			exec_bin(cmd, env_vars);
		cmd = cmd->next;
	}
}
