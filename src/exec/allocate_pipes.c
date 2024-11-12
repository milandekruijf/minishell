/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocate_pipes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: daria <daria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/12 00:37:49 by daria         #+#    #+#                 */
/*   Updated: 2024/11/12 12:22:58 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**allocate_pipes(int count)
{
	int	**pipes;
	int	i;

	pipes = ms_malloc(sizeof(int *) * (count + 1));
	i = 0;
	while (i <= count)
	{
		pipes[i] = ms_malloc(sizeof(int) * 2);
		i += 1;
	}
	pipes[0][0] = STDIN_FILENO;
	pipes[0][1] = -1;
	i = 1;
	while (i <= count)
		pipe(pipes[i++]);
	pipes[count][0] = -1;
	pipes[count][1] = STDOUT_FILENO;
	return (pipes);
}
