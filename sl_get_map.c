/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/19 17:06:47 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_count_line(t_data *data, int fd)
{
	data->nb_line = 0;
	while (data->nb_line)
		data->map[data->line_index++] = get_next_line(fd);
}

void	sl_get_map(t_data *data)
{
	int	i;
	int	fd;
	i = 0;
	fd = open("maps/map1.ber", O_RDONLY);
	sl_count_line(data, fd);
	data->line_index = i;
	data->map = malloc(sizeof(char **) * (data->nb_line + 1));
	while (TRUE)
	{
		data->map[data->line_index] = get_next_line(fd);
		if (data->map[data->line_index] == NULL)
			break ;
		data->nb_line++;
		printf("N°%d\t%s", data->nb_line, data->map[data->line_index]);
	}
	ft_printf("%d\n", data->nb_line);
	close(fd);
}