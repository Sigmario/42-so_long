/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/03 21:07:53 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_locate(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	data->direction = 0;
	while (data->map[line])
	{
		i = 0;
		while (data->map[line][i])
		{
			if (data->map[0][i] == '1')
				data->map[0][i] = 'S';
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

int	sl_count_line(t_data *data, int fd, char *path)
{
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_printf("Error\nYou must indicate one valid path.\n");
		exit(EXIT_SUCCESS);
		return (0);
	}
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
	return (0);
}

char	**sl_getmap(t_data *data, char *path)
{
	int	fd;

	fd = 0;
	sl_count_line(data, fd, path);
	fd = open(path, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->nb_line + 1));
	data->x = 0;
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
