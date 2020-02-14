NAME=account.exe

CXX=clang++
RM=rm -rfv
CXXFLAGS=-Wall -Wextra -Werror

SRC_PATH=src/
OBJ_PATH=obj/

HEADER_FILE=Account.class.hpp
SRC_NAME=tests.cpp Account.class.cpp
OBJ_NAME=$(subst .cpp,.o,$(SRC_NAME))

SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))

YELLOW=\033[1;33m
NC=\033[0m

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
	$(RM) test.log

re: fclean all

compex: all
	./$(NAME) > test.log
	@echo "$(YELLOW)=================OUTPUT FILE=================$(NC)"
	@cat test.log

exe: $(NAME)
	@echo "$(YELLOW)=================OUTPUT=================$(NC)"
	@./$(NAME)

.PHONY: all, clean, fclean, re