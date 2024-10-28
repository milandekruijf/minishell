/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_token.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:19:08 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/28 13:35:19 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_tkn(t_tkn_list *tokens, t_tkn *tkn)
{
	if (!tokens->tail)
	{
		tokens->head = tkn;
		tokens->tail = tkn;
		return ;
	}
	tokens->tail->next = tkn;
	tokens->tail = tkn;
}
