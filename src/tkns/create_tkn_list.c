/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_tkn_list.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 15:05:19 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 14:32:43 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn_list	*create_tkn_list(void)
{
	t_tkn_list	*list;

	list = ms_malloc(sizeof(t_tkn_list));
	init_tkn_list(list);
	return (list);
}
