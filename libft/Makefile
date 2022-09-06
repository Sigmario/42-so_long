# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 17:50:33 by julmuntz          #+#    #+#              #
#    Updated: 2022/06/02 17:26:40 by julmuntz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_bzero.c							\
				ft_calloc.c							\
    			ft_hexlen_u.c						\
    			ft_hexlen_ul.c						\
				ft_itoa.c							\
				ft_linelen.c						\
    			ft_memcpy.c 						\
    			ft_nbrcpy.c 						\
    			ft_nbrlen_u.c 						\
    			ft_nbrlen.c 						\
    			ft_putchar.c						\
    			ft_puthex_u_lower.c					\
    			ft_puthex_u_upper.c					\
    			ft_puthex_ul.c						\
    			ft_putnbr_u.c						\
    			ft_putnbr_ul.c						\
    			ft_putnbr.c							\
    			ft_strchr.c							\
    			ft_strdup.c							\
    			ft_strjoin.c						\
				ft_strlen.c							\
    			ft_strncmp.c						\
    			ft_strrchr.c						\
				get_next_line.c						\
				./ft_printf/ft_printf.c				\
				./ft_printf/convert_char.c			\
				./ft_printf/convert_decimal.c		\
				./ft_printf/convert_hex_lower.c		\
				./ft_printf/convert_hex_pointer.c	\
				./ft_printf/convert_hex_upper.c		\
				./ft_printf/convert_integer.c		\
				./ft_printf/convert_string.c		\
				./ft_printf/convert_unsigned.c		\

OBJDIR		= 	obj/

OBJS		= 	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

NAME		= 	libft.a

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror

$(OBJDIR)%.o:	%.c
					@mkdir -p $(OBJDIR)
					@mkdir -p $(OBJDIR)/ft_printf/
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
					ar rc $(NAME) $(OBJS)

all:			$(NAME)

clean:
					$(RM) -r $(OBJDIR)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re