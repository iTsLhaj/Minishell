/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:58:24 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 03:54:44 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_list	*splitter(char *line_read)
{
	t_list	*parse_list;
	t_list	*pl_root;
	char	token[1024];
	int		stats[4];

	parse_list = NULL;
	pl_root = NULL;
	ft_bzero((void *)stats, sizeof(int) * 4);
	ft_bzero((void *)token, 1024);
	while (line_read[stats[2]])
	{
		if (line_read[stats[2]] == ' ' && !stats[1] && token[0])
		{
			stats[3] = 0;
			parse_list = append(parse_list, &pl_root, token);
		}
		else if (line_read[stats[2]] == '\"' || line_read[stats[2]] == '\'')
			hq(&stats[1], line_read[stats[2]], &stats[0], &token[stats[3]]);
		else
			token[stats[3]++] = line_read[stats[2]];
		stats[2]++;
	}
	if (token[0])
		parse_list = append(parse_list, &pl_root, token);
	return (pl_root);
}

static t_token_type	get_toktype(t_toklst *node)
{
	if (!ft_strncmp(node->word, "|", 1))
		return (PIPE);
	else if (!ft_strncmp(node->word, ">>", 2))
		return (APPEND);
	else if (!ft_strncmp(node->word, ">", 1))
		return (TRUNCATE);
	else if (!ft_strncmp(node->word, "<<", 2))
		return (HEREDOC);
	else if (!ft_strncmp(node->word, "<", 1))
		return (REDIRECT_INPUT);
	else
		return (NONE);
}

static t_toklst	*add_token(t_toklst *toklist, t_toklst **tok_root, char *value)
{
	if (toklist == NULL)
	{
		toklist = (t_toklst *)malloc(sizeof(t_toklst));
		ft_bzero((void *)toklist, sizeof(t_toklst));
		toklist->word = ft_strdup(value);
		toklist->type = get_toktype(toklist);
		*tok_root = toklist;
	}
	else
	{
		toklist->next = (t_toklst *)malloc(sizeof(t_toklst));
		ft_bzero((void *)toklist->next, sizeof(t_toklst));
		toklist = toklist->next;
		toklist->word = ft_strdup(value);
		toklist->type = get_toktype(toklist);
	}
	return (toklist);
}

// static char	*get_strtype(t_token_type type)
// {
// 	if (type == PIPE)
// 		return ("PIPE");
// 	else if (type == TRUNCATE)
// 		return ("TRUNCATE");
// 	else if (type == APPEND)
// 		return ("APPEND");
// 	else if (type == REDIRECT_INPUT)
// 		return ("REDIRECT_INPUT");
// 	else if (type == HEREDOC)
// 		return ("HEREDOC");
// 	else
// 		return ("NONE");
// }

t_toklst	*ms_init_tokenlst(char *lineread)
{
	t_list		*list;
	t_list		*l_root;
	t_toklst	*tk_list;
	t_toklst	*tk_root;

	if (!*lineread)
		return (NULL);
	list = splitter(lineread);
	l_root = list;
	tk_list = NULL;
	while (list)
	{
		tk_list = add_token(tk_list, &tk_root, list->val);
		list = list->next;
	}
	free_llist(l_root);
	return (tk_root);
}
/** @brief now im done with the tokenization part now what !? */
