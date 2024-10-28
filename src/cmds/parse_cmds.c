/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:14:27 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 13:56:37 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_list	*parse_cmds(t_tkn_list *tkns)
{
	t_tkn	*tkn;
	t_tkn 	*start;
	t_cmd_list	*cmd_list;
	int		count;

	cmd_list = create_cmd_list();
	tkn = tkns->head;
	start = tkn;	
	while (tkn && tkn->type != TKN_PIPE)
	{
		tkn = tkn->next;
		count += 1;
	}
	cmd_list->head->argv = ms_malloc(sizeof(char *) * (count + 1));
}
