/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_verify.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:55:41 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/10 21:03:42 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_verify_rectangle(char **map)
{
	int	row;
	int	len;

	row = 0;
	len = ft_strlen(map[0]);
	while (map[row] != NULL)
	{
		if (len != ft_strlen(map[row]))
			ft_error("Error.\nMapa invallido.\n");
		row++;
	}
}

static void	ft_verify_wall(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[0][col] != '1' || map[ft_strlen_vert(map) - 1][col] != '1')
				ft_error("Error\n.Mapa invalido.\n");
			if (map[row][0] != '1' || map[row][ft_strlen(map[row]) - 1] != '1')
				ft_error("Error\n.Mapa invalido.\n");
			col++;
		}
		row++;
	}
}

static void	ft_verify_objects(char **map, t_window *window)
{
	int		c;
	int		e;
	int		p;

	ft_check_components(map);
	c = ft_count_objects(map, 'C');
	window->game->coin = c;
	e = ft_count_objects(map, 'E');
	p = ft_count_objects(map, 'P');
	if (c < 1)
		ft_error("Error\n.Mapa invalido.\n");
	if (e != 1)
		ft_error("Error\n.Mapa invalido.\n");
	if (p != 1)
		ft_error("Error\n.Mapa invalido.\n");
}

static void	ft_verify_path(t_game *game, char **map)
{
	char	**map_flooded;
	int		c;
	int		e;

	map_flooded = ft_flooder_player(game, map);
	c = ft_count_objects(map_flooded, 'C');
	if (c != 0)
		ft_error("Error\n.Mapa invalido.\n");
	e = ft_count_objects(map_flooded, 'E');
	if (e != 0)
		ft_error("Error\n.Mapa invalido.\n");
}

void	ft_init_map_verify(t_window *window, char **map)
{
	ft_verify_rectangle(map);
	ft_verify_wall(map);
	ft_verify_objects(map, window);
	ft_verify_path(window->game, map);
}
