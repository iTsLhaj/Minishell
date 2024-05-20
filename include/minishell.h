#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdlib.h>
# include <types.h>
# include <stdio.h>

t_lexter	*ms_parse_input(char *lineread);
void		h_list_parsedin(t_lexter *parsed_input);

#endif
