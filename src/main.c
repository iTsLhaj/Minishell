/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:53:35 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 13:04:07 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_minishell	*g_shell;


int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	*env_var;

	g_shell = (t_minishell *)malloc(sizeof(t_minishell));
	g_shell->_exit = 0;
	g_shell->envlist = ms_init_envs(envp);
	while (!g_shell->_exit)
	{
		ms_put_prompt();
		g_shell->line_read = readline(" ");
		ms_init_tokenlst(g_shell->line_read);
		env_var = ms_get_env(g_shell, g_shell->line_read);
		if (env_var != NULL)
			printf("%s\n", env_var);
		else
			printf("%s NOT FOUND\n", g_shell->line_read);
		g_shell->_exit = 1;
	}
	free(g_shell->line_read);
	free(g_shell);
}
