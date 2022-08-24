/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/24 18:51:50 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	static int i;
	t_data data;
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();

	data.map = sl_get_map(&data);
	if (sl_errors(data) == TRUE)
		return (ft_printf("\nError: Invalid Map\n"));
	while (data.map[i])
		ft_printf("%s", data.map[i++]);
	ft_printf("\n\nMap Size:\t%d x %d\n", data.nb_line, data.nb_char);
	free(data.map);

	mlx_win = mlx_new_window(mlx, 500, 300, "test");
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	img.img = mlx_xpm_file_to_image(mlx, "./images/w1.xpm", &data.h, &data.w);
	mlx_put_image_to_window(mlx, mlx_win, img.img, data.x, data.y);
	
	mlx_loop(mlx);
	return (0);
}
