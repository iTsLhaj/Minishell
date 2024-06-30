/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:31:19 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/30 18:14:59 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

int check_builtin(char *str)
{

	if (ft_strncmp(str, "echo",4) == 0)
		return (1);
	else if (ft_strncmp(str, "cd",2) == 0)
		return (2);
	else if (ft_strncmp(str, "pwd",3) == 0)
		return (3);
	else if (ft_strncmp(str, "export",5) == 0)
		return (4);
	else if (ft_strncmp(str, "unset",5) == 0)
		return (5);
	else if (ft_strncmp(str, "env",3) == 0)
		return (6);
	else if (ft_strncmp(str, "exit",4) == 0)
		return (7);
	else
		return (0);
}

/**
 *	@note commented lines ment to fix the quoting issue !
 */
int	main(int argc, char **argv, char **envp)
{
	printf("Minishell dzzb!\n");
}
