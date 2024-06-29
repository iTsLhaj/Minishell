/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:32:39 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/29 13:14:07 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



void pipex(t_minishell *shell , t_command *command, t_command *nex_command)
{
    int fd[2];
    int pid;
    int fd1;
    int fd2;
    pipe(fd);        
    pid = fork();
    // if(!= -1)
    // {
        if (pid == 0)
        {
            dup2(fd[1], 1);
            close(fd[0]);
            close(fd[1]);
            if(check_red(shell , command) == 0)
                check(shell , command);
        }
        // else if(pid != -1)
        // {
        //     dup2(fd[0], 0);
        //     close(fd[1]);
        //     close(fd[0]);
        //     if(check_red(shell , nex_command) == 0)
        //         check(shell, nex_command);
        // }
    // }
}
