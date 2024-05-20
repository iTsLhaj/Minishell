#ifndef TYPES_H
# define TYPES_H

/**
 * @brief	a enum type that indicates the token type
 *			wether a PIPE, TRUNCATE, APPEND,
 *			REDIRECT INPUT, HEREDOC, or NONE !
 */
typedef enum	e_token
{
	PIPE = 1,		// |
	TRUNCATE,		// >
	APPEND,			// >>
	REDIRECT_INPUT,	// <
	HEREDOC,		// <<
	NONE
}	t_token;

typedef struct	s_lexer
{
	char			*word;
	t_token			token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexter;

/**
 * @brief	struct dyaL minishell
 */
typedef struct	s_minishell
{
	void	*data;
	int		quit;
}	t_minishell;

#endif
