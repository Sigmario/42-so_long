/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_u_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:59:16 by julmuntz          #+#    #+#             */
/*   Updated: 2022/07/11 19:54:14 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_u_lower(unsigned int n)
{
	char	*reference;

	reference = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex_u_lower(n / 16);
		ft_puthex_u_lower(n % 16);
	}
	else
		write(1, &reference[n], 1);
}
