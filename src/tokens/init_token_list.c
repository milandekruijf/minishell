/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_token_list.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:13:24 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 13:29:48 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_token_list(t_token_list *tokens)
{
	tokens->head = NULL;
	tokens->tail = NULL;
}
