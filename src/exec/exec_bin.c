/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_bin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:29:03 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 16:02:43 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_bin(t_cmd *cmd, t_env_var_list *env_vars)
{
	g_sig.status = exec_abs(cmd, env_vars);
	if (g_sig.status != -1)
		exit(g_sig.status);
	g_sig.status = exec_path(cmd, env_vars);
	if (g_sig.status != -1)
		exit(g_sig.status);
	exit_err(MS_EXIT_CMD_NOT_FOUND, "%s: command not found\n", cmd->argv[0]);
}
