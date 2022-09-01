/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/27 19:33:08 by julmuntz         ###   ########.fr       */
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

void	sl_count_line(t_data *data, int fd, char *path)
{
	char	*line;

	fd = open(path, O_RDONLY);
	data->nb_line = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->nb_line++;
		data->nb_char = ft_linelen(line);
		free(line);
	}
	close(fd);
}

char	**sl_getmap(t_data *data, char *path)
{
	int	fd;

	fd = 0;
	sl_count_line(data, fd, path);
	fd = open(path, O_RDONLY);
	data->x = 0;
	data->map = malloc(sizeof(char *) * (data->nb_line + 1));
	while (TRUE)
	{
		data->map[data->x] = get_next_line(fd);
		if (data->map[data->x] == NULL)
			break ;
		data->x++;
	}
	close(fd);
	return (data->map);
}
