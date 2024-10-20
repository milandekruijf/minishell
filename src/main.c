/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:26:50 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 15:13:03 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, const char **argv, const char **envp)
{
	char			*line;
	t_token_list	*tokens;
	t_env_var_list	*env_vars;

	listen_sigint();
	env_vars = parse_envp(envp);
	while (true)
	{
		line = readline(MS_PROMPT);
		if (!line)
			break ;
		if (*line)
			add_history(line);
		tokens = parse_tokens(line);
		free(line);
		print_tokens(tokens);
		exec(tokens, env_vars);
	}
	free(line);
	free_env_vars(&env_vars);
	free_tokens(&tokens);
	return (EXIT_SUCCESS);
}
