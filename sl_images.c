/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:54:40 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/28 21:32:57 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*f(void *mlx, char *file, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, file, width, height));
}

static void	p_mlx_put_image_to_window(t_data *data, void *ptr, int i, int line)
{
	mlx_put_image_to_window(data->mlx, data->window, ptr,
		(i * 48), (line * 48));
}

int	sl_find_images(t_data *data)
{
	data->img_0 = f(data->mlx, "./images/void.xpm", &(data->w), &(data->h));
	data->img_1 = f(data->mlx, "./images/wall.xpm", &(data->w), &(data->h));
	data->img_e = f(data->mlx, "./images/exit.xpm", &(data->w), &(data->h));
	data->img_c = f(data->mlx, "./images/coin.xpm", &(data->w), &(data->h));
	data->img_p = f(data->mlx, "./images/r_w1.xpm", &(data->w), &(data->h));
	return (0);
}

int	sl_images(t_data *data)
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
				p_mlx_put_image_to_window(data, data->img_0, i, line);
			if (data->map[line][i] == '1')
				p_mlx_put_image_to_window(data, data->img_1, i, line);
			if (data->c_count > 0 && data->map[line][i] == 'E')
				p_mlx_put_image_to_window(data, data->img_1, i, line);
			if (data->c_count == 0 && data->map[line][i] == 'E')
				p_mlx_put_image_to_window(data, data->img_e, i, line);
			if (data->map[line][i] == 'C')
				p_mlx_put_image_to_window(data, data->img_c, i, line);
			if (data->map[line][i] == 'P')
				p_mlx_put_image_to_window(data, data->img_p, i, line);
		}
	}
	return (0);
}
