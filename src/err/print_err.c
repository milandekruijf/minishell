/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_err.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 12:08:31 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 15:51:52 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vdprintf(STDERR_FILENO, format, args);
	va_end(args);
}
