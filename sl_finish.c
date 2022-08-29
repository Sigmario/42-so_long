/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:32:32 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/29 21:57:59 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_collect(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	data->count = 0;
	while (data->map[line])
	{
		i = 0;
		while (data->map[line][i])
		{
			if (data->map[line][i] == 'C')
				data->count++;
			i++;
		}
		line++;
	}
}

void	sl_exit(t_data *data)
{
	if (data->count == 0)
	{
		mlx_destroy_window(data->mlx, data->window);
		ft_printf("Finished!\n");
		exit(EXIT_SUCCESS);
	}
}
