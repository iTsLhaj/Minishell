/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:47:34 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/13 22:12:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void red_in(char **str, t_minihell *shell)
{
    t_red red;
    int file;
    char *cmd;
    char *path;
    char **ptr;

    cmd = red.b_red;
    path = red.a_red;
    
    if(access(path , F_OK) == -1)
    {
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(path, 2);
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(" No such file or directory\n", 2);
    }
    // else
    // {

    // }
}
