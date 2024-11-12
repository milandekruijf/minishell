/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_sigint.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 14:12:51 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/11/12 15:28:28 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	(void)(sig);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}
