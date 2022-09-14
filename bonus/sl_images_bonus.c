/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_images_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:54:40 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/14 23:38:17 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*f(t_data *data, char *file, int *width, int *height)
{
	void	*tmp;

	tmp = mlx_xpm_file_to_image(data->mlx, file, width, height);
	if (!tmp)
	{
		ft_printf("Error\nInvalid image(s).\n");
		sl_free(data);
		exit(EXIT_SUCCESS);
		return (NULL);
	}
	return (tmp);
}

static void	p_mlx_put_image_to_window(t_data *data, void *ptr, int i, int line)
{
	mlx_put_image_to_window(data->mlx, data->window, ptr,
		(i * 48), (line * 48));
}

int	sl_find_images(t_data *data)
{
	data->img_s = f(data, "./images/sky.xpm", &(data->w), &(data->h));
	data->img_0 = f(data, "./images/void.xpm", &(data->w), &(data->h));
	data->img_1 = f(data, "./images/wall.xpm", &(data->w), &(data->h));
	data->img_c = f(data, "./images/coin.xpm", &(data->w), &(data->h));
	data->img_e = f(data, "./images/exit0.xpm", &(data->w), &(data->h));
	data->img_z = f(data, "./images/exitD.xpm", &(data->w), &(data->h));
	data->img_p = f(data, "./images/start.xpm", &(data->w), &(data->h));
	data->img_u_p = f(data, "./images/u_p.xpm", &(data->w), &(data->h));
	data->img_l_p = f(data, "./images/l_p.xpm", &(data->w), &(data->h));
	data->img_d_p = f(data, "./images/d_p.xpm", &(data->w), &(data->h));
	data->img_r_p = f(data, "./images/r_p.xpm", &(data->w), &(data->h));
	data->img_dig = f(data, "./images/dig.xpm", &(data->w), &(data->h));
	return (0);
}

void	sl_player_images(t_data *data, int line, int i)
{
	if (data->map[line][i] == 'Z')
		p_mlx_put_image_to_window(data, data->img_z, i, line);
	if (data->map[line][i] == 'D')
		p_mlx_put_image_to_window(data, data->img_dig, i, line);
	if (data->direction == 0 && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_p, i, line);
	if (data->direction == UP && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_u_p, i, line);
	if (data->direction == LEFT && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_l_p, i, line);
	if (data->direction == DOWN && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_d_p, i, line);
	if (data->direction == RIGHT && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_r_p, i, line);
}

int	sl_images(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[0][i] == '1')
				p_mlx_put_image_to_window(data, data->img_s, i, 0);
			if (data->map[line][i] == '1')
				p_mlx_put_image_to_window(data, data->img_1, i, line);
			if (data->map[line][i] == '0')
				p_mlx_put_image_to_window(data, data->img_0, i, line);
			if (data->c_count > 0 && data->map[line][i] == 'E')
				p_mlx_put_image_to_window(data, data->img_0, i, line);
			if (data->c_count == 0 && data->map[line][i] == 'E')
				p_mlx_put_image_to_window(data, data->img_e, i, line);
			if (data->map[line][i] == 'C')
				p_mlx_put_image_to_window(data, data->img_c, i, line);
			sl_player_images(data, line, i);
		}
	}
	return (0);
}
