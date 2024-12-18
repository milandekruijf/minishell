/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cwd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:08:57 by anonymous     #+#    #+#                 */
/*   Updated: 2024/11/04 11:52:10 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	ms_assert(cwd != NULL, "get_cwd: getcwd failed");
	return (cwd);
}
