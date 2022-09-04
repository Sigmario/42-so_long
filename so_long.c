/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/04 18:30:30 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_start(t_data data)
{
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		sl_free(data.mlx);
		exit(EXIT_FAILURE);
	}
	if (sl_errors(data) == TRUE)
		return (TRUE);
	if (sl_invalid_chars(data) == TRUE)
		return (TRUE);
	sl_count(&data);
	sl_locate(&data);
	data.window = mlx_new_window(data.mlx,
			data.nb_char * 48, data.nb_line * 48, "Dig Dug");
	sl_find_images(&data);
	sl_images(&data);
	mlx_string_put(data.mlx, data.window, 8, 20, 0xFFD700, "PLAYER 1");
	mlx_string_put(data.mlx, data.window, 16, 38, 0xFFFF00, "READY");
	mlx_hook(data.window, KeyPress, KeyPressMask, &sl_key, &data);
	mlx_hook(data.window, ClientMessage, 0, &sl_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	main(int arc, char **arv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.map = sl_getmap(&data, arv[1]);
	if (arc == 2)
	{
		if (sl_invalid_extension(arv[1]) == FALSE)
			return (ft_printf("Error\nNot a \".ber\" file.\n"), FALSE);
		sl_start(data);
	}
	return (0);
}
