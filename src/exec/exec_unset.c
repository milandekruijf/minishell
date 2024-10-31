/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_unset.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/31 14:40:13 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_unset(const char **argv, t_env_var_list *env_vars)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		unset_env_var(env_vars, argv[i]);
		i++;
	}
}
