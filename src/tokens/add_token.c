/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_token.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:19:08 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 13:21:53 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_token_list *tokens, t_token *token)
{
	if (!tokens->tail)
	{
		tokens->head = token;
		tokens->tail = token;
		return ;
	}
	tokens->tail->next = token;
	tokens->tail = token;
}
