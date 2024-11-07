/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vsnprintf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 15:09:06 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/07 14:27:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	size_t	i;
	size_t	written;
	char	*str_arg;

	i = 0;
	written = 0;
	while (format[i] != '\0' && written < size - 1)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				str_arg = va_arg(ap, char *);
				if (str_arg)
					while (*str_arg && written < size - 1)
						str[written++] = *str_arg++;
			}
			else
			{
				if (written < size - 1)
					str[written++] = '%';
				if (written < size - 1)
					str[written++] = format[i];
			}
		}
		else if (written < size - 1)
			str[written++] = format[i];
		i++;
	}
	str[written] = '\0';
	return (written);
}
