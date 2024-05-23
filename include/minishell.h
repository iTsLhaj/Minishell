/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:54:35 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 03:38:36 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <types.h>
# include <libft.h>
# include <color.h>

/**
 *	@brief i just get the current folder name from the cwd
 *	e.g:
 *		- /nfs/homes/hmouhib/Desktop/.qd/.local/minishell
 *		- i take the last one "/minishell"
 *		- all i need is the folder name "minishell"
 *		- print the prompt " $FOLDER + PROMPT " -> " minishell » "
 *		+ adding some colors :)
 */
# define PROMPT " »"
# define ABS(n) ( (n < 0) ? -(n) : (n) )

/* --- misc --- */
void	    ms_put_prompt(void);

/* --- tokenize --- */
// - utils
t_list		*append(
	t_list *parse_list,
	t_list **l_root,
	char *value
);
void		hq(
	int	*in_q,
	char chr,
	int *quote,
	char *token
);
void		free_llist(t_list *list);

// - tokenization functions
t_toklst	*ms_init_tokenlst(char *lineread);


/* --- env --- */
t_env_list	*ms_envlst_new(t_env_var *value);
t_env_list	*ms_init_envs(char **envp);
char		*ms_get_env(t_minishell *shell, char *key);

#endif
