/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vsprintf.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 14:47:15 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 15:53:12 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	return (ft_vsnprintf(str, ft_strlen(str), format, ap));
}
