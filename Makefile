NAME	=	miniRT

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -Iinclude -Ilibft -O3 -fsanitize=address -g
LDFLAGS	=	-Llibft -lft -lmlx -framework OpenGL -framework Appkit

SRC_DIR	=	./src/

SRCS	=	$(SRC_DIR)main.c						\
			$(SRC_DIR)panic.c						\
			$(SRC_DIR)vector3.c						\
			$(SRC_DIR)vector3_print.c				\
			$(SRC_DIR)vector3_add.c					\
			$(SRC_DIR)vector3_angle.c				\
			$(SRC_DIR)vector3_cross.c				\
			$(SRC_DIR)vector3_dot.c					\
			$(SRC_DIR)vector3_magnitude.c			\
			$(SRC_DIR)vector3_normalize.c			\
			$(SRC_DIR)vector3_scale.c				\
			$(SRC_DIR)vector3_subtract.c			\
			$(SRC_DIR)vector3_scale.c				\
			$(SRC_DIR)vector3_rotate.c				\
			$(SRC_DIR)vector3_to_color.c			\
			$(SRC_DIR)vector3_multiply.c			\
			$(SRC_DIR)vector_char.c					\
			$(SRC_DIR)vector_char_push_str.c		\
			$(SRC_DIR)parse.c						\
			$(SRC_DIR)parse_line.c					\
			$(SRC_DIR)parse_word.c					\
			$(SRC_DIR)parse_identifier.c			\
			$(SRC_DIR)parse_ambient.c				\
			$(SRC_DIR)parse_light.c					\
			$(SRC_DIR)parse_camera.c				\
			$(SRC_DIR)parse_object.c				\
			$(SRC_DIR)parse_plane.c					\
			$(SRC_DIR)parse_sphere.c				\
			$(SRC_DIR)parse_cylinder.c				\
			$(SRC_DIR)parse_utils.c					\
			$(SRC_DIR)parse_decimal.c				\
			$(SRC_DIR)parse_vector3.c				\
			$(SRC_DIR)parse_comma.c					\
			$(SRC_DIR)parse_newline.c				\
			$(SRC_DIR)object_ambient_print.c		\
			$(SRC_DIR)object_camera_print.c			\
			$(SRC_DIR)object_light_print.c			\
			$(SRC_DIR)object_print.c				\
			$(SRC_DIR)object_plane_print.c			\
			$(SRC_DIR)object_sphere_print.c			\
			$(SRC_DIR)object_cylinder_print.c		\
			$(SRC_DIR)object_get_closest.c			\
			$(SRC_DIR)object_distance.c				\
			$(SRC_DIR)object_plane_distance.c		\
			$(SRC_DIR)object_sphere_distance.c		\
			$(SRC_DIR)object_cylinder_distance.c	\
			$(SRC_DIR)object_color.c				\
			$(SRC_DIR)object_plane_color.c			\
			$(SRC_DIR)object_sphere_color.c			\
			$(SRC_DIR)object_cylinder_color.c		\
			$(SRC_DIR)object_is_shadow.c			\
			$(SRC_DIR)screen_pixel_to_ray.c			\
			$(SRC_DIR)screen_draw.c					\
			$(SRC_DIR)screen_destroy.c				\
			$(SRC_DIR)screen_key_hook.c				\
			$(SRC_DIR)environment.c					\
			$(SRC_DIR)environment_get_camera.c		\
			$(SRC_DIR)environment_get_light.c		\
			$(SRC_DIR)environment_get_ambient.c		\
			$(SRC_DIR)equation_closest_point_on_skew_lines.c

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
