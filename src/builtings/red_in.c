/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:47:34 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/24 13:22:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void red_in(t_minishell *shell)
{
    t_command *command;
    char *file_name;
    char **cmd;
    int file;
    int pid;
    int in = dup(0);
    t_list *tmp;
    
    tmp = shell->envlst;
    command = (t_command *)shell->commands->content;
    file_name = ((t_token *)command->redirections->content)->word;
    cmd = command->cmd_argv;
    if(access(file_name , F_OK) == -1)
        printf("minishell : %s: no such file or directory\n", file);
    else
    {
        file = open(file_name, O_RDONLY);
        pid = fork();
        if(pid == 0)
        {       
            if(file != -1)
            {
                if(check_builtin(cmd[0]))
                {
                    dup2(file, 0);
                    close(file);
                    builting(cmd , shell);
                }
                else if(check_exist_path(tmp) != NULL)
                {
                    dup2(file ,0);
                    close(file);
                    check(shell);
                }    
            }
            dup2(in ,0);
        }
        else
            waitpid(pid ,NULL, 0);
    }
}
