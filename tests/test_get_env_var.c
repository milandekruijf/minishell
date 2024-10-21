/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_env_var.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:04:13 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 13:36:03 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define TEST_NO_MAIN

#include "minishell_tests.h"

void	test_get_env_var(void)
{
	const char		**dummy_envp;
	t_env_var_list	list;

	dummy_envp = (const char *[]){"STRICT=0", "MS_PROMPT=T", NULL};
	list = parse_envp(dummy_envp);
	TEST_CHECK(get_env_var(&list, "STRICT") != NULL);
	TEST_CHECK(get_env_var(&list, "MS_PROMPT") != NULL);
	TEST_CHECK(get_env_var(&list, "UNKNOWN") == NULL);
	TEST_CHECK(ft_strcmp(get_env_var(&list, "MS_PROMPT")->key,
			"MS_PROMPT") == 0);
	TEST_CHECK(ft_strcmp(get_env_var(&list, "MS_PROMPT")->value, "T") == 0);
}
