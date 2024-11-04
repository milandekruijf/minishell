/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_snprintf.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/04 15:23:26 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 15:27:59 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define TEST_NO_MAIN

#include "minishell.h"
#include "minishell_tests.h"

void	test_snprintf(void)
{
	char	buffer[100];
	int		ret;

	ret = ft_snprintf(buffer, 100, "Hello, %s!", "world");
	TEST_ASSERT(ret == 13);
	TEST_ASSERT(strcmp(buffer, "Hello, world!") == 0);
}
