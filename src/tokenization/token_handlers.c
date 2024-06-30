/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:13:54 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/30 18:58:19 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/// return's the string interpretation of the t_tok type provided !
static char	*tok_str(t_tok tok)
{
	if (tok == PIPE)
		return ("|");
	else if (tok == TRUNCATE)
		return (">");
	else if (tok == REDIRECT_INPUT)
		return ("<");
	else
		return ("?");
}

int	handle_token(
	char *line_read,
	int i,
	t_list **lexer_list
)
{
	t_tok	token;

	token = get_tok(line_read[i]);
	if (token == TRUNCATE && get_tok(line_read[i + 1]) == TRUNCATE)
	{
		token = APPEND;
		append_node(NULL, token, lexer_list);
		return (2);
	}
	else if (token == REDIRECT_INPUT
		&& get_tok(line_read[i + 1]) == REDIRECT_INPUT)
	{
		token = HEREDOC;
		append_node(NULL, token, lexer_list);
		return (2);
	}
	else if (token != NONE)
	{
		append_node(NULL, token, lexer_list);
		return (1);
	}
	return (-1);
}

int	handle_quotes(char *line_read, int i, char quote)
{
	int	j;

	j = 0;
	if (line_read[i + j] == quote)
		j++;
	else
		return (0);
	while (line_read[i + j] && line_read[i + j] != quote)
		j++;
	return (++j);
}
