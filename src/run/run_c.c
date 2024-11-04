/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_c.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 16:01:09 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:45:48 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_c(char *c, t_env_var_list *env_vars)
{
	t_tkn_list	*tkns;
	t_cmd_list	*cmds;

	tkns = parse_tkns(c);
	cmds = parse_cmds(tkns);
	free(c);
	exec(cmds, env_vars);
	free_tkn_list(&tkns);
	free_cmd_list(&cmds);
}
