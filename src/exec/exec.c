/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:03:45 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 12:07:17 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_token_list *tokens, t_env_var_list *env_vars)
{
	t_token	*token;

	(void)(env_vars);
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
