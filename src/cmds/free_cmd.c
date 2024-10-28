/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_cmd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 18:53:57 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 13:27:02 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd **cmd)
{
	free((*cmd)->argv);
	free(*cmd);
	*cmd = NULL;
}
