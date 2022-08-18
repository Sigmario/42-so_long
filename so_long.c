/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:39:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/18 18:41:10 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data data;
	int fd;
	int		i;
	char	*line;
	i = 1;
	fd = open("maps/map1.ber", O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("N°%d\t%s", i, line);
		if (ft_strlen(line) == i)
			return (ft_printf("Error, not a rectangle.\n"));
		free(line);
		i++;
	}
	sl_get_map(&data);
	data.line_id = i;
	printf("%d\n", data.line_id);
	data.line_index = line;
	printf("%d\n", data.line_index);
	close(fd);
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