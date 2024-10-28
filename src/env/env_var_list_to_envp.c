/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_var_list_to_envp.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 18:53:57 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 13:11:12 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_var_list_to_envp(t_env_var_list *list)
{
	t_env_var	*var;
	char		**envp;
	size_t		i;
	size_t		key_len;
	size_t		value_len;

	envp = ms_malloc((get_env_var_list_size(list) + 1) * sizeof(char *));
	var = list->head;
	i = 0;
	while (var)
	{
		key_len = ft_strlen(var->key);
		value_len = ft_strlen(var->value);
		envp[i] = ms_malloc(key_len + value_len + 2);
		ft_strcpy(envp[i], var->key);
		ft_strcat(envp[i], "=");
		ft_strcat(envp[i], var->value);
		var = var->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
