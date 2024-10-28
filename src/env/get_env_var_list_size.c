/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_env_var_list_size.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 18:53:57 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 12:25:06 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_env_var_list_size(t_env_var_list *list)
{
	t_env_var	*var;
	size_t		size;

	size = 0;
	var = list->head;
	while (var)
	{
		size++;
		var = var->next;
	}
	return (size);
}
