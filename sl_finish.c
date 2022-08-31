/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:32:32 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/31 20:38:33 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_count(t_data *data)
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
}

void	sl_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_printf("Finished with %d moves!\n", data->p_count);
	exit(EXIT_SUCCESS);
}
