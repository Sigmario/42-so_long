/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:13:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/25 21:01:30 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct s_data
{
	char	*addr;
	void	*img;
	int		endian;
	int		line_len;
	char	**map;
	int		x;
	int		y;
	int		nb_line;
	int		nb_char;
	int		bpp;
	int		w;
	int		h;

	void	*void_image;
	void	*wall_image;
	void	*play_image;
	void	*coll_image;
	void	*exit_image;
}			t_data;

void		sl_mlx_pixel_put(t_data *data, int x, int y, int color);
char		**sl_get_map(t_data *data);
int			sl_errors(t_data data);
int			sl_invalid_char_errors(t_data data);
void		sl_images(t_data data);

#endif