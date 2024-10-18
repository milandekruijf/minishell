/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:12:31 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/18 12:56:51 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_SymbolType	get_symbol_type(char ch)
{
	if (ch == ' ')
		return (PS_SYMBOL_WHITESPACE);
	if (ch == '|')
		return (PS_SYMBOL_PIPE);
	return (PS_SYMBOL_LETTER);
}

void	handle_empty(enum e_ParseState *state, char **start, \
			char **s, t_token_list *token_list)
{
	if (get_symbol_type(**s) == PS_SYMBOL_WHITESPACE)
		return ;
	if (get_symbol_type(**s) == PS_SYMBOL_PIPE)
	{
		tkn_add_token_to_list(token_list, tkn_create_str(TKN_PIPE, "|"));
		*state = PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(**s) == PS_SYMBOL_LETTER)
	{
		*state = PS_WORD;
		*start = *s;
	}
}

void	handle_word(enum e_ParseState *state, char **start, \
			char **s, t_token_list *token_list)
{
	t_token	*token;

	if (get_symbol_type(**s) == PS_SYMBOL_WHITESPACE)
	{
		token = tkn_create_substr(TKN_ARG, *start, (*s - *start));
		tkn_add_token_to_list(token_list, token);
		*state = PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(**s) == PS_SYMBOL_PIPE)
	{
		token = tkn_create_substr(TKN_ARG, *start, (*s - *start));
		tkn_add_token_to_list(token_list, token);
		tkn_add_token_to_list(token_list, tkn_create_str(TKN_PIPE, "|"));
		*state = PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(**s) == PS_SYMBOL_LETTER)
	{
		return ;
	}
}

t_token	*parse_tokens(char *s)
{
	enum e_ParseState	state;
	char				*start;
	t_token_list		token_list;

	tkn_init_token_list(&token_list);
	state = PS_EMPTY;
	start = NULL;
	while (*s)
	{
		if (state == PS_EMPTY)
			handle_empty(&state, &start, &s, &token_list);
		else if (state == PS_WORD)
			handle_word(&state, &start, &s, &token_list);
		++s;
	}
	return (token_list.head);
}
