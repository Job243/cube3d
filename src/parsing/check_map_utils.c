/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:36:19 by jmafueni          #+#    #+#             */
/*   Updated: 2025/02/24 17:46:17 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floodfill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] ||
		x >= (int)ft_strlen(map[y]) || map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	floodfill(map, x + 1, y, game);
	floodfill(map, x - 1, y, game);
	floodfill(map, x, y + 1, game);
	floodfill(map, x, y - 1, game);
}



int	map_closed_inside(char **map, int begin, int end)
{
	int	x;
	int	y;
	int	len;

	y = begin + 1;
	while (y < end)
	{
		while (map[y])
		{
			x = 0;
			while (is_space(map[y][x]))
				x++;
			len = ft_strlen(map[y][x]) - 1;
			if (map[y][x] != '1' || map[y][len - 1] != '1')
				return (0);
		}
		y++;
	}
	return (1);
}
