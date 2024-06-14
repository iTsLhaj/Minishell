/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:07:31 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/14 21:12:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>
#include<fcntl.h>

int red_out(char **str, t_minishell *shell, int i)
{
    int file;
    t_red red;
    t_list *tmp;
    char *command;
    char *file_name;
    char **ptr;
    int     out = dup(1);
    char *p;
    int pid;

    tmp = shell->envlst ;
    file_name = red.a_red;
    command = red.b_red;
    ptr = ft_split(command, ' ');
    file = open(file_name , O_WRONLY | O_CREAT | O_TRUNC, 0644);
    pid = fork();
    if(pid == 0)
    {
        if(file != -1)
        {
            if(check_builtin(command))
            {
                dup2(file,1);
                close(file);
                builting(ptr, shell);
            }
            else if(check_exist_path(tmp) != NULL)
            {
                dup2(file ,1);
                close(file);
                check(ptr , shell);
            }
        }
        dup2(out, 1);
    }
    else
        waitpid(pid, NULL,0);
    return 0;    
}
