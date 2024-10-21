/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_env_var.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:18:56 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/21 12:37:37 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env_var(t_env_var_list *list, t_env_var *var)
{
	if (!list->tail)
	{
		list->head = var;
		list->tail = var;
		return ;
	}
	list->tail->next = var;
	list->tail = var;
}
