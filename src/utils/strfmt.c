/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strfmt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 15:56:23 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 16:05:28 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strfmt(const char *format, ...)
{
	va_list	ap;
	char	buffer[MS_BUFFER_SIZE];
	int		len;

	va_start(ap, format);
	len = ft_vsnprintf(buffer, MS_BUFFER_SIZE, format, ap);
	va_end(ap);
	return (ft_strdup(buffer));
}
