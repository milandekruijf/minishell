/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:26:50 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 15:26:15 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, const char **argv, const char **envp)
{
	t_env_var_list	*env_vars;

	env_vars = parse_envp(envp);
	if (argc == 1)
	{
		listen_sigint();
		run_it(env_vars);
	}
	else
		run_c(join_argv(argv), env_vars);
	free_env_var_list(&env_vars);
	printf("exit\n");
	return (EXIT_SUCCESS);
}
