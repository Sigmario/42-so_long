/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/19 21:16:12 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*CHANGES VALUE HERE*/
// void modif_data(t_data data)
// {
// 	data.line_index = 1;
// 	return;
// }

/*CHANGES VALUE GLOBALLY*/
// void modif_ptr(t_data *data)
// {
// 	data->line_index = -1;
// 	return;
// }

// char **array;

// array[0] = "abcd"
// array[1] = "efgh"

// array[0][0] = 'a'

int main(void)
{
	t_data data;

	// data.line_index = 0;
	// modif_data(data);
	// //0
	// modif_ptr(&data);
	sl_get_map(&data);
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