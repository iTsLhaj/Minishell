/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:31:59 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/27 11:48:01 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <types.h>
# include <color.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

/**
 * @author @gogo
 * @brief execution related functions !
 * @warning there might be a conflict
 * @todo FIX IT !
 */
/** ******************************************************* */

typedef struct cmd
{
	char **cmd;
	int infile;
	int outfile;
} t_cmd;

typedef struct s_env
{
	char	*key;
	char	*val;
}	t_env;

typedef struct s_tmp
{
	char **cmd;
}	t_tmp;

typedef struct s_red
{
	char *b_red;
	char *a_red;
}	t_red;


void builting(char **str, t_minishell *shell);
void miniexit(char **str);
void cd(char **str,int i);
void    pwd(char **str);
void mini_env(t_list *env);
void echo(char **str, int j);
void  check_path(char *path,char **str, t_minishell *shell);
t_list *env_list(char **env);
void export(char **str,t_list *list, int i);

/** @todo fix the conflict t_env by t_env_var */
void split_env(t_env_var *env_node, char *str);

void    unset(char **str,t_minishell *shell, int i);
char *check_exist_path(t_list *tmp);
char *check_valid_path(char **ptr, char **str);
int        check_pipe(char **str);

/** @todo fix the conflict c_cmd by t_command */
void pipex(t_cmd command , t_minishell *shell);

int check_builtin(char *str);

int red_out(t_minishell *shell);
void run_builting(char **str,t_minishell *shell, int i);
void check(t_minishell *shell);
int red_in(t_minishell *shell);
int here_doc(t_minishell *shell);
int append_red(t_minishell *shell);
/** ******************************************************* */

/**
 * @attention those are mine DONT TOUCH IT :3
 * @author @lh4j
 */
/** @todo make a doctype for those functions ! */
void	unquote(t_list *lexerlist);
void	extend(t_minishell *shell);

/**
 * @brief print's an error message and clear's the <lexer_list> !
 * @param n mode -1 will raise a Back PIPE error 1 Front !
 * @param lexer_list -
 * @return always 1
 */
int			raise_pipe_error(int n, t_list *lexer_list);

/**
 * @brief making sure we got all quotes closed !
 * @param lineread -
 * @return 1 if there's a quote syntax error 0 otherwise !
 */
int			check_quotes(char const *lineread);

/** @brief some useful bloody tools */

/**
 * @brief turn's a (t_tok) token to a string format
 * e.g: (t_tok)(PIPE = 1) => "PIPE"
 * @param token -
 * @return
 */
char		*stringify_token(t_tok token);

/** @brief put's the prompt " minishell » "
 *
 *	@details i just get the current folder name from the cwd
 *	e.g:
 *		- /nfs/homes/hmouhib/Desktop/.qd/.local/minishell
 *		- i take the last one "/minishell"
 *		- all i need is the folder name "minishell"
 *		- print the prompt " $FOLDER + PROMPT " -> " minishell » "
 *		+ adding some colors :)
 */
void		ms_put_prompt(void);

/// the main parser for our minishell !
int			parser(t_minishell *shell);

/**
 * @brief	this function meant to add a new redirection
 * 			linked list to the parser.redirections
 * 			and increase parser.redirections_count by 1
 * @param 	parser the parser struct !
 * @param 	node => [>]->[file.o]
 */
void		redirection_new(t_parser *parser, t_list *node);

/**
 * @brief initialize the parser struct <t_parser> !
 * @param lexerlst -
 * @param parser_ a pointer to the parser struct
 *                so i can fill it with it's proper values
 */
void		setup_parser_struct(
				t_list *lexerlst,
				t_parser **parser_
				);

/**
 * @brief	check's the lexer list from shell.lexerlst
 * 			for any syntax error's like double pipes, ... etc
 * @param 	shell -
 * @param 	token -
 * @return	1 on error found 0 elsewhere !
 */
int			check_pipe_syntax(
				t_minishell *shell,
				t_tok token
				);

/**
 * @brief	return's a new malloced command <t_command> struct !
 * @param 	argv_ required by the struct ! (arguments data)
 * @param 	redcs required by the struct ! (redirections)
 * @param 	redcs_count required by the struct ! (redirections count !)
 * @return	pointer to the malloced struct !
 */
t_command	*command_new(
				char **argv_,
				t_list *redcs,
				int redcs_count
				);

/** @brief	a few counting functions serve as a utils for the parser */

/**
 * @brief	counts how many pipes we've got !
 * @param 	lexer_list the list to check for pipes !
 * @return	n (pipes count)
 */
int			count_pipes(t_list *lexer_list);

/**
 * @brief	just counting how many args till we reach a PIPE !
 * @param 	lexer_list -
 * @return	n the count !
 */
int			count_args(t_list *lexer_list);

/**
 * @brief	used like a call-back func for ft_lstclear, delone ... etc
 * 			and some lexer cleaning functions
 * @attention only clears t_token content types !
 * @param 	content the data to clear (t_token) !
 */
void		clean_content(void *content);

/**
 * @brief	same as the one above just this one works for cleaning env_var !
 * @attention env_var list only !
 */
void		clear_env(void *content);

/**
 * @brief	this function deletes a single node in
 * 			the first, middle, end of the list !
 * @param 	lexer_list the linked list to delete from
 * @param 	key	the node which holds this key (target) !
 */
void		lexer_delone(t_list **lexer_list, int key);

/**
 * @brief	this function initializes the environment variables list
 * 			(t_minishell->envlst) which it's content holds a struct
 * 			(t_env_var) with two values: env_var's key <key> and it's value <val>
 * @param	envp environment variables
 * @return	a malloced (t_list *)
 */
t_list		*ms_init_env(char **envp);

/**
 * @brief	this function look's for an environment variable by it's key
 * @param	envlst the list to search in
 * @param 	key the key to fetch
 * @return	a char pointer if found else NULL
 */
char		*ms_get_env(
				t_list *envlst,
				char *key
				);

/**
 * @brief	this function adds a t_token node to the lexer list
 * @param	word the string/word (required by the t_token)
 * @param 	token the t_tok token type (required by the t_token)
 * @param	lexer_list the lexer list .
 * @return
 */
int			append_node(
				char *word,
				t_tok token,
				t_list **lexer_list
				);

/**
 * @brief	this function return's the token type (t_tok)
 * @param 	c the char encountered
 * @return
 */
t_tok		get_tok(char c);

/**
 * @brief	just another help function that return's the
 * 			index of str where all spaces are skipped !
 * @param 	str the string
 * @param 	i starting index
 * @return	the number needed to be added to the index (i)
 * 			in order to skip all spaces !
 */
int			ignore_spaces(char *str, int i);

/** @brief token handler's functions . */

/**
 * @brief	this function adds a node to the <lexer_list>
 * 			a node that holds the token string interpretation
 * 			of the token read and it's (t_tok) type !
 * @param	line_read the string to read
 * @param 	i the index where the token is encountered
 * @param	lexer_list the lexer list !
 * @return	the length of the token in order to skip them
 * 			from the caller (i + j) !
 */
int			handle_token(
				char *line_read,
				int i,
				t_list **lexer_list
				);

/**
 * @brief	calculate the character's inside the quotes
 * 			e.g: we have this prompt: `echo "hello world" | grep word`
 * 			here i just want the index i the start quote 5
 * 			it will return 12 .
 * @param 	line_read string to read from
 * @param 	i the starting quote index !
 * @param 	quote <'> | <"> ?
 * @return	j the char's count till the end quote is reached !
 */
int			handle_quotes(
				char *line_read,
				int i,
				char quote
				);

void		tokenize_input(t_minishell *shell);
#endif