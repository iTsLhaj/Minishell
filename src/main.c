/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/19 17:45:38 by agaougao         ###   ########.fr       */
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
    
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);
    command.cmd = readline("minishell$");
    while(command.cmd != NULL)
    {
        builting(command, env);
        free(command.cmd);
        command.cmd = readline("minishell$");
    }
    return (0);
}