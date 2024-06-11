/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/08 22:55:33 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*stringify_token(t_tok token)
{
	if (token == PIPE)
		return ("PIPE");
	else if (token == TRUNCATE)
		return ("TRUNCATE");
	else if (token == APPEND)
		return ("APPEND");
	else if (token == REDIRECT_INPUT)
		return ("REDIRECT_INPUT");
	else if (token == HEREDOC)
		return ("HEREDOC");
	else
		return ("NONE");
}

void	ms_put_prompt(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	printf(" %s%s%s%s%s",
		GRN, (ft_strrchr(cwd, '/') + 1),
		MAG, PROMPT, RESET
		);
	free(cwd);
}
