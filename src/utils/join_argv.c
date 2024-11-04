/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   join_argv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 16:08:05 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 12:45:48 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_argv(const char **argv)
{
	size_t	size;
	int		i;
	char	*res;

	i = 0;
	size = 0;
	while (argv[i])
		size += ft_strlen(argv[i++]) + 1;
	res = ms_malloc(size * sizeof(char));
	res[0] = '\0';
	i = 1;
	while (argv[i])
	{
		ft_strcat(res, argv[i]);
		if (argv[i + 1])
			ft_strcat(res, " ");
		i++;
	}
	return (res);
}
