/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env_var_list.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 12:19:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/28 13:30:00 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_var_list(t_env_var_list **list)
{
	t_env_var	*curr;
	t_env_var	*prev;

	if (list == NULL || *list == NULL)
		return ;
	curr = (*list)->head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free_env_var(&prev);
	}
	free(*list);
	*list = NULL;
}
