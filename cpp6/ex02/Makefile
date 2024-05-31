SRCS := main.cpp \
		A.cpp \
		B.cpp \
		C.cpp \
		Base.cpp \
		funcs.cpp

OBJS := $(SRCS:.cpp=.o)

NAME := convert

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp funcs.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re