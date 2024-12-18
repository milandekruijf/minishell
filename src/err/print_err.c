/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_err.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 16:03:23 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 16:03:35 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	vprint_err(format, ap);
	va_end(ap);
}
