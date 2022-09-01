/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:54:49 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/01 21:19:59 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_count(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	data->p_count = 0;
	data->c_count = 0;
	while (data->map[line])
	{
		i = 0;
		while (data->map[line][i])
		{
			if (data->map[line][i] == 'C')
				data->c_count++;
			i++;
		}
		line++;
	}
	return (0);
}

int	sl_quit(t_data *data)
{
	data->p_count++;
	ft_printf("Finished with %d moves!\n", data->p_count);
	sl_free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	sl_cross(t_data *data)
{
	ft_printf("So long!\n");
	sl_free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	sl_key(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_printf("So long!\n");
		sl_free_all(data);
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_w)
		sl_up(data);
	else if (key == XK_a)
		sl_left(data);
	else if (key == XK_s)
		sl_down(data);
	else if (key == XK_d)
		sl_right(data);
	sl_images(data);
	return (0);
}
