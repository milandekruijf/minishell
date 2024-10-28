/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:04:13 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 12:28:53 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_tests.h"

TEST_LIST = {{"parse_tokens", test_parse_tokens}, {"parse_envp",
	test_parse_envp}, {"get_env_var", test_get_env_var}, {NULL, NULL}};
