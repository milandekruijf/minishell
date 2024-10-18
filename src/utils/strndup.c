/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strndup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:46:03 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/18 12:57:47 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(char *s, ssize_t n)
{
	ssize_t	i;
	char	*copy;

	i = 0;
	copy = ms_malloc(n + 1);
	while (s[i] && i < n)
	{
		copy[i] = s[i];
		++i;
	}
	copy[n] = '\0';
	return (copy);
}