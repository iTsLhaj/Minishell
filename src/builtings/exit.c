/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:48:07 by agaougao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/20 12:10:55 by agaougao         ###   ########.fr       */
=======
/*   Updated: 2024/05/30 16:27:17 by agaougao         ###   ########.fr       */
>>>>>>> origin/exec
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

<<<<<<< HEAD
void miniexit(c_cmd command)
{
    if(ft_strncmp(command.cmd[0] , "exit", 4) == 0)
    {
        printf("exit\n");    
        exit(0);
    }
=======
void miniexit(char **str)
{
    printf("exit\n");    
    exit(0);
>>>>>>> origin/exec
}