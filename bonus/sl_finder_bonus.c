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

void	sl_find(t_data *data, int line, int i)
{
	if (data->map_copy[line][i] == 'E')
		data->e_count--;
	if (data->map_copy[line][i] == 'C')
		data->c_count_t--;
	if (data->map_copy[line][i] != '1')
		data->map_copy[line][i] = 'P';
}

void	sl_scan_2(t_data *data, int line, int i, int i_start)
{
	if (i_start == EAST)
		i = 0;
	if (i_start == WEST)
		i = data->nb_char - 1;
	while (i >= 0 && data->map_copy[line][i])
	{
		data->loop = 0;
		if (data->map_copy[line][i] == 'P')
		{
			sl_find(data, line + 1, i);
			sl_find(data, line - 1, i);
			sl_find(data, line, i + 1);
			sl_find(data, line, i - 1);
			data->loop = 1;
		}
		if (i_start == EAST)
			i++;
		if (i_start == WEST)
			i--;
	}
}

void	sl_scan(t_data *data, int line_start, int i_start)
{
	int		line;
	int		i;

	data->loop = 1;
	while (data->loop)
	{
		if (line_start == SOUTH)
			line = 0;
		if (line_start == NORTH)
			line = data->nb_line - 1;
		while (line >= 0 && data->map_copy[line])
		{
			i = 0;
			sl_scan_2(data, line, i, i_start);
			if (line_start == SOUTH)
				line++;
			if (line_start == NORTH)
				line--;
		}
	}
}

int	sl_invalid_path(t_data *data)
{
	sl_scan(data, SOUTH, WEST);
	sl_scan(data, NORTH, WEST);
	sl_scan(data, SOUTH, EAST);
	sl_scan(data, NORTH, EAST);
	sl_scan(data, SOUTH, WEST);
	sl_scan(data, SOUTH, EAST);
	sl_scan(data, NORTH, WEST);
	sl_scan(data, NORTH, EAST);
	sl_scan(data, NORTH, WEST);
	sl_scan(data, SOUTH, WEST);
	sl_scan(data, NORTH, EAST);
	sl_scan(data, SOUTH, EAST);
	sl_scan(data, SOUTH, EAST);
	sl_scan(data, SOUTH, WEST);
	sl_scan(data, NORTH, EAST);
	sl_scan(data, NORTH, WEST);
	if (data->e_count != 0 || data->c_count_t != 0)
		return (ft_printf("Error\nInvalid path.\n"), TRUE);
	else
		return (FALSE);
}
