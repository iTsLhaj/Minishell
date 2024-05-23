/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:53:48 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/21 20:08:13 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
