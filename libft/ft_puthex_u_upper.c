/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_u_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:41:21 by julmuntz          #+#    #+#             */
/*   Updated: 2022/07/11 19:54:47 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_u_upper(unsigned int n)
{
	char	*reference;

	reference = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_puthex_u_upper(n / 16);
		ft_puthex_u_upper(n % 16);
	}
	else
		write(1, &reference[n], 1);
}
