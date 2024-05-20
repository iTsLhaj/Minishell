/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:59:06 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/20 15:03:45 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void builting(c_cmd command , char **env)
{
    pwd(&command);
    miniexit(command);
    cd(&command , env);
    mini_env(command,env);
    echo(&command);
}