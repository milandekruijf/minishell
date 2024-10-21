/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_env_var_list.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 15:05:19 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 15:15:17 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_var_list	*create_env_var_list(void)
{
	t_env_var_list	*list;

	list = ms_malloc(sizeof(t_env_var_list));
	init_env_var_list(list);
	return (list);
}
