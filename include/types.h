/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:54:45 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 03:10:47 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/**
 * @brief	a enum type that indicates the token type
 *			wether a PIPE, TRUNCATE, APPEND,
 *			REDIRECT INPUT, HEREDOC, or NONE !
 */
typedef enum e_token_type
{
	PIPE = 1,		// |
	TRUNCATE,		// >
	APPEND,			// >>
	REDIRECT_INPUT,	// <
	HEREDOC,		// <<
	NONE
}	t_token_type;

typedef struct s_toklst
{
	char			*word;
	t_token_type	type;
	struct s_toklst	*next;
}	t_toklst;

typedef struct s_env_var
{
	char	*key;
	char	*val;
}	t_env_var;

typedef struct s_env_list
{
	t_env_var			*evar;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_minishell
{
	int			_exit;
	char		*line_read;
	t_env_list	*envlist;
}	t_minishell;

typedef struct	s_list
{
	char			*val;
	struct s_list	*next;
}	t_list;

#endif
