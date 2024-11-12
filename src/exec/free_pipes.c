/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_pipes.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: daria <daria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/12 00:40:28 by daria         #+#    #+#                 */
/*   Updated: 2024/11/12 12:24:32 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipes(int ***pipes, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free((*pipes)[i]);
		i += 1;
	}
	free(*pipes);
	*pipes = NULL;
}
