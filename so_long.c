/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/03 21:51:13 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_start(t_data data, char **ptr)
{
	data.mlx = mlx_init();
	if (!data.mlx)
		sl_free(&data);
	data.map = sl_getmap(&data, *ptr);
	sl_count(&data);
	if (sl_invalid_char_errors(data) == TRUE)
		return (TRUE);
	else if (sl_errors(data) == TRUE)
		return (TRUE);
	sl_locate(&data);
	data.window = mlx_new_window(data.mlx,
			data.nb_char * 48, data.nb_line * 48, "DIG DUG");
	sl_find_images(&data);
	sl_images(&data);
	mlx_string_put(data.mlx, data.window, 8, 20, 0xFFD700, "PLAYER 1");
	mlx_string_put(data.mlx, data.window, 16, 38, 0xFFFF00, "READY");
	mlx_hook(data.window, KeyPress, KeyPressMask, &sl_key, &data);
	mlx_hook(data.window, ClientMessage, 0, &sl_cross, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
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
