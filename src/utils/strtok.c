/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtok.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 15:41:43 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 15:50:43 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strtok(char *str, const char delim)
{
	static char	*rem;
	char		*ptr;

	if (str)
		rem = ft_strdup(str);
	if (!rem || *rem == '\0')
		return (NULL);
	ptr = rem;
	while (*rem && *rem != delim)
		rem++;
	if (*rem)
		*rem++ = '\0';
	return (ptr);
}
