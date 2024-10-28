/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strncat.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 16:55:53 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 12:59:40 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src && n > 0)
	{
		*tmp++ = *src++;
		n--;
	}
	*tmp = '\0';
	return (dest);
}
