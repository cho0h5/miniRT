NAME	=	miniRT

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -Ilibft

SRC_DIR	=	./src/
SRCS	=	$(SRC_DIR)main.c
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $^ -Llibft -lft

libft/libft.a:
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re:
	make fclean
	make all

test: all
	./miniRT

.PHONY: all clean fclean re test
