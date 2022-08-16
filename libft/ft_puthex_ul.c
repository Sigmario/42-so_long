/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:05:03 by julmuntz          #+#    #+#             */
/*   Updated: 2022/07/11 19:06:40 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_ul(unsigned long int n)
{
	char	*reference;

	reference = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex_ul(n / 16);
		ft_puthex_ul(n % 16);
	}
	else
		write(1, &reference[n], 1);
}
