/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_cmd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 18:53:57 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/28 14:28:06 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd **cmd)
{
	int	i;

	i = 0;
	while ((*cmd)->argv[i])
		free((*cmd)->argv[i++]);
	free((*cmd)->argv);
	free(*cmd);
	*cmd = NULL;
}