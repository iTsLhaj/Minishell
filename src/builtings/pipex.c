/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:32:39 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/02 16:44:25 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void pipex(c_cmd command , t_minishell *shell)
{
    int pipefd[2];
    pid_t pid;

    if (pipe(fd[2]) ==  -1)
    {
        perror("pipe");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
        close(fd)
    }
    
}