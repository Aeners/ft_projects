.PHONY : all clean fclean re
NAME = libft.a
SRC_PATH = srcs/
SRC_NAME =	ft_putchar.c \
			ft_putstr.c \
			ft_strcmp.c \
			ft_strlen.c \
			ft_swap.c
OBJ_PATH = obj/
HEADERFLAGS = -I includes/
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

all : $(NAME)

$(NAME) :
			$(CC) -c $(CFLAGS) $(SRC) $(HEADERFLAGS)
			ar rc $(NAME) $(OBJ_NAME)
			ranlib $(NAME)

clean :
	rm -fv $(OBJ_NAME)

fclean : clean
	rm -fv $(NAME)

re : fclean all
