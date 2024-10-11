/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_last_token.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 15:06:11 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/11 15:07:14 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_last_token(t_token *tokens)
{
	while (tokens)
	{
		if (!tokens->next)
			return (tokens);
		tokens = tokens->next;
	}
	return (tokens);
}
