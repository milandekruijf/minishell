/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:14:27 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 14:41:04 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_words(t_tkn *start, t_tkn *end, char **dest)
{
	int		i;
	t_tkn	*tkn;

	i = 0;
	tkn = start;
	while (tkn != end)
	{
		if (tkn->type == TKN_WORD)
			dest[i++] = ft_strdup(tkn->value);
		tkn = tkn->next;
	}
}

t_cmd_list	*parse_cmds(t_tkn_list *tkns)
{
	t_tkn		*tkn;
	t_tkn		*start;
	t_cmd_list	*cmd_list;
	int			i;

	cmd_list = create_cmd_list();
	tkn = tkns->head;
	while (tkn)
	{
		start = tkn;
		i = 0;
		while (tkn && tkn->type != TKN_PIPE)
		{
			if (tkn->type == TKN_WORD)
				i += 1;
			tkn = tkn->next;
		}
		add_cmd(cmd_list, create_empty_cmd());
		cmd_list->tail->argv = ms_malloc(sizeof(char *) * (i + 1));
		copy_words(start, tkn, cmd_list->tail->argv);
		if (tkn)
			tkn = tkn->next;
	}
	return (cmd_list);
}
