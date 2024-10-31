/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_env_var_list.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:22:41 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/31 14:28:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_var_list(const t_env_var_list *list, bool pretty)
{
	t_env_var	*var;

	var = list->head;
	while (var)
	{
		print_env_var(var, pretty);
		var = var->next;
	}
}
