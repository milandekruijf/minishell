/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_tkn.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:40:17 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/28 13:36:33 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn	*create_tkn(t_token_type type, const char *value)
{
	t_tkn	*token;

	token = ms_malloc(sizeof(t_tkn));
	token->type = type;
	token->value = ft_strdup(value);
	token->next = NULL;
	return (token);
}
