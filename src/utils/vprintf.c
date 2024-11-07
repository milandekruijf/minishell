/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vprintf.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 14:14:39 by anonymous     #+#    #+#                 */
/*   Updated: 2024/11/07 14:15:15 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}
