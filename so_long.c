/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/02 21:20:44 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_start(t_data data, char **ptr)
{
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		sl_free_all(&data);
		exit(EXIT_SUCCESS);
	}
	data.map = sl_getmap(&data, *ptr);
	sl_locate(&data);
	sl_count(&data);
	sl_errors(data);
	if (sl_invalid_char_errors(data) == TRUE)
		return (TRUE);
	sl_skybar(&data);
	data.window = mlx_new_window(data.mlx,
			data.nb_char * 48, data.nb_line * 48, "Dig Dug");
	mlx_hook(data.window, KeyPress, KeyPressMask, &sl_key, &data);
	mlx_hook(data.window, ClientMessage, 0, &sl_cross, &data);
	sl_find_images(&data);
	sl_images(&data);
	mlx_loop(data.mlx);
	return (0);
}

int	main(int arc, char **arv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (arc == 2)
		sl_start(data, &arv[1]);
	else
		ft_printf("Error\nYou must indicate the map's path as 1st argument.\n");
	return (0);
}
