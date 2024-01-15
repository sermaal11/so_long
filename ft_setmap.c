/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:02:31 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/11 12:23:08 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_setmap(int fd, t_game *game)
{
	char	*line_map;
	ssize_t	map_len;
	char	**map;
	char	**map_copy;

	line_map = (char *)malloc(BUFFER_SIZE * sizeof(char));
	map_len = read(fd, line_map, BUFFER_SIZE);
	line_map[map_len] = '\0';
	map = ft_split(line_map, '\n');
	map_copy = ft_split(line_map, '\n');
	if (map == NULL || map_copy == NULL)
		ft_error("Error\n.No es posible hacer el split.\n");
	game->map = map;
	game->map_copy = map_copy;
	free(line_map);
	line_map = NULL;
}
