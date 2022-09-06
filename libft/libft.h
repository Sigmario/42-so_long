/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:29:49 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/06 19:57:36 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 100
# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nbr, size_t size);
int				ft_hexlen_u(unsigned int n);
int				ft_hexlen_ul(unsigned long int n);
char			*ft_itoa(int nbr);
size_t			ft_linelen(char *line);
void			*ft_memcpy(void *dst, void *src, size_t n);
int				*ft_nbrcpy(int *n1, int *n2);
unsigned int	ft_nbrlen_u(unsigned int n);
int				ft_nbrlen(int n);
int				ft_putchar(char c);
void			ft_puthex_u_lower(unsigned int n);
void			ft_puthex_u_upper(unsigned int n);
void			ft_puthex_ul(unsigned long int n);
void			ft_putnbr_u(unsigned int n);
void			ft_putnbr(int n);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *s);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(char *s);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strrchr(char *s, int c);

/*				GET_NEXT_LINE												*/
char			*get_next_line(int fd);

/*				PRINTF														*/
int				ft_printf(const char *str, ...);
int				convert_char(char c);
int				convert_string(char *s);
int				convert_hex_pointer(unsigned long int hex_pointer);
int				convert_decimal(int decimal);
int				convert_integer(int integer);
int				convert_unsigned(unsigned int decimal_u);
int				convert_hex_lower(unsigned int hex_lower);
int				convert_hex_upper(unsigned int hex_upper);

#endif