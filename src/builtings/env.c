/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:15:03 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/20 12:01:34 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void mini_env(c_cmd command,char **env)
{
    int i;
    
    i = 0;
    command.env = env;
    if(ft_strncmp(command.cmd[0] ,"env",3) == 0)
    {
        while(command.env[i] != NULL)
        {
            printf("%s\n",command.env[i]);
            i++;
        }
    }
}