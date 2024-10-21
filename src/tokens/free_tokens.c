/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 12:19:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 13:20:29 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token_list *tokens)
{
	t_token	*curr;
	t_token	*prev;

	curr = tokens->head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free_token(prev);
	}
	tokens->head = NULL;
	tokens->tail = NULL;
}
