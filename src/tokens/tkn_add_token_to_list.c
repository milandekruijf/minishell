/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tkn_add_token_to_list.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:19:08 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 13:20:04 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tkn_add_token_to_list(t_token_list *tokens, t_token *token)
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
