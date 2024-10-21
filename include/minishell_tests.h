/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell_tests.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-krui <mde-krui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:13:25 by mde-krui      #+#    #+#                 */
/*   Updated: 2024/10/21 13:31:39 by mde-krui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TESTS_H
# define MINISHELL_TESTS_H

# include "acutest.h"
# include "minishell.h"

void	test_is_builtin(void);
void	test_parse_tokens(void);
void	test_parse_envp(void);
void	test_get_env_var(void);

#endif
