/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:17:03 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/19 18:12:57 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void cd(c_cmd *cmd , char **env)
{
    int i;
    char *path;
    int stat;
    (void) env;
    
    i = 0;
    path = cmd->cmd;
    stat = chdir(path);
    if(stat == -1)
        perror("unknow path\n");
    
}