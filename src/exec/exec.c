/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:03:45 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/18 13:51:55 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_token_list *tokens)
{
	t_token	*token;

	token = tokens->head;
	while (token->next)
	{
		if (is_builtin(token))
		{
			exec_builtin(token);
			token = token->next;
			continue ;
		}
		exec_external(token);
		token = token->next;
	}
}
