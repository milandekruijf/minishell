/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_cmd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:32:31 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 14:22:50 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*create_empty_cmd(void)
{
	t_cmd	*cmd;

	cmd = ms_malloc(sizeof(t_cmd));
	cmd->argv = NULL;
	cmd->next = NULL;
	return (cmd);
}
