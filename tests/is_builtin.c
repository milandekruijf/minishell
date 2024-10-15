/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_builtin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:04:13 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/15 13:49:10 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main(void)
{
	t_token	*token;
	bool	builtin;

	token = create_token(TKN_CMD, "echo");
	printf("Created token with type CMD and value 'echo'\n");
	builtin = is_builtin(token);
	if (builtin)
		printf("Token is a builtin command\n");
	else
		printf("Token is not a builtin command\n");
}
