/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_err.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 12:08:31 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:21:15 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err(const char *message, ...)
{
	va_list	args;

	va_start(args, message);
	ft_puts(ft_sprintf("minishell: %s\n", ft_sprintf(message, args)),
		STDERR_FILENO);
	va_end(args);
}
