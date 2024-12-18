/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell_tests.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/11/04 15:27:38 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TESTS_H
# define MINISHELL_TESTS_H

# include "acutest.h"
# include "minishell.h"

void	test_parse_tokens(void);
void	test_parse_envp(void);
void	test_get_env_var(void);
void	test_snprintf(void);

#endif
