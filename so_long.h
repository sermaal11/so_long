/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:16:22 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/15 17:46:30 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

# define BUFFER_SIZE 1000000
# define FLOOR "textures/floor.xpm"
# define WALL "textures/wall.xpm"
# define COIN "textures/coin.xpm"
# define PLAYER "textures/player.xpm"
# define EXIT_CLOSE "textures/exit_close.xpm"
# define EXIT_OPEN "textures/exit_open.xpm"
# define SPRITE_SIZE 100

typedef struct s_game	t_game;

typedef struct s_window {
	void	*mlx;
	void	*win;
	t_game	*game;
}				t_window;

typedef struct s_game
{
	int		x_player;
	int		y_player;
	char	**map;
	int		coin;
	int		steps;
	char	**map_copy;
}				t_game;

void	ft_error(char *str);
int		ft_strlen(const char *str);
int		ft_verify_extension(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	ft_setmap(int fd, t_game *game);
void	ft_init_map_verify(t_window *window, char **map);
int		ft_strlen_vert(char **map);
int		ft_count_objects(char **map, int c);
char	**ft_flooder_player(t_game *game, char **map);
char	**ft_flood_map(int row, int col, char **map);
void	ft_initialize_mlx(t_window *window, char **new_map);
int		ft_open_map(char *str);
void	ft_check_components(char **map);
int		ft_close_window(t_window *window);
int		key_hook(int keycode, t_window *window);
void	ft_print_sprites(t_window *window, char **map);
void	ft_move_up(t_window *window);
void	ft_move_right(t_window *window);
void	ft_move_down(t_window *window);
void	ft_move_left(t_window *window);
void	ft_putnbr(int n);

#endif