# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrison <abrison@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by abrison           #+#    #+#              #
#    Updated: 2015/10/28 14:16:38 by abrison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLIT = fillit
NAME = $(FILLIT)
LIBFT = libft.a
GCC_FLAGS = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAGS)
RM = rm -rf

SRCS = fillib.c \
	  special_test.c \
	  fillst.c \
	  main.c \
	  launcher.c \
	  prelauncher.c \
	  resolve.c \
	  save_reset.c 

SRCDIR = .
OBJDIR = .
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -Llibft $(OBJS) -lft -o $(NAME)
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m : $(NAME) compilation completed successfully !"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $^

$(LIBFT):
	@make -C ./libft/

clean:
	@$(RM) $(OBJS)
	@make clean -C ./libft/
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o of $(NAME) \033[1;34m$(NAME)\033[0m completed successfully !"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@make fclean -C ./libft/

re: fclean all