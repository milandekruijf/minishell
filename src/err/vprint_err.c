/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vprint_err.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 12:08:31 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 16:02:57 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	vprint_err(const char *format, va_list ap)
{
	ft_vdprintf(STDERR_FILENO, strfmt("minishell: %s", format), ap);
}
