/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_echo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:27:22 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_echo(const char **argv, t_env_var_list *env_vars)
{
	printf("%s\n", join_argv(argv));
}
