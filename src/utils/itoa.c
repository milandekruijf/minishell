/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:32:12 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 14:02:22 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_itoa(int n)
{
	char		*res;
	size_t		digitcnt;
	long int	absn;

	if (n == 0)
		return (ft_strdup("0"));
	digitcnt = ndigits(n, 10);
	absn = ft_abs(n);
	if (n < 0)
		digitcnt++;
	res = ms_malloc(sizeof(char) * (digitcnt + 1));
	res[digitcnt] = '\0';
	while (digitcnt--)
	{
		res[digitcnt] = absn % 10 + '0';
		absn /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
