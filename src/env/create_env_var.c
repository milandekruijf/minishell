/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_env_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:32:31 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/21 11:17:05 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_var	*create_env_var(const char *key, const char *value)
{
	t_env_var	*var;

	var = ms_malloc(sizeof(t_env_var));
	var->key = ft_strdup(key);
	var->value = ft_strdup(value);
	var->next = NULL;
	return (var);
}
