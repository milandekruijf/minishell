/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_err.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 16:03:42 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 16:03:47 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_err(int status, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	vexit_err(status, format, ap);
	va_end(ap);
}
