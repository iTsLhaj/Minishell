/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:35:29 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/22 11:53:49 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void export(c_cmd *cmd)
{
    char *str;
    int len;
    
    len = ft_strlen(cmd->cmd[1]);
    str = (char *)malloc(len + 1);
    int i;

    i = 0;
    if(ft_strncmp(cmd->cmd[0], "export", 5) == 0)
    {
        while(i < len)
        {
            str[i] = cmd->cmd[1][i];
            i++;
        }
        str[i] = '\0';
        ft_strjoin(cmd->env[0] , str);
    }
}