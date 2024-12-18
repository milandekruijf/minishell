/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_cd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 15:54:28 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_cd(const char **argv, t_env_var_list *env_vars)
{
	char	*path;

	if (argv[1] == NULL)
		path = ensure_env_var(env_vars, "HOME", "cd: HOME not set")->value;
	else
		path = (char *)argv[1];
	set_cwd(path, env_vars);
	return (1);
}
