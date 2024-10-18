/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_envp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 14:56:27 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/18 16:37:14 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envp(const char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
}
