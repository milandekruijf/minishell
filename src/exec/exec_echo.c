/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_echo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 15:54:18 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_echo(const char **argv, t_env_var_list *env_vars)
{
	char	*joined;
	int		no_newline;
	char	*expanded;

	joined = join_argv(argv);
	no_newline = (ft_strstr(joined, "-n ") == joined);
	if (no_newline)
		joined += 3;
	expanded = expand_vars(joined, env_vars);
	if (no_newline)
		printf("%s", expanded);
	else
		printf("%s\n", expanded);
	return (1);
}
