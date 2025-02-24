/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:08:02 by jmafueni          #+#    #+#             */
/*   Updated: 2025/02/24 19:00:48 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	return (0);
}
