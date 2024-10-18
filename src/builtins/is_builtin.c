/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_builtin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 14:48:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 14:41:32 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(t_token *token)
{
	if (get_builtin(token) != BI_UNKNOWN)
		return (true);
	return (false);
}
