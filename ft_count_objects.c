/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:23:56 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/11 12:47:45 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_objects(char **map, int c)
{
	int	row;
	int	col;
	int	count;

	row = 0;
	count = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == c)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

void	ft_check_components(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if ((map[row][col] != '1') && (map[row][col] != '0') &&
				(map[row][col] != 'P') && (map[row][col] != 'E') &&
				(map[row][col] != 'C'))
				ft_error("Error.\nMapa invalido.\n");
			col++;
		}
		row++;
	}
}
