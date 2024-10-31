/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_cd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/31 15:24:29 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cd(const char **argv, t_env_var_list *list)
{
	char	*path;

	if (argv[1] == NULL)
		path = ensure_env_var(list, "HOME", "cd: HOME not set")->value;
	set_cwd(path, list);
}
