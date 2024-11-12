/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_sig.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/12 15:37:07 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/12 15:43:29 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig	g_sig;

void	init_sig(void)
{
	g_sig.sigint = false;
	g_sig.pid = 0;
	g_sig.status = 0;
}
