/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:08:02 by jmafueni          #+#    #+#             */
/*   Updated: 2025/02/27 15:41:48 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	file_to_image(t_data *data)
{
	int	height;
	int	width;

	data->path_wall = "images/img_wall.xpm";
	data->path_floor = "images/img_floor.xpm";
	data->img_wall = mlx_xpm_file_to_image(data->vars->mlx_ptr,
			data->path_wall, &width, &height);
	data->img_floor = mlx_xpm_file_to_image(data->vars->mlx_ptr,
			data->path_floor, &width, &height);
	if (!data->img_floor || !data->img_wall)
	{
		clear_cub3d(data);
		exit(0);
	}
}

int	little_ft_atoi(char *s)
{
	int	i;
	int	value;

	i = 0;
	while (is_space(s[i]))
		i++;
	if (!ft_isdigit(s[i]))
		return (-1);
	while (ft_isdigit(s[i]))
	{
		if (!ft_isdigit(s[i]))
			return (-1);
		value = value * 10 + s[i] - 48;
		i++;
	}
	if (value > 255)
		return (-1);
	return (value);
}

int	check_color_value(t_data *data)
{
	int	i;

	i = 0;
	if (ft_tabsize(data->floor_color) != 4 || ft_tabsize(data->sky_color) != 4)
		return (1);
	while (data->floor_color[i])
	{
		data->floor_r = little_ft_atoi(data->floor_color[i++]);
		data->floor_g = little_ft_atoi(data->floor_color[i++]);
		data->floor_b = little_ft_atoi(data->floor_color[i++]);
	}
	while (data->sky_color[i])
	{
		data->sky_r = little_ft_atoi(data->sky_color[i++]);
		data->sky_g = little_ft_atoi(data->sky_color[i++]);
		data->sky_b = little_ft_atoi(data->sky_color[i++]);
	}
	if (!data->floor_r || !data->floor_g || !data->floor_b
		|| !data->sky_r || !data->sky_g || !data->sky_b)
		return (1);
	return (0);
}
