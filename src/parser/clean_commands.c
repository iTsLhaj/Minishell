/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/25 00:34:37 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	clean_command(void *content)
{
	t_command	*command_t;
	int			i;

	command_t = (t_command *)content;
	if (command_t->redirections != NULL)
		ft_lstclear(
			&command_t->redirections,
			&clean_content
		);
	i = 0;
	while (command_t->cmd_argv[i])
		free(command_t->cmd_argv[i++]);
	free(content);
}
