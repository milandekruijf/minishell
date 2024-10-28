/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:26:50 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 14:30:30 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, const char **argv, const char **envp)
{
	t_env_var_list	*env_vars;

	(void)argv;
	listen_sigint();
	env_vars = parse_envp(envp);
	if (argc == 1)
	{
		run_it(env_vars);
	}
	free_env_var_list(&env_vars);
	return (EXIT_SUCCESS);
}
