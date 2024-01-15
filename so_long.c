/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:31:17 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/11 12:34:37 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_window	window;
	t_game		game;

	if (argc == 2)
	{
		ft_verify_extension(argv[1]);
		fd = ft_open_map(argv[1]);
		ft_setmap(fd, &game);
		window.game = &game;
		ft_init_map_verify(&window, game.map_copy);
		ft_initialize_mlx(&window, game.map);
		ft_print_sprites(&window, game.map);
		window.game->steps = 0;
		mlx_key_hook(window.win, key_hook, &window);
		mlx_hook(window.win, 17, 0, ft_close_window, &window);
		mlx_loop(window.mlx);
		close(fd);
	}
	return (0);
}
