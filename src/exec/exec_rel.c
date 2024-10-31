/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_rel.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:55:49 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 15:29:30 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_rel(t_cmd *cmd, t_env_var_list *env_vars)
{
	char	*path;

	path = get_cwd(env_vars);
	ft_strcat(path, "/");
	ft_strcat(path, cmd->argv[0]);
	return (execve(path, cmd->argv, env_var_list_to_envp(env_vars)));
}