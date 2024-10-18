/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_builtin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:06:56 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/18 14:02:25 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_token *token)
{
	enum e_BuiltIn	builtin;

	assert_is_builtin(token);
	builtin = get_builtin(token);
	if (builtin == BI_ECHO)
		exec_echo(token);
	else if (builtin == BI_CD)
		exec_cd(token);
	else if (builtin == BI_PWD)
		exec_pwd(token);
	else if (builtin == BI_EXPORT)
		exec_export(token);
	else if (builtin == BI_UNSET)
		exec_unset(token);
	else if (builtin == BI_ENV)
		exec_env(token);
	else if (builtin == BI_EXIT)
		exec_exit(token);
}
