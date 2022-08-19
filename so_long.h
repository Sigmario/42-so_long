/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:13:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/19 15:09:40 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	char 	**map;
	int		line_index;
	int		line_len;
	int		nb_line;
	int		endian;
	char	*addr;
	void	*img;
	int		bpp;

}				t_data;

void	sl_mlx_pixel_put(t_data *data, int x, int y, int color);
void	sl_get_map(t_data *data);

#endif