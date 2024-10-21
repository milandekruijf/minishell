/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_envp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 14:56:27 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/21 15:19:21 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envp(const char **envp)
{
	while (*envp)
		printf("%s\n", *envp++);
}
