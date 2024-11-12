/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_pipes.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: daria <daria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/12 00:40:28 by daria         #+#    #+#                 */
/*   Updated: 2024/11/12 01:15:52 by daria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipes(int ***pipes, int count)
{
	int	i;

	fprintf(stderr, "freeing pipes\n");
	i = 0;
	while (i <= count)
	{
		free((*pipes)[i]);
		i += 1;
	}
	free(*pipes);
	*pipes = NULL;
}
