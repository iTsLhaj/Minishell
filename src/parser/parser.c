/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:51:52 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/09 05:52:45 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	export_redirections(t_parser *parser)
{
	t_list	*lexlst;

	lexlst = parser->lexer_list;
	while (lexlst && ((t_token *)(lexlst->content))->token == NONE)
		lexlst = lexlst->next;
	if (lexlst == NULL || ((t_token *)(lexlst->content))->token == PIPE)
		return (0);
	if (lexlst->next == NULL)
	{
		printf("syntax error: unexpected token near \'\\n\'\n");
		return (-1);
	}
	if (((t_token *)(lexlst->next->content))->token != NONE)
	{
		printf("syntax error: near unexpected token \'?\'\n");
		return (-1);
	}
	if (((t_token *)(lexlst->content))->token >= TRUNCATE
		&& ((t_token *)(lexlst->content))->token <= HEREDOC)
		redirection_new(parser, lexlst);
	export_redirections(parser);
}

static t_command	*fetch_command(t_parser *parsing_data)
{
	int		i;
	int		args_count;
	char	**argv_;
	t_list	*cur;

	i = 0;
	cur = parsing_data->lexer_list;
	if (export_redirections(parsing_data) < 0)
		return (NULL);
	args_count = count_args(parsing_data->lexer_list);
	argv_ = ft_calloc((args_count + 1), sizeof(char *));
	while (args_count > 0)
	{
		if (((t_token *)(cur->content))->word != NULL)
		{
			argv_[i++] = ft_strdup(((t_token *)(cur->content))->word);
			lexer_delone(
				&parsing_data->lexer_list, ((t_token *)(cur->content))->key);
			cur = parsing_data->lexer_list;
		}
		args_count--;
	}
	return (command_new(
			argv_, parsing_data->redirections,
			parsing_data->redirections_count));
}

/** @todo add this command cleaning option ! */
static void	parse_command(t_minishell *shell, t_parser *parser_)
{
	t_command	*cmd;

	cmd = fetch_command(parser_);
	if (cmd == NULL)
	{
		ft_lstclear(&shell->lexerlst, &clean_content);
		parser_->lexer_list = NULL;
		shell->commands = NULL;
	}
	else
		ft_lstadd_back(
			&shell->commands,
			ft_lstnew(cmd));
}

int	parser(t_minishell *shell)
{
	t_parser	*parser_struct;
	t_token		*data;

	shell->commands = NULL;
	if (((t_token *)(shell->lexerlst->content))->token == PIPE)
		return (raise_pipe_error(-1, shell->lexerlst));
	while (shell->lexerlst)
	{
		data = (t_token *)(shell->lexerlst->content);
		if (shell->lexerlst && data->token == PIPE)
		{
			lexer_delone(&shell->lexerlst,
				((t_token *)(shell->lexerlst->content))->key);
			if (shell->lexerlst == NULL)
				return (raise_pipe_error(1, shell->lexerlst));
		}
		if (check_pipe_syntax(
				shell, ((t_token *)(shell->lexerlst->content))->token))
			return (ft_lstclear(&shell->lexerlst, &clean_content), 1);
		setup_parser_struct(shell->lexerlst, &parser_struct);
		parse_command(shell, parser_struct);
		shell->lexerlst = parser_struct->lexer_list;
	}
	return (0);
}
