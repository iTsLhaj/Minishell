/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/23 13:21:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void signal_handler(int sig)
{
    char *prompt;
    
    prompt = "minishell$";
    if (sig == SIGINT)
    {
        printf("\n%s", prompt);
    }
}

int main(int ac , char **av, char **env)
{
    (void)ac;
    (void)av;
    c_cmd command;
    char *cmdline;

    command.env = env;
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, SIG_IGN);
    cmdline = readline("minishell$ ");
    command.cmd = ft_split(cmdline, ' ');
    while(cmdline != NULL)
    {
        builting(command, env);
        check_path(command);
        free(cmdline);
        cmdline= readline("minishell$ ");
        command.cmd = ft_split(cmdline, ' ');
    }
    return (0);
}
