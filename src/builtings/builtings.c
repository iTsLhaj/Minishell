/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:59:06 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/13 22:10:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void builting(char **str , t_minihell *shell)
{
    t_list *list;
    
    if(ft_strncmp(str[0],"pwd", 3) == 0)
        pwd(str);
    if(ft_strncmp(str[0] , "exit", 4) == 0)
        miniexit(str);
    if(ft_strncmp(str[0] ,"cd",2) == 0)
        cd(str,0);
    if(ft_strncmp(str[0], "echo",4) == 0)
        echo(str,0);
    if(ft_strncmp(str[0], "env", 3) == 0)
        mini_env(shell->env);
    if(ft_strncmp(str[0] , "export", 5) == 0)
        export(str,shell->env,0);
    if(ft_strncmp(str[0] , "unset", 5) == 0)
        unset(str, shell,0);
    
}

