/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:04:13 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 12:51:57 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_tests.h"

TEST_LIST = {{"is_builtin", test_is_builtin}, {"parse_tokens",
	test_parse_tokens}, {"parse_envp", test_parse_envp}, {NULL, NULL}};
