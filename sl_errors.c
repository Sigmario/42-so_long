/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:51:18 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/23 19:10:31 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_char_errors(t_data data)
{
	static int	line;
	int			count_exit;
	int			count_coll;
	int			count_play;
	int			i;

	count_exit = 0;
	count_coll = 0;
	count_play = 0;
	while (data.map[++line])
	{
		i = 0;
		while (data.map[line][++i])
		{
			if (data.map[line][i] == 'E')
				count_exit++;
			if (data.map[line][i] == 'C')
				count_coll++;
			if (data.map[line][i] == 'P')
				count_play++;
		}
	}
	if (count_exit < 1 || count_coll < 1 || count_play < 1)
		return (TRUE);
	return (FALSE);
}

int	sl_errors(t_data data)
{
	static int	line;
	int	i;

	if (sl_char_errors(data) == TRUE)
		return (TRUE);
	while (data.map[++line])
	{
		if (ft_linelen(data.map[line]) != ft_linelen(data.map[0]))
			return (TRUE);
		i = 0;
		while (data.map[line][i])
		{
			if ((data.map[0][i] != '1' && data.map[0][i] != '\n')
				|| (data.map[data.nb_line - 1][i] != '1'
					&& data.map[data.nb_line - 1][i] != '\0'))
				return (TRUE);
			if (data.map[line][0] != '1'
				|| data.map[line][ft_linelen(data.map[line] + 1)] != '1')
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}
