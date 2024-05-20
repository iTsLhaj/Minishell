#include <minishell.h>

static t_token	get_token(char *word)
{
	if (!ft_strncmp(word, "|", ft_strlen(word)))
		return (PIPE);
	else if (!ft_strncmp(word, ">", ft_strlen(word)))
		return (TRUNCATE);
	else if (!ft_strncmp(word, ">>", ft_strlen(word)))
		return (APPEND);
	else if (!ft_strncmp(word, "<", ft_strlen(word)))
		return (REDIRECT_INPUT);
	else if (!ft_strncmp(word, "<<", ft_strlen(word)))
		return (HEREDOC);
	else
		return (NONE);
}

static t_lexter	*get_last(t_lexter *root)
{
	if (!root)
		return (NULL);
	while (root->next)
		root = root->next;
	return (root);
}

t_lexter	*ms_parse_input(char *lineread)
{
	t_lexter	*last;
	t_lexter	*lexer;
	t_lexter	*l_root;
	char		**words;
	int			i;

	lexer = (t_lexter *)malloc(sizeof(t_lexter));
	l_root = lexer;
	ft_bzero((void *)lexer, sizeof(t_lexter));
	words = ft_split(lineread, ' ');
	i = 0;
	while (words[i])
	{
		last = get_last(l_root);
		if (!i)
			lexer->prev = NULL;
		else
		{
			lexer = (t_lexter *)malloc(sizeof(t_lexter));
			ft_bzero((void *)lexer, sizeof(t_lexter));
			lexer->prev = last;
			last->next = lexer;
		}
		lexer->next = NULL;
		lexer->i = i;
		lexer->token = get_token(words[i]);
		ft_strlcpy(lexer->word, words[i], ft_strlen(words[i]));
		i++;
	}
	return (l_root);
}

static char	*get_token_str(t_token token)
{
	if (token == PIPE)
		return ("PIPE");
	else if (token == TRUNCATE)
		return ("TRUNCATE");
	else if (token == APPEND)
		return ("APPEND");
	else if (token == REDIRECT_INPUT)
		return ("REDIRECT_INPUT");
	else if (token == HEREDOC)
		return ("HEREDOC");
	else
		return ("NONE");
}

void		h_list_parsedin(t_lexter *parsed_input)
{
	while (parsed_input)
	{
		printf(" - word: %s\n - index: %i\n - token: %s\n",
			parsed_input->word, parsed_input->i, get_token_str(parsed_input->token));
		parsed_input = parsed_input->next;
	}
}
