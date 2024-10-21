/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 12:19:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 12:24:05 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token_list *token_list)
{
	t_token	*current;
	t_token	*previous;

	current = token_list->head;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
		free(previous->value);
		free(previous);
	}
	token_list->head = NULL;
	token_list->tail = NULL;
}
