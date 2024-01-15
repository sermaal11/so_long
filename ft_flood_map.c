/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:49:43 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/10 16:19:33 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_flood_map(int row, int col, char **map)
{
	if (map[row][col] == 'E')
	{
		map[row][col] = '1';
		return (map);
	}
	map[row][col] = '1';
	if (map[row - 1][col] != '1')
		ft_flood_map(row - 1, col, map);
	if (map[row][col + 1] != '1')
		ft_flood_map(row, col + 1, map);
	if (map[row + 1][col] != '1')
		ft_flood_map(row + 1, col, map);
	if (map[row][col - 1] != '1')
		ft_flood_map(row, col - 1, map);
	return (map);
}
