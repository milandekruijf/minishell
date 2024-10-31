/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:11:56 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/31 15:24:04 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_assert(bool predicate, const char *message)
{
	if (!predicate)
	{
		printf("minishell: %s\n", message);
		exit(MS_EXIT_ASSERT_FAILED);
	}
}
