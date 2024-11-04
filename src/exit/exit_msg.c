/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_msg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 14:36:40 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 14:37:36 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_msg(int status, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	printf(format, args);
	va_end(args);
	exit(status);
}
