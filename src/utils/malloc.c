/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:58:07 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 14:31:51 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ms_malloc(size_t size)
{
	void	*memory;

	memory = malloc(size);
	ms_assert(memory != NULL, "ms_malloc: failed to allocate %zu bytes", size);
	return (memory);
}
