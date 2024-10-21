/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:12:31 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 15:07:16 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static enum e_TknParseSymbolType	get_symbol_type(char ch)
{
	if (ch == ' ')
		return (TKN_PS_SYMBOL_WHITESPACE);
	if (ch == '|')
		return (TKN_PS_SYMBOL_PIPE);
	if (ch == '\0')
		return (TKN_PS_SYMBOL_NULL_TERMINATOR);
	return (TKN_PS_SYMBOL_LETTER);
}

static void	handle_empty(enum e_TknParseState *state, char **start, char *s,
		t_token_list *token_list)
{
	if (get_symbol_type(*s) == TKN_PS_SYMBOL_WHITESPACE
		|| get_symbol_type(*s) == TKN_PS_SYMBOL_NULL_TERMINATOR)
		return ;
	if (get_symbol_type(*s) == TKN_PS_SYMBOL_PIPE)
	{
		add_token(token_list, create_token(TKN_PIPE, "|"));
		*state = TKN_PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(*s) == TKN_PS_SYMBOL_LETTER)
	{
		*state = TKN_PS_WORD;
		*start = s;
	}
}

static void	handle_word(enum e_TknParseState *state, char **start, char *s,
		t_token_list *token_list)
{
	t_token	*token;

	if (get_symbol_type(*s) == TKN_PS_SYMBOL_WHITESPACE
		|| get_symbol_type(*s) == TKN_PS_SYMBOL_NULL_TERMINATOR)
	{
		token = create_token(TKN_CMD, ft_strndup(*start, (s - *start)));
		add_token(token_list, token);
		*state = TKN_PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(*s) == TKN_PS_SYMBOL_PIPE)
	{
		token = create_token(TKN_ARG, ft_strndup(*start, (s - *start)));
		add_token(token_list, token);
		add_token(token_list, create_token(TKN_PIPE, "|"));
		*state = TKN_PS_EMPTY;
		*start = NULL;
	}
	if (get_symbol_type(*s) == TKN_PS_SYMBOL_LETTER)
	{
		return ;
	}
}

void	handle_state(enum e_TknParseState *state, char **start, char *s,
		t_token_list *token_list)
{
	if (*state == TKN_PS_EMPTY)
		handle_empty(state, start, s, token_list);
	else if (*state == TKN_PS_WORD)
		handle_word(state, start, s, token_list);
}

t_token_list	*parse_tokens(char *line)
{
	enum e_TknParseState	state;
	char					*start;
	t_token_list			*tokens;

	tokens = create_token_list();
	state = TKN_PS_EMPTY;
	start = NULL;
	while (*line)
	{
		handle_state(&state, &start, line, tokens);
		++line;
	}
	handle_state(&state, &start, line, tokens);
	return (tokens);
}
