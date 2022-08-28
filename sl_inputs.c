/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:54:49 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/28 21:40:45 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit_press(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	return (0);
}

int	sl_press(int key, t_data *data)
{
	if (key == XK_Escape)
		mlx_destroy_window(data->mlx, data->window);
	else if (key == XK_w)
		ft_printf("W: %x\n", key);
	else if (key == XK_a)
		ft_printf("A: %x\n", key);
	else if (key == XK_s)
		ft_printf("S: %x\n", key);
	else if (key == XK_d)
		ft_printf("D: %x\n", key);
	return (0);
}
