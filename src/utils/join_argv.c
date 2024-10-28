/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   join_argv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 16:08:05 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/28 16:12:26 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_argv(int argc, const char **argv)
{
	size_t	size;
	int		i;
	char	*joined_argv;

	i = 0;
	size = 0;
	while (i < argc)
		size += ft_strlen(argv[i++]) + 1;
	joined_argv = ms_malloc(size * sizeof(char));
	joined_argv[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strcat(joined_argv, argv[i]);
		if (i < argc - 1)
			ft_strcat(joined_argv, " ");
		i++;
	}
	return (joined_argv);
}
