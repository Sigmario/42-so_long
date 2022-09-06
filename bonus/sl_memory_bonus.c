/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_memory_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:59:55 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/06 21:22:16 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_free_image(t_data *data)
{
	if (data->img_s)
		mlx_destroy_image(data->mlx, data->img_s);
	if (data->img_0)
		mlx_destroy_image(data->mlx, data->img_0);
	if (data->img_1)
		mlx_destroy_image(data->mlx, data->img_1);
	if (data->img_x)
		mlx_destroy_image(data->mlx, data->img_x);
	if (data->img_e)
		mlx_destroy_image(data->mlx, data->img_e);
	if (data->img_c)
		mlx_destroy_image(data->mlx, data->img_c);
	if (data->img_p)
		mlx_destroy_image(data->mlx, data->img_p);
	if (data->img_u_p)
		mlx_destroy_image(data->mlx, data->img_u_p);
	if (data->img_l_p)
		mlx_destroy_image(data->mlx, data->img_l_p);
	if (data->img_d_p)
		mlx_destroy_image(data->mlx, data->img_d_p);
	if (data->img_r_p)
		mlx_destroy_image(data->mlx, data->img_r_p);
	if (data->img_dig)
		mlx_destroy_image(data->mlx, data->img_dig);
}

void	sl_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	sl_free(t_data *data)
{
	if (data)
	{
		sl_free_map(data);
		sl_free_image(data);
		mlx_clear_window(data->mlx, data->window);
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
