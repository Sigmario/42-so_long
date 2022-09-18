/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:54:49 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/04 20:24:14 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_count(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	data->e_count = 1;
	data->c_count = 0;
	data->p_count = 0;
	data->c_count_t = 0;
	while (data->map[line] && data->map_copy[line])
	{
		i = 0;
		while (data->map[line][i] && data->map_copy[line][i])
		{
			if (data->map[line][i] == 'C')
				data->c_count++;
			if (data->map_copy[line][i] == 'C')
				data->c_count_t++;
			i++;
		}
		line++;
	}
}

void	sl_score(t_data *data)
{
	if (data->p_count == 1)
		ft_printf("You did %d move.\n", data->p_count);
	else
		ft_printf("You did %d moves.\n", data->p_count);
}

int	sl_quit(t_data *data)
{
	if (data->c_count == 0)
	{
		ft_printf("Finished with %d moves!\n", data->p_count + 1);
		sl_free(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	sl_cross(t_data *data)
{
	ft_printf("So long!\n");
	sl_free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	sl_key(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_printf("So long!\n");
		sl_free(data);
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
	return (0);
}
