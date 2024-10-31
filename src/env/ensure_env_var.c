/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ensure_env_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:18:44 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 15:21:17 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_var	*ensure_env_var(t_env_var_list *env_vars, const char *key,
		const char *message)
{
	t_env_var	*var;

	var = get_env_var(env_vars, key);
	ms_assert(var != NULL, message);
	return (var);
}
