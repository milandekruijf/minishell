/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset_env_var.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:33:04 by anonymous     #+#    #+#                 */
/*   Updated: 2024/10/31 14:38:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env_var(t_env_var_list *list, const char *key)
{
	t_env_var	*curr;
	t_env_var	*prev;

	if (list == NULL || list->head == NULL)
		return ;
	curr = list->head;
	prev = NULL;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				list->head = curr->next;
			if (curr == list->tail)
				list->tail = prev;
			free(curr->key);
			free(curr->value);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
