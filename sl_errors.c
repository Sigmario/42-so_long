/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:51:18 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/23 13:15:54 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_errors(t_data data)
{
	int	i;
	int	c;

	i = 0;
	while (data.map[i])
	{
		if (ft_linelen(data.map[i]) != ft_linelen(data.map[0]))
			return (TRUE);
		c = 0;
		while (data.map[i][c])
		{
			if (data.map[i][c] != '\n' &&
				data.map[i][c] != '1' && data.map[i][c] != '0' &&
				data.map[i][c] != 'P' && data.map[i][c] != 'E' &&
				data.map[i][c] != 'C')
				return (TRUE);
			c++;
		}
		i++;
	}
	return (FALSE);
}
