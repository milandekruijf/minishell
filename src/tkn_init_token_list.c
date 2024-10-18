/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tkn_init_token_list.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:13:24 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/18 12:36:50 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tkn_init_token_list(t_token_list *tokens)
{
	tokens->head = NULL;
	tokens->tail = NULL;
}
