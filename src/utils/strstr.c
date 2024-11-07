/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strstr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 14:19:19 by anonymous     #+#    #+#                 */
/*   Updated: 2024/11/07 14:19:23 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strstr(const char *big, const char *little)
{
	return (ft_strnstr(big, little, ft_strlen(big)));
}
