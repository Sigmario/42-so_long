/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:29:49 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/22 17:43:45 by julmuntz         ###   ########.fr       */
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
# include "../mlx_linux/mlx.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_atoi(char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_convert_base(int n, int base);
int				ft_hexlen_u(unsigned int n);
int				ft_hexlen_ul(unsigned long int n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
size_t			ft_linelen(char *line);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*d)(void *));
void			ft_lstdelone(t_list *lst, void (*d)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memchr(void *s, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
void 			*ft_memcpy(void *dst, void *src, size_t n);
void 			*ft_memmove(void *dst, void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
int				ft_nbrcmp(int *n1, int *n2);
int				*ft_nbrcpy(int *n1, int *n2);
unsigned int	ft_nbrlen_u(unsigned int n);
int				ft_nbrlen(int n);
void			ft_putchar_fd(char c, int fd);
int				ft_putchar(char c);
void			ft_putendl_fd(char *s, int fd);
void			ft_puthex_u_lower(unsigned int n);
void			ft_puthex_u_upper(unsigned int n);
void			ft_puthex_ul(unsigned long int n);
void			ft_putint(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_u(unsigned int n);
void			ft_putnbr(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *str);
int				ft_scanf(char *fmt, ...);
char			**ft_split(char *s, char c);
char 			*ft_strchr(char *s, int c);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *s1, char *s2);
char 			*ft_strdup(char *s);
void 			ft_striteri(char *s, void (*f)(unsigned int, char *));
char 			*ft_strjoin(char *s1, char *s2);
size_t 			ft_strlcat(char *dst, char *src, size_t size);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
size_t			ft_strlen(char *s);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
int				ft_strncmp(char *s1, char *s2, size_t n);
size_t			ft_strnlen(char *str, size_t maxlen);
char			*ft_strnstr(char *big, char *little, size_t len);
char			*ft_strrchr(char *s, int c);
char			*ft_strtrim(char *s1, char *set);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			ft_swap(char *a, char *b);
int				ft_tolower(int c);
int				ft_toupper(int c);

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