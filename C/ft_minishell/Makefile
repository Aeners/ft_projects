# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 14:59:20 by arlecomt          #+#    #+#              #
#    Updated: 2017/04/29 17:53:51 by arlecomt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
NAME = minishell

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libft/

SRCS_LIST = main.c exec.c minishell.c ft_cd.c ft_exit.c ft_echo.c \
			env_func.c ft_env.c freefunc.c modif_env.c
SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR = objs/
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))
HEADERS = -I./libft -I./includes
LIBS = -L./libft -lft

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIB_PATH)
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tCompilation in progress..."
	@$(CC) -g $(CFLAGS) $^ $(LIBS) -o $@
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tBinary created."

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) -g $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tCompilation done!"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for the program \033[1;34m$(NAME)\033[0m"
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@echo "\t\033[1;3m'FCLEAN' ->\tDestruction\033[0m\tof program \033[1;34m$(NAME)\033[0m"
	@make -C $(LIB_PATH) fclean

re: fclean all

norme:
	@make -C $(LIB_PATH) norme
	@echo "\t\033[1;33m'NORME' ->\tChecking Norme \033[0m\tof project \033[1;34m$(NAME)\033[0m"
	@norminette $(SRCS) includes/
