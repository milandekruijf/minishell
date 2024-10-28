/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_line.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 16:01:09 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 16:01:24 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_line(char *line, t_env_var_list *env_vars)
{
	t_tkn_list	*tkns;
	t_cmd_list	*cmds;

	tkns = parse_tkns(line);
	cmds = parse_cmds(tkns);
	free(line);
	print_tkn_list(tkns);
	exec(cmds, env_vars);
	free_tkn_list(&tkns);
	free_cmd_list(&cmds);
}
