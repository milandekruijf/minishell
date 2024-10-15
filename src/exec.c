/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:03:45 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 14:45:52 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_token **tokens)
{
	t_token *token;

	token = *tokens;
	if (is_builtin(token))
	{
		exec_builtin(token);
		return ;
	}
}
