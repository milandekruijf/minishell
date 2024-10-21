/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_token.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:40:17 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/21 13:28:32 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(t_token_type type, const char *value)
{
	t_token	*token;

	token = ms_malloc(sizeof(t_token));
	token->type = type;
	token->value = ft_strdup(value);
	token->next = NULL;
	return (token);
}
