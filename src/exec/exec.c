/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:03:45 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:45:48 by dkolodze      ########   odam.nl         */
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
		else if (ft_strcmp(cmd->argv[0], "env") == 0)
			exec_env(env_vars);
		else if (ft_strcmp(cmd->argv[0], "unset") == 0)
			exec_unset((const char **)cmd->argv, env_vars);
		else if (ft_strcmp(cmd->argv[0], "export") == 0)
			exec_export((const char **)cmd->argv, env_vars);
		else if (ft_strcmp(cmd->argv[0], "cd") == 0)
			exec_cd((const char **)cmd->argv, env_vars);
		else if (ft_strcmp(cmd->argv[0], "echo") == 0)
			exec_echo((const char **)cmd->argv, env_vars);
		else
			exec_bin(cmd, env_vars);
		cmd = cmd->next;
	}
}
