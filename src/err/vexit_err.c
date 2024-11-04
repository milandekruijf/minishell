/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vexit_err.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 12:10:27 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 16:03:07 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	vexit_err(int status, const char *format, va_list ap)
{
	vprint_err(format, ap);
	exit(status);
}
