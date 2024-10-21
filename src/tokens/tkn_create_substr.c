/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tkn_create_substr.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:40:32 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 12:11:23 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tkn_create_substr(t_token_type type, char *s, ssize_t length)
{
	t_token	*token;

	token = ms_malloc(sizeof(t_token));
	token->type = type;
	token->value = ft_strndup(s, length);
	token->next = NULL;
	return (token);
}
