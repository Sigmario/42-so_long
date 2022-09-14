/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_getmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/14 23:36:08 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_locate(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	data->direction = 0;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == 'E')
			{
				data->e_line = line;
				data->e_char = i;
			}
			if (data->map[line][i] == 'P')
			{
				data->p_line = line;
				data->p_char = i;
			}
		}
	}
	return (0);
}

void	sl_count_line(t_data *data, int fd, char *filename)
{
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
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

char	**sl_getmap(t_data *data, char *filename)
{
	int	fd;

	fd = 0;
	sl_count_line(data, fd, filename);
	if (!data->nb_line)
	{
		ft_printf("Error\nIt's empty.\n");
		exit(EXIT_SUCCESS);
	}
	fd = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->nb_line + 1));
	if (data->map == NULL)
		return (NULL);
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

char	**sl_mapcpy(t_data *data)
{
	char	**map_copy;
	int		i;

	i = -1;
	map_copy = malloc((data->nb_line + 1) * sizeof(char *));
	if (!map_copy)
	{
		data->map_copy = 0;
		return (0);
	}
	while (data->map[++i])
		map_copy[i] = ft_strdup(data->map[i]);
	map_copy[i] = 0;
	data->map_copy = map_copy;
	return (map_copy);
}
