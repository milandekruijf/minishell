/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_env_var_list.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:20:13 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/18 15:20:32 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env_var_list(t_env_var_list *list)
{
	list->head = NULL;
	list->tail = NULL;
}
