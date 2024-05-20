CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
LIB		=	lib/libft/libft.a
INCFILE	=	include/

SRCS	=	src/main.c	\
			src/tokenize/tokenize.c

NAME	=	minishell
OBJS	=	$(SRCS:.c=.o)
RM		=	rm -rf


all: mklib $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) -I include/ $(CFLAGS) $^ -o $@

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
