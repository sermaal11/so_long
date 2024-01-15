/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:27:21 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/10 21:04:18 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_map(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error("Error\n.Error en la apertura de el archivo.\n");
	return (fd);
}
