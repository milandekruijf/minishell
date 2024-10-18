/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listen_sigint.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: minecraftmultiplayer <minecraftmultipla      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 14:14:24 by minecraftmu   #+#    #+#                 */
/*   Updated: 2024/10/18 14:14:39 by minecraftmu   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	listen_sigint(void)
{
	signal(SIGINT, handle_sigint);
}
