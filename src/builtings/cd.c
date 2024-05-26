/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:17:03 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/25 13:40:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void cd(c_cmd *cmd)
{
    char *path;

    int status;
    if(ft_strncmp(cmd->cmd[0] ,"cd",2) == 0)
    {
        path = cmd->cmd[1];
        if(path == NULL)
        {
            status = chdir(getenv("HOME"));
            if(status != 0)
            {
                ft_putstr_fd("cd: no such file or directory: ", 2);            
            }
        }
        else
        {
            status = chdir(path);
            if(status != 0)
            {
                ft_putstr_fd("cd: no such file or directory: ", 2);
                ft_putendl_fd(path, 2);
            }
        }
    }
}
