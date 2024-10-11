/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_builtin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 14:48:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/11 15:10:06 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(t_token *token)
{
	if (token->type != TKN_CMD)
		return (false);
	if (ft_strcmp(token->type, "echo"))
		return (true);
	if (ft_strcmp(token->type, "cd"))
		return (true);
	if (ft_strcmp(token->type, "pwd"))
		return (true);
	if (ft_strcmp(token->type, "export"))
		return (true);
	if (ft_strcmp(token->type, "unset"))
		return (true);
	if (ft_strcmp(token->type, "env"))
		return (true);
	if (ft_strcmp(token->type, "exit"))
		return (true);
	return (false);
}
