/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:59:06 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/19 18:19:34 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void builting(c_cmd command , char **env)
{
    miniexit(command);
    //cd(&command , env);
    pwd(&command);
    mini_env(env);
}