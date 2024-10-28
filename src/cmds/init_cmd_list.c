/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cmd_list.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:20:13 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 13:19:35 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd_list(t_cmd_list *list)
{
	list->head = NULL;
	list->tail = NULL;
}
