/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:54:40 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/26 21:19:25 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_put_images(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->void_image, (line * 33), (i * 37));
			if (data->map[line][i] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_image, (line * 33), (i * 37));
			if (data->map[line][i] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_image, (line * 33), (i * 37));
			if (data->map[line][i] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->coll_image, (line * 33), (i * 37));
			if (data->map[line][i] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->play_image, (line * 33), (i * 37));
		}
	}
}