/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_builtin.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:22:20 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 14:38:58 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_BuiltIn	get_builtin(t_token *token)
{
	if (token->type != TKN_CMD)
		return (BI_UNKNOWN);
	if (ft_strcmp(token->value, "echo"))
		return (BI_ECHO);
	if (ft_strcmp(token->value, "cd"))
		return (BI_CD);
	if (ft_strcmp(token->value, "pwd"))
		return (BI_PWD);
	if (ft_strcmp(token->value, "export"))
		return (BI_EXPORT);
	if (ft_strcmp(token->value, "unset"))
		return (BI_UNSET);
	if (ft_strcmp(token->value, "env"))
		return (BI_ENV);
	if (ft_strcmp(token->value, "exit"))
		return (BI_EXIT);
	return (BI_UNKNOWN);
}
