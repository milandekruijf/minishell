/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vsprintf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 14:47:15 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 16:05:53 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, MS_BUFFER_SIZE, format, ap));
}
