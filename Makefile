# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 16:15:09 by julmuntz          #+#    #+#              #
#    Updated: 2022/08/29 18:44:05 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	so_long.c				\
				sl_getmap.c				\
				sl_errors.c				\
				sl_images.c				\
				sl_inputs.c				\
				sl_player.c				\
				sl_motion.c				\

OBJS		= 	$(SRCS:.c=.o)

NAME		= 	so_long

LIBFT		=	./libft
MLX			=	./mlx

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror -g

.c.o :
	$(CC) -c -I $(LIBFT) $< -o $@
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):		$(OBJS)
					cd $(LIBFT) && $(MAKE)
					cd $(MLX) && $(MAKE)
					$(CC) $(OBJS) libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)


all:			$(NAME)

clean:
					$(RM) -r $(OBJS)
					cd $(LIBFT) && $(MAKE) clean
					cd $(MLX) && $(MAKE) clean

fclean:			clean
					$(RM) $(NAME)
					cd $(LIBFT) && $(MAKE) fclean
					cd $(MLX) && $(MAKE) fclean


re:				fclean all

.PHONY:			all clean fclean re