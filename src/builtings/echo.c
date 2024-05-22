/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:57:23 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/21 11:30:05 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void echo(c_cmd *cmd)
{
    if(ft_strncmp(cmd->cmd[0], "echo",4) == 0)
    {
        if(cmd->cmd[1] == NULL)
        {
            printf("\n");
        }
        else if(ft_strncmp(cmd->cmd[1], "-n",2) == 0)
        {
            if(cmd->cmd[2] == NULL)
            {
                printf("");
            }
            else
                printf("%s",cmd->cmd[2]);
        }
        else
            printf("%s\n",cmd->cmd[1]);
    }
}
