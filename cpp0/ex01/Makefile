SRC := Phonebook.cpp Contact.cpp main.cpp

OBJ := $(SRC:.cpp=.o)

NAME := phonebook

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) Phonebook.hpp Contact.hpp
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re