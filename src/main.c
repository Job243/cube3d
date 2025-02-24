/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:39:54 by jmafueni          #+#    #+#             */
/*   Updated: 2025/02/24 19:05:26 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_path(char *line, t_data *data, int index)
{
	int	i;

	i = 0;
	while (is_space(line))
		i++;
	if (index == 1)
		data->path_no = ft_strdup(&line[i]);
	else if (index == 2)
		data->path_so = ft_strdup(&line[i]);
	else if (index == 3)
		data->path_we = ft_strdup(&line[i]);
	else if (index == 4)
		data->path_ea = ft_strdup(&line[i]);
}

void	copy_color(char *line, t_data *data, int index)
{
	char	**tab;
	int		i;

	i = 0;
	while (is_space(line))
		i++;
	tab = ft_split(&line[i], ',');
	if (index == 1)
		data->floor_color = tab;
	else
		data->sky_color = tab;
}

int	check_line(char *line, t_data *data, int *ptr)
{
	if (!ft_strncmp("NO", line, 2) && data->path_no == NULL)
		copy_path(line + 2, data, 1);
	else if (!ft_strncmp("SO", line, 2) && data->path_so == NULL)
		copy_path(line + 2, data, 2);
	else if (!ft_strncmp("WE", line, 2) && data->path_we == NULL)
		copy_path(line + 2, data, 3);
	else if (!ft_strncmp("EA", line, 2) && data->path_ea == NULL)
		copy_path(line + 2, data, 4);
	else if (!ft_strncmp("F", line, 1) && data->floor_color == NULL)
		copy_color(line + 1, data, 1);
	else if (!ft_strncmp("C", line, 1) && data->sky_color == NULL)
		copy_color(line + 1, data, 2);
	else
		return (1);
	*ptr++;
	return (0);
}

int	check_file(int fd, t_data *data)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] && check_line(line, data, &count))
			return (1);
		free(line);
		if (count == 6)
			break ;
		line = get_next_line(fd);
	}
	if (!data->path_no || !data->path_so || !data->path_we || !data->path_ea
		|| !data->sky_color || !data->floor_color)
		return (1);
	copy_map(fd, data);
	return (!(!check_color_value(data->sky_color)
			&& !check_color_value(data->floor_color)));
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	ft_memset(&data, 0, sizeof(data));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	if (check_file(fd, &data))
		clear_cub3d(&data);
}
