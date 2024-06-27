/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:45:15 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/27 11:55:55 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

int append_red(t_minishell *shell)
{
    t_command *command;
    t_token *redirection;
    int fd;
    char **cmdline;
    int pid;
    t_list *tmp;
    int out = dup(1);

    tmp = shell->envlst;
    command =  (t_command *)(shell->commands->content);
    redirection = ((t_token *)command->redirections->content);
    cmdline = command->cmd_argv;
    fd = open(redirection->word , O_WRONLY | O_CREAT | O_APPEND , 0644);
    pid = fork();
    if (pid == 0)
    {
        if(fd != -1)
        {
            if(check_builtin(cmdline[0]))
            {
                dup2(fd, 1);
                close(fd);
                builting(cmdline, shell);
            }
            else if(check_exist_path(tmp) != NULL)
            {
                dup2(fd, 1);
                close(fd);
                check(shell);
            }
        }
        dup2(out ,1);
    }
    else
        waitpid(pid, NULL , 0);
    return (1);
}