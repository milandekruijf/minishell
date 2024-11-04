/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_err.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 12:10:27 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 15:12:45 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_err(int status, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	print_err(format, args);
	va_end(args);
	exit(status);
}
