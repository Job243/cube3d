/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:35:12 by jmafueni          #+#    #+#             */
/*   Updated: 2025/02/27 19:07:50 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	copy_map(int fd, t_data *data)
{
	int		i;
	char	*line_map;

	line_map = get_next_line(fd);
	i = 0;
	while (line_map)
	{
		data->map[i] = ft_strdup(line_map);
		i++;
		free(line_map);
		line_map = get_next_line(fd);
	}
}

int	check_map_name(char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (len <= 4 || len - 1 != 'b' || len - 2 != 'u' || len - 3 != 'c'
		|| len - 4 != '.')
		return (1);
	return (0);
}

int	check_map_in(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (empty_line(map[y]))
		y++;
	while (map[y])
	{
		if (empty_line(map[y]))
			break ;
		x = 0;
		while (map[y][x])
		{
			while (is_space(map[y][x]))
				x++;
			if (!map[y][x] || (map[y][x] != '0' && map[y][x] != '1'
					&& map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] 
						!= 'E' && map[y][x] != 'W' && is_space(map[x][y])))
				return (1);
			x++;
		}
		y++;
	}
	
	return (0);
}

int	check_map_closed(char **map, int cols, int rows)
{
	int	i;
	int	begin;
	int	end;

	if (!map || cols < 2 || rows < 2)
		return (0);
	begin = 0;
	while (empty_line(map[begin]))
		begin++;
	end = begin;
	while (!empty_line(map[end]))
		end++;
	while (i < cols)
	{
		if ((map[begin][i] != '1' && !is_space(map[begin][i]))
		|| (map[end - 1][i] != '1' && !is_space(map[end - 1][i])))
			return (0);
		i++;
	}
	if (!map_closed_inside(map, begin, end))
		return (0);
	return (1);
}
