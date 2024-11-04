/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memcpy.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:52:56 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 11:56:35 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)dest;
	while (n-- > 0)
		*(unsigned char *)tmp++ = *(unsigned char *)src++;
	return (dest);
}
