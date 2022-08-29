/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_motion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:39:44 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/29 22:11:09 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_up(t_data *data)
{
	if (data->map[data->p_line - 1][data->p_char] != '1')
	{
		if (data->map[data->p_line - 1][data->p_char] == 'C')
			data->count--;
		else if (data->map[data->p_line - 1][data->p_char] == 'E')
		{
			data->map[data->p_line + 1][data->p_char] = 'E';
			sl_exit(data);
		}
		data->p_line--;
		data->map[data->p_line][data->p_char] = 'P';
		data->map[data->p_line + 1][data->p_char] = '0';
	}
}

void	sl_left(t_data *data)
{
	if (data->map[data->p_line][data->p_char - 1] != '1')
	{
		if (data->map[data->p_line][data->p_char - 1] == 'C')
			data->count--;
		else if (data->map[data->p_line][data->p_char - 1] == 'E')
		{
			data->map[data->p_line][data->p_char + 1] = 'E';
			sl_exit(data);
		}
		data->p_char--;
		data->map[data->p_line][data->p_char] = 'P';
		data->map[data->p_line][data->p_char + 1] = '0';
	}
}

void	sl_down(t_data *data)
{
	if (data->map[data->p_line + 1][data->p_char] != '1')
	{
		if (data->map[data->p_line + 1][data->p_char] == 'C')
			data->count--;
		else if (data->map[data->p_line + 1][data->p_char] == 'E')
		{
			data->map[data->p_line - 1][data->p_char] = 'E';
			sl_exit(data);
		}
		data->p_line++;
		data->map[data->p_line][data->p_char] = 'P';
		data->map[data->p_line - 1][data->p_char] = '0';
	}
}

void	sl_right(t_data *data)
{
	if (data->map[data->p_line][data->p_char + 1] != '1')
	{
		if (data->map[data->p_line][data->p_char + 1] == 'C')
			data->count--;
		else if (data->map[data->p_line][data->p_char + 1] == 'E')
		{
			data->map[data->p_line][data->p_char - 1] = 'E';
			sl_exit(data);
		}
		data->p_char++;
		data->map[data->p_line][data->p_char] = 'P';
		data->map[data->p_line][data->p_char - 1] = '0';
	}
}
