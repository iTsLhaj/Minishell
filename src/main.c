/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:31:19 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/11 19:41:43 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_signal_handler(int sig)
{
	if (sig == SIGINT)
		ms_put_prompt();
}

void	init_shell(t_minishell *shell, char **envp)
{
	shell->envlst = ms_init_env(envp);
	shell->lexerlst = NULL;
	shell->input = NULL;
	shell->commands = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	shell;

	(void)argc;
	(void)argv;
	signal(SIGINT, &ms_signal_handler);
	signal(SIGQUIT, SIG_IGN);
	init_shell(&shell, envp);
	while (1)
	{
		ms_put_prompt();
		shell.input = readline(" ");
		if (shell.input == NULL)
			break ;
		if (!check_quotes(shell.input))
		{
			tokenize_input(&shell);
			unquote(shell.lexerlst);
			extend(&shell);
			if (shell.lexerlst)
				parser(&shell);
		}
		else
			printf("syntax error: unclosed quote !\n");
		free(shell.input);
	}
	ft_lstclear(&shell.envlst, &clear_env);
	ft_lstclear(&shell.lexerlst, &clean_content);
}
