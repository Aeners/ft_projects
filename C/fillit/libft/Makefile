# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 14:02:14 by arlecomt          #+#    #+#              #
#    Updated: 2016/11/08 14:02:15 by arlecomt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re
NAME = libft.a
SRC = 	ft_atoi.c 			\
		ft_bzero.c			\
		ft_isalnum.c 		\
		ft_isalpha.c 		\
		ft_isascii.c 		\
		ft_isdigit.c 		\
		ft_isprint.c 		\
		ft_itoa.c 			\
		ft_memalloc.c 		\
		ft_memccpy.c 		\
		ft_memchr.c 		\
		ft_memcmp.c 		\
		ft_memcpy.c 		\
		ft_memdel.c 		\
		ft_memmove.c 		\
		ft_memset.c 		\
		ft_putchar.c 		\
		ft_putchar_fd.c 	\
		ft_putendl.c 		\
		ft_putendl_fd.c 	\
		ft_putnbr.c 		\
		ft_putnbr_fd.c 		\
		ft_putstr.c 		\
		ft_putstr_fd.c 		\
		ft_strcat.c 		\
		ft_strchr.c 		\
		ft_strclr.c 		\
		ft_strcmp.c 		\
		ft_strcpy.c 		\
		ft_strdel.c 		\
		ft_strdup.c 		\
		ft_strequ.c 		\
		ft_striter.c 		\
		ft_striteri.c 		\
		ft_strjoin.c 		\
		ft_strlcat.c 		\
		ft_strlen.c 		\
		ft_strmap.c 		\
		ft_strmapi.c 		\
		ft_strncat.c 		\
		ft_strncmp.c 		\
		ft_strncpy.c 		\
		ft_strnequ.c 		\
		ft_strnew.c 		\
		ft_strnstr.c 		\
		ft_strrchr.c 		\
		ft_strsplit.c 		\
		ft_strstr.c 		\
		ft_strsub.c 		\
		ft_strtrim.c 		\
		ft_tolower.c 		\
		ft_toupper.c		\
		ft_lstnew.c			\
		ft_lstdelone.c		\
		ft_lstdel.c			\
		ft_lstadd.c			\
		ft_lstmap.c			\
		ft_lstiter.c
HEADERFLAGS = -I libft.h
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ = $(SRC:.c=.o)
RM = rm -f

all : $(NAME)

$(NAME) :
			@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation in progress..."
			@$(CC) -c $(CFLAGS) $(SRC) $(HEADERFLAGS)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m : Library compilation completed successfully !"

compile :
			@$(CC) $(CFLAGS) $(SRC) $(HEADERFLAGS)

clean :
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for the library \033[1;34m$(NAME)\033[0m"
	@$(RM) $(OBJ)
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for the library \033[1;34m$(NAME)\033[0m completed successfully !"

fclean : clean
	@$(RM) $(NAME)
	@echo "\t\033[1;31m'FCLEAN' ->\tDestruction\033[0m of library \033[1;34m$(NAME)\033[0m completed successfully !"

re : fclean all