/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_builtin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:42:33 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/11 14:19:29 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_builtin(t_token *token)
{
	char	*builtins;
	int		i;

	if (token->type != TKN_CMD)
		return (false);
	builtins = get_builtins();
	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(token->value, builtins[i]))
			return (true);
		return (false);
	}
}
