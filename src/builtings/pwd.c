/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:07:31 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/19 18:20:50 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void    pwd(c_cmd *cmd)
{
    char    *pwd;
    if(ft_strncmp(cmd->cmd,"pwd", 3) == 0)
    {
        pwd = getcwd(NULL, 0);
        if(pwd == NULL)
            return;
        printf("%s\n", pwd);
    }
}