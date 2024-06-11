/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:06:06 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/09 00:05:43 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	count_args(t_list *lexer_list)
{
	int	ac;

	ac = 0;
	if (lexer_list == NULL)
		return (ac);
	while (lexer_list && ((t_token *)(lexer_list->content))
		->token != PIPE)
	{
		ac++;
		lexer_list = lexer_list->next;
	}
	return (ac);
}
