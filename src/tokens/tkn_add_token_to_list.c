/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tkn_add_token_to_list.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:19:08 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/18 12:37:10 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tkn_add_token_to_list(t_token_list *token_list, t_token *token)
{
	if (token_list->tail == NULL)
	{
		token_list->head = token;
		token_list->tail = token;
		return ;
	}
	token_list->tail->next = token;
	token_list->tail = token;
}
