/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:23:17 by agaougao          #+#    #+#             */
/*   Updated: 2024/07/01 14:28:49 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"


int check_pipe(t_minishell *shell)
{
    t_command *command;
    t_command *nex_command;
    t_list *tmp;
    int out = dup(1);
    int in = dup(0);

    tmp = shell->commands;
    while(shell->commands)
    {
        command = (t_command *)(shell->commands->content);
        if(shell->commands->next)
        {
            nex_command = (t_command *)(shell->commands->next->content);
            pipex(shell, command , nex_command);
        }
        else
            pipex(shell, command ,NULL);
        shell->commands = shell->commands->next;
    }
    shell->commands = tmp;
    dup2(in, 0);
    dup2(out, 1);
    while (shell->commands)
    {
        waitpid(-1, NULL, 0);
        shell->commands = shell->commands->next;
    }
    return (0);
}