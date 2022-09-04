/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:54:40 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/04 16:06:15 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*f(void *mlx, char *file, int *width, int *height)
{
	void	*tmp;

	tmp = mlx_xpm_file_to_image(mlx, file, width, height);
	if (!tmp)
	{
		ft_printf("Error\nInvalid image(s).\n");
		free(mlx);
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
	data->img_s = f(data->mlx, "./images/sky.xpm", &(data->w), &(data->h));
	data->img_0 = f(data->mlx, "./images/void.xpm", &(data->w), &(data->h));
	data->img_1 = f(data->mlx, "./images/wall.xpm", &(data->w), &(data->h));
	data->img_x = f(data->mlx, "./images/rock.xpm", &(data->w), &(data->h));
	data->img_e = f(data->mlx, "./images/exit.xpm", &(data->w), &(data->h));
	data->img_c = f(data->mlx, "./images/coin.xpm", &(data->w), &(data->h));
	data->img_p = f(data->mlx, "./images/start.xpm", &(data->w), &(data->h));
	data->img_u_p = f(data->mlx, "./images/u_p.xpm", &(data->w), &(data->h));
	data->img_l_p = f(data->mlx, "./images/l_p.xpm", &(data->w), &(data->h));
	data->img_d_p = f(data->mlx, "./images/d_p.xpm", &(data->w), &(data->h));
	data->img_r_p = f(data->mlx, "./images/r_p.xpm", &(data->w), &(data->h));
	data->img_dig = f(data->mlx, "./images/dig.xpm", &(data->w), &(data->h));
	return (0);
}

void	sl_player_images(t_data *data, int line, int i)
{
	if (data->direction == UP && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_u_p, i, line);
	if (data->direction == 0 && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_p, i, line);
	if (data->direction == LEFT && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_l_p, i, line);
	if (data->direction == DOWN && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_d_p, i, line);
	if (data->direction == RIGHT && data->map[line][i] == 'P')
		p_mlx_put_image_to_window(data, data->img_r_p, i, line);
	if (data->map[line][i] == 'D')
		p_mlx_put_image_to_window(data, data->img_dig, i, line);
}

int	sl_images(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == 'S')
				p_mlx_put_image_to_window(data, data->img_s, i, line);
			if (data->map[line][i] == '1')
				p_mlx_put_image_to_window(data, data->img_1, i, line);
			if (data->map[line][i] == '0')
				p_mlx_put_image_to_window(data, data->img_0, i, line);
			if (data->c_count > 0 && data->map[line][i] == 'E')
				p_mlx_put_image_to_window(data, data->img_x, i, line);
			if (data->c_count == 0 && data->map[line][i] == 'E')
				p_mlx_put_image_to_window(data, data->img_e, i, line);
			if (data->map[line][i] == 'C')
				p_mlx_put_image_to_window(data, data->img_c, i, line);
			sl_player_images(data, line, i);
		}
	}
	return (0);
}
