NAME = gnl

HEADER = get_next_line.h

LIB = libft

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra
.PHONY : clean fclean re all

SRC = get_next_line.c main.c

OBJ = *.o

all: $(NAME)

$(NAME):
	make -C $(LIB)
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRC)
	$(CC) $(CFLAGS) -I$(HEADER) -L $(LIB) -lft $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIB) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean all
