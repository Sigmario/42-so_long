/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/28 21:37:37 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	static int	i;
	t_data		data;

	data.mlx = mlx_init();
	data.map = sl_get_map(&data);
	if (sl_errors(data) == FALSE)
	{
		if (data.nb_line == 0 && data.nb_char == 0)
			return (ft_printf("Error\nEmpty file.\n"));
		if (sl_invalid_char_errors(data) == TRUE)
			return (TRUE);
		while (data.map[i])
			ft_printf("%s", data.map[i++]);
		ft_printf("\n\nMap Size:\tHeight:\t%d\n\t\tWidth:\t%d\n", data.nb_line,
			data.nb_char);
		data.window = mlx_new_window(data.mlx, data.nb_char * 48, data.nb_line
				* 48, "StarWario");

		mlx_hook(data.window, KeyPress, KeyPressMask, &sl_press, &data);
		mlx_hook(data.window, ClientMessage, 0, &sl_exit_press, &data);

		mlx_loop_hook(data.mlx, &sl_put_images, &data);
		mlx_loop(data.mlx);

		mlx_destroy_display(data.mlx);
		free(data.mlx);
	}
	else
		return (TRUE);
	return (0);
}
