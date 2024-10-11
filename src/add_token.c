/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_token.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 15:05:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/11 15:09:29 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_token **tokens, t_token *token)
{
	t_token	*last;

	if (!tokens)
		return ;
	if (*tokens)
	{
		last = get_last_token(*tokens);
		last->next = token;
		return ;
	}
	*tokens = token;
}
