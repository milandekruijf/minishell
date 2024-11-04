/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   puts.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:35:12 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:09:16 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_puts(const char *s, int fd)
{
	write(fd, s, sizeof(char) * ft_strlen(s));
}
