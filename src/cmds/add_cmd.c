/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:18:56 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 13:23:37 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmd(t_cmd_list *list, t_cmd *cmd)
{
	if (!list->tail)
	{
		list->head = cmd;
		list->tail = cmd;
		return ;
	}
	list->tail->next = cmd;
	list->tail = cmd;
}
