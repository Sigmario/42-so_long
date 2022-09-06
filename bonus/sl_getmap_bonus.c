/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_getmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/06 21:10:08 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	sl_count_line(t_data *data, int fd, char *path)
{
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nYou must indicate the map's path as 1st argument.\n");
		return ;
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
}

char	**sl_getmap(t_data *data, char *path)
{
	int	fd;

	fd = 0;
	sl_count_line(data, fd, path);
	if (!data->nb_line)
	{
		ft_printf("Error\nEmpty file.\n");
		exit(EXIT_SUCCESS);
	}
	fd = open(path, O_RDONLY);
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
