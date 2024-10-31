/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_env_var.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:41:29 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 14:43:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env_var(t_env_var_list *list, const char *key, const char *value)
{
	t_env_var	*var;

	var = get_env_var(list, key);
	if (var)
	{
		free(var->value);
		var->value = ft_strdup(value);
	}
	else
		add_env_var(list, create_env_var(key, value));
}
