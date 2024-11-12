/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_pipes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: daria <daria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/12 00:12:32 by daria         #+#    #+#                 */
/*   Updated: 2024/11/12 01:32:40 by daria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(int **pipes, int count, int in_to_keep, int out_to_keep)
{
	int	i;

	i = 1;
	fprintf(stderr, "closing all pipes except %d %d\n", in_to_keep,
		out_to_keep);
	while (i < count)
	{
		if (pipes[i][0] != in_to_keep && pipes[i][0] != -1)
		{
			fprintf(stderr, "closing in fd %d\n", pipes[i][0]);
			close(pipes[i][0]);
		}
		if (pipes[i][1] != out_to_keep && pipes[i][1] != -1)
		{
			fprintf(stderr, "closing out fd %d\n", pipes[i][1]);
			close(pipes[i][1]);
		}
		i += 1;
	}
}
