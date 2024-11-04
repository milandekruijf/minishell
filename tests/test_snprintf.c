/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_snprintf.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 15:23:26 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 16:05:45 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define TEST_NO_MAIN

#include "minishell.h"
#include "minishell_tests.h"

void	test_snprintf(void)
{
	char	buffer[MS_BUFFER_SIZE];
	int		ret;

	ret = ft_snprintf(buffer, MS_BUFFER_SIZE, "Hello, %s!", "world");
	TEST_ASSERT(ret == 13);
	TEST_ASSERT(strcmp(buffer, "Hello, world!") == 0);
}
