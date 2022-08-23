/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/23 19:24:12 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	static int	i;
	t_data		data;

	data.map = sl_get_map(&data);
	if (sl_errors(data) == TRUE)
		return (ft_printf("\nError: Invalid Map\n"));
	while (data.map[i])
		ft_printf("%s", data.map[i++]);
	ft_printf("\n\nMap of %d x %d\n", data.nb_line, data.nb_char);
	free(data.map);
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "test");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len,
// 			&img.endian);
// 	sl_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 10, 10);
// 	mlx_loop(mlx);
// 	// mlx_hook(mlx, 02, (1L<<0), );
// 	// mlx_key_hook(mlx_win, mlx_destroy_window(27), mlx);
// }