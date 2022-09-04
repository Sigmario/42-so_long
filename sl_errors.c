/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:51:18 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/04 17:40:12 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_invalid_extension(char *filename)
{
	char	*ber;

	if (!filename)
		return (FALSE);
	ber = ft_strrchr(filename, '.');
	if (ft_strncmp(ber, ".ber", 4))
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
				return (ft_printf("Error\nInvalid char(s).\n"), TRUE);
			i++;
		}
		line++;
	}
	return (FALSE);
}

int	sl_char_errors_2(int count_exit, int count_coll, int count_play)
{
	if (count_exit < 1 || count_coll < 1 || count_play < 1)
	{
		ft_printf("Error\n");
		if (count_exit < 1)
			ft_printf("No exit found.\n");
		if (count_coll < 1)
			ft_printf("No collectible found.\n");
		if (count_play < 1)
			ft_printf("No player found.\n");
		return (TRUE);
	}
	return (FALSE);
}

int	sl_char_errors_1(t_data data)
{
	static int	count_exit;
	static int	count_coll;
	static int	count_play;
	int			line;
	int			i;

	line = 0;
	while (data.map[line])
	{
		i = 0;
		while (data.map[line][i])
		{
			if (data.map[line][i] == 'E')
				count_exit++;
			if (data.map[line][i] == 'C')
				count_coll++;
			if (data.map[line][i] == 'P')
				count_play++;
			i++;
		}
		line++;
	}
	if (sl_char_errors_2(count_exit, count_coll, count_play) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	sl_errors(t_data data)
{
	int	line;
	int	i;

	line = 0;
	while (data.map[line])
	{
		if (ft_linelen(data.map[line]) != ft_linelen(data.map[0]))
			return (ft_printf("Error\nNot rectangular.\n"));
		i = 0;
		while (data.map[line][i])
		{
			if ((data.map[0][i] != '1' && data.map[0][i] != '\n')
				|| (data.map[data.nb_line - 1][i] != '1'
					&& data.map[data.nb_line - 1][i] != '\0'))
				return (ft_printf("Error\nInvalid walls.\n"), TRUE);
			if (data.map[line][0] != '1'
				|| data.map[line][ft_linelen(data.map[line] + 1)] != '1')
				return (ft_printf("Error\nInvalid walls.\n"), TRUE);
			i++;
		}
		line++;
		if (sl_char_errors_1(data) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}
