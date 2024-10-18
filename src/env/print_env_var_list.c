/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_env_var_list.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:22:41 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/18 16:37:04 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_var_list(const t_env_var_list *list)
{
	t_env_var	*var;

	var = list->head;
	while (var->next)
	{
		print_env_var(var);
		var = var->next;
	}
}
