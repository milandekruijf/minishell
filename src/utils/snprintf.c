/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   snprintf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 15:27:07 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 15:27:11 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_vsnprintf(str, size, format, args);
	va_end(args);
	return (ret);
}
