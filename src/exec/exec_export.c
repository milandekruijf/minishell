/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_export.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:28:38 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/31 14:41:17 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_export(const char **argv, t_env_var_list *list)
{
	int		i;
	char	*key;
	char	*value;

	i = 1;
	while (argv[i])
	{
		key = ft_strtok(ft_strdup(argv[i]), '=');
		value = ft_strtok(NULL, '=');
		if (value)
			set_env_var(list, key, value);
		else
			set_env_var(list, key, "");
		free(key);
		i++;
	}
}
