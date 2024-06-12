/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:06:52 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/11 20:22:22 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <libft.h>

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

/**
 * @brief	a enum type that indicates the token type
 *			wether a PIPE, TRUNCATE, APPEND,
 *			REDIRECT INPUT, HEREDOC, or NONE !
 */
typedef enum e_tok
{
	PIPE = 1,		// |
	TRUNCATE,		// >
	APPEND,			// >>
	REDIRECT_INPUT,	// <
	HEREDOC,		// <<
	NONE
}	t_tok;

/**
@author @gogo
@attention  this is the env struct you used in execution
			the t_env_var is what i used for parsing
@todo we need to fix this conflict !

typedef struct s_env
{
	char	*key;
	char	*val;
}	t_env;
*/
typedef struct s_env_var
{
	char	*key;
	char	*val;
}	t_env_var;

/**
 * @author @gogo
 * @attention idk what (t_tmp) is it for but i kept it !
 */
// typedef struct s_tmp
// {
// 	char **cmd;
// }	t_tmp;

typedef struct s_token
{
	int		key;
	char	*word;
	t_tok	token;
}	t_token;

// typedef struct s_minishell
// {
// 	char	*input;
// 	t_list	*envlst;	// exec: t_list *env; | parse: t_list *envlst;
// 	t_list	*lexerlst;
// 	t_list	*commands;
// }	t_minishell;

typedef struct s_parser
{
	t_list		*lexer_list;
	t_list		*redirections;
	int			redirections_count;
}	t_parser;

typedef struct s_command
{
	char		**cmd_argv;
	int			cmd_argc;
	t_list		*redirections;
	int			redirections_count;
	int			input_fd;
	int			output_fd;
}	t_command;

#endif
