/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_malloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:58:07 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 14:35:37 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ms_malloc(size_t size)
{
	void	*memory;

	memory = malloc(size);
	if (memory == NULL)
	{
		printf("ms_malloc: failed to allocate %zu bytes\n", size);
		exit(MS_EXIT_MALLOC_ERROR);
	}
	return (memory);
}
