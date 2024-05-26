/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:59:06 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/26 16:32:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void builting(c_cmd command , t_minishell *shell)
{
    t_list *list;
    
    pwd(&command);
    miniexit(command);
    cd(&command);
    echo(&command);
    if(ft_strncmp(command.cmd[0], "env", 3) == 0)
    {
        mini_env(shell->env);
    }
    export(command,shell->env);
}
