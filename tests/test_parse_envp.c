/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_envp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:04:13 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 14:40:59 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define TEST_NO_MAIN

#include "minishell_tests.h"

void	test_parse_envp(void)
{
	const char		**dummy_envp;
	t_env_var_list	*list;
	t_env_var		*var;
	int				i;

	dummy_envp = (const char *[]){"STRICT=0", "MS_PROMPT=T", NULL};
	i = 1;
	list = parse_envp(dummy_envp);
	print_envp(dummy_envp);
	var = list->head;
	while (var->next)
	{
		if (i == 1)
		{
			TEST_CHECK(ft_strcmp(var->key, "STRICT") == 0);
			TEST_CHECK(ft_strcmp(var->value, "0") == 0);
		}
		else if (i == 2)
		{
			TEST_CHECK(ft_strcmp(var->key, "MS_PROMPT") == 0);
			TEST_CHECK(ft_strcmp(var->value, "T") == 0);
		}
		var = var->next;
		i++;
	}
	TEST_CHECK(i == 2);
	free_env_var_list(&list);
}
