/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:57:23 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:20 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo(c_cmd *cmd)
{
    int  i;

    i = 1;
    if(ft_strncmp(cmd->cmd[0], "echo",4) == 0)
    {
        if(cmd->cmd[1] == NULL)
            printf("\n");
        else if(ft_strncmp(cmd->cmd[1], "-n",2) == 0)
        {
            while(cmd->cmd[i])
            {
                if(ft_strncmp(cmd->cmd[i], "-n",2) != 0)
                    break;
                else
                    i++;
            }
            if(cmd->cmd[i] == NULL)
                printf("");
            else
                printf("%s",cmd->cmd[i]);
        }
        else
            printf("%s\n",cmd->cmd[1]);
    }
}
