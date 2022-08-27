/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:54:40 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/27 15:41:20 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_find_images(t_data *data)
{
	data->void_image = mlx_xpm_file_to_image(data->mlx, "./images/void.xpm", &(data->w), &(data->h));
	data->wall_image = mlx_xpm_file_to_image(data->mlx, "./images/wall.xpm", &(data->w), &(data->h));
	data->exit_image = mlx_xpm_file_to_image(data->mlx, "./images/exit.xpm", &(data->w), &(data->h));
	data->coll_image = mlx_xpm_file_to_image(data->mlx, "./images/coin.xpm", &(data->w), &(data->h));
	data->play_image = mlx_xpm_file_to_image(data->mlx, "./images/r_w1.xpm", &(data->w), &(data->h));
}

void	sl_put_images(t_data *data)
{
	int	line;
	int	i;

	sl_find_images(data);
	line = -1;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->void_image, (i * 48), (line * 48));
			if (data->map[line][i] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_image, (i * 48), (line * 48));
			if (data->map[line][i] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_image, (i * 48), (line * 48));
			if (data->map[line][i] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->coll_image, (i * 48), (line * 48));
			if (data->map[line][i] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->play_image, (i * 48), (line * 48));
		}
	}
}