NAME = get_next_line
CC = cc
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -g
BUFFER_SIZE = 42

SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)

BONUS_NAME = get_next_line_bonus
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)


all:	$(NAME)

$(NAME) : $(OBJ) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
bonus: $(BONUS_OBJ) Makefile
	$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)


clean:
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
