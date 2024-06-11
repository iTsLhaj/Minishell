/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:21:39 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/01 04:55:39 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	extract_word(
	char *line_read,
	int i,
	t_list **lexer_list
)
{
	int		j;
	t_tok	token;

	j = 0;
	while (line_read[i + j] && (get_tok(line_read[i + j]) == NONE))
	{
		j += handle_quotes(line_read, i + j, '\"');
		j += handle_quotes(line_read, i + j, '\'');
		if (line_read[i + j] == ' '
			|| (line_read[i + j] > 8 && line_read[i + j] < 14))
			break ;
		else
			j++;
	}
	token = NONE;
	append_node(
		ft_substr(line_read, i, j),
		token, lexer_list
		);
	return (j);
}

void	tokenize_input(t_minishell *shell)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_strtrim(shell->input, " ");
	free(shell->input);
	shell->input = tmp;
	i = 0;
	while (shell->input[i])
	{
		j = 0;
		i += ignore_spaces(shell->input, i);
		if (get_tok(shell->input[i]) != NONE)
			j = handle_token(
					shell->input, i,
					&shell->lexerlst
					);
		else
			j = extract_word(
					shell->input, i,
					&shell->lexerlst
					);
		i += j;
	}
}
