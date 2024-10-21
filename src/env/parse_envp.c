/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_envp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:09:18 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/21 12:33:26 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_var_list	parse_envp(const char **envp)
{
	t_env_var_list	list;
	char			*delim;
	char			*key;
	char			*value;

	init_env_var_list(&list);
	while (*envp)
	{
		delim = ft_strchr(*envp, '=');
		if (delim)
		{
			key = strndup(*envp, delim - *envp);
			value = strdup(delim + 1);
			add_env_var(&list, create_env_var(key, value));
			free(key);
			free(value);
		}
		envp++;
	}
	return (list);
}
