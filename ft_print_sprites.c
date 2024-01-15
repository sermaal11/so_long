/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:23:36 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/11 23:02:37 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_create_image(t_window *window, char *str)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(window->win, str, &width, &height);
	if (!img)
		ft_error("Error\n.Error al crear el sprite.\n");
	return (img);
}

void	ft_print_sprites(t_window *window, char **map)
{
	int		row;
	int		col;
	void	*img;

	row = -1;
	while (map[++row] != NULL)
	{
		col = -1;
		while (map[row][++col] != '\0')
		{
			if (map[row][col] == '0')
				img = ft_create_image(window, FLOOR);
			if (map[row][col] == '1')
				img = ft_create_image(window, WALL);
			if (map[row][col] == 'C')
				img = ft_create_image(window, COIN);
			if (map[row][col] == 'P')
				img = ft_create_image(window, PLAYER);
			if (map[row][col] == 'E')
				img = ft_create_image(window, EXIT_CLOSE);
			mlx_put_image_to_window(window->mlx, window->win, img,
				col * SPRITE_SIZE, row * SPRITE_SIZE);
		}
	}
}
