/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/20 16:12:53 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_count_line(t_data *data, int fd)
{
	data->nb_line = 0;
	while (data->nb_line)
		data->map[data->x] = get_next_line(fd);
}

int	sl_get_map(t_data *data)
{
	int	fd;

	fd = open("maps/map1.ber", O_RDONLY);
	sl_count_line(data, fd);
	data->x = 0;
	data->y = 0;
	data->map = malloc(sizeof(char *) * (data->nb_line + 1));
	while (TRUE)
	{
		data->map[data->x] = malloc(ft_strlen(data->map[data->x]) + 1 * sizeof(char *));
		data->map[data->x] = get_next_line(fd);
		if (data->map[data->x] == NULL)
			break ;
		data->nb_line++;
		while (data->map[data->x][data->y])
			data->y++;
		ft_printf("%c\n", data->map[data->x][3]); // Displays the 4th character of each line.
		ft_printf("%s", data->map[data->x]);
		free(data->map[data->x]);
	}
	ft_printf("Map de %d lignes.\n", data->nb_line);
	free(data->map);
	close(fd);
	return (0);
}