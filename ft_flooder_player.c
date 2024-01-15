/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flooder_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:06:18 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/10 16:21:28 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_flooder_player(t_game *game, char **map)
{
	int		row;
	int		col;
	char	**map_flooded;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
			{
				game->x_player = col;
				game->y_player = row;
				map_flooded = ft_flood_map(row, col, map);
			}
			col++;
		}
		row++;
	}
	return (map_flooded);
}
