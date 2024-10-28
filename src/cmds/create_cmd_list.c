/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_cmd_list.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 15:05:19 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 13:24:28 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_list	*create_cmd_list(void)
{
	t_cmd_list	*list;

	list = ms_malloc(sizeof(t_cmd_list));
	init_cmd_list(list);
	return (list);
}
