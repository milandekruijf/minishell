/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:41:49 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 11:47:41 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = ms_malloc(size);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}
