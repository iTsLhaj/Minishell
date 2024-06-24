/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:07:31 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/23 15:37:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>
#include<fcntl.h>

int red_out(t_minishell *shell)
{
    int file;
    t_list *tmp;
    char **command;
    char *file_name;
    char **ptr;
    int     out = dup(1);
    char *p;
    int pid;

    t_command *cmd;
    tmp = shell->envlst;
    
    cmd = (t_command *)(shell->commands->content);
    file_name =  ((t_token *)cmd->redirections->content)->word;
    command = cmd->cmd_argv;
    // ptr = ft_split(command, ' ');
    file = open(file_name , O_WRONLY | O_CREAT | O_TRUNC, 0644);
    pid = fork();
    if(pid == 0)
    {
        if(file != -1)
        {
            if(check_builtin(command[0]))
            {
                dup2(file,1);
                close(file);
                builting(command, shell);
            }
            else if(check_exist_path(tmp) != NULL)
            {
                dup2(file ,1);
                close(file);
                check(shell);
            }
        }
        dup2(out, 1);
    }
    else
        waitpid(pid, NULL,0);
    return 0;    
}
