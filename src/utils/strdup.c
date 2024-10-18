/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strdup.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 16:14:34 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/18 16:16:21 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s)
{
	return (ft_strndup(s, ft_strlen(s)));
}
