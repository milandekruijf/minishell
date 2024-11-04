/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprintf.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 11:39:08 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 15:02:36 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vsprintf(str, format, args);
	va_end(args);
	return (len);
}
