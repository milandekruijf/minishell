/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_var_list_to_envp.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 18:53:57 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 12:27:28 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_var_list_to_envp(t_env_var_list *list)
{
	t_env_var	*var;
	char		**envp;

	envp = ms_malloc(sizeof(char **) * get_env_var_list_size(list));
	var = list->head;
	while (var)
	{
		var = var->next;
	}
}
