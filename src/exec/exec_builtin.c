/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_builtin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: daria <daria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/11 17:39:15 by daria         #+#    #+#                 */
/*   Updated: 2024/11/11 17:39:45 by daria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_cmd *cmd, t_env_var_list *env_vars)
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
	ms_assert(false, "cmd %s is not a builtin passed to exec_builtin",
		cmd->argv[0]);
}
