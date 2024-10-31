/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_abs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:55:49 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 14:55:53 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_abs(t_cmd *cmd, t_env_var_list *env_vars)
{
	return (execve(cmd->argv[0], cmd->argv, env_var_list_to_envp(env_vars)));
}
