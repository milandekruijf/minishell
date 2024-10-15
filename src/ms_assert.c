/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_assert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:11:56 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 14:13:33 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_assert(bool predicate, char *message)
{
	if (!predicate)
	{
		printf("Assertion failed: %s\n", message);
		exit(MS_EXIT_ASSERT_FAILED);
	}
}
