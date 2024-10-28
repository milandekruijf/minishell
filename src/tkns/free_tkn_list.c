/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_tkn_list.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 12:19:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/28 14:31:41 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tkn_list(t_tkn_list **list)
{
	t_tkn	*curr;
	t_tkn	*prev;

	if (list == NULL || *list == NULL)
		return ;
	curr = (*list)->head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free_tkn(&prev);
	}
	free(*list);
	*list = NULL;
}
