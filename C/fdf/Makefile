# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 09:59:39 by AL                #+#    #+#              #
#    Updated: 2017/02/22 19:01:52 by arlecomt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ft_parsing.c main.c ft_fdf.c ft_trace.c ft_check_map.c ft_projections.c
SRCDIR = ./srcs/

OBJ = $(SRC:.c=.o)

LIBNAME = libft.a
LIBPATH = ./libft/

LIBMLX = ./minilibx_macos/

CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all : $(NAME)

$(NAME) :
	@make -C $(LIBPATH) re
	@make -C $(LIBMLX) re
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tCompilation in progress..."
	@gcc -g -I. -o $(NAME) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(addprefix $(SRCDIR), $(SRC)) $(addprefix $(LIBPATH), $(LIBNAME))
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation completed sucessfully !"

clean :
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for the program \033[1;34m$(NAME)\033[0m"
	@make -C $(LIBPATH) clean
	@make -C $(LIBMLX) clean

fclean : clean
	@$(RM) $(NAME)
	@echo "\t\033[1;31m'FCLEAN' ->\tDestruction\033[0m\tof program \033[1;34m$(NAME)\033[0m"
	@make -C $(LIBPATH) fclean

re : fclean all

cc :
	@echo "\t\033[33m'COMPILE NO FLAGS' ->\t\033[1;34m$(NAME)\033[0m :\tExecutable compilation in progress..."
	@gcc -g -I. -o $(NAME) -lmlx -framework OpenGL -framework AppKit $(addprefix $(SRCDIR), $(SRC)) $(addprefix $(LIBPATH), $(LIBNAME))
	@echo "\t\033[33m'COMPILE NO FLAGS' ->\t\033[1;34m$(NAME)\033[0m :\tCompilation completed sucessfully !"

cc_int :
	@echo "\t\033[33m'COMPILE NO FLAGS' ->\t\033[1;34m$(NAME)\033[0m :\tExecutable compilation in progress..."
	@gcc -g -I. -o $(NAME) -lmlx -framework OpenGL -framework AppKit $(addprefix $(SRCDIR), $(SRC)) $(addprefix $(LIBPATH), $(LIBNAME))
	@echo "\t\033[33m'COMPILE NO FLAGS' ->\t\033[1;34m$(NAME)\033[0m :\tCompilation completed sucessfully !"