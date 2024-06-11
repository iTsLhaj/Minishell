/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:55:11 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/01 04:56:19 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_tok	get_tok(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '>')
		return (TRUNCATE);
	else if (c == '<')
		return (REDIRECT_INPUT);
	else
		return (NONE);
}

int	ignore_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] == ' '
		|| (str[i + j] > 8 && str[i + j] < 14))
		j++;
	return (j);
}

int	append_node(char *word, t_tok token, t_list **lexer_list)
{
	t_list		*node;
	t_token		*content;
	static int	tracker;

	content = (t_token *)malloc(sizeof(t_token));
	if (content == NULL)
		return (0);
	content->token = token;
	content->word = word;
	content->key = tracker++;
	node = ft_lstnew((void *)content);
	if (node == NULL)
		return (0);
	if (*lexer_list == NULL)
		*lexer_list = node;
	else
		ft_lstadd_back(lexer_list, node);
	return (1);
}
