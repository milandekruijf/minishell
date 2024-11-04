/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprintf.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:39:08 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:08:01 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*resize_buffer(char *buffer, size_t *size)
{
	return (ft_realloc(buffer, (*size) *= 2));
}

static void	append_string(char **res, const char *str, size_t *size)
{
	if (ft_strlen(*res) + ft_strlen(str) + 1 > *size)
		*res = resize_buffer(*res, size);
	ft_strcat(*res, str);
}

static void	append_char(char **res, char c, size_t *size)
{
	size_t	len;

	len = ft_strlen(*res);
	if (len + 2 > *size)
		resize_buffer(*res, size);
	(*res)[len] = c;
	(*res)[len + 1] = '\0';
}

char	*ft_sprintf(const char *format, ...)
{
	va_list		args;
	char		*res;
	const char	*ptr;
	char		*arg;
	size_t		size;

	va_start(args, format);
	size = ft_strlen(format) + 256;
	res = ms_malloc(size);
	res[0] = '\0';
	ptr = format;
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1) == 's')
		{
			ptr += 2;
			arg = va_arg(args, char *);
			append_string(&res, arg, &size);
		}
		else
			append_char(&res, *ptr++, &size);
	}
	va_end(args);
	return (res);
}
