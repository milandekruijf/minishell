/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_it.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:43:36 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 16:21:18 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_it(t_env_var_list *env_vars)
{
	char	*c;

	while (true)
	{
		c = readline(MS_PROMPT);
		if (!c)
			break ;
		if (*c)
			add_history(c);
		run_c(c, env_vars);
	}
}
