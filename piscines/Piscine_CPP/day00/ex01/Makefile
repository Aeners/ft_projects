NAME=bestPhoneBookEva

CXX=clang++
RM=rm -rfv
CXXFLAGS=-Wall -Wextra -Werror

SRC_PATH=src/
OBJ_PATH=obj/

SRC_NAME=main.cpp PhoneBook.class.cpp
OBJ_NAME=$(subst .cpp,.o,$(SRC_NAME))

SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re