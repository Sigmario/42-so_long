/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:51:18 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/11 14:28:45 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// int	sl_issolution(t_data data)
// {
// 	if (data.map[data.p_line][data.p_char] != '1' && data.map[data.p_line][data.p_char] != 'E')
// 		return (TRUE);

// 	if (sl_issolution(map, p_line, p_char + 1) == TRUE)
// 		return (TRUE);
// 	if (sl_issolution(map, p_line, p_char - 1) == TRUE)
// 		return (TRUE);
// 	if (sl_issolution(map, p_line + 1, p_char) == TRUE)
// 		return (TRUE);
// 	if (sl_issolution(map, p_line - 1, p_char) == TRUE)
// 		return (TRUE);
// }

int	sl_invalid_extension(char *filename)
{
	char	*ber;

	if (!filename)
		return (FALSE);
	ber = ft_strrchr(filename, '.');
	if (ber && ft_strncmp(ber, ".ber", 4))
		return (FALSE);
	return (TRUE);
}

int	sl_invalid_chars(t_data data)
{
	int	line;
	int	i;

	line = 0;
	while (data.map[line])
	{
		i = 0;
		while (data.map[line][i])
		{
			if (data.map[line][i] != '0' && data.map[line][i] != '1'
				&& data.map[line][i] != 'E' && data.map[line][i] != 'C'
				&& data.map[line][i] != 'P' && data.map[line][i] != '\n')
				return (sl_free_map(&data),
					ft_printf("Error\nInvalid char(s).\n"), TRUE);
			i++;
		}
		line++;
	}
	return (FALSE);
}

int	sl_char_errors_2(int count_exit, int count_coll, int count_play)
{
	if (count_exit != 1 || count_coll < 1 || count_play != 1)
	{
		ft_printf("Error\n");
		if (count_exit < 1)
			ft_printf("No exit found.\n");
		if (count_exit > 1)
			ft_printf("Can't put more than 1 exit.\n");
		if (count_coll < 1)
			ft_printf("No collectible found.\n");
		if (count_play > 1)
			ft_printf("Can't put more than 1 player.\n");
		if (count_play < 1)
			ft_printf("No player found.\n");
		return (TRUE);
	}
	else
		return (FALSE);
}

int	sl_char_errors_1(t_data data)
{
	int	count[3];
	int	line;
	int	i;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	line = -1;
	while (data.map[++line])
	{
		i = -1;
		while (data.map[line][++i])
		{
			if (data.map[line][i] == 'E')
				count[0]++;
			if (data.map[line][i] == 'C')
				count[1]++;
			if (data.map[line][i] == 'P')
				count[2]++;
		}
	}
	if (sl_char_errors_2(count[0], count[1], count[2]) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	sl_errors(t_data data)
{
	int	line;
	int	i;

	if (!data.map)
		return (1);
	line = -1;
	while (data.map[++line])
	{
		if (ft_linelen(data.map[line]) != ft_linelen(data.map[0]))
			return (ft_printf("Error\nNot rectangular.\n"));
		i = -1;
		while (data.map[line][++i])
		{
			if ((data.map[0][i] != '1' && data.map[0][i] != '\n')
				|| (data.map[data.nb_line - 1][i] != '1'
					&& data.map[data.nb_line - 1][i] != '\0'))
				return (ft_printf("Error\nInvalid walls.\n"), TRUE);
			if (data.map[line][0] != '1'
				|| data.map[line][ft_linelen(data.map[line] + 1)] != '1')
				return (ft_printf("Error\nInvalid walls.\n"), TRUE);
		}
		if (sl_char_errors_1(data) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}
