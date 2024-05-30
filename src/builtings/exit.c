/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:48:07 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:17 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void miniexit(c_cmd command)
{
    if(ft_strncmp(command.cmd[0] , "exit", 4) == 0)
    {
        printf("exit\n");    
        exit(0);
    }
}