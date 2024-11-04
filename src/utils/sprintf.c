/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprintf.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:39:08 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 11:41:24 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_sprintf(const char *format, ...)
{
	va_list		args;
	char		*result;
	const char	*ptr;
	char		*arg;
	size_t		len;
	size_t		buffer_size;

	va_start(args, format);
	buffer_size = ft_strlen(format) + 256;
	result = ms_malloc(buffer_size);
	result[0] = '\0';
	ptr = format;
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1) == 's')
		{
			ptr += 2;
			arg = va_arg(args, char *);
			if (ft_strlen(result) + ft_strlen(arg) + 1 > buffer_size)
			{
				buffer_size *= 2;
				free(result);
				result = ms_malloc(buffer_size);
			}
			ft_strcat(result, arg);
		}
		else
		{
			len = ft_strlen(result);
			if (len + 2 > buffer_size)
			{
				buffer_size *= 2;
				free(result);
				result = ms_malloc(buffer_size);
			}
			result[len] = *ptr;
			result[len + 1] = '\0';
			ptr++;
		}
	}
	va_end(args);
	return (result);
}
