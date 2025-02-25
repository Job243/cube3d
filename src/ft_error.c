/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:29:53 by jmafueni          #+#    #+#             */
/*   Updated: 2025/02/25 17:30:31 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_vars(t_data *data)
{
	if (data->game)
	{
		free(data->game);
		data->game = NULL;
	}
	if (data->vars)
	{
		free(data->vars);
		data->vars = NULL;
	}
}

int	exit_game(t_data *data)
{
	free_images(data);
	if (data->vars)
	{
		if (data->vars->mlx_ptr && data->vars->win_ptr)
			mlx_destroy_window(data->vars->mlx_ptr, data->vars->win_ptr);
		if (data->vars->mlx_ptr)
		{
			mlx_destroy_display(data->vars->mlx_ptr);
			free(data->vars->mlx_ptr);
		}
	}
	ft_free(data->map);
	data->map = NULL;
	free_vars(data);
	exit(0);
	return (0);
}
