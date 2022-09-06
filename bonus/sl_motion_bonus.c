/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_motion_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:39:44 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/06 21:09:42 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_up(t_data *data)
{
	data->direction = UP;
	if (data->map[data->p_line - 1][data->p_char] != '1'
		&& data->map[data->p_line - 1][data->p_char] != 'S')
	{
		if (data->map[data->p_line - 1][data->p_char] == 'E'
			&& data->c_count == 0)
		{
			data->p_line--;
			sl_quit(data);
		}
		if (data->map[data->p_line - 1][data->p_char] != 'E')
		{
			if (data->map[data->p_line - 1][data->p_char] == 'C')
				data->c_count--;
			data->p_line--;
			data->map[data->p_line][data->p_char] = 'P';
			data->map[data->p_line + 1][data->p_char] = 'D';
			data->p_count++;
		}
	}
}

void	sl_left(t_data *data)
{
	data->direction = LEFT;
	if (data->map[data->p_line][data->p_char - 1] != '1'
		&& data->map[data->p_line][data->p_char - 1] != 'S')
	{
		if (data->map[data->p_line][data->p_char - 1] == 'E'
			&& data->c_count == 0)
		{
			data->p_char--;
			sl_quit(data);
		}
		if (data->map[data->p_line][data->p_char - 1] != 'E')
		{
			if (data->map[data->p_line][data->p_char - 1] == 'C')
				data->c_count--;
			data->p_char--;
			data->map[data->p_line][data->p_char] = 'P';
			data->map[data->p_line][data->p_char + 1] = 'D';
			data->p_count++;
		}
	}
}

void	sl_down(t_data *data)
{
	data->direction = DOWN;
	if (data->map[data->p_line + 1][data->p_char] != '1'
		&& data->map[data->p_line + 1][data->p_char] != 'S')
	{
		if (data->map[data->p_line + 1][data->p_char] == 'E'
			&& data->c_count == 0)
		{
			data->p_line++;
			sl_quit(data);
		}
		if (data->map[data->p_line + 1][data->p_char] != 'E')
		{
			if (data->map[data->p_line + 1][data->p_char] == 'C')
				data->c_count--;
			data->p_line++;
			data->map[data->p_line][data->p_char] = 'P';
			data->map[data->p_line - 1][data->p_char] = 'D';
			data->p_count++;
		}
	}
}

void	sl_right(t_data *data)
{
	data->direction = RIGHT;
	if (data->map[data->p_line][data->p_char + 1] != '1'
		&& data->map[data->p_line][data->p_char + 1] != 'S')
	{
		if (data->map[data->p_line][data->p_char + 1] == 'E'
			&& data->c_count == 0)
		{
			data->p_char++;
			sl_quit(data);
		}
		if (data->map[data->p_line][data->p_char + 1] != 'E')
		{
			if (data->map[data->p_line][data->p_char + 1] == 'C')
				data->c_count--;
			data->p_char++;
			data->map[data->p_line][data->p_char] = 'P';
			data->map[data->p_line][data->p_char - 1] = 'D';
			data->p_count++;
		}
	}
}
