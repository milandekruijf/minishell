/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_cmd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:32:31 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 13:23:05 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*create_cmd(const char **argv)
{
	t_cmd	*cmd;

	cmd = ms_malloc(sizeof(t_cmd));
	cmd->argv = argv;
	cmd->next = NULL;
	return (cmd);
}
