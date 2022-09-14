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

void	sl_axis(t_data *data, int line_srt, int i_srt, int line_nxt, int i_nxt)
{
	int		line;
	int		i;
	int		loop;

	loop = 1;
	while (loop)
	{
		line = line_srt;
		while (data->map[line])
		{
			i = i_srt;
			while (data->map[line][i])
			{
				loop = 0;
				if (data->map[line][i] == 'P')
				{
					if (data->map[line + 1][i] != '1')
					{
						data->map[line + 1][i] = 'P';
						loop = 1;
					}
					if (data->map[line - 1][i] != '1')
					{
						data->map[line - 1][i] = 'P';
						loop = 1;
					}
					if (data->map[line][i + 1] != '1')
					{
						data->map[line][i + 1] = 'P';
						loop = 1;
					}
					if (data->map[line][i - 1] != '1')
					{
						data->map[line][i - 1] = 'P';
						loop = 1;
					}
				}
				i_nxt;
			}
			line_nxt;
		}
	}
}

void	sl_scan(t_data *data)
{
	static int	line;
	static int	i;

	sl_axis(data, 0, 0, line++, i++);
	sl_axis(data, data->nb_line - 1, 0, line--, i++);
	sl_axis(data, 0, data->nb_char - 1, line++, i--);
	sl_axis(data, data->nb_line - 1, data->nb_char - 1, line--, i--);
}
