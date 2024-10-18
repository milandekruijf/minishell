/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:26:50 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/18 14:23:23 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char			*s;
	t_token_list	tokens;

	listen_sigint();
	while (true)
	{
		s = readline(MS_PROMPT);
		if (!s)
			break ;
		if (*s)
			add_history(s);
		tokens = parse_tokens(s);
		free(s);
		print_tokens(&tokens);
		exec(&tokens);
	}
	return (EXIT_SUCCESS);
}
