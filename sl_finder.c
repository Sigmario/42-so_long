/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:09:21 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/15 02:29:54 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_find(t_data *data, int line, int i)
{
	if (data->map_copy[line][i] == 'E')
		data->e_count--;
	if (data->map_copy[line][i] == 'C')
		data->c_count_t--;
	if (data->map_copy[line][i] != '1')
		data->map_copy[line][i] = 'P';
}

void	sl_axis(t_data *data, int line_start, int i_start)
{
	int		line;
	int		i;
	int		loop;

	loop = 1;
	while (loop)
	{
		line = 0;
		if (line_start == SOUTH)
			line = 0;
		if (line_start == NORTH)
			line = data->nb_line - 1;
		while (line >= 0 && data->map_copy[line])
		{
			i = 0;
			if (i_start == EAST)
				i = 0;
			if (i_start == WEST)
				i = data->nb_char - 1;
			while (i >= 0 && data->map_copy[line][i])
			{
				loop = 0;
				if (data->map_copy[line][i] == 'P')
				{
					sl_find(data, line + 1, i);
					sl_find(data, line - 1, i);
					sl_find(data, line, i + 1);
					sl_find(data, line, i - 1);
					loop = 1;
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
	if (data->e_count != 0 || data->c_count_t != 0)
		return (ft_printf("Error\nInvalid path."), TRUE);
	else
		return (FALSE);
}
