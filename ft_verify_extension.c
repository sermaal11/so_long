/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:37:21 by smarin-a          #+#    #+#             */
/*   Updated: 2024/01/14 20:44:41 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verify_extension(const char *str)
{
	int		len;
	int		i;
	char	*ext;

	i = 1;
	ext = ".ber";
	len = ft_strlen(str);
	while (i <= 4)
	{
		if (str[len - i] != *(ext + (4 - i)))
			ft_error("Error\n.Extension invalida.\n");
		i++;
	}
	return (0);
}
