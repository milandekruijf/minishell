/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cwd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:08:57 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 15:10:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cwd(t_env_var_list *env_vars)
{
	char		*cwd;
	t_env_var	*var;

	var = get_env_var(env_vars, "PWD");
	if (var)
		return (var->value);
	cwd = getcwd(NULL, 0);
	if (cwd)
		return (cwd);
	return (NULL);
}
