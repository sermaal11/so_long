/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:53:32 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/10 23:33:22 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_window *window)
{
	if (keycode == 53)
		ft_close_window(window);
	else if (keycode == 13 || keycode == 126)
		ft_move_up(window);
	else if (keycode == 2 || keycode == 124)
		ft_move_right(window);
	else if (keycode == 1 || keycode == 125)
		ft_move_down(window);
	else if (keycode == 0 || keycode == 123)
		ft_move_left(window);
	return (0);
}
