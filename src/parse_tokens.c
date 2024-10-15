/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:12:31 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 14:53:58 by mde-krui      ########   odam.nl         */
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

void	handle_empty(enum e_ParseState *state, char **start, char **s)
{
	if (get_symbol_type(**s) == PS_SYMBOL_WHITESPACE)
		return ;
	if (get_symbol_type(**s) == PS_SYMBOL_PIPE)
	{
	}
	if (get_symbol_type(**s) == PS_SYMBOL_LETTER)
	{
		*state = PS_WORD;
		*start = *s;
	}
}

void	handle_word(enum e_ParseState *state, char **start, char **s)
{
	if (get_symbol_type(**s) == PS_SYMBOL_WHITESPACE)
	{
	}
	if (get_symbol_type(**s) == PS_SYMBOL_PIPE)
	{
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

	state = PS_EMPTY;
	start = s;
	while (*s)
	{
		if (state == PS_EMPTY)
			handle_empty(&state, &start, &s);
		else if (state == PS_WORD)
			handle_word(&state, &start, &s);
		++s;
	}
}
