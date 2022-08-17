# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 16:15:09 by julmuntz          #+#    #+#              #
#    Updated: 2022/08/17 15:09:12 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	so_long.c

OBJS		= 	$(SRCS:.c=.o)

NAME		= 	so_long

LIBFT		=	./libft

MLX			=	./mlx_linux

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror

.c.o :
	$(CC) -c -I $(LIBFT) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):		$(OBJS)
					cd $(LIBFT) && $(MAKE)
					cp libft/libft.a $(NAME)
					cd $(MLX) && $(MAKE)
					cp mlx_linux/libmlx.a $(NAME)
					$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


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