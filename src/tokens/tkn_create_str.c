/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tkn_create_str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:40:17 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/18 12:51:07 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tkn_create_str(t_token_type type, char *s)
{
	return (tkn_create_substr(type, s, ft_strlen(s)));
}
