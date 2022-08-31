/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_locate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:56:21 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/31 20:38:15 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_locate(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	while (data->map[line])
	{
		i = 0;
		while (data->map[line][i])
		{
			if (data->map[line][i] == 'P')
			{
				data->p_line = line;
				data->p_char = i;
			}
			i++;
		}
		line++;
	}
	return (0);
}
