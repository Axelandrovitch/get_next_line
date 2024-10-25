NAME = get_next_line
CC = cc
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -g
BUFFER_SIZE = 42

SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)


all:	$(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
