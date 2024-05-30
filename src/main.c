/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/30 16:54:29 by agaougao         ###   ########.fr       */
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
int main(int ac , char **av, char **env)
{
    (void)ac;
    (void)av;
    c_cmd command;
    t_minishell *str;
    char *cmdline;
    int s;

    str = malloc(sizeof(t_minishell));
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, SIG_IGN);
    str->env = env_list(env);
    while(1)
    {
        cmdline= readline("minishell$ ");
        if(cmdline == NULL)
            break;
        command.cmd = ft_split(cmdline, ' ');
        s = check_builtin(command.cmd[0]);
        if(s != 0)
            builting(command, str);
        else
            check_path(command,str);
        add_history(cmdline);
        free(cmdline);
    }
    free(str);
    return (0);
}
