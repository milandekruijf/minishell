/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:12:31 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/18 16:34:08 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static enum e_TknParseSymbolType	get_symbol_type(char ch)
{
	if (ch == ' ')
		return (TKN_PS_SYMBOL_WHITESPACE);
	if (ch == '|')
		return (TKN_PS_SYMBOL_PIPE);
	return (TKN_PS_SYMBOL_LETTER);
}

static void	handle_empty(enum e_TknParseState *state, char **start, char **s,
		t_token_list *token_list)
{
	if (get_symbol_type(**s) == TKN_PS_SYMBOL_WHITESPACE)
		return ;
	if (get_symbol_type(**s) == TKN_PS_SYMBOL_PIPE)
	{
		tkn_add_token_to_list(token_list, tkn_create_str(TKN_PIPE, "|"));
		*state = TKN_PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(**s) == TKN_PS_SYMBOL_LETTER)
	{
		*state = TKN_PS_WORD;
		*start = *s;
	}
}

static void	handle_word(enum e_TknParseState *state, char **start, char **s,
		t_token_list *token_list)
{
	t_token	*token;

	if (get_symbol_type(**s) == TKN_PS_SYMBOL_WHITESPACE)
	{
		token = tkn_create_substr(TKN_CMD, *start, (*s - *start));
		tkn_add_token_to_list(token_list, token);
		*state = TKN_PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(**s) == TKN_PS_SYMBOL_PIPE)
	{
		token = tkn_create_substr(TKN_ARG, *start, (*s - *start));
		tkn_add_token_to_list(token_list, token);
		tkn_add_token_to_list(token_list, tkn_create_str(TKN_PIPE, "|"));
		*state = TKN_PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(**s) == TKN_PS_SYMBOL_LETTER)
	{
		return ;
	}
}

t_token_list	parse_tokens(char *line)
{
	enum e_TknParseState	state;
	char					*start;
	t_token_list			token_list;

	tkn_init_token_list(&token_list);
	state = TKN_PS_EMPTY;
	start = NULL;
	while (*line)
	{
		if (state == TKN_PS_EMPTY)
			handle_empty(&state, &start, &line, &token_list);
		else if (state == TKN_PS_WORD)
			handle_word(&state, &start, &line, &token_list);
		++line;
	}
	return (token_list);
}
