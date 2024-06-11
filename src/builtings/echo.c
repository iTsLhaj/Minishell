/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:57:23 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/23 15:00:50 by marvin           ###   ########.fr       */
=======
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:57:23 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:20 by agaougao         ###   ########.fr       */
>>>>>>> origin/exec
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
void echo(c_cmd *cmd)
=======
void echo(char **str , int j)
>>>>>>> origin/exec
{
    int  i;

    i = 1;
<<<<<<< HEAD
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
            // if(cmd->cmd[i] == NULL)
            //     printf("");
            // else
            //     printf("%s",cmd->cmd[i]);
        }
        else
            printf("%s\n",cmd->cmd[1]);
    }
=======
    if(str[j + 1] == NULL)
        printf("\n");
    else if(ft_strncmp(str[j + 1], "-n",2) == 0)
    {
        while(str[j + i])
        {
            if(ft_strncmp(str[j + i], "-n",2) != 0)
                break;
            else
                i++;
        }
        if(str[j + i] == NULL)
            printf("");
        else
            printf("%s",str[j + i]);
    }
    else
        printf("%s\n",str[j + i]);
>>>>>>> origin/exec
}
