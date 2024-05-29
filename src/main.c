/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/26 16:33:03 by marvin           ###   ########.fr       */
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
    t_minishell *str;
    char *cmdline;

    str = malloc(sizeof(t_minishell));
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, SIG_IGN);
    str->env = env_list(env);
    while(1)
    {
        // check_path(command);
        cmdline= readline("minishell$ ");
        if(cmdline == NULL)
            break;
        command.cmd = ft_split(cmdline, ' ');
        builting(command, str);
        add_history(cmdline);
        free(cmdline);
    }
    free(str);
    return (0);
}