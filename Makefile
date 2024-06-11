CC		=	cc -g
# CFLAGS	=	-Wall -Wextra -Werror
LIB		=	lib/libft/libft.a
INCFILE	=	include/

SRCS	=	src/main.c src/builtings/builtings.c src/builtings/exit.c src/builtings/cd.c src/builtings/pwd.c src/builtings/env.c src/builtings/export.c src/builtings/echo.c src/builtings/check_path.c src/builtings/env_to_list.c src/builtings/unset.c \
			src/builtings/check_pipe.c src/builtings/pipex.c src/builtings/red_out.c src/builtings/red_in.c
			src/environment/init_env.c	\
			src/environment/env_getter.c	\
			src/tokenization/lexer_utils.c	\
			src/tokenization/token_handlers.c	\
			src/tokenization/tokenize.c	\
			src/utils/lexer_cleaning_utils.c	\
			src/environment/clear_env.c	\
			src/parser/parser.c	\
			src/utils/counting_utils.c	\
			src/parser/parsing_utils.c	\
			src/utils/other_tools.c	\
			src/parser/parsing_quotes.c	\
			src/errors/custom_errors.c	\
			src/expander/expander.c	\
			src/expander/unquote.c

NAME	=	minishell
OBJS	=	$(SRCS:.c=.o)
RM		=	rm -rf


all: mklib $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) -I include/  $(CFLAGS) $^ -o $@ -lreadline

%.o: %.c
	$(CC) -I include/ $(CFLAGS) -c $< -o $@

mklib:
	@make -C lib/libft

clean:
	$(RM) $(OBJS)
	@make -C lib/libft clean

fclean:
	$(RM) $(OBJS) $(NAME)
	@make -C lib/libft fclean

re: fclean all
