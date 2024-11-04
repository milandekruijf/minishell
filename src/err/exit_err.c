/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_err.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 12:10:27 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:15:27 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_err(int status, const char *message, ...)
{
	va_list	args;

	va_start(args, message);
	print_err(message, args);
	va_end(args);
	exit(status);
}
