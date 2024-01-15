/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiaize_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:23:38 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/11 12:05:24 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_mlx(t_window *window, char **new_map)
{
	int	row;
	int	col;

	row = ft_strlen_vert(new_map);
	col = ft_strlen(new_map[0]);
	window->mlx = mlx_init();
	if (!window->mlx)
		ft_error("Error\n.Error al inicializar la conexión gráfica.\n");
	window->win = mlx_new_window(window->mlx,
			col * SPRITE_SIZE, row * SPRITE_SIZE, "THE GAME");
	if (!window->win)
		ft_error("Error\n.Error al crear la ventana.\n");
}
