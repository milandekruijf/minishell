/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:11:56 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:19:22 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_assert(bool predicate, const char *format, ...)
{
	va_list	args;

	if (!predicate)
	{
		va_start(args, format);
		exit_err(MS_EXIT_ASSERT_FAILED, format, args);
	}
}
