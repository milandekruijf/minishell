/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_export.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 15:54:01 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_export(const char **argv, t_env_var_list *env_vars)
{
	int		i;
	char	*key;
	char	*value;

	i = 1;
	while (argv[i])
	{
		key = ft_strtok(ft_strdup(argv[i]), "=");
		value = ft_strtok(NULL, "=");
		if (value)
			set_env_var(env_vars, key, value);
		else
			set_env_var(env_vars, key, "");
		free(key);
		i++;
	}
	return (1);
}
