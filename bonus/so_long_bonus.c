/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/07 14:08:50 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_start(t_data data)
{
	if (sl_errors(data) == TRUE)
		return (sl_free_map(&data), exit(EXIT_FAILURE), TRUE);
	if (sl_invalid_chars(data) == TRUE)
		return (sl_free_map(&data), exit(EXIT_FAILURE), TRUE);
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(EXIT_FAILURE);
	sl_count(&data);
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
	return (0);
}

int	main(int arc, char **arv)
{
	t_data	data;

	if (arc != 2)
		return (ft_printf("Error\nYou need a map path in the 1st argument.\n"));
	ft_bzero(&data, sizeof(t_data));
	data.map = sl_getmap(&data, arv[1]);
	if (!data.map)
		return (0);
	sl_free_map(&data);
	if (sl_invalid_extension(arv[1]) == FALSE)
		return (ft_printf("Error\nNot a \".ber\" file.\n"), FALSE);
	sl_start(data);
	return (0);
}
