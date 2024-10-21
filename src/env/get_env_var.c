/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_env_var.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 13:07:14 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 13:14:24 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_var	*get_env_var(t_env_var_list *list, const char *key)
{
	t_env_var	*var;

	var = list->head;
	while (var)
	{
		if (ft_strcmp(var->key, key) == 0)
			return (var);
		var = var->next;
	}
	return (NULL);
}
