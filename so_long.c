/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/15 17:26:55 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_start(t_data data)
{
	if (sl_invalid_chars(data) == TRUE)
		return (exit(EXIT_FAILURE), TRUE);
	if (sl_errors(data) == TRUE)
		return (sl_free_map(&data), exit(EXIT_FAILURE), TRUE);
	sl_mapcpy(&data);
	sl_count(&data);
	if (sl_invalid_path(&data) == TRUE)
		return (sl_free_mapall(&data), exit(EXIT_FAILURE), TRUE);
	sl_free_mapcpy(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (sl_free_map(&data), free(data.mlx), 0);
	sl_locate(&data);
	data.window = mlx_new_window(data.mlx, data.nb_char * 48, data.nb_line * 48,
			"DIG DUG   (c)  1982 Atari, Inc.  All rights reserved.");
	if (!data.window)
		return (0);
	sl_find_images(&data);
	sl_images(&data);
	mlx_hook(data.window, KeyPress, KeyPressMask, &sl_key, &data);
	mlx_hook(data.window, ClientMessage, 0, &sl_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	main(int arc, char **arv)
{
	t_data	data;

	if (arc != 2)
		return (ft_printf("Error\nYou need a map file in the 1st argument.\n"));
	if (sl_invalid_extension(arv[1]) == FALSE)
		return (ft_printf("Error\nNot a \".ber\" file.\n"), FALSE);
	ft_bzero(&data, sizeof(t_data));
	data.map = sl_getmap(&data, arv[1]);
	if (!data.map)
		return (0);
	sl_start(data);
	return (0);
}
