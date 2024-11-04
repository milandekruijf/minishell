/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_string.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 15:06:34 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 16:05:55 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*format_string(const char *format, va_list args)
{
	char	buffer[MS_BUFFER_SIZE];
	int		len;

	len = ft_vsprintf(buffer, format, args);
	return (ft_strdup(buffer));
}
