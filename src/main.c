/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/20 15:51:10 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void signal_handler(int sig)
{
    char *prompt;
    
    prompt = "minishell$";
    if(sig == SIGQUIT)
    {
        return;
    }
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
    
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);
    cmdline = readline("minishell$ ");
    command.cmd = ft_split(cmdline, ' ');
    while(cmdline != NULL)
    {
        builting(command, env);
        free(cmdline);
        cmdline= readline("minishell$ ");
        command.cmd = ft_split(cmdline, ' ');
    }
    return (0);
}
