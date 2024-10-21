/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 13:32:54 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/21 12:35:22 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token_list *tokens)
{
	t_token	*token;

	token = tokens->head;
	while (token)
	{
		print_token(token);
		token = token->next;
	}
}
