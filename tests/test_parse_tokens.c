/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_tokens.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 11:06:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/11/04 14:35:50 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define TEST_NO_MAIN

#include "minishell.h"
#include "minishell_tests.h"

typedef struct s_dummy_token
{
	t_token_type	type;
	char			*value;
}					t_dummy_token;

bool	are_equal(t_dummy_token *expected, t_tkn_list *actual_list)
{
	int		i;
	t_tkn	*actual;

	i = 0;
	actual = actual_list->head;
	while (actual != NULL && expected[i].type != TKN_END)
	{
		if (expected[i].type != actual->type)
		{
			print_err("types of tokens mismatch: expected %d, got %d\n",
				expected[i].type, actual->type);
			return (false);
		}
		if (ft_strcmp(expected[i].value, actual->value))
		{
			print_err("values of tokens mismatch: expected '%s', got '%s'\n",
				expected[i].value, actual->value);
			return (false);
		}
		actual = actual->next;
		i += 1;
	}
	if (expected[i].type != TKN_END)
	{
		print_err("expected more tokens, got only %d\n", i);
		print_tkn_list(actual_list);
		return (false);
	}
	return (true);
}

void	test_parse_tokens(void)
{
	t_dummy_token	answer[3] = {{TKN_WORD, "echo"}, {TKN_WORD, "Hi"}, {TKN_END,
			NULL}};
	t_tkn_list		*parsed;

	parsed = parse_tkns("echo    Hi");
	TEST_CHECK(are_equal(answer, parsed));
	free_tkn_list(&parsed);
}
