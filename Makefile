NAME	=	miniRT

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -Iinclude -Ilibft -fsanitize=address -g
LDFLAGS	=	-Llibft -lft

SRC_DIR	=	./src/

SRCS	=	$(SRC_DIR)main.c				\
			$(SRC_DIR)panic.c				\
			$(SRC_DIR)parse.c				\
			$(SRC_DIR)parse_line.c			\
			$(SRC_DIR)parse_identifier.c	\
			$(SRC_DIR)parse_ambient.c		\
			$(SRC_DIR)parse_light.c			\
			$(SRC_DIR)parse_camera.c		\
			$(SRC_DIR)parse_object.c		\
			$(SRC_DIR)environment.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $^

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
	./miniRT testcase/testcase1.rt

.PHONY: all clean fclean re test
