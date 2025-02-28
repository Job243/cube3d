/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:56:40 by jmafueni          #+#    #+#             */
/*   Updated: 2025/02/27 14:28:55 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;

typedef struct s_game
{
	int	player_pos_x;
	int	player_pos_y;
}	t_game;

typedef struct s_data
{
	char	**map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	**sky_color;
	int		sky_r;
	int		sky_g;
	int		sky_b;
	char	**floor_color;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	char	*path_floor;
	char	*path_wall;
	void	*img_floor;
	void	*img_wall;
	t_game	*game;
	t_vars	*vars;
}	t_data;

int		clear_cub3d(t_data *data);
int		check_color_value(t_data *data);
int		empty_line(char *s);
int		ft_tabsize(char **tab);
int		is_space(char c);
int		little_ft_atoi(char *s);
int		map_closed_inside(char **map, int begin, int end);
int		map_error(const char *message, t_data *data);

void	copy_map(int fd, t_data *data);

#endif
