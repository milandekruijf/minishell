/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_tkn_list.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 12:13:24 by dkolodze      #+#    #+#                 */
/*   Updated: 2024/10/28 13:38:11 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_tkn_list(t_tkn_list *list)
{
	list->head = NULL;
	list->tail = NULL;
}
