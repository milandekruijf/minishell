/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_is_builtin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:04:13 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 15:08:18 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define TEST_NO_MAIN

#include "minishell_tests.h"

void	test_is_builtin(void)
{
	t_token	*token;

	token = create_token(TKN_CMD, "echo");
	TEST_CHECK(is_builtin(token));
	free_token(&token);
	token = create_token(TKN_CMD, "unknown");
	TEST_CHECK(!is_builtin(token));
	free_token(&token);
	token = create_token(TKN_ARG, "echo");
	TEST_CHECK(!is_builtin(token));
	free_token(&token);
	token = create_token(TKN_CMD, "cd");
	TEST_CHECK(is_builtin(token));
	free_token(&token);
	token = create_token(TKN_CMD, "pwd");
	TEST_CHECK(is_builtin(token));
	free_token(&token);
	token = create_token(TKN_CMD, "export");
	TEST_CHECK(is_builtin(token));
	free_token(&token);
	token = create_token(TKN_CMD, "unset");
	TEST_CHECK(is_builtin(token));
	free_token(&token);
	token = create_token(TKN_CMD, "env");
	TEST_CHECK(is_builtin(token));
	free_token(&token);
	token = create_token(TKN_CMD, "exit");
	TEST_CHECK(is_builtin(token));
	free_token(&token);
}
