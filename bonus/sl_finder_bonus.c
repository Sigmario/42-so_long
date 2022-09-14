/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_finder_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:28:32 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/13 20:28:32 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_find(t_data *data, int loop, int line, int i)
{
	if (data->map[line][i] == 'E')
		data->e_count++;
	if (data->map[line][i] == 'C')
		data->c_count--;
	if (data->map[line][i] != '1')
	{
		data->map[line][i] = 'P';
		loop = 1;
	}
}

void	sl_axis(t_data *data, int line_start, int i_start)
{
	int		line;
	int		i;
	int		loop;

	loop = 1;
	while (loop)
	{
		if (line_start == SOUTH)
			line = 0;
		if (line_start == NORTH)
			line = data->nb_line - 1;
		while (data->map[line])
		{
			if (i_start == EAST)
				i = 0;
			if (i_start == WEST)
				i = data->nb_char - 1;
			while (data->map[line][i])
			{
				loop = 0;
				if (data->map[line][i] == 'P')
				{
					sl_find(data, loop, line + 1, i);
					sl_find(data, loop, line - 1, i);
					sl_find(data, loop, line, i + 1);
					sl_find(data, loop, line, i - 1);
				}
				if (i_start == EAST)
					i++;
				if (i_start == WEST)
					i--;
			}
			if (line_start == SOUTH)
				line++;
			if (line_start == NORTH)
				line--;
		}
	}
}

int	sl_invalid_path(t_data *data)
{
	sl_axis(data, SOUTH, EAST);
	sl_axis(data, SOUTH, WEST);
	sl_axis(data, NORTH, EAST);
	sl_axis(data, NORTH, WEST);
	sl_free_map(data);
	ft_printf("E: %d\n", data->e_count);
	ft_printf("C: %d\n", data->c_count);
	if (data->e_count != 1 && data->c_count != 0)
		return (ft_printf("Error\nInvalid path."), TRUE);
	else
		return (FALSE);
}
