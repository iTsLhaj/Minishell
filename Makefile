NAME		=	minishell
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
LIBFT		=	lib/libft/libft.a
LIBFT_P		=	lib/libft
SRC_FILES	=	src/main.c					\
				src/misc/ms_prompt.c		\
				src/env/ms_init_env.c		\
				src/env/ms_envlst_new.c		\
				src/env/ms_envlst_getter.c	\
				src/tokenize/ms_tokutils.c	\
				src/tokenize/ms_tokenize.c
INCLUDE		=	include/
OBJ_FILES	=	$(SRC_FILES:.c=.o)
GREEN		=	\033[0;32m
BLUE		=	\033[0;34m
RESET		=	\033[0m
RM			=	rm -rf

all: build_libft $(NAME)

build_libft:
	@echo " - $(GREEN)Compiling $(BLUE)LIBFT ...$(RESET)"
	@make -s -C $(LIBFT_P)
	@echo " - $(GREEN)Done !$(RESET)"

$(NAME): $(OBJ_FILES) $(LIBFT)
	@echo " - $(GREEN)Building $(BLUE)Minishell ...$(RESET)"
	@$(CC) -I include/ $(CFLAGS) $^ -o $@ -lreadline
	@echo " - $(GREEN)Done !$(RESET)"

%.o: %.c
	@$(CC) -I include/ $(CFLAGS) -c $< -o $@

clean:
	@echo " - $(BLUE)Cleaning ...$(RESET)"
	@make -s -C $(LIBFT_P) clean
	@$(RM) $(OBJ_FILES)
	@echo " - $(GREEN)Done !$(RESET)"

fclean:
	@echo " - $(BLUE)Cleaning ...$(RESET)"
	@make -s -C $(LIBFT_P) fclean
	@$(RM) $(OBJ_FILES) $(NAME)
	@echo " - $(GREEN)Done !$(RESET)"
