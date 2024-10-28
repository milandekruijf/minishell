/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_it.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 13:43:36 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 14:30:00 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_it(t_env_var_list *env_vars)
{
	char		*line;
	t_tkn_list	*tkns;
	t_cmd_list	*cmds;

	while (true)
	{
		line = readline(MS_PROMPT);
		if (!line)
			break ;
		if (*line)
			add_history(line);
		tkns = parse_tkns(line);
		cmds = parse_cmds(tkns);
		free(line);
		print_tkn_list(tkns);
		exec(cmds, env_vars);
		free_tkn_list(&tkns);
		free_cmd_list(&cmds);
	}
}
