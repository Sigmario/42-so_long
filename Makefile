# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 16:15:09 by julmuntz          #+#    #+#              #
#    Updated: 2022/08/16 18:31:03 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	so_long.c				\

OBJS		= 	$(SRCS:.c=.o)

NAME		= 	so_long.a

LIBFT		=	./libft

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror

.c.o :
	$(CC) -c -I $(LIBFT) $< -o $@

$(NAME):		$(OBJS)
					cd $(LIBFT) && $(MAKE)
					cp libft/libft.a $(NAME)
					ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
					$(RM) -r $(OBJS)
					cd $(LIBFT) && $(MAKE) clean

fclean:			clean
					$(RM) $(NAME)
					cd $(LIBFT) && $(MAKE) fclean

re:				fclean all

.PHONY:			all clean fclean re