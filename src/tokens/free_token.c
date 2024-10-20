/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_token.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 18:53:57 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/20 18:54:03 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token(t_token *token)
{
	free(token->value);
	free(token);
}
