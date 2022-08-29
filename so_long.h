/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:13:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/29 18:20:47 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

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

	void	*mlx;
	void	*window;

	void	*img_0;
	void	*img_1;
	void	*img_e;
	void	*img_c;
	void	*img_p;

	int		p_line;
	int		p_char;
}			t_data;

char	**sl_get_map(t_data *data);
int		sl_errors(t_data data);
int		sl_invalid_char_errors(t_data data);
int		sl_find_images(t_data *data);
int		sl_put_images(t_data *data);
int		sl_press(int key, t_data *data);
int		sl_exit_press(t_data *data);
int		sl_player(t_data *data);
void	sl_up(t_data *data);
void	sl_left(t_data *data);
void	sl_down(t_data *data);
void	sl_right(t_data *data);

#endif