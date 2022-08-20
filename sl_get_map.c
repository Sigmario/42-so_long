/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/20 12:22:21 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_count_line(t_data *data, int fd)
{
	data->nb_line = 0;
	while (data->nb_line)
		data->map[data->x] = get_next_line(fd);
}

void	sl_get_map(t_data *data)
{
	int y;
	int	fd;

	y = 0;
	fd = open("maps/map1.ber", O_RDONLY);
	sl_count_line(data, fd);
	data->x = 0;
	data->map = malloc(sizeof(char **) * (data->nb_line + 1));
	while (TRUE)
	{
		data->map[data->x] = get_next_line(fd);
		if (data->map[data->x] == NULL)
			break ;
		while () /*index char de chaque lignes*/
		data->nb_line++;
		ft_printf("%s", data->map[data->x]);
		free(data->map[data->x]);
	}
	ft_printf("Map de %d lignes.\n", data->nb_line);
	ft_printf("%c\n", data->map[17][0]);
	free(data->map);
	close(fd);
}