/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcspn.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 14:18:17 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 14:18:35 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(reject, s[i]))
			return (i);
		i++;
	}
	return (i);
}
