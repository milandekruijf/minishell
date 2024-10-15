/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_token.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 11:15:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 13:55:25 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(enum e_TokenType type, char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(*token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}
