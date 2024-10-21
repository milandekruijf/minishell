/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_env_var_list.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:22:41 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/21 12:38:13 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_var_list(const t_env_var_list *list)
{
	t_env_var	*var;

	var = list->head;
	while (var)
	{
		print_env_var(var);
		var = var->next;
	}
}
