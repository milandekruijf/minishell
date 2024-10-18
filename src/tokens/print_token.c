/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_token.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 13:32:54 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/18 13:58:31 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	char	*type_name;

	type_name = get_token_type_name(token->type);
	printf("Token { Type: %s, Value: %s }\n", type_name, token->value);
}
