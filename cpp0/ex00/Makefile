SRC := megaphone.cpp
OBJ := $(SRC:.cpp=.o)
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
NAME := megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re