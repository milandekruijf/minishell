/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vdprintf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 14:49:19 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 15:42:19 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	buffer[100];
	int		len;

	len = ft_vsprintf(buffer, format, ap);
	ft_fputs(buffer, fd);
	return (len);
}
