/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tkn.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 13:32:54 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 13:32:45 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tkn(t_tkn *tkn)
{
	char	*type_name;

	type_name = get_token_type_name(tkn->type);
	printf("Token { Type: %s, Value: %s }\n", type_name, tkn->value);
}
