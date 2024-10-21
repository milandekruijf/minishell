/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 12:19:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 15:09:13 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token_list **tokens)
{
	t_token	*curr;
	t_token	*prev;

	if (tokens == NULL || *tokens == NULL)
		return ;
	curr = (*tokens)->head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free_token(&prev);
	}
	free(*tokens);
	*tokens = NULL;
}
