/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ensure_cwd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:35:46 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 15:36:15 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ensure_cwd(t_env_var_list *env_vars)
{
	char	*cwd;

	cwd = get_cwd(env_vars);
	ms_assert(cwd != NULL, "Failed to get current working directory");
	return (cwd);
}
