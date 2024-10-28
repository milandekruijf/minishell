/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_cmd_list.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 12:19:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/28 14:34:40 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd_list(t_cmd_list **list)
{
	t_cmd	*curr;
	t_cmd	*prev;

	if (list == NULL || *list == NULL)
		return ;
	curr = (*list)->head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free_cmd(&prev);
	}
	free(*list);
	*list = NULL;
}
