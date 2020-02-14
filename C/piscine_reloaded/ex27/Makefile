.PHONY : all clean fclean re
NAME = ft_display_file
CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = ft_display_file.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -fv $(OBJ)

fclean : clean
	rm -fv $(NAME)

re : fclean all