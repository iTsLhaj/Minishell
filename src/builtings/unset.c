/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:08:28 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/20 14:35:27 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


void    unset(char **env, c_cmd *cmd)
{
    char *env;
    
    if(ft_strncmp(cmd->cmd[0], "unset",5) == 0)
    {
        env = getenv(cmd->cmd[1]);
        if(env != NULL)
        {
            
        }
        
    }
}