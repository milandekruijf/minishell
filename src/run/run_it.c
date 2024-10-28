/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_it.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:43:36 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 16:02:36 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_it(t_env_var_list *env_vars)
{
	char	*line;

	while (true)
	{
		line = readline(MS_PROMPT);
		if (!line)
			break ;
		if (*line)
			add_history(line);
		run_line(line, env_vars);
	}
}
