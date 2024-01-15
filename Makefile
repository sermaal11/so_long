# Nombre del programa de salida
NAME = so_long

# Norma de compilación
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

# Fuentes .c
SRCS =	so_long.c \
		ft_error.c \
		ft_split.c \
		ft_strlen.c \
		ft_substr.c \
		ft_verify_extension.c \
		ft_setmap.c \
		ft_init_map_verify.c \
		ft_strlen_vert.c \
		ft_count_objects.c \
		ft_flooder_player.c \
		ft_flood_map.c \
		ft_initiaize_mlx.c \
		ft_open_map.c \
		ft_window.c \
		ft_print_sprites.c \
		ft_move_player.c \
		ft_putnbr.c 
# Ruta a la mlx

MLX = ./mlx/libmlx.a

# Normas que convierten los .c en .o
OBJS = $(SRCS:.c=.o)

# Regla principal para construir el programa principal
all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Regla para compilar archivos .c en objetos .o
%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

# REgla MLX

$(MLX) :
	make -C ./mlx

# Regla para limpiar archivos objeto (.o)
clean:
	rm -f *.o
	make clean -C ./mlx

# Regla para limpiar archivos objeto y el programa de salida
fclean: clean
	rm -f $(NAME)

# Regla para limpiar y reconstruir todo
re: fclean all

# Indica que estas reglas no corresponden a archivos reales
.PHONY : clean fclean re #bonus

