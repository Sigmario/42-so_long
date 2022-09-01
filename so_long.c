/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/01 14:06:23 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arc, char **arv)
{
	t_data	data;

	if (arc == 2)
	{
		data.mlx = mlx_init();
		data.map = sl_getmap(&data, arv[1]);
		sl_locate(&data);
		sl_count(&data);
		sl_errors(data);
		if (sl_invalid_char_errors(data) == TRUE)
			return (TRUE);
		data.window = mlx_new_window(data.mlx,
				data.nb_char * 48, data.nb_line * 48, "StarWario");
		mlx_hook(data.window, KeyPress, KeyPressMask, &sl_key, &data);
		mlx_hook(data.window, ClientMessage, 0, &sl_cross, &data);
		sl_images(&data);
		mlx_loop(data.mlx);
	}
	else
		ft_printf("Error\nYou must indicate the map's path as 1st argument.\n");
	return (0);
}
