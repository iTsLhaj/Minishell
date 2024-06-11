/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/09 05:49:29 by meow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *	@author @lh4j
 *
 *	@attention
 *		this error handling file is temporary
 *		im using it for handling parsing errors
 *		execution errors might be added later
 *		things can take an unexpeted round
 *
 *	@brief
 *		take this source code as a temporary
 *		error handling dummies to practice on
 */

#include <minishell.h>

/**
 * @todo add this commands list learing option for n == 1 !
 *		 parser.c:100 -> there was a shell.command = NULL instr
 * @param n
 * @param lexer_list
 * @return
 */
int	raise_pipe_error(int n, t_list *lexer_list)
{
	if (n == -1)
		printf("syntax error: starting with a PIPE ?\n");
	if (n == 1)
		printf("syntax error: Ending with a PIPE?\n");
	ft_lstclear(&lexer_list, &clean_content);
	return (1);
}
