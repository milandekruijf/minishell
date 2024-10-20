/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_is_builtin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:04:13 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/20 18:56:01 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "acutest.h"
#include "minishell.h"

void	test_is_builtin(void)
{
	t_token	*token;

	token = tkn_create_str(TKN_CMD, "echo");
	TEST_CHECK(is_builtin(token));
	free_token(token);
	token = tkn_create_str(TKN_CMD, "unknown");
	TEST_CHECK(!is_builtin(token));
	free_token(token);
	token = tkn_create_str(TKN_ARG, "echo");
	TEST_CHECK(!is_builtin(token));
	free_token(token);
	token = tkn_create_str(TKN_CMD, "cd");
	TEST_CHECK(is_builtin(token));
	free_token(token);
	token = tkn_create_str(TKN_CMD, "pwd");
	TEST_CHECK(is_builtin(token));
	free_token(token);
	token = tkn_create_str(TKN_CMD, "export");
	TEST_CHECK(is_builtin(token));
	free_token(token);
	token = tkn_create_str(TKN_CMD, "unset");
	TEST_CHECK(is_builtin(token));
	free_token(token);
	token = tkn_create_str(TKN_CMD, "env");
	TEST_CHECK(is_builtin(token));
	free_token(token);
	token = tkn_create_str(TKN_CMD, "exit");
	TEST_CHECK(is_builtin(token));
	free_token(token);
}

TEST_LIST = {{"is_builtin", test_is_builtin}, {NULL, NULL}};