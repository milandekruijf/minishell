/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert_is_builtin.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:14:20 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 14:15:41 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	assert_is_builtin(t_token *token)
{
	ms_assert(is_builtin(token), "Token is not a builtin command");
}
