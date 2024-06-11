/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:37:36 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/09 00:09:17 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	setup_parser_struct(t_list *lexerlst, t_parser **parser_)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	parser->lexer_list = lexerlst;
	parser->redirections_count = 0;
	parser->redirections = NULL;
	*parser_ = parser;
}

int	check_pipe_syntax(t_minishell *shell, t_tok token)
{
	if (token == PIPE)
	{
		printf("syntax error: you got that double pipe !\n");
		return (1);
	}
	if (shell->lexerlst == NULL)
	{
		printf("syntax error: token must be followed with smth!\n");
		return (1);
	}
	return (0);
}

t_command	*command_new(
	char **argv_,
	t_list *redcs,
	int redcs_count
)
{
	t_command	*cmd;
	int			ac;

	ac = 0;
	while (argv_[ac])
		ac++;
	cmd = (t_command *)malloc(sizeof(t_command));
	cmd->redirections = redcs;
	cmd->cmd_argv = argv_;
	cmd->cmd_argc = ac;
	cmd->redirections_count = redcs_count;
	return (cmd);
}

void	redirection_new(t_parser *parser, t_list *node)
{
	t_token	*redirection_node;
	int		i_nodes[2];

	i_nodes[0] = ((t_token *)(node->content))->key;
	i_nodes[1] = ((t_token *)(node->next->content))->key;
	redirection_node = (t_token *)malloc(sizeof(t_token));
	ft_bzero(redirection_node, sizeof(t_token));
	redirection_node->key = -1;
	redirection_node->word = ft_strdup(
			((t_token *)(node->next->content))->word);
	redirection_node->token = ((t_token *)(node->content))->token;
	lexer_delone(&parser->lexer_list, i_nodes[0]);
	lexer_delone(&parser->lexer_list, i_nodes[1]);
	parser->redirections_count++;
	ft_lstadd_back(&parser->redirections, ft_lstnew(redirection_node));
}
